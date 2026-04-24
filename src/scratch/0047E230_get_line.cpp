// quick-win attempt log:
// no existing work file for 0047E230; starting with the literal list/string compare
// shape from the decompiler. The helper walks TTextPanel::list and returns the
// zero-based index of the first matching text node, or -1 if none match.

class TTextPanel_TextNode {
public:
    char* text;
    char* text2;
    long id;
    TTextPanel_TextNode* next_node;
};

class TTextPanel {
public:
    char gap_00[0xF4];
    TTextPanel_TextNode* list;

    long get_line(char*);
};

long TTextPanel::get_line(char* param_1) {
    TTextPanel_TextNode* node = this->list;
    long index = 0;

    while (node != 0) {
        char* text = node->text;
        char* query = param_1;
        unsigned char c;
        bool diff;

        while (true) {
            c = (unsigned char)*text;
            diff = c < (unsigned char)*query;
            if (c != (unsigned char)*query) {
                int cmp = (1 - (unsigned int)diff) - (unsigned int)(diff != 0);
                if (cmp == 0) {
                    return index;
                }
                break;
            }
            if (c == 0) {
                return index;
            }
            c = (unsigned char)text[1];
            diff = c < (unsigned char)query[1];
            if (c != (unsigned char)query[1]) {
                int cmp = (1 - (unsigned int)diff) - (unsigned int)(diff != 0);
                if (cmp == 0) {
                    return index;
                }
                break;
            }
            text += 2;
            query += 2;
            if (c == 0) {
                return index;
            }
        }

        node = node->next_node;
        index++;
    }

    return -1;
}
