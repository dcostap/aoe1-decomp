class RGE_Master_Static_Object {
public:
    char gap_00[0x14];
    short object_group;
};

class RGE_Static_Object {
public:
    char gap_00[0x08];
    RGE_Master_Static_Object* master_obj;
};

class TribeInformationAIModule {
public:
    int isBuilding(RGE_Static_Object* obj);
};

int TribeInformationAIModule::isBuilding(RGE_Static_Object* obj) {
    short group;

    group = obj->master_obj->object_group;
    if (group != 3 && group != 0x1B)
        return 0;
    return 1;
}
