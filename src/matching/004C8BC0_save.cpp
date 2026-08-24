// VA: 004C8BC0 TRIBE_Building_Object::save (234 B)
// PDB source: t_b_obj.cpp

#include "../../include/t_b_obj_context.h"

void TRIBE_Building_Object::save(int fd)
{
    ((TRIBE_Combat_Object_Base*)this)->save(fd);
    rge_write(fd, &built, 1);
    rge_write(fd, &build_pts, 4);
    rge_write(fd, &unique_build_id, 4);
    rge_write(fd, &culture, 1);
    rge_write(fd, &production_queue_size, 2);
    
    if (production_queue_size > 0) {
        for (short i = 0; i < production_queue_size; i++) {
            rge_write(fd, &production_queue[i * 2], 2);
            rge_write(fd, &production_queue[i * 2 + 1], 2);
        }
    }
    
    rge_write(fd, &production_queue_count, 2);
    rge_write(fd, &production_queue_enabled, 1);
    ((RGE_Action_List*)production_queue_actions)->save(fd);
}
