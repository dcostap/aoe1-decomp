#ifndef AOE1_TM_B_OBJ_H
#define AOE1_TM_B_OBJ_H

#include "tm_co_ob.h"
#include <stddef.h>

class RGE_Color_Table;
class RGE_Game_World;
class RGE_Player;
class RGE_Sound;
class RGE_Sprite;
class RGE_Static_Object;
class TDrawArea;

// tm_b_obj.cpp owns this building-master extension.
// BINARY NOTE: 00512A90 selects RGE_Master_Combat_Object for type 'F'
// (0x164 bytes) and this class for type 'P' (0x17C bytes).
// Do not replace these direct targets with Fish or Projectile classes.
// Base slots keep check_placement at +0x20, alignment at +0x24, and draw at
// +0x34. TRIBE_Master_Combat_Object keeps create_task_list at +0x38. The
// five-argument factory therefore occupies the proven +0x3C slot.
class TRIBE_Master_Building_Object : public TRIBE_Master_Combat_Object {
public:
    TRIBE_Master_Building_Object(TRIBE_Master_Building_Object*, int);
    TRIBE_Master_Building_Object(int, RGE_Sprite**, RGE_Sound**, int);
    TRIBE_Master_Building_Object(FILE*, RGE_Sprite**, RGE_Sound**, short, int);
    virtual ~TRIBE_Master_Building_Object();

protected:
    int setup(TRIBE_Master_Building_Object*);
    int setup(int, RGE_Sprite**, RGE_Sound**);
    int setup(FILE*, RGE_Sprite**, RGE_Sound**, short);

public:
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void save(int);
    virtual RGE_Static_Object* make_new_obj(RGE_Player*, float, float, float);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual RGE_Static_Object* make_new_obj(RGE_Player*, float, float, float,
                                            int);
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*, long, long,
                      int, unsigned char);
    virtual unsigned char alignment(float&, float&, RGE_Game_World*,
                                    unsigned char);

    RGE_Sound* construction_sound;
    RGE_Sprite* construction_sprite;
    unsigned char building_connect_flag;
    short building_facet;
    unsigned char build_and_go_away;
    short on_build_make_obj;
    short on_build_make_tile;
    short on_build_make_overlay;
    short on_build_make_tech;
};

typedef char tribe_master_building_object_size_check[
    (sizeof(TRIBE_Master_Building_Object) == 0x17C) ? 1 : -1];
typedef char tribe_master_building_object_sound_offset_check[
    (offsetof(TRIBE_Master_Building_Object, construction_sound) == 0x164) ? 1
                                                                         : -1];
typedef char tribe_master_building_object_factory_slot_check[
    (offsetof(TRIBE_Master_Building_Object, on_build_make_tech) == 0x178) ? 1
                                                                         : -1];

#endif  // AOE1_TM_B_OBJ_H
