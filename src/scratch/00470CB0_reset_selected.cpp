// attempt 1: direct field clears with the two big zero blocks expressed as memset
// attempt 2: fixed the selected-object / sel-count layout, but the remaining mismatch is the late sel_count+groups_used rep-stos basin
// leaving this paused in scratch because the remaining diff is localized to the zero-block codegen, not the guard/field semantics

#include <string.h>

class RGE_Player {
public:
    char gap_0[0x120];
    short selected_start_col;
    short selected_start_row;
    short selected_end_col;
    short selected_end_row;
    short replacement_terrain;
    short replacement_overlay;
    short replacement_overlay_shape;
    char gap_12E[2];
    void* selected_obj;
    void* sel_list[25];
    char gap_198[4];
    short sel_count;
    unsigned char groups_used[127];

    void reset_selected();
};

void RGE_Player::reset_selected() {
    this->selected_start_col = -1;
    this->selected_start_row = -1;
    this->selected_end_col = -1;
    this->selected_end_row = -1;
    this->replacement_terrain = -1;
    this->replacement_overlay = -1;
    this->replacement_overlay_shape = -1;
    this->sel_count = 0;
    this->selected_obj = 0;
    memset(this->sel_list, 0, 0x64);

    {
        unsigned long* p = (unsigned long*)this->groups_used;
        int count = 0x1F;
        do {
            *p++ = 0;
        } while (--count != 0);
        *(unsigned short*)p = 0;
        *((unsigned char*)p + 2) = 0;
    }
}
