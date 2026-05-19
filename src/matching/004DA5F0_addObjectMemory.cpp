// 004DA5F0 TribeInformationAIModule::addObjectMemory
// try 1: model real virtual float getters at vtable slots and natural forwarding overload.

class ObjectMemory;
class RGE_Master_Static_Object { public: char gap_00[0x10]; short master_id; char gap_12[2]; short object_group; };
class RGE_Player { public: char gap_00[0x4A]; unsigned char id; };

#define VPAD1(n) virtual void pad##n() {}
#define VPAD2(n) VPAD1(n) VPAD1(n##_a)
#define VPAD4(n) VPAD2(n) VPAD2(n##_b)
#define VPAD8(n) VPAD4(n) VPAD4(n##_c)
#define VPAD16(n) VPAD8(n) VPAD8(n##_d)
#define VPAD32(n) VPAD16(n) VPAD16(n##_e)

class RGE_Static_Object {
public:
    VPAD32(0) VPAD16(32) VPAD8(48) VPAD4(56) VPAD4(60)
    virtual float vf100();
    VPAD1(65)
    virtual float vf108();
    virtual float vf10C();

    int obj_id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x20];
    float field_30;
    char gap_34[4];
    float field_38;
    float field_3C;
    float field_40;
};

class TribeInformationAIModule {
public:
    ObjectMemory* addObjectMemory(int id, short mid, short grp, int a, int b, int c, unsigned char d, int e, int f, int g, float h, float i, float j, RGE_Static_Object* obj);
    ObjectMemory* addObjectMemory(RGE_Static_Object* obj);
};

ObjectMemory* TribeInformationAIModule::addObjectMemory(RGE_Static_Object* obj) {
    if (obj == 0) return 0;
    return addObjectMemory(obj->obj_id,
                           obj->master_obj->master_id,
                           obj->master_obj->object_group,
                           (int)obj->field_38,
                           (int)obj->field_3C,
                           (int)obj->field_40,
                           obj->owner->id,
                           (int)obj->field_30,
                           0,
                           0,
                           obj->vf108(),
                           obj->vf100(),
                           obj->vf10C(),
                           obj);
}
