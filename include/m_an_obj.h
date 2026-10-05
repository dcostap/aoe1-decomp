#ifndef AOE1_M_AN_OBJ_H
#define AOE1_M_AN_OBJ_H

#include <stdio.h>
#include "m_s_obj.h"

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
  public:
    virtual ~RGE_Master_Animated_Object();
    virtual void copy_obj(RGE_Master_Static_Object* source);
    virtual void modify(float amount, unsigned char flag);
    virtual void modify_delta(float amount, unsigned char flag);
    virtual void modify_percent(float amount, unsigned char flag);
    virtual void save(int outfile);
    virtual RGE_Static_Object* make_new_obj(RGE_Player* owner, float x, float y, float z);
    virtual RGE_Master_Static_Object* make_new_master();

    RGE_Master_Animated_Object(RGE_Master_Animated_Object* other_object, int do_setup);
    RGE_Master_Animated_Object(int infile, RGE_Sprite** sprites, RGE_Sound** sounds, int do_setup);
    RGE_Master_Animated_Object(FILE* infile, RGE_Sprite** sprites, RGE_Sound** sounds, short in_id, int do_setup);

  protected:
    int setup(RGE_Master_Animated_Object* other_object);
    int setup(int infile, RGE_Sprite** sprites, RGE_Sound** sounds);
    int setup(FILE* infile, RGE_Sprite** sprites, RGE_Sound** sounds, short in_id);

  public:
    float speed;
};

typedef char m_an_obj_animated_size[(sizeof(RGE_Master_Animated_Object) == 0xBC) ? 1 : -1];

#endif
