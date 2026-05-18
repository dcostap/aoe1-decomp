// 00486C40 RGE_RMM_Object_Generator::place_cluster
// Attempt log:
// try 1: packet-grounded reconstruction using rmm_obj sibling stubs. Models occupancy marking, randomized group count, stack pop loop, float half-tile adjustment from object radii, can_place/place_object, neighbor expansion, cleanup. Compiled too short (912B vs 974B).
// try 2: modeled initial init_stack/add_stack_node flow with map node address from [this+2c][x] + y*24.
// try 3: modeled exclusion rectangle clamp from info.radius against width/height and byte_rows fill to 1.
// try 4: modeled cluster count as base_count + randomized +/- variance, minimum 1, using debug_rand at rmm_obj.cpp:598.
// try 5: modeled pop_stack loop with object master lookup, radius fractional half-tile adjustment, can_place/place_object sequence.
// try 6: modeled success path clearing byte_rows[cur_x][cur_y] and four-neighbor expansion guarded by occupancy with debug_rand line IDs 624/627/630/633.
// try 7: tried natural member virtual surfaces for can_place/place_object and local structs to keep call shapes close to sibling place_objects attempts.
// try 8: removed accidental duplicate can_place probe; size became 880B, confirming original has additional stack/helper topology rather than duplicate behavior.
// try 9: corrected final deinit_stack to use the initialized stack object, not pop output; still too short.
// try 10: temporary diagnostic extra remove_area calls still compiled too short (928B) and were removed; no byte-compare reached.
// GIVEUP blockers: exact Map_Stack/local overlap layout, correct helper signatures for add_stack_node/pop_stack/remove_area_from_lists (argument order differs), natural one-call can_place topology, and byte-map coordinate naming needed to preserve original stack slots/registers. No inline asm used; no accepted_drift proposal.

class RGE_Player;
extern "C" int __cdecl debug_rand(char*, int);
extern "C" long __cdecl ftol(float);
extern char rmm_obj_cpp_path[];
extern float FLOAT_00571edc;
extern float FLOAT_00571ee0;

struct Map_Stack { int prev; int next; char pad[0x10]; };
struct RGE_Object_Info_Line {
    int obj_id; int terrain; unsigned char group_flag; char pad09[3]; int a0c; int variance; int base_count; char pad14[4]; int radius;
    char pad1c[0x10]; int object_exclusion_zone;
};
class RGE_Master_Static_Object {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual unsigned char can_place(RGE_Player*, float, float, int, int, int, int, int, int, int);
    char pad04[0x30-4]; float radius_x; float radius_y;
};
class RGE_Player {
public:
    virtual void p00(); virtual void p01(); virtual void p02(); virtual void p03(); virtual void p04(); virtual void p05(); virtual void p06(); virtual void p07();
    virtual void p08(); virtual void p09(); virtual void p10(); virtual void p11(); virtual void p12(); virtual void p13(); virtual void p14(); virtual void p15();
    virtual void p16(); virtual void p17(); virtual void p18(); virtual void p19(); virtual void p20(); virtual void p21(); virtual void p22(); virtual void p23();
    virtual void p24(); virtual void p25(); virtual void p26(); virtual void p27(); virtual void p28(); virtual void p29(); virtual void p30(); virtual void p31();
    virtual void p32(); virtual void p33(); virtual void p34(); virtual void p35(); virtual void p36();
    virtual void place_object(int obj_id, float x, float y, int, int);
    char pad04[0x24-4]; RGE_Master_Static_Object** master_objects;
};

class RGE_RMM_Object_Generator {
public:
    char pad00[0x14]; int width; int height; char pad1c[4]; unsigned char** byte_rows; char pad28[4]; void*** info_rows; RGE_Player* player;
    void init_stack(Map_Stack* s);
    void deinit_stack(Map_Stack* s);
    void add_stack_node(Map_Stack* s, void* node);
    int pop_stack(Map_Stack* s, int* out_y, int* out_x, Map_Stack* out_stack);
    void remove_area_from_lists(long left, long right, long y);
    void place_cluster(RGE_Object_Info_Line& info, long y, long x, RGE_Player* player);
};

void RGE_RMM_Object_Generator::place_cluster(RGE_Object_Info_Line& info, long y, long x, RGE_Player* player)
{
    int cur_x;
    int cur_y;
    int next_x;
    int next_y;
    float fx;
    float fy;
    int x0, y0, x1, y1;
    int count;
    Map_Stack stack;
    Map_Stack popped;

    this->init_stack(&stack);
    this->add_stack_node(&popped, (char*)this->info_rows[x] + y * 24);

    int r = info.radius;
    x0 = y - r;
    y0 = x - r;
    x1 = y + r;
    y1 = x + r;
    if (x0 < 0) x0 = 0;
    if (y0 < 0) y0 = 0;
    if (x1 >= this->width) x1 = this->width - 1;
    if (y1 >= this->height) y1 = this->height - 1;
    for (cur_x = y0; cur_x <= y1; ++cur_x) {
        for (cur_y = x0; cur_y <= x1; ++cur_y) {
            this->byte_rows[cur_x][cur_y] = 1;
        }
    }

    count = info.base_count + (debug_rand(rmm_obj_cpp_path, 598) * (info.variance + info.variance) / 0x7fff - info.variance);
    if (count < 1) count = 1;

    if (this->pop_stack(&stack, &cur_x, &cur_y, &popped)) {
        while (count > 0) {
            RGE_Master_Static_Object* master = player->master_objects[info.obj_id];
            fx = (float)cur_y;
            fy = (float)cur_x;
            int ix = (short)(int)master->radius_x;
            if (master->radius_x - (float)ix > 0.0f) fx = fx + 0.5f;
            int iy = (short)(int)master->radius_y;
            if (master->radius_y - (float)iy > 0.0f) fy = fy + 0.5f;
            if (!master->can_place(player, fx, fy, 0, 0, 1, 1, 1, 0, 1)) {
                player->place_object(info.obj_id, fx, fy, 0, 1);
                --count;
                this->byte_rows[cur_x][cur_y] = 0;
                if (cur_y > x0 && this->byte_rows[cur_x][cur_y - 1]) {
                    this->remove_area_from_lists(cur_y - 1, cur_x, debug_rand(rmm_obj_cpp_path, 624));
                }
                if (cur_y < x1 && this->byte_rows[cur_x][cur_y + 1]) {
                    this->remove_area_from_lists(cur_y + 1, cur_x, debug_rand(rmm_obj_cpp_path, 627));
                }
                if (cur_x > y0 && this->byte_rows[cur_x - 1][cur_y]) {
                    this->remove_area_from_lists(cur_y, cur_x - 1, debug_rand(rmm_obj_cpp_path, 630));
                }
                if (cur_x < y1 && this->byte_rows[cur_x + 1][cur_y]) {
                    this->remove_area_from_lists(cur_y, cur_x + 1, debug_rand(rmm_obj_cpp_path, 633));
                }
            }
            if (!this->pop_stack(&stack, &cur_x, &cur_y, &popped)) break;
        }
    }
    this->deinit_stack(&stack);
}
