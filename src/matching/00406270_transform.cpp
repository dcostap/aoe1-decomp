class RGE_Master_Static_Object;

class RGE_Action_List {
public:
    void delete_list(void);
};

class RGE_Moving_Object {
public:
    void* vtable_ptr;

    void transform(RGE_Master_Static_Object* master);
};

class RGE_Action_Object : public RGE_Moving_Object {
public:
    char gap_04[0x180];
    RGE_Action_List* actions;

    void transform(RGE_Master_Static_Object* master);
};

void RGE_Action_Object::transform(RGE_Master_Static_Object* master) {
    RGE_Moving_Object::transform(master);
    this->actions->delete_list();
}
