#ifndef RGE_VIEW_SHARED_CONTEXT
class TPanel {
public:
    void set_redraw(int mode);
};

class RGE_View {
public:
    char gap_04[0x13E];
    unsigned char render_terrain_mode;

    virtual void set_redraw(int mode);
};
#endif

void RGE_View::set_redraw(int mode) {
    ((TPanel*)this)->set_redraw(mode);
    if (mode == 2) {
        render_terrain_mode = 0;
    }
}
