// map.h is source-private because the public module header needs only pointer
// and base declarations.

#include "../include/rmm_shal.h"
#include "../include/map.h"

extern "C" int __cdecl debug_rand(char*, int);

RGE_RMM_Shallows_Generator::RGE_RMM_Shallows_Generator(
    RGE_Map* in_map, RGE_Random_Map_Module* parent_module,
    RGE_Shallows_Info* in_info)
    : RGE_Random_Map_Module(in_map, parent_module, 1)
{
    this->schedule = 1.1f;
    this->info = *in_info;
}

// inner loop at line 57, and connection call at line 58.
uchar RGE_RMM_Shallows_Generator::generate()
{
    this->clear_stack();

    long i, j;
    long x, y;
    for (i = 0; i < this->info.shallows_num; ++i) {
        for (j = i + 1; j < this->info.shallows_num; ++j) {
            this->make_tribe_connections(i, j);
        }
    }

    long count = 2;
    this->info.shallows_num += 2;
    long index1 = this->info.shallows_num - 1;
    long index2 = this->info.shallows_num - 2;

    do {
        int found = 0;
        do {
            x = (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_shal.cpp", 0x45) *
                 (this->map_width - 1)) / 0x7FFF;
            y = (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_shal.cpp", 0x46) *
                 (this->map_height - 1)) / 0x7FFF;
            uchar terrain = this->map_row_offset[y][x].terrain_type & 0x1f;
            if (terrain != 1 && terrain != 0x16 && terrain != 4) {
                this->info.shallows[index1].x = x;
                found = 1;
                this->info.shallows[index1].y = y;
            }
        } while (!found);

        found = 0;
        do {
            x = (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_shal.cpp", 0x54) *
                 (this->map_width - 1)) / 0x7FFF;
            y = (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_shal.cpp", 0x55) *
                 (this->map_height - 1)) / 0x7FFF;
            uchar terrain = this->map_row_offset[y][x].terrain_type & 0x1f;
            if (terrain != 1 && terrain != 0x16 && terrain != 4) {
                this->info.shallows[index2].x = x;
                found = 1;
                this->info.shallows[index2].y = y;
            }
        } while (!found);

        this->make_tribe_connections(index1, index2);
        --count;
    } while (count != 0);

    return 1;
}

