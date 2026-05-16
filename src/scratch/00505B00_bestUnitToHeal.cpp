// 00505B00 TribePriestUnitAIModule::bestUnitToHeal
// Attempt log:
// 1: Natural nested loops over four ally buckets: compiles 432 vs 445, wrong prologue/self in EBX and wrong canSee vtable surface.
// 2: Switch canSee to +0x194 virtual and bucket offset loop: exact size but 91% diff; self in ESI, 0x28 frame, bad global/list shape.
// 3: Use pointer-to-current bucket globals: frame 0x20 but self still ESI and broad diff.
// 4: Volatile self alias worsened prologue by homing this at [esp]; rolled back.
// 5: /Od and /O2-without-/Oy flag probes did not improve; removed custom flags.
// 6: Rewriting priority gates as <5/<3 worsened to 91.01% diff.
// 7: Naming fpriority before need calculation did not move first mismatch or improve diff.
// 8: Breaking outer loop then returning at function tail worsened to 89.89% diff.
// BLOCKER: remaining gap is TU/source-shape register allocation: original keeps this in EBP, bucket table pointer in ESI, object in EDI, and frame 0x1c; current best has self in ESI and frame 0x20. Final check: 445/445 bytes, 89.6629% positional diff, first mismatch offset 2.

extern unsigned int DAT_0087d7cc;
extern unsigned int DAT_0087d7d0;
extern unsigned int DAT_0087d7d4;
extern unsigned int DAT_0087d7d8;
extern unsigned int DAT_0087d7e4;
extern unsigned int DAT_0087d7e8;
extern unsigned int DAT_0087d7ec;
extern unsigned int DAT_0087d7f0;

struct RGE_Master_Static_Object {
    char gap_00[0x14];
    short object_group;
    char gap_16[0x10];
    short hp;
};

struct RGE_Static_Object {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual void vf74();
    virtual void vf75();
    virtual void vf76();
    virtual void vf77();
    virtual void vf78();
    virtual void vf79();
    virtual void vf80();
    virtual void vf81();
    virtual void vf82();
    virtual void vf83();
    virtual void vf84();
    virtual void vf85();
    virtual void vf86();
    virtual void vf87();
    virtual void vf88();
    virtual void vf89();
    virtual void vf90();
    virtual void vf91();
    virtual void vf92();
    virtual void vf93();
    virtual void vf94();
    virtual void vf95();
    virtual void vf96();
    virtual void vf97();
    virtual void vf98();
    virtual void vf99();
    virtual void vf100();
    virtual int canSeeObject(int id, float radius, int, int, int, int);
    int id;
    RGE_Master_Static_Object* master_obj;
    char gap_0c[0x30 - 0x0c];
    float hp;
    char gap_34[0x48 - 0x34];
    unsigned char object_state;
};

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual void save(int);
    virtual void load(int);
    virtual void* owner();
    virtual int order(int,int,int,int,float,float,float,float,int,int,int);
    virtual int notify(int,int,int,long,long,long);
    virtual int notifyCommander(int,int,int,long,long,long);
    virtual int notifyCommander(void*);
    virtual void search();
    RGE_Static_Object* obj;
    RGE_Static_Object* lookupObject(int unit_id);
};

class TribePriestUnitAIModule : public UnitAIModule {
public:
    int bestUnitToHeal(int param_1, float* param_2);
};

int TribePriestUnitAIModule::bestUnitToHeal(int param_1, float* param_2)
{
    this->search();

    int allyToHealID = -1;
    float allyNeed = 0.0f;
    int maxLimit = 2;

    if (*(short*)(*(char**)((char*)this->obj + 0x0c) + 0x4a) == 0) {
        maxLimit = 4;
    }

    int bucketOffset = 0;
    for (int a = 1; a <= maxLimit; ++a) {
        int* countPtr = (int*)((char*)&DAT_0087d7cc + bucketOffset);
        if (*countPtr > 0) {
            char** listPtr = (char**)((char*)&DAT_0087d7e4 + bucketOffset);
            for (int i = 0; i < *countPtr; ++i) {
                int offset = i * 8;
                int unit_id = *(int*)(*listPtr + offset);
                if (unit_id != this->obj->id) {
                    RGE_Static_Object* unit = this->lookupObject(unit_id);
                    if (unit != 0) {
                        RGE_Master_Static_Object* master = unit->master_obj;
                        if (master->object_group != 3) {
                            if ((float)(int)master->hp > unit->hp) {
                                if (unit->object_state < 3) {
                                    unsigned char priority = *(unsigned char*)(*listPtr + offset + 4);
                                    if (param_1 != 0 || priority <= 4) {
                                        if (*(short*)(*(char**)((char*)this->obj + 0x0c) + 0x4a) != 0 || priority <= 2) {
                                            if (this->obj->canSeeObject(unit_id, 1.0f, 0, 0, -1, -1)) {
                                                float need = (float)(int)master->hp - unit->hp / (float)(int)priority;
                                                if (allyToHealID == -1 || need < allyNeed) {
                                                    allyNeed = need;
                                                    allyToHealID = unit->id;
                                                    if (param_2 != 0) {
                                                        *param_2 = (float)(int)priority;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (allyToHealID != -1) {
            return allyToHealID;
        }
        bucketOffset += 4;
    }

    return -1;
}
