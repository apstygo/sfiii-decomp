void AcrMain();

#if defined(TARGET_PS2)
void main() {
    AcrMain();
}
#else
int main() {
    AcrMain();
    return 0;
}
#endif
