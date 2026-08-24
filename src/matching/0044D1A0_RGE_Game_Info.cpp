// VA: 0044D1A0 RGE_Game_Info::RGE_Game_Info(char* path)
// 346 bytes
// Matched 2026-05-31: hoisting the address-taken version local to function scope
// forced VC5 to use the original stack local instead of reusing the dead path parameter slot.

#include <string.h>

#ifndef GAMEINFO_SHARED_CONTEXT
int __cdecl rge_open(char* path, int mode);
int __cdecl rge_close(int fd);
int __cdecl rge_read(int fd, void* buf, int size);
void __cdecl free(void*);
void* __cdecl calloc(int count, int size);

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

    void find_campaigns();
    RGE_Game_Info(char* path);
};

extern int version_marker;
#endif

RGE_Game_Info::RGE_Game_Info(char* path) {
    int ver;

    people_info = 0;
    people_num = 0;
    campaign_num = 0;
    campaigns = 0;
    find_campaigns();
    strcpy(save_filename, path);
    int fd = rge_open(path, 0x8000);
    if (fd > -1) {
        rge_read(fd, &ver, 4);
        if (ver == version_marker) {
            rge_read(fd, this, 4);
            rge_read(fd, &people_num, 4);
            if (people_num > 0) {
                people_info = (RGE_Person_Info**)calloc(people_num, 4);
                for (int i = 0; i < people_num; i++) {
                    people_info[i] = new RGE_Person_Info(fd, campaigns, campaign_num);
                }
            } else {
                people_info = 0;
            }
            rge_close(fd);
        } else {
            current_person = -1;
            people_num = 0;
            people_info = 0;
        }
    } else {
        current_person = -1;
        people_num = 0;
        people_info = 0;
    }
}
