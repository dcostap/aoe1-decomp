// VA: 00526170 TRIBE_Game::load_game (3152 bytes)
// PDB source: tribegam.cpp:2787-3184
//
// Baseline reconstruction: restore the load transition first. The source uses
// named game, panel, world, communications, player, action, and path surfaces.
//
// Attempt log:
// - Baseline matched the initial panel, input, loading status, world load, and
//   failure transition, but omitted most DEBUGLOAD diagnostics.
// - Added the three saved object-list traversals, victory points, and path
//   waypoint logging from the executable evidence. This moved the size and
//   call set closer, but the debug block still has unresolved source shape.
// - Corrected world virtual slots so turn_sound_off is +0xB8 and load_game is
//   +0xCC. Object update is modeled through the proven +0x1D0 slot.
// - Duplicated the natural load_game_data failure guard to follow the first
//   unmatched panelname call sequence. VC5 folded it into the existing tail;
//   emitted code and structural metrics did not change.
// - Remaining blocker: DEBUGLOAD has 21 fprintf calls, six waypoint scans,
//   and compiler-generated floating conversion calls. The natural typed draft
//   has 13 fprintf calls and a smaller frame. Leave this target paused.
// - Replaced the action-list draft with the proven object lists, typed object
//   checksum calls, target lookup, nested action logs, and path scans. This
//   restored all 97 call sites and moved the frame to 0x2EC.
// - Reused one pathFinding result and the named fn local. The latter restored
//   the 260-byte filename home and moved the frame within eight bytes.
// - Moved shared panel recovery before the success path. All branch calls now
//   have the original order; remaining drift is local scheduling and layout.
// - Restored object master-id and world-position checksum accumulation. This
//   produced 12.69% exact-block coverage and a 52-byte size gap.
// - Tried preloading action log fields before direct calls; it crossed the
//   original boundary and was rolled back.
// - BINARY NOTE: the loading flag is at sound_system +1 through this +0x60;
//   comm_handler remains at this +0x18C for player-name calls.
// - BINARY NOTE: load_game's byte result is widened to int, then the reset
//   loop rereads world->player_num on each backedge.
// - BINARY NOTE: DEBUGLOAD packs num3, num2, action_checksum, and num1 into
//   one checksum before it updates the two totals.
// - BINARY NOTE: the Gaia player pointer is at world +0x28. Read it again for
//   each visibility flag instead of indexing the player array.
// - BINARY NOTE: master object id is at +0x10. The +0x0C field is padding.
// - BINARY NOTE: object scans reload list->object after checksum calls. Keep
//   direct list->object expressions instead of one long-lived object alias.
// - BINARY NOTE: separate position additions recover the original x87 order.
// - BINARY NOTE: path logs pass continue_counter before number_wait_delays.
// - Unresolved: exact codegen still differs. The first mismatch is the
//   old-panel and this-pointer home assignment at +0x1B.

#include <stdio.h>
#include <string.h>

extern "C" char* __cdecl TRIBE_mbschr(const char* text, int character);
extern "C" int numberPathingIterations;
extern int ENABLE_COMPRESSION;

#ifndef TRIBEGAM_TU_CONTEXT
class TPanel {
public:
    char* panelName();
};

class TPanelSystem {
public:
    TPanel* currentPanel();
    int setCurrentPanel(char* name, int mode);
    int destroyPanel(char* name);
};

extern TPanelSystem panel_system;

class TCommunications_Handler {
public:
    char gap_00;
    unsigned char game_loading;
    void SetPlayerName(int player, char* name);
    void SetPlayerHumanity(int player, int humanity);
};

class TSound_System {
public:
    char gap_00;
    unsigned char game_loading;
};

#endif

class RGE_Victory_Conditions {
public:
    long get_victory_points();
};

class Waypoint {
public:
    float x;
    float y;
    float z;
    unsigned char facetToNextWaypoint;
    char gap_0D[3];
};

class Path {
public:
    char gap_00[0x34];
    int numberOfWaypoints();
    void initToStart();
    Waypoint* currentWaypoint();
    void moveToNextWaypoint();
};

