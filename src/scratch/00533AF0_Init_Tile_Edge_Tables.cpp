// VA: 00533AF0 RGE_View::Init_Tile_Edge_Tables()
// Attempt log:
// 1: natural implementation from packet/decompiler with CRT open/lseek/tell/read/close/calloc and edge table loops.
// 2: first local check same-size 799B, exact through 0xE1; file-load/relocation first half very close.
// 3: kept `_open`/`_lseek`/`_tell`/`_read`/`_close` declarations instead of headers; call set/cleanup matches.
// 4: used offset globals +0x184/+0x188/+0x1A0; prologue and frame match original `sub esp,18` with EBX/EBP/ESI/EDI saves.
// 5: natural first pointer-fix loop matches first table exactly; second table differs by small register choice (`edx`/`ecx`) at 0x119 region.
// 6: black-edge nested pointer loop uses single pointer increment; original uses EDX count and ESI base, our source is semantically right but register allocation drifts.
// 7: `for` zero-fill compiled to original rep stosd fill of 0xff across 0x100 bytes.
// 8: first edge-number classification loop shape is broadly close but boolean local/register topology diverges after table loads.
// 9: second fill pass behavior modeled with bit masks; remaining drift includes real branch/register scheduling in edge-number canonicalization, not accepted-drift-safe.
// 10: no inline asm/custom flags; left in scratch at 55.8198% positional / 17.5219% edit.

extern "C" int __cdecl _open(const char*, int);
extern "C" int __cdecl _lseek(int, int, int);
extern "C" int __cdecl _tell(int);
extern "C" int __cdecl _read(int, void*, unsigned int);
extern "C" int __cdecl _close(int);
extern "C" void* __cdecl calloc(unsigned int, unsigned int);

#define TILE ((char*)0x0058CD44)
#define BLK  ((char*)0x0058CD30)

typedef unsigned char uchar;

class RGE_View { public: char gap[0x2A0]; void Init_Tile_Edge_Tables(); };
#define EDGE (*(int**)((char*)this + 0x184))
#define BLACK (*(int**)((char*)this + 0x188))
#define EDGENUM ((uchar*)((char*)this + 0x1A0))

void RGE_View::Init_Tile_Edge_Tables()
{
    int fd, len;
    int i, j;
    int* p;
    int base;
    uchar* edge;
    int count;
    int ok;
    int b0,b1,b2,b3,b4,b5,b6,b7;

    fd = _open(TILE, 0x8000);
    if (fd != -1) {
        _lseek(fd,0,2); len = _tell(fd); EDGE = (int*)calloc(1,len); _lseek(fd,0,0); _read(fd,EDGE,len); _close(fd);
        base = (int)EDGE;
        for (i=0;i<0x44;i+=4) *(int*)((char*)EDGE+i) += base;
        for (i=0;i<0x44;i+=4) { p = *(int**)((char*)EDGE+i); for (j=0x2f;j!=0;j--) { if (p[0]) p[0]+=base; if (p[1]) p[1]+=base; p+=2; } }
    }
    fd = _open(BLK, 0x8000);
    if (fd != -1) {
        _lseek(fd,0,2); len = _tell(fd); BLACK = (int*)calloc(1,len); _lseek(fd,0,0); _read(fd,BLACK,len); _close(fd);
        base = (int)BLACK;
        for (i=0;i<0x44;i+=4) *(int*)((char*)BLACK+i) += base;
        for (i=0;i<0x44;i+=4) { p = *(int**)((char*)BLACK+i); for (j=0x2f;j!=0;j--) { if (p[0]) p[0]+=base; p++; } }
    }
    edge = EDGENUM;
    for (i=0;i<0x100;i++) edge[i] = 0xff;
    count = 0;
    for (i=0;i<0x100;i++) {
        ok = 1;
        b0 = (i & 1) == 1;
        b1 = (i & 2) == 2;
        b2 = (i & 4) == 4;
        b3 = (i & 8) == 8;
        b4 = (i & 0x10) == 0x10;
        b5 = (i & 0x20) == 0x20;
        b6 = (i & 0x40) == 0x40;
        b7 = (i & 0x80) == 0x80;
        if (b7 && (b0 || b3)) ok = 0;
        if (b6 && (b2 || b3)) ok = 0;
        if (b5 && (b1 || b2)) ok = 0;
        if (b4 && (b0 || b1)) ok = 0;
        if (ok) edge[i] = (uchar)count++;
    }
    for (i=0;i<0x100;i++) {
        if (edge[i] == 0xff) {
            b0 = i & 1; b1 = i & 2; b2 = i & 4; b3 = i & 8; b4 = i & 0x10; b5 = i & 0x20; b6 = i & 0x40; b7 = i & 0x80;
            if (b7) { b3 = 0; b0 = 0; }
            if (b6) { b3 = 0; b2 = 0; }
            if (b5) { b2 = 0; b1 = 0; }
            if (b4) { b1 = 0; b0 = 0; }
            edge[i] = edge[b7 | b6 | b5 | b4 | b3 | b2 | b1 | b0];
        }
    }
}
