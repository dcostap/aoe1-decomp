#ifndef AOE1_TM_TRE_O_H
#define AOE1_TM_TRE_O_H

// Declarations for the PDB source module tm_tre_o.cpp.
//
// RGE_Master_Static_Object and RGE_Static_Object come from the reviewed
// master/static object surface. This header adds only the tree declarations
// owned by this module; it does not copy a base layout.

#include "m_s_obj_context.h"

class TRIBE_Master_Tree_Object : public RGE_Master_Static_Object {
public:
    virtual ~TRIBE_Master_Tree_Object();

    TRIBE_Master_Tree_Object(TRIBE_Master_Tree_Object* source, int do_setup);
    TRIBE_Master_Tree_Object(int id, RGE_Sprite** sprites,
                             RGE_Sound** sounds, int do_setup);
    TRIBE_Master_Tree_Object(FILE* file, RGE_Sprite** sprites,
                             RGE_Sound** sounds, short id, int do_setup);

    virtual RGE_Static_Object* make_new_obj(RGE_Player* player,
                                             float x, float y, float z);
    virtual RGE_Master_Static_Object* make_new_master();
};

// The tree object constructor is owned by t_tre_ob.cpp. This declaration is
// sufficient for the factory body and keeps that module's implementation out
// of this translation unit.
class TRIBE_Tree_Object : public RGE_Static_Object {
public:
    TRIBE_Tree_Object(TRIBE_Master_Tree_Object* master, RGE_Player* player,
                      float x, float y, float z, int do_setup);
};

#endif
