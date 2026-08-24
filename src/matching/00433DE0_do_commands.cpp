#ifndef COMMAND_TU_CONTEXT
class RGE_Command_Give_Attribute;
class RGE_Game_World;
class TCommunications_Handler {
public:
    void* get_command(void);
};

class RGE_Command {
public:
    virtual void do_command_give_attribute(RGE_Command_Give_Attribute* param_1);
    virtual ~RGE_Command();
    virtual void do_command(void* param_1);
    RGE_Game_World* world;
    unsigned char* last_order;
    long last_order_size;
    long last_order_time;
    TCommunications_Handler* com_hand;

    void do_commands(void);
};
#endif

extern void __cdecl operator delete(void*);

void RGE_Command::do_commands(void) {
    void* command;

    if (this->com_hand != 0) {
        while ((command = this->com_hand->get_command()) != 0) {
            this->do_command(command);
            if (command != 0) {
                operator delete(command);
            }
        }
    }
}
