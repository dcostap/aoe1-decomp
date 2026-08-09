// 00489030 RGE_RMM_Terrain_Generator::base_terrain_generate
// Baseline: period-plausible reconstruction from rmm_terr.cpp evidence.
// The local Map_Stack/terrain records use the proven 0x18/0x20 layouts; the
// attempt log below is updated only after an integrated checker probe.
// Attempt log:
// - Separate integer fairness-count lifetime from the later floating score;
//   this restored the ordered 35-call sequence and reduced the size gap.
// - A guarded hotspot-fairness loop was closer than the decompiler-shaped do-loop.
// - The retained initial clump loop is the guarded while form; do/infinite-loop
//   spellings duplicated the pop_stack site and added 50 bytes.
// - Materializing avoid_hot_spots was codegen-neutral.
// - Keep loc_stack.x as the horizontal bound and max_x as the row bound; this
//   is the best structural checkpoint (2240 vs 2204 bytes, 90.04% shape).
// - Passing y-field addresses for the stack records regressed; rolled back.
// - A union reusing the fairness slot for the later score regressed shape;
//   rolled back. Remaining mismatch is structural, beginning at the prologue.
//
// Session sa-c246dc4c-r1 (bounded continuation, budget 10):
// - SEMANTIC FIX: fair-extend third condition is search_map_rows[x][chance] < 0x1e
//   (original reads [esi+24h] unmasked), NOT map_row_offset tile terrain_type.
//   This alone moved diff 2036->2015 and flipped avoid_hot_spots into ebp.
// - check_terrain tests use `> 0` (clump/fair loops emit test al,al;jbe like the
//   original); grow loop uses `long ok` + `ok > 0` (test eax,eax;jle, ok kept in
//   eax into fig_chance, no stack spill).  This dropped the ok spill slot.
// - Removed the explicit `if (clumps > 0)` wrapper around the clump loop; the
//   while's own guard now matches the original single cmp/jle (was a duplicate
//   guard pair).  Big win: diff 2015->1655.
// - Split the horizontal bound into its own `long loc_stack_x` (+0x38) and the
//   list-head sentinel `Map_Stack loc_stack` (+0x3C); zero BOTH next and prev
//   before link_stack_randomly (original stores dwords at +0x4C and +0x50).
//   This restored frame 0xA54, the two zero stores, and head at +0x3C.
// - Tile stores use full member expressions (map_row_offset[x][chance].terrain_type)
//   so VC5 anchors the address at the +5 terrain byte like the original.
// - Negative evidence: declaration position of fStack_a4c (after fair_count,
//   before fair_count, or last), a union forcing the +0x18 slot share, and
//   base_area/loc_stack_x declaration order are ALL codegen-neutral or worse.
//   VC5's slot allocator here does not follow declaration order for this
//   function, so the score/index1 slot coloring could not be steered by
//   source ordering.
// Best state: diff 1761 (79.6%), shape 94.02%, exact-blocks 59.58%, size +8,
// frame 0xA54, 35/35 calls aligned.
// New worker context review: check_terrain's verified uchar/long call surface and
// link_stack_randomly's proven Map_Stack/base-module layout agree with this TU;
// no new ABI/layout fact justifies blind edits to this large generator.
// Remaining structural gap (next leads):
// 1) The float score still lands at +0x2C instead of reusing fair_count's +0x18
//    slot (original merges them; index1 keeps +0x24).  This shifts in_zone and
//    clump_size 4 bytes low (rebuilt +0x28/+0x24 vs original +0x2C/+0x28) and
//    drives most of the 70 positional spans.
// 2) The four tile-store sites emit `mov dl,cl; xor dl,bl` (a copy) instead of
//    the original's in-place `xor bl,cl` -- exactly +2 bytes x 4 = the +8 size
//    gap.  This looks linked to the score/index1 slot coloring (register
//    pressure around the grow loop), so fix (1) first, then re-check.
// 3) Minor: clump-guard lea/jle order and the zero-register (ebx vs edi) at the
//    link setup still differ with no size cost.

typedef unsigned char uchar;

extern "C" int __cdecl debug_rand(char* file, int line);

