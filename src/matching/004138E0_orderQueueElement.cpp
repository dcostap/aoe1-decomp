struct OrderQueueEntry {
    char data[36];
};

class UnitAIModule {
public:
    char gap_00[0x10];
    int orderQueueSizeValue;
    char gap_14[0x04];
    OrderQueueEntry* orderQueueValue;

    OrderQueueEntry* orderQueueElement(int index) const;
};

OrderQueueEntry* UnitAIModule::orderQueueElement(int index) const {
    if ((index >= 0) && (index < this->orderQueueSizeValue) && (this->orderQueueValue != 0)) {
        return this->orderQueueValue + index;
    }
    return 0;
}
