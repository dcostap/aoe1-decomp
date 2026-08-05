// VA: 00485520 RGE_RMM_Land_Generator::base_land_generate
// PDB: rmm_land.cpp lines 213-353 (1833 bytes, 602 asm lines)
// Default flags. No inline asm/hacks.
//
// attempt log:
// - baseline(1): first canonical reconstruction from Ghidra decompiler; 4 phases: A)
//   set_terrain+search_map zone fill+four edge pushes, B) flood-fill loop with
//   chance/check_terrain_and_zone and neighbor push_stack, C) pop_stack drain
//   toggling tile byte 5, D) deinit_stack. Ordering/behavior faithful. Calls 21/21
//   aligned, frame 0xB08/0xB10, shape 60.6%, posdiff 1762.
// - layout(2): removed redundant `index1 = plVar12` alias; phase A now uses the
//   running `plVar12` pointer for terrain_type ([plVar12-3]) and zone ([plVar12+2])
//   access like the original. B001 now 7/7 aligns; posdiff 1697, shape 60.95%,
//   frame 0xB04/0xB10. (kept)
// - transpose-fix(3): verified pop_stack ABI (param_2 = &x gets node->x = column,
//   param_3 = &y gets node->y = row) against the exact matched pop_stack and the
//   phase C bounds (row bounded by max_x = height-1, column by in_zone = width-1).
//   The rebuilt tile access is map_row_offset[row=y][col=x] and search_map_rows
//   is [y][x]. Prior source had every phase B/C search_map access and neighbor
//   push/check_terrain_and_zone argument transposed ([x][y], (y-1,x), etc.).
//   Fixed all of them; also pass &land_size[0] as the pop_stack cost out-param
//   (the original reuses the land_size[0] slot at [esp+48h]), and made the
//   chance comparison signed (original: cmp chance,rand / jg) instead of the
//   unsigned (rand < (uint)chance) spelling. Shape 60.95% -> 76.5%, frame 0xB04
//   -> 0xB10 exact. THIS WAS THE REAL BLOCKER the prior pause blamed on
//   frame-slot allocation: the transposed indices were real semantic bugs.
// - layout(4): compare operand order (iVar11 >= map_width / iVar10 >= map_height
//   -> cmp edi,eax; jl like original, not cmp eax,edi; jg); reuse the top-declared
//   iStack_af8/c/x/y locals across phases instead of fresh tile2/c2/x3/y3;
//   cost out-param is now genuinely (float*)land_size; index3 used directly
//   instead of lVar13 alias. Shape 76.5% -> 82.2%, edit-diff 835 -> 476.
// - control-flow(5): chance branch spelled main-first `if (bVar3 <= rand) {main}
//   else {0xff}` (original: cmp bVar3,rand; jg to the 0xff block). Shape 82.2%.
//   Kept: the 0xff write still lands inline before the phase B tail instead of
//   the original's cold tail after the epilogue; a goto-based cold block was
//   tried and deleted 3 calls (VC5 sank/merged badly), so reverted.
// - control-flow(6): phase C neighbor bounds spelled x>=1/y>=1 (original emits
//   cmp reg,1; jl there, unlike phase B's 0<x which uses test; jle). Shape 83.17%.
// - liveness/restore probes (7-10): declaration-order swaps, `register` on the
//   phase A bounds, tile-slot float type-pun, t_zone byte naming - all either
//   codegen-identical or worse; reverted. No compiler-steering scaffolding kept.
// - (pause) remaining drift (shape 83.17%, posdiff 1647, size 1816/1833, frame
//   0xB10 exact, 21/21 calls aligned): a genuine VC5 register-allocation basin
//   difference. The rebuilt keeps local_b08 in ebx across phase B (original
//   reloads it from its home at every call site), keeps plVar12 in ebp in phase A
//   (original uses ebx and reuses it for pRVar8), and spills bVar3/bVar4 to slots
//   (original keeps them in ebx/edi). Those choices cascade into slot packing
//   (x/y/c/done/index2 homes differ by small offsets). No natural source lever
//   found in 10 probes that flips the allocator; the source below is the clean
//   canonical reconstruction and the codegen is a stable 83.17% basin.
//
// Next-lead evidence for a future worker: the phase A plVar12 register (ebx vs
//   ebp) and phase B local_b08 (memory vs ebx) appear to be one linked coloring
//   decision. The phase B pop_stack/push_stack call sites in the original always
//   reload the head pointer from [esp+18h]; forcing that reload pattern (e.g.
//   via a helper-surface change or by shrinking local_b08's live range so VC5's
//   spill-cost model prefers memory) may cascade the whole function into the
//   original basin.
// Phase map (original asm offsets):
//   A: +0000..+024A  init_stack / bounds / set_terrain / zone fill / 4 edge pushes
//   B: +024A..+05DD  flood-fill do-while (done flag), chance/check_terrain_and_zone,
//                    four neighbor pushes, land_size[i+1]++ at +05B6
//   C: +05DD..+07DC  per-land stack drain, toggle tile byte 5 on edge tiles
//   D: +07DC..+0810  per-land deinit_stack
//   cold: +0812..+0828  search_map[y][x] = 0xFF (chance > rand) rare tail

int debug_rand(char* file, int line);

class RGE_Map {
public:
    void set_terrain(long a1, long a2, long a3, long a4, long a5, long a6,
                     unsigned char t1, unsigned char t2, unsigned char t3);
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
    unsigned char check_terrain_and_zone(unsigned char t, unsigned char index, long a, long b);
};

