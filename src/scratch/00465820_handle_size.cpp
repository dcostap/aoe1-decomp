// VA: 00465820 TPanel::handle_size
// Source: Panel.cpp lines 1558-1670
// Attempt log:
// 1: initial direct reconstruction from packet/decompiler with local layout and natural control flow; broad mismatch, compiler made 8-byte frame and kept this in ebp.
// 2: rewrote with mutable parameters and one explicit local to try original single push-ecx frame; behavior accidentally regressed and frame still 8 bytes, rolled back.
// 3: added register self local and used it for all member accesses; no register/frame improvement, rolled back.
// 4: expanded virtual surface for child call; did not improve prologue/frame, rolled back to raw vtable call.
// 5: tried /Od flag; worse, removed flag.
// 6: left in scratch: behavior is understood from packet/decompiler, but VC5 codegen basin is wrong from the prologue (rebuilt sub esp,8 / ebp=this vs original push ecx / ebx=this) and drift is broad.

struct Rect { int left; int top; int right; int bottom; };
struct PanelNode;

class TPanel {
public:
    void* vtbl;
    char gap_04[0x34 - 0x04];
    int position_mode;
    char gap_38[0x40 - 0x38];
    TPanel* parent_panel;
    TPanel* left_panel;
    TPanel* top_panel;
    TPanel* right_panel;
    TPanel* bottom_panel;
    char gap_54[0x58 - 0x54];
    PanelNode* first_child_node;
    char gap_5C[0x6C - 0x5C];
    int active;
    char gap_70[0x8C - 0x70];
    Rect render_rect;
    int left_border;
    int top_border;
    int right_border;
    int bottom_border;
    int min_wid;
    int max_wid;
    int min_hgt;
    int max_hgt;

    virtual void dtor();
    virtual void setup();
    virtual void set_rect(int left, int top, int right, int bottom);
    int handle_size(int wid, int hgt);
};

struct PanelNode { TPanel* panel; PanelNode* next; };
typedef int (*ChildFn)(TPanel*, int, int);

int TPanel::handle_size(int wid, int hgt)
{
    TPanel* p;
    int left;
    int top;
    int right;
    int bottom;
    int calc_wid;
    int calc_hgt;

    p = this->parent_panel;
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
        right = this->min_wid + left - 1;
        bottom = this->min_hgt + top - 1;
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

        calc_wid = right - left + 1;
        calc_hgt = bottom - top + 1;
        int limit = this->min_wid;
        if (limit != 0 && calc_wid < limit) {
            right = left + limit - 1;
        } else {
            limit = this->max_wid;
            if (limit != 0 && calc_wid > limit) {
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
            int real_w = right - left + 1;
            int real_h = bottom - top + 1;
            int xoff;
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
            int r = (*(ChildFn*)((char*)*(int*)child + 0x50))(child, hgt, wid);
            if (r != 0) {
                return r;
            }
            node = node->next;
        }
        ++pass;
    } while (pass < 2);
    return 0;
}
