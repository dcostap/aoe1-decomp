class RESENDER {
public:
    int TimeSent;
    char* ResendMsg;
    int Serial;
    int Length;
    unsigned int DestMap[10];

    RESENDER();
};

RESENDER::RESENDER() {
    int i;

    TimeSent = 0;
    Serial = 0;
    ResendMsg = 0;
    Length = 0;
    for (i = 0; i < 10; i++) {
        DestMap[i] = 0;
    }
}
