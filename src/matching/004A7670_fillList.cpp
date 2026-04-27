// attempt 1: natural two-pass save/scenario file scan; first build was size-correct but loop used lea-after-strlen basin
// attempt 2: keep a named fileInfo.name pointer/count to probe original strlen/strncpy register order

#include <io.h>
#include <stdio.h>
#include <string.h>

class TTextPanel {
public:
    char pad[0x15C];
    int flag_15c;

    void empty_list();
    int append_line(char* line, long param);
};

class RGE_Base_Game {
public:
    char gap_0[0x0C];
    char* base_path;
};

extern RGE_Base_Game* rge_base_game;

class TribeSaveGameScreen {
public:
    char gap_0[0x480];
    TTextPanel* list;
    char gap_484[0x69C - 0x484];
    int modeValue;

    void fillList();
};

void TribeSaveGameScreen::fillList() {
    char file_name[260];
    struct _finddata_t fileInfo;

    this->list->empty_list();
    this->list->flag_15c = 1;

    long handle;
    if (this->modeValue == 0) {
        sprintf(file_name, "%s*.gam", rge_base_game->base_path + 0xB12);
        handle = _findfirst(file_name, &fileInfo);
    } else {
        sprintf(file_name, "%s*.scn", rge_base_game->base_path + 0xC17);
        handle = _findfirst(file_name, &fileInfo);
    }

    if (handle != -1) {
        do {
            char* name = fileInfo.name;
            int count = strlen(name) - 4;
            strncpy(file_name, name, count);
            file_name[count] = 0;
            this->list->append_line(file_name, 0);
        } while (_findnext(handle, &fileInfo) != -1);
    }

    if (this->modeValue == 0) {
        sprintf(file_name, "%s*.gmx", rge_base_game->base_path + 0xB12);
        handle = _findfirst(file_name, &fileInfo);
    } else {
        sprintf(file_name, "%s*.scx", rge_base_game->base_path + 0xC17);
        handle = _findfirst(file_name, &fileInfo);
    }

    if (handle != -1) {
        do {
            char* name = fileInfo.name;
            int count = strlen(name) - 4;
            strncpy(file_name, name, count);
            file_name[count] = 0;
            this->list->append_line(file_name, 0);
        } while (_findnext(handle, &fileInfo) != -1);
    }
}
