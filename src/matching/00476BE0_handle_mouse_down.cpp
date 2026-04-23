class TPanel {
public:
    virtual long handle_mouse_down(unsigned char button, long x, long y, int flags, int area);
};

class TEditPanel : public TPanel {
public:
    long handle_mouse_down(unsigned char button, long x, long y, int flags, int area);
};

long TEditPanel::handle_mouse_down(unsigned char button, long x, long y, int flags, int area) {
    return TPanel::handle_mouse_down(button, x, y, flags, area);
}
