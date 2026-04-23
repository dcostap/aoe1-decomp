class TRIBE_Master_Combat_Object {
public:
    virtual void modify(float value, unsigned char attribute);
};

class TRIBE_Master_Building_Object : public TRIBE_Master_Combat_Object {
public:
    char gap_04[0x16A];
    short building_facet;

    virtual void modify(float value, unsigned char attribute);
};

void TRIBE_Master_Building_Object::modify(float value, unsigned char attribute) {
    if (attribute != 0x11) {
        TRIBE_Master_Combat_Object::modify(value, attribute);
        return;
    }
    this->building_facet = (short)value;
}
