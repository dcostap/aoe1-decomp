// VA: 00509C60 TRIBE_Command::do_command_build
// tcommand.cpp lines 256-331
// Attempt log:
// 1: natural structured source from packet/decompiler: 416 B, frame 8 not original 0xC; count tested as byte.
// 2: introduced int count local loaded from cmd->count early: restored original early prologue/load order through player lookup, still frame 8 and 416 B.
// 3: widened placementResult storage to int while passing uchar*: worsened to 400 B; rolled back.
// 4: split count declaration/assignment: no material change, still 416 B.
// 5: count stack-forcing: section 432 B, first mismatch still frame imm and broad extra traffic; rolled back.
// 6: positive count comparisons (0 < count) instead of count <= 0: no size/layout improvement.
// 7: local one variable for placement constant args optimized away/no improvement.
// 8: flags /O2 no-/Oy, /Ox, and /GX: same 416 B outcome.
// Left in scratch: behavior/call surface is modeled and early load order is close, but VC5 standalone keeps a 0x08 frame instead of original 0x0C and then broad branch/register displacement drift remains. Not accepted_drift-safe.
// This pass normalized the shared RGE_Command base and retested declaration
// order/self-alias context; output stayed at 405B/250 strict bytes, frame
// 0x08 versus 0x0C. Final candidate is natural and validated in scratch.
// Main-agent audit restored canonical polymorphic world/static/player/build
// ownership while retaining the ordinary placement/foundation branches.
// 9: ground-truth ABI pass changed command coordinates to float, IDs to RGE_Obj_Info, the player call to cancelBuild, the foundation call to make_new_obj, and the object call to do_command; size moved 405 -> 411 but the frame stayed 0x08.
// 10: nested the placement/pay/foundation arms to mirror the PDB line topology; it was slightly worse (407 B), so the natural early-return form remains authoritative.
// 11: tested int placementResult against the proven check_placement int* metadata; it regressed broadly and was rolled back to the binary-supported uchar local.
// 12-13: local declaration order and named command self alias were tested; emitted code was unchanged at 411 B/250 strict bytes.
// Current pause: canonical float/object/virtual surfaces and early-return behavior are modeled; remaining structural blocker is VC5's 0x08 standalone frame versus original 0x0C, shifting otherwise aligned stack homes by four bytes. Best output is 411/418 B, 10/10 ordered calls, CFG 12/12, 250 strict bytes.
// Main-agent audit removed the diagnostic command self-alias; direct member calls
// remain the canonical source even though the alias was codegen-neutral.
// Recovery: rebuilt the clean pinned source after the host crash; output stayed
// at 411/418 B and 250 strict bytes. No new evidence-backed structural lead
// remains, so this typed reconstruction stays in scratch.
// This pass recovered a distinct int placement output and uchar placement
// result. The adjacent local state reproduces the original 0x0C frame and
// exact pointer/result stack addresses, improving the clean result to 246
// strict bytes and 60.25% exact-block coverage. The canonical 0x14-byte
// command record with trailing RGE_Obj_Info records was codegen-neutral.
// Remaining drift is a 7-byte cancelBuild setup hunk: VC5 keeps count in EBX
// and emits one masked result load, while the original uses EAX/ECX and two
// result loads. No natural source change tested here recovered that basin.
// Ownership probe: the same-TU make_new_obj donor supports TRIBE_Master_Building_Object;
// its canonical hierarchy with the observed uchar placement ABI was codegen-neutral.
// The separate placement and placementResult locals retain the exact 0x0C frame.
// 17: the cancelBuild second argument is the check_placement int output, not count.
// The original reads that output from entry-relative stack home -8 in both calls.
// 18: separate int placement and uchar placementResult locals are exact at 418 B.
// Final: natural typed command/world ownership, call ABI, frame, CFG, and bytes match.
// Policy audit: replaced fake virtual-slot macros and the generic build type
// with the local RGE_Static_Object,
// RGE_Player, TRIBE_Player, and TRIBE_Master_Building_Object hierarchy.  The
// real slot names and layouts come from inventory/classes/dumps and
// inventory/types/dumps.  The clean source remains an exact 418-byte match.

typedef unsigned char uchar;

