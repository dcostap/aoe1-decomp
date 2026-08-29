#include "../include/tm_tre_o.h"
#include "../include/t_tre_ob.h"


TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object(
    TRIBE_Master_Tree_Object* source, int do_setup)
    : RGE_Master_Static_Object(source, 0)
{
    if (do_setup != 0) {
        setup(source);
        master_type = 0x5A;
    }
}

TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object(
    int id, RGE_Sprite** sprites, RGE_Sound** sounds, int do_setup)
    : RGE_Master_Static_Object(id, sprites, sounds, 0)
{
    if (do_setup != 0) {
        setup(id, sprites, sounds);
        master_type = 0x5A;
    }
}

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

RGE_Static_Object* TRIBE_Master_Tree_Object::make_new_obj(
    RGE_Player* player, float x, float y, float z)
{
    return new TRIBE_Tree_Object(this, player, x, y, z, 1);
}

RGE_Master_Static_Object* TRIBE_Master_Tree_Object::make_new_master()
{
    return new TRIBE_Master_Tree_Object(this, 1);
}
