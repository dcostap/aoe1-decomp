// 00508EC0 RGE_Task_List::load (task_lst.cpp:63-81, 155B)
// STATUS: GIVEN_UP (see attempt log)
// FLAGS: default
//
// Attempt log (2026-05-19):
// Probe 1 (existing from previous work): 41% positional diff
// try 1-2: same result - register allocation swap (this=esi, list_ptr=ebx vs this=ebx, list_ptr=esi)
// try 3-4: various C++ restructuring - no improvement
// try 5: self = this const pointer - same result
// GIVEUP: VC5 allocates `this` to ESI (not EBX) in isolated compilation.
//   Original from full TU has this=ebx, list_num_ptr=esi; rebuilt has this=esi, list_num_ptr=ebx.
//   This register swap cascades through the function body (prologue order, index calc regs,
//   jump distances). All code is semantically equivalent - only register coloring differs.
//   Requires full translation-unit context or compiler-hint override to fix.

class RGE_Sprite;
class RGE_Sound;

class RGE_Task {
public:
    short task_type;
    char gap_02[2];
    void load(int handle, RGE_Sprite** sprites, RGE_Sound** sounds);
};

extern void* __cdecl calloc(int, int);
extern int __cdecl rge_read(int handle, void* buf, int size);

class RGE_Task_List {
public:
    virtual RGE_Task* create_task(short task_type, int index);
    RGE_Task** list;        // +0x04
    short list_num;         // +0x08

    void delete_list();
    void load(int handle, RGE_Sprite** sprites, RGE_Sound** sounds);
};

void RGE_Task_List::load(int handle, RGE_Sprite** sprites, RGE_Sound** sounds)
{
    short local_type;
    RGE_Task_List* const self = this;

    // Access this->list FIRST
    if (self->list)
        self->delete_list();

    rge_read(handle, &self->list_num, 2);
    if (self->list_num <= 0)
        return;

    self->list = (RGE_Task**)calloc(self->list_num, 4);
    for (short i = 0; i < self->list_num; i++) {
        rge_read(handle, &local_type, 2);
        self->list[i] = self->create_task(local_type, i);
        self->list[i]->load(handle, sprites, sounds);
    }
}
