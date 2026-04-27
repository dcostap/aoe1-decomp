// VA: 00462670 resume_play (207B)
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
    char field_24C;
    
    void resume_play();
};

void TMusic_System::resume_play() {
    if (!field_248) return;
    
    // Resume playback from pause
    field_24C = 1;
}
