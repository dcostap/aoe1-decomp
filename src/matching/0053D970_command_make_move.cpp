// VA: 0053D970 RGE_Diamond_Map_View::command_make_move
// PDB: vw_dimap.cpp lines 301-316

#ifndef VW_DIMAP_SHARED_CONTEXT
#include "../../include/vw_dimap_tu_context.h"
#endif

// BINARY NOTE: player command_make_move is slot +0xA0; cleanup uses base slot +0x10.
extern int allow_user_commands;
extern float FLOAT_005777e8;
int RGE_Diamond_Map_View::command_make_move(long a1, long a2) {
    int result;
    short col;
    short row;
    RGE_Tile* tile;
    if (allow_user_commands == 0) return 0;
    result = 0;
    if (this->pick_tile(a1, a2, &col, &row, &tile) != 0) {
        float x = (float)row - FLOAT_005777e8;
        float y = (float)col - FLOAT_005777e8;
        result = this->player->command_make_move(0, y, x) & 0xff;
    }
    rge_base_game->set_game_mode(0, 0);
    return result;
}
