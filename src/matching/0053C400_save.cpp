#include "../../include/visible_context.h"

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
