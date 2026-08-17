// VA: 005182E0, TRIBE_Player::setupPhoenician, 275 bytes
// Source: tplayer.cpp lines 4248-4287
// FLAGS: default
//
// Attempt log:
// - Prior work tried a typed deathMatch method, a fastcall wrapper, declaration and
//   reassignment orders, separate/grouped constants, and direct stores. The stable
//   VC5 basin kept edx=64h before the non-deathmatch stores and ecx=14h later;
//   original keeps edx=14h for the first three 14h stores, then changes it to 64h.
// - Current source uses the period-plausible typed TRIBE_Game surface and direct
//   field assignments. The typed method fixed the call-site identity; store-order,
//   local/register, and donor-context probes did not change the 25-byte drift.
// - Store-order lab: all 24 permutations of four independent assignment groups
//   preserved size/frame/call set but produced six nonexact codegen groups; best
//   remained 25 positional bytes. This is diagnostic evidence, not living source.
//
// What matches (260/275 bytes):
// - All prologue through deathmatch switch path: first 157 bytes EXACT match
// - Non-deathmatch path: instruction patterns match, values correct
// - All comparison chains, return sequences, ret 10h cleanups
// - After offset 0xD3: everything matches to end (64 bytes)
//
// Remaining mismatches (25 bytes in 2 hunks, non-deathmatch only):
// 1. reg alloc: edx loads 100 (0x64) instead of 20 (0x14) initially.
//    Original: edx=20 → 3 stores to [0],[18h],[4C]; then edx=100 → [D4],[170]
//    Mine: edx=100 immediately; ecx=20 → same 3 stores via ecx
// 2. param_2 reload (mov ecx,[esp+8]) scheduled after v20 stores instead of before
//    → cascading 12-byte displacement difference.
// Both are VC5 register allocator / scheduler decisions. Exact same-TU setup donors
// and analogous setup functions show the same constant-hoisting basin.
//
// Note: logCommonHistory is __cdecl (has add esp,8 after call), not __thiscall.
// This was a key insight to get the first 157 bytes matching.
// Main-agent audit restored canonical game/player destructor ownership; the
// validated 25-byte constant-coloring gap is unchanged.
// The unified AIModule/TRIBE_Game/RGE_Player surface used by this tplayer.cpp
// setup cluster was also tested; it leaves the emitted code unchanged.
// The final shared surface includes the proven RGE_Base_Game base for ABI
// consistency with the difficulty-using siblings; this target is unchanged.
// - Moving the common 100 store after the mode branch broadened drift to 69
//   bytes; moving the branch before trailing common stores broadened it to 82.
// - A late `type = param_2` capture emitted the same 25-byte code as the clean
//   source. Moving the 20-valued stores before the 70-valued group reduced the
//   raw drift to 23 but worsened topology and contradicted the PDB store bands;
//   the canonical direct-store order is retained.
// - Fresh session probes: chained 20 stores, zero-offset `*param_1`, separate
//   twenty/hundred locals, `<stdlib.h>` context, a const mode reference, and
//   p[0]-value reuse all emitted the same 25-byte basin (or unchanged code).
// - Chaining all repeated 10/70/20 groups, including reversed operands to retain
//   store order, worsened the early store topology (31/45-byte drift); rolled
//   back. The remaining gap is still the EDX=14 versus EDX=64 constant coloring
//   plus the 12-byte late parameter-reload alignment hunk.
// - Same-TU donor preload probe: an early ordinary twenty local, used for the
//   three Phoenician 20-valued stores without changing their order, emitted the
//   identical 25-byte basin. Restored the direct literal source.
// - New close-out probes: isolated right-to-left grouping of the 70-valued and
//   10-valued stores, explicit natural phase scopes, and a local typed table
//   view all emitted the identical 25-byte basin. Restored the int* donor form.
// - Session sa-f9b73f31-r1 exhausted 9/10 meaningful hypotheses; final clean
//   source validation is required before pausing for the compiler-basin blocker.
// - TU-group closeout: the common civilization-table and TRIBE_Game declaration
//   context remains canonical; a fresh baseline emitted the same 25-byte basin.
//   The remaining EDX=14 versus EDX=64 coloring and late parameter reload have
//   no evidence-backed source lead in this session.
// - Revisit probes: moving the trailing 40/30/100 stores before the 20-valued
//   group, using a function-scope map_type copy, and flattening the local
//   player/game declarations all emitted the same 25-byte basin. Restored the
//   canonical typed source.
// - Specialist closeout: the period reconstruction in
//   C:\Projects\my_decomps\aoe1\src\game\src\TRIBE_Player.cpp was tested with
//   its non-deathmatch-first and explicit-return shape (283 bytes, 237-byte
//   drift). Reversing the outer condition without returns duplicated that basin.
//   Early mode captures, both at block entry and before the 20-valued stores,
//   duplicated the clean 25-byte basin. Restored this direct-store source.
// - Revisit sa-a32e6d95-r1 tested narrow period-style game/player declarations,
//   removal of the unused stddef include, and explicit deathmatch-arm returns.
//   Each emitted the same 275-byte basin and 25-byte positional drift. The
//   current VC5 output still loads 64h before the non-deathmatch stores and
//   reloads param_2 after the 14h stores; the oracle loads 14h first and
//   reloads param_2 before those stores.
// - Fresh local donor search found setupBabylonian as the closest exact
//   same-TU constant-store example. Its natural source emits the oracle's
//   14h register and early param_2 reload, but its store groups differ. This
//   is codegen evidence, not proof that Phoenician needs a different source.
// - Revisit sa-6e3c0b54-r1 tested all-constant aliases, full and partial comma
//   groups, PDB-line grouping, a const map type, a Phoenician enum constant,
//   explicit ordinary returns, and the three 20 stores as a producer group.
//   Every build duplicated the 275-byte / 25-byte-drift basin. These tests did
//   not identify a natural missing assignment or field-ownership change.
//   No policy-valid source lead remains. Keep this clean typed reconstruction.
// - TU reconstruction closeout (sa-48973eab-r1): the pinned default flags remain
//   /nologo /c /O2 /Oy. No-header, stddef, stdlib, string, memory, stdio, and
//   windows contexts, their period combinations, repository game_types and
//   game_globals headers, and both stddef include placements all rebuilt at
//   275 bytes with the same 25-byte drift. Full setup declaration order, the
//   complete class surfaces, the derived playerAI field type, early global
//   declaration, and full Babylonian/Phoenician/Sumerian donor ordering also
//   duplicated that basin. These are TU facts supported by local donors and
//   probes; none selects the oracle EDX=14 preload or early param_2 reload.
//   Baseline restored and validated. Preserve this source.
// - Object audit confirms the PDB range, named parameters, FPO/COFF shape,
//   four relocations, compiler directives, and exact-donor fingerprint. PDB
//   has no hidden local. deathMatch is a required direct nonvirtual call.
//   No object evidence supports aliases or store reordering.
// - Canonical ownership pass: AIModule, MainDecisionAIModule, and
//   TribeMainDecisionAIModule now form the typed AI chain; RGE_Player owns its
//   base fields and TRIBE_Player owns playerAI at +0x238. RGE_Base_Game owns
//   rge_base_game, and the derived TRIBE_Game cast keeps deathMatch direct and
//   nonvirtual. This source rebuilt in the same 275-byte, 25-byte basin.
// - One bounded PDB-supported source-group axis put the three existing 20-valued
//   stores on one source line versus separate statements. Both variants were
//   275 bytes with 25 positional differences and kept the oracle's calls and
//   store behavior. Retain separate direct statements; no preload change was
//   found and no schedule-steering form is kept.
// - Field cleanup replaced explicit alignment bytes and a byte-array tile view
//   with named RGE_Tile_List members and natural alignment. The rebuilt object
//   stayed byte-identical, so the named canonical form is retained.

