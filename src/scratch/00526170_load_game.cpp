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

#include <stdio.h>
#include <string.h>

extern "C" char* __cdecl _mbschr(const char* text, int character);
extern "C" int numberPathingIterations;
extern int ENABLE_COMPRESSION;

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

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
#define OBJ_VPAD1(n) virtual void obj_v##n();
#define OBJ_VPAD2(n) OBJ_VPAD1(n) OBJ_VPAD1(n##_1)
#define OBJ_VPAD4(n) OBJ_VPAD2(n) OBJ_VPAD2(n##_2)
#define OBJ_VPAD8(n) OBJ_VPAD4(n) OBJ_VPAD4(n##_4)
#define OBJ_VPAD16(n) OBJ_VPAD8(n) OBJ_VPAD8(n##_8)
#define OBJ_VPAD32(n) OBJ_VPAD16(n) OBJ_VPAD16(n##_16)
#define OBJ_VPAD64(n) OBJ_VPAD32(n) OBJ_VPAD32(n##_32)
    OBJ_VPAD32(1)
    OBJ_VPAD16(33)
    OBJ_VPAD2(49)
    virtual RGE_Static_Object* get_target_obj(); // +CC
    OBJ_VPAD16(52)
    OBJ_VPAD8(68)
    OBJ_VPAD4(76)
    OBJ_VPAD2(80)
    OBJ_VPAD32(82)
    OBJ_VPAD2(114)
    virtual long get_action_checksum(); // +1D0
#undef OBJ_VPAD64
#undef OBJ_VPAD32
#undef OBJ_VPAD16
#undef OBJ_VPAD8
#undef OBJ_VPAD4
#undef OBJ_VPAD2
#undef OBJ_VPAD1
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

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();
    virtual void vfB4();
    virtual void turn_sound_off(); // +B8
    virtual void vfBC();
    virtual void vfC0();
    virtual void vfC4();
    virtual void vfC8();
    virtual unsigned char load_game(char* file_name); // +CC
    virtual void vfD0();
    virtual void vfD4();
    virtual void vfD8();
    virtual void vfDC();
    virtual void vfE0();

    int world_time; // +4
    int old_world_time; // +8
    char gap_0C[0x0C];
    float game_speed; // +18
    char gap_1C[0x20];
    short player_num; // +3C
    char gap_3E[2];
    RGE_Player** players; // +40
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_04[0x188];
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

