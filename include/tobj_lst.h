#ifndef AOE1_TOBJ_LST_H
#define AOE1_TOBJ_LST_H

// Compiler-facing declarations for C:\\msdev\\work\\age1_x1\\tobj_lst.cpp.
// The object-list and object hierarchies come from their canonical owners.
#include "obj_list.h"
#include "t_b_obj.h"

class TRIBE_Object_List : public RGE_Object_List {
protected:
    void load(unsigned char type, int mode, RGE_Game_World* world);
};

#endif
