#pragma once
#include "common.h"
#include "XYZ.h"

class RGE_Game_World;

struct AIPlayStatusGrouping {
    int id;
    unsigned char groupID;
    unsigned char type;
    unsigned char _pad_end[2];
};
static_assert(sizeof(AIPlayStatusGrouping) == 0x8, "Size mismatch");

struct AIPlayStatus {
    union {
        struct {
            AIPlayStatusGrouping groupings[50];
            int playNumberValue;
            int targetValue;
            XYZ originalPointValue;
            int originalHitPointsValue[5];
            unsigned char currentPhaseValue;
            unsigned char _pad_0[3];
            int savedAttackerValue;
            unsigned long lastPhaseChangeTimeValue;
            unsigned char deviationValue;
            unsigned char _pad_end[3];
        };
        unsigned char bytes[0x1C8];
    };

    AIPlayStatus();
    int originalHitPoints(int index) const;
    void setOriginalHitPoints(int index, int value);
    unsigned char numberInPlay() const;
    unsigned char numberInGroup(int group) const;
    unsigned char numberOfTypeInGroup(int group, int type) const;
    unsigned char group(int unitId) const;
    int addGrouping(int unitId, unsigned char group, unsigned char type);
    int removeGrouping(int unitId);
    void zeroAllGroupings();
    void copyUnits(int* units, int* count);
    void load(int fd);
    void save(int fd);
    void copy(AIPlayStatus* src);
    void removeDeadUnits(int group, RGE_Game_World* world);
    void resetHitPoints(int group, RGE_Game_World* world);
};
static_assert(sizeof(AIPlayStatus) == 0x1C8, "Size mismatch");

