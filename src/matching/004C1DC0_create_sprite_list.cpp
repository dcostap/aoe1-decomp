// attempt log:
// first pass: straight new-expression wrapper with the live EH/new prolog in mind
// second pass: add a per-function /GX rsp because this helper lives in the EH/new constructor family
// rsp used: config/flags/004C1DC0_create_sprite_list.rsp = /nologo /c /O2 /Oy /GX
// target shape: return new RGE_Active_Sprite_List(this);

class RGE_Static_Object;
class RGE_Active_Sprite_Node;

class RGE_Active_Sprite_List {
public:
    void* vtable_ptr;
    RGE_Active_Sprite_Node* list;
    RGE_Static_Object* owner;

    RGE_Active_Sprite_List(RGE_Static_Object* owner);
};

class RGE_Static_Object {
public:
    RGE_Active_Sprite_List* create_sprite_list(void);
};

RGE_Active_Sprite_List* RGE_Static_Object::create_sprite_list(void) {
    return new RGE_Active_Sprite_List(this);
}
