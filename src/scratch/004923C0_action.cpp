// Attempt log for 004923C0 TribeMPCreateDialog::action
// baseline (prior worker): behavioral scaffold had exact size but used
// approximate panel/registry/log/DirectPlay surfaces and diverged from byte 25.
// probe 1 baseline (sa8d964310_r1): same scaffold rebuilt at 806 bytes;
// structural reconstruction is required before register tuning.
// probe 2-3 layout: restored the scr_cj TPanel/TDialogPanel boundary and
// named +0x20 render-area/+0x40 parent ownership; calls and fields aligned.
// probe 4-5 control-flow: strlen(currentLine)+1, aggregate ServiceGUID copy,
// reversed memcmp operands, duplicated status arms, and the typed DirectDraw
// chain recovered the original GUID/COM block and all 32 call sites.
// probe 6-7 ABI/liveness: typed PlayerStopTurn[1] clear and variadic
// TDebuggingLog::Log member ABI; the latter changes only the decorated target.
// probe 8: initialized result local forced a 0x14 frame and was rolled back.
// probe 9-10: nested result tree and dead-param result variants were unchanged
// or broader; restored the typed goto/result reconstruction.
// left in scratch: rebuilt 865B versus original 790B. Remaining drift is the
// compiler's duplicated EH epilogues/shared-return topology and one late
// register/order hunk around the PlayerStopTurn clear; behavior/calls/layout
// are otherwise binary-backed. No accepted-drift claim.
// probe 14 control-flow: direct returns instead of goto done were codegen
// identical; restored the shared result form.
// probe 15 control-flow: nested else-if and explicit fallback label were
// codegen identical; restored the simpler sibling guards.
// probe 16 liveness: a function-scope setup-screen pointer around new was
// codegen identical; restored the direct new expression.
// probe 17 ABI: adding a setup-screen virtual destructor worsened block shape;
// restored the narrow constructor-only class surface.
// probe 18 control-flow: explicit early null fallback was codegen identical;
// restored the positive outer guard.
// probe 19 control-flow: Ghidra's failure-first create-result source order
// moved four call sites and was rejected; restored success-first order.
// probe 23 control-flow: a single-iteration break join grew the function by
// 27 bytes and broke the ordered-call prefix; restored the binary-backed goto
// result topology.
// probe 26 ABI: model the generated TScreenPanel base and setup-screen virtual
// destructor while preserving sizeof(TribeMPSetupScreen)==0x890; emitted code
// was identical, so restored the narrow constructor-only local surface.
// probe 28 context: include <new.h> for the period operator-new declaration;
// emitted code was identical and the EH tail remained cloned.
// probe 30 variant: explicit default-constructor parentheses on new
// TribeMPSetupScreen emitted identical code; restored the clean spelling.
// Revisit probes 31-34: direct returns, failure-first create-result order,
// one common create-result return, and one success label all stayed in the
// 865-byte EH-tail basin or moved calls. Canonical derived destructors and
// function-scope locals were unchanged. A fully joined result tree reached
// 873B/0x14, then an initialized result reached 854B but broadened drift.
// Revisit probes 35-37: windows.h, memory.h, and stdlib.h context stayed in
// the same basin. Variant lab /Ob0 and /Ob1 also stayed identical. Direct
// PlayerStopTurn memset and direct parent popup expressions changed late
// scheduling or a call target; restored typed aliases. No exact result.
// Revisit probes 38-40: a split GUID declaration and a memcpy spelling were
// codegen-identical to aggregate assignment. The clean source remains the
// 865B typed reconstruction; the EH tail and shared-return shape stay open.
// Current claim probes 1-10: the binary-backed TScreenPanel and full
// TribeMPSetupScreen destructor surface was codegen-identical. Direct success
// labels, reordered labels, one common create-result assignment, a switch,
// and a register result were also identical. /Os, /Og-off, and /Ot-off changed
// the frame or call shape and were rejected. The restored clean source remains
// 865B, 0x10 frame, 32 ordered calls, and five duplicated cleanup returns.
// BINARY NOTE: the original has one shared cleanup tail at +0x301. The clean
// rebuild first diverges at +0x2A and has five returns. No tested natural
// source topology changed this EH-tail basin.

#include <string.h>

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawSystem;
class TDrawArea;
class TPanel;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long,
                                 TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, int);
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

    char gap_04[0x1C];
    TDrawArea* render_area;               // +0x20
    char gap_24[0x1C];
    TPanel* parent_panel;                 // +0x40
    char gap_44[0xB0];

    void set_curr_child(TPanel* child);
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];

    virtual ~TEasy_Panel();
    void popupOKDialog(long, char*, long, long);
};

class TDialogPanel : public TEasy_Panel {
public:
    char gap_478[0x18];
};

class TEditPanel : public TPanel {
public:
    int is_blank();
    char* currentLine();
};

class TribeMPCreateDialog : public TDialogPanel {
public:
    TPanel* title;                         // +0x490
    TPanel* input_title;                   // +0x494
    TEditPanel* inputGamename;             // +0x498
    TPanel* okButton;                      // +0x49C
    TPanel* cancelButton;                  // +0x4A0

    virtual long action(TPanel*, long, unsigned long, unsigned long);
};

class RGE_Base_Game {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual int get_string(int, char*, int);

