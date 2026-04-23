// straightforward selection-scan first
// tried the direct short-counter loop, then a label/goto form; mismatch stayed in the loop-entry compare/register basin
// current best lead is the top compare/load ordering around sel_count and sel_list[slot]

class RGE_Static_Object;

class RGE_Player {
public:
    void* vtable_ptr;
    char gap_04[0x12C];
    RGE_Static_Object* selected_obj;
    RGE_Static_Object* sel_list[25];
    unsigned long sel_object_properties;
    short sel_count;

    void unselect_one_object(short index);
    void unselect_one_object(RGE_Static_Object* object);
};

void RGE_Player::unselect_one_object(RGE_Static_Object* object) {
    RGE_Static_Object* target = object;
    short slot;
    short count;
    short limit;

    limit = this->sel_count;
    if (0 < limit) {
        slot = 0;
        count = 0;
L_top:
        if (count >= limit) {
            return;
        }
        {
            RGE_Static_Object* current = this->sel_list[slot];
            if (current != 0) {
                if (current == target) {
                    this->unselect_one_object(slot);
                    return;
                }
                count = count + 1;
            }
        }
        slot = slot + 1;
        if (0x18 < slot) {
            return;
        }
        goto L_top;
    }
}
