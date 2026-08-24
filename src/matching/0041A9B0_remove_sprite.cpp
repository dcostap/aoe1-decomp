// 0041A9B0 RGE_Active_Sprite_List::remove_sprite
// current: integrated while loop to match original not-found early epilogue; virtual destroy for slot-0 dispatch.

extern "C" void __cdecl free(void* block);

#ifndef ASP_LIST_SHARED_CONTEXT
class RGE_Sprite;
class RGE_Static_Object;

class RGE_Active_Sprite {
public:
    virtual void destroy(int);
    RGE_Sprite* sprite;
    int check_for_shadows();
};

class RGE_Sprite {};
class RGE_Static_Object { public: void remove_shadows(); };

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
    RGE_Static_Object* owner;
    void remove_sprite(RGE_Sprite* param_1);
};
#endif

void RGE_Active_Sprite_List::remove_sprite(RGE_Sprite* param_1) {
    RGE_Active_Sprite_Node* p = this->list;
    RGE_Active_Sprite_Node** ppPrev = &this->list;
    if (p != 0) {
        while (p != 0) {
            if (p->node->sprite == param_1) {
                if (p->count > 0) {
                    p->count = p->count + 0xff;
                    return;
                }
                *ppPrev = p->next;
                if (p->node->check_for_shadows() != 0 && this->owner != 0) {
                    this->owner->remove_shadows();
                }
                if (p->node != 0) {
                    p->node->destroy(1);
                }
                free(p);
                return;
            }
            ppPrev = &p->next;
            p = p->next;
        }
    }
}
