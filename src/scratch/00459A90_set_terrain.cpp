// 00459A90 RGE_Map::set_terrain
// Attempt log:
// initial low-level source from asm; model tile rows and terrain tables with raw offsets.
// first build compiled but rebuilt .text was 640 bytes vs original/configured 649, so check_function stopped before compare.
// fixed RGE_Map implicit vptr/base offset so width/height/rows/terrain_count landed at +8/+c/+8d8c/+8d90; early disassembly then used correct member offsets but still 640 bytes.
// tried int source parameters to mirror original stack-slot dword writes and word compares; still 640 bytes and compiler kept EBP=this instead of original EDI=this.
// tried explicit register map=this and using map throughout; VC5 still chose EBP=this, not original EDI, and size remained 640.
// fixed final invalidate call to use expanded x2/y2 instead of saved original x2; size changed during experiments but did not reach comparable exact basin.
// left in scratch: behavior model/calls are plausible, but codegen topology differs from entry (stack frame 0x1c vs original 0x14 and EBP=this vs EDI=this), not accepted_drift-safe.

class RGE_Player;
class RGE_Game_World;

class RGE_Map {
public:
    virtual ~RGE_Map();
    char gap_04[4];
    int width;              // +08
    int height;             // +0c
    char gap_10[0x8c-0x10];
    char terrain_type[1];   // +8c, records are 0x198 apart
    char gap_8d[0x8d8c-0x8d];
    void** rows;            // +8d8c
    short terrain_count;    // +8d90

    void set_terrain(RGE_Player* player, RGE_Game_World* world, int x1, int y1, int x2, int y2, unsigned char terrain, unsigned char blend, void* arg9);
    void sub_00458820(short x, short y, short terrain, RGE_Game_World* world, int a, int b, void* arg9, int c);
    void sub_0045A030(short x, short y);
    void sub_00455CB0(short x1, short y1, short x2, short y2, int flag);
};

void RGE_Map::set_terrain(RGE_Player* player, RGE_Game_World* world, int x1, int y1, int x2, int y2, unsigned char terrain, unsigned char blend, void* arg9)
{
    register RGE_Map* map = this;
    unsigned short t = terrain;
    if ((short)t >= map->terrain_count) return;

    unsigned int ti = terrain;
    unsigned int idx = ((ti << 4) + ti) * 3;
    char* trec = (char*)map + idx * 8;
    if (*(unsigned char*)(trec + 0x8c) == 0) {
        short base = *(short*)(trec + 0x144);
        if (base <= -1) return;
        int bi = base;
        unsigned int bidx = ((bi << 4) + bi) * 3;
        if (*(unsigned char*)((char*)map + bidx * 8 + 0x8c) != 1) return;
    }

    if ((short)y1 > (short)y2) { int tmp = y1; y1 = y2; y2 = tmp; }
    if ((short)x1 > (short)x2) { int tmp = x1; x1 = x2; x2 = tmp; }

    if (y1 < 0) y1 = 0;
    if ((short)y2 >= map->height) y2 = (short)(map->height - 1);
    if (x1 < 0) x1 = 0;
    if ((short)x2 >= map->width) x2 = (short)(map->width - 1);

    int start_y = y1;
    int start_x = x1;

    if (blend || player != 0) {
        int yy = y1;
        if ((short)yy <= (short)y2) {
            int rowoff = (int)yy * 4;
            do {
                short xx = x1;
                char* tile = (char*)map->rows[yy] + ((int)x1 * 24) + 5;
                if (xx <= x2) {
                    do {
                        unsigned char old = tile[-1];
                        int c = old;
                        int off = (c + ((int)terrain << 2) * 17 + 0x23) * 3;
                        if (*(short*)((char*)map + off * 2) > 0) {
                            unsigned char val = tile[0];
                            unsigned short cur = val & 0x1f;
                            if (cur != t) {
                                if (blend) {
                                    tile[0] = (blend ^ val) & 0x1f ^ val;
                                }
                            }
                            if (player) {
                                map->sub_00458820(xx, yy, (short)cur, world, 0xffffffff, 0xffffffff, arg9, x1);
                            }
                        }
                        xx++;
                        tile += 24;
                    } while (xx <= x2);
                }
                yy++;
            } while ((short)yy <= (short)y2);
        }
    }

    if (y1 > 0) y1--;
    if ((short)y2 < map->height - 1) y2++;
    if (x1 > 0) x1--;
    if ((short)x2 < map->width - 1) x2++;

    short yy2 = y1;
    if (yy2 <= y2) {
        do {
            short xx2 = x1;
            if (xx2 <= x2) {
                do {
                    map->sub_0045A030(xx2, yy2);
                    xx2++;
                } while (xx2 <= x2);
            }
            yy2++;
        } while (yy2 <= y2);
    }
    map->sub_00455CB0(start_x, start_y, x2, y2, 0);
}
