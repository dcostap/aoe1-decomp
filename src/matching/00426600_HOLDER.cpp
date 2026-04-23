class HOLDER {
public:
    char* HoldMsg;
    int Serial;
    int Length;
    int dcoFromID;
    int dcoReceiveID;

    ~HOLDER();
};

HOLDER::~HOLDER() {
    if (this->HoldMsg != 0) {
        ::operator delete(this->HoldMsg);
    }
    this->HoldMsg = 0;
    this->Serial = 0;
    this->Length = 0;
    this->dcoFromID = 0;
    this->dcoReceiveID = 0;
}
