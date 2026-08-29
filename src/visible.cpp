// Authentic complete owner for C:\\msdev\\work\\age1_x1\\visible.cpp.
// Normal owners stay in PDB source order.

#include "../include/visible.h"
#include "../include/map.h"
#include "../include/player.h"
#include "../include/world.h"
#include "../include/game_globals.h"
#include <stdio.h>
#include <string.h>

#pragma intrinsic(_rotl)

extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);
extern "C" void __cdecl free(void* block);
extern "C" void __cdecl rge_write(int handle, void* buffer, int count);
extern "C" void __cdecl rge_read(int handle, void* buffer, int count);

extern void __cdecl log_map_call(int world_time, int player_id, int type,
                                 int p6, int x1, int y1, int x2, int y2,
                                 int suppression);

// VA: 0053C1B0 RGE_Visible_Map::RGE_Visible_Map
// PDB source: visible.cpp lines 226-256.
RGE_Visible_Map::RGE_Visible_Map(RGE_Map* param_1, RGE_Player* param_2) {
    int row;

    this->world = param_2->world;
    this->player = param_2;
    this->map = param_1;
    this->widthValue = param_1->map_width;
    this->heightValue = param_1->map_height;
    this->numberTilesExploredValue = 0;
    this->numberTotalTilesValue = this->widthValue * this->heightValue;
    if ((this->widthValue <= 0) || (this->heightValue <= 0)) {
        this->visible_map = 0;
        this->map_offsets = 0;
    } else {
        this->visible_map = (unsigned char*)calloc(this->numberTotalTilesValue, 1);
        this->map_offsets = (unsigned char**)calloc(this->heightValue, 4);
        row = 0;
        if (0 < this->heightValue) {
            do {
                this->map_offsets[row] = this->visible_map + row * this->widthValue;
                row = row + 1;
            } while (row < this->heightValue);
        }
        memset(this->visible_map, 0xff, this->heightValue * this->widthValue);
    }
    unsigned long mask = 1 << (unsigned char)param_2->id;
    this->input_csum = 0;
    this->PlayerVisibleMaskValue = mask;
    this->PlayerVisibleMaskInvertValue = ~this->PlayerVisibleMaskValue;
    this->PlayerExploredMaskValue =
        *(volatile unsigned long*)&this->PlayerVisibleMaskValue << 0x10;
    this->PlayerExploredMaskInvertValue = ~this->PlayerExploredMaskValue;
}

// VA: 0053C290 RGE_Visible_Map::RGE_Visible_Map
// PDB source: visible.cpp lines 265-307.
RGE_Visible_Map::RGE_Visible_Map(int file, RGE_Game_World* world) {
    int player_id;

    this->world = world;
    this->map = world->map;
    this->numberTilesExploredValue = 0;

    rge_read(file, &this->widthValue, 4);
    rge_read(file, &this->heightValue, 4);
    if (save_game_version >= 6.7f) {
        rge_read(file, &this->numberTilesExploredValue, 4);
    }
    rge_read(file, &player_id, 2);

    this->numberTotalTilesValue = this->heightValue * this->widthValue;
    this->player = world->players[(short)player_id];

    if ((this->widthValue <= 0) || (this->heightValue <= 0)) {
        this->visible_map = 0;
        this->map_offsets = 0;
    } else {
        this->visible_map = (unsigned char*)calloc(this->numberTotalTilesValue, 1);
        this->map_offsets = (unsigned char**)calloc(this->heightValue, 4);

        int row = 0;
        if (0 < this->heightValue) {
            do {
                this->map_offsets[row] =
                    this->visible_map + row * this->widthValue;
                row = row + 1;
            } while (row < this->heightValue);
        }
        rge_read(file, this->visible_map,
                 this->widthValue * this->heightValue);
    }

    this->input_csum = 0;
    this->PlayerVisibleMaskValue = 1 << (unsigned char)player_id;
    this->PlayerVisibleMaskInvertValue = ~this->PlayerVisibleMaskValue;
    this->PlayerExploredMaskValue = this->PlayerVisibleMaskValue << 0x10;
    this->PlayerExploredMaskInvertValue = ~this->PlayerExploredMaskValue;
}

