#ifndef RGE_MS_OBJ_SHARED_CONTEXT
class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_0[0x94];
    int help_string_id;
    int get_help_message();
};
#endif

int RGE_Master_Static_Object::get_help_message() { return this->help_string_id; }
