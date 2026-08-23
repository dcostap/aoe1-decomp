struct InnerObj_004315B0 {
    char gap_0[0x138];
    float minimumWeaponRange;
};

class RGE_Static_Object {
public:
    char gap_0[8];
    InnerObj_004315B0 *ptr;
    float minimumWeaponRange();
};

float RGE_Static_Object::minimumWeaponRange() {
    return this->ptr->minimumWeaponRange;
}
