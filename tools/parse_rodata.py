from typing import Generic, TypeVar, Any, Iterable
from functools import reduce
import struct
from dataclasses import dataclass
from string_at_offset import read_string

with open("THIRD_U.BIN", "rb") as f:
    binary = f.read()

T = TypeVar("T")

class Decodable(Generic[T]):
    def __init__(self) -> None:
        super().__init__()

    def decode(self, data: bytes) -> T:
        pass

    def size(self) -> int:
        return 0
    
    def alignment(self) -> int:
        return 1
    
class IntDecodable(Decodable):
    def __init__(self, size: int, signed: bool) -> None:
        self.int_size = size
        self.signed = signed
        super().__init__()

    def decode(self, data: bytes) -> int:
        return int.from_bytes(data, byteorder="little", signed=self.signed)

    def size(self) -> int:
        return self.int_size
    
    def alignment(self) -> int:
        return self.int_size
    
class FloatDecodable(Decodable):
    def __init__(self, size: int) -> None:
        self.float_size = size
        super().__init__()

    def decode(self, data: bytes) -> float:
        return struct.unpack("<f", data)[0]
    
    def size(self) -> int:
        return self.float_size
    
    def alignment(self) -> int:
        return self.float_size
    
class StringDecodable(IntDecodable):
    def __init__(self) -> None:
        super().__init__(size=4, signed=False)

    def decode(self, data: bytes) -> str:
        vram_offset = super().decode(data)
        file_offset = vram_offset - 0x100000 + 0x80
        return read_string(binary, file_offset)[1:-1]
    
U8 = IntDecodable(1, False)
U16 = IntDecodable(2, False)
U32 = IntDecodable(4, False)
U64 = IntDecodable(8, False)
S8 = IntDecodable(1, True)
S16 = IntDecodable(2, True)
S32 = IntDecodable(4, True)
S64 = IntDecodable(8, True)
F32 = FloatDecodable(4)

@dataclass
class NamedValue:
    name: str
    value: Any

class StructDecodable(Decodable):
    def __init__(self, members: dict[str, Decodable]) -> None:
        self.members = members
        super().__init__()

    def decode(self, data: bytes) -> Any:
        decoded_members = list()
        offset = 0

        for name, member in self.members.items():
            offset = self.__align(offset, member.alignment())
            end_offset = offset + member.size()
            value = member.decode(data[offset:end_offset])
            decoded_members.append(NamedValue(name, value))
            offset += member.size()

        return decoded_members
    
    def size(self) -> int:
        offset = 0
        size = 0

        for member in self.members.values():
            offset = self.__align(offset, member.alignment())
            size = offset + member.size()
            offset = size

        return size
    
    def __align(self, offset: int, alignment: int) -> int:
        return ((offset + alignment - 1) // alignment) * alignment
    
class ArrayDecodable(Decodable):
    def __init__(self, element: Decodable, dimensions: Iterable[int]):
        if len(dimensions) == 0:
            raise ValueError("dimensions can't be empty")
        elif len(dimensions) > 1:
            self.element = ArrayDecodable(element, dimensions[1:])
        else:
            self.element = element

        self.dimensions = dimensions
        super().__init__()

    def decode(self, data: bytes) -> list[Any]:
        decoded_elements = list()

        for start in range(0, self.size(), self.stride):
            end = start + self.element.size()
            decoded_elements.append(self.element.decode(data[start:end]))

        return decoded_elements

    def size(self) -> int:
        return self.dimensions[0] * self.stride
    
    def alignment(self) -> int:
        return self.element.alignment()
    
    @property
    def stride(self) -> int:
        elem_size = self.element.size()
        elem_alignment = self.element.alignment()
        return (elem_size + elem_alignment - 1) // elem_alignment * elem_alignment
    
def decode_type(decodable: Decodable, offset: int) -> Any:
    end_offset = offset + decodable.size()
    data_to_decode = binary[offset:end_offset]
    return decodable.decode(data_to_decode)

def generate_code(value: Any, hex_ints: bool = False):
    if isinstance(value, list):
        print("{", end="")
        is_first = True

        for element in value:
            if not is_first:
                print(",", end="")

            is_first = False
            generate_code(element, hex_ints)

        print("}", end="")
    elif isinstance(value, float):
        print(f"{value}f", end="")
    elif isinstance(value, NamedValue):
        print(f".{value.name} = ", end="")
        generate_code(value.value, hex_ints)
    elif isinstance(value, str):
        print(f"\"{value}\"", end="")
    else:
        if hex_ints:
            prefix = ""

            if value < 0:
                value *= -1
                prefix = "-"

            print(f"{prefix}0x{value:X}", end="")
        else:
            print(value, end="")

def main():
    # Change these values

    offset = 0x423630
    decodable = ArrayDecodable(S16, [12])

    generate_code(decode_type(decodable, offset))

if __name__ == "__main__":
    main()
