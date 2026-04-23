extern "C" void __cdecl rge_write(int handle, void* buffer, int size);

class RGE_Combat_Object {
public:
    virtual void save(int handle);
};

class RGE_Missile_Object : public RGE_Combat_Object {
public:
    char gap_04[0x1C0];
    float max_range;

    void save(int handle);
};

void RGE_Missile_Object::save(int handle) {
    RGE_Combat_Object::save(handle);
    rge_write(handle, &this->max_range, 4);
}
