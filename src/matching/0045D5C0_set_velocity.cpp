#ifndef MOVE_OBJ_CANONICAL_TU
class RGE_Moving_Object {
public:
    char gap_0[0x90];
    int field_90;
    int field_94;
    int field_98;
    void set_velocity(int a, int b, int c);
};
#endif

#ifdef MOVE_OBJ_CANONICAL_TU
#define field_90 velocity_x
#define field_94 velocity_y
#define field_98 velocity_z
#endif

#ifdef MOVE_OBJ_CANONICAL_TU
void RGE_Moving_Object::set_velocity(float a, float b, float c) {
#else
void RGE_Moving_Object::set_velocity(int a, int b, int c) {
#endif
    this->field_90 = a;
    this->field_94 = b;
    this->field_98 = c;
}

#ifdef MOVE_OBJ_CANONICAL_TU
#undef field_90
#undef field_94
#undef field_98
#endif
