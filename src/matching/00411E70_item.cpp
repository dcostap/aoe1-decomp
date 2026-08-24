#include "../../include/airchmod_context.h"

TechnologyItem* ResearchAIModule::item(int tech_id)
{
    TechnologyItem* item = this->techTree.next;
    TechnologyItem* end = &this->techTree;

    while (item != end) {
        if (item == 0)
            return 0;
        if (item->id() == tech_id)
            return item;
        item = item->next;
    }

    return 0;
}
