// 00534340 RGE_View::calc_draw_vars
// PDB: view.cpp:916-942, 217 bytes
// __thiscall, void, ret
// FLAGS: default
//
// Attempt log:
// probe 1: class layout mismatch (160b vs 217b)
// probe 2-4: free fn / goto / all vars at top — 94-98% diff
// probe 5-6: nested blocks / __thiscall with class — 90%
// probe 7: inline checks, eager loads — 93%
// probe 8-9: vis before zero / literal 0 — 93%
// probe 10: declare pw/ph uninitialized, assign after checks — 90%
// probe 11: invert layout (success body first with &&, zero at end) — 36.9% 
//   Key: layout now matches original (calc inline, zero after)
//   Remaining 80 bytes = register allocation drift only:
//   - visible in EDX vs EAX (8b 51 70 vs 8b 41 70)
//   - zero in EAX vs EBP (33 c0 vs 33 ed, no push ebp before xor)
//   - tile_wid divisor in EBP vs EDI (movsx ebp,dx vs movsx edi,ax)
//   - zero path pops ESI/EBP before stores vs after stores
//   All semantically equivalent, VC5 register allocation stable
// probe 12: if/else vs if+return — identical binary to probe 11
//
// left in scratch: remaining drift is VC5 register allocation — 
// EAX/EBP/EDI register choices differ from original by 80 bytes (36.9%).
// Single-function scope cannot resolve. Needs TU context or register allocation control.
// probe 13: true TPanel base/polymorphic surface — emitted code unchanged.
// probe 14: short/int zero locals, register-qualified width locals, and natural
//   statement-order variants — unchanged or structurally worse.
// probe 15: exact tagRECT dword aggregate for render_rect — emitted code unchanged.
// final: retain the period-plausible inherited TPanel/tagRECT ownership; remaining
//   mismatch is isolated to VC5 register coloring and zero-path save/pop order.
// Session follow-up: named zero, direct-member width/height, and visible-local
// probes were rolled back; they were duplicate or farther.  Retain the clean
// named panel-width/height source and canonical RGE_View/TPanel/tagRECT surface.
// Main-agent audit confirmed canonical panel/view rectangle ownership and kept
// the natural visible/geometry branches.
// Matching-worker continuation: a nine-variant natural body lab (current,
// zero-local widths, inner/direct locals, declaration/order, math-order, and
// truthy guards) preserved the 217-byte size but produced only four codegen
// groups and no exact result.  The clean current source remains the best
// reconstruction; the remaining 80-byte gap is the stable EAX/EDX, EBP/EDI,
// and failure-tail register basin, likely requiring broader view.cpp TU context.
// fresh orch-view-01 pass: splitting the row-offset zero around max-column
//   changed size to 222 and 191-byte drift; restored clean.
// fresh pass: natural nested positive guards emitted the same 217/80-byte
//   codegen as clean; restored clean.
// fresh pass: reversed zero-comparison operands, leading short zero sentinel,
//   and chained offset assignment were duplicate or one byte farther; restored.
// fresh pass: explicit clear-draw-vars goto tail was 217/197 bytes; restored.
// fresh pass: one-sided panel-width/height local variants were 217/192 and
//   217/89 bytes; restored.
// fresh pass: 24-variant natural setup/math/local lab found 8 codegen groups,
//   10 size-eligible variants, and no exact match.
// fresh pass: broad period TPanel virtual surface changed output to 217/150;
//   retained minimal exact-donor-compatible surface and restored clean.
// Continuation sa-15c0371c-r1 (10-hypothesis budget):
// probe 62: removing the height local while keeping the clean statement order
//   worsened to 192 bytes; direct height rereads alone are not sufficient.
// probe 64: interleaving col-offset/max-col and row-offset/max-row changed the
//   zero register to EBX and grew to 222 bytes; restored.
// probe 66: combining that interleaving with direct typed pnl_hgt rereads gave
//   a natural 217-byte candidate at 61 differing bytes and 66.13% exact blocks.
//   It aligns the complete success tail from max-col onward; only zero/divisor
//   coloring and the clear-tail register lifetime remain.
// probes 67-75: explicit int/short zero locals, full RGE_View tail layout,
//   windows.h, declaration-order, and memory.h context were either worse or
//   codegen duplicates of the 61-byte candidate.
// final continuation source: retain the PDB-supported width local, direct
//   height rereads, and interleaved offset/max statements; do not retain
//   unused zero/header scaffolding. Remaining gap is stable EBP/EDI/EAX
//   allocation and clear-tail pop ordering.
// orch2 context probe: adding the exact set_rect donor's <new.h> context
//   emitted the same 217-byte code; restored because it did not change the
//   register basin.
// continuation sa61_calc_draw_vars: exact same-TU view.cpp donor
//   0053F6B0_handle_scroll_view confirms TPanel::pnl_wid/pnl_hgt are long;
//   normalized both local fields from int to long.  The rebuilt function
//   remains 217 bytes with the same 61-byte mismatch, CFG, memory effects,
//   and saved-register set.  Retain the canonical typed surface.
// Continuation sa1853792c_calc_draw_vars:
// probes 96-98: moving the proven width local into the success arm, changing
//   its type to long, and moving it to function scope were codegen duplicates.
// probe 99: truthy guards were a duplicate; probe 100: protected access and
//   the canonical RGE_View virtual surface were duplicates.
// probe 102: a natural height local after the row-offset store was a duplicate.
// probe 105: ungrouped center arithmetic was a duplicate; probe 106: long zero
//   literals were a duplicate; probe 107: natural implicit promotions were a
//   duplicate.  Restored the clean typed source after each diagnostic probe.
// final continuation: validated clean source remains 217 bytes with 61 strict
//   mismatches (66.13% exact blocks).  The first mismatch is the stable VC5
//   EBP/EDI zero-versus-divisor coloring and failure-tail pop order.
// Matching-worker fresh pass sa-6b1246ff: baseline reproduced 217 bytes,
//   61 strict mismatches, and 66.13% exact-block coverage.  Explicit int and
//   register-qualified zero locals were worse; a short zero local was a
//   codegen duplicate.  Complete same-TU TPanel and RGE_View data surfaces
//   were also duplicates.  Restored the clean natural source.  The remaining
//   gap is the known VC5 EBP/EDI allocator basin; broader view.cpp context is
//   still the useful next evidence.
// Matching-worker sa-90ba5ca0-r1 canonical-layout probes:
// probes 13-14: replaced the touched TPanel gaps with the inventory-proven
//   complete TPanel field surface, then replaced the RGE_View prefix gaps with
//   typed world/map and size fields.  Both rebuilt to the same 217-byte,
//   61-difference result.  Retain the stronger local layout declarations;
//   remaining drift stays in register coloring and the failure-tail lifetime.
// Fresh continuation sa-9bdbe17c-r1: direct typed pnl_wid reads, a mutable
// short zero local, and checked tile-width/height locals all reproduced the
// clean 217-byte/61-difference basin.  A long zero local worsened to 198
// differences.  A 256-sample ambient declaration context lab found five
// codegen groups but no exact result; it never changed the first zero-register
// mismatch.  Restored the pinned natural source.
// Matching-worker sa-69ff65e9-r1 deeper view-TU pass:
// The original PDB lists RGE_View::tile_wid/tile_hgt/tile_half_wid/
// tile_half_hgt as short fields at +0x108..+0x10E.  It lists TPanel::pnl_wid
// and pnl_hgt as long fields, and visible as int.  The target procedure has
// only the register symbol this.  The PDB has no named local for this body.
// Twenty new hypotheses tested those field types, tile local scopes, panel
// width/height lifetimes, zero lifetimes, inline accessors, return form, enum
// metadata, and complete RGE_View size.  The clean source stayed at 217 bytes,
// 61 differences, and 66.13% exact blocks.  The only farther variants were
// restored.  The remaining gap is the EBP zero versus EDI divisor color and
// the related clear-tail pop order.
// Source-gate audit: the living body uses named members and one carried width.
// It has no generic slots, raw addresses, cursor aliases, fake zero local, or
// no-effect scaffold.  The clear arm keeps the observed natural zero stores.
// Continuation sa-d08f1c06-r1 (PDB-supported zero-lifetime pass):
// probes 159-163 tested negative-guard, explicit invalid return, and nested
// positive guards.  VC5 canonicalized all three to the clean 217/61 basin.
// Probe 165 changed clear assignment order and was farther (same 61 bytes).
// Probe 167 carried both panel dimensions as locals; it grew to 222/191.
// Probes 169 and 185 joined width declaration/initialization (const and plain);
// both were clean-basin duplicates.  Probe 171 captured tile shorts and was
// farther at 71 bytes.  Probe 173 grouped the positive predicate and probe 177
// qualified the inherited visible field; both were duplicates.  Probe 175
// moved clear-offset stores first and was farther.  Probe 179 used a long
// height local and was 222/191.  Probe 181 used explicit success return and
// common clear block and was a duplicate.  No natural PDB-supported form moved
// the guard zero from EDI to the original EBP or changed the clear-tail pop.
// Restored the pinned clean source.  The remaining EBP zero and tail lifetime
// are not supported by a source-local natural control or declaration change.

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea;
class PanelNode;
class RGE_Game_World;
class RGE_Player;
class RGE_Map;

