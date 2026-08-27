// VA: 0052CAF0 draw_multi_object_outline (1385B)
// PDB: tvw_main.cpp, lines 39-210
//
// Baseline reconstruction from the original call order and the matching
// tvw_main.cpp donors.  The outline has four diagonal paths and two explicit
// edge paths for each non-diagonal orientation.
//
// Attempt log:
// - Baseline: typed player/master/view ownership, direct mouse and selection
//   calls, and explicit diagonal and edge outline paths.  All 28 calls align;
//   the remaining gap is structural, with a 0x38 frame versus 0x48 original.
// - Layout lead: named the binary-backed calculation and fixed-edge locals
//   and changed grid temporaries to int.  It improved size and frame, but
//   reduced code shape.  Restored the baseline source.
// - Left in scratch: call order is exact, but branch topology, frame locals,
//   and the global relocation remain unresolved.
// - Fresh r2 layout probe: restored the same-TU proven TPanel and RGE_View
//   offsets (+8C/+90 and +FC/+100); this changed only early field accesses.
// - Fresh r2 control-flow probe: tested the binary sentinel edge setup; it
//   reduced the byte diff but removed four real draw calls, so it was rolled back.
// - Fresh r2 liveness probe: named the binary boundary aliases while keeping
//   all 28 calls; size moved closer but shape moved farther, so it was rolled back.
// - Restored the binary diagonal nesting and duplicated edge-loop order guards;
//   this restored all 28 calls and improved structural coverage.
// - Scoped row-boundary and saved-end-row lifetime probes reached the frame
//   size, but changed early register homes; rolled back to the better basin.
// - Coordinate-home swap and direct abs spelling were tested and rolled back.
// - Final source: typed sentinel edge paths, 28 ordered calls, 0x44 frame versus
//   the original 0x48; remaining drift is structural and starts at the frame.
// - r4 ABI audit: used the landed canonical storage accessor so the global
//   loads now encode 0062C574 instead of an unresolved extern relocation.
// - r5 selection-home probe: let get_selection_area fill main_row as the
//   third coordinate and carry that x-end directly through the outline paths.
// - r6 moved the sentinel stores before distance selection, matching PDB lines
//   71/74 without changing the frame or call set.
// - r6 removed the compiler-only row_end alias and reused point.x for the
//   binary-proven horizontal row boundary; this removed the 20-byte excess.
// - r6 diagonal guard and operand forms were codegen duplicates. Best current
//   source is exact-size/frame with 28 calls and a 1081-byte strict diff.
// - Current matching pass: 19 meaningful probes tested distance lowering,
//   selection-home aliases, coordinate widths, fallback assignment order,
//   declaration scope, and branch topology.  Every probe was rolled back.
// - BINARY NOTE: The clean source emits 28 ordered calls, a 0x48 frame, and
//   all four saved registers.  Its first mismatch is at +0x18 because VC5
//   keeps this in ESI instead of the original EBP and chooses other output
//   homes for get_selection_area.
// - BINARY NOTE: The original distance block uses branchless signed-absolute
//   arithmetic in ESI/EAX.  Natural abs expressions entered a worse basin and
//   added 14 bytes, so the clean manual form remains pinned.
// - Claim probe: the real Windows SDK tagPOINT/tagRECT context changed the
//   result to 1100 bytes and 44.25% shape.  The local API clones remain closer.
// - Claim probe: the reviewed RGE_View/RGE_Main_View virtual surface was a
//   codegen duplicate.  It changed no emitted byte.
// - Claim probe: source fall-through for the row-dominant arm raised shape to
//   56.53% and exact blocks to 32.49%, but strict drift rose to 1134 bytes.
//   The clean source remains pinned.  This is a useful CFG lead, not a final
//   source model.
// - TU repair pass: fresh grouped validation keeps the target at 1100 strict
//   bytes, with 28 ordered calls, matching ownership, and no boundary escapes.
// - TU repair probes tested abs/labs/manual distance forms, endpoint copies,
//   declaration order, loop-index reuse, and the pre-r5 selection home. Each
//   result was worse or a codegen duplicate. The pinned source is restored.
// - Candidate proposal validates all eight exact neighbors. Accepted drift
//   0052D600 and 0052D970 remain unchanged at 14 bytes each.
// - Next lead: recover the original local-home and register basin from the
//   period tvw_main.cpp declaration and translation-unit context.  Do not add
//   aliases or fake volatility without new binary evidence.

#include <stdlib.h>
#include "../../include/rge_base_game_global.h"

#ifndef TVW_MAIN_SHARED_CONTEXT
struct tagPOINT {
    long x;
    long y;
};

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea {
public:
    void SetClipRect(tagRECT* rect);
};

