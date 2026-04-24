class RGE_Master_Combat_Object {
public:
    virtual void modify_percent(float param_1, unsigned char param_2);
};

class TRIBE_Master_Combat_Object : public RGE_Master_Combat_Object {
public:
    char gap_000[0x146];

    void modify_percent(float param_1, unsigned char param_2);
};

void TRIBE_Master_Combat_Object::modify_percent(float param_1, unsigned char param_2) {
    if (param_2 != 0x64) {
        RGE_Master_Combat_Object::modify_percent(param_1, param_2);
        return;
    }

    short* p = (short*)(this->gap_000 + 0x146);
    int i = 3;
    do {
        if (*((unsigned char*)p + 2) != 0) {
            p[0] = (short)((float)p[0] * param_1);
        }
        p += 3;
        i--;
    } while (i != 0);
}
