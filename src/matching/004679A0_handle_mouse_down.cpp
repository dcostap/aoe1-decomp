#ifndef AOE1_PANEL_EZ_CONTEXT_H
class TPanel {
public:
    virtual long handle_mouse_down(unsigned char button, long x, long y, int flags, int area);
};

class TEasy_Panel : public TPanel {
public:
    long command_do_popup_help(unsigned char button, long x, long y);
    long handle_mouse_down(unsigned char button, long x, long y, int flags, int area);
};
#endif

long TEasy_Panel::handle_mouse_down(unsigned char button, long x, long y, int flags, int area) {
    if (this->command_do_popup_help(button, x, y) != 0) {
        return 1;
    }
    return TPanel::handle_mouse_down(button, x, y, flags, area);
}
