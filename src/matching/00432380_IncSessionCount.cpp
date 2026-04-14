class TCom_Speed_Data {
public:
    volatile int sessionCount;
    void IncSessionCount();
};

void TCom_Speed_Data::IncSessionCount() {
    this->sessionCount = this->sessionCount + 1;
}
