// tried ppPrev before/after first loop; tried for-loop and while-loop forms
// tried moving ppPrev init inside/outside loop; tried do-while for second loop
// variant lab: 6 variants across 2 runs, all produce 160 bytes (2 too large)
// best mismatch at offset 38: VC5 loads [esi+4] into eax instead of ecx, then add esi,4 instead of lea edi,[esi+4]
// tried reversing local decl order, while vs for, early pp init: no change in register basin
// this is a codegen basin issue: VC5 modifies this pointer (esi) instead of keeping it and using edi for ppPrev
// original preserves esi (this) and uses edi for pointer-to-pointer traversal
// TU context or different register pressure from neighboring functions likely needed

extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);

class RGE_Sprite;
class RGE_Static_Object;

class RGE_Active_Sprite {
public:
    void* vtable_ptr;
    RGE_Sprite* sprite;
    void destroy(int);
    void set_offset(long, long);
    int check_for_shadows();
};

class RGE_Sprite {
public:
    int check_for_shadows();
    RGE_Active_Sprite* make_active_sprite();
};

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
    void add_sprite(RGE_Sprite* param_1, unsigned char param_2, long param_3, long param_4);
};

void RGE_Active_Sprite_List::add_sprite(RGE_Sprite* param_1, unsigned char param_2, long param_3, long param_4) {
    RGE_Active_Sprite_Node* pp;
    RGE_Active_Sprite_Node** ppPrev;

    if (param_1 == 0) { return; }

    if (param_1->check_for_shadows() && this->owner) {
        this->owner->remove_shadows();
    }

    ppPrev = &this->list;
    for (pp = this->list; pp; pp = pp->next) {
        if (pp->node->sprite == param_1) {
            pp->count++;
            return;
        }
    }

    pp = this->list;
    while (pp && pp->order <= param_2) {
        ppPrev = &pp->next;
        pp = pp->next;
    }

    RGE_Active_Sprite_Node* node = (RGE_Active_Sprite_Node*)calloc(1, 0xc);
    RGE_Active_Sprite* asp = param_1->make_active_sprite();
    node->node = asp;
    asp->set_offset(param_3, param_4);
    node->order = param_2;
    node->next = *ppPrev;
    *ppPrev = node;
}
