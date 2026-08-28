#include "../include/gameinfo.h"
#include "../include/campaign.h"

#include "../include/basegame.h"
#include "../include/debuglog.h"
#include "../include/game_globals.h"
#include "../include/main.h"
#include "../include/rge_base_game_global.h"
#include "../include/rge_fio.h"

#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern "C" void __cdecl getstring(char** destination, char* source);
extern "C" void __cdecl operator_delete(void* pointer);
extern int version_marker;

RGE_Campaign_Info::RGE_Campaign_Info(int fd, RGE_Campaign** camps, long cnum) {
    rge_read(fd, this, 0xFF);
    rge_read(fd, &current_scenario, 4);
    rge_read(fd, &scenario_num, 4);
    rge_read(fd, &last_scenario, 4);

    if (scenario_num > 0) {
        scenario_info = (RGE_Scenario_Info*)calloc(scenario_num, 1);
        rge_read(fd, scenario_info, scenario_num);
    } else {
        scenario_info = 0;
    }

    campaign = 0;

    if (cnum > 0) {
        RGE_Campaign** pcamp = camps;
        while (cnum > 0) {
            if (strcmp((*pcamp)->get_name(), name) == 0) {
                campaign = *pcamp;
                if (scenario_num != campaign->scenario_number()) {
                    if (scenario_num > campaign->scenario_number()) {
                        RGE_Scenario_Info* new_info =
                            (RGE_Scenario_Info*)calloc(campaign->scenario_number(), 1);
                        if (scenario_num < campaign->scenario_number()) {
                            memcpy(new_info, scenario_info, scenario_num);
                        } else {
                            memcpy(new_info, scenario_info,
                                   campaign->scenario_number());
                        }
                        free(scenario_info);
                        scenario_info = new_info;
                    }

                    scenario_num = campaign->scenario_number();
                    if (last_scenario >= scenario_num) {
                        last_scenario = scenario_num - 1;
                    }
                    if (current_scenario > last_scenario) {
                        current_scenario = last_scenario;
                    }
                }
            }
            ++pcamp;
            --cnum;
        }
    }
}

RGE_Campaign_Info::RGE_Campaign_Info(RGE_Campaign* camp) {
    if (camp) {
        campaign = camp;
        strcpy(name, camp->get_name());
        long snum = campaign->scenario_number();
        scenario_num = snum;
        if (snum > 0) {
            current_scenario = 0;
            last_scenario = 0;
            scenario_info = (RGE_Scenario_Info*)calloc(snum, 1);
            scenario_info->scenario_status = 2;
        } else {
            scenario_info = 0;
            current_scenario = -1;
            last_scenario = -1;
        }
    } else {
        campaign = 0;
        strcpy(name, "");
        current_scenario = 0;
        last_scenario = 0;
        scenario_num = 0;
        scenario_info = 0;
    }
}

RGE_Campaign_Info::~RGE_Campaign_Info() {
    if (this->scenario_info) {
        free(this->scenario_info);
        this->scenario_info = 0;
    }
}

void RGE_Campaign_Info::save(int fd) {
    L->Log("  (PIF)Saving campaign - (%d) %s", last_scenario, this);
    rge_write(fd, this, 0xFF);
    rge_write(fd, &current_scenario, 4);
    rge_write(fd, &scenario_num, 4);
    rge_write(fd, &last_scenario, 4);
    if (scenario_num > 0) {
        rge_write(fd, scenario_info, scenario_num);
    }
}

