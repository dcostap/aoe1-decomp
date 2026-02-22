#include "../include/RGE_Visible_Map.h"

#include "../include/RGE_Map.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Game_World.h"
#include "../include/globals.h"

#include <stdlib.h>
#include <string.h>

RGE_Visible_Map::RGE_Visible_Map(RGE_Map* param_1, RGE_Player* param_2) {
    // Fully verified. Source of truth: visible.cpp.decomp @ 0x0053C1B0
    this->world = param_2->world;
    this->player = param_2;
    this->map = param_1;
    this->widthValue = param_1->map_width;
    this->heightValue = param_1->map_height;
    this->numberTilesExploredValue = 0;
    this->numberTotalTilesValue = this->heightValue * this->widthValue;

    if (this->widthValue < 1 || this->heightValue < 1) {
        this->visible_map = nullptr;
        this->map_offsets = nullptr;
    } else {
        this->visible_map = (uchar*)calloc(this->heightValue * this->widthValue, 1);
        this->map_offsets = (uchar**)calloc(this->heightValue, 4);
        for (int i = 0; i < this->heightValue; ++i) {
            this->map_offsets[i] = this->visible_map + i * this->widthValue;
        }
        memset(this->visible_map, 0xFF, (size_t)(this->heightValue * this->widthValue));
    }

    ulong visible_mask = 1UL << ((uchar)param_2->id & 0x1F);
    this->input_csum = 0;
    this->PlayerVisibleMaskValue = visible_mask;
    this->PlayerVisibleMaskInvertValue = ~visible_mask;
    this->PlayerExploredMaskValue = visible_mask << 16;
    this->PlayerExploredMaskInvertValue = ~(visible_mask << 16);
}

RGE_Visible_Map::RGE_Visible_Map(int param_1, RGE_Game_World* param_2) {
    // Fully verified. Source of truth: visible.cpp.decomp @ 0x0053C290
    this->world = param_2;
    this->map = param_2->map;
    this->numberTilesExploredValue = 0;

    rge_read(param_1, &this->widthValue, 4);
    rge_read(param_1, &this->heightValue, 4);
    if (save_game_version >= 6.7f) {
        rge_read(param_1, &this->numberTilesExploredValue, 4);
    }

    short player_id = 0;
    rge_read(param_1, &player_id, 2);

    this->numberTotalTilesValue = this->heightValue * this->widthValue;
    this->player = param_2->players[player_id];

    if (this->widthValue < 1 || this->heightValue < 1) {
        this->visible_map = nullptr;
        this->map_offsets = nullptr;
    } else {
        this->visible_map = (uchar*)calloc(this->numberTotalTilesValue, 1);
        this->map_offsets = (uchar**)calloc(this->heightValue, 4);
        for (int i = 0; i < this->heightValue; ++i) {
            this->map_offsets[i] = this->visible_map + i * this->widthValue;
        }
        rge_read(param_1, this->visible_map, this->numberTotalTilesValue);
    }

    ulong visible_mask = 1UL << ((uchar)player_id & 0x1F);
    this->input_csum = 0;
    this->PlayerVisibleMaskValue = visible_mask;
    this->PlayerExploredMaskValue = visible_mask << 16;
    this->PlayerExploredMaskInvertValue = ~(visible_mask << 16);
    this->PlayerVisibleMaskInvertValue = ~visible_mask;
}

RGE_Visible_Map::~RGE_Visible_Map() {
    // Fully verified. Source of truth: visible.cpp.decomp @ 0x0053C3C0
    if (this->visible_map != nullptr) {
        free(this->visible_map);
        this->visible_map = nullptr;
    }
    if (this->map_offsets != nullptr) {
        free(this->map_offsets);
        this->map_offsets = nullptr;
    }
    this->player = nullptr;
    this->map = nullptr;
}

void RGE_Visible_Map::save(int param_1) {
    // Fully verified. Source of truth: visible.cpp.decomp @ 0x0053C400
    rge_write(param_1, &this->widthValue, 4);
    rge_write(param_1, &this->heightValue, 4);
    if (save_game_version >= 6.7f) {
        rge_write(param_1, &this->numberTilesExploredValue, 4);
    }
    rge_write(param_1, &this->player->id, 2);
    if (this->widthValue > 0 && this->heightValue > 0) {
        rge_write(param_1, this->visible_map, this->heightValue * this->widthValue);
    }
}

uchar RGE_Visible_Map::get_visible(int col, int row) {
    // Source of truth: visible.cpp.decomp @ 0x0053C490
    if (this->player == nullptr || row < 0 || col < 0) {
        return 0;
    }
    if (row >= 0x100 || unified_map_offsets[row] == nullptr) {
        return 0;
    }

    ulong tile_mask = unified_map_offsets[row][col];
    if ((tile_mask & this->player->mutualVisibleMask) != 0) {
        return 0x0F;
    }
    return (uchar)(((this->player->mutualExploredMask & tile_mask) != 0) ? 0x80 : 0x00);
}

float RGE_Visible_Map::percentExplored() {
    // Fully verified. Source of truth: visible.cpp.decomp @ 0x0053C670
    if (this->numberTotalTilesValue == 0) {
        return 0.0f;
    }
    return (float)this->numberTilesExploredValue / (float)this->numberTotalTilesValue;
}
