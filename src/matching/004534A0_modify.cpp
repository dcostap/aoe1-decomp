// VA: 004534A0 modify (115B)
// m_s_obj.cpp

#ifndef RGE_MS_OBJ_SHARED_CONTEXT
class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x22];
    short hp;           // +0x26
    float los;          // +0x28
    unsigned char obj_max; // +0x2C
    char gap_2D[0x3];
    float radius_x;     // +0x30
    float radius_y;     // +0x34
    char gap_38[0x44];
    short attribute_max_amount; // +0x7C

    void modify(float value, unsigned char op);
};
#endif

void RGE_Master_Static_Object::modify(float value, unsigned char op) {
    switch (op) {
        case 0:
            hp = (short)(long)value;
            break;
        case 1:
            los = value;
            break;
        case 2:
            obj_max = (unsigned char)(long)value;
            break;
        case 3:
            radius_x = value;
            break;
        case 4:
            radius_y = value;
            break;
        case 14:
            attribute_max_amount = (short)(long)value;
            break;
    }
}
