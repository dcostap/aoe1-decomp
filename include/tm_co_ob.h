#ifndef AOE1_TM_CO_OB_H
#define AOE1_TM_CO_OB_H

#include <stddef.h>
#include <stdio.h>

#include "m_co_obj.h"


class Attribute_Cost {
public:
    short type;
    short amount;
    unsigned char flag;
};

typedef char tm_co_ob_attribute_cost_size[
    (sizeof(Attribute_Cost) == 0x06) ? 1 : -1];

class TRIBE_Master_Combat_Object : public RGE_Master_Combat_Object {
public:
    virtual ~TRIBE_Master_Combat_Object();

    Attribute_Cost build_inventory[3];
    short build_pts_required;
    short id_of_building_obj;
    unsigned char button_location;
    short orig_pierce_armor;

    TRIBE_Master_Combat_Object(TRIBE_Master_Combat_Object* other_object, int do_setup);
    TRIBE_Master_Combat_Object(int infile, RGE_Sprite** sprites, RGE_Sound** sounds, int do_setup);
    TRIBE_Master_Combat_Object(FILE* infile, RGE_Sprite** sprites, RGE_Sound** sounds,
                               short in_id, int do_setup);

protected:
    int setup(TRIBE_Master_Combat_Object* other_object);
    int setup(int infile, RGE_Sprite** sprites, RGE_Sound** sounds);
    int setup(FILE* infile, RGE_Sprite** sprites, RGE_Sound** sounds, short in_id);

public:
    virtual void copy_obj(RGE_Master_Static_Object* source);
    virtual void modify(float amount, unsigned char flag);
    virtual void modify_delta(float amount, unsigned char flag);
    virtual void modify_percent(float amount, unsigned char flag);
    virtual void save(int outfile);
    virtual RGE_Static_Object* make_new_obj(RGE_Player* owner, float x, float y, float z);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual RGE_Task_List* create_task_list();
};

typedef char tm_co_ob_build_pts_required_offset[
    (offsetof(TRIBE_Master_Combat_Object, build_pts_required) == 0x15A) ? 1
                                                                         : -1];
typedef char tm_co_ob_tribe_size[
    (sizeof(TRIBE_Master_Combat_Object) == 0x164) ? 1 : -1];

#endif  // AOE1_TM_CO_OB_H
