#include "../include/RGE_Campaign.h"

#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Prog_Info.h"
#include "../include/RGE_Scenario_Offset.h"
#include "../include/globals.h"
#include "../include/mystring.h"

#include <fcntl.h>
#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

// Fully verified. Source of truth: campaign.cpp.decomp @ 0x00423230
RGE_Campaign::RGE_Campaign(char* param_1) {
    this->scenario_offsets = nullptr;
    memset(this->filename, 0, sizeof(this->filename));

    if (rge_base_game == nullptr || rge_base_game->prog_info == nullptr || param_1 == nullptr) {
        memset(&this->campaign_header, 0, sizeof(this->campaign_header));
        return;
    }

    sprintf(this->filename, "%s%s", rge_base_game->prog_info->campaign_dir, param_1);

    const int fd = _open(this->filename, _O_BINARY | _O_RDONLY);
    if (fd >= 0) {
        _read(fd, &this->campaign_header, sizeof(this->campaign_header));

        const long count = this->campaign_header.scenario_num;
        if (count > 0) {
            this->scenario_offsets = (RGE_Scenario_Offset*)calloc((size_t)count, sizeof(RGE_Scenario_Offset));
            if (this->scenario_offsets != nullptr) {
                _read(fd, this->scenario_offsets, (unsigned int)(count * (long)sizeof(RGE_Scenario_Offset)));
            }
        }
        _close(fd);
        return;
    }

    strncpy(this->campaign_header.name, "FILE NOT FOUND", sizeof(this->campaign_header.name) - 1);
    this->campaign_header.name[sizeof(this->campaign_header.name) - 1] = '\0';
    this->campaign_header.scenario_num = 0;
    this->campaign_header.version = 0;
}

// Fully verified. Source of truth: campaign.cpp.decomp @ 0x00423330
RGE_Campaign::RGE_Campaign(char* param_1, char* param_2, long param_3, char** param_4, char** param_5) {
    this->scenario_offsets = nullptr;
    memset(this->filename, 0, sizeof(this->filename));
    memset(&this->campaign_header, 0, sizeof(this->campaign_header));

    if (rge_base_game == nullptr || rge_base_game->prog_info == nullptr || param_1 == nullptr) {
        return;
    }

    sprintf(this->filename, "%s%s", rge_base_game->prog_info->campaign_dir, param_1);

    memcpy(&this->campaign_header.version, "1.00", 4);
    if (param_2 != nullptr) {
        strncpy(this->campaign_header.name, param_2, sizeof(this->campaign_header.name) - 1);
        this->campaign_header.name[sizeof(this->campaign_header.name) - 1] = '\0';
    }
    this->campaign_header.scenario_num = param_3;

    if (param_3 > 0) {
        this->scenario_offsets = (RGE_Scenario_Offset*)calloc((size_t)param_3, sizeof(RGE_Scenario_Offset));
        if (this->scenario_offsets != nullptr) {
            for (long i = 0; i < param_3; ++i) {
                const char* scen_name = (param_5 != nullptr) ? param_5[i] : nullptr;
                const char* scen_file = (param_4 != nullptr) ? param_4[i] : nullptr;

                if (scen_name != nullptr) {
                    strncpy(this->scenario_offsets[i].name, scen_name, sizeof(this->scenario_offsets[i].name) - 1);
                    this->scenario_offsets[i].name[sizeof(this->scenario_offsets[i].name) - 1] = '\0';
                }
                if (scen_file != nullptr) {
                    strncpy(this->scenario_offsets[i].file_name, scen_file, sizeof(this->scenario_offsets[i].file_name) - 1);
                    this->scenario_offsets[i].file_name[sizeof(this->scenario_offsets[i].file_name) - 1] = '\0';
                }
            }
        }
    }

    this->create_file();
}

// Fully verified. Source of truth: campaign.cpp.decomp @ 0x00423480
RGE_Campaign::~RGE_Campaign() {
    if (this->scenario_offsets != nullptr) {
        free(this->scenario_offsets);
        this->scenario_offsets = nullptr;
    }
}

// Fully verified. Source of truth: campaign.cpp.decomp @ 0x004234B0
void RGE_Campaign::create_file() {
    if (rge_base_game == nullptr || rge_base_game->prog_info == nullptr) {
        return;
    }

    const int fd = _open(this->filename, _O_BINARY | _O_CREAT | _O_TRUNC | _O_WRONLY, _S_IREAD | _S_IWRITE);
    if (fd < 0) {
        return;
    }

    _write(fd, &this->campaign_header, (unsigned int)sizeof(this->campaign_header));

    const long count = this->campaign_header.scenario_num;
    if (count > 0 && this->scenario_offsets != nullptr) {
        _write(fd, this->scenario_offsets, (unsigned int)(count * (long)sizeof(RGE_Scenario_Offset)));

        long current_offset = (long)sizeof(this->campaign_header) + count * (long)sizeof(RGE_Scenario_Offset);
        for (long i = 0; i < count; ++i) {
            char scen_path[512];
            sprintf(scen_path, "%s%s", rge_base_game->prog_info->scenario_dir, this->scenario_offsets[i].file_name);

            const int scen_fd = _open(scen_path, _O_BINARY | _O_RDONLY);
            if (scen_fd >= 0) {
                _lseek(scen_fd, 0, SEEK_END);
                const long size = _tell(scen_fd);
                void* buf = (size > 0) ? calloc((size_t)size, 1) : nullptr;
                _lseek(scen_fd, 0, SEEK_SET);
                if (buf != nullptr && size > 0) {
                    _read(scen_fd, buf, (unsigned int)size);
                    _write(fd, buf, (unsigned int)size);
                }
                this->scenario_offsets[i].offset = current_offset;
                this->scenario_offsets[i].size = size;
                current_offset += size;
                free(buf);
                _close(scen_fd);
            }
        }

        _lseek(fd, (long)sizeof(this->campaign_header), SEEK_SET);
        _write(fd, this->scenario_offsets, (unsigned int)(count * (long)sizeof(RGE_Scenario_Offset)));
    }

    _close(fd);
}

// Fully verified. Source of truth: campaign.cpp.decomp @ 0x00423730
long RGE_Campaign::scenario_info(char*** param_1) {
    if (param_1 == nullptr) {
        return 0;
    }

    const long count = this->campaign_header.scenario_num;
    char** out = (char**)calloc((size_t)count, sizeof(char*));
    *param_1 = out;

    if (out != nullptr && this->scenario_offsets != nullptr) {
        for (long i = 0; i < count; ++i) {
            getstring(&out[i], this->scenario_offsets[i].name);
        }
    }

    return count;
}

