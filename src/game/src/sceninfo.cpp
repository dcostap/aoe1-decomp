#include "../include/RGE_Scenario_File_Info.h"
#include "../include/RGE_Scenario_File_Entry.h"
#include "../include/RGE_Scenario_Header.h"
#include "../include/RGE_Base_Game.h"
#include "../include/globals.h"

#include <io.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

namespace {
static long rge_count_matching_files(const char* pattern) {
    _finddata_t file_info;
    long count = 0;

    long h = _findfirst(pattern, &file_info);
    if (h == -1) {
        return 0;
    }

    do {
        count = count + 1;
    } while (_findnext(h, &file_info) != -1);

    _findclose(h);
    return count;
}

static void rge_copy_entry_name(char* dst, const char* src) {
    if (dst == nullptr) {
        return;
    }

    if (src == nullptr) {
        dst[0] = '\0';
        return;
    }

    strncpy(dst, src, 259);
    dst[259] = '\0';
}

static void rge_write_empty_scenario_header(int fd) {
    long header_size = 0xC;
    long version = 0;
    int desc_size = 0;
    rge_write(fd, &header_size, 4);
    rge_write(fd, &version, 4);
    rge_write(fd, &desc_size, 4);
}
}

RGE_Scenario_File_Info::RGE_Scenario_File_Info(char* param_1) {
    // Fully verified. Source of truth: sceninfo.cpp.decomp @ 0x0048CEA0
    this->scenario_num = 0;
    this->scenarios = nullptr;
    rge_copy_entry_name(this->filename, param_1);

    int fd = rge_open(this->filename, _O_RDONLY | _O_BINARY);
    if (fd != -1) {
        rge_read(fd, &this->scenario_num, 4);
        if (this->scenario_num > 0) {
            this->scenarios = (RGE_Scenario_File_Entry*)calloc((size_t)this->scenario_num,
                                                                sizeof(RGE_Scenario_File_Entry));
            if (this->scenarios != nullptr) {
                for (long i = 0; i < this->scenario_num; ++i) {
                    rge_read(fd, &this->scenarios[i].time, 4);
                    rge_read(fd, this->scenarios[i].name, 0x104);
                    this->scenarios[i].name[259] = '\0';
                    this->scenarios[i].scenario_header =
                        (rge_base_game != nullptr) ? rge_base_game->new_scenario_header(fd) : nullptr;
                }
            } else {
                this->scenario_num = 0;
            }
        } else {
            this->scenario_num = 0;
            this->scenarios = nullptr;
        }
        rge_close(fd);
    }

    this->reload_scenarios();
}

RGE_Scenario_File_Info::~RGE_Scenario_File_Info() {
    // Fully verified. Source of truth: sceninfo.cpp.decomp @ 0x0048CFD0
    this->save();

    if (this->scenario_num > 0 && this->scenarios != nullptr) {
        for (long i = 0; i < this->scenario_num; ++i) {
            if (this->scenarios[i].scenario_header != nullptr) {
                delete this->scenarios[i].scenario_header;
                this->scenarios[i].scenario_header = nullptr;
            }
        }

        free(this->scenarios);
        this->scenarios = nullptr;
        this->scenario_num = 0;
    }
}

void RGE_Scenario_File_Info::save() {
    // Fully verified. Source of truth: sceninfo.cpp.decomp @ 0x0048D040
    int fd = rge_open(this->filename, _O_BINARY | _O_WRONLY | _O_CREAT | _O_TRUNC, _S_IREAD | _S_IWRITE);
    if (fd == -1) {
        return;
    }

    rge_write(fd, &this->scenario_num, 4);

    for (long i = 0; i < this->scenario_num; ++i) {
        rge_write(fd, &this->scenarios[i].time, 4);
        rge_write(fd, this->scenarios[i].name, 0x104);
        if (this->scenarios[i].scenario_header != nullptr) {
            this->scenarios[i].scenario_header->save(fd);
        } else {
            rge_write_empty_scenario_header(fd);
        }
    }

    rge_close(fd);
}

