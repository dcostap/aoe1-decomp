// RGE_Action_Transport::update — first pass
// VA: 00406F90
// PDB: act_tran.cpp:139-300

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
    unsigned char update();
};

extern void _dispatch(void* action, int state);
extern int _targetZone(void* action);
extern int _withinRange(void* obj, int zone, float range);
extern unsigned char _dropHeld(void* obj, int zone);
extern unsigned char _lookupZone(void* obj, int x, int y);
extern unsigned char _getTerrain(void* map, short x, short y);

unsigned char RGE_Action_Transport::update()
{
    switch (this->state) {
    case 1:
        return 1;
    case 4:
    case 0x0B: {
        int base_state = (this->state == 4) ? 2 : 6;
        unsigned char al = (unsigned char)((*(int (__fastcall**)(void*, int))((char*)*(void**)this->sub_actions + 0x0C)))(this->sub_actions, 0);
        if (al && al < 6) {
            _dispatch(this, base_state);
            return 0;
        }
        break;
    }
    case 6:
        _dispatch(this, 2);
        return 0;
    case 0x0D:
        _dispatch(this, 2);
        return 3;
    }
    return 0;
}
