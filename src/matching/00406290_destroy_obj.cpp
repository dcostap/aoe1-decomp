class RGE_Action_List {
public:
    void delete_list(void);
};

class RGE_Static_Object {
public:
    void* vtable_ptr;

    void destroy_obj(void);
};

class RGE_Action_Object : public RGE_Static_Object {
public:
    char gap_04[0x180];
    RGE_Action_List* actions;

    void destroy_obj(void);
};

void RGE_Action_Object::destroy_obj(void) {
    this->actions->delete_list();
    RGE_Static_Object::destroy_obj();
}