class TPanel {
public:
    virtual ~TPanel();
    TPanel* previousPanelValue;            // +0x04
    TPanel* previousModalPanelValue;       // +0x08
    long pnl_x;                            // +0x0C
    long pnl_y;                            // +0x10
    long pnl_wid;                          // +0x14; same-TU TPanel donor type
    long pnl_hgt;                          // +0x18; same-TU TPanel donor type
    char* panelNameValue;                  // +0x1C
    TDrawArea* render_area;                // +0x20
    tagRECT clip_rect;                     // +0x24
    int position_mode;                     // +0x34
    int need_redraw;                       // +0x38
    TPanel* curr_child;                    // +0x3C
    TPanel* parent_panel;                  // +0x40
    TPanel* left_panel;                    // +0x44
    TPanel* top_panel;                     // +0x48
    TPanel* right_panel;                   // +0x4C
    TPanel* bottom_panel;                  // +0x50
    PanelNode* node;                       // +0x54
    PanelNode* first_child_node;           // +0x58
    PanelNode* last_child_node;            // +0x5C
    TPanel* tab_prev_panel;                // +0x60
    TPanel* tab_next_panel;                // +0x64
    int mouse_captured;                    // +0x68
    int active;                            // +0x6C
    int visible;                           // +0x70
    int tab_stop;                          // +0x74
    int have_focus;                        // +0x78
    int overlapping_children;              // +0x7C
    int handle_mouse_input;                // +0x80
    int just_drawn;                        // +0x84
    void* clip_rgn;                        // +0x88
    tagRECT render_rect;                   // +0x8C
    long left_border;                      // +0x9C
    long top_border;                       // +0xA0
    long right_border;                     // +0xA4
    long bottom_border;                    // +0xA8
    long min_wid;                          // +0xAC
    long max_wid;                          // +0xB0
    long min_hgt;                          // +0xB4
    long max_hgt;                          // +0xB8
    long mouse_hold_interval;              // +0xBC
    long mouse_move_tolerance;             // +0xC0
    long mouse_down_x;                     // +0xC4
    long mouse_down_y;                     // +0xC8
    int mouse_down_ctrl;                   // +0xCC
    int mouse_down_shift;                  // +0xD0
    unsigned long mouse_down_time;         // +0xD4
    int error_code;                        // +0xD8
    int z_order;                            // +0xDC
    int display_changed_count;              // +0xE0
    long help_string_id;                   // +0xE4
    long help_page_id;                     // +0xE8
    unsigned char mouse_action;            // +0xEC
    unsigned char mouse_down_button;       // +0xED
    unsigned char panel_type;              // +0xEE
    unsigned char color;                   // +0xEF
    unsigned char fill_in_background;      // +0xF0
    unsigned char clip_to_parent;          // +0xF1
    unsigned char draw_rect2_flag;         // +0xF2
    unsigned char need_restore;            // +0xF3
};

