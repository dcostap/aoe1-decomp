#ifndef SCR_LOAD_CONTEXT_H
#define SCR_LOAD_CONTEXT_H

class TDrawArea;
class TPanel;
class TTextPanel;
class TListPanel;
class TScrollBarPanel;
class TButtonPanel;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup();
    virtual void set_rect();
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(long, long, long, long, long, long, long,
                                 long, long, TPanel*, TPanel*, TPanel*, TPanel*);
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
    virtual long handle_idle();
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

    char gap_04[0xD4];
    int setup_error;
    char gap_DC[0x18];

    char* panelName();
    int get_string(int string_id, char* buffer, int length);
    void set_help_info(long help_id, long page_id);
    void set_curr_child(TPanel* child);
    void set_tab_order(TPanel** panels, short count);
    void delete_panel(TPanel** panel);
};

class TTextPanel : public TPanel {
public:
    char gap_F4[0x68];
    int sorted;

    int numberLines() const;
    char* currentLine();
    long get_line();
    long get_line(char* text);
    int delete_line(long line);
    void empty_list();
    int append_line(char* text, int data);
};

class TListPanel : public TTextPanel {
public:
    void scroll_cur_line(unsigned char mode, short line, int update_scrollbar);
};

class TScrollBarPanel : public TPanel {
};

class TButtonPanel : public TPanel {
public:
    char gap_F4[0x1A4];
    long hotkey;
    long hotkey_shift;

    void set_disabled(int disabled);
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];

    virtual long action(TPanel*, long, unsigned long, unsigned long);
    char* get_info_file();
    long get_info_id();
    void setup_shadow_area(int force_rebuild);
    void set_ideal_size(long width, long height);
    int create_text(TPanel* parent, TTextPanel** out, long string_id,
                    long x, long y, long width, long height,
                    long p8, long p9, long p10, long p11);
    int create_list(TPanel* parent, TListPanel** out,
                    long x, long font, long width, long height, long lines);
    int create_auto_scrollbar(TScrollBarPanel** out, TTextPanel* text,
                              long width);
    int create_button(TPanel* parent, TButtonPanel** out, long string_id,
                      long p4, long x, long y, long width, long height,
                      long p9, long p10, long p11);
    void popupYesNoDialog(char* message, char* title, int style, int timeout);
    void popupOKDialog(long string_id, char* title, int style, int timeout);
};

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(char* name);
    virtual ~TScreenPanel();
    long setup(TDrawArea* draw_area, char* info_file, long info_id, int param);
};

class TPanelSystem {
public:
    TEasy_Panel* currentPanel();
    TPanel* panel(char* name);
    int setCurrentPanel(char* name, int mode);
    int destroyPanel(char* name);
};

extern TPanelSystem panel_system;

class RGE_Prog_Info {
public:
    char gap_00[0xB12];
    char save_dir[261];
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_04[8];
    RGE_Prog_Info* prog_info;
    char gap_10[0x3C];
    TDrawArea* draw_area;
    char gap_50[0x188];
    int input_enabled;
    char gap_1DC[0x824];
    int save_paused;

    char* get_save_game_name();
    int singlePlayerGame() const;
    void set_paused(int paused, int non_user_pause);
    void disable_input();
    void enable_input();
};

class TRIBE_Game : public RGE_Base_Game {
public:
    char* get_save_game_name();
    int load_game(char* file_name);
};

extern RGE_Base_Game* rge_base_game;

class TribeSPMenuScreen {
public:
    char data[0x49C];
    TribeSPMenuScreen();
};

class TribeLoadSavedGameScreen : public TScreenPanel {
public:
    TTextPanel* screenTitle;
    TTextPanel* listTitle;
    TListPanel* list;
    TScrollBarPanel* scrollbar;
    TButtonPanel* okButton;
    TButtonPanel* cancelButton;
    TButtonPanel* deleteButton;

    TribeLoadSavedGameScreen();
    virtual ~TribeLoadSavedGameScreen();
    virtual long handle_idle();
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    void fillList();
};

#endif
