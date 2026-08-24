// first pass: direct people-count gate, calloc-sized pointer array, and per-person string copies
// if this is sticky, the remaining work is likely just the exact loop/index spill shape around the copy helper
#include <stdlib.h>

#ifndef GAMEINFO_SHARED_CONTEXT
class RGE_Person_Info {
public:
    char* get_name(void);
};

class RGE_Game_Info {
public:
    long current_person;
    long people_num;
    RGE_Person_Info** people_info;
    long campaign_num;
    void* campaigns;
    char save_filename[260];

    long get_people_list(char*** out_list, long& out_current);
};

extern void getstring(char** param_1, char* param_2);
#endif

long RGE_Game_Info::get_people_list(char*** out_list, long& out_current) {
    char* name;
    int iVar3;
    char** ppcVar1;

    if (0 < this->people_num) {
        ppcVar1 = (char**)calloc(this->people_num, 4);
        iVar3 = 0;
        *out_list = ppcVar1;
        if (0 < this->people_num) {
            do {
                name = this->people_info[iVar3]->get_name();
                getstring(*out_list + iVar3, name);
                iVar3 = iVar3 + 1;
            } while (iVar3 < this->people_num);
        }
        out_current = this->current_person;
    }
    return this->people_num;
}
