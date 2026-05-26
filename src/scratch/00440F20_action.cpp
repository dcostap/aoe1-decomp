// 00440F20 TribeSendMessageDialog::action
// Attempt log:
// 1: behavior reconstruction from packet/Ghidra: send/close/help/filter buttons and fallback base action.
// 2: initial helper-based copy/send source compiled under-size (1104); inlined COPY_LINE/SEND_CHAT macros grew to 1232.
// 3: changed COPY_LINE to repeat currentLine() calls like original; reached exact 1264-byte size under default /O2 /Oy.
// 4: fixed player-button branch to toggle the four filter buttons at +504/+508/+50C/+510 instead of treating them as contiguous playerButtons[8..11].
// 5: /Od probe reached exact size but wrong EBP/debug-frame basin (81.0127% positional / 164.7943% edit) and was removed.
// 6: best exact-size /O2 attempt still broad mismatch (75.7911% positional / 90.5854% edit). First mismatch is early branch layout: original sends many cases to shared late epilogues/checkButtons tails, while natural source emits early returns and different block placement. Remaining gap is control-flow factoring/tail-sharing plus exact typed virtual/global surfaces, not accepted_drift-safe.

#include <string.h>

typedef unsigned long ulong;
class TPanel {};
class TEditPanel { public: char* currentLine(); void set_text(char*); };
class ScreenGame { public: void display_system_message(char*); };
class PanelSystem { public: int setCurrentPanel(char*, int); int destroyPanel(char*); };
class Comm { public: void SendGroupChatMsg(char*); };
class Log { public: void LogMsg(char*, ...); };
class PlayerObj { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual int canAlly(int); virtual int canEnemy(int); short pad4a; };
class BaseGame { public: void** vf; char gap[0x1B0-4]; int state; char gap2[0x3F4-0x1B4]; void* player; int chat(short,char*); int multiplayerGame(); int play_sound(int); int playerID(int); };
class Button { public: virtual void f0(); char gap[0xE0-4]; virtual void set_checked(int); };

extern BaseGame* rge_base_game;
extern Comm* comm;
extern Log* L;
extern PanelSystem panel_system;

class TribeSendMessageDialog {
public:
    char gap0[0x40];
    ScreenGame* screen; // +40
    char gap44[0x4D4-0x44];
    Button* playerButtons[8]; // +4D4
    char gap4f4[0x504-0x4F4];
    TPanel* alliesButton; // +504
    TPanel* enemiesButton; // +508
    TPanel* allButton; // +50C
    TPanel* noneButton; // +510
    char gap514[4];
    TEditPanel* edit; // +518
    char gap51c[4];
    TPanel* sendButton; // +520
    TPanel* helpButton; // +524
    long action(TPanel*, long, ulong, ulong);
    void checkButtons();
    void setup_popup_help();
    long base_action(TPanel*, long, ulong, ulong);
};


#define COPY_LINE(edit,out) do { if ((edit)->currentLine() && *(edit)->currentLine()) strcpy((out), (edit)->currentLine()); else (out)[0]=0; } while(0)
#define SEND_CHAT(msg,screen) do {     int player = *(short*)((char*)rge_base_game->player + 0x7c);     if (!rge_base_game->chat((short)player, (msg))) {         if (rge_base_game->multiplayerGame()) {             if (rge_base_game->state != 5) {                 comm->SendGroupChatMsg((msg));                 L->LogMsg((char*)0x584440, *(int*)((char*)rge_base_game->player + 4), (msg));             }         } else {             rge_base_game->play_sound(2);             (screen)->display_system_message((msg));         }     } } while(0)

long TribeSendMessageDialog::action(TPanel* panel, long p2, ulong p3, ulong p4)
{
    char save_msg[0x42];
    if (panel) {
        if (panel == (TPanel*)this->edit) {
            if (p2) return 1;
            ScreenGame* scr = this->screen;
            COPY_LINE(this->edit, save_msg);
            if (!*save_msg) return 1;
            SEND_CHAT(save_msg, scr);
            this->edit->set_text((char*)0x592A40);
            return 1;
        }
        if (panel == this->sendButton) {
            if (p2 != 1) { this->checkButtons(); return 1; }
            this->checkButtons();
            ScreenGame* scr = this->screen;
            COPY_LINE(this->edit, save_msg);
            panel_system.setCurrentPanel((char*)0x5842CC, 0);
            panel_system.destroyPanel((char*)0x58442C);
            if (!*save_msg) return 1;
            SEND_CHAT(save_msg, scr);
            return 1;
        }
        if (panel == this->helpButton) { this->setup_popup_help(); return 1; }
        Button** buttons = this->playerButtons;
        if (panel == (TPanel*)buttons[0] || panel == (TPanel*)buttons[1] || panel == (TPanel*)buttons[2] || panel == (TPanel*)buttons[3] || panel == (TPanel*)buttons[4] || panel == (TPanel*)buttons[5] || panel == (TPanel*)buttons[6] || panel == (TPanel*)buttons[7]) {
            ((Button*)this->alliesButton)->set_checked(0);
            ((Button*)this->enemiesButton)->set_checked(0);
            ((Button*)this->allButton)->set_checked(0);
            ((Button*)this->noneButton)->set_checked(1);
            this->checkButtons();
            return 1;
        }
        if (panel == this->alliesButton) {
            PlayerObj* pl = *(PlayerObj**)(*(int*)((char*)rge_base_game->player + 0x40) + (*(short*)((char*)rge_base_game->player + 0x7c))*4);
            for (int i=0;i<8;i++) if (buttons[i]) {
                int pid = rge_base_game->playerID(*(int*)((char*)&buttons[i] + 0x58));
                buttons[i]->set_checked((pid == *(short*)((char*)pl+0x4a) || pl->canAlly(pid)) ? 1 : 0);
            }
            this->checkButtons(); return 1;
        }
        if (panel == this->enemiesButton) {
            PlayerObj* pl = *(PlayerObj**)(*(int*)((char*)rge_base_game->player + 0x40) + (*(short*)((char*)rge_base_game->player + 0x7c))*4);
            for (int i=0;i<8;i++) if (buttons[i]) {
                int pid = rge_base_game->playerID(*(int*)((char*)&buttons[i] + 0x58));
                buttons[i]->set_checked((pid != *(short*)((char*)pl+0x4a) && pl->canEnemy(pid)) ? 1 : 0);
            }
            this->checkButtons(); return 1;
        }
        if (panel == this->allButton) {
            if (p2 != 1) { this->checkButtons(); return 1; }
            for (int i=0;i<8;i++) if (buttons[i]) buttons[i]->set_checked(1);
            this->checkButtons(); return 1;
        }
        if (panel == this->noneButton) { this->checkButtons(); return 1; }
        this->checkButtons(); return 1;
    }
    return this->base_action(panel, p2, p3, p4);
}
