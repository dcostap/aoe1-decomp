// VA: 00449B30 RGE_Flic_Player::RGE_Flic_Player(char* path)
// flics.cpp lines 21-50
// 161 bytes
// MATCHED 2026-05-19. Key fixes: keep fd/size as register locals and model the 0x84-byte header
// as a real aggregate (`FlicHead`) assigned from the file buffer; VC5 lowers that aggregate assignment
// to the original `rep movsd` and lands the EBX=this / EBP=fd / ESI=size register split.

int __cdecl __open(const char* path, int access);
int __cdecl lseek(int fd, int offset, int whence);
int __cdecl __tell(int fd);
int __cdecl read(int fd, void* buf, unsigned int size);
int __cdecl close(int fd);
void* __cdecl calloc(int count, int size);

struct FlicHead { int d[0x21]; };

struct RGE_Flic_Player {
    unsigned char* flic_buffer;  // +0x00
    int flic_handle;             // +0x04
    FlicHead flichead;        // +0x08 (33 dwords = 132 bytes)
    // +0x8C: more fields
    int gap_8C;                  // +0x8C
    int gap_90;                  // +0x90
    int flic_width;              // +0x94
    // ... more fields up to +0xB0

    RGE_Flic_Player(char* path);
    void start();
};

RGE_Flic_Player::RGE_Flic_Player(char* path) {
    register int size;
    register int fd = __open(path, 0x8000);
    if (fd > -1) {
        lseek(fd, 0, 2);
        size = __tell(fd);
        flic_buffer = (unsigned char*)calloc(size, 1);
        lseek(fd, 0, 0);
        read(fd, flic_buffer, size);
        flichead = *(FlicHead*)flic_buffer;
        flic_width = *(short*)((char*)&flichead + 0x08);
        start();
        close(fd);
    }
    else {
        flic_buffer = 0;
        flic_handle = -1;
    }
}
