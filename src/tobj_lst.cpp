//
// The shipped body uses a switch for the F/P dispatch. The

#include "../include/tobj_lst.h"

void TRIBE_Object_List::load(unsigned char type, int mode, RGE_Game_World* world)
{
    switch (type) {
    case 'F':
        new TRIBE_Combat_Object(mode, world, 1);
        break;
    case 'P':
        new TRIBE_Building_Object(mode, world, 1);
        break;
    default:
        RGE_Object_List::load(type, mode, world);
        break;
    }
}
