// 00508F60 RGE_Task_List::load
// task_lst.cpp lines 86-107, 161 bytes
// Round2 pass: tried 15 variants: direct for-loop, short*/short& count pointer,
// explicit self local/register, do/while vs while, int vs short loop counter, cached
// task array, temporary RGE_Task*, and alternate member/reference spellings.
// Best retained source is exact-size 161 bytes but non-exact: MISMATCH 39.7516%
// positional / 26.0870% edit, first mismatch 2. Remaining drift is broad VC5
// register-allocation basin (rebuilt keeps this in ESI and list_num pointer in EBX;
// original keeps this in EBX and list_num pointer/index offset in ESI) plus loop index
// address scheduling. Not accepted-drift quality.
// Retry 2026-05-20 Boss pass: revalidated baseline (161B, 39.7516% positional,
// 26.0870% edit, first mismatch +2). Tried 13 additional probes: self alias with
// count pointer/int index, register self, short-index variant, int task_type/local_4
// plus explicit vtable local, cached arr local, /O2 without /Oy, /Ox, /Oa, /Og,
// /O1, and explicit vtable function-pointer calls with __cdecl/__stdcall/default
// signatures. None fixed the EBX/ESI this-vs-count register basin; best edit-only
// probe (__stdcall vtable pointer) reached 25.4658% edit but used the wrong call
// convention/stack shape family and did not improve positional diff. Kept baseline.
// Retry 2026-05-21 Boss pass: tried explicit self+count aliases, register self/count,
// int task_type, int loop index, task local, cached tasks array, while/do-while loop
// forms, create_task(int,int), int-return RGE_Task::load/delete_list, unsigned list_num,
// and /G5 /Op /Gr flags. Most either stayed in the wrong ESI=this/EBX=count basin or
// shrank to 160B / broadly regressed; none recovered original EBX=this and ESI=list_num
// pointer/index-offset sharing. Restored exact-size baseline; no accepted_drift proposal.

struct FILE;
class RGE_Sprite;
class RGE_Sound;

class RGE_Task {
public:
    void load(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds);
};

extern int __cdecl fscanf(FILE* file, const char* format, ...);
extern void* __cdecl calloc(int count, int size);

class RGE_Task_List {
public:
    virtual RGE_Task* create_task(short task_type, int index);
    RGE_Task** list;
    short list_num;

    void delete_list();
    void load(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds);
};

void RGE_Task_List::load(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds)
{
    short task_type;

    if (list)
        delete_list();

    fscanf(file, "%hd", &list_num);
    if (list_num > 0) {
        list = (RGE_Task**)calloc((int)list_num, 4);
        for (short i = 0; i < list_num; i++) {
            fscanf(file, "%hd", &task_type);
            list[i] = create_task(task_type, i);
            list[i]->load(file, sprites, sounds);
        }
    }
}
