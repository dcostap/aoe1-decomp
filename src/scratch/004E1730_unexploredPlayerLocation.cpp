// 004E1730 TribeInformationAIModule::unexploredPlayerLocation
// PDB: taiinfmd.cpp:6562-6649, 499 bytes
// Attempt log:
// - v1: reconstructed from packet/decompiler using ObjectMemory layout, object/currentZone/lookupZone/distance, LOS virtual call and pathMap setValue.
// - v2: made byte offset a register local to probe original EDI offset allocation and 0x18 frame.
// - v3: fixed MainDecisionAIModule player pointer offset to +0xF0.
// - v4: made obj and best register locals to probe original EBX object / EBP best allocation; current best size 496/499.
// - v5: tried register self/no-register best; regressed to 480-byte .text, rolled back.
// BLOCKER: behavior/call set/field offsets are reconstructed, but rebuilt .text is 496 bytes vs original 499 so check_function cannot compare. Main drift is register/frame basin: original uses 0x18 frame, ESI=this, EBX=obj, EDI=byte offset, EBP=best entry, and stores current zone into the dead objectId parameter slot. Rebuilt uses 0x1C frame, EBP=this, EDI=obj, ESI=current entry, EBX=best, with an extra offset stack slot and different LOS virtual-call setup. Need source/topology breakthrough for original register allocation and 0x18 frame.

typedef unsigned char uchar;
struct XYPoint { int x; int y; };
struct XYZPoint { int x; int y; int z; };

struct ObjectMemory {
    int id; short type; short group; uchar x; uchar y; uchar z; uchar owner;
    short hp; uchar pad0e[2]; int attackAttempts; uchar kills; uchar pad15[3];
    float damageCapability; float rateOfFire; float range;
};

class MainDecisionAIModule { public: void* object(int id); char gap[0xf0]; void* player; };
class InfluenceMap { public: int setValue(int x, int y, int v); };
class RGE_Static_Object {
public:
    void** vtbl; char gap04[4]; void* master_obj; char gap0c[0x34]; float z;
    uchar lookupZone(int x, int y);
    uchar currentZone();
    float distance_to_position(float x, float y, float z);
};

typedef int (__stdcall *LosProc)(RGE_Static_Object*, XYZPoint, void*, float, int, XYPoint*, int, int, int);

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
    register int offset;
    register RGE_Static_Object* obj = (RGE_Static_Object*)this->md->object(objectId);
    if (objectId == 0) {
        return 0;
    }

    uchar zone = obj->currentZone();
    int bestDistance = -1;
    register ObjectMemory* best = 0;
    int index = 0;
    offset = 0;

    if (this->maxImportantObjectMemory > 0) {
        do {
            ObjectMemory* mem = (ObjectMemory*)((char*)this->importantObjectMemory + offset);
            if (mem->id != -1) {
                unsigned short owner = mem->owner;
                if (owner != *(unsigned short*)((char*)this->md->player + 0x4a) && mem->owner != 0) {
                    if (this->tileUncovered(mem->x, mem->y) != 1) {
                        if (obj->lookupZone(mem->x, mem->y) == zone) {
                            int dist = (int)obj->distance_to_position((float)mem->x, (float)mem->y, (float)mem->z);
                            if (best == 0 || bestDistance > dist) {
                                best = mem;
                                bestDistance = dist;
                            }
                        }
                    }
                }
            }
            index++;
            offset += 0x24;
        } while (index < this->maxImportantObjectMemory);
    }

    if (best == 0) {
        return 0;
    }

    out.x = best->x;
    out.y = best->y;

    int objZ = (int)obj->z;
    float los = *(float*)((char*)obj->master_obj + 0x28) - 1.0f;
    XYZPoint pt;
    pt.x = out.x;
    pt.y = out.y;
    pt.z = objZ;
    int ok = ((LosProc)obj->vtbl[0x66])(obj, pt, obj->master_obj, los, -1, &out, 1, -1, -1);
    if (ok == 0) {
        this->pathMap.setValue(out.x, out.y, 1);
        return 0;
    }
    this->pathMap.setValue(out.x, out.y, 0);
    return 1;
}
