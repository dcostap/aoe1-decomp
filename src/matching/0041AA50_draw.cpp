class RGE_Color_Table;
class TDrawArea;

class RGE_Active_Sprite {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void draw(short param_1, long param_2, long param_3,
                      long param_4, long param_5, RGE_Color_Table* param_6,
                      TDrawArea* param_7);
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

    void draw(short param_1, short param_2, short param_3,
              short param_4, short param_5, RGE_Color_Table* param_6,
              TDrawArea* param_7);
};

void RGE_Active_Sprite_List::draw(short param_1, short param_2, short param_3,
                                  short param_4, short param_5, RGE_Color_Table* param_6,
                                  TDrawArea* param_7) {
    RGE_Active_Sprite_Node* node = this->list;

    while (node) {
        node->node->draw(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
        node = node->next;
    }
}
