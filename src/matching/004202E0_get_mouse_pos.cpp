void RGE_Base_Game::get_mouse_pos(tagPOINT& pt) {
    GetCursorPos(&pt);
    if (this->prog_info->full_screen == 0) {
        ScreenToClient(this->prog_window, &pt);
        if (pt.x > 60000) {
            pt.x += -0x10000;
        }
        if (pt.y > 60000) {
            pt.y += -0x10000;
        }
    }
}
