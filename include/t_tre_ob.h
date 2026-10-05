#ifndef AOE1_T_TRE_OB_H
#define AOE1_T_TRE_OB_H

#include "stat_obj.h"
#include "tm_tre_o.h"

class TRIBE_Tree_Object : public RGE_Static_Object {
  public:
    TRIBE_Tree_Object(TRIBE_Master_Tree_Object* tobj, RGE_Player* obj_owner, float x, float y, float z, int do_setup);
    TRIBE_Tree_Object(int infile, RGE_Game_World* gworld, int do_setup);

    virtual void set_object_state(unsigned char new_object_state);
};

typedef char tribe_tree_object_size_check[(sizeof(TRIBE_Tree_Object) == 0x88) ? 1 : -1];

#endif
