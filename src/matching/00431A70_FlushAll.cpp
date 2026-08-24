#ifndef COM_Q_CONTEXT
class RGE_Communications_Queue {
public:
    void FlushTurnRange(unsigned long first, unsigned long last);
    void FlushAll();
};
#endif

void RGE_Communications_Queue::FlushAll() {
    this->FlushTurnRange(0, 0);
}