void RGE_Campaign_Info::rehook_campaigns(RGE_Campaign** list, long count) {
    campaign = 0;
    if (count <= 0) return;
    RGE_Campaign** pp = list;
    long remaining = count;
    do {
        if (strcmp((*pp)->get_name(), name) == 0) {
            campaign = *pp;
            if (scenario_num != campaign->scenario_number()) {
                RGE_Scenario_Info* newsi =
                    (RGE_Scenario_Info*)calloc(campaign->scenario_number(), 1);
                if (scenario_num < campaign->scenario_number()) {
                    memcpy(newsi, scenario_info, scenario_num);
                } else {
                    memcpy(newsi, scenario_info,
                           campaign->scenario_number());
                }
                free(scenario_info);
                scenario_info = newsi;
            }
            scenario_num = campaign->scenario_number();
            if (last_scenario >= scenario_num) {
                last_scenario = scenario_num - 1;
            }
            if (current_scenario > last_scenario) {
                current_scenario = last_scenario;
            }
        }
        pp++;
        remaining--;
    } while (remaining);
}

unsigned char RGE_Campaign_Info::set_current_scenario(long param_1) {
    if (param_1 < scenario_num && scenario_info[param_1].scenario_status != 0) {
        if (param_1 > last_scenario) {
            current_scenario = last_scenario;
        } else {
            current_scenario = param_1;
        }
        return 1;
    }
    return 0;
}

unsigned char RGE_Campaign_Info::verify_campaign_name(char* campaign) {
    if (strcmp(this->name, campaign) != 0) {
        return 0;
    }
    return 1;
}

long RGE_Campaign_Info::get_scenario_list(char*** list, long& current) {
    if (campaign) {
        *list = (char**)calloc(last_scenario + 1, 4);
        for (int i = 0; i <= last_scenario; i++) {
            getstring((*list) + i, campaign->get_scenario_name(i));
        }
        current = current_scenario;
        return last_scenario + 1;
    }
    current = -1;
    return -1;
}

long RGE_Campaign_Info::get_current_scenario() { return this->current_scenario; }

void RGE_Campaign_Info::notify_of_scenario_complete() {
    if (this->current_scenario > -1) {
        this->scenario_info[this->current_scenario].scenario_status = 1;

        if (this->last_scenario <= this->current_scenario) {
            this->last_scenario = this->current_scenario + 1;
            this->set_current_scenario(this->last_scenario);
        }

        if (this->last_scenario >= this->scenario_num) {
            this->last_scenario = this->scenario_num - 1;
        }

        this->scenario_info[this->last_scenario].scenario_status = 2;
    }
}

int RGE_Campaign_Info::open_scenario() {
    if (this->current_scenario > -1) {
        return this->campaign->open_scenario(this->current_scenario);
    }
    return -1;
}

RGE_Person_Info::RGE_Person_Info(int fd, RGE_Campaign** camps, long cnum) {
    campaign_num = cnum;
    campaigns = camps;
    rge_read(fd, this, 0xFF);
    rge_read(fd, &current_campaign, 4);
    rge_read(fd, &campaign_info_num, 4);

    if (campaign_info_num > 0) {
        campaign_info = (RGE_Campaign_Info**)calloc(campaign_info_num, 4);
        for (int i = 0; i < campaign_info_num; i++) {
            campaign_info[i] = new RGE_Campaign_Info(fd, campaigns, campaign_num);
        }
    } else {
        campaign_info = 0;
    }
}

RGE_Person_Info::RGE_Person_Info(char* name, RGE_Campaign** campaigns, long campaign_num) {
    strcpy(this->name, name);
    this->current_campaign = -1;
    this->campaign_num = campaign_num;
    this->campaign_info_num = 0;
    this->campaign_info = 0;
    this->campaigns = campaigns;
}

RGE_Person_Info::~RGE_Person_Info() {
    if (campaign_info != 0) {
        for (int i = 0; i < campaign_info_num; i++) {
            RGE_Campaign_Info* ci = campaign_info[i];
            if (ci != 0) {
                ci->~RGE_Campaign_Info();
                operator_delete(ci);
            }
        }
        free(campaign_info);
        campaign_info = 0;
        campaign_info_num = 0;
    }
}

void RGE_Person_Info::save(int fd) {
    L->Log("(PIF)Saving player - %s", this);
    rge_write(fd, this, 0xFF);
    rge_write(fd, &current_campaign, 4);
    rge_write(fd, &campaign_info_num, 4);
    for (int i = 0; i < campaign_info_num; i++) {
        campaign_info[i]->save(fd);
    }
}

