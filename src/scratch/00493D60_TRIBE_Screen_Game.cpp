// 00493D60 TRIBE_Screen_Game::TRIBE_Screen_Game
// Starting point copied from the repo-local Ghidra approximation in
// orig/ghidra_decomp/scr_game.cpp.decomp.  This file intentionally keeps the
// raw offset surface first: TRIBE_Screen_Game's working shared layout is not yet
// promoted, and this constructor is large enough that a compiling behavioral
// baseline is more useful than speculative pretty fields.
// pass 1: established a compiling constructor skeleton through the pre-setup
// initialization band (PDB lines 201-232) plus the first setup call.
// pass 2: grew through button TShape loading, main/map view construction,
// inventory/object panels, command button allocation, and first message/time
// panels.
// pass 3: added chat panels, age/fps panels, score panels, toolbox creation,
// z-order/curr-child/timer startup tail, pause flag, and raw anim-pal bootstrap.
// pass 4: copied more of the Ghidra constructor tail: detailed command-button
// text/bevel setup, pause/quit and log text widgets, toolbox tail calls, player
// change/clock/score startup, and PAUSE argument side effects.
// current: exact early initialization through the first setup/test band (first
// mismatch is now the downstream failure-branch displacement after offset 0x37e,
// not frame size); TShape size, cached world/draw-area uses, toolbox sound temp,
// direct text/log field out-params, virtual TPanel::setup for message panels,
// raw Ghidra-style message-panel validation, age/fps split setup failures,
// alignment enum values, and score font slot reuse are durable wins.
// pass 5: fixed TButtonPanel::set_id surface from 4 params to 3 after original
// command-button setup showed only three pushes per call; identified
// rge_base_game->get_string(int,int,int,char*,int) as vtable+0x28 dispatch
// instead of direct. Keeping direct draw_buttons reloads plus the 3-param set_id
// signature improved edit diff to ~6.04%, with remaining draw-button loop drift
// in scheduling/byte-register order. Palette-tail lab variants (int/uchar/
// signed/immediate constants), pal3f/pal7b declaration-order swap, a volatile
// 0x5f store, and comma-operator scheduling in the get_string str argument all
// collapsed to the same emitted code or worsened diff, so they were rolled back.
// Additional rolled-back probes: explicit game_for_text/str_arg locals around
// get_string widened edit diff (~6.50%); per-iteration button local widened it
// badly (~16.30%); inven_area local for the inventory-panel constructor widened
// it badly (~23.83%); casting font->font through *(TFont**)font, making the
// 0x69c palette word store volatile, and moving pal27 between the palette word
// stores emitted the same code. Modeled TButtonPanel byte +0x2c0 as a local
// field (same code, but documents the observed layout). Additional draw-loop
// probes: &str[0], sizeof(str), str_arg local, button temp, comma-store in the
// get_string str arg, volatile +0x2c0 store, and draw_buttons[0] spelling all
// emitted the same current loop; game_for_text local after the byte store fixed
// the following bevel register cycle but widened get_string scheduling/spilled
// the game pointer, worsening edit diff to ~6.21% (before-store form ~6.50%).
// Kept a raw load through *(BaseGameStub**)0x62c574 for this loop's get_string
// call: behavior is the same stable rge_base_game global, but avoiding the
// object relocation on these two loads reduces edit diff to 349 / 5.9566%.
// It still uses eax (original uses edx) and the loop remains one byte short.
// 2026-05-12 pass: revalidated current baseline (edit diff 349 / 5.9566%).
// Rolled back: per-iteration button local (widened to 15.79% edit), normal
// rge_base_game get_string in draw loop (6.04%), buffer cast / str+(i-i) no
// change, volatile palette stores worsened to 6.23%. Palette source-order tweak
// around pal27 emitted identical code; remaining durable gap is still draw-loop
// get_string scheduling/bevel arg register cycle plus palette-store scheduling.
// Follow-up lab: comma_str/comma_zero/comma_id/split_outer draw-loop variants all
// collapsed to baseline; temp_id became a much worse 1688 edit diff. Forcing
// game_for_text before setDrawType widened to ~14.85%; volatile global load and
// post-store game local both widened to ~6.21%. Flag probes /O1 and /Os emitted
// undersized text; /Ob0 widened badly; /Gf no change. Palette pal7b arithmetic
// or late declaration still collapsed to baseline.
// 2026-08-13 shardA6-493D60-r1: naming the screen draw area before the inventory
// panel constructor was a natural ownership probe, but added 4 bytes and widened
// the positional diff from 3154 to 3999. Restored the clean reconstruction.
// 2026-08-13 orch-493D60-a: named TPanel+0x20 draw_area, used TRIBE_Player for
// inventory, typed the button array as TRIBE_Panel_Button**, and added stdio;
// each emitted the baseline code. Restored the clean source.
// 2026-08-13 orch-493D60-a: draw-loop lab tested baseline, plus4, count-local,
// buffer-local, split, and comma forms. Baseline, plus4, and split grouped.
// The count-local form was much worse. No source-backed lead remains.
// 2026-08-13 orch-493D60-a: proven string-address macros kept strict diff at
// 3154 and improved resync only. Restored named globals and clean source.
// 2026-08-17 sustained pass: twenty meaningful probes completed. The clean
// baseline remains authoritative: size 5859, frame 0x210, 180 calls, and
// strict diff 3154 bytes. The first mismatch is +0x37E. Edit cost is 577.
// BINARY NOTE: offsets 0x69E-0x6B2 are seven packed three-byte palette entries.
// A typed table improved one local metric to 3142, but lost seven code bytes.
// It was not retained because its structural result was worse.
// BINARY NOTE: the draw loop loads the game vtable through EDX in the original.
// The clean source uses the raw global fallback and still loads it through EAX.
// This remains the strongest codegen lead. Address and temporary variants failed.
// Tested and rolled back: typed palette ownership, palette statement order,
// draw-area locals, staged draw text values, standard headers, and ABI proxies.
// Proven ABI forms tested without emitted changes include RGE_Base_Game,
// TShape(char*,long), set_help_info(long,long), set_z_order(unsigned char,short),
// TScreenPanel::setup(...,long,int), and TButtonPanel::set_text(short,long).
// LIKELY INTENT: the remaining drift is a historical source or compiler-context
// difference around draw-button argument scheduling and palette initialization.
// BLOCKER: For the inventory-panel constructor, the executable reads the screen
// draw area before font->font. The rebuild reads font->font first. Constructor
// arguments and all 180 calls match, but invalid-pointer fault order differs.
// 2026-08-22 claim sa-db4c643e: tested player and draw-area locals, canonical
// void* font ABI surfaces, comma sequencing, loop predicates, local scopes,
// base-pointer ownership, and a function-scope string buffer. The player and
// draw-area locals worsened structure or call order. Other probes emitted the
// clean 5859-byte baseline with diff 3154. Restored the clean source.
// 2026-08-23 subagent sa-727c2e97: fresh validation kept this standalone
// scr_game.cpp owner. The grouped scr_game_context surface moved the base-game
// world field by four bytes and changed message-panel setup calls. It was not
// retained. The local TPanel surface now follows the proven full slot order
// and size. Panel constructors use reviewed pointer and long types.
// TRIBE_Main_View now uses its implicit constructor. This removes the old raw
// constructor pointer write. A typed AnimPalEntry trial reproduced more original blocks but
// lost seven bytes. It was restored because exactness is the first gate.
// Final unresolved evidence: one byte is missing. The ordered 180-call list,
// frame, saved registers, owner symbol, and CFG signals match. Inventory and
// object constructor loads remain reordered. The draw loop still loads the
// game receiver through EAX, not EDX. Do not claim exactness.

