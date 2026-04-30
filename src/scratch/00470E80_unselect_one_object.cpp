// attempt 7: rely on while condition instead of early return

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
    short slot = 0;
    short count = 0;
    while (count < this->sel_count) {
        RGE_Static_Object* current = this->sel_list[slot];
        if (current != 0) {
            if (current == object) {
                this->unselect_one_object(slot);
                return;
            }
            count++;
        }
        slot++;
        if (slot >= 25) return;
    }
}
