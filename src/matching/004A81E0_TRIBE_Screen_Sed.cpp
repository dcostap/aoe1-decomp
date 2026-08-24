// 004A81E0 TRIBE_Screen_Sed::TRIBE_Screen_Sed
// Attempt log:
// 1: broad reconstruction from packet: base screen ctor, member initialization, debug timers, graphics/view/panel allocations, scenario-file handling, setup calls and failure path.
// 2: fixed local stub declarations for panel/view/scenario helper calls and compiled with /GX; optimized /O2 body is only 1152 bytes vs original 1381, so reconstruction is too high-level/under-specified.
// 3: /Od /GX probe reaches exact 1381-byte size but is wrong debug-frame basin (EBP frame prologue, 85.2281% positional / 123.7509% edit) and was rolled back to /O2 /GX.
// 4: current behavior surface includes original major effects: TScreenPanel base ctor, vtable/member initialization, init_module_variables, debug_timeGetTime probes, global world age/state call, setup and failure d8 path, name compare for autosave-ish flag, UI panel allocations, scenario name handling, setup page calls, final scenario mode and game panel calls.
// 5: remaining gap is broad constructor/source-context mismatch: original is hand-scheduled VC5 /O2 EH constructor with 0x210 frame, two 260-byte stack buffers, precise allocation temp/EH states, inline string compare/copy loops and many concrete typed calls; current source collapses much of that through high-level/fake helper surfaces, leaving /O2 far under-size. Not accepted_drift-safe.
// 6: replaced unsupported panel/view/world facades with the proven
// TScreenPanel, TRIBE_Main_View, RGE_Diamond_Map_View, TMessagePanel, TPanel,
// RGE_Base_Game, and RGE_Game_World ownership surfaces.  The baseline restored
// the original 0x210 EH frame, 0x380/0x16C/0x380/0xF4 allocation sizes, and
// all 49 ordered calls.
// 7: corrected the RGE_Base_Game and RGE_Diamond_Map field offsets from binary
// evidence.  This restored the draw area, registry, map-save area, and view
// links without adding raw offset plumbing.
// 8: changed the scenario player scan to a natural bounded for loop.  This
// removed the compiler-generated duplicate call site and restored 1381 bytes,
// 49 calls, and the original call order.  Remaining drift is localized around
// EH/vtable relocation bytes and the branch before the default-player path.
// 9: placed typed set_line calls in the two source branches, matching the
// packet's branch-local line 403 and compiler tail merge; diff improved to 176
// bytes with 86.26% exact-block coverage, so this natural form is retained.
// 10: reordered the two cross-link stores; the register schedule worsened the
// localized gap from 10 to 18 bytes, so the original order was restored.
// 11: typed RGE_Diamond_Map::main_view as RGE_Main_View*; no emitted change.
// 12: carried both cross-link pointers as long-lived locals; this removed
// reloads and caused a broad size/call-basins mismatch, so it was rolled back.
// 13: retained the canonical RGE_View* type for RGE_Diamond_Map::main_view;
// the emitted code stayed unchanged.
// 14-15: base casts around the cross-link stores and help call had no effect.
// 16: scoped pointer aliases around each independent cross-link store reduced
// the gap to 6 bytes without changing size, calls, or control flow.
// 17: one shared short-lived pointer pair improved the first store but removed
// reloads and caused a broad size mismatch, so it was rolled back.
// 18: separate short-lived pointer pairs with reversed declaration order for
// each store reproduce the original ecx/eax schedule; exact match validated.

#ifndef SCR_SED_TU_CONTEXT
extern "C" int __cdecl sprintf(char*, const char*, ...);
extern "C" int __cdecl strcmp(const char*, const char*);
extern "C" char* __cdecl strstr(const char*, const char*);
extern "C" unsigned long debug_timeGetTime(char*, int);

class TDrawArea;
class TRegistry;
class RGE_Font;
class RGE_Game_World;
class RGE_Scenario;
class RGE_Map;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    char gap_04[0x1C];
    TDrawArea* render_area;
    char gap_24[0xB4];
    int setup_error;
    char gap_DC[0x18];
    TPanel();
    void set_help_info(long, long);
    void set_curr_child(TPanel*);
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];
    void setup_shadow_area(int);
};

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(char*);
    virtual ~TScreenPanel();
    long setup(TDrawArea*, char*, long, int);
};

class TRIBE_Main_View;
class RGE_Main_View;
class RGE_Diamond_Map_View;

class RGE_View : public TPanel {
public:
    char gap_F4[0x26C];
    long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char,
               int, char*);
};

