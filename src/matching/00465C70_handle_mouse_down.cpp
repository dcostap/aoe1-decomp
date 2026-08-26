// VA: 00465C70 handle_mouse_down
// PDB source: Panel.cpp
// Attempt log:

#ifndef AOE1_PANEL_CONTEXT_H
struct PanelNode {
    class TPanel* panel;
    PanelNode* prev_node;
};

class TPanel {
public:
    // vtable slots up to index 47 (0xBC)

    char gap_04[0x38];
    TPanel* curr_child;
    TPanel* parent_panel;
    TPanel* left_panel;
    TPanel* top_panel;
    TPanel* right_panel;
    TPanel* bottom_panel;
    PanelNode* node;
    PanelNode* first_child_node;
    PanelNode* last_child_node;
    TPanel* tab_prev_panel;
    TPanel* tab_next_panel;
    int mouse_captured;
    int active;
    int visible;
    int tab_stop;
    int have_focus;
    int overlapping_children;
    int handle_mouse_input;
    char gap_84[0x40];
    long mouse_down_x;
    long mouse_down_y;
    int mouse_down_ctrl;
    int mouse_down_shift;
    unsigned long mouse_down_time;
    char gap_D8[0x14];
    unsigned char mouse_action;
    unsigned char mouse_down_button;
    char gap_EE[6];

    long handle_mouse_down(unsigned char param_1, long param_2, long param_3, int param_4, int param_5);
    void set_curr_child(TPanel* child);
};

extern unsigned long __cdecl debug_timeGetTime(char* file, int line);

#endif
long TPanel::handle_mouse_down(unsigned char param_1, long param_2, long param_3, int param_4, int param_5)
{
    if (this->active == 0)
        return 0;

    if (this->mouse_captured == 0) {
        if (this->is_inside(param_2, param_3) == 0)
            return 0;

        for (PanelNode* node = this->last_child_node; node != 0; node = node->prev_node) {
            long result = node->panel->handle_mouse_down(param_1, param_2, param_3, param_4, param_5);
            if (result != 0)
                return result;
        }

        if (this->handle_mouse_input == 0)
            return 0;

        this->mouse_down_button = param_1;
        this->mouse_down_x = param_2;
        this->mouse_down_y = param_3;
        this->mouse_down_ctrl = param_4;
        this->mouse_down_shift = param_5;
        this->mouse_down_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Panel.cpp", 0x72C);
        this->mouse_action = 1;

        if (this->tab_stop != 0 && this->parent_panel != 0 && this->mouse_down_button == 1) {
            this->parent_panel->set_curr_child(this);
        }
    }

    if (this->handle_mouse_input == 0)
        return 0;

    if (this->mouse_down_button == 1) {
        this->mouse_left_down_action(param_2, param_3, param_4, param_5);
    } else {
        this->mouse_right_down_action(param_2, param_3, param_4, param_5);
    }
    return 1;
}
