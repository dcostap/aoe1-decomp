class RGE_Communications_Queue {
public:
    int field_0;
    int GetQueueDepth();
};

int RGE_Communications_Queue::GetQueueDepth() { return this->field_0; }
