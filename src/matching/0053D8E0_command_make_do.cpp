// VA: 0053D8E0 RGE_Diamond_Map_View::command_make_do
// PDB: vw_dimap.cpp lines 281-295

#ifndef VW_DIMAP_SHARED_CONTEXT
#include "../../include/vw_dimap_tu_context.h"
#endif

// BINARY NOTE: the player command call is the virtual slot at +0xA8.
extern int allow_user_commands;
extern float FLOAT_005777e8;
int RGE_Diamond_Map_View::command_make_do(long a1, long a2) {
    int result;
    short col;
    short row;
    RGE_Tile* tile;
    if (allow_user_commands == 0) return 0;
    result = 0;
    if (this->pick_tile(a1, a2, &col, &row, &tile) != 0) {
        float x = (float)row - FLOAT_005777e8;
        float y = (float)col - FLOAT_005777e8;
        result = this->player->command_make_do(0, y, x) & 0xff;
    }
    return result;
}
