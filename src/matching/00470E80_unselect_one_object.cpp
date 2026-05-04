// attempt 12: outer early sel_count guard + own_selected-style inner count check

class RGE_Static_Object;

class RGE_Player {
public:
    char gap_00[0x134];
    RGE_Static_Object* sel_list[25];
    char gap_198[4];
    short sel_count;

    void unselect_one_object(short index);
    void unselect_one_object(RGE_Static_Object* object);
};

void RGE_Player::unselect_one_object(RGE_Static_Object* object) {
    short slot;
    short count;
    RGE_Static_Object* current;

    if (this->sel_count <= 0) {
        return;
    }

    slot = 0;
    count = 0;
    while (slot < 25) {
        if (count >= this->sel_count) {
            return;
        }
        current = this->sel_list[slot];
        if (current != 0) {
            if (current == object) {
                this->unselect_one_object(slot);
                return;
            }
            count = count + 1;
        }
        slot = slot + 1;
    }
}
