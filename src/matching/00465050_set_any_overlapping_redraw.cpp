// 00465050 TPanel::set_any_overlapping_redraw
// Source: Panel.cpp lines 1264-1294, size 263 bytes
//
// Baseline: period-plausible rectangle-overlap traversal reconstructed from
// the adjacent Panel.cpp set_overlapped_redraw implementation and the binary
// field/call evidence.  Keep the comparison tree explicit because the
// executable preserves the original edge-inclusive rectangle tests.
//
// Attempt log:
// - baseline: natural copied RECTs, named PanelNode traversal, and typed
//   virtual redraw calls produced the exact size/frame/call set; 24 bytes
//   remained in comparator operand order.
// - control-flow: used the binary-proven symmetric comparator spellings
//   (for example panel_rect.left > this_rect.right and this_rect.left >=
//   panel_rect.left); VC5 then emitted the original 263 bytes exactly.
// FLAGS: default
// Main-agent audit restored the canonical TPanel destructor slot; emitted
// code remains exact.

#ifndef AOE1_PANEL_CONTEXT_H
struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TPanel;

struct PanelNode {
    TPanel* panel;
    PanelNode* prev_node;
    PanelNode* next_node;
};

class TPanel {
public:
    virtual ~TPanel();
    virtual void vf04(void) = 0;
    virtual void vf08(void) = 0;
    virtual void vf0C(void) = 0;
    virtual void vf10(void) = 0;
    virtual void vf14(void) = 0;
    virtual void vf18(void) = 0;
    virtual void vf1C(void) = 0;
    virtual void set_redraw(int mode) = 0; // vtable slot 8 (+0x20)

    char gap_04[0x20];
    tagRECT clip_rect;
    char gap_34[0x24];
    PanelNode* first_child_node;

    void set_any_overlapping_redraw(TPanel* param_1, int param_2);
};

#endif
void TPanel::set_any_overlapping_redraw(TPanel* param_1, int param_2)
{
    tagRECT this_rect = param_1->clip_rect;
    PanelNode* temp_node = this->first_child_node;

    while (temp_node != 0) {
        TPanel* panel = temp_node->panel;
        if (panel != param_1) {
            tagRECT panel_rect = panel->clip_rect;

            if (((((panel_rect.left < this_rect.left) ||
                  (panel_rect.left > this_rect.right)) &&
                 ((panel_rect.right < this_rect.left) ||
                  (panel_rect.right > this_rect.right))) &&
                ((panel_rect.left >= this_rect.left) ||
                 (panel_rect.right <= this_rect.right))) ||
                (((panel_rect.top < this_rect.top) ||
                  (panel_rect.top > this_rect.bottom)) &&
                 (((panel_rect.bottom < this_rect.top) ||
                   (panel_rect.bottom > this_rect.bottom)) &&
                  ((panel_rect.top >= this_rect.top) ||
                   (panel_rect.bottom <= this_rect.bottom))))) {
                    if (((((this_rect.left >= panel_rect.left) &&
                       (this_rect.left <= panel_rect.right)) ||
                      ((this_rect.right >= panel_rect.left) &&
                       (this_rect.right <= panel_rect.right))) ||
                     ((this_rect.left < panel_rect.left) &&
                      (this_rect.right > panel_rect.right))) &&
                    (((this_rect.top >= panel_rect.top) &&
                      (this_rect.top <= panel_rect.bottom)) ||
                     ((this_rect.bottom >= panel_rect.top) &&
                      (this_rect.bottom <= panel_rect.bottom)) ||
                     ((this_rect.top < panel_rect.top) &&
                      (this_rect.bottom > panel_rect.bottom)))) {
                    panel->set_redraw(param_2);
                }
            } else {
                panel->set_redraw(param_2);
            }
        }
        temp_node = temp_node->next_node;
    }
}
