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
    RGE_Master_Doppleganger_Object(RGE_Master_Doppleganger_Object*, int);
    RGE_Master_Doppleganger_Object(int, RGE_Sprite**, RGE_Sound**, int);
    RGE_Master_Doppleganger_Object(FILE*, RGE_Sprite**, RGE_Sound**, short, int);

    virtual ~RGE_Master_Doppleganger_Object();
    virtual RGE_Static_Object* make_new_obj(RGE_Player*, float, float, float,
                                            RGE_Static_Object*);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void save(int);

protected:
    int setup(RGE_Master_Doppleganger_Object*);
    int setup(int, RGE_Sprite**, RGE_Sound**);
    int setup(FILE*, RGE_Sprite**, RGE_Sound**, short);
};

typedef char m_dg_master_doppleganger_size[(sizeof(RGE_Master_Doppleganger_Object) == 0xBC) ? 1 : -1];

#endif
