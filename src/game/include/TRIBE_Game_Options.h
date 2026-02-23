#pragma once
#include "common.h"

typedef int MapSize;
typedef int MapType;
typedef int VictoryType;
typedef int ResourceLevel;
typedef int Age;

// Decomp uses these symbolic defaults in several screens (e.g. scr_cams.cpp.decomp).
// Verified by ASM call sites: all are passed as literal 0.
enum {
    VictoryDefault = 0,
    DefaultResources = 0,
    DefaultAge = 0,
};

struct TRIBE_Game_Options {
    MapSize mapSizeValue;
    MapType mapTypeValue;
    int animalsValue;
    int predatorsValue;
    VictoryType victoryTypeValue;
    int victoryAmountValue;
    uchar civilizationValue[9];
    int scenarioPlayerValue[9];
    uchar playerColorValue[9];
    uchar computerNameValue[9];
    uchar allowTradingValue;
    uchar longCombatValue;
    uchar randomizePositionsValue;
    uchar fullTechTreeValue;
    ResourceLevel resourceLevelValue;
    Age startingAgeValue;
    uchar startingUnitsValue;
    uchar deathMatchValue;
    uchar popLimitValue;
};
static_assert(sizeof(TRIBE_Game_Options) == 0x6C, "Size mismatch");
