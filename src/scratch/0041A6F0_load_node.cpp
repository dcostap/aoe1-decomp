// tried the load-node constructor scaffold; still in scratch because VC5 emits a smaller scaffold than the packet
// next lead: revisit only if the EH/constructor shape becomes the right shape to target

extern "C" void __cdecl rge_read(int handle, void* buffer, int size);
extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);
void* operator new(unsigned int size);

class RGE_Sprite;
class RGE_Active_Sprite;
class RGE_Active_Animated_Sprite;

class RGE_Active_Sprite_Node {
public:
    RGE_Active_Sprite* node;
    char gap_04[0x4];
    RGE_Active_Sprite_Node* next;
};

class RGE_Active_Sprite_List {
public:
    virtual ~RGE_Active_Sprite_List();
    virtual short frame(RGE_Sprite* param_1);
    virtual void update(float param_1, float param_2);
    virtual void draw(short param_1, short param_2, short param_3, short param_4, short param_5, class RGE_Color_Table* param_6, class TDrawArea* param_7);
    virtual void normal_draw(short param_1, short param_2, short param_3, class RGE_Color_Table* param_4, class TDrawArea* param_5);
    virtual void shadow_draw(short param_1, short param_2, short param_3, class RGE_Color_Table* param_4, class TDrawArea* param_5, unsigned char param_6);
    virtual unsigned char is_animating(RGE_Sprite* param_1);
    virtual void set_frame(RGE_Sprite* param_1, short param_2);
    virtual unsigned char frame_passed(RGE_Sprite* param_1, short param_2);
    virtual unsigned char looped(RGE_Sprite* param_1);
    virtual short get_facetindex(RGE_Sprite* param_1, short param_2);
    virtual unsigned char load_node(int param_1, unsigned char param_2, RGE_Sprite** param_3);

    RGE_Active_Sprite_Node* list;
    RGE_Active_Sprite_List* owner;

    unsigned char load(int param_1, RGE_Sprite** param_2);
};

class RGE_Active_Sprite {
public:
    RGE_Active_Sprite* RGE_Active_Sprite_ctor(int param_1, RGE_Sprite** param_2);
};

class RGE_Active_Animated_Sprite {
public:
    RGE_Active_Sprite* RGE_Active_Animated_Sprite_ctor(int param_1, RGE_Sprite** param_2);
};

unsigned char RGE_Active_Sprite_List::load_node(int param_1, unsigned char param_2, RGE_Sprite** param_3) {
    RGE_Active_Sprite_Node* pRVar1;
    RGE_Active_Animated_Sprite* this_00;
    RGE_Active_Sprite* pRVar2;

    if (param_2 == 0) {
        return 0;
    }
    if (param_2 == 1) {
        pRVar1 = (RGE_Active_Sprite_Node*)calloc(0xc, 1);
        pRVar2 = (RGE_Active_Sprite*)operator new(0x14);
        if (pRVar2 != 0) {
            pRVar2 = pRVar2->RGE_Active_Sprite_ctor(param_1, param_3);
            pRVar1->node = pRVar2;
            pRVar1->next = this->list;
            this->list = pRVar1;
            return 1;
        }
    }
    else if (param_2 == 2) {
        pRVar1 = (RGE_Active_Sprite_Node*)calloc(0xc, 1);
        this_00 = (RGE_Active_Animated_Sprite*)operator new(0x28);
        if (this_00 != 0) {
            pRVar2 = (RGE_Active_Sprite*)this_00->RGE_Active_Animated_Sprite_ctor(param_1, param_3);
            pRVar1->node = pRVar2;
            pRVar1->next = this->list;
            this->list = pRVar1;
            return 1;
        }
    }
    pRVar1->node = 0;
    pRVar1->next = this->list;
    this->list = pRVar1;
    return 1;
}
