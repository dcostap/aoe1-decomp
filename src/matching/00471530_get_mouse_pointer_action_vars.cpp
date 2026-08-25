#ifndef PLAYER_GROUPED_TU
class RGE_Player {
public:
    int get_mouse_pointer_action_vars(int param1, int* param2, int* param3);
};
#endif

int RGE_Player::get_mouse_pointer_action_vars(int param1, int* param2, int* param3) {
    *param2 = 0;
    *param3 = 0;
    return 0;
}
