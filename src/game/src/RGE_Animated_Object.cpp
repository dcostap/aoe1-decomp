#include "../include/RGE_Animated_Object.h"
#include "../include/RGE_Game_World.h"
#include "../include/globals.h"

// Default constructor for make_new_obj usage
RGE_Animated_Object::RGE_Animated_Object()
    : RGE_Static_Object()
{
    this->speed = 0.0f;
}

// Fully verified. Source of truth: ani_obj.cpp.decomp @ 0x0041A210
RGE_Animated_Object::RGE_Animated_Object(int param_1, RGE_Game_World* param_2, int param_3)
    : RGE_Static_Object(param_1, param_2, 0)
{
    // vtable is set implicitly by C++
    if (param_3 != 0) {
        this->setup(param_1, param_2);
    }
}

// Fully verified. Source of truth: ani_obj.cpp.decomp @ 0x0041A310
int RGE_Animated_Object::setup(int param_1, RGE_Game_World* param_2) {
    RGE_Static_Object::setup(param_1, param_2);
    this->type = 0x14;
    rge_read(param_1, &this->speed, 4);
    return 1;
}