class RGE_View : public TPanel {
public:
    TDrawArea* cur_render_area;            // +0xF4
    int calc_draw_count;                   // +0xF8
    RGE_Game_World* world;                  // +0xFC
    RGE_Player* player;                     // +0x100
    RGE_Map* map;                           // +0x104
    short tile_wid;                        // +0x108
    short tile_hgt;                        // +0x10A
    short tile_half_wid;                   // +0x10C
    short tile_half_hgt;                   // +0x10E
    short elev_hgt;                         // +0x110
    short render_rect_wid;                  // +0x112
    short render_rect_hgt;                  // +0x114
    short max_col_num;                     // +0x116
    short max_row_num;                     // +0x118
    short center_scr_col;                  // +0x11A
    short center_scr_row;                  // +0x11C
    short center_scr_col_offset;           // +0x11E
    short center_scr_row_offset;           // +0x120
    short center_map_col;                  // +0x122
    short center_map_row;                  // +0x124

protected:
    void calc_draw_vars();
};

void RGE_View::calc_draw_vars() {
    int pw;

    if (this->visible != 0 && this->tile_wid != 0 && this->tile_hgt != 0) {
        pw = this->pnl_wid;

        this->center_scr_col_offset = 0;
        this->max_col_num = (short)(pw / (int)this->tile_wid);
        this->center_scr_row_offset = 0;
        this->max_row_num = (short)(this->pnl_hgt / (int)this->tile_hgt);
        this->center_scr_col = (this->render_rect.left - this->tile_half_wid) + (short)(pw / 2);
        this->center_scr_row = (this->render_rect.top - this->tile_half_hgt) + (short)(this->pnl_hgt / 2);
    } else {
        this->max_row_num = 0;
        this->max_col_num = 0;
        this->center_scr_col = 0;
        this->center_scr_row = 0;
        this->center_map_col = 0;
        this->center_map_row = 0;
        this->center_scr_col_offset = 0;
        this->center_scr_row_offset = 0;
    }
}
