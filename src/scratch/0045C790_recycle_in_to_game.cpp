// VA: 0045C790 RGE_Moving_Object::recycle_in_to_game (471B)
// move_obj.cpp lines 164-202
// FLAGS: config/flags/0045C790_recycle_in_to_game.rsp (/GX for the Path local)
// Attempt log:
// - Replaced the old allocation-only scaffold with the period moving-object
//   hierarchy, Path temporary/assignment, reset sequence, base recycle call,
//   and sprite-facet random-angle normalization shown by the packet.
// - Scoped the temporary Path: this reproduces its assignment/destructor
//   sequence before the movement-state reset (294 strict diff bytes).
// - Restored the typed start waypoint and its x/y/z zeroing; this recovered
//   the original 471-byte structural basin through the base recycle call.
// - The oracle compares facet_num in memory and sign-extends it again after
//   the guard.  A narrow volatile member preserves those binary-observed
//   accesses; nested positive guards retain the common set_angle tail.
// - Inlined debug_rand into the angle expression (best 99 strict diff bytes).
//   Remaining codegen drift is the x87 pair of redundant fxch instructions
//   and the quotient sign-adjust register; the Path call identity is recorded
//   by the target-specific original-symbol override.
// - Removed the explicit float cast from the double angle quotient. This
//   removed both fxch instructions and restored the exact 471-byte structure;
//   only three quotient sign-adjust register bytes differ.
// - A named quotient temp was much worse (123 bytes). A named debug_rand
//   result with the no-fxch expression reached 13 bytes but changed the
//   original multiply setup. Restored the direct period expression.
// - Tried the natural temporary assignment `this->pathValue = Path(10);` to
//   test the original Path lifetime. It lost the exact block topology (407
//   bytes); restored the scoped named Path source.
// - Tried a natural `short facings` declaration to mirror the sprite member;
//   VC5 emitted the same 3-byte quotient-register drift, so restored `int`.
// - Tried natural copy-initialization `Path path = Path(10)`; VC5 emitted
//   unchanged code, so restored direct named construction.
// - This claim tested a natural named random_angle, function-scope short
//   facings, register-qualified facings, reversed product operands, and an
//   explicit long product cast; all kept the same 3-byte ECX/EAX drift.
// - Function-scope or register-qualified random-result locals were worse
//   (134B and 13B); a six-case quotient variant lab had no invariant lead.
// - Function-scope sprite declaration also emitted unchanged code. Restored
//   the clean direct-expression source; only quotient sign-adjust coloring
//   remains unresolved.

class RGE_Master_Static_Object;
class RGE_Player;

class RGE_Sprite {
public:
    char gap_00[0x60];
    volatile short facet_num;
    char gap_62[0x0E];
    unsigned char flag;
};

struct Path {
public:
    Path(int maxSize);
    ~Path();
    Path& operator=(const Path& other);
    char data[0x34];
};

struct Waypoint {
    float x;
    float y;
    float z;
    unsigned char facet;
    unsigned char pad[3];
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    RGE_Sprite* sprite;
    char gap_14[0x74];

    void recycle_in_to_game(RGE_Master_Static_Object* master,
                            RGE_Player* player,
                            float x, float y, float z);
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    float speed;

    void recycle_in_to_game(RGE_Master_Static_Object* master,
                            RGE_Player* player,
                            float x, float y, float z);
};

class RGE_Master_Moving_Object;

class RGE_Moving_Object : public RGE_Animated_Object {
public:
    float trail_remainder;
    float velocity_x;
    float velocity_y;
    float velocity_z;
    float angle;
    float turn_towards_time;
    Path pathValue;
    Path exceptionPathValue;
    Waypoint startValue;
    Waypoint goalValue;
    float turnTimer;
    float collisionAvoidanceDistance;
    float actionRange;
    int targetIDValue;
    float targetRadiusX;
    float targetRadiusY;
    int continueCounter;
    int rangeStatusValue;
    int currentTerrainException1;
    int currentTerrainException2;
    unsigned char storePathInExceptionPath;
    unsigned char waitingToMove;
    unsigned char numberWaitDelays;
    char gap_157;
    char gap_158[0x10];
    void* userDefinedWaypoints;
    int numberUserDefinedWaypointsValue;
    int maxUserDefinedWaypointsValue;
    unsigned char finalUserDefinedWaypoint;
    char gap_175[3];
    float closestDistanceToWaypoint;
    unsigned char lastFacet;
    unsigned char lastFacet2;
    char gap_17E[2];

    virtual void recycle_in_to_game(RGE_Master_Static_Object* master,
                                    RGE_Player* player,
                                    float x, float y, float z);
    void setGoal(float x, float y, float z);
    void set_angle();
};

extern "C" int __cdecl debug_rand(char* file, int line);
extern double DAT_00570b40;
extern float DAT_00570b48;
extern float DAT_00570b4c;
extern float DAT_00570b50;

void RGE_Moving_Object::recycle_in_to_game(
    RGE_Master_Static_Object* master,
    RGE_Player* player,
    float x, float y, float z)
{
    {
        Path path(10);
        this->pathValue = path;
    }

    this->rangeStatusValue = 2;
    this->currentTerrainException1 = -1;
    this->currentTerrainException2 = -1;
    this->storePathInExceptionPath = 0;
    this->waitingToMove = 0;
    this->numberWaitDelays = 0;
    this->startValue.x = 0.0f;
    this->startValue.y = 0.0f;
    this->startValue.z = 0.0f;
    this->setGoal(0.0f, 0.0f, 0.0f);

    this->lastFacet = 0xFF;
    this->lastFacet2 = 0xFF;
    this->turnTimer = 0.0f;
    this->collisionAvoidanceDistance = 0.0f;
    this->actionRange = 0.0f;
    this->targetIDValue = -1;
    this->targetRadiusX = 0.0f;
    this->targetRadiusY = 0.0f;
    this->continueCounter = 0;
    this->closestDistanceToWaypoint = 100000.0f;

    RGE_Animated_Object::recycle_in_to_game(master, player, x, y, z);

    this->velocity_x = 0.0f;
    this->velocity_y = 0.0f;
    this->velocity_z = 0.0f;
    this->angle = 0.0f;
    this->turn_towards_time = 0.0f;
    this->trail_remainder = 0.0f;

    RGE_Sprite* sprite = this->sprite;
    if (sprite != 0) {
        if ((sprite->flag & 2) != 0) {
            if (sprite->facet_num > 1) {
                int facings = sprite->facet_num;
                this->angle =
                    (DAT_00570b40 / (float)(int)facings) *
                    (float)((debug_rand(
                        (char*)"C:\\msdev\\work\\age1_x1\\move_obj.cpp", 0xC5) *
                             facings) / 0x7FFF);

                if (this->angle < DAT_00570b48) {
                    this->angle = this->angle - DAT_00570b4c;
                } else if (this->angle > DAT_00570b50) {
                    this->angle = this->angle - DAT_00570b50;
                }
            }
        }
    }

    this->set_angle();
}
