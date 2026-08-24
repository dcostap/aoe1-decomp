#ifndef MOVE_OBJ_CANONICAL_TU
class RGE_Moving_Object {
public:
    virtual ~RGE_Moving_Object();
    char gap_0[0x84];
    int field_88;
    void stop_moving();
};
#endif

#ifdef MOVE_OBJ_CANONICAL_TU
#define field_88 speed
#endif

void RGE_Moving_Object::stop_moving() { this->field_88 = 0; }

#ifdef MOVE_OBJ_CANONICAL_TU
#undef field_88
#endif
