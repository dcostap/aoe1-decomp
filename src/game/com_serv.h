#pragma once
#include "../common.h"

class TCommunications_Services {
public:
    int ServiceCount;                        // 0x2580

    TCommunications_Services();
    virtual ~TCommunications_Services();
    virtual int GetServiceCount();
    virtual int IncServiceCount();
    virtual char* GetServiceName(int param_1);
    virtual int SetServiceName(int param_1, char* param_2);
    virtual _GUID* GetServiceGUID(_GUID* __return_storage_ptr__, int param_1);
    virtual void EnumServiceGUID(int param_1, _GUID* param_2);
    virtual int GetServiceActive(int param_1);
    virtual void SetServiceActive(int param_1, int param_2);
};

static_assert(sizeof(TCommunications_Services) == 0x2584, "TCommunications_Services Size Mismatch");
static_assert(offsetof(TCommunications_Services, ServiceCount) == 0x2580, "TCommunications_Services Offset Mismatch");

