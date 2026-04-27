// VA: 004547F0 draw (348B)
// m_s_obj.cpp

class RGE_Master_Static_Object {
public:
    char gap4[0x14];
    int field_18;
    char gap1C[0x4];
    int field_20;
    char gap24[0x4];
    int field_28;
    
    void draw(int x, int y, int z);
};

void RGE_Master_Static_Object::draw(int x, int y, int z) {
    if (!field_18) return;
    
    field_20 = x;
    field_28 = y;
}
