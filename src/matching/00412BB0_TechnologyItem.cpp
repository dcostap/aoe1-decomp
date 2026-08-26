#include <string.h>

#include "../../include/aitchitm_context.h"

extern char s_592A40[];

TechnologyItem::TechnologyItem()
    : next(0), prev(0), idValue(0), resourceCostValue(0) {
    strcpy(this->nameValue, s_592A40);
}