// VA: 0053C3C0 RGE_Visible_Map::~RGE_Visible_Map
// PDB source: visible.cpp lines 313-329.
RGE_Visible_Map::~RGE_Visible_Map() {
    if (this->visible_map != 0) {
        free(this->visible_map);
        this->visible_map = 0;
    }
    if (this->map_offsets != 0) {
        free(this->map_offsets);
        this->map_offsets = 0;
    }
    this->player = 0;
    this->map = 0;
}

// VA: 0053C400 RGE_Visible_Map::save
// PDB source: visible.cpp lines 336-350.
void RGE_Visible_Map::save(int handle) {
    rge_write(handle, &this->widthValue, 4);
    rge_write(handle, &this->heightValue, 4);
    if (save_game_version >= 6.7f) {
        rge_write(handle, &this->numberTilesExploredValue, 4);
    }
    rge_write(handle, &this->player->id, 2);
    if ((0 < this->widthValue) && (0 < this->heightValue)) {
        rge_write(handle, this->visible_map, this->widthValue * this->heightValue);
    }
}

// VA: 0053C490 RGE_Visible_Map::get_visible
// PDB source: visible.cpp lines 361-382.
unsigned char RGE_Visible_Map::get_visible(int x, int y) const {
    unsigned long cell = unified_map_offsets[y][x];
    RGE_Player* p = this->player;
    if ((cell & p->mutualVisibleMask) != 0) return 0x0F;
    if ((cell & p->mutualExploredMask) != 0) return 0x80;
    return 0;
}

// VA: 0053C4D0 RGE_Visible_Map::set_all
// PDB source: visible.cpp lines 389-436.
void RGE_Visible_Map::set_all(unsigned char value) {
    log_map_call(this->world->world_time, (int)this->player->id, 5, 0,
                 (unsigned int)value, 0, 0, 0, 0);

    int y = 0;
    if (0 < this->heightValue) {
        do {
            int x = 0;
            if (0 < this->widthValue) {
                do {
                    this->map_offsets[y][x] = value;
                    x = x + 1;
                } while (x < this->widthValue);
            }
            y = y + 1;
        } while (y < this->heightValue);
    }

    if ((value == 0xff) || (value == 0)) {
        unsigned long mask = this->PlayerVisibleMaskInvertValue;
        if (value == 0xff) {
            mask = mask & this->PlayerExploredMaskInvertValue;
        }

        y = 0;
        if (0 < this->heightValue) {
            unsigned long** offsets = unified_map_offsets;
            do {
                int x = 0;
                if (0 < this->widthValue) {
                    do {
                        (*offsets)[x] = (*offsets)[x] & mask;
                        x = x + 1;
                    } while (x < this->widthValue);
                }
                y = y + 1;
                offsets = offsets + 1;
            } while (y < this->heightValue);
        }
    } else {
        unsigned long mask = this->PlayerExploredMaskValue;
        mask = mask | this->PlayerVisibleMaskValue;
        y = 0;
        if (0 < this->heightValue) {
            unsigned long** offsets = unified_map_offsets;
            do {
                int x = 0;
                if (0 < this->widthValue) {
                    do {
                        (*offsets)[x] = (*offsets)[x] | mask;
                        x = x + 1;
                    } while (x < this->widthValue);
                }
                y = y + 1;
                offsets = offsets + 1;
            } while (y < this->heightValue);
        }
    }

    if (value == 0xff) {
        this->numberTilesExploredValue = 0;
    } else {
        this->numberTilesExploredValue = this->numberTotalTilesValue;
    }
}

// VA: 0053C5D0 RGE_Visible_Map::explore_all
// PDB source: visible.cpp lines 442-467.
void RGE_Visible_Map::explore_all(void) {
    log_map_call(this->world->world_time, (int)this->player->id, 6, 0, 0, 0, 0, 0, 0);

    int y = 0;
    if (this->heightValue > 0) {
        do {
            int x = 0;
            if (this->widthValue > 0) {
                do {
                    unsigned char* row = this->map_offsets[y];
                    if (row[x] == 0xFF) {
                        row[x] = 0;
                        this->numberTilesExploredValue++;
                        unsigned long* explored = unified_map_offsets[y];
                        explored[x] |= this->PlayerExploredMaskValue;
                        this->player->tile_list.add_node(x, y);
                    }
                    x++;
                } while (x < this->widthValue);
            }
            y++;
        } while (y < this->heightValue);
    }
    this->player->tile_list.collapse_list = 1;
}