void RGE_Scenario_File_Info::reload_scenarios() {
    // Fully verified. Source of truth: sceninfo.cpp.decomp @ 0x0048D0E0
    if (rge_base_game == nullptr || rge_base_game->prog_info == nullptr) {
        return;
    }

    char pattern[512];
    const char* scenario_dir = rge_base_game->prog_info->scenario_dir;

    sprintf(pattern, "%s*.scn", scenario_dir);
    long total = rge_count_matching_files(pattern);

    sprintf(pattern, "%s*.scx", scenario_dir);
    total += rge_count_matching_files(pattern);

    if (total <= 0) {
        return;
    }

    RGE_Scenario_File_Entry* new_scenarios =
        (RGE_Scenario_File_Entry*)calloc((size_t)total, sizeof(RGE_Scenario_File_Entry));
    if (new_scenarios == nullptr) {
        return;
    }

    long write_index = 0;
    bool looped_scx = false;
    _finddata_t file_info;

    sprintf(pattern, "%s*.scn", scenario_dir);
    long handle = _findfirst(pattern, &file_info);
    if (handle == -1) {
        sprintf(pattern, "%s*.scx", scenario_dir);
        handle = _findfirst(pattern, &file_info);
        looped_scx = true;
    }

    while (handle != -1) {
        bool found_in_list = false;

        for (long old_index = 0; old_index < this->scenario_num; ++old_index) {
            if (strcmp(file_info.name, this->scenarios[old_index].name) == 0) {
                if ((long)file_info.size <= this->scenarios[old_index].time) {
                    rge_copy_entry_name(new_scenarios[write_index].name, this->scenarios[old_index].name);
                    new_scenarios[write_index].time = this->scenarios[old_index].time;
                    new_scenarios[write_index].scenario_header = this->scenarios[old_index].scenario_header;
                    this->scenarios[old_index].scenario_header = nullptr;
                    found_in_list = true;
                }
                break;
            }
        }

        if (!found_in_list) {
            rge_copy_entry_name(new_scenarios[write_index].name, file_info.name);
            new_scenarios[write_index].time = (long)file_info.size;

            char full_path[512];
            sprintf(full_path, "%s%s", scenario_dir, file_info.name);

            int fd = rge_open(full_path, _O_RDONLY | _O_BINARY);
            if (fd != -1) {
                long version = 0;
                rge_read(fd, &version, 4);
                new_scenarios[write_index].scenario_header =
                    (rge_base_game != nullptr) ? rge_base_game->new_scenario_header(fd) : nullptr;
                rge_close(fd);
            }
        }

        write_index = write_index + 1;

        if (_findnext(handle, &file_info) == -1) {
            _findclose(handle);
            handle = -1;

            if (!looped_scx) {
                sprintf(pattern, "%s*.scx", scenario_dir);
                handle = _findfirst(pattern, &file_info);
                looped_scx = true;
            }
        }
    }

    if (this->scenarios != nullptr) {
        for (long i = 0; i < this->scenario_num; ++i) {
            if (this->scenarios[i].scenario_header != nullptr) {
                delete this->scenarios[i].scenario_header;
                this->scenarios[i].scenario_header = nullptr;
            }
        }
        free(this->scenarios);
    }

    this->scenarios = new_scenarios;
    this->scenario_num = write_index;
}

char* RGE_Scenario_File_Info::get_scenario_name(long param_1) {
    // Fully verified. Source of truth: sceninfo.cpp.decomp @ 0x0048D4D0
    if (param_1 >= 0 && param_1 < this->scenario_num && this->scenarios != nullptr) {
        return this->scenarios[param_1].name;
    }
    return nullptr;
}

RGE_Scenario_Header* RGE_Scenario_File_Info::get_scenario_info(long param_1) {
    // Fully verified. Source of truth: sceninfo.cpp.decomp @ 0x0048D500
    if (param_1 >= 0 && param_1 < this->scenario_num && this->scenarios != nullptr) {
        return this->scenarios[param_1].scenario_header;
    }
    return nullptr;
}
