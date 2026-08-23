// 00535210 RGE_View::update
// Attempt log:
// 1: natural decompiler-shaped implementation with local RGE_View/RGE_Map/RGE_Tile layout: wrong field ordering caused +4 offsets and 0x18 frame; .text 576 < original 619.
// 2: fix view field offsets/order from asm: center_map at 0x122/0x124, start screen/map fields at 0x126..0x12c, last_view at 0x138/0x13c; offsets fixed but compiler still chooses 0x18 frame and EDI=player.
// 3: rewrite body closer to decompiler with named short temporaries instead of int-heavy expression staging: size improved 576 -> 592, offsets fixed, but frame still sub esp,18 and EDI holds player instead of original EBX; check cannot compare because .text < configured 619.
// 4: explicit default /O2 /Oy flags produced same 592-byte body; removed redundant flag file.
// 5: /O1 /Oy probe shrank body to 546 bytes, wrong direction; rolled back to default flags.
// 6: using exact field order is required: player 0x100, map 0x104, tile dims 0x10c/0x10e/0x110, max cols/rows 0x116/0x118, center_map 0x122/0x124, last_view 0x138/0x13c.
// 7: current blocker is source/FPU liveness basin: original uses only 0x0c locals, EBX=player then BX=center_scr_col, BP=center_scr_row, and keeps fractional deltas on FPU stack; rebuilt spills more and uses 0x18 locals.
// 8: broad mismatch is not accepted_drift-safe; although behavior surface is close, register/frame/FPU scheduling differs before the geometry calculations.
// 9: likely next probes: restructure first half to avoid preserving converted col/row as C locals, and model the two __ftol adjustment results as stack-reused int temporaries rather than named shorts.
// 10: left in scratch after honest attempts; no exact match.
// 11: fresh pass restored the period TPanel ownership: pnl_wid/pnl_hgt at +14/+18 and render_rect at +8c.
// 12: reused the center-map shorts for the projection and viewport bounds; calls, CFG, and all field offsets stayed aligned.
// 13: direct view_y and (view_x - view_y) projection expressions gave the best current result: 550 bytes, 0x14 frame, 517 strict diff.
// 14: split fractional terms and an explicit col adjustment improved shape but worsened resync; rolled back as unsupported codegen steering.
// 15: remaining blocker is the original 0x0c FPU/local lifetime and register coloring (original EBX=player; rebuilt EDI=player); calls and CFG match.
// 16: direct typed this->player ownership was a codegen duplicate; retained the cached player local and clean candidate.
// 17: direct center-map field reload improved strict diff to 507 but widened the frame to 0x18; rolled back.
// 18: direct center-map assignments with a short cached column improved strict diff to 498 and shape to 50.9%; retained.
// 19: explicit int col_adj for map indexing was a codegen duplicate; removed.
// 20: natural fractional isometric projections from center-map deltas reduced strict diff to 495, but frame remains 0x1c and structural shape is unresolved.
// 21: positive __ftol temporaries and decompiler-style short lifetimes improved shape but worsened strict diff to 535; rolled back.
// 22: a typed three-slot fraction aggregate improved size by 2 bytes but worsened strict diff to 509; rolled back.
// 23: moving tile-half-height outside the second __ftol reduced the frame to 0x18 but widened strict diff to 510; retained only as behavior evidence.
// 24: term-wise x87 products reached size 620 and strict diff 489, but the half-height remained inside __ftol; diagnostic only.
// 25: term-wise products with the post-__ftol half-height matched size 619, strict diff 507, and preserved the observed truncation behavior.
// 26: positive term-wise projection temporaries with explicit subtract-half source form are the current clean candidate: 607 bytes, strict diff 494, 0x18 frame.
// 27: the reviewed DAT_005776b4 value is 0.5f; replacing the unsupported 48.0f
//     scale preserved the natural typed projection but changed the candidate to
//     595 bytes / 507 strict bytes / 0x18 frame.
// 28: grouping the half-row and column deltas matched the isometric behavior but
//     moved to a 567-byte codegen basin. The term-wise source better preserves the
//     original x87 stack shape and remains the clean candidate.
// 29: int projection temporaries preserve the original full-width __ftol results;
//     this is a codegen duplicate of the term-wise candidate.
// 30: a literal 0.5f is a closer metric basin but loses the reviewed data symbol;
//     restored DAT_005776b4 and the typed source.
// 31: explicit half-scaled terms on both coordinate axes, with the PDB/decompiler
//     center-map assignment order, reached 600 bytes / 494 strict bytes / 46.11%
//     shape.  The original 0x0c frame and three reused dword homes remain absent.
// 32: grouped half-scaled row/column expressions reached 579 bytes / 497 strict
//     bytes; the separate term-wise products are closer to the original x87 shape.
// 33: full-width projection locals reached 607 bytes / 523 strict bytes; rolled back.
// 34: row and coordinate float locals, polymorphic player/map surfaces, full TPanel
//     virtual context, split map-row fetch, and function-scope declaration variants
//     were duplicate or farther.  Restored the minimal typed surface.
// 35: fresh validation of the pinned clean source stayed at 600 bytes / 494
//     strict bytes / 0x18 frame, with four direct __ftol calls and exact owner.
// 36: a six-variant source lab covered term-wise, asymmetric, grouped, and
//     early-publication forms.  No exact variant appeared; the pinned clean
//     algebra remained the closest positional basin.
// 37-43: canonical RGE_View tail, polymorphic RGE_Player/RGE_Map, an explicit
//     center-column adjustment, and decompiler declaration order did not recover
//     the 0x0C frame.  The canonical polymorphic pair reached 606 bytes / 530
//     strict bytes and was restored.
// 44: the original reads DAT_005776B4 twice, once per projection.  It leaves the
//     column delta unscaled.  A natural asymmetric source reached 594 bytes /
//     536 strict bytes, so the clean metric candidate was not behavior-safe.
// 45: row-first term order was a codegen duplicate of the asymmetric form.
// 46: the current source keeps the binary-proven asymmetric projection and the
//     two early center-screen publications before the second conversion.
//     This preserves partial update state and fault order; exactness remains
//     blocked by the frame/register/FPU basin.

