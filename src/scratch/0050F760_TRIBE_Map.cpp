// tried direct forwarding and then decompiler-shaped call variants
// remaining mismatch was in the exact forwarded parameter load/push order for the RGE_Map constructor
// paused here because the body is behaviorally right but the call sequence still drifts

class RGE_Sound;
class RGE_Map {
public:
    void* vtable_ptr;
    RGE_Map(char* param_1, char* param_2, char* param_3, char* param_4, short param_5, short param_6, short param_7, RGE_Sound** param_8);
};

class TRIBE_Map : public RGE_Map {
public:
    TRIBE_Map(char* param_1, char* param_2, char* param_3, char* param_4, short param_5, short param_6, short param_7, RGE_Sound** param_8);
};

TRIBE_Map::TRIBE_Map(char* param_1, char* param_2, char* param_3, char* param_4, short param_5, short param_6, short param_7, RGE_Sound** param_8)
    : RGE_Map(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8) {
    this->vtable_ptr = (void*)0x5767C8;
}
