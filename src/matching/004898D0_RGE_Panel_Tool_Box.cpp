// VA: 004898D0 RGE_Panel_Tool_Box ctor (1431B)
// rpnl_tbx.cpp lines 39-161
// Attempt log:
// - Baseline used named panel ownership and direct child-button construction.
// - Matched the six-button local as a contiguous radio group.
// - Kept a named base-game pointer for the final mode update.
// - Aggregate initialization of the six-button group matched the original load/store schedule.

#ifndef RPNL_TBX_TU_CONTEXT
typedef unsigned char uchar;

class TDrawArea;
class TDigital;
class TScreenPanel;
class RGE_View;
class RGE_Diamond_Map;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, int);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void set_color(uchar);
    virtual void set_active(int);

    char gap_04[0x1C];
    TDrawArea* render_area;
    char gap_24[0xB4];
    int error_code;
    char gap_DC[0x18];

    TPanel();
};

class TButtonPanel : public TPanel {
public:
    char gap_F4[0x2B8 - 0xF4];

    TButtonPanel();
    virtual ~TButtonPanel();

    long setup(TDrawArea*, TPanel*, long, long, long, long, long, TDigital*, long, long);
    void set_text_info(char*, void*, long, long, long, long);
    void set_text(short, char*);
    void set_radio_info(TPanel*, int);
    void set_state_info(short);
};

class RGE_Base_Game {
public:
    char gap_00[0x1B4];
    long game_mode;
};

extern RGE_Base_Game* rge_base_game;
#endif

static char text_game[] = "Game";
static char text_game_label[] = "<Game>";
static char text_object[] = "Obj";
static char text_object_label[] = "<Obj>";
static char text_move[] = "Move";
static char text_move_label[] = "<Move>";
static char text_delete[] = "Del";
static char text_delete_label[] = "<Del>";
static char text_terrain[] = "Terr";
static char text_terrain_label[] = "<Terr>";
static char text_elevation[] = "Elev";
static char text_elevation_label[] = "<Elev>";
static char text_command[] = "Cmd";
static char text_command_label[] = "<Cmd>";

#ifndef RPNL_TBX_TU_CONTEXT
class RGE_Panel_Tool_Box : public TPanel {
public:
    TScreenPanel* screen_panel;
    RGE_View* view;
    RGE_Diamond_Map* map;
    TButtonPanel* game_mode_button;
    TButtonPanel* object_mode_button;
    TButtonPanel* delete_mode_button;
    TButtonPanel* move_mode_button;
    TButtonPanel* terrain_mode_button;
    TButtonPanel* elevation_mode_button;
    TButtonPanel* command_button;
    TPanel* dialog;

    RGE_Panel_Tool_Box(TDrawArea*, TPanel*, long, long, long, long, void*, long, long,
                       TDigital*, TScreenPanel*, RGE_View*, RGE_Diamond_Map*);
    virtual ~RGE_Panel_Tool_Box();
    void game_mode_changed(int, int);
};
#endif

