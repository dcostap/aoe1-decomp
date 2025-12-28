#pragma once
#include "../types.h"

// Forward declarations
class TPanel;
struct PanelNode;

class TPanelSystem {
public:
    static void release_palette(TPanelSystem *ps, void *pal);
    static void *get_palette(TPanelSystem *ps, const char *pal_file, int id);
    static void setCurrentPanel(TPanelSystem *ps, const char *name, int id);
    static void destroyPanel(TPanelSystem *ps, const char *name);
    static void *panel(TPanelSystem *ps, const char *name);

    char placeholder[2776];
};

static_assert(sizeof(TPanelSystem) == 2776, "TPanelSystem size mismatch");
