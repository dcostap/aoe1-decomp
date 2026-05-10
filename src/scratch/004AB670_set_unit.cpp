// VA: 004AB670 TRIBE_Screen_Sed::set_unit(short)
// PDB source: scr_sed.cpp lines 2178-2183 (102 bytes, 31 asm lines)
// Default flags. No inline asm/hacks.
//
// Behavior: if unit == -1, set rge_base_game->master_obj_id to -1 and scroll the unit list to -1.
// Otherwise set master_obj_id to unit_list_info[unit].id and scroll the unit list to unit.
//
// Attempt log:
// - Existing scratch/baseline is behaviorally correct but VC5 chooses ESI as the preserved parameter register
//   (`push esi; mov esi,[esp+8]`) while original chooses EDI (`push edi; mov edi,[esp+8]`). This cascades into
//   push-immediate -1 vs push-register, opposite global-cache register in the non--1 path, and shifted push order.
// - Tried local-only surface without shared include: same ESI-param family.
// - Tried `register short` parameter hint: ignored, same output.
// - Tried `int` parameter with short casts: same ESI-param family.
// - Tried aliased stack/local reads (`short u = *(short*)&unit`) and aliasing only the -1 call argument: optimized
//   back to the same ESI-param family.
// - Tried volatile local alias: forced stack spills/reloads and wrong broad family.
// - Tried `/Ob0`: no effect. Tried `/O1`: wrong 95-byte family. Removed custom flag file.
// - Tried else-path `RGE_Base_Game* game` local before index: moved some push scheduling but still ESI-param/global-EDI.
// - Tried unsigned-short surface: worse constant 0xFFFF stores/pushes and still ESI-param.
// - Tried reversed positive-first branch: wrong block order and still ESI-param.
// - Tried `extern RGE_Base_Game* rge_base_game` instead of absolute macro: worse global reload/call shape.
// - 2026-05-10 pass on this VA only: retried 15+ focused variants: switch/default, positive-first if/goto,
//   parameter self-assign/address/volatile-address, int/long/ushort signatures, raw member pointers, local list/info/game,
//   explicit int index, precomputed id, and alternate local/global scheduling. No exact. All sane variants still choose
//   ESI for the incoming parameter and EDI for the else-path global, opposite of original; variants that add locals push
//   both ESI/EDI at entry and worsen block shape. Not an accepted_drift suggestion because register swap cascades through
//   push encodings/block size and can truncate the tail in the compared window.
// - 2026-05-10 second pass: tested natural common-call source matching PDB line 2182, common-call with unit/-1 store,
//   explicit early-return and goto forms, list/game/info locals, const/signed/volatile parameter spellings, casted call
//   arguments, int/short index copies, manual offset math, and flag probes `/O2 /Oy`, `/Ob0`, `/Oa`, `/Ow`, `/Og`, `/Ot`,
//   `/Ox`, `/O2` without `/Oy`, `/Oy-`, and `/Od`. Best is the common-call + positive-branch game local below
//   (102/102, positional 23.5294%, edit 21.5686%), but it remains the same ESI-param/EDI-global family.
// Left in scratch: remaining blocker is register-allocation/source-shape around keeping the incoming short parameter
// in EDI across both branches while using ESI only as the else-path cached global pointer. Calls, stores, offsets,
// stack cleanup, and behavior are understood.

class RGE_Base_Game {
public:
    char gap[0x3FC];
    short master_obj_id;
};

#define rge_base_game (*(RGE_Base_Game**)0x62C574)

struct ListInfo {
    char text[100];
    short id;
};

class TListPanel {
public:
    void scroll_cur_line(unsigned char mode, short line, int update_scrollbar);
};

class TRIBE_Screen_Sed {
public:
    char gap_000[0x63C];
    TListPanel* unit_list;      // +0x63C
    char gap_640[4];
    ListInfo* unit_list_info;   // +0x644

    void set_unit(short unit);
};

void TRIBE_Screen_Sed::set_unit(short unit) {
    RGE_Base_Game* game;

    if (unit == -1) {
        rge_base_game->master_obj_id = unit;
    }
    else {
        game = rge_base_game;
        game->master_obj_id = unit_list_info[unit].id;
    }

    unit_list->scroll_cur_line(1, unit, 1);
}
