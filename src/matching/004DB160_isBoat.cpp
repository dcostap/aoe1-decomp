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
    int isBoat(RGE_Static_Object* obj);
};

int TribeInformationAIModule::isBoat(RGE_Static_Object* obj) {
    short group;

    group = obj->master_obj->object_group;
    if (group != 0x15 && group != 2 && group != 0x14 && group != 0x16)
        return 0;
    return 1;
}
