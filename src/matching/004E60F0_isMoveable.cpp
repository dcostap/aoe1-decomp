// 004E60F0 TribeMainDecisionAIModule::isMoveable
// Source: taimdmd.cpp lines 904-924
// public: int __thiscall TribeMainDecisionAIModule::isMoveable(int)
//
// Attempt log:
// Probe 1: natural if-chain on object_group, default flags
//   -> Wrong field offsets: missing padding in RGE_Static_Object and RGE_Master_Static_Object stubs
// Probe 2: added correct padding for skipped fields before master_obj and object_group

#include "..\..\include\game_globals.h"

// Minimal stubs — only fields accessed, with correct padding for preceding fields

class RGE_Master_Static_Object {
public:
    char _gap_00[0x14];  // skip vtable(4)+master_type(1)+pad(3)+name(4)+string_id(2)+string_id2(2)+id(2)+copy_id(2) = 0x14
    short object_group;   // +0x14 (2)
};

class RGE_Static_Object {
public:
    char _gap_00[8];      // skip vtable(4)+id(4) = 8
    RGE_Master_Static_Object* master_obj; // +0x08 (4)
};

class MainDecisionAIModule {
public:
    RGE_Static_Object* object(int id);
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    int isMoveable(int id);
};

int TribeMainDecisionAIModule::isMoveable(int id)
{
    RGE_Static_Object* obj = this->object(id);
    if (obj == 0)
        return 0;

    short group = obj->master_obj->object_group;
    if (group == 3 || group == 0x1B || group == 0x1E || group == 0x1F ||
        group == 5 || group == 0x21 || group == 7 || group == 8 ||
        group == 0x20 || group == 0x10 || group == 0x0E || group == 0x0F)
        return 0;

    return 1;
}
