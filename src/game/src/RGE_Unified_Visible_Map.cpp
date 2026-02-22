#include "../include/RGE_Unified_Visible_Map.h"
#include "../include/globals.h"

#include <stdlib.h>
#include <string.h>

void RGE_Unified_Visible_Map::Set_Map_Offsets() {
    // Source of truth: visible.cpp.decomp @ 0x0053D070
    int row = 0;
    if (this->mapHeight > 0) {
        for (; row < this->mapHeight && row < 0x100; ++row) {
            unified_map_offsets[row] = (this->UnifiedVisibleMap != nullptr) ? (this->UnifiedVisibleMap + (this->mapWidth * row)) : nullptr;
        }
    }
    for (; row < 0x100; ++row) {
        unified_map_offsets[row] = nullptr;
    }
}

void RGE_Unified_Visible_Map::load(int param_1) {
    // Fully verified. Source of truth: visible.cpp.decomp @ 0x0053CF10
    const int old_h = this->mapHeight;
    const int old_w = this->mapWidth;

    rge_read(param_1, &this->mapWidth, 4);
    rge_read(param_1, &this->mapHeight, 4);

    if (this->mapHeight > 0 && this->mapWidth > 0) {
        if (old_w != this->mapWidth || old_h != this->mapHeight) {
            if (this->UnifiedVisibleMap != nullptr) {
                free(this->UnifiedVisibleMap);
            }
            this->UnifiedVisibleMap = (ulong*)calloc((size_t)this->mapWidth * (size_t)this->mapHeight, 4);
        }
        if (this->UnifiedVisibleMap != nullptr) {
            rge_read(param_1, this->UnifiedVisibleMap, this->mapWidth * this->mapHeight * 4);
        }
        return;
    }

    if (this->UnifiedVisibleMap != nullptr) {
        free(this->UnifiedVisibleMap);
    }
    this->UnifiedVisibleMap = nullptr;
    this->mapHeight = 0;
    this->mapWidth = 0;
}

void RGE_Unified_Visible_Map::save(int param_1) {
    // Source of truth: visible.cpp.decomp @ 0x0053CFF0
    rge_write(param_1, &this->mapWidth, 4);
    rge_write(param_1, &this->mapHeight, 4);
    if (this->mapHeight > 0 && this->mapWidth > 0 && this->UnifiedVisibleMap != nullptr) {
        rge_write(param_1, this->UnifiedVisibleMap, this->mapWidth * this->mapHeight * 4);
    }
}

void RGE_Unified_Visible_Map::reset() {
    // Source of truth: visible.cpp.decomp @ 0x0053D040
    if (this->UnifiedVisibleMap != nullptr && this->mapHeight > 0 && this->mapWidth > 0) {
        memset(this->UnifiedVisibleMap, 0, (size_t)this->mapWidth * (size_t)this->mapHeight * sizeof(ulong));
    }
}

void RGE_Unified_Visible_Map::suppress_updates(int param_1) {
    // Source of truth: visible.cpp.decomp @ 0x0053D0C0
    Map_Update_Suppresion = param_1;
}

