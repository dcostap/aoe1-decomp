#pragma once
#include "../types.h"

// Forward declarations
class TPanel;
struct PanelNode;

class TPanelSystem {
public:
    /* 0x0000 */ TPanel *mouseOwnerValue;
    /* 0x0004 */ TPanel *keyboardOwnerValue;
    /* 0x0008 */ TPanel *modalPanelValue;
    /* 0x000C */ TPanel *currentPanelValue;
    /* 0x0010 */ PanelNode *panelListValue;
    /* 0x0014 */ int numberActivePanelsValue;
    /* 0x0018 */ TPanel *prevCurrentChildValue;
    /* 0x001C */ void *palette[10];
    /* 0x0044 */ char palette_file[10][260];
    /* 0x0A6C */ int palette_use_count[10];
    /* 0x0A94 */ long palette_id[10];
    /* 0x0ABC */ unsigned long Imc;
    /* 0x0AC0 */ int ImeEnabled;
    /* 0x0AC4 */ int ImeOn;
    /* 0x0AC8 */ int InputEnabled;
    /* 0x0ACC */ int saved_colors;
    /* 0x0AD0 */ int _padding[2]; // To reach 2776 bytes

    TPanelSystem();

    static void release_palette(TPanelSystem *ps, void *pal);
    static void *get_palette(TPanelSystem *ps, const char *pal_file, int id);
    static void setCurrentPanel(TPanelSystem *ps, const char *name, int id);
    static void destroyPanel(TPanelSystem *ps, const char *name);
    static void *panel(TPanelSystem *ps, const char *name);
};

static_assert(sizeof(TPanelSystem) == 2776, "TPanelSystem size mismatch");
static_assert(offsetof(TPanelSystem, palette_file) == 0x44, "palette_file offset");
static_assert(offsetof(TPanelSystem, palette_id) == 0xA94, "palette_id offset");

extern TPanelSystem panel_system;
