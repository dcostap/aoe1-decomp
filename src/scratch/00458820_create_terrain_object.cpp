// VA: 00458820 RGE_Map::create_terrain_object
// PDB: map.cpp:1989-2092
//
// Attempt log:
// - Replaced the earlier raw-offset/vtable scaffold with the period map.cpp
//   ownership model: RGE_Map terrain records, row-offset tiles, object nodes,
//   RGE_Player master_objects, and the real master/object virtual surfaces.
// - The world parameter is present in the ABI but is not consumed by the
//   original body; placement calls receive the player as their first argument.
// - The initial clean reconstruction preserves the two terrain-object cleanup
//   paths, the replacement-terrain compatibility scan, and the typed density /
//   placement loop.  First checker run is the session baseline.
// - baseline: clean typed source was 839 bytes/frame 0x20; all 10 calls aligned
//   but the local/control-flow basin was broad.
// - paired density/placement cursors and a short terrain result reduced output
//   to 757-761 bytes/frame 0x14 and aligned the outer pointer loop; assigning
//   placement before density recovered the oracle's address/store order.
// - direct `terrain_types[new_terrain].obj_types[]` restored the natural
//   replacement-table ownership and exact output size (794 bytes), improving
//   shape to 71.54%; the pointer alias was kept only as diagnostic evidence.
// - polymorphic map/player declarations, owner-compare reversal, scan-player
//   alias, do/while node spelling, and top-scoped node were neutral or worse.
//   The final clean candidate keeps the named typed surfaces and no raw vtable
//   plumbing; the density[-30] access is retained as the binary-proven adjacent
//   obj_types/obj_density cursor topology.
// - A typed RGE_Tile_Set* terrain-record alias for the initial count and paired
//   arrays grew output to 795 bytes and worsened positional diff to 704; rolled back.
// - Matched the original place ABI and coordinate order: vslot 0x18 takes
//   player, local_c, x, and one zero argument.  This recovered one exact block.
// - bounded pause: calls are 10/10 aligned and size is exact, but the first
//   mismatch remains the prologue/frame (rebuilt frame 0x14 vs 0x10), followed
//   by broad local/register and shifted block drift. Not accepted-drift-safe.
//
// Revisit sa-8632da43-r1:
// - The direct replacement-table scan keeps the 794-byte size but needs a
//   0x14-byte frame.  A typed short* replacement_types alias removes that
//   frame slot and gives a 0x10-byte frame with 241 instructions.
// - The alias candidate has 10/10 ordered calls and 49.38% exact-block
//   coverage.  Its best check is 686 differing bytes and 759 effective bytes.
// - A natural short-circuit replacement scan improves loop shape but removes
//   one required cleanup call.  It was rejected.
// - Twenty-five source and context probes, plus a six-variant declaration and
//   width lab, did not recover the initial register colors or coordinate FPU
//   homes.  The remaining drift is structural and not accepted-drift-safe.
//
// Revisit sa-0ec82117-r1:
// - The clean pointer-alias candidate remains the smallest checked source with
//   the exact frame and all 10 ordered calls: 759 effective bytes, 686 diff.
// - Rechecked declaration order, function-scope mode and coordinate locals,
//   staged coordinate arithmetic, max-id operand order, a tile alias, and a
//   top-tested node loop. These were duplicates or worse and were discarded.
// - The short-circuit replacement scan gives 742 bytes and 50.62% block
//   coverage, but it removes a target cleanup CFG block. It is not retained.
// - The first structural divergence is +0x3B: the executable carries the
//   initial count in DX and the terrain base in ECX. The clean source emits BP
//   and EDX. The next useful lead is the original map.cpp local lifetime or TU
//   context, not metric-only register steering.

extern "C" int __cdecl debug_rand(char*, int);

#ifndef MAP_CONTEXT_H
class RGE_Player;
class RGE_Game_World;
class RGE_Master_Static_Object;
class RGE_Static_Object;

class RGE_Object_Node {
public:
    RGE_Static_Object* node;
    RGE_Object_Node* next;
};

class RGE_Object_List {
public:
    void* vtable_ptr;
    RGE_Object_Node* list;
    short number_of_objects;
    char gap_0A[2];
};

class RGE_Tile {
public:
    char gap_00[0xC];
    RGE_Object_List objects;
};

