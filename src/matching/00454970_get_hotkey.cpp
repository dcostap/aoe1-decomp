#ifndef RGE_MS_OBJ_SHARED_CONTEXT
class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_0[0x9C];
    int hotkey_id;
    long get_hotkey();
};
#endif

long RGE_Master_Static_Object::get_hotkey() { return this->hotkey_id; }
