// PDB source module: C:\msdev\work\age1_x1\tworld.cpp.
// Definitions follow the original PDB source-line and address order.

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/tworld.h"
#include "../include/world_info.h"
#include "../include/player.h"
#include "../include/tplayer.h"
#include "../include/tech.h"
#include "../include/tmap.h"
#include "../include/tmplayer.h"
#include "../include/teffects.h"
#include "../include/tscenaro.h"
#include "../include/t_histry.h"
#include "../include/victory.h"
#include "../include/tribegam.h"
#include "../include/com_hand.h"
#include "../include/mst_play.h"
#include "../include/map.h"
#include "../include/obj_list.h"
#include "../include/m_s_obj.h"
#include "../include/stat_obj.h"
#include "../include/rge_fio.h"
#include "../include/main.h"
#include "../include/basegame.h"
#include "../include/scenario.h"
#include "../include/aipbook.h"
#include "../include/taipbook.h"
#include "../include/rge_base_game_global.h"
#include "../include/tcommand.h"
#include "../include/effects.h"
#include "../include/visible.h"
#include "../include/panel.h"
#include "../include/rmm_obj.h"

extern TCommunications_Handler* comm;
extern float save_game_version;
extern float DAT_00577578;
extern float DAT_00577580;
extern unsigned char die_die_die;
extern "C" int useComputerPlayers;
extern "C" int __cdecl debug_rand(char*, int);

// VA: 0052DF60 TRIBE_World ctor
// tworld.cpp

char data_aoe_ply[] = "data\\aoe.ply";

TRIBE_World::TRIBE_World() : controllingComputerPlayer(-1) {
    tech = 0;
    victory_type = 0;
    artifact_count = 0;
    ruin_count = 0;
    sent_zone_score = 0;
    countdown_victory = 0;
    countdown_clock = 0;
    score_displayed = 0;

    TribeAIPlayBook* pb = new TribeAIPlayBook;
    playbook = pb;
    if (pb) {
        pb->loadPlays(data_aoe_ply);
    }
}

TRIBE_World::~TRIBE_World() {
    if (this->tech != 0) {
        delete this->tech;
        this->tech = 0;
    }
}

// VA: 0052E0B0 TRIBE_World::logStatus (358 B)
// PDB source: tworld.cpp
// Packet-grounded status logger: timestamp, player count, scenario name, and
// translated map/victory settings.
// Attempt log:
// - Reconstructed the proven clock/tempString stack window as `long clock`
//   followed by `char tempString[256]`; typed TRIBE_Game helpers plus the
//   inherited vslot +0x20 get_string restored all 16 ordered calls.
// - Removed the decompiler-only `scenario != 0` guard.  The oracle reads
//   scenario->scenario_name at +0x1010 directly, then tests that name; the
//   natural typed source is an exact 358-byte match.


extern "C" int __cdecl fprintf(FILE* stream, const char* format, ...);
extern "C" long __cdecl time(long* value);
extern "C" void* __cdecl localtime(long* value);
extern "C" char* __cdecl asctime(void* value);
void TRIBE_World::logStatus(FILE* stream, int verbose)
{
    long clock;
    char tempString[256];

    if (stream != 0 && verbose == 1) {
        fprintf(stream, "\n\n\n****************************************\n");

        time(&clock);
        fprintf(stream, "AI Log file for Game Started %s", asctime(localtime(&clock)));
        fprintf(stream, "Number Players:          %d\n", (int)this->player_num - 1);

        if (this->scenario->scenario_name != 0 &&
            strlen(this->scenario->scenario_name) != 0) {
            fprintf(stream, "Scenario:                %s\n", this->scenario->scenario_name);
            return;
        }

        ((TRIBE_Game*)rge_base_game)->get_string(
            ((TRIBE_Game*)rge_base_game)->mapSize() + 0x2973,
            tempString, 0x100);
        fprintf(stream, "Map Size:                %s\n", tempString);

        ((TRIBE_Game*)rge_base_game)->get_string(
            ((TRIBE_Game*)rge_base_game)->mapType() + 0x296A,
            tempString, 0x100);
        fprintf(stream, "Map Type:                %s\n", tempString);

        ((TRIBE_Game*)rge_base_game)->get_string(
            ((TRIBE_Game*)rge_base_game)->victoryType() + 0x28A6,
            tempString, 0x100);
        fprintf(stream, "Victory Condition:       %s\n", tempString);
    }
}

// VA: 0052E220 TRIBE_World::data_load_players_type(short, short, FILE*)
// PDB source: tworld.cpp lines 187-197 (141 B, 44 asm)
// FLAGS: default
//
// Attempt log (2026-05-19):
// try 5: Now have movsx/dec/je! Load before [fs:0] scheduling + register assignment left.
// try 6: Cast to force ecx->eax register flow
// ACCEPTED_DRIFT 2026-05-19: approved localized behavior-equivalent EH/register scheduling drift.
// Rebuilt loads p2 before installing FS while original loads it immediately after; no throwing
// operation occurs between. Remaining differences are temp-register choices for compare/call
// setup and equivalent base/index register swap in the final store. Calls, predicates, EH
// cleanup, stack cleanup, allocation size, constructor call, and memory effects are identical.

void TRIBE_World::data_load_players_type(short p1, short p2, FILE* f)
{
    if ((int)(short)p2 - 1 != 0) {
        RGE_Game_World::data_load_players_type(p1, p2, f);
        return;
    }

    this->master_players[p1] = new TRIBE_Master_Player(f);
}

// 0052E2B0 TRIBE_World::data_load_map
// PDB source: tworld.cpp lines 201-206

void TRIBE_World::data_load_map(char* p1, char* p2, char* p3, char* p4, short p5, short p6, short p7, RGE_Sound** p8, char* p9)
{
    TRIBE_Map* m = new TRIBE_Map(p1, p2, p3, p4, p5, p6, p7, p8);
    this->map = m;
    m->load_terrain_obj_types(p9);
}

// VA: 0052E350 TRIBE_World::data_load_world
// tworld.cpp:210-227
// FLAGS: /GX


unsigned char TRIBE_World::data_load_world(FILE* f)
{
    char tech_file[23];

    RGE_Game_World::data_load_world(f);
    fscanf(f, "%s ", tech_file);
    this->tech = new TRIBE_Tech(tech_file);
    this->victory_type = 0;
    this->artifact_count = 0;
    this->ruin_count = 0;
    this->countdown_victory = 0;
    this->countdown_clock = 0.0f;
    this->score_displayed = 0;
    return 1;
}

// VA: 0052E400 TRIBE_World::init_player_type
// PDB source: tworld.cpp
// Attempt log:
// natural /GX new-expression for TRIBE_Master_Player, base fallback, virtual setup slot +4: correct EH/new/ctor/body skeleton.
// The canonical master-player and World fields preserve the proven offsets.
// tried allocated class size 0x2C via implicit vptr+0x28 payload; operator new size correct.
// tried condition spellings: type!=1, (type&0xff)!=1, int temp, unsigned temp with &=0xff/--temp. Best keeps 180B but hoists type load before FS registration and uses a different top compare/push family.
// tried /Ob0 (no help) and /O1 (too short); kept /GX because original has EH frame.
// left in scratch: body after branch is largely understood, but remaining mismatch is broad early EH/parameter scheduling and fallback push order, not accepted drift.
// Retry 2026-05-26 Boss pass: 15 probes on VA 0052E400 only. Revalidated baseline /GX: 180B, 73.8889% positional / 38.8889% edit, first mismatch +14 from type load before FS registration. Tried direct `type != 1`, `type == 1` else, unsigned-char temp, int temp with decrement, mutating `type`, saving `player` before/after branch, direct `p->init`, index local, manual placement-new (VC5 rejected), expression forms `((t&0xff)-1)==0` / `!=0`, no-temp casts, and flags /Ob0 /G5 /Oa /Oy- /O1 with /GX. Kept the int-temp/decrement variant because it improves to 67.7778% positional / 25.0000% edit and first mismatch +35, but it still has an extra `and eax,0xff` and shifts the allocation branch. GIVEUP: not accepted_drift quality; remaining drift is broad EH/type-test/fallback layout and shifted new/virtual-call path, not localized equivalent drift.
// Luna52E400 session: baseline rebuilt 185B, 147 differing bytes, first mismatch +35 from a duplicate `and eax,0xff`; all four calls and body CFG aligned.
// Tested direct type guards, unsigned/int/byte temporary variants, promoted `type - 1`, and explicit mask forms; the closest unchanged basin is the int temporary with one explicit byte cast.
// Tested the canonical RGE_Master_Player/TRIBE_Master_Player inheritance and finish_init(void*) surface; emitted metrics stayed in the same 185B basin, so it is retained for source plausibility.
// Tested condition arm inversion and found it changes branch layout/call ordering; restored the clean source after each nonproductive probe.
// Session exhausted at 10 meaningful hypotheses; remaining gap is localized to VC5 type-test/EH scheduling, not behavior or call/layout uncertainty.
// Main-agent source audit: removed the redundant `t = (unsigned char)t` compiler-
// steering assignment from the retained candidate. The parameter already has the
// proven unsigned-byte ABI, so the ordinary promoted temporary is the defensible
// source even though it returns to the broader early-load codegen basin. Validation:
// 181/180 bytes, 150 strict differing bytes, 98.31% shape, 4/4 calls aligned;
// first mismatch +0x0E from loading `type` before FS registration.
// Luna52E400b sequential pass: full RGE world/Player virtual surfaces and inherited
// field ownership, switch CFG, self alias, and volatile dword parameter-view probes
// were nonproductive; the full context/switch/alias forms were codegen-neutral and
// the volatile view regressed size/coverage. A guarded variant lab (8 source forms,
// plus VC5-small flag classification) found no exact or invariant-eligible variant;
// restored the prior clean canonical source. Remaining lead is VC5 EH/type-test
// scheduling at +0x0E, with body/calls/layout aligned and no behavioral blocker.
// orch-luna-52e400-w1: direct switch(type) with case 1 and a shared success return
// reproduces the original dec/je dispatch and exact 180-byte output; switching a
// decremented temporary was codegen-equivalent but hoisted the type load.

unsigned char TRIBE_World::init_player_type(int player, short index, unsigned char type)
{
    switch (type) {
    case 1: {
        TRIBE_Master_Player* p = new TRIBE_Master_Player(player);
        this->master_players[index] = p;
        this->master_players[index]->finish_init(player, this->sprites, this->sounds);
        break;
    }
    default:
        return RGE_Game_World::init_player_type(player, index, type);
    }

    return 1;
}

