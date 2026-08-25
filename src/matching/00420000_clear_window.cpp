

void RGE_Base_Game::clear_window() {
    RECT rect;
    void* dc;
    void* brush;

    if (this->prog_window != 0) {
        dc = GetDC(this->prog_window);
        GetClientRect(this->prog_window, &rect);
        brush = GetStockObject(4);
        FillRect(dc, &rect, brush);
        ReleaseDC(this->prog_window, dc);
    }
}
