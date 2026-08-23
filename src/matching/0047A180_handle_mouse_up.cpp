#ifndef AOE1_PNL_MSG_CONTEXT_H
class TMessagePanel {
public:
    virtual ~TMessagePanel();
    long handle_mouse_up(unsigned char p0, long p1, long p2, int p3, int p4);
};
#endif

long TMessagePanel::handle_mouse_up(unsigned char p0, long p1, long p2, int p3, int p4) { return 0; }