// VA: 0053C670 RGE_Visible_Map::percentExplored
// PDB source: visible.cpp lines 474-476.
float RGE_Visible_Map::percentExplored(void) const {
    return (float)this->numberTilesExploredValue /
           this->numberTotalTilesValue;
}

// VA: 0053C680 RGE_Visible_Map::recomputeExplored
// PDB source: visible.cpp lines 483-497.
void RGE_Visible_Map::recomputeExplored(void) {
    int y;
    int x;

    y = 0;
    this->numberTilesExploredValue = 0;
    if (this->heightValue > y) {
        do {
            x = 0;
            if (this->widthValue > 0) {
                unsigned char** row_ptr = this->map_offsets + y;
                do {
                    if (row_ptr[0][x] != 0xFF) {
                        this->numberTilesExploredValue = this->numberTilesExploredValue + 1;
                    }
                    x = x + 1;
                } while (x < this->widthValue);
            }
            y = y + 1;
        } while (y < this->heightValue);
    }
}

// VA: 0053C6C0 RGE_Visible_Map::get_los_table
// PDB source: visible.cpp lines 504-514.
LOSTBL* RGE_Visible_Map::get_los_table(int distance, int diagonal) {
    if (distance > 0x10) {
        distance = 0x10;
    }
    if (distance < 0) {
        distance = 0;
    }
    if (diagonal != 0) {
        return SquareLOS[distance];
    }
    return NormalLOS[distance];
}

// VA: 0053C6F0 RGE_Visible_Map::explore_terrain
// PDB source: visible.cpp lines 521-658.
int RGE_Visible_Map::explore_terrain(int x, int y, int radius, int square,
                                     int update_tiles, int p6) {
    int Revealed;
    int checksum;
    int radius_value;
    RGE_Player* curPlayer;
    int VisibleToCurPlayer;
    RGE_Player* curVisPlayer;
    LOSTBL* offsets;
    int offY;
    int y2;
    int x1;
    int x2;
    unsigned char* vis;
    unsigned long* unified;
    RGE_Tile* tile;
    unsigned char v;

    Revealed = 0;
    log_map_call(this->world->world_time, this->player->id, 1, p6,
                 x, y, radius, square, Map_Update_Suppresion);
    if (Map_Update_Suppresion != 0) {
        return 0;
    }

    p6 = this->input_csum;
    checksum = (int)this->player->id;
    p6 = _rotl(p6, 3);
    p6 ^= 0x01010101;
    p6 = _rotl(p6, 2);
    p6 ^= checksum;
    p6 = _rotl(p6, 3);
    p6 ^= x;
    p6 = _rotl(p6, 4);
    p6 ^= y;
    p6 = _rotl(p6, 3);
    p6 ^= radius;
    p6 += square;
    this->input_csum = p6;

    curPlayer = this->world->players[this->world->curr_player];
    if (curPlayer != 0) {
        VisibleToCurPlayer =
            (curPlayer->mutualAlly[this->player->id] == 1);
    } else {
        VisibleToCurPlayer = 0;
    }

    tile = 0;
    curVisPlayer = 0;
    if (VisibleToCurPlayer) {
        curVisPlayer = curPlayer;
    }

    radius_value = radius;
    if (radius_value > 0x10) {
        radius_value = 0x10;
    }

    if (square != 0) {
        offsets = SquareLOS[radius_value];
    } else {
        offsets = NormalLOS[radius_value];
    }

    offY = offsets->y;
    while (offY != 999) {
        y2 = y + offY;
        if ((y2 >= 0) && (y2 < this->heightValue)) {
            x1 = x + offsets->x1;
            if (x1 < 0) {
                x1 = 0;
            }
            x2 = x + offsets->x2;
            if (x2 >= this->widthValue) {
                x2 = this->widthValue - 1;
            }

            vis = this->map_offsets[y2] + x1;
            unified = unified_map_offsets[y2] + x1;
            if (update_tiles != 0) {
                tile = this->map->map_row_offset[y2] + x1;
            }

            while (x1 <= x2) {
                v = (unsigned char)(*vis + 1);
                if (v == 0) {
                    Revealed++;
                    this->numberTilesExploredValue++;
                    this->player->tile_list.add_node(x1, y2);
                    if (VisibleToCurPlayer) {
                        curVisPlayer->diam_tile_list.add_node(x1, y2);
                    }
                    v = 1;
                    *unified |= this->PlayerExploredMaskValue;
                }
                if (v == 1) {
                    if (update_tiles != 0) {
                        tile->last_drawn_shape2 = 0x0F;
                    }
                    *unified |= this->PlayerVisibleMaskValue;
                }
                if (v == 0xFA) {
                    v = 0xF9;
                }
                *vis = v;
                ++vis;
                ++unified;
                x1++;
                ++tile;
            }
        }
        ++offsets;
        offY = offsets->y;
    }
    return Revealed;
}

