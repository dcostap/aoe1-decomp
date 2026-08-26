// VA: 0053F810 command_place_object (512B)
// PDB source: vw_main.cpp, lines 1365-1433
//
// Baseline reconstruction: typed placement flow using the RGE view, base-game,
// player, master-object, and movable-object surfaces proven by the packet.
// The mode-1 player command and mode-8 scenario-object path follow the original
// branch bands.  The compiler-facing source stays natural; no raw offsets or
// code-generation scaffolding are used.
//
// Attempt log:
// - baseline: typed placement flow reached the exact size, frame, and 17-call
//   set; the first mismatch was the alignment-mode expression.
// - control-flow: an unsigned-char alignment flag added stack traffic and was
//   rolled back; the int default-one/zero flag matched the original register
//   branch.  The RGE_View map field restored movable_object at +174.
// - liveness: the int alignment flag held the original EAX value and reduced
//   the strict diff from 358 bytes to 61 bytes.
// - abi: a separate int placement result preserved the original check result
//   home while keeping the mode-1 command result as a direct byte predicate.
// - control-flow: inverted the draw-level test to match both redraw tails;
//   exact 512 bytes under default.rsp.

#ifndef RGE_MAIN_VIEW_SHARED_CONTEXT
class RGE_Game_World;
class RGE_Map;
class RGE_Player;
class RGE_Static_Object;
class RGE_Active_Sprite_List;
class RGE_Sprite;
class RGE_Tile;
class XYZBYTEPoint;

struct RGE_Pick_Info {
    float x;
    float y;
    short scr_x;
    short scr_y;
    RGE_Static_Object* object;
    RGE_Tile* tile;
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void save(int);
    virtual RGE_Static_Object* make_new_obj(RGE_Player*, float, float, float);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual unsigned char check_placement(
        RGE_Player*, float, float, int*, unsigned char, unsigned char,
        unsigned char, unsigned char, unsigned char, unsigned char);
    virtual unsigned char alignment(
        float*, float*, RGE_Game_World*, unsigned char);

    char gap_04[0x60];
    unsigned char elevation_flag;
};

class RGE_Active_Sprite_List {
public:
    unsigned char get_lowest_draw_level();
};

class RGE_Sprite {
public:
    unsigned char get_lowest_draw_level();
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*,
                                    float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(void*, short, short, void*);
    virtual void shadow_draw(void*, short, short, unsigned char);
    virtual void normal_draw(void*, short, short);
    virtual void draw_front_frame(void*, short, short);
    virtual void draw_back_frame(void*, short, short);
    virtual void draw_frame(void*, short, short);
    virtual unsigned char update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int);
    virtual float teleport(float, float, float);

    long id;
    void* master_obj;
    RGE_Player* owner;
    RGE_Sprite* sprite;
    RGE_Sprite* old_sprite;
    RGE_Active_Sprite_List* sprite_list;
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual void run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int, int);

    char gap_04[0x1B0];
    int game_mode;
    int sub_game_mode;
    char gap_1BC[0x240];
    short master_obj_id;

    RGE_Player* get_player();
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char);
    virtual void do_resign(int);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int);
    virtual int isEnemy(int);
    virtual int isAlly(int);
    virtual int isNeutral(int);
    virtual int isAllNeutral();
    virtual void setDiplomaticStance(int, int);
    virtual void loadAIInformation(char*, char*, char*, int, int);
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float, float,
                                 float, int, int, int);
    virtual void processAIOrder(int, int, int, int, int, float, float, float,
                                float, int, int, int);
    virtual void kickAI(int);
    virtual int strategicNumber(int);
    virtual void sendGameOrder(RGE_Static_Object*, RGE_Static_Object*, float,
                               float);
    virtual void sendAddWaypointCommand(int, XYZBYTEPoint*, int);
    virtual void processAddWaypointCommand(int, XYZBYTEPoint*, int);
    virtual void sendPlayCommand(int, int*, int, int, int);
    virtual void sendPlayCommand(int, int, int);
    virtual int sendAICommand(int, int, int, int, int);
    virtual int objectCostByType(int);
    virtual void trackUnitGather(int, int, int);
    virtual RGE_Static_Object* make_scenario_obj(float, float, float, short,
                                                  unsigned char, float);
    virtual void scenario_save(int);
    virtual void scenario_load(int, long*, float);
    virtual void scenario_postsave(int);
    virtual void scenario_postload(int, long*, float);
    virtual void load(int);
    virtual void add_attribute_num(short, float, unsigned char);
    virtual void update();
    virtual void update_dopplegangers();
    virtual void save(int);
    virtual void save2(int);
    virtual void save_info(int);
    virtual void random_start();
    virtual RGE_Static_Object* make_new_object(
        long, float, float, float, int);
    virtual void analyze_selected_objects();
    virtual int get_mouse_pointer_action_vars(int, int*, int*);
    virtual void command_make_move(RGE_Static_Object*, float, float);
    virtual void command_make_work(RGE_Static_Object*, float, float);
    virtual void command_make_do(RGE_Static_Object*, float, float);
    virtual void command_stop();
    virtual unsigned char command_place_object(
        short, float, float, float);

    char gap_04[0x20];
    RGE_Master_Static_Object** master_objects;
};

