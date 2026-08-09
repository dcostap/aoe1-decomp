// VA: 00466490 TPanel::set_child_z_order
// Source: Panel.cpp lines 2222-2322
// Attempt log:
// initial natural implementation from packet/decompiler using known PanelNode/TPanel layout.
// exact call set/layout: first_child_node +0x58, last_child_node +0x5C, curr_child +0x3C, z_order +0xDC; remove/add calls at +0x64BF0/+0x64B50.
// tried direct this member access and an early target alias; VC5 emitted the same basin.
// cached order before the case-0 scan; size/resync improved but positional bytes worsened, so rolled back.
// replaced opaque gaps with the canonical full TPanel field ownership; emitted code was unchanged.
// saved the matched node before remove_panel_node; this recovered the original pointer lifetime and moved the diff deeper.
// changed the removal/reinsert and case-0 child-list scans to natural top-tested for loops; size is exact and CFG/calls align.
// left unresolved: remaining drift is localized to case-0 scan register/order scheduling; current source is the clean typed reconstruction.
// Main-agent audit restored canonical polymorphic panel ownership and removed
// the diagnostic self alias; typed node/list traversal remains authoritative.
// Final audited check: exact 366-byte size, 3/3 ordered calls, 166-byte diff.

class TPanel;

struct PanelNode {
    TPanel* panel;
    PanelNode* prev_node;
    PanelNode* next_node;
};

class TPanel {
public:
    virtual ~TPanel();
    TPanel* previous_panel;
    TPanel* previous_modal_panel;
    int pnl_x;
    int pnl_y;
    int pnl_wid;
    int pnl_hgt;
    char* panel_name;
    void* render_area;
    int clip_left;
    int clip_top;
    int clip_right;
    int clip_bottom;
    int position_mode;
    int need_redraw;
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
    int just_drawn;
    void* clip_rgn;
    int render_left;
    int render_top;
    int render_right;
    int render_bottom;
    int left_border;
    int top_border;
    int right_border;
    int bottom_border;
    int min_wid;
    int max_wid;
    int min_hgt;
    int max_hgt;
    int mouse_hold_interval;
    int mouse_move_tolerance;
    int mouse_down_x;
    int mouse_down_y;
    int mouse_down_ctrl;
    int mouse_down_shift;
    unsigned long mouse_down_time;
    int error_code;
    int z_order;

    void add_panel_node(PanelNode* node, PanelNode* sibling, int after);
    void remove_panel_node(PanelNode* node);
    void set_child_z_order(TPanel* child, unsigned char mode, short order);
};

void TPanel::set_child_z_order(TPanel* child, unsigned char mode, short order)
{
    PanelNode* node;
    PanelNode* found_node;
    TPanel* old_curr;

    switch (mode) {
    case 0: {
        PanelNode* start = this->first_child_node;
        PanelNode* scan = start;
        int found = 0;
        for (; scan != 0; scan = scan->next_node) {
            if (scan->panel->z_order == (int)order) {
                found = 1;
                break;
            }
        }
        if (found) {
            node = start;
            if (node != 0) {
                int ord = (int)order;
                do {
                    TPanel* p = node->panel;
                    int z = p->z_order;
                    if (z >= ord) {
                        p->z_order = z + 1;
                    }
                    node = node->next_node;
                } while (node != 0);
            }
        }
        child->z_order = (int)order;
        break;
    }
    case 1: {
        short v = 0;
        node = this->first_child_node;
        if (node != 0) {
            do {
                TPanel* p = node->panel;
                if (p != child && p->z_order > (int)v) {
                    v = (short)p->z_order;
                }
                node = node->next_node;
            } while (node != 0);
        }
        child->z_order = (int)v + 1;
        break;
    }
    case 2: {
        short v = 0;
        node = this->first_child_node;
        if (node != 0) {
            do {
                TPanel* p = node->panel;
                if (p != child && p->z_order < (int)v) {
                    v = (short)p->z_order;
                }
                node = node->next_node;
            } while (node != 0);
        }
        child->z_order = (int)v - 1;
        break;
    }
    default:
        break;
    }

    node = this->first_child_node;
    old_curr = this->curr_child;
    found_node = 0;
    this->curr_child = 0;
    for (; node != 0; node = node->next_node) {
        if (node->panel == child) {
            found_node = node;
            this->remove_panel_node(node);
            break;
        }
    }

    if (found_node != 0) {
        int inserted = 0;
        node = this->first_child_node;
        for (; node != 0; node = node->next_node) {
            if (node->panel->z_order > child->z_order) {
                this->add_panel_node(found_node, node, 0);
                inserted = 1;
                break;
            }
        }
        if (!inserted) {
            this->add_panel_node(found_node, this->last_child_node, 1);
        }
    }
    this->curr_child = old_curr;
}