// VA: 0053C920 RGE_Visible_Map::unexplore_terrain
// PDB source: visible.cpp lines 665-767.
void RGE_Visible_Map::unexplore_terrain(int x, int y, int radius, int square,
                                        int update_tiles, int p6) {
    RGE_Tile* tile = 0;
    int plNum;

    log_map_call(this->world->world_time, (int)this->player->id, 3, p6,
                 x, y, radius, square, Map_Update_Suppresion);

    if (Map_Update_Suppresion == 0) {
        p6 = this->input_csum;
        plNum = (int)this->player->id;
        p6 = _rotl(p6, 3);
        p6 ^= 0x20202020;
        p6 = _rotl(p6, 2);
        p6 ^= plNum;
        p6 = _rotl(p6, 3);
        p6 ^= x;
        p6 = _rotl(p6, 4);
        p6 ^= y;
        p6 = _rotl(p6, 3);
        p6 ^= radius;
        p6 += square;
        this->input_csum = p6;

        if (radius > 0x10) {
            radius = 0x10;
        }

        LOSTBL* offsets;
        if (square != 0) {
            offsets = SquareLOS[radius];
        } else {
            offsets = NormalLOS[radius];
        }

        int off_y = offsets->y;
        while (off_y != 999) {
            off_y += y;
            if ((off_y >= 0) && (off_y < this->heightValue)) {
                int x1 = offsets->x1 + x;
                if (x1 < 0) {
                    x1 = 0;
                }
                int x2 = offsets->x2 + x;
                if (x2 >= this->widthValue) {
                    x2 = this->widthValue - 1;
                }

                unsigned char* visible = this->map_offsets[off_y] + x1;
                unsigned long* explored = unified_map_offsets[off_y] + x1;
                if (update_tiles != 0) {
                    tile = this->map->map_row_offset[off_y] + x1;
                }

                if (x1 <= x2) {
                    int count = x2 - x1 + 1;
                    do {
                        unsigned char value = *visible;
                        --value;
                        if (value == 0xff) {
                            value = 0;
                        }
                        if (value == 0) {
                            if (update_tiles != 0) {
                                tile->last_drawn_shape2 = 0x80;
                            }
                            *explored &= this->PlayerVisibleMaskInvertValue;
                        }
                        *visible = value;
                        ++visible;
                        ++explored;
                        ++tile;
                        --count;
                    } while (count != 0);
                }
            }

            ++offsets;
            off_y = offsets->y;
        }
    }
}

