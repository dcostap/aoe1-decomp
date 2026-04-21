class RGE_Static_Object;
class RGE_Active_Sprite_Node;

class RGE_Active_Sprite_List {
public:
    void* vtable_ptr;
    RGE_Active_Sprite_Node* list;
    RGE_Static_Object* owner;

    RGE_Active_Sprite_List(RGE_Static_Object* owner);
};

RGE_Active_Sprite_List::RGE_Active_Sprite_List(RGE_Static_Object* owner) {
    this->vtable_ptr = (void*)0x56EE08;
    this->list = 0;
    this->owner = owner;
}
