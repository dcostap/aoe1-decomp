extern "C" void __cdecl free(void* block);
extern "C" __declspec(dllimport) int __stdcall DeleteObject(void* object);

#ifndef AOE1_PANEL_CONTEXT_H
struct PanelNode;
class TPanel;

class TPanelSystem {
public:
    int inSystem(TPanel* panel);
    int removePanel(char* name);
};

extern TPanelSystem panel_system;

struct PanelNode {
    TPanel* panel;
    PanelNode* prev_node;
    PanelNode* next_node;
};

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TPanel {
public:
    virtual ~TPanel();

    TPanel* previousPanelValue;
    TPanel* previousModalPanelValue;
    int pnl_x;
    int pnl_y;
    int pnl_wid;
    int pnl_hgt;
    char* panelNameValue;
    void* render_area;
    tagRECT clip_rect;
    int need_redraw;
    int field_38;
    int field_3C;
    TPanel* parent_panel;
    int field_44;
    int field_48;
    int field_4C;
    int field_50;
    PanelNode* node;
    PanelNode* first_child_node;
    PanelNode* last_child_node;
    TPanel* curr_child;
    char gap_60[0x24];
    void* clip_rgn;

    void release_mouse(void);
    char* panelName(void);
    void remove_panel_node(PanelNode* node);
};

#endif
TPanel::~TPanel() {
    TPanel* self;

    self = this;
    release_mouse();
    if (panelNameValue != 0) {
        if (panel_system.inSystem(self) != 0) {
            panel_system.removePanel(panelName());
        }
    }
    if (node != 0) {
        if (parent_panel != 0) {
            parent_panel->remove_panel_node(node);
        }
        free(node);
        node = 0;
    }
    first_child_node = 0;
    if (clip_rgn != 0) {
        DeleteObject(clip_rgn);
        clip_rgn = 0;
    }
    if (parent_panel != 0) {
        parent_panel->set_redraw(TPanel::RedrawImmediate);
    }
    if (panelNameValue != 0) {
        free(panelNameValue);
    }
}
