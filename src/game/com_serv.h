#pragma once
#include "common.h"

class TCommunications_Services {
public:
    SPs Service[100];                        // 0x0
    int ServiceCount;                        // 0x2580

    TCommunications_Services();
    ~TCommunications_Services();
    int GetServiceCount();
    int IncServiceCount();
    char* GetServiceName(int param_1);
    int SetServiceName(int param_1, char* param_2);
    _GUID* GetServiceGUID(int param_1);
    void EnumServiceGUID(int param_1, _GUID* param_2);
    int GetServiceActive(int param_1);
    void SetServiceActive(int param_1, int param_2);
};

static_assert(sizeof(TCommunications_Services) == 0x2584, "TCommunications_Services Size Mismatch");

