// TRIBE_Mission_Screen::TRIBE_Mission_Screen
// VA: 004B8100
// PDB: scr_vc.cpp:45-194
//
// EXACT MATCH. FLAGS: config/flags/004B8100_TRIBE_Mission_Screen.rsp (/GX EH).
//
// Canonical reconstruction: /GX (EH-framed) constructor of a TScreenPanel
// derived screen.  Owns TTextPanel/TButtonPanel members at +0x478..+0x498.
// Mirrors the exact-slot panel virtual surface (set_active @0x14,
// set_fixed_position @0x1C, setText @0xE8 and the 7-arg text virtual @0xEC)
// proven by the scr_vc.cpp fillMissionText/fillTribeText exact donors.
// Called functions are declared as direct members so VC5 emits the original
// __thiscall sequences.
//
// Attempt log (prior sessions + this one):
// - baseline: natural member inits, "scr9" info file, scenario-name title,
//   3-resolution set_fixed_position tail-merged block, and 3-message radio
//   tab logic with a byte starting_description counter. Frame 0x110 -> calls 54/54.
// - layout: added second 260-byte local buffer for the "scr9" setup file param.
//   Frame now exact 0x214/0x214. 5 field zero order (title,ok,list,scroll,vc) now
//   matches original body order.
// - layout: moved 5 pointer fields + game_flag into member-init list; VC5 emitted
//   DECLARATION order (title,list,scroll,ok,vc) which contradicts original body
//   order; rolled back to body assignments.
// - layout: game_flag assigned after text_buttons (last); VC5 then loaded the
//   game_flag param LATE (mov al,[esp+238] at +006E) whereas original loads cl at
//   +002F and stores at +0072; rolled back to game_flag assigned 6th.
// - layout: removed decompiler-only +4 from the two local string buffers.  The
//   natural buffer starts reproduce the proven setup/title LEAs.
// - abi: TScreenPanel's packet/PDB constructor parameter is char* (PAD), not
//   const char* (PBD); corrected the local declaration so the direct-call
//   relocation identity is the historical constructor symbol.
// - THIS SESSION (sa28a3dbfd-r1):
//   * manual deferred vptr store `*(unsigned long*)this = 0x574318` (the
//     TribeSaveGameScreen donor DSE trick) moved the vftable store after the 5
//     field zeros but left game_flag/panel loads hoisted (1515).
//   * constant-count loop `for (j=0;j<3;j++) text_buttons[j]=0` produced the
//     original's working-pointer+fresh-zero store form (mov eax,ebx / xor
//     edx / [eax],[eax+4],[eax+8]) instead of [ebx],... (explicit stores).
//     Later replaced by memset, which is codegen-identical and cleaner.
//   * moving `TButtonPanel** text_button_1 = &this->text_buttons[1];` to just
//     before the tb1 create_button fixed the esi LEA position (arg-push slot
//     instead of hoisted into the ok-button call setup).
//   * scenario null tail: the original emits lea edx,[esp+1Ch]; sub edx,4;
//     mov [ecx+edx],al (base-4+len). Spelling the null write as
//     `adjusted_name[strlen(scenario_name) - 4] = 0;` reproduces the binary's
//     base+len-4 termination exactly (the executable truncates the copied name
//     by 4 bytes; binary-observed quirk, kept deliberately).
//   * THE KEY: `this->game_flag = game_flag;` must be the FIRST body statement.
//     Then VC5 hoists the param load to the top (mov cl,[esp+238h] at +002F),
//     sinks the member store to +0072 (after the automatic vptr store, which
//     VC5 schedules at +006B after the 5 field-zero stores), reuses eax as the
//     tb working pointer, uses edx as the tb zero, and interleaves the
//     panel_system load between tb[0] and tb[1] -- the full original prologue
//     schedule. No manual vptr store is needed; the automatic store lands in
//     the right place under this scheduling.  Any prior statement before the
//     game_flag assignment (including the manual vptr store or a `gf` local)
//     breaks the load hoist and re-shifts the prologue.
// - Not exact until the game_flag-first ordering; then exact immediately.

#include <string.h>

#include "../../include/scr_vc_context.h"

