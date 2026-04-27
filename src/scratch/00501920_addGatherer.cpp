// VA: 00501920 addGatherer (155B)
// taitacmd.cpp

class TribeAICommand {
public:
    char gap4[0x4];
    int field_8;
    
    void addGatherer(int a1);
};

int __cdecl sub_0040E830(int* log, const char* msg);

void TribeAICommand::addGatherer(int a1) {
    if (a1 == -1) {
        sub_0040E830((int*)this, "message_at_588AA8");
    }
    field_8 = a1;
}
