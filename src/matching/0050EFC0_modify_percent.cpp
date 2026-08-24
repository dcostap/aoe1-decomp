#ifndef TM_CO_OB_SHARED_CONTEXT
class RGE_Master_Combat_Object {
public:
    virtual void modify_percent(float param_1, unsigned char param_2);
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
    char gap_004[0x144];
    Attribute_Cost build_inventory[3];

    void modify_percent(float param_1, unsigned char param_2);
};
#endif

void TRIBE_Master_Combat_Object::modify_percent(float param_1, unsigned char param_2) {
    if (param_2 != 0x64) {
        RGE_Master_Combat_Object::modify_percent(param_1, param_2);
        return;
    }

    Attribute_Cost* p = build_inventory;
    int i = 3;
    do {
        if (p->flag != 0) {
            p->amount = (short)((float)p->amount * param_1);
        }
        p++;
        i--;
    } while (i != 0);
}
