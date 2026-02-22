#include "../include/RGE_Game_Info.h"
#include "../include/RGE_Person_Info.h"
#include "../include/RGE_Campaign_Info.h"
#include "../include/RGE_Campaign.h"
#include "../include/mystring.h"
#include "../include/globals.h"
#include <io.h>
#include <fcntl.h>
#include <stdlib.h>
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

char* RGE_Campaign::get_scenario_name(long param_1) {
    // Fully verified. Source of truth: campaign.cpp.decomp @ 0x004237A0
    return this->scenario_offsets[param_1].name;
}

long RGE_Campaign::scenario_number() {
    // Source of truth: gameinfo.cpp.decomp (used by campaign info sizing)
    return this->campaign_header.scenario_num;
}

RGE_Campaign_Info::~RGE_Campaign_Info() {
    // Fully verified. Source of truth: gameinfo.cpp.decomp @ 0x0044C870
    if (this->scenario_info != nullptr) {
        free(this->scenario_info);
        this->scenario_info = nullptr;
    }
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

long RGE_Campaign_Info::get_scenario_list(char*** param_1, long* param_2) {
    // Fully verified. Source of truth: gameinfo.cpp.asm @ 0x0044CB20
    if (this->campaign == nullptr) {
        if (param_2) {
            *param_2 = -1;
        }
        return -1;
    }

    // Allocate up to last unlocked scenario (inclusive).
    char** list = (char**)calloc((size_t)(this->last_scenario + 1), 4);
    if (param_1) {
        *param_1 = list;
    }

    if (this->last_scenario >= 0 && list != nullptr) {
        for (long i = 0; i <= this->last_scenario; ++i) {
            char* name = this->campaign->get_scenario_name(i);
            getstring(&list[i], name);
        }
    }

    if (param_2) {
        *param_2 = this->current_scenario;
    }
    return this->last_scenario + 1;
}

RGE_Person_Info::RGE_Person_Info(char* param_1, RGE_Campaign** param_2, long param_3) {
    // Fully verified. Source of truth: gameinfo.cpp.asm @ 0x0044CD40
    memset(this->name, 0, sizeof(this->name));
    if (param_1 != nullptr) {
        strncpy(this->name, param_1, sizeof(this->name) - 1);
    }

    this->campaign_info_num = 0;
    this->campaign_info = nullptr;
    this->campaigns = param_2;
    this->current_campaign = -1;
    this->campaign_num = param_3;
}

RGE_Person_Info::~RGE_Person_Info() {
    // Fully verified. Source of truth: gameinfo.cpp.asm @ 0x0044CDA0
    if (this->campaign_info != nullptr) {
        for (int i = 0; i < this->campaign_info_num; ++i) {
            if (this->campaign_info[i] != nullptr) {
                delete this->campaign_info[i];
                this->campaign_info[i] = nullptr;
            }
        }
        free(this->campaign_info);
        this->campaign_info = nullptr;
        this->campaign_info_num = 0;
    }
}

char* RGE_Person_Info::get_name() {
    // Fully verified. Source of truth: gameinfo.cpp.decomp @ 0x0044CEE0
    return this->name;
}

long RGE_Person_Info::get_current_campaign() {
    // Fully verified. Source of truth: gameinfo.cpp.asm @ 0x0044D050
    if (this->current_campaign < 0 || this->current_campaign >= this->campaign_info_num || this->campaign_info == nullptr) {
        return -1;
    }

    for (int i = 0; i < this->campaign_num; ++i) {
        if (this->campaigns == nullptr || this->campaigns[i] == nullptr) {
            continue;
        }
        char* name = this->campaigns[i]->get_name();
        if (this->campaign_info[this->current_campaign]->verify_campaign_name(name) != '\0') {
            return i;
        }
    }
    return -1;
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

long RGE_Person_Info::get_scenario_list(char*** param_1, long* param_2) {
    // Fully verified. Source of truth: gameinfo.cpp.decomp @ 0x0044D130
    if (this->current_campaign < 0 || this->campaign_info == nullptr) {
        return 0;
    }
    return this->campaign_info[this->current_campaign]->get_scenario_list(param_1, param_2);
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

uchar RGE_Game_Info::add_new_person(char* param_1) {
    // Source of truth: gameinfo.cpp.decomp @ 0x0044D710
    RGE_Person_Info** ppRVar1 = (RGE_Person_Info**)calloc((size_t)this->people_num + 1, 4);
    if (ppRVar1 == nullptr) {
        return '\0';
    }

    for (int i = 0; i < this->people_num; ++i) {
        ppRVar1[i] = (this->people_info != nullptr) ? this->people_info[i] : nullptr;
    }

    if (this->people_info != nullptr) {
        free(this->people_info);
    }
    this->people_info = ppRVar1;

    RGE_Person_Info* person = new (std::nothrow) RGE_Person_Info(param_1, this->campaigns, this->campaign_num);
    this->people_info[this->people_num] = person;
    this->current_person = this->people_num;
    this->people_num = this->people_num + 1;
    return '\x01';
}

long RGE_Game_Info::get_people_list(char*** param_1, long* param_2) {
    // Fully verified. Source of truth: gameinfo.cpp.asm @ 0x0044D850
    if (0 < this->people_num) {
        char** list = (char**)calloc((size_t)this->people_num, 4);
        *param_1 = list;

        for (int i = 0; i < this->people_num; ++i) {
            char* name = this->people_info[i]->get_name();
            getstring(&list[i], name);
        }

        *param_2 = this->current_person;
    }
    return this->people_num;
}

long RGE_Game_Info::get_campaign_list(char*** param_1, long* param_2) {
    // Fully verified. Source of truth: gameinfo.cpp.decomp @ 0x0044D8C0
    if (0 < this->campaign_num) {
        char** list = (char**)calloc((size_t)this->campaign_num, 4);
        *param_1 = list;

        for (int i = 0; i < this->campaign_num; ++i) {
            char* name = this->campaigns[i]->get_name();
            getstring(&list[i], name);
        }

        int iVar4 = (int)this->current_person;
        if ((iVar4 < this->people_num) && (-1 < iVar4)) {
            long lVar3 = this->people_info[iVar4]->get_current_campaign();
            *param_2 = lVar3;
        }
    }
    return this->campaign_num;
}

long RGE_Game_Info::get_scenario_list(char*** param_1, long* param_2) {
    // Fully verified. Source of truth: gameinfo.cpp.decomp @ 0x0044D940
    int iVar1 = (int)this->current_person;
    if ((iVar1 < this->people_num) && (-1 < iVar1)) {
        long lVar2 = this->people_info[iVar1]->get_current_scenario();
        *param_2 = lVar2;
        return this->people_info[this->current_person]->get_scenario_list(param_1, param_2);
    }

    *param_2 = -1;
    return -1;
}

void RGE_Game_Info::remove_player(long param_1) {
    // Fully verified. Source of truth: gameinfo.cpp.decomp @ 0x0044DA50
    if ((-1 < param_1) && (param_1 < this->people_num) && this->people_info != nullptr) {
        RGE_Person_Info* person = this->people_info[param_1];
        if (person != nullptr) {
            delete person;
        }

        if (param_1 < this->people_num - 1) {
            do {
                long next = param_1 + 1;
                this->people_info[param_1] = this->people_info[next];
                param_1 = next;
            } while (param_1 < this->people_num - 1);
        }

        int old_num = this->people_num;
        int new_num = old_num - 1;
        this->people_num = new_num;
        if (this->current_person == new_num) {
            this->current_person = old_num - 2;
        }
    }
}
