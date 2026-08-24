extern "C" void __cdecl rge_write(int file, void* data, int size);

#ifndef ASP_LIST_SHARED_CONTEXT
class RGE_Active_Sprite {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void save(int file);
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

    void save(int file);
};
#endif

void RGE_Active_Sprite_List::save(int file) {
    RGE_Active_Sprite_Node* node = this->list;
    unsigned char ender = 0;

    while (node) {
        node->node->save(file);
        node = node->next;
    }

    rge_write(file, &ender, 1);
}
