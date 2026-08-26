// 0041A9B0 RGE_Active_Sprite_List::remove_sprite
// Current: integrated while loop and natural delete preserve the original
// not-found epilogue and deleting-destructor dispatch.

extern "C" void __cdecl free(void* block);

#ifndef ASP_LIST_SHARED_CONTEXT
#include "../asp_list_context.h"
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
                    delete p->node;
                }
                free(p);
                return;
            }
            ppPrev = &p->next;
            p = p->next;
        }
    }
}
