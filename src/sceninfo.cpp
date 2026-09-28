
#include "../include/basegame.h"
#include "../include/main.h"
#include "../include/rge_base_game_global.h"
#include "../include/scenario.h"
#include "../include/sceninfo.h"

#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/rge_fio.h"

RGE_Scenario_File_Info::RGE_Scenario_File_Info(char* in_filename) {
    long i;

    strcpy(filename, in_filename);

    int fd = rge_open(this->filename, _O_BINARY);
    if (fd != -1) {
        rge_read_uncompressed(fd, &this->scenario_num, 4);
        i = 0;

        if (this->scenario_num > 0) {
            this->scenarios = (RGE_Scenario_File_Entry*)calloc(this->scenario_num, sizeof(RGE_Scenario_File_Entry));
            for (i = 0; i < this->scenario_num; i++) {
                rge_read_uncompressed(fd, &this->scenarios[i].time, 4);
                rge_read_uncompressed(fd, this->scenarios[i].name, 260);
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

void RGE_Scenario_File_Info::save() {
    int fd = rge_open(this->filename, _O_BINARY | _O_WRONLY | _O_CREAT | _O_TRUNC, _S_IREAD | _S_IWRITE);
    if (fd == -1)
        return;

    int cnt;
    rge_write_uncompressed(fd, &this->scenario_num, 4);
    cnt = 0;

    if (this->scenario_num > 0) {
        do {
            rge_write_uncompressed(fd, &this->scenarios[cnt].time, 4);
            rge_write_uncompressed(fd, this->scenarios[cnt].name, 260);
            this->scenarios[cnt].scenario_header->save(fd);

            cnt++;
        } while (cnt < this->scenario_num);
    }

    rge_close(fd);
}

void RGE_Scenario_File_Info::reload_scenarios() {
    long count = 0;
    long version;
    char file_name[256];
    struct _finddata_t file_info;
    long handle;
    unsigned char looped = 0;
    RGE_Scenario_File_Entry* new_scenarios;
    RGE_Scenario_File_Entry* current;
    int index;
    unsigned char found_in_list;

    sprintf(file_name, "%s*.scn", rge_base_game->prog_info->scenario_dir);
    handle = _findfirst(file_name, &file_info);
    if (handle != -1) {
        do {
            ++count;
        } while (_findnext(handle, &file_info) != -1);
    }

    sprintf(file_name, "%s*.scx", rge_base_game->prog_info->scenario_dir);
    handle = _findfirst(file_name, &file_info);
    if (handle != -1) {
        do {
            ++count;
        } while (_findnext(handle, &file_info) != -1);
    }

    sprintf(file_name, "%s*.scn", rge_base_game->prog_info->scenario_dir);
    if (count <= 0)
        return;

    handle = _findfirst(file_name, &file_info);
    if (handle == -1) {
        sprintf(file_name, "%s*.scx", rge_base_game->prog_info->scenario_dir);
        handle = _findfirst(file_name, &file_info);
        looped = 1;
    }

    if (handle == -1)
        return;

    new_scenarios = (RGE_Scenario_File_Entry*)calloc(count, sizeof(RGE_Scenario_File_Entry));
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

            sprintf(file_name, "%s%s", rge_base_game->prog_info->scenario_dir, file_info.name);
            int fd = rge_open(file_name, _O_BINARY);
            if (fd > -1) {
                rge_read_uncompressed(fd, &version, 4);
                current->scenario_header = rge_base_game->new_scenario_header(fd);
                rge_close(fd);
            }
        }

        ++current;

        if (_findnext(handle, &file_info) == -1) {
            if (looped)
                break;

            sprintf(file_name, "%s*.scx", rge_base_game->prog_info->scenario_dir);
            handle = _findfirst(file_name, &file_info);
            if (handle == -1)
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
    this->scenario_num = count;
}

char* RGE_Scenario_File_Info::get_scenario_name(long id) {
    if (id >= this->scenario_num || id < 0) return 0;
    return this->scenarios[id].name;
}

RGE_Scenario_Header* RGE_Scenario_File_Info::get_scenario_info(long id) {
    if (id >= this->scenario_num || id < 0) return 0;
    return this->scenarios[id].scenario_header;
}
