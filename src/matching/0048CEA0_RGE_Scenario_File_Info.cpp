// VA: 0048CEA0 RGE_Scenario_File_Info::RGE_Scenario_File_Info
// PDB source: sceninfo.cpp
// Attempt log:
// - baseline candidate: natural typed constructor with the sceninfo entry layout,
//   real RGE_Base_Game virtual slot, and ordinary indexed entry loading.
// - positive outer count guard plus a function-scope loop counter improved call
//   topology but moved the zeroing ahead of the filename copy (rolled back).
// - declaration/context variants were duplicates or lost the second close/reload
//   paths; the best source initializes the long loop counter after rge_open.
// - this claim's after-read counter, allocation-result, count-pointer, and
//   volatile-reread probes were reverted; the explicit positive-tail return is
//   the best plausible source shape found here.
// - this claim's inverted outer guard was structural and was rolled back;
//   unqualified strcpy was an emitted duplicate. Reusing i for the failed-open
//   zero stores removed the tail drift. Ordinary zero assignments emit the
//   same exact code. A natural pre-tested counted loop under the outer positive
//   guard reproduces the original store-before-count-reload schedule.
// Main-agent audit confirmed canonical base-game/header/scenario-entry ownership
// and retained the ordinary indexed loader.

#include <stdlib.h>
#include <string.h>

#ifndef AOE1_SCENINFO_TU_CONTEXT
extern "C" {
    int rge_open(char* filename, int mode);
    void rge_read_uncompressed(int fd, void* buf, int size);
    void rge_close(int fd);
}
#endif

#ifndef AOE1_SCENINFO_TU_CONTEXT
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
#endif

RGE_Scenario_File_Info::RGE_Scenario_File_Info(char* path)
{
    long i;

    strcpy(filename, path);

    int fd = rge_open(this->filename, 0x8000);
    if (fd != -1) {
        rge_read_uncompressed(fd, &this->scenario_num, 4);
        i = 0;

        if (this->scenario_num > 0) {
            this->scenarios = (RGE_Scenario_File_Entry*)calloc(this->scenario_num, 0x10C);
            for (i = 0; i < this->scenario_num; i++) {
                rge_read_uncompressed(fd, &this->scenarios[i].time, 4);
                rge_read_uncompressed(fd, this->scenarios[i].name, 0x104);
                this->scenarios[i].scenario_header = rge_base_game->new_scenario_header(fd);
            }

            rge_close(fd);
            this->reload_scenarios();
            return;
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
