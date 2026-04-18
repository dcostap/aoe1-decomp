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
int TribeCivilianUnitAIModule::canAttackUnit(RGE_Static_Object* obj) {
    if (!obj) return 0;
    return obj->field_08->field_14 != 1;
}
