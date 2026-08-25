#ifndef PLAYER_GROUPED_TU
class RGE_Static_Object {
public:
    char gap_00[0x36];
    unsigned char selected;
};
#endif

#ifndef PLAYER_GROUPED_TU
class RGE_Player {
public:
    char gap_00[0x130];
    RGE_Static_Object* selected_obj;
    RGE_Static_Object* sel_list[25];
    char gap_198[4];
    short sel_count;

    void unselect_object();
};
#endif

void RGE_Player::unselect_object() {
    short i;
    short removed_count;
    RGE_Static_Object* obj;

    if (this->sel_count > 0) {
        i = 0;
        this->selected_obj = 0;
        removed_count = 0;
        for (; i < 25; ++i) {
            if (removed_count >= this->sel_count) {
                break;
            }
            obj = this->sel_list[i];
            if (obj != 0) {
                obj->selected = 0;
                ++removed_count;
                this->sel_list[i] = 0;
            }
        }
        this->sel_count = 0;
    }
}
