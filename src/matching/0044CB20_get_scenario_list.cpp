// VA: 0044CB20 RGE_Campaign_Info::get_scenario_list(char***, long&)
// gameinfo.cpp lines 218-232, 131 bytes

void* __cdecl calloc(int count, int size);

struct RGE_Campaign {
    char* get_scenario_name(int index);
};

struct RGE_Campaign_Info {
    char name[256];           // +0x00
    int current_scenario;     // +0x100
    int scenario_num;         // +0x104
    char* scenario_info;      // +0x108
    int last_scenario;        // +0x10C
    RGE_Campaign* campaign;   // +0x110

    long get_scenario_list(char*** list, long& current);
};

void __cdecl getstring(char** dest, char* src);

long RGE_Campaign_Info::get_scenario_list(char*** list, long& current) {
    if (campaign) {
        *list = (char**)calloc(last_scenario + 1, 4);
        for (int i = 0; i <= last_scenario; i++) {
            getstring((*list) + i, campaign->get_scenario_name(i));
        }
        current = current_scenario;
        return last_scenario + 1;
    }
    current = -1;
    return -1;
}
