// 00510960 TRIBE_Map::delete_cliff(long, long) — MATCHED (0.0000%)
// Source: tmap.cpp lines 819-838
// Size: 228 bytes
// NC: no custom flags (default /O2 /Oy)
//
// Probe 5 (sa233db36e_r1) baseline produced an exact match on the first
// clean reconstruction. Promoted to src/matching.

// Attempt log:
// Probe 1: initial impl — 72.4% positional, full 228 bytes
// Probe 2: fix game_world offset + virtual dispatch — 72.4%
// Probe 3: minimize locals, direct float access — 70.2%
// Probe 4: use (long) cast for ftol — 70.2%, virtual call matches pattern
// Probe 5 (sa233db36e_r1): clean re-reconstruction using exact donor ABI.
//   - get_cliff_info is a 16-byte STRUCT RETURN (TRIBE_Cliff_Info), not a
//     void* out-param helper. Call 1 initializes info directly (hidden ret =
//     &info); call 2 is an assignment that materializes through a temp then
//     copies 4 dwords into info. The old void* shape made the rebuilt read
//     the stack buffer directly (mov ecx,[esp+20h]) instead of through the
//     return pointer (mov ecx,[eax]).
//   - remove_cliff_edge real mangled name is ?remove_cliff_edge@TRIBE_Map@@
//     QAEXJJJ@Z (long,long,long), not (int,int,int).
//   - param_2's home slot is reused as the outer loop counter (mov dword
//     [esp+38h],-1; ...; inc; store back), so mutate param_2 directly.
//   - game_world is reloaded every inner iteration (mov edi,[ebp+8DC0h]
//     inside the loop) -> direct member access / loop-local, not hoisted.
//   - cliff->z loaded first (fld [ebx+3Ch]) then cliff->y (fld [ebx+38h]):
//     add_node(param_2 + (long)y, inner + (long)z) right-to-left evaluation.
//   - Tail is delete cliff (push 1; call [vtable+0] = scalar deleting dtor).
// Grouped TU audit: the canonical RGE_Player surface names the +0x6C list
// diam_tile_list.  Using that owner keeps standalone bytes exact and restores
// the grouped 228-byte match; tile_list in that surface is at +0x58.

#ifndef TMAP_GROUP_CONTEXT
struct TRIBE_Cliff_Info {
    int info[4];
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();   // vtable slot 0 (delete cliff -> call [vtbl])
    char gap_04[0x34];              // +0x04..+0x37
    float y;                        // +0x38
    float z;                        // +0x3C
};

class RGE_Tile_List {
public:
    char gap_00[0x14];
    void add_node(int col, int row);
};

class RGE_Player {
public:
    char gap_00[0x6C];
    RGE_Tile_List diam_tile_list;   // +0x6C
};

class RGE_Game_World {
public:
    char gap_00[0x40];
    RGE_Player** players;           // +0x40
    char gap_44[0x38];
    short curr_player;              // +0x7C
};

class TRIBE_Map {
public:
    char gap_00[0x8DC0];
    RGE_Game_World* game_world;     // +0x8DC0

    RGE_Static_Object* find_cliff(long x, long y);
    TRIBE_Cliff_Info get_cliff_info(RGE_Static_Object* obj);
    void remove_cliff_edge(long x, long y, long dir);
    void delete_cliff(long x, long y);
};
#endif

void TRIBE_Map::delete_cliff(long param_1, long param_2)
{
    RGE_Static_Object* cliff = find_cliff(param_1, param_2);

    TRIBE_Cliff_Info info = get_cliff_info(cliff);

    if (cliff != 0) {
        info = get_cliff_info(cliff);

        for (int i = 0; i < 4; i++) {
            if (info.info[i] != 0)
                remove_cliff_edge(param_1, param_2, i);
        }

        param_2 = -1;
        do {
            int inner = -1;
            do {
                RGE_Game_World* world = this->game_world;
                world->players[world->curr_player]->diam_tile_list.add_node(
                    param_2 + (long)cliff->y, inner + (long)cliff->z);
                inner++;
            } while (inner < 2);
            param_2++;
        } while (param_2 < 2);

        delete cliff;
    }
}
