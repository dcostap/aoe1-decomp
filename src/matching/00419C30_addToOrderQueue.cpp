// VA: 00419C30 UnitAIModule::addToOrderQueue
// PDB owner/access: protected nonvirtual UnitAIModule::addToOrderQueue
// (?addToOrderQueue@UnitAIModule@@IAEHPAUOrderEvent@@H@Z), aiuaimod.cpp:5751-5755.
// Body boundary: 00419C30-00419C63; 00419C70 is the next sibling.
// EXACT MATCH: forwards the OrderEvent fields and param2 to the ten-parameter overload.
//
// Exact-finish notes:
// - REQUIRED: protected access restores the PDB-qualified IAEH owner ABI.
// - WALKBACK: public access emitted identical body bytes but the wrong QAEH owner.
// - REQUIRED: the sibling ABI is four ints, four floats, then two ints; an
//   all-int donor declaration created a synthetic direct target.
// - BINARY NOTE: param2 is reread from its incoming home after the first push.
// - BINARY NOTE: the call is direct to 00419C70 and ret 8 cleans both parameters.

#ifndef AOE1_AIUAIMOD_COMPLETE_TU
struct OrderEvent {
    int issuer;
    int orderType;
    int priority;
    int target;
    int targetOwner;
    float targetX;
    float targetY;
    float targetZ;
    float range;
};

class UnitAIModule {
protected:
    int addToOrderQueue(int issuer, int orderType, int target, int targetOwner,
                        float targetX, float targetY, float targetZ, float range,
                        int param2, int priority);
    int addToOrderQueue(OrderEvent* order, int param2);
};
#endif

int UnitAIModule::addToOrderQueue(OrderEvent* order, int param2) {
    return this->addToOrderQueue(order->issuer, order->orderType,
                                 order->target, order->targetOwner,
                                 order->targetX, order->targetY,
                                 order->targetZ, order->range,
                                 param2, order->priority);
}
