#include <string.h>
class TTTextPanel_TextNode { public: char* text; char* text2; long id; TTTextPanel_TextNode* next_node; };
class TTTextPanel { public: char gap_00[0xF4]; TTTextPanel_TextNode* list; long get_line(char* s); };
long TTTextPanel::get_line(char* s) {
    TTTextPanel_TextNode* node = this->list;
    long i = 0;
    while (node != 0) {
        if (strcmp(node->text, s) == 0) return i;
        node = node->next_node;
        ++i;
    }
    return -1;
}
