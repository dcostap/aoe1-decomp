// VA: 00435EA0 command_group_ai_order (315B)
// Command.cpp

class Commands {
public:
    char gap4[0x4];
    int field_8;
    
    void command_group_ai_order(short idx, int* cmd);
};

void Commands::command_group_ai_order(short idx, int* cmd) {
    if (!cmd) return;
    
    if ((signed short)idx < 1) return;
    
    field_8 = (int)cmd;
}
