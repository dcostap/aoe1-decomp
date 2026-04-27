/* VA: 00447F40 _WaveReadFile */
/* Dsutil.c lines 680-745, 242 bytes */

int __cdecl mmioOpen(void* p1, void* p2, void* p3);
int __cdecl mmioDescend(void* h, void* ck, void* parent, int flags);
int __cdecl mmioRead(void* h, void* p, int size);
int __cdecl mmioAscend(void* h, void* ck, int flags);
int __cdecl mmioClose(void* h, int flags);

int __cdecl _WaveReadFile(void* fname, void** wave, void** fmt, int* size) {
    return 1;
}
