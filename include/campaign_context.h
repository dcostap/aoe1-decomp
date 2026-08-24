#ifndef CAMPAIGN_CONTEXT_H
#define CAMPAIGN_CONTEXT_H

#include <string.h>

// PDB campaign.cpp shared records.  The shipped file uses one 0x20C campaign
// object and 0x208-byte scenario entries across all nine source-line bands.
class RGE_Scenario_Offset {
public:
    long size;
    long offset;
    char name[255];
    char file_name[255];
    unsigned char _pad_end[2];
};

struct RGE_Campaign_Header {
    long version;
    char name[255];
    unsigned char _pad_103;
    long scenario_num;
};

class RGE_Campaign {
public:
    RGE_Campaign_Header campaign_header;
    RGE_Scenario_Offset* scenario_offsets;
    char filename[255];
    unsigned char _pad_end;

    RGE_Campaign(char* param1);
    RGE_Campaign(char* param1, char* param2, long count,
                 char** names, char** filenames);
    ~RGE_Campaign();
    void create_file();
    int open_scenario(long index);
    char* get_name();
    long scenario_number();
    long scenario_info(char*** param1);
    char* get_scenario_name(long index);
};

class RGE_Prog_Info {
public:
    char _gap_00[0xC17];
    char scenario_dir[256];
    unsigned char _gap_C17[5];
    char campaign_dir[256];
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char _gap_04[0x08];
    RGE_Prog_Info* prog_info;
};

extern RGE_Base_Game* rge_base_game;
extern long campaign_version;

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
extern "C" void* __cdecl calloc(int, int);
extern "C" void __cdecl free(void*);
extern "C" int __cdecl rge_fake_open(int, int);
extern "C" void __cdecl getstring(char**, char*);

#endif
