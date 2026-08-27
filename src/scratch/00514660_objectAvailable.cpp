// VA: 00514660, TRIBE_Player::objectAvailable
// PDB: tplayer.cpp:1722-1727
// BINARY NOTE: master_objects is read at +0x24. The available byte is at
// +0x52 in RGE_Master_Static_Object; object 0x6D is always available.

#include "../../include/m_s_obj.h"
#include "../../include/tplayer.h"

int TRIBE_Player::objectAvailable(int obj_id)
{
    if ((master_objects[obj_id] != 0 &&
         master_objects[obj_id]->available) || obj_id == 0x6D) {
        return 1;
    }
    return 0;
}
