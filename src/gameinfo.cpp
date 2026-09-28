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

extern void __cdecl getstring(char** destination, char* source);
extern int version_marker;

RGE_Campaign_Info::RGE_Campaign_Info(int infile, RGE_Campaign** campaigns, long campaign_num) {
    rge_read(infile, this, 255);
    rge_read(infile, &current_scenario, 4);
    rge_read(infile, &scenario_num, 4);
    rge_read(infile, &last_scenario, 4);

    if (scenario_num > 0) {
        scenario_info = (RGE_Scenario_Info*)calloc(scenario_num, 1);
        rge_read(infile, scenario_info, scenario_num);
    } else {
        scenario_info = 0;
    }

    campaign = 0;

    if (campaign_num > 0) {
        RGE_Campaign** pcamp = campaigns;
        while (campaign_num > 0) {
            if (strcmp((*pcamp)->get_name(), name) == 0) {
                campaign = *pcamp;
                if (scenario_num != campaign->scenario_number()) {
                    if (scenario_num > campaign->scenario_number()) {
                        RGE_Scenario_Info* new_info = (RGE_Scenario_Info*)calloc(campaign->scenario_number(), 1);
                        if (scenario_num < campaign->scenario_number()) {
                            memcpy(new_info, scenario_info, scenario_num);
                        } else {
                            memcpy(new_info, scenario_info, campaign->scenario_number());
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
            --campaign_num;
        }
    }
}

RGE_Campaign_Info::RGE_Campaign_Info(RGE_Campaign* new_campaign) {
    if (new_campaign) {
        campaign = new_campaign;
        strcpy(name, new_campaign->get_name());
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

void RGE_Campaign_Info::save(int outfile) {
    L->Log("  (PIF)Saving campaign - (%d) %s", last_scenario, this);
    rge_write(outfile, this, 255);
    rge_write(outfile, &current_scenario, 4);
    rge_write(outfile, &scenario_num, 4);
    rge_write(outfile, &last_scenario, 4);
    if (scenario_num > 0) {
        rge_write(outfile, scenario_info, scenario_num);
    }
}

void RGE_Campaign_Info::rehook_campaigns(RGE_Campaign** campaigns, long campaign_num) {
    campaign = 0;
    if (campaign_num <= 0) return;
    RGE_Campaign** pp = campaigns;
    long remaining = campaign_num;
    do {
        if (strcmp((*pp)->get_name(), name) == 0) {
            campaign = *pp;
            if (scenario_num != campaign->scenario_number()) {
                RGE_Scenario_Info* newsi = (RGE_Scenario_Info*)calloc(campaign->scenario_number(), 1);
                if (scenario_num < campaign->scenario_number()) {
                    memcpy(newsi, scenario_info, scenario_num);
                } else {
                    memcpy(newsi, scenario_info, campaign->scenario_number());
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

unsigned char RGE_Campaign_Info::set_current_scenario(long num) {
    if (num < scenario_num && scenario_info[num].scenario_status != 0) {
        if (num > last_scenario) {
            current_scenario = last_scenario;
        } else {
            current_scenario = num;
        }
        return 1;
    }
    return 0;
}

unsigned char RGE_Campaign_Info::verify_campaign_name(char* in_campaign_name) {
    if (strcmp(this->name, in_campaign_name) != 0) {
        return 0;
    }
    return 1;
}

long RGE_Campaign_Info::get_scenario_list(char*** list, long& curr_scenario) {
    if (campaign) {
        *list = (char**)calloc(last_scenario + 1, 4);
        for (int i = 0; i <= last_scenario; i++) {
            getstring((*list) + i, campaign->get_scenario_name(i));
        }
        curr_scenario = current_scenario;
        return last_scenario + 1;
    }
    curr_scenario = -1;
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

RGE_Person_Info::RGE_Person_Info(int infile, RGE_Campaign** in_campaigns, long in_campaign_num) {
    campaign_num = in_campaign_num;
    campaigns = in_campaigns;
    rge_read(infile, this, 255);
    rge_read(infile, &current_campaign, 4);
    rge_read(infile, &campaign_info_num, 4);

    if (campaign_info_num > 0) {
        campaign_info = (RGE_Campaign_Info**)calloc(campaign_info_num, 4);
        for (int i = 0; i < campaign_info_num; i++) {
            campaign_info[i] = new RGE_Campaign_Info(infile, campaigns, campaign_num);
        }
    } else {
        campaign_info = 0;
    }
}

RGE_Person_Info::RGE_Person_Info(char* in_name, RGE_Campaign** in_campaigns, long in_campaign_num) {
    strcpy(this->name, in_name);
    this->current_campaign = -1;
    this->campaign_num = in_campaign_num;
    this->campaign_info_num = 0;
    this->campaign_info = 0;
    this->campaigns = in_campaigns;
}

RGE_Person_Info::~RGE_Person_Info() {
    if (campaign_info != 0) {
        for (int i = 0; i < campaign_info_num; i++) {
            RGE_Campaign_Info* ci = campaign_info[i];
            if (ci != 0) {
                delete ci;
            }
        }
        free(campaign_info);
        campaign_info = 0;
        campaign_info_num = 0;
    }
}

void RGE_Person_Info::save(int outfile) {
    L->Log("(PIF)Saving player - %s", this);
    rge_write(outfile, this, 255);
    rge_write(outfile, &current_campaign, 4);
    rge_write(outfile, &campaign_info_num, 4);
    for (int i = 0; i < campaign_info_num; i++) {
        campaign_info[i]->save(outfile);
    }
}

void RGE_Person_Info::rehook_campaigns(RGE_Campaign** in_campaigns, long in_campaign_num) {
    int i;

    i = 0;
    this->campaign_num = in_campaign_num;
    this->campaigns = in_campaigns;
    if (this->campaign_info_num > 0) {
        do {
            this->campaign_info[i]->rehook_campaigns(this->campaigns, this->campaign_num);
            i = i + 1;
        } while (i < this->campaign_info_num);
    }
}

char* RGE_Person_Info::get_name() { return this->name; }

unsigned char RGE_Person_Info::set_current_campaign(long num) {
    if (num < 0 || num >= campaign_num || campaigns[num] == 0) {
        return 0;
    }

    for (int i = 0; i < campaign_info_num; i++) {
        if (campaign_info[i]->verify_campaign_name(campaigns[num]->get_name())) {
            current_campaign = i;
            return 1;
        }
    }

    RGE_Campaign_Info** new_campaign_info = (RGE_Campaign_Info**)calloc(campaign_info_num + 1, 4);
    if (campaign_info != 0) {
        memcpy(new_campaign_info, campaign_info, campaign_info_num * 4);
    }
    free(campaign_info);
    campaign_info = new_campaign_info;

    campaign_info[campaign_info_num] = new RGE_Campaign_Info(campaigns[num]);
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

unsigned char RGE_Person_Info::set_current_scenario(long num) {
    int current_campaign = this->current_campaign;
    if ((current_campaign > -1) && (this->campaigns[current_campaign] != 0)) {
        return this->campaign_info[current_campaign]->set_current_scenario(num);
    }
    return 0;
}

long RGE_Person_Info::get_scenario_list(char*** list, long& current_scenario) {
    if (this->current_campaign > -1)
        return this->campaign_info[this->current_campaign]->get_scenario_list(list, current_scenario);
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

RGE_Game_Info::RGE_Game_Info(char* filename) {
    int version;

    people_info = 0;
    people_num = 0;
    campaign_num = 0;
    campaigns = 0;
    find_campaigns();
    strcpy(save_filename, filename);
    int fd = rge_open(filename, _O_BINARY);
    if (fd > -1) {
        rge_read(fd, &version, 4);
        if (version == version_marker) {
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
                delete cp;
            }
        }
        free(campaigns);
        campaigns = 0;
    }
    if (people_info) {
        for (int i = 0; i < people_num; i++) {
            RGE_Person_Info* pi = people_info[i];
            if (pi) {
                delete pi;
            }
        }
        free(people_info);
        people_info = 0;
    }
}

void RGE_Game_Info::save(char* filename) {
    L->Log("(PIF)Creating Player Info File");

    strcpy(save_filename, filename);

    int fd = rge_open(filename, _O_BINARY | _O_WRONLY | _O_CREAT | _O_APPEND | _O_TRUNC, _S_IREAD | _S_IWRITE);
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
                    delete campaign;
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

unsigned char RGE_Game_Info::set_current_person(long num) {
    if (num < this->people_num) {
        this->current_person = num;
        return 1;
    }
    this->current_person = -1;
    return 0;
}

unsigned char RGE_Game_Info::set_current_campaign(long num) {
    if (this->current_person < this->people_num && this->current_person >= 0)
        return this->people_info[this->current_person]->set_current_campaign(num);
    return 0;
}

unsigned char RGE_Game_Info::set_current_scenario(long num) {
    if (this->current_person >= 0 && this->current_person < this->people_num)
        return this->people_info[this->current_person]->set_current_scenario(num);
    return 0;
}

long RGE_Game_Info::get_people_list(char*** list, long& current_player) {
    char* name;
    int i;
    char** new_list;

    if (0 < this->people_num) {
        new_list = (char**)calloc(this->people_num, 4);
        i = 0;
        *list = new_list;
        if (0 < this->people_num) {
            do {
                name = this->people_info[i]->get_name();
                getstring(*list + i, name);
                i = i + 1;
            } while (i < this->people_num);
        }
        current_player = this->current_person;
    }
    return this->people_num;
}

long RGE_Game_Info::get_campaign_list(char*** list, long& current_campaign) {
    if (campaign_num > 0) {
        *list = (char**)calloc(campaign_num, 4);
        for (int i = 0; i < campaign_num; i++) {
            getstring(*list + i, campaigns[i]->get_name());
        }
        if (current_person < people_num && current_person >= 0) {
            current_campaign = people_info[current_person]->get_current_campaign();
        }
    }
    return campaign_num;
}

long RGE_Game_Info::get_scenario_list(char*** list, long& current_scenario) {
    if (this->current_person < this->people_num) {
        if (0 <= this->current_person) {
            current_scenario = this->people_info[this->current_person]->get_current_scenario();
            return this->people_info[this->current_person]->get_scenario_list(list, current_scenario);
        }
    }
    current_scenario = -1;
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

void RGE_Game_Info::remove_player(long id) {
    if (id < 0) return;
    if (id >= people_num) return;

    RGE_Person_Info* person = people_info[id];
    if (person != 0) {
        delete person;
    }

    long idx = id;
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
