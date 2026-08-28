// PDB source module: C:\\msdev\\work\\age1_x1\\sceninfo.cpp.
// The definitions follow the original source order.

#include "../include/basegame.h"
#include "../include/main.h"
#include "../include/rge_base_game_global.h"
#include "../include/scenario.h"
#include "../include/sceninfo.h"

#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern "C" {
int rge_open(char* filename, int mode, ...);
void rge_read_uncompressed(int fd, void* buffer, int count);
void rge_write_uncompressed(int fd, void* buffer, int count);
int rge_close(int fd);
}

// 0048CEA0 RGE_Scenario_File_Info::RGE_Scenario_File_Info(char*)
RGE_Scenario_File_Info::RGE_Scenario_File_Info(char* path)
{
    long i;

    strcpy(filename, path);

    int fd = rge_open(this->filename, 0x8000);
    if (fd != -1) {
        rge_read_uncompressed(fd, &this->scenario_num, 4);
        i = 0;

        if (this->scenario_num > 0) {
            this->scenarios = (RGE_Scenario_File_Entry*)calloc(
                this->scenario_num, sizeof(RGE_Scenario_File_Entry));
            for (i = 0; i < this->scenario_num; i++) {
                rge_read_uncompressed(fd, &this->scenarios[i].time, 4);
                rge_read_uncompressed(fd, this->scenarios[i].name, 0x104);
                this->scenarios[i].scenario_header = rge_base_game->new_scenario_header(fd);
            }

            rge_close(fd);
            this->reload_scenarios();
            return;
        } else {
            this->scenarios = 0;
        }

        rge_close(fd);
        this->reload_scenarios();
    } else {
        this->scenario_num = 0;
        this->scenarios = 0;
        this->reload_scenarios();
    }
}

// 0048CFD0 RGE_Scenario_File_Info::~RGE_Scenario_File_Info()
RGE_Scenario_File_Info::~RGE_Scenario_File_Info() {
    save();
    if (scenario_num > 0) {
        for (int i = 0; i < scenario_num; i++) {
            RGE_Scenario_Header* hdr = scenarios[i].scenario_header;
            if (hdr != 0) {
                delete hdr;
            }
        }
        free(scenarios);
        scenarios = 0;
        scenario_num = 0;
    }
}

// 0048D040 RGE_Scenario_File_Info::save()
void RGE_Scenario_File_Info::save()
{
    int fd = rge_open(this->filename, 0x8301, 0x180);
    if (fd == -1)
        return;

    int cnt;
    rge_write_uncompressed(fd, &this->scenario_num, 4);
    cnt = 0;

    if (this->scenario_num > 0) {
        do {
            rge_write_uncompressed(fd, &this->scenarios[cnt].time, 4);
            rge_write_uncompressed(fd, this->scenarios[cnt].name, 0x104);
            this->scenarios[cnt].scenario_header->save(fd);

            cnt++;
        } while (cnt < this->scenario_num);
    }

    rge_close(fd);
}

// 0048D0E0 RGE_Scenario_File_Info::reload_scenarios()
void RGE_Scenario_File_Info::reload_scenarios()
{
    char file_name[260];
    struct _finddata_t file_info;
    long handle;
    long count;
    int total = 0;
    char looped = 0;
    RGE_Scenario_File_Entry* new_scenarios;
    RGE_Scenario_File_Entry* current;
    int index;
    char found_in_list;

    sprintf(file_name + 4, "%s*.scn", rge_base_game->prog_info->scenario_dir);
    handle = _findfirst(file_name + 4, &file_info);
    if (handle != -1) {
        do {
            ++total;
        } while (_findnext(handle, &file_info) != -1);
    }

    sprintf(file_name + 4, "%s*.scx", rge_base_game->prog_info->scenario_dir);
    handle = _findfirst(file_name + 4, &file_info);
    if (handle != -1) {
        do {
            ++total;
        } while (_findnext(handle, &file_info) != -1);
    }

    sprintf(file_name + 4, "%s*.scn", rge_base_game->prog_info->scenario_dir);
    if (total <= 0)
        return;

    count = _findfirst(file_name + 4, &file_info);
    if (count == -1) {
        sprintf(file_name + 4, "%s*.scx", rge_base_game->prog_info->scenario_dir);
        count = _findfirst(file_name + 4, &file_info);
        looped = 1;
    }

    if (count == -1)
        return;

    new_scenarios = (RGE_Scenario_File_Entry*)calloc(
        total, sizeof(RGE_Scenario_File_Entry));
    current = new_scenarios;

    do {
        index = 0;
        found_in_list = 0;

        while (index < this->scenario_num) {
            if (strcmp(this->scenarios[index].name, file_info.name) == 0) {
                if (file_info.time_write <= this->scenarios[index].time) {
                    strcpy(current->name, this->scenarios[index].name);
                    found_in_list = 1;
                    current->time = this->scenarios[index].time;
                    current->scenario_header = this->scenarios[index].scenario_header;
                    this->scenarios[index].scenario_header = 0;
                }
                break;
            }
            ++index;
        }

        if (!found_in_list) {
            strcpy(current->name, file_info.name);
            current->time = file_info.time_write;

            sprintf(file_name + 4, "%s%s",
                    rge_base_game->prog_info->scenario_dir,
                    file_info.name);
            int fd = rge_open(file_name + 4, 0x8000);
            if (fd > -1) {
                rge_read_uncompressed(fd, file_name, 4);
                current->scenario_header = rge_base_game->new_scenario_header(fd);
                rge_close(fd);
            }
        }

        ++current;

        if (_findnext(count, &file_info) == -1) {
            if (looped)
                break;

            sprintf(file_name + 4, "%s*.scx", rge_base_game->prog_info->scenario_dir);
            count = _findfirst(file_name + 4, &file_info);
            if (count == -1)
                break;
            looped = 1;
        }
    } while (1);

    if (this->scenarios != 0) {
        for (index = 0; index < this->scenario_num; ++index) {
            if (this->scenarios[index].scenario_header != 0)
                delete this->scenarios[index].scenario_header;
        }
        free(this->scenarios);
    }

    this->scenarios = new_scenarios;
    this->scenario_num = total;
}

// 0048D4D0 RGE_Scenario_File_Info::get_scenario_name(long)
char* RGE_Scenario_File_Info::get_scenario_name(long index) {
    if (index >= this->scenario_num || index < 0) return 0;
    return this->scenarios[index].name;
}

// 0048D500 RGE_Scenario_File_Info::get_scenario_info(long)
RGE_Scenario_Header* RGE_Scenario_File_Info::get_scenario_info(long index) {
    if (index >= this->scenario_num || index < 0) return 0;
    return this->scenarios[index].scenario_header;
}
