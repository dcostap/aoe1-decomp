// 004AB670 TRIBE_Screen_Sed::set_unit(short)
// PDB: scr_sed.cpp lines 2178-2183 (102 bytes, 31 asm lines)
// Default flags. No inline asm/hacks.
//
// === ACCEPTED_DRIFT ===
// Remaining diff: VC5 consistently allocates ESI for the `unit` parameter and EDI
// for the else-path `rge_base_game` pointer, instead of the original's EDI/ESI pairing.
// This is a pure benign register swap (ESI↔EDI) with zero behavioral effect.
// Every instruction, constant, offset, branch target, and call is identical except
// for the register choice. The function is exactly 102 bytes in both versions.
//
// Attempt log (15+ variants across multiple sessions):
// - Baseline common-call form compiles to same structure with swapped ESI/EDI registers.
// - Tried: int vs short parameter, raw pointer casts, separate short local, int index,
//   volatile local, early-return forms, duplicate call in each branch, `if`/`goto`,
//   multiple declaration orders, and various flag probes (/Ob0, /Oa, /Og, /Ot, /Ox, /Od).
//   All produce the same ESI-unit/EDI-global allocation.
// - VC5 seems to have a fixed preference for ESI as the first saved register for the
//   incoming short parameter in this function shape. No source-level override works.
//
// Accepted as benign saved-register allocation/scheduling drift. No inline asm/hacks.

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
    TListPanel* unit_list;
    char gap_640[4];
    ListInfo* unit_list_info;

    void set_unit(short unit);
};

void TRIBE_Screen_Sed::set_unit(short unit) {
    if (unit == -1) {
        rge_base_game->master_obj_id = unit;
    } else {
        rge_base_game->master_obj_id = unit_list_info[unit].id;
    }

    unit_list->scroll_cur_line(1, unit, 1);
}
