// RGE_Victory_Conditions::check_for_victory
// VA: 00531DB0
// victory.cpp
// Attempt log:
// - Baseline early-return form was 185 bytes different; the binary's repeated list check
//   requires an outer non-null guard and a second owning-list assignment before clearing.
// - Reusing the list cursor, leaving the group selector uninitialized, and using integer
//   locals for the three group counters recovered the original register/frame basin.
// - A switch over states 1/2/3 recovered the decrement dispatch and exact 216-byte size.
// - Explicit `has_success == 1` and `completed > 0` predicates recovered all branch bytes.
// - The remaining two bytes are the commutative completion/failure add destination; operand
//   and named-temporary variants were unchanged. Left in scratch with exact CFG/size parity.
// ACCEPTED_DRIFT: the sole difference is `add eax,ebx; cmp esi,eax` versus
// `add ebx,eax; cmp esi,ebx`. The same 32-bit sum is compared, both result
// registers are dead/overwritten immediately afterward, and all CFG, memory
// effects, and 216 function bytes otherwise align (214/216 equal).
// BINARY NOTE: The shared victory_context.h declaration preserves the proven
// entry fields and owner symbol. The two-byte register recolor remains.

#include "../../include/victory_context.h"

void RGE_Victory_Conditions::check_for_victory() {
    RGE_Victory_Entry* entry = this->victory_list;
    long failed_group_num = 0;
    long curr_victory_group = 0;
    long group_num = 0;

    if (entry != 0) {
        this->victory = 0;
        entry = this->victory_list;

        // Clear all checked flags
        for (; entry != 0; entry = entry->next) {
            entry->checked_flag = 0;
        }

        // Main group iteration loop
        while (true) {
            // Find next unchecked group
            RGE_Victory_Entry* group_entry = this->victory_list;
            long target_group;

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
            long has_success = 0;

            for (RGE_Victory_Entry* e = group_entry; e != 0; e = e->next) {
                if (e->victory_group == target_group) {
                    total_in_group++;
                    e->checked_flag = 1;

                    switch (e->state) {
                    case 1:
                        has_success = 1;
                        break;
                    case 2:
                        completed++;
                        break;
                    case 3:
                        failed_group_num++;
                        break;
                    }
                }
            }

            if (has_success == 1) {
                group_num++;
                continue;
            }

            if (completed > 0 && total_in_group == failed_group_num + completed) {
                this->victory = 2;
                break;
            }
        }

        if (curr_victory_group == group_num) {
            this->victory = 1;
        }
    }
}
