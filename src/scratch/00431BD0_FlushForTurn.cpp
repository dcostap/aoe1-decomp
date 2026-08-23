class RGE_Communications_Queue {
public:
    void target_func(int p0, int p1);
    void FlushForTurn(int p);
};

void RGE_Communications_Queue::FlushForTurn(int p) { this->target_func(p, p); }
