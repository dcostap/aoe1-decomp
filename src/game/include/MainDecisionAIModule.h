#pragma once
#include "common.h"

class MainDecisionAIModule {
public:
    MainDecisionAIModule();
    MainDecisionAIModule(void* param_1, int param_2, RGE_Player* param_3);
    MainDecisionAIModule(int param_1, RGE_Player* param_2, int param_3);

    // Virtuals (best-effort)
    virtual ~MainDecisionAIModule(); // vt[0] (0x0)
    virtual int loggingHistory(); // vt[1] (0x4)
    virtual void setLogHistory(int param_1); // vt[2] (0x8)
    virtual void toggleLogHistory(); // vt[3] (0xC)
    virtual void setHistoryFilename(char* param_1); // vt[4] (0x10)
    virtual int loggingCommonHistory(); // vt[5] (0x14)
    virtual void setLogCommonHistory(int param_1); // vt[6] (0x18)
    virtual void toggleLogCommonHistory(); // vt[7] (0x1C)
    virtual int loadState(char* param_1); // vt[8] (0x20)
    virtual int saveState(char* param_1); // vt[9] (0x24)
    virtual int gleanState(int param_1); // vt[10] (0x28)
    virtual int processMessage(AIModuleMessage* param_1); // vt[11] (0x2C)
    virtual int update(int param_1); // vt[12] (0x30)
    virtual void setCallbackMessage(AIModuleMessage* param_1); // vt[13] (0x34)
    virtual int filterOutMessage(AIModuleMessage* param_1); // vt[14] (0x38)
    virtual int save(int param_1); // vt[15] (0x3C)
    virtual int addObject(RGE_Static_Object* param_1); // vt[16] (0x40)
    virtual int removeObject(int param_1); // vt[17] (0x44)
    virtual int objectGroupThatCanPerformAction(int param_1); // vt[18] (0x48)
    virtual int canPerformAction(int param_1, int param_2); // vt[19] (0x4C)

    int numberObjects();
    int numberObjectsWithAction(int param_1);
    int numberObjectsWithGroup(int param_1);
    int numberObjectsWithActionAndTarget(int param_1, int param_2);
    int numberObjectsWithTargetType(int param_1);
    int numberObjectsWithActionAndTargetType(int param_1, int param_2);
    RGE_Static_Object* object(int param_1);
    RGE_Static_Object* object(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7, int param_8, int param_9, int param_10);
    RGE_Static_Object* object(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6);
    int numberBusyObjects();
    RGE_Static_Object* mostDamaged(int param_1, int param_2);

    int padding0;
    int padding1;
    int padding2;
    int padding3;
    int padding4;
    int padding5;
    int padding6;
    int padding7;
    int padding8;
    int padding9;
    int padding10;
    int padding11;
    int padding12;
    int padding13;
    int padding14;
    int padding15;
    int padding16;
    int padding17;
    int padding18;
    int padding19;
    int padding20;
    int padding21;
    int padding22;
    int padding23;
    int padding24;
    int padding25;
    int padding26;
    int padding27;
    int padding28;
    int padding29;
    int padding30;
    int padding31;
    int padding32;
    int padding33;
    int padding34;
    int padding35;
    int padding36;
    int padding37;
    int padding38;
    int padding39;
    int padding40;
    int padding41;
    int padding42;
    int padding43;
    int padding44;
    int padding45;
    int padding46;
    int padding47;
    int padding48;
    int padding49;
    int padding50;
    int padding51;
    int padding52;
    int padding53;
    int padding54;
    int padding55;
    int padding56;
    int padding57;
    int padding58;
    RGE_Player* player;
    ManagedArray<int> objects;
};
static_assert(sizeof(MainDecisionAIModule) == 0x104, "Size mismatch");