// VA: 0052E4C0 TRIBE_World::map_init(int, TSound_Driver*)
// PDB source: tworld.cpp lines 249-252 (97 bytes, 30 asm lines)
// FLAGS: /GX
//
// __thiscall: this in ecx, 2 stack params. ret 8 cleanup.
// SEH-framed, allocates TRIBE_Map (0xB5F8 bytes), constructs if non-null,
// stores at this->map (+0x28).
//
// === ACCEPTED_DRIFT ===
// 2026-05-12: Switched from direct-new (21.65% pos, sunk-store) to common-store
// self-assign form (16.49% pos/11.34% edit) matching the accepted_drift pattern
// in 00541C90/00541BC0/00541B60. Same VC5 /GX new-expression + EH lowering
// artifact: first N bytes exact (prologue, new, null test, ctor, jmp, xor), then
// dead zero-displacement `test eax,eax; jne +0` at the common-store join. Accepted
// as behavior-neutral; it only shifts/truncates epilogue into padding.
//
// Attempt log (prior passes):
// - GraniteCub: 19 focused variants — local/direct, explicit if/goto/common-store,
//   two-stage result, member/parameter/this locals, assignment-in-if/comma/volatile,
//   no-virtual map surface, void*/int map member, ctor flag/arg changes, /O1+/GX.
//   Direct new keeps exact EH/new/ctor but sinks store into success path.
//   Common-store forms reach closer basin but insert redundant post-merge test.
// - LemonLily: 12 more — plain/direct/volatile, explicit null/self-assign, goto,
//   if/else, ternary, slot pointer, member local, dummy param_2, flag local.
//   Flag probes: /Oa, /Ow, /Ot, /Ox, /O1 with /GX. No exact.
//   2026-05-10: 15 more — local/null common-store, unqualified store, goto, empty
//   else, slot-after-new, field/param/flag locals, if-store-arms, ternary,
//   plain/void/int map member, placement-new, flags /Ob0 /Og /Oa /Ot /G5 /Ox /O1
//   /Oy-. No exact.
// 2026-05-12: Verified same artifact as accepted_drift siblings. Common-store
// form is the best basin (16.49%/11.34%). Recommended accepted_drift per Boss ruling.
//
void TRIBE_World::map_init(int param_1, TSound_Driver* param_2) {
    TRIBE_Map* p = new TRIBE_Map(param_1, this->sounds, 1);
    if (p == 0) {
        p = 0;
    }
    this->map = p;
}

// 0052E530 TRIBE_World::command_init
// EH-framed allocate and construct TRIBE_Command, store at +0x58.
// FLAGS: config/flags/0052E530_command_init.rsp uses /GX for original EH frame.
//
// === ACCEPTED_DRIFT CANDIDATE ===
// Remaining diff: 4 bytes of dead no-op `test eax,eax; jne +0` before common store.
// Behavior: Identical. The test+jnz is a VC5 phi-merge artifact that never branches.
// Shift: Epilogue moves 4 bytes into post-function padding; all regs/memory exact.
// Review: Low risk, no behavior change. Same VC5 artifact as just-approved 0052E650.
// Move to accepted_drift/ if Boss approves.
//
// Attempt log — 20+ focused variants and confirmed by variant lab (5 variants, G0000):
// All approaches that force a common store produce identical codegen:
// `test eax,eax; jne +0` persists as a VC5 phi-merge artifact.
//
// Direct `this->commands = new TRIBE_Command(this, handler)` gives sunk-store (21 pos diff).
// If-else separate stores avoid the artifact but have 2 stores (14 pos diff, worse edit).
// Variant lab confirmed G0000 (if_assign) is the best basin (16 pos / 11 edit).
//
// Best source below. If accepted, promote to src/accepted_drift/.

void TRIBE_World::command_init(int unused, TCommunications_Handler* handler) {
    TRIBE_Command* cmd;
    cmd = new TRIBE_Command(this, handler);
    if (cmd == 0) {
        cmd = 0;
    }
    this->commands = cmd;
}

// 0052E590 TRIBE_World::scenario_init(int, RGE_Game_World*)
// EH-framed allocate and construct T_Scenario (two ctor args), store at +0x5C.
// FLAGS: config/flags/0052E590_scenario_init.rsp uses /GX for original EH frame.
//
// === ACCEPTED_DRIFT CANDIDATE ===
// Remaining diff: 4 bytes of dead no-op `test eax,eax; jne +0` before common store.
// Behavior: Identical. The test+jnz is a VC5 phi-merge artifact that never branches.
// Shift: Epilogue moves 4 bytes into post-function padding; all regs/memory exact.
// Review: Low risk, no behavior change. Same VC5 artifact as just-approved 0052E5F0/0052E530/0052E650.
//
// Attempt log — 20+ focused variants confirming same converging basin. All common-store
// approaches produce the identical redundant join-test. Same VC5 phi-merge artifact
// as all sibling new+null+ctor+store functions from tworld.cpp.
//
// Best source below. If accepted, promote to src/accepted_drift/.

void TRIBE_World::scenario_init(int param_1, RGE_Game_World* param_2) {
    T_Scenario* s = new T_Scenario(param_1, param_2);
    if (s == 0) {
        s = 0;
    }
    this->scenario = s;
}

// 0052E5F0 TRIBE_World::scenario_init
// EH-framed allocate and construct T_Scenario, store at +0x5C.
// FLAGS: config/flags/0052E5F0_scenario_init.rsp uses /GX for original EH frame.
//
// === ACCEPTED_DRIFT CANDIDATE ===
// Remaining diff: 4 bytes of dead no-op `test eax,eax; jne +0` before common store.
// Behavior: Identical. The test+jnz is a VC5 phi-merge artifact that never branches.
// Shift: Epilogue moves 4 bytes into post-function padding; all regs/memory exact.
// Review: Low risk, no behavior change. Same VC5 artifact as just-approved 0052E650/0052E530.
//
// Attempt log — 20+ focused variants confirming same converging basin as effects_init
// and command_init. All common-store approaches produce the identical redundant join-test.
// Direct `this->scenario = new T_Scenario(param_1)` gives sunk-store (21 pos diff).
// Variant lab previously confirmed same convergence (G0000, same `test/jne` artifact).
//
// Best source below. If accepted, promote to src/accepted_drift/.

void TRIBE_World::scenario_init(RGE_Game_World* param_1) {
    T_Scenario* s = new T_Scenario(param_1);
    if (s == 0) {
        s = 0;
    }
    this->scenario = s;
}

// 0052E650 TRIBE_World::effects_init
// EH-framed allocate and construct TRIBE_Effects, store at +0x4C.
// FLAGS: config/flags/0052E650_effects_init.rsp uses /GX for the original EH frame.
//
// === ACCEPTED_DRIFT CANDIDATE ===
// Remaining diff: 4 bytes of dead no-op `test eax,eax; jne +0` before common store.
// Behavior: Identical. The test+jnz is a VC5 phi-merge artifact that never branches.
// Shift: Epilogue moves 4 bytes into post-function padding; all regs/memory exact.
// Review: Low risk, no behavior change. Move to accepted_drift/ if Boss approves.
//
// Attempt log — over 20 focused variants probed:
// All approaches that force a common store (if-assign, while-assign, ternary, comma,
// switch, do-while-break, if-inverted, ptr-to-member, volatile local, etc.) produce
// identical codegen: the `test eax,eax; jne +0` artifact persists. The 4 bytes are
// an intrinsic VC5 phi-merge characteristic for this new/null/store pattern.
//
// Direct `this->effects = new TRIBE_Effects(param_1)` gives sunk-store (21 pos diff).
// If-else separate stores avoid the artifact but have 2 stores at different offsets
// (14 pos diff, worse edit diff).
//
// Variant lab confirmed: all 12 successful common-store variants produce group G0000
// with identical 16-positional/11-edit diff, always the same `test eax,eax; jne +0`.
//
// Best source below. If accepted, promote to src/accepted_drift/.

void TRIBE_World::effects_init(int param_1) {
    TRIBE_Effects* e = new TRIBE_Effects(param_1);
    if (e == 0) {
        e = 0;
    }
    this->effects = e;
}

// VA: 0052E6B0 TRIBE_World::world_init
// PDB source: tworld.cpp
// Attempt log:
// try 1: natural member implementation with base world_init and TRIBE_Tech allocation.

void TRIBE_World::world_init(int param_1, TSound_Driver* sound, TCommunications_Handler* comm)
{
    RGE_Game_World::world_init(param_1, sound, comm);

    TRIBE_Tech* new_tech = new TRIBE_Tech(param_1, this);
    this->tech = new_tech;
    this->victory_type = 0;
    this->artifact_count = 0;
    this->ruin_count = 0;
    this->countdown_victory = 0;
    this->countdown_clock = 0;
    this->score_displayed = 0;
}

// VA: 0052E750 TRIBE_World::init(char*, TSound_Driver*, TCommunications_Handler*)
// BINARY NOTE: the direct call target is RGE_Game_World::init with the same
// three-argument surface.  The prior placeholder target_method changed only
// relocation identity.  The canonical base declaration now reports MATCH.

unsigned char TRIBE_World::init(char* file, TSound_Driver* sound,
                        TCommunications_Handler* communications)
{
    return RGE_Game_World::init(file, sound, communications);
}

void TRIBE_World::base_save(int value) {
    RGE_Game_World::base_save(value);
    this->tech->save(value);
}

// VA: 0052E790 TRIBE_World::save (145 B)
// PDB source: tworld.cpp

void TRIBE_World::save(int fd)
{
    RGE_Game_World::save(fd);
    rge_write(fd, &victory_type, 4);
    rge_write(fd, &artifact_count, 4);
    rge_write(fd, &ruin_count, 4);
    rge_write(fd, &countdown_victory, 1);
    rge_write(fd, &countdown_clock, 4);
    rge_write(fd, &score_displayed, 1);
    rge_write(fd, &controllingComputerPlayer, 1);
}

// VA: 0052E830 TRIBE_World::load_player
// PDB source: tworld.cpp lines 328-344
//
// Baseline reconstruction: player slots are the RGE world array at +0x40;
// types 1 and 3 load TRIBE_Player, type 2 loads TRIBE_Gaia, and all other
// types defer to RGE_Game_World.  The final call is TRIBE_Player::load at
// vtable slot 0x74.  The class sizes are the proven 0x848/0x858 allocation
// sizes, rather than decompiler cursor arithmetic.

void TRIBE_World::load_player(int player, unsigned char type, short player_id)
{
    switch (type) {
    case 1:
    case 3:
        this->players[player_id] =
            (RGE_Player*)new TRIBE_Player(player, this, (unsigned char)player_id);
        break;
    case 2:
        this->players[player_id] =
            (RGE_Player*)new TRIBE_Gaia(player, this, (unsigned char)player_id);
        break;
    default:
        RGE_Game_World::load_player(player, type, player_id);
        return;
    }

    ((TRIBE_Player*)this->players[player_id])->load(player);
}

