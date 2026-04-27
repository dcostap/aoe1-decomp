// VA: 004B3740 fillList
// scr_sedo.cpp lines 116-149

// attempt 1: natural translation -> exact size (352), 52% diff
//   remaining diffs: lea [ecx-4] vs mov+sub (codegen), jump offset drifts
//   structurally correct

#include <stdio.h>
#include <string.h>
#include <io.h>

extern void* rge_base_game;  // 62C574h

class TTextPanel {
public:
    char gap_000[0x15C];
    int field_15C;
    void empty_list();
    int append_line(char* text, int flag);
};

class TRIBE_Screen_Sed_Open {
public:
    char gap_000[0x47C];
    TTextPanel* list;

    void fillList();
};

void TRIBE_Screen_Sed_Open::fillList() {
    long handle;
    char file_name[260];
    struct _finddata_t file_info;

    this->list->empty_list();
    this->list->field_15C = 1;

    // *.scn scan
    sprintf(file_name, "%s*.scn", *(char**)((char*)rge_base_game + 0x0C) + 0xC17);
    handle = _findfirst(file_name, &file_info);
    if (handle != -1) {
        do {
            int len = strlen(file_info.name);
            int n = len;
            n -= 4;
            strncpy(file_name, file_info.name, n);
            file_name[n] = 0;
            this->list->append_line(file_name, 0);
        } while (_findnext(handle, &file_info) != -1);
    }

    // *.scx scan
    sprintf(file_name, "%s*.scx", *(char**)((char*)rge_base_game + 0x0C) + 0xC17);
    handle = _findfirst(file_name, &file_info);
    if (handle != -1) {
        do {
            int len = strlen(file_info.name);
            int n = len;
            n -= 4;
            strncpy(file_name, file_info.name, n);
            file_name[n] = 0;
            this->list->append_line(file_name, 0);
        } while (_findnext(handle, &file_info) != -1);
    }
}
