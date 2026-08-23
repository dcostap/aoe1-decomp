// PDB: mystring.cpp:19-23. The natural forward loop preserves the shipped
// underscore-to-space update and the original byte-walk fault order.
// Exact finish: owner ?convert_us@@YAXPAD@Z, boundary 00462D70-00462D8A,
// strict positional match 26/26.
void __cdecl convert_us(char* str) {
    while (*str != '\0') {
        if (*str == '_') {
            *str = ' ';
        }
        str = str + 1;
    }
}
