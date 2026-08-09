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
    char gap_00[0x60];
    short facet_num;
    char gap_62[0x0E];
    unsigned char flag;
};

// Diagnostic alias: the original reloads facet_num after the guard rather
// than reusing the compare value.  Keep the canonical RGE_Sprite access for
// the value used by the calculation.
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

int RGE_Moving_Object::setup(RGE_Master_Moving_Object* master_obj,
                             RGE_Player* player, float x, float y, float z) {
    RGE_Sprite* sprite;
    this->RGE_Animated_Object::setup(master_obj, player, x, y, z);

    this->type = 0x1E;
    this->velocity_x = 0.0f;
    this->velocity_y = 0.0f;
    this->velocity_z = 0.0f;
    this->angle = 0.0f;
    this->turn_towards_time = 0.0f;
    this->trail_remainder = 0.0f;

    sprite = this->sprite;
    if (sprite != 0 && (sprite->flag & 2) != 0 &&
        1 < sprite->facet_num) {
            int facings = sprite->facet_num;
            int random_value = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\move_obj.cpp", 0xDE);
            float random_angle = (float)(DAT_00570b40 / (float)(int)facings) *
                (float)((random_value * facings) / 0x7FFF);
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

    this->set_angle();
    return 1;
}
