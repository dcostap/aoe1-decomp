class RGE_Communications_Addresses {
public:
    char gap_00[0x21C];
    unsigned int AliasesAvailable;
    char* pIPAD;

    char* GetAlias(unsigned int index);
};

char* RGE_Communications_Addresses::GetAlias(unsigned int index) {
    char* alias;

    if (index > this->AliasesAvailable) {
        return (char*)0x00580460;
    }
    alias = &this->pIPAD[index * 0xA0 + 0x20];
    if (alias == 0) {
        return (char*)0x00580460;
    }
    return alias;
}
