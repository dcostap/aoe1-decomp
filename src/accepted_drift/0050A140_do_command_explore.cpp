// ACCEPTED_DRIFT: early player-existence check uses ecx as the zero/index register and eax as world pointer instead of original eax index/ecx world pointer. The same world->players[player] slot is tested, and the loop/calls/stack cleanup match exactly afterward.
#include <windows.h>

class RGE_Player;
class RGE_Game_World;
class RGE_Static_Object;

struct RGE_Obj_Info { int id; };

class RGE_Game_World { public: char gap_00[0x40]; RGE_Player** players; };
class RGE_Command {
public:
    virtual void vfunc0() = 0;
    virtual ~RGE_Command() {}
    virtual void vfunc8() = 0;
    virtual void vfuncC() = 0;
    RGE_Game_World* world;
    void* last_order;
    int last_order_size;
    unsigned int last_order_time;
    void* com_hand;
    RGE_Static_Object* get_obj(RGE_Obj_Info info);
};

class RGE_Static_Object {
public:
    virtual void v0(); virtual void v4(); virtual void v8(); virtual void vC();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5C();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6C();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7C();
    virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8C();
    virtual void v90(); virtual void v94(); virtual void v98(); virtual void v9C();
    virtual void vA0(); virtual void vA4(); virtual void vA8(); virtual void vAC();
    virtual void vB0(); virtual void vB4(); virtual void vB8(); virtual void vBC();
    virtual void vC0(); virtual void vC4(); virtual void vC8(); virtual void vCC();
    virtual void vD0(); virtual void vD4(); virtual void vD8(); virtual void vDC();
    virtual void vE0(); virtual void vE4(); virtual void vE8(); virtual void vEC();
    virtual void vF0(); virtual void vF4(); virtual void vF8(); virtual void vFC();
    virtual void v100(); virtual void v104(); virtual void v108(); virtual void v10C();
    virtual void v110(); virtual void v114(); virtual void v118(); virtual void v11C();
    virtual void v120(); virtual void v124(); virtual void v128(); virtual void v12C();
    virtual void v130(); virtual void v134(); virtual void v138(); virtual void v13C();
    virtual void v140(); virtual void v144(); virtual void v148(); virtual void v14C();
    virtual void v150(); virtual void v154(); virtual void v158(); virtual void v15C();
    virtual void v160(); virtual void v164(); virtual void v168(); virtual void v16C();
    virtual void v170(); virtual void v174(); virtual void v178();
    virtual void explore(int x, int y, int one);
    void removeAllFromPathingGroup();
};

struct TRIBE_Command_Explore {
    unsigned char command;
    unsigned char numUnits;
    unsigned char unit_player_id;
    char gap_03;
    float targetXPosition;
    float targetYPosition;
    RGE_Obj_Info unit_ids[1];
};

class TRIBE_Command : public RGE_Command { public: void do_command_explore(TRIBE_Command_Explore* cmd); };
extern "C" long __cdecl _ftol(float f);

void TRIBE_Command::do_command_explore(TRIBE_Command_Explore* cmd)
{
    TRIBE_Command* self = this;
    RGE_Game_World* world = self->world;
    int player_id = cmd->unit_player_id;
    RGE_Obj_Info* ids = cmd->unit_ids;
    if (world->players[player_id] != 0) {
        int i = 0;
        if (cmd->numUnits > 0) {
            do {
                RGE_Static_Object* obj = self->get_obj(*ids);
                if (obj != 0) {
                    obj->removeAllFromPathingGroup();
                    obj->explore((int)cmd->targetXPosition, (int)cmd->targetYPosition, 1);
                }
                ++i;
                ++ids;
            } while (i < (int)cmd->numUnits);
        }
    }
}
