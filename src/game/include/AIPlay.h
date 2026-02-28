#pragma once
#include "common.h"

#include "AIPlayGroup.h"
#include "AIPlayPhase.h"

class AIPlayStatus;
class RGE_Game_World;

struct AIPlay {
    char nameValue[65];
    uchar minimumNumberUnitsValue;
    uchar maximumNumberUnitsValue;
    uchar typeValue;
    uchar targetTypeValue[5];
    uchar targetCharacteristicValue[5];
    uchar powerValue;
    uchar overflowValue;
    uchar intelligenceValue;
    uchar deathPercentageValue;
    uchar numberGroupsValue;
    AIPlayGroup groups[5];
    AIPlayPhase phases[10];

    AIPlay();
    void setName(char* name);
    int humanPlay() const;
    char* typeName() const;
    uchar targetType(int index) const;
    int isTargetType(uchar type) const;
    int addTargetType(uchar type);
    uchar targetCharacteristic(int index) const;
    int isTargetCharacteristic(uchar characteristic) const;
    int addTargetCharacteristic(uchar characteristic);
    int gatherTolerance(int unused, int phaseIndex);
    AIPlayGroup* group(int index);
    AIPlayPhase* phase(int index);
    int fillGroups(AIPlayStatus* status, int* units, int unitCount, RGE_Game_World* world);
    int groupGivenCommandOnPhase(int groupNumber, int commandType, int phaseIndex);
    int locationsOnMap(int xOffset, int yOffset, int width, int height);

protected:
    uchar convertToIntType(char* typeName) const;
    char* convertToNameType(uchar type) const;
};
static_assert(sizeof(AIPlay) == 0x608, "Size mismatch");
