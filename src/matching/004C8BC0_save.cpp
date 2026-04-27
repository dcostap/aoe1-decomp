// VA: 004C8BC0 TRIBE_Building_Object::save (234 B)
// PDB source: t_b_obj.cpp

extern "C" {
    void rge_write(int fd, void* buf, int size);
}

struct TRIBE_Combat_Object_Base {
    char base[0x1C8];
    void save(int fd);
};

struct RGE_Action_List {
    char base[4];
    void save(int fd);
};

struct TRIBE_Building_Object {
    char pad0[0x1C8];
    short* production_queue;         // +0x1C8
    short production_queue_size;     // +0x1CC
    short production_queue_count;    // +0x1CE
    unsigned char production_queue_enabled; // +0x1D0
    char pad1[3];                    // +0x1D1
    void* production_queue_actions;  // +0x1D4
    unsigned char production_queue_change_flag; // +0x1D8
    char pad2[3];                    // +0x1D9
    int build_pts;                   // +0x1DC
    int unique_build_id;             // +0x1E0
    unsigned char culture;           // +0x1E4
    unsigned char built;             // +0x1E5
    
    void save(int fd);
};

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