// VA: 0053CAC0 RGE_Visible_Map::explore_terrain_sq
// PDB source: visible.cpp lines 775-883.
int RGE_Visible_Map::explore_terrain_sq(int x1, int y1, int x2, int y2,
                                        int update_tiles, int p6) {
    unsigned char* p;
    unsigned long* unified;
    int Revealed;
    RGE_Player* curVisPlayer;
    int isCurPlayer;
    unsigned long checksum;
    RGE_Tile* tile;

    Revealed = 0;
    log_map_call(this->world->world_time, (int)this->player->id, 2, p6,
                 x1, y1, x2, y2, Map_Update_Suppresion);

    if (Map_Update_Suppresion != 0) {
        return 0;
    }

    isCurPlayer =
        (this->world->players[this->world->curr_player]->
             mutualAlly[this->player->id] == 1);
    p6 = 0;
    curVisPlayer = 0;
    tile = 0;

    checksum = this->input_csum;
    checksum = _rotl(checksum, 3);
    checksum ^= 0x34343434;
    checksum = _rotl(checksum, 2);
    checksum ^= x1;
    checksum = _rotl(checksum, 4);
    checksum ^= y1;
    checksum = _rotl(checksum, 3);
    checksum ^= x2;
    checksum = _rotl(checksum, 3);
    checksum ^= y2;
    this->input_csum = checksum;

    if (isCurPlayer) {
        curVisPlayer =
            this->world->players[this->world->curr_player];
    }

    int width = this->widthValue;
    int height = this->heightValue;

    if ((x1 >= width) || (x2 < 0)) {
        return 0;
    }
    if (y1 >= height) {
        return 0;
    }
    if (y2 < 0) {
        return 0;
    }
    if (x1 < 0) {
        x1 = 0;
    }
    if (x2 >= width) {
        x2 = width - 1;
    }
    if (y1 < 0) {
        y1 = 0;
    }
    if (y2 >= height) {
        y2 = height - 1;
    }

    for (; y1 <= y2; ++y1) {
        p = this->map_offsets[y1] + x1;
        unified = unified_map_offsets[y1] + x1;
        int x = x1;
        if (update_tiles != 0) {
            tile = this->map->map_row_offset[y1] + x1;
        }

        while (x <= x2) {
            unsigned char value = *p;
            ++value;
            if (value == 0) {
                ++Revealed;
                ++this->numberTilesExploredValue;
                this->player->tile_list.add_node(x, y1);
                if (isCurPlayer) {
                    curVisPlayer->diam_tile_list.add_node(x, y1);
                }
                *unified |= this->PlayerExploredMaskValue;
                value = 1;
            }
            if (value == 1) {
                if (update_tiles != 0) {
                    tile->last_drawn_shape2 = 0x0F;
                }
                *unified |= this->PlayerVisibleMaskValue;
            }
            if (value == 0xFA) {
                value = 0xF9;
            }
            *p = value;
            ++p;
            ++unified;
            ++x;
            ++tile;
        }
    }
    return Revealed;
}

// VA: 0053CCF0 RGE_Visible_Map::unexplore_terrain_sq
// PDB source: visible.cpp lines 891-975.
void RGE_Visible_Map::unexplore_terrain_sq(int x1, int y1, int x2, int y2,
                                           int update_tiles, int p6) {
    RGE_Visible_Map* self = this;
    RGE_Tile* tile = 0;

    log_map_call(self->world->world_time, (int)self->player->id, 4, p6,
                 x1, y1, x2, y2, Map_Update_Suppresion);

    if (Map_Update_Suppresion == 0) {
        p6 = self->input_csum;
        p6 = _rotl(p6, 3);
        p6 ^= 0x56565656;
        p6 = _rotl(p6, 2);
        p6 ^= x1;
        p6 = _rotl(p6, 4);
        p6 ^= y1;
        p6 = _rotl(p6, 3);
        p6 ^= x2;
        p6 = _rotl(p6, 3);
        p6 ^= y2;
        self->input_csum = p6;

        if ((x1 >= self->widthValue) || (x2 < 0) ||
            (y1 >= self->heightValue) || (y2 < 0)) {
            return;
        }
        if (x1 < 0) {
            x1 = 0;
        }
        if (x2 >= self->widthValue) {
            x2 = self->widthValue - 1;
        }
        if (y1 < 0) {
            y1 = 0;
        }
        if (y2 >= self->heightValue) {
            y2 = self->heightValue - 1;
        }

        for (; y1 <= y2; ++y1) {
            unsigned char* visible = self->map_offsets[y1] + x1;
            unsigned long* explored = unified_map_offsets[y1] + x1;

            if (update_tiles != 0) {
                tile = self->map->map_row_offset[y1] + x1;
            }

            if (x1 <= x2) {
                int count = x2 - x1 + 1;
                do {
                    unsigned char value = *visible;
                    --value;
                    if (value == 0xff) {
                        value = 0;
                    }
                    if (value == 0) {
                        if (update_tiles != 0) {
                            tile->last_drawn_shape2 = 0x80;
                        }
                        *explored &= self->PlayerVisibleMaskInvertValue;
                    }
                    *visible = value;
                    ++visible;
                    ++explored;
                    ++tile;
                    --count;
                } while (count != 0);
            }
        }
    }
}

// VA: 0053CE70 RGE_Visible_Map::checksum_visible_inputs
// PDB source: visible.cpp lines 983-990.
unsigned long RGE_Visible_Map::checksum_visible_inputs() {
    unsigned long v = this->input_csum;
    this->input_csum = 0;
    return v;
}

