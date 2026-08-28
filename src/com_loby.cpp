#include <dplay.h>
#include <dplobby.h>
#include "../include/com_loby.h"
#include "../include/debuglog.h"
#include <string.h>

extern TDebuggingLog* L;
extern char _s_Release[];

// PDB signature is non-const; the SDK callback type is const-qualified.
int __stdcall EnumPlayersCallbackLobby(
    DPID dpId, DWORD dwPlayerType, DPNAME* lpName, DWORD dwFlags,
    LPVOID lpContext);

typedef char com_loby_size_check[
    (sizeof(RGE_Lobby) == 0x1c) ? 1 : -1];
typedef char com_loby_session_size_check[
    (sizeof(DPSESSIONDESC2) == 0x50) ? 1 : -1];
typedef char com_loby_name_size_check[
    (sizeof(DPNAME) == 0x10) ? 1 : -1];
typedef char com_loby_connection_size_check[
    (sizeof(DPLCONNECTION) == 0x28) ? 1 : -1];
typedef char com_loby_caps_size_check[
    (sizeof(DPCAPS) == 0x28) ? 1 : -1];

struct LobbySystemMessage {
    DWORD type;
};

struct ZoneMessageHeader {
    DWORD type;
    DWORD flags;
    GUID nullGuid;
    GUID messageGuid;
    DWORD size;
};

RGE_Lobby::RGE_Lobby(void* hwnd) {
    this->HostHWND = hwnd;

    this->Err = new RGE_Comm_Error(hwnd);
    this->glpDP = 0;
    this->glpdplConnection = 0;
    this->glpDPL = 0;
    this->glpDPL2 = 0;
    this->lobby_game = 0;
}

RGE_Lobby::~RGE_Lobby() {
    delete this->Err;
    this->ClearLobbyInfo();
}

void RGE_Lobby::ClearLobbyInfo(void) {
    if (this->glpdplConnection != 0) {
        delete[] static_cast<char*>(
            static_cast<void*>(this->glpdplConnection));
        this->glpdplConnection = 0;
    }
    if (this->glpDPL2 != 0) {
        IDirectPlayLobby2* pLobby = this->glpDPL2;
        long result = pLobby->Release();
        this->Err->ShowReturn(result, _s_Release);
        this->glpDPL2 = 0;
    }
    this->lobby_game = 0;
    this->glpDP = 0;
}

int RGE_Lobby::IsLobbyLaunched(void) {
    L->Log("LOBBY GAME LAUNCH STATUS = %d",
           static_cast<unsigned int>(this->lobby_game));
    return static_cast<unsigned int>(this->lobby_game);
}

int __stdcall EnumPlayersCallbackLobby(DPID dpId, DWORD dwPlayerType,
                                       DPNAME* lpName, DWORD dwFlags,
                                       LPVOID lpContext) {
    L->Log("ENUMPLAYER: DPID = %ld", dpId);
    L->Log("ENUMPLAYER: NAME = %s", lpName->lpszShortNameA);
    L->Log("+++ Enumeration not done");
    if ((dwFlags & 0x10) != 0) {
        L->Log("Remote Player");
    }
    if ((dwFlags & 8) != 0) {
        L->Log("Local Player");
    }
    return 1;
}

unsigned char RGE_Lobby::CheckForLobbyLaunch(IDirectPlay3*& dplay) {
    unsigned long dwSize = 0x29;
    dplay = 0;
    this->ClearLobbyInfo();

    HRESULT result = DirectPlayLobbyCreateA(0, &this->glpDPL, 0, 0, 0);
    this->Err->ShowReturn(result, "Lobby Create");
    if (result < 0) {
        return 0;
    }

    LPVOID lobbyObject;
    this->glpDPL->QueryInterface(IID_IDirectPlayLobby2A, &lobbyObject);
    this->glpDPL2 = static_cast<IDirectPlayLobby2*>(lobbyObject);
    if (this->glpDPL2 == 0) {
        return 0;
    }

    this->glpDPL2->GetConnectionSettings(0, 0, &dwSize);
    char* connectionBuffer = new char[dwSize + 1];
    this->glpdplConnection = static_cast<DPLCONNECTION*>(
        static_cast<void*>(connectionBuffer));
    result = this->glpDPL2->GetConnectionSettings(
        0, static_cast<void*>(this->glpdplConnection), &dwSize);
    if (result < 0) {
        this->lobby_game = 0;
        return 0;
    }

    L->Log("LOBBY LAUNCHED GAME.");

    this->glpdplConnection->lpSessionDesc->dwFlags = 0x44;
    this->glpdplConnection->lpSessionDesc->dwMaxPlayers = 9;

    this->glpDPL2->SetConnectionSettings(0, 0, this->glpdplConnection);
    L->Log("Pre-connect");

    result = this->glpDPL2->Connect(0, &this->glpDP, 0);
    L->Log("Post Connect");
    if (result < 0) {
        if (result == 0x887700F0) {
            return 0xFF;
        }
        L->Log("Failed to connect!");
        this->Err->ShowReturn(result, "Connect");
        return 0xFF;
    }

    L->Log("Pre QI");
    LPVOID dplayObject;
    result = this->glpDP->QueryInterface(IID_IDirectPlay3A, &dplayObject);
    dplay = static_cast<IDirectPlay3*>(dplayObject);
    this->Err->ShowReturn(result, "Lobby QI");
    if (result < 0) {
        L->Log("Queryinterface failed.");
        return 0xFF;
    }

    L->Log("Calling enumeration of players.");
    // The game callback is non-const, unlike the SDK callback typedef.
    dplay->EnumPlayers(
        0, reinterpret_cast<LPDPENUMPLAYERSCALLBACK2>(
               EnumPlayersCallbackLobby),
        this, 0);
    L->Log("Post ENUMP");
    this->lobby_game = 1;
    return 1;
}

