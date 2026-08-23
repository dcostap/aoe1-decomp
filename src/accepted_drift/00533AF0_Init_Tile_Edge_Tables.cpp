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
// 9: replaced the black serialized-root byte-offset loop with a typed
//    Tile_BlackEdge_Table** walk; the diff fell to 341 bytes and size to 800,
//    but the first structural hunk remains at the second relocation loop.
// 10: typed-base, do-while, separate-index, and array-index byte-offset
//     variants restored the original relocation block but stayed at 806 bytes
//     and 453-455 bytes; rolled back. The typed 0x11-root walk remains best.
// 11: Restored named file literals and RGE_View fields. The macro lvalues and
//     raw addresses were diagnostic forms, not living source ownership.
// 12: changed the edge predicate and bit locals to bool from the decompiler's
//     bool labels; VC5 expanded the frame to 0x24 and 930 bytes, so restored int
//     locals. The binary's dword homes are not source-level bool evidence here.
// 13-19: typed root indexing, scalar aliases, declaration order, address-add
//     spelling, width, comparison, and nested-guard variants did not improve
//     the typed root basin.
// 20: scoping the eight bit locals inside each edge pass recovered the original
//     dword homes and most late blocks. Best result is 800 bytes and 338 strict
//     changed bytes. The remaining structural hunk is the black-root relocation
//     loop, where the original uses a byte-offset lowering.
// 21-22: separate declaration statements and explicit do-while forms were
//     codegen duplicates. No policy-valid exact source was found in this pass.
// 23: a fresh finish pass tested raw base, raw field, pointer-alias, named
//     cursor, and int** root forms. None was exact. The typed 0x11-root walk
//     remains the smallest clean source at 338 changed bytes.
// 24: compiling the owner with the reviewed view.cpp header context did not
//     change its body. The PDB owner is protected; keep the IAEX access form.
// 25: exact-finish probes tested dword root loops, scoped lvalues, byte-buffer
//     fields, pointer widths, root-cursor scope, and receiver aliases. The
//     raw-root forms were 796-806 bytes with 450-455 changed bytes. A typed
//     alias basin reached 98.96% exact block coverage but changed the base
//     register and removed the proven black-field reload. Restore the pinned
//     800-byte typed-root source after each probe.
// BINARY NOTE: the target has integer arithmetic only. It has no x87 path.
// Accepted-drift review: the executable reloads Black_Edge_Tables and uses a
// byte offset for each of 17 roots. The rebuild carries a typed root pointer
// and count. No call occurs in this loop; both read, relocate, and write the
// same entries in order. The later drift only changes bit-test registers and
// equivalent base/index encodings. All 14 calls and table effects match.

extern "C" int __cdecl _open(const char*, int);
extern "C" int __cdecl _lseek(int, int, int);
extern "C" int __cdecl _tell(int);
extern "C" int __cdecl _read(int, void*, unsigned int);
extern "C" int __cdecl _close(int);
extern "C" void* __cdecl calloc(unsigned int, unsigned int);

static const char s_tile_file[] = "DATA2\\TILEEDGE.DAT";
static const char s_black_tile_file[] = "DATA2\\BLKEDGE.DAT";

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

protected:
    void Init_Tile_Edge_Tables();
};
void RGE_View::Init_Tile_Edge_Tables()
{
    int fd, len;
    int i, j;
    Tile_FogEdge_Table* fog_table;
    Tile_BlackEdge_Table* black_table;
    int base;
    int count;
    int ok;
    Tile_BlackEdge_Table** black_roots;

    fd = _open(s_tile_file, 0x8000);
    if (fd != -1) {
        _lseek(fd,0,2); len = _tell(fd); this->Tile_Edge_Tables = (Tile_FogEdge_Table**)calloc(1,len); _lseek(fd,0,0); _read(fd,this->Tile_Edge_Tables,len); _close(fd);
        base = (int)this->Tile_Edge_Tables;
        for (i=0;i<0x44;i+=4)
            *(int*)((char*)this->Tile_Edge_Tables+i) += base;
        for (i=0;i<0x44;i+=4) {
            fog_table = *(Tile_FogEdge_Table**)((char*)this->Tile_Edge_Tables+i);
            for (j=0;j<0x2f;j++) {
                if (fog_table[j].normal_draw)
                    fog_table[j].normal_draw = (VSpanMiniList*)((char*)fog_table[j].normal_draw + base);
                if (fog_table[j].fog_draw)
                    fog_table[j].fog_draw = (VSpanMiniList*)((char*)fog_table[j].fog_draw + base);
            }
        }
    }
    fd = _open(s_black_tile_file, 0x8000);
    if (fd != -1) {
        _lseek(fd,0,2); len = _tell(fd); this->Black_Edge_Tables = (Tile_BlackEdge_Table**)calloc(1,len); _lseek(fd,0,0); _read(fd,this->Black_Edge_Tables,len); _close(fd);
        base = (int)this->Black_Edge_Tables;
        black_roots = this->Black_Edge_Tables;
        for (i=0;i<0x11;i++,black_roots++)
            *black_roots = (Tile_BlackEdge_Table*)((char*)*black_roots + base);
        for (i=0;i<0x44;i+=4) {
            black_table = *(Tile_BlackEdge_Table**)((char*)this->Black_Edge_Tables+i);
            for (j=0;j<0x2f;j++) {
                if (black_table[j].black_UNdraw)
                    black_table[j].black_UNdraw = (VSpanMiniList*)((char*)black_table[j].black_UNdraw + base);
            }
        }
    }
    uchar* edge = this->EdgeNumber;
    for (i=0;i<0x100;i++) edge[i] = 0xff;
    count = 0;
    i = 0;
    do {
        int b0,b1,b2,b3,b4,b5,b6,b7;
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
        i++;
    } while (i < 0x100);
    i = 0;
    do {
        if (edge[i] == 0xff) {
            int b0,b1,b2,b3,b4,b5,b6,b7;
            b0 = i & 1; b1 = i & 2; b2 = i & 4; b3 = i & 8; b4 = i & 0x10; b5 = i & 0x20; b6 = i & 0x40; b7 = i & 0x80;
            if (b7) { b3 = 0; b0 = 0; }
            if (b6) { b3 = 0; b2 = 0; }
            if (b5) { b2 = 0; b1 = 0; }
            if (b4) { b1 = 0; b0 = 0; }
            edge[i] = edge[b7 | b6 | b5 | b4 | b3 | b2 | b1 | b0];
        }
        i++;
    } while (i < 0x100);
}
