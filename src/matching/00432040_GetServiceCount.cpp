#ifndef COM_SERV_TU_CONTEXT
class TCommunications_Services {
public:
    virtual ~TCommunications_Services();
    char gap_0[0x257C];
    int field_2580;
    int GetServiceCount();
};
#endif

int TCommunications_Services::GetServiceCount() { return this->field_2580; }
