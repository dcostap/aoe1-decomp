// 004DA5F0 TribeInformationAIModule::addObjectMemory
// Size: 138 bytes

typedef int (*FtolFunc)();

class RGE_Static_Object {
public:
    char gap_00[4];
    int obj_id;                // +0x04
    void* master_obj;          // +0x08
    void* owner;               // +0x0C
    char gap_10[0x20];
    float field_30;            // +0x30
    char gap_34[4];
    float field_38;            // +0x38
    float field_3C;            // +0x3C
    float field_40;            // +0x40
};

class RGE_Master_Static_Object {
public:
    char gap_00[0x10];
    short master_id;           // +0x10
    short object_group;        // +0x14
};

class ObjectMemory;
class TribeInformationAIModule {
public:
    ObjectMemory* addObjectMemory(int id, short mid, short grp, int a, int b, int c, unsigned char d, int e, int f, int g, float h, float i, float j, RGE_Static_Object* obj);
    ObjectMemory* addObjectMemory(RGE_Static_Object* obj);
};

FtolFunc ftol_helper();

ObjectMemory* TribeInformationAIModule::addObjectMemory(RGE_Static_Object* obj) {
    if (obj == 0) {
        return 0;
    }

    int vt = *(int*)obj;
    RGE_Master_Static_Object* master = (RGE_Master_Static_Object*)obj->master_obj;

    return addObjectMemory(
        obj->obj_id,
        master->master_id,
        master->object_group,
        (int)((FtolFunc)*(int*)(vt + 0x10C))(),
        (int)((FtolFunc)*(int*)(vt + 0x100))(),
        (int)((FtolFunc)*(int*)(vt + 0x108))(),
        *(unsigned char*)((char*)obj->owner + 0x4A),
        (int)ftol_helper(), (int)ftol_helper(), (int)ftol_helper(),
        0.0f, 0.0f, 0.0f, obj);
}
