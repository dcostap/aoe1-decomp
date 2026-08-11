// 004864F0 RGE_RMM_Object_Generator::place_objects
// Attempt log:
// 1: initial natural implementation from packet/decompiler and rmm_obj neighbor stubs: exact size but 78% diff; compiler emitted counted byte loop and used edi=this.
// 2: use memset plus explicit self local to try original rep stosd clear and ebp=this register: first 74 bytes match; count kept in esi and player load scheduled later.
// 3: make count volatile to force stack local and memory test/dec: edit diff improved to 16.7%, but world/player load still scheduled after mask and stack arg LEAs shifted.
// 4: split world load to a separate local before player-id mask: no codegen change.
// 5: use <= -1 spelling for player-id mask to match cmp -1/setle: improved to 13.4%; remaining early mismatch is world load scheduled after mask and pop_stack arg order.
// 6: split players pointer load before mask: no codegen change.
// 7: store player id in a temp before indexing to probe load scheduling: no codegen change.
// 8: volatile world local to force load before mask: worsened to 27% edit diff with extra stack store; rolled back.
// 9: restored the proven Map_Stack/pop_stack ABI, long coordinate outputs, and
//    natural while(pop_stack && count > 0) tail; this reached exact size/CFG and
//    a 43-byte positional diff, with only the early setup hunk unresolved.
// 10: a focused 15-variant pre-loop lab (world/player declaration forms and
//     loop predicates) collapsed to duplicate codegen groups; reversing the
//     commutative mask operands was also a duplicate. The remaining drift is
//     VC5 world/mask/register and pop-argument scheduling, not behavior/calls.

extern "C" void* __cdecl memset(void*, int, unsigned int);

struct Map_Stack {
    long x;
    long y;
    float cost;
    float tot_cost;
    Map_Stack* next;
    Map_Stack* prev;
};
struct RGE_Tile { char gap[5]; unsigned char terrain; char rest[18]; };
struct RGE_Object_Info_Line {
    int obj_id;                    // +00
    int terrain;                   // +04
    unsigned char group_flag;      // +08
    char pad09[0x14 - 0x09];
    int number_of_groups;          // +14
    char pad18[0x1c - 0x18];
    int player_id;                 // +1c
    char pad20[0x2c - 0x20];
    int object_exclusion_zone;     // +2c
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

struct RGE_World { char pad00[0x40]; RGE_Player** players; };

class RGE_RMM_Object_Generator {
public:
    char pad00[0x10];
    RGE_Tile** map;                // +10
    int width;                     // +14
    int height;                    // +18
    char pad1c[0x20 - 0x1c];
    unsigned char* byte_map;       // +20
    char pad24[0x30 - 0x24];
    RGE_World* world;              // +30

    void init_stack(Map_Stack* s);
    void deinit_stack(Map_Stack* s);
    void make_placement_stack(Map_Stack* s, long x, long y, int unk, int area);
    Map_Stack* pop_stack(Map_Stack* s, long* out_col, long* out_x, float* out_cost);
    void remove_area_from_lists(long left, long right, long y);
    void place_group(RGE_Object_Info_Line& info, long x, long y, RGE_Player* player);
    void place_cluster(RGE_Object_Info_Line& info, long x, long y, RGE_Player* player);
    void place_objects(RGE_Object_Info_Line& info);
};

void RGE_RMM_Object_Generator::place_objects(RGE_Object_Info_Line& info)
{
    long y;
    long x;
    long col;
    int count;
    float fx;
    float fy;
    int zone;
    Map_Stack obj_stack;

    // clear occupancy byte map to 1
    memset(this->byte_map, 1, this->width * this->height);

    this->init_stack(&obj_stack);
    this->make_placement_stack(&obj_stack, -1, -1, -1, -1);

    RGE_Player* player;
    player = this->world->players[
        info.player_id & (info.player_id <= -1 ? 0 : -1)];
    count = info.number_of_groups;

    while (pop_stack(&obj_stack, &col, &x, (float*)&y) && count > 0) {
            if (info.terrain < 0 || ((this->map[x][col].terrain & 0x1f) == (unsigned int)info.terrain)) {
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
                    remove_area_from_lists(col, x, info.object_exclusion_zone);
                    switch (info.group_flag) {
                    case 0:
                        player->place_object(info.obj_id, fx, fy, 0, 1);
                        break;
                    case 1:
                        place_group(info, col, x, player);
                        break;
                    case 2:
                        place_cluster(info, col, x, player);
                        break;
                    }
                    count--;
                }
            }
        }
    this->deinit_stack(&obj_stack);
}
