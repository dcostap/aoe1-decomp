#pragma once
#include <windows.h>

class TPanelSystem {
public:
    static void release_palette(void **panel_system, void *palette);
    static void *get_palette(void **panel_system, const char *pal_file, int id);
    static void setCurrentPanel(void **panel_system, const char *name, int id);
    static void destroyPanel(void **panel_system, const char *name);
    static void *panel(void **panel_system, const char *name);
};
