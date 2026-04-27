// RGE_Action_Transport::next_to_drop_off_terrain — first pass
// VA: 004072B0
// PDB: act_tran.cpp:392-462

#include "../../include/game_globals.h"

class RGE_Action_Transport {
public:
    void* vtable_ptr;
    short action_type;
    char gap_06[2];
    void* obj;
    unsigned char state;
    char gap_0D[3];
    void* target_obj;
    void* target_obj2;
    int targetID;
    int target2ID;
    float target_x;
    float target_y;
    float target_z;
    float timer;
    void* task;
    void* sub_actions;
    void* sprite;
    unsigned char subActionValue;
    char gap_3D[3];
    int next_to_drop_off_terrain();
};

extern int __cdecl __ftol(float);
extern int _targetZone(void* action);
extern unsigned char _lookupZone(void* obj, int x, int y);
extern unsigned char _getTerrain(void* map, short x, short y);

int RGE_Action_Transport::next_to_drop_off_terrain()
{
    if (this->task && *(short*)((char*)this->task + 0x0E) == -1)
        return 1;

    void* sobj = this->obj;
    void* spr_list = *(void**)((char*)sobj + 8);
    float obj_z = *(float*)((char*)sobj + 0x38);
    float spr_z = *(float*)((char*)spr_list + 0x30);
    int y1 = (int)__ftol(obj_z - spr_z - 1.0f);
    obj_z = *(float*)((char*)sobj + 0x3C);
    spr_z = *(float*)((char*)spr_list + 0x34);
    int x2 = (int)__ftol(obj_z - spr_z - 1.0f);
    float spr_x = *(float*)((char*)spr_list + 0x30);
    obj_z = *(float*)((char*)sobj + 0x38);
    int y2 = (int)__ftol(spr_x + obj_z + 1.0f);
    spr_z = *(float*)((char*)spr_list + 0x34);
    obj_z = *(float*)((char*)sobj + 0x3C);
    int x1 = (int)__ftol(spr_z + obj_z + 1.0f);

    void* scn = *(void**)((char*)sobj + 0x0C);
    void* map = *(void**)((char*)*(void**)((char*)scn + 0x3C) + 0x28);

    // Clamp
    if (y1 < 0) y1 = 0;
    if (y2 >= *(int*)((char*)map + 8)) y2 = *(int*)((char*)map + 8) - 1;
    if (x2 < 0) x2 = 0;
    if (x1 >= *(int*)((char*)map + 0x0C)) x1 = *(int*)((char*)map + 0x0C) - 1;

    int target_zone = _targetZone(this);
    if (*(int*)&this->target_x != 0xBF800000) {
        short sy = (short)__ftol(this->target_y);
        short sx = (short)__ftol(this->target_x);
        target_zone = (int)_lookupZone(this->obj, sx, sy);
    }

    // 2D scan
    for (int y = y1; y <= x1; y++) {
        for (int x = x2; x <= y2; x++) {
            if (target_zone == -1 || _lookupZone(this->obj, x, y) == target_zone) {
                unsigned char terrain = _getTerrain(map, (short)x, (short)y);
                if (terrain == 2 || terrain == 4)
                    return 1;
            }
        }
    }
    return 0;
}
