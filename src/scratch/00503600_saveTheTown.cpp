// VA: 00503600 saveTheTown (1450B)
// taitacmd.cpp

class TribeAICommand {
public:
    char gap4[0x4];
    int field_8;
    
    void saveTheTown();
};

int __cdecl sub_004231E0(int a1, int a2);

void TribeAICommand::saveTheTown() {
    sub_004231E0(0x3420, (int)"string_at_5880C0");
    field_8 = 1;
}
