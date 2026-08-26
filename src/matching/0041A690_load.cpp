extern "C" void __cdecl rge_read(int handle, void* buffer, int size);

#ifndef ASP_LIST_SHARED_CONTEXT
#include "../asp_list_context.h"
#endif

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
