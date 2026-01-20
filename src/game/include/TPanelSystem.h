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
    char palette_file[10];
    int palette_use_count[10];
    long palette_id[10];
    ulong Imc;
    int ImeEnabled;
    int ImeOn;
    int InputEnabled;
    int saved_colors;
    ulong save_back_color;
    ulong save_text_color;
};
static_assert(sizeof(TPanelSystem) == 0xAD8, "Size mismatch");
