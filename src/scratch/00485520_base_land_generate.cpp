// VA: 00485520 RGE_RMM_Land_Generator::base_land_generate
// PDB: rmm_land.cpp lines 213-353 (1833 bytes, 602 asm lines)
// Default flags. No inline asm/hacks.
//
// Attempt log:
// - The four phases, 21 direct calls, 0xB10 frame, and map/stack ownership are
//   recovered from the executable and PDB.
// - BINARY NOTE: pop_stack writes node->x to its first output and node->y to
//   its second. Source therefore uses &x, &y, with x as column and y as row.
// - BINARY NOTE: map rows use [y][x]. The chance and terrain helpers receive
//   column x before row y. The signed terrain result uses a > 0 gate.
// - BINARY NOTE: the cost output reuses land_size[0]. The neighbor cost uses
//   one integer local. A typed tile pointer replaces the old integer overlay.
// - H1: restoring the PDB REAL32 in_zone and land_size[99] added ftol calls,
//   changed the frame to 0xB0C, and worsened the result. Retain integer bounds
//   and the 0xB10 natural basin.
// - H2: restoring &x, &y and chance(x,y,index3) reduced positional diff to
//   1645 bytes. Keep this ABI-correct source despite lower shape score.
// - H3-H16: PDB scalar cursors, scoped count locals, typed tile ownership,
//   cold-label control flow, explicit do/while, promoted chance/result locals,
//   and one shared float temp were duplicate or worse. No metric-only form is
//   retained.
// - Current clean result: 1645 differing bytes, 81.68% shape, 21/21 calls,
//   0xB10 frame, and 1816 rebuilt bytes. The remaining drift is local-home,
//   register-color, and cold-tail layout drift.
// Phase map (original asm offsets):
//   A: +0000..+024A  init_stack / bounds / set_terrain / zone fill / 4 edge pushes
//   B: +024A..+05DD  flood-fill do-while (done flag), chance/check_terrain_and_zone,
//                    four neighbor pushes, land_size[i+1]++ at +05B6
//   C: +05DD..+07DC  per-land stack drain, toggle tile byte 5 on edge tiles
//   D: +07DC..+0810  per-land deinit_stack
//   cold: +0812..+0828  search_map[y][x] = 0xFF (chance > rand) rare tail

int debug_rand(char* file, int line);

class RGE_Player;
class RGE_Game_World;

class RGE_Map {
public:
    void set_terrain(RGE_Player* player, RGE_Game_World* world,
                     short a3, short a4, short a5, short a6,
                     unsigned char t1, unsigned char t2, int t3);
};

struct RGE_Tile {
    char data[0x18];
};

struct Map_Stack {
    long x;
    long y;
    float cost;
    float tot_cost;
    Map_Stack* next;
    Map_Stack* prev;
};

struct RGE_Land_Info_Line {
    long land_size;       // +0x0
    long terrain_type;    // +0x4
    long x;               // +0x8
    long y;               // +0xC
    long base_size;       // +0x10
    long area;            // +0x14
    unsigned char zone;   // +0x18
    char pad[3];
    long clumpiness_factor; // +0x1C
    long w1, w2, w3, w4;    // +0x20..+0x2C
    unsigned char wall_fade; // +0x30
    char pad2[3];
};

struct RGE_Land_Info {
    RGE_Land_Info_Line land[99];
    long land_num;        // +0x141C
};

class RGE_Random_Map_Module {
public:
    void* vftable;            // +0x00
    void* parent;             // +0x04
    void* list;               // +0x08
    RGE_Map* map;             // +0x0C
    RGE_Tile** map_row_offset;// +0x10
    long map_width;           // +0x14
    long map_height;          // +0x18
    float schedule;           // +0x1C
    unsigned char* search_map;// +0x20
    unsigned char** search_map_rows; // +0x24
    Map_Stack* stack_array;   // +0x28
    Map_Stack** stack_offsets;// +0x2C

    void init_stack(Map_Stack* stack);
    void push_stack(Map_Stack* list, long p2, long p3, float p4, float p5);
    Map_Stack* pop_stack(Map_Stack* head, long* x, long* y, float* cost);
    void deinit_stack(Map_Stack* stack);
};

class RGE_RMM_Land_Generator : public RGE_Random_Map_Module {
public:
    RGE_Land_Info info;       // +0x30

    unsigned char base_land_generate();
    unsigned char chance(long a, long b, long c);
    unsigned char check_terrain_and_zone(unsigned char unused, unsigned char land_id,
                                         long column, long row);
};

