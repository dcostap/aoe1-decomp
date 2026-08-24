// VA: 00419C30 UnitAIModule::addToOrderQueue
// PDB owner/access: protected nonvirtual UnitAIModule::addToOrderQueue
// (?addToOrderQueue@UnitAIModule@@IAEHPAUOrderEvent@@H@Z), aiuaimod.cpp:5751-5755.
// Body boundary: 00419C30-00419C63; 00419C70 is the next sibling.
// EXACT MATCH: forwards the OrderEvent fields and param2 to the ten-int overload.
//
// Exact-finish notes:
// - REQUIRED: protected access restores the PDB-qualified IAEH owner ABI.
// - WALKBACK: public access emitted identical body bytes but the wrong QAEH owner.
// - BINARY NOTE: param2 is reread from its incoming home after the first push.
// - BINARY NOTE: the call is direct to 00419C70 and ret 8 cleans both parameters.

#ifndef AOE1_AIUAIMOD_COMPLETE_TU
struct OrderEvent {
    int issuer;
    int orderType;
    int priority;
    int range;
    int targetZ;
    int targetY;
    int targetX;
    int targetOwner;
    int target;
};

class UnitAIModule {
public:
    int addToOrderQueue(int issuer, int orderType, int range, int targetZ, int targetY, int targetX, int targetOwner, int target, int param2, int priority);

protected:
    int addToOrderQueue(OrderEvent* order, int param2);
};
#endif

int UnitAIModule::addToOrderQueue(OrderEvent* order, int param2) {
    return this->addToOrderQueue(order->issuer, order->orderType, order->range, order->targetZ, order->targetY, order->targetX, order->targetOwner, order->target, param2, order->priority);
}
