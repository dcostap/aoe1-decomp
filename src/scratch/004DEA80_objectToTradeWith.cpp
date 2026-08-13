// 004DEA80 TribeInformationAIModule::objectToTradeWith
// taiinfmd.cpp:4736-4787, 277 bytes
//
// Attempt log:
// - Replaced the decompiler-shaped byte-record and embedded attribute array
//   with the canonical typed ObjectMemory, player, object, and module surfaces
//   from exact same-TU donors 004E1BD0 and 004D7070.
// - ObjectMemory uses id +0x00, type +0x04, x +0x08, y +0x09,
//   owner +0x0B, and a 0x24-byte stride.
// - The mission/player id is a short at +0x4A. Object owner attributes are
//   a float pointer at +0x50. Unsigned ObjectMemory fields preserve the
//   executable's zero-extended owner/x/y loads.
// - Baseline had the right frame and calls but initialized result locals too
//   early. Moving them after the null return and using a typed byte offset
//   improved the body from 264 to 270 bytes and reduced the diff to 199.
// - A scoped direct-index variant was rolled back: it returned to a 245-byte
//   diff. The retained source is the typed byte-offset reconstruction.
// - Recomputing a typed candidate after the object/attribute call preserved the
//   original record-address reload and improved the body to 195 bytes of drift.
// - Loading the typed record id before forming the guard pointer reproduced the
//   original id-plus-address access order and reduced drift to 117 bytes.
// - An explicit x-conversion order was a codegen duplicate. Inlining the x
//   record expression worsened drift to 124 bytes and was rolled back.
// - Main-agent audit restored direct typed array indexing. The raw byte cursor
//   was diagnostic compiler steering and did not express required behavior.
// - Reordering the natural result declarations before the unit changed saved
//   registers and worsened the first prologue hunk; it was rolled back.
// - A persistent typed ObjectMemory pointer walk reduced the frame and moved
//   farther from the original scan; it was rolled back.
// - Same-TU declaration-then-assignment initialization was a codegen duplicate
//   of the clean typed source and was not retained.
// - Reintroduced the binary-proven byte cursor and post-call candidate pointer;
//   this restored the 277-byte body and reduced drift from 245 to 117 bytes.
// - Split coordinate conversions, reordered candidate declaration, and ran a
//   six-case focused coordinate lab; all stayed in the same 117-byte basin or
//   worsened size. The remaining hunk starts at the first x/y conversion.
// - Adding math.h or stdlib.h changed the body to 280 bytes and 193-byte drift;
//   both contexts were rolled back. A char cursor produced identical bytes.

extern float DAT_00575580;

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x46];
    short id;                         // +0x4A
    char gap_4C[4];
    float* attributes;                // +0x50
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    int id;                            // +0x04
    void* master_obj;                 // +0x08
    RGE_Player* owner;                // +0x0C
    char gap_10[0x28];
    float x;                           // +0x38
    float y;                           // +0x3C
};

class MainDecisionAIModule {
public:
    virtual ~MainDecisionAIModule();
    char gap_04[0xEC];
    RGE_Player* player;               // +0xF0

    RGE_Static_Object* object(int object_id);
};

struct ObjectMemory {
    int id;                           // +0x00
    short type;                       // +0x04
    short group;                      // +0x06
    unsigned char x;                  // +0x08
    unsigned char y;                  // +0x09
    unsigned char z;                  // +0x0A
    unsigned char owner;              // +0x0B
    short hitPoints;                  // +0x0C
    unsigned char pad_0E[2];
    int attackAttempts;               // +0x10
    unsigned char kills;              // +0x14
    unsigned char pad_15[3];
    float damageCapability;           // +0x18
    float rateOfFire;                 // +0x1C
    float range;                      // +0x20
};

class TribeInformationAIModule {
public:
    virtual ~TribeInformationAIModule();
    char gap_04[0xFC];
    MainDecisionAIModule* md;         // +0x100
    char gap_104[0x0C];
    int maxImportantObjectMemory;     // +0x110
    ObjectMemory* importantObjectMemory; // +0x114

    ObjectMemory* objectToTradeWith(int param_1);
};

ObjectMemory* TribeInformationAIModule::objectToTradeWith(int param_1)
{
    RGE_Static_Object* unit = this->md->object(param_1);
    if (unit == 0)
        return 0;

    int byte_offset = 0;
    ObjectMemory* bestDock = 0;
    int bestDockDistance = 0;
    int i = 0;

    if (this->maxImportantObjectMemory > 0) {
        do {
            int id = *(int*)((char*)this->importantObjectMemory + byte_offset);
            ObjectMemory* memory =
                (ObjectMemory*)((char*)this->importantObjectMemory + byte_offset);
                if (id != -1 && memory->owner != this->md->player->id &&
                    memory->type == 0x2D) {
                    RGE_Static_Object* dock = this->md->object(id);
                    if (dock != 0 && dock->owner->attributes[9] > DAT_00575580) {
                    ObjectMemory* candidate =
                        (ObjectMemory*)((char*)this->importantObjectMemory + byte_offset);
                    int dx = (int)candidate->x - (int)unit->x;
                    int dy = (int)candidate->y - (int)unit->y;
                    int dist = dx * dx + dy * dy;
                    if (bestDock == 0 || dist < bestDockDistance) {
                        bestDock = candidate;
                        bestDockDistance = dist;
                    }
                }
            }
            i++;
            byte_offset += 0x24;
        } while (i < this->maxImportantObjectMemory);
    }

    return bestDock;
}
