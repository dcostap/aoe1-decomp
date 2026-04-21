// tried several source shapes; logic and memory effects match, but the count-check branch still drifts
// tried: register-hint the target sprite; next probe is a packet-shaped for-loop with a body compare

extern "C" void __cdecl free(void* block);

class RGE_Sprite;

class RGE_Static_Object {
public:
    void remove_shadows();
};

class RGE_Active_Sprite {
public:
    virtual void destroy(int flags);
    RGE_Sprite* sprite;
    int check_for_shadows();
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
    RGE_Static_Object* owner;

    void remove_sprite(RGE_Sprite* param_1);
};

void RGE_Active_Sprite_List::remove_sprite(RGE_Sprite* param_1) {
    RGE_Active_Sprite_Node **ppRVar1;
    int iVar2;
    RGE_Active_Sprite_Node *pRVar3;
    RGE_Sprite *target;

    pRVar3 = this->list;
    ppRVar1 = &this->list;
    if (pRVar3 == 0) {
        return;
    }
    target = param_1;
    for (; pRVar3 != 0; pRVar3 = pRVar3->next) {
        if (pRVar3->node->sprite == target) {
            break;
        }
        ppRVar1 = &pRVar3->next;
    }
    if (pRVar3 == 0) {
        return;
    }
    if (pRVar3->count != 0) {
        pRVar3->count = pRVar3->count + 0xff;
        return;
    }
    *ppRVar1 = pRVar3->next;
    iVar2 = pRVar3->node->check_for_shadows();
    if (iVar2 != 0 && this->owner != 0) {
        this->owner->remove_shadows();
    }
    if (pRVar3->node != 0) {
        pRVar3->node->destroy(1);
    }
    free(pRVar3);
}
