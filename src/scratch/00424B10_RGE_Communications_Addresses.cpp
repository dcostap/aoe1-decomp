// tried the obvious destructor chain first: EraseInformation, conditional WSACleanup, then delete[] pIPAD
// if this misses, the remaining gap is likely just EH/helper spelling around the array teardown
extern "C" void __stdcall WSACleanup(void);

class IPAD {
public:
    char DottedIPAddress[32];
    char Alias[128];
};

class TCommunications_Handler;

class RGE_Communications_Addresses {
public:
    TCommunications_Handler* comm;
    char wsaData[0x190];
    char hostname[128];
    int Status;
    unsigned int AddressesAvailable;
    unsigned int AliasesAvailable;
    IPAD* pIPAD;

    void EraseInformation(void);
    ~RGE_Communications_Addresses(void);
};

void RGE_Communications_Addresses::~RGE_Communications_Addresses(void) {
    this->EraseInformation();
    if (this->Status != 0) {
        WSACleanup();
    }
    if (this->pIPAD != 0) {
        delete[] this->pIPAD;
    }
}
