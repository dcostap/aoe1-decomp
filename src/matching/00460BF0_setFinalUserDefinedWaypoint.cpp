#ifndef MOVE_OBJ_CANONICAL_TU
class RGE_Moving_Object {
public:
    virtual ~RGE_Moving_Object();
    char gap_0[0x170];
    unsigned char field_174;
    void setFinalUserDefinedWaypoint();
};
#endif

#ifdef MOVE_OBJ_CANONICAL_TU
#define field_174 finalUserDefinedWaypoint
#endif

void RGE_Moving_Object::setFinalUserDefinedWaypoint() { this->field_174 = 1; }

#ifdef MOVE_OBJ_CANONICAL_TU
#undef field_174
#endif
