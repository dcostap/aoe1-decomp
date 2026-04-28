// VA: 00480080 rge_read
// rge_fio.cpp lines 222-306
// 523 bytes, __cdecl
//
// Attempt log:
// v1-orig: first draft, 68.6% diff - baseline
// v7-memcpy: for-loop subtraction memcpy + void* rbuf local, 36.3% - big win
// 
// Remaining (~36%):
// - Early prologue: original reads param_2 into ECX before register saves
//   (mov ecx,[esp+0Ch] + mov [esp+1Ch],ecx). Rebuilt uses EBX after push ebx.
//   This is a VC5 register allocation choice (caller-saved vs callee-saved)
// - Scattered scheduling differences throughout the rest
// 
// Key: for-loop subtraction pattern (for(;cnt>=4;cnt-=4)) triggers shr+rep movsd
// rather than sar+loop. The void* rbuf = buf copy forces early parameter read.

extern int __cdecl read(int fd, void* buf, unsigned int size);
extern void* __cdecl calloc(int count, int size);
extern int __cdecl _Inf32BufSize();
extern int __cdecl _Inf32Decode(void* compressed, int offset, void* file_size, void* buf, int zero1, void* local_4, void* decomp_buf, int one);

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
            int fsize;
            DAT_0086b26c = (int)calloc(_Inf32BufSize(), 1);
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
                int* dst = (int*)rbuf;
                int* src = ptr;
                int cnt = copy;
                for (; cnt >= 4; cnt -= 4) *dst++ = *src++;
                {
                    char* cdst = (char*)dst;
                    char* csrc = (char*)src;
                    for (; cnt > 0; cnt--) *cdst++ = *csrc++;
                }
                
                {
                    int fsize;
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
                int* dst = (int*)rbuf;
                int* src = ptr;
                int cnt = remaining;
                for (; cnt >= 4; cnt -= 4) *dst++ = *src++;
                {
                    char* cdst = (char*)dst;
                    char* csrc = (char*)src;
                    for (; cnt > 0; cnt--) *cdst++ = *csrc++;
                }
                DAT_0086b268 += remaining;
                DAT_0086b278 += remaining;
            }
        }
    }
}
