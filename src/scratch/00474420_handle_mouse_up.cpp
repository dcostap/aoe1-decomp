class TPanel {
public:
    virtual long handle_mouse_up(unsigned char p1, long p2, long p3, int p4, int p5);
};

class TDropDownPanel : public TPanel {
public:
    long handle_mouse_up(unsigned char p1, long p2, long p3, int p4, int p5);
};

long TDropDownPanel::handle_mouse_up(unsigned char p1, long p2, long p3, int p4, int p5) {
    return TPanel::handle_mouse_up(p1, p2, p3, p4, p5);
}
