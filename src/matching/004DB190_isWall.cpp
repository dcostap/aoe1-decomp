struct SubObj { char pad[0x14]; short field_14; };
struct RGE_Static_Object { char pad[0x08]; SubObj* field_08; };
class TribeInformationAIModule {
public:
    int isWall(RGE_Static_Object* obj);
};
int TribeInformationAIModule::isWall(RGE_Static_Object* obj) {
    return obj->field_08->field_14 == 0x1B;
}
