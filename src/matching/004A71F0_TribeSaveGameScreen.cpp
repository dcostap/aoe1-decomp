// attempt 1: natural constructor reconstructed from panel creation sequence and /GX EH-shaped scr_save.cpp context
// attempt 2: add TScreenPanel +4 size pad; reverted constructor declaration to PDB order after arg-load probe failed
// attempt 3: use a titlePtr local to try to keep EBX anchored on +0x478 like original
// attempt 4: swapped mode/quit assignments to match early arg-load order
// attempt 5: introduce ok/delete/cancel pointer locals near button phase to reduce early EBX hoist
// attempt 6: rolled back button pointer locals; they hoisted EBX to +0x48c and worsened the early init basin
// attempt 7: tried keeping only titlePtr live through create_text; EBX still anchored on +0x48c, rolled back
// attempt 8: move panel pointer zeroing into constructor initializer list to probe original member-init lowering
// attempt 9: remove named from_panel local; keep current panel only in tabList[0] like original stack use
// attempt 10: use six-entry tabList so tabList[0] holds caller panel and tab order uses tabList+1, restoring original stack frame
// attempt 11: tried six-entry tabList plus titlePtr body local; worse than member-initializer zeroing, rolled back
// attempt 12: keep six-entry tabList/member-initializer baseline as current best
// attempt 13: probed six-entry tabList with direct body zeroing/direct title create_text; slightly worse, rolled back
// attempt 14: member-init baseline plus titlePtr local used only at create_text to probe EBX anchor
// attempt 15: added stdlib include as CRT context probe; no codegen change, rolled back
// attempt 16: correct local TPanel/TButtonPanel size surface so hotkey fields are +0x298/+0x29c while keeping screen fields at +0x478
// attempt 17: make edit width unsigned to match original jbe clamp compare
// attempt 18: spell width clamp with duplicated strlen in the else arm like original asm
// attempt 19: combine duplicated width clamp with direct body zeroing to restore vptr/mode/init order
// attempt 20: swapped scalar assignment order under current best constructor shape; worsened first mismatch, rolled back
// attempt 21: assigned mode through pointer local; worsened first mismatch, rolled back
// attempt 22: model vptr explicitly and manually store derived vtable to control vptr/mode ordering
// attempt 23: pre-load draw_area before get_popup_info_id to match original setup argument scheduling
// attempt 26: pass info_file (not +4) because VC5 pre-pushes the final setup arg before forming the pointer
// attempt 27: reordered final tabList stores; no codegen change
// attempt 28: split current-panel local from five-entry final tabList while preserving contiguous stack layout; same codegen as six-slot array
// attempt 29: used cancel/delete button locals and shared zero; improved to 4.0340 but preloaded delete too early
// attempt 30: tried cancel local only/direct delete stores; worsened target span, rolled back
// attempt 31: declared delete local after cancel stores; hotkey block now exact, remaining drift is final tabList load order
// attempt 32: swap final list/ok assignment source order to probe VC5 load scheduling
// attempt 24: tried five-slot tabList plus dummy local; stack frame shrank/worsened, rolled back
// attempt 25: tried five-slot tabList with 264-byte info buffer; frame ok but early stack offsets worsened, rolled back
// attempt 33: restored the complete inherited virtual surface in scr_save_context.h;
// VC5 now emits the derived vptr without a raw store, leaving only mode/vptr order drift
// attempt 34: moved modeValue into its natural member initializer; the shared
// scr_save.cpp build became exact while the smaller no-raw body differed by 10 bytes
// MODULE FLAGS: config/flags/scr_save.rsp

#include <string.h>
#include "../../include/scr_save_context.h"

#if 0
class TPanel;
class TTextPanel;
class TEditPanel;
class TListPanel;
class TScrollBarPanel;
class TButtonPanel;
class TDrawArea;

class TPanel {
public:
    void* vftable;
    char pad[0xEC];
    void set_help_info(long id, long param);
    void set_curr_child(TPanel* child);
    void set_tab_order(TPanel** panels, int count);
};

class TButtonPanel : public TPanel {
public:
    char gap_f0[0x298 - 0xF0];
    long hotkey;
    long hotkey_shift;
    void set_disabled(int disabled);
};

class TTextPanel : public TPanel {
public:
    char* currentLine();
};

class TEditPanel : public TTextPanel {};
class TListPanel : public TTextPanel {};
class TScrollBarPanel : public TPanel {};

class TEasy_Panel : public TPanel {
public:
    char pad_easy[0x384];

    char* get_popup_info_file();
    long get_popup_info_id();
    void setup_shadow_area(int param);
    void set_ideal_size(long x, long y);
    int create_text(TPanel* panel, TTextPanel** out, long id, long x, long y, long w, long h, long a, long b, long c, long d);
    int create_edit(TPanel* panel, TEditPanel** out, char* text, short width, long format, long x, long y, long w, long h, long font, long a, long b);
    int create_list(TPanel* panel, TListPanel** out, long x, long font, long w, long h, long lines);
    int create_auto_scrollbar(TScrollBarPanel** out, TTextPanel* text, long param);
    int create_button(TPanel* panel, TButtonPanel** out, long id, long a, long x, long y, long w, long h, long b, long c, long d);
};