class RGE_View {
public:
    virtual ~RGE_View();
    virtual void setup(void*, RGE_View*, long, long, long, long,
                       unsigned char);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long,
                                 long, long, RGE_View*, RGE_View*, RGE_View*,
                                 RGE_View*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int);

    char gap_04[0xF8];
    RGE_Game_World* world;
    RGE_Player* player;
    RGE_Map* map;
    char gap_108[0x6C];
    RGE_Static_Object* movable_object;
};

class RGE_Main_View : public RGE_View {
public:
    virtual int command_place_object(long, long, int);

    unsigned char pick1(unsigned char, unsigned char, long, long,
                         RGE_Pick_Info*, RGE_Static_Object*, int);
    void fixup_pick_info(RGE_Pick_Info*);
};
#endif

extern int allow_user_commands;
extern RGE_Base_Game* rge_base_game;

int RGE_Main_View::command_place_object(long param_1, long param_2, int param_3)
{
    int object_id;
    RGE_Master_Static_Object* master_obj;
    RGE_Pick_Info pick_info;
    RGE_Static_Object* object;
    int placement_result;
    int alignment_flag;

    if (allow_user_commands != 0) {
        if (this->pick1(0x28, 0, param_1, param_2,
                        &pick_info, 0, 1) == 0x33) {
            this->fixup_pick_info(&pick_info);
            object_id = rge_base_game->master_obj_id;
            if (object_id != -1 &&
                rge_base_game->get_player()->master_objects[object_id] != 0) {
                master_obj =
                    rge_base_game->get_player()->master_objects[object_id];
                alignment_flag = 1;
                if (rge_base_game->sub_game_mode == 3) {
                    alignment_flag = 0;
                }
                master_obj->alignment(
                    &pick_info.x, &pick_info.y, this->world,
                    alignment_flag);
                placement_result = master_obj->check_placement(
                        rge_base_game->get_player(), pick_info.x, pick_info.y,
                        0, 1, master_obj->elevation_flag, 0, 1, 1, 1);
                if (placement_result == 0) {
                    if (rge_base_game->game_mode == 1) {
                        if (rge_base_game->get_player()->command_place_object(
                                (short)object_id, pick_info.x, pick_info.y,
                                0.0f) != 0) {
                            if (param_3 != 0) {
                                rge_base_game->set_game_mode(0, 0);
                            }
                            return 1;
                        }
                    } else if (rge_base_game->game_mode == 8) {
                        if (rge_base_game->sub_game_mode == 1) {
                            object = this->movable_object;
                            object->teleport(pick_info.x, pick_info.y, 0.0f);
                        } else {
                            object = rge_base_game->get_player()->make_new_object(
                                object_id, pick_info.x, pick_info.y, 0.0f, 1);
                        }
                        if (object != 0) {
                            unsigned char draw_level;
                            if (object->sprite_list != 0) {
                                draw_level =
                                    object->sprite_list->get_lowest_draw_level();
                            } else if (object->sprite != 0) {
                                draw_level = object->sprite->get_lowest_draw_level();
                            } else {
                                draw_level = 0x14;
                            }
                            if (draw_level == 0) {
                                this->set_redraw(2);
                            } else {
                                this->set_redraw(1);
                            }
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
