// VA: 004543D0 alignment (690B)
// m_s_obj.cpp

class RGE_Master_Static_Object {
public:
    char gap4[0x2C];
    int field_30;
    char gap34[0x4];
    int field_38;
    
    void alignment(int* a1, int* a2, int* a3);
};

void RGE_Master_Static_Object::alignment(int* a1, int* a2, int* a3) {
    int* ptr = *(int**)((char*)a1 + 0x28);
    float f1 = *(float*)a2;
    float f2 = *(float*)((char*)this + 0x30);
    float diff = f1 - f2;
    
    int w = *(int*)((char*)ptr + 8);
    int h = *(int*)((char*)ptr + 0x0C);
    
    if (w > 0 && h > 0) {
        field_38 = w + h;
    }
}
