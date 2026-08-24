#ifndef AOE1_PANEL_CONTEXT_H
struct tagPOINT {
    long x;
    long y;
};

class TPanel {
public:
    void get_mouse_info(unsigned int keys, long packed_pos, tagPOINT& pt, int& focus_flag, int& capture_flag);
};

#endif
void TPanel::get_mouse_info(unsigned int keys, long packed_pos, tagPOINT& pt, int& focus_flag, int& capture_flag) {
    int x;
    int y;

    x = ((unsigned int)packed_pos) & 0xFFFF;
    y = ((unsigned int)packed_pos) >> 16;
    pt.x = x;
    pt.y = y;
    if (x > 60000) {
        pt.x = x - 0x10000;
    }
    if (y > 60000) {
        pt.y = y - 0x10000;
    }
    focus_flag = keys & 8;
    capture_flag = keys & 4;
}
