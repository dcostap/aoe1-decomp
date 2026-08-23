#ifndef AOE1_PNL_MSG_CONTEXT_H
class TMessagePanel {
public:
    virtual ~TMessagePanel();
    long handle_mouse_move(long p0, long p1, int p2, int p3);
};
#endif

long TMessagePanel::handle_mouse_move(long p0, long p1, int p2, int p3) { return 0; }
