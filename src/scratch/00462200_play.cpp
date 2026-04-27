// VA: 00462200 play (952B)
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
    
    int play(int a1, int a2, int a3, int a4, int a5, int a6);
};

int __cdecl midiStreamOpen(int* hStream, int* a, int b, int c, int d);

int TMusic_System::play(int a1, int a2, int a3, int a4, int a5, int a6) {
    if (!field_248) return 0;
    
    // Play music track
    int hStream = 0;
    int result = midiStreamOpen(&hStream, &a1, a2, 0, 0);
    if (result != 0) return 0;
    
    field_230 = a3;
    field_234 = a4;
    field_238 = a5;
    field_23C = a6;
    field_240 = a1;
    
    return 1;
}
