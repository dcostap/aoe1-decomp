// 00486C40 RGE_RMM_Object_Generator::place_cluster
// Clean reset: typed random-map stack, search rows, object-info fields, and
// master-object alignment/check/placement calls follow the executable.
// Baseline: canonical ownership and period-plausible cluster expansion source.
// Attempt log:
// - Restored stack-offset, search-row, and world fields at +2c, +24, and +30.
// - Restored the exact group-area clamp, count variance shift, alignment call,
//   placement check, and four typed neighbor pushes.
// - Explicit stack-link initialization and aggregate zero initialization were
//   tested, but they worsened the prologue and were removed.
// - Player-local and while-loop spellings were codegen duplicates.
// - Main audit removed a register hint and decompiler-style subtraction of a
//   negative half. Ordinary local and += spellings preserve the same behavior.
// - Named the binary-observed pop result and used one natural pop/count loop;
//   this reached exact size, 19/19 calls, and 649 differing bytes.
//   The checker now reports BLOCK SHAPE AND LIVENESS.
// - Diagnostic explicit next/prev zero stores matched the extra early stores
//   but widened positional drift to 895-897 bytes; restored the clean source.
// - Zero-value, self-alias, row-pointer, declaration-order, and master-scope
//   probes were duplicates or worse; retained the named-node reconstruction.
// - Ghidra's initial stack-store lead was isolated: next-only moved the first
//   mismatch to the second store, while pair and chained forms colored zero in
//   EBP and widened drift to 895 bytes; no form reproduced EBX zero.
// - A focused seven-form initialization lab and a proven base-class context
//   were diagnostic only; the clean typed source remains the best reconstruction.
// - Managed claim probes 1-20 tested stack-link forms, parameter-home reuse,
//   declaration scope, flag types, helper references, and local aliases.
// - The best natural source uses a distinct x_start local for the lower bound
//   and the reviewed Map_Stack reference ABI. It reaches 648 differing bytes,
//   92.33% shape, exact size, and 19/19 aligned calls.
// - The x_start form emits the same bytes as direct reuse of the second scalar
//   parameter home. This supports a compiler coalescing explanation, not a
//   requirement for parameter mutation in source.
// - Explicit next/prev stores, aggregate zero initialization, named zero
//   locals, float zone, byte equality-to-one, and player aliases were worse or
//   codegen duplicates. No exact result was found.

extern "C" int __cdecl debug_rand(char* file, int line);
extern "C" long __cdecl ftol(float);

struct Map_Stack {
    long x;
    long y;
    float cost;
    float tot_cost;
    Map_Stack* next;
    Map_Stack* prev;
};

struct RGE_Object_Info_Line {
    long obj_id;
    long terrain;
    unsigned char group_flag;
    unsigned char scale_flag;
    unsigned char gap_0a[2];
    long object_number_per_group;
    long object_number_varience;
    long number_of_groups;
    long group_area;
    long player_id;
    long land_id;
    long land_inner_radius;
    long land_outer_radius;
    long object_exclusion_zone;
};

class RGE_Player;
class RGE_Game_World;

class RGE_Master_Static_Object {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual unsigned char check_placement(RGE_Player*, float, float, int*,
        unsigned char, unsigned char, unsigned char, unsigned char,
        unsigned char, unsigned char);
    virtual unsigned char alignment(float&, float&, RGE_Game_World*,
        unsigned char);

    char gap_04[0x30 - 4];
    float radius_x;
    float radius_y;
};

class RGE_Player {
public:
    virtual void p00();
    virtual void p01();
    virtual void p02();
    virtual void p03();
    virtual void p04();
    virtual void p05();
    virtual void p06();
    virtual void p07();
    virtual void p08();
    virtual void p09();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual void p13();
    virtual void p14();
    virtual void p15();
    virtual void p16();
    virtual void p17();
    virtual void p18();
    virtual void p19();
    virtual void p20();
    virtual void p21();
    virtual void p22();
    virtual void p23();
    virtual void p24();
    virtual void p25();
    virtual void p26();
    virtual void p27();
    virtual void p28();
    virtual void p29();
    virtual void p30();
    virtual void p31();
    virtual void p32();
    virtual void p33();
    virtual void p34();
    virtual void p35();
    virtual void p36();
    virtual void place_object(long, float, float, int, int);

    char gap_04[0x24 - 4];
    RGE_Master_Static_Object** master_objects;
};

