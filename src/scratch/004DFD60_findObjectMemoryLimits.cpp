// 004DFD60 TribeInformationAIModule::findObjectMemoryLimits
// Attempt log:
// - Baseline: the prior source had the right call set but a 0x44 frame and broad
//   mismatch from blanket ObjectMemory initialization.
// - Reconstructed canonical 0x24-byte ObjectMemory ownership, the same-TU
//   polymorphic md/Tribe surfaces, direct byte-offset scan, typed visible-map
//   access, and the nested weapon-range/zone check.  Frame became 0x3c and the
//   best diagnostic build reached 734 bytes, 224 instructions, and 83.93% shape.
// - Binary ABI correction: vslot +0x10c is the no-argument weaponRange(), not a
//   point-taking helper; this removed the extra pre-call push and aligned the
//   range-check block.
// - The oracle retains a localized result-initialization/return-slot packing
//   hunk and a later field/induction schedule gap.  A raw aggregate-zero alias
//   reproduced one prologue store diagnostically (510-byte diff) but is not kept
//   in the living source because it is compiler-steering rather than canonical
//   source.  The prior worker paused after the ten-hypothesis budget.
// - Rechecked the first result hunk: the returned max-distance field is also
//   initialized to zero before the scan.

typedef unsigned char uchar;

struct ObjectMemory {
    int id;              // +00 also used as max distance result in return struct
    short type;          // +04
    short group;         // +06
    uchar x;             // +08
    uchar y;             // +09
    uchar z;             // +0A
    uchar owner;         // +0B
    short hitPoints;     // +0C
    short pad0e;         // +0E
    int attackAttempts;  // +10
    uchar kills;         // +14
    char pad15[3];
    float damageCapability; // +18
    float rateOfFire;       // +1C
    float range;            // +20
};

struct RGE_Static_Object;
struct RGE_Visible_Map { uchar get_visible(int x, int y); };
struct VisibleMapHolder {
    char gap_00[0x38];
    RGE_Visible_Map* map;
};
struct MainDecisionAIModule {
    virtual ~MainDecisionAIModule();
    char gap_04[0xEC];
    VisibleMapHolder* map_holder;
    RGE_Static_Object* object(int id);
};

struct RGE_Static_Object {
    virtual void pad000(); virtual void pad004(); virtual void pad008(); virtual void pad00c();
    virtual void pad010(); virtual void pad014(); virtual void pad018(); virtual void pad01c();
    virtual void pad020(); virtual void pad024(); virtual void pad028(); virtual void pad02c();
    virtual void pad030(); virtual void pad034(); virtual void pad038(); virtual void pad03c();
    virtual void pad040(); virtual void pad044(); virtual void pad048(); virtual void pad04c();
    virtual void pad050(); virtual void pad054(); virtual void pad058(); virtual void pad05c();
    virtual void pad060(); virtual void pad064(); virtual void pad068(); virtual void pad06c();
    virtual void pad070(); virtual void pad074(); virtual void pad078(); virtual void pad07c();
    virtual void pad080(); virtual void pad084(); virtual void pad088(); virtual void pad08c();
    virtual void pad090(); virtual void pad094(); virtual void pad098(); virtual void pad09c();
    virtual void pad0a0(); virtual void pad0a4(); virtual void pad0a8(); virtual void pad0ac();
    virtual void pad0b0(); virtual void pad0b4(); virtual void pad0b8(); virtual void pad0bc();
    virtual void pad0c0(); virtual void pad0c4(); virtual void pad0c8(); virtual void pad0cc();
    virtual void pad0d0(); virtual void pad0d4(); virtual void pad0d8(); virtual void pad0dc();
    virtual void pad0e0(); virtual void pad0e4(); virtual void pad0e8(); virtual void pad0ec();
    virtual void pad0f0(); virtual void pad0f4(); virtual void pad0f8(); virtual void pad0fc();
    virtual void pad100(); virtual void pad104(); virtual void pad108();
    virtual float vf10c();
    char gap004[0x34];
    float x; // +38
    float y; // +3c
    uchar currentZone();
    int withinRangeOfZoneAtPoint(uchar zone, float dist, int* pt);
    float distance_to_position(float x, float y, float z);
};

struct TribeInformationAIModule {
    virtual ~TribeInformationAIModule();
    char pad004[0xFC];
    MainDecisionAIModule* md;
    char pad104[0x0c];
    int maxImportantObjectMemory;
    ObjectMemory* importantObjectMemory;
    ObjectMemory findObjectMemoryLimits(int owner, int object_id, int& a, int& b);
};

