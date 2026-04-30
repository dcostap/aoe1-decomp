// VA: 004162C0 stopObject (118B)
// aiuaimod.cpp

#include <stdio.h>

extern FILE* actionFile;

class RGE_World {
public:
    long world_time; // +0x4
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_World* world; // +0x3C
};

class RGE_Static_Object {
public:
    int id; // +0x4
    RGE_Player* owner; // +0xC
    // Extends to various vtable slots
};

// Vtable proxy with exactly 100 virtual slots (0x18C/4 = 99)
struct ObjVtable {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63();
    virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67();
    virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71();
    virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75();
    virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
    virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83();
    virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87();
    virtual void v88(); virtual void v89(); virtual void v90(); virtual void v91();
    virtual void v92(); virtual void v93(); virtual void v94(); virtual void v95();
    virtual void v96(); virtual void v97(); virtual void v98();
    virtual void stopAction(); // vtable[99] = offset 0x18C
};

class UnitAIModule {
public:
    void* vtable_ptr; // +0x0
    RGE_Static_Object* objectValue; // +0x4
    int moodValue; // +0x8
    int objectCategoryValue; // +0xC
    int orderQueueSizeValue; // +0x10
    int orderQueueMaxSizeValue; // +0x14
    void* orderQueueValue; // +0x18
    int notifyQueueSizeValue; // +0x1C
    int notifyQueueMaxSizeValue; // +0x20
    void* notifyQueueValue; // +0x24
    int currentOrderValue; // +0x28
    int currentOrderPriorityValue; // +0x2C
    int currentActionValue; // +0x30
    int currentTargetValue; // +0x34
    int currentTargetTypeValue; // +0x38
    float currentTargetXValue; // +0x3C
    float currentTargetYValue; // +0x40
    float currentTargetZValue; // +0x44
    float desiredTargetDistanceValue; // +0x48
    int defendTargetValue; // +0x4C
    int lastOrderValue; // +0x50
    int lastActionValue; // +0x54

    int stopObject(int param);
};

int UnitAIModule::stopObject(int param) {
    if (actionFile != 0) {
        fprintf(actionFile, "t%ld, U#%d sO, cOAA=%d.\n",
            objectValue->owner->world->world_time,
            objectValue->id,
            param);
    }

    lastActionValue = currentActionValue;
    if (param == 0 || currentActionValue + 100 == currentOrderValue) {
        lastOrderValue = currentOrderValue;
        currentOrderValue = -1;
        currentOrderPriorityValue = -1;
    }

    ((ObjVtable*)(void*)objectValue)->stopAction();
    currentActionValue = -1;
    return 1;
}
