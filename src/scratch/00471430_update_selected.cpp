// tried the direct decompiler shape first; the compare direction and unselect-call basin were off
// tried flipping the count compare; VC5 still chose the wrong compare operand order
// tried removing the temp object pointer and using the member call explicitly; prolog still drifted to mov edi,ecx before xor esi
// remaining mismatch is the prolog compare/branch basin and the unselect_one_object call site
class RGE_Static_Object;

class RGE_Player {
public:
    char gap_00[0x134];
    RGE_Static_Object* sel_list[25];
    unsigned long sel_object_properties;
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

void RGE_Player::update_selected()
{
    short index;
    short selected_count;

    index = 0;
    selected_count = 0;
    do {
        if (selected_count >= this->sel_count)
            return;
        if (this->sel_list[index] != 0) {
            if (this->sel_list[index]->object_state < 7 && this->sel_list[index]->inside_obj == 0)
                selected_count = selected_count + 1;
            else
                this->unselect_one_object(index);
        }
        index = index + 1;
    } while (index < 0x19);
}
