// VA: 0048FBC0 TRIBE_Campaign_Editor_Screen::fill_campaign_drop | scr_cam.cpp:211-249

#include "../../include/scr_cam_context.h"

#if 0
extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);
extern "C" char* __cdecl strncpy(char* dst, const char* src, unsigned int count);
extern "C" unsigned int __cdecl strlen(const char* s);
extern "C" long __cdecl _findfirst(const char* filespec, void* fileinfo);
extern "C" int __cdecl _findnext(long handle, void* fileinfo);

struct TDropDownPanel {
    void set_sorted(int sorted);
    void empty_list();
    int append_line(char* text, int data);
};
struct ProgInfo { char gap_00[0xD1C]; char campaign_dir[1]; };
struct Game { char gap_00[0x0C]; ProgInfo* prog_info; };
extern Game* rge_base_game;

struct FindDataLocal {
    char gap_00[0x10];
    char name[260];
    char pad_114[4];
};

struct TRIBE_Campaign_Editor_Screen {
    char gap_00[0x4BC];
    TDropDownPanel* filename_drop;
    void fill_campaign_drop();
};
#endif

void TRIBE_Campaign_Editor_Screen::fill_campaign_drop()
{
    char file_name[256];
    FindDataLocal file_info;
    long handle;
    int len;

    this->filename_drop->set_sorted(1);
    this->filename_drop->empty_list();

    sprintf(file_name, "%s*.cpn", rge_base_game->prog_info->campaign_dir);
    handle = _findfirst(file_name, &file_info);
    while (handle != -1) {
        len = strlen(file_info.name + 4) - 4;
        strncpy(file_name, file_info.name + 4, len);
        file_name[len] = 0;
        this->filename_drop->append_line(file_name, 0);
        if (_findnext(handle, &file_info) == -1) {
            break;
        }
    }

    sprintf(file_name, "%s*.cpx", rge_base_game->prog_info->campaign_dir);
    handle = _findfirst(file_name, &file_info);
    while (handle != -1) {
        len = strlen(file_info.name + 4) - 4;
        strncpy(file_name, file_info.name + 4, len);
        file_name[len] = 0;
        this->filename_drop->append_line(file_name, 0);
        if (_findnext(handle, &file_info) == -1) {
            break;
        }
    }
}
