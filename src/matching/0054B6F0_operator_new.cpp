void* __cdecl __nh_malloc(unsigned int size, int new_mode);

void* __cdecl operator_new(unsigned int size) {
    return __nh_malloc(size, 1);
}
