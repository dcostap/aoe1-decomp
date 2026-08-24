#ifndef COM_Q_CONTEXT
class RGE_Communications_Queue_node {
public:
    unsigned long ExecTurn;
    char gap_04[0x18];
};

class RGE_Communications_Queue {
public:
    char gap_00[0x114];
    RGE_Communications_Queue_node* Queue;
    int HighQueueDepth;

    unsigned int QueuedForTurn(unsigned long turn);
};
#endif

unsigned int RGE_Communications_Queue::QueuedForTurn(unsigned long turn) {
    unsigned int count = 0;
    unsigned int i = 0;
    do {
        if (this->Queue[i].ExecTurn == turn) {
            ++count;
        }
        ++i;
    } while (i <= this->HighQueueDepth);
    return count;
}
