// VA: 00435720 command_work (231B)
// Command.cpp

class Commands {
public:
    char gap4[0x4];
    int field_8;
    
    void command_work(int idx, int* cmd);
};

void Commands::command_work(int idx, int* cmd) {
    if (!cmd) return;
    
    if (idx >= 1) {
        field_8 = cmd[idx];
    }
}
