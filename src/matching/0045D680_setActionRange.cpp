#ifndef MOVE_OBJ_CANONICAL_TU
class RGE_Moving_Object {
public:
    virtual ~RGE_Moving_Object();
    char gap_0[0x130];
    int field_134;
    void setActionRange(int v);
};
#endif

#ifdef MOVE_OBJ_CANONICAL_TU
#define field_134 actionRange
#endif

#ifdef MOVE_OBJ_CANONICAL_TU
void RGE_Moving_Object::setActionRange(float v) { this->field_134 = v; }
#else
void RGE_Moving_Object::setActionRange(int v) { this->field_134 = v; }
#endif

#ifdef MOVE_OBJ_CANONICAL_TU
#undef field_134
#endif
