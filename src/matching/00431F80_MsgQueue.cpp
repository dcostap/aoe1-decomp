void __cdecl operator delete(void* ptr);

class MsgQueue {
public:
    int Code;
    int ExecTurn;
    unsigned char SeqNo;
    char gap_09[3];
    char* msgptr;
    int From;
    int Size;
    int ControlCommand;

    ~MsgQueue();
};

MsgQueue::~MsgQueue() {
    this->Code = 0;
    this->ExecTurn = 0;
    this->SeqNo = 0;
    this->From = 0;
    this->Size = 0;
    this->ControlCommand = 0;
    if (this->msgptr != 0) {
        operator delete(this->msgptr);
    }
    this->msgptr = 0;
}
