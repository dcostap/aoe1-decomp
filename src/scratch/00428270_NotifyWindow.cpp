class TCommunications_Handler {
public:
    void target_func(int p0, int p1);
    void NotifyWindow(int p);
};

void TCommunications_Handler::NotifyWindow(int p) { this->target_func(p, 0); }