unsigned char RGE_RMM_Land_Generator::base_land_generate() {
    long land_size[100];
    Map_Stack stack[99];

    long y;                    // row (pop_stack out, bounded by max_x)
    long x;                    // column (pop_stack out, bounded by in_zone)
    unsigned char bVar3;       // chance result (phase B)
    unsigned char bVar4;       // check_terrain_and_zone result (phase B)
    long* index1;              // land_size[1..] pointer (phase B)
    Map_Stack* local_b08;      // running stack head
    long index3;               // land loop counter
    long tile;                 // row cursor / float temp (phase A)
    long iStack_af8;           // edge/neighbor temp
    long c;                    // neighbor cost temp
    unsigned char done;        // phase B flood-fill loop flag
    unsigned char index2;      // zone byte (phase A)
    long x1;                   // edge push cursor (phase A)
    long terrain;              // clipped left bound (phase A)
    long* max_y;               // land_size[1] pointer (phase A)
    long in_zone;              // width - 1
    long max_x;                // height - 1
    long* plVar12;             // running land-info pointer (phase B)
    long index2b;              // land_size[i+1] value (phase B)
    index3 = 0;
    in_zone = this->map_width - 1;
    max_x = this->map_height - 1;

    // Phase A: for each land, expand around its base tile and stamp terrain + search map.
    if (this->info.land_num > 0) {
        local_b08 = &stack[0];
        max_y = &land_size[1];
        long* plVar12 = &this->info.land[0].base_size;
        do {
            this->init_stack(local_b08);

            long iVar11 = plVar12[-2];   // land x
            long iVar10 = plVar12[-1];   // land y
            *max_y = 0;
            long iVar9 = *plVar12;       // base_size
            terrain = iVar11 - iVar9;
            long pRVar8 = iVar10 - iVar9;
            iVar11 += iVar9;
            iVar10 += iVar9;
            if (terrain < 0) terrain = 0;
            if (pRVar8 < 0) pRVar8 = 0;
            if (iVar11 >= this->map_width) iVar11 = this->map_width - 1;
            if (iVar10 >= this->map_height) iVar10 = this->map_height - 1;

            this->map->set_terrain(0, 0, terrain, pRVar8, iVar11, iVar10,
                                   *(unsigned char*)(plVar12 - 3), 1, 0);

            index2 = *(unsigned char*)(plVar12 + 2);
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
            plVar12 += 13;
            local_b08 += 1;
        } while (index3 < this->info.land_num);
    }

    // Phase B: flood-fill pass.
    for (;;) {
        done = 1;
        index3 = 0;
        if (0 < this->info.land_num) {
            index1 = &land_size[1];
            local_b08 = &stack[0];
            plVar12 = &this->info.land[0].clumpiness_factor;
            do {
                index2b = *index1;
                if (index2b < plVar12[-7] &&
                    this->pop_stack(local_b08, &x, &y, (float*)land_size) != 0) {
                    done = 0;
                    bVar3 = this->chance(x, y, index3);
                    long iVar11 = debug_rand("C:\\msdev\\work\\age1_x1\\rmm_land.cpp", 299);
                    if (bVar3 <= (iVar11 * 100) / 0x7fff) {
                        iStack_af8 = (long)&this->map_row_offset[y][x];
                        bVar4 = this->check_terrain_and_zone(
                            (unsigned char)plVar12[-6], (unsigned char)index3, x, y);
                        unsigned int uVar6 = bVar4;
                        if (this->search_map_rows[y][x] == this->info.land_num && uVar6 != 0) {
                            RGE_Tile* tile2 = (RGE_Tile*)iStack_af8;
                            tile2->data[5] = ((unsigned char)plVar12[-6] ^ tile2->data[5]) & 0x1f ^ tile2->data[5];
                            this->search_map_rows[y][x] = *(unsigned char*)(plVar12 - 1);

                            if (0 < x && this->search_map_rows[y][x - 1] == this->info.land_num) {
                                c = ((debug_rand("C:\\msdev\\work\\age1_x1\\rmm_land.cpp", 0x138) * 100) / 0x7fff
                                     - uVar6 * plVar12[0]) + 0xfa;
                                this->push_stack(local_b08, x - 1, y, 0.0f, (float)c);
                            }
                            if (x < in_zone && this->search_map_rows[y][x + 1] == this->info.land_num) {
                                c = ((debug_rand("C:\\msdev\\work\\age1_x1\\rmm_land.cpp", 0x13b) * 100) / 0x7fff
                                     - uVar6 * plVar12[0]) + 0xfa;
                                this->push_stack(local_b08, x + 1, y, 0.0f, (float)c);
                            }
                            if (0 < y && this->search_map_rows[y - 1][x] == this->info.land_num) {
                                c = ((debug_rand("C:\\msdev\\work\\age1_x1\\rmm_land.cpp", 0x13e) * 100) / 0x7fff
                                     - uVar6 * plVar12[0]) + 0xfa;
                                this->push_stack(local_b08, x, y - 1, 0.0f, (float)c);
                            }
                            if (y < max_x && this->search_map_rows[y + 1][x] == this->info.land_num) {
                                c = ((debug_rand("C:\\msdev\\work\\age1_x1\\rmm_land.cpp", 0x141) * 100) / 0x7fff
                                     - uVar6 * plVar12[0]) + 0xfa;
                                this->push_stack(local_b08, x, y + 1, 0.0f, (float)c);
                            }
                            *index1 = index2b + 1;
                        }
                    } else {
                        this->search_map_rows[y][x] = 0xff;
                    }
                }
                index3++;
                plVar12 += 13;
                local_b08 += 1;
                index1 += 1;
            } while (index3 < this->info.land_num);
        }
        if (done != 0) break;
    }

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
}