class RGE_Action {
public:
    char gap_00[4];
    short action_type;
    char gap_06[2];
    void* object;
    unsigned char state;
    char gap_0D[3];
    void* target_obj;
    void* target_obj2;
    int target_id;
    int target2_id;
    float target_x;
    float target_y;
    float target_z;
    float timer;
    void* task;
    void* sub_actions;
    void* sprite;
    unsigned char sub_action_value;
    char gap_3D[3];

    unsigned char subAction();
    float targetZ();
    float targetY();
    float targetX();
};

class RGE_Action_Node {
public:
    RGE_Action* action;
    RGE_Action_Node* next;
};

class RGE_Action_List {
public:
    char gap_00[8];
    RGE_Action_Node* list;
};

class RGE_Static_Object;
class RGE_Player;
class RGE_Master_Static_Object {
public:
    char gap_00[4];
    unsigned char object_type;
    char gap_05[3];
    char* name;
    char gap_0C[4];
    short id;
    short copy_id;
};

class RGE_Object_Node {
public:
    RGE_Static_Object* object;
    RGE_Object_Node* next;
};

class RGE_Object_List {
public:
    char gap_00[4];
    RGE_Object_Node* list;
    short number;
    char gap_0A[2];
};

#ifndef TRIBEGAM_TU_CONTEXT
class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game();
    virtual void recycle_out_of_game();
    virtual void draw();
    virtual void shadow_draw();
    virtual void normal_draw();
    virtual void draw_front_frame();
    virtual void draw_back_frame();
    virtual void draw_frame();
    virtual unsigned char update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int file);
    virtual float teleport(float x, float y, float z);
    virtual void new_sprite();
    virtual void add_overlay_sprite(unsigned char value);
    virtual void remove_overlay_sprite();
    virtual void change_ownership(RGE_Player* player);
    virtual void modify(float value, unsigned char type);
    virtual void modify_delta(float value, unsigned char type);
    virtual void modify_percent(float value, unsigned char type);
    virtual void transform();
    virtual void copy_obj();
    virtual void set_object_state(unsigned char state);
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();
    virtual void die_die_die();
    virtual void damage();
    virtual float calculateDamage();
    virtual void rotate(long angle);
    virtual unsigned char can_attack();
    virtual void set_attribute(short attr, float value);
    virtual void set_attribute_amount(float amount, unsigned char attr,
                                      unsigned char type);
    virtual int heal(int amount, int type);
    virtual unsigned char heal(float amount);
    virtual int canRepair();
    virtual void notify_of_relation(long player, unsigned char relation);
    virtual void do_command(RGE_Static_Object* object, float x, float y,
                            float z);
    virtual void move_to(RGE_Static_Object* object, float x, float y,
                         float z);
    virtual void work(RGE_Static_Object* object, float x, float y, float z);
    virtual void stop();
    virtual void set_attack(RGE_Static_Object* object);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void new_angle(float angle);
    virtual RGE_Static_Object* spawn_death_obj();
    virtual void* get_command_master();
    virtual void set_being_worked_on();
    virtual void release_being_worked_on(RGE_Static_Object* object);
    virtual unsigned char is_moving();
    virtual RGE_Static_Object* get_target_obj(); // +CC
    virtual void enter_obj(RGE_Static_Object* object);
    virtual void exit_obj();
    virtual int explore_terrain();
    virtual void unexplore_terrain();
    virtual void* get_los_table();
    virtual int inAttackRange(RGE_Static_Object* object);
    virtual unsigned char underAttack();
    virtual void setUnderAttack(unsigned char value);
    virtual float calc_attack_modifier(RGE_Static_Object* object);
    virtual float getSpeed();
    virtual float getAngle();
    virtual float maximumSpeed();
    virtual float rateOfFire();
    virtual float damageCapability(RGE_Static_Object* object);
    virtual float damageCapability();
    virtual float weaponRange();
    virtual float minimumWeaponRange();
    virtual int passableTile(float x, float y, int value);
    virtual unsigned char facetToNextWaypoint();
    virtual int currentTargetID();
    virtual float currentTargetX();
    virtual float currentTargetY();
    virtual float currentTargetZ();
    virtual void setWaitingToMove(unsigned char value);
    virtual unsigned char waitingToMove();
    virtual unsigned char actionState();
    virtual unsigned char keepGatheringWhenObjectIsOut(int value);
    virtual unsigned char produceWhenKilledBy(int value);
    virtual unsigned char useSameZoneDropsite();
    virtual void logDebug(const char* format, ...);
    virtual void notify(int a, int b, int c, long d, long e, long f);
    virtual int attack(float x, float y, float z, int value);
    virtual int attack(int target, int value);
    virtual int moveTo(float x, float y, float z, float speed, int value);
    virtual int moveTo(int target, float speed, int value);
    virtual int moveTo(int target, int value);
    virtual int moveAwayFrom(int target, int value);
    virtual int hunt(int target, int value);
    virtual int gather(int target, int value);
    virtual int convert(int target, int value);
    virtual int repair(int target, int value);
    virtual int build(int target, int value);
    virtual int trade(int target, int value);
    virtual int explore(int target, int value, int type);
    virtual int enter(int target, int value);
    virtual int unload(int target, float x, float y, float z);
    virtual int transport(float x, float y, float z, int target);
    virtual int stopAction();
    virtual int pause();
    virtual int canPath(int target, float value, float* result,
                        int a, int b, int c);
    virtual int canPath(void* point, float value, int target, float* result,
                        int a, int b, int c);
    virtual int canBidirectionPath(int a, int b, float value, float* result,
                                   int c, int d, int e);
    virtual int canPathWithObstructions(int target, float value, float* result,
                                        int a, int b, int c, void* data);
    virtual int canPathWithAdditionalPassability(
        void* point, float value, int target, float* result,
        int a, int b, int c, int d, int e);
    virtual int findFirstTerrainAlongExceptionPath(int target, float* x,
                                                   float* y);
    virtual int canLinePath(int a, int b, int c, int d, float value, int e);
    virtual int canLinePath(void* first, void* second, float value,
                            void* third, int value2);
    virtual int firstTileAlongLine(void* first, void* second, void* third,
                                   int a, int b, int c);
    virtual void* userDefinedWaypoint(int index);
    virtual int addUserDefinedWaypoint(void* point, int index);
    virtual void removeAllUserDefinedWaypoints(int value);
    virtual void removeUserDefinedWaypoint(int value);
    virtual int numberUserDefinedWaypoints();
    virtual void* findAvoidancePath(void* point, float value, int target);
    virtual long get_action_checksum(); // +1D0
    long id; // +4
    RGE_Master_Static_Object* master_obj; // +8
    RGE_Player* owner; // +C
    char gap_10[0x28];
    float world_x; // +38
    float world_y; // +3C
    float world_z; // +40
    float attribute_amount_held; // +44
    unsigned char object_state; // +48
    unsigned char sleep_flag; // +49
    unsigned char dopple_flag; // +4A
    unsigned char goto_sleep_flag; // +4B
    short attribute_type_held; // +4C
    unsigned char object_type; // +4E
    unsigned char worker_num; // +4F
    char gap_50[0x38];
};
#endif

