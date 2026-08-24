#ifndef T_B_OBJ_CONTEXT_H
class TRIBE_Combat_Object {
public:
    virtual void modify(float value, unsigned char attribute);
};

class TRIBE_Building_Object : public TRIBE_Combat_Object {
public:
    char gap_04[0x31];
    unsigned char field_35;

    virtual void modify(float value, unsigned char attribute);
};
#endif

void TRIBE_Building_Object::modify(float value, unsigned char attribute) {
    if (attribute != 0x11) {
        TRIBE_Combat_Object::modify(value, attribute);
        return;
    }
    this->field_35 = (unsigned char)value;
}
