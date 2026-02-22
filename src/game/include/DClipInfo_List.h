#pragma once
#include "common.h"

struct DClipInfo_Node;

struct DClipInfo_List {
    DClipInfo_Node** Zone_Ptrs;
    int* Zone_Size_Ptrs;
    int Used_Zones;
    int Max_Zones;
    DClipInfo_Node* Free_Head;
    int Free_Pool_Zone;
    int Free_Pool_Index;
    int Total_Blocks;
    int Free_Blocks;
    int Default_Grow_Size;
    int Element_Size;
    int Alloc_Count;
    int Dealloc_Count;
    int NewZone_Count;
    int Reset_Count;
    int SD_XMin;
    int SD_XMax;
    int SD_YMin;
    int SD_YMax;
    int Max_Draw_Levels;
    int Accept_Min_Level;
    int Accept_Max_Level;
    DClipInfo_Node** Draw_Clip_Nodes;
    DClipInfo_Node** Draw_Level_Head;
    DClipInfo_Node** Draw_Level_Tail;
    int YLine_Offset;
    int YLine_Size;
    short* Select_Box;
};
static_assert(sizeof(DClipInfo_List) == 0x70, "Size mismatch");
