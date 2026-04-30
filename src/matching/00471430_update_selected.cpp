// tried the direct decompiler shape first; the compare direction and unselect-call basin were off
// tried flipping the count compare; VC5 still chose the wrong compare operand order
// tried removing the temp object pointer and using the member call explicitly; prolog still drifted to mov edi,ecx before xor esi
// attempt 2: natural for-loop with short counters

class RGE_Static_Object;

class RGE_Player {
public:
    char gap_00[0x134];
    RGE_Static_Object* sel_list[25];
    char gap_198[4];
    short sel_count;

    void unselect_one_object(short index);
    void update_selected();
};

class RGE_Static_Object {
public:
    char gap_00[0x20];
    RGE_Static_Object* inside_obj;
    char gap_24[0x24];
    unsigned char object_state;
};

void RGE_Player::update_selected() {
    RGE_Player* p = this;
    for (short index = 0, selected = 0; index < 25; index++) {
        if (selected >= p->sel_count) return;
        RGE_Static_Object* obj = p->sel_list[index];
        if (obj != 0) {
            if (obj->object_state < 7 && obj->inside_obj == 0)
                selected++;
            else
                p->unselect_one_object(index);
        }
    }
}
