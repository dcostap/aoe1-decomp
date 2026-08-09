// 00437CC0 RGE_Diamond_Map::draw_objects (diam_map.cpp:923-1015)
// Baseline reconstruction from the object-list, player, selection, and
// underAttack() dispatches visible in the original routine.
// Attempt log (sa-d55a5d35-draw_objects):
// - Replaced the stub with named object-list/player/color-table/selection ownership and
//   the four observed draw_objects_mode passes.
// - Removed a needless world temporary so VC5 reloads this->world at the original loop
//   boundaries; reordered the selection index/count initialization to retain the original
//   loop topology.
// - The exact source loads map_color independently into color1 and color2. VC5 folds the
//   duplicate read to one byte load but retains both homes, reproducing the original 0xC
//   frame and stack colors without opaque scheduling scaffolding.

class TDrawArea {
public:
    unsigned char* Lock(char*, int);
    void Unlock(char*);
};

class RGE_Static_Object;

class RGE_Object_Node {
public:
    RGE_Static_Object* node;
    RGE_Object_Node* next;
    RGE_Object_Node* prev;
    unsigned char centered;
};

class RGE_Object_List {
public:
    virtual ~RGE_Object_List();
    RGE_Object_Node* list;
    short number_of_objects;
    unsigned char gap_0A[2];
};

class RGE_Color_Table {
public:
    virtual ~RGE_Color_Table();
    char gap_04[0x21];
    unsigned char map_color;
};

class RGE_Player {
public:
    char gap_00[0x28];
    RGE_Object_List* objects;
    char gap_2C[4];
    RGE_Object_List* doppleganger_objects;
    char gap_34[0xD4];
    RGE_Color_Table* color_table;
    char gap_10C[0x28];
    RGE_Static_Object* sel_list[25];
    char gap_198[4];
    short sel_count;
};

class RGE_Game_World {
public:
    char gap_00[0x3C];
    short player_num;
    char gap_3E[2];
    RGE_Player** players;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(); virtual void recycle_out_of_game();
    virtual void draw(); virtual void shadow_draw(); virtual void normal_draw();
    virtual void draw_front_frame(); virtual void draw_back_frame(); virtual void draw_frame();
    virtual unsigned char update(); virtual void check_damage_sprites(); virtual void rehook();
    virtual void save(int); virtual float teleport(float, float, float); virtual void new_sprite();
    virtual void add_overlay_sprite(); virtual void remove_overlay_sprite();
    virtual void change_ownership(RGE_Player*); virtual void modify(); virtual void modify_delta();
    virtual void modify_percent(); virtual void transform(); virtual void copy_obj();
    virtual void set_object_state(unsigned char); virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying(); virtual void destroy_obj(); virtual void die_die_die();
    virtual void damage(); virtual float calculateDamage(); virtual void rotate(long);
    virtual unsigned char can_attack(); virtual void set_attribute(); virtual void set_attribute_amount();
    virtual int heal(int, int); virtual unsigned char heal(float); virtual int canRepair();
    virtual void notify_of_relation(); virtual void do_command(); virtual void move_to(); virtual void work();
    virtual void stop(); virtual void set_attack(); virtual void play_command_sound();
    virtual void play_move_sound(); virtual void new_angle(float); virtual RGE_Static_Object* spawn_death_obj();
    virtual void* get_command_master(); virtual void set_being_worked_on();
    virtual void release_being_worked_on(); virtual unsigned char is_moving();
    virtual RGE_Static_Object* get_target_obj(); virtual void enter_obj(); virtual void exit_obj();
    virtual int explore_terrain(); virtual void unexplore_terrain(); virtual void* get_los_table();
    virtual int inAttackRange(RGE_Static_Object*);
    virtual unsigned char underAttack();

