#ifndef TAITACMD_SHARED_CONTEXT
// VA: 004F4AA0 TribeTacticalAIModule::taskUngroupedSoldiers
// PDB source: taitacmd.cpp lines 5522-5565
//
// CodeView proves i at -0x1C, soldierObj at -0x14, centerPoint at -0x10,
// and gatherPoint at -0x08. The move destination uses gatherPoint.x and y.
//
// The protected ManagedArray layout requires the public number, operator[],
// contains, add, and remove methods. The outer for-loop and direct
// findGatherPosition predicate are codegen-active. A named result changes
// inlined add allocation and loses exactness. Direct member expressions, the
// contains predicate spelling, and the two local declaration orders tested in
// reduction are incidental.
//
// BINARY NOTE: contains checks membership before add. Inlined add performs its
// own duplicate scan. Both scans are present in the original executable.
//
// SHARED-CONTEXT NOTE: the tactical header's nested operator[] growth changes
// this body from 740 to 852 bytes. The canonical utmarray.h surface keeps the
// resize calls out of line and preserves the exact body. Using that surface in
// the shared wrapper regresses earlier exact anchors, so this owner stays out.

#ifndef TAITACMD_SHARED_CONTEXT
#include "../../include/utmarray.h"
#endif

#ifndef TAITACMD_SHARED_CONTEXT
struct XYPoint {
    int x;
    int y;
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    unsigned long world_time;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_04[0x34];
    float world_x;
    float world_y;
};

class TribeInformationAIModule {
public:
    virtual ~TribeInformationAIModule();
    int findGatherPosition(XYPoint& center, int desiredUnits, int flag,
                           int sn16, int sn48, RGE_Static_Object* object,
                           XYPoint& gather);
};

class MainDecisionAIModule {
public:
    virtual ~MainDecisionAIModule();
    char gap_04[0xEC];
    RGE_Player* player;

    RGE_Static_Object* object(int objectID);
    RGE_Static_Object* object(int objectID, int type, int objectClass,
                              int action, int hasOrderFilter,
                              int resourceClass, int resourceSubclass,
                              int state, int minHitPoints,
                              int civilization);
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    char gap_F4[0xCEC - 0xF4];
    TribeInformationAIModule informationAI;
};

class TacticalAIModule {
public:
    virtual ~TacticalAIModule();
    char gap_04[0xEC];
};

class TacticalAIGroup;

class TribeTacticalAIModule : public TacticalAIModule {
public:
    TribeMainDecisionAIModule* md;
    ManagedArray<int> civilians;
    ManagedArray<int> civilianExplorers;
    ManagedArray<int> soldiers;
    ManagedArray<int> ungroupedSoldiers;
    ManagedArray<int> boats;
    ManagedArray<int> warBoats;
    ManagedArray<int> fishingBoats;
    ManagedArray<int> tradeBoats;
    ManagedArray<int> transportBoats;
    ManagedArray<int> artifacts;
    int sn[226];
    char gap_51C[0xFA8 - 0x51C];
    unsigned long lastUngroupedSoldierTaskTime;

    TacticalAIGroup* groupUnitIsIn(int unit);
    void moveUnit(int unit, float x, float y, int priority);
    void taskUngroupedSoldiers();
};
#endif

void TribeTacticalAIModule::taskUngroupedSoldiers()
{
    int i;
    XYPoint centerPoint;
    RGE_Static_Object* soldierObj;
    XYPoint gatherPoint;

    unsigned long currentTime = this->md->player->world->world_time;
    if ((currentTime - this->lastUngroupedSoldierTaskTime) / 1000 >= 60) {
        this->lastUngroupedSoldierTaskTime = currentTime;
        soldierObj = this->md->object(
            -1, 0x6D, -1, -1, -1, -1, -1, -1, -1, -1);
        if (soldierObj != 0) {
            centerPoint.x = (int)soldierObj->world_x;
            centerPoint.y = (int)soldierObj->world_y;
            for (i = 0; i < this->soldiers.number(); i++) {
                if (this->groupUnitIsIn(this->soldiers[i]) != 0) {
                    this->ungroupedSoldiers.remove(this->soldiers[i]);
                }
                else {
                    soldierObj = this->md->object(this->soldiers[i]);
                    if (soldierObj != 0) {
                        if (this->ungroupedSoldiers.contains(
                                this->soldiers[i]) == 0) {
                            this->ungroupedSoldiers.add(this->soldiers[i]);
                            if (this->md->informationAI.findGatherPosition(
                                    centerPoint, 1, 1,
                                    this->sn[0x16], this->sn[0x48],
                                    soldierObj, gatherPoint) == 1) {
                                this->moveUnit(
                                    this->soldiers[i],
                                    (float)gatherPoint.x,
                                    (float)gatherPoint.y, 0x32);
                            }
                        }
                    }
                }
            }
        }
    }
}
#else
void TribeTacticalAIModule::taskUngroupedSoldiers() {}
#endif
