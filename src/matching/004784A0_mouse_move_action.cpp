// attempt 1: natural null-check + virtual helper call + item/goto range gate
// result: exact match after restoring the base layout and reversing the range compare into the original VC5 basin
// moved to src\matching\004784A0_mouse_move_action.cpp after local validation

long TListPanel::mouse_move_action(long param_1, long param_2, int, int) {
    if (this->auto_track == 0) {
        return 0;
    }

    if (this->is_inside(param_1, param_2) == 0) {
        return 0;
    }

    short item = this->item_at(param_1, param_2);
    if (item < this->item_min) {
        return 1;
    }
    if (item > this->item_max) {
        return 1;
    }
    this->goto_item(param_1, param_2);

    return 1;
}
