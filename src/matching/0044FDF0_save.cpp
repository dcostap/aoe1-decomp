#ifndef RGE_MAN_OBJ_SHARED_CONTEXT
extern "C" void __cdecl rge_write(int handle, void* buffer, int size);

class RGE_Master_Static_Object {
public:
    virtual void save(int handle);
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    char gap_04[0xB4];
    float speed;

    void save(int handle);
};
#endif

void RGE_Master_Animated_Object::save(int handle) {
    RGE_Master_Static_Object::save(handle);
    rge_write(handle, &this->speed, 4);
}
