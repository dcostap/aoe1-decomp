#pragma once
#include "common.h"

struct TPanelSystem {
    TPanel* mouseOwnerValue;
    TPanel* keyboardOwnerValue;
    TPanel* modalPanelValue;
    TPanel* currentPanelValue;
    PanelNode* panelListValue;
    int numberActivePanelsValue;
    TPanel* prevCurrentChildValue;
    void* palette[10];
    char palette_file[10][260];
    int palette_use_count[10];
    long palette_id[10];
    unsigned long Imc;
    int ImeEnabled;
    int ImeOn;
    int InputEnabled;
    int saved_colors;
    unsigned long save_back_color;
    unsigned long save_text_color;

    void* get_palette(char* file, long id);
    void release_palette(void* pal);
    void DisableIME();
};
static_assert(sizeof(TPanelSystem) == 0xAD8, "Size mismatch");
