// VA: 0044D8C0 RGE_Game_Info::get_campaign_list(char***, long&)
// gameinfo.cpp lines 700-713, 121 bytes

#ifndef GAMEINFO_SHARED_CONTEXT
void* __cdecl calloc(int count, int size);

struct RGE_Campaign {
    char* get_name();
};

struct RGE_Person_Info {
    long get_current_campaign();
};

struct RGE_Game_Info {
    int current_person;       // +0x00
    int people_num;           // +0x04
    RGE_Person_Info** people_info;  // +0x08
    int campaign_num;         // +0x0C
    RGE_Campaign** campaigns; // +0x10

    long get_campaign_list(char*** list, long& current);
};

void __cdecl getstring(char** dest, char* src);
#endif

long RGE_Game_Info::get_campaign_list(char*** list, long& current) {
    if (campaign_num > 0) {
        *list = (char**)calloc(campaign_num, 4);
        for (int i = 0; i < campaign_num; i++) {
            getstring(*list + i, campaigns[i]->get_name());
        }
        if (current_person < people_num && current_person >= 0) {
            current = people_info[current_person]->get_current_campaign();
        }
    }
    return campaign_num;
}
