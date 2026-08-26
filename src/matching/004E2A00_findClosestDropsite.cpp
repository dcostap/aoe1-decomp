// 004E2A00 TribeInformationAIModule::findClosestDropsite
// Source: taiinfmd.cpp lines 7342-7376
// attempt 1: direct decompiler-shaped source with inline ManagedArray<int> resize.

extern "C" long __cdecl _ftol();

#ifndef TAIINFMD_PREFIX_CONTEXT
void* operator_new(unsigned int size);
void operator_delete(void* ptr);
#endif

#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
class RGE_Master_Static_Object {
public:
    char gap_00[0x10];
    short id; // +0x10
};

#endif
class RGE_Static_Object {
public:
    char gap_00[4];
    int id;
    RGE_Master_Static_Object* master_obj;
    char gap_0C[0x2C];
    float world_x; // +0x38
    float world_y; // +0x3C

    unsigned char currentZone();
    unsigned char lookupZone(int x, int y);
};

class MainDecisionAIModule {
public:
    char gap_00[0xF0];
    RGE_Static_Object* object(int id);
};

struct ManagedArray_int {
    int* value;            // +0x00
    int numberValue;       // +0x04
    int desiredNumberValue;// +0x08
    int maximumSizeValue;  // +0x0C

    int& operator[](int index)
    {
        if (index > this->maximumSizeValue - 1) {
            int new_size = index + 1;
            int* new_data = (int*)operator_new(new_size * 4);
            if (new_data != 0) {
                int i;
                for (i = 0; i < this->maximumSizeValue && i < new_size; i++) {
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

#ifndef TAIINFMD_PREFIX_CONTEXT
class TribeInformationAIModule {
public:
    char gap_000[0x100];
    MainDecisionAIModule* md;        // +0x100
    char gap_104[0x8C];
    ManagedArray_int playerBuildings; // +0x190

    float findClosestDropsite(RGE_Static_Object* obj, int mode, int& dropsiteID);
};
#endif

#include <math.h>
#pragma intrinsic(sqrt)

extern float DAT_00575588;

#endif
float TribeInformationAIModule::findClosestDropsite(RGE_Static_Object* obj, int mode, int& dropsiteID)
{
    float best;
    unsigned char resourceZone;
    int i;
    RGE_Static_Object* dropsite;

    best = 1000.0f;
    resourceZone = obj->currentZone();
    dropsiteID = -1;

    i = 0;
    if (this->playerBuildings.numberValue > 0) {
        do {
            dropsite = this->md->object(this->playerBuildings[i]);
            if (dropsite != 0) {
                if (obj->lookupZone((int)dropsite->world_x, (int)dropsite->world_y) == resourceZone) {
                    int group = dropsite->master_obj->id;
                    if ((group == 0x6D && mode != 0) ||
                        (group == 0x67 && obj->master_obj->id != 0x3B && obj->master_obj->id != 0x32) ||
                        (group == 0x44 && (obj->master_obj->id == 0x3B || obj->master_obj->id == 0x32))) {
                        float dx = dropsite->world_x - obj->world_x;
                        float dy = dropsite->world_y - obj->world_y;
                        float dist = (float)sqrt(dx * dx + dy * dy);
                        if (best == DAT_00575588 || dist < best) {
                            dropsiteID = dropsite->id;
                            best = dist;
                        }
                    }
                }
            }

            i++;
        } while (i < this->playerBuildings.numberValue);
    }

    return best;
}