extern "C" double __cdecl sqrt(double value);
#pragma intrinsic(sqrt)

struct Map_Stack {
    long x;
    long y;
    float cost;
    float tot_cost;
    Map_Stack* next;
    Map_Stack* prev;
};

struct RGE_Terrain_Hot_Spots {
    long x;
    long y;
    long radius;
    long fade;
};

struct RGE_Terrain_Info_Line {
    long terrain_size;
    long terrain_generated;
    long terrain_type;
    long clumps;
    long spacing;
    long base_terrain_type;
    long clumpiness_factor;
    long avoid_hot_spots;
};

struct RGE_Terrain_Info {
    RGE_Terrain_Info_Line terrain[99];
    long terrain_num;
    RGE_Terrain_Hot_Spots hot_spots[99];
    long hot_spot_num;
};

struct RGE_Tile {
    short screen_xpos;
    short screen_ypos;
    uchar tile_type;
    uchar terrain_type : 5;
    uchar border_type : 4;
    uchar last_drawn_as;
    uchar last_drawn_shape;
    uchar draw_as;
    uchar draw_attribute;
    uchar last_drawn_shape2;
    char objects[12];
};

class RGE_Map;

class RGE_Random_Map_Module {
public:
    virtual uchar generate() = 0;

    RGE_Random_Map_Module* parent;
    void* list;
    RGE_Map* map;
    RGE_Tile** map_row_offset;
    long map_width;
    long map_height;
    float schedule;
    uchar* search_map;
    uchar** search_map_rows;
    Map_Stack* stack_array;
    Map_Stack** stack_offsets;

    void init_stack(Map_Stack* stack);
    void deinit_stack(Map_Stack* stack);
    Map_Stack* pop_stack(Map_Stack* head, long* x, long* y, float* cost);
    void push_stack(Map_Stack* list, long x, long y, float cost, float total_cost);
};

class RGE_Zone_Map {
public:
    uchar get_zone_info(long x, long y);
};

class RGE_RMM_Terrain_Generator : public RGE_Random_Map_Module {
public:
    RGE_Terrain_Info info;
    RGE_Zone_Map* map_zone;

    virtual uchar generate();
    void link_stack_randomly(Map_Stack* stack, uchar terrain);
    uchar check_terrain(uchar terrain, long x, long y, long radius, uchar avoid_terrain);
    void remove_area_from_lists(long x, long y, long radius);
    float fig_chance(long terrain, long x, long y, long factor);
    uchar base_terrain_generate(RGE_Terrain_Info_Line line);
};

