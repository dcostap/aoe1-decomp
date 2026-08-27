#ifndef AOE1_DPL_OBJ_H
#define AOE1_DPL_OBJ_H

#include "ani_obj.h"
#include "m_dg_obj.h"

class RGE_Color_Table;

class RGE_Doppleganger_Object : public RGE_Animated_Object {
public:
    virtual ~RGE_Doppleganger_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*,
                                    float, float, float, RGE_Static_Object*);
    virtual unsigned char update();
    virtual void rehook();
    virtual void save(int);
    virtual void validate();

    RGE_Doppleganger_Object(RGE_Master_Doppleganger_Object*, RGE_Player*,
                            float, float, float, int, RGE_Static_Object*);
    RGE_Doppleganger_Object(int, RGE_Game_World*, int);

protected:
    virtual int setup(RGE_Master_Doppleganger_Object*, RGE_Player*, float,
                      float, float);
    virtual int setup(int, RGE_Game_World*);

public:
    RGE_Static_Object* doppled_object;
    RGE_Color_Table* draw_color;
    RGE_Master_Static_Object* doppled_master_obj;
    int doppled_player;
    unsigned long* MapAddress;
    unsigned long LastMapValue;
    unsigned long CantSeeBits;
    unsigned char map_draw_level;
    unsigned char map_color;
    int doppledObjectID;
};

typedef char rge_doppleganger_object_size_check[
    (sizeof(RGE_Doppleganger_Object) == 0xB0) ? 1 : -1];

class RGE_Doppleganger_Creator {
public:
    RGE_Player* owner;
    int allocated_size;
    int active_size;
    RGE_Static_Object** Objects;
    unsigned long** Map_Addresses;
    unsigned long* Last_Map_Value;
    int* Object_ids;

    RGE_Doppleganger_Creator(RGE_Player*, int);
    ~RGE_Doppleganger_Creator();
    int add_doppleganger_check(RGE_Static_Object*, unsigned long*);
    int remove_doppleganger_check(RGE_Static_Object*);
    void perform_doppleganger_checks();

protected:
    void expand_allocations(int);
};

typedef char rge_doppleganger_creator_size_check[
    (sizeof(RGE_Doppleganger_Creator) == 0x1C) ? 1 : -1];

#endif  // AOE1_DPL_OBJ_H
