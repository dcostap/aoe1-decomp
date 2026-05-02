// VA: 00424B10 RGE_Communications_Addresses::~RGE_Communications_Addresses (67 B)
// PDB source: com_addr.cpp lines 82-90
//
// FLAGS: /GX (needed for _eh_vector_destructor_iterator on delete[] of non-trivial IPAD)
//
// Attempt log:
// 1. EraseInformation, conditional WSACleanup, delete[] pIPAD. First 32 bytes matched.
//    delete[] generated inline loop without /GX; /GX fixed it to _eh_vector_destructor_iterator.

extern "C" void __stdcall WSACleanup(void);
extern void* operator new(unsigned int size);
extern void operator delete(void* p);

class IPAD {
public:
    char DottedIPAddress[32];
    char Alias[128];

    ~IPAD() {}
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

RGE_Communications_Addresses::~RGE_Communications_Addresses() {
    this->EraseInformation();
    if (this->Status != 0) {
        WSACleanup();
    }
    if (this->pIPAD != 0) {
        delete[] this->pIPAD;
    }
}
