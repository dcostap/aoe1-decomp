// VA: 00435620 command_work (256B)
// Command.cpp

class Commands {
public:
    char gap4[0x4];
    int field_8;
    char gapC[0x4];
    int field_10;
    
    void command_work(short idx, int* cmd);
};

void Commands::command_work(short idx, int* cmd) {
    int index = (signed short)idx;
    int offset = index * 4 + 0x14;
    
    if (cmd) {
        field_8 = cmd[0];
        field_10 = cmd[index];
    }
}
