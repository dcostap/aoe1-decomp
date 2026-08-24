// VA: 004C8490 TRIBE_Building_Object::setup (307 B)
// PDB source: t_b_obj.cpp
// Attempt log:
// - Initial natural load mirror from save.cpp and packet.

#include <stddef.h>

extern "C" {
    void rge_read(int fd, void* buf, int size);
    void* calloc(size_t count, size_t size);
}

extern float save_game_version;

#include "../../include/t_b_obj_context.h"

int TRIBE_Building_Object::setup(int fd, RGE_Game_World* world)
{
    ((TRIBE_Combat_Object_Base*)this)->setup(fd, world);
    this->type = 0x50;
    rge_read(fd, &this->built, 1);
    rge_read(fd, &this->build_pts, 4);
    rge_read(fd, &this->unique_build_id, 4);
    rge_read(fd, &this->culture, 1);
    this->production_queue_actions = this->create_action_list();

    if (save_game_version >= 7.21f) {
        short* psize = &this->production_queue_size;
        rge_read(fd, psize, 2);
        if (*psize > 0) {
            Production_Queue_Record* queue = (Production_Queue_Record*)calloc(*psize, 4);
            short i = 0;
            if (i < *psize) {
                this->production_queue = queue;
                do {
                    rge_read(fd, &this->production_queue[i * 2], 2);
                    rge_read(fd, &this->production_queue[i * 2 + 1], 2);
                    i++;
                } while (i < this->production_queue_size);
            } else {
                this->production_queue = queue;
            }
        }
        rge_read(fd, &this->production_queue_count, 2);
        rge_read(fd, &this->production_queue_enabled, 1);
        this->production_queue_actions->load(fd);
    }
    return 1;
}
