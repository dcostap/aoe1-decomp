// VA: 004CA640 TRIBE_Combat_Object::modify
// PDB source: t_c_obj.cpp

#ifndef T_C_OBJ_CONTEXT_H
class RGE_Static_Object {
public:
    virtual void modify(float value, unsigned char attribute);
};

class TribeStats {
public:
    char gap_00[0x10];
    float f10;
    char gap_14[0x18];
    float f2c;
    char gap_30[0x1c];
    float f4c;
};

class TribePlayerSub {
public:
    char gap_00[0x50];
    TribeStats* stats;
};

class TRIBE_Combat_Object : public RGE_Static_Object {
public:
    char gap_04[4];
    char* master; // +8
    TribePlayerSub* sub; // +c

    virtual void modify(float value, unsigned char attribute);
};
#endif

void TRIBE_Combat_Object::modify(float value, unsigned char attribute)
{
    if (attribute == 0x65) {
        int value_off = 0x70;
        int type_off = 0x6a;
        do {
            if (*(short*)(this->master + type_off) == 4) {
                TribeStats* s = this->sub->stats;
                s->f10 = s->f10 - *(float*)(this->master + value_off);
                s = this->sub->stats;
                s->f10 = *(volatile float*)&value + s->f10;
            }
            if (*(short*)(this->master + type_off) == 0x0b) {
                TribeStats* s = this->sub->stats;
                s->f2c = s->f2c - *(float*)(this->master + value_off);
                s = this->sub->stats;
                s->f2c = s->f2c - value;
            }
            if (*(short*)(this->master + type_off) == 0x13) {
                TribeStats* s = this->sub->stats;
                s->f4c = s->f4c - *(float*)(this->master + value_off);
                s = this->sub->stats;
                s->f4c = s->f4c - value;
            }
            type_off += 2;
            value_off += 4;
        } while (type_off < 0x70);
    }
    RGE_Static_Object::modify(value, attribute);
}
