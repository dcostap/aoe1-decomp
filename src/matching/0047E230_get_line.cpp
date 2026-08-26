#include <string.h>
#ifndef PNL_TXT_TU_CONTEXT
struct TextNode {
    char* text;
    char* text2;
    long id;
    TextNode* next_node;
};
class TTextPanel {
public:
    char gap_00[0xF4];
    TextNode* list;
    long get_line(char* s);
};
#endif
long TTextPanel::get_line(char* s) {
    TextNode* node = this->list;
    long i = 0;
    while (node != 0) {
        if (strcmp(node->text, s) == 0) return i;
        node = node->next_node;
        ++i;
    }
    return -1;
}
