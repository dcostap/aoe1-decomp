#ifndef AOE1_T_TRE_OB_H
#define AOE1_T_TRE_OB_H

#include "stat_obj.h"
#include "tm_tre_o.h"

class TRIBE_Tree_Object : public RGE_Static_Object {
public:
    virtual ~TRIBE_Tree_Object();

    TRIBE_Tree_Object(TRIBE_Master_Tree_Object*, RGE_Player*,
                      float, float, float, int);
    TRIBE_Tree_Object(int, RGE_Game_World*, int);

    virtual void set_object_state(unsigned char);
};

typedef char tribe_tree_object_size_check[
    (sizeof(TRIBE_Tree_Object) == 0x88) ? 1 : -1];

#endif
