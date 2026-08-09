// 004D9EC0 TribeInformationAIModule::numberDocksInZone(int, RGE_Zone_Map*)
// Source: taiinfmd.cpp lines 1816-1828
// NC: no custom flags (default /O2 /Oy)
//
// Attempt log:
// Baseline: hand-expanded playerBuildings growth scan, 252 bytes / 84.9%
// positional diff.  The binary supports the period-plausible inline
// ManagedArray<int>::operator[] form used by the same-TU exact scanners.
// Probe 2: natural operator[] growth plus a positive numberValue guard,
// typed object/master/zone-map surfaces — exact 249/249 bytes.
// Probe 3: removed explicit unsigned casts from the zone comparison; output
// remained exact, so ordinary integral promotion is retained.

#include <stddef.h>

void* operator new(size_t size);
void operator delete(void* ptr);

struct RGE_Master_Static_Object {
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x0C];
    short id;                           // +0x10
};

struct RGE_Static_Object {
    virtual ~RGE_Static_Object();
    int id;
    RGE_Master_Static_Object* master_obj; // +0x08
    char gap_0C[0x2C];                   // +0x0C to +0x37
    float x;                             // +0x38
    float y;                             // +0x3C
};

struct MainDecisionAIModule {
    virtual ~MainDecisionAIModule();
    RGE_Static_Object* object(int id);
};

struct RGE_Zone_Map {
    unsigned char get_zone_info(int x, int y);
};

struct ManagedIntArray {
    int* value;                          // +0x00
    int numberValue;                     // +0x04
    int desiredNumberValue;              // +0x08
    int maximumSizeValue;                // +0x0C

    int& operator[](int index) {
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

struct TribeInformationAIModule {
    virtual ~TribeInformationAIModule();
    char gap_04[0xEC];
    ManagedIntArray farmsTaskedThisUpdate;
    MainDecisionAIModule* md;            // +0x100
    char gap_104[0x8C];                   // +0x104 to +0x18F
    ManagedIntArray playerBuildings;     // +0x190

    int numberDocksInZone(int param_1, RGE_Zone_Map* param_2);
};

int TribeInformationAIModule::numberDocksInZone(int param_1, RGE_Zone_Map* param_2)
{
    int count = 0;
    int i = 0;

    if (this->playerBuildings.numberValue > 0) {
        do {
            RGE_Static_Object* obj = this->md->object(this->playerBuildings[i]);
            if (obj != 0 && obj->master_obj->id == 0x2D) {
                unsigned char dockZone = param_2->get_zone_info(
                    (int)obj->x, (int)obj->y);
                if (dockZone == param_1) {
                    count++;
                }
            }

            i++;
        } while (i < this->playerBuildings.numberValue);
    }

    return count;
}
