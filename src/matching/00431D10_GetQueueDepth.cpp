#ifndef COM_Q_CONTEXT
class RGE_Communications_Queue {
public:
    unsigned int QueueDepth;
    int GetQueueDepth();
};
#endif

int RGE_Communications_Queue::GetQueueDepth() {
    return this->QueueDepth;
}
