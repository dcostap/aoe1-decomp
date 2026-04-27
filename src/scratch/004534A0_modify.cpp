// VA: 004534A0 modify (115B)
// m_s_obj.cpp

class RGE_Master_Static_Object {
public:
    char gap4[0x22];
    short field_26;
    
    void modify(float value);
};

int __cdecl floatToInt(float val);

void RGE_Master_Static_Object::modify(float value) {
    int op = ((int)value) & 0xFF;
    if (op > 0x0E) return;
    
    // Jump table dispatch on op
    switch (op) {
        case 0:
            floatToInt(value);
            break;
    }
}
