extern void (__stdcall *g_draw_window_fn)(int hwnd);

class RGE_Base_Game {
public:
    char gap_0[0x10];
    int hwnd;
    void draw_window();
};

void RGE_Base_Game::draw_window() {
    g_draw_window_fn(this->hwnd);
}
