extern "C" void __cdecl rge_write(int handle, void* buffer, int size);

class RGE_Action_List {
public:
    void save(int handle);
};

class RGE_Moving_Object {
public:
    void save(int handle);
};

class RGE_Action_Object {
public:
    char gap_00[0x180];
    unsigned char waiting;
    char gap_181[0x03];
    RGE_Action_List* actions;
    unsigned char command_flag;

    void save(int handle);
};

void RGE_Action_Object::save(int handle) {
    ((RGE_Moving_Object*)this)->RGE_Moving_Object::save(handle);
    rge_write(handle, &this->waiting, 1);
    rge_write(handle, &this->command_flag, 1);
    this->actions->save(handle);
}