    void disable_input();
    void draw_window();
};

class TRIBE_Game : public RGE_Base_Game {
public:
    void show_status_message(int, char*, long);
};

extern TRIBE_Game* rge_base_game;

class TRegistry {
public:
    int RegSetAscii(int, const char*, unsigned char*, unsigned long);
};

extern TRegistry* Regs;

struct _GUID {
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
};

class TCommunications_Handler {
public:
    char gap_000[0x12DC];
    _GUID ServiceGUID;                    // +0x12DC
    char gap_12EC[0xD0];
    unsigned long PlayerStopTurn[10];    // +0x13BC

    int SetGameTitle(char*);
    int CreateMultiplayerGame();
};

extern TCommunications_Handler* comm;

class TDebuggingLog {
public:
    void Log(char*, ...);
};
extern TDebuggingLog* L;

class TPanelSystem {
public:
    int setCurrentPanel(char*, int);
    int destroyPanel(char*);
};

extern TPanelSystem panel_system;

class TribeMPSetupScreen {
public:
    TribeMPSetupScreen();
    char gap[0x890];
};

class IDirectDraw {
public:
    virtual long __stdcall QueryInterface();
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual long __stdcall Compact();
    virtual long __stdcall CreateClipper(unsigned long, void**, void*);
    virtual long __stdcall CreatePalette(unsigned long, void*, void**, void*);
    virtual long __stdcall CreateSurface();
    virtual long __stdcall DuplicateSurface();
    virtual long __stdcall EnumDisplayModes();
    virtual long __stdcall EnumSurfaces();
    virtual long __stdcall FlipToGDISurface();
};

class TDrawSystem {
public:
    IDirectDraw* gap_00;
    char gap_04[0x14];
    IDirectDraw* DirDraw;                 // +0x18
    char gap_1C[0x45C];
    unsigned char DrawType;               // +0x478
    unsigned char ScreenMode;             // +0x479
};

class TDrawArea {
public:
    TDrawSystem* DrawSystem;
};

extern "C" const _GUID DPSPGUID_TCPIP;
extern "C" int (__stdcall* const WinExec)(char*, int);
extern "C" void* (__stdcall* const FindWindowA)(char*, char*);
extern "C" int (__stdcall* const SendMessageA)(void*, int, int, int);

long TribeMPCreateDialog::action(TPanel* panel, long command,
                                 unsigned long param3, unsigned long param4)
{
    long result;

    if (panel != 0) {
        if ((panel == this->okButton && command == 1) ||
            (panel == this->inputGamename && command == 0)) {
            if (this->inputGamename->is_blank()) {
                this->set_curr_child(this->inputGamename);
                result = 1;
                goto done;
            }

            rge_base_game->disable_input();
            Regs->RegSetAscii(1, "Default Age Of Empires MP Gamename",
                              (unsigned char*)this->inputGamename->currentLine(),
                              strlen(this->inputGamename->currentLine()) + 1);
            comm->SetGameTitle(this->inputGamename->currentLine());

            TDrawArea* draw_area = this->render_area;
            L->Log("$$$ CALLING CreateMultiplayerGame");
            panel_system.setCurrentPanel("Join Screen", 0);
            rge_base_game->draw_window();

            _GUID service_guid = comm->ServiceGUID;
            if (memcmp(&service_guid, &DPSPGUID_TCPIP, sizeof(_GUID)) == 0)
                rge_base_game->show_status_message(0x4C3, "scr3", 0xC385);
            else
                rge_base_game->show_status_message(0x4C2, "scr3", 0xC385);
            rge_base_game->draw_window();
            WinExec("data\\closedpw.exe", 0);

            if (draw_area->DrawSystem->DrawType == 2 &&
                draw_area->DrawSystem->ScreenMode == 2)
                draw_area->DrawSystem->DirDraw->FlipToGDISurface();

            TCommunications_Handler* communications = comm;
            memset(&communications->PlayerStopTurn[1], 0,
                   9 * sizeof(communications->PlayerStopTurn[0]));
            int create_result = comm->CreateMultiplayerGame();
            L->Log("$$$ RETURNED FROM CreateMultiplayerGame");

            void* window = FindWindowA("closedpw", "closedpw");
            if (window != 0)
                SendMessageA(window, 0x10, 0, 0);

            if (create_result != 0) {
                new TribeMPSetupScreen;
                panel_system.setCurrentPanel("MP Setup Screen", 0);
                panel_system.destroyPanel("Status Screen");
                panel_system.destroyPanel("Create Dialog");
                panel_system.destroyPanel("Join Screen");
                result = 1;
                goto done;
            }

            TEasy_Panel* parent = (TEasy_Panel*)this->parent_panel;
            panel_system.destroyPanel("Create Dialog");
            panel_system.setCurrentPanel("Join Screen", 0);
            panel_system.destroyPanel("Status Screen");
            parent->popupOKDialog(0x25AD, 0, 0x1C2, 100);
            result = 1;
            goto done;
        }

        if ((panel == this->cancelButton && command == 1) ||
            (panel == this->inputGamename && command == 1)) {
            panel_system.setCurrentPanel("Join Screen", 0);
            panel_system.destroyPanel("Create Dialog");
            result = 1;
            goto done;
        }
    }

    result = TPanel::action(panel, command, param3, param4);

done:
    return result;
}
