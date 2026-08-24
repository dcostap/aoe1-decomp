#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_0[0x64];
    int field_68;
    int inGroup();
};
#endif

int RGE_Static_Object::inGroup() { return this->field_68 > 0; }
