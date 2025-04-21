from typing import Generic, TypeVar, Any, Iterable
from functools import reduce
import struct

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
    
class IntDecodable(Decodable):
    def __init__(self, size: int, signed: bool) -> None:
        self.int_size = size
        self.signed = signed
        super().__init__()

    def decode(self, data: bytes) -> int:
        return int.from_bytes(data, byteorder="little", signed=self.signed)

    def size(self) -> int:
        return self.int_size
    
class FloatDecodable(Decodable):
    def __init__(self, size: int) -> None:
        self.float_size = size
        super().__init__()

    def decode(self, data: bytes) -> float:
        return struct.unpack("<f", data)[0]
    
    def size(self) -> int:
        return self.float_size
    
U8 = IntDecodable(1, False)
U16 = IntDecodable(2, False)
U32 = IntDecodable(4, False)
S8 = IntDecodable(1, True)
S16 = IntDecodable(2, True)
S32 = IntDecodable(4, True)
F32 = FloatDecodable(4)

class StructDecodable(Decodable):
    def __init__(self, members: list[Decodable]) -> None:
        self.members = members
        super().__init__()

    def decode(self, data: bytes) -> Any:
        decoded_members = list()
        offset = 0

        for member in self.members:
            end_offset = offset + member.size()
            decoded_members.append(member.decode(data[offset:end_offset]))
            offset += member.size()

        return decoded_members
    
    def size(self) -> int:
        return sum([x.size() for x in self.members])
    
def decode_type(decodable: Decodable, offset: int) -> Any:
    end_offset = offset + decodable.size()
    data_to_decode = binary[offset:end_offset]
    return decodable.decode(data_to_decode)

def decode_array(decodable: Decodable, offset: int, dimensions: Iterable[int]) -> Any:
    if len(dimensions) == 0:
        return decode_type(decodable, offset)

    result = list()
    stride = reduce(lambda x, y: x * y, dimensions[1:], 1)
    stride *= decodable.size()

    for i in range(dimensions[0]):
        sub_result_offset = offset + i * stride
        sub_result = decode_array(decodable, sub_result_offset, dimensions[1:])
        result.append(sub_result)

    return result

def generate_code(value: Any):
    if isinstance(value, list):
        print("{", end="")
        is_first = True

        for element in value:
            if not is_first:
                print(",", end="")

            is_first = False
            generate_code(element)

        print("}", end="")
    elif isinstance(value, float):
        print(f"{value}f", end="")
    else:
        print(value, end="")

def main():
    # Change these values

    offset = 0x423630
    decodable = S16
    dimensions = [12]

    generate_code(decode_array(decodable, offset, dimensions))

if __name__ == "__main__":
    main()
