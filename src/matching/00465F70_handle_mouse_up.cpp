// VA: 00465F70 TPanel::handle_mouse_up
// PDB source: Panel.cpp lines 1919-1959
// Attempt log:
// Baseline reconstruction: use the period-plausible TPanel member surface and
// typed virtual calls, rather than the prior free-function vtable scaffolding.

#ifndef AOE1_PANEL_CONTEXT_H
struct PanelNode;

class TPanel {
public:
    virtual long handle_mouse_down(unsigned char param_1, long param_2, long param_3,
                                   int param_4, int param_5);
    virtual long handle_mouse_move(long param_1, long param_2, int param_3, int param_4);
    virtual long handle_mouse_up(unsigned char param_1, long param_2, long param_3,
                                 int param_4, int param_5);
    virtual long handle_mouse_dbl_click(unsigned char param_1, long param_2, long param_3,
                                        int param_4, int param_5);
    virtual long mouse_left_down_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_left_move_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_left_up_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_right_down_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_right_move_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_right_up_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4);
    virtual int is_inside(long param_1, long param_2);

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
};

struct PanelNode {
    TPanel* panel;
    PanelNode* prev_node;
};

#endif
long TPanel::handle_mouse_up(unsigned char param_1, long param_2, long param_3,
                             int param_4, int param_5)
{
    if (this->active == 0)
        return 0;

    if (this->mouse_captured == 0) {
        if (this->is_inside(param_2, param_3) == 0)
            return 0;

        for (PanelNode* node = this->last_child_node; node != 0; node = node->prev_node) {
            long result = node->panel->handle_mouse_up(param_1, param_2, param_3, param_4, param_5);
            if (result != 0)
                return result;
        }
    } else {
        if (this->handle_mouse_input == 0)
            return 0;

        long result;
        if (this->mouse_down_button == 1)
            result = this->mouse_left_up_action(param_2, param_3, param_4, param_5);
        else
            result = this->mouse_right_up_action(param_2, param_3, param_4, param_5);

        if (result != 0)
            return 0;

        if (param_1 == this->mouse_down_button) {
            this->mouse_down_button = 0;
            this->mouse_action = 0;
        }

        return 1;
    }

    return 0;
}
