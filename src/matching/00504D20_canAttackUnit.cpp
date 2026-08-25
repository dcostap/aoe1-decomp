#ifndef TAIUAIMD_COMPLETE_TU
struct SubObj {
    char pad[0x14];
    short field_14;
};
struct RGE_Static_Object {
    char pad[0x08];
    SubObj* field_08;
};
class TribeCivilianUnitAIModule {
public:
    int canAttackUnit(RGE_Static_Object* obj);
};
#endif
int TribeCivilianUnitAIModule::canAttackUnit(RGE_Static_Object* obj) {
    if (!obj) return 0;
#ifdef TAIUAIMD_COMPLETE_TU
    return obj->master_obj->id != 1;
#else
    return obj->field_08->field_14 != 1;
#endif
}