RGE_Panel_Tool_Box::RGE_Panel_Tool_Box(
    TDrawArea* draw_area,
    TPanel* parent,
    long x,
    long y,
    long width,
    long height,
    void* font,
    long font_width,
    long font_height,
    TDigital* sound,
    TScreenPanel* screen_panel_value,
    RGE_View* view_value,
    RGE_Diamond_Map* map_value)
    : TPanel()
{
    this->screen_panel = screen_panel_value;
    this->view = view_value;
    this->map = map_value;
    this->game_mode_button = 0;
    this->object_mode_button = 0;
    this->delete_mode_button = 0;
    this->move_mode_button = 0;
    this->terrain_mode_button = 0;
    this->elevation_mode_button = 0;
    this->command_button = 0;
    this->dialog = 0;

    if (TPanel::setup(draw_area, parent, x, y, width, height, 0) == 0) {
        this->error_code = 1;
    }
    if (this->view == 0) {
        this->error_code = 1;
    }
    else {
        this->game_mode_button = new TButtonPanel;
        if (this->game_mode_button == 0) {
            this->error_code = 1;
        }
        else {
            this->game_mode_button->setup(this->render_area, this, 0, 0, 0x32, 0x1E, 3, sound, 1, 0);
            this->game_mode_button->set_text_info(text_game, font, font_width, font_height, -1, -1);
            this->game_mode_button->set_text(1, text_game_label);

            this->object_mode_button = new TButtonPanel;
            if (this->object_mode_button == 0) {
                this->error_code = 1;
            }
            else {
                this->object_mode_button->setup(this->render_area, this, 0x34, 0, 0x32, 0x1E, 3, sound, 1, 0);
                this->object_mode_button->set_text_info(text_object, font, font_width, font_height, -1, -1);
                this->object_mode_button->set_text(1, text_object_label);

                this->move_mode_button = new TButtonPanel;
                if (this->move_mode_button == 0) {
                    this->error_code = 1;
                }
                else {
                    this->move_mode_button->setup(this->render_area, this, 0x68, 0, 0x32, 0x1E, 3, sound, 1, 0);
                    this->move_mode_button->set_text_info(text_move, font, font_width, font_height, -1, -1);
                    this->move_mode_button->set_text(1, text_move_label);

                    this->delete_mode_button = new TButtonPanel;
                    if (this->delete_mode_button == 0) {
                        this->error_code = 1;
                    }
                    else {
                        this->delete_mode_button->setup(this->render_area, this, 0x9C, 0, 0x32, 0x1E, 3, sound, 1, 0);
                        this->delete_mode_button->set_text_info(text_delete, font, font_width, font_height, -1, -1);
                        this->delete_mode_button->set_text(1, text_delete_label);

                        this->terrain_mode_button = new TButtonPanel;
                        if (this->terrain_mode_button == 0) {
                            this->error_code = 1;
                        }
                        else {
                            this->terrain_mode_button->setup(this->render_area, this, 0xD0, 0, 0x32, 0x1E, 3, sound, 1, 0);
                            this->terrain_mode_button->set_text_info(text_terrain, font, font_width, font_height, -1, -1);
                            this->terrain_mode_button->set_text(1, text_terrain_label);
                            this->terrain_mode_button->set_active(0);

                            this->elevation_mode_button = new TButtonPanel;
                            if (this->elevation_mode_button == 0) {
                                this->error_code = 1;
                            }
                            else {
                                this->elevation_mode_button->setup(this->render_area, this, 0x104, 0, 0x32, 0x1E, 3, sound, 1, 0);
                                this->elevation_mode_button->set_text_info(text_elevation, font, font_width, font_height, -1, -1);
                                this->elevation_mode_button->set_text(1, text_elevation_label);
                                this->elevation_mode_button->set_active(0);

                                TButtonPanel* mode_buttons[6] = {
                                    this->game_mode_button,
                                    this->object_mode_button,
                                    this->move_mode_button,
                                    this->delete_mode_button,
                                    this->terrain_mode_button,
                                    this->elevation_mode_button
                                };
                                this->game_mode_button->set_radio_info((TPanel*)mode_buttons, 6);
                                this->object_mode_button->set_radio_info((TPanel*)mode_buttons, 6);
                                this->move_mode_button->set_radio_info((TPanel*)mode_buttons, 6);
                                this->delete_mode_button->set_radio_info((TPanel*)mode_buttons, 6);
                                this->terrain_mode_button->set_radio_info((TPanel*)mode_buttons, 6);
                                this->elevation_mode_button->set_radio_info((TPanel*)mode_buttons, 6);

                                this->command_button = new TButtonPanel;
                                if (this->command_button == 0) {
                                    this->error_code = 1;
                                }
                                else {
                                    this->command_button->setup(this->render_area, this, 0x13A, 0, 0x32, 0x1E, 3, sound, 1, 0);
                                    this->command_button->set_text_info(text_command, font, font_width, font_height, -1, -1);
                                    this->command_button->set_text(1, text_command_label);
                                    this->command_button->set_state_info(2);
                                    RGE_Base_Game* base_game = rge_base_game;
                                    this->game_mode_changed(base_game->game_mode, base_game->game_mode);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
