// 00486A60 RGE_RMM_Object_Generator::place_group (rmm_obj.cpp:514-556)
// Attempt log:
// 1: Natural decompiler-shaped implementation: 75.59% diff; frame 0x24 not 0x2c, master vcall slot +10 not +20, FPU expressions over-combined.
// 2: Map_Stack 0x18 fixed frame and vcall slot; diff 74.52%, first mismatch random math because count/variance in EDI/EBP swapped.
// 3: Register count/load variance first only swapped to EBP=variance, EDI=count; not useful.
// 4: Register variance count-first still EDI=count/EBP=variance; expression shape wrong (`imul ecx,ebp; shl ecx`).
// 5: Split range/delta locals: no codegen change for random multiply.
// 6: Direct while(pop&&count>0) improved edit diff to 29.98%; loop layout near original, first mismatch random multiply `imul+shl` vs `lea+imul`.
// 7: Self-add range: no change.
// 8: Volatile floats worsened frame/codegen badly (76.66%, first mismatch frame); rolled back.
// 9: `zone < radius` shortened function to 464 bytes; rolled back.
// 10: `radius-zone > 0.0f` worsened edit diff to 31.26%; rolled back.
// 11: Long range temp no change.
// 12: Swapped multiply operands: no change.
// 13: Making the radius truncation scratch an int (rather than a float) restored the
//     original fild/movsx/fsubr/fcomp/test topology, exact size, and 123-byte aligned run.
// 14: Five focused random-count source variants (including doubled expressions,
//     separate temporaries, and *2 spelling) produced only three codegen groups;
//     none emitted the original LEA-before-IMUL. Compound versus direct self-add was
//     also a duplicate. The variant lab was diagnostic only and did not replace this source.
// 15: Restoring the PDB char* debug_rand ABI was a codegen duplicate.
// 16: A focused six-form random-math lab found an exact natural source form:
//     shift the named variance left by one before the debug_rand multiply.
//     This emits the original LEA-before-IMUL block and the full function matches.
// 17: ABI audit replaced the fake Map_Stack output cast with the proven
//     pop_stack(long*, long*, float*) surface. The safe typed source remains exact.
// The typed ownership, frame, stack homes, loop/call topology, and radius/FPU
// sequence now match exactly. The shift is a period-plausible integer doubling
// form and is retained as the canonical source reconstruction.

extern "C" int __cdecl debug_rand(char*, int);

#if !defined(RMM_OBJ_TU_COMBINED_CONTEXT)
struct Map_Stack { char data[0x18]; };
struct RGE_Tile { char gap[5]; unsigned char terrain; char rest[18]; };
struct RGE_Object_Info_Line {
    int obj_id;
    int terrain;
    int pad08;
    int object_number_per_group;
    int object_number_varience;
    int pad14;
    int group_area;
};

class RGE_Player;
class RGE_Master_Static_Object {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual unsigned char can_place(RGE_Player*, float, float, int, int, int, int, int, int, int);
    char pad04[0x30-4];
    float radius_x;
    float radius_y;
};

class RGE_Player {
public:
    virtual void p00(); virtual void p01(); virtual void p02(); virtual void p03();
    virtual void p04(); virtual void p05(); virtual void p06(); virtual void p07();
    virtual void p08(); virtual void p09(); virtual void p10(); virtual void p11();
    virtual void p12(); virtual void p13(); virtual void p14(); virtual void p15();
    virtual void p16(); virtual void p17(); virtual void p18(); virtual void p19();
    virtual void p20(); virtual void p21(); virtual void p22(); virtual void p23();
    virtual void p24(); virtual void p25(); virtual void p26(); virtual void p27();
    virtual void p28(); virtual void p29(); virtual void p30(); virtual void p31();
    virtual void p32(); virtual void p33(); virtual void p34(); virtual void p35();
    virtual void p36();
    virtual void place_object(int obj_id, float x, float y, int, int);
    char pad04[0x24-4];
    RGE_Master_Static_Object** master_objects;
};

class RGE_RMM_Object_Generator {
public:
    char pad00[0x10];
    RGE_Tile** map;

    void init_stack(Map_Stack* s);
    void deinit_stack(Map_Stack* s);
    void make_placement_stack(Map_Stack* s, long x, long y, int unk, int area);
    Map_Stack* pop_stack(Map_Stack* s, long* out_col, long* out_x, float* out_cost);
    void place_group(RGE_Object_Info_Line& info, long x, long y, RGE_Player* player);
};
#endif

void RGE_RMM_Object_Generator::place_group(RGE_Object_Info_Line& info, long px, long py, RGE_Player* player)
{
    long x;
    long col;
    float cost;
    RGE_RMM_Object_Generator* self;
    int zone;
    float fx;
    float fy;
    Map_Stack obj_stack;

    self = this;
    init_stack(&obj_stack);
#if defined(RMM_OBJ_TU_COMBINED_CONTEXT)
    make_placement_stack(obj_stack, px, py, 0, info.group_area);
#else
    make_placement_stack(&obj_stack, px, py, 0, info.group_area);
#endif

    int count = info.object_number_per_group;
    register int var = info.object_number_varience;
    int delta = (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_obj.cpp", 0x212) *
                 (var << 1)) / 0x7fff - var;
    count += delta;
    if (count < 1) count = 1;

    while (pop_stack(&obj_stack, &col, &x, &cost) && count > 0) {
#if defined(RMM_OBJ_TU_COMBINED_CONTEXT)
            if (info.terrain < 0 || ((this->map_row_offset[x][col].terrain & 0x1f) == (unsigned int)info.terrain)) {
#else
            if (info.terrain < 0 || ((this->map[x][col].terrain & 0x1f) == (unsigned int)info.terrain)) {
#endif
                fx = (float)col;
                fy = (float)x;
                RGE_Master_Static_Object* master = player->master_objects[info.obj_id];
                zone = (short)(int)master->radius_x;
                if (0.0f < master->radius_x - (float)zone) {
                    fx = fx - -0.5f;
                }
                zone = (short)(int)master->radius_y;
                if (0.0f < master->radius_y - (float)zone) {
                    fy = fy - -0.5f;
                }
                if (!master->can_place(player, fx, fy, 0, 0, 1, 1, 1, 0, 1)) {
                    player->place_object(info.obj_id, fx, fy, 0, 1);
                    count--;
                }
            }
    }
    self->deinit_stack(&obj_stack);
}