// VA: 0052E920 TRIBE_World::setup_gaia()
// PDB: tworld.cpp lines 348-351 (102 bytes, 33 asm lines)
// FLAGS: config/flags/0052E920_setup_gaia.rsp (/nologo /c /O2 /Oy /GX)
// No inline asm/hacks.
//
// === ACCEPTED_DRIFT ===
// Remaining diff: 4-byte `test eax,eax; jne +0` (85c07500 = phi-merge artifact)
// inserted after xor eax,eax (null path) before the common players[0] = g store.
// This is the EXACT same VC5 phi-merge behavior observed in the previously accepted
// 0052E530/0052E590/0052E5F0/0052E650 accepted_drift functions — the `if (g == 0) g = 0;`
// normalization forces a common store point but VC5 adds a dead test/jne phi shunt.
//
// First 81 bytes match exactly (relocations masked by the tool are not real diffs).
// The 4-byte insert at offset 0x51 shifts the remaining code; the final 4 bytes of
// the 102-byte window are the shifted-out padding (difference in padding bytes only).
// edit diff = 7.84% (all from the 4-byte insert + corresponding tail deletion).
// positional diff = 16.67% (also from 4-byte insert cascade).
//
// No source/flag workaround found. Probes from multiple prior sessions (LemonLily,
// GraniteCub) tried: if/else/ternary/goto/comma/volatile/while/for/switch/null-normalization
// patterns; no /O flag variant eliminates the artifact for this +ctor SEH pattern.
//
// Accepted as same behavior-neutral no-op phi-merge artifact as sibling init helpers.
// Prefix TU pass: migrated to the shared canonical tworld context without changing
// the reviewed drift or the six exact anchors.

void TRIBE_World::setup_gaia() {
    TRIBE_Gaia* g;
    g = new TRIBE_Gaia(this, (RGE_Master_Player*)this->master_players[0], 0, "GAIA", 0);
    if (g == 0) {
        g = 0;
    }
    this->players[0] = g;
}

// VA: 0052E990 TRIBE_World::setup_players (304 B)
// PDB source: tworld.cpp:355-380
// Attempt log:
// baseline: raw shim/free-function reconstruction; it missed the EH frame and
// called the player constructor through a cdecl helper.
// probe 2: natural TRIBE_World member plus typed RGE_Player_Info arrays and the
// real TRIBE_Player constructor surface; /GX is required by the original EH
// registration.  This is the canonical source reconstruction baseline.
// probes 3-6: inverted the type/useComputerPlayers dispatch, routed unknown
// types directly to the loop tail, and used a switch with case 0 before case 4;
// this recovered the original 304-byte CFG and all five ordered calls.
// probes 7-10: equivalent pointer-addition, local-byte, unsigned-byte, and
// pointer-parameter forms did not change the emitted code.  The best natural
// source remains one byte short of exactness: the dispatch load's SIB byte is
// [ebx+esi+248] instead of the original [esi+ebx+248].
// probe 15: a scoped type-table pointer was codegen-neutral.
// probe 16: a focused /GX variant lab over six natural type-table spellings
//   kept size/frame/call-set invariants but produced only the same three SIB
//   groups; no living source steering was retained.
// left in scratch: exact boundary/size/CFG/call set and all other bytes match;
// remaining drift is a single VC5 address-term encoding with no productive
// source axis found in this bounded assignment.
// Main-agent audit confirmed canonical world/player/info ownership and natural
// switch construction; no address-term steering survives in the source.
// sequential pass: direct branch-local slot stores, player-result declaration
// scope/order, short/register loop-index forms, inherited RGE_Player result
// typing, an input-pointer alias, subscript-term order, an equivalent for-loop,
// and a const dispatch local were all codegen-neutral or regressed.  The clean
// natural source remains 304B with one documented dispatch SIB byte differing.
// sequential TU pass: typed ABI and same-TU donor review found no new source
// or layout fact for the lone commutative SIB encoding; keep the natural source.
// probe 40: restored the same-TU world's proven virtual surface and declared
// setup_players at slot 24; this natural context fixes the lone SIB byte.
// Canonical World, player, and info ownership is used by the complete module.

extern "C" int useComputerPlayers;

void TRIBE_World::setup_players(RGE_Player_Info& info)
{
    int index = 1;

    if (this->player_num > 1) {
        do {
            TRIBE_Player* player;

            char type = info.type[index - 1];
            switch (type) {
            case 0:
                player = new TRIBE_Player(this,
                    this->master_players[info.tribe[index - 1]],
                    (unsigned char)index, info.name[index - 1],
                    info.tribe[index - 1], 0, 1, 0, 0, 0);
                break;
            case 4:
                if (useComputerPlayers == 0) {
                    player = new TRIBE_Player(this,
                        this->master_players[info.tribe[index - 1]],
                        (unsigned char)index, info.name[index - 1],
                        info.tribe[index - 1], 0, 1, 0, 0, 0);
                } else {
                    player = new TRIBE_Player(this,
                        this->master_players[info.tribe[index - 1]],
                        (unsigned char)index, info.name[index - 1],
                        info.tribe[index - 1], 1, 1, 0, 0, 0);
                }
                break;
            default:
                goto next_player;
            }

            this->players[index] = player;
        next_player:
            ++index;
        } while (index < this->player_num);
    }
}

// VA: 0052EAC0 TRIBE_World::check_destructables (560 B)
// PDB source: tworld.cpp
// Packet-grounded: inspect nearby master objects and notify/destruct objects
// whose bounding radii overlap the requested map coordinate.
// Attempt log:
// - Recovered typed ownership: players[short] -> master_objects,
//   RGE_Map rows of 0x18-byte RGE_Tile records, inline tile object lists, and
//   RGE_Static_Object/master radius fields.  All six oracle calls are aligned.
// - Short coordinate locals reproduce the word clamps and four __ftol calls.
//   The typed row/tile do-while preserves the natural object-list traversal.
// - A direct row index plus the known 0x18-byte tile stride is closer than a
//   cached row pointer. Raw byte cursors and parameter-home mutation are not
//   retained because policy forbids them.
// - Naming both real object radius fields before coordinate math, then using a
//   combined overlap predicate, reaches 560 B/frame 0x20 and 84.15% shape.
//   It also raises exact-block coverage to 43.43% with all six calls aligned.
// - World/map aliases and alternate radius operand directions were tested and
//   discarded when they worsened or did not change the natural code shape.
// - Canonical class-dump audit: replaced the world/object/list vfXX surfaces
//   with their reviewed names and signatures, retained TRIBE_World inheritance,
//   and used the canonical RGE_Tile/RGE_Object_Node fields.
// - Structural probes moved the row/tile calculation before the horizontal
//   gate and moved the column count into that gate.  This reduced the mismatch
//   from 530 to 306 bytes and reached the original 560-byte body size.
// - Direct master_id use, a typed stride local, a moving row cursor, widened
//   x-index locals, an explicit next pointer, and unqualified members were
//   tested.  The stride and cursor forms regressed.  The other forms were
//   neutral or are retained only when they simplify the source.
// - Current validation: 306 strict bytes differ; rebuilt instructions are
//   183 versus 175 original.  The first mismatch is the implicit-this home
//   at +0008.  All six calls remain aligned and the frame is 0x20.
// BINARY NOTE: Keep the initial players[player_id] and master_objects[master_id]
//   reads before radius, map, or coordinate work. Do not add defensive guards.
// BINARY NOTE: Advance the list node before reading object_master. Publish the
//   delete or destroy action only after the complete overlap predicate.
// Prefix TU pass: use the shared canonical world, map, tile, object-list, and
// object surfaces. The source keeps the observed fault and action order.
// Shared-context check: the 560-byte boundary, 0x20 frame, six aligned calls,
// and 306 strict-byte drift are unchanged.

void TRIBE_World::check_destructables(short player_id, short master_id,
                                      float x, float y, unsigned char flag)
{
    RGE_Master_Static_Object* master =
        players[player_id]->master_objects[master_id];

    if (master != 0) {
        float radius_x = master->radius_x;
        float radius_y = master->radius_y;
        if (radius_x > 0.0f || radius_y > 0.0f) {
            short x_min = (short)(x - 0.5f);
            short y_min = (short)(y - 0.5f);
            short x_max = (short)(x + 0.5f);
            short y_max = (short)(y + 0.5f);
            if (x_min < 0)
                x_min = 0;
            if (x_max >= map->map_width)
                x_max = (short)(map->map_width - 1);
            if (y_min < 0)
                y_min = 0;
            if (y_max >= map->map_height)
                y_max = map->map_height - 1;

            if (y_min <= y_max) {
                int row_index = y_min;
                int row_count = (int)y_max - (int)y_min + 1;
                do {
                    RGE_Tile* tile =
                        map->map_row_offset[row_index] + x_min;
                    if (x_min <= x_max) {
                        int columns = (int)x_max - (int)x_min + 1;
                        do {
                            RGE_Object_Node* node = tile->objects.list;
                            while (node != 0) {
                                RGE_Static_Object* object = node->node;
                                node = node->next;
                                RGE_Master_Static_Object* object_master = object->master_obj;

                                if (object_master->id != master_id &&
                                    object_master->can_be_built_on != 0) {
                                    float object_radius_x = object_master->radius_x;
                                    float object_radius_y = object_master->radius_y;
                                    float dy = object->world_y - y;
                                    float dx = object->world_x - x;
                                    if (dy < 0.0f)
                                        dy = -dy;
                                    if (dx < 0.0f)
                                        dx = -dx;

                                    if (dx < object_radius_x + radius_x &&
                                        dy < object_radius_y + radius_y) {
                                        if (flag != 0) {
                                            if (object != 0)
                                                delete object;
                                        } else {
                                            object->destroy_obj();
                                        }
                                    }
                                }
                            }
                            ++tile;
                            --columns;
                        } while (columns != 0);
                    }
                    ++row_index;
                    --row_count;
                } while (row_count != 0);
            }
        }
    }
}

// VA: 0052ECF0 TRIBE_World::scenario_make_player
// PDB source: tworld.cpp lines 458-470
// Baseline reconstruction: allocate a TRIBE_Player for each scenario slot,
// selecting the computer-player constructor flag only for type 4.
// Attempt log:
// - /GX is required by the original FS:[0] EH registration; it improves the
//   clean default candidate from 152 to 219 bytes and restores the CFG/body
//   basin.  /Ob0 is codegen-neutral and was not retained.
// - Nested type dispatch, switch dispatch, type-4 outer dispatch, and a
//   branch-local type-4 result were tested.  The nested type-0-first form is
//   the best natural source and matches all original calls except one merged
//   TRIBE_Player constructor site.
// - Proven ABI/layout facts retained: TRIBE_World* constructor argument,
//   RGE_Player base size 0x220, TRIBE_Player size 0x848, world arrays at
//   +0x40/+0x48.  Remaining structural gap is VC5 call factoring: rebuilt
//   code is 219 vs 255 bytes with 4/5 calls and 83.13% shape similarity.
// probes 12-14: the type==4 predicate, a branch-local scalar flag, and
//   equivalent local name/flag expressions were codegen-neutral.
// probe 13: six natural local/master/flag spellings grouped into 219B, or
//   265-268B with extra saved-register liveness; none restored the call site.
// probe 14: reference/dereference/index expression variants likewise stayed
//   in the 219B basin; pointer references reached 268B with EBX/EBP saves.
// probe 15: corrected the inherited array ownership to RGE_Player**; emitted
//   bytes were unchanged and the canonical declaration is retained.
// probe 17: explicit placement-new/operator-new diagnostics destroyed the
//   EH/body basin (143-167B), so they are not source candidates.
// probe 18: an explicit goto store join was codegen-neutral.
// probe 19: /Ob0, /O1, and /Od flag variants did not produce the original
//   255B/5-call basin; only /GX retained the 219B candidate.
// probe 21: assigning the player slot directly in each natural branch inhibits
//   VC5's constructor-call tail factoring while its optimized common store
//   still reproduces the original 255B/5-call output exactly.
// Prefix TU pass: moved world, player, and constructor ownership into the
//   shared canonical context. The isolated owner remains exact.

