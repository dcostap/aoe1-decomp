// 0049DD40 TribeLoadSavedGameScreen::TribeLoadSavedGameScreen
// scratch give-up: natural reconstruction from packet/decompiler.
// Tried /O2 /GX first: optimized body was only 768B, below original 822B, despite correct broad call set.
// Tried /O2 with extra visible virtual/destructor surfaces and direct member offsets; still too short/wrong.
// Tried /Od /GX as diagnostic only: checkable exact-size 822B but broad mismatch (82.36% positional /
// 104.26% edit), first mismatch at prologue (original optimized EH frame vs /Od EBP frame). Kept /Od
// response file only so check_function has comparable bytes; not a promotion candidate and not drift-safe.

class TPanel { public: void set_help_info(long,int); void set_curr_child(TPanel*); void set_tab_order(TPanel**, int); };
class TTextPanel: public TPanel { public: char* currentLine(); long get_line(char*); void scroll_cur_line(unsigned char, short, int); };
class TButtonPanel: public TPanel { public: char gap[0x298]; int hotkey; int hotkey_shift; void set_disabled(int); };
class TEasy_Panel: public TPanel { public: char* get_info_file(); long get_info_id(); void setup_shadow_area(int); void set_ideal_size(long,long); int create_text(TPanel*, TPanel**, long,int,int,int,int,int,int,int,int); int create_button(TPanel*, TPanel**, long,int,int,int,int,int,int,int,int); int create_list(TPanel*, TPanel**, int,int,int,int,int); int create_auto_scrollbar(TPanel**, TTextPanel*, int); };
class TScreenPanel: public TEasy_Panel { public: TScreenPanel(char*); long setup(void*, char*, long, int); };
class TPanelSystem { public: TPanel* currentPanel(); };
class TRIBE_Game { public: char gap[0x4c]; void* draw_area; char* get_save_game_name(); };
extern TPanelSystem panel_system;
extern TRIBE_Game* rge_base_game;

class TribeLoadSavedGameScreen: public TScreenPanel {
public:
    char gap[0x478 - sizeof(TScreenPanel)];
    TPanel* screenTitle;
    TPanel* listTitle;
    TTextPanel* list;
    TPanel* scrollbar;
    TButtonPanel* okButton;
    TButtonPanel* cancelButton;
    TButtonPanel* deleteButton;
    TribeLoadSavedGameScreen();
    void fillList();
};

TribeLoadSavedGameScreen::TribeLoadSavedGameScreen() : TScreenPanel("Load Saved Game Screen")
{
    TPanel* tabList[4];
    char info_file[260];
    TPanel* from_panel;

    this->screenTitle = 0;
    this->listTitle = 0;
    this->list = 0;
    this->scrollbar = 0;
    this->okButton = 0;
    this->cancelButton = 0;
    this->deleteButton = 0;

    from_panel = panel_system.currentPanel();
    tabList[0] = from_panel;
    char* src = ((TEasy_Panel*)from_panel)->get_info_file();
    char* dst = info_file + 4;
    while ((*dst++ = *src++) != 0) {}

    if (!this->setup(rge_base_game->draw_area, info_file + 4, ((TEasy_Panel*)from_panel)->get_info_id(), 1)) {
        *(int*)((char*)this + 0xD8) = 1;
        return;
    }
    this->setup_shadow_area(0);
    this->set_ideal_size(0x280,0x1e0);
    if (!this->create_text(this, &this->screenTitle, 0x24ff, 0x14, 0x0a, 0x258, 0x1e, 1, 1, 0, 0)) return;
    if (!this->create_text(this, &this->listTitle, 0x2502, 0x14, 0x2d, 0x258, 0x14, 4, 0, 0, 0)) return;
    if (!this->create_list(this, (TPanel**)&this->list, 0x14, 0x41, 0x258, 0x160, 0x0b)) return;
    if (!this->create_auto_scrollbar(&this->scrollbar, this->list, 0x14)) return;
    this->scrollbar->set_help_info(0x7670, -1);
    if (!this->create_button(this, (TPanel**)&this->okButton, 0x0fa1, 0, 0x1e, 0x1b8, 0xb4, 0x1e, 0, 0, 0)) return;
    if (!this->create_button(this, (TPanel**)&this->deleteButton, 0x24c9, 0, 0xe6, 0x1b8, 0xb4, 0x1e, 0, 0, 0)) return;
    if (!this->create_button(this, (TPanel**)&this->cancelButton, 0x0fa2, 0, 0x1ae, 0x1b8, 0xb4, 0x1e, 0, 0, 0)) return;
    this->okButton->set_help_info(0x7531, -1);
    this->cancelButton->set_help_info(0x7532, -1);
    this->cancelButton->hotkey = 0x1b;
    this->cancelButton->hotkey_shift = 0;
    this->deleteButton->hotkey_shift = 0;
    this->deleteButton->hotkey = 0x2e;
    this->fillList();
    if (this->list->currentLine()[0] == 0) {
        this->okButton->set_disabled(1);
        this->deleteButton->set_disabled(1);
    }
    long line = this->list->get_line(rge_base_game->get_save_game_name());
    if (line != -1) this->list->scroll_cur_line(1, (short)line, 1);
    this->set_curr_child(this->list);
    tabList[1] = this->list;
    tabList[2] = this->okButton;
    tabList[3] = this->deleteButton;
    this->set_tab_order(tabList + 1, 4);
}
