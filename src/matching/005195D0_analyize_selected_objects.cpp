// 005195D0 TRIBE_Player::analyize_selected_objects
// Baseline reconstruction from the original tplayer.cpp line bands and the
// proven RGE_Player/RGE_Static_Object layouts in the generated type dump.
// Attempt log:
// - baseline: canonical typed ownership and bounded selected-list scan.
// - restored the two-counter scan and direct cursor topology from the original
//   backedge; the final form uses a natural for-header increment.
// - direct cursor dereferences recovered the repeated selected-list reloads.
// - zero-count early return preserved the original shared epilogue shape.
// - narrow volatile/count, hoisted-mask, and explicit-label variants were
//   diagnostic only and were rolled back as compiler-steering scaffolding.
// - left in scratch during the earlier pass: structural drift remained in VC5
//   scheduling and loop guard placement; no calls or unknown data ownership
//   remained.
// - Main-agent audit restored canonical player/master/object destructor slots;
//   the validated structural gap is unchanged.
// - A later same-TU pass restored the full named RGE_Player base through the
//   selection fields; that canonical context emitted identically to the prior
//   narrow surface.
// - A for-header increment (`++i, ++p`) moved the build to a 2-byte drift;
//   spelling the inner bound as `j >= sel_count` matched the oracle's
//   `cmp edi,eax; jge` and produced exact bytes.
// - The shared canonical player/object surface preserves the exact owner and
//   266 emitted bytes.

#include "../../include/tplayer_context.h"

extern unsigned int DAT_0086bc88;
extern unsigned int DAT_0086bc8c;
extern float DAT_0057682c;
extern unsigned long tribe_group_properties[];
extern int tribe_group_properties_num;

void TRIBE_Player::analyize_selected_objects()
{
    int i = 0;
    DAT_0086bc8c = 0;
    this->sel_object_properties = 0;

    if (this->sel_count == 0) {
        return;
    }

    int j = 0;
    RGE_Static_Object** p = this->sel_list;
    for (; i < 25; ++i, ++p) {
        if (j >= this->sel_count) {
            return;
        }
        if (*p != 0) {
            if ((*p)->owner->id == this->id) {
                int group = (*p)->master_obj->object_group;
                if (group >= 0 && group < tribe_group_properties_num) {
                    if (group == 0x12) {
                        this->sel_object_properties |= 0x16;
                        ++DAT_0086bc8c;
                        DAT_0086bc88 = (*p)->id;
                        if ((*p)->attribute_amount_held >= DAT_0057682c) {
                            this->sel_object_properties |= 0x80;
                        }
                    } else {
                        this->sel_object_properties |= tribe_group_properties[group];
                    }
                }

                int object_id = (*p)->master_obj->id;
                if (object_id == 0x4F || object_id == 0xC7 ||
                    object_id == 0x45 || object_id == 0x116) {
                    this->sel_object_properties |= 1;
                }
            }
            ++j;
        }
    }
}