TRIBE_Mission_Screen::TRIBE_Mission_Screen(char* info_file, unsigned char game_flag,
                                           TPicture* vc_back_bmp)
    : TScreenPanel("Mission Dialog")
{
    char adjusted_name[260];
    char setup_file[260];
    unsigned char starting_description = 0;

    this->game_flag = game_flag;
    this->title = 0;
    this->ok_button = 0;
    this->list = 0;
    this->scroll_bar = 0;
    this->vc_back_bmp = 0;
    memset(this->text_buttons, 0, sizeof(this->text_buttons));

    panel_system.currentPanel();
    strcpy(setup_file, "scr9");

    if (!setup(rge_base_game->draw_area, setup_file, 0xC38C, 1)) {
        *(int*)((char*)this + 0xD8) = 1;
        return;
    }

    setup_shadow_area(0);
    set_ideal_size(0x280, 0x1E0);

    char* scenario_name = rge_base_game->world->scenario->Get_scenario_name();
    if (scenario_name != 0 && scenario_name[0] != 0) {
        strcpy(adjusted_name, scenario_name);
        // Binary-observed: null terminates at base + strlen - 4 (truncates the
        // copied name by 4 bytes); lea edx,[esp+1Ch]; sub edx,4; mov [ecx+edx],al.
        adjusted_name[strlen(scenario_name) - 4] = 0;
    } else {
        strcpy(adjusted_name, get_string(0x2655));
    }

    create_text(this, &this->title, adjusted_name, 10, 0xF, 0x26C, 0x14, 4, 1, 1, 0);
    create_text(this, &this->list, info_file, 0xF, 0x46, 0x12C, 0x154, 0xB, 0, 0, 1);
    create_auto_scrollbar(&this->scroll_bar, this->list, 0x14);

    if (this->field_31C) {
        this->list->textExtra(3, this->desc[0], this->desc[1], this->desc[2],
                              this->desc[3], this->desc[4], this->desc[5]);
    }

    create_button(this, &this->ok_button, 0xFA1, 0, 0xC8, 0x1B8, 0xF0, 0x1E, 0, 0, 0);
    create_button(this, &this->text_buttons[0], 0x2A31, 0, 0x145, 0x13C, 0xB4, 0x1E, 0, -1, 0);
    TButtonPanel** text_button_1 = &this->text_buttons[1];
    create_button(this, text_button_1, 0x2A32, 0, 0x145, 0x15C, 0xB4, 0x1E, 0, -1, 0);
    create_button(this, &this->text_buttons[2], 0x2A37, 0, 0x145, 0x17C, 0xB4, 0x1E, 0, -1, 0);

    for (int i = 0; i < 3; i++) {
        this->text_buttons[i]->set_radio_info((TPanel*)this->text_buttons, 3);
    }

    if (this->pnl_wid <= 0x280) {
        this->title->set_fixed_position(3, 0xF, 0x27A, 0x14);
        this->list->set_fixed_position(0x14, 0x32, 0x258, 0x73);
        this->text_buttons[0]->set_fixed_position(5, 0x1BD, 0x96, 0x1E);
        (*text_button_1)->set_fixed_position(0xA5, 0x1BD, 0x96, 0x1E);
        this->text_buttons[2]->set_fixed_position(0x145, 0x1BD, 0x96, 0x1E);
        this->ok_button->set_fixed_position(0x1E5, 0x1BD, 0x96, 0x1E);
    } else if (this->pnl_wid <= 0x320) {
        set_ideal_size(0x320, 0x280);
        this->title->set_fixed_position(3, 0xF, 0x31A, 0x14);
        this->list->set_fixed_position(0x1E, 0x2D, 0x2E4, 0xE6);
        this->text_buttons[0]->set_fixed_position(5, 0x235, 0xBE, 0x1E);
        (*text_button_1)->set_fixed_position(0xCD, 0x235, 0xBE, 0x1E);
        this->text_buttons[2]->set_fixed_position(0x195, 0x235, 0xBE, 0x1E);
        this->ok_button->set_fixed_position(0x25D, 0x235, 0xBE, 0x1E);
    } else {
        set_ideal_size(0x400, 0x300);
        this->title->set_fixed_position(3, 0xF, 0x3FA, 0x14);
        this->list->set_fixed_position(0x28, 0x41, 0x3B0, 0x136);
        this->text_buttons[0]->set_fixed_position(10, 0x2B2, 0xF0, 0x32);
        (*text_button_1)->set_fixed_position(0x10A, 0x2B2, 0xF0, 0x32);
        this->text_buttons[2]->set_fixed_position(0x20A, 0x2B2, 0xF0, 0x32);
        this->ok_button->set_fixed_position(0x306, 0x2B2, 0xF0, 0x32);
    }

    if (rge_base_game->world->scenario->Get_message(0) != 0) {
        this->list->setText(rge_base_game->world->scenario->Get_message(0));
        (*text_button_1)->set_radio_button();
        starting_description = 1;
    } else {
        (*text_button_1)->set_active(0);
    }

    if (rge_base_game->world->scenario->Get_message(4) != 0) {
        if (!starting_description) {
            this->list->setText(rge_base_game->world->scenario->Get_message(4));
            this->text_buttons[0]->set_radio_button();
        }
        starting_description++;
    } else {
        this->text_buttons[0]->set_active(0);
    }

    if (rge_base_game->world->scenario->Get_message(1) != 0) {
        if (!starting_description) {
            this->list->setText(rge_base_game->world->scenario->Get_message(1));
            this->text_buttons[2]->set_radio_button();
        }
        starting_description++;
    } else {
        this->text_buttons[2]->set_active(0);
        if (!starting_description) {
            this->list->set_active(0);
        }
    }

    if (starting_description == 1) {
        this->text_buttons[0]->set_active(0);
        this->text_buttons[1]->set_active(0);
        this->text_buttons[2]->set_active(0);
    }

    set_curr_child(this->ok_button);
    this->vc_back_bmp = vc_back_bmp;
}