uchar RGE_RMM_Terrain_Generator::base_terrain_generate(RGE_Terrain_Info_Line line)
{
    long x;
    long y;
    long chance;
    long fair_count;
    float fStack_a4c;
    uchar done;
    long local_a44;
    long index1;
    long clump_size;
    long in_zone;
    long max_y;
    long max_x;
    int hot_i;
    int stack_i;
    int fair_i;
    int scan_i;
    int cleanup_i;
    long loc_stack_x;
    Map_Stack loc_stack;
    uchar terrain_fairness_zones_visited[99];
    uchar terrain_fairness_zones[99];
    Map_Stack stack[99];

    // The original keeps the horizontal bound in a separate long (loc_stack_x)
    // and the list-head sentinel in loc_stack; max_x is the row bound.
    loc_stack_x = this->map_width - 1;
    in_zone = 0;
    max_x = this->map_height - 1;
    fair_count = 0;

    if (line.avoid_hot_spots == 2 && this->info.hot_spot_num > 0) {
        hot_i = 0;
        RGE_Terrain_Hot_Spots* hot_spot = this->info.hot_spots;
        do {
            terrain_fairness_zones[hot_i] = this->map_zone->get_zone_info(hot_spot->x, hot_spot->y);
            terrain_fairness_zones_visited[hot_i] = 0;
            ++hot_i;
            ++hot_spot;
        } while (hot_i < this->info.hot_spot_num);
    }

    for (stack_i = 0; stack_i < 99; ++stack_i) {
        this->init_stack(&stack[stack_i]);
    }

    loc_stack.next = 0;
    loc_stack.prev = 0;
    this->link_stack_randomly(&loc_stack, (uchar)line.base_terrain_type);

    local_a44 = (long)sqrt((double)line.terrain_size / (double)line.clumps);
    local_a44 += local_a44;
    if (local_a44 < 2) {
        local_a44 = 2;
    }

    clump_size = 0;
    Map_Stack* stack_ptr = stack;
    while (clump_size < line.clumps) {
            if (this->pop_stack(&loc_stack, &chance, &x, (float*)&max_y) == 0) {
                break;
            }

            if ((this->map_row_offset[x][chance].terrain_type & 0x1f) == line.base_terrain_type &&
                this->check_terrain((uchar)line.terrain_type, chance, x,
                    line.spacing, (uchar)line.base_terrain_type) > 0 &&
                (line.avoid_hot_spots == 0 || this->search_map_rows[x][chance] == 0)) {
                this->remove_area_from_lists(chance, x, local_a44);

                this->map_row_offset[x][chance].terrain_type = (uchar)line.terrain_type;

                if (chance > 0) {
                    this->push_stack(stack_ptr, chance - 1, x, 0.0f, 0.0f);
                }
                if (x > 0) {
                    this->push_stack(stack_ptr, chance, x - 1, 0.0f, 0.0f);
                }
                if (chance < this->map_width - 1) {
                    this->push_stack(stack_ptr, chance + 1, x, 0.0f, 0.0f);
                }
                if (x < this->map_height - 1) {
                    this->push_stack(stack_ptr, chance, x + 1, 0.0f, 0.0f);
                }

                ++in_zone;
                ++clump_size;
                ++stack_ptr;

                uchar zone = this->map_zone->get_zone_info(chance, x);
                if (line.avoid_hot_spots == 2) {
                    fair_i = 0;
                    if (this->info.hot_spot_num > 0) {
                        do {
                            if (terrain_fairness_zones[fair_i] == zone &&
                                terrain_fairness_zones_visited[fair_i] == 0) {
                                terrain_fairness_zones_visited[fair_i] = 1;
                                ++fair_count;
                            }
                            ++fair_i;
                        } while (fair_i < this->info.hot_spot_num);
                    }
                }
            }
        }

    if (line.avoid_hot_spots == 2 && fair_count < this->info.hot_spot_num) {
        Map_Stack* stack_ptr = &stack[clump_size];
        while (fair_count < this->info.hot_spot_num) {
            if (this->pop_stack(&loc_stack, &chance, &x, (float*)&max_y) == 0) {
                break;
            }

            if ((this->map_row_offset[x][chance].terrain_type & 0x1f) == line.base_terrain_type &&
                this->check_terrain((uchar)line.terrain_type, chance, x,
                    line.spacing, (uchar)line.base_terrain_type) > 0 &&
                this->search_map_rows[x][chance] < 0x1e) {
                uchar zone = this->map_zone->get_zone_info(chance, x);
                fair_i = 0;
                if (this->info.hot_spot_num > 0) {
                    do {
                        if (terrain_fairness_zones[fair_i] == zone &&
                            terrain_fairness_zones_visited[fair_i] == 0) {
                            break;
                        }
                        ++fair_i;
                    } while (fair_i < this->info.hot_spot_num);
                }

                if (fair_i != this->info.hot_spot_num) {
                    ++fair_count;
                    terrain_fairness_zones_visited[fair_i] = 1;
                    this->remove_area_from_lists(chance, x, local_a44);

                    this->map_row_offset[x][chance].terrain_type = (uchar)line.terrain_type;

                    if (chance > 0) {
                        this->push_stack(stack_ptr, chance - 1, x, 0.0f, 0.0f);
                    }
                    if (x > 0) {
                        this->push_stack(stack_ptr, chance, x - 1, 0.0f, 0.0f);
                    }
                    if (chance < this->map_width - 1) {
                        this->push_stack(stack_ptr, chance + 1, x, 0.0f, 0.0f);
                    }
                    if (x < this->map_height - 1) {
                        this->push_stack(stack_ptr, chance, x + 1, 0.0f, 0.0f);
                    }

                    ++in_zone;
                    ++clump_size;
                    ++stack_ptr;
                }
            }
        }
    }

    do {
        done = 1;
        if (clump_size > 0) {
            Map_Stack* stack_ptr = stack;
            local_a44 = clump_size;
            do {
                if (in_zone < line.terrain_size &&
                    this->pop_stack(stack_ptr, &chance, &x, (float*)&max_y) != 0) {
                    done = 0;

                    if (line.avoid_hot_spots == 0 ||
                        (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_terr.cpp", 0x1c6) * 100) / 0x7fff >=
                            this->search_map_rows[x][chance]) {
                        RGE_Tile* tile = &this->map_row_offset[x][chance];
                        long ok = this->check_terrain((uchar)line.terrain_type, chance, x,
                            line.spacing, (uchar)line.base_terrain_type);
                        if ((tile->terrain_type & 0x1f) == line.base_terrain_type && ok > 0) {
                            fStack_a4c = this->fig_chance(ok, chance, x, line.clumpiness_factor);
                            if (line.avoid_hot_spots != 0) {
                                index1 = this->search_map_rows[x][chance];
                                fStack_a4c += (float)index1;
                            }

                            tile->terrain_type = (uchar)line.terrain_type;

                            if (chance > 0 &&
                                (tile[-1].terrain_type & 0x1f) == line.base_terrain_type) {
                                index1 = (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_terr.cpp", 0x1d5) * 100) / 0x7fff;
                                this->push_stack(stack_ptr, chance - 1, x, 0.0f,
                                    (float)index1 + fStack_a4c);
                            }
                            if (chance < loc_stack_x &&
                                (tile[1].terrain_type & 0x1f) == line.base_terrain_type) {
                                index1 = (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_terr.cpp", 0x1d7) * 100) / 0x7fff;
                                this->push_stack(stack_ptr, chance + 1, x, 0.0f,
                                    (float)index1 + fStack_a4c);
                            }
                            if (x > 0 &&
                                (((RGE_Tile*)((char*)tile - this->map_width * 0x18))->terrain_type & 0x1f) ==
                                    line.base_terrain_type) {
                                index1 = (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_terr.cpp", 0x1d9) * 100) / 0x7fff;
                                this->push_stack(stack_ptr, chance, x - 1, 0.0f,
                                    (float)index1 + fStack_a4c);
                            }
                            if (x < max_x &&
                                (((RGE_Tile*)((char*)tile + this->map_width * 0x18))->terrain_type & 0x1f) ==
                                    line.base_terrain_type) {
                                index1 = (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_terr.cpp", 0x1db) * 100) / 0x7fff;
                                this->push_stack(stack_ptr, chance, x + 1, 0.0f,
                                    (float)index1 + fStack_a4c);
                            }
                            ++in_zone;
                        }
                    }
                }
                ++stack_ptr;
                --local_a44;
            } while (local_a44 != 0);
        }
    } while (done == 0);

    if (line.clumps > 0) {
        Map_Stack* stack_ptr = stack;
        local_a44 = line.clumps;
        do {
            while (this->pop_stack(stack_ptr, &chance, &x, (float*)&max_y) != 0) {
                RGE_Tile* tile = &this->map_row_offset[x][chance];
                if ((chance > 0 &&
                    (tile[-1].terrain_type & 0x1f) == (uchar)line.terrain_type &&
                    chance < loc_stack_x &&
                    (tile[1].terrain_type & 0x1f) == (uchar)line.terrain_type) ||
                    (x > 0 &&
                    (((RGE_Tile*)((char*)tile - this->map_width * 0x18))->terrain_type & 0x1f) == (uchar)line.terrain_type &&
                    max_x < x &&
                    (((RGE_Tile*)((char*)tile + this->map_width * 0x18))->terrain_type & 0x1f) == (uchar)line.terrain_type)) {
                    tile->terrain_type = (uchar)line.terrain_type;
                }
            }
            ++stack_ptr;
            --local_a44;
        } while (local_a44 != 0);
    }

    for (cleanup_i = 0; cleanup_i < 99; ++cleanup_i) {
        this->deinit_stack(&stack[cleanup_i]);
    }
    return 1;
}