class RGE_Active_Sprite_List;
class RGE_Action_Object;
class RGE_Armor_Weapon_Info;
class RGE_Color_Table;
class RGE_Game_World;
class RGE_Map;
class RGE_Master_Combat_Object;
class RGE_Master_Static_Object;
class RGE_Object_List;
class RGE_Object_Node;
class RGE_Static_Object;
class RGE_Player;
class RGE_Player_Info;
class RGE_Scenario;
class RGE_Sound;
class RGE_Sprite;
class RGE_Task_List;
class TSound_Driver;
class TDrawArea;
class XYZBYTEPoint;
class RGE_Command_Give_Attribute;
class TCommunications_Handler;
struct _iobuf;
typedef _iobuf FILE;
struct RGE_Obj_Info {
    int id;
};

class RGE_Game_World {
public:
    virtual uchar data_load_world(FILE* file);
    virtual uchar data_load_terrain_tables(char* file);
    virtual uchar data_load_players(char* file);
    virtual uchar data_load_objects(char* file);
    virtual uchar data_load_sounds(char* file);
    virtual uchar data_load_color_tables(char* file);
    virtual uchar data_load_sprites(char* file);
    virtual void data_load_players_type(short type, short count, FILE* file);
    virtual void data_load_effects(char* file);
    virtual void data_load_map(char* a, char* b, char* c, char* d,
                               short e, short f, short g, RGE_Sound** sounds,
                               char* h);
    virtual void data_load_random_map(char* a, char* b, char* c, char* d);
    virtual uchar init_player_type(int type, short player, uchar flag);
    virtual uchar init_player(int player);
    virtual void load_player(int player, uchar type, short id);
    virtual void color_table_init(int count);
    virtual void terrain_tables_init(int count);
    virtual void init_sounds(int count, TSound_Driver* driver);
    virtual void init_sprites(int count);
    virtual void map_init(int count, TSound_Driver* driver);
    virtual void effects_init(int count);
    virtual void master_player_init(int count);
    virtual void command_init(int count, TCommunications_Handler* handler);
    virtual void world_init(int count, TSound_Driver* driver,
                            TCommunications_Handler* handler);
    virtual void setup_gaia();
    virtual void setup_players(RGE_Player_Info* info);
    virtual uchar new_random_game(RGE_Player_Info* info);
    virtual void save(int file);
    virtual void scenario_make_player(short id, uchar type, uchar civ,
                                      uchar computer, char* name);
    virtual void scenario_make_map(int file);
    virtual uchar load_scenario(RGE_Player_Info* info);
    virtual uchar load_scenario(char* file, RGE_Player_Info* info);
    virtual void load_scenario1(int file, RGE_Player_Info* info);
    virtual void load_scenario2(int file, RGE_Player_Info* info);
    virtual void load_scenario3(int file, RGE_Player_Info* info);
    virtual void load_scenario4(int file, RGE_Player_Info* info);
    virtual void load_scenario5(int file, RGE_Player_Info* info);
    virtual void load_scenario6(int file, RGE_Player_Info* info);
    virtual void load_scenario7(int file, RGE_Player_Info* info);
    virtual void load_scenario8(int file, RGE_Player_Info* info);
    virtual void logStatus(FILE* file, int mode);
    virtual ~RGE_Game_World();

    unsigned long world_time;
    unsigned long old_world_time;
    unsigned long world_time_delta;
    float timer;
    unsigned long old_time;
    float game_speed;
    uchar temp_pause;
    uchar game_state;
    uchar game_end_condition;
    uchar pad_1;
    long sound_update_index;
    long sprite_update_index;
    RGE_Map* map;
    short sound_num;
    uchar pad_2[2];
    RGE_Sound** sounds;
    short sprite_num;
    uchar pad_3[2];
    RGE_Sprite** sprites;
    short player_num;
    uchar pad_4[2];
    RGE_Player** players;
};

class RGE_Command {
public:
    virtual void do_command_give_attribute(RGE_Command_Give_Attribute* command);
    virtual ~RGE_Command();
    virtual void do_command(void* command);
    virtual void command_give_attribute(int player, int object, int attribute,
                                        float amount);

    RGE_Game_World* world;
    uchar* last_order;
    long last_order_size;
    long last_order_time;
    TCommunications_Handler* com_hand;

