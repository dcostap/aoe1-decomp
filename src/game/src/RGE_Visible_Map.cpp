#include "RGE_Visible_Map.h"

uchar RGE_Visible_Map::get_visible(int col, int row)
{
    if (col < 0 || col >= this->widthValue || row < 0 || row >= this->heightValue)
        return 0;
    if (this->map_offsets == nullptr)
        return 0xF; // Assume fully visible if no map
    return this->map_offsets[row][col];
}
