#include "../include/RGE_Game_Info.h"
#include "../include/RGE_Person_Info.h"
#include "../include/RGE_Campaign_Info.h"
#include "../include/RGE_Campaign.h"
#include "../include/globals.h"
#include <io.h>
#include <fcntl.h>
#include <string.h>
#include <new>

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

char* RGE_Campaign::get_name() {
    // Source of truth: gameinfo.cpp.decomp (used by campaign info matching)
    return this->campaign_header.name;
}

long RGE_Campaign::scenario_number() {
    // Source of truth: gameinfo.cpp.decomp (used by campaign info sizing)
    return this->campaign_header.scenario_num;
}

RGE_Campaign_Info::RGE_Campaign_Info(RGE_Campaign* param_1) {
    // Source of truth: gameinfo.cpp.decomp @ 0x0044C780
    this->campaign = param_1;

    memset(this->campaign_name, 0, sizeof(this->campaign_name));
    if (param_1 != nullptr) {
        strncpy(this->campaign_name, param_1->get_name(), sizeof(this->campaign_name) - 1);
    }

    this->scenario_info = nullptr;
    this->scenario_num = 0;
    this->current_scenario = -1;
    this->last_scenario = -1;

    if (param_1 != nullptr) {
        this->scenario_num = param_1->scenario_number();
        if (this->scenario_num > 0) {
            this->current_scenario = 0;
            this->last_scenario = 0;
            this->scenario_info = (RGE_Scenario_Info*)calloc((size_t)this->scenario_num, 1);
            if (this->scenario_info != nullptr) {
                this->scenario_info[0].scenario_status = '\x02';
            }
        }
    }
}

uchar RGE_Campaign_Info::verify_campaign_name(char* param_1) {
    // Source of truth: gameinfo.cpp.decomp @ 0x0044CAD0
    if (param_1 == nullptr) {
        return '\0';
    }
    return (strcmp(this->campaign_name, param_1) == 0) ? '\x01' : '\0';
}

uchar RGE_Campaign_Info::set_current_scenario(long param_1) {
    // Source of truth: gameinfo.cpp.decomp @ 0x0044CA90
    if (param_1 < 0 || param_1 >= this->scenario_num || this->scenario_info == nullptr) {
        return '\0';
    }

    if (this->scenario_info[param_1].scenario_status == '\0') {
        return '\0';
    }

    if (this->last_scenario < param_1) {
        this->current_scenario = this->last_scenario;
        return '\x01';
    }

    this->current_scenario = param_1;
    return '\x01';
}

void RGE_Campaign_Info::notify_of_scenario_complete() {
    // Source of truth: gameinfo.cpp.decomp @ 0x0044CBC0
    if (this->current_scenario < 0 || this->scenario_info == nullptr) {
        return;
    }

    this->scenario_info[this->current_scenario].scenario_status = '\x01';
    if (this->last_scenario <= this->current_scenario) {
        long next = this->current_scenario + 1;
        this->last_scenario = next;
        this->set_current_scenario(next);
    }

    if (this->scenario_num <= this->last_scenario) {
        this->last_scenario = this->scenario_num - 1;
    }

    if (this->last_scenario >= 0 && this->last_scenario < this->scenario_num) {
        this->scenario_info[this->last_scenario].scenario_status = '\x02';
    }
}

