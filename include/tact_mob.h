#ifndef AOE1_TACT_MOB_H
#define AOE1_TACT_MOB_H

// Local declarations for C:\\msdev\\work\\age1_x1\\tact_mob.cpp.
// Shared engine classes come from their reviewed owner headers.
#include "action.h"
#include "act_obj.h"
#include "stat_obj.h"
#include "m_co_obj.h"
#include "world.h"
#include "player.h"
#include "tplayer.h"
#include "basegame.h"
#include "rge_base_game_global.h"
#include "game_globals.h"
#include <string.h>

typedef unsigned char uchar;

extern "C" void __cdecl rge_read(int, void*, int);
extern "C" void __cdecl rge_write(int, void*, int);
extern "C" int __cdecl debug_rand(char*, int);
extern float save_game_version;

class TRIBE_Action_Make_Obj : public RGE_Action {
public:
    TRIBE_Action_Make_Obj(int, RGE_Action_Object*);
    TRIBE_Action_Make_Obj(RGE_Action_Object*, short, int, uchar);

    virtual ~TRIBE_Action_Make_Obj();
    virtual void save(int);
    virtual void first_in_stack(uchar);
    virtual uchar update();
    virtual int stop();

protected:
    virtual void set_state(uchar);
    uchar place_obj(RGE_Static_Object**);

public:
    short obj_id;
    float work_done;
    int unique_id;
    uchar pre_paid;

    void get_info(short&, short&, char*, short);
};

typedef char tact_mob_action_size[(sizeof(RGE_Action) == 0x40) ? 1 : -1];
typedef char tact_mob_make_obj_size[
    (sizeof(TRIBE_Action_Make_Obj) == 0x50) ? 1 : -1];

#endif
