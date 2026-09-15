#ifndef AOE1_ANI_OBJ_H
#define AOE1_ANI_OBJ_H

#include "stat_obj.h"
#include "m_an_obj.h"

class RGE_Animated_Object : public RGE_Static_Object {
public:
    RGE_Animated_Object(RGE_Master_Animated_Object* tobj, RGE_Player* obj_owner,
                        float x, float y, float z, int do_setup);
    RGE_Animated_Object(int infile, RGE_Game_World* gworld, int do_setup);

    virtual float getSpeed() const { return this->speed; }

protected:
    virtual int setup(RGE_Master_Animated_Object* tobj, RGE_Player* obj_owner,
                      float x, float y, float z);
    virtual int setup(int infile, RGE_Game_World* gworld);

public:
    virtual void recycle_in_to_game(RGE_Master_Static_Object* tobj,
                                    RGE_Player* obj_owner, float x, float y,
                                    float z);
    virtual unsigned char update();
    virtual void save(int outfile);
    virtual void transform(RGE_Master_Static_Object* obj);
    virtual void set_being_worked_on(RGE_Action_Object* work_obj,
                                     short action_type,
                                     unsigned char attack_flag);
    virtual void release_being_worked_on(RGE_Static_Object* caller);

    float speed;
};

typedef char rge_animated_object_size_check[
    (sizeof(RGE_Animated_Object) == 0x8C) ? 1 : -1];

#endif
