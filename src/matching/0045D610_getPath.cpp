#ifndef MOVE_OBJ_CANONICAL_TU
class RGE_Moving_Object {
public:
    virtual ~RGE_Moving_Object();
    char gap_0[0xA0];
    char field_A4[1];
    char* getPath();
};
#endif

#ifdef MOVE_OBJ_CANONICAL_TU
Path* RGE_Moving_Object::getPath() { return &this->pathValue; }
#else
char* RGE_Moving_Object::getPath() { return this->field_A4; }
#endif
