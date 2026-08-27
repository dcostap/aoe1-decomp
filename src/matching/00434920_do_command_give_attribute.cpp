// VA: 00434920 do_command_give_attribute (210B)
// Command.cpp lines 692-718.
//
// Initial reconstruction: the base command transfers an attribute from the
// issuing player to the destination player, records the command, and sends the
// resulting event.  The local declarations model only the proven world/player
// ownership and virtual slots used by this function.
//
// Attempt log:
// - Baseline natural transfer reconstruction reached the correct call set and
//   frame, but used the reversed FPU comparison and had a vslot+0x3C base-game
//   call because the local placeholder count was one short.
// - Reversed the inclusive comparison operands to preserve the original
//   `fld attributes; fcomp amount; test ah,1` ordering.
// - Added the proven base-game slot, the sixth zero argument to notify, and
//   the generated RGE_Player/RGE_Base_Game/RGE_Command ABI names.  The final
//   event's zero is a real stack argument, not a temporary scheduling aid.
// Result: exact 210-byte match under config/flags/default.rsp.

#ifndef COMMAND_TU_CONTEXT
class RGE_Static_Object;
class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char); virtual void do_resign(int);
    virtual void changeToHumanPlayer(); virtual void changeToComputerPlayer();
    virtual char* aiStatus(int); virtual int isEnemy(int); virtual int isAlly(int);
    virtual int isNeutral(int); virtual int isAllNeutral();
    virtual void setDiplomaticStance(int, int);
    virtual void loadAIInformation(char*, char*, char*, int, int);
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float,
                                 float, float, int, int, int);
    virtual void processAIOrder(int, int, int, int, int, float, float, float,
                                float, int, int, int);
    virtual void kickAI(int); virtual int strategicNumber(int);
    virtual void sendGameOrder(RGE_Static_Object*, RGE_Static_Object*, float, float);
    virtual void sendAddWaypointCommand(int, void*, int);
    virtual void processAddWaypointCommand(int, void*, int);
    virtual void sendPlayCommand(int, int*, int, int, int);
    virtual void sendPlayCommand(int, int, int);
    virtual int sendAICommand(int, int, int, int, int);
    virtual int objectCostByType(int); virtual void trackUnitGather(int, int, int);
    virtual void save(int); virtual void scenario_save(int);
    virtual void scenario_load(int, long*, float); virtual void scenario_postsave(int);
    virtual void scenario_postload(int, long*, float); virtual void load(int);
    virtual void add_attribute_num(short attr_id, float amount,
                                   unsigned char flag);

    virtual void update(); virtual void update_dopplegangers(); virtual void save2(int);
    virtual void save_info(int); virtual void random_start();
    virtual void* make_new_object(long, float, float, float, int);
    virtual void analyize_selected_objects();
    virtual int get_mouse_pointer_action_vars(int, int*, int*);
    virtual unsigned char command_make_move(void*, float, float);
    virtual unsigned char command_make_work(void*, float, float);
    virtual unsigned char command_make_do(void*, float, float);
    virtual unsigned char command_stop();
    virtual unsigned char command_place_object(short, float, float, float);
    virtual unsigned char command_add_attribute(int, float);
    virtual unsigned char command_give_attribute(int, int, float);
    virtual unsigned char command_formation(int);
    virtual unsigned char command_stand_ground();
    virtual unsigned char command_create_group(int, int*, int, float);
    virtual unsigned char command_add_to_group(int, int, float);
    virtual unsigned char command_remove_from_group(int, int);
    virtual unsigned char command_destroy_group(int);
    virtual unsigned char command_resign(int, int);
    virtual unsigned char command_add_waypoint(float, float, float);
    virtual void* addObject(void*, int, int); virtual void removeObject(void*, int, int, void*);
    virtual void logMessage(char*);
    virtual void notify(int player_id, int to_player_id, int event_id,
                        long attr_id, long amount, long zero);

    char gap_04[0x4C];
    float* attributes;
};

class RGE_Game_World {
public:
    char gap_00[0x40];
    RGE_Player** players;
};
#endif

#ifndef COMMAND_TU_CONTEXT
struct RGE_Command_Give_Attribute {
    unsigned char command;
    unsigned char player_id;
    unsigned char to_player_id;
    unsigned char attr_id;
    float attr_amount;
};
#endif

#ifndef COMMAND_TU_CONTEXT
class RGE_Base_Game {
public:
    virtual void set_prog_mode(); virtual void get_view_panel();
    virtual void get_map_panel(); virtual void processCheatCode();
    virtual void handle_message(); virtual void action_update();
    virtual void action_mouse_move(); virtual void action_key_down();
    virtual void action_user_command(); virtual void action_command();
    virtual void action_music_done(); virtual void action_activate();
    virtual void action_deactivate(); virtual void action_init_menu();
    virtual void action_exit_menu(); virtual void action_size();
    virtual void notification(int command, long player_id, long to_player_id,
                              long attr_id, long amount);
};

extern RGE_Base_Game* rge_base_game;
#endif

#ifndef COMMAND_TU_CONTEXT
class RGE_Command {
public:
    virtual void do_command_give_attribute(RGE_Command_Give_Attribute* cmd);
    virtual ~RGE_Command();
    virtual void do_command(void* cmd);
    virtual void command_give_attribute(int player_id, int attr_id, int amount,
                                        float value);
    RGE_Game_World* world;
};
#endif

void RGE_Command::do_command_give_attribute(RGE_Command_Give_Attribute* cmd)
{
    RGE_Player* player = this->world->players[cmd->player_id];

    if (player->attributes[cmd->attr_id] >= cmd->attr_amount) {
        player->add_attribute_num(cmd->attr_id, -cmd->attr_amount, 0);
        this->world->players[cmd->to_player_id]->add_attribute_num(
            cmd->attr_id, cmd->attr_amount, 0);

        rge_base_game->notification(7, cmd->player_id, cmd->to_player_id,
                                    cmd->attr_id, (long)cmd->attr_amount);

        this->world->players[cmd->to_player_id]->notify(
            cmd->player_id, cmd->to_player_id, 0x20A, cmd->attr_id,
            (long)cmd->attr_amount, 0);
    }
}
