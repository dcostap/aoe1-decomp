#ifndef MOVE_OBJ_CANONICAL_TU
class RGE_Moving_Object {
public:
    char gap_0[0x11C];
    int field_11C;
    int field_120;
    int field_124;
    void setGoal(int a, int b, int c);
};
#endif

#ifdef MOVE_OBJ_CANONICAL_TU
#define field_11C goalValue.x
#define field_120 goalValue.y
#define field_124 goalValue.z
#endif

#ifdef MOVE_OBJ_CANONICAL_TU
void RGE_Moving_Object::setGoal(float a, float b, float c) {
#else
void RGE_Moving_Object::setGoal(int a, int b, int c) {
#endif
    this->field_11C = a;
    this->field_120 = b;
    this->field_124 = c;
}

#ifdef MOVE_OBJ_CANONICAL_TU
#undef field_11C
#undef field_120
#undef field_124
#endif
