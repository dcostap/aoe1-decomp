#ifndef COM_Q_CONTEXT
class RGE_Communications_Queue {
public:
    unsigned int QueueDepth;
    unsigned int HighQueueDepth;
    int GetHighQueueDepth();
};
#endif

int RGE_Communications_Queue::GetHighQueueDepth() {
    return this->HighQueueDepth;
}
