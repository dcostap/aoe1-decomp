// VA: 00435320 command_order (256B)
// Command.cpp

class Commands {
public:
    char gap4[0x4];
    int field_8;
    
    void command_order(short idx, int* cmd);
};

void Commands::command_order(short idx, int* cmd) {
    int index = (signed short)idx;
    int allocSize = index * 4 + 0x14;
    
    if (cmd) {
        field_8 = allocSize;
    } else {
        field_8 = 0;
    }
}
