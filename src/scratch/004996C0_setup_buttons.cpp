// VA: 004996C0 TRIBE_Screen_Game::setup_buttons (4574B)
// PDB source: scr_game.cpp lines 3395-4017
// Attempt log:
// - baseline: canonical TRIBE_Screen_Game fields and named UI/game surfaces,
//   with the inventory, unit-level, production, and technology branches
//   reconstructed from the packet and exact scr_game.cpp donors.
// - removed an unsupported start_item prologue store; the original initializes
//   item_cnt and last_item only (the temporary metric was slightly worse).
// - /GX was tested against the existing scr_game donor flag context; emitted
//   code was unchanged, so the default response file remains authoritative.
// - corrected production dispatch to game_obj->object_state and work_type,
//   including the 0x67 command path and the production-queue menu.
// - restored named selection-hole handling and the original 0x4E43 versus
//   0x1D4E3 multi-selection IDs; the remaining drift is compiler CFG/tail
//   merging and late production/default-button scheduling, not an unknown
//   pointer-offset scaffold.
// - moved the packet-backed level-zero selection/button tail outside the
//   level-two building branch; this restored two set_button sites and the
//   level-zero any_selected_have_action path, improving the diff by 27 bytes
//   and matching the original unit-level-zero guard.
// - tested the null-object cancel set_button, the empty level-two production
//   tail, a master_type == 'P' building guard, a level-three action temporary,
//   and declaration/pointer-walk ordering; each was rolled back or codegen-
//   neutral. The clean source remains the best structural reconstruction.
// - restored the level-seven objects dereference without a null guard; the
//   original reads object->objects directly and this reduced the diff by 16.
// - changed the level-four movable flag to int, modeled the production queue
//   scan as a do-while, and changed the technology loop index to int. Together
//   with the direct level-seven dereference, these reduced the diff to 4188B,
//   added seven exact blocks, and raised resync similarity to 51.40%.
// - tested level-four and level-seven loop rotations, raw uchar have_action,
//   int found, an explicit final-tail goto, and a live one local. They were
//   neutral or worse and are not retained. Two set_button sites and one
//   any_selected_have_action site still tail-merge versus the executable.

extern "C" void __cdecl free(void*);
extern "C" void* __cdecl calloc(unsigned int, unsigned int);

typedef unsigned char uchar;

typedef unsigned long ulong;

class RGE_Player;
class RGE_Static_Object;
class RGE_Master_Static_Object;
class RGE_Master_Combat_Object;
class TRIBE_Master_Combat_Object;
class TRIBE_Master_Building_Object;
class RGE_Color_Table;
class TShape;
class TDrawArea;
class TPanel;
class TButtonPanel;
class TRIBE_Panel_Button;
class TTextPanel;
class TRIBE_Player_Tech;
class TRIBE_World;
class TRIBE_Screen_Game;
class Item_Avail;

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, uchar);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(uchar);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long,
                                 TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int);

    TPanel* previousPanelValue;
    TPanel* previousModalPanelValue;
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char* panelNameValue;
    char gap_20[0xD4];
};

class TEasy_Panel : public TPanel {
public:
    long ideal_width;
    long ideal_height;
    char info_file_name[260];
    long info_id;
    TShape* background_pic;
    TShape* background_pic2;
    void* palette;
    char cursor_file[260];
    long cursor_id;
    int background_pos;
    int use_bevels;
    uchar bevel_color1;
    uchar bevel_color2;
    uchar bevel_color3;
    uchar bevel_color4;
    uchar bevel_color5;
    uchar bevel_color6;
    uchar gap_326[2];
    ulong text_color1;
    ulong text_color2;
    ulong focus_color1;
    ulong focus_color2;
    ulong state_color1;
    ulong state_color2;
    char popup_info_file_name[260];
    long popup_info_id;
    TShape* button_pics;
    void* shadow_color_table;
    long shadow_amount;
    uchar background_color1;
    uchar background_color2;
    uchar gap_456[2];
    int enable_ime;
    uchar help_mode;
    uchar gap_45D[3];
    int stock_brush;
    void* brush;
    ulong brush_color;
    void* shadow_area;
    int allow_shadow_area;
    int saved_mouse_mode;
};

