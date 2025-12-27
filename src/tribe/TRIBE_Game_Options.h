#pragma once
#include "../types.h"

#pragma pack(push, 1)

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

struct TRIBE_Game_Options {
    /* 0x00 */ enum MapSize mapSizeValue;
    /* 0x04 */ enum TRIBE_MapType mapTypeValue;
    /* 0x08 */ int animalsValue;
    /* 0x0c */ int predatorsValue;
    /* 0x10 */ enum TRIBE_VictoryType victoryTypeValue;
    /* 0x14 */ int victoryAmountValue;
    /* 0x18 */ uchar civilizationValue[9];
    /* 0x21 */ uchar _pad_21[3];
    /* 0x24 */ int scenarioPlayerValue[9];
    /* 0x48 */ uchar playerColorValue[9];
    /* 0x51 */ uchar computerNameValue[9];
    /* 0x5a */ uchar allowTradingValue;
    /* 0x5b */ uchar longCombatValue;
    /* 0x5c */ uchar randomizePositionsValue;
    /* 0x5d */ uchar fullTechTreeValue;
    /* 0x5e */ uchar _pad_5e[2];
    /* 0x60 */ enum ResourceLevel resourceLevelValue;
    /* 0x64 */ enum Age startingAgeValue;
    /* 0x68 */ uchar startingUnitsValue;
    /* 0x69 */ uchar deathMatchValue;
    /* 0x6a */ uchar popLimitValue;
    /* 0x6b */ uchar _pad_6b;
};
#pragma pack(pop)

