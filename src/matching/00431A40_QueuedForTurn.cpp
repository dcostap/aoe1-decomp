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

unsigned int RGE_Communications_Queue::QueuedForTurn(unsigned long turn) {
    unsigned int count = 0;
    RGE_Communications_Queue_node* node = &this->Queue->ExecTurn;
    int depth = this->HighQueueDepth + 1;
    do {
        if (node->ExecTurn == turn) {
            ++count;
        }
        node = (RGE_Communications_Queue_node*)((char*)node + 0x1C);
        --depth;
    } while (depth != 0);
    return count;
}
