// 004E1BD0 TribeInformationAIModule::withinXTilesOfObject
// Source: taiinfmd.cpp lines 6750-6791, size 310 bytes
//
// Attempt log:
// - The inherited scratch used a packed record with incorrect x/y/owner
//   offsets and an OwnerCheckProxy.  It also treated a caller register as an
//   ABI requirement.  The executable instead supports an ordinary typed
//   ObjectMemory scan and the same RGE_Player::isEnemy surface as the exact
//   withinXTilesOfEnemyTowncenter donor.
// - Baseline reset: canonical ObjectMemory ownership (+0x04 type, +0x08 x,
//   +0x09 y, +0x0B owner, stride 0x24), polymorphic object/master fields, and
//   natural positive object/type/owner guards.  Remaining codegen is to be
//   measured; no inline asm or compiler-steering source is retained.
// - Behavior correction: the original returns the id of the closest matching
//   object, while retaining its squared distance in the other parameter home;
//   the natural source therefore returns closest_id.
// - Session probes: a contiguous pointer walk, narrowed object class, scoped
//   loop counter, and explicit count/byte-offset induction did not improve the
//   structural basin.  Mirroring the exact same-TU donor's direct indexed
//   importantObjectMemory[i] expressions restored the original 310-byte
//   structure; swapping the two result declarations restored the original
//   initialization order.  The <=2 state threshold remains a natural spelling
//   of the observed cmp 2/ja branch.

#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
struct RGE_Master_Static_Object {
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x0C];
    short id;                         // +0x10
};

#endif
class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    int id;                            // +0x04
    RGE_Master_Static_Object* master_obj; // +0x08
    char gap_0C[0x30 - 0x0C];
    float hp;                          // +0x30
    float pad_34;                      // +0x34
    float x;                            // +0x38
    float y;                            // +0x3C
    char gap_40[0x08];
    unsigned char object_state;         // +0x48
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char status);
    virtual void do_resign(int player_id);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int value);
    virtual int isEnemy(int playerNum); // vslot +0x18
};

class MainDecisionAIModule {
public:
    virtual ~MainDecisionAIModule();
    char gap_04[0xF0 - 0x04];
    RGE_Player* player;                 // +0xF0

    RGE_Static_Object* object(int object_id);
};

struct ObjectMemory {
    int id;                             // +0x00
    short type;                         // +0x04
    short group;                        // +0x06
    unsigned char x;                    // +0x08
    unsigned char y;                    // +0x09
    unsigned char z;                    // +0x0A
    unsigned char owner;                // +0x0B
    short hitPoints;                    // +0x0C
    unsigned char pad_0E[2];
    int attackAttempts;                 // +0x10
    unsigned char kills;                // +0x14
    unsigned char pad_15[3];
    float damageCapability;             // +0x18
    float rateOfFire;                   // +0x1C
    float range;                        // +0x20
};

// Main-agent audit confirmed canonical typed object-memory/player/object
// ownership and retained the corrected squared-distance/state semantics.
#ifndef TAIINFMD_PREFIX_CONTEXT
class TribeInformationAIModule {
public:
    virtual ~TribeInformationAIModule();
    char gap_04[0x100 - 0x04];
    MainDecisionAIModule* md;           // +0x100
    char gap_104[0x0C];
    int maxImportantObjectMemory;       // +0x110
    ObjectMemory* importantObjectMemory; // +0x114

    int withinXTilesOfObject(RGE_Static_Object* obj, int tile_range,
                             int type1, int type2, int type3, int type4);
};
#endif

#endif
int TribeInformationAIModule::withinXTilesOfObject(
    RGE_Static_Object* obj, int tile_range,
    int type1, int type2, int type3, int type4)
{
    int tile_range_sq = tile_range * tile_range;
    int obj_x = (int)obj->x;
    int obj_y = (int)obj->y;
    int closest_id = -1;
    int closest_dist = -1;
    int i = 0;

    if (this->maxImportantObjectMemory > 0) {
        do {
            RGE_Static_Object* target = this->md->object(
                this->importantObjectMemory[i].id);

            if (target != 0 && target->object_state <= 2 && target->hp != 0.0f) {
                int type = (int)this->importantObjectMemory[i].type;
                if ((type == type1 || type == type2 ||
                     type == type3 || type == type4) &&
                    this->md->player->isEnemy(
                        this->importantObjectMemory[i].owner) != 0) {
                    int dx = (unsigned char)this->importantObjectMemory[i].x - obj_x;
                    int dy = (unsigned char)this->importantObjectMemory[i].y - obj_y;
                    int dist = dx * dx + dy * dy;

                    if (dist <= tile_range_sq &&
                        (dist < closest_dist || closest_id == -1)) {
                        closest_dist = dist;
                        closest_id = this->importantObjectMemory[i].id;
                    }
                }
            }

            i++;
        } while (i < this->maxImportantObjectMemory);
    }

    return closest_id;
}
