class RGE_Combat_Object {
public:
    virtual void update();
};

class RGE_Missile_Object : public RGE_Combat_Object {
public:
    void update();
};

void RGE_Missile_Object::update() { RGE_Combat_Object::update(); }
