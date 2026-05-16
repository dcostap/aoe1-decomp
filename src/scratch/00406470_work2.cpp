// 00406470 RGE_Action_Object::work2
// scratch give-up: natural reconstruction from packet; broad action/task + UI switch. Tried explicit
// ActionFactory/RGE_Task/RGE_Action_List virtual surfaces, matching switch constants/order, direct this
// member calls for p54/p9c/p208, and fallback task-work paths. It compiles to exact size 789 but broad
// mismatch (79.47% positional / 115.34% edit); first mismatch is prologue/register allocation (target
// loaded into EDI before EBP, push order differs), and the action/task call surface is too approximate.

typedef unsigned char uchar;
struct RGE_Task; struct RGE_Action_Object; struct RGE_Static_Object;
struct ActionFactory { virtual void p0(); virtual RGE_Task* work(RGE_Action_Object*, RGE_Static_Object*, float, float, float); };
struct RGE_Static_Object { char pad04[4]; uchar owner; char pad05[3]; void* object_type; char pad0c[8]; short id2; char pad16[0xd6]; uchar field_ec; ActionFactory* action_factory; };
struct RGE_Task { virtual void p0(); virtual RGE_Task* work(RGE_Static_Object*, float, float, float, uchar); virtual void p8(); virtual void pc(); virtual void p10(); virtual void p14(); virtual short action_id(); virtual void p1c(); virtual void p20(); virtual void p24(); virtual void p28(); virtual void p2c(); virtual void p30(); virtual int can_work(RGE_Static_Object*, float, float, float); virtual void p38(); virtual void p3c(); virtual void p40(); virtual void p44(); virtual RGE_Static_Object* target(); };
struct RGE_Action_List { virtual void p0(); virtual RGE_Task* work(RGE_Task*, RGE_Static_Object*, float, float, float); RGE_Task* get_task(); uchar have_action(); RGE_Task* get_action(); int action_work(RGE_Static_Object*, float, float, float); };
struct UnitAIModule { void setCurrentOrder(int); void setCurrentAction(int); void setCurrentTarget(int,int,float,float,uchar); void setTaskedByPlayer(); };
struct Contained { short count; void* list; };
struct RGE_Action_Object { virtual void p0(); char gap04[4]; RGE_Static_Object* obj; Contained* contained; char gap10[0x64]; UnitAIModule* unitAI; char gap78[0x10c]; RGE_Action_List* actions; virtual void p54(RGE_Static_Object*); virtual void p9c(RGE_Static_Object*, float,float,float, uchar); virtual void p208(RGE_Task*); void work2(RGE_Static_Object*, float,float,float, uchar); };
extern "C" void __cdecl setCurrentOrder(UnitAIModule*, int);

void RGE_Action_Object::work2(RGE_Static_Object* target, float a, float b, float c, uchar d)
{
    int skip;
    RGE_Task* task;
    int action_id;
    RGE_Static_Object* other;
    int i;
    int order;
    int action;

    if ((RGE_Action_Object*)target == this) return;
    task = this->obj->action_factory ? this->obj->action_factory->work(this, target, a, b, c) : 0;
    if (task == 0 && this->obj->field_ec != 0) {
        i = 0;
        if (this->contained->count > 0) {
            do {
                other = ((RGE_Static_Object**)this->contained->list)[i];
                if (other != 0 && other->id2 == this->obj->id2 && other->owner == this->obj->owner && other->field_ec == this->obj->field_ec) {
                    task = other->action_factory->work(this, target, a, b, c);
                    if (task != 0) { this->p54(other); break; }
                }
                i++;
            } while (i < this->contained->count);
        }
    }
    skip = 0;
    action_id = -1;
    if (this->actions->get_task() != 0 && task == this->actions->get_task()) {
        if (this->actions->action_work(target, a, b, c)) { action_id = this->actions->get_action()->action_id(); skip = 1; }
    }
    if (this->actions->have_action() == 1) {
        if (this->actions->get_action()->target() == target && this->actions->get_action()->action_id() == 9) {
            if (this->actions->get_action()->can_work(target,a,b,c)) { action_id = this->actions->get_action()->action_id(); skip = 1; }
        }
    }
    if (!skip) {
        if (task) task = this->actions->work(task, target, a,b,c); else task = 0;
        if (task) { action_id = task->action_id(); this->p208(task); }
        else { action_id = 1; this->p9c(target,a,b,c,d); }
    }
    if (this->unitAI == 0) return;
    order = -1; action = -1;
    switch(action_id) {
    case 9: order=0x2bc; action=0x258; break;
    case 0x65: order=0x2be; action=0x25a; break;
    case 3: order=0x2cd; action=0x269; break;
    case 4: order=0x2c1; action=0x25d; break;
    case 5: order=0x2c5; action=0x261; break;
    case 1: order=0x2c6; action=0x262; break;
    case 0x6e: order=0x2c9; action=0x265; break;
    case 0xc: order=0x2ca; action=0x266; break;
    case 0x6f: order=0x2cb; action=0x267; break;
    case 0x68: order=0x2c0; action=0x25c; break;
    case 0x69: order=0x2bf; action=0x25b; break;
    case 0x6a: order=0x2ce; action=0x26a; break;
    }
    this->unitAI->setCurrentOrder(order);
    this->unitAI->setCurrentAction(action);
    if (target) this->unitAI->setCurrentTarget(target->object_type ? *(short*)((char*)target->object_type+0x14) : -1, *(int*)((char*)target+4), a,b,d);
    else this->unitAI->setCurrentTarget(-1,-1,a,b,d);
    this->unitAI->setTaskedByPlayer();
}
