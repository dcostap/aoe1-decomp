// 00470ED0 RGE_Player::unselect_one_object
// player.cpp:1892-1927, 163 bytes
// Round2 pass: 10 variants tried: natural decompiler shape, inverted remove branch,
// explicit goto remove branch, slot pointer store, sel_count vs last zeroing, for/goto
// scan loop, short vs int index/count, and compare algebra variants.
// Best source compiles to same behavior but .text is 160 bytes versus configured 163;
// closest drift is a broad branch/loop-shape issue: VC5 merges the remove-slot zero
// and prechecks the first selected slot, while original keeps a separate jl/fallthrough
// remove branch and scans from xor eax/movsx. Not accepted-drift quality.

#ifndef PLAYER_GROUPED_TU
class RGE_Static_Object { public: char gap[0x36]; unsigned char selected; };
class RGE_Player {
public:
    char gap0[0x130];
    RGE_Static_Object* selected_obj;
    RGE_Static_Object* sel_list[26];
    short sel_count;
    void unselect_one_object(short index);
};
#endif

void RGE_Player::unselect_one_object(short index)
{
    int i = index;
    RGE_Static_Object* obj = sel_list[i];
    if (obj != 0) {
        obj->selected = 0;
        int count = sel_count;
        int last = count - 1;
        if (i >= last) {
            sel_list[i] = 0;
        } else {
            sel_list[i] = sel_list[count - 1];
            sel_list[sel_count - 1] = 0;
        }
        RGE_Static_Object* cur = selected_obj;
        --sel_count;
        short new_count = sel_count;
        if (cur == obj) {
            selected_obj = 0;
            if (new_count > 0) {
                for (short j = 0; j < 25; ++j) {
                    if (sel_list[j] != 0) {
                        selected_obj = sel_list[j];
                        return;
                    }
                }
            }
        }
    }
}
