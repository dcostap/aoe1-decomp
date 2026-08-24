#ifndef MOVE_OBJ_CANONICAL_TU
class RGE_Moving_Object {
public:
    char gap_0[0x13C];
    int field_13C;
    int field_140;
    void setTargetRadius(int a, int b);
};
#endif

#ifdef MOVE_OBJ_CANONICAL_TU
#define field_13C targetRadiusX
#define field_140 targetRadiusY
#endif

#ifdef MOVE_OBJ_CANONICAL_TU
void RGE_Moving_Object::setTargetRadius(float a, float b) {
#else
void RGE_Moving_Object::setTargetRadius(int a, int b) {
#endif
    this->field_13C = a;
    this->field_140 = b;
}

#ifdef MOVE_OBJ_CANONICAL_TU
#undef field_13C
#undef field_140
#endif
