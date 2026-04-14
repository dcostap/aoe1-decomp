class TListPanel {
public:
    short item_at(long p1, long p2, int flag);
    void scroll_cur_line(unsigned char flag, short item);
    void goto_item(long p1, long p2);
};

void TListPanel::goto_item(long p1, long p2) {
    short result = item_at(p1, p2, 1);
    scroll_cur_line(1, result);
}
