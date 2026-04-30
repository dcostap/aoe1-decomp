// TListPanel::char_action — goto-based loop to match asm structure

extern "C" int __cdecl toupper(int c);

class TListPanel {
public:
    char gap_00[0xF4];
    void* linked_list;                // 0xF4
    short num_lines;                  // 0xF8
    short draw_lines;                 // 0xFA
    short top_line;                   // 0xFC
    short bot_line;                   // 0xFE
    short cur_line;                   // 0x100
    char pad_102[0xBE];

    void scroll_cur_line(unsigned char action, short line, int flag);

    long char_action(long param_1, short param_2);
};

long TListPanel::char_action(long param_1, short param_2) {
    int ch = toupper((int)param_1);
    int i = 0;
    void** node = (void**)this->linked_list;

    if (node != 0) {
        do {
            if (i > (int)(short)this->cur_line) {
                if (toupper((int)*(char*)node[0]) == ch)
                    goto found;
            }
            i++;
            node = (void**)node[3];
        } while (node != 0);
    }

    if ((int)(short)this->cur_line > 0) {
        node = (void**)this->linked_list;
        i = 0;
        if (node != 0) {
            goto second_entry;
            do {
                if (toupper((int)*(char*)node[0]) == ch)
                    goto found;
second_entry:
                if (i >= (int)(short)this->cur_line - 1)
                    return 0;
                i++;
                node = (void**)node[3];
            } while (node != 0);
        }
    }

    return 0;

found:
    this->scroll_cur_line(1, (short)i, 1);
    return 1;
}
