typedef int (__stdcall *LoadStringFunc)(void*, int, char*, int);
extern void* DAT_0062c4a0;
extern LoadStringFunc FN_0088a818;

char* __stdcall get_string(int string_id, char* buffer, int buffer_size) {
    int result = FN_0088a818(DAT_0062c4a0, string_id, buffer, buffer_size);
    if (!result) {
        *buffer = 0;
    }
    buffer[buffer_size - 1] = 0;
    return buffer;
}
