// VA: 0048CEA0 RGE_Scenario_File_Info::RGE_Scenario_File_Info
// PDB source: sceninfo.cpp
// Attempt log:
// - baseline candidate: natural typed constructor with the sceninfo entry layout,
//   real RGE_Base_Game virtual slot, and ordinary indexed entry loading.
// - positive outer count guard plus a function-scope loop counter improved call
//   topology but moved the zeroing ahead of the filename copy (rolled back).
// - declaration/context variants were duplicates or lost the second close/reload
//   paths; the best source initializes the long loop counter after rge_open.
// - final bounded pause: 99 positional bytes remain; all 11 calls and CFG counts
//   align, with a localized zero-register/second-count scheduling difference.

#include <stdlib.h>
#include <string.h>

extern "C" {
    int rge_open(char* filename, int mode);
    void rge_read_uncompressed(int fd, void* buf, int size);
    void rge_close(int fd);
}

class RGE_Scenario_Header;

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

RGE_Scenario_File_Info::RGE_Scenario_File_Info(char* path)
{
    strcpy(this->filename, path);

    int fd = rge_open(this->filename, 0x8000);
    long i = 0;
    if (fd != -1) {
        rge_read_uncompressed(fd, &this->scenario_num, 4);

        if (this->scenario_num > 0) {
            this->scenarios = (RGE_Scenario_File_Entry*)calloc(this->scenario_num, 0x10C);

            if (this->scenario_num > 0) {
                for (; i < this->scenario_num; i++) {
                    rge_read_uncompressed(fd, &this->scenarios[i].time, 4);
                    rge_read_uncompressed(fd, this->scenarios[i].name, 0x104);
                    this->scenarios[i].scenario_header = rge_base_game->new_scenario_header(fd);
                }
            }
        } else {
            this->scenarios = 0;
        }

        rge_close(fd);
        this->reload_scenarios();
    } else {
        this->scenario_num = 0;
        this->scenarios = 0;
        this->reload_scenarios();
    }
}
