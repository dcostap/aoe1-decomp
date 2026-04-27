// VA: 00462C30 get_play_info (309B)
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
    
    int get_play_info();
};

int TMusic_System::get_play_info() {
    if (!field_248) return 0;
    
    // Return playback position/info
    return field_240;
}
