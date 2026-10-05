#ifndef AOE1_COM_ERR_H
#define AOE1_COM_ERR_H

#include "com_types.h"
// Canonical com_err.cpp surface for the four contiguous owners below.

class RGE_Comm_Error {
  public:
    void* HostHWND;
    long LastReportedError;

    RGE_Comm_Error(void* Host);
    ~RGE_Comm_Error();
    void NotifyWindowParam(COMMMESSAGES msg, long lparam);
    void ShowReturn(long hr, char* Text);
};

#endif