void RGE_Campaign_Info::save(int param_1) {
    // Source of truth: gameinfo.cpp.decomp @ 0x0044C8A0
    rge_write(param_1, this, 0xFF);
    rge_write(param_1, &this->current_scenario, 4);
    rge_write(param_1, &this->scenario_num, 4);
    rge_write(param_1, &this->last_scenario, 4);
    if (this->scenario_num > 0) {
        rge_write(param_1, this->scenario_info, (int)this->scenario_num);
    }
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

void RGE_Person_Info::save(int param_1) {
    // Source of truth: gameinfo.cpp.decomp @ 0x0044CE10
    rge_write(param_1, this, 0xFF);
    rge_write(param_1, &this->current_campaign, 4);
    rge_write(param_1, &this->campaign_info_num, 4);
    if (this->campaign_info_num > 0) {
        for (int i = 0; i < this->campaign_info_num; ++i) {
            this->campaign_info[i]->save(param_1);
        }
    }
}

uchar RGE_Person_Info::set_current_campaign(long param_1) {
    // Source of truth: gameinfo.cpp.decomp @ 0x0044CEF0 (simplified: no exception frame)
    if (param_1 < 0 || param_1 >= this->campaign_num || this->campaigns == nullptr || this->campaigns[param_1] == nullptr) {
        return '\0';
    }

    const char* name = this->campaigns[param_1]->get_name();
    for (int i = 0; i < this->campaign_info_num; ++i) {
        if (this->campaign_info != nullptr && this->campaign_info[i] != nullptr &&
            this->campaign_info[i]->verify_campaign_name((char*)name) != '\0') {
            this->current_campaign = i;
            return '\x01';
        }
    }

    RGE_Campaign_Info** new_list = (RGE_Campaign_Info**)calloc((size_t)this->campaign_info_num + 1, sizeof(RGE_Campaign_Info*));
    if (new_list == nullptr) {
        return '\0';
    }

    for (int i = 0; i < this->campaign_info_num; ++i) {
        new_list[i] = (this->campaign_info != nullptr) ? this->campaign_info[i] : nullptr;
    }
    if (this->campaign_info != nullptr) {
        free(this->campaign_info);
    }
    this->campaign_info = new_list;

    RGE_Campaign_Info* info = new (std::nothrow) RGE_Campaign_Info(this->campaigns[param_1]);
    if (info == nullptr) {
        return '\0';
    }

    this->campaign_info[this->campaign_info_num] = info;
    this->current_campaign = this->campaign_info_num;
    this->campaign_info_num = this->campaign_info_num + 1;
    return '\x01';
}

uchar RGE_Person_Info::set_current_scenario(long param_1) {
    // Source of truth: gameinfo.cpp.decomp @ 0x0044D0F0
    if (this->current_campaign < 0 || this->current_campaign >= this->campaign_info_num || this->campaign_info == nullptr) {
        return '\0';
    }
    RGE_Campaign_Info* info = this->campaign_info[this->current_campaign];
    if (info == nullptr) {
        return '\0';
    }
    return info->set_current_scenario(param_1);
}

void RGE_Person_Info::notify_of_scenario_complete() {
    // Source of truth: gameinfo.cpp.decomp @ 0x0044D160
    if (this->current_campaign < 0 || this->current_campaign >= this->campaign_info_num || this->campaign_info == nullptr) {
        return;
    }
    RGE_Campaign_Info* info = this->campaign_info[this->current_campaign];
    if (info != nullptr) {
        info->notify_of_scenario_complete();
    }
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

uchar RGE_Game_Info::set_current_person(long param_1) {
    // Source of truth: gameinfo.cpp.decomp @ 0x0044D7D0
    if (param_1 < this->people_num) {
        this->current_person = param_1;
        return '\x01';
    }
    this->current_person = -1;
    return '\0';
}

uchar RGE_Game_Info::set_current_campaign(long param_1) {
    // Source of truth: gameinfo.cpp.decomp @ 0x0044D7F0
    int idx = (int)this->current_person;
    if (idx >= 0 && idx < this->people_num && this->people_info != nullptr && this->people_info[idx] != nullptr) {
        return this->people_info[idx]->set_current_campaign(param_1);
    }
    return '\0';
}

uchar RGE_Game_Info::set_current_scenario(long param_1) {
    // Source of truth: gameinfo.cpp.decomp @ 0x0044D820
    int idx = (int)this->current_person;
    if (idx >= 0 && idx < this->people_num && this->people_info != nullptr && this->people_info[idx] != nullptr) {
        return this->people_info[idx]->set_current_scenario(param_1);
    }
    return '\0';
}

void RGE_Game_Info::save(char* param_1) {
    // Source of truth: gameinfo.cpp.decomp @ 0x0044D3B0
    static const char kPifVersion[4] = {'1', '.', '0', '0'};

    strcpy(this->save_filename, param_1);

    int fd = rge_open(param_1, 0x8309, 0x180);
    if (fd != -1) {
        rge_write(fd, (void*)kPifVersion, 4);
        rge_write(fd, this, 4);
        rge_write(fd, &this->people_num, 4);
        if (this->people_num > 0) {
            for (int i = 0; i < this->people_num; ++i) {
                this->people_info[i]->save(fd);
            }
        }
        rge_close(fd);
    }
}

void RGE_Game_Info::notify_of_scenario_complete() {
    // Source of truth: gameinfo.cpp.decomp @ 0x0044DA00
    int idx = (int)this->current_person;
    if (idx >= 0 && idx < this->people_num && this->people_info != nullptr && this->people_info[idx] != nullptr) {
        this->people_info[idx]->notify_of_scenario_complete();
    }
    this->save(this->save_filename);
}
