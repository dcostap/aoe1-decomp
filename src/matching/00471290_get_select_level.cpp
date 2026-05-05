// VA: 00471290 get_select_level
// Scans select_level from sel_list entries. Clamped by both sel_count and 25-entry limit.
// Attempt log:
//   Initial: wrong sel_count offset (0x1A0 instead of 0x19C)
// FLAGS: default.rsp (/O2 /Oy)

class RGE_Static_Object {
public:
    char gap_00[0x8D];
    unsigned char select_level;
};

class SelectionEntry {
public:
    char gap_00[8];
    RGE_Static_Object* master_obj;
};

class RGE_Player {
public:
    char gap_00[0x134];
    SelectionEntry* sel_list[25];
    char gap_198[4];
    short sel_count;
    char gap_19E[2];

    unsigned char get_select_level();
};

unsigned char RGE_Player::get_select_level() {
    unsigned char select_level = 0xFF;
    short count = this->sel_count;
    short i = 0;
    short matches = 0;

    for (; i < 25; i++) {
        if (matches >= count) break;
        SelectionEntry* entry = this->sel_list[i];
        if (entry != 0) {
            unsigned char level = entry->master_obj->select_level;
            if (level < select_level) {
                select_level = level;
            }
            matches++;
        }
    }

    if (select_level == 0xFF)
        return 0;
    return select_level;
}
