void __cdecl unconvert_us(char* str) {
    while (*str != '\0') {
        if (*str == ' ') {
            *str = '_';
        }
        str = str + 1;
    }
}
