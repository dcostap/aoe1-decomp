// attempt 1: natural action reconstruction from packet/decompiler; broad first pass, stack frame was 4 bytes short
// attempt 2: make text scratch 560 bytes to match original 0x334 local frame
// attempt 3: flatten local panel stubs so TribeSaveGameScreen fields land at true +0x478 offsets
// attempt 4: spell Cancel Dialog msg==0 body to try to avoid early local epilogue
// attempt 5: name save/scenario dir locals before currentLine calls in Cancel Dialog path
// attempt 6: tried visible TPanel vptr for TPanel-base calls; worsened overall diff, rolled back
// attempt 7: declared TPanel helper methods directly on TribeSaveGameScreen; no improvement, rolled back
// attempt 8: tried hoisting prog_info before second Cancel Dialog extension unlink branch; object became 15 bytes short, rolled back
// attempt 9: declared get_string/set_curr_child on TEasy_Panel; worsened overall diff, rolled back
// attempt 10: tried removing TEasy_Panel base and putting panel helpers directly; worsened diff, rolled back
// attempt 11: tried real TPanel/TEasy sizes plus screen gap; worsened diff, rolled back
// attempt 10: tried explicit TPanel casts for inherited panel helpers; worsened diff, rolled back
// attempt 12: tried pre-loading rge_base_game after first Cancel Dialog unlink; worsened diff, rolled back
// attempt 13: pre-loaded ProgramInfo after first unlink; improved to 36.8396, kept
// attempt 14: named currentLine locals in second-extension branch; no codegen change
// attempt 15: wrote empty-name popup as mode==0 first; slight improvement, kept
// attempt 18: loaded mode before ProgramInfo in second-extension branch; improved schedule, kept
// attempt 19: hoisted second-extension dir/format selection into common sprintf; worsened branch layout, rolled back
// attempt 20: spelled second-extension dirs as explicit byte offsets; no codegen change
// attempt 21: removed named line locals in explicit-offset second-extension branch; no codegen change
// attempt 27: named second-extension output pointer; no codegen change
// attempt 28: introduced game2 local before prog2; improved to 29.6171, kept
// attempt 29: removed no-op out2 local under game2/prog2 shape; no codegen change
// attempt 30: declared game2 before mode2; worsened diff, rolled back
// attempt 22: replaced ternary setCurrentPanel with explicit if/else; matched original branch shape in cancel path, kept
// attempt 23: declared set_curr_child directly on TribeSaveGameScreen; object shrank to 2048/.text extraction failed, rolled back
// attempt 24: used zero-offset facade for get_string/set_curr_child; object shrank to 2048/.text extraction failed, rolled back
// attempt 25: used zero-offset facade only for delete prompt get_string; worsened diff, rolled back
// attempt 26: used zero-offset facade only for dialog set_curr_child; object shrank to 2048/.text extraction failed, rolled back
// attempt 16: declared get_string directly on TribeSaveGameScreen; worsened diff, rolled back
// attempt 17: made TPanel polymorphic; object shrank to 2048/.text extraction failed, rolled back
// attempt 31: inverted YesNoDialog msg branch; restored original 71-call topology and reduced size gap to 2 bytes
// attempt 32: restored canonical RGE_Base_Game/RGE_Prog_Info ownership; codegen duplicate, kept as source cleanup

// probe 32: direct second-extension expressions; diff 1703 and branch basin worsened, rolled back
// probe 33: branch-local currentLine result; emitted code unchanged, rolled back
// probe 34: canonical RGE_Base_Game/RGE_Prog_Info ownership and inherited base calls; emitted code unchanged, kept
// probe 35: mode local with direct prog_info expressions; diff 1703 and branch basin worsened, rolled back
// probe 36: named second-extension directory locals; emitted code unchanged, rolled back
// probe 37: direct modeValue/prog_info expressions followed the original decomp but duplicated probe 14 at diff 1703; rolled back
// probe 38: branch-local second-extension list aliases matched the clean 747-byte codegen; no new emitted-code lead, rolled back
// probe 41/H21 and probe 61/H31: direct modeValue with a direct prog_info local worsened to diff 924; rolled back.
// probes 43/H22, 49/H25, 51/H26, and 57/H29: branch-local line or base/self aliases
// preserved the clean 747-byte basin but did not move the first structural hunk; rolled back.
// probes 45/H23, 53/H27, and 59/H30: game/prog_info alias variants worsened to
// diff 1221 or 919; rolled back. Probe 47/H24 conditional directory selection
// worsened to diff 1699. These tests do not prove a canonical alias shape.
// BLOCKER: After the first _unlink, the executable reads the screen member at
// +0x69C before rge_base_game. The rebuild reads rge_base_game first. Fault and
// concurrent-mutation order differ before the same later calls.

