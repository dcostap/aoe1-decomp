// VA: 004E6490 revokeTributeAlliance (230B)
// taimdmd.cpp

class TribeMainDecisionAIModule {
public:
    char gap4[0xEC];
    int field_F0;
    char gapF4[0x1078];
    int field_1146C;
    
    void revokeTributeAlliance(int a1);
};

int __cdecl sub_004F6210(void* this_, int a1);

void TribeMainDecisionAIModule::revokeTributeAlliance(int a1) {
    char buf[256];
    
    int* obj = *(int**)field_F0;
    int val = obj[0];
    
    int result = sub_004F6210((char*)this + 0x1146C, 0x80);
    if (result > 0) {
        // Revoke tribute/alliance
    }
}
