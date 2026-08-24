#ifndef AOE1_CHAT_CONTEXT_H
class TChat {
public:
    virtual ~TChat();
    int MaxArraySize();
};
#endif

int TChat::MaxArraySize() { return 50; }
