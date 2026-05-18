// 00500DE0 TribeTacticalAIModule::setGroupInfluences
// taitacmd.cpp
// Attempt log:
// try 1: reconstructed group/object influence drawing from packet: group list pass plus object-id array pass.
// try 2: modeled stack locals as min[2], max[2], clearDistance/float temp matching packet stack slots.
// try 3: modeled group sentinel at this+0x9D4 and first node at +0x9D8; group iteration skips sentinel/null and advances via node+4.
// try 4: modeled gatherLocation() at 004EB5F0 and zero-x filter against float constant 0.0.
// try 5: modeled groupRadius() -> world+0xCEC getClearDistance(radius), half-distance integer divide by 2, then two snapped boxes.
// try 6: modeled InfluenceMap calls as 5-arg thiscalls: setInfluence(...,255) and setInfluence2(...,10).
// try 7: modeled dynamic object-id array growth at +0x124/+0x130 using malloc/free and copy loop before per-object pass.
// try 8: modeled world GetObject(id) call from this+0xF0 and object coordinates at +0x38/+0x3C.
// try 9: first build used explicit extern `_ftol(double)` helper calls; VC5 emitted EBP frame/alignment prologue (`push ebp; mov ebp,esp; and esp,-8`) unlike original.
// try 10: changed float-to-int conversions to C casts so VC5 emits FPU expression followed by internal `_ftol`-style calls; prologue family improved but rebuilt .text is now 896B vs original 932B, so no full diff.
// try 11: reviewed original: many repeated gatherLocation calls are intentionally not CSE'd; current source still likely hoists/reuses object/group coordinate expressions and collapses duplicated snap/set blocks differently.
// left in scratch: behavior is reconstructed but exact source shape for repeated coordinate conversions/call scheduling is unresolved; rebuilt is 36 bytes short. No accepted_drift: no full-size localized diff.

typedef int BOOL;
extern "C" void* __cdecl malloc(unsigned int);
extern "C" void __cdecl free(void*);

struct Waypoint { float x; float y; };
class TacticalAIGroup {
public:
    TacticalAIGroup* next;
    char gap_04[0x34];
    Waypoint* gatherLocation();
    int groupRadius();
};
class InfluenceMap {
public:
    void setInfluence(int x1,int y1,int x2,int y2,int val);
    void setInfluence2(int x1,int y1,int x2,int y2,int val);
};
class InfluenceHelper {
public:
    int getClearDistance(int);
    void snapPoint(int* p);
};
class TUnit { public: char gap_00[0x38]; float x; float y; };
class World { public: TUnit* GetObject(int id); };

class TribeTacticalAIModule {
public:
    char gap_000[0xF0];
    World* world;           // +f0
    char gap_0F4[0x124-0x0F4];
    int* objectIds;         // +124
    int objectCount;        // +128
    char gap_12C[4];
    int objectCapacity;     // +130
    char gap_134[0x9D4-0x134];
    TacticalAIGroup groupSentinel; // +9d4, next at +9d8

    void setGroupInfluences(InfluenceMap& map);
};

void TribeTacticalAIModule::setGroupInfluences(InfluenceMap& map) {
    int minpt[2];
    int maxpt[2];
    int clearDistance;
    int half;
    TacticalAIGroup* group;
    TacticalAIGroup* end;
    Waypoint* loc;
    TUnit* obj;
    int i;

    group = groupSentinel.next;
    end = &groupSentinel;
    if (group != end && group != 0) {
        do {
            loc = group->gatherLocation();
            if (loc->x != 0.0f) {
                clearDistance = ((InfluenceHelper*)((char*)world + 0xCEC))->getClearDistance(group->groupRadius());
                half = clearDistance / 2;
                minpt[0] = (int)(loc->x - (float)half);
                minpt[1] = (int)(loc->y - (float)half);
                ((InfluenceHelper*)((char*)world + 0xCEC))->snapPoint(minpt);
                maxpt[0] = (int)(loc->x + (float)half);
                maxpt[1] = (int)(loc->y + (float)half);
                ((InfluenceHelper*)((char*)world + 0xCEC))->snapPoint(maxpt);
                map.setInfluence(minpt[0], minpt[1], maxpt[0], maxpt[1], 255);

                half = clearDistance;
                minpt[0] = (int)(loc->x - (float)half);
                minpt[1] = (int)(loc->y - (float)half);
                ((InfluenceHelper*)((char*)world + 0xCEC))->snapPoint(minpt);
                maxpt[0] = (int)(loc->x + (float)half);
                maxpt[1] = (int)(loc->y + (float)half);
                ((InfluenceHelper*)((char*)world + 0xCEC))->snapPoint(maxpt);
                map.setInfluence2(minpt[0], minpt[1], maxpt[0], maxpt[1], 10);
            }
            group = group->next;
        } while (group != end);
    }

    i = 0;
    if (objectCount > 0) {
        do {
            if (i > objectCapacity - 1) {
                int* newIds = (int*)malloc(i * 4 + 4);
                if (newIds != 0) {
                    int j = 0;
                    if (objectCapacity > 0) {
                        do {
                            if (j >= i + 1) break;
                            newIds[j] = objectIds[j];
                            ++j;
                        } while (j < objectCapacity);
                    }
                    free(objectIds);
                    objectIds = newIds;
                    objectCapacity = i + 1;
                }
            }
            obj = world->GetObject(objectIds[i]);
            if (obj != 0) {
                minpt[0] = (int)obj->x;
                minpt[1] = (int)obj->y;
                ((InfluenceHelper*)((char*)world + 0xCEC))->snapPoint(minpt);
                maxpt[0] = (int)obj->x;
                maxpt[1] = (int)obj->y;
                ((InfluenceHelper*)((char*)world + 0xCEC))->snapPoint(maxpt);
                map.setInfluence(minpt[0], minpt[1], maxpt[0], maxpt[1], 255);

                clearDistance = ((InfluenceHelper*)((char*)world + 0xCEC))->getClearDistance(1);
                minpt[0] = (int)(obj->x - (float)clearDistance);
                minpt[1] = (int)(obj->y - (float)clearDistance);
                ((InfluenceHelper*)((char*)world + 0xCEC))->snapPoint(minpt);
                maxpt[0] = (int)((float)clearDistance + obj->x);
                maxpt[1] = (int)((float)clearDistance + obj->y);
                ((InfluenceHelper*)((char*)world + 0xCEC))->snapPoint(maxpt);
                map.setInfluence2(minpt[0], minpt[1], maxpt[0], maxpt[1], 10);
            }
            ++i;
        } while (i < objectCount);
    }
}
