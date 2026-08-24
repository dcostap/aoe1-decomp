#ifndef MOVE_OBJ_CANONICAL_TU
class RGE_Moving_Object_Master {
public:
    char gap_00[0x64];
    float speed_multiplier;
};

class RGE_Moving_Object_Type {
public:
    char gap_00[0xB8];
    float maximum_speed;
};

class RGE_Moving_Object {
public:
    char gap_00[0x04];
    RGE_Moving_Object_Type* type;
    int gap_0C;
    RGE_Moving_Object_Master* master;

    virtual float maximumSpeed(void);
};
#endif

#ifdef MOVE_OBJ_CANONICAL_TU
#define type master_obj
#define master master_obj
#define speed_multiplier radius_x
#define maximum_speed radius_y
#endif

float RGE_Moving_Object::maximumSpeed(void) {
    if (this->master != 0 && this->master->speed_multiplier > 0.0) {
        return this->type->maximum_speed * this->master->speed_multiplier;
    }
    return this->type->maximum_speed;
}

#ifdef MOVE_OBJ_CANONICAL_TU
#undef type
#undef master
#undef speed_multiplier
#undef maximum_speed
#endif
