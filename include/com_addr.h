#ifndef AOE1_COM_ADDR_H
#define AOE1_COM_ADDR_H

#include <winsock.h>
#include <string.h>

class TCommunications_Handler;
class TribeMPSetupScreen;

class IPAD {
  public:
    char DottedIPAddress[0x20];
    char Alias[0x80];

    IPAD() {
        strcpy(this->DottedIPAddress, "");
        strcpy(this->Alias, "");
    }
    ~IPAD() {
    }
};

class RGE_Communications_Addresses {
    friend class TribeMPSetupScreen;

  private:
    TCommunications_Handler* comm;   // +0x00
    WSADATA wsaData;                 // +0x04
    char hostname[0x80];             // +0x194
    int Status;                      // +0x214
    unsigned int AddressesAvailable; // +0x218
    unsigned int AliasesAvailable;   // +0x21C
    IPAD* pIPAD;                     // +0x220

  public:
    RGE_Communications_Addresses(TCommunications_Handler* CommIn);
    ~RGE_Communications_Addresses();
    char* GetHostName();

  protected:
    int SetIPAliases(char* sz);
    int SetIPAddresses(char* sz);
    void EraseInformation();

  public:
    char* GetAddress(unsigned int Num);
    char* GetAlias(unsigned int Num);
};

typedef char com_addr_size_check[(sizeof(RGE_Communications_Addresses) == 0x224) ? 1 : -1];
typedef char ipad_size_check[(sizeof(IPAD) == 0x0A0) ? 1 : -1];

#endif
