#include <winsock2.h>

#include "../include/RGE_Communications_Addresses.h"

#include <new>
#include <stdio.h>
#include <string.h>

static char s_empty_string[] = "";

IPAD::IPAD() {
    // Fully verified. Source of truth: com_addr.cpp.decomp @ 0x00424DD0
    this->DottedIPAddress[0] = '\0';
    this->Alias[0] = '\0';
}

IPAD::~IPAD() {
    // Fully verified. Source of truth: com_addr.cpp.decomp @ 0x00424E30
}

RGE_Communications_Addresses::RGE_Communications_Addresses(TCommunications_Handler* comm_) {
    // Source of truth: com_addr.cpp.decomp @ 0x004249D0
    this->comm = comm_;
    this->pIPAD = nullptr;

    this->EraseInformation();

    const int startup = WSAStartup(0x101, &this->wsaData);

    this->pIPAD = new (std::nothrow) IPAD[8];

    if (startup == 0) {
        this->Status = 1;
        (void)this->GetHostName();

        char* scratch = new (std::nothrow) char[0xFF];
        if (scratch != nullptr) {
            (void)this->SetIPAddresses(scratch);
            (void)this->SetIPAliases(scratch);
            delete[] scratch;
        }
    } else {
        this->Status = 0;
    }
}

RGE_Communications_Addresses::~RGE_Communications_Addresses() {
    // Source of truth: com_addr.cpp.decomp @ 0x00424B10
    this->EraseInformation();

    if (this->Status != 0) {
        (void)WSACleanup();
    }

    delete[] this->pIPAD;
    this->pIPAD = nullptr;
}

char* RGE_Communications_Addresses::GetHostName() {
    // Fully verified. Source of truth: com_addr.cpp.decomp @ 0x00424B60
    (void)gethostname(this->hostname, 0x80);
    return this->hostname;
}

int RGE_Communications_Addresses::SetIPAliases(char* /*scratch*/) {
    // Source of truth: com_addr.cpp.decomp @ 0x00424B80
    if (this->hostname[0] == '\0') {
        return 0;
    }

    hostent* host = gethostbyname(this->hostname);
    if (host == nullptr || host->h_aliases == nullptr) {
        return 0;
    }

    this->AliasesAvailable = 0;
    for (char** alias = host->h_aliases; *alias != nullptr; ++alias) {
        if (this->pIPAD == nullptr || this->AliasesAvailable >= 8) {
            break;
        }
        strncpy(this->pIPAD[this->AliasesAvailable].Alias, *alias, sizeof(this->pIPAD[0].Alias) - 1);
        this->pIPAD[this->AliasesAvailable].Alias[sizeof(this->pIPAD[0].Alias) - 1] = '\0';
        ++this->AliasesAvailable;
    }

    return (int)this->AliasesAvailable;
}

char* RGE_Communications_Addresses::GetAddress(uint index) {
    // Fully verified. Source of truth: com_addr.cpp.decomp @ 0x00424C20
    if (this->pIPAD == nullptr || index >= this->AddressesAvailable) {
        return s_empty_string;
    }
    return this->pIPAD[index].DottedIPAddress;
}

char* RGE_Communications_Addresses::GetAlias(uint index) {
    // Fully verified. Source of truth: com_addr.cpp.decomp @ 0x00424C50
    if (this->pIPAD == nullptr || index >= this->AliasesAvailable) {
        return s_empty_string;
    }
    const char* alias = this->pIPAD[index].Alias;
    if (alias == nullptr || alias[0] == '\0') {
        return s_empty_string;
    }
    return this->pIPAD[index].Alias;
}

int RGE_Communications_Addresses::SetIPAddresses(char* /*scratch*/) {
    // Source of truth: com_addr.cpp.decomp @ 0x00424C80
    if (this->hostname[0] == '\0') {
        return 0;
    }

    hostent* host = gethostbyname(this->hostname);
    if (host == nullptr || host->h_addr_list == nullptr) {
        return 0;
    }

    this->AddressesAvailable = 0;
    for (char** addr = host->h_addr_list; *addr != nullptr; ++addr) {
        if (this->pIPAD == nullptr || this->AddressesAvailable >= 8) {
            break;
        }

        const unsigned char* bytes = (const unsigned char*)*addr;
        char temp[25];
        sprintf(temp, "%d.%d.%d.%d", bytes[0], bytes[1], bytes[2], bytes[3]);

        strncpy(this->pIPAD[this->AddressesAvailable].DottedIPAddress, temp,
                sizeof(this->pIPAD[0].DottedIPAddress) - 1);
        this->pIPAD[this->AddressesAvailable].DottedIPAddress[sizeof(this->pIPAD[0].DottedIPAddress) - 1] = '\0';
        ++this->AddressesAvailable;
    }

    return (int)this->AddressesAvailable;
}

void RGE_Communications_Addresses::EraseInformation() {
    // Fully verified. Source of truth: com_addr.cpp.decomp @ 0x00424D90
    this->hostname[0] = '\0';
    this->AliasesAvailable = 0;
    this->AddressesAvailable = 0;
}

