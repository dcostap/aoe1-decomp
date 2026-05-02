// VA: 00424C20 GetAddress (40B, com_addr.cpp)
// RGE_Communications_Addresses::GetAddress
class RGE_Communications_Addresses {
public:
    char gap_00[0x218];
    unsigned int AddressesAvailable;
    unsigned int AliasesAvailable;
    char* pIPAD;

    char* GetAddress(unsigned int index);
};

char* RGE_Communications_Addresses::GetAddress(unsigned int index) {
    if (this->pIPAD + index * 0xA0 != 0 && index <= this->AddressesAvailable) {
        return this->pIPAD + index * 0xA0;
    }
    return (char*)0x580460;
}
