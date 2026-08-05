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

class TPanel;
class TTextPanel;
class TButtonPanel;
class TScrollBarPanel;
class TDrawArea;

class TPanel {
public:
    virtual ~TPanel();                 // slot 0  (0x00)
    virtual void vf04();               // slot 1  (0x04)
    virtual void vf08();               // slot 2  (0x08)
    virtual void vf0C();               // slot 3  (0x0C)
    virtual void vf10();               // slot 4  (0x10)
    virtual void set_active(int active);// slot 5 (0x14)
    virtual void vf18();               // slot 6  (0x18)
    virtual void set_fixed_position(long x, long y, long width, long height); // slot 7 (0x1C)
    virtual void vf20();               // slot 8  (0x20)
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();
    virtual void vfB4();
    virtual void vfB8();
    virtual void vfBC();
    virtual void vfC0();
    virtual void vfC4();
    virtual void vfC8();
    virtual void vfCC();
    virtual void vfD0();
    virtual void vfD4();
    virtual void vfD8();
    virtual void vfDC();
    virtual void vfE0();
    virtual void set_ideal_size(long width, long height); // slot 57 (0xE4)

    void set_curr_child(TPanel* child);
    char* get_string(int lang_id);

    char gap_04[4];                    // +0x04
    char gap_08[4];                    // +0x08
    long pnl_x;                        // +0x0C
    long pnl_y;                        // +0x10
    long pnl_wid;                      // +0x14
    long pnl_hgt;                      // +0x18
    char gap_1C[0x40 - 0x1C];          // +0x1C ..
};

class TTextPanel : public TPanel {
public:
    virtual void setText(char* text);                  // slot 58 (0xE8)
    virtual void textExtra(int a, int b, int c, int d, int e, int f, int g); // slot 59 (0xEC)
};

class TButtonPanel : public TPanel {
public:
    void set_radio_info(TPanel* group, int param);
    void set_radio_button();
};

class TScrollBarPanel : public TPanel {
};

class TEasy_Panel : public TPanel {
public:
    virtual void set_ideal_size(long width, long height);
    virtual int create_button(TPanel* panel, TButtonPanel** out, int lang, int a4,
                              int x, int y, int w, int h, int a, int b, int c);
    virtual int create_button(TPanel* panel, TButtonPanel** out, char* lang, char* a4,
                              int x, int y, int w, int h, int a, int b, int c);
    virtual int create_check_box(TPanel* panel, TButtonPanel** out, int lang, int a4,
                                 int x, int y, int w, int h, int a);
    virtual int create_radio_button(TPanel* panel, TButtonPanel** out, int lang, int a4,
                                    int x, int y, int w, int h, int a);
    virtual int create_text(TPanel* panel, TTextPanel** out, int lang,
                            int x, int y, int w, int h, int font, int center_h,
                            int center_v, int word_wrap);
    virtual int create_text(TPanel* panel, TTextPanel** out, char** lang,
                            int x, int y, int w, int h, int font, int center_h,
                            int center_v, int word_wrap);
    virtual int create_text(TPanel* panel, TTextPanel** out, char* text,
                            int x, int y, int w, int h, int font, int center_h,
                            int center_v, int word_wrap);
    virtual int create_input(TPanel* panel, void* out, char* text, short width,
                             int format, int x, int y, int w, int h, int font);
    virtual int create_edit(TPanel* panel, void* out, char* text, short width,
                            int format, int x, int y, int w, int h, int font, int a, int b);
    virtual int create_drop_down(TPanel* panel, void* out, int lang, int a4,
                                 int x, int y, int w, int h, int a);
    virtual int create_list(TPanel* panel, void* out, int x, int font,
                            int w, int h, int lines);
    virtual int create_scrollbar(TPanel* panel, void* out, TTextPanel* text,
                                 int x, int y, int w, int h, int a);
    virtual int create_auto_scrollbar(TScrollBarPanel** out, TTextPanel* text, int param);
    virtual int create_vert_slider(TPanel* panel, void* out, int x, int y,
                                   int w, int h, int a, int b, int c);
    virtual int create_horz_slider(TPanel* panel, void* out, int x, int y,
                                   int w, int h, int a, int b, int c);
    virtual void position_panel(TPanel* panel, int x, int y, int w, int h);

    void setup_shadow_area(int param);

    char pad_40[0x31C - 0x40];         // +0x40 ..
    int  field_31C;                    // +0x31C
    unsigned char desc[6];             // +0x320
    char pad_326[0x474 - 0x326];       // +0x326 ..
};

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(char* name);
    virtual ~TScreenPanel();
    int setup(TDrawArea* draw_area, char* info_file, long info_id, int param);
    char pad_474[4];                   // +0x474 ..
};

class TPicture;

class TPanelSystem {
public:
    TEasy_Panel* currentPanel();
};

class RGE_Scenario {
public:
    char* Get_scenario_name();
    char* Get_message(long id);
};

class RGE_World {
public:
    char gap_00[0x5C];
    RGE_Scenario* scenario;            // +0x5C
};

class RGE_Base_Game {
public:
    char gap_00[0x4C];
    TDrawArea* draw_area;              // +0x4C
    char gap_50[0x3F4 - 0x50];
    RGE_World* world;                  // +0x3F4
};

extern RGE_Base_Game* rge_base_game;
extern TPanelSystem panel_system;

class TRIBE_Mission_Screen : public TScreenPanel {
public:
    TTextPanel* title;                 // +0x478
    TTextPanel* list;                  // +0x47C
    TScrollBarPanel* scroll_bar;       // +0x480
    TButtonPanel* ok_button;           // +0x484
    TButtonPanel* text_buttons[3];     // +0x488
    unsigned char game_flag;           // +0x494
    char pad_495[3];
    TPicture* vc_back_bmp;             // +0x498

    TRIBE_Mission_Screen(char* info_file, unsigned char game_flag, TPicture* vc_back_bmp);
};

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
