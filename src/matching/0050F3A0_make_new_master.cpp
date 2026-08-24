// 0050F3A0 TRIBE_Master_Tree_Object::make_new_master
// Source: tm_tre_o.cpp lines 59-61
// Size: 98 bytes, 0.0000% MATCH
// Flags: /GX (EH prologue for the factory helper)
//
// Attempt log:
// - Probe 1-3: class had no padding → sizeof = 0xBC (188), original = 0xB8 (184)
// - Fix: added char gap_00[0xB4] to RGE_Master_Static_Object → sizeof = 0xB8
// - MATCH

#include "..\..\include\tm_tre_o_context.h"

RGE_Master_Static_Object* TRIBE_Master_Tree_Object::make_new_master(void) {
    return new TRIBE_Master_Tree_Object(this, 1);
}