unsigned char RGE_Lobby::IsThisHost(void) {
    if (!this->lobby_game) {
        return 0;
    }

    if (!((this->glpdplConnection->dwFlags >> 1) & 1)) {
        return 0;
    }
    return 1;
}

unsigned char RGE_Lobby::GetPlayerInfo(char** out) {
    if (this->lobby_game == 0) {
        return 0;
    }
    *out = this->glpdplConnection->lpPlayerName->lpszShortNameA;
    return 1;
}

unsigned char RGE_Lobby::GetSessionInfo(DPSESSIONDESC2& out) {
    if (this->lobby_game == 0) {
        return 0;
    }
    out = *this->glpdplConnection->lpSessionDesc;
    return 1;
}

long RGE_Lobby::SendZoneHandshakeResponse(void) {
    return this->lobby_game != 0;
}

int RGE_Lobby::GameIsOver(void) {
    return this->lobby_game != 0;
}

long RGE_Lobby::ReceiveZoneMessages(void) {
    if (this->lobby_game == 0) {
        return 0;
    }

    unsigned long dwDataSize = 0x800;
    unsigned long dwRXFlags;
    char data[2048];

    long result = this->glpDPL->ReceiveLobbyMessage(
        0, 0, &dwRXFlags, data, &dwDataSize);

    this->Err->ShowReturn(result, "RX Lobby Messages");

    if (result == 0x887700BE) {
        return 0;
    }
    if (dwDataSize == 0) {
        return 0;
    }

    if (result != 0) {
        this->Err->ShowReturn(result, "RxLOBBY MSG");
        return 0;
    }

    if (dwRXFlags != 1) {
        return 0;
    }

    L->Log("LOBBY: System Message");

    LobbySystemMessage message;
    memcpy(&message, data, sizeof(message));
    unsigned long dwMessageType = message.type;
    int msgType = static_cast<int>(dwMessageType) - 1;

    switch (msgType) {
        case 3:
            L->Log("!!! Lobby: Application has been terminated.");
            break;
        case 0:
            L->Log("Lobby connection settings read.");
            break;
        case 1:
            L->Log("!!! Lobby: Connection failed.");
            break;
        case 2:
            L->Log("Lobby: Connection successful.");
            break;
        default:
            L->Log("!!! Lobby: Unknown message from lobby. %d",
                   dwMessageType);
            break;
    }

    return 0;
}

long RGE_Lobby::SendZoneMessage(char* data, unsigned long dataSize,
                                _GUID guid) {
    if (this->lobby_game == 0) {
        return 0;
    }

    unsigned long total = dataSize + 0x30;

    L->Log("Sending %d bytes to the Zone (Total message size = %d)",
           dataSize, total);

    ZoneMessageHeader header;
    header.type = 5;
    header.flags = 0;
    header.nullGuid = GUID_NULL;
    header.messageGuid = guid;
    header.size = total;

    char* message = new char[total];
    memcpy(message, &header, sizeof(header));
    memcpy(message + sizeof(header), data, dataSize);

    long result = this->glpDPL2->SendLobbyMessage(0, 0, message, total);
    delete[] message;

    if (result == 0) {
        L->Log("SendLobbyMessage returns OK");
    }
    this->Err->ShowReturn(result, "Send Lobby Msg");
    return result;
}
