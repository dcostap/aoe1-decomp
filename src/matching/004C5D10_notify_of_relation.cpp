#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void notify_of_relation(long p0, unsigned char p1);
};

#endif

void RGE_Static_Object::notify_of_relation(long p0, unsigned char p1) {}
