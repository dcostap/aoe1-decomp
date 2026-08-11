// 0049E2E0 TribeLoadSavedGameScreen::action
// scr_load.cpp lines 187-275
// Attempt log:
// - Prior scratch was a broad decompiler-shaped scaffold: it used fake UI
//   helpers, the wrong child offsets, no real TEasy_Panel action surface, and
//   no compiler-owned new/EH path.  It was size-matched only by accident.
// - Reconstructed the period panel hierarchy and canonical child ownership
//   from the exact scr_load.cpp constructor/destructor/fillList donors.  The
//   target has a 0x478 TScreenPanel base and list/OK/cancel/delete at +480,
//   +488, +48C, +490; the inherited TPanel action slot is +B4.
// - Replaced fake wrappers with typed TPanel/TPanelSystem/TEasy_Panel and
//   RGE_Base_Game/TRIBE_Game calls.  The saved-game and single-player paths
//   retain the binary-observed file buffers, a leading _finddata_t-compatible
//   scratch window, and the direct new TribeSPMenuScreen expression.
// - baseline: typed /GX reconstruction was 1005B with all calls present but
//   a 0x324 frame; the frame/local layout probe identified the extra popup/
//   find scratch window.
// - control-flow probes: source-leading list handling plus the existing-Game-
//   Screen arm first restored the oracle's late virtual action and cold new
//   block; ordered calls reached 36/36 with no site gaps.
// - layout: `char fileInfo[0x230]` exposed the binary-backed scratch extent;
//   reducing it to 0x22C accounts for the compiler new-expression home and
//   reaches the exact 0x438 frame.  The larger typed window is kept as the
//   best period-plausible model, with `_finddata_t` used only at the API cast.
// - ABI/context and event/panel-local aliases were codegen duplicates and
//   were rolled back.  Final validation remains nonexact: 1005B, 0x438 frame,
//   36/36 ordered calls, 50.18% exact-block coverage, 898 positional diff
//   bytes.  The remaining broad gap starts in VC5 callee-save coloring and
//   the EH prologue (target EBX=event/EDI=panel/EBP=this); left in scratch.

#include <io.h>
#include <stdio.h>
#include <string.h>

class TDrawArea;
class TTextPanel;
class TListPanel;
class TButtonPanel;
class TScrollBarPanel;
class TInputPanel;
class TEditPanel;
class TDropDownPanel;
class TVerticalSliderPanel;

// The old panel ABI has action in slot 45 (+0xB4).  Keep the complete slot
// count here so the recursive action dispatch below is a real virtual call,
// not a fabricated direct helper.
class TPanel {
public:
    virtual ~TPanel();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
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
    virtual long action(TPanel*, long, unsigned long, unsigned long);

    char gap_04[0xF0];

    char* panelName();
    int get_string(int string_id, char* buffer, int length);
};

class TTextPanel : public TPanel {
public:
    char* currentLine();
    int numberLines();
    long get_line();
    long delete_line(long line);
};

class TListPanel : public TTextPanel {
};

class TButtonPanel : public TPanel {
public:
    void set_disabled(int disabled);
};

class TScrollBarPanel : public TPanel {
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];

    virtual long action(TPanel*, long, unsigned long, unsigned long);
    void popupYesNoDialog(char* message, char* title, int style, int timeout);
    void popupOKDialog(long string_id, char* title, int style, int timeout);
};

class TScreenPanel : public TEasy_Panel {
public:
    virtual ~TScreenPanel();
};

class TPanelSystem {
public:
    TPanel* panel(char* name);
    int setCurrentPanel(char* name, int mode);
    int destroyPanel(char* name);
};

extern TPanelSystem panel_system;

class RGE_Prog_Info {
public:
    char gap_00[0xB12];
    char save_dir[1];
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_04[8];
    RGE_Prog_Info* prog_info;
    char gap_10[0x9F0];
    int save_paused;

    int singlePlayerGame();
    void set_paused(int paused, int non_user_pause);
    void disable_input();
};

class TRIBE_Game : public RGE_Base_Game {
public:
    int load_game(char* file_name);
};

extern RGE_Base_Game* rge_base_game;

// The direct new-expression and its 0x49C size are compiler/EH evidence in
// the oracle, not a hand-written allocation wrapper.
class TribeSPMenuScreen {
public:
    char data[0x49C];
    TribeSPMenuScreen();
};

