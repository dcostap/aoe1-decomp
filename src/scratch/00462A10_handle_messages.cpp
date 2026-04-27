// VA: 00462A10 handle_messages (295B)
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
    void handle_messages();
};

void TMusic_System::handle_messages() {
    if (!field_248) return;
    
    // Process MIDI/wave messages
    if (field_24C > 0) {
        do_fade();
    }
}
