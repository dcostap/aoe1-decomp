// VA: 004DA1F0 TribeInformationAIModule::addEnemyInfluences
// Attempt log:
// Prior work tried helper extraction, a dummy local, self aliases, /Oy-, /GX,
// /O1, and direct map wrappers.  Those variants either changed the frame or
// used the wrong call symbols.
// Session baseline: use the typed 0x24-byte ObjectMemory ownership, the
// MainDecision::object and aiPathSystem lookup/set surfaces, and the external
// DAT_00575564 (>1.0) range threshold.  This aligned all 17 calls and the
// original 0x28 frame, but left broad FPU/register drift.
// Session probes: moving byte-offset initialization into the positive guard
// restored the exact prologue.  Typed polymorphic object/master/TU surfaces
// were codegen-neutral.  A volatile master-pointer diagnostic reproduced the
// repeated [object+8] reloads and reduced drift to 29 bytes, but is not kept as
// unsupported compiler steering.  A max-range operand-order probe and a
// focused master/range lab were unchanged/nonexact.
// This claim tested a typed ObjectMemory* surviving the object lookup and
// owning owner/id/range reads.  It widened the frame to 0x2C and worsened the
// structural diff, so it was rolled back.
// This pass moved the XYPoint locals to function scope, as shown by the
// original local lifetime.  The diff fell from 427 to 17 bytes at exact size.
// Separate rectangle counters and reversed range terms were codegen-neutral.
// Replacing raw ObjectMemory byte-offset expressions with direct indexed named
// fields both restores canonical ownership and reduces the drift to seven
// bytes. The remaining minRange x/y FPU-store schedule is localized.

#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
struct XYPoint { int x; int y; };

struct RGE_Master_Static_Object {
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x24];
    float los;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    int id;
    RGE_Master_Static_Object* master_obj;
    char gap_0C[0x38-0x0C];
    float world_x;
    float world_y;
    float world_z;
};

struct ObjectMemory {
    int id;
    short type;
    short group;
    unsigned char x;
    unsigned char y;
    unsigned char z;
    unsigned char owner;
    short hitPoints;
    char gap_0E[2];
    int attackAttempts;
    unsigned char kills;
    char gap_15[3];
    float damageCapability;
    float rateOfFire;
    float range;
};

class MainDecisionAIModule {
public:
    virtual ~MainDecisionAIModule();
    RGE_Static_Object* object(int id);
};
class PathingSystem {
public:
    unsigned char lookupMisc(int row, int column);
    void setMisc(int row, int column, unsigned char value);
};

extern PathingSystem aiPathSystem;

#ifndef TAIINFMD_PREFIX_CONTEXT
class TribeInformationAIModule {
public:
    virtual ~TribeInformationAIModule();
    char gap_004[0x100-0x04];
    MainDecisionAIModule* md;
    char gap_104[0x110-0x104];
    int maxImportantObjectMemory;
    ObjectMemory* importantObjectMemory;
    void mapBound(XYPoint* p);
    void addEnemyInfluences(int player, int excludeId);
};
#endif

extern float DAT_00575564;

#endif

#endif
void TribeInformationAIModule::addEnemyInfluences(int player, int excludeId)
{
    XYPoint maxLOS;
    XYPoint maxRange;
    XYPoint minLOS;
    XYPoint minRange;
    int index = 0;
    if (this->maxImportantObjectMemory <= 0) return;
    do {
        if (this->importantObjectMemory[index].owner == player) {
            int id = this->importantObjectMemory[index].id;
            if (id != excludeId) {
                RGE_Static_Object* obj = this->md->object(id);
                if (obj != 0) {
                    minLOS.x = (int)(obj->world_x - obj->master_obj->los);
                    minLOS.y = (int)(obj->world_y - obj->master_obj->los);
                    this->mapBound(&minLOS);
                    maxLOS.x = (int)(obj->master_obj->los + obj->world_x);
                    maxLOS.y = (int)(obj->master_obj->los + obj->world_y);
                    this->mapBound(&maxLOS);
                    int x = minLOS.x;
                    if (x <= maxLOS.x) {
                        do {
                            int y = minLOS.y;
                            if (y <= maxLOS.y) {
                                do {
                                    int v = (int)aiPathSystem.lookupMisc(x, y) + 10;
                                    if (v > 255) v = 255;
                                    aiPathSystem.setMisc(x, y, (unsigned char)v);
                                    y++;
                                } while (y <= maxLOS.y);
                            }
                            x++;
                        } while (x <= maxLOS.x);
                    }

                    if (this->importantObjectMemory[index].range > DAT_00575564) {
                        minRange.x = (int)(obj->world_x - this->importantObjectMemory[index].range);
                        minRange.y = (int)(obj->world_y - this->importantObjectMemory[index].range);
                        this->mapBound(&minRange);
                        maxRange.x = (int)(obj->world_x + this->importantObjectMemory[index].range);
                        maxRange.y = (int)(obj->world_y + this->importantObjectMemory[index].range);
                        this->mapBound(&maxRange);
                        int x2 = minRange.x;
                        if (x2 <= maxRange.x) {
                            do {
                                int y2 = minRange.y;
                                if (y2 <= maxRange.y) {
                                    do {
                                        int v2 = (int)aiPathSystem.lookupMisc(x2, y2) + 10;
                                        if (v2 > 255) v2 = 255;
                                        aiPathSystem.setMisc(x2, y2, (unsigned char)v2);
                                        y2++;
                                    } while (y2 <= maxRange.y);
                                }
                                x2++;
                            } while (x2 <= maxRange.x);
                        }
                    }
                }
            }
        }
        index++;
    } while (index < this->maxImportantObjectMemory);
}
