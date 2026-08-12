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
// - Remaining blocker: DEBUGLOAD has 21 fprintf calls, six waypoint scans,
//   and compiler-generated floating conversion calls. The natural typed draft
//   has 13 fprintf calls and a smaller frame. Leave this target paused.

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
    void SetPlayerName(int player, char* name);
    void SetPlayerHumanity(int player, int humanity);
};

class RGE_Victory_Conditions {
public:
    long get_victory_points();
};

class Waypoint {
public:
    short x;
    short y;
    unsigned char facetToNextWaypoint;
};

class Path {
public:
    char gap_00[0xA4];
    int numberOfWaypoints();
    void initToStart();
    Waypoint* currentWaypoint();
    void moveToNextWaypoint();
};

class RGE_Action {
public:
    virtual ~RGE_Action();
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
    virtual void vfB8();
    virtual void vfBC();
    virtual void vfC0();
    virtual void vfC4();
    virtual void vfC8();
    virtual void vfCC();
    virtual void vfD0();
    virtual void vfD4();
    virtual void vfD8();
    short action_type;
    short gap_06;
    int object_id;
    unsigned char attribute;
    char gap_11[0x2B];
    float x;
    float y;
    float z;
    void subAction();
    float targetZ();
    float targetY();
    float targetX();
    virtual void update();
    Path path;
};

class RGE_Action_Node {
public:
    RGE_Action* action;
    RGE_Action_Node* next;
};

