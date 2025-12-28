#pragma once
#include "../types.h"

enum TRIBE_MapType {
    MapTypeNone=0,
    MapTypeBlank=1,
    MapTypeRandom=2,
    MapTypeSeed=3
};

enum TRIBE_VictoryType {
    VictoryTypeNone=0,
    VictoryTypeStandard=1,
    VictoryTypeConquest=2,
    VictoryTypeScore=3,
    VictoryTypeTime=4,
    VictoryTypeCustom=5
};

// TRIBE_Game_Options - 108 bytes per layout.json
struct TRIBE_Game_Options {
    /* 0x00 */ enum MapSize mapSizeValue;
    /* 0x04 */ enum TRIBE_MapType mapTypeValue;
    /* 0x08 */ int animalsValue;
    /* 0x0C */ int predatorsValue;
    /* 0x10 */ enum TRIBE_VictoryType victoryTypeValue;
    /* 0x14 */ int victoryAmountValue;
    /* 0x18 */ uchar civilizationValue[9];
    // Compiler adds 3 bytes padding here to align next int
    /* 0x24 */ int scenarioPlayerValue[9];
    /* 0x48 */ uchar playerColorValue[9];
    /* 0x51 */ uchar computerNameValue[9];
    /* 0x5A */ uchar allowTradingValue;
    /* 0x5B */ uchar longCombatValue;
    /* 0x5C */ uchar randomizePositionsValue;
    /* 0x5D */ uchar fullTechTreeValue;
    // Compiler adds 2 bytes padding here to align next enum
    /* 0x60 */ enum ResourceLevel resourceLevelValue;
    /* 0x64 */ enum Age startingAgeValue;
    /* 0x68 */ uchar startingUnitsValue;
    /* 0x69 */ uchar deathMatchValue;
    /* 0x6A */ uchar popLimitValue;
    // Compiler adds 1 byte padding to reach 108 bytes
};

// MANDATORY VERIFICATION
static_assert(sizeof(TRIBE_Game_Options) == 0x6C, "TRIBE_Game_Options size mismatch");
