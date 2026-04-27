// VA: 0048CEA0 RGE_Scenario_File_Info::RGE_Scenario_File_Info
// PDB source: sceninfo.cpp

#include <stdlib.h>
#include <string.h>
#include <string.h>

extern "C" {
    int rge_open(char* filename, int mode);
    void rge_read_uncompressed(int fd, void* buf, int size);
    void rge_close(int fd);
    void free(void* ptr);
}

struct RGE_Scenario_Header {
    virtual void dummy0() {}
    virtual void dummy1() {}
};

struct RGE_Scenario_File_Entry {
    int time;                  // +0x00
    RGE_Scenario_Header* hdr;  // +0x04
    char name[0x104];          // +0x08
};

class RGE_Scenario_File_Info {
public:
    char filename[0x104];     // +0x000
    int scenario_num;          // +0x104
    RGE_Scenario_File_Entry* scenarios; // +0x108

    RGE_Scenario_File_Info(char* path);
    void reload_scenarios();
};

// External base game pointer for scenario header creation
extern void* rge_base_game;

RGE_Scenario_File_Info::RGE_Scenario_File_Info(char* path)
{
    // Copy filename from path (strcpy equivalent)
    strcpy(filename, path);

    int fd = rge_open(filename, 0x8000);
    if (fd != -1) {
        rge_read_uncompressed(fd, &scenario_num, 4);

        if (scenario_num > 0) {
            scenarios = (RGE_Scenario_File_Entry*)calloc(scenario_num, 0x10C);

            if (scenario_num > 0) {
                for (int i = 0; i < scenario_num; i++) {
                    char* entry = (char*)scenarios;
                    int off = i * 0x10C;
                    rge_read_uncompressed(fd, entry + off, 4);            // read time at +0
                    rge_read_uncompressed(fd, entry + off + 8, 0x104);     // read name at +8

                    // Create scenario header via virtual call through rge_base_game
                    void* bg = rge_base_game;
                    void* vt = *(void**)bg;
                    RGE_Scenario_Header* h = (RGE_Scenario_Header*)((void*(__cdecl*)(int))((void**)vt)[0x38/4])(fd);
                    ((RGE_Scenario_File_Entry*)(entry + off))->hdr = h;
                }
            }
        } else {
            scenarios = 0;
        }

        rge_close(fd);
        reload_scenarios();
    } else {
        scenario_num = 0;
        scenarios = 0;
        reload_scenarios();
    }
}
