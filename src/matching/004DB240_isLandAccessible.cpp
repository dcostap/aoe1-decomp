#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
class RGE_Master_Object {
public:
    char gap_00[0x14];
    short object_group;
};

class RGE_Static_Object {
public:
    char gap_00[0x8];
    RGE_Master_Object* master_obj;
};

class MainDecisionAIModule {
public:
    char gap_000[0x100];
    RGE_Static_Object* object(int);
};

class TribeInformationAIModule {
public:
    char gap_0000[0x100];
    MainDecisionAIModule* md;

    int isLandAccessible(RGE_Static_Object* param_1, int param_2);
};
#endif

#endif
int TribeInformationAIModule::isLandAccessible(RGE_Static_Object* param_1, int param_2) {
    RGE_Static_Object* object = md->object(param_2);
    if (object != 0) {
        short group = object->master_obj->object_group;
        if (group != 0x15 && group != 2 && group != 0x14 && group != 0x16) {
            return 1;
        }
    }
    return 0;
}
