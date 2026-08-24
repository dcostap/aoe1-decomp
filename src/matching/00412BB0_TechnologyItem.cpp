#include <string.h>

#include "../../include/aitchitm_context.h"

extern char s_592A40[];

TechnologyItem::TechnologyItem() {
    this->next = 0;
    this->prev = 0;
    this->idValue = 0;
    this->resourceCostValue = 0;
    strcpy(this->nameValue, s_592A40);
}