class TScreenPanel : public TEasy_Panel {
};

class TShape {
};

class RGE_Color_Table {
public:
    virtual ~RGE_Color_Table();
    char gap_04[0x24];
    uchar table[0x100];
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[4];
    char* name;
    short string_id;
    short string_id2;
    short id;
    char gap_12[0x7D];
    uchar unit_level;
    uchar gap_90[0x0C];
    long help_page_id;
    long hotkey_id;
    char gap_A4[0x14];
};

class RGE_Master_Combat_Object : public RGE_Master_Static_Object {
public:
    char gap_B8[0x60];
    float area_effect_range;
    uchar gap_11C[8];
    short missile_id;
    char gap_126[0x22];
};

class TRIBE_Master_Combat_Object : public RGE_Master_Combat_Object {
public:
    char gap_148[0x16];
    uchar button_location;
    uchar gap_15F[0x5];
};

class TRIBE_Master_Building_Object : public TRIBE_Master_Combat_Object {
public:
    char gap_164[0x0A];
    short building_facet;
};

class RGE_Object_List {
public:
    virtual ~RGE_Object_List();
    void* list;
    short number_of_objects;
    short gap_0A;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x14];
    RGE_Object_List* objects;
    char gap_28[0x0F];
    uchar selected_group;
    uchar gap_38[0x10];
    uchar object_state;
    uchar gap_49[0x3F];
};

class RGE_Action_Object : public RGE_Static_Object {
public:
    char gap_88[0xFC];
    uchar have_action();
};

class Production_Queue_Record {
public:
    short master_id;
    short unit_count;
};

class TRIBE_Building_Object : public RGE_Static_Object {
public:
    char gap_88[0x140];
    Production_Queue_Record* production_queue;
    short production_queue_size;
    short production_queue_count;
    uchar production_queue_enabled;
    uchar production_queue_change_flag;
    uchar production_queue_auto_paused;
    uchar production_queue_need_attr;
    long build_pts;
    long unique_build_id;
    uchar culture;
    uchar built;
    char gap_1E6[0x0E];
    int work_status(short&, short&, short&, char*, short);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x20];
    RGE_Master_Static_Object** master_objects;
    RGE_Object_List* objects;
    char gap_2C[0x1E];
    short id;
    short attribute_num;
    char gap_4E[2];
    float* attributes;
    uchar culture;
    uchar gap_55[0xB3];
    RGE_Color_Table* color_table;
    char gap_10C[0x24];
    RGE_Static_Object* selected_obj;
    RGE_Static_Object* sel_list[25];
    long sel_object_properties;
    short sel_count;
    uchar gap_19E[0x82];

    uchar unit_level_selected();
    int is_group_selected(short);
};

class Tech_Player_Tree {
public:
    float research_done;
    short state;
    short gap_06;
};

class Tech_Tree {
public:
    char* name;
    short gap_04[16];
    short icon;
    uchar gap_26[2];
    short build_obj_id;
    short string_id;
    short string_id2;
    uchar gap_2E[2];
    long help_string_id;
    long help_page_id;
    long hotkey_id;
};

class TRIBE_Tech {
public:
    Tech_Tree* tech_tree;
};

class RGE_Game_World {
public:
    uchar gap_00[0x104];
};

class TRIBE_World : public RGE_Game_World {
public:
    TRIBE_Tech* tech;
};

class TRIBE_Player_Tech {
public:
    Tech_Player_Tree* tech_player_tree;
    short tech_player_tree_num;
    short gap_06;
    TRIBE_Tech* base_tech;
    RGE_Player* owner;

    short get_tech_state(short);
    void tech_cost(short, short*, short*, short*, short*, short*, short*);
    long get_help_message(short);
    long get_help_page(short);
    short get_string_id(short);
    short get_string_id2(short);
    uchar get_button_location(short);
    long get_hotkey(short);
};

class TRIBE_Player : public RGE_Player {
public:
    TRIBE_Player_Tech* tech_tree;

