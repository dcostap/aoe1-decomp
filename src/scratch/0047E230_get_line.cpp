// quick-win attempt log:
// the direct byte-compare shape was still landing in the wrong prolog family
// this probe keeps the same text-node walk but spells the compare as ordered
// less/greater tests, hoping to recover the original sbb-style compare basin

class TTTextPanel_TextNode {
public:
    char* text;
    char* text2;
    long id;
    TTTextPanel_TextNode* next_node;
};

class TTTextPanel {
public:
    char gap_00[0xF4];
    TTTextPanel_TextNode* list;

    long get_line(char*);
};

long TTTextPanel::get_line(char* param_1) {
    TTTextPanel_TextNode* node = this->list;
    long index = 0;

    while (node != 0) {
        unsigned char* text = (unsigned char*)node->text;
        unsigned char* query = (unsigned char*)param_1;

        while (true) {
            unsigned char a = text[0];
            unsigned char b = query[0];
            if (a < b) {
                break;
            }
            if (a > b) {
                break;
            }
            if (a == 0) {
                return index;
            }
            a = text[1];
            b = query[1];
            if (a < b) {
                break;
            }
            if (a > b) {
                break;
            }
            text += 2;
            query += 2;
            if (a == 0) {
                return index;
            }
        }

        node = node->next_node;
        index++;
    }

    return -1;
}
