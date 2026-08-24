// 004D1680 TRIBE_Action_Repair::TRIBE_Action_Repair
// Source: tact_rep.cpp lines 41-46
// public: __thiscall TRIBE_Action_Repair::TRIBE_Action_Repair(int,RGE_Action_Object*,int)
//
// Attempt log:
// Probe 1: natural ctor with base init + conditional setup, default flags
//   -> 48 vs 107: missing EH prolog, vtable init, and field init
// Probe 2: Added /GX rsp, made setup virtual for vtable, added action_type field init

#include "..\..\include\game_globals.h"

#ifndef TACT_REP_CONTEXT_H
class RGE_Action_Object;

// RGE_Action — base class with virtual dtor so vtable is generated
class RGE_Action {
public:
    virtual ~RGE_Action();
    short action_type; // +0x4 (2)

    RGE_Action(int param_1, RGE_Action_Object* param_2, int param_3);
};

// TRIBE_Action_Repair — inherits from RGE_Action, size 0x44
class TRIBE_Action_Repair : public RGE_Action {
public:
    void setup(int param_1, RGE_Action_Object* param_2);

    TRIBE_Action_Repair(int param_1, RGE_Action_Object* param_2, int param_3);
};
#endif

TRIBE_Action_Repair::TRIBE_Action_Repair(int param_1, RGE_Action_Object* param_2, int param_3)
    : RGE_Action(param_1, param_2, 0)
{
    this->action_type = 0x6A;
    if (param_3 != 0) {
        this->setup(param_1, param_2);
    }
}
