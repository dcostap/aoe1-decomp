#ifndef RGE_MS_OBJ_SHARED_CONTEXT
class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_0[0x98];
    int help_page_id;
    long get_help_page();
};
#endif

long RGE_Master_Static_Object::get_help_page() { return this->help_page_id; }
