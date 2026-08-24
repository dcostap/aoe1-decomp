#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    unsigned char is_moving();
};
#endif

unsigned char RGE_Static_Object::is_moving() { return 0; }
