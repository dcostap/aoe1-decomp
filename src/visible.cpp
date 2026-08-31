
#include "../include/visible.h"
#include "../include/map.h"
#include "../include/player.h"
#include "../include/world.h"
#include "../include/game_globals.h"
#include <stdio.h>
#include <string.h>

// Their source data is static. The terminator row is part of each table.
LOSTBL Edge_Offsets_N0[2] = {{0, 0, 0}, {999, 0, 0}};
LOSTBL Edge_Offsets_N1[4] = {{-1, -1, 1}, {0, -1, 1}, {1, -1, 1}, {999, 0, 0}};
LOSTBL Edge_Offsets_N2[6] = {{-2, -1, 1}, {-1, -2, 2}, {0, -2, 2}, {1, -2, 2}, {2, -1, 1}, {999, 0, 0}};
LOSTBL Edge_Offsets_N3[8] = {{-3, -1, 1}, {-2, -2, 2}, {-1, -3, 3}, {0, -3, 3}, {1, -3, 3}, {2, -2, 2}, {3, -1, 1}, {999, 0, 0}};
LOSTBL Edge_Offsets_N4[10] = {{-4, -1, 1}, {-3, -3, 3}, {-2, -3, 3}, {-1, -4, 4}, {0, -4, 4}, {1, -4, 4}, {2, -3, 3}, {3, -3, 3}, {4, -1, 1}, {999, 0, 0}};
LOSTBL Edge_Offsets_N5[12] = {{-5, -2, 2}, {-4, -3, 3}, {-3, -4, 4}, {-2, -5, 5}, {-1, -5, 5}, {0, -5, 5}, {1, -5, 5}, {2, -5, 5}, {3, -4, 4}, {4, -3, 3}, {5, -2, 2}, {999, 0, 0}};
LOSTBL Edge_Offsets_N6[14] = {{-6, -2, 2}, {-5, -4, 4}, {-4, -5, 5}, {-3, -5, 5}, {-2, -6, 6}, {-1, -6, 6}, {0, -6, 6}, {1, -6, 6}, {2, -6, 6}, {3, -5, 5}, {4, -5, 5}, {5, -4, 4}, {6, -2, 2}, {999, 0, 0}};
LOSTBL Edge_Offsets_N7[16] = {{-7, -2, 2}, {-6, -4, 4}, {-5, -5, 5}, {-4, -6, 6}, {-3, -6, 6}, {-2, -7, 7}, {-1, -7, 7}, {0, -7, 7}, {1, -7, 7}, {2, -7, 7}, {3, -6, 6}, {4, -6, 6}, {5, -5, 5}, {6, -4, 4}, {7, -2, 2}, {999, 0, 0}};
LOSTBL Edge_Offsets_N8[18] = {{-8, -2, 2}, {-7, -4, 4}, {-6, -5, 5}, {-5, -6, 6}, {-4, -7, 7}, {-3, -7, 7}, {-2, -8, 8}, {-1, -8, 8}, {0, -8, 8}, {1, -8, 8}, {2, -8, 8}, {3, -7, 7}, {4, -7, 7}, {5, -6, 6}, {6, -5, 5}, {7, -4, 4}, {8, -2, 2}, {999, 0, 0}};
LOSTBL Edge_Offsets_N9[20] = {{-9, -2, 2}, {-8, -5, 5}, {-7, -6, 6}, {-6, -7, 7}, {-5, -8, 8}, {-4, -8, 8}, {-3, -8, 8}, {-2, -9, 9}, {-1, -9, 9}, {0, -9, 9}, {1, -9, 9}, {2, -9, 9}, {3, -8, 8}, {4, -8, 8}, {5, -8, 8}, {6, -7, 7}, {7, -6, 6}, {8, -5, 5}, {9, -2, 2}, {999, 0, 0}};
LOSTBL Edge_Offsets_N10[22] = {{-10, -3, 3}, {-9, -5, 5}, {-8, -6, 6}, {-7, -7, 7}, {-6, -8, 8}, {-5, -9, 9}, {-4, -9, 9}, {-3, -10, 10}, {-2, -10, 10}, {-1, -10, 10}, {0, -10, 10}, {1, -10, 10}, {2, -10, 10}, {3, -10, 10}, {4, -9, 9}, {5, -9, 9}, {6, -8, 8}, {7, -7, 7}, {8, -6, 6}, {9, -5, 5}, {10, -3, 3}, {999, 0, 0}};
LOSTBL Edge_Offsets_N11[24] = {{-11, -3, 3}, {-10, -5, 5}, {-9, -7, 7}, {-8, -8, 8}, {-7, -9, 9}, {-6, -9, 9}, {-5, -10, 10}, {-4, -10, 10}, {-3, -11, 11}, {-2, -11, 11}, {-1, -11, 11}, {0, -11, 11}, {1, -11, 11}, {2, -11, 11}, {3, -11, 11}, {4, -10, 10}, {5, -10, 10}, {6, -9, 9}, {7, -9, 9}, {8, -8, 8}, {9, -7, 7}, {10, -5, 5}, {11, -3, 3}, {999, 0, 0}};
LOSTBL Edge_Offsets_N12[26] = {{-12, -3, 3}, {-11, -5, 5}, {-10, -7, 7}, {-9, -8, 8}, {-8, -9, 9}, {-7, -10, 10}, {-6, -10, 10}, {-5, -11, 11}, {-4, -11, 11}, {-3, -12, 12}, {-2, -12, 12}, {-1, -12, 12}, {0, -12, 12}, {1, -12, 12}, {2, -12, 12}, {3, -12, 12}, {4, -11, 11}, {5, -11, 11}, {6, -10, 10}, {7, -10, 10}, {8, -9, 9}, {9, -8, 8}, {10, -7, 7}, {11, -5, 5}, {12, -3, 3}, {999, 0, 0}};
LOSTBL Edge_Offsets_N13[28] = {{-13, -3, 3}, {-12, -6, 6}, {-11, -7, 7}, {-10, -8, 8}, {-9, -9, 9}, {-8, -10, 10}, {-7, -11, 11}, {-6, -12, 12}, {-5, -12, 12}, {-4, -12, 12}, {-3, -13, 13}, {-2, -13, 13}, {-1, -13, 13}, {0, -13, 13}, {1, -13, 13}, {2, -13, 13}, {3, -13, 13}, {4, -12, 12}, {5, -12, 12}, {6, -12, 12}, {7, -11, 11}, {8, -10, 10}, {9, -9, 9}, {10, -8, 8}, {11, -7, 7}, {12, -6, 6}, {13, -3, 3}, {999, 0, 0}};
LOSTBL Edge_Offsets_N14[30] = {{-14, -3, 3}, {-13, -6, 6}, {-12, -8, 8}, {-11, -9, 9}, {-10, -10, 10}, {-9, -11, 11}, {-8, -12, 12}, {-7, -12, 12}, {-6, -13, 13}, {-5, -13, 13}, {-4, -13, 13}, {-3, -14, 14}, {-2, -14, 14}, {-1, -14, 14}, {0, -14, 14}, {1, -14, 14}, {2, -14, 14}, {3, -14, 14}, {4, -13, 13}, {5, -13, 13}, {6, -13, 13}, {7, -12, 12}, {8, -12, 12}, {9, -11, 11}, {10, -10, 10}, {11, -9, 9}, {12, -8, 8}, {13, -6, 6}, {14, -3, 3}, {999, 0, 0}};
LOSTBL Edge_Offsets_N15[32] = {{-15, -3, 3}, {-14, -6, 6}, {-13, -8, 8}, {-12, -9, 9}, {-11, -10, 10}, {-10, -11, 11}, {-9, -12, 12}, {-8, -13, 13}, {-7, -13, 13}, {-6, -14, 14}, {-5, -14, 14}, {-4, -14, 14}, {-3, -15, 15}, {-2, -15, 15}, {-1, -15, 15}, {0, -15, 15}, {1, -15, 15}, {2, -15, 15}, {3, -15, 15}, {4, -14, 14}, {5, -14, 14}, {6, -14, 14}, {7, -13, 13}, {8, -13, 13}, {9, -12, 12}, {10, -11, 11}, {11, -10, 10}, {12, -9, 9}, {13, -8, 8}, {14, -6, 6}, {15, -3, 3}, {999, 0, 0}};
LOSTBL Edge_Offsets_N16[34] = {{-16, -3, 3}, {-15, -6, 6}, {-14, -8, 8}, {-13, -10, 10}, {-12, -11, 11}, {-11, -12, 12}, {-10, -13, 13}, {-9, -13, 13}, {-8, -14, 14}, {-7, -14, 14}, {-6, -15, 15}, {-5, -15, 15}, {-4, -15, 15}, {-3, -16, 16}, {-2, -16, 16}, {-1, -16, 16}, {0, -16, 16}, {1, -16, 16}, {2, -16, 16}, {3, -16, 16}, {4, -15, 15}, {5, -15, 15}, {6, -15, 15}, {7, -14, 14}, {8, -14, 14}, {9, -13, 13}, {10, -13, 13}, {11, -12, 12}, {12, -11, 11}, {13, -10, 10}, {14, -8, 8}, {15, -6, 6}, {16, -3, 3}, {999, 0, 0}};
LOSTBL Edge_Offsets_T0[2] = {{0, 0, 0}, {999, 0, 0}};
LOSTBL Edge_Offsets_T1[3] = {{-1, -1, 0}, {0, -1, 0}, {999, 0, 0}};
LOSTBL Edge_Offsets_T2[5] = {{-2, -2, 1}, {-1, -2, 1}, {0, -2, 1}, {1, -2, 1}, {999, 0, 0}};
LOSTBL Edge_Offsets_T3[7] = {{-3, -2, 1}, {-2, -3, 2}, {-1, -3, 2}, {0, -3, 2}, {1, -3, 2}, {2, -2, 1}, {999, 0, 0}};
LOSTBL Edge_Offsets_T4[9] = {{-4, -2, 1}, {-3, -3, 2}, {-2, -4, 3}, {-1, -4, 3}, {0, -4, 3}, {1, -4, 3}, {2, -3, 2}, {3, -2, 1}, {999, 0, 0}};
LOSTBL Edge_Offsets_T5[11] = {{-5, -2, 1}, {-4, -4, 3}, {-3, -4, 3}, {-2, -5, 4}, {-1, -5, 4}, {0, -5, 4}, {1, -5, 4}, {2, -4, 3}, {3, -4, 3}, {4, -2, 1}, {999, 0, 0}};
LOSTBL Edge_Offsets_T6[13] = {{-6, -2, 1}, {-5, -4, 3}, {-4, -5, 4}, {-3, -5, 4}, {-2, -6, 5}, {-1, -6, 5}, {0, -6, 5}, {1, -6, 5}, {2, -5, 4}, {3, -5, 4}, {4, -4, 3}, {5, -2, 1}, {999, 0, 0}};
LOSTBL Edge_Offsets_T7[15] = {{-7, -2, 1}, {-6, -4, 3}, {-5, -5, 4}, {-4, -6, 5}, {-3, -6, 5}, {-2, -7, 6}, {-1, -7, 6}, {0, -7, 6}, {1, -7, 6}, {2, -6, 5}, {3, -6, 5}, {4, -5, 4}, {5, -4, 3}, {6, -2, 1}, {999, 0, 0}};
LOSTBL Edge_Offsets_T8[17] = {{-8, -3, 2}, {-7, -5, 4}, {-6, -6, 5}, {-5, -7, 6}, {-4, -7, 6}, {-3, -8, 7}, {-2, -8, 7}, {-1, -8, 7}, {0, -8, 7}, {1, -8, 7}, {2, -8, 7}, {3, -7, 6}, {4, -7, 6}, {5, -6, 5}, {6, -5, 4}, {7, -3, 2}, {999, 0, 0}};
LOSTBL Edge_Offsets_T9[19] = {{-9, -3, 2}, {-8, -5, 4}, {-7, -6, 5}, {-6, -7, 6}, {-5, -8, 7}, {-4, -8, 7}, {-3, -9, 8}, {-2, -9, 8}, {-1, -9, 8}, {0, -9, 8}, {1, -9, 8}, {2, -9, 8}, {3, -8, 7}, {4, -8, 7}, {5, -7, 6}, {6, -6, 5}, {7, -5, 4}, {8, -3, 2}, {999, 0, 0}};
LOSTBL Edge_Offsets_T10[21] = {{-10, -3, 2}, {-9, -5, 4}, {-8, -7, 6}, {-7, -8, 7}, {-6, -8, 7}, {-5, -9, 8}, {-4, -9, 8}, {-3, -10, 9}, {-2, -10, 9}, {-1, -10, 9}, {0, -10, 9}, {1, -10, 9}, {2, -10, 9}, {3, -9, 8}, {4, -9, 8}, {5, -8, 7}, {6, -8, 7}, {7, -7, 6}, {8, -5, 4}, {9, -3, 2}, {999, 0, 0}};
LOSTBL Edge_Offsets_T11[23] = {{-11, -3, 2}, {-10, -5, 4}, {-9, -7, 6}, {-8, -8, 7}, {-7, -9, 8}, {-6, -9, 8}, {-5, -10, 9}, {-4, -10, 9}, {-3, -11, 10}, {-2, -11, 10}, {-1, -11, 10}, {0, -11, 10}, {1, -11, 10}, {2, -11, 10}, {3, -10, 9}, {4, -10, 9}, {5, -9, 8}, {6, -9, 8}, {7, -8, 7}, {8, -7, 6}, {9, -5, 4}, {10, -3, 2}, {999, 0, 0}};
LOSTBL Edge_Offsets_T12[25] = {{-12, -3, 2}, {-11, -6, 5}, {-10, -7, 6}, {-9, -8, 7}, {-8, -9, 8}, {-7, -10, 9}, {-6, -11, 10}, {-5, -11, 10}, {-4, -11, 10}, {-3, -12, 11}, {-2, -12, 11}, {-1, -12, 11}, {0, -12, 11}, {1, -12, 11}, {2, -12, 11}, {3, -11, 10}, {4, -11, 10}, {5, -11, 10}, {6, -10, 9}, {7, -9, 8}, {8, -8, 7}, {9, -7, 6}, {10, -6, 5}, {11, -3, 2}, {999, 0, 0}};
LOSTBL Edge_Offsets_T13[27] = {{-13, -3, 2}, {-12, -6, 5}, {-11, -8, 7}, {-10, -9, 8}, {-9, -10, 9}, {-8, -11, 10}, {-7, -11, 10}, {-6, -12, 11}, {-5, -12, 11}, {-4, -12, 11}, {-3, -13, 12}, {-2, -13, 12}, {-1, -13, 12}, {0, -13, 12}, {1, -13, 12}, {2, -13, 12}, {3, -12, 11}, {4, -12, 11}, {5, -12, 11}, {6, -11, 10}, {7, -11, 10}, {8, -10, 9}, {9, -9, 8}, {10, -8, 7}, {11, -6, 5}, {12, -3, 2}, {999, 0, 0}};
LOSTBL Edge_Offsets_T14[29] = {{-14, -4, 3}, {-13, -6, 5}, {-12, -8, 7}, {-11, -9, 8}, {-10, -10, 9}, {-9, -11, 10}, {-8, -12, 11}, {-7, -12, 11}, {-6, -13, 12}, {-5, -13, 12}, {-4, -14, 13}, {-3, -14, 13}, {-2, -14, 13}, {-1, -14, 13}, {0, -14, 13}, {1, -14, 13}, {2, -14, 13}, {3, -14, 13}, {4, -13, 12}, {5, -13, 12}, {6, -12, 11}, {7, -12, 11}, {8, -11, 10}, {9, -10, 9}, {10, -9, 8}, {11, -8, 7}, {12, -6, 5}, {13, -4, 3}, {999, 0, 0}};
LOSTBL Edge_Offsets_T15[31] = {{-15, -4, 3}, {-14, -6, 5}, {-13, -8, 7}, {-12, -10, 9}, {-11, -11, 10}, {-10, -12, 11}, {-9, -12, 11}, {-8, -13, 12}, {-7, -13, 12}, {-6, -14, 13}, {-5, -14, 13}, {-4, -15, 14}, {-3, -15, 14}, {-2, -15, 14}, {-1, -15, 14}, {0, -15, 14}, {1, -15, 14}, {2, -15, 14}, {3, -15, 14}, {4, -14, 13}, {5, -14, 13}, {6, -13, 12}, {7, -13, 12}, {8, -12, 11}, {9, -12, 11}, {10, -11, 10}, {11, -10, 9}, {12, -8, 7}, {13, -6, 5}, {14, -4, 3}, {999, 0, 0}};
LOSTBL Edge_Offsets_T16[33] = {{-16, -4, 3}, {-15, -7, 6}, {-14, -8, 7}, {-13, -10, 9}, {-12, -11, 10}, {-11, -12, 11}, {-10, -13, 12}, {-9, -13, 12}, {-8, -14, 13}, {-7, -15, 14}, {-6, -15, 14}, {-5, -15, 14}, {-4, -16, 15}, {-3, -16, 15}, {-2, -16, 15}, {-1, -16, 15}, {0, -16, 15}, {1, -16, 15}, {2, -16, 15}, {3, -16, 15}, {4, -15, 14}, {5, -15, 14}, {6, -15, 14}, {7, -14, 13}, {8, -13, 12}, {9, -13, 12}, {10, -12, 11}, {11, -11, 10}, {12, -10, 9}, {13, -8, 7}, {14, -7, 6}, {15, -4, 3}, {999, 0, 0}};
LOSTBL* NormalLOS[17] = {Edge_Offsets_N0, Edge_Offsets_N1, Edge_Offsets_N2, Edge_Offsets_N3, Edge_Offsets_N4, Edge_Offsets_N5, Edge_Offsets_N6, Edge_Offsets_N7, Edge_Offsets_N8, Edge_Offsets_N9, Edge_Offsets_N10, Edge_Offsets_N11, Edge_Offsets_N12, Edge_Offsets_N13, Edge_Offsets_N14, Edge_Offsets_N15, Edge_Offsets_N16};
LOSTBL* SquareLOS[17] = {Edge_Offsets_T0, Edge_Offsets_T1, Edge_Offsets_T2, Edge_Offsets_T3, Edge_Offsets_T4, Edge_Offsets_T5, Edge_Offsets_T6, Edge_Offsets_T7, Edge_Offsets_T8, Edge_Offsets_T9, Edge_Offsets_T10, Edge_Offsets_T11, Edge_Offsets_T12, Edge_Offsets_T13, Edge_Offsets_T14, Edge_Offsets_T15, Edge_Offsets_T16};

