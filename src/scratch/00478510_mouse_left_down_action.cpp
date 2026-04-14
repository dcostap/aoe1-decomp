class TPanel {
public:
    virtual void dummy_vf();
    int capture_mouse();
};

class TListPanel : public TPanel {
public:
    virtual long mouse_left_down_action(long p1, long p2, int p3, int p4);
    void goto_item(long p1, long p2);
};

long TListPanel::mouse_left_down_action(long p1, long p2, int p3, int p4) {
    capture_mouse();
    goto_item(p1, p2);
    return 1;
}
