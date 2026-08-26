#ifndef MOVE_OBJ_CANONICAL_TU
class Path {
public:
    char gap_00[0x80];
};

class RGE_Moving_Object {
public:
    virtual ~RGE_Moving_Object();
    char gap_0[0xA0];
    Path pathValue;
    const Path& getPath() const;
};
#endif

#ifdef MOVE_OBJ_CANONICAL_TU
const Path& RGE_Moving_Object::getPath() const { return this->pathValue; }
#else
const Path& RGE_Moving_Object::getPath() const { return this->pathValue; }
#endif
