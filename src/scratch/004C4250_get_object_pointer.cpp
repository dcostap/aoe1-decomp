// VA: 004C4250 RGE_Static_Object::get_object_pointer
// PDB source: stat_obj.cpp lines 1978-2011
#include <stdlib.h>

// Attempt log:
// baseline: natural owner/object-list search with the binary-proven
// player-index and world/player layouts; exact size/call set, 139 bytes differ.
// liveness: delayed signed compare-index initialization until after the player
// count guard; reduced the mismatch to 37 bytes and preserved all call sites.
// liveness: parameter-home reuse and several declaration/type/order variants
// either widened the function or emitted the same 37-byte codegen basin; rolled back.
// variant: 32 natural declaration/update variants produced only the same
// 37-byte basin or a 227-byte context tail; no exact candidate.
// fresh worker: direct (short) casts of the byte player index widened to 227B/190;
// restored the canonical compare-index source.
// fresh worker: register-qualified compare-index local emitted the same 219B/37
// basin; restored the ordinary local.
// 2026-08-10 orch-statobj-fresh-03 fresh pass (7 meaningful probes):
// unsigned-short/explicit-promotion, int-width, comma-update, and decompiler
// parameter-home/index forms either widened the body or emitted the same 219B/37
// basin. The unsigned-short Ghidra uVar4 spelling with signed casts was also a
// codegen duplicate. All six calls and canonical owner/world/player/list accesses
// remain exact; only ESI-owner versus EDX-compare-index loop-tail coloring and its
// dependent branch displacements differ.
// 2026-08-10 wave20-statobj-01 fresh pass (9 meaningful probes):
// a 32-variant declaration/owner-test/update lab, direct owner rereads,
// function-scope Ghidra local ordering, canonical polymorphic Player/World/List
// surfaces, explicit byte-to-short conversion, and signed/unsigned width pairs
// either reproduced the same 219B/37 basin or widened the function. The final
// unsigned-width variant widened to 247B/237; restored the clean source.
// left in scratch: best source is the readable owner/world/player reconstruction;
// remaining drift is only owner/compare-index register coloring and the loop tail.
// 2026-08-11 sa-2ff614d9-r1 fresh pass (9 meaningful probes): reordered the
// object-id/owner declarations, mixed direct byte-promotion with the named
// compare local, made the parameter-home reset explicit, restored <stdlib.h>,
// reversed equality operands, scoped the compare temporary, combined register
// hints, and tried a const owner pointer; all retained-size variants stayed in
// the 219B/37 basin or widened. A 24-variant mixed loop-surface lab likewise
// found no exact candidate. Restored the clean readable source; no probe moved
// the ESI-owner versus EDX-compare-index loop-tail hunk.
// 2026-08-12 orch2-4C4250-tail focused tail pass (3 meaningful probes): moving
// world reload before compare assignment widened to 227B/190; reusing the dead
// id home after the byte increment was a 219B/37 duplicate; combining both
// changes widened to 227B/190. Restored the clean source; the original
// increment/home/world/word-compare order remains unresolved.
// 2026-08-12 follow-C4250-r1 pass: adding the binary-supported polymorphic
// surface to RGE_Object_List, then to RGE_Player/RGE_Game_World, left the
// 219B/37 output unchanged. Routing the tail compare through the dead id
// parameter widened to 229B/158; swapping compare/index declaration order
// gave 219B/52; an explicit tail compare zero was a 219B/37 duplicate.
// Restored the readable clean source. Direct find_by_id calls remain exact;
// the unresolved drift is still only ESI owner versus EDX compare coloring
// and its dependent loop-tail branch displacements.

