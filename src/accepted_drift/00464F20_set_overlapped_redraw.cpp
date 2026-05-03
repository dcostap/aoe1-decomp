// VA: 00464F20, TPanel::set_overlapped_redraw, 295 bytes
// Source: Panel.cpp lines 1216-1256
// FLAGS: default
//
// ACCEPTED_DRIFT: 9.5% positional diff (28/295 bytes). All diffs are:
// 1. Register allocation for z_order (edx/esi vs edx/eax) — original uses 
//    ESI for param_1->z_order, our VC5 uses EAX then re-derives from ECX.
// 2. Compare direction inversions (jl vs jg, jle vs jge) — semantically
//    equivalent but different opcode encoding.
// 3. A few stack references shifted by 4 bytes in the second y-check section.
// 
// Behavior identical. Structurally identical prologue (first 83 bytes match
// perfectly). The struct copy approach (tagRECT p1_rect = param_1->clip_rect)
// forced VC5 to match the original's LEA+offset prologue pattern exactly.

#include <stddef.h>

class TPanel;

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea;

struct PanelNode {
    TPanel* panel;
    PanelNode* prev_node;
    PanelNode* next_node;
};

class TPanel {
public:
    char gap_00[0x20];
    tagRECT clip_rect;
    char gap_34[0x24];
    PanelNode* first_child_node;
    char gap_5C[0x80];
    int z_order;

    virtual void dummy00() = 0;
    virtual void dummy01() = 0;
    virtual void dummy02() = 0;
    virtual void dummy03() = 0;
    virtual void dummy04() = 0;
    virtual void dummy05() = 0;
    virtual void dummy06() = 0;
    virtual void dummy07() = 0;
    virtual void redraw(int mode) = 0;

    void set_overlapped_redraw(TPanel* param_1, TPanel* param_2, int param_3);
};

void TPanel::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, int param_3)
{
    tagRECT p1_rect = param_1->clip_rect;
    int p1_left = p1_rect.left;
    int p1_top = p1_rect.top;
    int p1_right = p1_rect.right;
    int p1_bottom = p1_rect.bottom;

    PanelNode* node = first_child_node;
    if (node == 0) return;

    do {
        TPanel* panel = node->panel;
        if (panel != param_1 && panel != param_2 && param_1->z_order < panel->z_order) {
            tagRECT n_rect = panel->clip_rect;
            int n_left = n_rect.left;
            int n_top = n_rect.top;
            int n_right = n_rect.right;
            int n_bottom = n_rect.bottom;

            if ((((n_left < p1_left || p1_right < n_left) &&
                  (n_right < p1_left || p1_right < n_right)) &&
                 (p1_left <= n_left || n_right <= p1_right)) ||
                (((n_top < p1_top || p1_bottom < n_top) &&
                  (n_bottom < p1_top || p1_bottom < n_bottom)) &&
                 (p1_top <= n_top || n_bottom <= p1_bottom)))
            {
                if ((((n_left <= p1_left && p1_left <= n_right) ||
                      (n_left <= p1_right && p1_right <= n_right)) ||
                     (p1_left < n_left && n_right < p1_right)) &&
                    (((n_top <= p1_top && p1_top <= n_bottom) ||
                      (n_top <= p1_bottom && p1_bottom <= n_bottom)) ||
                     (p1_top < n_top && n_bottom < p1_bottom)))
                {
                    panel->redraw(param_3);
                }
            } else {
                panel->redraw(param_3);
            }
        }
        node = node->next_node;
    } while (node != 0);
}