// VA: 0053CE80 RGE_Unified_Visible_Map::RGE_Unified_Visible_Map
// PDB source: visible.cpp lines 1005-1026.
RGE_Unified_Visible_Map::RGE_Unified_Visible_Map(int mapWidth, int mapHeight) {
    this->mapWidth = mapWidth;
    this->mapHeight = mapHeight;
    Map_Update_Suppresion = 0;
    if ((0 < this->mapHeight) && (0 < this->mapWidth)) {
        this->UnifiedVisibleMap = (unsigned long*)calloc(this->mapWidth * this->mapHeight, 4);
        Set_Map_Offsets();
    } else {
        this->UnifiedVisibleMap = 0;
        this->mapWidth = 0;
        this->mapHeight = 0;
        Set_Map_Offsets();
    }
}

// VA: 0053CEE0 RGE_Unified_Visible_Map::RGE_Unified_Visible_Map
// PDB source: visible.cpp lines 1032-1042.
RGE_Unified_Visible_Map::RGE_Unified_Visible_Map(int map, RGE_Game_World* world) {
    this->UnifiedVisibleMap = 0;
    this->mapWidth = 0;
    this->mapHeight = 0;
    Map_Update_Suppresion = 0;
    load(map);
    Set_Map_Offsets();
}

// VA: 0053CF10 RGE_Unified_Visible_Map::load
// PDB source: visible.cpp lines 1046-1074.
void RGE_Unified_Visible_Map::load(int handle) {
    int oldH = this->mapHeight;
    int oldW = this->mapWidth;

    rge_read(handle, this, 4);
    rge_read(handle, &this->mapHeight, 4);
    if ((0 < this->mapHeight) && (0 < this->mapWidth)) {
        if ((oldW != this->mapWidth) || (oldH != this->mapHeight)) {
            if (this->UnifiedVisibleMap != 0) {
                free(this->UnifiedVisibleMap);
            }
            this->UnifiedVisibleMap = (unsigned long*)calloc(this->mapHeight * this->mapWidth, 4);
        }
        rge_read(handle, this->UnifiedVisibleMap, this->mapHeight * this->mapWidth * 4);
        return;
    }
    this->mapHeight = 0;
    this->UnifiedVisibleMap = 0;
    this->mapWidth = 0;
}

// VA: 0053CFC0 RGE_Unified_Visible_Map::~RGE_Unified_Visible_Map
// PDB source: visible.cpp lines 1079-1084.
RGE_Unified_Visible_Map::~RGE_Unified_Visible_Map() {
    this->mapHeight = 0;
    Set_Map_Offsets();
    if (this->UnifiedVisibleMap != 0) {
        free(this->UnifiedVisibleMap);
    }
}

// VA: 0053CFF0 RGE_Unified_Visible_Map::save
// PDB source: visible.cpp lines 1088-1095.
void RGE_Unified_Visible_Map::save(int handle) {
    rge_write(handle, this, 4);
    rge_write(handle, &this->mapHeight, 4);
    if ((this->mapHeight > 0) && (this->mapWidth > 0)) {
        rge_write(handle, this->UnifiedVisibleMap, this->mapWidth * this->mapHeight * 4);
    }
}

// VA: 0053D040 RGE_Unified_Visible_Map::reset
// PDB source: visible.cpp lines 1099-1106.
void RGE_Unified_Visible_Map::reset(void) {
    if (this->UnifiedVisibleMap != 0) {
        memset(this->UnifiedVisibleMap, 0, this->mapWidth * this->mapHeight * 4);
    }
}

// VA: 0053D070 RGE_Unified_Visible_Map::Set_Map_Offsets
// PDB source: visible.cpp lines 1111-1119.
void RGE_Unified_Visible_Map::Set_Map_Offsets(void) {
    int y = 0;
    if (this->mapHeight > 0) {
        unsigned long** row = unified_map_offsets;
        do {
            *row = this->UnifiedVisibleMap + this->mapWidth * y;
            y++;
            row++;
        } while (y < this->mapHeight);
    }

    int height = this->mapHeight;
    for (; height < 256; height++) {
        unified_map_offsets[height] = 0;
    }
}

// VA: 0053D0C0 RGE_Unified_Visible_Map::suppress_updates
// PDB source: visible.cpp lines 1123-1125.
void RGE_Unified_Visible_Map::suppress_updates(int val) {
    Map_Update_Suppresion = val;
}

