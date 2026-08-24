#ifndef RGE_MAIN_VIEW_SHARED_CONTEXT
class TPanel {
public:
    virtual ~TPanel();
    virtual void setup(void*, TPanel*, long, long, long, long,
                       unsigned char);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long,
                                 long, long, TPanel*, TPanel*, TPanel*,
                                 TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int param_1);
};

class RGE_View {
public:
    int start_scroll_view(unsigned char param_1, long param_2, long param_3, int param_4, int param_5);
};

class RGE_Main_View {
public:
    char gap_000[0x360];
    TPanel* map_view;

    int start_scroll_view(unsigned char param_1, long param_2, long param_3, int param_4, int param_5);
};
#endif

int RGE_Main_View::start_scroll_view(unsigned char param_1, long param_2, long param_3, int param_4, int param_5) {
#ifdef RGE_MAIN_VIEW_SHARED_CONTEXT
    if (this->RGE_View::start_scroll_view(param_1, param_2, param_3, param_4, param_5) != 0) {
#else
    if (((RGE_View*)this)->start_scroll_view(param_1, param_2, param_3, param_4, param_5) != 0) {
#endif
        if (this->map_view != 0) {
            this->map_view->set_redraw(1);
        }
        return 1;
    }
    return 0;
}
