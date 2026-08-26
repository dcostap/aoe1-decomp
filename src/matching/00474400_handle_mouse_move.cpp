#ifndef PNL_DROP_CONTEXT
class TDropDownPanel {
public:
    virtual long handle_mouse_move(long a, long b, int c, int d);
};
#endif

long TDropDownPanel::handle_mouse_move(long a, long b, int c, int d) {
    return TPanel::handle_mouse_move(a, b, c, d);
}
