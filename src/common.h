#pragma once

typedef unsigned char uchar;
typedef unsigned long ulong;
typedef unsigned short ushort;

struct ICINFO {
    ulong dwSize;
    ulong fccType;
    ulong fccHandler;
    ulong dwFlags;
    ulong dwVersion;
    ulong dwVersionICM;
    ushort szName[16];
    ushort szDescription[128];
    ushort szDriver[128];
};

enum ResourceLevel {
    DefaultResources = 0,
    LowResource = 1,
    MediumResources = 2,
    HighResources = 3,
    VeryHighResources = 4,
};

enum Age {
    DefaultAge = 0,
    NomadAge = 1,
    StoneAge = 2,
    ToolAge = 3,
    BronzeAge = 4,
    IronAge = 5,
};

enum MapSize {
    Tiny = 0,
    Small = 1,
    Medium = 2,
    Large = 3,
    Huge = 4,
    Humongous = 5,
};
enum MapType {
    AllWater = 0,
    MostlyWater = 1,
    WaterAndLand = 2,
    MostlyLand = 3,
    AllLand = 4,
    Continental = 5,
    Lake = 6,
    Hilly = 7,
    Isthmas = 8,
};

enum VictoryType {
    VictoryDefault = 0,
    VictoryConquest = 1,
    VictoryExplore = 2,
    VictoryRuins = 3,
    VictoryArtifacts = 4,
    VictoryDiscoveries = 5,
    VictoryGold = 6,
    VictoryTime = 7,
    VictoryScore = 8,
    VictoryStandard = 9,
};