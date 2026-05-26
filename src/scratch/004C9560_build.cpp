// VA: 004C9560 TRIBE_Building_Object::build
// PDB source: t_b_obj.cpp
// Retry 2026-05-26 Boss pass: implemented full behavior from packet. Baseline full source reached exact 182B but 79.1209% positional / 30.2198% edit, first mismatch +31; FPU compare/order differed around build_pts + amount and progress clamp.
// Tried 15 probes: sum temp, volatile-param sum (kept; improves to 74.1758% / 28.5714%, first mismatch +8), reversed compare, explicit progress temp, rate temp, mutating param through volatile, raw offset accesses, else-return layout, double casts, and flags /G5 /Op /Ob0 /Oa /Oy- /O1. /Oa, /Oy-, /O1 shrank; /Op broad wrong. GIVEUP: behavior and calls understood, but remaining drift is broad FPU stack/compare branch layout and return/call scheduling, not localized accepted-drift quality.

class BuildingMaster {
public:
    char gap_00[0x26];
    short build_rate;       // +26
    char gap_28[0x132];
    short build_points;     // +15a
};

class TRIBE_Building_Object {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54(); virtual void v58();
    virtual void set_status(int status); // +5c

    char gap_04[4];
    BuildingMaster* master; // +8
    char gap_0c[0x24];
    float progress;         // +30
    char gap_34[0x14];
    unsigned char status;   // +48
    char gap_49[0x193];
    float build_pts;        // +1dc

    unsigned char build(float amount);
};

unsigned char TRIBE_Building_Object::build(float amount)
{
    if (this->status != 0) {
        return 1;
    }

    BuildingMaster* m = this->master;
    float needed = (float)(int)m->build_points;
    float sum = *(volatile float*)&amount + this->build_pts;
    if (needed < sum) {
        amount = needed - this->build_pts;
    }

    this->progress = ((float)(int)m->build_rate * amount) / needed + this->progress;
    if ((float)(int)m->build_rate < this->progress) {
        this->progress = (float)(int)m->build_rate;
    }

    this->build_pts = amount + this->build_pts;
    if (this->build_pts < (float)(int)m->build_points) {
        return 0;
    }

    this->set_status(2);
    return 1;
}
