// Canonical ownership: owner_data->world resolves the target; actions is the
// inherited action list at +0x184. RGE_Action is the 0x40-byte action base,
// and TRIBE_Action_Heal uses the proven +0x40 constructor allocation.
// Attempt log:
// - baseline: corrected the action ABI, float target coordinates, action-list
//   delete_list, object slots +0x208/+0x210, and 0x40-byte allocation.
// - positive target guard improved the first body shape but left duplicated
//   success/failure epilogues.
// - typed target-result reuse restored exact size, one-return CFG, and 97.27%
//   instruction shape; remaining drift is the VC5 result-register basin and
//   isolated EH-handler address, matching the paired hunt/convert lead.
// - bounded follow-up: an uninitialized/int result status expanded to 421B;
//   scalar int status was byte-identical to the clean pointer source.
// - explicit success/failure labels improved diagnostic resync to 350B/100
//   differing bytes but duplicated the EH return path; block-scoped locals did
//   not change it. Restored the typed result source.
// - single target/status pointer reuse reached 333B/77 differing bytes and
//   exact code through the task call; remaining drift is the task-null zero
//   edge (rebuilt xor-esi/jump) and final status return (mov esi,1; mov eax,esi).
//   Removing task zeroing reached 331B/48 only by returning the nonzero target
//   on task failure, so it was diagnostic and rolled back. A scoped constructor
//   target copy and constructor-result assignment did not improve the basin.
// - The typed result-pointer reconstruction was diagnostic compiler steering.
//   Target, task, action, and status have separate ownership in living source.
// - fresh pass: initialized and uninitialized scalar result forms, reversed
//   declaration order, TU-style top-scoped task/action locals, and base-action
//   typing were nonproductive or duplicate codegen.
// - fresh best: use one result pointer as target through make_action, then
//   preserve the target with a late action_target alias before reusing result
//   for task/action status. This reaches 333 bytes, 77 differing bytes, and
//   93.05% resync similarity with all calls aligned. Moving the alias before
//   make_action swaps target/task registers and worsens the result to 93 bytes.
//   This was diagnostic only. The natural typed control flow remains authoritative.
// FLAGS: config/flags/004CB300_heal.rsp (/GX)

