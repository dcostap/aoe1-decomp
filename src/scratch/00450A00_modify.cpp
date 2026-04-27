// VA: 00450A00 modify (265B)
// m_co_obj.cpp

class RGE_Master_Combat_Object {
public:
    char gap4[0x100];
    int field_104;
    char gap108[0xBC];
    int field_1C4;
    
    void modify(unsigned char op, float value);
};

int __cdecl floatToInt(float f);

void RGE_Master_Combat_Object::modify(unsigned char op, float value) {
    switch (op) {
    case 8:
        floatToInt(value);
        if (field_104) {
            // Modify field
        }
        break;
    case 9:
    case 10:
        // More cases
        break;
    default:
        break;
    }
}