class RGE_Game_World;
class RGE_Static_Object;
class RGE_Master_Static_Object;
class TRIBE_Master_Building_Object;

struct RGE_Pick_Info {
    float x;
    float y;
    short scr_x;
    short scr_y;
    RGE_Static_Object* object;
    void* tile;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x20];
    RGE_Master_Static_Object** master_objects;
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_04[0x1AC];
    int prog_mode;
    int game_mode;
    int sub_game_mode;
    char gap_1BC[0x238];
    RGE_Game_World* world;
    int render_all;
    short master_obj_id;
    short terrain_id;
    short elevation_height;
    short brush_size;

    void get_mouse_pos(tagPOINT& point);
};

extern "C" long __cdecl _ftol(void);

class TPanel {
public:
    virtual int dummy00();
    virtual int dummy04();
    virtual int dummy08();
    virtual int dummy0c();
    virtual int dummy10();
    virtual int dummy14();
    virtual int dummy18();
    virtual int dummy1c();
    virtual int dummy20();
    virtual int dummy24();
    virtual int dummy28();
    virtual int dummy2c();
    virtual int dummy30();
    virtual int dummy34();
    virtual int dummy38();
    virtual int dummy3c();
    virtual int dummy40();
    virtual int dummy44();
    virtual int dummy48();
    virtual int dummy4c();
    virtual int dummy50();
    virtual int dummy54();
    virtual int dummy58();
    virtual int dummy5c();
    virtual int dummy60();
    virtual int dummy64();
    virtual int dummy68();
    virtual int dummy6c();
    virtual int dummy70();
    virtual int dummy74();
    virtual int dummy78();
    virtual int dummy7c();
    virtual int dummy80();
    virtual int dummy84();
    virtual int dummy88();
    virtual int dummy8c();
    virtual int dummy90();
    virtual int dummy94();
    virtual int dummy98();
    virtual int dummy9c();
    virtual int dummya0();
    virtual int dummya4();
    virtual int dummya8();
    virtual int dummyac();
    virtual int dummyb0();
    virtual int dummyb4();
    virtual int dummyb8();
    virtual int is_inside(long x, long y);

    char gap_04[0x1C];
    TDrawArea* render_area;
    tagRECT clip_rect;
    char gap_34[0x58];
    long left;
    long top;
    long right;
    long bottom;
};

class RGE_View : public TPanel {
public:
    char gap_9C[0x60];
    RGE_Game_World* world;
    RGE_Player* player;

    int get_selection_area(
        long* col1, long* row1, long* col2, long* row2, int normalize);
};

class RGE_Main_View : public RGE_View {
public:
    unsigned char pick1(
        unsigned char command, unsigned char mode, long x, long y,
        RGE_Pick_Info* info, RGE_Static_Object* exclude, int flags);
    void fixup_pick_info(RGE_Pick_Info* info);
};

class TRIBE_Main_View : public RGE_Main_View {
public:
    int draw_wall_outline(
        long col, long row, TRIBE_Master_Building_Object* master,
        long endpoint);
    virtual void draw_multi_object_outline();
};
#endif

