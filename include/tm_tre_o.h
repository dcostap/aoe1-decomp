#ifndef AOE1_TM_TRE_O_H
#define AOE1_TM_TRE_O_H

//
// RGE_Master_Static_Object comes from its canonical owner header.
// This header adds only the tree-master declaration owned here.

#include "m_s_obj.h"

struct _iobuf;
typedef struct _iobuf FILE;

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

typedef char tribe_master_tree_object_size_check[
    (sizeof(TRIBE_Master_Tree_Object) == 0xB8) ? 1 : -1];

#endif
