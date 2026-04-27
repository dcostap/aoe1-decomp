// attempt 1: direct guard + FPU expression with the __ftol byte store
// result: exact match after keeping the original FPU basin and the late byte store to +0x35
// moved to src\matching\0045D360_set_angle.cpp after local validation

class RGE_Master_Object {
public:
    char gap_00[0x60];
    short facings;
    char gap_62[0xE];
    unsigned char flags;
};

class RGE_Moving_Object {
public:
    char gap_00[0x10];
    RGE_Master_Object* master;
    char gap_14[0x21];
    unsigned char field_35;
    char gap_36[0x66];
    float angle;

    void set_angle();
};

extern float DAT_00570b88;
extern float DAT_00570b78;
extern float DAT_00570b80;
extern float DAT_00570b48;

void RGE_Moving_Object::set_angle() {
    RGE_Master_Object* master = this->master;
    if (master == 0 || (master->flags & 2) == 0 || master->facings <= 0) {
        this->field_35 = 0;
        return;
    }

    float temp = this->angle - DAT_00570b88;
    int facings = master->facings;
    temp = temp * (float)facings;
    temp = temp * DAT_00570b78;
    temp = temp - DAT_00570b80;
    if (temp < DAT_00570b48) {
        temp = temp + (float)facings;
    }
    this->field_35 = (unsigned char)((int)temp);
}
