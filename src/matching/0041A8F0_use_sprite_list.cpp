class RGE_Active_Sprite_Node;

class RGE_Active_Sprite_List {
public:
    void* vtable_ptr;
    RGE_Active_Sprite_Node* list;

    void delete_list();
    void use_sprite_list(RGE_Active_Sprite_Node* list);
};

void RGE_Active_Sprite_List::use_sprite_list(RGE_Active_Sprite_Node* list) {
    this->delete_list();
    this->list = list;
}
