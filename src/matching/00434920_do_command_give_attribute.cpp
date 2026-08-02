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

class RGE_Player {
public:
    virtual void v00();  virtual void v04();  virtual void v08();
    virtual void v0C();  virtual void v10();  virtual void v14();
    virtual void v18();  virtual void v1C();  virtual void v20();
    virtual void v24();  virtual void v28();  virtual void v2C();
    virtual void v30();  virtual void v34();  virtual void v38();
    virtual void v3C();  virtual void v40();  virtual void v44();
    virtual void v48();  virtual void v4C();  virtual void v50();
    virtual void v54();  virtual void v58();  virtual void v5C();
    virtual void v60();  virtual void v64();  virtual void v68();
    virtual void v6C();  virtual void v70();  virtual void v74();
    virtual void add_attribute_num(short attr_id, float amount,
                                   unsigned char flag);

    virtual void v7C();  virtual void v80();  virtual void v84();
    virtual void v88();  virtual void v8C();  virtual void v90();
    virtual void v94();  virtual void v98();  virtual void v9C();
    virtual void vA0();  virtual void vA4();  virtual void vA8();
    virtual void vAC();  virtual void vB0();  virtual void vB4();
    virtual void vB8();  virtual void vBC();  virtual void vC0();
    virtual void vC4();  virtual void vC8();  virtual void vCC();
    virtual void vD0();  virtual void vD4();  virtual void vD8();
    virtual void vDC();  virtual void vE0();  virtual void vE4();
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

struct RGE_Command_Give_Attribute {
    unsigned char command;
    unsigned char player_id;
    unsigned char to_player_id;
    unsigned char attr_id;
    float attr_amount;
};

class RGE_Base_Game {
public:
    virtual void v00();  virtual void v04();  virtual void v08();
    virtual void v0C();  virtual void v10();  virtual void v14();
    virtual void v18();  virtual void v1C();  virtual void v20();
    virtual void v24();  virtual void v28();  virtual void v2C();
    virtual void v30();  virtual void v34();  virtual void v38();
    virtual void v3C();
    virtual void notification(int command, long player_id, long to_player_id,
                              long attr_id, long amount);
};

extern RGE_Base_Game* rge_base_game;

class RGE_Command {
public:
    virtual void do_command_give_attribute(RGE_Command_Give_Attribute* cmd);
    virtual ~RGE_Command();
    virtual void do_command(void* cmd);
    virtual void command_give_attribute(int player_id, int attr_id, int amount,
                                        float value);
    RGE_Game_World* world;
};

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
