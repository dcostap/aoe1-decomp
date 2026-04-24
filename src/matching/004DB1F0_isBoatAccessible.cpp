class RGE_Master_Static_Object {
public:
    char gap_00[0x10];
    short id;
    short copy_id;
    short object_group;
};

class RGE_Static_Object {
public:
    char gap_00[0x8];
    RGE_Master_Static_Object* master_obj;
};

class MainDecisionAIModule {
public:
    char gap_00[0x100];
    RGE_Static_Object* object(int param_1);
};

class TribeInformationAIModule {
public:
    char gap_00[0x100];
    MainDecisionAIModule* md;

    int isBoatAccessible(RGE_Static_Object* param_1, int param_2);
};

int TribeInformationAIModule::isBoatAccessible(RGE_Static_Object* param_1, int param_2) {
    RGE_Static_Object* obj = this->md->object(param_2);
    if (obj == 0) {
        return 0;
    }
    if (obj->master_obj->object_group == 0x15 || obj->master_obj->object_group == 2 || obj->master_obj->object_group == 0x14 || obj->master_obj->object_group == 0x16 || obj->master_obj->id == 0x2d) {
        return 1;
    }
    return 0;
}
