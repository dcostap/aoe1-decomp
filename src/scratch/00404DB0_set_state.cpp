// VA: 00404DB0 set_state (805B)
// ACT_misl.cpp lines 91-200

class RGE_Action {
public:
    virtual ~RGE_Action();
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
    int state;                  // ~+0x308
    
    int set_state(int state);
};

int RGE_Action_Missile::set_state(int state) {
    // Call base class set_state first
    RGE_Action::set_state(state);
    
    // Handle missile-specific state transitions
    if (state == 0) {
        velocity_x = 0;
        velocity_y = 0;
        velocity_z = 0;
        ballistic_velocity = 0;
        ballistic_acceleration = 0;
    }
    
    return 0;
}
