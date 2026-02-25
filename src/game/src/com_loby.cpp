#include "../include/RGE_Lobby.h"

#include "../include/RGE_Comm_Error.h"

#include <dplay.h>
#include <dplobby.h>

#include <new>
#include <string.h>

static BOOL FAR PASCAL EnumPlayersCallbackLobby(DPID /*dpid*/, DWORD /*dwPlayerType*/, LPCDPNAME /*name*/, DWORD /*flags*/, LPVOID /*context*/) {
    // Fully verified. Source of truth: com_loby.cpp.decomp @ 0x0042F3A0
    return TRUE;
}

RGE_Lobby::RGE_Lobby(void* host_hwnd) {
    // Source of truth: com_loby.cpp.decomp @ 0x0042F290
    this->HostHWND = host_hwnd;
    this->Err = new (std::nothrow) RGE_Comm_Error(host_hwnd);
    this->glpDP = nullptr;
    this->glpdplConnection = nullptr;
    this->glpDPL = nullptr;
    this->glpDPL2 = nullptr;
    this->lobby_game = 0;
}

RGE_Lobby::~RGE_Lobby() {
    // Source of truth: com_loby.cpp.decomp @ 0x0042F300
    delete this->Err;
    this->Err = nullptr;
    this->ClearLobbyInfo();
}

void RGE_Lobby::ClearLobbyInfo() {
    // Source of truth: com_loby.cpp.decomp @ 0x0042F330
    if (this->glpdplConnection != nullptr) {
        delete[] (char*)this->glpdplConnection;
        this->glpdplConnection = nullptr;
    }

    if (this->glpDPL2 != nullptr) {
        (void)this->glpDPL2->Release();
        this->glpDPL2 = nullptr;
    }

    if (this->glpDPL != nullptr) {
        (void)this->glpDPL->Release();
        this->glpDPL = nullptr;
    }

    this->lobby_game = 0;
    this->glpDP = nullptr;
}

int RGE_Lobby::IsLobbyLaunched() {
    // Fully verified. Source of truth: com_loby.cpp.decomp @ 0x0042F370
    return (int)this->lobby_game;
}

uchar RGE_Lobby::CheckForLobbyLaunch(IDirectPlay3** out_dp3) {
    // Fully verified. Source of truth: com_loby.cpp.decomp @ 0x0042F430
    *out_dp3 = nullptr;

    this->ClearLobbyInfo();

    HRESULT hr = DirectPlayLobbyCreateA(nullptr, (LPDIRECTPLAYLOBBYA*)&this->glpDPL, nullptr, nullptr, 0);
    this->Err->ShowReturn((long)hr, "Lobby Create");
    if (FAILED(hr)) {
        return 0;
    }

    hr = this->glpDPL->QueryInterface(IID_IDirectPlayLobby2A, (LPVOID*)&this->glpDPL2);
    if (this->glpDPL2 == nullptr) {
        return 0;
    }

    DWORD size = 0;
    (void)this->glpDPL2->GetConnectionSettings(0, nullptr, &size);

    this->glpdplConnection = (DPLCONNECTION*)new char[size + 1];

    hr = this->glpDPL2->GetConnectionSettings(0, this->glpdplConnection, &size);
    if (FAILED(hr)) {
        this->lobby_game = 0;
        return 0;
    }

    this->glpdplConnection->lpSessionDesc->dwFlags = 0x44;
    this->glpdplConnection->lpSessionDesc->dwMaxPlayers = 9;
    (void)this->glpDPL2->SetConnectionSettings(0, 0, this->glpdplConnection);

    hr = this->glpDPL2->Connect(0, (LPDIRECTPLAY2*)&this->glpDP, nullptr);
    if (FAILED(hr)) {
        // Original special-case: DPERR_CONNECTING returns immediately without ShowReturn.
        if ((unsigned long)hr == 0x887700F0) {
            return 0xFF;
        }
        this->Err->ShowReturn((long)hr, "Connect");
        return 0xFF;
    }

    hr = this->glpDP->QueryInterface(IID_IDirectPlay3A, (LPVOID*)out_dp3);
    this->Err->ShowReturn((long)hr, "Lobby QI");
    if (FAILED(hr)) {
        return 0xFF;
    }
    (void)(*out_dp3)->EnumPlayers(nullptr, EnumPlayersCallbackLobby, this, 0);

    this->lobby_game = 1;
    return 1;
}

