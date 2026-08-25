// 004DA5F0 TribeInformationAIModule::addObjectMemory
// try 1: model real virtual float getters at dispatch table slots and natural forwarding overload.

#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
class ObjectMemory;
class RGE_Master_Static_Object { public: char gap_00[0x10]; short master_id; char gap_12[2]; short object_group; };
class RGE_Player { public: char gap_00[0x4A]; unsigned char id; };

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual float get100();
    virtual float get108();
    virtual float get10C();

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

#ifndef TAIINFMD_PREFIX_CONTEXT
class TribeInformationAIModule {
public:
    ObjectMemory* addObjectMemory(int id, short mid, short grp, int a, int b, int c, unsigned char d, int e, int f, int g, float h, float i, float j, RGE_Static_Object* obj);
    ObjectMemory* addObjectMemory(RGE_Static_Object* obj);
};
#endif
#endif

#endif
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
                           obj->get108(),
                           obj->get100(),
                           obj->get10C(),
                           obj);
}
