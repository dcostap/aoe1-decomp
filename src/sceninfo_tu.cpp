// Authentic sceninfo.cpp candidate translation unit.
//
// The PDB owner order is 26-61, 67-80, 86-105, 111-230, 236-240,
// and 246-250.  The owner files stay independently checkable.  This guard
// selects the one module-local declaration surface when they are included.
#define AOE1_SCENINFO_TU_CONTEXT 1

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
    int rge_open(char* filename, int mode, ...);
    void rge_read_uncompressed(int fd, void* buf, int size);
    void rge_write_uncompressed(int fd, void* buf, int size);
    int rge_close(int fd);
    long _findfirst(const char* pattern, struct _finddata_t* file_info);
    int _findnext(long handle, struct _finddata_t* file_info);
}

extern void __cdecl operator_delete(void* block);

class RGE_Scenario_Header {
public:
    // The module calls save through vtable slot +4.  The shipped sceninfo
    // cleanup calls the complete destructor directly, so its destructor is
    // not declared virtual in this module-local surface.
    virtual void vtable_slot_00();
    virtual void save(int fd);
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

    RGE_Scenario_File_Info(char* path);
    ~RGE_Scenario_File_Info();
    void save();
    void reload_scenarios();
    char* get_scenario_name(long index);
    RGE_Scenario_Header* get_scenario_info(long index);
};

#include "matching/0048CEA0_RGE_Scenario_File_Info.cpp"
#include "matching/0048CFD0_RGE_Scenario_File_Info.cpp"
#include "accepted_drift/0048D040_save.cpp"
#include "accepted_drift/0048D0E0_reload_scenarios.cpp"
#include "matching/0048D4D0_get_scenario_name.cpp"
#include "scratch/0048D500_get_scenario_info.cpp"

#undef AOE1_SCENINFO_TU_CONTEXT
