#ifndef M_DG_OBJ_H
#define M_DG_OBJ_H

#include <stdio.h>
#include "m_an_obj.h"

class RGE_Sprite;
class RGE_Sound;
class RGE_Player;
class RGE_Static_Object;

class RGE_Master_Doppleganger_Object : public RGE_Master_Animated_Object {
public:
    RGE_Master_Doppleganger_Object(RGE_Master_Doppleganger_Object* other_object, int do_setup);
    RGE_Master_Doppleganger_Object(int infile, RGE_Sprite** sprites, RGE_Sound** sounds, int do_setup);
    RGE_Master_Doppleganger_Object(FILE* infile, RGE_Sprite** sprites, RGE_Sound** sounds, short in_id, int do_setup);

    virtual ~RGE_Master_Doppleganger_Object();
    virtual RGE_Static_Object* make_new_obj(RGE_Player* owner, float x, float y, float z,
                                            RGE_Static_Object* obj_to_dopple);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual void copy_obj(RGE_Master_Static_Object* source);
    virtual void save(int outfile);

protected:
    int setup(RGE_Master_Doppleganger_Object* other_object);
    int setup(int infile, RGE_Sprite** sprites, RGE_Sound** sounds);
    int setup(FILE* infile, RGE_Sprite** sprites, RGE_Sound** sounds, short in_id);
};

typedef char m_dg_master_doppleganger_size[(sizeof(RGE_Master_Doppleganger_Object) == 0xBC) ? 1 : -1];

#endif
