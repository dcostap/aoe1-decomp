// attempt 1: wrong sel_count offset (+0x198 vs +0x19C); 6 bytes short
// attempt 2: fixed offset, size matches (86), but total mismatch at +3 (register allocation)
// Original: keeps this in ecx, bl=select_level, di=sel_count, dx=loop_i, si=matches
// VC5: modifies ecx to point to sel_list base, uses different regs throughout
// Left in scratch: benign register-allocation drift, behavior correct

class RGE_Static_Object {
public:
    char gap_00[0x8D];
    unsigned char select_level;
};

class SelectionEntry {
public:
    RGE_Static_Object* master_obj;
};

class RGE_Player {
public:
    char gap_00[0x134];
    SelectionEntry* sel_list[0x1A];
    short sel_count;

    unsigned char get_select_level();
};

unsigned char RGE_Player::get_select_level() {
    unsigned char bl = 0xFF;
    int si = 0;
    for (int i = 0; i < 0x19; i++) {
        if (si >= sel_count) break;
        if (sel_list[i]) {
            unsigned char level = sel_list[i]->master_obj->select_level;
            if (level < bl) {
                bl = level;
            }
            si++;
        }
    }
    return (int)(bl != 0xFF) ? bl : 0;
}
