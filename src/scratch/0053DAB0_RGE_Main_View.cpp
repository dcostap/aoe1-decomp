// tried the straightforward derived-ctor spelling with base construction and member stores; first mismatch stayed at the entry/prolog basin
// tried a direct base-ctor stub to force the call target, but that pulled the match into a bad codegen family immediately
// leaving in scratch: the remaining gap is still constructor-call shape / vtable setup, not the field initializers

class RGE_Player;

class RGE_View {
public:
    virtual ~RGE_View();
    RGE_View();
};

class RGE_Main_View : public RGE_View {
public:
    char gap_04[0x35C];
    void* map_view;
    int last_mouse_scroll_time;
    int mouse_scrolling;
    long mouse_last_x;
    long mouse_last_y;
    unsigned long last_key_scroll_time;
    int key_scrolling;
    RGE_Player* save_player;

    RGE_Main_View();
};

RGE_View::RGE_View() {
    static volatile int sink;
    sink = sink;
}

RGE_Main_View::RGE_Main_View() : RGE_View() {
    this->map_view = 0;
    this->last_mouse_scroll_time = 0;
    this->mouse_scrolling = 0;
    this->last_key_scroll_time = 0;
    this->key_scrolling = 0;
    this->save_player = 0;
    this->mouse_last_x = -1;
    this->mouse_last_y = -1;
}
