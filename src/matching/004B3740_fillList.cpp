// VA: 004B3740 TRIBE_Screen_Sed_Open::fillList | scr_sedo.cpp:116-149
// Refreshed to the exact VC5 findfirst/findnext local shape used by nearby fillList helpers.

#include "../../include/scr_sedo_context.h"

extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);
extern "C" char* __cdecl strncpy(char* dst, const char* src, unsigned int count);
extern "C" unsigned int __cdecl strlen(const char* s);
extern "C" long __cdecl _findfirst(const char* filespec, void* fileinfo);
extern "C" int __cdecl _findnext(long handle, void* fileinfo);

struct FindDataLocal {
    char gap_00[0x10];
    char name[260];
    char pad_114[4];
};

void TRIBE_Screen_Sed_Open::fillList()
{
    char file_name[260];
    FindDataLocal fileInfo;
    long handle;
    int len;

    this->list->empty_list();
    this->list->sorted = 1;

    sprintf(file_name, "%s*.scn", rge_base_game->prog_info->scenario_dir);
    handle = _findfirst(file_name, &fileInfo);
    while (handle != -1) {
        len = strlen(fileInfo.name + 4) - 4;
        strncpy(file_name, fileInfo.name + 4, len);
        file_name[len] = 0;
        this->list->append_line(file_name, 0);
        if (_findnext(handle, &fileInfo) == -1) {
            break;
        }
    }

    sprintf(file_name, "%s*.scx", rge_base_game->prog_info->scenario_dir);
    handle = _findfirst(file_name, &fileInfo);
    while (handle != -1) {
        len = strlen(fileInfo.name + 4) - 4;
        strncpy(file_name, fileInfo.name + 4, len);
        file_name[len] = 0;
        this->list->append_line(file_name, 0);
        if (_findnext(handle, &fileInfo) == -1) {
            break;
        }
    }
}
