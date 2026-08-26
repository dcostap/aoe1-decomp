#ifndef RGE_VIEW_SHARED_CONTEXT
class TPanel {
public:
    enum RedrawMode { redraw_mode_value };
    virtual void set_redraw(RedrawMode mode);
};

class RGE_View {
public:
    char gap_04[0x13E];
    unsigned char render_terrain_mode;

    virtual void set_redraw(TPanel::RedrawMode mode);
};
#endif

void RGE_View::set_redraw(TPanel::RedrawMode mode) {
    this->TPanel::set_redraw(mode);
    if (mode == 2) {
        render_terrain_mode = 0;
    }
}
