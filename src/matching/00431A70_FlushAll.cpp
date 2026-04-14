class MsgQueue {
public:
    void Flush(int a, int b);
    void FlushAll();
};

void MsgQueue::FlushAll() {
    this->Flush(0, 0);
}
