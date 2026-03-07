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

// Fully verified. Marker reconciliation coverage: campaign.cpp accessors/open path are implemented in gameinfo.cpp.

RGE_Campaign::RGE_Campaign(char* param_1) {
    // Fully verified. Source of truth: campaign.cpp.decomp + campaign.cpp.asm @ 0x00423230
    this->scenario_offsets = nullptr;
    memset(this->filename, 0, sizeof(this->filename));
    sprintf(this->filename, "%s%s", rge_base_game->prog_info->campaign_dir, param_1);

    const int fd = _open(this->filename, _O_BINARY | _O_RDONLY);
    if (fd >= 0) {
        _read(fd, &this->campaign_header, sizeof(this->campaign_header));

        const long count = this->campaign_header.scenario_num;
        if (count > 0) {
            this->scenario_offsets = (RGE_Scenario_Offset*)calloc((size_t)count, sizeof(RGE_Scenario_Offset));
            _read(fd, this->scenario_offsets, (unsigned int)(count * (long)sizeof(RGE_Scenario_Offset)));
        } else {
            this->scenario_offsets = nullptr;
        }
        _close(fd);
        return;
    }

    strncpy(this->campaign_header.name, "FILE NOT FOUND", sizeof(this->campaign_header.name) - 1);
    this->campaign_header.name[sizeof(this->campaign_header.name) - 1] = '\0';
    this->campaign_header.scenario_num = 0;
    this->campaign_header.version = 0;
}

RGE_Campaign::RGE_Campaign(char* param_1, char* param_2, long param_3, char** param_4, char** param_5) {
    // Fully verified. Source of truth: campaign.cpp.decomp + campaign.cpp.asm @ 0x00423330
    this->scenario_offsets = nullptr;
    memset(this->filename, 0, sizeof(this->filename));
    memset(&this->campaign_header, 0, sizeof(this->campaign_header));
    sprintf(this->filename, "%s%s", rge_base_game->prog_info->campaign_dir, param_1);

    memcpy(&this->campaign_header.version, "1.00", 4);
    strcpy(this->campaign_header.name, param_2);
    this->campaign_header.scenario_num = param_3;

    if (param_3 > 0) {
        this->scenario_offsets = (RGE_Scenario_Offset*)calloc((size_t)param_3, sizeof(RGE_Scenario_Offset));
        for (long i = 0; i < param_3; ++i) {
            strcpy(this->scenario_offsets[i].name, param_5[i]);
            strcpy(this->scenario_offsets[i].file_name, param_4[i]);
        }
    } else {
        this->scenario_offsets = nullptr;
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

void RGE_Campaign::create_file() {
    // Fully verified. Source of truth: campaign.cpp.decomp + campaign.cpp.asm @ 0x004234B0
    const int fd = _open(this->filename, _O_BINARY | _O_CREAT | _O_TRUNC | _O_WRONLY, _S_IREAD | _S_IWRITE);
    if (fd < 0) {
        return;
    }

    _write(fd, &this->campaign_header, (unsigned int)sizeof(this->campaign_header));

    const long count = this->campaign_header.scenario_num;
    if (count > 0) {
        _write(fd, this->scenario_offsets, (unsigned int)(count * (long)sizeof(RGE_Scenario_Offset)));

        long current_offset = (long)sizeof(this->campaign_header) + count * (long)sizeof(RGE_Scenario_Offset);
        for (long i = 0; i < count; ++i) {
            char scen_path[300];
            sprintf(scen_path, "%s%s", rge_base_game->prog_info->scenario_dir, this->scenario_offsets[i].file_name);

            const int scen_fd = _open(scen_path, _O_BINARY | _O_RDONLY);
            if (scen_fd >= 0) {
                _lseek(scen_fd, 0, SEEK_END);
                const long size = _tell(scen_fd);
                void* buf = calloc((size_t)size, 1);
                _lseek(scen_fd, 0, SEEK_SET);
                _read(scen_fd, buf, (unsigned int)size);
                _write(fd, buf, (unsigned int)size);
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

long RGE_Campaign::scenario_info(char*** param_1) {
    // Fully verified. Source of truth: campaign.cpp.decomp + campaign.cpp.asm @ 0x00423730
    const long count = this->campaign_header.scenario_num;
    char** out = (char**)calloc((size_t)count, sizeof(char*));
    *param_1 = out;

    if (count > 0) {
        for (long i = 0; i < count; ++i) {
            getstring(&out[i], this->scenario_offsets[i].name);
        }
    }

    return count;
}


