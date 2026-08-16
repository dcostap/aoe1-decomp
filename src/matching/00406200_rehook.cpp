class RGE_Action_List {
public:
    void rehook();
};

class RGE_Static_Object {
public:
    virtual void rehook();
};

class RGE_Action_Object : public RGE_Static_Object {
public:
    char gap_04[0x180];
    RGE_Action_List* actions;

    virtual void rehook();
};

void RGE_Action_Object::rehook() {
    RGE_Static_Object::rehook();
    this->actions->rehook();
}