void TRIBE_World::scenario_make_player(short player_id, unsigned char master_id,
    unsigned char type, unsigned char civ, char* player_info)
{
    if (type == 0) {
        this->players[player_id] = new TRIBE_Player(this, this->master_players[master_id],
            (unsigned char)player_id, player_info, master_id, 0, 1, 0, 0, 0);
    } else {
        if (type == 4) {
            this->players[player_id] = new TRIBE_Player(this, this->master_players[master_id],
                (unsigned char)player_id, player_info, master_id, 1, 1, 0, 0, 0);
        } else {
            this->players[player_id] = new TRIBE_Player(this, this->master_players[master_id],
                (unsigned char)player_id, player_info, master_id, 0, 1, 0, 0, 0);
        }
    }
}

// VA: 0052EDF0 TRIBE_World::load_world (314 B)
// PDB source: tworld.cpp
// Packet-grounded: base load_world, version-checked field reads
//   field_108 (victory_type, int, read if ver >= 5.6)
//   field_10C (artifact_count, int), field_110 (ruin_count, int, read if ver >= 5.3)
//   field_114 (countdown_victory, byte), field_118 (countdown_clock, float, read if ver >= 5.4)
//   field_11C (score_displayed, byte, read if ver >= 6.6)
//   field_11D (controllingComputerPlayer, byte, read if ver >= 6.97)
// Attempt log:
// - Replaced the free base shim with the typed RGE_Game_World base call and
//   restored the proven vtable surface; this aligned all eight direct calls.
// - Positive version-read guards recover the original inline-read/cold-zero
//   CFG and 96% instruction-shape similarity.  A direct base-load guard also
//   removes the decompiler-only result local and reaches the 315-byte basin.
// - A scoped zero local was codegen-neutral and was removed.  Remaining drift
//   is the VC5 callee-save basin: rebuilt saves EBX at entry, while the oracle
//   shrink-wraps push/pop EBX around the first version gate (known SIB/shift
//   consequences); no ABI, call-set, or field-layout uncertainty remains.
// sequential pass: donor stdlib context, explicit zero reuse, ground-truth
// world-tail/member ownership, real destructor surfaces, explicit cdecl, and
// an explicit base-result zero comparison were all neutral or regressed.  The
// clean typed source remains the best 315B basin; the remaining structural gap
// is the entry EBX save versus the oracle's late push/pop EBX schedule.
// - The ordinary C++ rge_read declaration preserved the typed call ABI and
//   restored all 18 call relocations. Negative guards improved the prologue but
//   inverted the original branch blocks. The first gate's cold zero label keeps
//   the observed read-before-zero order and late EBX lifetime; this is exact.
// Prefix TU pass: moved world, field, base-load, and read ownership into the
//   shared canonical context. The isolated owner remains exact.

void rge_read(int handle, void* buf, int size);

extern float save_game_version;

unsigned char TRIBE_World::load_world(int handle)
{
    if (!RGE_Game_World::load_world(handle))
        return 0;

    // Version-checked conditional reads
    if (save_game_version >= 5.6f) {
        rge_read(handle, &this->victory_type, 4);
    } else {
        goto victory_zero;
    }
    goto victory_done;
victory_zero:
    this->victory_type = 0;
victory_done:;
    
    if (save_game_version >= 5.3f) {
        rge_read(handle, &this->artifact_count, 4);
        rge_read(handle, &this->ruin_count, 4);
    } else {
        this->artifact_count = 0;
        this->ruin_count = 0;
    }
    
    if (save_game_version >= 5.4f) {
        rge_read(handle, &this->countdown_victory, 1);
        rge_read(handle, &this->countdown_clock, 4);
    } else {
        this->countdown_victory = 0;
        this->countdown_clock = 0.0f;
    }
    
    if (save_game_version >= 6.6f) {
        rge_read(handle, &this->score_displayed, 1);
    } else {
        this->score_displayed = 0;
    }

    if (save_game_version >= 6.97f) {
        rge_read(handle, &this->controllingComputerPlayer, 1);
    } else {
        this->controllingComputerPlayer = 2;
    }

    return 1;
}

// Initial heuristic C++ lift from Ghidra for TRIBE_World::new_game (0052EF30).
// This is intentionally broad and local-stub-heavy: first goal is to get the full
// behavioral surface compiling, then iterate call/layout/codegen toward parity.
// FLAGS: config/flags/0052EF30_new_game.rsp (/GX)
// Natural new/delete for RGE_RMM_Object_Generator plus /GX recovers the original
// EH prologue shape and 0x1308 frame; broad code-shape drift remains.
// Inlining description helpers and direct player/resource access brought the body
// above 5028 bytes so check_function now reports a real diff instead of size-stop.
// Remaining early mismatch: VC5 stores base new_game result from AL to [esp+17]
// and frees EBX for a hoisted strlen mask; original keeps AL in BL, stores BL,
// and later tests BL. Tried register/result-holder forms; they were unchanged.
// Attempt log:
// - Replaced the description-path goto with one negated guard; VC5 emitted the
//   same bytes, so the natural guard remains the source form.
// - Collapsed duplicate base-new-game result locals; VC5 emitted the same bytes.
// - Cached the post-save victory getter after Save_victory_conditions_into_players;
//   this removes one rebuilt call and matches the oracle's single post-save call.
// - Modeled the generator's binary-proven 0x1920 object size with derived padding;
//   this fixed the allocation ABI and improved the structural call surface.
// - Restored explicit branches for the Yes/No description selectors; this fixed
//   the condition count and one exact description block.
// - Retained the binary-proven standalone difficulty getter despite local drift;
//   a register-qualified return local emitted duplicate code.
// - Buffered difficulty formatting matched the virtual call surface but exceeded
//   the original boundary by 164 bytes, so it was rolled back.
// - Restored the victory switch's binary case table: cases 0/9 map to type 0,
//   1 to type 1, 7 to type 2, and 8 to type 3; cases 2-6 set amount fields.
//   This moved the switch hunk one byte closer but VC5 still tail-merged the
//   five source conquest calls into two emitted calls.
// - Tested the period VictoryType enum return surface from the Ghidra source;
//   VC5 emitted identical bytes and the enum surface was rolled back.
// - Tested 20 source, type, control-flow, context, and flag hypotheses. /Ob1 and
//   header changes were duplicates. /Ob0 and /O1 were worse.
// - The oracle uses a buffered difficulty format-string fetch, not generic
//   append_line. This restores one virtual call slot and 247 positional bytes.
// - VC5 still merges four conquest setter tails. Separate if arms restore all
//   four calls but add 168 bytes, so the switch remains the clean source.
// - The stack helper still emits __chkstk instead of the oracle's __alloca_probe.
// Follow-up pass:
// - The PDB/Ghidra player scans use a saved count, a moving player cursor, a
//   positive guard, and a bottom decrement.  The two reusable scans now use
//   that natural form.  This reduced the positional diff from 4403 to 4369.
// - The original PDB ABI uses RGE_Player_Info&.  The reference surface is
//   retained.  It is codegen-neutral in this function.
// - The post-save enum values are VictoryTime=7 and VictoryScore=8.  The
//   source now uses those proven values.
// - Grouped and reordered victory switch cases recovered the missing setter
//   calls only with a 184-byte boundary overrun.  The natural ascending switch
//   remains the clean source.
// - Separate result, register, zero-local, and object-id forms were neutral or
//   worse.  They are not retained.
// - Remaining blockers are the base-result BL schedule, three merged conquest
//   setter calls, and the compiler's __chkstk symbol choice.
// BINARY NOTE: score_displayed and controllingComputerPlayer publish before
//   the base new_game call. Keep that order and the direct RGE_Player_Info& ABI.
// BINARY NOTE: player objects, victory state, resources, and civilization use
//   the reviewed RGE_Player offsets. TRIBE_Player casts only select derived calls.
// BINARY NOTE: the post-save victory query is one call, generator publication
//   follows the scenario updates, and player effects follow generator cleanup.
// Shared-context audit: world/player ownership is canonical. The 5028-byte
//   candidate retains 168/171 calls and 4369 strict drift; the missing calls are
//   repeated equal-value conquest setter tails, not missing source branches.

#define S_EMPTY ((char*)0x592A40)
#define S_NEWLINE_JOIN ((const char*)0x58C624)

static __inline int count_objects(TRIBE_World* world, short id) {
    int count = 0;
    int player_count = world->player_num;
    if (player_count > 0) {
        RGE_Player** player = world->players;
        do {
        RGE_Object_Node* node = (*player)->objects->list;
        while (node != 0) {
            if (node->node->master_obj->id == id) {
                ++count;
            }
            node = node->next;
        }
        ++player;
        --player_count;
        } while (player_count != 0);
    }
    return count;
}

static __inline int count_ruins(TRIBE_World* world) {
    int count = 0;
    int player_count = world->player_num;
    if (player_count > 0) {
        RGE_Player** player = world->players;
        do {
        RGE_Object_Node* node = (*player)->objects->list;
        while (node != 0) {
            short id = node->node->master_obj->id;
            if (id == 0x9e || id == 0xa3) {
                ++count;
            }
            node = node->next;
        }
        ++player;
        --player_count;
        } while (player_count != 0);
    }
    return count;
}

static __inline void append_line(char* description, char* temp, const char* fmt, int text_id, char* value) {
    sprintf(temp, static_cast<TRIBE_Game*>(rge_base_game)->get_string(text_id), value);
    sprintf(description, S_NEWLINE_JOIN, description, temp);
}

