// 0041ED70 RGE_Base_Game::setup_registry
// Source: basegame.cpp lines 2451-2459
// protected: virtual int __thiscall RGE_Base_Game::setup_registry(void)
//
// Attempt log:
// Probe 1: natural new-expression shape with /GX per-function rsp.
//   Exact match (0.0000%). /GX confirmed needed for EH prolog.
//   Neighbor setup_chat (0041ED00) also uses /GX — consistent with basegame.cpp cluster.

#include "..\..\include\game_globals.h"
#include <new.h>

// TRegistry size 0x110 (from inventory types dump)
class TRegistry {
public:
    void* ghMachineKey;       // +0x0 (4)
    void* ghUserKey;          // +0x4 (4)
    void* ghMachineKeyRead;   // +0x8 (4)
    unsigned long gdwDisp;    // +0xC (4)
    char Data[255];           // +0x10 (0xFF)
    unsigned char _pad_end;   // 0x010F (1)

    TRegistry(char* key);
};

// RGE_Prog_Info stub — only the fields we need
// Full size 0x1238, registry_key at +0x418 (char[256])
class RGE_Prog_Info {
public:
    char _gap_0x0000[0x418]; // skip to registry_key
    char registry_key[256];   // +0x418
};

// RGE_Base_Game stub — only the fields we need
// Full size 0xA24, prog_info at +0xC, registry at +0x1AC
class RGE_Base_Game {
public:
    void* vtable_ptr;           // +0x0 (4)
    void* player_game_info;     // +0x4 (4)
    void* scenario_info;        // +0x8 (4)
    RGE_Prog_Info* prog_info;   // +0xC (4)
    char _gap_0x0010[0x19C];    // +0x10..0x1AB (0x19C bytes)
    TRegistry* registry;        // +0x1AC (4)

    int setup_registry();
};

int RGE_Base_Game::setup_registry()
{
    TRegistry* reg = new TRegistry(this->prog_info->registry_key);
    this->registry = reg;
    return reg != 0;
}
