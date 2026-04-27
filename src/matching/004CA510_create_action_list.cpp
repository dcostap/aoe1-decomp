// attempt log:
// first pass: straight new-expression wrapper with the EH/new prolog family in mind
// second pass: add a per-function /GX rsp because this helper is the same constructor/new family as create_sprite_list
// rsp used: config/flags/004CA510_create_action_list.rsp = /nologo /c /O2 /Oy /GX
// target shape: return new TRIBE_Action_List(this);

class RGE_Action_Object;

class RGE_Action_List {
public:
    virtual void vf00(void);
    RGE_Action_Object* obj;
    void* list;

    RGE_Action_List(RGE_Action_Object* object);
};

class TRIBE_Action_List : public RGE_Action_List {
public:
    TRIBE_Action_List(RGE_Action_Object* object);
};

class RGE_Action_Object {
public:
    virtual RGE_Action_List* create_action_list(void);
};

class TRIBE_Combat_Object : public RGE_Action_Object {
public:
    RGE_Action_List* create_action_list(void);
};

RGE_Action_List* TRIBE_Combat_Object::create_action_list(void) {
    return new TRIBE_Action_List(this);
}
