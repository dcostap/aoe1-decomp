#include "../../include/aiblditm_context.h"

int BuildItem::terrainAdjacency(int index) const {
    if ((index >= 1) && (index <= 2)) {
        return terrainAdjacencyValue[index - 1];
    }
    return -1;
}
