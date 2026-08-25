// 00545D80 RGE_Game_World::object_ptr(int) -> RGE_Static_Object*
#include "../world_phase2_context.h"
// PDB: C:\msdev\work\age1_x1\World.cpp lines 3609-3630.
// BINARY NOTE: object() owns 00545D30-00545D73. Bytes 00545D74-00545D7F
// are alignment data before this wrapper. Keep object() as the owner of the
// object arrays, index guards, and pointer publication.
RGE_Static_Object* RGE_Game_World::object_ptr(int index) {
    return object(index);
}
