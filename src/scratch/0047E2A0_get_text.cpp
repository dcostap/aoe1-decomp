// tried the natural linked-list walk with a shared empty-string return; VC5 kept sinking the counter into ECX instead of matching the original EDX basin
// tried a decompiler-style loop, then a register keyword probe; the remaining mismatch stayed in the early loop/register basin right after the list-null test

class TTTextPanel {
public:
    struct TextNode {
        char* text;
        char* text2;
        long id;
        TextNode* next_node;
    };

    char gap_000[0xF4];
    TextNode* list;

    char* get_text(long param_1);
};

static char g_empty_text[4];

char* TTTextPanel::get_text(long param_1) {
    TextNode* node;
    register long index;
    long wanted;

    node = this->list;
    wanted = param_1;
    index = 0;
    if (node == 0) {
        g_empty_text[0] = 0;
        return g_empty_text;
    }

    while (1) {
        if (index == wanted) {
            return node->text;
        }
        node = node->next_node;
        index++;
        if (node == 0) {
            break;
        }
    }

    g_empty_text[0] = 0;
    return g_empty_text;
}
