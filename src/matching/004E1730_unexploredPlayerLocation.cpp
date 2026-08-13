// 004E1730 TribeInformationAIModule::unexploredPlayerLocation
// PDB: taiinfmd.cpp:6562-6649, 499 bytes
// Attempt log:
// - v1: reconstructed from packet/decompiler using ObjectMemory layout, object/currentZone/lookupZone/distance, LOS virtual call and pathMap setValue.
// - v2: made byte offset a register local to probe original EDI offset allocation and 0x18 frame.
// - v3: fixed MainDecisionAIModule player pointer offset to +0xF0.
// - v4: made obj and best register locals to probe original EBX object / EBP best allocation; current best size 496/499.
// - v5: tried register self/no-register best; regressed to 480-byte .text, rolled back.
// - v6: replaced the manual LOS pointer call with the period canPath virtual at vslot +0x198.
// - v7: removed the transient record pointer and used typed ObjectMemory cursor expressions; reused the objectId home for currentZone. This restored the 0x18 frame, cursor EDI, object EBX, and best EBP.
// - v8: nested the nonzero-object and nonnull-best paths under one final zero return. This restored the original 167-instruction CFG and shared failure tail.
// - v9: compared the max-memory gate against the zero cursor. This improved the setup to the original cmp/register family; alternate zero-initialization orders were duplicate or worse.
// - v10: replaced raw important-memory cursor arithmetic with direct indexed ObjectMemory ownership and typed player/master fields. This improved the structural match to 130 differing bytes.
// - v11: modeled the ignored canPath output as a local float. VC5 reused the dead parameter home and produced an exact 499-byte match.
// EXACT: canonical ObjectMemory ownership, typed player/master ABI, 0x24 scan stride, parameter-home zone reuse, and canPath output lifetime are reconstructed. Original uses ESI=this, EBX=obj, EDI=byte cursor, EBP=best entry, and the dead parameter home for the canPath result.

typedef unsigned char uchar;
struct XYPoint { int x; int y; };
struct XYZPoint { int x; int y; int z; };

struct ObjectMemory {
    int id; short type; short group; uchar x; uchar y; uchar z; uchar owner;
    short hp; uchar pad0e[2]; int attackAttempts; uchar kills; uchar pad15[3];
    float damageCapability; float rateOfFire; float range;
};

class PlayerWorld { public: char gap[0x3c]; short player_num; };
class RGE_Player {
public:
    char gap_00[0x3c]; PlayerWorld* world; char gap_40[0x0a]; short id;
};
class MainDecisionAIModule { public: void* object(int id); char gap[0xf0]; RGE_Player* player; };
class InfluenceMap { public: int setValue(int x, int y, int v); };

class RGE_Master_Static_Object { public: char gap[0x28]; float los; };

#define LOS_VPAD1(n) virtual void los_vpad##n();
#define LOS_VPAD2(n) LOS_VPAD1(n) LOS_VPAD1(n##_1)
#define LOS_VPAD4(n) LOS_VPAD2(n) LOS_VPAD2(n##_2)
#define LOS_VPAD8(n) LOS_VPAD4(n) LOS_VPAD4(n##_4)
#define LOS_VPAD16(n) LOS_VPAD8(n) LOS_VPAD8(n##_8)
#define LOS_VPAD32(n) LOS_VPAD16(n) LOS_VPAD16(n##_16)
#define LOS_VPAD64(n) LOS_VPAD32(n) LOS_VPAD32(n##_32)

class RGE_Static_Object {
public:
    LOS_VPAD64(0)
    LOS_VPAD32(64)
    LOS_VPAD4(96)
    LOS_VPAD2(100)
    virtual int canPath(XYZPoint, float, int, float*, int, int, int);

    char gap04[4]; class RGE_Master_Static_Object* master_obj; char gap0c[0x34]; float z;
    uchar lookupZone(int x, int y);
    uchar currentZone();
    float distance_to_position(float x, float y, float z);
};

#undef LOS_VPAD64
#undef LOS_VPAD32
#undef LOS_VPAD16
#undef LOS_VPAD8
#undef LOS_VPAD4
#undef LOS_VPAD2
#undef LOS_VPAD1

class TribeInformationAIModule {
public:
    char gap_000[0x100];
    MainDecisionAIModule* md;
    int mapXSizeValue;
    int mapYSizeValue;
    int lastUpdateRowValue;
    int maxImportantObjectMemory;
    ObjectMemory* importantObjectMemory;
    char gap_118[0x158 - 0x118];
    InfluenceMap pathMap;

    int tileUncovered(int x, int y);
    int unexploredPlayerLocation(int objectId, XYPoint& out);
};

int TribeInformationAIModule::unexploredPlayerLocation(int objectId, XYPoint& out)
{
    RGE_Static_Object* obj = (RGE_Static_Object*)this->md->object(objectId);
    if (objectId != 0) {
        *(uchar*)&objectId = obj->currentZone();
        int bestDistance;
        ObjectMemory* best;
        int index;
        best = 0;
        bestDistance = -1;
        index = 0;

        if (this->maxImportantObjectMemory > 0) {
            do {
                if (this->importantObjectMemory[index].id != -1) {
                    unsigned short owner =
                        this->importantObjectMemory[index].owner;
                    if (owner != this->md->player->id &&
                        this->importantObjectMemory[index].owner != 0) {
                        if (this->tileUncovered(
                                this->importantObjectMemory[index].x,
                                this->importantObjectMemory[index].y) != 1) {
                            if (obj->lookupZone(
                                    this->importantObjectMemory[index].x,
                                    this->importantObjectMemory[index].y) ==
                                (uchar)objectId) {
                                int dist = (int)obj->distance_to_position(
                                    (float)this->importantObjectMemory[index].x,
                                    (float)this->importantObjectMemory[index].y,
                                    (float)this->importantObjectMemory[index].z);
                                if (best == 0 || bestDistance > dist) {
                                    best = &this->importantObjectMemory[index];
                                    bestDistance = dist;
                                }
                            }
                        }
                    }
                }
                index++;
            } while (index < this->maxImportantObjectMemory);
        }

        if (best != 0) {
            out.x = best->x;
            out.y = best->y;

            int objZ = (int)obj->z;
            XYZPoint pt;
            pt.x = out.x;
            pt.y = out.y;
            pt.z = objZ;
            float pathResult;
            int ok = obj->canPath(pt, obj->master_obj->los - 1.0f,
                                  -1, &pathResult, 1, -1, -1);
            if (ok == 0) {
                this->pathMap.setValue(out.x, out.y, 1);
                return 0;
            }
            this->pathMap.setValue(out.x, out.y, 0);
            return 1;
        }
    }
    return 0;
}
