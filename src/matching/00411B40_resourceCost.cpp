#include "../../include/airchmod_context.h"

ResourceItem* ResearchAIModule::resourceCost(int id) {
    TechnologyItem* tech = this->item(id);
    if (tech == 0) {
        return 0;
    }
    return tech->resourceCost();
}
