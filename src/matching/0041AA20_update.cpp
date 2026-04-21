class RGE_Active_Sprite {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void update(float param_1, float param_2);
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

    void update(float param_1, float param_2);
};

void RGE_Active_Sprite_List::update(float param_1, float param_2) {
    RGE_Active_Sprite_Node* node = this->list;

    if (node) {
        float p2 = param_2;
        float p1 = param_1;

        do {
            node->node->update(p1, p2);
            node = node->next;
        } while (node);
    }
}
