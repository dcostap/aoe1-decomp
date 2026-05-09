// RGE_Game_World::map_init
// VA: 00541C20
// World.cpp:831-833
// FLAGS: /GX
//
// BLOCKER: same /GX new-expression common-tail scheduling family as
// 005414A0/00541BC0/0052E5F0. Natural direct new emits exact EH prologue,
// allocation size, ctor args/order, and constructor call family, but sinks the
// member store into the non-null path and sends the null path to a cleanup tail
// after the compared range. Volatile-read source preserves the original short
// null branch and common join, matching the first 81 bytes, but spills EAX
// through [esp+18h] and reloads before `mov [esi+28h], eax` instead of the
// original direct store.
//
// Attempt log:
// v1: prior new RGE_Map(...) — correct sizeof(0x8DD0), exact EH frame/allocation/ctor family, but store sinks into non-null path.
// v2: volatile read of local: first 81B exact/common join retained, but spills EAX through [esp+18h].
// v3: explicit if/else assignment: adds unwanted post-join test/jne.
// v4: volatile member with direct assignment: no change from direct sunk-store basin.
// v5: volatile local pointer: no change from direct sunk-store basin.
// v6: explicit operator new + ctor wrapper: no EH new-expression frame, 64-byte body.
// v7: variant_lab over direct/local/ternary/ifelse/volread/slot shapes, preloaded sounds vs direct member, member pointer/void/volatile surfaces, and vc5-risky flags: no exact. Best default-compatible family remains /GX volread (first mismatch 81, edit 16); /GX /Oa volread has slightly smaller edit diff 14 but still spills EAX.

class RGE_Game_World {
public:
    char gap_00[0x28];
    void* map;           // +0x28
    char gap_2C[4];      // +0x2C padding
    void* sounds;        // +0x30

    void map_init(int param_1, void* param_2);
};

class RGE_Map {
public:
    char gap[0x8DD0];
    RGE_Map(int param_1, void* sounds, int param_3);
};

void RGE_Game_World::map_init(int param_1, void* param_2) {
    RGE_Map* new_map = new RGE_Map(param_1, this->sounds, 1);
    this->map = *(RGE_Map* volatile*)&new_map;
}