unsigned char TRIBE_World::new_game(RGE_Player_Info& param_1, int param_2) {
    int victoryAmount;
    RGE_RMM_Object_Generator* generator;
    unsigned char ret_num;
    char str1[256];
    char str2[256];
    char str3[256];
    char description[4096];
    int i;
    int age;
    int res;
    int want;
    int missing;
    int postVictoryType;

    this->score_displayed = 0;
    this->controllingComputerPlayer = 0xff;
    ret_num = RGE_Game_World::new_game(param_1, param_2);

    for (i = 0; i < this->player_num; ++i) {
        static_cast<TRIBE_Game*>(rge_base_game)->reset_countdown_timer(i);
    }

    if (!((static_cast<TRIBE_Game*>(rge_base_game)->campaignGame() || !static_cast<TRIBE_Game*>(rge_base_game)->randomGame()) && static_cast<TRIBE_Game*>(rge_base_game)->victoryType() == 0)) {
        if (!static_cast<TRIBE_Game*>(rge_base_game)->campaignGame() && static_cast<TRIBE_Game*>(rge_base_game)->randomGame()) {
        static_cast<T_Scenario*>(this->scenario)->Set_scenario_name(S_EMPTY);
        }

    switch (static_cast<TRIBE_Game*>(rge_base_game)->victoryType()) {
    case 0:
    case 9:
        static_cast<TRIBE_Game*>(rge_base_game)->get_string(0x265c, description, 0x1000);
        break;
    case 1:
        static_cast<TRIBE_Game*>(rge_base_game)->get_string(0x265f, description, 0x1000);
        break;
    case 7:
        static_cast<TRIBE_Game*>(rge_base_game)->get_string(0x265d, description, 0x1000);
        break;
    case 8:
        static_cast<TRIBE_Game*>(rge_base_game)->get_string(0x265e, description, 0x1000);
        break;
    default:
        break;
    }

    switch (static_cast<TRIBE_Game*>(rge_base_game)->mapSize()) {
    case 0: strcpy(str1, static_cast<TRIBE_Game*>(rge_base_game)->get_string(0x2973)); break;
    case 1: strcpy(str1, static_cast<TRIBE_Game*>(rge_base_game)->get_string(0x2974)); break;
    case 2: strcpy(str1, static_cast<TRIBE_Game*>(rge_base_game)->get_string(0x2975)); break;
    case 3: strcpy(str1, static_cast<TRIBE_Game*>(rge_base_game)->get_string(0x2976)); break;
    case 4: strcpy(str1, static_cast<TRIBE_Game*>(rge_base_game)->get_string(0x2977)); break;
    case 5: strcpy(str1, static_cast<TRIBE_Game*>(rge_base_game)->get_string(0x2978)); break;
    }
    append_line(description, str2, "%s", 0x25da, str1);

    if (static_cast<TRIBE_Game*>(rge_base_game)->randomGame()) {
        switch (static_cast<TRIBE_Game*>(rge_base_game)->mapType()) {
        case 0: strcpy(str1, static_cast<TRIBE_Game*>(rge_base_game)->get_string(0x296a)); break;
        case 1: strcpy(str1, static_cast<TRIBE_Game*>(rge_base_game)->get_string(0x296b)); break;
        case 2: strcpy(str1, static_cast<TRIBE_Game*>(rge_base_game)->get_string(0x296c)); break;
        case 3: strcpy(str1, static_cast<TRIBE_Game*>(rge_base_game)->get_string(0x296d)); break;
        case 4: strcpy(str1, static_cast<TRIBE_Game*>(rge_base_game)->get_string(0x296e)); break;
        case 5: strcpy(str1, static_cast<TRIBE_Game*>(rge_base_game)->get_string(0x296f)); break;
        case 6: strcpy(str1, static_cast<TRIBE_Game*>(rge_base_game)->get_string(0x2970)); break;
        case 7: strcpy(str1, static_cast<TRIBE_Game*>(rge_base_game)->get_string(0x2971)); break;
        case 8: strcpy(str1, static_cast<TRIBE_Game*>(rge_base_game)->get_string(0x2972)); break;
        }
        append_line(description, str2, "%s", 0x25b6, str1);
    }

    age = static_cast<TRIBE_Game*>(rge_base_game)->startingAge();
    if (age == 0) {
        static_cast<TRIBE_Game*>(rge_base_game)->get_string(0x10e7, str1, 0x100);
    } else if (age == 1) {
        static_cast<TRIBE_Game*>(rge_base_game)->get_string(0x106e, str1, 0x100);
    } else {
        static_cast<TRIBE_Game*>(rge_base_game)->get_string(age + 0x1067, str1, 0x100);
    }
    append_line(description, str2, "%s", 0x25e4, str1);

    res = static_cast<TRIBE_Game*>(rge_base_game)->resourceLevel();
    if (res == 0) {
        static_cast<TRIBE_Game*>(rge_base_game)->get_string(0x10e7, str1, 0x100);
    } else {
        static_cast<TRIBE_Game*>(rge_base_game)->get_string(res + 0x25e5, str1, 0x100);
    }
    append_line(description, str2, "%s", 0x25e5, str1);

    static_cast<TRIBE_Game*>(rge_base_game)->difficulty();
    static_cast<TRIBE_Game*>(rge_base_game)->get_string(static_cast<TRIBE_Game*>(rge_base_game)->difficulty() + 0x2bd0, str1, 0x100);
    // BINARY NOTE: the shipped block buffers its format string before sprintf.
    static_cast<TRIBE_Game*>(rge_base_game)->get_string(0x25e0, str2, 0x100);
    sprintf(str3, str2, str1);
    sprintf(description, S_NEWLINE_JOIN, description, str3);

    if (static_cast<TRIBE_Game*>(rge_base_game)->randomizePositions() == 0) {
        static_cast<TRIBE_Game*>(rge_base_game)->get_string(0x0fa3, str1, 0x100);
    } else {
        static_cast<TRIBE_Game*>(rge_base_game)->get_string(0x0fa4, str1, 0x100);
    }
    append_line(description, str2, "%s", 0x25e9, str1);
    if (static_cast<TRIBE_Game*>(rge_base_game)->fullVisibility() == 0) {
        strcpy(str1, static_cast<TRIBE_Game*>(rge_base_game)->get_string(0x0fa4));
    } else {
        strcpy(str1, static_cast<TRIBE_Game*>(rge_base_game)->get_string(0x0fa3));
    }
    append_line(description, str2, "%s", 0x25b8, str1);
    if (static_cast<TRIBE_Game*>(rge_base_game)->fullTechTree() == 0) {
        static_cast<TRIBE_Game*>(rge_base_game)->get_string(0x0fa4, str1, 0x100);
    } else {
        static_cast<TRIBE_Game*>(rge_base_game)->get_string(0x0fa3, str1, 0x100);
    }
    append_line(description, str2, "%s", 0x25ec, str1);

    if (static_cast<TRIBE_Game*>(rge_base_game)->multiplayerGame()) {
        if (static_cast<TRIBE_Game*>(rge_base_game)->allowCheatCodes() == 0) {
            strcpy(str1, static_cast<TRIBE_Game*>(rge_base_game)->get_string(0x0fa4));
        } else {
            strcpy(str1, static_cast<TRIBE_Game*>(rge_base_game)->get_string(0x0fa3));
        }
        append_line(description, str2, "%s", 0x25bb, str1);
    }

    static_cast<TRIBE_Game*>(rge_base_game)->get_string((static_cast<TRIBE_Game*>(rge_base_game)->multiplayerGame() ? static_cast<TRIBE_Game*>(rge_base_game)->mpPathFinding() : static_cast<TRIBE_Game*>(rge_base_game)->pathFinding()) + 0x260e, str1, 0x100);
    append_line(description, str2, "%s", 0x25f1, str1);

    sprintf(str2, static_cast<TRIBE_Game*>(rge_base_game)->get_string(0x25f0), (int)static_cast<TRIBE_Game*>(rge_base_game)->popLimit());
    sprintf(description, S_NEWLINE_JOIN, description, str2);
        static_cast<T_Scenario*>(this->scenario)->add_description(description);
    }

    if (ret_num) {
        this->victory_type = 4;
        this->countdown_victory = 0;
        this->countdown_clock = 0.0f;

        if ((!static_cast<TRIBE_Game*>(rge_base_game)->campaignGame() && static_cast<TRIBE_Game*>(rge_base_game)->randomGame()) || static_cast<TRIBE_Game*>(rge_base_game)->victoryType() != 0) {
            static_cast<T_Scenario*>(this->scenario)->Set_victory_all_flag(0);
            static_cast<T_Scenario*>(this->scenario)->Set_Multi_Conquest(0);
            static_cast<T_Scenario*>(this->scenario)->Set_Multi_Ruins(0);
            static_cast<T_Scenario*>(this->scenario)->Set_Multi_Artifacts(0);
            static_cast<T_Scenario*>(this->scenario)->Set_Multi_Discoveries(0);
            static_cast<T_Scenario*>(this->scenario)->Set_Multi_Exploration(0);
            static_cast<T_Scenario*>(this->scenario)->Set_Multi_Gold(0);
            victoryAmount = static_cast<TRIBE_Game*>(rge_base_game)->victoryAmount();
            switch (static_cast<TRIBE_Game*>(rge_base_game)->victoryType()) {
            case 0:
                this->victory_type = 0;
                static_cast<T_Scenario*>(this->scenario)->Set_Multi_Conquest(1);
                break;
            case 1:
                this->victory_type = 1;
                static_cast<T_Scenario*>(this->scenario)->Set_Multi_Conquest(1);
                break;
            case 2:
                static_cast<T_Scenario*>(this->scenario)->Set_Multi_Exploration(victoryAmount);
                break;
            case 3:
                static_cast<T_Scenario*>(this->scenario)->Set_Multi_Ruins(victoryAmount);
                break;
            case 4:
                static_cast<T_Scenario*>(this->scenario)->Set_Multi_Artifacts(victoryAmount);
                break;
            case 5:
                static_cast<T_Scenario*>(this->scenario)->Set_Multi_Discoveries(victoryAmount);
                break;
            case 6:
                static_cast<T_Scenario*>(this->scenario)->Set_Multi_Gold(victoryAmount);
                break;
            case 7:
                this->victory_type = 2;
                static_cast<T_Scenario*>(this->scenario)->Set_Multi_Conquest(1);
                break;
            case 8:
                this->victory_type = 3;
                static_cast<T_Scenario*>(this->scenario)->Set_Multi_Conquest(1);
                break;
            case 9:
                this->victory_type = 0;
                static_cast<T_Scenario*>(this->scenario)->Set_Multi_Conquest(1);
                break;
            }
            static_cast<T_Scenario*>(this->scenario)->Save_victory_conditions_into_players(0);
            // BINARY NOTE: the executable makes one post-save victoryType call.
            postVictoryType = static_cast<TRIBE_Game*>(rge_base_game)->victoryType();
            if (postVictoryType == 7) {
                this->countdown_victory = 1;
                this->countdown_clock = (float)victoryAmount;
            } else if (postVictoryType == 8) {
                for (i = 1; i < this->player_num; ++i) {
                    this->players[i]->victory_conditions->add_victory_points(0, victoryAmount, 1);
                }
            }
        } else {
            if (static_cast<TRIBE_Game*>(rge_base_game)->campaignGame() || static_cast<TRIBE_Game*>(rge_base_game)->scenarioGame()) {
                switch (static_cast<T_Scenario*>(this->scenario)->GetMPVictory()) {
                case 0:
                    this->victory_type = 0;
                    break;
                case 1:
                    this->victory_type = 1;
                    break;
                case 2: {
                    this->victory_type = 3;
                    victoryAmount = static_cast<T_Scenario*>(this->scenario)->GetVictoryScore();
                    for (i = 1; i < this->player_num; ++i) {
                        this->players[i]->victory_conditions->add_victory_points(0, victoryAmount, 1);
                    }
                    break;
                }
                case 3:
                    this->victory_type = 2;
                    this->countdown_victory = 1;
                    this->countdown_clock = (float)static_cast<T_Scenario*>(this->scenario)->GetVictoryTime();
                    break;
                }
            }
        }

        generator = new RGE_RMM_Object_Generator(this->map, 0, this, 0, 0);

        want = static_cast<T_Scenario*>(this->scenario)->Get_Multi_Artifacts();
        if (want > 0) {
            missing = want - count_objects(this, 0x9f);
            if (missing > 0) generator->add_quick_obj(0x9f, missing, 0);
        }
        want = static_cast<T_Scenario*>(this->scenario)->Get_Multi_Discoveries();
        if (want > 0) {
            missing = want - count_objects(this, 10);
            if (missing > 0) generator->add_quick_obj(10, missing, 0);
        }
        want = static_cast<T_Scenario*>(this->scenario)->Get_Multi_Ruins();
        if (want > 0) {
            missing = want - count_ruins(this);
            if (missing > 0) generator->add_quick_obj(0x9e, missing, 0);
        }

        if (!static_cast<TRIBE_Game*>(rge_base_game)->campaignGame() && static_cast<TRIBE_Game*>(rge_base_game)->randomGame()) {
            if (this->victory_type == 3 || debug_rand((char*)0x58c600, 0x38d) % 100 < 50) {
                generator->add_quick_obj(0x9f, 5, *((int*)this->map + 2) / 5);
                this->artifact_count = 5;
            }
            if (debug_rand((char*)0x58c600, 0x394) % 100 < 50) {
                generator->add_quick_obj(0x9e, 5, *((int*)this->map + 2) / 5);
                this->ruin_count = 5;
            }
        } else {
            this->artifact_count = count_objects(this, 0x9f);
            this->ruin_count = count_ruins(this);
        }

        generator->generate();
        if (generator != 0) {
            delete generator;
        }
    }

    if (!static_cast<TRIBE_Game*>(rge_base_game)->allowTrading()) {
        for (i = 1; i < this->player_num; ++i) {
            this->effects->do_effect(0x69, (TRIBE_Player*)this->players[i]);
        }
    }
    if (static_cast<TRIBE_Game*>(rge_base_game)->longCombat() == 1) {
        for (i = 1; i < this->player_num; ++i) {
            this->effects->do_effect(0x64, (TRIBE_Player*)this->players[i]);
        }
    }

    if (!static_cast<TRIBE_Game*>(rge_base_game)->fullTechTree() && !static_cast<T_Scenario*>(this->scenario)->GetScenarioOption(2)) {
        for (i = 1; i < this->player_num; ++i) {
            this->effects->do_effect(this->players[i]->culture, (TRIBE_Player*)this->players[i]);
        }
    } else {
        for (i = 1; i < this->player_num; ++i) {
            this->effects->do_effect(0xd2, (TRIBE_Player*)this->players[i]);
        }
    }

    switch (static_cast<TRIBE_Game*>(rge_base_game)->resourceLevel()) {
    case 1:
        for (i = 1; i < this->player_num; ++i) {
            *(int*)&this->players[i]->attributes[0] = 0x43480000;
            *(int*)&this->players[i]->attributes[1] = 0x43480000;
            *(int*)&this->players[i]->attributes[3] = 0;
            *(int*)&this->players[i]->attributes[2] = 0x42c80000;
        }
        break;
    case 2:
        for (i = 1; i < this->player_num; ++i) {
            *(int*)&this->players[i]->attributes[0] = 0x43fa0000;
            *(int*)&this->players[i]->attributes[1] = 0x43fa0000;
            *(int*)&this->players[i]->attributes[3] = 0;
            *(int*)&this->players[i]->attributes[2] = 0x437a0000;
        }
        break;
    case 3:
        for (i = 1; i < this->player_num; ++i) {
            *(int*)&this->players[i]->attributes[0] = 0x447a0000;
            *(int*)&this->players[i]->attributes[1] = 0x447a0000;
            *(int*)&this->players[i]->attributes[3] = 0;
            *(int*)&this->players[i]->attributes[2] = 0x443b8000;
        }
        break;
    }

    if (static_cast<TRIBE_Game*>(rge_base_game)->deathMatch()) {
        for (i = 1; i < this->player_num; ++i) {
            *(int*)&this->players[i]->attributes[0] = 0x469c4000;
            *(int*)&this->players[i]->attributes[1] = 0x469c4000;
            *(int*)&this->players[i]->attributes[3] = 0x461c4000;
            *(int*)&this->players[i]->attributes[2] = 0x459c4000;
        }
    }

    switch (static_cast<TRIBE_Game*>(rge_base_game)->startingAge()) {
    case 3:
        for (i = 1; i < this->player_num; ++i) ((TRIBE_Player*)this->players[i])->rev_tech(0x19);
        break;
    case 4:
        for (i = 1; i < this->player_num; ++i) ((TRIBE_Player*)this->players[i])->rev_tech(0x17);
        break;
    case 5:
        for (i = 1; i < this->player_num; ++i) ((TRIBE_Player*)this->players[i])->rev_tech(0x18);
        break;
    }

    if (static_cast<TRIBE_Game*>(rge_base_game)->check_prog_argument((char*)0x58c5f4)) {
        for (i = 1; i < this->player_num; ++i) {
            ((TRIBE_Player*)this->players[i])->new_attribute_num(0x20, 50.0f);
            ((TRIBE_Player*)this->players[i])->new_attribute_num(0x21, 0.0f);
            ((TRIBE_Player*)this->players[i])->new_attribute_num(0x1e, 500.0f);
            ((TRIBE_Player*)this->players[i])->new_attribute_num(0x1f, 5000.0f);
        }
    } else if (static_cast<TRIBE_Game*>(rge_base_game)->check_prog_argument((char*)0x58c5ec)) {
        for (i = 1; i < this->player_num; ++i) {
            ((TRIBE_Player*)this->players[i])->new_attribute_num(0x20, 50.0f);
            ((TRIBE_Player*)this->players[i])->new_attribute_num(0x21, 0.0f);
        }
    } else {
        for (i = 1; i < this->player_num; ++i) {
            ((TRIBE_Player*)this->players[i])->new_attribute_num(0x20, (float)static_cast<TRIBE_Game*>(rge_base_game)->popLimit());
            ((TRIBE_Player*)this->players[i])->new_attribute_num(0x21, 0.0f);
            ((TRIBE_Player*)this->players[i])->new_attribute_num(0x1e, 500.0f);
            ((TRIBE_Player*)this->players[i])->new_attribute_num(0x2d, 1.0f);
            this->players[i]->victory_conditions->add_points_attribute_amount(0, 0, 0x14, 2, 1);
            this->players[i]->victory_conditions->add_points_attribute_amount(0, 1, 0x2b, 1, 1);
            this->players[i]->victory_conditions->add_points_attribute_amount(0, 2, 0x2c, 1, 1);
            this->players[i]->victory_conditions->add_points_high_attribute_once(0, 3, 0x28, 1, 0x19);
            this->players[i]->victory_conditions->add_points_attribute_amount(1, 4, 0x31, 100, 1);
            this->players[i]->victory_conditions->add_points_attribute_amount(1, 9, 0x35, 0x3c, 1);
            this->players[i]->victory_conditions->add_points_high_attribute_amount(1, 5, 0x25, 1, 1);
            this->players[i]->victory_conditions->add_points_high_attribute_once(1, 6, 0x25, 1, 0x19);
            this->players[i]->victory_conditions->add_points_attribute_amount(1, 7, 0x16, 3, 1);
            if (!static_cast<TRIBE_Game*>(rge_base_game)->fullVisibility()) {
                this->players[i]->victory_conditions->add_points_highest_attribute(1, 8, 0x16, 1, 0x19);
            }
            this->players[i]->victory_conditions->add_points_attribute_amount(2, 10, 0x29, 1, 2);
            this->players[i]->victory_conditions->add_points_highest_attribute(2, 11, 0x29, 1, 0x19);
            this->players[i]->victory_conditions->add_points_attribute_amount(2, 12, 0x0e, 1, 10);
            this->players[i]->victory_conditions->add_points_attribute_amount(2, 13, 7, 1, 10);
            this->players[i]->victory_conditions->add_points_attribute_amount(2, 14, 0x34, 1, 3);
            this->players[i]->victory_conditions->add_points_attribute_amount(2, 16, 0x37, 1, 0x32);
            this->players[i]->victory_conditions->add_points_attribute_amount(2, 15, 0x36, 1, 0x32);
            this->players[i]->victory_conditions->add_points_attribute_amount(3, 17, 0x15, 1, 2);
            this->players[i]->victory_conditions->add_points_highest_attribute(3, 18, 0x15, 1, 0x32);
            this->players[i]->victory_conditions->add_points_attribute_first(3, 19, 6, 3, 0x19);
            this->players[i]->victory_conditions->add_points_attribute_first(3, 20, 6, 4, 0x19);
            this->players[i]->victory_conditions->add_points_attribute_amount(4, 22, 0x2d, 1, 100);
            this->players[i]->victory_conditions->add_points_attribute_amount(4, 23, 0x2a, 1, 100);
            ((TRIBE_Player*)this->players[i])->add_population_entry();
        }    }

    return ret_num;
}

