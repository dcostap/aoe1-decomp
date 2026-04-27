// VA: 004E6600 processAICommand (577B)
// taimdmd.cpp

class TribeMainDecisionAIModule {
public:
    char gap4[0xCE8];
    int field_0CEC;
    
    int processAICommand(int cmd);
};

int __cdecl sub_004E4040(void* this_);

int TribeMainDecisionAIModule::processAICommand(int cmd) {
    if (cmd > 7) return 0;
    
    switch (cmd) {
        case 0:
            return sub_004E4040((char*)this + 0xCEC);
        default:
            return 0;
    }
}
