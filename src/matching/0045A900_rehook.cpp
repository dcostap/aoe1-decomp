class RGE_Action_Object {
public:
    virtual void rehook();
};

class RGE_Missile_Object : public RGE_Action_Object {
public:
    void rehook();
};

void RGE_Missile_Object::rehook() { RGE_Action_Object::rehook(); }
