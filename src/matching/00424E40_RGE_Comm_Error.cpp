class RGE_Comm_Error {
public:
    void* HostHWND;
    int LastReportedError;

    RGE_Comm_Error(void* param);
};

RGE_Comm_Error::RGE_Comm_Error(void* param) {
    HostHWND = param;
    LastReportedError = 0;
}
