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

    TRIBE_Master_Combat_Object(TRIBE_Master_Combat_Object* source,
                               int do_setup);
    TRIBE_Master_Combat_Object(int id, RGE_Sprite** sprites,
                               RGE_Sound** sounds, int flag);
    TRIBE_Master_Combat_Object(FILE* file, RGE_Sprite** sprites,
                               RGE_Sound** sounds, short id, int flag);

protected:
    int setup(TRIBE_Master_Combat_Object* source);
    int setup(int fd, RGE_Sprite** sprites, RGE_Sound** sounds);
    int setup(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds,
              short id);

public:
    virtual void copy_obj(RGE_Master_Static_Object* source);
    virtual void modify(float value, unsigned char attribute);
    virtual void modify_delta(float value, unsigned char attribute);
    virtual void modify_percent(float value, unsigned char attribute);
    virtual void save(int file);
    virtual RGE_Static_Object* make_new_obj(RGE_Player* player,
                                             float x, float y, float z);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual RGE_Task_List* create_task_list();
};

typedef char tm_co_ob_build_pts_required_offset[
    (offsetof(TRIBE_Master_Combat_Object, build_pts_required) == 0x15A) ? 1
                                                                         : -1];
typedef char tm_co_ob_tribe_size[
    (sizeof(TRIBE_Master_Combat_Object) == 0x164) ? 1 : -1];

#endif  // AOE1_TM_CO_OB_H