class RGE_Main_View : public RGE_View {
public:
    RGE_Diamond_Map_View* map_view;
    unsigned long last_mouse_scroll_time;
    int mouse_scrolling;
    long mouse_last_x;
    long mouse_last_y;
    unsigned long last_key_scroll_time;
    int key_scrolling;
    void* save_player;
    RGE_Main_View();
    virtual ~RGE_Main_View();
};

class TRIBE_Main_View : public RGE_Main_View {
};

class RGE_Diamond_Map : public TPanel {
public:
    void* world;
    void* player;
    void* map;
    int all_visible;
    int render_all;
    long mouse_last_x;
    long mouse_last_y;
    int repos_mouse;
    char gap_114[0x10];
    void* last_player;
    void* map_image_lines;
    void* map_tile_rows;
    char gap_130[0x20];
    RGE_View* main_view;
    int scrolling;
    char gap_158[4];
    int draw_objects_mode;
    unsigned long cur_player_bit;
    int own_save_area;
    TDrawArea* save_area;
    virtual ~RGE_Diamond_Map();
    long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char,
               int, TDrawArea*);
    int set_bitmap(char*, long);
};

class RGE_Diamond_Map_View : public RGE_Diamond_Map {
public:
    RGE_Diamond_Map_View();
    virtual ~RGE_Diamond_Map_View();
};

class RGE_Font {
public:
    void* font;
    long font_wid;
    long font_hgt;
};

class TMessagePanel : public TPanel {
public:
    char gap_F4[0x28C];
    TMessagePanel(void*, long, long);
};

class TDropDownPanel : public TPanel {
public:
    void set_line(long);
};

class RGE_Scenario {
public:
    void Set_scenario_name(char*);
    int Get_player_Active(int);
};

class RGE_Map {
public:
    void set_map_visible(unsigned char);
    void set_map_fog(unsigned char);
};

class RGE_Game_World {
public:
    char gap_00[0x28];
    RGE_Map* map;
    char gap_2C[0x30];
    RGE_Scenario* scenario;
};

class RGE_Base_Game {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void set_game_mode(int);
    char gap_04[0x48];
    TDrawArea* draw_area;
    char gap_50[0x15C];
    TRegistry* registry;
    char gap_1B0[0x244];
    RGE_Game_World* world;
    char gap_3F8[0x628];
    TDrawArea* map_save_area;
    RGE_Font* get_font(int);
};

extern RGE_Base_Game* rge_base_game;

class TRegistry {
public:
    int RegGetInt(int, char*);
};

class TRIBE_Screen_Sed : public TScreenPanel {
public:
    int is_multi_player;
    char gap_47C[4];
    void* SelectedObject;
    void* DestinationObject;
    float px1, py1, px2, py2;
    int CurrentVictory;
    int CurrentPlayer;
    char gap_4A0[4];
    int scenario_mode;
    int map_type;
    int mp_victory_type;
    int brush_size;
    int paint_type;
    short player_num;
    char gap_4BA[2];
    int message_type;
    unsigned char need_to_save_flag;
    unsigned char valid_save_spot_flag;
    char gap_4C2[6];
    TRIBE_Main_View* main_view;
    RGE_Diamond_Map_View* map_view;
    TMessagePanel* message_panel;
    TPanel* bottom_panel;
    char gap_4D8[0x5B8 - 0x4D8];
    TDropDownPanel* player_number_list;
    char gap_5BC[0x928 - 0x5BC];
    RGE_Game_World* world;
    int update_interval;
    unsigned long last_update_time;
    int map_redraw_interval;
    unsigned long last_map_redraw_time;
    int changed_system_colors;
    int save_text_color;
    int save_window_color;

    virtual ~TRIBE_Screen_Sed();
    TRIBE_Screen_Sed(char*, int);
    void init_module_variables();
    int command_new_map(char*, int, int, int, int, int);
    void create_all_buttons_etc();
    void set_player_active(short, int);
    void SavePlayerActiveStatus();
    void position_panels();
    void set_panel_info();
    void set_map_type(int, int);
    void set_mp_victory_type(int, int);
    void set_brush_size(int);
    void set_paint_type(int, int);
    void set_player(short, unsigned char, unsigned char);
    void set_unit_player(short);
    void set_message_type(int, int);
    void set_scenario_mode(int);
    void set_unit(short);
};
#endif