    long id;
    void* master_obj;
    RGE_Player* owner;
    char gap_10[0x26];
    unsigned char selected;
};

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(); virtual void set_rect(); virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char); virtual void set_active(int); virtual void set_positioning();
    virtual void set_fixed_position(long, long, long, long); virtual void set_redraw(int);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, int); virtual void draw_setup(int);
    virtual void draw_finish(); virtual void draw(); virtual void draw_rect(void*);
    virtual void draw_offset(); virtual void draw_rect2(void*); virtual void draw_offset2();
    virtual void paint(); virtual long wnd_proc(); virtual long handle_idle();
    virtual long handle_size(long, long); virtual long handle_paint();
    virtual long handle_key_down(long, short, int, int, int); virtual long handle_char(long, short);
    virtual long handle_command(unsigned int, long); virtual long handle_user_command(unsigned int, long);
    virtual long handle_timer_command(unsigned int, long); virtual long handle_scroll(long, long);
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
    virtual long handle_mouse_move(long, long, int, int);
    virtual long handle_mouse_up(unsigned char, long, long, int, int);
    virtual long handle_mouse_dbl_click(unsigned char, long, long, int, int);
    virtual long mouse_move_action(long, long, int, int); virtual long mouse_left_down_action(long, long, int, int);
    virtual long mouse_left_hold_action(long, long, int, int); virtual long mouse_left_move_action(long, long, int, int);
    virtual long mouse_left_up_action(long, long, int, int); virtual long mouse_left_dbl_click_action(long, long, int, int);
    virtual long mouse_right_down_action(long, long, int, int); virtual long mouse_right_hold_action(long, long, int, int);
    virtual long mouse_right_move_action(long, long, int, int); virtual long mouse_right_up_action(long, long, int, int);
    virtual long mouse_right_dbl_click_action(long, long, int, int);
    virtual long key_down_action(long, short, int, int, int); virtual long char_action(long, short);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void get_true_render_rect(void*); virtual int is_inside(long, long); virtual void set_focus(int);
    virtual void set_tab_order(TPanel*, TPanel*); virtual void set_tab_order(TPanel**, short);
    virtual unsigned char get_help_info(char**, long*, long, long); virtual void stop_sound_system();
    virtual int restart_sound_system(); virtual void take_snapshot(); virtual void handle_reactivate();

    char gap_04[0x1C];
    TDrawArea* render_area;
    char gap_24[0xD0];
};

class RGE_Diamond_Map : public TPanel {
public:
    virtual void draw_selected_area();
    virtual void draw_objects();
    virtual void draw_visible_object(RGE_Static_Object*, unsigned char, unsigned char);
    virtual void draw_object(short, short, unsigned char, short, RGE_Static_Object*);
    virtual void draw_view_rect();

    RGE_Game_World* world;
    RGE_Player* player;
    char gap_FC[0x60];
    int draw_objects_mode;
};

void RGE_Diamond_Map::draw_objects()
{
    RGE_Object_Node* node;
    RGE_Static_Object* object;
    RGE_Player* player;
    unsigned char color2;
    unsigned char color1;
    short i;
    short j;

    if (this->render_area->Lock("diam_map::draw_objects", 1) == 0)
        return;

    this->draw_objects_mode = 1;
    for (node = this->world->players[0]->objects->list;
         node != 0;
         node = node->next) {
        if (node->node != 0)
            this->draw_visible_object(node->node, 0xFF, 0xFF);
    }

    this->draw_objects_mode = 2;
    i = 1;
    if (i < this->world->player_num) {
        do {
            player = this->world->players[i];
            color1 = player->color_table->map_color;
            color2 = player->color_table->map_color;

            for (node = player->doppleganger_objects->list;
                 node != 0;
                 node = node->next) {
                if (node->node != 0)
                    this->draw_visible_object(node->node, color1, color2);
            }

            for (node = player->objects->list;
                 node != 0;
                 node = node->next) {
                object = node->node;
                if (object != 0 && (object->selected & 1) == 0 &&
                    (object->owner != this->player ||
                     object->underAttack() == 0)) {
                    this->draw_visible_object(object, color1, color2);
                }
            }

            ++i;
        } while (i < this->world->player_num);
    }

    if (this->player->sel_count > 0) {
        this->draw_objects_mode = 3;
        i = 0;
        j = 0;
        while (i < 25 && j < this->player->sel_count) {
            object = this->player->sel_list[i];
            if (object != 0) {
                this->draw_visible_object(object, 0xFF, 0xFF);
                ++j;
            }
            ++i;
        }
    }

    this->draw_objects_mode = 4;
    color1 = this->player->color_table->map_color;
    color2 = this->player->color_table->map_color;
    for (node = this->player->objects->list;
         node != 0;
         node = node->next) {
        object = node->node;
        if (object != 0 && object->underAttack() != 0)
            this->draw_visible_object(object, color1, color2);
    }

    this->render_area->Unlock("diam_map::draw_objects");
}
