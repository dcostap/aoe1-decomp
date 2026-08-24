#ifndef ASP_LIST_SHARED_CONTEXT
class RGE_Static_Object;
class RGE_Active_Sprite_Node;

class RGE_Active_Sprite_List {
public:
    virtual ~RGE_Active_Sprite_List();
    RGE_Active_Sprite_Node* list;
    RGE_Static_Object* owner;

    RGE_Active_Sprite_List(RGE_Static_Object* owner);
};
#endif

RGE_Active_Sprite_List::RGE_Active_Sprite_List(RGE_Static_Object* owner) {
    this->list = 0;
    this->owner = owner;
}
