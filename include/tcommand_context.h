#ifndef TCOMMAND_CONTEXT_H
#define TCOMMAND_CONTEXT_H

class TDebuggingLog {
public:
    void __cdecl Log(char* format, ...);
};

extern TDebuggingLog* L;

class RGE_Game_World;
class TCommunications_Handler;
class RGE_Command_Give_Attribute;
class TRIBE_Command_Give_Attribute;

class RGE_Static_Object {
public:
    char gap_00[4];
    int id;
};

class RGE_Command {
public:
    virtual void do_command_give_attribute(
        RGE_Command_Give_Attribute* command);
    virtual ~RGE_Command();
    virtual void do_command(void* command);
    virtual void command_give_attribute(
        int player, int attribute, int amount, float value);

    RGE_Game_World* world;
    unsigned char* last_order;
    long last_order_size;
    unsigned long last_order_time;
    TCommunications_Handler* com_hand;

protected:
    void submit(void* command, long size);
};

class TRIBE_Command : public RGE_Command {
public:
    virtual void do_command_give_attribute(
        RGE_Command_Give_Attribute* command);
    virtual ~TRIBE_Command();
    virtual void do_command(void* command);
    virtual void do_command_give_attribute(
        TRIBE_Command_Give_Attribute* command);
    virtual void command_give_attribute(
        int player, int to_player, int attribute, float amount, float cost);

    void command_quick_build(short value);
    void command_shared_los(short value);
    void command_cancel_build(RGE_Static_Object* object);
    void command_attack_ground(
        RGE_Static_Object** objects, short count, float x, float y);
    void command_cheat(short cheat, short value);
    void command_trade_attribute(
        RGE_Static_Object** objects, short count, long attribute);
    void command_trade_attribute(int object, int unused, long attribute);
    void command_repair(
        RGE_Static_Object** objects,
        short count,
        RGE_Static_Object* target);
};

class TRIBE_Command_Game {
public:
    unsigned char command;
    unsigned char game_command;
    short var1;
    short var2;
    char gap_06[2];
    float var3;
    short var4;
    char gap_0E[2];
};

class TRIBE_Command_Cancel_Build {
public:
    unsigned char command;
    char gap_01[3];
    int unit_id;
};

class TRIBE_Command_Attack_Ground {
public:
    unsigned char command;
    unsigned char unit_num;
    char gap_02[2];
    float location_x;
    float location_y;
};

class TRIBE_Command_Give_Attribute {
public:
    unsigned char command;
    unsigned char player_id;
    unsigned char to_player_id;
    unsigned char attr_id;
    float attr_amount;
    float attr_cost;
};

class TRIBE_Command_Trade_Attribute {
public:
    unsigned char command;
    unsigned char unit_num;
    char gap_02[2];
    long attribute;
};

class RGE_Obj_Info {
public:
    long id;
};

class TRIBE_Command_Repair {
public:
    unsigned char command;
    unsigned char unit_num;
    char gap_02[2];
    RGE_Obj_Info target;
};


#endif
