// VA: 00424B10 RGE_Communications_Addresses::~RGE_Communications_Addresses (67 B)
// PDB source: com_addr.cpp lines 82-90
//
// FLAGS: /GX (needed for _eh_vector_destructor_iterator on delete[] of non-trivial IPAD)
//
// Attempt log:
// 1. EraseInformation, conditional WSACleanup, delete[] pIPAD. First 32 bytes matched.
//    delete[] generated inline loop without /GX; /GX fixed it to _eh_vector_destructor_iterator.
// 2. Replaced the raw 0x190-byte wsaData member with canonical WSADATA; bytes stayed exact.
// 3. Removing the non-trivial IPAD destructor removed the iterator call and changed the boundary.

// BINARY NOTE: The qualified owner is RGE_Communications_Addresses::~RGE_Communications_Addresses.
// Its body is 00424B10-00424B52 inclusive; 00424B53 starts padding.
// BINARY NOTE: WSADATA starts at +0x04, hostname at +0x194, and IPAD elements are 0xA0 bytes.
// BINARY NOTE: Cleanup order is EraseInformation, conditional WSACleanup, then IPAD destruction.

#include "..\..\include\game_globals.h"

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
    WSADATA wsaData;
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
