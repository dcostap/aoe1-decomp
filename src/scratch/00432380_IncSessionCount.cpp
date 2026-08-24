#ifndef COM_SESS_TU_CONTEXT
class TCommunications_Sessions {
public:
    int SessionCount;
    int IncSessionCount();
};
#endif

int TCommunications_Sessions::IncSessionCount() {
    int value = this->SessionCount + 1;
    this->SessionCount = value;
    return value;
}
