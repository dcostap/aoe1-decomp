// VA: 004611D0 RGE_Master_Player::finish_init (153 B)
// PDB source: mst_play.cpp

#include <stdlib.h>

extern "C" {
    void rge_read(int fd, void* buf, int size);
}

struct RGE_Master_Player_fi {
    void* vtable;           
    char name[20];          
    short master_object_num;// +0x18
    void** master_objects;  // +0x1C
    short tribe_effect;     // +0x20
    float* attributes;      // +0x24
    char culture;           // +0x28
    char type;              // +0x29
    short attribute_num;    // +0x2A
    
    void finish_init(int fd, void** sprites, void** sounds);
};

void RGE_Master_Player_fi::finish_init(int fd, void** sprites, void** sounds)
{
    rge_read(fd, &master_object_num, 2);
    if (master_object_num > 0) {
        master_objects = (void**)calloc(master_object_num, 4);
        rge_read(fd, master_objects, master_object_num * 4);
        for (int i = 0; i < master_object_num; i++) {
            if (master_objects[i] != 0) {
                rge_read(fd, &fd, 1);
                // virtual call at vtable[8] for load_master_object
                // This needs sized-struct for RGE_Master_Static_Object
            }
        }
    } else {
        master_objects = 0;
    }
}
