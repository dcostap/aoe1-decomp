class RGE_Master_Object {
public:
    char gap_00[0x10];
    unsigned short id;
    char gap_12[0x02];
    unsigned short object_group;
};

class RGE_Static_Object {
public:
    char gap_00[0x08];
    RGE_Master_Object* master_obj;
};

class TribeInformationAIModule {
public:
    int isBoat(RGE_Static_Object* obj);
};

int TribeInformationAIModule::isBoat(RGE_Static_Object* obj) {
    unsigned short group = obj->master_obj->object_group;
    if (group == 0x15 || group == 2 || group == 0x14 || group == 0x16) {
        return 1;
    }
    return 0;
}
