// RGE_Base_Game::handle_mouse_move
// VA: 00421110
// basegame.cpp






int RGE_Base_Game::handle_mouse_move(void* p1, unsigned int p2, unsigned int p3, long p4)
{
    struct Frame {
        int ctrl_key;
        int right_btn;
        int left_btn;
        tagPOINT point;
        int shift_key;
    } f;
    if (this->prog_ready == 0) {
        return 1;
    }

    if (this->custom_mouse != 0 && this->windows_mouse == 0) {
        if (this->mouse_pointer->in_game_mode()) {
            this->mouse_pointer->Poll();
        } else {
            this->mouse_pointer->draw(0);
        }
    }

    this->get_mouse_info(p3, p4, &f.point.y, &f.point.x, &f.left_btn, &f.right_btn, &f.ctrl_key);
    this->action_mouse_move(
        f.point.y, f.shift_key, f.point.x, f.left_btn, f.right_btn, f.ctrl_key);
    this->handle_idle();
    return 1;
}
