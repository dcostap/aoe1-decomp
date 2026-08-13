// 00500DE0 TribeTacticalAIModule::setGroupInfluences
// taitacmd.cpp
// Attempt log:
// baseline: canonical group sentinel/object-id array ownership; typed group and object influence passes with natural repeated gather and map calls.
// probe 2: replaced InfluenceHelper/malloc scaffolding with the proven
//   TribeInformationAIModule::groupInfluenceDimension/mapBound, InfluenceMap,
//   and inlined ManagedArray<int> surfaces; size, calls, and CFG now match.
// probe 3: used the binary-supported XYPoint aggregate locals rather than four
//   untyped integer array elements; this was codegen-neutral.
// probe 4: reusing one point across both object-bound calls enlarged the frame
//   and reversed the block basin; rolled back.
// probe 6: swapping the two point roles globally moved the group hunk and
//   enlarged the localized drift; rolled back.
// probe 8: swapped only the two equal-coordinate object point roles; this
//   reduced the localized drift from 23 to 13 bytes and was retained.
// probe 9: propagating the object-role swap into the later clear-distance
//   rectangle moved the group block; rolled back.
// probe 11: kept group distance live only through the first map update and used
//   a separate object-clear-distance local; this reduced drift to 11 bytes and
//   moved the FPU conversion onto the original parameter home.
// probe 12: swapping clear-rectangle roles while retaining the separate
//   distance local moved the group block; rolled back.
// probe 14 variant lab: tested do/for group loops crossed with both clear-point
//   role orders under size/frame/call-set gates.  The retained do/minmax source
//   was best at 11 bytes; for changed size and role swap regressed to 41 bytes.
// probe 33: replaced the do-loop with a natural while loop and an in-body null
//   break; this matched the original null-check back edge and reduced drift to 10.
// probe 34: swapped clear-point roles with the improved loop; drift regressed to
//   40 bytes and disturbed the exact group block, so it was rolled back.
// probe 36: separate clearMinpt/clearMaxpt aggregates enlarged the frame to
//   0x20 and reached 75 bytes; rolled back.
// probes 38/40: pointer and reference aliases for swapped clear roles kept the
//   frame but disturbed the exact group block at 40 bytes; rolled back.
// probe 42: hoisted objectClearDistance declaration was codegen-duplicate at
//   10 bytes; rolled back.
// probe 44: reusing clearDistance moved the conversion home and regressed to
//   12 bytes; rolled back.
// probe 46 variant lab: natural/reversed-term forms stayed at 10 bytes,
//   y-first reached 14, and swapped roles reached 40; no exact variant.
// probe 47: swapped clear roles with hoisted distance declaration duplicated
//   the 40-byte basin; rolled back.
// probe 49: declaration initialization was codegen-duplicate at 10 bytes.
// probes 50/52: Ghidra-natural min-then-max object ownership reached 20 bytes
//   with a separate distance and 22 bytes when reusing clearDistance; rolled back.
// probe 66: matched the PDB's separate group/object min/max scopes and its
//   shadowed clearDistance locals.  The object scope uses min first, which
//   restores the target clear-distance point homes and reaches an exact match.
// Exact candidate: 932/932 bytes, 43/43 calls, 0x14 frame, default flags.

#include <math.h>

void* operator_new(unsigned int size);
void __cdecl operator_delete(void* ptr);

struct Waypoint {
    float x;
    float y;
    float z;
};

struct XYPoint {
    int x;
    int y;
};

class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    TacticalAIGroup* next;

    const Waypoint& gatherLocation() const;
    int desiredNumberUnits() const;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_04[0x34];
    float world_x;
    float world_y;
};

class TribeInformationAIModule {
public:
    virtual ~TribeInformationAIModule();
    int groupInfluenceDimension(int dim);
    int mapBound(XYPoint* point);
};

class MainDecisionAIModule {
public:
    virtual ~MainDecisionAIModule();
    char gap_04[0x100];
    RGE_Static_Object* object(int id);
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    char gap_104[0xCEC - 0x104];
    TribeInformationAIModule informationAI;
};

