// VA: 00424C20 GetAddress (40B, com_addr.cpp)
// RGE_Address::GetAddress - simple getter
// TODO: implement with correct class layout

class RGE_Address {
public:
    char gap_00[4];
    char ip[16];    // placeholder
    
    char* GetAddress();
};

char* RGE_Address::GetAddress() {
    return this->ip;
}
