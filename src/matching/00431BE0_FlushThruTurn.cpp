class RGE_Communications_Queue {
public:
    void target_func(int p0, int p1);
    void FlushThruTurn(int p);
};

void RGE_Communications_Queue::FlushThruTurn(int p) { this->target_func(0, p); }