// 00530370 TRIBE_World::new_scenario
// PDB source: tworld.cpp

unsigned char TRIBE_World::new_scenario(RGE_Player_Info& info, int flags) {
    unsigned char result = RGE_Game_World::new_scenario(info, flags);
    int i = 1;
    if (this->player_num > 1) {
        do {
            ++i;
            this->players[i - 1]->attributes[0] = 200.0f;
            this->players[i - 1]->attributes[1] = 200.0f;
            this->players[i - 1]->attributes[3] = 0;
            this->players[i - 1]->attributes[2] = 100.0f;
        } while (i < this->player_num);
    }
    return result;
}

// VA: 005303F0 TRIBE_World::check_game_state
// PDB source: tworld.cpp lines 1151-1371
// Attempt log:
// 1: initial natural reconstruction from Ghidra body, typed local arrays and direct call surfaces.
// 2: corrected world/player offsets, float constants, and direct victory/message call surfaces; call set aligned but body remained structurally broad.
// 3: tried source loop/local-shape reductions and external float constants; no exact basin, frame/size still drift.
// 4: replaced the raw volatile game-state guard with the named game_state field; emitted code was unchanged, so the natural form remains.
// 5: threshold-left and negated-less countdown guards changed FPU order but did not match; kept the period guard form.
// 6: removing the positive array-init guard changed the call prefix and worsened the body; restored it.
// 7-8: local base-game aliases prevented message-call tail merging and aligned all virtual calls, but added code.
// 9: removed the grouping p local and used direct player expressions; frame reached 0x1A4 and team arrays reached original homes.
// 10: removed the outer team-building guard; one loop entry test now matches the original and size dropped to +22 bytes.
// 11: cached player_count across team setup; size reached +11 bytes, but register/block shape worsened.
// 12: kept a local base-game alias for the ruin-start message; all 16 calls now align, with 1668 rebuilt bytes vs 1653 original.
// 13: tested the proven 00577580 global for held == -1 comparisons; kept it because the original has two absolute references.
// 14: tested scoped base-game aliases at each message site and direct player_num bounds; call and block shape improved, but the source was compiler-steering and was rolled back.
// 15: restored the clean cached-player reconstruction; remaining drift is team-array scheduling and the saved this home.
// 16: direct team_size increments reduced the strict difference to 1457 bytes.
// 17: keeping player_count only for the two fill loops and reloading player_num
//     for the team loops reduced the strict difference to 1300 bytes.
// 18-21: declaration, comparison, pointer-scope, and cursor variants did not
//        change emitted code or improve the 1300-byte result.
// Main-agent audit replaced raw-address macros with named extern globals.
// Best clean result: 1653 rebuilt bytes, 0 size delta, exact frame, all 16
// calls aligned, 1300 strict differing bytes, 87.03% shape similarity.
// BINARY NOTE: The original reloads player_num at the team-loop backedge.
// Keep those bounds as direct this->player_num expressions.
// 22: the CodeView-declared float held_time type added an unwanted __ftol call;
//     the int count form is the supported codegen basin.
// 23-24: bulk memset and intrinsic variants added byte-tail code and were
//        discarded; the existing integer fill lowering is closer in size.
// 25-27: do-loop and block-scope victory-index variants were codegen-neutral.
// 28-30, 33: typed row/size cursors improved CFG shape but moved pointer homes
//            and increased strict drift; the direct indexed form remains.
// 31: member-left winner comparison restores the original CMP/JLE block.
// 32, 34-35: the canonical RGE_Player attributes pointer improves exact
//             attribute blocks; lifted p/held variants do not improve codegen.
// BINARY NOTE: Artifact totals and reset-zero effects use attributes[7] and
// attributes[55]. Ruin uses attributes[14] and attributes[54]. Held timers
// still use the direct derived fields at +840 and +844.
// Current semantic checkpoint: 1662 bytes, exact frame, all 16 calls aligned,
// 1437 strict differing bytes, and 63.37% exact-block coverage.
// Unresolved: the victory guard hoists i=1 and team-array cursor homes differ.

