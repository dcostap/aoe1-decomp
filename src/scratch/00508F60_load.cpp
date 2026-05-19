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
