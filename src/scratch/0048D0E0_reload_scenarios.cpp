// VA: 0048D0E0 RGE_Scenario_File_Info::reload_scenarios
// PDB source: sceninfo.cpp
// File enumeration, name matching, scenario reload
//
// Attempt log:
// - baseline reconstruction: period-plausible typed _finddata_t traversal,
//   named scenario-entry ownership, typed base-game virtual header creation,
//   and natural delete/free cleanup. Raw decompiler cursors were removed.
// - probe: use the source-like pre-tested `while` scan for existing entries and
//   reorder the long-lived locals toward the sceninfo declaration order.
// - probe: use the named scenario array directly for existing-entry lookup,
//   removing the extra destination-header cursor and keeping ownership typed.
// - probe: restored the PDB/decompiler-indicated long `version` local between
//   the output pointer and file buffers to test the missing 4-byte local window.
// - probe: grouped the proven contiguous file-name/version/find-data work
//   window in a typed aggregate, preserving the name base while adding the
//   binary-observed 4-byte gap before _finddata_t.
// - final pass: a typed old-name alias regressed frame/CFG; restored the
//   direct indexed array form. Best source is exact-size/frame with all 22
//   calls aligned; remaining drift is the handle/name stack-home order and
//   late block placement.
// - same-corpus VC5 _finddata_t layout was modeled explicitly. Removing the
//   decompiler-shaped file_info.name + 4 moved the best diff from 277 to 274;
//   separate file/find-data locals and typed cursor variants regressed frame or
//   block shape. The unused function-scope version local had no emitted effect
//   and was removed. Final source keeps the typed aggregate and direct index.
// - paused after bounded probes: exact size/frame and all 22 calls align. The
//   remaining drift is the original count/old-entry stack-home swap plus late
//   block placement.
// - Main-agent audit corrected a new entry's cached time to time_write. The
//   executable compares that same timestamp when it decides to reuse a header.
// Main-agent audit confirmed the binary-proven typed filename/version/find-data
// work window and retained natural enumeration, ownership transfer, and cleanup.
// - first-hunk layout probe: moving the typed reload-work aggregate after the
//   scalar declarations emitted an exact duplicate; restored the clean order.
// - binary note: writing the open-success guard as `fd > -1` restores the
//   original cmp -1/jle form. `fd >= 0` emits test/jl and shifts the suffix.
// - binary note: the original keeps the final search count at [esp+18h] and
//   uses [esp+14h] for a transient entry/name cursor. The clean source emits
//   these two proven homes in reverse order; 23 focused probes did not resolve
//   that compiler allocation difference without less natural source.
// - likely intent: the two initial file scans are guarded do/while searches;
//   the donor-supported form preserves their shipped enumeration behavior.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _finddata_t {
    unsigned attrib;
    long time_create;
    long time_access;
    long time_write;
    unsigned long size;
    char name[260];
};

extern "C" {
    long _findfirst(const char* pattern, struct _finddata_t* file_info);
    int _findnext(long handle, struct _finddata_t* file_info);
}

extern "C" {
    int rge_open(char* filename, int mode);
    void rge_read_uncompressed(int fd, void* buf, int size);
    void rge_close(int fd);
}

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

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual RGE_Scenario_Header* new_scenario_header(int fd);

    RGE_Game_Info* player_game_info;
    char gap_008[4];
    RGE_Prog_Info* prog_info;
};

extern RGE_Base_Game* rge_base_game;

struct RGE_Scenario_File_Entry {
    long time;
    RGE_Scenario_Header* scenario_header;
    char name[260];
};

struct RGE_Scenario_Reload_Work {
    char file_name[256];
    long version;
    struct _finddata_t file_info;
};

class RGE_Scenario_File_Info {
public:
    char filename[260];
    long scenario_num;
    RGE_Scenario_File_Entry* scenarios;

    void reload_scenarios();
};

void RGE_Scenario_File_Info::reload_scenarios()
{
    RGE_Scenario_Reload_Work work;
    long handle;
    long count;
    int total = 0;
    char looped = 0;
    RGE_Scenario_File_Entry* new_scenarios;
    RGE_Scenario_File_Entry* current;
    int index;
    char found_in_list;

    sprintf(work.file_name + 4, "%s*.scn", rge_base_game->prog_info->scenario_dir);
    handle = _findfirst(work.file_name + 4, &work.file_info);
    if (handle != -1) {
        do {
            ++total;
        } while (_findnext(handle, &work.file_info) != -1);
    }

    sprintf(work.file_name + 4, "%s*.scx", rge_base_game->prog_info->scenario_dir);
    handle = _findfirst(work.file_name + 4, &work.file_info);
    if (handle != -1) {
        do {
            ++total;
        } while (_findnext(handle, &work.file_info) != -1);
    }

    sprintf(work.file_name + 4, "%s*.scn", rge_base_game->prog_info->scenario_dir);
    if (total <= 0)
        return;

    count = _findfirst(work.file_name + 4, &work.file_info);
    if (count == -1) {
        sprintf(work.file_name + 4, "%s*.scx", rge_base_game->prog_info->scenario_dir);
        count = _findfirst(work.file_name + 4, &work.file_info);
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
            if (strcmp(this->scenarios[index].name, work.file_info.name) == 0) {
                if (work.file_info.time_write <= this->scenarios[index].time) {
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
            strcpy(current->name, work.file_info.name);
            current->time = work.file_info.time_write;

            sprintf(work.file_name + 4, "%s%s",
                    rge_base_game->prog_info->scenario_dir,
                    work.file_info.name);
            int fd = rge_open(work.file_name + 4, 0x8000);
            if (fd > -1) {
                rge_read_uncompressed(fd, work.file_name, 4);
                current->scenario_header = rge_base_game->new_scenario_header(fd);
                rge_close(fd);
            }
        }

        ++current;

        if (_findnext(count, &work.file_info) == -1) {
            if (looped)
                break;

            sprintf(work.file_name + 4, "%s*.scx", rge_base_game->prog_info->scenario_dir);
            count = _findfirst(work.file_name + 4, &work.file_info);
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
