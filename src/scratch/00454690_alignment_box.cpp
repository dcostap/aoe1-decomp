// VA: 00454690 alignment_box (337B)
// m_s_obj.cpp

class RGE_Master_Static_Object {
public:
    char gap4[0x2C];
    int field_30;
    char gap34[0x4];
    int field_38;
    
    void alignment_box(float a1, float a2, float a3);
};

int __cdecl floatToInt(float val);

void RGE_Master_Static_Object::alignment_box(float a1, float a2, float a3) {
    int val = floatToInt(a1);
    float diff = a2 - (float)val;
    
    if ((int)diff > 0) {
        field_38 = val;
    }
}
