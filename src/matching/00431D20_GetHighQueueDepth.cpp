class RGE_Communications_Queue {
public:
    virtual ~RGE_Communications_Queue();
    int field_4;
    int GetHighQueueDepth();
};

int RGE_Communications_Queue::GetHighQueueDepth() { return this->field_4; }
