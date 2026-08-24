#ifndef MOVE_OBJ_CANONICAL_TU
class RGE_Moving_Object {
public:
    char gap_00[0x88];
    float move_speed;

    unsigned char is_moving();
};
#endif

#ifdef MOVE_OBJ_CANONICAL_TU
#define move_speed speed
#endif

unsigned char RGE_Moving_Object::is_moving() {
    if (this->move_speed > 0.0f) {
        return 1;
    }
    return 0;
}

#ifdef MOVE_OBJ_CANONICAL_TU
#undef move_speed
#endif
