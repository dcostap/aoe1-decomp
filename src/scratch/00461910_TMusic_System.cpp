// VA: 00461910 TMusic_System ctor (265B)
// music.cpp

class TMusic_System {
public:
    char gap4[0x100];
    char field_104;     // +104
    int field_108;      // +108
    int field_10C;      // +10C
    int field_110;      // +110
    int field_114;      // +114
    int field_118;      // +118
    char gap11C[0x10];
    char field_128;     // +128
    char field_129;     // +129
    char gap12A[0x106];
    int field_230;      // +230
    int field_234;      // +234
    int field_238;      // +238
    int field_23C;      // +23C
    int field_240;      // +240
    int field_244;      // +244
    int field_248;      // +248
    
    TMusic_System(char a1, int a2, int a3, int a4, int a5);
};

TMusic_System::TMusic_System(char a1, int a2, int a3, int a4, int a5) {
    field_104 = a1;
    field_108 = a5;
    field_110 = a4;
    field_10C = a3;
    field_114 = 0;
    field_118 = 0;
    field_128 = 0;
    field_230 = 0;
    field_234 = 0;
}
