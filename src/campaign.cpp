// PDB source module: C:\\msdev\\work\\age1_x1\\campaign.cpp.
// Definitions follow the original source order.

#include "../include/campaign.h"
#include "../include/main.h"
#include "../include/mystring.h"

#include <string.h>

// These declarations name the period CRT and executable helpers used by this
// source.  Their direct call targets are part of the recovered owners.
extern "C" int __cdecl sprintf(char*, const char*, ...);
extern "C" int __cdecl open(const char*, int);
extern "C" int __cdecl __open(const char*, int, ...);
extern "C" int __cdecl _open(const char*, int);
extern "C" int __cdecl read(int, void*, int);
extern "C" int __cdecl write(int, void*, int);
extern "C" int __cdecl close(int);
extern "C" int __cdecl lseek(int, int, int);
extern "C" int __cdecl _lseek(int, int, int);
extern "C" int __cdecl __tell(int);
extern "C" void* __cdecl calloc(unsigned int, unsigned int);
extern "C" void __cdecl free(void*);
extern "C" int __cdecl rge_fake_open(int, int);

// VA 00423230 | campaign.cpp lines 22-54.
RGE_Campaign::RGE_Campaign(char* param1)
{
    sprintf(this->filename, "%s%s", rge_base_game->prog_info->campaign_dir, param1);

    int handle = open(this->filename, 0x8000);
    if (handle >= 0) {
        read(handle, this, 0x108);
        if (this->campaign_header.scenario_num > 0) {
            this->scenario_offsets = (RGE_Scenario_Offset*)calloc(
                this->campaign_header.scenario_num, 0x208);
            read(handle, this->scenario_offsets,
                this->campaign_header.scenario_num * 0x208);
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

// VA 00423330 | campaign.cpp lines 65-90.
RGE_Campaign::RGE_Campaign(char* param1, char* param2, long count,
                           char** names, char** filenames)
{
    sprintf(this->filename, "%s%s", rge_base_game->prog_info->campaign_dir, param1);

    this->campaign_header.version = campaign_version;
    strcpy(this->campaign_header.name, param2);
    this->campaign_header.scenario_num = count;

    if (count > 0) {
        this->scenario_offsets = (RGE_Scenario_Offset*)calloc(count, 0x208);
        for (long i = 0; i < count; ++i) {
            strcpy(this->scenario_offsets[i].name, filenames[i]);
            strcpy(this->scenario_offsets[i].file_name, names[i]);
        }
    } else {
        this->scenario_offsets = 0;
    }

    this->create_file();
}

// VA 00423480 | campaign.cpp lines 94-100.
RGE_Campaign::~RGE_Campaign()
{
    if (this->scenario_offsets != 0) {
        free(this->scenario_offsets);
        this->scenario_offsets = 0;
    }
}

// VA 004234B0 | campaign.cpp lines 104-169.
void RGE_Campaign::create_file()
{
    int fd;
    int output_offset;
    int current_offset;
    char tempname[300];

    fd = __open(this->filename, 0x8301, 0x180);
    if (fd >= 0) {
        write(fd, this, 0x108);
        if (this->campaign_header.scenario_num > 0) {
            write(fd, this->scenario_offsets,
                this->campaign_header.scenario_num * 0x208);
            current_offset = 0;
            output_offset = this->campaign_header.scenario_num * 0x208 + 0x108;
            if (this->campaign_header.scenario_num > 0) {
                do {
                    sprintf(tempname, "%s%s",
                        rge_base_game->prog_info->scenario_dir,
                        this->scenario_offsets[current_offset].file_name);
                    int scenario_file = __open(tempname, 0x8000);
                    if (scenario_file > -1) {
                        lseek(scenario_file, 0, 2);
                        int size = __tell(scenario_file);
                        void* buffer = calloc(size, 1);
                        lseek(scenario_file, 0, 0);
                        read(scenario_file, buffer, size);
                        write(fd, buffer, size);
                        this->scenario_offsets[current_offset].offset = output_offset;
                        this->scenario_offsets[current_offset].size = size;
                        output_offset += size;
                        free(buffer);
                        close(scenario_file);
                    }
                    ++current_offset;
                } while (current_offset < this->campaign_header.scenario_num);
            }
            lseek(fd, 0x108, 0);
            write(fd, this->scenario_offsets,
                this->campaign_header.scenario_num * 0x208);
        }
        close(fd);
    }
}

// VA 00423690 | campaign.cpp lines 175-193.
int RGE_Campaign::open_scenario(long index)
{
    if (index >= 0 && index < this->campaign_header.scenario_num) {
        int h = _open(this->filename, 0x8000);
        if (h >= 0) {
            _lseek(h, this->scenario_offsets[index].offset, 0);
            rge_fake_open(h, this->scenario_offsets[index].size);
            return h;
        }
    }
    return -1;
}

// VA 00423710 | campaign.cpp lines 198-200.
char* RGE_Campaign::get_name()
{
    return this->campaign_header.name;
}

// VA 00423720 | campaign.cpp lines 205-207.
long RGE_Campaign::scenario_number()
{
    return this->campaign_header.scenario_num;
}

// VA 00423730 | campaign.cpp lines 212-223.
long RGE_Campaign::scenario_info(char*** list)
{
    char** strings = (char**)calloc(
        (unsigned int)this->campaign_header.scenario_num, 4);
    *list = strings;

    int i = 0;
    if (0 < this->campaign_header.scenario_num) {
        do {
            getstring(strings + i, this->scenario_offsets[i].name);
            ++i;
        } while (i < this->campaign_header.scenario_num);
    }

    return this->campaign_header.scenario_num;
}

// VA 004237A0 | campaign.cpp lines 227-229.
char* RGE_Campaign::get_scenario_name(long index)
{
    return this->scenario_offsets[index].name;
}
