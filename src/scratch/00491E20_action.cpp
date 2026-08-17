// VA: 00491E20 TribeJoinScreen::action
// PDB source: scr_cj.cpp, lines 289-368
//
// Canonical ownership is TribeJoinScreen's named panel fields at +0x478..+0x4AC.
// The two 256-byte formatting buffers are the natural local arrays used by the
// join-error path.  The startup/create branches use real C++ new expressions;
// the original EH state around those constructors is therefore compiler-owned.
//
// Attempt log:
// - binary ownership: PDB lines 289-368, 22 ordered calls, +0x488..+0x4AC
//   fields, a 0x204 frame, and one saved ESI establish this typed screen model.
// - source recovery: natural panel guards, shared result/done flow, real
//   constructor new expressions, and the two 256-byte local arrays restore
//   the complete 671-byte body and all calls.
// - expression: passing temp and string at their array bases, not at +4,
//   changes the frontier from 16 to 12 bytes and makes the full body through
//   the fallback call byte-identical.  PDB LEAs at +8 and +108 support this.
// - declaration/lifetime: function-scope arrays, reversed array order, named
//   new results, result width/initialization, command copies, aliases, and
//   explicit constructor parentheses were neutral and were rejected.
// - control-flow: early fallback and reordered first-arm predicates either
//   stayed neutral or widened the diff.  The positive outer guard and nested
//   checks remain the binary-backed form.
// - ABI/context: <new.h>, plain allocation-site class shells, destructor
//   definitions, and global operator-delete declarations were neutral.  An
//   int command changed the virtual call from slot B4 to B8.  Long is required.
// - diagnostic only: volatile command caused a 474-byte mismatch with forced
//   rereads and extra saved registers.  It is not a source recovery method.
// - exact frontier: original prolog loads command before pushing the saved FS
//   value, then loads panel.  Rebuilt code pushes FS first, then loads panel
//   and command.  Original epilogue restores FS before pop ESI; rebuilt pops
//   ESI first.  The handler relocation is original 55EA3C versus rebuilt 0.
// - left in scratch: exact size/frame, saved-register set, CFG, all 22 calls,
//   and 145 instructions across 28 blocks match.  The remaining 12 bytes are
//   confined to the EH/prolog and EH epilogue frontier.
// FLAGS: /nologo /c /O2 /Oy /GX (retained for the binary EH registration).

#include <stdio.h>

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

typedef int PositionMode;
typedef int RedrawMode;

class TDrawArea;
class TButtonPanel;
class TTextPanel;
class TListPanel;
class TScrollBarPanel;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(PositionMode, long, long, long, long, long, long,
                                 long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(RedrawMode);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, RedrawMode);
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(tagRECT*);
    virtual void draw_offset(long, long, tagRECT*);
    virtual void draw_rect2(tagRECT*);
    virtual void draw_offset2(long, long, tagRECT*);
    virtual void paint();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual long handle_idle();
    virtual long handle_size(long, long);
    virtual long handle_paint();
    virtual long handle_key_down(long, short, int, int, int);
    virtual long handle_char(long, short);
    virtual long handle_command(unsigned int, long);
    virtual long handle_user_command(unsigned int, long);
    virtual long handle_timer_command(unsigned int, long);
    virtual long handle_scroll(long, long);
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
    virtual long handle_mouse_move(long, long, int, int);
    virtual long handle_mouse_up(unsigned char, long, long, int, int);
    virtual long handle_mouse_dbl_click(unsigned char, long, long, int, int);
    virtual long mouse_move_action(long, long, int, int);
    virtual long mouse_left_down_action(long, long, int, int);
    virtual long mouse_left_hold_action(long, long, int, int);
    virtual long mouse_left_move_action(long, long, int, int);
    virtual long mouse_left_up_action(long, long, int, int);
    virtual long mouse_left_dbl_click_action(long, long, int, int);
    virtual long mouse_right_down_action(long, long, int, int);
    virtual long mouse_right_hold_action(long, long, int, int);
    virtual long mouse_right_move_action(long, long, int, int);
    virtual long mouse_right_up_action(long, long, int, int);
    virtual long mouse_right_dbl_click_action(long, long, int, int);
    virtual long key_down_action(long, short, int, int, int);
    virtual long char_action(long, short);
    virtual long action(TPanel*, long, unsigned long, unsigned long);

    char gap_04[0xF0];

    int get_string(int resid, char* buffer, int len);
};

class TButtonPanel : public TPanel {
};

