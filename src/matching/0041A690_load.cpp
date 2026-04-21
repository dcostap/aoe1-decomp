extern "C" void __cdecl rge_read(int handle, void* buffer, int size);

class RGE_Color_Table;
class RGE_Sprite;
class TDrawArea;
class RGE_Static_Object;

class RGE_Active_Sprite_Node {
public:
    char gap_00[0x8];
    RGE_Active_Sprite_Node* next;
};

class RGE_Active_Sprite_List {
public:
    virtual ~RGE_Active_Sprite_List();
    virtual short frame(RGE_Sprite* param_1);
    virtual void update(float param_1, float param_2);
    virtual void draw(short param_1, short param_2, short param_3, short param_4, short param_5, RGE_Color_Table* param_6, TDrawArea* param_7);
    virtual void normal_draw(short param_1, short param_2, short param_3, RGE_Color_Table* param_4, TDrawArea* param_5);
    virtual void shadow_draw(short param_1, short param_2, short param_3, RGE_Color_Table* param_4, TDrawArea* param_5, unsigned char param_6);
    virtual unsigned char is_animating(RGE_Sprite* param_1);
    virtual void set_frame(RGE_Sprite* param_1, short param_2);
    virtual unsigned char frame_passed(RGE_Sprite* param_1, short param_2);
    virtual unsigned char looped(RGE_Sprite* param_1);
    virtual short get_facetindex(RGE_Sprite* param_1, short param_2);
    virtual unsigned char load_node(int param_1, unsigned char param_2, RGE_Sprite** param_3);

    RGE_Active_Sprite_Node* list;
    RGE_Static_Object* owner;

    void load(int param_1, RGE_Sprite** param_2);
};

void RGE_Active_Sprite_List::load(int param_1, RGE_Sprite** param_2) {
    unsigned char cVar4;
    RGE_Active_Sprite_Node* pRVar2;
    RGE_Active_Sprite_Node* pRVar5;
    RGE_Sprite** ppRVar3;

    ppRVar3 = param_2;
    do {
        rge_read(param_1, &param_2, 1);
        cVar4 = this->load_node(param_1, (unsigned char)param_2, ppRVar3);
    } while (cVar4 != 0);

    pRVar5 = 0;
    while (this->list != 0) {
        pRVar2 = this->list->next;
        this->list->next = pRVar5;
        pRVar5 = this->list;
        this->list = pRVar2;
    }
    this->list = pRVar5;
}