typedef unsigned char uchar;

// These are the period class relationships used by tplayer.cpp.  Only the
// methods used here are declared, but each method keeps its real owner.
class AIModule {
public:
    virtual ~AIModule();
    void logCommonHistory(char* message, ...);
};

class MainDecisionAIModule : public AIModule {
public:
    virtual ~MainDecisionAIModule();
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    virtual ~TribeMainDecisionAIModule();
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    int difficulty();
};

class TRIBE_Game : public RGE_Base_Game {
public:
    virtual ~TRIBE_Game();
    uchar deathMatch();
};

class RGE_Object_List;
class RGE_Static_Object;
class RGE_Victory_Conditions;
class RGE_Visible_Map;
class RGE_Doppleganger_Creator;
class RGE_Color_Table;
class Visible_Resource_Manager;
class RGE_Master_Static_Object;
class RGE_Object_Node;
class RGE_Sprite;
class RGE_Sound;
class RGE_Game_World;

class RGE_Tile_List {
public:
    int list_size;
    int num_active;
    int new_count;
    int collapse_list;
    void* list;
};

class RGE_Player {
public:
    virtual ~RGE_Player();

    int computerPlayerValue;
    int pathingAttemptCapValue;
    int pathingDelayCapValue;
    int currentUpdatePathingAttemptsValue;
    long checksum;
    long position_checksum;
    long action_checksum;
    uchar checksum_created_this_update;
    short master_object_num;
    RGE_Master_Static_Object** master_objects;
    RGE_Object_List* objects;
    RGE_Object_List* sleeping_objects;
    RGE_Object_List* doppleganger_objects;
    RGE_Victory_Conditions* victory_conditions;
    RGE_Visible_Map* visible;
    RGE_Game_World* world;
    RGE_Doppleganger_Creator* doppleganger_creator;
    char* name;
    uchar type;
    short id;
    short attribute_num;
    float* attributes;
    uchar culture;
    RGE_Tile_List tile_list;
    RGE_Tile_List diam_tile_list;
    uchar game_status;
    uchar resigned;
    uchar* relations;
    int unitDiplomacy[9];
    int mutualAlly[9];
    unsigned long mutualExploredMask;
    unsigned long mutualVisibleMask;
    unsigned long nonMutualVisibleMask;
    unsigned long RemoveVisibleBits[9];
    int allied_LOS_Enable;
    uchar allied_victory;
    uchar master_player_id;
    RGE_Color_Table* color_table;
    long tribe_effect;
    Visible_Resource_Manager* VR_List;
    float view_x;
    float view_y;
    short map_x;
    short map_y;
    short selected_start_col;
    short selected_start_row;
    short selected_end_col;
    short selected_end_row;
    short replacement_terrain;
    short replacement_overlay;
    short replacement_overlay_shape;
    RGE_Static_Object* selected_obj;
    RGE_Static_Object* sel_list[25];
    unsigned long sel_object_properties;
    short sel_count;
    uchar groups_used[127];
};

