// VA: 004E6580 setTributeChat (117B)
// taimdmd.cpp

class TribeMainDecisionAIModule {
public:
    char gap4[0x11468];
    int field_1146C;
    
    void setTributeChat(int a1);
};

int __cdecl sub_004F6210(void* this_, int a1);

void TribeMainDecisionAIModule::setTributeChat(int a1) {
    int result = sub_004F6210((char*)this + 0x1146C, 0x7E);
    if (result > 0) {
        a1 = 0x41D;
    }
}
