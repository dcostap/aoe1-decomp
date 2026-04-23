extern "C" void __cdecl rge_write(int handle, void* buffer, int size);

class RGE_Static_Object {
public:
    virtual void save(int handle);
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    char gap_04[0x84];
    float speed;

    void save(int handle);
};

void RGE_Animated_Object::save(int handle) {
    RGE_Static_Object::save(handle);
    rge_write(handle, &this->speed, 4);
}