void RGE_Person_Info::rehook_campaigns(RGE_Campaign** campaigns, long campaign_num) {
    int i;

    i = 0;
    this->campaign_num = campaign_num;
    this->campaigns = campaigns;
    if (this->campaign_info_num > 0) {
        do {
            this->campaign_info[i]->rehook_campaigns(this->campaigns, this->campaign_num);
            i = i + 1;
        } while (i < this->campaign_info_num);
    }
}

char* RGE_Person_Info::get_name() { return this->name; }

unsigned char RGE_Person_Info::set_current_campaign(long index) {
    if (index < 0 || index >= campaign_num || campaigns[index] == 0) {
        return 0;
    }

    for (int i = 0; i < campaign_info_num; i++) {
        if (campaign_info[i]->verify_campaign_name(campaigns[index]->get_name())) {
            current_campaign = i;
            return 1;
        }
    }

    RGE_Campaign_Info** newlist = (RGE_Campaign_Info**)calloc(campaign_info_num + 1, 4);
    if (campaign_info != 0) {
        memcpy(newlist, campaign_info, campaign_info_num * 4);
    }
    free(campaign_info);
    campaign_info = newlist;

    campaign_info[campaign_info_num] = new RGE_Campaign_Info(campaigns[index]);
    current_campaign = campaign_info_num;
    campaign_info_num++;
    return 1;
}

long RGE_Person_Info::get_current_campaign() {
    if (this->current_campaign < 0 || this->current_campaign >= this->campaign_info_num) {
        return -1;
    }

    for (long i = 0; i < this->campaign_num; ++i) {
        if (this->campaign_info[this->current_campaign]->verify_campaign_name(this->campaigns[i]->get_name()) != 0) {
            return i;
        }
    }

    return -1;
}

long RGE_Person_Info::get_current_scenario() {
    int i;

    i = this->current_campaign;
    if (i > -1 && this->campaigns[i] != 0)
        return this->campaign_info[i]->get_current_scenario();
    return -1;
}

unsigned char RGE_Person_Info::set_current_scenario(long scenario) {
    int current_campaign = this->current_campaign;
    if ((current_campaign > -1) && (this->campaigns[current_campaign] != 0)) {
        return this->campaign_info[current_campaign]->set_current_scenario(scenario);
    }
    return 0;
}

long RGE_Person_Info::get_scenario_list(char*** list, long& count) {
    if (this->current_campaign > -1)
        return this->campaign_info[this->current_campaign]->get_scenario_list(list, count);
    return 0;
}

void RGE_Person_Info::notify_of_scenario_complete() {
    long current_campaign;

    current_campaign = this->current_campaign;
    if (current_campaign > -1) {
        this->campaign_info[current_campaign]->notify_of_scenario_complete();
    }
}

int RGE_Person_Info::open_scenario() {
    long current_campaign;

    current_campaign = this->current_campaign;
    if (current_campaign > -1) {
        return this->campaign_info[current_campaign]->open_scenario();
    }
    return -1;
}

RGE_Game_Info::RGE_Game_Info(char* path) {
    int ver;

    people_info = 0;
    people_num = 0;
    campaign_num = 0;
    campaigns = 0;
    find_campaigns();
    strcpy(save_filename, path);
    int fd = rge_open(path, 0x8000);
    if (fd > -1) {
        rge_read(fd, &ver, 4);
        if (ver == version_marker) {
            rge_read(fd, this, 4);
            rge_read(fd, &people_num, 4);
            if (people_num > 0) {
                people_info = (RGE_Person_Info**)calloc(people_num, 4);
                for (int i = 0; i < people_num; i++) {
                    people_info[i] = new RGE_Person_Info(fd, campaigns, campaign_num);
                }
            } else {
                people_info = 0;
            }
            rge_close(fd);
        } else {
            current_person = -1;
            people_num = 0;
            people_info = 0;
        }
    } else {
        current_person = -1;
        people_num = 0;
        people_info = 0;
    }
}

