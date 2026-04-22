void __cdecl convert_us(char* str) {
    while (*str != '\0') {
        if (*str == '_') {
            *str = ' ';
        }
        str = str + 1;
    }
}
