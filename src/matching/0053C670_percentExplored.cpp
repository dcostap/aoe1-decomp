#include "../visible_tu_context.h"

float RGE_Visible_Map::percentExplored(void) const {
    return (float)this->numberTilesExploredValue /
           this->numberTotalTilesValue;
}