uchar RGE_Lobby::IsThisHost() {
    // Fully verified. Source of truth: com_loby.cpp.decomp @ 0x0042F640
    if (this->lobby_game == 0 || this->glpdplConnection == nullptr) {
        return 0;
    }
    return (uchar)((this->glpdplConnection->dwFlags >> 1) & 1);
}

uchar RGE_Lobby::GetPlayerInfo(char** out_name) {
    // Source of truth: com_loby.cpp.decomp @ 0x0042F660
    if (out_name == nullptr) {
        return 0;
    }
    *out_name = nullptr;
    if (this->lobby_game == 0 || this->glpdplConnection == nullptr || this->glpdplConnection->lpPlayerName == nullptr) {
        return 0;
    }

    *out_name = this->glpdplConnection->lpPlayerName->lpszShortNameA;
    return 1;
}

uchar RGE_Lobby::GetSessionInfo(DPSESSIONDESC2* out_desc) {
    // Source of truth: com_loby.cpp.decomp @ 0x0042F680
    if (this->lobby_game == 0 || this->glpdplConnection == nullptr || this->glpdplConnection->lpSessionDesc == nullptr ||
        out_desc == nullptr) {
        return 0;
    }

    memcpy(out_desc, this->glpdplConnection->lpSessionDesc, sizeof(DPSESSIONDESC2));
    return 1;
}

long RGE_Lobby::SendZoneHandshakeResponse() {
    // Fully verified. Source of truth: com_loby.cpp.decomp @ 0x0042F6B0
    return (long)(this->lobby_game != 0);
}

int RGE_Lobby::GameIsOver() {
    // Fully verified. Source of truth: com_loby.cpp.decomp @ 0x0042F6C0
    return (int)(this->lobby_game != 0);
}

long RGE_Lobby::ReceiveZoneMessages() {
    // Source of truth: com_loby.cpp.decomp @ 0x0042F6D0
    if (this->lobby_game != 0 && this->glpDPL != nullptr) {
        DWORD size = 2048;
        DWORD rx_flags = 0;
        char data[2048];
        HRESULT hr = this->glpDPL->ReceiveLobbyMessage(0, 0, &rx_flags, data, &size);
        if (this->Err != nullptr) {
            this->Err->ShowReturn((long)hr, "RX Lobby Messages");
        }
    }
    return 0;
}

long RGE_Lobby::SendZoneMessage(char* data, ulong data_size, _GUID to_player) {
    // Source of truth: com_loby.cpp.decomp @ 0x0042F830
    if (this->lobby_game == 0 || this->glpDPL2 == nullptr || data == nullptr) {
        return 0;
    }

    const uint full_len = (uint)data_size + 0x30;
    unsigned int* buf = (unsigned int*)::operator new(full_len, std::nothrow);
    if (buf == nullptr) {
        return 0;
    }

    // Zone message header (12 dwords), then payload.
    buf[0] = 5;
    buf[1] = 0;
    buf[2] = 0;
    buf[3] = 0;
    buf[4] = 0;
    buf[10] = full_len;
    buf[5] = 0;
    buf[6] = to_player.Data1;
    buf[7] = ((uint)to_player.Data3 << 16) | (uint)to_player.Data2;
    uint d4_0 = 0;
    uint d4_4 = 0;
    memcpy(&d4_0, &to_player.Data4[0], 4);
    memcpy(&d4_4, &to_player.Data4[4], 4);
    buf[8] = d4_0;
    buf[9] = d4_4;

    memcpy(buf + 0x0B, data, (size_t)data_size);

    HRESULT hr = this->glpDPL2->SendLobbyMessage(0, 0, buf, full_len);
    ::operator delete(buf);

    if (this->Err != nullptr) {
        this->Err->ShowReturn((long)hr, "Send Lobby Msg");
    }
    return (long)hr;
}

