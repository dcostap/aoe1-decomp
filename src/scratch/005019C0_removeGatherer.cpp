// VA: 005019C0 removeGatherer (192B)
// taitacmd.cpp

class TribeAICommand {
public:
    char gap4[0x4];
    int field_8;
    
    void removeGatherer(int a1);
};

int __cdecl sub_0040E830(int* log, const char* msg);

void TribeAICommand::removeGatherer(int a1) {
    if (a1 == -1) {
        sub_0040E830((int*)this, "message_at_588AC8");
    }
    field_8 = 0;
}
