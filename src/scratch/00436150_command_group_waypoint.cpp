// VA: 00436150 command_group_waypoint (204B)
// Command.cpp

class Commands {
public:
    char gap4[0x4];
    int field_8;
    
    void command_group_waypoint(short idx, int* cmd);
};

void Commands::command_group_waypoint(short idx, int* cmd) {
    int index = (signed short)idx;
    int allocSize = index * 4 + 4;
    
    if (cmd) {
        field_8 = allocSize;
    } else {
        field_8 = 0;
    }
}
