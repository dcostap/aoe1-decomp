// target: VA 004162C0 UnitAIModule::stopObject(int)
// first pass: natural object/log/update/stop sequence with direct nested member access
// tried a direct fprintf/logFile shape; actionFile still codegens as eax-load/test, not the original ecx basin
// tried the 0x18C call as a deep virtual slot; object layout and vtable-call basin still need more work

#include <stdio.h>

extern FILE* actionFile;

class RGE_World {
public:
    void* vtable_ptr;
    long world_time; // +0x4
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_World* world; // +0x3C
};

class RGE_Static_Object {
public:
    void* vtable_ptr;
    long id; // +0x4
    char gap_08[4];
    RGE_Player* owner; // +0xC
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
    virtual void stopAction();
};

class UnitAIModule {
public:
    void* vtable_ptr; // +0x0
    RGE_Static_Object* objectValue; // +0x4
    int moodValue;
    int objectCategoryValue;
    int orderQueueSizeValue;
    int orderQueueMaxSizeValue;
    void* orderQueueValue;
    int notifyQueueSizeValue;
    int notifyQueueMaxSizeValue;
    void* notifyQueueValue;
    int currentOrderValue; // +0x28
    int currentOrderPriorityValue; // +0x2C
    int currentActionValue; // +0x30
    int currentTargetValue;
    int currentTargetTypeValue;
    float currentTargetXValue;
    float currentTargetYValue;
    float currentTargetZValue;
    float desiredTargetDistanceValue;
    int defendTargetValue;
    int lastOrderValue; // +0x50
    int lastActionValue; // +0x54

    int stopObject(int param);
};

int UnitAIModule::stopObject(int param) {
    RGE_Static_Object* object;
    FILE* logFile;

    object = this->objectValue;
    logFile = actionFile;
    if (logFile != 0) {
        fprintf(logFile, "t%ld, U#%d sO, cOAA=%d.\n", object->owner->world->world_time, object->id, param);
    }

    this->lastActionValue = this->currentActionValue;
    if (param == 0 || this->currentActionValue + 0x64 == this->currentOrderValue) {
        this->lastOrderValue = this->currentOrderValue;
        this->currentOrderValue = -1;
        this->currentOrderPriorityValue = -1;
    }

    object->stopAction();
    this->currentActionValue = -1;
    return 1;
}
