// PDB-qualified owner: RGE_Comm_Error::RGE_Comm_Error(void*), com_err.cpp:6-9.
// BINARY NOTE: The body is 00424E40-00424E51; padding/data starts at 00424E52.
// BINARY NOTE: 00424E22-00424E2F and 00424E31-00424E3F are padding/data around
// the one-byte IPAD::~IPAD sibling.  Do not claim synthetic owners for them.

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