class TScrollBarPanel : public TPanel {
};

class TTextPanel : public TPanel {
public:
    int currentLineNumber() const;
    char* currentLine();
};

class TListPanel : public TTextPanel {
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];

    virtual ~TEasy_Panel();
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    void popupOKDialog(long text_id, char* panel_name, int param_4, int param_5);
    void popupOKDialog(char* text, char* panel_name, int param_4, int param_5);
};

class TScreenPanel : public TEasy_Panel {
public:
    virtual ~TScreenPanel();
};

class TDialogPanel : public TEasy_Panel {
public:
    char gap_478[0x18];
};

class TribeMPStartupScreen : public TScreenPanel {
public:
    char gap_478[0x6A0 - 0x478];
    virtual ~TribeMPStartupScreen();
    TribeMPStartupScreen();
};

class TribeMPCreateDialog : public TDialogPanel {
public:
    char gap_490[0x4A4 - 0x490];
    virtual ~TribeMPCreateDialog();
    TribeMPCreateDialog(TPanel* parent);
};

struct _GUID;

class TCommunications_Handler {
public:
    int JoinMultiplayerGame(_GUID* guid);
    void UnlinkToLevel(int param);
};

class TCommunications_Sessions {
public:
    _GUID* GetSessionGUID(int index);
};

class RGE_Base_Game {
public:
    void disable_input();
    void close();
};

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int param);
    int destroyPanel(char* name);
};

extern RGE_Base_Game* rge_base_game;
extern TCommunications_Handler* comm;
extern TCommunications_Sessions* Sess;
extern TPanelSystem panel_system;
extern "C" unsigned long __cdecl debug_timeGetTime(char* file, int line);

class TribeJoinScreen : public TScreenPanel {
public:
    int startedSession;
    int listFilled;
    TTextPanel* title;
    TTextPanel* listTitle;
    TListPanel* list;
    TScrollBarPanel* scrollbar;
    TButtonPanel* joinButton;
    TButtonPanel* createButton;
    TButtonPanel* cancelButton;
    TButtonPanel* refreshButton;
    TButtonPanel* close_button;
    int game_count;
    int waitingToStart;
    unsigned long joinTime;

    virtual long action(TPanel*, long, unsigned long, unsigned long);
    void fillList();
};

long TribeJoinScreen::action(TPanel* panel, long command,
                             unsigned long param3, unsigned long param4)
{
    long result;

    if (panel != 0) {
        if (panel == this->list) {
            if (command == 3 && this->game_count > 0) {
                this->action(this->joinButton, 1, 0, 0);
                result = 1;
                goto done;
            }
        } else if (panel == this->joinButton) {
            if (command == 1) {
                if (this->game_count > 0) {
                    int line = this->list->currentLineNumber();
                    _GUID* guid = Sess->GetSessionGUID(line);
                    int join_result = comm->JoinMultiplayerGame(guid);
                    if (join_result == 0) {
                        char temp[256];
                        char string[256];
                        this->get_string(0x25A3, temp, 0x100);
                        sprintf(string, temp, this->list->currentLine());
                        TEasy_Panel::popupOKDialog(string, 0, 0x1C2, 100);
                        result = 1;
                        goto done;
                    }

                    rge_base_game->disable_input();
                    this->waitingToStart = 1;
                    this->joinTime = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\scr_cj.cpp", 0x140);
                    result = 1;
                    goto done;
                }

                TEasy_Panel::popupOKDialog(0x25A4, 0, 0x1C2, 100);
                result = 1;
                goto done;
            }
        } else if (panel == this->cancelButton) {
            if (command == 1) {
                rge_base_game->disable_input();
                comm->UnlinkToLevel(2);
                new TribeMPStartupScreen;
                panel_system.setCurrentPanel("MP Startup Screen", 0);
                panel_system.destroyPanel("Join Screen");
                result = 1;
                goto done;
            }
        } else if (panel == this->createButton && command == 1) {
            new TribeMPCreateDialog(this);
            result = 1;
            goto done;
        } else if (panel == this->refreshButton) {
            if (command == 1) {
                this->fillList();
                result = 1;
                goto done;
            }
        } else {
            if (panel != this->close_button || command != 1)
                goto fallback;

            rge_base_game->close();
            result = 1;
            goto done;
        }
    } else {
        goto fallback;
    }

    result = 1;
    goto done;

fallback:
    result = TEasy_Panel::action(panel, command, param3, param4);

done:
    return result;
}
