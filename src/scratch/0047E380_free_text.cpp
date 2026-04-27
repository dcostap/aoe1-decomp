// first pass: walk the text-node list, free each payload, clear the list, then rebuild draw state
// if this is sticky, the remaining gap is likely just the exact vtable-call shape at the tail
// tried the straight node/free loop with a raw tail vcall; prolog drifted to EBP and the tail call shape was wrong
// tried a virtual-slot spelling and it kept shifting the class layout / prolog basin instead of landing on the packet
// leaving this in scratch because the remaining diff is the init/prolog + tail-call basin, not the list-free logic
extern "C" void __cdecl free(void* block);

class TTextPanel {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20(int arg);

    struct TextNode {
        char* text;
        char* text2;
        TextNode* next;
        char* pad_0C;
    };

    char pad_00[0xF4];
    TextNode* list;
    short num_lines;

    void calc_draw_info(int param_1);
    void free_text(void);
};

void TTextPanel::free_text(void) {
    TextNode* node;
    TextNode* next;

    node = this->list;
    if (node != 0) {
        do {
            if (node->text != 0) {
                free(node->text);
            }
            if (node->text2 != 0) {
                free(node->text2);
            }
            next = node->next;
            free(node);
            node = next;
        } while (node != 0);
        this->list = 0;
    }
    this->num_lines = 0;
    this->calc_draw_info(1);
    this->vf20(1);
}
