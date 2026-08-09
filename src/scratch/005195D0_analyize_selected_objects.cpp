// 005195D0 TRIBE_Player::analyize_selected_objects
// Baseline reconstruction from the original tplayer.cpp line bands and the
// proven RGE_Player/RGE_Static_Object layouts in the generated type dump.
// Attempt log:
// - baseline: canonical typed ownership and bounded selected-list scan.
// - restored the two-counter do/while topology from the original backedge.
// - direct cursor dereferences recovered the repeated selected-list reloads.
// - zero-count early return preserved the original shared epilogue shape.
// - narrow volatile/count, hoisted-mask, and explicit-label variants were
//   diagnostic only and were rolled back as compiler-steering scaffolding.
// - left in scratch: structural drift remains in VC5 scheduling and loop
//   guard placement; no calls or unknown data ownership remain.
// - Main-agent audit restored canonical player/master/object destructor slots;
//   the validated structural gap is unchanged.

extern unsigned int DAT_0086bc88;
extern unsigned int DAT_0086bc8c;
extern float DAT_0057682c;
extern unsigned long tribe_group_properties[];
extern int tribe_group_properties_num;

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x46];
    short id;
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x0C];
    short id;
    short copy_id;
    short object_group;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    int id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x34];
    float attribute_amount_held;
};

class TRIBE_Player {
public:
    virtual ~TRIBE_Player();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void analyize_selected_objects();

    char gap_04[0x4A - 0x04];
    short id;
    char gap_4C[0x130 - 0x4C];
    RGE_Static_Object* selected_obj;
    RGE_Static_Object* sel_list[25];
    unsigned int sel_object_properties;
    short sel_count;
};

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
    do {
        if (this->sel_count <= j) {
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
        ++i;
        ++p;
    } while (i < 25);
}
