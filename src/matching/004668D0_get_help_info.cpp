#include <string.h>

#ifndef AOE1_PANEL_CONTEXT_H
class TPanel;

struct PanelNode {
    TPanel* panel;
    PanelNode* prev_node;
    PanelNode* next_node;
};

class TPanel {
public:

    char gap_04[0x58];
    PanelNode* last_child_node;
    char gap_60[0x0C];
    int active;
    char gap_70[0x74];
    int help_string_id;
    int help_page_id;

    char* get_string(int string_id);
    unsigned char get_help_info(char** out_str, long* out_page, long x, long y);
};

#endif
unsigned char TPanel::get_help_info(char*& out_str, long& out_page, long x, long y) {
    PanelNode* node;

    if (active == 0) {
        return 0;
    }
    if (is_inside(x, y) == 0) {
        return 0;
    }
    node = last_child_node;
    while (node != 0) {
        if (node->panel->get_help_info(out_str, out_page, x, y)) {
            return 1;
        }
        node = node->prev_node;
    }
    if (help_string_id >= 0) {
        strcpy(out_str, get_string(help_string_id));
        out_page = help_page_id;
        return 1;
    }
    return 0;
}
