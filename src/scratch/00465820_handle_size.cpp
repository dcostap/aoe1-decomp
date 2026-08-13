// VA: 00465820 TPanel::handle_size
// Source: Panel.cpp lines 1558-1670
// Attempt log:
// baseline: natural geometry source had correct fields/calls but an explicit vptr
// shifted every TPanel member by four bytes and the raw child call used cdecl.
// removed explicit vptr in favor of the compiler-owned virtual layout; offsets align.
// typed child->handle_size(wid,hgt) at vtable slot 0x50 fixes the thiscall ABI and cleanup.
// removed durable calc_wid and retained only the height bound; frame became push-ecx
// family and size drift fell from 18 to 8 bytes with exact call/CFG counts.
// self alias and scalar/panel declaration-order probes were codegen duplicates.
// swapped fixed-arm bottom/right assignment to follow the original min_hgt load; positional drift improved locally.
// long coordinate types and canonical named TPanel fields preserve the proven layout but do not change codegen.
// tried one shared calc_hgt for fixed and centered bottom ownership; diff worsened 494->498, so restored.
// restored proven PanelNode::prev_node; original next_node load is at +8, not +4.
// left unresolved: residual prologue/register coloring and set_rect/centered scheduling drift; source is typed and period-plausible.
// Main-agent audit restored the canonical virtual destructor surface; typed
// panel geometry and recursive child ownership remain authoritative. Final
// audited check: 593/585 bytes, 2/2 ordered calls, 494-byte diff.

struct Rect { long left; long top; long right; long bottom; };
struct PanelNode;

class TPanel {
public:
    TPanel* previous_panel;
    TPanel* previous_modal_panel;
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char* panel_name;
    void* render_area;
    Rect clip_rect;
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
    Rect render_rect;
    long left_border;
    long top_border;
    long right_border;
    long bottom_border;
    long min_wid;
    long max_wid;
    long min_hgt;
    long max_hgt;

    virtual ~TPanel();
    virtual void setup();
    virtual void set_rect(long left, long top, long right, long bottom);
    virtual void pad03();
    virtual void pad04();
    virtual void pad05();
    virtual void pad06();
    virtual void pad07();
    virtual void pad08();
    virtual void pad09();
    virtual void pad0A();
    virtual void pad0B();
    virtual void pad0C();
    virtual void pad0D();
    virtual void pad0E();
    virtual void pad0F();
    virtual void pad10();
    virtual void pad11();
    virtual void pad12();
    virtual void pad13();
    virtual long handle_size(long wid, long hgt);
};

struct PanelNode {
    TPanel* panel;
    PanelNode* prev;
    PanelNode* next;
};

long TPanel::handle_size(long wid, long hgt)
{
    TPanel* p = this->parent_panel;
    long left;
    long top;
    long right;
    long bottom;
    long calc_hgt;

    if (p != 0) {
        right = p->render_rect.right;
        left = p->render_rect.left;
        top = p->render_rect.top;
        bottom = p->render_rect.bottom;
        wid = right - left + 1;
        hgt = bottom - top + 1;
    } else {
        left = 0;
        top = 0;
        right = wid - 1;
        bottom = hgt - 1;
    }

    if (this->position_mode == 0) {
        left = this->left_border + left;
        top = this->top_border + top;
        bottom = this->min_hgt + top - 1;
        right = this->min_wid + left - 1;
    } else {
        p = this->left_panel;
        if (p != 0 && p->active != 0) {
            left = this->left_border + p->render_rect.right + 1;
        } else {
            left = this->left_border + left;
        }
        p = this->top_panel;
        if (p != 0 && p->active != 0) {
            top = this->top_border + p->render_rect.bottom + 1;
        } else {
            top = this->top_border + top;
        }
        p = this->right_panel;
        if (p != 0 && p->active != 0) {
            right = p->render_rect.left - this->right_border - 1;
        } else {
            right -= this->right_border;
        }
        p = this->bottom_panel;
        if (p != 0 && p->active != 0) {
            bottom = p->render_rect.top - this->bottom_border - 1;
        } else {
            bottom -= this->bottom_border;
        }

        calc_hgt = bottom - top + 1;
        long limit = this->min_wid;
        if (limit != 0 && right - left + 1 < limit) {
            right = left + limit - 1;
        } else {
            limit = this->max_wid;
            if (limit != 0 && right - left + 1 > limit) {
                if (this->position_mode == 3 || this->position_mode == 7 || this->position_mode == 8) {
                    right = left + limit - 1;
                } else {
                    left = right - limit + 1;
                }
            }
        }
        limit = this->min_hgt;
        if (limit != 0 && calc_hgt < limit) {
            bottom = top + limit - 1;
        } else {
            limit = this->max_hgt;
            if (limit != 0 && calc_hgt > limit) {
                if (this->position_mode == 4 || this->position_mode == 7 || this->position_mode == 9) {
                    bottom = top + limit - 1;
                } else {
                    top = bottom - limit + 1;
                }
            }
        }

        if (this->position_mode == 2) {
            long real_w = right - left + 1;
            long real_h = bottom - top + 1;
            long xoff;
            if (real_w == wid) {
                xoff = 0;
            } else {
                xoff = wid / 2 - real_w / 2;
            }
            right = real_w + xoff - 1;
            if (real_h == hgt) {
                top = 0;
            } else {
                top = hgt / 2 - real_h / 2;
            }
            bottom = real_h + top - 1;
            left = xoff;
        }
    }

    this->set_rect(left, top, right, bottom);
    int pass = 0;
    do {
        PanelNode* node = this->first_child_node;
        while (node != 0) {
            TPanel* child = node->panel;
            long r = child->handle_size(wid, hgt);
            if (r != 0) {
                return r;
            }
            node = node->next;
        }
        ++pass;
    } while (pass < 2);
    return 0;
}
