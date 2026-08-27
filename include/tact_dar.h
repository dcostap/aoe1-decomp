#ifndef AOE1_TACT_DAR_H
#define AOE1_TACT_DAR_H

#include "action.h"
#include "act_list.h"
#include "act_obj.h"
#include "stat_obj.h"
#include "m_s_obj.h"
#include "m_ac_obj.h"
#include "move_obj.h"
#include "map.h"
#include "world.h"
#include "obj_list.h"
#include "player.h"
#include "basegame.h"

// The file I/O helpers are imported C functions in the original executable.
extern "C" {
void __cdecl rge_read(int file, void* data, int size);
void __cdecl rge_write(int file, void* data, int size);
}

typedef unsigned char uchar;

extern float DAT_00575078;
extern float DAT_0057507c;
extern double DAT_00575070;

// This class is owned by tact_dar.cpp. Its only added data is the flags table
// at +0x40; all action data and virtual slots come from RGE_Action.
class TRIBE_Action_Discovery_Artifact : public RGE_Action {
public:
    unsigned char* flags;

    TRIBE_Action_Discovery_Artifact(int file, RGE_Action_Object* object);
    TRIBE_Action_Discovery_Artifact(RGE_Action_Object* object,
                                    RGE_Task* task,
                                    RGE_Static_Object* target);
    TRIBE_Action_Discovery_Artifact(RGE_Action_Object* object,
                                    RGE_Task* task,
                                    float x, float y, float z);

    virtual void save(int);
    virtual void first_in_stack(unsigned char);
    virtual unsigned char update();

protected:
    virtual void set_state(unsigned char);
    void check_objects();
};

typedef char tact_dar_action_size_check[
    (sizeof(RGE_Action) == 0x40) ? 1 : -1];
typedef char tact_dar_discovery_size_check[
    (sizeof(TRIBE_Action_Discovery_Artifact) == 0x44) ? 1 : -1];

#endif  // AOE1_TACT_DAR_H