class RGE_Master_Static_Object {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void place(RGE_Player*, float, float, int);
    virtual void vf1C();
    virtual unsigned char can_place(RGE_Player*, float, float, int, int, int, int, int, int, int);

    char gap_04[0x0C];
    short id;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
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
    virtual void destroy_obj();

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x78];
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x20];
    RGE_Master_Static_Object** master_objects;
};

class RGE_Tile_Set {
public:
    char gap_00[0xFE];
    short obj_types[30];
    short obj_density[30];
    unsigned char obj_placement_flag[30];
    short num_obj_type;
    char gap_196[2];
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    char gap_04[0x88];
    RGE_Tile_Set terrain_types[32];
    char gap_338C[0x5A00];
    RGE_Tile** map_row_offset;

    unsigned char get_terrain(short, short);
    void create_terrain_object(RGE_Player*, RGE_Game_World*, short, short,
                               short, int, int, int);
};

#endif

void RGE_Map::create_terrain_object(RGE_Player* player, RGE_Game_World* /*world*/,
                                    short row, short col, short new_terrain,
                                    int remove_now, int min_id, int max_id)
{
    float local_c = 0.0f;
    float x = 0.0f;
    short terrain = (short)this->get_terrain(col, row);
    short num_obj_type = this->terrain_types[terrain].num_obj_type;
    RGE_Object_Node* node;
    RGE_Static_Object* object;
    short object_id;

    if (num_obj_type > 0) {
        node = this->map_row_offset[row][col].objects.list;
        if (node != 0) {
            do {
            object = node->node;
            node = node->next;

            object_id = object->master_obj->id;
            if (object->owner == player &&
                (object_id < min_id || object_id > max_id)) {
                    if (new_terrain < 0) {
                        if (remove_now != 0) {
                            if (object != 0)
                                delete object;
                        } else {
                            object->destroy_obj();
                        }
                    } else {
                        short replacement_count =
                            this->terrain_types[new_terrain].num_obj_type;
                        if (replacement_count >= 0) {
                            short* replacement_types =
                                this->terrain_types[new_terrain].obj_types;
                            do {
                                if (replacement_types[replacement_count] == object_id)
                                    break;
                                --replacement_count;
                            } while (replacement_count >= 0);

                            if (replacement_count >= 0) {
                                if (remove_now != 0) {
                                    if (object != 0)
                                        delete object;
                                } else {
                                    object->destroy_obj();
                                }
                            }
                        }
                    }
            }
            } while (node != 0);
        }

        if (num_obj_type > 0) {
            unsigned char* placement =
                this->terrain_types[terrain].obj_placement_flag;
            short* density = this->terrain_types[terrain].obj_density;
            int remaining = (int)num_obj_type;
            do {
                short object_type = density[-30];
                if (object_type != -1) {
                    short chance = *density;
                    RGE_Master_Static_Object* master =
                        player->master_objects[object_type];
                    unsigned char mode = *placement;

                    if (master != 0 && chance > 0) {
                        int chance_left = (int)chance;
                        do {
                            switch (mode) {
                            case 0:
                                local_c = (float)(int)col -
                                    (float)debug_rand("C:\\msdev\\work\\age1_x1\\map.cpp", 0x813) *
                                    -3.051851e-05f;
                                x = (float)(int)row -
                                    (float)debug_rand("C:\\msdev\\work\\age1_x1\\map.cpp", 0x814) *
                                    -3.051851e-05f;
                                break;
                            case 1:
                                local_c = (float)(int)col - -0.5f;
                                x = (float)(int)row - -0.5f;
                                break;
                            }

                            int place_it;
                            if (chance < 1000) {
                                int random_value = debug_rand(
                                    "C:\\msdev\\work\\age1_x1\\map.cpp", 0x820);
                                place_it = (random_value * 1000) / 0x7fff < chance_left;
                            } else {
                                place_it = 1;
                            }

                            if (place_it) {
                                if (!master->can_place(player, local_c, x,
                                                       0, 0, 1, 0, 1, 0, 1))
                                    master->place(player, local_c, x, 0);
                            }

                            chance -= 1000;
                            chance_left -= 1000;
                        } while (chance > 0);
                    }
                }

                ++density;
                ++placement;
                --remaining;
            } while (remaining != 0);
        }
    }
}
