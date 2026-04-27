struct TextNode {
    char gap_00[0x8];
    long id;
    TextNode* next_node;
};

class TTTextPanel {
public:
    char gap_00[0xF4];
    TextNode* list;
    short num_lines;
    short draw_lines;
    short top_line;
    short bot_line;
    short cur_line;
    short cur_col;

    void calc_draw_info(int param_1);
    void set_line(long param_1);
    void set_line_by_id(long param_1);
};

void TTTextPanel::set_line_by_id(long param_1) {
    int index = 0;
    TextNode* node = this->list;
    while (true) {
        if (node == 0) {
            return;
        }
        if (node->id == param_1) {
            break;
        }
        node = node->next_node;
        ++index;
    }
    this->set_line(index);
}

void TTTextPanel::set_line(long line) {
    cur_line = (short)line;
    calc_draw_info(1);
}
