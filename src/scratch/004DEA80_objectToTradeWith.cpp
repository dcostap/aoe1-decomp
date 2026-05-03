// 004DEA80 TribeInformationAIModule::objectToTradeWith
// taiinfmd.cpp:4736-4787, 277 bytes
//
// ObjectMemory* __thiscall TribeInformationAIModule::objectToTradeWith(int param_1)
// ret 4 cleanup (1 stack param + this in ecx)
//
// Flow:
// 1. Look up trading unit via this->md->object(param_1) — if NULL, return NULL
// 2. Iterate important-memory array (36-byte stride at +0x114):
//    - Skip if unit_id == -1 (empty slot)
//    - Skip if entry.owner == missionObj->field_4A (same player = no self-trade)
//    - Skip if entry.type != 0x2D (not a dock)
//    - Look up dock object via md->object(unit_id)
//    - Skip if dock == NULL or dock->owner->attributes[9] <= 0.0
//    - Compute squared distance: (tile_x - (int)trading_x)^2 + (tile_y - (int)trading_y)^2
//      using __ftol for float→int conversion
//    - Track closest dock (store pointer to its array entry and squared distance)
// 3. Return best dock's array entry pointer (or NULL)
//
// === Attempt log ===
// 1: sub esp,10h vs orig sub esp,0Ch (4B extra local space)
//    this in ebp vs orig ebx; ebx used for trading unit ptr
//    Nested if structure instead of goto structure
//    Owner comparison: byte vs byte (dl) instead of zero-extend to 16-bit (movzx si)
//    Tile coords: movsx sign-extend byte vs mov cl (byte load only)
//    Same TU-context register allocation cascade pattern
// BLOCKER: TU-context register allocation + stack frame layout differences

#include <stdlib.h>

struct RGE_StaticObj {
    void* vtbl;
    int id;
    void* master;            // +0x08
    void* owner;             // +0x0C
    char _pad10[0x38 - 0x10];
    float x_pos;             // +0x38
    float y_pos;             // +0x3C
    char _pad40[0x48 - 0x40];
    unsigned char obj_state; // +0x48
};

struct ObjectMemory {
    int unit_id;             // +0x00
    short type;              // +0x04 (0x2D = dock)
    char _pad06[2];
    unsigned char tile_x;    // +0x08
    unsigned char tile_y;    // +0x09
    char _pad0A;
    unsigned char owner;     // +0x0B
    char _pad0C[0x24 - 0x0C]; // total 36-byte stride
};

struct RGE_Player {
    char _pad00[0x50];
    float attributes[20];    // +0x50, [9] at +0x74
};

class MainDecisionModule {
public:
    char _gap00[0xF0];
    void* missionObj;        // +0xF0 (short field_4A at +0x4A)

    RGE_StaticObj* object(int unit_id);
};

class TribeInformationModule {
public:
    char _gap00[0x100];
    MainDecisionModule* md;              // +0x100
    char _gap104[0x110 - 0x104];
    int count;                           // +0x110
    ObjectMemory* importantMemory;       // +0x114

    ObjectMemory* objectToTradeWith(int param_1);
};

ObjectMemory* TribeInformationModule::objectToTradeWith(int param_1)
{
    RGE_StaticObj* tradingUnit = this->md->object(param_1);
    if (tradingUnit == 0)
        return 0;

    int byte_offset = 0;
    int bestDistSq = 0;
    int loopCount = 0;
    ObjectMemory* bestDock = 0;

    if (this->count <= 0)
        return bestDock;

    do {
        char* entry_bytes = (char*)this->importantMemory + byte_offset;
        int e_id = *(int*)(entry_bytes + 0);

        if (e_id != -1) {
            unsigned char owner = *(entry_bytes + 0x0B);
            short mf4a = *(short*)((char*)this->md->missionObj + 0x4A);
            if (owner != (unsigned char)mf4a) {
                short etype = *(short*)(entry_bytes + 4);
                if (etype == 0x2D) {
                    RGE_StaticObj* dockObj = this->md->object(e_id);
                    if (dockObj != 0) {
                        RGE_Player* dockOwner = (RGE_Player*)dockObj->owner;
                        if (dockOwner->attributes[9] > 0.0f) {
                            int tradingX = (int)tradingUnit->x_pos;
                            int tradingY = (int)tradingUnit->y_pos;
                            int dx = (int)entry_bytes[8] - tradingX;
                            int dy = (int)entry_bytes[9] - tradingY;
                            int distSq = dx * dx + dy * dy;

                            if (bestDock == 0 || distSq < bestDistSq) {
                                bestDock = (ObjectMemory*)entry_bytes;
                                bestDistSq = distSq;
                            }
                        }
                    }
                }
            }
        }

        loopCount++;
        byte_offset += 0x24;
    } while (loopCount < this->count);

    return bestDock;
}
