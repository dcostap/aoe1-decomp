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
// Prefix TU pass: moved the proven player/info ownership into the shared
// tworld_prefix context. Isolated and six-owner grouped checks remain exact.

#include "../../include/tworld_prefix_context.h"

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
