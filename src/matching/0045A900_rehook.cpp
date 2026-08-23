#ifndef RGE_MISL_OBJ_SHARED_CONTEXT
class RGE_Action_Object {
public:
    virtual void rehook();
};

class RGE_Missile_Object : public RGE_Action_Object {
public:
    void rehook();
};
#endif

void RGE_Missile_Object::rehook() { RGE_Action_Object::rehook(); }