class TRIBE_Player_Tech;
class TRIBE_History_Info;

class TRIBE_Player : public RGE_Player {
public:
    virtual ~TRIBE_Player();

    TRIBE_Player_Tech* tech_tree;
    long fog_update;
    long update_count;
    long update_history_count;
    long updateCountNeedHelp;
    float update_time;
    TribeMainDecisionAIModule* playerAI;
    char aiStatusInformationValue[256];
    char aiStatusInformationValue2[256];
    char aiStatusInformationValue3[256];
    char aiStatusInformationValue4[256];
    char aiStatusInformationValue5[256];
    char aiStatusInformationValue6[256];
    TRIBE_History_Info* history;
    float ruin_held_time;
    float artifact_held_time;

    void setupPhoenician(int* param_1, int param_2, int param_3, int param_4);
};

extern RGE_Base_Game* rge_base_game;

void TRIBE_Player::setupPhoenician(int* param_1, int param_2, int param_3, int param_4)
{
    this->playerAI->logCommonHistory("Setting up as Phoenicians.");

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch() == 1) {
        if (param_2 == 0 || param_2 == 1) {
            param_1[0x44] = 100;
        } else if (param_2 == 2 || param_2 == 6) {
            param_1[0x1E] = 60;
            param_1[0x44] = 40;
        } else if (param_2 == 5 || param_2 == 8) {
            param_1[0x1E] = 80;
            param_1[0x44] = 20;
        } else {
            param_1[0x1E] = 100;
        }
    } else {
        param_1[3] = 10;
        param_1[4] = 10;
        param_1[9] = 10;
        param_1[10] = 10;
        param_1[11] = 10;
        param_1[0x11] = 70;
        param_1[0x12] = 70;
        param_1[0] = 20;
        param_1[6] = 20;
        param_1[0x13] = 20;
        param_1[1] = 40;
        param_1[0x14] = 30;
        param_1[0x35] = 100;

        if (param_2 == 0 || param_2 == 1) {
            param_1[0x5C] = 200;
        } else if (param_2 == 2 || param_2 == 6 || param_2 == 8 || param_2 == 5) {
            param_1[0x5C] = 100;
        }
    }
}