unsigned char TRIBE_World::check_game_state()
{
    int i;
    int held_time;
    int local_1a0;
    int team_count;
    int local_198;
    int team_size[9];
    int player_team[9];
    TRIBE_Player* team_player[9][9];

    if (this->game_state == 0) {
        if (this->victory_type == 2 && this->countdown_victory != 0 &&
            this->countdown_clock >= DAT_00577578) {
            if ((this->countdown_clock =
                     this->countdown_clock - (this->world_time_delta_seconds + this->world_time_delta_seconds)) <
                DAT_00577578) {
                for (i = 0; i < 9; ++i)
                    team_size[i] = -1;
                for (i = 1; i < this->player_num; ++i) {
                    team_size[i] = this->players[i]->victory_conditions->get_victory_points();
                    held_time = 1;
                    if (this->players[i]->allied_victory != 0 && this->player_num > 1) {
                        for (local_1a0 = 1; local_1a0 < this->player_num; ++local_1a0) {
                            if (local_1a0 != i &&
                                this->players[i]->relation(local_1a0) == 0 &&
                                this->players[local_1a0]->relation(i) == 0 &&
                                this->players[local_1a0]->allied_victory != 0) {
                                team_size[i] += this->players[local_1a0]->victory_conditions->get_victory_points();
                                ++held_time;
                            }
                        }
                    }
                    team_size[i] /= held_time;
                }
                TRIBE_Player* winner = 0;
                int best = -1;
                for (i = 1; i < this->player_num; ++i) {
                    if (team_size[i] > best) {
                    winner = static_cast<TRIBE_Player*>(this->players[i]);
                        best = team_size[i];
                    }
                }
                if (winner != 0) {
                    winner->win_game_now();
                    this->game_end_condition = 0x67;
                }
            }
        }

        if (this->artifact_count > 0 || this->ruin_count > 0) {
            int player_count = this->player_num;
            if (player_count > 0) {
                for (i = 0; i < player_count; ++i)
                    team_size[i] = 0;
                for (i = 0; i < player_count; ++i)
                    player_team[i] = -1;
            }
            local_198 = 0;
            held_time = 1;
            team_count = 0;
            for (i = 1; i < this->player_num; ++i) {
                if (player_team[i] == -1) {
                    player_team[i] = local_198;
                    team_player[local_198][team_size[local_198]] = static_cast<TRIBE_Player*>(this->players[i]);
                    ++team_size[local_198];
                    if (this->players[i]->allied_victory != 0) {
                        local_1a0 = 1;
                        for (; local_1a0 < this->player_num; ++local_1a0) {
                            if (player_team[local_1a0] == -1 &&
                                this->players[local_1a0]->allied_victory != 0 &&
                                this->players[i]->relation(local_1a0) == 0 &&
                                this->players[local_1a0]->relation(i) == 0) {
                                player_team[local_1a0] = local_198;
                                    team_player[local_198][team_size[local_198]] =
                                        static_cast<TRIBE_Player*>(this->players[local_1a0]);
                                ++team_size[local_198];
                            }
                        }
                    }
                    ++local_198;
                    team_count += 9;
                }
            }

            if (this->artifact_count > 0 && local_198 > 0) {
                for (i = 0; i < local_198; ++i) {
                    int count = team_size[i];
                    int total = 0;
                    for (int j = 0; j < count; ++j)
                        total += (int)team_player[i][j]->attributes[7];
                    if (total == this->artifact_count) {
                        TRIBE_Player* p = team_player[i][0];
                        float held = p->artifact_held_time;
                        if (held == DAT_00577580) {
                            for (int j = 0; j < count; ++j)
                                team_player[i][j]->attributes[55] = 1.0f;
                            if (this->victory_type == 0) {
                                for (int j = 0; j < count; ++j)
                                    team_player[i][j]->artifact_held_time = 2000.0f;
                                rge_base_game->notification(0x72,
                                    p->id, 0, 0, 0);
                            }
                        }
                        else if (held >= DAT_00577578 && this->victory_type == 0) {
                            held = held - (this->world_time_delta_seconds + this->world_time_delta_seconds);
                            for (int j = 0; j < count; ++j)
                                team_player[i][j]->artifact_held_time = held;
                            if (held < DAT_00577578) {
                                p->win_game_now();
                                this->game_end_condition = 0x65;
                            }
                        }
                    }
                    else {
                        TRIBE_Player* p = team_player[i][0];
                        if (p->artifact_held_time != -1.0f) {
                            for (int j = 0; j < count; ++j)
                                team_player[i][j]->attributes[55] = 0.0f;
                            if (this->victory_type == 0) {
                                for (int j = 0; j < count; ++j)
                                    team_player[i][j]->artifact_held_time = -1.0f;
                                rge_base_game->notification(0x73,
                                    p->id, 0, 0, 0);
                            }
                        }
                    }
                }
            }

            if (this->ruin_count > 0 && local_198 > 0) {
                for (i = 0; i < local_198; ++i) {
                    int count = team_size[i];
                    int total = 0;
                    for (int j = 0; j < count; ++j)
                        total += (int)team_player[i][j]->attributes[14];
                    if (total == this->ruin_count) {
                        TRIBE_Player* p = team_player[i][0];
                        float held = p->ruin_held_time;
                        if (held == DAT_00577580) {
                            for (int j = 0; j < count; ++j)
                                team_player[i][j]->attributes[54] = 1.0f;
                            if (this->victory_type == 0) {
                                for (int j = 0; j < count; ++j)
                                    team_player[i][j]->ruin_held_time = 2000.0f;
                                RGE_Base_Game* game = rge_base_game;
                                game->notification(0x74, p->id, 0, 0, 0);
                            }
                        }
                        else if (held >= DAT_00577578 && this->victory_type == 0) {
                            held = held - (this->world_time_delta_seconds + this->world_time_delta_seconds);
                            for (int j = 0; j < count; ++j)
                                team_player[i][j]->ruin_held_time = held;
                            if (held < DAT_00577578) {
                                p->win_game_now();
                                this->game_end_condition = 0x66;
                            }
                        }
                    }
                    else {
                        TRIBE_Player* p = team_player[i][0];
                        if (p->ruin_held_time != -1.0f) {
                            for (int j = 0; j < count; ++j)
                                team_player[i][j]->attributes[54] = 0.0f;
                            if (this->victory_type == 0) {
                                for (int j = 0; j < count; ++j)
                                    team_player[i][j]->ruin_held_time = -1.0f;
                                rge_base_game->notification(0x75, p->id, 0, 0, 0);
                            }
                        }
                    }
                }
            }
        }
    }

    return RGE_Game_World::check_game_state();
}

long TRIBE_World::get_achievement(unsigned char achievement_id, char** buffers) {
    int player = 1;

    if (this->player_num > 1) {
        do {
            TRIBE_Player* p = static_cast<TRIBE_Player*>(this->players[player]);
            if (p != 0) {
                p->get_achievement(achievement_id, buffers[player]);
            }
            player++;
        } while (player < this->player_num);
    }

    return this->player_num;
}

// VA: 00530AC0 TRIBE_World::send_cheat(short)
// BINARY NOTE: the direct target is TRIBE_Command::command_cheat(short, short).
// Keep the command owner and method name.  A generic InnerObj::method changes
// relocation identity even when the instruction bytes stay aligned.

void TRIBE_World::send_cheat(short code) {
    static_cast<TRIBE_Command*>(this->commands)->command_cheat(
        this->curr_player, code);
}

// VA: 00530AE0 TRIBE_World::cheat (1534 B)
// PDB source: tworld.cpp:1395-1606
// Baseline reconstruction: dispatch the multiplayer cheat command, object-list
// actions, player diplomacy checks, and the map visibility actions through the
// period class surfaces proved by the original call sites.
// Attempt log:
// - Baseline had the correct 1534-byte body but omitted two effects calls and
//   factored three repeated kill loops through a helper.
// - Inlined the three object-list loops and restored effects 0xd8 and 0xd9;
//   the result is an exact 1534-byte match with all 44 calls aligned.

