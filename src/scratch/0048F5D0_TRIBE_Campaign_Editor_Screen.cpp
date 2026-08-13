// 0048F5D0 TRIBE_Campaign_Editor_Screen::TRIBE_Campaign_Editor_Screen
// PDB: scr_cam.cpp:59-144
// Attempt log:
// - typed baseline: restored the TPanel -> TEasy_Panel -> TScreenPanel
//   hierarchy, named panel ownership, same-TU factory signatures, and the
//   observed constructor call order.
// - lifetime correction: kept the typed cancel button in a local across its
//   hotkey stores, as in the matching same-TU constructor donor.
// - explicit alias assignments for the three carried output fields produced
//   identical code; retained the natural named source and stopped the probe.
// - reordered alias declarations and assignments; one form reduced the
//   positional diff to 733 bytes, but later context probes were duplicates.
// - restored the clean typed source; remaining drift starts after base ctor
//   vptr setup and keeps the exact call set, frame, and code size.
// FLAGS: config/flags/0048F5D0_TRIBE_Campaign_Editor_Screen.rsp (/GX)

struct tagRECT;
class TDrawArea;
class TTextPanel;
class TListPanel;
class TScrollBarPanel;
class TButtonPanel;
class TEditPanel;
class TDropDownPanel;

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
    void set_curr_child(TPanel* child);
    void set_tab_order(TPanel** panels, short count);
};

class TTextPanel : public TPanel {
public:
    void empty_list();
};

class TListPanel : public TTextPanel {
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
};

class TDropDownPanel : public TPanel {
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[4];
    long ideal_width;
    long ideal_height;
    char gap_100[0x378];

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
};

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(char* name);
    virtual ~TScreenPanel();
    long setup(TDrawArea* draw_area_value, char* info_file,
               long info_id, int param);
};

class RGE_Campaign;

class RGE_Base_Game {
public:
    char gap_00[0x4C];
    TDrawArea* draw_area;
};

extern RGE_Base_Game* rge_base_game;

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

    virtual ~TRIBE_Campaign_Editor_Screen();
    TRIBE_Campaign_Editor_Screen();
    void fill_scenario_list();
    void fill_campaign_drop();
    void load_campaign();
};

TRIBE_Campaign_Editor_Screen::TRIBE_Campaign_Editor_Screen()
    : TScreenPanel((char*)"Campaign Editor Screen")
{
    TListPanel** scenarios;
    TListPanel** campaign_scenarios;
    TDropDownPanel** filename_drop;

    scenarios = &this->scenarios;
    campaign_scenarios = &this->campaign_scenarios;
    filename_drop = &this->filename_drop;

    this->title = 0;
    this->scenarios_title = 0;
    *scenarios = 0;
    this->scenarios_bar = 0;
    this->campaign_scenarios_title = 0;
    *campaign_scenarios = 0;
    this->campaign_scenarios_bar = 0;
    this->filename_title = 0;
    this->filename = 0;
    this->cancel_button = 0;
    this->save_button = 0;
    this->ok_button = 0;
    this->campaign = 0;
    *filename_drop = 0;
    this->add_button = 0;
    this->remove_button = 0;
    this->move_scenario_up_button = 0;
    this->move_scenario_down_button = 0;

    if (!this->setup(rge_base_game->draw_area, (char*)"scr4", 0xC386, 1)) {
        this->setup_error = 1;
        return;
    }

    this->setup_shadow_area(0);
    this->set_ideal_size(0x280, 0x1E0);

    this->create_text(this, &this->title, 0x2BC1,
                      10, 10, 0x26C, 0x32, 1, 3, 0, 0);
    this->create_text(this, &this->filename_title, 0x2BC2,
                      0x14, 0x28, 0x104, 0x14, 4, 0, 0, 0);
    this->create_drop_down(this, filename_drop,
                           0x17C, 0xC8, 0x14, 0x3C, 0x17C,
                           (this->ideal_width * 30) / this->height, 0xB);

    char* default_campaign = this->get_string(0x2BCA);
    this->create_edit(this, &this->filename, default_campaign,
                      100, 5, 0, 0, 0x168, 0x1E, 0xB, 1, 1);

    this->create_button(this, &this->save_button, 0x2BC4,
                        0, 0x1A4, 0x3C, 0xC8, 0x1E, 0, 0, 0);
    this->create_button(this, &this->add_button, 0x2BC5,
                        0, 0x118, 0x104, 0xA0, 0x1E, 0, 0, 0);
    this->create_button(this, &this->remove_button, 0x2BC6,
                        0, 0x1CC, 0x104, 0xA0, 0x1E, 0, 0, 0);
    this->create_text(this, &this->scenarios_title, 0x2BC7,
                      0x14, 0x64, 0xC8, 0x14, 4, 0, 0, 0);
    this->create_list(this, scenarios, 0x14, 0x78, 0x258, 0x82, 0xB);
    this->create_auto_scrollbar(&this->scenarios_bar, *scenarios, 0x14);
    this->create_text(this, &this->campaign_scenarios_title, 0x2BC8,
                      0x14, 0x118, 0xC8, 0x14, 4, 0, 0, 0);
    this->create_list(this, campaign_scenarios,
                      0x14, 0x12C, 0x1F4, 0x82, 0xB);
    this->create_auto_scrollbar(&this->campaign_scenarios_bar,
                                *campaign_scenarios, 0x14);

    this->create_button(this, &this->ok_button, 0xFA1,
                        0, 0x14, 0x1BD, 0x118, 0x1E, 0, 0, 0);
    this->create_button(this, &this->cancel_button, 0xFA2,
                        0, 0x154, 0x1BD, 0x118, 0x1E, 0, 0, 0);
    TButtonPanel* cancel = this->cancel_button;
    cancel->hotkey = 0x1B;
    cancel->hotkey_shift = 0;

    this->create_button(this, &this->move_scenario_up_button, 0x2BD5,
                        0, 0x212, 0x12C, 0x5A, 0x1E, 0, 0, 0);
    this->create_button(this, &this->move_scenario_down_button, 0x2BD6,
                        0, 0x212, 0x154, 0x5A, 0x1E, 0, 0, 0);

    TPanel* tab_list[8];
    tab_list[0] = *filename_drop;
    tab_list[1] = this->save_button;
    tab_list[2] = *scenarios;
    tab_list[3] = this->add_button;
    tab_list[4] = this->remove_button;
    tab_list[5] = *campaign_scenarios;
    tab_list[6] = this->ok_button;
    tab_list[7] = this->cancel_button;
    this->set_tab_order(tab_list, 8);

    (*filename_drop)->set_curr_child(this->filename);
    this->set_curr_child(*filename_drop);
    this->fill_scenario_list();
    this->fill_campaign_drop();
    (*campaign_scenarios)->empty_list();
    this->load_campaign();
    this->need_to_save = 0;
}
