// VA: 00450B40 modify_delta (391B)
// m_co_obj.cpp

class RGE_Master_Combat_Object {
public:
    char gap4[0x100];
    int field_104;
    char gap108[0xBC];
    int field_1C4;
    
    void modify_delta(unsigned char op, float delta);
};

int __cdecl floatToInt(float f);

void RGE_Master_Combat_Object::modify_delta(unsigned char op, float delta) {
    switch (op) {
    case 0:
        floatToInt(delta);
        if (field_104) {
            // Add delta to field
        }
        break;
    default:
        break;
    }
}
