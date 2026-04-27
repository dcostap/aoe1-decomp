// VA: 0048D0E0 RGE_Scenario_File_Info::reload_scenarios
// PDB source: sceninfo.cpp
// File enumeration, name matching, scenario reload
//
// Attempt log:
// - First pass: simplified extern stubs

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>

extern "C" {
    int rge_open(char* filename, int mode);
    void rge_read_uncompressed(int fd, void* buf, int size);
    void rge_close(int fd);
    void* calloc(size_t count, size_t size);
    void free(void* ptr);
}

extern void* rge_base_game;

struct RGE_Scenario_File_Entry {
    int time;
    void* hdr;
    char name[0x104];
};

class RGE_Scenario_File_Info {
public:
    char filename[0x104];
    int scenario_num;
    RGE_Scenario_File_Entry* scenarios;
    void reload_scenarios();
};

void RGE_Scenario_File_Info::reload_scenarios()
{
    char file_name[256];
    struct _finddata_t file_info;
    long fh;
    long count = -1;
    int total = 0;
    int flag = 0;
    int i;
    RGE_Scenario_File_Entry* new_scenarios;
    RGE_Scenario_File_Entry* cur;
    char* base;
    int idx;
    int found;
    int fd;
    void* bg;
    void* vt;

    // Phase 1: Count .scn files
    bg = rge_base_game;
    sprintf(file_name + 4, "%s*.scn", (char*)(*(char**)((char*)bg + 0xC) + 0xC17));
    fh = _findfirst(file_name + 4, &file_info);
    while (fh != -1) {
        total++;
        if (_findnext(fh, &file_info) == -1)
            break;
    }

    // Phase 2: Count .scx files
    bg = rge_base_game;
    sprintf(file_name + 4, "%s*.scx", (char*)(*(char**)((char*)bg + 0xC) + 0xC17));
    fh = _findfirst(file_name + 4, &file_info);
    while (fh != -1) {
        total++;
        if (_findnext(fh, &file_info) == -1)
            break;
    }

    // Phase 3: Reload
    bg = rge_base_game;
    sprintf(file_name + 4, "%s*.scn", (char*)(*(char**)((char*)bg + 0xC) + 0xC17));
    if (total <= 0)
        return;

    count = _findfirst(file_name + 4, &file_info);
    if (count == -1) {
        bg = rge_base_game;
        sprintf(file_name + 4, "%s*.scx", (char*)(*(char**)((char*)bg + 0xC) + 0xC17));
        count = _findfirst(file_name + 4, &file_info);
        flag = 1;
    }

    if (count == -1)
        return;

    new_scenarios = (RGE_Scenario_File_Entry*)calloc(total, 0x10C);
    cur = new_scenarios;

    do {
        found = 0;
        idx = 0;
        base = (char*)scenarios;

        if (scenario_num > 0) {
            char* ename = base + 8;
            do {
                // Custom strcmp equivalent
                char* a = ename;
                char* b = file_info.name + 4;
                int r;
                while (*a == *b && *a != 0) {
                    a++;
                    b++;
                }
                if (*a == *b)
                    r = 0;
                else if (*a < *b)
                    r = -1;
                else
                    r = 1;

                if (r == 0 && file_info.size <= ((RGE_Scenario_File_Entry*)(base + idx * 0x10C))->time) {
                    strcpy(cur->name, ename);
                    found = 1;
                    cur->time = ((RGE_Scenario_File_Entry*)(base + idx * 0x10C))->time;
                    cur->hdr = ((RGE_Scenario_File_Entry*)(base + idx * 0x10C))->hdr;
                    ((RGE_Scenario_File_Entry*)(base + idx * 0x10C))->hdr = 0;
                    break;
                }
                idx++;
                ename += 0x10C;
            } while (idx < scenario_num);
        }

        if (!found) {
            strcpy(cur->name, file_info.name + 4);
            cur->time = file_info.size;

            bg = rge_base_game;
            sprintf(file_name + 4, "%s%s", (char*)(*(char**)((char*)bg + 0xC) + 0xC17), file_info.name + 4);
            fd = rge_open(file_name + 4, 0x8000);
            if (fd >= 0) {
                rge_read_uncompressed(fd, file_name, 4);
                bg = rge_base_game;
                vt = *(void**)bg;
                cur->hdr = (void*)((void*(__cdecl*)(int))((void**)vt)[0x38/4])(fd);
                rge_close(fd);
            }
        }

        cur++;

        if (_findnext(count, &file_info) == -1) {
            if (flag)
                goto do_cleanup;
            bg = rge_base_game;
            sprintf(file_name + 4, "%s*.scx", (char*)(*(char**)((char*)bg + 0xC) + 0xC17));
            count = _findfirst(file_name + 4, &file_info);
            if (count == -1)
                goto do_cleanup;
            flag = 1;
        }
    } while (1);

do_cleanup:
    if (scenarios) {
        for (i = 0; i < scenario_num; i++) {
            void* h = ((RGE_Scenario_File_Entry*)(base + i * 0x10C))->hdr;
            if (h)
                free(h);
        }
        free(scenarios);
    }

    scenarios = new_scenarios;
    scenario_num = total;
}
