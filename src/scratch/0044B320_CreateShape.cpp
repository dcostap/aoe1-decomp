// VA: 0044B320 CreateShape (334B)
// fractal.cpp

class RGE_Fractal {
public:
    char gap4[0xFDC];
    int field_FE0;
    char gapFE4[0x260];
    int field_1044;
    
    void CreateShape();
};

void __cdecl sub_0044B210(void* this_);
void __cdecl sub_0044C4B0(void* this_);

void RGE_Fractal::CreateShape() {
    field_FE0 = 0;
    sub_0044B210(this);
    sub_0044C4B0(this);
    
    int* params = (int*)field_1044;
    if (params) {
        field_FE0 = params[0];
    }
}
