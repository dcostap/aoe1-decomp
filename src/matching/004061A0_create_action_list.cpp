void* __cdecl operator new(unsigned int size);

class RGE_Action_Object;

class RGE_Action_List {
public:
    virtual void vf00(void);

    RGE_Action_Object* obj;
    void* list;

    RGE_Action_List(RGE_Action_Object* obj);
};

class RGE_Action_Object {
public:
    RGE_Action_List* create_action_list(void);
};

RGE_Action_List* RGE_Action_Object::create_action_list(void) {
    return new RGE_Action_List(this);
}
