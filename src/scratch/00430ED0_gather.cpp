// attempt 1: natural RGE_Combat_Object::gather with virtual-slot ladders for observed calls; size matched, first 0x2f bytes matched, but early-return epilogues differ from original shared epilogue
// tried goto/shared-result rewrites; they worsened register allocation (this moved to ESI, target to EDI) or added a result local, so rolled back to the cleaner natural basin
// Fresh worker probe: use one status pointer for the task/action result, as the
// original register topology suggests, while retaining a separate target.
// Follow-up: initialize that status to null instead of copying the target, so
// target/task failure can share the EAX-zero path without an explicit store.
// Follow-up 2: bind status to the task result immediately, testing whether the
// compiler can use the call's zero directly at the shared failure edge.
// The separate task/action form reduced the rebuild to 333 bytes and 77 strict
// differing bytes with all calls aligned; combined status/task forms regressed
// to 257 differing bytes and were rolled back. Remaining drift is the task-null
// branch's extra zero/jump versus the original direct EAX-zero edge.
// Main-agent audit restored canonical destructor ownership for action, world,
// player, static object, and combat object; natural task/action flow remains.
// Current worker: direct task-null returns (including returning the proven null
// task value) expanded the EH tail to 350 bytes/122 diff and were rolled back.
// Rewriting all failures/successes as direct returns or separating an int status
// expanded the function to 391 bytes; these forms are not the source basin.
// The prior pointer-status diagnostic remains the codegen frontier at 331/49,
// but it omits the task-null status assignment and is not retained as the clean
// behavior reconstruction. Canonical source remains 333/77 with all 16 calls.
// Remaining blocker is VC5 EH-tail lowering: the oracle branches `je` directly
// from the task call's zero EAX and, after construction, tests ESI then emits
// `xor eax,eax`; the natural shared-status source inserts extra zero/return moves.

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_04[0x34];
    int world_x;
    int world_y;
    int world_z;
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    RGE_Static_Object* object(int id);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world;
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual void avf01();
    virtual void avf02();
    virtual void avf03();
    virtual void avf04();
    virtual void avf05();
    virtual short action_type();
    virtual void avf07();
    virtual void avf08();
    virtual void avf09();
    virtual void avf10();
    virtual void avf11();
    virtual void avf12();
    virtual void set_target_pos(void* target, int x, int y, int z);
    virtual void avf14();
    virtual void avf15();
    virtual void avf16();
    virtual void avf17();
    virtual void avf18();
    virtual void* get_target();
};

class RGE_Action_List {
public:
    unsigned char have_action();
    RGE_Action* get_action();
    void delete_list();
};

class RGE_Task {
};

class RGE_Combat_Object;

class RGE_Action_Gather : public RGE_Action {
public:
    char data[0x44 - 4];
    RGE_Action_Gather(RGE_Combat_Object* object, RGE_Task* task, RGE_Static_Object* target);
};

class RGE_Combat_Object {
public:
    char gap_04[8];
    RGE_Player* player;
    char gap_10[0x174];
    RGE_Action_List* action_list;

    virtual ~RGE_Combat_Object();
    virtual void vf001();
    virtual void vf002();
    virtual void vf003();
    virtual void vf004();
    virtual void vf005();
    virtual void vf006();
    virtual void vf007();
    virtual void vf008();
    virtual void vf009();
    virtual void vf010();
    virtual void vf011();
    virtual void vf012();
    virtual void vf013();
    virtual void vf014();
    virtual void vf015();
    virtual void vf016();
    virtual void vf017();
    virtual void vf018();
    virtual void vf019();
    virtual void vf020();
    virtual void vf021();
    virtual void vf022();
    virtual void vf023();
    virtual void vf024();
    virtual void vf025();
    virtual void vf026();
    virtual void vf027();
    virtual void vf028();
    virtual void vf029();
    virtual void vf030();
    virtual void vf031();
    virtual void vf032();
    virtual void vf033();
    virtual void vf034();
    virtual void vf035();
    virtual void vf036();
    virtual void vf037();
    virtual void vf038();
    virtual void vf039();
    virtual void vf040();
    virtual void vf041();
    virtual void vf042();
    virtual void vf043();
    virtual void vf044();
    virtual void vf045();
    virtual void vf046();
    virtual void vf047();
    virtual void vf048();
    virtual void vf049();
    virtual void vf050();
    virtual void vf051();
    virtual void vf052();
    virtual void vf053();
    virtual void vf054();
    virtual void vf055();
    virtual void vf056();
    virtual void vf057();
    virtual void vf058();
    virtual void vf059();
    virtual void vf060();
    virtual void vf061();
    virtual void vf062();
    virtual void vf063();
    virtual void vf064();
    virtual void vf065();
    virtual void vf066();
    virtual void vf067();
    virtual void vf068();
    virtual void vf069();
    virtual void vf070();
    virtual void vf071();
    virtual void vf072();
    virtual void vf073();
    virtual void vf074();
    virtual void vf075();
    virtual void vf076();
    virtual void vf077();
    virtual void vf078();
    virtual void vf079();
    virtual void vf080();
    virtual void vf081();
    virtual void vf082();
    virtual void vf083();
    virtual void vf084();
    virtual void vf085();
    virtual void vf086();
    virtual void vf087();
    virtual void vf088();
    virtual void vf089();
    virtual void vf090();
    virtual void vf091();
    virtual void vf092();
    virtual void vf093();
    virtual void vf094();
    virtual void vf095();
    virtual void vf096();
    virtual void vf097();
    virtual void vf098();
    virtual void vf099();
    virtual void vf100();
    virtual void vf101();
    virtual void vf102();
    virtual void vf103();
    virtual void vf104();
    virtual void vf105();
    virtual void vf106();
    virtual void vf107();
    virtual void vf108();
    virtual void vf109();
    virtual void vf110();
    virtual void vf111();
    virtual void vf112();
    virtual void vf113();
    virtual void vf114();
    virtual void vf115();
    virtual void vf116();
    virtual void vf117();
    virtual void vf118();
    virtual void vf119();
    virtual void vf120();
    virtual void vf121();
    virtual void vf122();
    virtual void vf123();
    virtual void vf124();
    virtual void vf125();
    virtual void vf126();
    virtual void vf127();
    virtual void vf128();
    virtual void vf129();
    virtual int add_action(RGE_Action* action);
    virtual void vf131();
    virtual RGE_Task* create_gather_task(RGE_Static_Object* target, int x, int y, int z);

    virtual int gather(int object_id, int force);
};

int RGE_Combat_Object::gather(int object_id, int force) {
    RGE_Static_Object* target = this->player->world->object(object_id);
    RGE_Static_Object* result = target;
    RGE_Task* task;
    RGE_Action_Gather* action;
    if (target == 0) {
        goto done;
    }

    if (force == 0 &&
        this->action_list->have_action() == 1 &&
        this->action_list->get_action()->get_target() == target &&
        this->action_list->get_action()->action_type() == 5) {
        goto success;
    }

    if (this->action_list->have_action() == 1 &&
        this->action_list->get_action()->action_type() == 5) {
        this->action_list->get_action()->set_target_pos(target, target->world_x, target->world_y, target->world_z);
        goto success;
    }

    task = this->create_gather_task(target, target->world_x, target->world_y, target->world_z);
    if (task == 0) {
        result = 0;
        goto done;
    }

    action = new RGE_Action_Gather(this, task, target);
    result = (RGE_Static_Object*)action;
    if (action == 0) {
        goto done;
    }

    this->action_list->delete_list();
    this->add_action(action);
success:
    result = (RGE_Static_Object*)1;
done:
    return (int)result;
}
