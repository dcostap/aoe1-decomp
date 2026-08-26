// VA: 004C4E90 | RGE_Static_Object::modify_percent(float,uchar) | stat_obj.cpp:2490-2504 | 116 bytes
//
// Attempt log:
// [1] __fastcall vtable approach. Generated correct call but with extra xor edx,edx.
//     Code structure very different (if-else vs switch).
// [2] Try switch statement for dispatch, and vtable proxy class for virtual calls.

#include "../../include/game_types.h"
#include <stdlib.h>

#include "../../include/stat_obj_context.h"
#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
#define RGE_STAT_OBJ_SHARED_CONTEXT 1
#endif

#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
class RGE_Master_Static_Object {
public:
    char _gap_00[0x28];
    float los; // +0x28
};

// Proxy for calling vtable slots 0xD8 (54) and 0xDC (55) on RGE_Static_Object
struct VTableProxy {
    virtual void _d00(); virtual void _d01(); virtual void _d02(); virtual void _d03();
    virtual void _d04(); virtual void _d05(); virtual void _d06(); virtual void _d07();
    virtual void _d08(); virtual void _d09(); virtual void _d10(); virtual void _d11();
    virtual void _d12(); virtual void _d13(); virtual void _d14(); virtual void _d15();
    virtual void _d16(); virtual void _d17(); virtual void _d18(); virtual void _d19();
    virtual void _d20(); virtual void _d21(); virtual void _d22(); virtual void _d23();
    virtual void _d24(); virtual void _d25(); virtual void _d26(); virtual void _d27();
    virtual void _d28(); virtual void _d29(); virtual void _d30(); virtual void _d31();
    virtual void _d32(); virtual void _d33(); virtual void _d34(); virtual void _d35();
    virtual void _d36(); virtual void _d37(); virtual void _d38(); virtual void _d39();
    virtual void _d40(); virtual void _d41(); virtual void _d42(); virtual void _d43();
    virtual void _d44(); virtual void _d45(); virtual void _d46(); virtual void _d47();
    virtual void _d48(); virtual void _d49(); virtual void _d50(); virtual void _d51();
    virtual void _d52(); virtual void _d53(); // 54 dummies for slots 0-53
    virtual void funcAtD8(void* a, int b, int c); // slot 54 (0xD8)
    virtual void funcAtDC(void* a, int b, int c); // slot 55 (0xDC)
};

class RGE_Static_Object {
public:
    void** vtable;              // +0x00
    char _gap_04[0x04];
    RGE_Master_Static_Object* master_obj; // +0x08
    void* owner;                // +0x0C
    char _gap_10[0x0C];
    void* tile;                 // +0x1C
    char _gap_20[0x10];
    float hp;                   // +0x30
    char _gap_34[0x14];
    unsigned char object_state; // +0x48

    void modify_percent(float percent, unsigned char mode);
};
#endif

void RGE_Static_Object::modify_percent(float percent, unsigned char mode) {
    switch (mode) {
    case 0: {
        int tmp = (int)(percent * hp);
        hp = (float)(short)tmp;
        break;
    }
    case 1:
        if (tile != 0 && object_state == 2) {
            this->unexplore_terrain(this->owner, 0, -1);

            int val = (int)(master_obj->los * percent);
            this->explore_terrain(this->owner, 0, val);
        }
        break;
    }
}
