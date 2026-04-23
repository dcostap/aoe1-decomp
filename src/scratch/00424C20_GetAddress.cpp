class RGE_Communications_Addresses {
public:
    char gap_00[0x218];
    unsigned int AddressesAvailable;
    char gap_21C[0x04];
    char* pIPAD;

    char* GetAddress(unsigned int index);
};

char* RGE_Communications_Addresses::GetAddress(unsigned int index) {
    char* address = &this->pIPAD[index * 0xA0];

    if ((address == 0) || (this->AddressesAvailable < index)) {
        return (char*)0x00580460;
    }
    return address;
}
