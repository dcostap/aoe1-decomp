// VA: 004628A0 do_fade (262B)
// music.cpp

class TMusic_System {
public:
    char gap4[0xFC];
    char field_100;
    char gap101[0x28];
    char field_129;
    char gap12A[0x106];
    int field_230;
    int field_234;
    int field_238;
    int field_23C;
    int field_240;
    int field_244;
    int field_248;
    int field_24C;
    
    void do_fade();
};

void TMusic_System::do_fade() {
    // Perform volume fade
    if (field_24C > 0) {
        field_230 -= 1;
        if (field_230 <= 0) {
            field_129 = 1;
        }
    }
}
