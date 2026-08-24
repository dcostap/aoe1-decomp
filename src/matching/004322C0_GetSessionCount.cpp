#ifndef COM_SESS_TU_CONTEXT
class TCommunications_Sessions {
public:
    int field_0;
    int GetSessionCount();
};
#endif

int TCommunications_Sessions::GetSessionCount() { return this->field_0; }
