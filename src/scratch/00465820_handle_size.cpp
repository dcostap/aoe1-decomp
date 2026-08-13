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
// direct typed edge-panel member tests improved exact-block coverage without changing size.
// modeled the vslot+8 set_rect call as a 16-byte Rect-by-value argument; original sub-esp call setup now matches and diff is 440/592 bytes.
// full TPanel virtual overload declarations shifted the call to vslot+0xC, so the minimal slot-preserving surface remains authoritative.
// a scoped active temporary for one edge panel was a codegen duplicate; restored the direct condition.
// left unresolved: residual prologue/register coloring and set_rect/centered scheduling drift; source is typed and period-plausible.
// Main-agent audit restored the canonical virtual destructor surface; typed
// panel geometry and recursive child ownership remain authoritative. Final
// audited check: 593/585 bytes, 2/2 ordered calls, 494-byte diff.
// this claim: local tagRECT plus PositionMode enum is period-plausible and
// reaches exact size with a 437-byte diff; keep it over the 592-byte int basin.
// this claim: reused the Ghidra-supported edge-panel cursor under the enum
// surface; codegen stayed at 437 bytes, so the typed cursor remains source.
// this claim: full trailing TPanel fields through +0xF3 are layout-canonical;
// VC5 output was unchanged.
// this claim: common calc_wid/calc_hgt and SDK windows.h context were tested;
// both returned larger or older basins, so direct width and local tagRECT stay.

struct tagRECT { long left; long top; long right; long bottom; };
enum PositionMode {
    PositionFixed = 0,
    PositionLeft = 3,
    PositionCentered = 2,
    PositionTop = 4,
    PositionLeftTop = 7,
    PositionLeftBottom = 8,
    PositionRightTop = 9
};
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
    tagRECT clip_rect;
    PositionMode position_mode;
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
    tagRECT render_rect;
    long left_border;
    long top_border;
    long right_border;
    long bottom_border;
    long min_wid;
    long max_wid;
    long min_hgt;
    long max_hgt;
    long mouse_hold_interval;
    long mouse_move_tolerance;
    long mouse_down_x;
    long mouse_down_y;
    int mouse_down_ctrl;
    int mouse_down_shift;
    unsigned long mouse_down_time;
    int error_code;
    int z_order;
    int display_changed_count;
    long help_string_id;
    long help_page_id;
    unsigned char mouse_action;
    unsigned char mouse_down_button;
    unsigned char panel_type;
    unsigned char color;
    unsigned char fill_in_background;
    unsigned char clip_to_parent;
    unsigned char draw_rect2_flag;
    unsigned char need_restore;

    virtual ~TPanel();
    virtual void setup();
    virtual void set_rect(tagRECT rect);
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

    if (this->position_mode == PositionFixed) {
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
                if (this->position_mode == PositionLeft || this->position_mode == PositionLeftTop || this->position_mode == PositionLeftBottom) {
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
                if (this->position_mode == PositionTop || this->position_mode == PositionLeftTop || this->position_mode == PositionRightTop) {
                    bottom = top + limit - 1;
                } else {
                    top = bottom - limit + 1;
                }
            }
        }

        if (this->position_mode == PositionCentered) {
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

    tagRECT rect = { left, top, right, bottom };
    this->set_rect(rect);
    int pass = 0;
    do {
        for (PanelNode* node = this->first_child_node; node != 0; node = node->next) {
            TPanel* child = node->panel;
            long r = child->handle_size(wid, hgt);
            if (r != 0) {
                return r;
            }
        }
        ++pass;
    } while (pass < 2);
    return 0;
}
