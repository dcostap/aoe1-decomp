#include "../include/tm_tre_o.h"
#include "../include/t_tre_ob.h"

// PDB source: C:\\msdev\\work\\age1_x1\\tm_tre_o.cpp
// The definitions follow the original source order.

// PDB lines 21-27; VA 0050F180.
TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object(
    TRIBE_Master_Tree_Object* source, int do_setup)
    : RGE_Master_Static_Object(source, 0)
{
    if (do_setup != 0) {
        setup(source);
        master_type = 0x5A;
    }
}

// PDB lines 32-38; VA 0050F220.
TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object(
    int id, RGE_Sprite** sprites, RGE_Sound** sounds, int do_setup)
    : RGE_Master_Static_Object(id, sprites, sounds, 0)
{
    if (do_setup != 0) {
        setup(id, sprites, sounds);
        master_type = 0x5A;
    }
}

// PDB lines 43-49; VA 0050F2A0.
TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object(
    FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds,
    short id, int do_setup)
    : RGE_Master_Static_Object(file, sprites, sounds, id, 0)
{
    if (do_setup != 0) {
        setup(file, sprites, sounds, id);
        master_type = 0x5A;
    }
}

// PDB lines 53-55; VA 0050F320.
RGE_Static_Object* TRIBE_Master_Tree_Object::make_new_obj(
    RGE_Player* player, float x, float y, float z)
{
    return new TRIBE_Tree_Object(this, player, x, y, z, 1);
}

// PDB lines 59-61; VA 0050F3A0.
RGE_Master_Static_Object* TRIBE_Master_Tree_Object::make_new_master()
{
    return new TRIBE_Master_Tree_Object(this, 1);
}