class RGE_Moving_Object : public RGE_Static_Object {
public:
    char gap_88[0x1C];
    Path path; // +A4
    Path exception_path; // +D8
    Waypoint start; // +10C
    Waypoint goal; // +11C
    float turn_timer; // +12C
    float collision_avoidance_distance; // +130
    float action_range; // +134
    int target_id; // +138
    float target_radius_x; // +13C
    float target_radius_y; // +140
    int continue_counter; // +144
    char gap_148[0x0E];
    unsigned char number_wait_delays; // +156
    char gap_157[0x29];
};

class RGE_Action_Object : public RGE_Moving_Object {
public:
    unsigned char waiting;
    char gap_181[3];
    RGE_Action_List* action_list; // +184
};

class RGE_Doppleganger_Object : public RGE_Static_Object {
public:
    char gap_88[0x0C];
    RGE_Master_Static_Object* doppled_master_obj; // +94
    char gap_98[0x0C];
    Path path; // +A4
    Path exception_path; // +D8
    Waypoint start; // +10C
    Waypoint goal; // +11C
    float turn_timer; // +12C
    float collision_avoidance_distance; // +130
    float action_range; // +134
    int target_id; // +138
    float target_radius_x; // +13C
    float target_radius_y; // +140
    int continue_counter; // +144
    char gap_148[0x0E];
    unsigned char number_wait_delays; // +156
    char gap_157[0x29];
    unsigned char waiting; // +180
    char gap_181[3];
    RGE_Action_List* action_list; // +184
};