#pragma intrinsic(_rotl)

extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);
extern "C" void __cdecl free(void* block);
extern "C" void __cdecl rge_write(int handle, void* buffer, int count);
extern "C" void __cdecl rge_read(int handle, void* buffer, int count);

extern void __cdecl log_map_call(int world_time, int player_id, int type,
                                 int p6, int x1, int y1, int x2, int y2,
                                 int suppression);

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

unsigned char RGE_Visible_Map::get_visible(int x, int y) const {
    unsigned long cell = unified_map_offsets[y][x];
    RGE_Player* p = this->player;
    if ((cell & p->mutualVisibleMask) != 0) return 0x0F;
    if ((cell & p->mutualExploredMask) != 0) return 0x80;
    return 0;
}

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

float RGE_Visible_Map::percentExplored(void) const {
    return (float)this->numberTilesExploredValue /
           this->numberTotalTilesValue;
}

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
                        tile->draw_as = 0x0F;
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
                                tile->draw_as = 0x80;
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
                            tile->draw_as = 0x80;
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

unsigned long RGE_Visible_Map::checksum_visible_inputs() {
    unsigned long v = this->input_csum;
    this->input_csum = 0;
    return v;
}

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

RGE_Unified_Visible_Map::RGE_Unified_Visible_Map(int map, RGE_Game_World* world) {
    this->UnifiedVisibleMap = 0;
    this->mapWidth = 0;
    this->mapHeight = 0;
    Map_Update_Suppresion = 0;
    load(map);
    Set_Map_Offsets();
}

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

RGE_Unified_Visible_Map::~RGE_Unified_Visible_Map() {
    this->mapHeight = 0;
    Set_Map_Offsets();
    if (this->UnifiedVisibleMap != 0) {
        free(this->UnifiedVisibleMap);
    }
}

void RGE_Unified_Visible_Map::save(int handle) {
    rge_write(handle, this, 4);
    rge_write(handle, &this->mapHeight, 4);
    if ((this->mapHeight > 0) && (this->mapWidth > 0)) {
        rge_write(handle, this->UnifiedVisibleMap, this->mapWidth * this->mapHeight * 4);
    }
}

void RGE_Unified_Visible_Map::reset(void) {
    if (this->UnifiedVisibleMap != 0) {
        memset(this->UnifiedVisibleMap, 0, this->mapWidth * this->mapHeight * 4);
    }
}

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

void RGE_Unified_Visible_Map::suppress_updates(int val) {
    Map_Update_Suppresion = val;
}

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
