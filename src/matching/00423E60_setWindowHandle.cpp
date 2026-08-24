#ifndef AOE1_CHAT_CONTEXT_H
class TChat {
public:
    int field_0;
    void setWindowHandle(void* v);
};
#endif

void TChat::setWindowHandle(void* v) { this->HostWnd = v; }
