#ifndef MOVE_OBJ_CANONICAL_TU
class RGE_Moving_Object {
public:
    virtual ~RGE_Moving_Object();
    char gap_0[0x151];
    unsigned char field_155;
    void setWaitingToMove(unsigned char v);
};
#endif

#ifdef MOVE_OBJ_CANONICAL_TU
#define field_155 waitingToMoveValue
#endif

void RGE_Moving_Object::setWaitingToMove(unsigned char v) { this->field_155 = v; }

#ifdef MOVE_OBJ_CANONICAL_TU
#undef field_155
#endif
