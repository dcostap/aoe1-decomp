// VA: 004FD8D0 displaySoldierGroups (1324B)
// taitacmd.cpp

class TribeAICommand {
public:
    char gap4[0x4];
    int field_8;
    
    void displaySoldierGroups();
};

int __cdecl sub_0040E830(int* log, const char* msg);

void TribeAICommand::displaySoldierGroups() {
    sub_0040E830((int*)this, "soldier_groups_msg");
    field_8 = 0;
}
