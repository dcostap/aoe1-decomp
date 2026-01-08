#pragma once
#include "../common.h"

class TCommunications_Services       {
public:
    SPs Service[100];                        // 0x0
    int ServiceCount;                        // 0x2580

    TCommunications_Services();

    // --- Non-Virtual Destructor ---
    ~TCommunications_Services() noexcept(false);
    // --- Non-Virtual Members ---
    int GetServiceCount();
    int IncServiceCount();
    char* GetServiceName(int param_1);
    int SetServiceName(int param_1, char* param_2);
    _GUID* GetServiceGUID(_GUID* __return_storage_ptr__, int param_1);
    void EnumServiceGUID(int param_1, _GUID* param_2);
    int GetServiceActive(int param_1);
    void SetServiceActive(int param_1, int param_2);
};

static_assert(sizeof(TCommunications_Services) == 0x2584, "TCommunications_Services Size Mismatch");
static_assert(offsetof(TCommunications_Services, ServiceCount) == 0x2580, "TCommunications_Services Offset Mismatch");

