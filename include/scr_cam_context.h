#ifndef SCR_CAM_CONTEXT_H
#define SCR_CAM_CONTEXT_H

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
    virtual long setup();
    virtual void set_rect(tagRECT rect);
    virtual void set_rect(long left, long top, long right, long bottom);
    virtual void set_color(unsigned char color);
    virtual void set_active(int active);
    virtual void set_positioning(long mode, long a2, long a3, long a4,
                                 long a5, long a6, long a7, long a8,
                                 long a9, TPanel* a10, TPanel* a11,
                                 TPanel* a12, TPanel* a13);

    char gap_04[0x10];
    long width;
    long height;
    char gap_1C[4];
    TDrawArea* draw_area;
    char gap_24[0xB4];
    int setup_error;
    char gap_DC[0x18];

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
    virtual void set_string_id(long id);

    char* get_string(int string_id);
    char* panelName();
    void set_curr_child(TPanel* child);
    void set_tab_order(TPanel** panels, short count);
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
    long action(TPanel* panel, long code, unsigned long p3,
                unsigned long p4);
};

#endif
