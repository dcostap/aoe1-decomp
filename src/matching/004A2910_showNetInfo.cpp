// VA: 004A2910 TribeMPSetupScreen::showNetInfo
// Attempt log:
// 1: natural reconstruction from packet using real new/ctor/delete and strcat/sprintf.
// 2: /GX required for original EH frame; class size padded to 0x224 to match operator new size.
// 3: OKDialog prototype/call order is (message,title,line,height), not decompiler-looking title,line,message,height.

extern "C" int __cdecl sprintf(char*, const char*, ...);
extern "C" char* __cdecl strcat(char*, const char*);
extern "C" char* __cdecl strcpy(char*, const char*);

struct RGE_Communications;
extern RGE_Communications* comm;

struct RGE_Communications_Addresses {
    RGE_Communications_Addresses(RGE_Communications*);
    ~RGE_Communications_Addresses();
    char* GetHostName();
    char* GetAddress(unsigned int);
    char* GetAlias(unsigned int);
    char gap_0[0x220];
    unsigned int num_addr;
};

class TribeMPSetupScreen {
public:
    char* get_string(int);
    void OKDialog(char*, int, int, int);
    void ErrorDialog(int, int, int, int);
    void showNetInfo();
};

void TribeMPSetupScreen::showNetInfo()
{
    char message[1024];
    char temp_str[256];

    RGE_Communications_Addresses* addresses = new RGE_Communications_Addresses(comm);
    if (addresses) {
        unsigned int num_addr = *(unsigned int*)((char*)addresses + 0x218);
        message[0] = 0;
        if (num_addr > 0) {
            strcat(message, (char*)0x005868AC);
            sprintf(temp_str, this->get_string(0x238c), addresses->GetHostName());
            strcat(message, temp_str);
            strcat(message, (char*)0x00583994);
            for (unsigned int i = 0; i < num_addr; i++) {
                if (addresses->GetAddress(i)) {
                    strcat(message, addresses->GetAddress(i));
                    strcat(message, (char*)0x00580460);
                }
                if (addresses->GetAlias(i)) {
                    strcat(message, addresses->GetAlias(i));
                }
                strcat(message, (char*)0x00583994);
            }
            this->OKDialog(message, 0x584eb4, 0x1c2, num_addr * 18 + 100);
        } else {
            this->ErrorDialog(0x238d, 0, 0x1c2, 100);
        }
        addresses->~RGE_Communications_Addresses();
        operator delete(addresses);
    }
}