    RGE_Static_Object* get_obj(RGE_Obj_Info id);
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*,
                                    float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*);
    virtual void shadow_draw(TDrawArea*, short, short, uchar);
    virtual void normal_draw(TDrawArea*, short, short);
    virtual void draw_front_frame(TDrawArea*, short, short);
    virtual void draw_back_frame(TDrawArea*, short, short);
    virtual void draw_frame(TDrawArea*, short, short);
    virtual uchar update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int);
    virtual float teleport(float, float, float);
    virtual void new_sprite(RGE_Sprite*);
    virtual void add_overlay_sprite(RGE_Sprite*, uchar);
    virtual void remove_overlay_sprite(RGE_Sprite*);
    virtual void change_ownership(RGE_Player*);
    virtual void modify(float, uchar);
    virtual void modify_delta(float, uchar);
    virtual void modify_percent(float, uchar);
    virtual void transform(RGE_Master_Static_Object*);
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void set_object_state(uchar);
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();
    virtual void die_die_die();
    virtual void damage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*,
                        RGE_Static_Object*);
    virtual float calculateDamage(int, RGE_Armor_Weapon_Info*, float,
                                  RGE_Player*, RGE_Static_Object*);
    virtual void rotate(long);
    virtual uchar can_attack();
    virtual void set_attribute(short, float);
    virtual void set_attribute_amount(float, uchar, uchar);
    virtual int heal(int, int);
    virtual uchar heal(float);
    virtual int canRepair();
    virtual void notify_of_relation(long, uchar);
    virtual void do_command(RGE_Static_Object* foundation, float x, float y, float z);

    long id;
    void removeAllFromPathingGroup();
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(uchar);
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
                                                   uchar, float);
    virtual void scenario_save(int);
    virtual void scenario_load(int, long*, float);
    virtual void scenario_postsave(int);
    virtual void scenario_postload(int, long*, float);
    virtual void load(int);
    virtual void add_attribute_num(short, float, uchar);
    virtual void update();
    virtual void update_dopplegangers();
    virtual void save(int);
    virtual void save2(int);
    virtual void save_info(int);
    virtual void random_start();
    virtual RGE_Static_Object* make_new_object(long, float, float, float, int);
    virtual void analyize_selected_objects();
    virtual int get_mouse_pointer_action_vars(int, int*, int*);
    virtual uchar command_make_move(RGE_Static_Object*, float, float);
    virtual uchar command_make_work(RGE_Static_Object*, float, float);
    virtual uchar command_make_do(RGE_Static_Object*, float, float);
    virtual uchar command_stop();
    virtual uchar command_place_object(short, float, float, float);
    virtual uchar command_add_attribute(int, float);
    virtual uchar command_give_attribute(int, int, float);
    virtual uchar command_formation(int);
    virtual uchar command_stand_ground();
    virtual uchar command_create_group(int, int*, int, float);
    virtual uchar command_add_to_group(int, int, float);
    virtual uchar command_remove_from_group(int, int);
    virtual uchar command_destroy_group(int);
    virtual uchar command_resign(int, int);
    virtual uchar command_add_waypoint(float, float, float);
    virtual RGE_Object_Node* addObject(RGE_Static_Object*, int, int);
    virtual void removeObject(RGE_Static_Object*, int, int, RGE_Object_Node*);
    virtual void logMessage(char*);
    virtual void notify(int, int, int, long, long, long);
    virtual void logStatus(void*, int);
    virtual void load_victory(int, long*, uchar);
    virtual void new_victory();

    int computerPlayerValue;
    int pathingAttemptCapValue;
    int pathingDelayCapValue;
    int currentUpdatePathingAttemptsValue;
    long checksum;
    long position_checksum;
    long action_checksum;
    uchar checksum_created_this_update;
    uchar pad_1;
    short master_object_num;
    RGE_Master_Static_Object** master_objects;
    RGE_Object_List* objects;
    RGE_Object_List* sleeping_objects;
    RGE_Object_List* doppleganger_objects;
    void* victory_conditions;
    void* visible;
    RGE_Game_World* world;
    uchar pay_obj_cost(short obj_id, float amount, int flag);
};

