#ifndef AOE1_MISL_OBJ_H
#define AOE1_MISL_OBJ_H

#include "com_obj.h"
#include <stddef.h>

class RGE_Game_World;
class RGE_Master_Combat_Object;
class RGE_Player;
class RGE_Static_Object;
class RGE_Check_List;

// misl_obj.cpp owns the missile-object extension. All inherited state and
// virtual slots come from the canonical RGE_Combat_Object owner.
class RGE_Missile_Object : public RGE_Combat_Object {
public:
    RGE_Missile_Object(RGE_Master_Combat_Object*, RGE_Player*, float, float,
                       float, int);
    RGE_Missile_Object(int, RGE_Game_World*, int);

protected:
    virtual int setup(RGE_Master_Combat_Object*, RGE_Player*, float, float,
                      float);
    virtual int setup(int, RGE_Game_World*);

public:
    virtual void rehook();
    virtual void save(int);
    virtual unsigned char update();

    void init_missile(RGE_Combat_Object*, RGE_Static_Object*, float);
    void init_missile(RGE_Combat_Object*, float, float, float, float);
    unsigned char missile_move();
    RGE_Check_List* make_object_collision_list(float);

    float max_range;
};

typedef char rge_missile_object_max_range_offset_check[
    (offsetof(RGE_Missile_Object, max_range) == 0x1C4) ? 1 : -1];
typedef char rge_missile_object_size_check[
    (sizeof(RGE_Missile_Object) == 0x1C8) ? 1 : -1];

#endif  // AOE1_MISL_OBJ_H
