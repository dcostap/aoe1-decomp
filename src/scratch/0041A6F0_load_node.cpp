// tried without /GX: 192 bytes vs 289 expected; SEH scaffolding missing
// with /GX + single try block: 272 bytes (too small)
// with /GX + nested try blocks: 289 bytes (size matches!) but prolog differs
// original interleaves SEH setup (mov [fs:0],esp) with param_2 check (dec eax / je / dec eax / jne)
// mine: SEH prolog complete, then param_2 check (test al,al / je / cmp al,1 / jne)
// tried /Oy removed; same prolog difference
// this is a deep VC5 SEH codegen basin: the original's SEH+param_2 interleaving is highly specific
// size matches at 289 bytes, remaining gap is prolog SEH setup pattern

// FLAGS: /nologo /c /O2 /GX

extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);
void* __cdecl operator new(unsigned int size);

class RGE_Sprite;
class RGE_Static_Object;

class RGE_Active_Sprite {
public:
    RGE_Active_Sprite(int param_1, RGE_Sprite** param_2);
};

class RGE_Active_Animated_Sprite {
public:
    RGE_Active_Animated_Sprite(int param_1, RGE_Sprite** param_2);
};

RGE_Active_Sprite* RGE_Active_Sprite_ctor(RGE_Active_Sprite*, int param_1, RGE_Sprite** param_2);
RGE_Active_Sprite* RGE_Active_Animated_Sprite_ctor(RGE_Active_Sprite*, int param_1, RGE_Sprite** param_2);

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
    virtual ~RGE_Active_Sprite_List();
    virtual unsigned char load_node(int param_1, unsigned char param_2, RGE_Sprite** param_3);

    RGE_Active_Sprite_Node* list;
    RGE_Static_Object* owner;
};

unsigned char RGE_Active_Sprite_List::load_node(int param_1, unsigned char param_2, RGE_Sprite** param_3) {
    RGE_Active_Sprite_Node* node;
    RGE_Active_Sprite* asp;

    if (param_2 == 0) {
        return 0;
    }

    if (param_2 == 1) {
        node = (RGE_Active_Sprite_Node*)calloc(1, 0xc);
        __try {
            asp = (RGE_Active_Sprite*)operator new(0x14);
            if (asp) {
                asp = RGE_Active_Sprite_ctor(asp, param_1, param_3);
            }
        } __finally {
        }
        node->node = asp;
        node->next = this->list;
        this->list = node;
        return 1;
    }

    if (param_2 == 2) {
        node = (RGE_Active_Sprite_Node*)calloc(1, 0xc);
        __try {
            asp = (RGE_Active_Sprite*)operator new(0x28);
            if (asp) {
                asp = RGE_Active_Animated_Sprite_ctor(asp, param_1, param_3);
            }
        } __finally {
        }
        node->node = asp;
        node->next = this->list;
        this->list = node;
        return 1;
    }

    return 0;
}
