#include "../include/com_addr.h"
#include <stdio.h>
#include <string.h>

// comm is at +0x00, Status is at +0x214, and pIPAD is at +0x220.
// The constructor calls EraseInformation, WSAStartup, the IPAD
// array construction, GetHostName, both address loaders, and buffer cleanup.
RGE_Communications_Addresses::RGE_Communications_Addresses(TCommunications_Handler* handler)
{
    this->comm = handler;
    this->EraseInformation();

    int wsResult = WSAStartup(0x101, &this->wsaData);

    this->pIPAD = new IPAD[8];

    if (wsResult != 0) {
        this->Status = 0;
    } else {
        this->Status = 1;
        this->GetHostName();
        char* buffer = new char[0xFF];
        this->SetIPAddresses(buffer);
        this->SetIPAliases(buffer);
        delete[] buffer;
    }
}

// Cleanup order is EraseInformation, conditional WSACleanup,
// then destruction of the IPAD array.
RGE_Communications_Addresses::~RGE_Communications_Addresses() {
    this->EraseInformation();
    if (this->Status != 0) {
        WSACleanup();
    }
    if (this->pIPAD != 0) {
        delete[] this->pIPAD;
    }
}

// hostname begins at +0x194 after the WSADATA member.
char* RGE_Communications_Addresses::GetHostName()
{
    gethostname(this->hostname, 0x80);
    return this->hostname;
}

// The method publishes a zero through the caller buffer, scans
// host aliases, copies each alias, and updates AliasesAvailable.
int RGE_Communications_Addresses::SetIPAliases(char* out_buffer)
{
    if (!hostname)
        return 0;

    struct hostent* he = gethostbyname(hostname);
    if (!he)
        return 0;

    *out_buffer = 0;

    char** alias_ptr = he->h_aliases;
    AliasesAvailable = 0;

    char* alias;
    while ((alias = *alias_ptr) != 0) {
        strcpy(pIPAD[AliasesAvailable].Alias, alias);
        AliasesAvailable++;
        alias_ptr++;
    }

    return AliasesAvailable;
}

// pIPAD[index] is formed before the count check. The fallback is
// the natural empty string literal used by the original source.
char* RGE_Communications_Addresses::GetAddress(unsigned int index) {
    if (this->pIPAD + index != 0 &&
        index <= this->AddressesAvailable) {
        return this->pIPAD[index].DottedIPAddress;
    }
    return "";
}

// The count check, indexed record access, null test, and fallback
// keep the shipped fault order.
char* RGE_Communications_Addresses::GetAlias(unsigned int index) {
    char* alias;

    // The alias count itself passes this test and selects the next record.
    // A >= correction would reject that shipped case and change malformed-input behavior.
    if (index > this->AliasesAvailable) {
        return "";
    }
    alias = this->pIPAD[index].Alias;
    if (alias == 0) {
        return "";
    }
    return alias;
}

// The method tests hostname, resolves the address list, publishes
// a zero through out_buffer, and then copies each formatted address.
int RGE_Communications_Addresses::SetIPAddresses(char* out_buffer)
{
    char temp[25];

    if (!hostname)
        return 0;

    struct hostent* host = gethostbyname(hostname);
    if (!host)
        return 0;

    *out_buffer = 0;

    char** address_ptr = host->h_addr_list;
    AddressesAvailable = 0;

    unsigned char* address;
    while ((address = (unsigned char*)*address_ptr) != 0) {
        sprintf(temp, "%d.%d.%d.%d\n",
                address[0], address[1], address[2], address[3]);
        strcat(out_buffer, temp);
        strcpy(pIPAD[AddressesAvailable].DottedIPAddress, temp);
        AddressesAvailable++;
        address_ptr++;
    }

    return AddressesAvailable;
}

// The method copies a natural empty string literal to hostname,
// then clears AliasesAvailable and AddressesAvailable.
void RGE_Communications_Addresses::EraseInformation(void) {
    strcpy(this->hostname, "");
    this->AliasesAvailable = 0;
    this->AddressesAvailable = 0;
}