// tu-statobj-C4250 2026-08-12: retained the complete static/master surface and
// stat_obj.cpp header context. The layout/context ABI probe was codegen-neutral;
// the readable typed source still differs only in the owner/compare tail basin.
// 2026-08-13 sa-e39fccc4-r1-tail2 reassessment: direct owner rereads were a
// 219B/37 codegen duplicate. Unsigned or byte compare-index types widened the
// body (227B-238B); dead parameter-home update/order variants widened it to
// 241B-247B. Restored the clean typed source; no new tail lead was found.
// 2026-08-16 sa-967e1011-r1 fresh pass (11 meaningful probes): direct signed
// casts at both predicates, player and compare register hints, function-scope
// compare declaration, cached owner id, signed-byte and unsigned-owner-id
// types, split loop comparisons, split index initialization, and related
// declaration forms either widened the body or reproduced the 219B/37 basin.
// The split-comparison form briefly selected ESI for the owner and EDX for the
// tail compare, but lost the original EBX byte home and prologue. Restored the
// readable typed source. Remaining drift is the ESI-owner versus EDX-compare
// loop-tail register map and its dependent branch displacements.
// 2026-08-17 sa-27522190-r1 reassessment: direct byte comparisons widened the
// body; removing the object-id alias, direct owner rereads, split compare
// initialization, and byte-cast tail tests either duplicated 219B/37 or lost
// the original EBX byte home. Eight standard-header combinations also formed
// one duplicate 219B/37 basin. Restored the clean typed source; no natural
// source form moved the owner/compare register-map hunk.
// 2026-08-17 sa-222d08b4-r1 revisit: the Ghidra-supported unsigned compare,
// parameter-home index, loop-local compare, declaration-order, update-order,
// const-owner, and split-initialization forms either widened the body or
// reproduced the 219B/37 basin. The clean typed source remains authoritative.
// 2026-08-17 deep stat_obj/scenario context pass: replaced the anonymous local
// vtable pads with the donor-backed RGE_Static_Object prefix, the minimal
// stat_obj RGE_Player destructor/field surface, the one-slot polymorphic
// RGE_Game_World surface, and the real RGE_Object_List load header. These
// canonical context changes were codegen-neutral and retained the 219B/37
// basin. A full named player prefix and full world virtual ordering were also
// neutral. An owner reference or const pointer widened to 147 bytes. The
// explicit parameter-home index update, both alone and with a const saved id,
// widened to 227/190 bytes. Split owner/world initialization and const saved
// object-id forms were neutral. No policy-valid owner/index lifetime form moved
// the ESI-owner versus EDX-compare tail basin; the canonical context is kept.
// 2026-08-17 PDB-local audit: DIA names only obj_id and one player_id local;
// player_id has one-byte type metadata at virtual-frame offset +8. This supports
// the byte index and treats Ghidra's ushort uVar4 as a promotion temporary.
// Natural one-byte player_id reconstructions widened to 227 bytes or changed
// result allocation. The clean two-local form remains the only 219B/37 basin.
// 2026-08-17 source-gate audit: removed unused, incomplete virtual surfaces and
// the unrelated master-object aggregate. The object, player, world, and list
// owners now keep only proven fields and named polymorphic entries. World uses
// its proven virtual destructor; object-list load is the proven slot-0 method.
// This is a policy cleanup, not a compare-index or color-register probe.
// 2026-08-17 sa-45b09fe7-r1 focused tail pass (18 meaningful probes): direct
// byte player_id predicates, parameter-home index reuse, declaration and
// initialization order, signed/unsigned compare widths, real-local register
// hints, and Ghidra-shaped update order either widened the body or reproduced
// the 219B/37 basin. The direct byte forms widened to 227B/190; the hoisted,
// split, and typed real-local forms retained 219B/37. Restored the clean
// canonical source. No policy-valid source form selected ESI for owner and
// EDX for the 16-bit tail compare. The 37-byte hunk remains register coloring.

class RGE_Static_Object;
class RGE_Master_Static_Object;
class RGE_Player;
class RGE_Game_World;

class RGE_Object_List {
public:
    virtual void load(unsigned char flag, int file, RGE_Game_World* world);
    void* list;
    short number_of_objects;
    RGE_Static_Object* find_by_id(long id);
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x38];
    short player_num;
    char gap_3E[0x02];
    RGE_Player** players;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x24];
    RGE_Object_List* objects;
    RGE_Object_List* sleeping_objects;
    RGE_Object_List* doppleganger_objects;
    char gap_34[0x08];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short id;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();

    long id; // +0x04
    RGE_Master_Static_Object* master_obj; // +0x08; target does not dereference this field
    RGE_Player* owner; // +0x0C

    RGE_Static_Object* get_object_pointer(long id);
};

RGE_Static_Object* RGE_Static_Object::get_object_pointer(long id)
{
    RGE_Static_Object* object = 0;

    if (id >= 0) {
        object = this->owner->objects->find_by_id(id);
        if (object == 0) {
            object = this->owner->sleeping_objects->find_by_id(id);
            if (object == 0) {
                object = this->owner->doppleganger_objects->find_by_id(id);
                if (object == 0) {
                    long object_id = id;
                    RGE_Player* player = this->owner;
                    unsigned char player_index = 0;
                    RGE_Game_World* world = player->world;
                    if (world->player_num > 0) {
                        short compare_index = 0;
                        do {
                            if (compare_index != player->id) {
                                object = world->players[player_index]->objects->find_by_id(object_id);
                                if (object != 0) {
                                    return object;
                                }
                                object = this->owner->world->players[player_index]->sleeping_objects->find_by_id(object_id);
                                if (object != 0) {
                                    return object;
                                }
                                object = this->owner->world->players[player_index]->doppleganger_objects->find_by_id(object_id);
                                if (object != 0) {
                                    return object;
                                }
                            }
                            player = this->owner;
                            ++player_index;
                            compare_index = player_index;
                            world = player->world;
                        } while (compare_index < world->player_num);
                    }
                }
            }
        }
    }

    return object;
}
