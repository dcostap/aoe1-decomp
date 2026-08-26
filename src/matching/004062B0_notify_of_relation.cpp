#ifndef ACT_OBJ_CONTEXT_H
class RGE_Action_Object {
public:
    virtual ~RGE_Action_Object();
    void notify_of_relation(int p0, int p1);
};
#endif

void RGE_Action_Object::notify_of_relation(long p0, uchar p1) {}
