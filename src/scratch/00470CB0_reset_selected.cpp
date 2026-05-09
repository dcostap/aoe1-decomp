// VA: 00470CB0 reset_selected (101B)
// Best basin: high-level memset form is exact except the second memset setup order.
// Original after first `rep stosd`: `lea edi,[edx+19E]; mov ecx,1Fh; rep stosd; stosw; stosb`.
// VC5 emits `mov ecx,1Fh; lea edi,[edx+19E]; rep stosd; stosw; stosb`.
// 2026-05-09 GraniteCub: tried 13 focused variants: manual dword loop for groups_used,
// manual loops for both arrays, raw address `(char*)this+0x19E`, temp pointer/temp size,
// comma pointer assignment, volatile pointer, array reference, expression/UL size spellings,
// and pointer-before-size/source-order variants. All either stayed in the same 8-byte
// setup-order drift or regressed into immediate stores/manual-loop basin. No inline asm/hacks.
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
    memset(this->groups_used, 0, 0x7F);
}