RGE_Game_Info::~RGE_Game_Info() {
    if (save_filename[0]) {
        save(save_filename);
    }
    if (campaigns) {
        for (int i = 0; i < campaign_num; i++) {
            RGE_Campaign* cp = campaigns[i];
            if (cp) {
                cp->~RGE_Campaign();
                operator_delete(cp);
            }
        }
        free(campaigns);
        campaigns = 0;
    }
    if (people_info) {
        for (int i = 0; i < people_num; i++) {
            RGE_Person_Info* pi = people_info[i];
            if (pi) {
                pi->~RGE_Person_Info();
                operator_delete(pi);
            }
        }
        free(people_info);
        people_info = 0;
    }
}

void RGE_Game_Info::save(char* path) {
    L->Log("(PIF)Creating Player Info File");

    strcpy(save_filename, path);

    int fd = rge_open(path, 0x8309, 0x180);
    if (fd == -1) return;

    rge_write(fd, &version_marker, 4);
    rge_write(fd, this, 4);
    rge_write(fd, &people_num, 4);

    int count = people_num;
    if (count > 0) { int j; for (j=0; j<count; j++) { people_info[j]->save(fd); count=people_num; } }
    rge_close(fd);
}

void RGE_Game_Info::find_campaigns() {
    _finddata_t file_info;
    char file_name[260];
    long handle;
    int i = 0;

    if (campaigns != 0) {
        i = 0;
        if (campaign_num > 0) {
            do {
                RGE_Campaign* campaign = campaigns[i];
                if (campaign != 0) {
                    campaign->~RGE_Campaign();
                    operator_delete(campaign);
                }
                ++i;
            } while (i < campaign_num);
        }
        free(campaigns);
        campaigns = 0;
    }

    sprintf(file_name, "%s*.cpn", rge_base_game->prog_info->campaign_dir);
    handle = _findfirst(file_name, &file_info);
    campaign_num = 0;
    if (handle != -1) {
        do {
            ++campaign_num;
        } while (_findnext(handle, &file_info) != -1);
    }

    sprintf(file_name, "%s*.cpx", rge_base_game->prog_info->campaign_dir);
    handle = _findfirst(file_name, &file_info);
    if (handle != -1) {
        do {
            ++campaign_num;
        } while (_findnext(handle, &file_info) != -1);
    }

    if (campaign_num > 0) {
        campaigns = (RGE_Campaign**)calloc(campaign_num, 4);
        i = 0;

        sprintf(file_name, "%s*.cpn", rge_base_game->prog_info->campaign_dir);
        handle = _findfirst(file_name, &file_info);
        if (handle != -1) {
            do {
                campaigns[i] = new RGE_Campaign(file_info.name);
                ++i;
            } while (_findnext(handle, &file_info) != -1);
        }

        sprintf(file_name, "%s*.cpx", rge_base_game->prog_info->campaign_dir);
        handle = _findfirst(file_name, &file_info);
        if (handle != -1) {
            for (;;) {
                campaigns[i] = new RGE_Campaign(file_info.name);
                if (_findnext(handle, &file_info) == -1) {
                    break;
                }
                ++i;
            }
        }
    } else {
        campaigns = 0;
    }

    for (i = 0; i < people_num; ++i) {
        people_info[i]->rehook_campaigns(campaigns, campaign_num);
    }
}

unsigned char RGE_Game_Info::add_new_person(char* name) {
    RGE_Person_Info** newlist = (RGE_Person_Info**)calloc(people_num + 1, 4);
    memcpy(newlist, people_info, people_num * 4);
    free(people_info);
    people_info = newlist;
    people_info[people_num] = new RGE_Person_Info(name, campaigns, campaign_num);
    current_person = people_num;
    people_num++;
    return 1;
}