class InfluenceMap {
public:
    int setValue(int x1, int y1, int x2, int y2, unsigned char value);
    int decrementValue(int x1, int y1, int x2, int y2, unsigned char amount);
};

class ManagedArray_int {
public:
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    int& operator[](int index) {
        if (index > this->maximumSizeValue - 1) {
            int new_size = index + 1;
            int* new_data = (int*)operator_new(new_size * 4);
            if (new_data != 0) {
                for (int i = 0; i < this->maximumSizeValue && i < new_size; i++) {
                    new_data[i] = this->value[i];
                }
                operator_delete(this->value);
                this->value = new_data;
                this->maximumSizeValue = new_size;
            }
        }
        return this->value[index];
    }
};

class TribeTacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
    char gap_04[0xEC];
    TribeMainDecisionAIModule* md;
    char gap_F4[0x30];
    ManagedArray_int ungroupedSoldiers;
    char gap_134[0x9D4 - 0x134];
    TacticalAIGroup groups;

    void setGroupInfluences(InfluenceMap& map);
};

void TribeTacticalAIModule::setGroupInfluences(InfluenceMap& map)
{
    int half;
    TacticalAIGroup* group;
    TacticalAIGroup* end;
    RGE_Static_Object* object;
    int i;

    group = this->groups.next;
    end = &this->groups;
    if (group != end) {
        int clearDistance;
        XYPoint minpt;
        XYPoint maxpt;
        while (group != end) {
            if (group == 0)
                break;
            if (group->gatherLocation().x != -1.0f) {
                clearDistance = this->md->informationAI.groupInfluenceDimension(
                    group->desiredNumberUnits());
                half = clearDistance / 2;

                minpt.x = (int)(group->gatherLocation().x - (float)half);
                minpt.y = (int)(group->gatherLocation().y - (float)half);
                this->md->informationAI.mapBound(&minpt);
                maxpt.x = (int)(group->gatherLocation().x + (float)half);
                maxpt.y = (int)(group->gatherLocation().y + (float)half);
                this->md->informationAI.mapBound(&maxpt);
                map.setValue(minpt.x, minpt.y, maxpt.x, maxpt.y, 255);

                half = clearDistance;
                minpt.x = (int)(group->gatherLocation().x - (float)half);
                minpt.y = (int)(group->gatherLocation().y - (float)half);
                this->md->informationAI.mapBound(&minpt);
                maxpt.x = (int)(group->gatherLocation().x + (float)half);
                maxpt.y = (int)(group->gatherLocation().y + (float)half);
                this->md->informationAI.mapBound(&maxpt);
                map.decrementValue(minpt.x, minpt.y, maxpt.x, maxpt.y, 10);
            }
            group = group->next;
        }
    }

    i = 0;
    if (this->ungroupedSoldiers.numberValue > 0) {
        XYPoint minpt;
        XYPoint maxpt;
        do {
            object = this->md->object(this->ungroupedSoldiers[i]);
            if (object != 0) {
                minpt.x = (int)object->world_x;
                minpt.y = (int)object->world_y;
                this->md->informationAI.mapBound(&minpt);
                maxpt.x = (int)object->world_x;
                maxpt.y = (int)object->world_y;
                this->md->informationAI.mapBound(&maxpt);
                map.setValue(minpt.x, minpt.y, maxpt.x, maxpt.y, 255);

                int clearDistance;
                clearDistance = this->md->informationAI.groupInfluenceDimension(1);
                minpt.x = (int)(object->world_x - (float)clearDistance);
                minpt.y = (int)(object->world_y - (float)clearDistance);
                this->md->informationAI.mapBound(&minpt);
                maxpt.x = (int)((float)clearDistance + object->world_x);
                maxpt.y = (int)((float)clearDistance + object->world_y);
                this->md->informationAI.mapBound(&maxpt);
                map.decrementValue(minpt.x, minpt.y, maxpt.x, maxpt.y, 10);
            }
            i++;
        } while (i < this->ungroupedSoldiers.numberValue);
    }
}
