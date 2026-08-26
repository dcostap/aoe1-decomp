// 00464A80 TPanel::setup
// Prologue scheduling fix: match load order by swapping field assignments

extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);
#ifndef AOE1_PANEL_CONTEXT_H

#ifndef AOE1_PANEL_CONTEXT_H
struct TDrawArea {
    char gap_00[0x18];
    long width;
    long height;
};
#endif

class TPanel;

struct PanelNode {
    TPanel* panel;
    PanelNode* prev_node;
    PanelNode* next_node;
};

class TPanel {
public:

    char gap_04[0x1C];
    TDrawArea* render_area;
    char gap_24[0x10];
    int position_mode;
    char gap_38[0x08];
    TPanel* parent_panel;
    TPanel* left_panel;
    TPanel* top_panel;
    TPanel* right_panel;
    TPanel* bottom_panel;
    PanelNode* node;
    char gap_58[0x10];
    int field_68;
    char gap_6C[0x30];
    int left_border;
    int top_border;
    int right_border;
    int bottom_border;
    int min_wid;
    int max_wid;
    int min_hgt;
    int max_hgt;

    void add_panel_node(PanelNode* node, PanelNode* sibling, int after);
    int setup(TDrawArea* area, TPanel* parent, long left, long top, long width, long height, int value);
};

#endif
long TPanel::setup(TDrawArea* area, TPanel* parent, long left, long top, long width, long height, unsigned char value) {
    // render_area first to match original prologue
    render_area = area;
    parent_panel = parent;
    if (position_mode == 0) {
        left_border = left;
        top_border = top;
        min_wid = width;
        max_wid = width;
        right_border = 0;
        bottom_border = 0;
        min_hgt = height;
        max_hgt = height;
    }
    if (area != 0) {
        handle_size(area->width, area->height);
    } else {
        handle_size(0, 0);
    }
    set_color((unsigned char)value);
    field_68 = 0;
    if (node == 0) {
        node = (PanelNode*)calloc(1, 0xC);
        if (node == 0) {
            return 0;
        }
        node->panel = this;
        node->prev_node = 0;
        node->next_node = 0;
        if (parent_panel != 0) {
            parent_panel->add_panel_node(node, 0, 0);
        }
    }
    return 1;
}
