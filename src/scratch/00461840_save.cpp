// VA: 00461840 RGE_Master_Player::save (198 B)
// PDB source: mst_play.cpp
// Fix: vtable offset (save at slot 5 = 0x14), short loop counter

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

struct RGE_Master_Player_s {
    void* vtable;           
    char name[20];          
    short master_object_num; 
    void** master_objects;  
    short tribe_effect;     
    float* attributes;      
    char culture;           
    char type;              
    short attribute_num;  
    
    void save(int fd);
};

void RGE_Master_Player_s::save(int fd)
{
    short i;
    
    rge_write(fd, &type, 1);
    rge_write(fd, name, 20);
    rge_write(fd, &tribe_effect, 2);
    rge_write(fd, &attribute_num, 2);
    
    if (tribe_effect > 0) {
        rge_write(fd, attributes, tribe_effect * 4);
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
