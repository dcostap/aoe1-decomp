#pragma once
#include "common.h"

struct SP_Victory_Info {
    int ObjType;
    int AllFlag;
    int PlayerID;
    int DestObjID;
    float x1;
    float y1;
    float x2;
    float y2;
    int VictoryType;
    int Amount;
    int AttribType;
    int obj_ID;
    int dest_obj_ID;
    RGE_Static_Object* obj;
    RGE_Static_Object* dest_obj;
};
static_assert(sizeof(SP_Victory_Info) == 0x3C, "Size mismatch");