void RGE_RMM_Shallows_Generator::make_tribe_connections(long param_1, long param_2) {
    int iVar2;
    int iVar4;
    long lVar6;
    float* pfVar7;
    long lVar8;
    int iVar9;
    long y;
    long ty2;
    long end_x;
    long tx1;
    long end_y;
    long ty;
    long done;
    long tx2;
    long in_zone;
    Map_Stack stack;
    float terrain[41];
    terrain[1] = 0.0f;
    end_x = this->info.shallows[param_1].x;
    done = this->info.shallows[param_1].y;
    iVar2 = this->info.shallows[param_2].x;
    iVar9 = this->info.shallows[param_2].y;

    // zero out terrain[2..40]
    pfVar7 = terrain + 2;
    iVar4 = 0x27;
    while (iVar4 != 0) {
        *pfVar7 = 0.0f;
        pfVar7++;
        iVar4--;
    }

    tx1 = iVar2;
    ty = iVar9;

    this->init_stack(stack);

    terrain[1] = 1.0f;
    terrain[3] = 1.0f;
    terrain[2] = 7.0f;
    terrain[0x17] = 14.0f;
    terrain[5] = 2.0f;

    this->find_path(end_x, done, tx1, ty, &terrain[1]);

    if (tx1 != iVar2 || ty != iVar9) return;

    // Keep the first step coordinates live before the bounds guard. The
    // original loop carries these values across its back edge.
    y = tx1;
    ty2 = ty;

    if (tx1 < 0 || tx1 >= this->map_width) return;
    if (ty < 0 || ty >= this->map_height) return;

    stack.prev = 0;
    terrain[0] = 0.0f;
    tx2 = 0;

    while (1) {
        switch (this->search_map_rows[ty][tx1]) {
        case 7: // tile type 7
            --ty2;
            break;
        case 6: // tile type 6
            ++ty2;
            break;
        case 11: // tile type 11
            --ty2;
            --y;
            break;
        case 9: // tile type 9
            --ty2;
            ++y;
            break;
        case 10: // tile type 10
            ++ty2;
        case 5: // tile type 5
            --y;
            break;
        case 8: // tile type 8
            ++ty2;
        case 4: // tile type 4
            ++y;
            break;
        default:
            tx2 = 1;
            break;
        }

        if (y < 0 || y >= this->map_width || ty2 < 0 || ty2 >= this->map_height) {
            tx2 = 1;
        }

        if (tx2 != 0) {
            // Pop from stack and modify terrain tiles.
            while (this->pop_stack(stack, y, ty2, stack.cost) != 0) {
                RGE_Tile& tile = this->map_row_offset[ty2][y];
                tile.terrain_type = 4;
            }
            this->deinit_stack(stack);
            return;
        }

        // Check current tile terrain.
        RGE_Tile** rows3 = this->map_row_offset;
        unsigned char terrain_type = rows3[ty2][y].terrain_type & 0x1F;

        if (terrain_type == 1 || terrain_type == 0x16) {
            // Water tile - generate random area around it.
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
            // This bound remains live for the outer row loop.
            end_x = (iVar2 * 3) / 0x7FFF + 1 + ty2;
            if (end_x >= this->map_height) end_x = this->map_height - 1;

            done = lVar8;
            if (lVar8 <= end_x) {
                iVar2 = lVar8;
                do {
                    if (end_y <= in_zone) {
                        iVar9 = end_y;
                        done = lVar8;
                        do {
                            if ((this->map_row_offset[iVar2][iVar9].terrain_type & 0x1F) == 1 ||
                                (this->map_row_offset[iVar2][iVar9].terrain_type & 0x1F) == 0x16) {
                                this->push_stack(stack, lVar6, lVar8, 0.0f, 0.0f);
                                lVar8 = done;
                            }
                            lVar6++;
                            ++iVar9;
                        } while (lVar6 <= in_zone);
                    }
                    lVar8++;
                    ++iVar2;
                    lVar6 = end_y;
                    done = lVar8;
                } while (lVar8 <= end_x);
            }
        } else {
            // Land tile - push adjacent water tiles to stack.
            if (y > 0) {
                RGE_Tile** rows5 = this->map_row_offset;
                unsigned char adj = rows5[ty2][y - 1].terrain_type & 0x1F;
                if (adj == 1 || adj == 0x16) {
                    this->push_stack(stack, y - 1, ty2, 0.0f, 0.0f);
                }
            }
            if (y < this->map_width - 1) {
                RGE_Tile** rows5 = this->map_row_offset;
                unsigned char adj = rows5[ty2][y + 1].terrain_type & 0x1F;
                if (adj == 1 || adj == 0x16) {
                    this->push_stack(stack, y + 1, ty2, 0.0f, 0.0f);
                }
            }
            if (ty2 > 0) {
                RGE_Tile** rows5 = this->map_row_offset;
                unsigned char adj = rows5[ty2 - 1][y].terrain_type & 0x1F;
                if (adj == 1 || adj == 0x16) {
                    this->push_stack(stack, y, ty2 - 1, 0.0f, 0.0f);
                }
            }
            if (ty2 < this->map_height - 1) {
                RGE_Tile** rows5 = this->map_row_offset;
                unsigned char adj = rows5[ty2 + 1][y].terrain_type & 0x1F;
                if (adj == 1 || adj == 0x16) {
                    this->push_stack(stack, y, ty2 + 1, 0.0f, 0.0f);
                }
            }
        }

        // Mark current tile on block map.
        unsigned char** block_rows = (unsigned char**)this->search_map_rows;
        block_rows[ty][tx1] = 0xFF;

        tx1 = y;
        ty = ty2;
    }
}