#ifndef TRIBEGAM_TU_CONTEXT
class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x24];
    RGE_Object_List* objects; // +28
    RGE_Object_List* sleeping_objects; // +2C
    RGE_Object_List* doppleganger_objects; // +30
    RGE_Victory_Conditions* victory_conditions; // +34
    char gap_38[0x0C];
    char* name; // +44
    unsigned char type; // +48
    char gap_49[1];
    short id; // +4A
    short attribute_num; // +4C
    char gap_4E[2];
    float* attributes; // +50
    char gap_54[0xB1];
    unsigned char civilization; // +105
    char gap_106[0x8CB2];
    unsigned char full_visibility; // +8DB8
    unsigned char fog_of_war; // +8DB9
    char* player_name();
};
#endif

#ifndef TRIBEGAM_TU_CONTEXT
struct RGE_Player_Info;
class RGE_Sound;
class TSound_Driver;
class RGE_Scenario;
class RGE_Game_World {
public:
    virtual unsigned char data_load_world(void* file);
    virtual unsigned char data_load_terrain_tables(char* name);
    virtual unsigned char data_load_players(char* name);
    virtual unsigned char data_load_objects(char* name);
    virtual unsigned char data_load_sounds(char* name);
    virtual unsigned char data_load_color_tables(char* name);
    virtual unsigned char data_load_sprites(char* name);
    virtual void data_load_players_type(short player, short type, void* file);
    virtual void data_load_effects(char* name);
    virtual void data_load_map(char* map, char* terrain, char* effect,
                               char* random, short width, short height,
                               short tile_set, RGE_Sound** sounds,
                               char* name);
    virtual void data_load_random_map(char* map, char* terrain,
                                      char* effect, char* random);
    virtual unsigned char init_player_type(int player, short type,
                                           unsigned char active);
    virtual unsigned char init_player(int player);
    virtual void load_player(int player, unsigned char type, short id);
    virtual void color_table_init(int table);
    virtual void terrain_tables_init(int table);
    virtual void init_sounds(int count, TSound_Driver* driver);
    virtual void init_sprites(int count);
    virtual void map_init(int count, TSound_Driver* driver);
    virtual void effects_init(int count);
    virtual void master_player_init(int count);
    virtual void command_init(int count, TCommunications_Handler* comm);
    virtual void world_init(int count, TSound_Driver* driver,
                            TCommunications_Handler* comm);
    virtual void setup_gaia();
    virtual void setup_players(RGE_Player_Info* info);
    virtual unsigned char new_random_game(RGE_Player_Info* info);
    virtual void save(int file);
    virtual void scenario_make_player(short player, unsigned char active,
                                      unsigned char type, unsigned char civ,
                                      char* name);
    virtual void scenario_make_map(int map);
    virtual unsigned char load_scenario(RGE_Player_Info* info);
    virtual unsigned char load_scenario(char* name, RGE_Player_Info* info);
    virtual void load_scenario1(int player, RGE_Player_Info* info);
    virtual void load_scenario2(int player, RGE_Player_Info* info);
    virtual void load_scenario3(int player, RGE_Player_Info* info);
    virtual void load_scenario4(int player, RGE_Player_Info* info);
    virtual void load_scenario5(int player, RGE_Player_Info* info);
    virtual void load_scenario6(int player, RGE_Player_Info* info);
    virtual void load_scenario7(int player, RGE_Player_Info* info);
    virtual void load_scenario8(int player, RGE_Player_Info* info);
    virtual void logStatus(void* file, int verbose);
    virtual ~RGE_Game_World();
    virtual void setup_player_colors();
    virtual void setup_player_colors(RGE_Player_Info* info);
    virtual unsigned char data_load(char* first, char* second);
    virtual unsigned char init(char* name, TSound_Driver* driver,
                               TCommunications_Handler* comm);
    virtual void turn_sound_off();
    virtual void del_game_info();
    virtual unsigned char update();
    virtual unsigned char get_game_state();
    virtual unsigned char check_game_state();
    virtual unsigned char load_world(int file);
    virtual unsigned char load_game(char* file_name);
    virtual unsigned char new_game(RGE_Player_Info* info, int flags);
    virtual unsigned char new_scenario(RGE_Player_Info* info, int flags);
    virtual unsigned char save_game(char* name);
    virtual void base_save(char* name);
    virtual void base_save(int file);
    virtual unsigned char save_scenario(char* name);
    virtual RGE_Scenario* get_scenario_info(char* name);
    virtual void pause(unsigned char value);
    virtual void scenario_init(RGE_Game_World* world);
    virtual void scenario_init(int file, RGE_Game_World* world);

