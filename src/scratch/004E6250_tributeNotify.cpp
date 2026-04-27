// VA: 004E6250 tributeNotify (568B)
// taimdmd.cpp

class TribeMainDecisionAIModule {
public:
    char gap4[0x12588];
    int field_1258C;
    
    void tributeNotify(int a1);
};

int __cdecl sub_004F6210(void* this_, int a1);

void TribeMainDecisionAIModule::tributeNotify(int a1) {
    char buf[260];
    
    if (field_1258C != 1) return;
    
    int result = sub_004F6210((char*)this + 0x1146C, 0x80);
    if (result > 0) {
        // Handle tribute notification
    }
}
