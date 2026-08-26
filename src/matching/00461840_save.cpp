// VA: 00461840 RGE_Master_Player::save (198 B)
// PDB source: mst_play.cpp
// Fix: vtable offset (save at slot 5 = 0x14), short loop counter
// TU proposal: src/mst_play_tu.cpp, with /GX from the two EH-bearing owners.
// Candidate validation: 7 exact owners, this observed owner, and 1 generated
// vector-deleting destructor all matched; no blocked owner was proposed.

#ifndef MST_PLAY_SHARED_CONTEXT
#include <stdlib.h>

extern "C" {
    void rge_write(int fd, void* buf, int size);
}

struct RGE_Master_Static_Object {
    void* vtable;
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object* param_1);
    virtual void modify(float param_1, unsigned char param_2);
    virtual void modify_delta(float param_1, unsigned char param_2);
    virtual void modify_percent(float param_1, unsigned char param_2);
    virtual void save(int fd);
};

class RGE_Master_Player {
public:
    virtual ~RGE_Master_Player();
    virtual void finish_init(int fd, void** sprites, void** sounds);
    virtual void load_master_object(int id, unsigned char type, void** sprites, void** sounds, short index);
    virtual void create_master_object_space(short count);
    virtual void load_object(void* file, unsigned char type, void** sprites, void** sounds, short index);
    virtual void save(int fd);

    char name[20];          
    short master_object_num; 
    unsigned char pad_1A[2];
    RGE_Master_Static_Object** master_objects;
    short attribute_num;
    unsigned char pad_22[2];
    float* attributes;
    unsigned char culture;
    unsigned char type;
    short tribe_effect;
};
#endif

void RGE_Master_Player::save(int fd)
{
    short i;
    
    rge_write(fd, &type, 1);
    rge_write(fd, name, 20);
    rge_write(fd, &attribute_num, 2);
    rge_write(fd, &tribe_effect, 2);
    
    if (attribute_num > 0) {
        rge_write(fd, attributes, attribute_num * 4);
    }
    
    rge_write(fd, &culture, 1);
    rge_write(fd, &master_object_num, 2);
    
    if (master_object_num > 0) {
        rge_write(fd, master_objects, master_object_num * 4);
        for (i = 0; i < master_object_num; i++) {
            if (master_objects[i] != 0) {
                ((RGE_Master_Static_Object*)master_objects[i])->save(fd);
            }
        }
    }
}