class RGE_Action_List {
public:
    char gap_00[4];
    RGE_Action_Node* list;
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
    virtual void object_action(); // +CC
    OBJ_VPAD16(52)
    OBJ_VPAD8(68)
    OBJ_VPAD4(76)
    OBJ_VPAD2(80)
    OBJ_VPAD32(82)
    OBJ_VPAD2(114)
    virtual void object_update(); // +1D0
#undef OBJ_VPAD64
#undef OBJ_VPAD32
#undef OBJ_VPAD16
#undef OBJ_VPAD8
#undef OBJ_VPAD4
#undef OBJ_VPAD2
#undef OBJ_VPAD1
    char gap_04[0x24];
    RGE_Action_List* action_list; // +28
    char gap_2C[0x18];
    unsigned char object_type; // +44
    char gap_45[3];
    char* name; // +48
    char gap_4C[4];
    float* attributes; // +50
    char gap_54[0x50];
    Path path; // +A4
    RGE_Action_List* action_list_184; // +184
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x24];
    RGE_Action_List* action_list; // +28
    RGE_Action_List* second_list; // +2C
    RGE_Action_List* third_list; // +30
    RGE_Victory_Conditions* victory_conditions; // +34
    char gap_38[0x0C];
    char* name; // +44
    char gap_48[8];
    float* attributes; // +50
    char gap_54[0xB1];
    unsigned char civilization; // +105
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
        if (*old_panel->panelName() != 0) {
            panel_system.setCurrentPanel(old_panel->panelName(), 0);
            panel_system.destroyPanel("Status Screen");
            this->enable_input();
            return 0;
        }
        goto load_game_failed;
    }

    this->show_status_message(0x452, 0, -1);
    if (this->comm_handler != 0)
        *(unsigned char*)((char*)this->comm_handler + 1) = 1;

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
        *(unsigned char*)((char*)this->comm_handler + 1) = 0;

    if (loaded != 0) {
        RGE_Player* gaia = this->world->players[0];
        this->setFullVisibility(
            *(unsigned char*)((char*)gaia + 0x8DB8));
        this->setFogOfWar(
            *(unsigned char*)((char*)gaia + 0x8DB9));
        this->setAllowCheatCodes(1);
        this->setSavedGame(1);
        this->setNumberPlayers(this->world->player_num - 1);

        if (this->pathFinding() == 1)
            numberPathingIterations = 5000;
        else if (this->pathFinding() == 2)
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

        strcpy(target_name + 0x30, file_name);
        char* dot = _mbschr(target_name + 0x30, '.');
        if (dot != 0)
            *dot = 0;
        this->set_save_game_name(target_name + 0x30);
        this->set_load_game_name(target_name + 0x30);

        if (this->check_prog_argument("DEBUGLOAD") != 0) {
            sprintf(fileNameNoExt + 0x100, "c:\\%s.txt", target_name + 0x30);
            FILE* debug_file = fopen(fileNameNoExt + 0x100, "w");
            if (debug_file != 0) {
                long total_action_checksum = 0;
                int total_checksum = 0;
                fprintf(debug_file, "world_time %u\n", this->world->world_time);
                fprintf(debug_file, "old_world_time %u\n",
                        this->world->old_world_time);
                fprintf(debug_file, "game_speed %6.2f\n",
                        (double)this->world->game_speed);

                for (i = 0; i < this->world->player_num; ++i) {
                    RGE_Player* player = this->world->players[i];
                    int object_count = 0;
                    int action_checksum = 0;
                    int object_checksum = 0;
                    long victory_points = 0;
                    if (player->victory_conditions != 0)
                        victory_points =
                            player->victory_conditions->get_victory_points();
                    fprintf(debug_file, "  player %d civ %d score %ld\n",
                            i, player->civilization, victory_points);
                    fprintf(debug_file, "    num_sleep_obj %d\n", 0);
                    fprintf(debug_file, "    num_dopple_obj %d\n", 0);

                    RGE_Action_Node* node = 0;
                    if (player->action_list != 0)
                        node = player->action_list->list;
                    while (node != 0) {
                        RGE_Action* action = node->action;
                        if (action != 0) {
                            action_checksum += action->action_type;
                            action_checksum += action->attribute;
                            ++object_count;
                            action->update();
                            RGE_Static_Object* target = 0;
                            if (target != 0)
                                strcpy(target_name_1, target->name);
                            else
                                target_name_1[0] = 0;
                            fprintf(debug_file, "    p %d ob %d %s st %d\n",
                                    i, action->object_id,
                                    target_name_1, action->attribute);
                            action->subAction();
                            action->targetZ();
                            action->targetY();
                            action->targetX();

                            Path* path = &action->path;
                            int waypoint_count = path->numberOfWaypoints();
                            if (waypoint_count > 0) {
                                int waypoint_index = 0;
                                path->initToStart();
                                waypoint_count = path->numberOfWaypoints();
                                while (waypoint_index < waypoint_count) {
                                    Waypoint* waypoint = path->currentWaypoint();
                                    fprintf(debug_file,
                                            "      w %d %6.2f %6.2f %d\n",
                                            waypoint_index,
                                            (double)waypoint->x,
                                            (double)waypoint->y,
                                            waypoint->facetToNextWaypoint);
                                    ++waypoint_index;
                                    path->moveToNextWaypoint();
                                    waypoint_count = path->numberOfWaypoints();
                                }
                                path->initToStart();
                                path->moveToNextWaypoint();
                            }
                        }
                        node = node->next;
                    }

                    node = 0;
                    if (player->second_list != 0)
                        node = player->second_list->list;
                    while (node != 0) {
                        RGE_Action* action = node->action;
                        if (action != 0) {
                            action_checksum += action->action_type;
                            ++object_count;
                            action->update();
                            action->subAction();
                            action->targetZ();
                            action->targetY();
                            action->targetX();
                            const char* action_name_ptr =
                                *(const char**)((char*)action + 8);
                            if (action_name_ptr != 0)
                                strcpy(target_name_2, action_name_ptr);
                            else
                                target_name_2[0] = 0;
                            fprintf(debug_file, "    p %d ob %d %s\n",
                                    i, action->object_id, target_name_2);

                            Path* path = &action->path;
                            int waypoint_count = path->numberOfWaypoints();
                            if (waypoint_count > 0) {
                                int waypoint_index = 0;
                                path->initToStart();
                                waypoint_count = path->numberOfWaypoints();
                                while (waypoint_index < waypoint_count) {
                                    Waypoint* waypoint = path->currentWaypoint();
                                    fprintf(debug_file,
                                            "      w %d %6.2f %6.2f %d\n",
                                            waypoint_index,
                                            (double)waypoint->x,
                                            (double)waypoint->y,
                                            waypoint->facetToNextWaypoint);
                                    ++waypoint_index;
                                    path->moveToNextWaypoint();
                                    waypoint_count = path->numberOfWaypoints();
                                }
                                path->initToStart();
                                path->moveToNextWaypoint();
                            }
                        }
                        node = node->next;
                    }

                    node = 0;
                    if (player->third_list != 0)
                        node = player->third_list->list;
                    while (node != 0) {
                        RGE_Action* action = node->action;
                        if (action != 0) {
                            action_checksum += action->action_type;
                            ++object_count;
                            action->update();
                            action->subAction();
                            action->targetZ();
                            action->targetY();
                            action->targetX();
                            const char* action_name_ptr =
                                *(const char**)((char*)action + 8);
                            if (action_name_ptr != 0)
                                strcpy(action_name, action_name_ptr);
                            else
                                action_name[0] = 0;
                            fprintf(debug_file, "    p %d ob %d %s\n",
                                    i, action->object_id, action_name);
                        }
                        node = node->next;
                    }
                    fprintf(debug_file, "    checksum %d %d %d\n",
                            i, object_checksum, action_checksum);
                    total_action_checksum += action_checksum;
                    total_checksum += object_count;
                }

                fprintf(debug_file, "total_checksum %ld act %ld\n",
                        (long)total_checksum, total_action_checksum);
                fclose(debug_file);
            }
        }

        this->close_game_screens(0);
        return this->create_game_screen();
    }

    if (old_panel == 0 || old_panel->panelName() == 0)
        goto load_game_failed;
    if (*old_panel->panelName() != 0) {
        panel_system.setCurrentPanel(old_panel->panelName(), 0);
        panel_system.destroyPanel("Status Screen");
        this->enable_input();
        return 0;
    }

load_game_failed:
    this->close_status_message();
    this->enable_input();
    return 0;
}
