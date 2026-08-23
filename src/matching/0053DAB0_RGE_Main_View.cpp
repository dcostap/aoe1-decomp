#ifndef RGE_MAIN_VIEW_SHARED_CONTEXT
class RGE_Player;

class RGE_View {
public:
    void* vftable;
    char gap_04[0xBC];
    int mouse_move_tolerance;
    char gap_C4[0x29C];

    RGE_View();
};

class RGE_Main_View : public RGE_View {
public:
    void* map_view;
    unsigned long last_mouse_scroll_time;
    int mouse_scrolling;
    long mouse_last_x;
    long mouse_last_y;
    unsigned long last_key_scroll_time;
    int key_scrolling;
    RGE_Player* save_player;

    RGE_Main_View();
};
#endif

RGE_Main_View::RGE_Main_View() : RGE_View() {
    this->map_view = 0;
    this->last_mouse_scroll_time = 0;
    this->mouse_scrolling = 0;
    this->last_key_scroll_time = 0;
#ifndef RGE_MAIN_VIEW_SHARED_CONTEXT
    this->vftable = (void*)0x005777F0;
#endif
    this->mouse_move_tolerance = 10;
    this->mouse_last_x = -1;
    this->mouse_last_y = -1;
    this->key_scrolling = 0;
    this->save_player = 0;
}