    void interface_item_avail(Item_Avail**, short*, short);
    void interface_tech_avail(Item_Avail**, short*, short);
};

class Item_Avail {
public:
    char* name;
    short id;
    short pict;
    short inventory_item_1;
    short gap_0A;
    float inventory_cost_1;
    short inventory_item_2;
    short gap_12;
    float inventory_cost_2;
    short inventory_item_3;
    short gap_1A;
    float inventory_cost_3;
    long help_string_id;
    long help_page_id;
};

class Trade_Avail {
};

class TButtonPanel : public TPanel {
public:
    virtual ~TButtonPanel();
    char gap_F4[0x1C4];

    void set_picture(short, TShape*, short);
    long get_id();
    void set_text_color(int, ulong, ulong);
};

class TRIBE_Panel_Button : public TButtonPanel {
public:
    int display_garrison;
    int garrison_number;
    uchar tribe_button_type;
    uchar gap_2C1[3];
    TShape* border_pic;
    char gap_2C8[0x108];
    int in_use;

    void set_display_garrison(int);
    void set_garrison_number(int);
};

class TTextPanel : public TPanel {
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int, int);
    virtual void set_player(short);
    virtual int get_error_code();
    virtual char* get_string(int, long, char*, int);
    virtual char* get_string(long, char*, int);
    virtual char* get_string(long);

    char gap_04[0x1AC];
    int prog_mode;
    int game_mode;
    int sub_game_mode;

    RGE_Player* get_player();
};

class TRIBE_Screen_Game : public TScreenPanel {
public:
    TShape* game_screen_pic;
    TShape* button_border1_pic;
    TShape* button_other_pic;
    TShape* button_border2_pic;
    TShape* button_border3_pic;
    TShape* button_cmd_pic;
    TShape* button_tech_pic;
    TShape* button_unit_pic;
    TShape* button_bldg_pics[5];
    TShape* more_cancel_pic;
    short more_frame;
    short cancel_frame;
    short unselect_frame;
    uchar gap_4B6[2];
    void* main_view;
    void* map_view;
    void* inven_panel;
    void* object_panel;
    TRIBE_Panel_Button* button_panel[17];
    char gap_50C[0xA8];
    TRIBE_World* world;
    unsigned long update_interval;
    unsigned long last_update_time;
    unsigned long map_redraw_interval;
    unsigned long last_map_redraw_time;
    RGE_Static_Object* game_obj;
    short sel_count;
    uchar gap_5CE[2];
    Item_Avail* tech_list;
    Item_Avail* make_list;
    Item_Avail* bldg_list;
    Trade_Avail* trade_list;
    short item_cnt;
    short start_item;
    short last_item;
    uchar gap_5E6[0x122];
    long mouse_last_x;
    long mouse_last_y;

    void setup_buttons();
    char* calc_text_msg(char*, Item_Avail*, long, long);
    short calc_button_loc(uchar);
    void set_button(TShape*, short, short, long, long, long, long, long,
                    uchar*, char*, char*, int);
    int any_selected_have_action();
    void disable_unused_buttons();
};

extern RGE_Base_Game* rge_base_game;
extern uchar production_queues_is_use;

#define set_command_button(screen, index, frame, type, string_id) \
    (screen)->set_button((screen)->button_cmd_pic, (index), (frame), \
                         (type), 0, (string_id), -1, 0, (uchar*)0, \
                         (char*)0, (char*)0, 0)

