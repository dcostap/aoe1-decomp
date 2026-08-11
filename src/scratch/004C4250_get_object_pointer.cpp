// VA: 004C4250 RGE_Static_Object::get_object_pointer
// PDB source: stat_obj.cpp lines 1978-2011
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

class RGE_Static_Object;
class RGE_Sprite;
class RGE_Master_Static_Object;
class RGE_Player;
class RGE_Game_World;

class RGE_Object_List {
public:
    RGE_Static_Object* find_by_id(long id);
};

class RGE_Game_World {
public:
    char gap_00[0x3C];
    short player_num;
    char gap_3E[0x02];
    RGE_Player** players;
};

class RGE_Player {
public:
    char gap_00[0x28];
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
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void check_damage_sprites();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void new_sprite(RGE_Sprite* sprite);
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();
    virtual void vfB4();
    virtual void vfB8();
    virtual void vfBC();
    virtual void vfC0();
    virtual void vfC4();
    virtual void vfC8();
    virtual void vfCC();
    virtual int explore_terrain(RGE_Player* player, unsigned char mode, int value);
    virtual void unexplore_terrain(RGE_Player* player, unsigned char mode, int value);

    char gap_04[0x08];
    RGE_Player* owner;

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
