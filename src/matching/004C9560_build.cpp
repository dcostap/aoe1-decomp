// VA: 004C9560 TRIBE_Building_Object::build
// PDB source: t_b_obj.cpp
// Retry 2026-05-26 Boss pass: implemented full behavior from packet; reached exact size but broad FPU/return-tail drift.
// MATCH 2026-05-31: inline volatile reads of the float parameter for both build_pts sums forced the original fld-param/fadd-member order; spelling the status gate as a positive outer `if (status == 0)` kept the late return-1 tail; spelling completion as a positive `>=` branch preserved the call/fail/late-success tail order.

#include "../../include/t_b_obj_context.h"

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
