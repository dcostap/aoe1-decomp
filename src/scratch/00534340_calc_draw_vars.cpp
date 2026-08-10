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

class tagRECT {
public:
    long left;
    long top;
    long right;
    long bottom;
};

class TPanel {
public:
    virtual ~TPanel();
    char gap_04[0x10];
    int pnl_wid;                           // +0x14
    int pnl_hgt;                           // +0x18
    char gap_1C[0x54];                     // +0x1C to +0x6F
    int visible;                           // +0x70
    char gap_74[0x18];                     // +0x74 to +0x8B
    tagRECT render_rect;                   // +0x8C
    char gap_9C[0x58];                     // +0x9C to +0xF3
};

class RGE_View : public TPanel {
public:
    char gap_F4[0x14];                     // +0xF4 to +0x107
    short tile_wid;                        // +0x108
    short tile_hgt;                        // +0x10A
    short tile_half_wid;                   // +0x10C
    short tile_half_hgt;                   // +0x10E
    char gap_110[0x6];                     // +0x110 to +0x115
    short max_col_num;                     // +0x116
    short max_row_num;                     // +0x118
    short center_scr_col;                  // +0x11A
    short center_scr_row;                  // +0x11C
    short center_scr_col_offset;           // +0x11E
    short center_scr_row_offset;           // +0x120
    short center_map_col;                  // +0x122
    short center_map_row;                  // +0x124

    void calc_draw_vars();
};

void RGE_View::calc_draw_vars() {
    int pw;
    int ph;

    if (this->visible != 0 && this->tile_wid != 0 && this->tile_hgt != 0) {
        pw = this->pnl_wid;
        ph = this->pnl_hgt;

        this->center_scr_col_offset = 0;
        this->center_scr_row_offset = 0;
        this->max_col_num = (short)(pw / (int)this->tile_wid);
        this->max_row_num = (short)(ph / (int)this->tile_hgt);
        this->center_scr_col = (this->render_rect.left - this->tile_half_wid) + (short)(pw / 2);
        this->center_scr_row = (this->render_rect.top - this->tile_half_hgt) + (short)(ph / 2);
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
