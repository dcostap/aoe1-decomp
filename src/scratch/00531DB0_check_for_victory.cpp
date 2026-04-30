// RGE_Victory_Conditions::check_for_victory
// VA: 00531DB0
// victory.cpp

class RGE_Victory_Entry {
public:
    char gap_00[0x2C];
    unsigned char victory_group; // +0x2C
    char gap_2D;
    unsigned char state;      // +0x2E
    unsigned char checked_flag; // +0x2F
    RGE_Victory_Entry* next;  // +0x30
};

class RGE_Victory_Conditions {
public:
    void* vtable_ptr;          // +0x00
    RGE_Victory_Entry* victory_list; // +0x04
    char gap_08[8];
    unsigned char victory;     // +0x10

    void check_for_victory();
};

void RGE_Victory_Conditions::check_for_victory() {
    RGE_Victory_Entry* entry = this->victory_list;
    long failed_group_num = 0;
    long curr_victory_group = 0;
    long group_num = 0;

    if (entry == 0) return;

    this->victory = 0;

    // Clear all checked flags
    for (RGE_Victory_Entry* e = entry; e != 0; e = e->next) {
        e->checked_flag = 0;
    }

    // Main group iteration loop
    while (true) {
        // Find next unchecked group
        RGE_Victory_Entry* group_entry = this->victory_list;
        long target_group = 0;

        while (group_entry != 0) {
            if (group_entry->checked_flag == 0) {
                target_group = group_entry->victory_group;
                curr_victory_group++;
                break;
            }
            group_entry = group_entry->next;
        }

        if (group_entry == 0) break;

        // Scan all entries for this group
        long total_in_group = 0;
        long completed = 0;
        bool has_success = false;

        for (RGE_Victory_Entry* e = group_entry; e != 0; e = e->next) {
            if (e->victory_group == target_group) {
                total_in_group++;
                e->checked_flag = 1;

                if (e->state == 1) {
                    has_success = true;
                } else if (e->state == 2) {
                    completed++;
                } else if (e->state == 3) {
                    failed_group_num++;
                }
            }
        }

        if (has_success) {
            group_num++;
            continue;
        }

        if (completed >= 1 && total_in_group == completed + failed_group_num) {
            this->victory = 2;
            break;
        }
    }

    if (curr_victory_group == group_num) {
        this->victory = 1;
    }
}
