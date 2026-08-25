// 004E3530 TribeInformationAIModule::inRangeOfUnits
// taiinfmd.cpp:7745-7769, 271 bytes
//
// Attempt log:
// - Baseline: the prior decompiler-shaped owner/type labels and manual
//   function-pointer calls produced the right call count but the wrong CFG,
//   argument ABI, and a 255-byte function (240 differing bytes).
// - Restored canonical 0x24-byte ObjectMemory ownership, the exact donor's
//   combined owner/sentinel predicate and typed player virtual at +0x18, the
//   object virtual range surface at +0x10C, and float world_z: size became
//   exact and the remaining drift was 49 bytes.
// - Added the proven object id word to place master/world_z/state at +8/+40/+48
//   (46 bytes); reversed the equivalent LOS comparison to recover the original
//   fld-los/fcomp-distance x87 topology (38 bytes).
// - A standalone found label and an explicit infinite-loop exhaustion return
//   were codegen duplicates.  The exact donor-shaped tail keeps `continue`
//   while the count remains, returns zero on exhaustion inside the positive
//   guard, and places `found` before the outer zero return.  This restores the
//   oracle's direct `jl` backedge and separate late epilogues: MATCH, 271/271.

#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
struct ObjectMemory {
    int id;                         // +0x00
    short type;                     // +0x04
    short group;                    // +0x06
    unsigned char x;                // +0x08
    unsigned char y;                // +0x09
    unsigned char z;                // +0x0A
    unsigned char owner;            // +0x0B
    short hitPoints;                // +0x0C
    unsigned char pad_0E[2];        // +0x0E
    int attackAttempts;             // +0x10
    unsigned char kills;            // +0x14
    unsigned char pad_15[3];        // +0x15
    float damageCapability;         // +0x18
    float rateOfFire;               // +0x1C
    float range;                    // +0x20
};

#endif
class RGE_Player {
public:
    virtual void vt00();
    virtual void vt04();
    virtual void vt08();
    virtual void vt0C();
    virtual void vt10();
    virtual void vt14();
    virtual int isEnemy(int playerNum); // vslot +0x18
};

class RGE_Master_Static_Object {
public:
    char gap_00[0x28];
    float los;                       // +0x28
};

class RGE_Static_Object {
public:
    virtual void vt000();
    virtual void vt004();
    virtual void vt008();
    virtual void vt00C();
    virtual void vt010();
    virtual void vt014();
    virtual void vt018();
    virtual void vt01C();
    virtual void vt020();
    virtual void vt024();
    virtual void vt028();
    virtual void vt02C();
    virtual void vt030();
    virtual void vt034();
    virtual void vt038();
    virtual void vt03C();
    virtual void vt040();
    virtual void vt044();
    virtual void vt048();
    virtual void vt04C();
    virtual void vt050();
    virtual void vt054();
    virtual void vt058();
    virtual void vt05C();
    virtual void vt060();
    virtual void vt064();
    virtual void vt068();
    virtual void vt06C();
    virtual void vt070();
    virtual void vt074();
    virtual void vt078();
    virtual void vt07C();
    virtual void vt080();
    virtual void vt084();
    virtual void vt088();
    virtual void vt08C();
    virtual void vt090();
    virtual void vt094();
    virtual void vt098();
    virtual void vt09C();
    virtual void vt0A0();
    virtual void vt0A4();
    virtual void vt0A8();
    virtual void vt0AC();
    virtual void vt0B0();
    virtual void vt0B4();
    virtual void vt0B8();
    virtual void vt0BC();
    virtual void vt0C0();
    virtual void vt0C4();
    virtual void vt0C8();
    virtual void vt0CC();
    virtual void vt0D0();
    virtual void vt0D4();
    virtual void vt0D8();
    virtual void vt0DC();
    virtual void vt0E0();
    virtual void vt0E4();
    virtual void vt0E8();
    virtual void vt0EC();
    virtual void vt0F0();
    virtual void vt0F4();
    virtual void vt0F8();
    virtual void vt0FC();
    virtual void vt100();
    virtual void vt104();
    virtual void vt108();
    virtual float range();            // vslot +0x10C

    int id;                           // +0x04
    RGE_Master_Static_Object* master_obj; // +0x08
    char gap_0C[0x34];
    float world_z;                   // +0x40
    char gap_44[0x04];
    unsigned char object_state;      // +0x48

    float distance_to_position(float x, float y, float z);
};

class MainDecisionAIModule {
public:
    char gap_00[0xF0];
    RGE_Player* player;              // +0xF0

    RGE_Static_Object* object(int object_id);
};

#ifndef TAIINFMD_PREFIX_CONTEXT
class TribeInformationAIModule {
public:
    char gap_00[0x100];
    MainDecisionAIModule* md;         // +0x100
    char gap_104[0x0C];
    int maxImportantObjectMemory;     // +0x110
    ObjectMemory* importantObjectMemory; // +0x114

    int inRangeOfUnits(int playerFilter, int x, int y, int mapRange);
};
#endif

#endif
int TribeInformationAIModule::inRangeOfUnits(
    int playerFilter, int x, int y, int mapRange)
{
    int i = 0;

    if (this->maxImportantObjectMemory > 0) {
        while (true) {
            if ((playerFilter == -1 ||
                 (int)this->importantObjectMemory[i].owner == playerFilter) &&
                (playerFilter != -1 ||
                 this->md->player->isEnemy(
                     this->importantObjectMemory[i].owner) != 0)) {
                RGE_Static_Object* object = this->md->object(
                    this->importantObjectMemory[i].id);
                if (object != 0 && object->object_state <= 2) {
                    float distance = object->distance_to_position(
                        (float)x, (float)y, object->world_z);
                    float range = object->range();
                    if (mapRange == 0 && object->master_obj->los > distance) {
                        range = object->master_obj->los;
                    }
                    if (distance <= range) {
                        goto found;
                    }
                }
            }

            i++;
            if (i < this->maxImportantObjectMemory)
                continue;
            return 0;
        }

found:
        return 1;
    }

    return 0;
}
