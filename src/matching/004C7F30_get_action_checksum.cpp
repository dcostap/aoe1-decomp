#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    int get_action_checksum();
};
#endif

int RGE_Static_Object::get_action_checksum() { return 0; }
