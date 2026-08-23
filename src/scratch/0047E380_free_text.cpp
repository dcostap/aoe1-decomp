// 0047E380 TTextPanel::free_text
// Attempt log:
// 1. Prior straight loop used wrong object/list offsets (+F8/+FC) and node next at +8, causing EBP/EDI basin.
// 2. Corrected TTextPanel layout (vptr + pad to list at +F4) and TextNode next at +0C.

extern "C" void __cdecl free(void* block);

class TTTextPanel {
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
        char* pad_08;
        TextNode* next;
    };

    char pad_04[0xF4 - 4];
    TextNode* list;
    short num_lines;

    void calc_draw_info(int param_1);
    void free_text(void);
};

void TTTextPanel::free_text(void) {
    TextNode* node = this->list;
    if (node != 0) {
        do {
            if (node->text != 0) {
                free(node->text);
            }
            if (node->text2 != 0) {
                free(node->text2);
            }
            TextNode* old = node;
            node = node->next;
            free(old);
        } while (node != 0);
        this->list = 0;
    }
    this->num_lines = 0;
    this->calc_draw_info(1);
    this->vf20(1);
}
