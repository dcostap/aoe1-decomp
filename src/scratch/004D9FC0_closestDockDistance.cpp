// 004D9FC0 TribeInformationAIModule::closestDockDistance
// PDB: taiinfmd.cpp:1833-1848, 279 bytes
// int __thiscall closestDockDistance(int param_1, int param_2)
// ret 8 (2 params)
// FLAGS: default
//
// Attempt log:
// Baseline: decompiler-shaped raw playerBuildings fields and helper names; 279
// bytes but 256 positional differences.
// Probe 2: adopted the same-TU ManagedIntArray growth operator[] and virtual
// class surfaces as numberDocksInZone; 25 positional differences remained.
// Probe 3: reversed the closest-distance comparison to match cmp operand order;
// 23 positional differences remained and all blocks became exact.
// Probes 4-9: declaration/assignment order, object scope, explicit self alias,
// and qualified/unqualified member spelling did not change emitted code.
// Probe 10: allocation-local declaration variant lab; no emitted-code change.
// Best natural reconstruction below keeps named ManagedIntArray ownership,
// typed object coordinates, and the observed inline growth/scan behavior.

#include <stddef.h>
#include <math.h>

void* operator new(size_t size);
void operator delete(void* ptr);

struct RGE_Master_Static_Object {
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x0C];
    short id;                         // +0x10
};

struct RGE_Static_Object {
    virtual ~RGE_Static_Object();
    int id;
    RGE_Master_Static_Object* master_obj; // +0x08
    char gap_0C[0x2C];                 // +0x0C to +0x37
    float x;                            // +0x38
    float y;                            // +0x3C
};

struct MainDecisionAIModule {
    virtual ~MainDecisionAIModule();
    RGE_Static_Object* object(int id);
};

struct ManagedIntArray {
    int* value;                          // +0x00
    int numberValue;                     // +0x04
    int desiredNumberValue;             // +0x08
    int maximumSizeValue;                // +0x0C

    int& operator[](int index)
    {
        if (index > this->maximumSizeValue - 1) {
            int new_size = index + 1;
            int* new_data = (int*)::operator new(new_size * 4);
            if (new_data != 0) {
                int i;
                for (i = 0; i < this->maximumSizeValue && i < new_size; i++) {
                    new_data[i] = this->value[i];
                }
                ::operator delete(this->value);
                this->value = new_data;
                this->maximumSizeValue = new_size;
            }
        }
        return this->value[index];
    }
};

// Main-agent audit confirmed canonical typed dock/object ownership and retained
// the natural closest-distance scan.
struct TribeInformationAIModule {
    virtual ~TribeInformationAIModule();
    char gap_04[0xEC];
    ManagedIntArray farmsTaskedThisUpdate;
    MainDecisionAIModule* md;            // +0x100
    char gap_104[0x8C];                   // +0x104 to +0x18F
    ManagedIntArray playerBuildings;     // +0x190

    int closestDockDistance(int x, int y);
};

int TribeInformationAIModule::closestDockDistance(int x, int y)
{
    int i;
    int distance;

    i = 0;
    distance = -1;

    if (this->playerBuildings.numberValue > 0) {
        do {
            RGE_Static_Object* obj = this->md->object(this->playerBuildings[i]);
            if (obj != 0 && obj->master_obj->id == 0x2D) {
                int dx = x - (int)obj->x;
                int dy = y - (int)obj->y;
                int distanceSquared = dx * dx + dy * dy;
                int currentDistance = (int)sqrt((float)distanceSquared);

                if (currentDistance != 0 &&
                    (distance == -1 || distance > currentDistance)) {
                    distance = currentDistance;
                }
            }

            i++;
        } while (i < this->playerBuildings.numberValue);
    }

    return distance;
}
