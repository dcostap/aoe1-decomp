// VA: 00462140 play_tracks (183B)
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
    
    void play_tracks(int a1, int a2, int a3, int a4, int a5);
};

void TMusic_System::play_tracks(int a1, int a2, int a3, int a4, int a5) {
    field_240 = a1;
    field_129 = 0;
    field_230 = a2;
    field_234 = a3;
    field_238 = a4;
    field_23C = a5;
    
    if (!field_248) return;
    
    // Continue playback
}
