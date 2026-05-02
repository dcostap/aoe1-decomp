// VA: 0044C5A0 RGE_Campaign_Info ctor (474B)
// gameinfo.cpp

#include <stdlib.h>

int __cdecl rge_read(int fd, void* buf, int size);
void* __cdecl calloc(int count, int size);
void __cdecl free(void*);

class RGE_Campaign {
public:
    char* get_name(void);
    int scenario_number(void);
};

class RGE_Campaign_Info {
public:
    char name[256];             // +0x000
    int current_scenario;       // +0x100
    int scenario_num;           // +0x104
    char* scenario_info;        // +0x108
    int last_scenario;          // +0x10C
    RGE_Campaign* campaign;     // +0x110

    RGE_Campaign_Info(int fd, RGE_Campaign** camps, int cnum);
};

RGE_Campaign_Info::RGE_Campaign_Info(int fd, RGE_Campaign** camps, int cnum) {
    rge_read(fd, this, 0xFF);
    rge_read(fd, &current_scenario, 4);
    rge_read(fd, &scenario_num, 4);
    rge_read(fd, &last_scenario, 4);
    
    if (scenario_num > 0) {
        scenario_info = (char*)calloc(scenario_num, 1);
        rge_read(fd, scenario_info, scenario_num);
    } else {
        scenario_info = 0;
    }
    
    campaign = 0;
    
    if (cnum > 0) {
        int i = cnum;
        RGE_Campaign** pcamp = camps;
        int loop_counter = cnum;
        
        while (loop_counter > 0) {
            RGE_Campaign* cp = *pcamp;
            char* camp_name = cp->get_name();
            
            // Inline strcmp loop (unrolled 2 chars at a time)
            char* a = camp_name;
            char* b = name;
            int result;
            while (1) {
                char ca = *a;
                char cb = *b;
                if (ca != cb) {
                    if (ca < cb) result = -1;
                    else result = 1;
                    break;
                }
                if (ca == 0) {
                    result = 0;
                    break;
                }
                a++;
                b++;
                ca = *a;
                cb = *b;
                if (ca != cb) {
                    if (ca < cb) result = -1;
                    else result = 1;
                    break;
                }
                if (ca == 0) {
                    result = 0;
                    break;
                }
                a++;
                b++;
            }
            
            if (result == 0) {
                campaign = cp;
                if (cp->scenario_number() != current_scenario) {
                    if (cp->scenario_number() > current_scenario) {
                        char* new_info = (char*)calloc(cp->scenario_number() + 1, 1);
                        int sc = current_scenario;
                        if (sc < cp->scenario_number()) {
                            for (int k = 0; k < sc; k++) new_info[k] = scenario_info[k];
                        } else {
                            for (int k = 0; k < cp->scenario_number(); k++) new_info[k] = scenario_info[k];
                        }
                        free(scenario_info);
                        scenario_info = new_info;
                    }
                    
                    current_scenario = cp->scenario_number();
                    if (last_scenario >= current_scenario) {
                        last_scenario = current_scenario - 1;
                    }
                    if (this->current_scenario > last_scenario) {
                        this->current_scenario = last_scenario;
                    }
                }
            }
            
            loop_counter--;
            pcamp++;
        }
    }
}
