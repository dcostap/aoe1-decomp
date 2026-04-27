// VA: 00434DC0 do_command_group_ai_order (239B)
// Command.cpp

class Commands {
public:
    char gap4[0x4];
    int field_8;
    
    void do_command_group_ai_order(int* cmd);
};

void Commands::do_command_group_ai_order(int* cmd) {
    int count = *(unsigned char*)((char*)cmd + 3);
    int* data = (int*)((char*)cmd + 0x24);
    
    if (count <= 0) return;
    
    field_8 = data[0];
}
