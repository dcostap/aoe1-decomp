#ifndef COM_Q_CONTEXT
class RGE_Communications_Queue {
public:
    unsigned int FlushTurnRange(unsigned long p0, unsigned long p1);
    unsigned int FlushForTurn(unsigned long p);
};
#endif

unsigned int RGE_Communications_Queue::FlushForTurn(unsigned long p) {
    return this->FlushTurnRange(p, p);
}