class TScreenPanel : public TEasy_Panel {
public:
    char pad_screen[4];

    TScreenPanel(char* name);
    ~TScreenPanel();
    int setup(TDrawArea* draw_area, char* info_file, long info_id, int param);
};

class TPanelSystem {
public:
    TEasy_Panel* currentPanel();
};

extern TPanelSystem panel_system;

class TRIBE_Game {
public:
    char gap_0[0x0C];
    char* base_path;
    char gap_10[0x4C - 0x10];
    TDrawArea* draw_area;
    char gap_50[0x1E8 - 0x50];
    char work_dir[1];

    char* get_save_game_name();
};

extern TRIBE_Game* rge_base_game;

class TribeSaveGameScreen : public TScreenPanel {
public:
    TTextPanel* title;
    TEditPanel* input;
    TListPanel* list;
    TScrollBarPanel* scrollbar;
    TButtonPanel* okButton;
    TButtonPanel* cancelButton;
    TButtonPanel* deleteButton;
    char fileName[260];
    char fileNameNoExt[260];
    int modeValue;
    int quit_after_save;

    enum Mode { SaveGame = 0, SaveScenario = 1 };

    TribeSaveGameScreen(Mode mode, char* name, int quit_after_save);
    void fillList();
};
#endif

TribeSaveGameScreen::TribeSaveGameScreen(Mode mode, char* name, int quit) : TScreenPanel("Save Game Screen"), modeValue(mode) {
    TPanel* fromPanel;
    TPanel* tabList[5];
    char info_file[260];

    this->quit_after_save = quit;
    this->title = 0;
    this->input = 0;
    this->list = 0;
    this->scrollbar = 0;
    this->okButton = 0;
    this->cancelButton = 0;
    this->deleteButton = 0;

    if (name == 0 && mode == SaveGame) {
        name = ((TRIBE_Game*)rge_base_game)->get_save_game_name();
    }

    fromPanel = panel_system.currentPanel();
    strcpy(info_file, ((TEasy_Panel*)fromPanel)->get_popup_info_file());

    TDrawArea* draw_area = rge_base_game->draw_area;
    if (!this->setup(draw_area, info_file, ((TEasy_Panel*)fromPanel)->get_popup_info_id(), 1)) {
        *(int*)((char*)this + 0xD8) = 1;
        return;
    }

    this->setup_shadow_area(0);
    this->set_ideal_size(640, 480);

    TTextPanel** titlePtr = &this->title;
    if (!this->create_text(this, titlePtr, (this->modeValue != SaveGame) + 0x24C3, 20, 20, 600, 30, 1, 1, 0, 0)) {
        return;
    }

    unsigned int width;
    if (0x7A - strlen(rge_base_game->work_dir) > 0x50) {
        width = 0x50;
    } else {
        width = 0x7A - strlen(rge_base_game->work_dir);
    }

    if (!this->create_edit(this, &this->input, name, (short)width, FormatFileName, 20, 70, 600, 23, 11, 1, 1)) {
        return;
    }
    this->input->set_help_info(0x7670, -1);

    if (!this->create_list(this, &this->list, 20, 0x6E, 600, 300, 11)) {
        return;
    }
    if (!this->create_auto_scrollbar(&this->scrollbar, this->list, 20)) {
        return;
    }
    this->scrollbar->set_help_info(0x7671, -1);

    if (!this->create_button(this, &this->okButton, 0xFA1, 0, 30, 440, 180, 30, 0, 0, 0)) {
        return;
    }
    if (!this->create_button(this, &this->deleteButton, 0x24C9, 0, 230, 440, 180, 30, 0, 0, 0)) {
        return;
    }
    if (!this->create_button(this, &this->cancelButton, 0xFA2, 0, 430, 440, 180, 30, 0, 0, 0)) {
        return;
    }

    this->okButton->set_help_info(0x7531, -1);
    this->cancelButton->set_help_info(0x7532, -1);
    TButtonPanel* cancelLocal = this->cancelButton;
    int zero = 0;
    cancelLocal->hotkey = 0x1B;
    cancelLocal->hotkey_shift = zero;
    TButtonPanel* deleteLocal = this->deleteButton;
    deleteLocal->hotkey_shift = zero;
    deleteLocal->hotkey = 0x2E;

    this->fillList();
    if (this->list->currentLine()[0] == 0) {
        this->deleteButton->set_disabled(1);
    }

    this->set_curr_child(this->input);
    tabList[0] = this->input;
    tabList[1] = this->list;
    tabList[2] = this->okButton;
    tabList[3] = this->deleteButton;
    tabList[4] = this->cancelButton;
    this->set_tab_order(tabList, 5);
}
