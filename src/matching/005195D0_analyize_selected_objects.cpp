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

extern unsigned int DAT_0086bc88;
extern unsigned int DAT_0086bc8c;
extern float DAT_0057682c;
extern unsigned long tribe_group_properties[];
extern int tribe_group_properties_num;

class RGE_Static_Object;

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status();
    virtual void do_resign();
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual void aiStatus();
    virtual void isEnemy();
    virtual void isAlly();
    virtual void isNeutral();
    virtual void isAllNeutral();
    virtual void setDiplomaticStance();
    virtual void loadAIInformation();
    virtual void sendUnitAIOrder();
    virtual void processAIOrder();
    virtual void kickAI();
    virtual void strategicNumber();
    virtual void sendGameOrder();
    virtual void sendAddWaypointCommand();
    virtual void processAddWaypointCommand();
    virtual void sendPlayCommand();
    virtual void sendPlayCommand2();
    virtual void sendAICommand();
    virtual void objectCostByType();
    virtual void trackUnitGather();
    virtual void make_scenario_obj();
    virtual void scenario_save();
    virtual void scenario_load();
    virtual void scenario_postsave();
    virtual void scenario_postload();
    virtual void load();
    virtual void add_attribute_num();
    virtual void update();
    virtual void update_dopplegangers();
    virtual void save();
    virtual void save2();
    virtual void save_info();
    virtual void random_start();
    virtual void make_new_object();

    char gap_04[0x46];
    short id;
    char gap_4C[0xE4];
    RGE_Static_Object* selected_obj;
    RGE_Static_Object* sel_list[25];
    unsigned int sel_object_properties;
    short sel_count;
    char gap_19E[0x82];
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

class TRIBE_Player : public RGE_Player {
public:
    virtual void analyize_selected_objects();
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