void TRIBE_World::cheat(short player, short cheat_code)
{
    if (rge_base_game->allowCheatCodes() != 0) {
        switch (cheat_code) {
        case 0:
            if (player > 0) {
                RGE_Static_Object* object = this->players[player]->objects->find_by_master_id(
                    0x6d, -1.0f, -1.0f, 1, 2, 0);
                if (object != 0)
                    static_cast<TRIBE_Command*>(this->commands)->command_make(object, 0x112);
            }
            break;
        case 1:
            if (player > 0) {
                RGE_Static_Object* object = this->players[player]->objects->find_by_master_id(
                    0x6d, -1.0f, -1.0f, 1, 2, 0);
                if (object != 0)
                    static_cast<TRIBE_Command*>(this->commands)->command_make(object, 0xf8);
            }
            break;
        case 2:
            if (player > 0)
                this->effects->do_effect(0x7f, this->players[player]);
            break;
        case 3:
            if (player > 0)
                this->effects->do_effect(0x80, this->players[player]);
            break;
        case 4:
            if (player > 0)
                this->effects->do_effect(0x81, this->players[player]);
            break;
        case 5:
            this->effects->do_effect(0x82, this->players[0]);
            break;
        case 6:
            if (player > 0)
                this->effects->do_effect(0x83, this->players[player]);
            break;
        case 7:
            if (player > 0)
                this->effects->do_effect(0x84, this->players[player]);
            break;
        case 8:
            if (player > 0)
                this->effects->do_effect(0x85, this->players[player]);
            break;
        case 9:
            if (player > 0)
                this->effects->do_effect(0x86, this->players[player]);
            break;
        case 10:
            if (player > 0)
                this->effects->do_effect(0x87, this->players[player]);
            break;
        case 11:
            if (player > 0)
                this->effects->do_effect(0x88, this->players[player]);
            break;
        case 12:
            if (player > 0)
                this->effects->do_effect(0x89, this->players[player]);
            break;
        case 13:
            if (player > 0)
                this->effects->do_effect(0x8a, this->players[player]);
            break;
        case 14:
            if (player > 0) {
                RGE_Static_Object* object = this->players[player]->objects->find_by_master_id(
                    0x6d, -1.0f, -1.0f, 1, 2, 0);
                if (object != 0)
                    static_cast<TRIBE_Command*>(this->commands)->command_make(object, 0x182);
            }
            break;
        case 15:
            if (player > 0)
                this->effects->do_effect(0xd7, this->players[player]);
            break;
        case 16:
            if (player > 0) {
                RGE_Static_Object* object = this->players[player]->objects->find_by_master_id(
                    0x6d, -1.0f, -1.0f, 1, 2, 0);
                if (object != 0)
                    static_cast<TRIBE_Command*>(this->commands)->command_make(object, 0x18d);
            }
            break;
        case 17:
            if (player > 0)
                this->players[player]->objects->find_by_master_id(
                    0x6d, -1.0f, -1.0f, 1, 2, 0);
            break;
        case 18:
            this->effects->do_effect(0xd8, this->players[0]);
            break;
        case 19:
            this->effects->do_effect(0xd9, this->players[0]);
            break;
        case 100: {
            int i = 1;
            die_die_die = 1;
            if (this->player_num > 1) {
                do {
                    if (i != player || this->players[player]->isAlly(i) == 0 ||
                        this->players[i]->isAlly(player) == 0)
                    {
                        RGE_Object_Node* node = this->players[i]->objects->list;
                        while (node != 0) {
                            RGE_Static_Object* object = node->node;
                            if (object->object_state < 3 &&
                                object->master_obj->object_group != 1)
                                object->die_die_die();
                            node = node->next;
                        }
                    }
                    ++i;
                } while (i < this->player_num);
            }
            break;
        }
        case 101:
            {
                RGE_Object_Node* node = this->players[player]->objects->list;
                while (node != 0) {
                    RGE_Static_Object* object = node->node;
                    if (object->object_state < 3 &&
                        object->master_obj->object_group != 1)
                        object->die_die_die();
                    node = node->next;
                }
            }
            break;
        case 102:
            this->players[player]->win_game_now();
            this->game_end_condition = 0x68;
            break;
        case 103:
            this->players[player]->loss_if_game_on();
            break;
        case 200:
        case 201:
        case 202:
        case 203:
        case 204:
        case 205:
        case 206:
        case 207:
        case 208:
        case 209: {
            int other_player = cheat_code - 200;
            if ((other_player != player ||
                 this->players[player]->isAlly(other_player) == 0 ||
                 this->players[other_player]->isAlly(player) == 0) &&
                this->players[other_player]->objects->list != 0) {
                RGE_Object_Node* node = this->players[other_player]->objects->list;
                while (node != 0) {
                    RGE_Static_Object* object = node->node;
                    if (object->object_state < 3 &&
                        object->master_obj->object_group != 1)
                        object->die_die_die();
                    node = node->next;
                }
            }
            break;
        }
        case 220: {
            RGE_Static_Object* object = this->players[player]->objects->find_by_master_id(
                0x6d, -1.0f, -1.0f, 1, 2, 0);
            if (object != 0)
                static_cast<TRIBE_Command*>(this->commands)->command_make(object, 0x174);
            break;
        }
        case 230:
            rge_base_game->set_map_visible(1);
            rge_base_game->get_view_panel()->set_redraw(TPanel::RedrawImmediate);
            rge_base_game->get_map_panel()->set_redraw(TPanel::RedrawImmediate);
            break;
        case 231:
            rge_base_game->set_map_fog(0);
            rge_base_game->get_view_panel()->set_redraw(TPanel::RedrawImmediate);
            break;
        }
    }
}

// 00531240 TRIBE_World::fill_in_score
// PDB source: tworld.cpp:1610-1637
//
// Baseline reconstruction: choose the highest victory score among human
// players (slots 1 through player_num - 1), copy the selected player's
// display data, then count mutually unrelated other players.
// Main-agent audit restored polymorphic player/world ownership at the proven
// offsets; emitted code remains exact.


void TRIBE_World::fill_in_score(TRIBE_Zone_High_Score_Info& info, long group)
{
    int player = 1;
    long high_score = 0;
    int hi_player = 1;

    if (1 < this->player_num) {
        do {
            if (this->players[player]->computerPlayer() == 0) {
                if (this->players[player]->victory_conditions->get_victory_points_group((unsigned char)group) > high_score) {
                    high_score = this->players[player]->victory_conditions->get_victory_points_group((unsigned char)group);
                    hi_player = player;
                }
            }
            player++;
        } while (player < this->player_num);
    }

    info.score = high_score;
    info.civ = this->players[hi_player]->culture;
    strcpy(info.player_name, this->players[hi_player]->name);

    long count = 0;
    player = 1;
    if (1 < this->player_num) {
        do {
            if ((player != hi_player) &&
                (this->players[player]->relation(hi_player) == 0) &&
                (this->players[hi_player]->relation(player) == 0)) {
                count++;
            }
            player++;
        } while (player < this->player_num);
    }
    info.num_allies = (unsigned char)count;
}

// VA: 00531350 TRIBE_World::send_zone_score_info (877 B)
// PDB source: tworld.cpp lines 1641-1757
// The packet records and all foreign classes come from their canonical owners.

void TRIBE_World::send_zone_score_info()
{
    TRIBE_Zone_Info info;
    TRIBE_Game::TRIBE_Game_Options options;
    int computer_players = 0;
    int player;

    if (this->sent_zone_score == 0) {
        this->sent_zone_score = 1;
        info.number_of_players = 0;
        computer_players = 0;
        player = 1;
        if (player < this->player_num) {
            do {
                if (this->players[player]->computerPlayer() == 0)
                    info.number_of_players++;
                else
                    computer_players++;
                player++;
            } while (player < this->player_num);
        }
        info.number_of_computer_players = (unsigned char)computer_players;

        strcpy(info.scenario_name, this->scenario->Get_scenario_name());
        info.game_time = this->world_time / 1000;

        this->fill_in_score(info.total_score, 0xFF);
        this->fill_in_score(info.religion_score, 2);
        this->fill_in_score(info.economy_score, 1);
        this->fill_in_score(info.combat_score, 0);
        this->fill_in_score(info.research_score, 3);

        player = 1;
        if (player < this->player_num) {
            do {
                strcpy(info.player_info[player - 1].name,
                    this->players[player]->name);
                info.player_info[player - 1].score =
                    this->players[player]->victory_conditions->get_victory_points();
                info.player_info[player - 1].winner =
                    (this->players[player]->game_status == 1);
                info.player_info[player - 1].civ_played =
                    (unsigned char)static_cast<TRIBE_Game*>(rge_base_game)->civilization(player - 1);
                info.player_info[player - 1].civ_random =
                    (unsigned char)static_cast<TRIBE_Game*>(rge_base_game)->random_civ[player - 1];
                info.player_info[player - 1].player_no =
                    (unsigned char)static_cast<TRIBE_Game*>(rge_base_game)->playerColor(player - 1);
                info.player_info[player - 1].team_no =
                    (unsigned char)static_cast<TRIBE_Game*>(rge_base_game)->playerTeam(player - 1);
                int game_outcome = comm->WasKicked[player - 1];
                info.player_info[player - 1].game_outcome =
                    (unsigned char)game_outcome;
                info.player_info[player - 1].tool_time = -1;
                info.player_info[player - 1].bronze_time = -1;
                info.player_info[player - 1].iron_time = -1;

                TRIBE_History_Events* event =
                    static_cast<TRIBE_Player*>(this->players[player])->history->events;
                while (event != 0) {
                    switch (event->event) {
                    case 0:
                        info.player_info[player - 1].tool_time = event->world_time;
                        break;
                    case 1:
                        info.player_info[player - 1].bronze_time = event->world_time;
                        break;
                    case 2:
                        info.player_info[player - 1].iron_time = event->world_time;
                        break;
                    }
                    event = event->next;
                }
                player++;
            } while (player < this->player_num);
        }

        info.cheats_enabled = (unsigned char)static_cast<TRIBE_Game*>(rge_base_game)->allowCheatCodes();
        switch (this->game_end_condition) {
        case 0:
            info.game_end_condition_code = 0;
            break;
        case 1:
            info.game_end_condition_code = 1;
            break;
        case 100:
            info.game_end_condition_code = 2;
            break;
        case 101:
            info.game_end_condition_code = 3;
            break;
        case 102:
            info.game_end_condition_code = 4;
            break;
        case 103:
            info.game_end_condition_code = 5;
            break;
        case 2:
            info.game_end_condition_code = 6;
            break;
        case 104:
            info.game_end_condition_code = 7;
            break;
        default:
            info.game_end_condition_code = 8;
            break;
        }

        static_cast<TRIBE_Game*>(rge_base_game)->get_tribe_options(&options);
        info.map_info.Map_Size = (unsigned char)options.mapSizeValue;
        info.map_info.Map_Type = (unsigned char)options.mapTypeValue;
        info.map_info.Victory_Condition = (unsigned char)options.victoryTypeValue;
        info.map_info.Start_Age = (unsigned char)options.startingAgeValue;
        info.map_info.Resources = (unsigned char)options.resourceLevelValue;
        info.map_info.Full_Tech = options.fullTechTreeValue;
        info.map_info.Fixed_Pos = options.randomizePositionsValue;
        info.map_info.Reveal_Map = (unsigned char)static_cast<TRIBE_Game*>(rge_base_game)->fullVisibility();
        info.map_info.Death_Match = options.deathMatchValue;
        info.map_info.Pop_Limit = (short)options.popLimitValue;

        info.database_checksum = 0;
        info.code_checksum = 0;
        info.program_version = 0;

        this->commands->com_hand->SendZoneMessage((char*)&info, 0x1fc);
    }
}