TRIBE_Screen_Sed::TRIBE_Screen_Sed(char* file, int mode) : TScreenPanel("Scenario Editor Screen")
{
    char name[260];
    char temp_name[260];
    this->is_multi_player = 0;
    this->scenario_mode = 0;
    this->map_type = 0;
    this->mp_victory_type = 2;
    this->brush_size = 0;
    this->paint_type = 0;
    this->player_num = 1;
    this->message_type = 0;
    this->SelectedObject = 0;
    this->DestinationObject = 0;
    this->CurrentPlayer = 0;
    this->need_to_save_flag = 0;
    this->valid_save_spot_flag = 0;
    this->init_module_variables();
    this->update_interval = 200;
    this->last_update_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\scr_sed.cpp", 0x117);
    this->map_redraw_interval = 1000;
    this->last_map_redraw_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\scr_sed.cpp", 0x11A);
    this->save_text_color = 0;
    this->save_window_color = 0;
    this->changed_system_colors = 0;
    this->CurrentVictory = 0;
    rge_base_game->set_game_mode(7);
    if (!this->command_new_map(file, mode, 0, 0x90, 0x90, 1)) {
        this->setup_error = 1;
        return;
    }
    int game_file_number = rge_base_game->registry->RegGetInt(0, "Game File Number");
    sprintf(temp_name, "default%d.scx", game_file_number);
    if (file && strcmp(file, temp_name) == 0)
        this->need_to_save_flag = 1;
    if (!this->TScreenPanel::setup(rge_base_game->draw_area,
                                   "scr5", 0xC387, 1)) {
        this->setup_error = 1;
        return;
    }
    this->TEasy_Panel::setup_shadow_area(0);
    this->main_view = new TRIBE_Main_View;
    if (this->main_view == 0 || this->main_view->setup_error != 0) {
        this->setup_error = 1;
        return;
    }
    if (!this->main_view->RGE_View::setup(this->render_area, this,
                                          0, 0, 0, 0, 0xA1, 0,
                                          "bordline")) {
        this->setup_error = 1;
        return;
    }
    this->map_view = new RGE_Diamond_Map_View;
    if (this->map_view == 0 || this->map_view->setup_error != 0) {
        this->setup_error = 1;
        return;
    }
    if (!this->map_view->RGE_Diamond_Map::setup(
            this->render_area, this, 0, 0, 0, 0, 0xA1, 0,
            rge_base_game->map_save_area)) {
        this->setup_error = 1;
        return;
    }
    this->map_view->set_bitmap("map640.bmp", 0xC4E1);
    {
        TRIBE_Main_View* main_view = this->main_view;
        RGE_Diamond_Map_View* map_view = this->map_view;
        map_view->main_view = main_view;
    }
    {
        RGE_Diamond_Map_View* map_view = this->map_view;
        TRIBE_Main_View* main_view = this->main_view;
        main_view->map_view = map_view;
    }
    this->main_view->set_help_info(-1, -1);
    RGE_Font* font = rge_base_game->get_font(0x0B);
    this->message_panel = new TMessagePanel(font->font, font->font_wid,
                                             font->font_hgt);
    if (this->message_panel == 0 || this->message_panel->setup_error != 0) {
        this->setup_error = 1;
        return;
    }
    if (!this->message_panel->setup(this->render_area, this->main_view,
                                    0, 0, 0, 0, 0)) {
        this->setup_error = 1;
        return;
    }
    this->bottom_panel = new TPanel;
    if (this->bottom_panel == 0 || this->bottom_panel->setup_error != 0) {
        this->setup_error = 1;
        return;
    }
    if (!this->bottom_panel->setup(this->render_area, this,
                                   0, 0, 0, 0, 0)) {
        this->setup_error = 1;
        return;
    }
    this->create_all_buttons_etc();
    int idx;
    if (file && *file) {
        if (strstr(file, ".scn") != 0 ||
            strstr(file, ".SCN") != 0) {
            char* source = file;
            int i = 0;
            do {
                name[i++] = source[0];
                source++;
            } while (source[0] != '.');
            name[i] = 0;
            sprintf(file, "%s.scx", name);
            this->world->scenario->Set_scenario_name(file);
        }
        for (idx = 0; idx < 8; ++idx) {
            if (this->world->scenario->Get_player_Active(idx) == 0)
                break;
        }
        --idx;
        this->player_number_list->set_line(idx);
    } else {
        this->set_player_active(0, 1);
        this->set_player_active(1, 1);
        this->player_number_list->set_line(1);
    }
    this->SavePlayerActiveStatus();
    this->set_curr_child(this->bottom_panel);
    this->position_panels();
    this->set_panel_info();
    this->set_map_type(1, 0);
    this->set_mp_victory_type(1, 0);
    this->set_brush_size(1);
    this->set_paint_type(1, 0);
    this->set_player(1, 0, 0);
    this->set_unit_player(1);
    this->set_message_type(1, 0);
    this->set_scenario_mode(1);
    this->set_unit(-1);
    this->world->map->set_map_visible(1);
    this->world->map->set_map_fog(0);
}