unsigned char RGE_Game_Info::set_current_person(long person) {
    if (person < this->people_num) {
        this->current_person = person;
        return 1;
    }
    this->current_person = -1;
    return 0;
}

unsigned char RGE_Game_Info::set_current_campaign(long campaign) {
    if (this->current_person < this->people_num && this->current_person >= 0)
        return this->people_info[this->current_person]->set_current_campaign(campaign);
    return 0;
}

unsigned char RGE_Game_Info::set_current_scenario(long scenario) {
    if (this->current_person >= 0 && this->current_person < this->people_num)
        return this->people_info[this->current_person]->set_current_scenario(scenario);
    return 0;
}

long RGE_Game_Info::get_people_list(char*** out_list, long& out_current) {
    char* name;
    int iVar3;
    char** ppcVar1;

    if (0 < this->people_num) {
        ppcVar1 = (char**)calloc(this->people_num, 4);
        iVar3 = 0;
        *out_list = ppcVar1;
        if (0 < this->people_num) {
            do {
                name = this->people_info[iVar3]->get_name();
                getstring(*out_list + iVar3, name);
                iVar3 = iVar3 + 1;
            } while (iVar3 < this->people_num);
        }
        out_current = this->current_person;
    }
    return this->people_num;
}

long RGE_Game_Info::get_campaign_list(char*** list, long& current) {
    if (campaign_num > 0) {
        *list = (char**)calloc(campaign_num, 4);
        for (int i = 0; i < campaign_num; i++) {
            getstring(*list + i, campaigns[i]->get_name());
        }
        if (current_person < people_num && current_person >= 0) {
            current = people_info[current_person]->get_current_campaign();
        }
    }
    return campaign_num;
}

long RGE_Game_Info::get_scenario_list(char*** param_1, long& param_2) {
    if (this->current_person < this->people_num) {
        if (0 <= this->current_person) {
            param_2 = this->people_info[this->current_person]->get_current_scenario();
            return this->people_info[this->current_person]->get_scenario_list(param_1, param_2);
        }
    }
    param_2 = -1;
    return -1;
}

long RGE_Game_Info::get_current_scenario() {
    long current_person;

    current_person = this->current_person;
    if (current_person < this->people_num) {
        if (current_person >= 0) {
            return this->people_info[current_person]->get_current_scenario();
        }
    }
    return -1;
}

long RGE_Game_Info::get_current_campaign() {
    long current_person;

    current_person = this->current_person;
    if (current_person < this->people_num) {
        if (current_person >= 0) {
            return this->people_info[current_person]->get_current_campaign();
        }
    }
    return -1;
}

long RGE_Game_Info::get_current_player() { return this->current_person; }

char* RGE_Game_Info::get_current_player_name() {
    long current_person;

    current_person = this->current_person;
    if (current_person < 0) {
        return 0;
    }
    return this->people_info[current_person]->get_name();
}

void RGE_Game_Info::notify_of_scenario_complete() {
    if (this->current_person < this->people_num && this->current_person >= 0) {
        this->people_info[this->current_person]->notify_of_scenario_complete();
    }
    this->save(this->save_filename);
}

int RGE_Game_Info::open_scenario() {
    long current_person;

    current_person = this->current_person;
    if (current_person < this->people_num) {
        if (current_person >= 0) {
            return this->people_info[current_person]->open_scenario();
        }
    }
    return -1;
}

void RGE_Game_Info::remove_player(long person_index) {
    if (person_index < 0) return;
    if (person_index >= people_num) return;

    RGE_Person_Info* person = people_info[person_index];
    if (person != 0) {
        person->~RGE_Person_Info();
        operator_delete(person);
    }

    long idx = person_index;
    long bound = people_num;
    if (idx < bound - 1) {
        do {
            people_info[idx] = people_info[idx + 1];
            idx++;
        } while (idx < people_num - 1);
    }

    people_num--;
    if (current_person == people_num) {
        current_person = people_num - 1;
    }
}
