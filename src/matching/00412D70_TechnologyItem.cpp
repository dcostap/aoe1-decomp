#include "../../include/aitchitm_context.h"

TechnologyItem::~TechnologyItem() {
    if (this->resourceCostValue != 0) {
        delete this->resourceCostValue;
    }
}
