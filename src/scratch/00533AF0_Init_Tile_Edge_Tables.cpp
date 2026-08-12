// VA: 00533AF0 RGE_View::Init_Tile_Edge_Tables()
// Attempt log:
// 1: initial raw-offset reconstruction from the packet; call set and frame match.
// 2: typed table ownership and the two file-load/relocation passes are now the
//    living reconstruction. The downloaded pointer values are file-relative,
//    so the small integer relocation loop is required by the data format.
// 3: direct typed fields and indexed table roots introduced division and a
//    large prologue/layout drift; rolled back.
// 4: typed record members with fixed byte-offset roots preserved the 806-byte
//    basin (453 positional bytes, 133 edit bytes, 92.73% shape).
// 5: a scoped black-table alias reached the original 799-byte size but changed
//    liveness and raised positional drift to 481 bytes; rolled back.
// 6: reading through that alias worsened the second file block to 529 bytes;
//    rolled back.
// 7: a named black root-entry pointer changed the block shape but gave 455
//    positional bytes; rolled back as weaker than the typed baseline.
// 8: direct named RGE_View fields remained a 780-byte, 615-byte-diff basin;
//    restored the typed fixed-offset lvalues. No fake volatility or asm is used.

extern "C" int __cdecl _open(const char*, int);
extern "C" int __cdecl _lseek(int, int, int);
extern "C" int __cdecl _tell(int);
extern "C" int __cdecl _read(int, void*, unsigned int);
extern "C" int __cdecl _close(int);
extern "C" void* __cdecl calloc(unsigned int, unsigned int);

#define TILE ((char*)0x0058CD44)
#define BLK  ((char*)0x0058CD30)

typedef unsigned char uchar;

struct VSpanMiniList;

struct Tile_FogEdge_Table {
    VSpanMiniList* normal_draw;
    VSpanMiniList* fog_draw;
};

struct Tile_BlackEdge_Table {
    VSpanMiniList* black_UNdraw;
};

class RGE_View {
public:
    char gap_000[0x184];
    Tile_FogEdge_Table** Tile_Edge_Tables;
    Tile_BlackEdge_Table** Black_Edge_Tables;
    char gap_18C[0x14];
    uchar EdgeNumber[0x100];

    void Init_Tile_Edge_Tables();
};
#define EDGE_TABLES (*(Tile_FogEdge_Table***)((char*)this + 0x184))
#define BLACK_TABLES (*(Tile_BlackEdge_Table***)((char*)this + 0x188))
#define EDGENUM ((uchar*)((char*)this + 0x1A0))

void RGE_View::Init_Tile_Edge_Tables()
{
    int fd, len;
    int i, j;
    Tile_FogEdge_Table* fog_table;
    Tile_BlackEdge_Table* black_table;
    int base;
    int count;
    int ok;
    int b0,b1,b2,b3,b4,b5,b6,b7;

    fd = _open(TILE, 0x8000);
    if (fd != -1) {
        _lseek(fd,0,2); len = _tell(fd); EDGE_TABLES = (Tile_FogEdge_Table**)calloc(1,len); _lseek(fd,0,0); _read(fd,EDGE_TABLES,len); _close(fd);
        base = (int)EDGE_TABLES;
        for (i=0;i<0x44;i+=4)
            *(int*)((char*)EDGE_TABLES+i) += base;
        for (i=0;i<0x44;i+=4) {
            fog_table = *(Tile_FogEdge_Table**)((char*)EDGE_TABLES+i);
            for (j=0;j<0x2f;j++) {
                if (fog_table[j].normal_draw)
                    fog_table[j].normal_draw = (VSpanMiniList*)((char*)fog_table[j].normal_draw + base);
                if (fog_table[j].fog_draw)
                    fog_table[j].fog_draw = (VSpanMiniList*)((char*)fog_table[j].fog_draw + base);
            }
        }
    }
    fd = _open(BLK, 0x8000);
    if (fd != -1) {
        _lseek(fd,0,2); len = _tell(fd); BLACK_TABLES = (Tile_BlackEdge_Table**)calloc(1,len); _lseek(fd,0,0); _read(fd,BLACK_TABLES,len); _close(fd);
        base = (int)BLACK_TABLES;
        for (i=0;i<0x44;i+=4)
            *(int*)((char*)BLACK_TABLES+i) += base;
        for (i=0;i<0x44;i+=4) {
            black_table = *(Tile_BlackEdge_Table**)((char*)BLACK_TABLES+i);
            for (j=0;j<0x2f;j++) {
                if (black_table[j].black_UNdraw)
                    black_table[j].black_UNdraw = (VSpanMiniList*)((char*)black_table[j].black_UNdraw + base);
            }
        }
    }
    uchar* edge = EDGENUM;
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
