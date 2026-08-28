#ifndef AOE1_RGE_COMMAND_H
#define AOE1_RGE_COMMAND_H

class RGE_Command_Give_Attribute;
class RGE_Game_World;
class TCommunications_Handler;

class RGE_Command {
protected:
    virtual void do_command_give_attribute(RGE_Command_Give_Attribute*);

public:
    virtual ~RGE_Command();
    virtual void do_command(void*);

    RGE_Game_World* world;
    unsigned char* last_order;
    long last_order_size;
    long last_order_time;
    TCommunications_Handler* com_hand;

    RGE_Command(RGE_Game_World*, TCommunications_Handler*);
    void reset_communications(TCommunications_Handler*);
    void do_commands();
};

typedef char rge_command_size_check[
    (sizeof(RGE_Command) == 0x18) ? 1 : -1];

#endif  // AOE1_RGE_COMMAND_H
