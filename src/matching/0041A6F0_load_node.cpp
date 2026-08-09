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

class RGE_Sprite;
class RGE_Static_Object;
class RGE_Color_Table;
class TDrawArea;

class RGE_Active_Sprite {
public:
    virtual ~RGE_Active_Sprite();
    RGE_Sprite* sprite;
    unsigned char type;
    char gap_09[0x3];
    long offset_x;
    long offset_y;

    RGE_Active_Sprite(int param_1, RGE_Sprite** param_2);
};

class RGE_Active_Animated_Sprite : public RGE_Active_Sprite {
public:
    short frame;
    char gap_16[0x2];
    long animate_interval;
    long animate_last;
    short last_frame;
    unsigned char frame_changed;
    unsigned char frame_looped;
    unsigned char animate_flag;
    char gap_25[0x3];

    RGE_Active_Animated_Sprite(int param_1, RGE_Sprite** param_2);
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
};

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
