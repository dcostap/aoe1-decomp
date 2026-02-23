#pragma once
#include "common.h"
#include "SPs.h"

struct TCommunications_Services {
    TCommunications_Services();
    ~TCommunications_Services();

    int GetServiceCount();
    int IncServiceCount();
    char* GetServiceName(int index);
    int SetServiceName(int index, char* name);
    _GUID GetServiceGUID(int index);
    void EnumServiceGUID(int index, _GUID* guid);
    int GetServiceActive(int index);
    void SetServiceActive(int index, int active);

    SPs Service[100];
    int ServiceCount;
};
static_assert(sizeof(TCommunications_Services) == 0x2584, "Size mismatch");
