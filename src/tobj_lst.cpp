// PDB source module: C:\\msdev\\work\\age1_x1\\tobj_lst.cpp.
// The definition follows the original source-line and address order.
//
// PDB: tobj_lst.cpp:24-37; 00511B00
// BINARY NOTE: The shipped body uses a switch for the F/P dispatch. The
// constructors and the virtual base destructor require the module's /GX context.

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
