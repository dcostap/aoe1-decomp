// attempt 1: EXACT MATCH - natural ctor, Service[100] array (Name[80] + 4 ints at 0x50-0x5C),
//   loop copies empty string via rep movs, zeros 4 ints per element, then DirectPlayEnumerateA
//   Key: ServiceCount at offset 0x2580 (right after 100*96=0x2580), loop step 0x60=96 bytes

#include <string.h>

#ifndef COM_SERV_TU_CONTEXT
struct GUID {};

extern "C" void __stdcall DirectPlayEnumerateA(void* callback, void* lpContext);
void __stdcall DPEnumCallback(const GUID* param_1, char* param_2, unsigned long param_3, unsigned long param_4, void* param_5);

struct Service_Entry {
    char Name[80];
    int field_50;
    int field_54;
    int field_58;
    int Active;
};

class TCommunications_Services {
public:
    Service_Entry Service[100];
    int ServiceCount;

public:
    TCommunications_Services();

    int GetServiceCount();
    void SetServiceName(int index, const char* name);
    void EnumServiceGUID(int index, const GUID* guid);
    void SetServiceActive(int index, int active);
    int IncServiceCount();
};
#endif

TCommunications_Services::TCommunications_Services() {
    this->ServiceCount = 0;

    for (int i = 0; i < 100; i++) {
        strcpy(this->Service[i].Name, "");
        this->Service[i].field_50 = 0;
        this->Service[i].Active = 0;
        this->Service[i].field_58 = 0;
        this->Service[i].field_54 = 0;
    }

    DirectPlayEnumerateA(DPEnumCallback, this);
}
