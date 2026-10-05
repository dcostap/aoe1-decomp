
#include "../include/campaign.h"
#include "../include/main.h"
#include "../include/basegame.h"
#include "../include/rge_base_game_global.h"
#include "../include/mystring.h"

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

// These declarations expose the period CRT and executable helper interfaces.
extern "C" int __cdecl sprintf(char*, const char*, ...);
extern "C" int __cdecl open(const char*, int);
extern "C" int __cdecl _open(const char*, int, ...);
extern "C" int __cdecl read(int, void*, int);
extern "C" int __cdecl write(int, void*, int);
extern "C" int __cdecl close(int);
extern "C" int __cdecl lseek(int, int, int);
extern "C" int __cdecl _lseek(int, int, int);
extern "C" long __cdecl _tell(int);
extern "C" void* __cdecl calloc(unsigned int, unsigned int);
extern "C" void __cdecl free(void*);
extern int __cdecl rge_fake_open(int, int);

RGE_Campaign::RGE_Campaign(char* in_filename) {
    sprintf(this->filename, "%s%s", rge_base_game->prog_info->campaign_dir, in_filename);

    int handle = open(this->filename, _O_BINARY);
    if (handle >= 0) {
        read(handle, this, 264);
        if (this->campaign_header.scenario_num > 0) {
            this->scenario_offsets = (RGE_Scenario_Offset*) calloc(this->campaign_header.scenario_num, 520);
            read(handle, this->scenario_offsets, this->campaign_header.scenario_num * 520);
        } else {
            this->scenario_offsets = 0;
        }
        close(handle);
        return;
    }

    strcpy(this->campaign_header.name, "FILE NOT FOUND");
    this->campaign_header.scenario_num = 0;
    this->campaign_header.version = 0;
    this->scenario_offsets = 0;
}

RGE_Campaign::RGE_Campaign(
    char* campaign_filename, char* campaign_name, long scenario_num, char** scenarios, char** scenarios_name
) {
    sprintf(this->filename, "%s%s", rge_base_game->prog_info->campaign_dir, campaign_filename);

    this->campaign_header.version = version_marker;
    strcpy(this->campaign_header.name, campaign_name);
    this->campaign_header.scenario_num = scenario_num;

    if (scenario_num > 0) {
        this->scenario_offsets = (RGE_Scenario_Offset*) calloc(scenario_num, 520);
        for (long i = 0; i < scenario_num; ++i) {
            strcpy(this->scenario_offsets[i].name, scenarios_name[i]);
            strcpy(this->scenario_offsets[i].file_name, scenarios[i]);
        }
    } else {
        this->scenario_offsets = 0;
    }

    this->create_file();
}

RGE_Campaign::~RGE_Campaign() {
    if (this->scenario_offsets != 0) {
        free(this->scenario_offsets);
        this->scenario_offsets = 0;
    }
}

void RGE_Campaign::create_file() {
    int handle;
    int index;
    int current_offset;
    char tempname[300];

    handle = _open(this->filename, _O_WRONLY | _O_CREAT | _O_TRUNC | _O_BINARY, _S_IREAD | _S_IWRITE);
    if (handle >= 0) {
        write(handle, this, 264);
        if (this->campaign_header.scenario_num > 0) {
            write(handle, this->scenario_offsets, this->campaign_header.scenario_num * 520);
            current_offset = 0;
            index = this->campaign_header.scenario_num * 0x208 + 0x108;
            if (this->campaign_header.scenario_num > 0) {
                do {
                    sprintf(
                        tempname, "%s%s", rge_base_game->prog_info->scenario_dir,
                        this->scenario_offsets[current_offset].file_name
                    );
                    int scenario_file = _open(tempname, _O_BINARY);
                    if (scenario_file > -1) {
                        lseek(scenario_file, 0, SEEK_END);
                        int size = _tell(scenario_file);
                        void* buffer = calloc(size, 1);
                        lseek(scenario_file, 0, SEEK_SET);
                        read(scenario_file, buffer, size);
                        write(handle, buffer, size);
                        this->scenario_offsets[current_offset].offset = index;
                        this->scenario_offsets[current_offset].size = size;
                        index += size;
                        free(buffer);
                        close(scenario_file);
                    }
                    ++current_offset;
                } while (current_offset < this->campaign_header.scenario_num);
            }
            lseek(handle, 0x108, SEEK_SET);
            write(handle, this->scenario_offsets, this->campaign_header.scenario_num * 520);
        }
        close(handle);
    }
}

int RGE_Campaign::open_scenario(long scenario) {
    if (scenario >= 0 && scenario < this->campaign_header.scenario_num) {
        int h = _open(this->filename, _O_BINARY);
        if (h >= 0) {
            _lseek(h, this->scenario_offsets[scenario].offset, SEEK_SET);
            rge_fake_open(h, this->scenario_offsets[scenario].size);
            return h;
        }
    }
    return -1;
}

char* RGE_Campaign::get_name() {
    return this->campaign_header.name;
}

long RGE_Campaign::scenario_number() {
    return this->campaign_header.scenario_num;
}

long RGE_Campaign::scenario_info(char*** scenario_names) {
    char** strings = (char**) calloc((unsigned int) this->campaign_header.scenario_num, 4);
    *scenario_names = strings;

    int i = 0;
    if (0 < this->campaign_header.scenario_num) {
        do {
            getstring(*scenario_names + i, (this->scenario_offsets + i)->name);
            ++i;
        } while (i < this->campaign_header.scenario_num);
    }

    return this->campaign_header.scenario_num;
}

char* RGE_Campaign::get_scenario_name(long num) {
    return this->scenario_offsets[num].name;
}
