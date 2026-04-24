// tact_dar.cpp - TRIBE_Action_Discovery_Artifact functions
// 5 functions: 3 constructors, update, check_objects
// PDB: C:\msdev\work\age1_x1\tact_dar.cpp, lines 32-165
//
// STATUS: initial draft, not yet compiled
// 3 unclaimed constructors (004CE530, 004CE5F0, 004CE670)
// update (004CE740) - state machine with timer check
// check_objects (004CE7A0) - nested grid loop with object iteration

#include "..\include\game_globals.h"

void rge_write(int file, void* data, int size);
void rge_read(int file, void* data, int size);

struct DiscoverySizeInfo {
    char gap_00[0x3C];
    short size;
};

struct DiscoveryInfo {
    char gap_00[0x3C];
    DiscoverySizeInfo* size_info;
};

struct DiscoveryMaster {
    char gap_00[0x0C];
    DiscoveryInfo* info;
};

class RGE_Action {
public:
    virtual void vf00(void);
    RGE_Action_Object* object;
    int mode;
    char gap_10[0x10];

    RGE_Action(int mode, RGE_Action_Object* object, int doSetup);
    RGE_Action(RGE_Action_Object* object, int do_setup);
    void set_target_obj(RGE_Static_Object* obj);
    void save(int file);
};

class RGE_Map {
public:
    short tileX;
    short tileY;
    char gap_04[0x24];
    int* map_data;
};

class RGE_Object_Info {
public:
    char gap_00[0x24];
    RGE_Map* map;
};

class RGE_Object_List {
public:
    int id;
    char gap_04[0x46];
    short player_index;
};

class TRIBE_Action_Discovery_Artifact : public RGE_Action {
public:
    float minX;
    float minY;
    float maxX;
    float maxY;
    RGE_Task* task;
    float timer;
    unsigned char state;
    char* flags;

    TRIBE_Action_Discovery_Artifact(int file, RGE_Action_Object* obj);
    TRIBE_Action_Discovery_Artifact(RGE_Action_Object* obj, RGE_Task* task, RGE_Static_Object* target);
    TRIBE_Action_Discovery_Artifact(RGE_Action_Object* obj, RGE_Task* task, float fx, float fy, float fx2, float fy2);
    unsigned char update();
    void set_state(unsigned char v);
    void check_objects();
    void save(int file);
};

TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact(int file, RGE_Action_Object* obj) {
    RGE_Action::RGE_Action(1, obj, 1);
    this->flags = (char*)calloc(
        ((DiscoveryMaster*)this->object)->info->size_info->size,
        1
    );
    rge_read(file, this->flags,
        ((DiscoveryMaster*)this->object)->info->size_info->size
    );
}

TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact(RGE_Action_Object* obj, RGE_Task* task, RGE_Static_Object* target) {
    RGE_Action::RGE_Action(obj, 1);
    this->task = task;
    this->mode = 1;
    set_target_obj(target);
    this->flags = (char*)calloc(
        ((DiscoveryMaster*)this->object)->info->size_info->size,
        1
    );
}

TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact(RGE_Action_Object* obj, RGE_Task* task, float fx, float fy, float fx2, float fy2) {
    RGE_Action::RGE_Action(obj, 1);
    this->task = task;
    this->minX = fx;
    this->minY = fy;
    this->maxX = fx2;
    this->maxY = fy2;
    this->mode = 1;
    this->flags = (char*)calloc(
        ((DiscoveryMaster*)this->object)->info->size_info->size,
        1
    );
}

unsigned char TRIBE_Action_Discovery_Artifact::update() {
    if (this->state == 1) {
        return 1;
    }
    if (this->state == 6) {
        check_objects();
        set_state(10);
        return 0;
    }
    if (this->state == 10) {
        this->timer -= DAT_00575078;
        if (this->timer <= (float)DAT_00575070) {
            set_state(6);
            return 0;
        }
    }
    return 0;
}

void TRIBE_Action_Discovery_Artifact::check_objects() {
    short x0, x1, y0, y1;
    int edi, i, j;
    RGE_Map* map;

    x1 = (short)__ftol(this->minX - DAT_00575078);
    y1 = (short)__ftol(this->maxX - DAT_00575078);
    x0 = (short)__ftol(this->minY + this->maxX - DAT_0057507c);
    y0 = (short)__ftol(this->minY + this->maxY - DAT_0057507c);

    map = ((RGE_Object_Info*)this->object)->map;

    if (x1 < 0) x1 = 0;
    if (x0 < 0) x0 = 0;
    if (y1 >= map->tileX) y1 = map->tileX - 1;
    if (x0 >= map->tileY) x0 = map->tileY - 1;

    if (x0 > y0) return;

    edi = 0x10;
    for (i = y1 - x0 + 1; i; ) {
        if (x1 <= y1) {
            for (j = y1 - x1 + 1; j; ) {
                int* obj_list = (int**)(map->map_data)[x1 * 4][edi + 0x10];
                // iterate objects...
                edi += 0x18;
                if (--j == 0) break;
            }
        }
        x1 += 4;
        if (--i == 0) break;
    }
}
