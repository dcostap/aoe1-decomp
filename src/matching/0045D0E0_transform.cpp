#ifndef MOVE_OBJ_CANONICAL_TU
class RGE_Master_Static_Object;

class RGE_Animated_Object {
public:
    void* vtable_ptr;
    char gap_04[0x84];
    float speed;

    void transform(RGE_Master_Static_Object* master);
};

class RGE_Moving_Object : public RGE_Animated_Object {
public:
    float trail_remainder;
    float velocity_x;
    float velocity_y;
    float velocity_z;
    float angle;
    float turn_towards_time;
    char gap_A4[0x88];
    float turnTimer;
    float collisionAvoidanceDistance;
    void set_angle(void);

    void transform(RGE_Master_Static_Object* master);
};
#endif

void RGE_Moving_Object::transform(RGE_Master_Static_Object* master) {
    this->RGE_Animated_Object::transform(master);
    this->velocity_x = 0.0f;
    this->velocity_y = 0.0f;
    this->velocity_z = 0.0f;
    this->collisionAvoidanceDistance = 0.0f;
    this->turnTimer = 0.0f;
    this->turn_towards_time = 0.0f;
    this->set_angle();
}
