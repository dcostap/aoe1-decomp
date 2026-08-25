extern void (__stdcall *g_draw_window_fn)(int hwnd);


void RGE_Base_Game::draw_window() {
    g_draw_window_fn((int)this->hwnd);
}