#include <stdio.h>
#include <string.h>
#include <io.h>

class TPanel {
public:
    char* panelName();
    int get_string(int id, char* dest, int size);
    void set_curr_child(TPanel* child);
};

class TButtonPanel : public TPanel {
public:
    void set_disabled(int disabled);
};

class TTextPanel : public TPanel {
public:
    char* currentLine();
    long get_line();
    int delete_line(long line);
};

class TEditPanel : public TTextPanel {
public:
    void set_text(char* text);
    char* get_trimmed_str(char* out, int size);
};

class TListPanel : public TTextPanel {};
class TScrollBarPanel {};

class TEasy_Panel : public TPanel {
public:
    virtual long action(TPanel* panel, long msg, unsigned long p3, unsigned long p4);
    void popupOKDialog(long id, char* text, long type, long timeout);
    void popupYesNoDialog(long id, char* text, long type, long timeout);
    void popupYesNoDialog(char* text, char* name, long type, long timeout);
};

class TPanelSystem {
public:
    int destroyPanel(char* name);
    int setCurrentPanel(char* name, int param);
};

extern TPanelSystem panel_system;

class RGE_Prog_Info {
public:
    char gap_0[0xB12];
    char save_dir[0x105];
    char scenario_dir[1];
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_4[0x08];
    RGE_Prog_Info* prog_info;
    char gap_10[0xA00 - 0x10];
    int save_paused;

    int singlePlayerGame();
    void set_paused(int a, int b);
};

class TRIBE_Game : public RGE_Base_Game {
public:
    int save_game(char* name);
    int save_scenario(char* name);
};

extern RGE_Base_Game* rge_base_game;

class TribeSaveGameScreen : public TEasy_Panel {
public:
    char gap_0[0x474];
    TPanel* title;
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

    long action(TPanel* panel, long msg, unsigned long p3, unsigned long p4);
    void save_for_scenario_editor();
};

