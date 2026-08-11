// 00491650 TribeJoinScreen::TribeJoinScreen
//
// Binary-backed ownership: TScreenPanel ends at +0x478; the named screen
// fields occupy +0x478..+0x4AC, and TButtonPanel hotkeys are +0x298/+0x29C.
// The constructor's direct factory calls are the period TEasy_Panel wrappers;
// the list and close button use their inherited virtual panel surfaces.
//
// Attempt log:
// - prior scaffold used the wrong TEasy_Panel base constructor and helper
//   surfaces (resource/input/edit/default-button), producing the wrong call set.
// - baseline reset: restore the TScreenPanel hierarchy, Pnl_scr setup overload,
//   SetPlayerHumanity, create_text/list/scrollbar/button wrappers, and the
//   binary-backed positive nested factory topology. Current source is the clean
//   period-plausible reconstruction being tested.
// - liveness: keep a local cancel-button pointer across the two hotkey stores;
//   this preserves VC5's interleaving of the close-button argument pushes.
//   Result: exact 797-byte match.
// FLAGS: config/flags/00491650_TribeJoinScreen.rsp (/GX), required for the
// original constructor EH registration frame.

struct tagRECT;
class TDrawArea;
class TTextPanel;
class TListPanel;
class TScrollBarPanel;
class TButtonPanel;
class TCommunications_Sessions;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup();
    virtual void set_rect(tagRECT rect);
    virtual void set_rect(long left, long top, long right, long bottom);
    virtual void set_color(unsigned char color);
    virtual void set_active(int active);
    virtual void set_positioning(long mode, long a2, long a3, long a4,
                                 long a5, long a6, long a7, long a8,
                                 long a9, TPanel* a10, TPanel* a11,
                                 TPanel* a12, TPanel* a13);

    char gap_04[0xD4];
    int setup_error;                         // +0xD8
    char gap_DC[0x18];                       // sizeof(TPanel) == 0xF4

    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void set_string_id(long id);     // vslot +0xE4

    void set_curr_child(TPanel* child);
    void set_tab_order(TPanel** panels, short count);
};

class TTextPanel : public TPanel {
};

class TListPanel : public TTextPanel {
};

class TScrollBarPanel : public TPanel {
};

class TButtonPanel : public TPanel {
public:
    char gap_F4[0x1A4];
    long hotkey;                             // +0x298
    long hotkey_shift;                       // +0x29C
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];                      // sizeof(TEasy_Panel) == 0x478

    void setup_shadow_area(int force_rebuild);
    void set_ideal_size(long width, long height);
    int create_text(TPanel* parent, TTextPanel** output, long string_id,
                    long x, long y, long width, long height,
                    long font, long align, long center, long wrap);
    int create_list(TPanel* parent, TListPanel** output,
                    long x, long y, long width, long height, long lines);
    int create_auto_scrollbar(TScrollBarPanel** output,
                              TTextPanel* text, long width);
    int create_button(TPanel* parent, TButtonPanel** output, long string_id,
                      long text2, long x, long y, long width, long height,
                      long p9, long p10, long p11);
};

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(char* name);
    virtual ~TScreenPanel();
    long setup(TDrawArea* draw_area, char* info_file, long info_id,
               int param);
};

class TCommunications_Handler {
public:
    void SetPlayerHumanity(unsigned int player, int humanity);
};

class RGE_Base_Game {
public:
    char gap_00[0x4C];
    TDrawArea* draw_area;
};

#define comm (*(TCommunications_Handler**)0x0062C4C0)
#define rge_base_game (*(RGE_Base_Game**)0x0062C574)
#define Sess (*(TCommunications_Sessions**)0x0086B288)

class TribeJoinScreen : public TScreenPanel {
public:
    int startedSession;                      // +0x478
    int listFilled;                          // +0x47C
    TTextPanel* title;                       // +0x480
    TTextPanel* listTitle;                   // +0x484
    TListPanel* list;                        // +0x488
    TScrollBarPanel* scrollbar;              // +0x48C
    TButtonPanel* joinButton;                // +0x490
    TButtonPanel* createButton;              // +0x494
    TButtonPanel* cancelButton;              // +0x498
    TButtonPanel* refreshButton;             // +0x49C
    TButtonPanel* close_button;              // +0x4A0
    int game_count;                          // +0x4A4
    int waitingToStart;                      // +0x4A8
    unsigned long joinTime;                  // +0x4AC

    virtual ~TribeJoinScreen();
    TribeJoinScreen();
};

TribeJoinScreen::TribeJoinScreen()
    : TScreenPanel((char*)0x0058617C)
{
    this->startedSession = 0;
    this->listFilled = 0;
    Sess = 0;
    this->game_count = 0;
    this->waitingToStart = 0;
    this->joinTime = 0;
    this->close_button = 0;

    comm->SetPlayerHumanity(1, 2);
    for (int player = 2; player <= 9; ++player) {
        comm->SetPlayerHumanity(player, 0);
    }

    if (this->setup(rge_base_game->draw_area, (char*)0x00586174,
                    0xC385, 1) == 0) {
        this->setup_error = 1;
        return;
    }

    this->setup_shadow_area(0);
    this->set_ideal_size(0x280, 0x1E0);

    if (this->create_text(this, &this->title, 0x259F,
                          0x14, 0x14, 0x258, 0x1E, 1, 1, 0, 0)) {
        this->create_text(this, &this->listTitle, 0x25A8,
                          0x14, 0x41, 0x258, 0x14, 4, 0, 0, 0);
        if (this->create_list(this, &this->list,
                              0x14, 0x5A, 0x258, 0x10E, 0x0B)) {
            if (this->create_auto_scrollbar(&this->scrollbar,
                                            this->list, 0x14)) {
                this->listFilled = 1;
                this->list->set_string_id(0x25AB);
                if (this->create_button(this, &this->refreshButton,
                                        0x25A1, 0, 0xD2, 0x172,
                                        0xDC, 0x1E, 0, 0, 0)) {
                    if (this->create_button(this, &this->joinButton,
                                            0x25A0, 0, 0x0A, 0x1B8,
                                            0xC8, 0x1E, 0, 0, 0)) {
                        if (this->create_button(this, &this->createButton,
                                                0x25A2, 0, 0xDC, 0x1B8,
                                                0xC8, 0x1E, 0, 0, 0)) {
                            if (this->create_button(this, &this->cancelButton,
                                                    0x0FA2, 0, 0x1AE,
                                                    0x1B8, 0xC8, 0x1E,
                                                    0, 0, 0)) {
                                TButtonPanel* cancel = this->cancelButton;
                                cancel->hotkey = 0x1B;
                                cancel->hotkey_shift = 0;

                                if (this->create_button(this,
                                                        &this->close_button,
                                                        0x03EA, 0, 0, 0, 0,
                                                        0, -1, -1, 0)) {
                                    this->close_button->set_active(1);
                                    this->close_button->set_positioning(
                                        9, 4, 4, 4, 4, 0x11, 0x11,
                                        0x11, 0x11, 0, 0, 0, 0);
                                    this->set_curr_child(this->refreshButton);

                                    TPanel* tabList[5];
                                    tabList[0] = this->list;
                                    tabList[1] = this->refreshButton;
                                    tabList[2] = this->joinButton;
                                    tabList[3] = this->createButton;
                                    tabList[4] = this->cancelButton;
                                    this->set_tab_order(tabList, 5);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
