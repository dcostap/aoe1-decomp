struct OrderQueueEntry {
    char data[36];
};

struct SomeClass {
    char gap_0[0xD4];
    OrderQueueEntry orderQueue[25];
    int numberOrders;
};

OrderQueueEntry* __fastcall orderQueueElement(SomeClass* self, int, int index) {
    if (index < 0)
        return 0;
    if (index >= self->numberOrders)
        return 0;
    return &self->orderQueue[index];
}
