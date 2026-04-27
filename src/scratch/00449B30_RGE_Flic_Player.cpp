// VA: 00449B30 RGE_Flic_Player::RGE_Flic_Player(char* path)
// flics.cpp lines 21-50
// 161 bytes
// First-pass skeleton/partial — needs proper implementation

int __cdecl __open(const char* path, int access);
int __cdecl lseek(int fd, int offset, int whence);
int __cdecl __tell(int fd);
int __cdecl read(int fd, void* buf, unsigned int size);
int __cdecl close(int fd);
void* __cdecl calloc(int count, int size);

struct RGE_Flic_Player {
    unsigned char* flic_buffer;  // +0x00
    int flic_handle;             // +0x04
    char flichead[0x84];        // +0x08 (33 dwords = 132 bytes)
    // +0x8C: more fields
    int gap_8C;                  // +0x8C
    int gap_90;                  // +0x90
    int flic_width;              // +0x94
    // ... more fields up to +0xB0

    RGE_Flic_Player(char* path);
    void start();
};

RGE_Flic_Player::RGE_Flic_Player(char* path) {
    flic_handle = __open(path, 0x8000);
    if (flic_handle < 0) {
        flic_buffer = 0;
        flic_handle = -1;
        return;
    }
    lseek(flic_handle, 0, 2);
    int size = __tell(flic_handle);
    flic_buffer = (unsigned char*)calloc(size, 1);
    lseek(flic_handle, 0, 0);
    read(flic_handle, flic_buffer, size);
    // Copy FlicHead from buffer to struct
    int* src = (int*)flic_buffer;
    int* dst = (int*)(flichead);
    for (int i = 0; i < 0x21; i++) {
        *dst++ = *src++;
    }
    flic_width = *(short*)(flichead + 0x08);
    start();
    close(flic_handle);
}
