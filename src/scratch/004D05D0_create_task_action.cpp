// VA: 004D05D0 TActionList::create_task_action
// PDB source: tact_lst.cpp
// Attempt log:
// - broad switch reconstruction from packet: allocate action by task type, choose short/long constructor based on optional existing action arg, fallback to base factory.
// - used /GX because original has EH registration/unwind states around operator new + constructor calls.
// - /O2 /Oy /GX compiles but .text is 1280 bytes vs target 1496, too short for extraction; helper factoring collapses the original per-case duplicated new/ctor/return arms.
// - tried /Od /Oy- /GX diagnostically: 1484 bytes, still too short and wrong EBP/debug frame family.
// - restored /O2 /Oy /GX. Give-up: needs exact task type grouping/switch table and explicit per-class constructor declarations/source arms; no accepted_drift proposed.

extern void* operator new(unsigned int);
struct Task { char gap0[6]; short type; };
struct ActionList { char gap0[4]; void* owner; void* create_task_action(Task*, int, int, int, void*); };
struct A40 { A40(void*,Task*,void*); A40(void*,Task*,int,int,int); };
struct A48 { A48(void*,Task*,void*); A48(void*,Task*,int,int,int); };
struct A44 { A44(void*,Task*,void*); A44(void*,Task*,int,int,int); };
struct A0 { A0(void*,Task*,void*); A0(void*,Task*,int,int,int); };
struct Only { Only(void*); };
extern void* base_factory(ActionList*,Task*,int,int,int,void*);

static void* make40(void* o, Task* t, int a,int b,int c, void* old){ if(old) return new A40(o,t,old); return new A40(o,t,a,b,c); }
static void* make48(void* o, Task* t, int a,int b,int c, void* old){ if(old) return new A48(o,t,old); return new A48(o,t,a,b,c); }
static void* make44(void* o, Task* t, int a,int b,int c, void* old){ if(old) return new A44(o,t,old); return new A44(o,t,a,b,c); }
static void* make0(void* o, Task* t, int a,int b,int c, void* old){ if(old) return new A0(o,t,old); return new A0(o,t,a,b,c); }

void* ActionList::create_task_action(Task* task, int a, int b, int c, void* old)
{
    switch(task->type) {
    case 3: case 4: return make40(owner,task,a,b,c,old);
    case 5: case 6: return make48(owner,task,a,b,c,old);
    case 7: case 8: return make40(owner,task,a,b,c,old);
    case 9: case 10: return make40(owner,task,a,b,c,old);
    case 11: return new Only(owner);
    case 12: case 13: return make44(owner,task,a,b,c,old);
    case 14: case 15: return make44(owner,task,a,b,c,old);
    case 16: case 17: return make48(owner,task,a,b,c,old);
    case 18: return make0(owner,task,a,b,c,old);
    case 19: return make40(owner,task,a,b,c,old);
    default: return base_factory(this,task,a,b,c,old);
    }
}
