// VA: 004543D0 alignment (690B)
// m_s_obj.cpp, lines 1021-1088
// RGE_Master_Static_Object::alignment (vt[9], offset 0x24)
// Returns uchar, always 1
//
// ATTEMPT LOG (sa878e036b_r1):
// - baseline: natural named edge/map locals; 566B rebuilt, 614 strict diff.
// - layout: corrected the implicit-vptr gap so radius_x/radius_y are +30/+34;
//   this moved the first field hunk one byte deeper.
// - layout: declaration-order probes favored left/top/right/bottom, then the
//   x-min/x-max/y-min/y-max variant was retained as a small negative check.
// - behavior: replaced many edge/coordinate temporaries with the binary's
//   six-float plus short reuse family. This recovered the 4 short-width
//   __ftol conversions, the four-return topology, 640B rebuilt size, and
//   66.53% shape; best strict diff is 564B.
// - variant: four initialization-order cases did not change the best basin.
// - behavior: a transposed strict-less boundary interpretation was tested and
//   worsened the emitted CFG/size; restored the six-float reconstruction.
// - variant: boundary-topology combinations were swept after restoration;
//   none beat the retained natural six-float source. Remaining mismatch starts
//   with ESI/EDI parameter coloring and then the initial x87 load order/branch
//   topology. Paused at the bounded hypothesis budget; likely next lead is
//   donor TU/class surface or a focused parameter-liveness/context probe.
// - abi: changed the two coordinate parameters from references to pointers,
//   matching exact same-TU/class alignment declarations; emitted code was
//   unchanged, so this did not explain the ESI/EDI coloring.
// - context: typed the existing virtual surface through the same-TU/class
//   donor methods after alignment; emitted code was unchanged. No scheduling
//   locals or behavior changes were retained.

class RGE_Game_World;
class RGE_Map;
class RGE_Static_Object;
class RGE_Player;

class RGE_Master_Static_Object {
public:
    // vtable slot 0: destructor
    virtual ~RGE_Master_Static_Object();
    // vt[1]: copy_obj
    virtual void copy_obj(RGE_Master_Static_Object* src);
    // vt[2]: modify
    virtual void modify(float val, unsigned char op);
    // vt[3]: modify_delta
    virtual void modify_delta(float val, unsigned char op);
    // vt[4]: modify_percent
    virtual void modify_percent(float val, unsigned char op);
    // vt[5]: save
    virtual void save(int param_1);
    // vt[6]: make_new_obj
    virtual RGE_Static_Object* make_new_obj(RGE_Player* player, float x, float y, float z);
    // vt[7]: make_new_master
    virtual RGE_Master_Static_Object* make_new_master();
    // vt[8]: check_placement
    virtual unsigned char check_placement(RGE_Player* player, float x, float y, int* arr,
        unsigned char p5, unsigned char p6, unsigned char p7, unsigned char p8,
        unsigned char p9, unsigned char p10);
    // vt[9]: alignment
    virtual unsigned char alignment(float* param_1, float* param_2, RGE_Game_World* param_3, unsigned char param_4);
    virtual long calc_base_damage_ability(void* object);
    virtual void play_command_sound();

    // The implicit vptr occupies the first dword; the first named field is
    // therefore reached with a 0x2C-byte post-vptr gap.
    char gap_00[0x2C];
    float radius_x;       // +0x30
    float radius_y;       // +0x34
    float radius_z;       // +0x38
    char gap_3C[0x7C];
};

class RGE_Game_World {
public:
    char gap_00[0x28];
    RGE_Map* map;         // +0x28
};

class RGE_Map {
public:
    char gap_00[0x8];
    int map_width;        // +0x8
    int map_height;       // +0xC
};

unsigned char RGE_Master_Static_Object::alignment(float* param_1, float* param_2, RGE_Game_World* param_3, unsigned char param_4)
{
    float fVar1 = *param_1 - radius_x;
    float fVar3 = *param_1 + radius_x;
    float fVar2 = *param_2 - radius_y;
    float fVar4 = *param_2 + radius_y;
    float fVar5 = (float)param_3->map->map_width - 0.00001f;
    float fVar6 = (float)param_3->map->map_height - 0.00001f;
    short sVar7;

    if (fVar1 < 0.0f) {
        fVar1 = -fVar1;
        fVar3 = fVar3 + fVar1;
        *param_1 = *param_1 + fVar1;
    }
    if (fVar2 < 0.0f) {
        fVar2 = -fVar2;
        fVar4 = fVar4 + fVar2;
        *param_2 = *param_2 + fVar2;
    }
    if (fVar5 <= fVar3)
        *param_1 = *param_1 + (fVar5 - fVar3);
    if (fVar6 <= fVar4)
        *param_2 = *param_2 + (fVar6 - fVar4);

    if (param_4 == 0)
        return 1;

    if (fVar1 < 0.0f) fVar1 = -fVar1;
    if (fVar2 < 0.0f) fVar2 = -fVar2;
    if (fVar3 < 0.0f) fVar3 = -fVar3;
    if (fVar4 < 0.0f) fVar4 = -fVar4;

    sVar7 = (short)(long)fVar1;
    fVar1 = fVar1 - (float)(int)sVar7;
    sVar7 = (short)(long)fVar2;
    fVar2 = fVar2 - (float)(int)sVar7;
    sVar7 = (short)(long)fVar3;
    fVar3 = 1.0f - (fVar3 - (float)(int)sVar7);
    sVar7 = (short)(long)fVar4;
    fVar4 = 1.0f - (fVar4 - (float)(int)sVar7);

    if (fVar3 + fVar1 < 1.0f) {
        fVar1 = *param_1;
    } else if (fVar1 <= fVar3) {
        fVar1 = *param_1 - (1.0f - fVar3);
    } else {
        fVar1 = (1.0f - fVar1) + *param_1;
    }

    if (1.0f <= fVar4 + fVar2) {
        if (fVar4 < fVar2) {
            fVar3 = *param_2;
            *param_1 = fVar1;
            *param_2 = (1.0f - fVar2) + fVar3;
            return 1;
        }
        fVar2 = *param_2;
        *param_1 = fVar1;
        *param_2 = fVar2 - (1.0f - fVar4);
        return 1;
    }
    fVar2 = *param_2;
    *param_1 = fVar1;
    *param_2 = fVar2;
    return 1;
}
