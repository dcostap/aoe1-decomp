#ifndef AOE1_SCR_CAM_H
#define AOE1_SCR_CAM_H

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea;
class TTextPanel;
class TListPanel;
class TScrollBarPanel;
class TButtonPanel;
class TEditPanel;
class TDropDownPanel;
class RGE_Campaign;

extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);
extern "C" char* __cdecl strncpy(char* dst, const char* src,
                                  unsigned int count);
extern "C" unsigned int __cdecl strlen(const char* text);
extern "C" long __cdecl _findfirst(const char* filespec, void* fileinfo);
extern "C" int __cdecl _findnext(long handle, void* fileinfo);
extern "C" void __cdecl free(void* pointer);
extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);
extern "C" void __cdecl addstring(char** dst, char* first, char* second);
extern "C" void __cdecl getstring(char** dst, char* source);

struct FindDataLocal {
    char gap_00[0x10];
    char name[260];
    char pad_114[4];
};

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long,
                       unsigned char);
    virtual void set_rect(tagRECT rect);
    virtual void set_rect(long left, long top, long right, long bottom);
    virtual void set_color(unsigned char color);
    virtual void set_active(int active);
    virtual void set_positioning(long mode, long a2, long a3, long a4,
                                 long a5, long a6, long a7, long a8,
                                 long a9, TPanel* a10, TPanel* a11,
                                 TPanel* a12, TPanel* a13);
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
    virtual void get_true_render_rect(tagRECT*);
    virtual int is_inside(long, long);
    virtual void set_focus(int);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual void set_tab_order(TPanel**, short);
    virtual unsigned char get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();

    char gap_04[0x10];
    long width;
    long height;
    char gap_1C[4];
    TDrawArea* draw_area;
    char gap_24[0xB4];
    int setup_error;
    char gap_DC[0x18];

    virtual void set_string(long);
    virtual void set_string(char*);

    char* get_string(int string_id);
    char* panelName();
    void set_curr_child(TPanel* child);
};

class TTextPanel : public TPanel {
public:
    char gap_0F4[0x68];
    long sorted;

    void empty_list();
    int append_line(char* text, int data);
    int append_line(const char* text, int data);
    int numberLines();
    char* get_text();
    char* get_text(int index);
    long get_line(char* text);
    long get_line(const char* text);
    long get_line();
    void set_line(long line);
    int delete_line(long line);
    void insert_line(long line, char* text, long value);
};

class TListPanel : public TTextPanel {
public:
    void scroll_cur_line(unsigned char direction, int line, int flag);
    void scroll_cur_line(unsigned char direction, short line, int flag);
    void scroll_cur_line(int direction, short line, int flag);
};

class TScrollBarPanel : public TPanel {
};

class TButtonPanel : public TPanel {
public:
    char gap_F4[0x1A4];
    long hotkey;
    long hotkey_shift;
};

class TEditPanel : public TPanel {
public:
    char* get_text();
    void set_text(char* text);
};

class TDropDownPanel : public TPanel {
public:
    void set_sorted(int sorted_value);
    void empty_list();
    int append_line(char* text, int data);
    char* get_text();
};

class TEasy_Panel : public TPanel {
public:
    using TPanel::get_string;

    char gap_F4[4];
    long ideal_width;
    long ideal_height;
    char gap_100[0x378];

    virtual ~TEasy_Panel();
    virtual long action(TPanel* panel, long code, unsigned long p3,
                        unsigned long p4);

    void setup_shadow_area(int force_rebuild);
    void set_ideal_size(long width_value, long height_value);
    int create_text(TPanel* parent, TTextPanel** output, long string_id,
                    long x, long y, long width_value, long height_value,
                    long font, long align, long center, long wrap);
    int create_drop_down(TPanel* parent, TDropDownPanel** output,
                         long x, long y, long width_value, long height_value,
                         long font, long line_height, long style);
    int create_edit(TPanel* parent, TEditPanel** output, char* text,
                    short width_value, long format, long x, long y,
                    long width_arg, long height_arg, long font,
                    long param_11, long param_12);
    int create_button(TPanel* parent, TButtonPanel** output, long string_id,
                      long text2, long x, long y, long width_value,
                      long height_value, long param_9, long param_10,
                      long param_11);
    int create_list(TPanel* parent, TListPanel** output,
                    long x, long y, long width_value, long height_value,
                    long lines);
    int create_auto_scrollbar(TScrollBarPanel** output,
                              TTextPanel* text, long width_value);
    void popupOKDialog(long text_id, char* panel_name, int width, int height);
    int get_string(int string_id, char* buffer, int buffer_size);
    void popupYesNoCancelDialog(char* text, char* panel_name,
                                int width, int height);
    void set_curr_child(TPanel* child);
};

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(char* name);
    virtual ~TScreenPanel();
    long setup(TDrawArea* draw_area_value, char* info_file,
               long info_id, int param);
};

class RGE_Prog_Info {
public:
    char gap_000[0xC17];
    char scenario_dir[0x105];
    char campaign_dir[1];
};

class RGE_Base_Game {
public:
    char gap_000[0x0C];
    RGE_Prog_Info* prog_info;
    char gap_010[0x3C];
    TDrawArea* draw_area;

    void find_campaigns();
};

extern RGE_Base_Game* rge_base_game;

class RGE_Campaign {
public:
    char gap_000[0x20C];
    RGE_Campaign(char* path);
    RGE_Campaign(char* path, char* name, int count,
                 char** campaign_filenames, char** scenario_text);
    ~RGE_Campaign();
    long scenario_info(char*** list);
};

class TPanelSystem {
public:
    int destroyPanel(char* name);
    int setCurrentPanel(char* name, int modal);
};

extern TPanelSystem panel_system;

class TRIBE_Screen_Sed_Menu {
public:
    char gap_000[0x490];
    TRIBE_Screen_Sed_Menu();
};

class TRIBE_Campaign_Editor_Screen : public TScreenPanel {
public:
    unsigned char need_to_save;
    char gap_479[3];
    TTextPanel* title;
    TTextPanel* filename_title;
    TTextPanel* scenarios_title;
    TTextPanel* campaign_scenarios_title;
    TListPanel* scenarios;
    TListPanel* campaign_scenarios;
    TScrollBarPanel* scenarios_bar;
    TScrollBarPanel* campaign_scenarios_bar;
    TEditPanel* filename;
    TButtonPanel* ok_button;
    TButtonPanel* cancel_button;
    TButtonPanel* save_button;
    TButtonPanel* add_button;
    TButtonPanel* remove_button;
    TButtonPanel* move_scenario_up_button;
    TButtonPanel* move_scenario_down_button;
    TDropDownPanel* filename_drop;
    RGE_Campaign* campaign;

    TRIBE_Campaign_Editor_Screen();
    virtual ~TRIBE_Campaign_Editor_Screen();

protected:
    void fill_campaign_drop();
    void fill_scenario_list();
    void fill_campaign_scenario_list();
    unsigned char check_lists();
    void load_campaign();
    void make_campaign();
    void add_scenario();
    void remove_scenario();
    void move_scenario_up();
    void move_scenario_down();
    virtual long action(TPanel* panel, long code, unsigned long p3,
                        unsigned long p4);
};

#endif
