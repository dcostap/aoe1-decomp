// 004E2BA0 TribeInformationAIModule::findClosestReturnDropsite
// Source: taiinfmd.cpp lines 7382-7417
// Attempt log:
// 1: initial natural ManagedIntArray growth + object/zone/distance scan: same size, 23.9% edit diff; FPU distance/id filter very close, but this/obj in EDI/ESI instead of original ESI/EDI.
// 2: added local this alias: no register change.
// 3: modeled TribeInformationAIModule as polymorphic with vptr-adjusted gap: no change.
// 4: combined copy-loop condition with preincrement store: shortened to 352 bytes, wrong copy-loop family.
// 5: explicit while(1) copy loop with top newMax break/bottom cap continue: also 352 bytes, wrong family.
// 6: named object id local before md->object call: no call-setup/register change.
// 7: made md field volatile: no change.
// 8: switch id filter with duplicated distance body: much worse (87% positional, changed prologue/frame).
// 9: remove cap local and read maximumSizeValue directly: big improvement, exact this/obj registers; 15.2% edit diff. Remaining copy-loop branch order/4-byte shift.
// 10: do/while copy with top j>=newMax break and bottom maximumSizeValue condition.

#include <stddef.h>
#include <math.h>

void* operator new(size_t size);
void operator delete(void* ptr);

struct ManagedIntArray {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

struct RGE_Master_Static_Object {
    char gap_00[0x10];
    short id;
};

struct RGE_Static_Object {
    char gap_00[0x08];
    RGE_Master_Static_Object* master_obj;
    char gap_0C[0x2C];
    float world_x;
    float world_y;
    char gap_40[0x0C];
    short attribute_type_held;

    unsigned char currentZone();
    unsigned char lookupZone(int x, int y);
};

struct MainDecisionAIModule {
    char gap_00[0x04];
    RGE_Static_Object* object(int objId);
};

struct TribeInformationAIModule {
    char gap_00[0xF0];
    ManagedIntArray farmsTaskedThisUpdate;
    MainDecisionAIModule* md;
    char gap_104[0x8C];
    ManagedIntArray playerBuildings;

    RGE_Static_Object* findClosestReturnDropsite(RGE_Static_Object* unit);
};

RGE_Static_Object* TribeInformationAIModule::findClosestReturnDropsite(RGE_Static_Object* unit)
{
    RGE_Static_Object* result = 0;
    float best = 1000.0f;
    unsigned char unitZone = unit->currentZone();
    int i = 0;

    if (this->playerBuildings.numberValue > 0) {
        do {
            if (i > this->playerBuildings.maximumSizeValue - 1) {
                int newMax = i + 1;
                int* newArray = (int*)::operator new(newMax * sizeof(int));
                if (newArray != 0) {
                    int j = 0;
                    if (this->playerBuildings.maximumSizeValue > 0) {
                        do {
                            if (j >= newMax) break;
                            newArray[j] = this->playerBuildings.value[j];
                            j++;
                        } while (j < this->playerBuildings.maximumSizeValue);
                    }
                    ::operator delete(this->playerBuildings.value);
                    this->playerBuildings.value = newArray;
                    this->playerBuildings.maximumSizeValue = newMax;
                }
            }

            RGE_Static_Object* obj = this->md->object(this->playerBuildings.value[i]);
            if (obj != 0) {
                if (unit->lookupZone((int)obj->world_x, (int)obj->world_y) == unitZone) {
                    int id = obj->master_obj->id;
                    if (id == 0x6D ||
                        (id == 0x67 && unit->attribute_type_held != 0x10) ||
                        (id == 0x44 && unit->attribute_type_held == 0x10)) {
                        float xDiff = obj->world_x - unit->world_x;
                        float yDiff = obj->world_y - unit->world_y;
                        float dist = (float)sqrt(xDiff * xDiff + yDiff * yDiff);
                        if (result == 0 || dist < best) {
                            best = dist;
                            result = obj;
                        }
                    }
                }
            }

            i++;
        } while (i < this->playerBuildings.numberValue);
    }

    return result;
}
