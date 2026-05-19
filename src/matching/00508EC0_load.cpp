// 00508EC0 RGE_Task_List::load (task_lst.cpp:63-81, 155B)
// MATCHED 2026-05-19. Default flags.
// Key fix after prior give-up: keep `register RGE_Task_List* self = this`, but make the
// loop counter an int and cast only at the compare/index uses. That gives VC5 the original
// EBX=this / ESI=&list_num register split and SHL index sequence.

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
    register RGE_Task_List* self = this;

    if (self->list)
        self->delete_list();

    rge_read(handle, &self->list_num, 2);
    if (self->list_num <= 0)
        return;

    self->list = (RGE_Task**)calloc(self->list_num, 4);
    for (int i = 0; (short)i < self->list_num; i++) {
        rge_read(handle, &local_type, 2);
        self->list[(short)i] = self->create_task(local_type, i);
        self->list[(short)i]->load(handle, sprites, sounds);
    }
}
