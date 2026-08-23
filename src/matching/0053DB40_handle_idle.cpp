#ifndef RGE_MAIN_VIEW_SHARED_CONTEXT
class TPanel {
public:
    long handle_idle(void);
};

class RGE_Main_View : public TPanel {
public:
    char gap_00[0x350];
    unsigned long last_mouse_scroll_time;
    int mouse_scrolling;
    long mouse_last_x;
    long mouse_last_y;
    unsigned long last_key_scroll_time;
    int key_scrolling;
    void* save_player;

    long do_auto_scroll(void);
    long handle_keys(void);
    long handle_idle(void);
};

extern void color_log(unsigned char, unsigned char, unsigned char);
#endif

long RGE_Main_View::handle_idle(void) {
    long result;

    color_log('E', 'E', 5);
    do_auto_scroll();
    color_log('E', 0x16, 5);
    handle_keys();
    color_log('E', '$', 5);
    result = TPanel::handle_idle();
    color_log('E', '_', 5);
    return result;
}