long TribeSaveGameScreen::action(TPanel* panel, long msg, unsigned long p3, unsigned long p4) {
    // BINARY NOTE: The executable keeps state bytes before the formatted text in both buffers.
    char tempFileName[260];
    char text[560];

    if (panel != 0) {
        char* panel_name = panel->panelName();
        if (panel_name != 0 && strcmp(panel->panelName(), "Cancel Dialog") == 0) {
            panel_system.destroyPanel("Cancel Dialog");
            if (msg == 0) {
                if (this->modeValue == 0) {
                    char* dir = rge_base_game->prog_info->save_dir;
                    sprintf(tempFileName + 4, "%s%s.gam", dir, this->list->currentLine());
                } else {
                    char* dir = rge_base_game->prog_info->scenario_dir;
                    sprintf(tempFileName + 4, "%s%s.scn", dir, this->list->currentLine());
                }
                _unlink(tempFileName + 4);
                int mode2;
                mode2 = this->modeValue;
                TRIBE_Game* game2 = (TRIBE_Game*)rge_base_game;
                RGE_Prog_Info* prog2 = game2->prog_info;
                // BINARY NOTE: Each extension arm fetches the current list line before formatting.
                if (mode2 == 0) {
                    sprintf(tempFileName + 4, "%s%s.gmx", ((char*)prog2) + 0xB12, this->list->currentLine());
                } else {
                    sprintf(tempFileName + 4, "%s%s.scx", ((char*)prog2) + 0xC17, this->list->currentLine());
                }
                _unlink(tempFileName + 4);
                this->list->delete_line(this->list->get_line());
                this->input->set_text(this->list->currentLine());
                if (this->list->currentLine()[0] == 0) {
                    this->deleteButton->set_disabled(1);
                }
            }
            return 1;
        }

        if (panel == this->deleteButton && msg == 1 && this->list->currentLine()[0] != 0) {
            this->get_string(0x24CA, tempFileName + 4, 0x100);
            sprintf(text + 4, tempFileName + 4, this->list->currentLine());
            this->popupYesNoDialog(text + 4, "Cancel Dialog", 0x1C2, 100);
        }

        TListPanel* listPanel = this->list;
        if (panel == listPanel && msg == 1) {
            this->input->set_text(listPanel->currentLine());
            return 1;
        }

        if ((panel == this->okButton && msg == 1) || (panel == this->input && msg == 0) || (panel == listPanel && msg == 3)) {
            char* base = this->fileNameNoExt;
            this->input->get_trimmed_str(base, 0x104);
            if (strlen(base) == 0) {
                if (this->modeValue == 0) {
                    this->popupOKDialog(0x24C6, 0, 0x1C2, 100);
                } else {
                    this->popupOKDialog(0x24C7, 0, 0x1C2, 100);
                }
                return 1;
            }

            // BINARY NOTE: Byte 3 is the existence flag; formatted paths start at byte 4.
            tempFileName[3] = 0;
            if (this->modeValue == 0) {
                sprintf(this->fileName, "%s.gam", base);
                sprintf(tempFileName + 4, "%s%s", rge_base_game->prog_info->save_dir, this->fileName);
            } else {
                sprintf(this->fileName, "%s.scn", base);
                sprintf(tempFileName + 4, "%s%s", rge_base_game->prog_info->scenario_dir, this->fileName);
            }
            FILE* fp = fopen(tempFileName + 4, "rb");
            if (fp != 0) {
                tempFileName[3] = 1;
                fclose(fp);
            }
            if (this->modeValue == 0) {
                sprintf(this->fileName, "%s.gmx", base);
                sprintf(tempFileName + 4, "%s%s", rge_base_game->prog_info->save_dir, this->fileName);
            } else {
                sprintf(this->fileName, "%s.scx", base);
                sprintf(tempFileName + 4, "%s%s", rge_base_game->prog_info->scenario_dir, this->fileName);
            }
            if (tempFileName[3] == 0) {
                fp = fopen(tempFileName + 4, "rb");
                if (fp != 0) {
                    tempFileName[3] = 1;
                    fclose(fp);
                }
                if (tempFileName[3] == 0) {
                    int mode = this->modeValue;
                    if (mode == 0) {
                        if (!((TRIBE_Game*)rge_base_game)->save_game(this->fileName)) {
                            this->popupOKDialog(0x962, 0, 0x1C2, 100);
                        }
                    } else if (mode == 1) {
                        if (!((TRIBE_Game*)rge_base_game)->save_scenario(this->fileName)) {
                            this->popupOKDialog(0x963, 0, 0x1C2, 100);
                        }
                    } else if (mode == 2) {
                        this->save_for_scenario_editor();
                    }
                    return 1;
                }
            }
            this->popupYesNoDialog(0x24C8, 0, 0x1C2, 100);
            return 1;
        }

        if ((panel == this->cancelButton && msg == 1) || (panel == this->input && msg == 1)) {
            if (rge_base_game->singlePlayerGame() == 1 && rge_base_game->save_paused == 0) {
                rge_base_game->set_paused(0, 0);
            }
            if (this->modeValue == 2) {
                panel_system.setCurrentPanel("Scenario Editor Screen", 0);
            } else {
                panel_system.setCurrentPanel("Game Screen", 0);
            }
            panel_system.destroyPanel("Save Game Screen");
            return 1;
        }

        panel_name = panel->panelName();
        if (panel_name != 0 && strcmp(panel->panelName(), "OKDialog") == 0) {
            panel_system.destroyPanel("OKDialog");
            this->set_curr_child(this->input);
            return 1;
        }

        panel_name = panel->panelName();
        if (panel_name != 0 && strcmp(panel->panelName(), "YesNoDialog") == 0) {
            if (msg == 0) {
                panel_system.destroyPanel("YesNoDialog");
                int mode = this->modeValue;
                if (mode == 0) {
                    this->input->get_trimmed_str(this->fileNameNoExt, 0x104);
                    sprintf(tempFileName + 4, "%s%s.gam", rge_base_game->prog_info->save_dir, this->fileNameNoExt);
                    _unlink(tempFileName + 4);
                    if (!((TRIBE_Game*)rge_base_game)->save_game(this->fileName)) {
                        this->popupOKDialog(0x962, 0, 0x1C2, 100);
                    }
                    return 1;
                }
                if (mode == 1) {
                    this->input->get_trimmed_str(this->fileNameNoExt, 0x104);
                    sprintf(tempFileName + 4, "%s%s.scn", rge_base_game->prog_info->scenario_dir, this->fileNameNoExt);
                    _unlink(tempFileName + 4);
                    if (!((TRIBE_Game*)rge_base_game)->save_scenario(this->fileName)) {
                        this->popupOKDialog(0x963, 0, 0x1C2, 100);
                    }
                    return 1;
                }
                if (mode == 2) {
                    this->input->get_trimmed_str(this->fileNameNoExt, 0x104);
                    sprintf(tempFileName + 4, "%s%s.scn", rge_base_game->prog_info->scenario_dir, this->fileNameNoExt);
                    _unlink(tempFileName + 4);
                    this->save_for_scenario_editor();
                    return 1;
                }
            } else {
                panel_system.destroyPanel("YesNoDialog");
                this->set_curr_child(this->input);
            }
            return 1;
        }
    }

    return TEasy_Panel::action(panel, msg, p3, p4);
}
