#include "../include/RGE_Game_Info.h"
#include "../include/RGE_Person_Info.h"
#include "../include/RGE_Campaign_Info.h"
#include "../include/RGE_Campaign.h"
#include "../include/globals.h"
#include <io.h>
#include <fcntl.h>

int RGE_Campaign::open_scenario(long param_1) {
    // Source of truth: campaign.cpp.decomp @ 0x00423690
    if (param_1 < 0 || param_1 >= this->campaign_header.scenario_num || this->scenario_offsets == nullptr) {
        return -1;
    }

    int handle = rge_open(this->filename, _O_BINARY | _O_RDONLY);
    if (handle < 0) {
        return -1;
    }

    _lseek(handle, this->scenario_offsets[param_1].offset, SEEK_SET);
    rge_fake_open(handle, this->scenario_offsets[param_1].size);
    return handle;
}

long RGE_Campaign_Info::get_current_scenario() {
    // Source of truth: gameinfo.cpp.decomp @ 0x0044D0E0
    return this->current_scenario;
}

int RGE_Campaign_Info::open_scenario() {
    // Source of truth: gameinfo.cpp.decomp @ 0x0044D180
    if (this->campaign == nullptr) {
        return -1;
    }
    return this->campaign->open_scenario(this->current_scenario);
}

long RGE_Person_Info::get_current_campaign() {
    // Source of truth: gameinfo.cpp.decomp @ 0x0044D090
    return this->current_campaign;
}

long RGE_Person_Info::get_current_scenario() {
    // Source of truth: gameinfo.cpp.decomp @ 0x0044D0D0
    if (this->current_campaign < 0 || this->current_campaign >= this->campaign_info_num || this->campaign_info == nullptr) {
        return -1;
    }
    RGE_Campaign_Info* info = this->campaign_info[this->current_campaign];
    if (info == nullptr) {
        return -1;
    }
    return info->get_current_scenario();
}

int RGE_Person_Info::open_scenario() {
    // Source of truth: gameinfo.cpp.decomp @ 0x0044D180
    if (this->current_campaign < 0 || this->current_campaign >= this->campaign_info_num || this->campaign_info == nullptr) {
        return -1;
    }
    RGE_Campaign_Info* info = this->campaign_info[this->current_campaign];
    if (info == nullptr) {
        return -1;
    }
    return info->open_scenario();
}

long RGE_Game_Info::get_current_scenario() {
    // Source of truth: gameinfo.cpp.decomp @ 0x0044D990
    if (this->current_person < 0 || this->current_person >= this->people_num || this->people_info == nullptr) {
        return -1;
    }
    RGE_Person_Info* person = this->people_info[this->current_person];
    if (person == nullptr) {
        return -1;
    }
    return person->get_current_scenario();
}

long RGE_Game_Info::get_current_campaign() {
    // Source of truth: gameinfo.cpp.decomp @ 0x0044D9B0
    if (this->current_person < 0 || this->current_person >= this->people_num || this->people_info == nullptr) {
        return -1;
    }
    RGE_Person_Info* person = this->people_info[this->current_person];
    if (person == nullptr) {
        return -1;
    }
    return person->get_current_campaign();
}

long RGE_Game_Info::get_current_player() {
    // Source of truth: gameinfo.cpp.decomp @ 0x0044D9D0
    return this->current_person;
}

char* RGE_Game_Info::get_current_player_name() {
    // Fully verified. Source of truth: gameinfo.cpp.decomp @ 0x0044D9E0
    if (this->current_person < 0 || this->current_person >= this->people_num || this->people_info == nullptr) {
        return nullptr;
    }
    return this->people_info[this->current_person]->name;
}

int RGE_Game_Info::open_scenario() {
    // Source of truth: gameinfo.cpp.decomp @ 0x0044DA30
    if (this->current_person < 0 || this->current_person >= this->people_num || this->people_info == nullptr) {
        return -1;
    }
    RGE_Person_Info* person = this->people_info[this->current_person];
    if (person == nullptr) {
        return -1;
    }
    return person->open_scenario();
}
