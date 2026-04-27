// VA: 00461D20 open_mixer (406B)
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
    
    int open_mixer(int a1, int a2);
};

int __cdecl waveOutOpen(int* hWave, int a, int b, int c, int d, int e);

int TMusic_System::open_mixer(int a1, int a2) {
    // Open mixer device
    int hWave = 0;
    int result = waveOutOpen(&hWave, a1, a2, 0, 0, 0);
    if (result != 0) return 0;
    
    field_248 = hWave;
    return 1;
}
