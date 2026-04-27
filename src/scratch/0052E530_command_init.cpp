// tried the natural new-expression shape first; VC5 compiled it into the wrong allocator symbol and too-small text
// switched to the project allocator name and then to placement-new; that fixed the call surface but still missed the EH frame
// tried a try/catch rethrow shape; that got the byte count up to 89 but introduced an EBP-based frame, unlike the packet
// tried a guard object with a destructor; the remaining gap is now the early EH/prolog layout and a few stack-slot moves
// kept the function in scratch because the remaining mismatch is localized EH/prolog drift, not a changed call set or store target
class TCommunications_Handler;
class RGE_Command;

extern void* __cdecl operator_new(unsigned int size);
inline void* __cdecl operator new(unsigned int, void* place) {
    return place;
}

class RGE_Game_World {
public:
    char pad_00[0x58];
    RGE_Command* commands;
};

class RGE_Command_Give_Attribute;
class TRIBE_Command_Give_Attribute;

class RGE_Command_Give_Attribute;
class RGE_Command_Add_Attribute;
class RGE_Command_Add_To_Group;
class RGE_Command_Add_Waypoint;

class RGE_Command {
public:
    virtual void do_command_give_attribute(RGE_Command_Give_Attribute* param_1);
    virtual ~RGE_Command();
    virtual void do_command(void* param_1);
    virtual void command_give_attribute(int param_1, int param_2, int param_3, float param_4);
    RGE_Game_World* world;
    unsigned char* last_order;
    long last_order_size;
    long last_order_time;
    TCommunications_Handler* com_hand;
};

class TRIBE_World : public RGE_Game_World {
public:
    void command_init(int param_1, TCommunications_Handler* param_2);
};

class TRIBE_Command : public RGE_Command {
public:
    virtual void do_command_give_attribute(TRIBE_Command_Give_Attribute* param_1);
    virtual ~TRIBE_Command();
    virtual void do_command(void* param_1);
    virtual void command_give_attribute(int param_1, int param_2, int param_3, float param_4, float param_5);
    TRIBE_Command(TRIBE_World* world, TCommunications_Handler* handler);
};

class TRIBE_World_Command_Init_Guard {
public:
    TRIBE_World* world;
    TRIBE_Command* command;
    ~TRIBE_World_Command_Init_Guard() {
        world->commands = command;
    }
};

void TRIBE_World::command_init(int param_1, TCommunications_Handler* param_2) {
    TRIBE_World_Command_Init_Guard guard;
    guard.world = this;
    guard.command = 0;
    guard.command = (TRIBE_Command*)operator_new(0x18);
    if (guard.command != 0) {
        guard.command = new (guard.command) TRIBE_Command(this, param_2);
    }
}
