#ifndef TAITACMD_SHARED_CONTEXT
// 004F9470 TribeTacticalAIModule::highLevelTaskExplorer
// Source: taitacmd.cpp lines 7907-7983
// Attempt log:
// - Replaced the parked wrapper/raw-offset scaffold with the packet-supported
//   typed explorer predicate: world->object, repeated UnitAI calls, current
//   action/order checks, held-attribute gate, and taskExplorer(this,id,mode).
// - Member-left positive held-attribute rejection recovered the original x87
//   compare/branch. Nesting the final object->unitAI()->hasOrderOnQueue(0x2C1)
//   call restored VC5's push-before-object evaluation order and matched exactly.
// - Main-agent audit restored canonical polymorphic object/player/world/AI
//   ownership; exact bytes were revalidated after promotion.

#ifndef TAITACMD_SHARED_CONTEXT
class UnitAIModule {
public:
    int currentOrder();
    int currentOrderPriority();
    int currentAction();
    int hasOrderOnQueue(int order);
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_04[0x40];
    float attribute_amount_held;

    UnitAIModule* unitAI();
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    RGE_Static_Object* object(int id);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world;
};

class TribeMainDecisionAIModule {
public:
    virtual ~TribeMainDecisionAIModule();
    char gap_04[0xEC];
    RGE_Player* player;
};

class TribeTacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
    char gap_04[0xEC];
    TribeMainDecisionAIModule* md;

    int taskExplorer(int id, int mode);
    int highLevelTaskExplorer(int id, int mode);
};

#endif
int TribeTacticalAIModule::highLevelTaskExplorer(int id, int mode)
{
    RGE_Static_Object* object = this->md->player->world->object(id);
    if (object == 0 || object->unitAI() == 0) {
        return 0;
    }

    UnitAIModule* ai = object->unitAI();
    int action = ai->currentAction();
    if (action == 0x258) {
        return 1;
    }

    ai = object->unitAI();
    action = ai->currentAction();
    if (action != 0x25A) {
        ai = object->unitAI();
        action = ai->currentAction();
        if (action != 0x26A) {
            ai = object->unitAI();
            action = ai->currentAction();
            if (action == 0x25D) {
                return 1;
            }

            if (object->attribute_amount_held > 0.0f) {
                return 0;
            }

            ai = object->unitAI();
            if (ai->currentOrder() == 0x2C6) {
                ai = object->unitAI();
                if (ai->currentOrderPriority() == 100) {
                    return 0;
                }
            }

            ai = object->unitAI();
            if (ai->currentOrder() == 0x2BE) {
                return 0;
            }

            if (object->unitAI()->hasOrderOnQueue(0x2C1) == 1) {
                return 0;
            }

            return this->taskExplorer(id, mode) != 0;
        }
    }
    return 1;
}
#else
int TribeTacticalAIModule::highLevelTaskExplorer(int, int) { return 0; }
#endif