    int world_time; // +4
    int old_world_time; // +8
    char gap_0C[0x0C];
    float game_speed; // +18
    char gap_1C[0x0C];
    RGE_Player* player_zero; // +28
    char gap_2C[0x10];
    short player_num; // +3C
    char gap_3E[2];
    RGE_Player** players; // +40
};
#endif

#ifndef TRIBEGAM_TU_CONTEXT
class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_04[0x5C];
    TSound_System* sound_system; // +0x60
    char gap_64[0x128];
    TCommunications_Handler* comm_handler; // +18C
    char gap_190[0x20];
    int prog_mode; // +1B0
    char gap_1B4[0x240];
    RGE_Game_World* world; // +3F4
    char gap_3F8[0x62C];

    void disable_input();
    void enable_input();
    unsigned char check_prog_argument(char* argument);
    unsigned char pathFinding();
    void setFullVisibility(int value);
    void setFogOfWar(int value);
    void setAllowCheatCodes(int value);
    void setSavedGame(int value);
    void setNumberPlayers(int value);
    void setPlayerID(int player, int id);
    void reset_countdown_timer(int player);
};
#endif

#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game : public RGE_Base_Game {
public:
    char gap_A24[0x200];
    void* game_screen; // +C24
    char gap_C28[0x628];
    int inHandleIdle; // +1250

    void show_status_message(int string_id, char* param, long value);
    int load_game_data();
    void close_status_message();
    void close_game_screens(int destroy_game_screen);
    int create_game_screen();
    void set_save_game_name(char* name);
    void set_load_game_name(char* name);
    int playerColor(int player);
    int load_game(char* file_name);
};
#endif

