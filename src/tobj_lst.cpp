#include "../include/tobj_lst.h"

void TRIBE_Object_List::load(unsigned char object_type, int infile, RGE_Game_World* world) {
    switch (object_type) {
        case 'F':
            new TRIBE_Combat_Object(infile, world, 1);
            break;
        case 'P':
            new TRIBE_Building_Object(infile, world, 1);
            break;
        default:
            RGE_Object_List::load(object_type, infile, world);
            break;
    }
}
