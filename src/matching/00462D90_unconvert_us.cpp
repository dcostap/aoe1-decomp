// PDB: mystring.cpp:27-31. This is the global ?unconvert_us@@YAXPAD@Z.
// The natural forward loop preserves the shipped space-to-underscore update
// and the original byte-walk fault order.
// Exact finish: boundary 00462D90-00462DAA, strict positional match 26/26.
void __cdecl unconvert_us(char* str) {
    while (*str != '\0') {
        if (*str == ' ') {
            *str = '_';
        }
        str = str + 1;
    }
}
