#include "../include/TCommunications_Services.h"

#include <dplay.h>

#include <string.h>

static BOOL FAR PASCAL DPEnumCallback(GUID* guid_sp, LPSTR sp_name, DWORD /*major*/, DWORD /*minor*/, LPVOID context) {
    // Source of truth: com_serv.cpp.decomp @ 0x00432180
    if (context == nullptr) {
        return TRUE;
    }

    TCommunications_Services* services = (TCommunications_Services*)context;
    const int index = services->GetServiceCount();

    services->SetServiceName(index, sp_name);
    services->EnumServiceGUID(index, guid_sp);

    LPDIRECTPLAY dp = nullptr;
    const HRESULT hr = DirectPlayCreate(guid_sp, &dp, nullptr);
    if (hr == DP_OK && dp != nullptr) {
        services->SetServiceActive(index, 1);
        dp->Release();
    } else {
        services->SetServiceActive(index, 0);
    }

    services->IncServiceCount();
    return TRUE;
}

TCommunications_Services::TCommunications_Services() {
    // Source of truth: com_serv.cpp.decomp @ 0x00431FB0
    this->ServiceCount = 0;

    for (int i = 0; i < 100; ++i) {
        this->Service[i].Name[0] = '\0';
        this->Service[i].GUID = nullptr;
        this->Service[i].MajVersion = 0;
        this->Service[i].MinVersion = 0;
        this->Service[i].Active = 0;
    }

    (void)DirectPlayEnumerateA(DPEnumCallback, this);
}

TCommunications_Services::~TCommunications_Services() {
    // Fully verified. Source of truth: com_serv.cpp.decomp @ 0x00432030
}

int TCommunications_Services::GetServiceCount() {
    // Fully verified. Source of truth: com_serv.cpp.decomp @ 0x00432040
    return this->ServiceCount;
}

int TCommunications_Services::IncServiceCount() {
    // Fully verified. Source of truth: com_serv.cpp.decomp @ 0x00432050
    const int next = this->ServiceCount + 1;
    this->ServiceCount = next;
    return next;
}

char* TCommunications_Services::GetServiceName(int index) {
    // Fully verified. Source of truth: com_serv.cpp.decomp @ 0x00432060
    if (index > -1 && index <= this->ServiceCount) {
        return this->Service[index].Name;
    }
    return nullptr;
}

int TCommunications_Services::SetServiceName(int index, char* name) {
    // Source of truth: com_serv.cpp.decomp @ 0x00432080
    if (index < 0 || index >= 100 || name == nullptr) {
        return 0;
    }

    strncpy(this->Service[index].Name, name, sizeof(this->Service[index].Name) - 1);
    this->Service[index].Name[sizeof(this->Service[index].Name) - 1] = '\0';
    return 1;
}

_GUID TCommunications_Services::GetServiceGUID(int index) {
    // Source of truth: com_serv.cpp.decomp @ 0x004320C0
    _GUID out{};
    if (index < 0 || index >= 100) {
        return out;
    }

    _GUID* guid = this->Service[index].GUID;
    if (guid != nullptr) {
        out = *guid;
    }
    return out;
}

void TCommunications_Services::EnumServiceGUID(int index, _GUID* guid) {
    // Source of truth: com_serv.cpp.decomp @ 0x004320F0
    if (index > -1 && index <= this->ServiceCount) {
        this->Service[index].GUID = guid;
    }
}

int TCommunications_Services::GetServiceActive(int index) {
    // Fully verified. Source of truth: com_serv.cpp.decomp @ 0x00432120
    if (index > -1 && index <= this->ServiceCount) {
        return this->Service[index].Active;
    }
    return 0;
}

void TCommunications_Services::SetServiceActive(int index, int active) {
    // Fully verified. Source of truth: com_serv.cpp.decomp @ 0x00432150
    if (index > -1 && index <= this->ServiceCount) {
        this->Service[index].Active = active;
    }
}

