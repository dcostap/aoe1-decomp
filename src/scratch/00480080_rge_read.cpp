// VA: 00480080 rge_read
// rge_fio.cpp lines 222-306
// 523 bytes, __cdecl
//
// Attempt log:
// baseline: named rbuf cursor and manual dword/byte copies; 574 bytes, 277 diff.
// ABI: C linkage for Inf32 helpers aligned all seven call targets; retained.
// control-flow: separate BufSize result from calloc; matched the first helper call order.
// variant: intrinsic memcpy produced the original REP MOVSD/MOVSB copies and exact size.
// layout: function-scope fsize before loc matched decode stack homes; best is 528 bytes, 127 diff.
// rejected: mutating fd or using buf as the cursor broke the original prologue and stack shape.
// remaining: register and post-decode scheduling drift after the second Inf32Decode call.

extern int __cdecl read(int fd, void* buf, unsigned int size);
extern void* __cdecl calloc(int count, int size);
extern "C" int __cdecl _Inf32BufSize();
extern "C" int __cdecl _Inf32Decode(void* compressed, int offset, void* file_size, void* buf, int zero1, void* local_4, void* decomp_buf, int one);
extern "C" void* __cdecl memcpy(void* dst, const void* src, unsigned int size);
#pragma intrinsic(memcpy)

extern int ENABLE_COMPRESSION;
extern int DAT_0086b260;
extern unsigned char DAT_0086b264;
extern int DAT_0086b268;
extern int DAT_0086b26c;
extern int DAT_0086b270;
extern int DAT_0086b274;
extern int DAT_0086b278;
extern int DAT_0086b27c;
extern int DAT_0086b280;
extern int DAT_0086b25c;

void __cdecl rge_read(int fd, void* buf, int size) {
    int fsize;
    int loc;
    void* rbuf = buf;

    if (ENABLE_COMPRESSION == 0) {
        if (fd >= 0 && fd == DAT_0086b260) {
            read(fd, rbuf, size);
            DAT_0086b27c -= size;
            DAT_0086b274 += size;
        }
    } else if (fd >= 0 && fd == DAT_0086b260) {
        if (DAT_0086b264 != 0) {
            int buf_size = _Inf32BufSize();
            DAT_0086b26c = (int)calloc(buf_size, 1);
            DAT_0086b280 = (int)calloc(DAT_0086b27c, 1);
            read(fd, (void*)DAT_0086b280, DAT_0086b27c);
            fsize = DAT_0086b27c;
            DAT_0086b25c = 0;
            loc = 0x10000;
            _Inf32Decode((void*)DAT_0086b280, 0, &fsize, (void*)DAT_0086b270, 0, &loc, (void*)DAT_0086b26c, 1);
            DAT_0086b25c += fsize;
            DAT_0086b264 = 0;
        }
        {
            int remaining = size;
            int cur = DAT_0086b268;
            int* ptr = (int*)DAT_0086b278;
            while (remaining + cur > 0x10000) {
                int copy = 0x10000 - cur;
                memcpy(rbuf, ptr, copy);
                
                {
                    fsize = DAT_0086b27c;
                    loc = 0x10000;
                    _Inf32Decode((void*)DAT_0086b280, DAT_0086b25c, &fsize, (void*)DAT_0086b270, 0, &loc, (void*)DAT_0086b26c, 1);
                    DAT_0086b25c += fsize;
                }
                
                rbuf = (char*)rbuf + copy;
                DAT_0086b268 = 0;
                remaining -= copy;
                DAT_0086b278 = DAT_0086b270;
                ptr = (int*)DAT_0086b270;
                cur = 0;
            }
            if (remaining > 0) {
                memcpy(rbuf, ptr, remaining);
                DAT_0086b268 += remaining;
                DAT_0086b278 += remaining;
            }
        }
    }
}