class RGE_RMM_Object_Generator {
public:
    char gap_00[0x10];
    void* map;
    long width;
    long height;
    char gap_1c[4];
    char gap_20[4];
    unsigned char** search_map_rows;
    Map_Stack* stack_array;
    Map_Stack** stack_offsets;
    RGE_Game_World* world;

    void init_stack(Map_Stack& stack);
    void deinit_stack(Map_Stack& stack);
    void add_stack_node(Map_Stack& target, Map_Stack& node);
    Map_Stack* pop_stack(Map_Stack& head, long& x, long& y, float& cost);
    void push_stack(Map_Stack& list, long x, long y, float cost,
        float total_cost);
    void place_cluster(RGE_Object_Info_Line& info, long x, long y,
        RGE_Player* player);
};

void RGE_RMM_Object_Generator::place_cluster(RGE_Object_Info_Line& info,
    long x, long y, RGE_Player* player)
{
    long tile_y;
    long x1;
    long y0;
    long y1;
    long x_start;
    long zone;
    long count;
    float tile_x;
    float tile_y_float;
    float cost;
    Map_Stack* node;

    Map_Stack obj_stack;
    this->init_stack(obj_stack);
    this->add_stack_node(obj_stack, this->stack_offsets[y][x]);

    y1 = y - info.group_area;
    y0 = x + info.group_area;
    zone = y + info.group_area;
    x_start = x - info.group_area;
    if (x_start < 0) x_start = 0;
    if (y1 < 0) y1 = 0;
    if (y0 >= this->width) y0 = this->width - 1;
    if (zone >= this->height) zone = this->height - 1;

    for (x1 = y1; x1 <= zone; ++x1) {
        for (tile_y = x_start; tile_y <= y0; ++tile_y) {
            this->search_map_rows[x1][tile_y] = 1;
        }
    }

    count = info.object_number_per_group;
    long variance = info.object_number_varience;
    count += (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_obj.cpp", 0x256) *
        (variance << 1)) / 0x7fff - variance;
    if (count < 1) count = 1;

    node = this->pop_stack(obj_stack, tile_y, x1, cost);
    while (node != 0 && count > 0) {
            RGE_Master_Static_Object* master =
                player->master_objects[info.obj_id];
            tile_y_float = (float)tile_y;
            tile_x = (float)x1;
            if (master->radius_x - (float)(short)(int)master->radius_x > 0.0f) {
                tile_y_float += 0.5f;
            }
            if (master->radius_y - (float)(short)(int)master->radius_y > 0.0f) {
                tile_x += 0.5f;
            }

            master->alignment(tile_y_float, tile_x, this->world, 1);
            if (master->check_placement(player, tile_y_float, tile_x,
                    0, 0, 1, 1, 1, 0, 1) == 0) {
                player->place_object(info.obj_id, tile_y_float, tile_x, 0, 1);
                --count;
                this->search_map_rows[x1][tile_y] = 0;

                if (tile_y > x_start &&
                    this->search_map_rows[x1][tile_y - 1] != 0) {
                    this->push_stack(obj_stack, tile_y - 1, x1, 0.0f,
                        (float)debug_rand(
                            "C:\\msdev\\work\\age1_x1\\rmm_obj.cpp", 0x270));
                }
                if (tile_y < y0 &&
                    this->search_map_rows[x1][tile_y + 1] != 0) {
                    this->push_stack(obj_stack, tile_y + 1, x1, 0.0f,
                        (float)debug_rand(
                            "C:\\msdev\\work\\age1_x1\\rmm_obj.cpp", 0x273));
                }
                if (x1 > y1 &&
                    this->search_map_rows[x1 - 1][tile_y] != 0) {
                    this->push_stack(obj_stack, tile_y, x1 - 1, 0.0f,
                        (float)debug_rand(
                            "C:\\msdev\\work\\age1_x1\\rmm_obj.cpp", 0x276));
                }
                if (x1 < zone &&
                    this->search_map_rows[x1 + 1][tile_y] != 0) {
                    this->push_stack(obj_stack, tile_y, x1 + 1, 0.0f,
                        (float)debug_rand(
                            "C:\\msdev\\work\\age1_x1\\rmm_obj.cpp", 0x279));
                }
            }
        node = this->pop_stack(obj_stack, tile_y, x1, cost);
    }

    this->deinit_stack(obj_stack);
}
