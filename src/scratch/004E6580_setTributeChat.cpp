// VA: 004E6580 setTributeChat (117B)
// taimdmd.cpp

class TribeTacticalAIModule {
public:
    int strategicNumber(int id);
};

extern "C" int __cdecl debug_rand(char* file, int line);

class TribeMainDecisionAIModule {
public:
    char gap_00[0x1146C];
    TribeTacticalAIModule tacticalAI;
    char gap_after[0x12588 - 0x1146C - 1];
    int tributeChatTimeout;

    void setTributeChat();
};

void TribeMainDecisionAIModule::setTributeChat() {
    TribeTacticalAIModule* tactical = &this->tacticalAI;
    if (tactical->strategicNumber(0x7E) > 0) {
        int rem = debug_rand("C:\\msdev\\work\\age1_x1\\taimdmd.cpp", 0x41D);
        int span = tactical->strategicNumber(0x7E);
        rem = rem % span;
        int offset = tactical->strategicNumber(0x7E);
        int base = tactical->strategicNumber(0x7D);
        this->tributeChatTimeout = rem - offset / 2 + base;
    } else {
        this->tributeChatTimeout = tactical->strategicNumber(0x7D);
    }
}
