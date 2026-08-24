#ifndef COM_Q_CONTEXT
class RGE_Communications_Queue {
public:
    unsigned int FlushTurnRange(unsigned long p0, unsigned long p1);
    unsigned int FlushThruTurn(unsigned long p);
};
#endif

unsigned int RGE_Communications_Queue::FlushThruTurn(unsigned long p) {
    return this->FlushTurnRange(0, p);
}
