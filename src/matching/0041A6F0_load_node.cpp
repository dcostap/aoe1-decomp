// Prior attempt used hand-written __try/__finally blocks and constructor wrappers;
// it matched size but emitted outlined common-tail calls and the wrong ABI symbols.
// The binary supports ordinary typed allocation/construction: node is a 0xc-byte
// record, and its payload is one of the two real sprite classes.
// Direct new expressions aligned the constructor call set and EH frame.
// A promoted int dispatch local plus switch recovered the dword mask/dec chain.
// One post-switch return preserved the shared line-89 cleanup clones.
// calloc(0xc, 1) preserves the original cdecl argument push order.
// Keeping case 1 before case 2 preserves VC5 EH-state numbering while the
// optimized switch still lays out the animated case as the fall-through arm.
// Main-agent audit confirmed canonical sprite/list ownership and natural typed
// allocation/construction; emitted code remains exact.

// FLAGS: /nologo /c /O2 /Oy /GX

extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);

#ifndef ASP_LIST_SHARED_CONTEXT
#include "../asp_list_context.h"
#endif

unsigned char RGE_Active_Sprite_List::load_node(int param_1, unsigned char param_2, RGE_Sprite** param_3) {
    RGE_Active_Sprite_Node* node;
    RGE_Active_Sprite* sprite;
    int type = param_2;

    switch (type) {
    case 1:
        node = (RGE_Active_Sprite_Node*)calloc(0xc, 1);
        sprite = new RGE_Active_Sprite(param_1, param_3);
        node->node = sprite;
        node->next = this->list;
        this->list = node;
        break;

    case 2:
        node = (RGE_Active_Sprite_Node*)calloc(0xc, 1);
        sprite = new RGE_Active_Animated_Sprite(param_1, param_3);
        node->node = sprite;
        node->next = this->list;
        this->list = node;
        break;

    case 0:
        return 0;
    }

    return 1;
}