// VA: 0053D0D0 RGE_Visible_Map::checksumVisible
// PDB source: visible.cpp lines 1132-1140.
long RGE_Visible_Map::checksumVisible(void) {
    unsigned int value = 0;
    int y = 0;

    if (this->heightValue > 0) {
        do {
            int x = 0;
            if (this->widthValue > 0) {
                unsigned char* row = this->map_offsets[y];
                do {
                    value ^= x[row];
                    x++;
                } while (x < this->widthValue);
            }
            y++;
        } while (y < this->heightValue);
    }
    return value;
}

// VA: 0053D110 RGE_Visible_Map::checksumUnifiedVisible
// PDB source: visible.cpp lines 1146-1154.
unsigned long RGE_Visible_Map::checksumUnifiedVisible(void) {
    unsigned long value;

    value = 0;
    if (this->heightValue > 0) {
        unsigned long** offsets;
        int height;

        offsets = unified_map_offsets;
        height = this->heightValue;
        do {
            if (this->widthValue > 0) {
                unsigned long* row;
                int width;

                row = *offsets;
                width = this->widthValue;
                do {
                    value ^= *row;
                    row = row + 1;
                    width = width - 1;
                } while (width != 0);
            }
            offsets = offsets + 1;
            height = height - 1;
        } while (height != 0);
    }
    return value;
}

// VA: 0053D150 log_map_call
// PDB source: visible.cpp lines 1162-1196.
void __cdecl log_map_call(int param_1, int param_2, int param_3, int param_4,
                          int param_5, int param_6, int param_7, int param_8,
                          int param_9) {
    int idx = VCALL_LOG_HEAD + 1;
    if (idx >= 0x400) {
        idx = 0;
        VCALL_LOG_TAIL = 1;
    } else if (VCALL_LOG_TAIL >= 0) {
        VCALL_LOG_TAIL = idx + 1;
        if (VCALL_LOG_TAIL >= 0x400) {
            VCALL_LOG_TAIL = 0;
        }
    }
    VCALL_LOG_HEAD = idx;
    VCALL_LOG[idx].world_time = param_1;
    VCALL_LOG[idx].player_id = param_2;
    VCALL_LOG[idx].action = param_3;
    VCALL_LOG[idx].object_id = param_4;
    VCALL_LOG[idx].x1 = param_5;
    VCALL_LOG[idx].y1 = param_6;
    VCALL_LOG[idx].x2 = param_7;
    VCALL_LOG[idx].y2 = param_8;
    VCALL_LOG[idx].supress = param_9;
}

// VA: 0053D200 dump_vismap_log
// PDB source: visible.cpp lines 1199-1249.
void __cdecl dump_vismap_log() {
    int done = 0;
    FILE* f = fopen("c:\\aoeexlog.txt", "w");

    if (VCALL_LOG_HEAD < 0) {
        fprintf(f, "NULL LOG\n");
        fclose(f);
        return;
    }

    int idx = VCALL_LOG_TAIL;
    if (idx < 0) {
        idx = 0;
    }

    do {
        int action = VCALL_LOG[idx].action;

        switch (action) {
        case 1:
            fprintf(f, "EXPLORE     ");
            break;
        case 2:
            fprintf(f, "EXPLORE SQ  ");
            break;
        case 3:
            fprintf(f, "UNEXPLORE   ");
            break;
        case 4:
            fprintf(f, "UNEXPLORE SQ");
            break;
        case 5:
            fprintf(f, "SET ALL     ");
            break;
        case 6:
            fprintf(f, "EXPLORE ALL ");
            break;
        default:
            fprintf(f, "*ERROR* Undef Action = %d ", action);
            break;
        }

        fprintf(f,
            " wt = %d, plyr = %d, id = %d, x1=%d, y1=%d, x2=%d, y2=%d, wt=%d",
            VCALL_LOG[idx].world_time,
            VCALL_LOG[idx].player_id,
            VCALL_LOG[idx].object_id,
            VCALL_LOG[idx].x1,
            VCALL_LOG[idx].y1,
            VCALL_LOG[idx].x2,
            VCALL_LOG[idx].y2,
            VCALL_LOG[idx].supress);

        if (idx == VCALL_LOG_HEAD) {
            done = 1;
        }

        idx++;
        if (idx >= 0x400) {
            idx = 0;
        }
    } while (!done);

    fclose(f);
}
