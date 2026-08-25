// 0041ED70 RGE_Base_Game::setup_registry
// Source: basegame.cpp lines 2451-2459
// protected: virtual int __thiscall RGE_Base_Game::setup_registry(void)
//
// Attempt log:
// Probe 1: natural new-expression shape with /GX per-function rsp.
//   Exact match (0.0000%). /GX confirmed needed for EH prolog.
//   Neighbor setup_chat (0041ED00) also uses /GX â€” consistent with basegame.cpp cluster.

#include <new.h>

// TRegistry size 0x110 (from inventory types dump)


// RGE_Prog_Info uses registry_key at +0x418.


// RGE_Base_Game uses prog_info at +0xC and registry at +0x1AC.


int RGE_Base_Game::setup_registry()
{
    TRegistry* reg = new TRegistry(this->prog_info->registry_key);
    this->registry = reg;
    return reg != 0;
}
