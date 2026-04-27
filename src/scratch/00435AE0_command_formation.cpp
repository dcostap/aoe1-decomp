// VA: 00435AE0 command_formation (207B)
// Command.cpp

class Commands {
public:
    char gap4[0x4];
    int field_8;
    
    void command_formation(int idx, int* cmd);
};

void Commands::command_formation(int idx, int* cmd) {
    int allocSize = idx * 4 + 0x0C;
    
    if (cmd) {
        field_8 = allocSize;
    } else {
        field_8 = 0;
    }
}
