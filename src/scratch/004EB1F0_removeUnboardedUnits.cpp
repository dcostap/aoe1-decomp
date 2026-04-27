// VA: 004EB1F0 removeUnboardedUnits (156B)
// taitacmd.cpp

class TribeAICommand {
public:
    char gap4[0x18];
    int field_1C;
    char gap20[0x4];
    int field_24;
    
    void removeUnboardedUnits(int a1);
};

void TribeAICommand::removeUnboardedUnits(int a1) {
    if (field_1C) {
        field_1C = a1;
        field_24 = 0;
    }
}
