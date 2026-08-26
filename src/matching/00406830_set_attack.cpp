#ifndef ACT_OBJ_CONTEXT_H
class RGE_Action_Object {
public:
    virtual ~RGE_Action_Object();
    void set_attack(int p0);
};
#endif

void RGE_Action_Object::set_attack(RGE_Static_Object* p0) {}
