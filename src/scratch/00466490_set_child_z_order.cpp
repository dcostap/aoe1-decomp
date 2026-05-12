// VA: 00466490 TPanel::set_child_z_order
// Source: Panel.cpp lines 2222-2322
// Attempt log:
// initial natural implementation from packet/decompiler using known PanelNode/TPanel layout.
// exact call set/layout: first_child_node +0x58, last_child_node +0x5C, curr_child +0x3C, z_order +0xDC; remove/add calls at +0x64BF0/+0x64B50.
// tried explicit parent/target locals, parent-first vs target-first declarations, and register parent: no change; VC5 keeps EBX=this and EBP=child, while original has EBX=child and EBP=this plus a saved-this stack home.
// tried bool vs int found/inserted flags: worsened slightly, rolled back to int.
// tried widening mode to int with unsigned-char switch cast: no change, rolled back to unsigned char.
// tried /O1 as diagnostic: rebuilt text too small (331B); removed custom flag and kept default /O2 /Oy.
// left unresolved: behavior/calls look modeled, but remaining diff is broad register-allocation/control-flow shape from the wrong EBX/EBP topology and case-0 loop rotation.

class TPanel;

struct PanelNode {
    TPanel* panel;
    PanelNode* prev_node;
    PanelNode* next_node;
};

class TPanel {
public:
    char gap_00[0x3C];
    TPanel* curr_child;
    char gap_40[0x18];
    PanelNode* first_child_node;
    PanelNode* last_child_node;
    char gap_60[0xDC - 0x60];
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
    TPanel* parent = this;

    switch (mode) {
    case 0: {
        PanelNode* start = parent->first_child_node;
        int found = 0;
        node = start;
        if (node != 0) {
            do {
                if (node->panel->z_order == (int)order) {
                    found = 1;
                    break;
                }
                node = node->next_node;
            } while (node != 0);
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
        node = parent->first_child_node;
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
        node = parent->first_child_node;
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

    node = parent->first_child_node;
    old_curr = parent->curr_child;
    found_node = 0;
    parent->curr_child = 0;
    if (node != 0) {
        do {
            if (node->panel == child) {
                parent->remove_panel_node(node);
                found_node = node;
                break;
            }
            node = node->next_node;
        } while (node != 0);
    }

    if (found_node != 0) {
        int inserted = 0;
        node = parent->first_child_node;
        if (node != 0) {
            do {
                if (node->panel->z_order > child->z_order) {
                    parent->add_panel_node(found_node, node, 0);
                    inserted = 1;
                    break;
                }
                node = node->next_node;
            } while (node != 0);
        }
        if (!inserted) {
            parent->add_panel_node(found_node, parent->last_child_node, 1);
        }
    }
    parent->curr_child = old_curr;
}