unsigned char RGE_RMM_Land_Generator::base_land_generate() {
    long land_size[100];
    Map_Stack stack[99];

    long y;                    // row (pop_stack second out, bounded by max_x)
    long x;                    // column (pop_stack first out, bounded by in_zone)
    unsigned char bVar3;       // chance result (phase B)
    unsigned char bVar4;       // check_terrain_and_zone result (phase B)
    long* index1;              // running land-info / land-size cursor
    Map_Stack* local_b08;      // running stack head
    long index3;               // land loop counter
    long tile;                 // row cursor / float temp (phase A)
    long iStack_af8;           // edge/neighbor temp
    unsigned char done;        // phase B flood-fill loop flag
    long x1;                   // edge push cursor (phase A)
    long terrain;              // clipped left bound (phase A)
    long* max_y;               // land_size[1] pointer (phase A)
    long in_zone;              // width - 1
    long max_x;                // height - 1
    long* plVar12;             // running land-info pointer (phase B)
    index3 = 0;
    in_zone = this->map_width - 1;
    max_x = this->map_height - 1;

    // Phase A: for each land, expand around its base tile and stamp terrain + search map.
    if (this->info.land_num > 0) {
        local_b08 = &stack[0];
        max_y = &land_size[1];
        index1 = &this->info.land[0].base_size;
        do {
            this->init_stack(local_b08);

            long iVar11 = index1[-2];   // land x
            long iVar10 = index1[-1];   // land y
            *max_y = 0;
            long iVar9 = *index1;       // base_size
            terrain = iVar11 - iVar9;
            long pRVar8 = iVar10 - iVar9;
            iVar11 += iVar9;
            iVar10 += iVar9;
            if (terrain < 0) terrain = 0;
            if (pRVar8 < 0) pRVar8 = 0;
            if (iVar11 >= this->map_width) iVar11 = this->map_width - 1;
            if (iVar10 >= this->map_height) iVar10 = this->map_height - 1;

            this->map->set_terrain(0, 0, terrain, pRVar8, iVar11, iVar10,
                                   *(unsigned char*)(index1 - 3), 1, 0);

            unsigned char index2 = *(unsigned char*)(index1 + 2);
            land_size[index2 + 1] = (iVar11 - terrain + 1) * (iVar10 - pRVar8 + 1);

            for (tile = pRVar8; tile <= iVar10; tile++) {
                for (long x2 = terrain; x2 <= iVar11; x2++) {
                    this->search_map_rows[tile][x2] = index2;
                }
            }

            if (0 < terrain && pRVar8 <= iVar10) {
                float f = (float)index3;
                x1 = pRVar8;
                do {
                    this->push_stack(local_b08, terrain - 1, x1, f, 0.0f);
                    x1++;
                } while (x1 <= iVar10);
            }
            if (0 < pRVar8 && terrain <= iVar11) {
                float f = (float)index3;
                x1 = terrain;
                do {
                    this->push_stack(local_b08, x1, pRVar8 - 1, f, 0.0f);
                    x1++;
                } while (x1 <= iVar11);
            }
            if (iVar11 < this->map_width - 1 && pRVar8 <= iVar10) {
                float f = (float)index3;
                x1 = pRVar8;
                do {
                    this->push_stack(local_b08, iVar11 + 1, x1, f, 0.0f);
                    x1++;
                } while (x1 <= iVar10);
            }
            if (iVar10 < this->map_height - 1 && terrain <= iVar11) {
                float f = (float)index3;
                iStack_af8 = terrain;
                do {
                    this->push_stack(local_b08, iStack_af8, iVar10 + 1, f, 0.0f);
                    iStack_af8++;
                } while (iStack_af8 <= iVar11);
            }

            index3++;
            max_y += 1;
            index1 += 13;
            local_b08 += 1;
        } while (index3 < this->info.land_num);
    }

    // Phase B: flood-fill pass.
    do {
        done = 1;
        index3 = 0;
        if (0 < this->info.land_num) {
            index1 = &land_size[1];
            local_b08 = &stack[0];
            plVar12 = &this->info.land[0].clumpiness_factor;
            do {
                long index2b;
                index2b = *index1;
                if (index2b < plVar12[-7] &&
                    this->pop_stack(local_b08, &x, &y, (float*)land_size) != 0) {
                    done = 0;
                    bVar3 = this->chance(x, y, index3);
                    long iVar11 = debug_rand("C:\\msdev\\work\\age1_x1\\rmm_land.cpp", 299);
                    if (bVar3 <= (iVar11 * 100) / 0x7fff) {
                        RGE_Tile* tile2 = &this->map_row_offset[y][x];
                        // ABI: unused terrain byte, land id, column, row.
                        bVar4 = this->check_terrain_and_zone(
                            (unsigned char)plVar12[-6], (unsigned char)index3, x, y);
                        int uVar6 = bVar4;
                        if (this->search_map_rows[y][x] == this->info.land_num && uVar6 > 0) {
                            tile2->data[5] = ((unsigned char)plVar12[-6] ^ tile2->data[5]) & 0x1f ^ tile2->data[5];
                            this->search_map_rows[y][x] = *(unsigned char*)(plVar12 - 1);

                            if (0 < x && this->search_map_rows[y][x - 1] == this->info.land_num) {
                                iStack_af8 = ((debug_rand("C:\\msdev\\work\\age1_x1\\rmm_land.cpp", 0x138) * 100) / 0x7fff
                                     - uVar6 * plVar12[0]) + 0xfa;
                                this->push_stack(local_b08, x - 1, y, 0.0f, (float)iStack_af8);
                            }
                            if (x < in_zone && this->search_map_rows[y][x + 1] == this->info.land_num) {
                                iStack_af8 = ((debug_rand("C:\\msdev\\work\\age1_x1\\rmm_land.cpp", 0x13b) * 100) / 0x7fff
                                     - uVar6 * plVar12[0]) + 0xfa;
                                this->push_stack(local_b08, x + 1, y, 0.0f, (float)iStack_af8);
                            }
                            if (0 < y && this->search_map_rows[y - 1][x] == this->info.land_num) {
                                iStack_af8 = ((debug_rand("C:\\msdev\\work\\age1_x1\\rmm_land.cpp", 0x13e) * 100) / 0x7fff
                                     - uVar6 * plVar12[0]) + 0xfa;
                                this->push_stack(local_b08, x, y - 1, 0.0f, (float)iStack_af8);
                            }
                            if (y < max_x && this->search_map_rows[y + 1][x] == this->info.land_num) {
                                iStack_af8 = ((debug_rand("C:\\msdev\\work\\age1_x1\\rmm_land.cpp", 0x141) * 100) / 0x7fff
                                     - uVar6 * plVar12[0]) + 0xfa;
                                this->push_stack(local_b08, x, y + 1, 0.0f, (float)iStack_af8);
                            }
                            *index1 = index2b + 1;
                        }
                    } else {
                        goto mark_ff;
                    }
                }
phase_b_continue:
                index3++;
                plVar12 += 13;
                local_b08 += 1;
                index1 += 1;
            } while (index3 < this->info.land_num);
        }
    } while (done == 0);

    // Phase C: drain each land stack, toggling the tile byte.
    index3 = 0;
    if (0 < this->info.land_num) {
        Map_Stack* pMVar5 = &stack[0];
        unsigned char* puVar14 = &this->info.land[0].zone;
        do {
            unsigned char uVar1 = *puVar14;
            unsigned char sVar = *(unsigned char*)(puVar14 - 0x14);
            Map_Stack* pMVar2 = pMVar5;
            while (this->pop_stack(pMVar2, &x, &y, (float*)land_size) != 0) {
                RGE_Tile* tile3 = &this->map_row_offset[y][x];
                if (((x >= 1 && this->search_map_rows[y][x - 1] == uVar1 && x < in_zone &&
                      this->search_map_rows[y][x + 1] == uVar1)) ||
                    ((y >= 1 && this->search_map_rows[y - 1][x] == uVar1 && y < max_x &&
                      this->search_map_rows[y + 1][x] == uVar1))) {
                    tile3->data[5] = (sVar ^ tile3->data[5]) & 0x1f ^ tile3->data[5];
                }
            }
            index3++;
            puVar14 += 0x34;
            pMVar5 += 1;
        } while (index3 < this->info.land_num);
    }

    // Phase D: deinit each stack.
    index3 = 0;
    if (0 < this->info.land_num) {
        Map_Stack* pMVar5 = &stack[0];
        do {
            this->deinit_stack(pMVar5);
            index3++;
            pMVar5 += 1;
        } while (index3 < this->info.land_num);
    }

    return 1;

mark_ff:
    this->search_map_rows[y][x] = 0xff;
    goto phase_b_continue;
}
