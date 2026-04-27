// VA: 004EEF40 update (1421B)
// taitacmd.cpp

class TribeAICommand {
public:
    char gap4[0xEC];
    int field_F0;
    char gapF4[0xE24];
    int field_D1C;
    
    void update();
};

void TribeAICommand::update() {
    int* obj = (int*)field_F0;
    if (obj) {
        int* sub = (int*)obj[0x3C];  // field_F0
        if (sub) {
            field_D1C = (int)sub + 0x0F0;
        }
    }
}