#include "../../include/game_types.h"
#include "../../include/game_globals.h"

#if !defined(SCR_GAME_TU_CONTEXT)
#include "../../include/scr_game_context.h"
#endif

#define OFF32(o) (*(int*)((char*)this + (o)))
#define OFFU32(o) (*(unsigned long*)((char*)this + (o)))
#define OFF16(o) (*(short*)((char*)this + (o)))
#define OFF8(o) (*(unsigned char*)((char*)this + (o)))
#define MAIN_VIEW ((TRIBE_Main_View*)OFF32(0x4b8))
#define MAP_VIEW ((TRIBE_Diamond_Map_View*)OFF32(0x4bc))

#if defined(SCR_GAME_TU_CONTEXT)
TRIBE_Main_View::~TRIBE_Main_View() {}
#endif

TRIBE_Screen_Game::TRIBE_Screen_Game()
    : TScreenPanel(s_Game_Screen)
{
    displayPathingFlags = 0;
    allow_user_commands = (do_fixed_update == 0);
    die_die_die = 0;

    register int i;
    OFF32(0x478) = 0;
    OFF32(0x47c) = 0;
    OFF32(0x480) = 0;
    OFF32(0x484) = 0;
    OFF32(0x488) = 0;
    OFF32(0x48c) = 0;
    OFF32(0x490) = 0;
    OFF32(0x494) = 0;
    OFF32(0x4ac) = 0;
    for (i = 0; i < 5; i++) {
        ((TShape**)((char*)this + 0x498))[i] = 0;
    }
    OFF32(0x4b8) = 0;
    OFF32(0x4bc) = 0;
    OFF32(0x4c0) = 0;
    OFF32(0x4c4) = 0;
    OFF32(0x580) = 0;
    OFF32(0x588) = 0;
    memset((char*)this + 0x58c, 0, 8 * 4);
    OFF32(0x5ac) = 0;
    OFF32(0x5b0) = 0;
    memset((char*)this + 0x4c8, 0, 0x11 * 4);
    OFF32(0x50c) = 0;
    OFF32(0x510) = 0;
    OFF32(0x514) = 0;
    OFF32(0x540) = 0;
    memset((char*)this + 0x518, 0, 10 * 4);
    OFF32(0x544) = 0;
    OFF32(0x548) = 0;
    OFF32(0x54c) = 0;
    OFF32(0x550) = 0;
    OFF32(0x554) = 0;
    OFF32(0x558) = 0;
    memset((char*)this + 0x55c, 0, 8 * 4);
    OFF32(0x57c) = 0;
    OFF8(0x45c) = 0;
    OFF32(0x734) = 0;
    OFF8(0x738) = 0;

    OFF32(0x5b4) = (int)rge_base_game->world;
    OFFU32(0x5b8) = rge_base_game->prog_info->update_interval;
    OFFU32(0x5bc) = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_game_c, 0x116);
    OFF32(0x5c0) = 0x14d;
    OFFU32(0x5c4) = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_game_c, 0x119);
    OFF32(0x5c8) = 0;
    OFF32(0x5d0) = 0;
    OFF32(0x5d4) = 0;
    OFF32(0x5d8) = 0;
    OFF32(0x5dc) = 0;
    OFF16(0x5e0) = 0;
    OFF16(0x5e2) = 0;
    OFF16(0x5e4) = -1;
    OFF32(0x678) = 0;
    OFF32(0x67c) = 0;
    OFF32(0x680) = 0;
    OFF32(0x684) = 0;
    OFF32(0x688) = 0;
    OFF32(0x68c) = 1;
    OFF32(0x690) = 0;
    OFF32(0x694) = 0;
    OFF16(0x698) = 0;
    OFF16(0x69a) = 0;
    OFF16(0x69c) = 0;
    OFF32(0x708) = -1;
    OFF32(0x70c) = -1;
    OFF32(0x710) = 0;
    OFF32(0x714) = -1;
    OFF32(0x718) = 0;
    OFF32(0x71c) = 0;
    OFF32(0x720) = 0;
    OFF32(0x724) = 0;
    OFF32(0x728) = 100;
    OFFU32(0x72c) = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_game_c, 0x142);
    OFF32(0x730) = 0;

    OFF32(0x76c) = *this->get_string(0x103f);
    OFF32(0x770) = 0;
    OFF32(0x774) = *this->get_string(0x104a);
    OFF32(0x778) = 0;
    OFF32(0x77c) = *this->get_string(0x103a);
    OFF32(0x780) = 0x41;
    for (i = 0; i < 8; i++) {
        OFF32(0x784 + i * 4) = *this->get_string(i + 0x1040);
    }
    OFF32(0x7a4) = 1;
    OFF32(0x7a8) = 3000;
    OFFU32(0x7ac) = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_game_c, 0x154);
    OFF32(0x7b0) = 0;
    OFF32(0x7b4) = 0;
    OFF32(0x7b8) = 0;
    OFF32(0x7bc) = 0;
    OFF32(0x7c0) = 0;

    if (!this->setup(rge_base_game->draw_area, s_scr6, 0xc388, 1)) {
        OFF32(0xd8) = 1;
        return;
    }

    char str[512];

    OFF32(0x494) = (int)new TShape(s_btnunit_shp, 0xc62a);
    if (OFF32(0x494) == 0 || !((TShape*)OFF32(0x494))->is_loaded()) {
        OFF32(0xd8) = 1;
        return;
    }

    OFF32(0x490) = (int)new TShape(s_btntech_shp, 0xc629);
    if (OFF32(0x490) == 0 || !((TShape*)OFF32(0x490))->is_loaded()) {
        OFF32(0xd8) = 1;
        return;
    }

    OFF32(0x48c) = (int)new TShape(s_btncmd_shp, 0xc621);
    if (OFF32(0x48c) == 0 || !((TShape*)OFF32(0x48c))->is_loaded()) {
        OFF32(0xd8) = 1;
        return;
    }

    for (i = 0; i < 5; i++) {
        sprintf(str, s_btnbldg_d_shp, i);
        if (i < 4) {
            OFF32(0x498 + i * 4) = (int)new TShape(str, i + 0xc610);
        }
        else {
            OFF32(0x498 + i * 4) = (int)new TShape(str, 0xcf0d);
        }
        if (OFF32(0x498 + i * 4) == 0 || !((TShape*)OFF32(0x498 + i * 4))->is_loaded()) {
            OFF32(0xd8) = 1;
            return;
        }
    }

    TRIBE_Main_View* main_tmp = new TRIBE_Main_View;
    OFF32(0x4b8) = (int)main_tmp;
    if (main_tmp == 0 || main_tmp->error_code != 0) {
        OFF32(0xd8) = 1;
        return;
    }
    if (!MAIN_VIEW->setup((TDrawArea*)OFF32(0x20), this, 0, 0, 0, 0, 0, 1, s_bordline)) {
        OFF32(0xd8) = 1;
        return;
    }
    MAIN_VIEW->set_world((RGE_Game_World*)OFF32(0x5b4));
    MAIN_VIEW->set_player(rge_base_game->get_player());

    OFF32(0x4bc) = (int)new TRIBE_Diamond_Map_View;
    if (MAP_VIEW == 0 || MAP_VIEW->error_code != 0) {
        OFF32(0xd8) = 1;
        return;
    }
    if (!MAP_VIEW->setup((TDrawArea*)OFF32(0x20), this, 0, 0, 0, 0, 0, 0, rge_base_game->map_save_area)) {
        OFF32(0xd8) = 1;
        return;
    }
    MAP_VIEW->set_help_info(0x4e33, -1);
    MAP_VIEW->set_world((RGE_Game_World*)OFF32(0x5b4));
    MAP_VIEW->set_bitmap(s_map_bmp, 0xc4e1);
    MAP_VIEW->set_player(rge_base_game->get_player());
    TRIBE_Main_View* main_view_for_map = MAIN_VIEW;
    MAP_VIEW->main_view = main_view_for_map;

    RGE_Font* font = rge_base_game->get_font(0xb);
    {
    TRIBE_Panel_Inven* inven = new TRIBE_Panel_Inven(*(TDrawArea**)((char*)this + 0x20), this, font->font, rge_base_game->get_player());
    OFF32(0x4c0) = (int)inven;
    if (inven == 0 || inven->error_code != 0) {
        OFF32(0xd8) = 1;
        return;
    }
    inven->set_help_info(0x4e25, -1);
    }

    font = rge_base_game->get_font(7);
    {
    TRIBE_Panel_Object* object_panel = new TRIBE_Panel_Object((TDrawArea*)OFF32(0x20), this, font->font, font->font_wid, font->font_hgt, (TShape*)OFF32(0x494), (TShape**)((char*)this + 0x498), rge_base_game->get_player());
    OFF32(0x4c4) = (int)object_panel;
    if (object_panel == 0 || object_panel->error_code != 0) {
        OFF32(0xd8) = 1;
        return;
    }
    object_panel->set_help_info(0x19bb8, 0x265ac);
    }

    font = rge_base_game->get_font(0xb);
    TDigital* sound = rge_base_game->get_sound(1);
    for (i = 0; i < 0x11; i++) {
        OFF32(0x4c8 + i * 4) = (int)new TRIBE_Panel_Button((TDrawArea*)OFF32(0x20), this, sound, font->font, font->font_wid, font->font_hgt, (i < 0x0c) ? (TShape*)OFF32(0x47c) : (TShape*)OFF32(0x484));
        if (OFF32(0x4c8 + i * 4) == 0 || ((TPanel*)OFF32(0x4c8 + i * 4))->error_code != 0) {
            OFF32(0xd8) = 1;
            return;
        }
        ((TButtonPanel*)OFF32(0x4c8 + i * 4))->set_text_color(0, 0, 0xffffff);
        ((TButtonPanel*)OFF32(0x4c8 + i * 4))->set_sound_number(1);
    }

    ((TButtonPanel*)OFF32(0x4f8))->set_id(0, 0x0d, 0);
    ((TPanel*)OFF32(0x4f8))->set_help_info(0x1d4cf, -1);
    ((TButtonPanel*)OFF32(0x4fc))->set_id(0, 0x0e, 0);
    ((TPanel*)OFF32(0x4fc))->set_help_info(0x1d4d1, -1);
    ((TButtonPanel*)OFF32(0x500))->set_id(0, 0x0f, 0);
    ((TPanel*)OFF32(0x500))->set_help_info(0x1d4cd, -1);
    ((TButtonPanel*)OFF32(0x504))->set_id(0, 0x15, 0);
    ((TPanel*)OFF32(0x504))->set_help_info(0x1d4db, -1);
    ((TButtonPanel*)OFF32(0x508))->set_id(0, 0x18, 0);
    ((TPanel*)OFF32(0x508))->set_help_info(0x1d4dc, -1);

    {
    TButtonPanel** draw_buttons = (TButtonPanel**)((char*)this + 0x4f8);
    for (i = 3; i != 0; i--) {
        (*draw_buttons)->setDrawType(3);
        (*draw_buttons)->draw_type_byte = 3;
        (*draw_buttons)->set_text(0, (*(RGE_Base_Game**)0x62c574)->get_string(0x66, (*draw_buttons)->get_id(), 0, str, 0x200));
        (*draw_buttons)->set_bevel_info(3, OFF8(0x320), OFF8(0x321), OFF8(0x322), OFF8(0x323), OFF8(0x324), OFF8(0x325));
        draw_buttons++;
    }
    }
    if (rge_base_game->singlePlayerGame() == 1) {
        ((TPanel*)OFF32(0x4f8))->set_active(0);
    }
    ((TButtonPanel*)OFF32(0x504))->setDrawType(3);
    ((TButtonPanel*)OFF32(0x504))->set_bevel_info(4, OFF8(0x320), OFF8(0x321), OFF8(0x322), OFF8(0x323), OFF8(0x324), OFF8(0x325));
    *(unsigned char*)((char*)OFF32(0x504) + 0x2c0) = 3;
    ((TButtonPanel*)OFF32(0x504))->set_text(0, (char*)0x0fa9);
    ((TButtonPanel*)OFF32(0x508))->setDrawType(3);
    ((TButtonPanel*)OFF32(0x508))->set_bevel_info(4, OFF8(0x320), OFF8(0x321), OFF8(0x322), OFF8(0x323), OFF8(0x324), OFF8(0x325));
    *(unsigned char*)((char*)OFF32(0x508) + 0x2c0) = 3;
    ((TButtonPanel*)OFF32(0x508))->set_text(0, (char*)0x1023);
    this->get_string(0x1024, str, 0x200);
    ((TRIBE_Panel_Button*)OFF32(0x508))->set_text_msg(str);

    {
    font = rge_base_game->get_font(0xb);
    OFF32(0x50c) = (int)new TMessagePanel(font->font, font->font_wid, font->font_hgt);
    if (OFF32(0x50c) == 0 || ((TPanel*)OFF32(0x50c))->error_code != 0) {
        OFF32(0xd8) = 1;
        return;
    }
    if (!((TMessagePanel*)OFF32(0x50c))->setup((TDrawArea*)OFF32(0x20), MAIN_VIEW, 0, 0, 0, 0, 0)) {
        OFF32(0xd8) = 1;
        return;
    }
    ((TMessagePanel*)OFF32(0x50c))->set_justification(2, 1, 1);
    *(int*)((char*)MAIN_VIEW + 0x34c) = OFF32(0x50c);

    TTextPanel** quit_text = (TTextPanel**)((char*)this + 0x510);
    this->create_text(MAIN_VIEW, quit_text, 0x232e, 0, 0, 600, 0x3c, 0x0b, 1, 1, 0);
    if (*quit_text != 0) {
        (*quit_text)->set_text_color(0xffffff, 0);
        (*quit_text)->set_active(0);
    }
    TTextPanel** pause_text = (TTextPanel**)((char*)this + 0x584);
    this->create_text(MAIN_VIEW, pause_text, 0x2329, 0, 0, 600, 0x3c, 1, 1, 1, 0);
    if (*pause_text != 0) {
        (*pause_text)->set_text_color(0xffffff, 0);
        (*pause_text)->set_active(0);
    }
    }

    {
    TRIBE_Panel_Time* time_panel = new TRIBE_Panel_Time((TDrawArea*)OFF32(0x20), MAIN_VIEW);
    OFF32(0x514) = (int)time_panel;
    if (time_panel == 0 || time_panel->error_code != 0) {
        OFF32(0xd8) = 1;
        return;
    }
    time_panel->set_active(0);

    TRIBE_Panel_Pop* pop_panel = new TRIBE_Panel_Pop((TDrawArea*)OFF32(0x20), MAIN_VIEW);
    OFF32(0x540) = (int)pop_panel;
    if (pop_panel == 0 || pop_panel->error_code != 0) {
        OFF32(0xd8) = 1;
        return;
    }
    pop_panel->set_active(0);

    for (i = 0; i < 10; i++) {
        TRIBE_Panel_Time* clock = new TRIBE_Panel_Time((TDrawArea*)OFF32(0x20), MAIN_VIEW);
        OFF32(0x518 + i * 4) = (int)clock;
        if (clock == 0 || clock->error_code != 0) {
            OFF32(0xd8) = 1;
            return;
        }
        clock->set_active(0);
    }
    }

    rge_base_game->get_sound(1);
    font = rge_base_game->get_font(0xb);
    OFF32(0x544) = (int)new TMessagePanel(font->font, font->font_wid, font->font_hgt);
    OFF32(0x548) = (int)new TMessagePanel(font->font, font->font_wid, font->font_hgt);
    OFF32(0x54c) = (int)new TMessagePanel(font->font, font->font_wid, font->font_hgt);
    OFF32(0x550) = (int)new TMessagePanel(font->font, font->font_wid, font->font_hgt);
    OFF32(0x554) = (int)new TMessagePanel(font->font, font->font_wid, font->font_hgt);
    OFF32(0x558) = (int)new TMessagePanel(font->font, font->font_wid, font->font_hgt);
    TMessagePanel* message_panel = (TMessagePanel*)OFF32(0x544);
    TMessagePanel* message_check;
    if (message_panel == 0 || message_panel->error_code != 0 ||
        (message_check = (TMessagePanel*)OFF32(0x548)) == 0 || message_check->error_code != 0 ||
        (message_check = (TMessagePanel*)OFF32(0x54c)) == 0 || message_check->error_code != 0 ||
        (message_check = (TMessagePanel*)OFF32(0x550)) == 0 ||
        OFF32(0x554) == 0 ||
        OFF32(0x558) == 0 ||
        message_check->error_code != 0) {
        OFF32(0xd8) = 1;
        return;
    }
    if (!((TMessagePanel*)OFF32(0x544))->setup((TDrawArea*)OFF32(0x20), MAIN_VIEW, 0, 0, 0, 0, 0) ||
        !((TMessagePanel*)OFF32(0x548))->setup((TDrawArea*)OFF32(0x20), MAIN_VIEW, 0, 0, 0, 0, 0) ||
        !((TMessagePanel*)OFF32(0x54c))->setup((TDrawArea*)OFF32(0x20), MAIN_VIEW, 0, 0, 0, 0, 0) ||
        !((TMessagePanel*)OFF32(0x550))->setup((TDrawArea*)OFF32(0x20), MAIN_VIEW, 0, 0, 0, 0, 0) ||
        !((TMessagePanel*)OFF32(0x554))->setup((TDrawArea*)OFF32(0x20), MAIN_VIEW, 0, 0, 0, 0, 0) ||
        !((TMessagePanel*)OFF32(0x558))->setup((TDrawArea*)OFF32(0x20), MAIN_VIEW, 0, 0, 0, 0, 0)) {
        OFF32(0xd8) = 1;
        return;
    }

    font = rge_base_game->get_font(0xb);
    for (i = 0; i < 8; i++) {
        TMessagePanel* chat = new TMessagePanel(font->font, font->font_wid, font->font_hgt);
        OFF32(0x55c + i * 4) = (int)chat;
        if (chat == 0 || chat->error_code != 0 || !chat->setup((TDrawArea*)OFF32(0x20), MAIN_VIEW, 0, 0, 0, 0, 0)) {
            OFF32(0xd8) = 1;
            return;
        }
    }

    {
    font = rge_base_game->get_font(0xb);
    OFF32(0x580) = (int)new TTextPanel;
    if (OFF32(0x580) == 0 || ((TTextPanel*)OFF32(0x580))->error_code != 0) {
        OFF32(0xd8) = 1;
        return;
    }
    if (!((TTextPanel*)OFF32(0x580))->setup((TDrawArea*)OFF32(0x20), this, 0, 0, 0, 0, font->font, font->font_wid, font->font_hgt, 0, 0, 0, 0, 0, 0, 0)) {
        OFF32(0xd8) = 1;
        return;
    }
    ((TTextPanel*)OFF32(0x580))->set_alignment(0, 0);
    ((TTextPanel*)OFF32(0x580))->set_help_info(0x4e35, -1);
    if (do_color_log) {
        ((TPanel*)OFF32(0x580))->set_active(0);
    }

    font = rge_base_game->get_font(10);
    OFF32(0x588) = (int)new TTextPanel;
    if (OFF32(0x588) == 0 || ((TTextPanel*)OFF32(0x588))->error_code != 0) {
        OFF32(0xd8) = 1;
        return;
    }
    if (!((TTextPanel*)OFF32(0x588))->setup((TDrawArea*)OFF32(0x20), this, 0, 0, 0, 0, font->font, font->font_wid, font->font_hgt, 0, 1, 0, 0, 0, 0, 0)) {
        OFF32(0xd8) = 1;
        return;
    }
    ((TTextPanel*)OFF32(0x588))->set_alignment(0, 1);
    if (*(int*)((char*)rge_base_game + 0x8e8) != 0) {
        ((TPanel*)OFF32(0x588))->set_active(1);
        ((TPanel*)OFF32(0x4c0))->set_active(0);
        if (do_color_log == 0) {
            ((TPanel*)OFF32(0x580))->set_active(0);
        }
    }
    else {
        ((TPanel*)OFF32(0x588))->set_active(0);
        ((TPanel*)OFF32(0x4c0))->set_active(1);
        if (do_color_log == 0) {
            ((TPanel*)OFF32(0x580))->set_active(1);
        }
    }
    }

    font = rge_base_game->get_font(0xb);
    int num_game_players = 0;
    if (rge_base_game->multiplayerGame()) {
        for (i = 1; i < 9; i++) {
            if (comm->GetPlayerHumanity(i) == 2 || comm->GetPlayerHumanity(i) == 4) {
                num_game_players++;
            }
        }
        if (num_game_players == 0) num_game_players = 1;
    }
    else {
        num_game_players = *(short*)((char*)OFF32(0x5b4) + 0x3c) - 1;
    }
    for (i = 0; i < num_game_players; i++) {
        TMessagePanel* score = new TMessagePanel(font->font, font->font_wid, font->font_hgt);
        ((TMessagePanel**)((char*)this + 0x58c))[i] = score;
        if (!score->setup((TDrawArea*)OFF32(0x20), MAIN_VIEW, 0, 0, 0, 0, 0) || ((TMessagePanel**)((char*)this + 0x58c))[i] == 0 || ((TMessagePanel**)((char*)this + 0x58c))[i]->error_code != 0) {
            OFF32(0xd8) = 1;
            return;
        }
    }

    {
    TTextPanel** log_text_ptr = (TTextPanel**)((char*)this + 0x5ac);
    if (!this->create_text(this, log_text_ptr, s_, 10, 300, 400, 0x60, 7, 0, 0, 0)) {
        OFF32(0xd8) = 1;
        return;
    }
    (*log_text_ptr)->set_back_pic(0);
    (*log_text_ptr)->set_fill_back(1, 0);
    (*log_text_ptr)->set_style(0);
    (*log_text_ptr)->set_text_color(0xffffff, 0);
    TScrollBarPanel** log_scrollbar_ptr = (TScrollBarPanel**)((char*)this + 0x5b0);
    if (!this->create_auto_scrollbar(log_scrollbar_ptr, *log_text_ptr, 0x14)) {
        OFF32(0xd8) = 1;
        return;
    }
    (*log_scrollbar_ptr)->set_bevel_info(1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff);
    (*log_text_ptr)->empty_list();
    (*log_text_ptr)->set_active(0);
    }

    font = rge_base_game->get_font(7);
    TDigital* tool_sound = rge_base_game->get_sound(1);
    {
    RGE_Panel_Tool_Box* tool_box = new RGE_Panel_Tool_Box((TDrawArea*)OFF32(0x20), this, 0, 0, 0, 0, font->font, font->font_wid, font->font_hgt, tool_sound, this, MAIN_VIEW, MAP_VIEW);
    OFF32(0x57c) = (int)tool_box;
    if (tool_box == 0 || tool_box->error_code != 0) {
        OFF32(0xd8) = 1;
        return;
    }
    tool_box->set_active(0);
    }
    for (i = 0; i < 0x11; i++) {
        ((TPanel*)OFF32(0x4c8 + i * 4))->set_z_order(1, 0);
    }
    this->handle_size(OFF32(0x14), OFF32(0x18));
    this->set_curr_child(MAIN_VIEW);
    this->player_changed(*(short*)((char*)rge_base_game->get_player() + 0x4a),
                         *(short*)((char*)rge_base_game->get_player() + 0x4a));

    OFF32(0x678) = 20000;
    OFFU32(0x67c) = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_game_c, 0x339);
    OFF32(0x690) = 200;
    OFFU32(0x694) = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_game_c, 0x33f);
    OFF16(0x698) = 0;
    OFF16(0x69a) = 0;
    OFF16(0x69c) = 0;
    unsigned char pal27 = 0x27;

    // Raw palette/bootstrap bytes from the tail of the Ghidra approximation.
    // Keep raw until the packed anim-pal structs are proven.
    OFF8(0x69f) = pal27;
    OFF8(0x6a1) = pal27;
    unsigned char pal3f = 0x3f;
    unsigned char pal7b = 0x7b;
    OFF8(0x6ad) = pal27;
    OFF8(0x6b1) = pal27;
    OFF8(0x69e) = 0x17;
    OFF8(0x6a0) = 0x7c;
    OFF8(0x6a2) = pal3f;
    OFF8(0x6a3) = 0x90;
    OFF8(0x6a4) = pal3f;
    OFF8(0x6a5) = 0x5f;
    OFF8(0x6a6) = 0x9f;
    OFF8(0x6a7) = 0x57;
    OFF8(0x6a8) = pal7b;
    OFF8(0x6a9) = 0xb4;
    OFF8(0x6aa) = pal3f;
    OFF8(0x6ab) = 0x5f;
    OFF8(0x6ac) = 0xa0;
    OFF8(0x6ae) = pal3f;
    OFF8(0x6af) = 0x91;
    OFF8(0x6b0) = 0x17;
    OFF8(0x6b2) = pal7b;

    ((TRIBE_Panel_Time*)OFF32(0x514))->startup();
    ((TRIBE_Panel_Time*)OFF32(0x514))->set_clock_type(0, 0);
    for (i = 0; i < 10; i++) {
        ((TRIBE_Panel_Time*)OFF32(0x518 + i * 4))->startup();
        ((TRIBE_Panel_Time*)OFF32(0x518 + i * 4))->set_clock_type(0, 0);
    }
    this->reset_clocks();
    ((TRIBE_Panel_Pop*)OFF32(0x540))->startup();
    this->command_score((unsigned int)*(unsigned char*)((char*)OFF32(0x5b4) + 0x11c));

    confirmed_close = 0;
    if (rge_base_game->check_prog_argument(s_PAUSE)) {
        start_paused = 1;
        rge_base_game->set_game_mode(6);
        *(unsigned char*)((char*)rge_base_game->world + 0x1c) = 1;
    }
}

#undef OFF32
#undef OFFU32
#undef OFF16
#undef MAIN_VIEW
#undef MAP_VIEW
#undef OFF8
