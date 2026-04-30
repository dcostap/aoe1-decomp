// 004D9FC0 TribeInformationAIModule::closestDockDistance
// PDB: taiinfmd.cpp:1833-1848, 279 bytes
// int __thiscall closestDockDistance(int param_1, int param_2)
// ret 8 (2 params)
// FLAGS: default

#include <stdlib.h>
#include <math.h>

typedef unsigned long DWORD;

void* __cdecl operator_new(unsigned int size);
void __cdecl operator_delete(void* ptr);

struct RGE_Master_Static_Object {
    char _gap_00[0x10];
    short id;                      // +0x10
};

struct RGE_Static_Object {
    char _gap_00[4];
    int object_id;                  // +0x04
    RGE_Master_Static_Object* master_obj;  // +0x08
    char _gap_0C[0x2C];
    float x_pos;                    // +0x38
    float y_pos;                    // +0x3C
};

class MainDecisionAIModule {
public:
    RGE_Static_Object* object(int id);
};

class TribeInformationAIModule {
public:
    char _gap_000[0x100];
    MainDecisionAIModule* md;               // +0x100
    char _gap_104[0x8C];
    int* playerBuildings_value;             // +0x190
    int playerBuildings_numberValue;        // +0x194
    char _gap_198[4];
    int playerBuildings_maximumSizeValue;   // +0x19C

    int closestDockDistance(int x, int y);
};

int TribeInformationAIModule::closestDockDistance(int x, int y)
{
    int i;
    int best;

    i = 0;
    best = -1;

    if (this->playerBuildings_numberValue <= 0)
        return best;

    do {
        // Grow array if i >= capacity
        if (i > this->playerBuildings_maximumSizeValue - 1) {
            int new_cap = i + 1;
            int* new_arr = (int*)operator_new(new_cap * 4);
            if (new_arr) {
                int j;
                for (j = 0; j < this->playerBuildings_maximumSizeValue && j < new_cap; j++)
                    new_arr[j] = this->playerBuildings_value[j];
                operator_delete(this->playerBuildings_value);
                this->playerBuildings_value = new_arr;
                this->playerBuildings_maximumSizeValue = new_cap;
            }
        }

        int obj_id = this->playerBuildings_value[i];
        RGE_Static_Object* obj = this->md->object(obj_id);

        if (obj != 0 && obj->master_obj->id == 0x2D) {
            int dx = x - (int)(obj->x_pos);
            int dy = y - (int)(obj->y_pos);
            int dist_sq = dx * dx + dy * dy;
            int dist = (int)sqrt((float)dist_sq);

            if (dist != 0) {
                if (best == -1 || dist < best)
                    best = dist;
            }
        }

        i++;
    } while (i < this->playerBuildings_numberValue);

    return best;
}
