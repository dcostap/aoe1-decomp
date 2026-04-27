// VA: 00462B40 after_end_track (228B)
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
    
    void after_end_track();
};

void TMusic_System::after_end_track() {
    if (!field_248) return;
    
    field_100 = 0;
    // Queue next track or stop
}
