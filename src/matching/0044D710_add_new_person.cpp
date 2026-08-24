// VA: 0044D710 RGE_Game_Info::add_new_person(int fd)
// 179 bytes

#include <string.h>

#ifndef GAMEINFO_SHARED_CONTEXT
void* __cdecl calloc(int count, int size);
void __cdecl free(void*);

struct RGE_Campaign;

struct RGE_Person_Info {
    char name[256];
    int current_campaign;
    int campaign_info_num;
    void** campaign_info;
    int campaign_num;
    RGE_Campaign** campaigns;

    RGE_Person_Info(int fd, RGE_Campaign** camps, long cnum);
};

struct RGE_Game_Info {
    int current_person;
    int people_num;
    RGE_Person_Info** people_info;
    int campaign_num;
    RGE_Campaign** campaigns;
    char save_filename[256];

    unsigned char add_new_person(int fd);
};
#endif

unsigned char RGE_Game_Info::add_new_person(int fd) {
    RGE_Person_Info** newlist = (RGE_Person_Info**)calloc(people_num + 1, 4);
    memcpy(newlist, people_info, people_num * 4);
    free(people_info);
    people_info = newlist;
    people_info[people_num] = new RGE_Person_Info(fd, campaigns, campaign_num);
    current_person = people_num;
    people_num++;
    return 1;
}
