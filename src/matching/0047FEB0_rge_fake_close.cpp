// VA: 0047FEB0 rge_fake_close
// rge_fio.cpp lines 123-147
// 115 bytes

int __cdecl __open(const char* path, int access, ...);
void __cdecl free(void* ptr);
void* __cdecl calloc(int count, int size);

extern int DAT_0086b260;   // current file handle
extern int DAT_0086b26c;   // deflate buffer
extern int DAT_0086b270;   // read buffer
extern int DAT_0086b280;   // compressed data buffer

int __cdecl rge_fake_close(int param_1) {
    if (param_1 >= 0 && param_1 == DAT_0086b260) {
        if (DAT_0086b270 != 0) {
            free((void*)DAT_0086b270);
            DAT_0086b270 = 0;
        }
        if (DAT_0086b26c != 0) {
            free((void*)DAT_0086b26c);
            DAT_0086b26c = 0;
        }
        if (DAT_0086b280 != 0) {
            free((void*)DAT_0086b280);
            DAT_0086b280 = 0;
        }
        DAT_0086b260 = -1;
    }
    return param_1;
}
