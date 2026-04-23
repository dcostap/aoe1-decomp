void __cdecl operator delete(void* ptr);

class RESENDER {
public:
    int TimeSent;
    int Serial;
    char* ResendMsg;
    int Length;
    unsigned int DestMap[10];

    ~RESENDER();
};

RESENDER::~RESENDER() {
    this->TimeSent = 0;
    if (this->ResendMsg != 0) {
        operator delete(this->ResendMsg);
    }
    this->ResendMsg = 0;
    this->Serial = 0;
    this->Length = 0;
    for (int i = 0; i < 10; i++) {
        this->DestMap[i] = 0;
    }
}
