// VA: 004050F0 update (955B)
// ACT_misl.cpp

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int update();
    virtual int set_state(int state);
};

class RGE_Action_Missile : public RGE_Action {
public:
    short typeAt4;              // +04
    char gap6[0x3A];
    int velocity_x;             // +40
    int velocity_y;             // +44
    int velocity_z;             // +48
    int ballistic_velocity;     // +4C
    int ballistic_acceleration; // +50
    char gap54[0x2B4];
    int state;
    
    int update();
};

int RGE_Action_Missile::update() {
    // Update missile position and velocity with ballistic physics
    ballistic_velocity += ballistic_acceleration;
    velocity_x += velocity_x;
    velocity_y += velocity_y;
    velocity_z += velocity_z;
    
    return 0;
}
