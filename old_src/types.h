#pragma once
#include <windows.h>

//==============================================================================
// Primitive Types (Matching Ghidra/Original Source)
//==============================================================================
typedef unsigned char  uchar;
typedef unsigned short ushort;
typedef unsigned int   uint;
typedef unsigned long  ulong;

//==============================================================================
// Enums (Direct from PDB Dump)
//==============================================================================
enum MapSize {
    Tiny = 0,
    Small = 1,
    Medium = 2,
    Large = 3,
    Huge = 4,
    Humongous = 5
};

enum MapType { 
    Coastal = 0, 
    Inland = 1, 
    Highland = 2, 
    Continental = 3 
};

enum VictoryType { 
    Standard = 0, 
    Conquest = 1, 
    TimeLimit = 2, 
    Score = 3 
};

enum ResourceLevel {
    DefaultResources = 0,
    LowResource = 1,
    MediumResources = 2,
    HighResources = 3,
    VeryHighResources = 4
};

enum Age {
    DefaultAge = 0,
    NomadAge = 1,
    StoneAge = 2,
    ToolAge = 3,
    BronzeAge = 4,
    IronAge = 5
};