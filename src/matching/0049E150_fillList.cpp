// VA: 0049E150 TribeLoadSavedGameScreen::fillList | scr_load.cpp:137-170

#include <io.h>
#include <stdio.h>
#include <string.h>
#include "../../include/scr_load_context.h"

#if 0
extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);
extern "C" char* __cdecl strncpy(char* dst, const char* src, unsigned int count);
extern "C" unsigned int __cdecl strlen(const char* s);
extern "C" long __cdecl _findfirst(const char* filespec, void* fileinfo);
extern "C" int __cdecl _findnext(long handle, void* fileinfo);

struct TTextPanel {
    char gap_00[0x15C];
    int sorted;
    void empty_list();
    int append_line(char* text, int data);
};
struct ProgInfo { char gap_00[0xB12]; char save_dir[1]; };
struct Game { char gap_00[0x0C]; ProgInfo* prog_info; };
extern Game* rge_base_game;

struct FindDataLocal {
    char gap_00[0x10];
    char name[260];
    char pad_114[4];
};

struct TribeLoadSavedGameScreen {
    char gap_00[0x480];
    TTextPanel* list;
    void fillList();
};
#endif

void TribeLoadSavedGameScreen::fillList()
{
    char file_name[260];
    _finddata_t fileInfo;
    long handle;
    int len;

    this->list->empty_list();
    this->list->sorted = 1;

    sprintf(file_name, "%s*.gam", rge_base_game->prog_info->save_dir);
    handle = _findfirst(file_name, &fileInfo);
    while (handle != -1) {
        len = strlen(fileInfo.name) - 4;
        strncpy(file_name, fileInfo.name, len);
        file_name[len] = 0;
        this->list->append_line(file_name, 0);
        if (_findnext(handle, &fileInfo) == -1) {
            break;
        }
    }

    sprintf(file_name, "%s*.gmx", rge_base_game->prog_info->save_dir);
    handle = _findfirst(file_name, &fileInfo);
    while (handle != -1) {
        len = strlen(fileInfo.name) - 4;
        strncpy(file_name, fileInfo.name, len);
        file_name[len] = 0;
        this->list->append_line(file_name, 0);
        if (_findnext(handle, &fileInfo) == -1) {
            break;
        }
    }
}
