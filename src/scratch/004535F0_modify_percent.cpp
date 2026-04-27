// VA: 004535F0 modify_percent (165B)
// m_s_obj.cpp

class RGE_Master_Static_Object {
public:
    char gap4[0x22];
    short field_26;
    
    void modify_percent(float value);
};

int __cdecl floatToInt(float val);

void RGE_Master_Static_Object::modify_percent(float value) {
    int op = ((int)value) & 0xFF;
    if (op > 0x0E) return;
    
    switch (op) {
        case 0:
            field_26 = floatToInt(value);
            break;
    }
}
