// VA: 00487200 make_tribe_connections
// rmm_shal.cpp lines 106-245

// attempt 1: first-pass translation from Ghidra decompiler
//   -> compiles to EXACT SIZE (1172 bytes!) but 88% diff
//   needs significant struct/layout tuning, switch table shape, and call signatures
//   left in scratch due to complexity; would need many probes

class RGE_Random_Map_Module {
public:
    void* vtable_ptr;
    void* parent;
    void* list;
    void* map;
    void* map_row_offset;
    int map_width;
    int map_height;
    float schedule;
    void* search_map;
    void* search_map_rows;
    void* stack_array;
    void* stack_offsets;

    void clear_stack();
    void init_stack(void* stack);
    unsigned char find_path(int sx, int sy, int* tx, int* ty, float* terrain_info);
    void push_stack(void* stack, int x, int y, float a, float b);
    void* pop_stack(void* stack, int* x, int* y, float* info);
    void deinit_stack(void* stack);
};

class RGE_RMM_Shallows_Generator : public RGE_Random_Map_Module {
public:
    struct { long x, y; } shallows[99];
    int shallows_num;

    void make_tribe_connections(int a, int b);
};

extern int debug_rand(char*, int);

void RGE_RMM_Shallows_Generator::make_tribe_connections(int param_1, int param_2) {
    int end_x, end_y;
    int tx1, ty;
    float terrain[40];
    int tx2;
    int ty2, y;
    int x, z;
    int lVar6, lVar8;
    int in_zone;
    int iVar2, iVar9;
    int done;
    int stack[4]; // struct for push_stack/pop_stack

    terrain[0] = 0.0f;
    end_x = this->shallows[param_1].x;
    end_y = this->shallows[param_1].y;
    iVar2 = this->shallows[param_2].x;
    iVar9 = this->shallows[param_2].y;

    // zero out terrain[2..39]
    {
        int i = 0;
        while (i < 0x27) {
            terrain[i + 2] = 0.0f;
            i++;
        }
    }

    tx1 = iVar2;
    ty = iVar9;

    this->init_stack(&stack[1]); // stack.y

    terrain[1] = 1.0f;
    terrain[3] = 1.0f;
    terrain[2] = 7.0f;
    terrain[0x17] = 14.0f;
    terrain[5] = 2.0f;

    this->find_path(end_x, end_y, &tx1, &ty, &terrain[1]);

    if (tx1 != iVar2 || ty != iVar9) return;
    if (tx1 < 0 || tx1 >= this->map_width) return;
    if (ty < 0 || ty >= this->map_height) return;

    x = 0;
    z = 0;
    tx2 = 0;

    while (1) {
        ty2 = ty;
        y = tx1;

        unsigned char** rows = (unsigned char**)this->search_map_rows;
        unsigned char tile_type = rows[ty][tx1];

        switch (tile_type) {
        case 4: // tile type 4
            y = tx1 + 1;
            break;
        case 5: // tile type 5
            y = tx1 - 1;
            break;
        case 6: // tile type 6
            ty2 = ty + 1;
            break;
        case 7: // tile type 7
            ty2 = ty - 1;
            break;
        case 8: // tile type 8
            y = tx1 + 1;
            ty2 = ty + 1;
            break;
        case 9: // tile type 9
            y = tx1 + 1;
            ty2 = ty - 1;
            break;
        case 10: // tile type 10
            y = tx1 - 1;
            ty2 = ty + 1;
            break;
        case 11: // tile type 11
            y = tx1 - 1;
            ty2 = ty - 1;
            break;
        default:
            tx2 = 1;
            break;
        }

        if (y < 0 || y >= this->map_width || ty2 < 0 || ty2 >= this->map_height) {
            tx2 = 1;
        }

        if (tx2 != 0) {
            // Pop from stack and modify terrain tiles
            while (1) {
                void* result = this->pop_stack(&stack[1], &y, &ty2, (float*)&stack);
                if (result == 0) break;
                unsigned char** rows2 = (unsigned char**)this->search_map_rows;
                unsigned char* tile_ptr = &rows2[ty2][y * 24 + 5];
                *tile_ptr = (*tile_ptr & 0xE4) | 4;

                // Second pop in loop
                result = this->pop_stack(&stack[1], &y, &ty2, (float*)&stack);
                if (result == 0) break;
                tile_ptr = &rows2[ty2][y * 24 + 5];
                *tile_ptr = (*tile_ptr & 0xE4) | 4;
            }
            this->deinit_stack(&stack[1]);
            return;
        }

        // Check current tile terrain
        unsigned char** rows3 = (unsigned char**)this->search_map;
        unsigned char* curr_tile = &rows3[ty2][y * 24 + 5];
        unsigned char terrain_type = *curr_tile & 0x1F;

        if (terrain_type == 1 || terrain_type == 0x16) {
            // Water tile - generate random area around it
            iVar2 = debug_rand("C:\\msdev\\work\\age1_x1\\rmm_shal.cpp", 0xC6);
            end_y = (y - (iVar2 * 2) / 0x7FFF) - 1;
            if (end_y < 0) end_y = 0;
            lVar6 = end_y;

            iVar2 = debug_rand("C:\\msdev\\work\\age1_x1\\rmm_shal.cpp", 0xCA);
            lVar8 = (ty2 - (iVar2 * 2) / 0x7FFF) - 1;
            if (lVar8 < 0) lVar8 = 0;

            iVar2 = debug_rand("C:\\msdev\\work\\age1_x1\\rmm_shal.cpp", 0xCE);
            in_zone = (iVar2 * 2) / 0x7FFF + 1 + y;
            if (in_zone >= this->map_width) in_zone = this->map_width - 1;

            iVar2 = debug_rand("C:\\msdev\\work\\age1_x1\\rmm_shal.cpp", 0xD2);
            done = (iVar2 * 3) / 0x7FFF + 1 + ty2;
            if (done >= this->map_height) done = this->map_height - 1;

            done = lVar8;
            if (lVar8 <= done) {
                iVar2 = lVar8 * 4;
                do {
                    if (end_y <= in_zone) {
                        iVar9 = end_y * 24;
                        done = lVar8;
                        do {
                            unsigned char** rows4 = (unsigned char**)this->search_map;
                            unsigned char tile_check = rows4[iVar2 / 4][5 + iVar9] & 0x1F;
                            if (tile_check == 1 || tile_check == 0x16) {
                                this->push_stack(&stack[1], lVar6, lVar8, 0.0f, 0.0f);
                            }
                            lVar6++;
                            iVar9 += 24;
                        } while (lVar6 <= in_zone);
                    }
                    lVar8++;
                    iVar2 += 4;
                    lVar6 = end_y;
                    done = lVar8;
                } while (lVar8 <= done);
            }
        } else {
            // Land tile - push adjacent water tiles to stack
            if (y > 0) {
                unsigned char** rows5 = (unsigned char**)this->search_map;
                unsigned char adj = rows5[ty2][(y - 1) * 24 + 5] & 0x1F;
                if (adj == 1 || adj == 0x16) {
                    this->push_stack(&stack[1], y - 1, ty2, 0.0f, 0.0f);
                }
            }
            if (y < this->map_width - 1) {
                unsigned char** rows5 = (unsigned char**)this->search_map;
                unsigned char adj = rows5[ty2][(y + 1) * 24 + 5] & 0x1F;
                if (adj == 1 || adj == 0x16) {
                    this->push_stack(&stack[1], y + 1, ty2, 0.0f, 0.0f);
                }
            }
            if (ty2 > 0) {
                unsigned char** rows5 = (unsigned char**)this->search_map;
                unsigned char adj = rows5[ty2 - 1][y * 24 + 5] & 0x1F;
                if (adj == 1 || adj == 0x16) {
                    this->push_stack(&stack[1], y, ty2 - 1, 0.0f, 0.0f);
                }
            }
            if (ty2 < this->map_height - 1) {
                unsigned char** rows5 = (unsigned char**)this->search_map;
                unsigned char adj = rows5[ty2 + 1][y * 24 + 5] & 0x1F;
                if (adj == 1 || adj == 0x16) {
                    this->push_stack(&stack[1], y, ty2 + 1, 0.0f, 0.0f);
                }
            }
        }

        // Mark current tile on block map
        unsigned char** block_rows = (unsigned char**)this->search_map_rows;
        block_rows[ty][tx1] = 0xFF;

        tx1 = y;
        ty = ty2;
    }
}
