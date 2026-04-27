// VA: 00435810 command_move (239B)
// Command.cpp

class Commands {
public:
    char gap4[0x4];
    int field_8;
    
    void command_move(short idx, int* cmd);
};

void Commands::command_move(short idx, int* cmd) {
    if (!cmd) return;
    
    if ((signed short)idx >= 1) {
        field_8 = (int)cmd;
    }
}
