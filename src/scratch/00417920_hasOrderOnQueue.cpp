// tried explicit count/index locals; VC5 still chooses the wrong prolog register basin
// remaining gap is register-allocation/layout only; call set and loop logic are still right
class OrderEvent {
public:
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
public:
    void* vtable_ptr;
    void* objectValue;
    int moodValue;
    int objectCategoryValue;
    int orderQueueSizeValue;
    int orderQueueMaxSizeValue;
    OrderEvent* orderQueueValue;

    int hasOrderOnQueue(int param_1);
};

int UnitAIModule::hasOrderOnQueue(int param_1) {
    int count = this->orderQueueSizeValue;
    int index = 0;
    if (count <= 0) {
        return 0;
    }

    int* orderType = &this->orderQueueValue->orderType;
    do {
        if (*orderType == param_1) {
            return 1;
        }
        ++index;
        orderType += 9;
    } while (index < count);

    return 0;
}
