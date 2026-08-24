// VA: 0048D0E0 RGE_Scenario_File_Info::reload_scenarios
// PDB source: sceninfo.cpp
// File enumeration, name matching, scenario reload
//
// Attempt log:
// - baseline reconstruction: period-plausible typed _finddata_t traversal,
//   named scenario-entry ownership, typed base-game virtual header creation,
//   and natural delete/free cleanup.
// - source-gate audit: file_name and _finddata_t remain separate typed locals;
//   new_scenario_header(int) is the named virtual method for slot 0x38.
// - binary note: `fd > -1` preserves the observed cmp -1/jle open-success form.
// - binary note: the two initial scans use guarded do/while searches.
// - BINARY NOTE: file_info begins 0x104 bytes after file_name.  The 260-byte
//   file_name object is required; a 256-byte buffer rebuilds a 0x22C frame.
// - frontier audit: the natural local, scope, declaration-order, _finddata_t,
//   handle-width, and canonical virtual-surface probes retained 22 ordered
//   calls and the 0x230 frame.  The remaining 10 bytes are only the swapped
//   count and transient old-entry dword-home displacements.
// ACCEPTED DRIFT: All ten differing bytes consistently exchange the two dword
// stack homes at ESP+0x14 and ESP+0x18. Neither home's address escapes. Every
// read follows the matching write in both builds, and register use after each
// load is identical. Calls, values, writes, predicates, cleanup, and faults are
// therefore equal. All non-displacement bytes match.
//
// Exact-finish audit: reusing one find handle, changing four-byte signed types,
// swapping handle phases, naming the old-entry pointer, and splitting the
// looped initializer did not change this exchange. The clean source remains
// the smallest supported reconstruction.
//
// Exact-finish audit update: a fresh build also kept this exchange after
// swapping the count and handle declarations and after scoping the first-scan
// handle. The fresh grouped result is 985 equal bytes and 10 differing
// displacement bytes. The exact screen/list callers at 004B44F0 and 004B5E00
// remain separate anchors; their fresh checks are exact.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef AOE1_SCENINFO_TU_CONTEXT
struct _finddata_t {
    unsigned attrib;
    long time_create;
    long time_access;
    long time_write;
    unsigned long size;
    char name[260];
};
#endif

#ifndef AOE1_SCENINFO_TU_CONTEXT
extern "C" {
    long _findfirst(const char* pattern, struct _finddata_t* file_info);
    int _findnext(long handle, struct _finddata_t* file_info);
}
#endif

#ifndef AOE1_SCENINFO_TU_CONTEXT
extern "C" {
    int rge_open(char* filename, int mode);
    void rge_read_uncompressed(int fd, void* buf, int size);
    void rge_close(int fd);
}
#endif

#ifndef AOE1_SCENINFO_TU_CONTEXT
class RGE_Scenario_Header {
public:
    ~RGE_Scenario_Header();
};

class RGE_Prog_Info {
public:
    char gap_000[0xC17];
    char scenario_dir[256];
};

class RGE_Game_Info;
class RGE_Scenario;
class RGE_Scenario_File_Info;
class TPanel;

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void* param_1, unsigned int param_2,
                          unsigned int param_3, long param_4);
    virtual void set_prog_mode(int param_1);
    virtual void set_game_mode(int param_1, int param_2);
    virtual void set_player(short param_1);
    virtual int get_error_code();
    virtual char* get_string(int param_1, long param_2, char* param_3,
                             int param_4);
    virtual char* get_string(long param_1, char* param_2, int param_3);
    virtual char* get_string(long param_1);
    virtual char* get_string2(int param_1, long param_2, long param_3,
                              char* param_4, int param_5);
    virtual TPanel* get_view_panel();
    virtual TPanel* get_map_panel();
    virtual RGE_Scenario_Header* new_scenario_header(int fd);
    virtual RGE_Scenario_Header* new_scenario_header(RGE_Scenario* scenario);

    RGE_Game_Info* player_game_info;
    RGE_Scenario_File_Info* scenario_info;
    RGE_Prog_Info* prog_info;
};

extern RGE_Base_Game* rge_base_game;

struct RGE_Scenario_File_Entry {
    long time;
    RGE_Scenario_Header* scenario_header;
    char name[260];
};

class RGE_Scenario_File_Info {
public:
    char filename[260];
    long scenario_num;
    RGE_Scenario_File_Entry* scenarios;

    void reload_scenarios();
};
#endif

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

    new_scenarios = (RGE_Scenario_File_Entry*)calloc(total, 0x10C);
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
