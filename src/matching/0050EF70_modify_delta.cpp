// tm_co_ob.cpp:215-229
// The 0x64 path updates each enabled build-inventory amount.  Other
// attributes use the inherited combat-object implementation.

#ifndef TM_CO_OB_SHARED_CONTEXT
class RGE_Master_Combat_Object {
public:
    virtual void modify_delta(float value, unsigned char attribute);
};

class Attribute_Cost {
public:
    short type;
    short amount;
    unsigned char flag;
    unsigned char gap_005;
};

class TRIBE_Master_Combat_Object : public RGE_Master_Combat_Object {
public:
    char gap_04[0x144];
    Attribute_Cost build_inventory[3];

    virtual void modify_delta(float value, unsigned char attribute);
};
#endif

void TRIBE_Master_Combat_Object::modify_delta(float value,
                                               unsigned char attribute) {
    if (attribute != 0x64) {
        RGE_Master_Combat_Object::modify_delta(value, attribute);
        return;
    }

    Attribute_Cost* entry = build_inventory;
    int remaining = 3;

    do {
        if (entry->flag != 0) {
            entry->amount = entry->amount + (short)value;
        }
        ++entry;
    } while (--remaining != 0);
}
