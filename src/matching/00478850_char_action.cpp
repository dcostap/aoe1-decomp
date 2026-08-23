// TListPanel::char_action — wrap-around linear search through linked TextNode list

extern "C" int __cdecl toupper(int c);

#ifndef AOE1_PNL_LST_CONTEXT_H
struct TextNode {
    char* text;       // +0x00
    char gap_04[8];   // +0x04
    TextNode* next;   // +0x0C
};

class TPanel {
public:
    char pad_00[0xF4];
};

class TListPanel : public TPanel {
public:
    TextNode* list;                   // 0xF4
    short num_lines;                  // 0xF8
    short draw_lines;                 // 0xFA
    short top_line;                   // 0xFC
    short bot_line;                   // 0xFE
    short cur_line;                   // 0x100
    char pad_102[0xBE];

    void scroll_cur_line(unsigned char action, short line, int flag);

    long char_action(long param_1, short param_2);
};
#endif

long TListPanel::char_action(long param_1, short param_2) {
    int ch = toupper((int)param_1);
    TextNode* node = this->list;
    int i = 0;

    while (node != 0) {
        if (i > (int)(short)this->cur_line) {
            if (toupper((int)*node->text) == ch)
                goto found;
        }
        i++;
        node = node->next;
    }

    if ((int)(short)this->cur_line > 0) {
        node = this->list;
        i = 0;
        while (node != 0) {
            if (toupper((int)*node->text) == ch)
                goto found;
            i++;
            if (i >= (int)(short)this->cur_line)
                return 0;
            node = node->next;
        }
    }

    return 0;

found:
    this->scroll_cur_line(1, (short)i, 1);
    return 1;
}
