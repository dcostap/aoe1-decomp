// VA: 00480080 rge_read
// rge_fio.cpp lines 222-306
// 523 bytes

// attempt 1: first-draft C code, 523/523 exact size, 319 diff
// attempt 2: reduced locals, 523/523 exact size, 359 diff (worse)
// The decompression loop with _Inf32Decode creates deep codegen mismatch
// Calloc push order, register scheduling, and stack layout all differ
// 5 sibling functions already exact matched
// Leaving in scratch - needs structured probe series

unsigned int __cdecl read(int fd, void* buf, unsigned int size);
void* __cdecl calloc(int count, int size);
int __cdecl _Inf32BufSize();
int __cdecl _Inf32Decode(void* compressed, int offset, void* file_size, void* buf, int zero1, void* local_4, void* decomp_buf, int one);

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
    if (ENABLE_COMPRESSION == 0) {
        if (fd >= 0 && fd == DAT_0086b260) {
            read(fd, buf, size);
            DAT_0086b27c -= size;
            DAT_0086b274 += size;
        }
    } else if (fd >= 0 && fd == DAT_0086b260) {
        if (DAT_0086b264 != 0) {
            DAT_0086b26c = (int)calloc(_Inf32BufSize(), 1);
            DAT_0086b280 = (int)calloc(DAT_0086b27c, 1);
            read(fd, (void*)DAT_0086b280, DAT_0086b27c);
            {
                int fsize = DAT_0086b27c;
                DAT_0086b25c = 0;
                int loc = 0x10000;
                _Inf32Decode((void*)DAT_0086b280, 0, &fsize, (void*)DAT_0086b270, 0, &loc, (void*)DAT_0086b26c, 1);
                DAT_0086b25c += fsize;
                DAT_0086b264 = 0;
            }
        }
        {
            int cur = DAT_0086b268;
            int* ptr = (int*)DAT_0086b278;
            int remaining = size;
            while (remaining + cur > 0x10000) {
                int copy = 0x10000 - cur;
                int wc = copy >> 2;
                int bc = copy & 3;
                {
                    int* dw = (int*)buf;
                    int* sw = ptr;
                    while (wc > 0) { *dw++ = *sw++; wc--; }
                    char* db = (char*)dw;
                    char* sb = (char*)sw;
                    while (bc > 0) { *db++ = *sb++; bc--; }
                }
                {
                    int fsize = DAT_0086b27c;
                    int loc = 0x10000;
                    _Inf32Decode((void*)DAT_0086b280, DAT_0086b25c, &fsize, (void*)DAT_0086b270, 0, &loc, (void*)DAT_0086b26c, 1);
                    DAT_0086b25c += fsize;
                }
                buf = (char*)buf + copy;
                DAT_0086b268 = 0;
                remaining -= copy;
                DAT_0086b278 = DAT_0086b270;
                ptr = (int*)DAT_0086b270;
                cur = 0;
            }
            if (remaining > 0) {
                int wc = remaining >> 2;
                int bc = remaining & 3;
                {
                    int* dw = (int*)buf;
                    int* sw = ptr;
                    while (wc > 0) { *dw++ = *sw++; wc--; }
                    char* db = (char*)dw;
                    char* sb = (char*)sw;
                    while (bc > 0) { *db++ = *sb++; bc--; }
                }
                DAT_0086b268 += remaining;
                DAT_0086b278 += remaining;
            }
        }
    }
}
