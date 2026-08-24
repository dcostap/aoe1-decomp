#include "../../include/campaign_context.h"

RGE_Campaign::~RGE_Campaign() {
    if (this->scenario_offsets != 0) {
        free(this->scenario_offsets);
        this->scenario_offsets = 0;
    }
}