class TribeLoadSavedGameScreen : public TScreenPanel {
public:
    TTextPanel* screenTitle;                 // +0x478
    TTextPanel* listTitle;                   // +0x47C
    TListPanel* list;                         // +0x480
    TScrollBarPanel* scrollbar;              // +0x484
    TButtonPanel* okButton;                  // +0x488
    TButtonPanel* cancelButton;              // +0x48C
    TButtonPanel* deleteButton;              // +0x490

    virtual long action(TPanel*, long, unsigned long, unsigned long);
};

long TribeLoadSavedGameScreen::action(TPanel* panel, long msg,
                                      unsigned long p3, unsigned long p4) {
    char fileName[260];
    char fileNameNoExt[260];
    // The load API only consumes the leading _finddata_t window, while the
    // delete confirmation formats text into the same local.  The oracle's
    // 0x438 frame and contiguous local addresses prove the larger scratch
    // window rather than a standalone 0x118-byte _finddata_t.  The compiler's
    // 4-byte new-expression home occupies the remaining dword of the frame.
    char fileInfo[0x22C];

    if (panel != 0) {
        if (panel->panelName() != 0 &&
            strcmp(panel->panelName(), (char*)0x5860E4) == 0) {
            panel_system.destroyPanel((char*)0x5860E4);

            if (msg == 0) {
                RGE_Prog_Info* prog_info = rge_base_game->prog_info;
                char* line = this->list->currentLine();
                sprintf(fileName, (char*)0x586684, prog_info->save_dir, line);
                _unlink(fileName);

                prog_info = rge_base_game->prog_info;
                line = this->list->currentLine();
                sprintf(fileName, (char*)0x586678, prog_info->save_dir, line);
                _unlink(fileName);

                long current_line = this->list->get_line();
                this->list->delete_line(current_line);
                line = this->list->currentLine();
                if (*line == 0) {
                    this->okButton->set_disabled(1);
                    this->deleteButton->set_disabled(1);
                    return 1;
                }
            }
            return 1;
        }

        if (panel == this->deleteButton && msg == 1) {
            char* line = this->list->currentLine();
            if (*line != 0) {
                this->get_string(0x24CA, fileName, 0x100);
                sprintf(fileInfo, fileName, this->list->currentLine());
                this->popupYesNoDialog(fileInfo,
                                       (char*)0x5860E4, 0x1C2, 100);
            }
        }

        if (panel == this->list) {
            if (msg == 3) {
                this->action(this->okButton, 1, 0, 0);
                return 1;
            }
            goto fallback;
        }

        if (panel == this->okButton) {
            if (msg != 1) {
                goto fallback;
            }

            if (this->list->numberLines() > 0) {
                strcpy(fileNameNoExt, this->list->currentLine());
                sprintf(fileName, (char*)0x586678,
                        rge_base_game->prog_info->save_dir,
                        fileNameNoExt);
                long handle = _findfirst(fileName,
                                         (_finddata_t*)fileInfo);
                char* format;
                if (handle == -1) {
                    format = (char*)0x586670;
                } else {
                    format = (char*)0x586668;
                }
                sprintf(fileName, format, fileNameNoExt);
                int loaded = ((TRIBE_Game*)rge_base_game)->load_game(fileName);
                if (loaded == 0) {
                    this->popupOKDialog(0x2501, 0, 0x1C2, 100);
                    return 1;
                }
            }
        } else {
            if (panel != this->cancelButton || msg != 1) {
                goto fallback;
            }

            TPanel* game_screen = panel_system.panel((char*)0x5842CC);
            char* next_panel;
            if (game_screen != 0) {
                if (rge_base_game->singlePlayerGame() == msg &&
                    rge_base_game->save_paused == 0) {
                        rge_base_game->set_paused(0, 0);
                }
                next_panel = (char*)0x5842CC;
            } else {
                rge_base_game->disable_input();
                new TribeSPMenuScreen;
                next_panel = (char*)0x586638;
            }
            panel_system.setCurrentPanel(next_panel, 0);
            panel_system.destroyPanel((char*)0x586464);
        }
        return 1;
    }

fallback:
    return this->TEasy_Panel::action(panel, msg, p3, p4);
}
