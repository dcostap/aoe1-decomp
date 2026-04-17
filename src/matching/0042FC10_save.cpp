extern "C" void rge_write(int handle, void* buffer, int size);

class RGE_Action_Object {
public:
    virtual void save(int handle);
};

class RGE_Combat_Object : public RGE_Action_Object {
public:
    unsigned char gap_04[0x1B8];
    float attack_timer;
    unsigned char capture_flag;

    virtual void save(int handle);
};

void RGE_Combat_Object::save(int handle) {
    RGE_Action_Object::save(handle);
    rge_write(handle, &attack_timer, 4);
    rge_write(handle, &capture_flag, 1);
}
