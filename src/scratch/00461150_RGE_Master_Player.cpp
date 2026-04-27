// VA: 00461150 ~RGE_Master_Player (123 B)
// PDB source: mst_play.cpp
// Attempt log:
// - Frees attributes and master_objects arrays
// - 3 references to free(), won't match without proper context
// - Left in scratch after shallow pass

#include <stdlib.h>

struct RGE_Master_Player_d {
    void* vtable;           
    char name[20];          
    short master_object_num; 
    void** master_objects;  
    short tribe_effect;     
    float* attributes;      
    char culture;           
    char type;              
    short attribute_num;    
    
    ~RGE_Master_Player_d();
};

RGE_Master_Player_d::~RGE_Master_Player_d()
{
    if (attributes) {
        free(attributes);
    }
    if (master_objects) {
        free(master_objects);
    }
}
