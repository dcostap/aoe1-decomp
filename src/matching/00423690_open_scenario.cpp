// 00423690 RGE_Campaign::open_scenario
// Source: campaign.cpp lines 175-193

#include "../../include/campaign_context.h"

int RGE_Campaign::open_scenario(long index)
{
    if (index >= 0 && index < this->campaign_header.scenario_num) {
        int h = _open(this->filename, 0x8000);
        if (h >= 0) {
            _lseek(h, this->scenario_offsets[index].offset, 0);
            rge_fake_open(h, this->scenario_offsets[index].size);
            return h;
        }
    }
    return -1;
}