int TRIBE_Game::load_game(char* file_name)
{
    TPanel* old_panel;
    int loaded;
    RGE_Object_Node* list;
    RGE_Action_Node* act_node;
    long action_checksum;
    long num2;
    long num3;
    float temp_position_checksum;
    int i;
    long total_action_checksum;
    long total_checksum;
    long checksum;
    long num1;
    long num4;
    char target_name_1[50];
    char target_name_2[50];
    char target_name[50];
    char fileNameNoExt[260];
    char fn[260];

    this->inHandleIdle = 0;
    old_panel = panel_system.currentPanel();
    this->disable_input();

    if (this->prog_mode == 4 || this->prog_mode == 6 ||
        this->prog_mode == 5) {
        this->world->turn_sound_off();
        this->prog_mode = 0;
        this->game_screen = 0;
        panel_system.destroyPanel("Game Screen");
    }

    this->show_status_message(0x44D, 0, -1);
    if (this->load_game_data() == 0) {
        if (old_panel == 0 || old_panel->panelName() == 0)
            goto load_game_failed;
        if (*old_panel->panelName() == 0)
            goto load_game_failed;
        goto load_game_panel;
    }

    this->show_status_message(0x452, 0, -1);
    if (this->sound_system != 0)
        this->sound_system->game_loading = 1;

    if (this->check_prog_argument("DEBUGSAVEGAME") != 0)
        ENABLE_COMPRESSION = 0;

    loaded = this->world->load_game(file_name);
    for (i = 0; i < this->world->player_num; ++i) {
        this->reset_countdown_timer(i);
    }

    ENABLE_COMPRESSION = 1;
    if (this->sound_system != 0)
        this->sound_system->game_loading = 0;

    if (loaded == 0) {
        if (old_panel == 0 || old_panel->panelName() == 0)
            goto load_game_failed;
        if (*old_panel->panelName() == 0)
            goto load_game_failed;
        goto load_game_panel;
    }
    goto load_game_success;

load_game_panel:
    panel_system.setCurrentPanel(old_panel->panelName(), 0);
    panel_system.destroyPanel("Status Screen");
    this->enable_input();
    return 0;

load_game_failed:
    this->close_status_message();
    this->enable_input();
    return 0;

load_game_success:
    {
        this->setFullVisibility(
            this->world->player_zero->full_visibility);
        this->setFogOfWar(
            this->world->player_zero->fog_of_war);
        this->setAllowCheatCodes(1);
        this->setSavedGame(1);
        this->setNumberPlayers(this->world->player_num - 1);

        loaded = this->pathFinding();
        switch (loaded) {
        case 1:
            numberPathingIterations = 5000;
            break;
        case 2:
            numberPathingIterations = 0x1D4C;
            break;
        default:
            numberPathingIterations = 0x9C4;
            break;
        }

        for (i = 0; i < 9; ++i) {
            if (i < this->world->player_num) {
                this->setPlayerID(i, i);
                if (i > 0) {
                    this->comm_handler->SetPlayerName(
                        i, this->world->players[i]->name);
                    if (i == 1)
                        this->comm_handler->SetPlayerHumanity(i, 2);
                    else
                        this->comm_handler->SetPlayerHumanity(i, 4);
                } else {
                    this->comm_handler->SetPlayerHumanity(i, 0);
                }
            } else {
                this->setPlayerID(i, 0);
                this->comm_handler->SetPlayerHumanity(i, 0);
            }
        }

        strcpy(fn, file_name);
        char* dot = TRIBE_mbschr(fn, '.');
        if (dot != 0)
            *dot = 0;
        this->set_save_game_name(fn);
        this->set_load_game_name(fn);

        if (this->check_prog_argument("DEBUGLOAD") != 0) {
            sprintf(fileNameNoExt + 0x100, "c:\\%s.txt", fn);
            FILE* debug_file = fopen(fileNameNoExt + 0x100, "w");
            if (debug_file != 0) {
                total_action_checksum = 0;
                total_checksum = 0;
                fprintf(debug_file, "world_time=%u\n", this->world->world_time);
                fprintf(debug_file, "old_world_time=%u\n",
                        this->world->old_world_time);
                fprintf(debug_file, "game_speed %6.2f\n",
                        (double)this->world->game_speed);

                for (i = 0; i < this->world->player_num; ++i) {
                    RGE_Player* player = this->world->players[i];
                    long victory_points = 0;
                    if (player->victory_conditions != 0)
                        victory_points =
                            player->victory_conditions->get_victory_points();
                    fprintf(debug_file,
                            "player %d, civ=%d, score=%d, %s\n",
                            i, player->civilization, victory_points,
                            player->name);
                    fprintf(debug_file, "  Writing=%f\n",
                            (double)player->attributes[200]);
                    fprintf(debug_file, "  num_sleep_obj=%d\n",
                            player->sleeping_objects == 0 ? 0 :
                                player->sleeping_objects->number);
                    fprintf(debug_file, "  num_dopple_obj=%d\n",
                            player->doppleganger_objects == 0 ? 0 :
                                player->doppleganger_objects->number);

                    action_checksum = 0;
                    num1 = 0;
                    temp_position_checksum = 0.0f;
                    num3 = player->sleeping_objects->number +
                        player->doppleganger_objects->number + player->id;
                    num4 = 0;
                    while (num4 < player->attribute_num) {
                        num1 += (int)player->attributes[num4];
                        fprintf(debug_file, "  p#%d attr[%d]=%12.8f\n",
                                player->id, num4,
                                (double)player->attributes[num4]);
                        ++num4;
                    }
                    num2 = 0;
                    list = player->objects->list;
                    while (list != 0) {
                            int attribute_value =
                                (int)list->object->attribute_amount_held;
                            num1 += list->object->object_state + attribute_value;
                            ++num2;
                            num3 += list->object->master_obj->id + num2 +
                                list->object->object_state + attribute_value;
                            temp_position_checksum += list->object->world_x;
                            temp_position_checksum += list->object->world_y;
                            temp_position_checksum += list->object->world_z;
                            action_checksum += list->object->get_action_checksum();
                            RGE_Static_Object* target =
                                list->object->get_target_obj();
                            if (target != 0) {
                                target_name_1[0] = 0;
                                strcpy(target_name_1, target->master_obj->name);
                                num4 = target->id;
                            } else {
                                target_name_1[0] = 0;
                                num4 = -1;
                            }
                            fprintf(debug_file,
                                    "  p#%d ob=%d (%s), st=%d, at=%8.4f, pos=%6.2f,%6.2f,%6.2f, tar=%d (%s)\n",
                                    player->id, list->object->id,
                                    list->object->master_obj->name,
                                    list->object->object_state,
                                    (double)list->object->attribute_amount_held,
                                    (double)list->object->world_x,
                                    (double)list->object->world_y,
                                    (double)list->object->world_z,
                                    num4, target_name_1);

                            RGE_Action_Object* moving_object =
                                (RGE_Action_Object*)list->object;
                            if (list->object->master_obj->object_type >= 0x1E &&
                                list->object->master_obj->object_type != 0x5A) {
                                Path* path = &moving_object->path;
                                if (path->numberOfWaypoints() > 0) {
                                    path->initToStart();
                                    fprintf(debug_file,
                                            "    path: s=%6.2f,%6.2f,%6.2f,g=%6.2f,%6.2f,%6.2f,cc=%d,wd=%d\n",
                                            (double)moving_object->start.x,
                                            (double)moving_object->start.y,
                                            (double)moving_object->start.z,
                                            (double)moving_object->goal.x,
                                            (double)moving_object->goal.y,
                                            (double)moving_object->goal.z,
                                            moving_object->continue_counter,
                                            moving_object->number_wait_delays);
                                    int waypoint_index = 0;
                                    int waypoint_count =
                                        path->numberOfWaypoints();
                                    while (waypoint_index < waypoint_count) {
                                        unsigned char facet =
                                            path->currentWaypoint()->facetToNextWaypoint;
                                        double y =
                                            path->currentWaypoint()->y;
                                        double x =
                                            path->currentWaypoint()->x;
                                        fprintf(debug_file,
                                                "        w%i=%6.2f,%6.2f,%d\n",
                                                waypoint_index, x, y, facet);
                                        ++waypoint_index;
                                        path->moveToNextWaypoint();
                                        waypoint_count =
                                            path->numberOfWaypoints();
                                    }
                                    path->initToStart();
                                    path->moveToNextWaypoint();
                                }
                            }

                            if (list->object->master_obj->object_type >= 0x28 &&
                                list->object->master_obj->object_type != 0x5A) {
                                act_node = moving_object->action_list->list;
                                while (act_node != 0) {
                                    RGE_Action* action = act_node->action;
                                    if (action != 0) {
                                        fprintf(debug_file,
                                                "    action: typ=%d, st=%d, tar1=%d, tar2=%d, tp=%6.2f,%6.2f,%6.2f, subac=%d, tim=%6.2f\n",
                                                action->action_type,
                                                action->state,
                                                action->target_id,
                                                action->target2_id,
                                                (double)action->targetX(),
                                                (double)action->targetY(),
                                                (double)action->targetZ(),
                                                (int)action->subAction(),
                                                (double)action->timer);
                                    }
                                    act_node = act_node->next;
                                }
                            }
                        list = list->next;
                    }

                    list = player->sleeping_objects->list;
                    while (list != 0) {
                            int attribute_value =
                                (int)list->object->attribute_amount_held;
                            num1 += list->object->object_state + attribute_value;
                            ++num2;
                            num3 += list->object->master_obj->id + num2 +
                                list->object->object_state + attribute_value;
                            temp_position_checksum += list->object->world_x;
                            temp_position_checksum += list->object->world_y;
                            temp_position_checksum += list->object->world_z;
                            action_checksum += list->object->get_action_checksum();
                            RGE_Doppleganger_Object* dopple =
                                (RGE_Doppleganger_Object*)list->object;
                            RGE_Static_Object* target =
                                list->object->get_target_obj();
                            if (target != 0) {
                                target_name_2[0] = 0;
                                strcpy(target_name_2, target->master_obj->name);
                                num4 = target->id;
                            } else {
                                target_name_2[0] = 0;
                                num4 = -1;
                            }
                            fprintf(debug_file,
                                    "  p#%d ob=%d (%s), st=%d, at=%8.4f, pos=%6.2f,%6.2f,%6.2f, tar=%d (%s)\n",
                                    player->id, list->object->id,
                                    list->object->master_obj->name,
                                    list->object->object_state,
                                    (double)list->object->attribute_amount_held,
                                    (double)list->object->world_x,
                                    (double)list->object->world_y,
                                    (double)list->object->world_z,
                                    num4, target_name_2);
                            if (dopple->doppled_master_obj != 0)
                                fprintf(debug_file,
                                        "    Doppled master obj:  %s, %d.\n",
                                        dopple->doppled_master_obj->name,
                                        dopple->doppled_master_obj->object_type);
                            else
                                fprintf(debug_file,
                                        "    NULL doppled master obj.\n");

                            if (list->object->master_obj->object_type >= 0x1E &&
                                list->object->master_obj->object_type != 0x5A) {
                                Path* path = &dopple->path;
                                if (path->numberOfWaypoints() > 0) {
                                    path->initToStart();
                                    fprintf(debug_file,
                                            "    path: s=%6.2f,%6.2f,%6.2f,g=%6.2f,%6.2f,%6.2f,cc=%d,wd=%d\n",
                                            (double)dopple->start.x,
                                            (double)dopple->start.y,
                                            (double)dopple->start.z,
                                            (double)dopple->goal.x,
                                            (double)dopple->goal.y,
                                            (double)dopple->goal.z,
                                            dopple->continue_counter,
                                            dopple->number_wait_delays);
                                    int waypoint_index = 0;
                                    int waypoint_count =
                                        path->numberOfWaypoints();
                                    while (waypoint_index < waypoint_count) {
                                        unsigned char facet =
                                            path->currentWaypoint()->facetToNextWaypoint;
                                        double y =
                                            path->currentWaypoint()->y;
                                        double x =
                                            path->currentWaypoint()->x;
                                        fprintf(debug_file,
                                                "        w%i=%6.2f,%6.2f,%d\n",
                                                waypoint_index, x, y, facet);
                                        ++waypoint_index;
                                        path->moveToNextWaypoint();
                                        waypoint_count =
                                            path->numberOfWaypoints();
                                    }
                                    path->initToStart();
                                    path->moveToNextWaypoint();
                                }
                            }

                            if (list->object->master_obj->object_type >= 0x28 &&
                                list->object->master_obj->object_type != 0x5A) {
                                act_node = dopple->action_list->list;
                                while (act_node != 0) {
                                    RGE_Action* action = act_node->action;
                                    if (action != 0) {
                                        fprintf(debug_file,
                                                "    action: typ=%d, st=%d, tar1=%d, tar2=%d, tp=%6.2f,%6.2f,%6.2f, subac=%d, tim=%6.2f\n",
                                                action->action_type,
                                                action->state,
                                                action->target_id,
                                                action->target2_id,
                                                (double)action->targetX(),
                                                (double)action->targetY(),
                                                (double)action->targetZ(),
                                                (int)action->subAction(),
                                                (double)action->timer);
                                    }
                                    act_node = act_node->next;
                                }
                            }
                        list = list->next;
                    }

                    list = player->doppleganger_objects->list;
                    while (list != 0) {
                            RGE_Static_Object* target =
                                list->object->get_target_obj();
                            if (target != 0) {
                                target_name[0] = 0;
                                strcpy(target_name, target->master_obj->name);
                                num4 = target->id;
                            } else {
                                target_name[0] = 0;
                                num4 = -1;
                            }
                            fprintf(debug_file,
                                    "  p#%d ob=%d (%s), st=%d, at=%8.4f, pos=%6.2f,%6.2f,%6.2f, tar=%d (%s)\n",
                                    player->id, list->object->id,
                                    list->object->master_obj->name,
                                    list->object->object_state,
                                    (double)list->object->attribute_amount_held,
                                    (double)list->object->world_x,
                                    (double)list->object->world_y,
                                    (double)list->object->world_z,
                                    num4, target_name);
                        list = list->next;
                    }

                    checksum = (((num3 * 0x100 + num2) * 0x100 +
                                 action_checksum) * 0x100) + num1;
                    total_action_checksum += checksum;
                    total_checksum += action_checksum;
                    fprintf(debug_file,
                            "  p#%d checksum=%d, 1=%d, 2=%d, 3=%d, 4=%d, act=%d\n",
                            player->id, checksum, num1, action_checksum, num2,
                            num3, action_checksum);
                }

                fprintf(debug_file, "total checksum=%d, act=%d\n",
                        total_checksum, total_action_checksum);
                fclose(debug_file);
            }
        }

        this->close_game_screens(0);
        return this->create_game_screen();
    }
}