class RGE_Action_Object;
class RGE_Task;
class RGE_Static_Object { public: char gap_00[0x38]; float x; float y; float z; };
class RGE_Game_World { public: RGE_Static_Object* object(int id); };
class GameShell { public: char gap_00[0x3C]; RGE_Game_World* world; };
class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual void vf04(); virtual void vf08(); virtual void vf0C(); virtual void vf10(); virtual void vf14();
    virtual short action_id();
    virtual void vf1C(); virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C(); virtual void vf30();
    virtual void set_target(RGE_Static_Object*, float, float, float);
    virtual void vf38(); virtual void vf3C(); virtual void vf40(); virtual void vf44(); virtual void vf48();
    virtual RGE_Static_Object* target_obj();

    char gap_04[0x3C];
};
class RGE_Action_List { public: unsigned char have_action(); RGE_Action* get_action(); void delete_list(); };
class TRIBE_Action_Heal : public RGE_Action {
public:
    TRIBE_Action_Heal(RGE_Action_Object* owner, RGE_Task* obj, RGE_Static_Object* target);
};
class TRIBE_Combat_Object {
public:
    virtual void vf000(); virtual void vf004(); virtual void vf008(); virtual void vf00C(); virtual void vf010(); virtual void vf014(); virtual void vf018(); virtual void vf01C();
    virtual void vf020(); virtual void vf024(); virtual void vf028(); virtual void vf02C(); virtual void vf030(); virtual void vf034(); virtual void vf038(); virtual void vf03C();
    virtual void vf040(); virtual void vf044(); virtual void vf048(); virtual void vf04C(); virtual void vf050(); virtual void vf054(); virtual void vf058(); virtual void vf05C();
    virtual void vf060(); virtual void vf064(); virtual void vf068(); virtual void vf06C(); virtual void vf070(); virtual void vf074(); virtual void vf078(); virtual void vf07C();
    virtual void vf080(); virtual void vf084(); virtual void vf088(); virtual void vf08C(); virtual void vf090(); virtual void vf094(); virtual void vf098(); virtual void vf09C();
    virtual void vf0A0(); virtual void vf0A4(); virtual void vf0A8(); virtual void vf0AC(); virtual void vf0B0(); virtual void vf0B4(); virtual void vf0B8(); virtual void vf0BC();
    virtual void vf0C0(); virtual void vf0C4(); virtual void vf0C8(); virtual void vf0CC(); virtual void vf0D0(); virtual void vf0D4(); virtual void vf0D8(); virtual void vf0DC();
    virtual void vf0E0(); virtual void vf0E4(); virtual void vf0E8(); virtual void vf0EC(); virtual void vf0F0(); virtual void vf0F4(); virtual void vf0F8(); virtual void vf0FC();
    virtual void vf100(); virtual void vf104(); virtual void vf108(); virtual void vf10C();
    virtual void vf110(); virtual void vf114(); virtual void vf118(); virtual void vf11C();
    virtual void vf120(); virtual void vf124(); virtual void vf128(); virtual void vf12C();
    virtual void vf130(); virtual void vf134(); virtual void vf138(); virtual void vf13C();
    virtual void vf140(); virtual void vf144(); virtual void vf148(); virtual void vf14C();
    virtual void vf150(); virtual void vf154(); virtual void vf158(); virtual void vf15C();
    virtual void vf160(); virtual void vf164(); virtual void vf168(); virtual void vf16C();
    virtual void vf170(); virtual void vf174(); virtual void vf178(); virtual void vf17C();
    virtual void vf180(); virtual void vf184(); virtual void vf188(); virtual void vf18C();
    virtual void vf190(); virtual void vf194(); virtual void vf198(); virtual void vf19C();
    virtual void vf1A0(); virtual void vf1A4(); virtual void vf1A8(); virtual void vf1AC();
    virtual void vf1B0(); virtual void vf1B4(); virtual void vf1B8(); virtual void vf1BC();
    virtual void vf1C0(); virtual void vf1C4(); virtual void vf1C8(); virtual void vf1CC();
    virtual void vf1D0(); virtual void vf1D4(); virtual void vf1D8(); virtual void vf1DC();
    virtual void vf1E0(); virtual void vf1E4(); virtual void vf1E8(); virtual void vf1EC();
    virtual void vf1F0(); virtual void vf1F4(); virtual void vf1F8(); virtual void vf1FC();
    virtual void vf200(); virtual void vf204();
    virtual void add_action(RGE_Action*);
    virtual void vf20C();
    virtual RGE_Task* make_action(RGE_Static_Object*, float, float, float);
    char gap_004[8]; GameShell* game; char gap_010[0x174]; RGE_Action_List* action_list;
    int heal(int id, int flag);
};

int TRIBE_Combat_Object::heal(int id, int flag) {
    RGE_Static_Object* target = this->game->world->object(id);
    if (target == 0)
        return 0;

    if (flag == 0 && this->action_list->have_action() == 1 && this->action_list->get_action()->target_obj() == target && this->action_list->get_action()->action_id() == 0x69)
        return 1;

    if (this->action_list->have_action() == 1 && this->action_list->get_action()->action_id() == 0x69) {
        this->action_list->get_action()->set_target(target, target->x, target->y, target->z);
        return 1;
    }

    RGE_Task* task = this->make_action(target, target->x, target->y, target->z);
    if (task == 0)
        return 0;

    TRIBE_Action_Heal* action = new TRIBE_Action_Heal((RGE_Action_Object*)this, task, target);
    if (action == 0)
        return 0;

    this->action_list->delete_list();
    this->add_action(action);
    return 1;
}
