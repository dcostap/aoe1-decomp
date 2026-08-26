// 0047E380 TTextPanel::free_text
// Attempt log:
// 1. Prior straight loop used wrong object/list offsets (+F8/+FC) and node next at +8, causing EBP/EDI basin.
// 2. Corrected TTextPanel layout (vptr + pad to list at +F4) and TextNode next at +0C.

extern "C" void __cdecl free(void* block);

#ifndef PNL_TXT_TU_CONTEXT
struct TextNode {
    char* text;
    char* text2;
    long id;
    TextNode* next;
};

class TTextPanel {
public:
    virtual ~TTextPanel();
    virtual long setup(void*, TTextPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(void*);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long,
                                  long, long, TTextPanel*, TTextPanel*,
                                  TTextPanel*, TTextPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int arg);

    char pad_04[0xF4 - 4];
    TextNode* list;
    short num_lines;

    void calc_draw_info(int param_1);
    void free_text(void);
};
#endif

void TTextPanel::free_text(void) {
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
    this->set_redraw(1);
}