int TRIBE_Game::load_game(char* file_name)
{
    TPanel* old_panel;
    unsigned char loaded;
    RGE_Object_Node* list;
    RGE_Action_Node* act_node;
    RGE_Player* p;
    long action_checksum;
    long num2;
    long num3;
    float temp_position_checksum;
    long total_action_checksum;
    long total_checksum;
    long num1;
    long num4;
    int i;
    int player_count;
    char action_name[4];
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
    if (this->comm_handler != 0)
        this->comm_handler->game_loading = 1;

    if (this->check_prog_argument("DEBUGSAVEGAME") != 0)
        ENABLE_COMPRESSION = 0;

    loaded = this->world->load_game(file_name);
    i = 0;
    player_count = this->world->player_num;
    while (i < player_count) {
        this->reset_countdown_timer(i);
        ++i;
    }

    ENABLE_COMPRESSION = 1;
    if (this->comm_handler != 0)
        this->comm_handler->game_loading = 0;

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
        RGE_Player* gaia = this->world->players[0];
        this->setFullVisibility(
            gaia->full_visibility);
        this->setFogOfWar(
            gaia->fog_of_war);
        this->setAllowCheatCodes(1);
        this->setSavedGame(1);
        this->setNumberPlayers(this->world->player_num - 1);

        loaded = this->pathFinding();
        if (loaded == 1)
            numberPathingIterations = 5000;
        else if (loaded == 2)
            numberPathingIterations = 0x1D4C;
        else
            numberPathingIterations = 0x9C4;

        for (i = 0; i < 9; ++i) {
            if (i < this->world->player_num) {
                this->setPlayerID(i, i);
                if (i > 0) {
                    this->comm_handler->SetPlayerName(
                        i, this->world->players[i]->name);
                    this->comm_handler->SetPlayerHumanity(
                        i, i == 1 ? 2 : 4);
                } else {
                    this->comm_handler->SetPlayerHumanity(i, 0);
                }
            } else {
                this->setPlayerID(i, 0);
                this->comm_handler->SetPlayerHumanity(i, 0);
            }
        }

        strcpy(fn, file_name);
        char* dot = _mbschr(fn, '.');
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
                    p = 0;
                    list = player->objects->list;
                    while (list != 0) {
                        RGE_Static_Object* object = list->object;
                            int attribute_value =
                                (int)object->attribute_amount_held;
                            num1 += object->object_state + attribute_value;
                            ++num2;
                            num3 += object->master_obj->id + num2 +
                                object->object_state + attribute_value;
                            temp_position_checksum += object->world_x +
                                object->world_y + object->world_z;
                            action_checksum += object->get_action_checksum();
                            RGE_Static_Object* target =
                                object->get_target_obj();
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
                                    player->id, object->id,
                                    object->master_obj->name,
                                    object->object_state,
                                    (double)object->attribute_amount_held,
                                    (double)object->world_x,
                                    (double)object->world_y,
                                    (double)object->world_z,
                                    num4, target_name_1);

                            RGE_Action_Object* moving_object =
                                (RGE_Action_Object*)object;
                            if (object->master_obj->object_type >= 0x1E &&
                                object->master_obj->object_type != 0x5A) {
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
                                            moving_object->number_wait_delays,
                                            moving_object->continue_counter);
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

                            if (object->master_obj->object_type >= 0x28 &&
                                object->master_obj->object_type != 0x5A) {
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
                        RGE_Static_Object* object = list->object;
                            int attribute_value =
                                (int)object->attribute_amount_held;
                            num1 += object->object_state + attribute_value;
                            ++num2;
                            num3 += object->master_obj->id + num2 +
                                object->object_state + attribute_value;
                            temp_position_checksum += object->world_x +
                                object->world_y + object->world_z;
                            action_checksum += object->get_action_checksum();
                            RGE_Doppleganger_Object* dopple =
                                (RGE_Doppleganger_Object*)object;
                            RGE_Static_Object* target =
                                object->get_target_obj();
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
                                    player->id, object->id,
                                    object->master_obj->name,
                                    object->object_state,
                                    (double)object->attribute_amount_held,
                                    (double)object->world_x,
                                    (double)object->world_y,
                                    (double)object->world_z,
                                    num4, target_name_2);
                            if (dopple->doppled_master_obj != 0)
                                fprintf(debug_file,
                                        "    Doppled master obj:  %s, %d.\n",
                                        dopple->doppled_master_obj->name,
                                        dopple->doppled_master_obj->object_type);
                            else
                                fprintf(debug_file,
                                        "    NULL doppled master obj.\n");

                            if (object->master_obj->object_type >= 0x1E &&
                                object->master_obj->object_type != 0x5A) {
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
                                            dopple->number_wait_delays,
                                            dopple->continue_counter);
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

                            if (object->master_obj->object_type >= 0x28 &&
                                object->master_obj->object_type != 0x5A) {
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
                        RGE_Static_Object* object = list->object;
                            RGE_Static_Object* target = object->get_target_obj();
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
                                    player->id, object->id,
                                    object->master_obj->name,
                                    object->object_state,
                                    (double)object->attribute_amount_held,
                                    (double)object->world_x,
                                    (double)object->world_y,
                                    (double)object->world_z,
                                    num4, target_name);
                        list = list->next;
                    }

                    num3 += num1;
                    total_action_checksum += action_checksum;
                    total_checksum += num2;
                    fprintf(debug_file,
                            "  p#%d checksum=%d, 1=%d, 2=%d, 3=%d, 4=%d, act=%d\n",
                            player->id, num1, num1, action_checksum, num2,
                            num3, p);
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
