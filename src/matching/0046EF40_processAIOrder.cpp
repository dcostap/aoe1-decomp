// attempt 1: player AI-order wrapper that resolves the object, checks unitAI twice, then forwards the packet to the unit AI vcall
// target shape: world->object(param_2); if object or unitAI is null return; call unitAI again and vcall +0x10 with the original push order

#ifndef PLAYER_GROUPED_TU
class UnitAIModule {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void processAIOrder(int param_1, int param_3, int param_4, int param_5, float param_6, float param_7, float param_8, float param_9, int param_10, int param_11, int param_12);
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_0[0x70];
    UnitAIModule* field_74;
    UnitAIModule* unitAI();
};

class RGE_Game_World {
public:
    char gap_00[0x3C];
    RGE_Static_Object* object(int id);
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;

    void processAIOrder(int param_1, int param_2, int param_3, int param_4, int param_5, float param_6, float param_7, float param_8, float param_9, int param_10, int param_11, int param_12);
};
#endif

void RGE_Player::processAIOrder(int param_1, int param_2, int param_3, int param_4, int param_5, float param_6, float param_7, float param_8, float param_9, int param_10, int param_11, int param_12) {
    RGE_Static_Object* obj;
    UnitAIModule* ai;

    obj = this->world->object(param_2);
    if (obj == 0) {
        return;
    }

    ai = obj->unitAI();
    if (ai == 0) {
        return;
    }

    ai = obj->unitAI();
    ai->processAIOrder(param_1, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12);
}