struct RGE_Player { unsigned char pad_000[0x114]; float view_x; float view_y; };
struct RGE_Tile { short screen_xpos; short screen_ypos; unsigned char field_4; unsigned char flags; unsigned char pad[0x12]; };
struct RGE_Map { unsigned char pad_000[0x8d8c]; RGE_Tile** map_row_offset; };
extern float DAT_005776b4;
struct tagRECT { long left; long top; long right; long bottom; };
class TPanel {
public:
    virtual ~TPanel();
    unsigned char gap_04[0x10];
    long pnl_wid;                         // +0x14
    long pnl_hgt;                         // +0x18
    unsigned char gap_1c[0x70];
    tagRECT render_rect;                  // +0x8C
    unsigned char gap_9c[0x58];
};
class RGE_View : public TPanel {
public:
    unsigned char gap_00f4[0x0c];
    RGE_Player* player;                   // +0x100
    RGE_Map* map;                          // +0x104
    short tile_wid;                        // +0x108
    short tile_hgt;                        // +0x10A
    short tile_half_wid;                   // +0x10C
    short tile_half_hgt;                   // +0x10E
    short elev_hgt;                        // +0x110
    unsigned char pad_112[4];
    short max_col_num;                     // +0x116
    short max_row_num;                     // +0x118
    short center_scr_col; short center_scr_row; short center_scr_col_offset; short center_scr_row_offset; short center_map_col; short center_map_row; short start_scr_col; short start_scr_row; short start_map_col; short start_map_row;
    int map_scr_x_offset; int map_scr_y_offset; float last_view_x; float last_view_y;
    void update();
};

void RGE_View::update()
{
    RGE_Player* p;
    short sVar6;
    short sVar7;
    short sVar8;
    short sVar9;
    short sVar10;
    RGE_Tile* tile;
    p = this->player;
    if (p && (p->view_x != this->last_view_x || p->view_y != this->last_view_y)) {
        sVar6 = (short)(int)p->view_x;
        this->center_map_col = sVar6;
        sVar7 = (short)(int)p->view_y;
        sVar6 = this->center_map_col;
        this->center_map_row = sVar7;
        sVar9 = (short)(this->render_rect.left + this->pnl_wid / 2) - this->tile_half_wid;
        sVar10 = (short)(this->render_rect.top + this->pnl_hgt / 2) - this->tile_half_hgt;
        this->last_view_x = p->view_x;
        this->last_view_y = p->view_y;
        // BINARY NOTE: the executable publishes these base coordinates before
        // the second conversion.  Keep the partial state on a conversion fault.
        this->center_scr_col = sVar9;
        this->center_scr_row = sVar10;
        sVar7 = (short)(int)(((p->view_y - (float)this->center_map_row) * DAT_005776b4 *
                              (float)this->tile_wid) +
                             ((p->view_x - (float)sVar6) *
                              (float)this->tile_wid));
        sVar8 = (short)(int)(((p->view_y - (float)this->center_map_row) * DAT_005776b4 *
                              (float)this->tile_hgt) -
                             ((p->view_x - (float)sVar6) *
                              (float)this->tile_hgt));
        sVar9 -= sVar7;
        sVar10 -= sVar8 + this->tile_half_hgt;
        this->center_scr_col = sVar9;
        this->center_scr_row = sVar10;
        tile = this->map->map_row_offset[this->center_map_row] + sVar6;
        this->map_scr_x_offset = (int)tile->screen_xpos - (int)sVar9;
        this->map_scr_y_offset = ((int)this->elev_hgt * ((unsigned int)tile->flags >> 5) + (int)tile->screen_ypos) - (int)sVar10;
        this->center_scr_col_offset = (short)((sVar6 + this->center_map_row) * this->tile_half_wid - sVar7);
        this->center_scr_row_offset = (short)((this->center_map_row - sVar6) * this->tile_half_hgt - sVar8 - this->tile_half_hgt);
        sVar7 = this->max_col_num / 2 + 2;
        this->start_map_row = this->center_map_row;
        this->start_map_row -= sVar7;
        this->start_map_col = sVar6 - sVar7;
        this->start_scr_col = (short)(sVar9 - sVar7 * this->tile_half_wid * 2);
        sVar6 = this->max_row_num / 2 + 1;
        this->start_map_col += sVar6;
        this->start_map_row -= sVar6;
        this->start_scr_row = (short)(sVar10 - sVar6 * this->tile_half_hgt * 2);
    }
}
