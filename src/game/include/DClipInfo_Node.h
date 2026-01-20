#pragma once
#include "common.h"

struct DClipInfo_Node {
    DClipInfo_Node* Next;
    DClipInfo_Node* NextOnLevel;
    int Object_ID;
    Shape_Info* Shape;
    int Draw_Level;
    int Draw_X;
    int Draw_Y;
    int Draw_Flag;
    uchar* Shape_Base;
    uchar* Color_Table;
    int Xform_Mask;
    int Node_Type;
    short x1;
    short y1;
    short x2;
    short y2;
    short x3;
    short y3;
    short x4;
    short y4;
};
static_assert(sizeof(DClipInfo_Node) == 0x40, "Size mismatch");
