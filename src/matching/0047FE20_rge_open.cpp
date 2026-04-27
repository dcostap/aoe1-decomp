// VA: 0047FE20 rge_open (3-param)
// rge_fio.cpp lines 96-119
// 137 bytes

int __cdecl __open(const char* path, int access, ...);
void* __cdecl calloc(int count, int size);
int __cdecl lseek(int fd, int offset, int whence);
int __cdecl __tell(int fd);

extern unsigned char DAT_0086b264;  // mode flag
extern int DAT_0086b268;            // buffer offset
extern int DAT_0086b270;            // read buffer
extern int DAT_0086b274;            // read position
extern int DAT_0086b278;            // read buffer pointer
extern int DAT_0086b27c;            // file size
extern int DAT_0086b280;            // compressed data buffer
extern int DAT_0086b26c;            // deflate buffer
extern int DAT_0086b260;            // current file handle

int __cdecl rge_open(const char* path, int access, int attr) {
    int handle = __open(path, access, attr);
    if (handle >= 0) {
        DAT_0086b264 = 2;
        DAT_0086b268 = 0;
        DAT_0086b270 = (int)calloc(0x10000, 1);
        DAT_0086b278 = DAT_0086b270;
        DAT_0086b280 = 0;
        DAT_0086b26c = 0;
        DAT_0086b260 = handle;
        lseek(handle, 0, 2);
        DAT_0086b27c = __tell(handle);
        DAT_0086b274 = 0;
        lseek(handle, 0, 0);
    }
    return handle;
}
