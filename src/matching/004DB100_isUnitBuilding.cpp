#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
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
    int isUnitBuilding(RGE_Static_Object* obj);
};
#endif

#endif
int TribeInformationAIModule::isUnitBuilding(RGE_Static_Object* obj) {
    RGE_Master_Object* mo = obj->master_obj;
    if (mo->object_group != 3) {
        return 0;
    }
    unsigned short id = mo->id;
    if (id == 0x6d || id == 0x0c || id == 0x57 || id == 0x31 || id == 0x2d || id == 0 || id == 0x65 || id == 0x68) {
        return 1;
    }
    return 0;
}
