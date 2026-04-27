// VA: 004FFEE0 displayBoatGroups (889B)
// taitacmd.cpp

class TribeAICommand {
public:
    char gap4[0x4];
    int field_8;
    
    void displayBoatGroups();
};

int __cdecl sub_0040E830(int* log, const char* msg);

void TribeAICommand::displayBoatGroups() {
    sub_0040E830((int*)this, "boat_groups_msg");
    field_8 = 0;
}
