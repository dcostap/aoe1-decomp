class RGE_Sprite;

class RGE_Active_Sprite {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual short frame();
    virtual unsigned char is_animating();
    virtual void set_frame(short param_1);
    virtual unsigned char frame_passed(short param_1);
    virtual unsigned char looped();
    virtual short get_facetindex(short param_1);

    RGE_Sprite* sprite;
};

class RGE_Active_Sprite_Node {
public:
    RGE_Active_Sprite* node;
    unsigned char order;
    unsigned char count;
    char gap_06[0x2];
    RGE_Active_Sprite_Node* next;
};

class RGE_Active_Sprite_List {
public:
    void* vtable_ptr;
    RGE_Active_Sprite_Node* list;

    short get_facetindex(RGE_Sprite* param_1, short param_2);
};

short RGE_Active_Sprite_List::get_facetindex(RGE_Sprite* param_1, short param_2) {
    RGE_Active_Sprite_Node* node = this->list;

    while (node) {
        if (node->node->sprite == param_1) {
            return node->node->get_facetindex(param_2);
        }
        node = node->next;
    }

    return 0;
}
