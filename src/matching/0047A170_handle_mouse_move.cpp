class TMessagePanel {
public:
    virtual ~TMessagePanel();
    int handle_mouse_move(int p0, int p1, int p2, int p3);
};

int TMessagePanel::handle_mouse_move(int p0, int p1, int p2, int p3) { return 0; }
