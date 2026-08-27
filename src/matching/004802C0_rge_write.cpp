// VA: 004802C0 rge_write
// rge_fio.cpp lines 326-360
// 195 bytes

void* __cdecl calloc(int count, int size);
extern "C" int __cdecl write(int fd, const void* buf, unsigned int size);
int __cdecl deflate_buf_size();
int __cdecl rge_buffer_full(unsigned char* buffer, int count);
int __cdecl deflate_init(void* buffer, int param_2, int param_3, int param_4, void* buf, int size, int (__cdecl *callback)(unsigned char*, int));
int __cdecl deflate_data(void* buffer, void* src, int size, int flag);

extern int DAT_0086b260;            // current file handle
extern unsigned char DAT_0086b264;  // mode flag
extern int DAT_0086b26c;            // deflate buffer
extern int DAT_0086b270;            // read/write buffer
extern int ENABLE_COMPRESSION;      // 00585A6C
// The PDB names 0086B284 as the C++ global rge_write_error.
extern int rge_write_error;

void __cdecl rge_write(int param_1, void* param_2, int param_3) {
    if (ENABLE_COMPRESSION == 0) {
        if (param_1 >= 0 && param_1 == DAT_0086b260) {
            int result = write(param_1, param_2, param_3);
            if (result <= 0) {
                rge_write_error = 1;
            }
        }
    } else {
        if (param_1 >= 0 && param_1 == DAT_0086b260) {
            if (DAT_0086b264 != 1) {
                DAT_0086b264 = 1;
                int buf_size = deflate_buf_size();
                DAT_0086b26c = (int)calloc(buf_size, 1);
                deflate_init((void*)DAT_0086b26c, 0x4B, 2, 1, (void*)DAT_0086b270, 0x10000, rge_buffer_full);
            }
            int result = deflate_data((void*)DAT_0086b26c, param_2, param_3, 0);
            if (result == 2) {
                rge_write_error = 1;
            }
        }
    }
}
