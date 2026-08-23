#ifndef AOE1_PNL_LST_CONTEXT_H
class TListPanel {
public:
    short item_at(long p1, long p2);
    void scroll_cur_line(unsigned char flag, short item, int update_scrollbar);
    void goto_item(long p1, long p2);
};
#endif

void TListPanel::goto_item(long p1, long p2) {
    scroll_cur_line(1, item_at(p1, p2), 1);
}
