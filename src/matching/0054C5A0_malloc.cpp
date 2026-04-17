extern int __newmode;
void* __cdecl __nh_malloc(unsigned int size, int new_mode);

void* __cdecl malloc(unsigned int size) {
    return __nh_malloc(size, __newmode);
}
