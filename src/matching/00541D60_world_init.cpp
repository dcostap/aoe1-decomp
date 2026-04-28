// 00541D60 RGE_Game_World::world_init
// PDB: World.cpp:858-867, 76 bytes
// FLAGS: default
//
// Fixed: init_40/init_48 take TSound_Driver* (param_2), not TCommunications_Handler*.
// init_54 takes TCommunications_Handler* (param_3), not TSound_Driver*.
// The names init_3c/init_38 are slot numbers, not meaningful identifiers — the
// association between slot and argument type was wrong in the original scratch.
class TSound_Driver;
class TCommunications_Handler;

class RGE_Game_World {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void init_3c(int param_1);
    virtual void init_38(int param_1);
    virtual void init_40(int param_1, TSound_Driver* param_2);
    virtual void init_44(int param_1);
    virtual void init_48(int param_1, TSound_Driver* param_2);
    virtual void init_4c(int param_1);
    virtual void init_50(int param_1);
    virtual void init_54(int param_1, TCommunications_Handler* param_2);

    char gap_04[0x3F0];

    void world_init(int param_1, TSound_Driver* param_2, TCommunications_Handler* param_3);
};

void RGE_Game_World::world_init(int param_1, TSound_Driver* param_2, TCommunications_Handler* param_3) {
    this->init_38(param_1);
    this->init_3c(param_1);
    this->init_40(param_1, param_2);
    this->init_44(param_1);
    this->init_48(param_1, param_2);
    this->init_4c(param_1);
    this->init_50(param_1);
    this->init_54(param_1, param_3);
}
