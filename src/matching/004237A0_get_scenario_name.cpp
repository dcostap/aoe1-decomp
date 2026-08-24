// 004237A0 RGE_Campaign::get_scenario_name
// Source: campaign.cpp lines 227-229
#include "../../include/campaign_context.h"

char* RGE_Campaign::get_scenario_name(long index) {
    return this->scenario_offsets[index].name;
}
