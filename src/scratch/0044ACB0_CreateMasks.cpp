// VA: 0044ACB0 CreateMasks (721B)
// fractal.cpp

class RGE_Fractal {
public:
    char gap4[0xFA4];
    int field_FA8;
    char gapFAC[0x28];
    int field_FD4;
    int field_FD8;
    char gapFDC[0x4];
    int field_FE0;
    char gapFE4[0x14];
    int field_FF8;
    char gapFFC[0x8];
    int field_1004;
    int field_1008;
    int field_100C;
    char gap1010[0x34];
    int field_1044;
    
    void CreateMasks();
};

void* __cdecl operator_new(unsigned size);

void RGE_Fractal::CreateMasks() {
    field_FA8 = (int)operator_new(0x10);
    operator_new(0x19);
    operator_new(0x19);
}