class TRIBE_Player : public RGE_Player {
public:
    virtual ~TRIBE_Player();
    virtual uchar command_give_attribute(int, int, float, float);
    virtual void buildObject(int, int, float, float, int);
    virtual void cancelBuild(int, int, int, float, float, int, int);
    virtual void registerBuild(RGE_Static_Object*, int);
    virtual void trainUnit(int, int, int);
    virtual void cancelTrain(int, int, int, int);
    virtual void registerTrain(int, int, int, int);
    virtual void research(int, int, int);
    virtual void cancelResearch(int, int, int, int);
    virtual void registerResearch(int, int, int);
    virtual void taskTrader(int, int, int, float, float);
    virtual void taskResourceGatherer(int, int, int, float, float);
    virtual void notifyAI(int, int, int, long, long, long);
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void modify(float, uchar);
    virtual void modify_delta(float, uchar);
    virtual void modify_percent(float, uchar);
    virtual void save(int);
    virtual RGE_Static_Object* make_new_obj(RGE_Player*, float, float, float);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual uchar check_placement(RGE_Player*, float, float, int*, uchar, uchar,
                                  uchar, uchar, uchar, uchar);
    virtual uchar alignment(float*, float*, RGE_Game_World*, uchar);
    virtual long calc_base_damage_ability(RGE_Master_Combat_Object*);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*, long, long,
                      int, uchar);
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
};

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
};

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    virtual RGE_Task_List* create_task_list();
};

class RGE_Master_Combat_Object : public RGE_Master_Action_Object {
};

class TRIBE_Master_Combat_Object : public RGE_Master_Combat_Object {
};

class TRIBE_Master_Building_Object : public TRIBE_Master_Combat_Object {
public:
    virtual RGE_Static_Object* make_new_obj(RGE_Player*, float, float, float,
                                            int);
};

struct TRIBE_Command_Build {
    uchar command;
    uchar count;
    uchar player_id;
    uchar pad3;
    float x;
    float y;
    short obj_id;
    short padE;
    int unique_id;
};

class TRIBE_Command : public RGE_Command {
public:
    void do_command_build(TRIBE_Command_Build* cmd);
};

void TRIBE_Command::do_command_build(TRIBE_Command_Build* cmd)
{
    RGE_Static_Object* blockingObject;
    int placement;
    uchar placementResult;
    int count = cmd->count;
    RGE_Static_Object* obj;

    TRIBE_Player* player = (TRIBE_Player*)this->world->players[cmd->player_id];
    if (player == 0) {
        return;
    }
    if (cmd->obj_id == -1) {
        return;
    }

    TRIBE_Master_Building_Object* info =
        (TRIBE_Master_Building_Object*)player->master_objects[cmd->obj_id];
    if (info == 0) {
        return;
    }

    placementResult = info->check_placement(player, cmd->x, cmd->y,
                                            &placement,
                                            1, 1, 1, 1, 1, 1);
    if (placementResult != 0) {
        if (count > 0) {
            obj = this->get_obj(*(RGE_Obj_Info*)(cmd + 1));
            if (obj != 0) {
                player->cancelBuild(placementResult, placement,
                                    cmd->obj_id, cmd->x, cmd->y, cmd->unique_id,
                                    obj->id);
            }
        }
        return;
    } else {

    if (!player->pay_obj_cost(cmd->obj_id, 1.0f, 0)) {
        if (count <= 0) {
            return;
        }
        obj = this->get_obj(*(RGE_Obj_Info*)(cmd + 1));
        if (obj == 0) {
            return;
        }
        player->cancelBuild(0, placement, cmd->obj_id,
                            cmd->x, cmd->y, cmd->unique_id, obj->id);
        return;
    }

    blockingObject = info->make_new_obj(player, cmd->x, cmd->y, 0,
                                        cmd->unique_id);
    if (count <= 0) {
        return;
    }

    RGE_Obj_Info* idp = (RGE_Obj_Info*)(cmd + 1);
    int n = count;
    do {
        obj = this->get_obj(*idp);
        if (obj != 0) {
            obj->removeAllFromPathingGroup();
            obj->do_command(blockingObject, cmd->x, cmd->y, 0.0f);
        }
        ++idp;
        --n;
    } while (n != 0);
    }
}
