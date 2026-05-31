// VA: 004C9560 TRIBE_Building_Object::build
// PDB source: t_b_obj.cpp
// Retry 2026-05-26 Boss pass: implemented full behavior from packet; reached exact size but broad FPU/return-tail drift.
// MATCH 2026-05-31: inline volatile reads of the float parameter for both build_pts sums forced the original fld-param/fadd-member order; spelling the status gate as a positive outer `if (status == 0)` kept the late return-1 tail; spelling completion as a positive `>=` branch preserved the call/fail/late-success tail order.

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
    if (this->status == 0) {
        BuildingMaster* m = this->master;
        float needed = (float)(int)m->build_points;
        if (*(volatile float*)&amount + this->build_pts > needed) {
            amount = needed - this->build_pts;
        }

        this->progress = ((float)(int)m->build_rate * amount) / needed + this->progress;
        if (this->progress > (float)(int)m->build_rate) {
            this->progress = (float)(int)m->build_rate;
        }

        this->build_pts = *(volatile float*)&amount + this->build_pts;
        if (this->build_pts >= (float)(int)m->build_points) {
            this->set_status(2);
            return 1;
        }
        return 0;
    }
    return 1;
}
