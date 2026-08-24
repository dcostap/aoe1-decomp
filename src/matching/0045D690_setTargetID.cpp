#ifndef MOVE_OBJ_CANONICAL_TU
class RGE_Moving_Object {
public:
    virtual ~RGE_Moving_Object();
    char gap_0[0x134];
    int field_138;
    void setTargetID(int v);
};
#endif

#ifdef MOVE_OBJ_CANONICAL_TU
#define field_138 targetIDValue
#endif

void RGE_Moving_Object::setTargetID(int v) { this->field_138 = v; }

#ifdef MOVE_OBJ_CANONICAL_TU
#undef field_138
#endif
