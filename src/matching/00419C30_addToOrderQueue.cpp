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
    int addToOrderQueue(OrderEvent* order, int param2);
};

int UnitAIModule::addToOrderQueue(OrderEvent* order, int param2) {
    return this->addToOrderQueue(order->issuer, order->orderType, order->range, order->targetZ, order->targetY, order->targetX, order->targetOwner, order->target, param2, order->priority);
}
