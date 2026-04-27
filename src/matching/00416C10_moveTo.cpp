// attempt 2: use a vtable-shaped RGE_Static_Object stub so the moveTo call lands on the observed 0x154 slot
// blocker watch: the prior direct-function-pointer form called the wrong slot; this probe keeps the gate logic but changes only the object surface
#include "..\..\include\game_types.h"

class RGE_Static_Object {
public:
    void* vtable_ptr;
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
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
    virtual int moveTo(float param_1, float param_2, float param_3, float param_4, int param_5);
};

class UnitAIModule {
public:
    char gap_00[0x4];
    RGE_Static_Object* objectValue;
    char gap_08[0x28];
    int currentActionValue;

    void setCurrentAction(int value);
    void setCurrentTarget(int id, float x, float y, float z);
    int moveTo(float param_1, float param_2, float param_3, float param_4, int param_5);
};

int UnitAIModule::moveTo(float param_1, float param_2, float param_3, float param_4, int param_5) {
    int result;

    if (param_5 != 0 || this->currentActionValue == -1) {
        result = this->objectValue->moveTo(param_1, param_2, param_3, param_4, param_5);
        if (result == 1) {
            this->setCurrentAction(0x262);
            this->setCurrentTarget(-1, param_1, param_2, param_3);
            return 1;
        }
    }
    return 0;
}
