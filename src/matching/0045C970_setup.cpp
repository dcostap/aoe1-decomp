// VA: 0045C970 RGE_Moving_Object::setup
// Attempt log:
// - baseline: natural setup reconstruction with named RGE_Sprite fields, the
//   six movement-state resets, and binary-proven random-angle normalization.
// - nested/combined sprite guards, int facet count, direct member rereads, and
//   global angle constants: size/CFG improved, but VC5 kept the facet load
//   before the compare and still chose EAX for the sprite pointer.
// - retained canonical sprite/type ownership; no raw-offset or volatility
//   scaffolding. Remaining drift starts at the facet guard and FPU scheduling.
// - Main-agent audit restored canonical polymorphic master-object ownership;
//   validated output remains the same 152-byte structural mismatch.
// - This session: zero-local, post-guard pointer alias, short facings, direct
//   sprite rereads, scoped/const sprite lifetime, and full static-object
//   surface probes were unchanged or worse; all rolled back.
// - Literal angle constants worsened FPU bytes. A diagnostic narrow volatile
//   facet-guard lab changed size to 293B but left the sprite register mismatch;
//   no volatility retained in living source.
// - Paused at 10 meaningful hypotheses: current clean source is 295B vs 291B,
//   with five ordered calls aligned; first unresolved block is sprite/facet
//   guard (original ECX direct short compare/reload vs rebuilt EAX/AX reuse).
// - Session sa27551fc4: reversed facet compare, reordered zero declaration,
//   pointer/reference and mixed-alias guard forms, complete RGE_Sprite layout,
//   multiplication-order variants, a 24-case guard/facing/angle lab, and a
//   function-scope short facing local were tested. The direct-cmp forms reduced
//   size in isolation but worsened the FPU/tail drift; no form changed the
//   rebuilt EAX sprite allocation. Restored the natural int-facing source.
// - Paused after the 10-hypothesis budget: 295B vs 291B, five ordered calls
//   aligned, 152 positional diff bytes; remaining lead is original ECX sprite
//   versus rebuilt EAX/zero-ECX coloring plus the later FPU multiply schedule.
// - orch2-45C970-rand: inlined debug_rand directly in the facings product,
//   following exact donor 00488EA0. This moved the diff 152 -> 142 bytes and
//   shape 92.94% -> 94.12%; calls and CFG stayed aligned. The first structural
//   hunk remains the sprite/facet guard, so no second blind hypothesis was run.
// - tu-moveobj-45C970: direct facet use improved size/shape but worsened bytes;
//   separate debug_rand before facet reload reached 291B and 66-byte diff.
//   Direct member rereads broke the base-call argument schedule. Reordered
//   facet assignment before debug_rand returned to the earlier 152-byte basin.
//   Keep the natural separate-call form; remaining gap is ECX/EDX pointer
//   coloring and the direct facet compare.
// - shardC2-45C970: moved the existing typed sprite assignment immediately
//   after base setup, before reset stores; emitted code stayed unchanged.
// - Worker sa-3d6312ea: clean baseline rebuilt at 291B with five ordered calls
//   aligned and 66 positional diff bytes. Direct member rereads, pre-call
//   facings, function-scope facings, scalar sprite handles, volatile facet
//   reloads, and expression/liveness variants were unchanged or worse.
// - The unresolved lead remains original ECX sprite -> EDX preservation and
//   EDI facings coloring versus rebuilt EDI sprite -> ECX facings, plus the
//   rebuilt FXCH pair in the random-angle FPU expression. Restored clean source.
// - Exact recovery: nested direct sprite guards, an inline debug_rand product,
//   and a double denominator term without an outer float cast reproduce 291B.

#ifndef MOVE_OBJ_CANONICAL_TU
extern "C" int __cdecl debug_rand(char* file, int line);

extern double DAT_00570b40;
extern float DAT_00570b48;
extern float DAT_00570b4c;
extern float DAT_00570b50;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
};

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
};

class RGE_Sprite {
public:
    char pict_name[0x0D];
    char gap_0D[3];
    long resource_id;
    unsigned char loaded;
    char gap_15[3];
    void* color_tables;
    void* shape;
    long last_time;
    long delta_time;
    unsigned char color_flag;
    unsigned char draw_level;
    short color_table;
    unsigned char transparent_picking_flag;
    char gap_2D;
    short box_x1;
    short box_y1;
    short box_x2;
    short box_y2;
    short draw_list_num;
    void* draw_list;
    void* main_sound;
    unsigned char micro_man_sound;
    char gap_41[3];
    void* sound_list;
    char name[0x15];
    char gap_5D;
    short frame_num;
    short facet_num;
    char gap_62[2];
    float base_speed;
    float duration;
    float pause_between_loops;
    unsigned char flag;
    char gap_71;
    short id;
    unsigned char mirror_flag;
    char gap_75[3];
};

class RGE_Player;

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_04[0x0C];
    RGE_Sprite* sprite;
    char gap_14[0x3A];
    unsigned char type;
    char gap_4F[0x39];
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    float speed;

    int setup(RGE_Master_Animated_Object* master, RGE_Player* player,
              float x, float y, float z);
};

class RGE_Moving_Object : public RGE_Animated_Object {
public:
    float trail_remainder;
    float velocity_x;
    float velocity_y;
    float velocity_z;
    float angle;
    float turn_towards_time;
    int setup(RGE_Master_Moving_Object* master, RGE_Player* player,
              float x, float y, float z);
    void set_angle();
};

#endif

int RGE_Moving_Object::setup(RGE_Master_Moving_Object* master_obj,
                             RGE_Player* player, float x, float y, float z) {
    this->RGE_Animated_Object::setup(master_obj, player, x, y, z);

    this->type = 0x1E;
    this->velocity_x = 0.0f;
    this->velocity_y = 0.0f;
    this->velocity_z = 0.0f;
    this->angle = 0.0f;
    this->turn_towards_time = 0.0f;
    this->trail_remainder = 0.0f;

    if (this->sprite != 0) {
        if ((this->sprite->flag & 2) != 0) {
            if (1 < this->sprite->facet_num) {
                float random_angle =
                    DAT_00570b40 / (float)(int)this->sprite->facet_num *
                    (float)((debug_rand("C:\\msdev\\work\\age1_x1\\move_obj.cpp", 0xDE) *
                             (int)this->sprite->facet_num) / 0x7FFF);
                this->angle = random_angle;

                if (this->angle < DAT_00570b48) {
                    this->angle = random_angle - DAT_00570b4c;
                    this->set_angle();
                    return 1;
                }
                if (this->angle > DAT_00570b50) {
                    this->angle = random_angle - DAT_00570b50;
                    this->set_angle();
                    return 1;
                }
            }
        }
    }

    this->set_angle();
    return 1;
}