void TRIBE_Screen_Game::setup_buttons()
{
    TRIBE_Player* player;
    char name[512];
    char msg_str[512];
    int culture;
    TShape* final_pic;
    short final_frame;
    long final_type;

    this->item_cnt = 0;
    this->last_item = -1;

    TRIBE_Panel_Button** button = this->button_panel;
    for (int i0 = 0; i0 < 12; ++i0) {
        (*button)->in_use = 0;
        ++button;
    }

    this->mouse_last_x = -1;
    this->mouse_last_y = -1;

    if (this->game_obj == 0) {
        goto finish_disable_buttons;
    }

    player = (TRIBE_Player*)rge_base_game->get_player();
    culture = player->culture;
    if (culture > 5) {
        culture = 0;
    }
    if ((rge_base_game->game_mode == 6) &&
        (rge_base_game->sub_game_mode == 1)) {
        short building_count;
        short inv_2 = -1;
        short tech_count = -1;

        player->interface_item_avail(&this->bldg_list,
                                     &this->item_cnt, 0x76);
        building_count = this->item_cnt;

        for (short i1 = 0; i1 < building_count; ++i1) {
            if (this->bldg_list[i1].id == 0x6D) {
                inv_2 = i1;
            }
            if (this->bldg_list[i1].id == 0x57) {
                tech_count = i1;
            }
        }

        for (short i2 = 0; i2 < building_count; ++i2) {
            Item_Avail* item = &this->bldg_list[i2];
            RGE_Master_Static_Object* base_master =
                player->master_objects[item->id];
            TRIBE_Master_Building_Object* master =
                (TRIBE_Master_Building_Object*)base_master;
            uchar button_location =
                ((TRIBE_Master_Combat_Object*)base_master)->button_location;

            if ((i2 == inv_2) && (tech_count == -1)) {
                button_location = 6;
            }

            if (this->start_item == 0) {
                if (button_location > 10) {
                    this->start_item = 1;
                    continue;
                }
            } else if (button_location < 11) {
                this->start_item = 1;
                continue;
            }

            rge_base_game->get_string(master->string_id, name + 4, 0x200);
            this->calc_text_msg(msg_str + 4, item, 0x13,
                                master->string_id2);
            short index = this->calc_button_loc(button_location);
            this->set_button(this->button_bldg_pics[culture], index,
                             (short)(master->building_facet + item->pict),
                             0x13, item->id,
                             master->string_id2 + 100000,
                             item->help_page_id, master->hotkey_id,
                             player->color_table->table, name + 4,
                             msg_str + 4, 0);
        }

        if (this->start_item != 0) {
            this->set_button(this->more_cancel_pic, 5, this->more_frame,
                             0x0C, 0, 0x1D4D7, -1, 0,
                             (uchar*)0, (char*)0, (char*)0, 0);
        }

        final_pic = this->more_cancel_pic;
        final_frame = this->cancel_frame;
        final_type = 0x0B;
    } else if ((rge_base_game->game_mode == 0) &&
               (rge_base_game->prog_mode != 5)) {
        if (this->game_obj->owner == player) {
            uchar level = player->unit_level_selected();

            if (level == 3) {
                set_command_button(this, 0, 2, 3, 0x1D4DF);
                set_command_button(this, 1, 0, 0x1F, 0x1D4F6);
                if (this->any_selected_have_action()) {
                    set_command_button(this, 2, 3, 5, 0x1D4DD);
                }

                if (player->sel_count > 1) {
                    set_command_button(this, 6, 7, 8, 0x1D4E1);
                    set_command_button(this, 7, 8, 9, 0x4E43);
                } else if (this->game_obj->selected_group != 0) {
                    set_command_button(this, 6, 8, 9, 0x1D4E3);
                }
            } else if (level == 9) {
                if (this->any_selected_have_action()) {
                    set_command_button(this, 0, 3, 5, 0x1D4DD);
                }
                if (player->sel_count > 1) {
                    set_command_button(this, 6, 7, 8, 0x1D4E1);
                    set_command_button(this, 7, 8, 9, 0x1D4E3);
                } else if (this->game_obj->selected_group != 0) {
                    set_command_button(this, 6, 8, 9, 0x1D4E3);
                }
            } else if (level == 4) {
                short selected = 0;
                int movable = 1;
                short i = 0;

                while ((selected < player->sel_count) && (i < 25)) {
                    RGE_Static_Object* object = player->sel_list[i];
                    if (object != 0) {
                        RGE_Master_Combat_Object* master =
                            (RGE_Master_Combat_Object*)object->master_obj;
                        if ((master->missile_id == -1) ||
                            (master->area_effect_range == 0.0f)) {
                            movable = 0;
                            break;
                        }
                        ++selected;
                    }
                    ++i;
                }

                set_command_button(this, 0, 4, 0x16, 0x1D4EA);
                short command_index = 1;
                if (movable) {
                    set_command_button(this, 1, 0x0C, 0x17, 0x1D4EB);
                    command_index = 2;
                }
                if (this->any_selected_have_action()) {
                    set_command_button(this, command_index, 3, 5,
                                       0x1D4DD);
                }

                if (player->sel_count > 1) {
                    set_command_button(this, 6, 7, 8, 0x1D4E1);
                    set_command_button(this, 7, 8, 9, 0x4E43);
                } else if (this->game_obj->selected_group != 0) {
                    set_command_button(this, 6, 8, 9, 0x1D4E3);
                }
            } else if (level == 6) {
                set_command_button(this, 0, 0x0D, 0x1C, 0x1D4F1);
                set_command_button(this, 1, 0x0E, 0x1D, 0x1D4F2);
                if (this->any_selected_have_action()) {
                    set_command_button(this, 2, 3, 5, 0x1D4DD);
                }

                if (player->sel_count > 1) {
                    set_command_button(this, 6, 7, 8, 0x1D4E1);
                    set_command_button(this, 7, 8, 9, 0x4E43);
                } else if (this->game_obj->selected_group != 0) {
                    set_command_button(this, 6, 8, 9, 0x1D4E3);
                }
            } else if (level == 7) {
                short selected = 0;
                int found = 0;
                short i = 0;

                while ((selected < player->sel_count) && (i < 25)) {
                    RGE_Static_Object* object = player->sel_list[i];
                    if (object != 0) {
                        ++selected;
                        if (object->objects->number_of_objects > 0) {
                            set_command_button(this, 0, 5, 7, 0x1D4E9);
                            found = 1;
                            break;
                        }
                    }
                    ++i;
                }

                short command_index = found;
                if (this->any_selected_have_action()) {
                    set_command_button(this, command_index, 3, 5,
                                       0x1D4DD);
                }
                if (player->sel_count > 1) {
                    set_command_button(this, 6, 7, 8, 0x1D4E1);
                    set_command_button(this, 7, 8, 9, 0x4E43);
                } else if (this->game_obj->selected_group != 0) {
                    set_command_button(this, 6, 8, 9, 0x1D4E3);
                }
            } else if (level == 5) {
                this->set_button(this->button_tech_pic, 1, 0x57, 0x19,
                                 0, 0x1A25C, 0x265AF, 0,
                                 (uchar*)0, (char*)0, (char*)0, 0);
                this->set_button(this->button_tech_pic, 2, 0x56, 0x1A,
                                 0, 0x1A25D, 0x265AF, 0,
                                 (uchar*)0, (char*)0, (char*)0, 0);
                this->set_button(this->button_tech_pic, 3, 0x58, 0x1B,
                                 0, 0x1A25E, 0x265AF, 0,
                                 (uchar*)0, (char*)0, (char*)0, 0);
                if (this->any_selected_have_action()) {
                    set_command_button(this, 0, 3, 5, 0x1D4DD);
                }
                if (player->sel_count > 1) {
                    set_command_button(this, 6, 7, 8, 0x1D4E1);
                    set_command_button(this, 7, 8, 9, 0x1D4E3);
                } else if (this->game_obj->selected_group != 0) {
                    set_command_button(this, 6, 8, 9, 0x1D4E3);
                }
            } else if (level == 2) {
                TRIBE_Building_Object* building =
                    (TRIBE_Building_Object*)this->game_obj;
                short work_type;
                short work_target;
                short progress;

                building->work_status(work_type, work_target, progress,
                                      name + 4, 0x200);
                if (progress == 100) {
                    work_type = 0;
                }

                uchar object_state = building->object_state;
                if (object_state < 2) {
                    set_command_button(this, 0, 3, 0x14, 0x1D4E5);
                    final_pic = this->more_cancel_pic;
                    final_frame = this->unselect_frame;
                    final_type = 6;
                    goto finish_normal_buttons;
                } else if ((object_state == 2) && (work_type == 0x67)) {
                    set_command_button(this, 0, 3, 5, 0x1D4DD);
                    final_pic = this->more_cancel_pic;
                    final_frame = this->unselect_frame;
                    final_type = 6;
                    goto finish_normal_buttons;
                } else if ((object_state == 2) &&
                           ((work_type != 0x66) ||
                            (production_queues_is_use != 0))) {
                    short tech_count_local;
                    short make_count;
                    player->interface_tech_avail(&this->tech_list,
                                                 &tech_count_local,
                                                 building->master_obj->id);
                    player->interface_item_avail(&this->make_list,
                                                 &make_count,
                                                 building->master_obj->id);
                    this->start_item = make_count + tech_count_local;

                    bool show_queue =
                        (production_queues_is_use != 0) &&
                        (building->production_queue_count > 0);
                    if (show_queue) {
                        set_command_button(this, 6, 3, 5, 0x1D4DD);
                    }

                    for (short i3 = 0; i3 < make_count; ++i3) {
                        Item_Avail* item = &this->make_list[i3];
                        RGE_Master_Static_Object* base_master =
                            player->master_objects[item->id];
                        TRIBE_Master_Combat_Object* master =
                            (TRIBE_Master_Combat_Object*)base_master;
                        int queued = 0;

                        if (show_queue) {
                            Production_Queue_Record* queue =
                                building->production_queue;
                            short queue_count = building->production_queue_count;
                            do {
                                if (queue->master_id == master->id) {
                                    queued += queue->unit_count;
                                }
                                ++queue;
                                --queue_count;
                            } while (queue_count != 0);
                        }

                        if ((!show_queue) || (queued > 0)) {
                            rge_base_game->get_string(master->string_id,
                                                      name + 4, 0x200);
                            this->calc_text_msg(msg_str + 4, item, 0x12,
                                                master->string_id2);
                            short index = this->calc_button_loc(
                                master->button_location);
                            this->set_button(this->button_unit_pic, index,
                                             item->pict, 0x12, item->id,
                                             master->string_id2 + 100000,
                                             item->help_page_id,
                                             master->hotkey_id,
                                             player->color_table->table,
                                             name + 4, msg_str + 4, 0);
                            if ((!show_queue) || (queued < 1)) {
                                this->button_panel[index]
                                    ->set_display_garrison(0);
                            } else {
                                this->button_panel[index]
                                    ->set_display_garrison(1);
                                this->button_panel[index]
                                    ->set_garrison_number(queued);
                            }
                        }
                    }

                    int tech_disabled = 0;
                    if (show_queue) {
                        goto finish_disable_buttons;
                    }

                    if ((building->master_obj->id == 0x6D) &&
                        (tech_count_local == 0) &&
                        ((int)rge_base_game->get_player()->attributes[6] < 4)) {
                        short tech_id =
                            (short)((int)rge_base_game->get_player()->attributes[6] + 100);
                        if (player->tech_tree->get_tech_state(tech_id) != -1) {
                            if (this->tech_list != 0) {
                                free(this->tech_list);
                            }
                            this->tech_list =
                                (Item_Avail*)calloc(1, 0x28);
                            if (this->tech_list != 0) {
                                tech_count_local = 1;
                                tech_disabled = 1;
                                short inv_1;
                                short amt_1;
                                short inv_2;
                                short amt_2;
                                short inv_3;
                                short amt_3;
                                player->tech_tree->tech_cost(
                                    tech_id, &inv_1, &amt_1, &inv_2,
                                    &amt_2, &inv_3, &amt_3);
                                Tech_Tree* tech =
                                    &this->world->tech->tech_tree[tech_id];
                                this->tech_list->id = tech_id;
                                this->tech_list->name = tech->name;
                                this->tech_list->pict = tech->icon;
                                this->tech_list->inventory_item_1 = inv_1;
                                this->tech_list->inventory_cost_1 = (float)amt_1;
                                this->tech_list->inventory_item_2 = inv_2;
                                this->tech_list->inventory_cost_2 = (float)amt_2;
                                this->tech_list->inventory_item_3 = inv_3;
                                this->tech_list->inventory_cost_3 = (float)amt_3;
                                this->tech_list->help_string_id =
                                    player->tech_tree->get_help_message(tech_id);
                                this->tech_list->help_page_id =
                                    player->tech_tree->get_help_page(tech_id);
                            }
                        }
                    }

                    for (int i4 = 0; i4 < tech_count_local; ++i4) {
                        Item_Avail* item = &this->tech_list[i4];
                        short string_id =
                            player->tech_tree->get_string_id(item->id);
                        rge_base_game->get_string(string_id, name + 4,
                                                  0x200);
                        short string_id2 =
                            player->tech_tree->get_string_id2(item->id);
                        this->calc_text_msg(msg_str + 4, item, 0x11,
                                            string_id2);
                        uchar button_location =
                            player->tech_tree->get_button_location(item->id);
                        short index = this->calc_button_loc(button_location);
                        this->set_button(this->button_tech_pic, index,
                                         item->pict, 0x11, item->id,
                                         item->help_string_id,
                                         item->help_page_id,
                                         player->tech_tree->get_hotkey(item->id),
                                         player->color_table->table,
                                         name + 4, msg_str + 4,
                                         tech_disabled);
                    }

                    if ((make_count != 0) || (tech_count_local != 0)) {
                        final_pic = this->more_cancel_pic;
                        final_frame = this->unselect_frame;
                        final_type = 6;
                        goto finish_normal_buttons;
                    }
                }

            }

            bool special_selection =
                (level == 0) && (player->sel_count > 1);
            bool all_known = true;
            bool have_action = false;
            if (special_selection) {
                short selected = 0;
                for (short i5 = 0;
                     (i5 < 25) && (selected < player->sel_count); ++i5) {
                    RGE_Action_Object* object =
                        (RGE_Action_Object*)player->sel_list[i5];
                    if (object != 0) {
                        uchar object_level = object->master_obj->unit_level;
                        if ((object_level != 3) &&
                            (object_level != 9) &&
                            (object_level != 4) &&
                            (object_level != 5) &&
                            (object_level != 6) &&
                            (object_level != 7) &&
                            (object_level != 8)) {
                            all_known = false;
                            break;
                        }
                        if (!have_action) {
                            have_action = object->have_action() != 0;
                        }
                        ++selected;
                    }
                }
            }

            int group;
            if (special_selection && all_known) {
                group = player->is_group_selected(4);
                if (group != 0) {
                    set_command_button(this, 0, 2, 3, 0x1D4DF);
                }
                if (have_action) {
                    set_command_button(this, group != 0, 3, 5,
                                       0x1D4DD);
                }
            } else {
                group = player->is_group_selected(4);
                if (group != 0) {
                    set_command_button(this, 0, 2, 3, 0x1D4DF);
                }
                if (this->any_selected_have_action()) {
                    set_command_button(this, group != 0, 3, 5,
                                       0x1D4DD);
                }
            }
            if (player->sel_count > 1) {
                set_command_button(this, 6, 7, 8, 0x1D4E1);
                set_command_button(this, 7, 8, 9, 0x4E43);
            } else if (this->game_obj->selected_group != 0) {
                set_command_button(this, 6, 8, 9, 0x1D4E3);
            }
        }

        final_pic = this->more_cancel_pic;
        final_frame = this->unselect_frame;
        final_type = 6;
    } else {
        final_pic = this->more_cancel_pic;
        final_frame = this->cancel_frame;
        final_type = 0x0B;
    }

finish_normal_buttons:
    this->set_button(final_pic, 0x0B, final_frame, final_type, 0,
                     0x1D4D9, -1, 0, (uchar*)0, (char*)0, (char*)0, 0);

finish_disable_buttons:
    this->disable_unused_buttons();
}

// Managed pass 2026-08-17 notes:
// Baseline: 4268 differing bytes, 4129 rebuilt bytes, and 80 calls.
// The reviewed work_status reference ABI emitted the same bytes as pointers.
// The pointer spelling was not canonical, so this source uses references.
// The original passes tech_count_local to interface_tech_avail without a store.
// Removing its zero initializer added one exact block in a valid source model.
// Late disable labels for null-object and queue exits were codegen-neutral.
// Byte culture changed compare width. Other tested aliases and guards were worse.