ObjectMemory TribeInformationAIModule::findObjectMemoryLimits(int owner, int object_id, int& c1, int& c2)
{
    ObjectMemory rVal;
    RGE_Static_Object* target;
    RGE_Static_Object* obj;
    int i;
    int offset;
    uchar zone;
    int pt[2];
    int ix;
    int iy;
    int dx;
    int dy;
    float dist;

    c1 = 0;
    c2 = 0;
    rVal.id = 0;
    rVal.type = 0;
    rVal.group = 0;
    rVal.hitPoints = 0;
    rVal.attackAttempts = 0;
    rVal.kills = 0;
    rVal.damageCapability = 0.0f;
    rVal.rateOfFire = 0.0f;
    rVal.range = 0.0f;

    target = this->md->object(object_id);
    if (target != 0) {
        zone = target->currentZone();
        i = 0;
        if (this->maxImportantObjectMemory > 0) {
            offset = 0;
            do {
                if ((int)*(uchar*)((char*)this->importantObjectMemory + offset + 0x0B) == owner) {
                    obj = this->md->object(
                        *(int*)((char*)this->importantObjectMemory + offset));
                    if (obj != 0) {
                        if (zone != obj->currentZone()) {
                            pt[0] = (int)obj->x;
                            pt[1] = (int)obj->y;
                            if (target->withinRangeOfZoneAtPoint(
                                    zone, target->vf10c(), pt) != 1)
                                goto next;
                        }
                        obj = this->md->object(
                            *(int*)((char*)this->importantObjectMemory + offset));
                        if (obj != 0) {
                            ix = (int)obj->x;
                            dx = (int)*(uchar*)((char*)this->importantObjectMemory + offset + 8) - ix;
                            if (dx < 0) dx = -dx;
                            iy = (int)obj->y;
                            dy = (int)*(uchar*)((char*)this->importantObjectMemory + offset + 9) - iy;
                            if (dy < 0) dy = -dy;
                            if ((dx > 5 || dy > 5) &&
                                this->md->map_holder->map->get_visible(ix, iy) != 0x0F)
                                goto skip_visible;
                            if (*(short*)((char*)this->importantObjectMemory + offset + 6) != 3 &&
                                *(short*)((char*)this->importantObjectMemory + offset + 6) != 0x1B)
                                c1++;
                            if (*(short*)((char*)this->importantObjectMemory + offset + 6) != 2 &&
                                *(short*)((char*)this->importantObjectMemory + offset + 6) != 0x15 &&
                                *(short*)((char*)this->importantObjectMemory + offset + 6) != 0x16 &&
                                *(short*)((char*)this->importantObjectMemory + offset + 6) != 0x14 &&
                                *(short*)((char*)this->importantObjectMemory + offset + 4) != 0x2D)
                                c2++;
                            dist = target->distance_to_position(
                                (float)*(uchar*)((char*)this->importantObjectMemory + offset + 8),
                                (float)*(uchar*)((char*)this->importantObjectMemory + offset + 9),
                                (float)*(uchar*)((char*)this->importantObjectMemory + offset + 0x0A));
                            if ((float)rVal.id < dist) rVal.id = (int)dist;
                            if (rVal.hitPoints <
                                *(short*)((char*)this->importantObjectMemory + offset + 0x0C))
                                rVal.hitPoints =
                                    *(short*)((char*)this->importantObjectMemory + offset + 0x0C);
                            if (*(int*)((char*)this->importantObjectMemory + offset + 0x10) > 0)
                                rVal.hitPoints =
                                    (short)*(int*)((char*)this->importantObjectMemory + offset + 0x10);
                            if (*(uchar*)((char*)this->importantObjectMemory + offset + 0x14) != 0)
                                rVal.hitPoints =
                                    (unsigned short)*(uchar*)((char*)this->importantObjectMemory + offset + 0x14);
                            if (rVal.damageCapability <
                                *(float*)((char*)this->importantObjectMemory + offset + 0x18))
                                rVal.damageCapability =
                                    *(float*)((char*)this->importantObjectMemory + offset + 0x18);
                            if (rVal.rateOfFire <
                                *(float*)((char*)this->importantObjectMemory + offset + 0x1C))
                                rVal.rateOfFire =
                                    *(float*)((char*)this->importantObjectMemory + offset + 0x1C);
                            if (rVal.range <
                                *(float*)((char*)this->importantObjectMemory + offset + 0x20))
                                rVal.range =
                                    *(float*)((char*)this->importantObjectMemory + offset + 0x20);
                        }
                    }
                }
skip_visible:
next:
                i++;
                offset += 0x24;
            } while (i < this->maxImportantObjectMemory);
        }
    }
    return rVal;
}
