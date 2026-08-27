// VA: 0047FF30 rge_close
// rge_fio.cpp lines 151-188
// 196 bytes

void __cdecl free(void* ptr);
int __cdecl close(int fd);
int __cdecl deflate_data(void* buffer, void* src, int size, int flag);
void __cdecl deflate_deinit(void* buffer);

extern unsigned char DAT_0086b264;  // mode flag (1 = write compressed)
extern int DAT_0086b26c;            // deflate buffer
extern int DAT_0086b270;            // read buffer
extern int DAT_0086b280;            // compressed data buffer
extern int DAT_0086b260;            // current file handle
// The PDB names 0086B284 as the C++ global rge_write_error.
extern int rge_write_error;

int __cdecl rge_close(int param_1) {
    if (param_1 >= 0 && param_1 == DAT_0086b260) {
        if (DAT_0086b264 == 1 && DAT_0086b26c != 0) {
            int result = deflate_data((void*)DAT_0086b26c, 0, 0, 1);
            if (result == 2) {
                rge_write_error = 1;
            }
            deflate_deinit((void*)DAT_0086b26c);
        }
        DAT_0086b260 = -1;
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
        param_1 = close(param_1);
    }
    return param_1;
}