void TRIBE_Main_View::draw_multi_object_outline() {
    short master_id;
    long calc_row2;
    TRIBE_Master_Building_Object* master;
    long end_col;
    long end_row;
    long calc_col1;
    long start_col;
    long calc_col2;
    long main_row;
    long main_col;
    long calc_row1;
    long start_row;
    long col;
    long row;
    long endpoint;
    int row_distance;
    int col_distance;
    tagPOINT point;
    RGE_Pick_Info pick_info;

    master_id = rge_base_game_at_storage()->master_obj_id;
    if (master_id == -1)
        return;

    master = (TRIBE_Master_Building_Object*)
        this->player->master_objects[(int)master_id];
    if (master == 0)
        return;

    this->render_area->SetClipRect(&this->clip_rect);

    if (this->get_selection_area(
            &start_col, &start_row, &main_row, &end_row, 0) == 0) {
        rge_base_game_at_storage()->get_mouse_pos(point);
        if (this->is_inside(point.x, point.y) == 0)
            return;

        if (this->pick1(
                0x28, 0, point.x - this->left, point.y - this->top,
                &pick_info, 0, 1) != 0x33)
            return;

        this->fixup_pick_info(&pick_info);
        start_col = (int)pick_info.x;
        main_row = start_col;
        start_row = (int)pick_info.y;
        end_row = start_row;
    }

    calc_row1 = -1;
    main_col = -1;
    end_col = main_row;
    col_distance = end_col - start_col;
    if (col_distance < 0)
        col_distance = -col_distance;
    row_distance = end_row - start_row;
    if (row_distance < 0)
        row_distance = -row_distance;

    if (col_distance == row_distance) {
        if (end_col < start_col) {
            col = end_col;
            row = end_row;
            if (end_row < start_row) {
                while (col <= start_col) {
                    this->draw_wall_outline(col, row, master, 2);
                    ++col;
                    ++row;
                }
                this->render_area->SetClipRect(0);
                return;
            }
            col = start_col;
            row = start_row;
            if (start_col > end_col) {
                if (col >= end_col) {
                    while (col >= end_col) {
                        this->draw_wall_outline(col, row, master, 2);
                        --col;
                        ++row;
                    }
                    this->render_area->SetClipRect(0);
                    return;
                }
            }
        }

        col = end_col;
        row = end_row;
        if (end_row < start_row) {
            while (col >= start_col) {
                this->draw_wall_outline(col, row, master, 2);
                --col;
                ++row;
            }
            this->render_area->SetClipRect(0);
            return;
        }

        col = start_col;
        row = start_row;
        if (start_col <= end_col) {
            while (col <= end_col) {
                this->draw_wall_outline(col, row, master, 2);
                ++col;
                ++row;
            }
            this->render_area->SetClipRect(0);
            return;
        }
    }

    if (col_distance > row_distance) {
        calc_row2 = end_row;
        end_row = end_col;
        calc_col2 = start_col;
        if (start_col < end_col) {
            end_row = start_col;
            calc_col2 = end_col;
        }

        if (start_row < calc_row2) {
            point.x = start_row + 1;
            calc_row1 = end_col;
            calc_col1 = calc_row2;
            main_col = start_row;
        } else if (calc_row2 < start_row) {
            point.x = calc_row2;
            calc_row1 = end_col;
            calc_col1 = start_row;
            main_col = start_row;
        }

        if (calc_row1 == -1 || start_row < point.x) {
            if (end_row <= calc_col2) {
                for (col = calc_col2; col >= end_row; --col) {
                    endpoint = (col == start_col || col == end_col) ? 2 : 0;
                    this->draw_wall_outline(col, start_row, master, endpoint);
                }
            }
            if (calc_row1 != -1 && point.x <= calc_col1) {
                for (row = point.x; row <= calc_col1; ++row) {
                    endpoint = (row == start_row || row == calc_row2) ? 2 : 1;
                    this->draw_wall_outline(calc_row1, row, master, endpoint);
                }
            }
        } else {
            if (calc_row1 != -1 && point.x <= calc_col1) {
                for (row = point.x; row <= calc_col1; ++row) {
                    endpoint = (row == start_row || row == calc_row2) ? 2 : 1;
                    this->draw_wall_outline(calc_row1, row, master, endpoint);
                }
            }
            if (end_row <= calc_col2) {
                for (col = calc_col2; col >= end_row; --col) {
                    endpoint = (col == start_col || col == end_col) ? 2 : 0;
                    this->draw_wall_outline(col, start_row, master, endpoint);
                }
            }
        }
        this->render_area->SetClipRect(0);
        return;
    }

    calc_row1 = start_row;
    calc_row2 = end_row;
    if (calc_row2 < calc_row1) {
        calc_row1 = end_row;
        calc_row2 = start_row;
    }

    main_col = -1;
    if (start_col < end_col) {
        main_col = end_row;
        calc_col1 = start_col + 1;
        calc_col2 = end_col;
    } else if (end_col < start_col) {
        main_col = end_row;
        calc_col1 = end_col;
        calc_col2 = start_col - 1;
    }

    if (main_col == -1 || calc_col2 < start_col) {
        if (calc_row1 <= calc_row2) {
            for (row = calc_row1; row <= calc_row2; ++row) {
                endpoint = (row == start_row || row == end_row) ? 2 : 0;
                this->draw_wall_outline(start_col, row, master, endpoint);
            }
        }
        if (main_col != -1 && calc_col1 <= calc_col2) {
            for (col = calc_col1; col <= calc_col2; ++col) {
                endpoint = (col == start_col || col == end_col) ? 2 : 1;
                this->draw_wall_outline(col, main_col, master, endpoint);
            }
        }
    } else {
        if (main_col != -1 && calc_col1 <= calc_col2) {
            for (col = calc_col1; col <= calc_col2; ++col) {
                endpoint = (col == start_col || col == end_col) ? 2 : 1;
                this->draw_wall_outline(col, main_col, master, endpoint);
            }
        }
        if (calc_row1 <= calc_row2) {
            for (row = calc_row1; row <= calc_row2; ++row) {
                endpoint = (row == start_row || row == end_row) ? 2 : 0;
                this->draw_wall_outline(start_col, row, master, endpoint);
            }
        }
    }
    this->render_area->SetClipRect(0);
}
