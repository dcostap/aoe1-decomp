// VA: 00450D00 modify_percent (234B)
// m_co_obj.cpp

class RGE_Master_Combat_Object {
public:
    char gap4[0xC0];
    float field_C4;
    
    void modify_percent(unsigned char op, float pct);
};

void RGE_Master_Combat_Object::modify_percent(unsigned char op, float pct) {
    switch (op) {
    case 6:
        field_C4 *= pct;
        break;
    default:
        break;
    }
}
