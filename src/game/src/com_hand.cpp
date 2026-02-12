#include "../include/TCommunications_Handler.h"

namespace {
// COMMPLAYEROPTIONS::Humanity offset inside PlayerOptions.
// Source-of-truth:
// - all_types_ground_truth.h (COMMPLAYEROPTIONS::Humanity @ +0x184)
// - com_hand.cpp.decomp (Get/SetPlayerHumanity)
static const int kCommPlayerOptionsHumanityOffset = 0x184;
static const int kCommPlayerOptionsNeedsToBeSentOffset = 0x0;
static const int kCommPlayerOptionsProgramStateOffset = 0x8;

// Source-of-truth constants from com_hand.cpp.asm:
// - COMM_UPDATE_PARAMS literal pushed at SetPlayerHumanity+0x35 (0x0042cc5e): 0x17a6
// - COMM_STATE_JOINNOW compare at SetPlayerHumanity+0x41 (0x0042cc71): 3
static const int kCommMessageUpdateParams = 0x17a6;
static const int kCommStateJoinNow = 3;
}

int TCommunications_Handler::IsPaused() {
    // Offset 0x1558 in TCommunications_Handler is the pause state
    // According to assembly at 0x0042C7F0:
    // 0x1558 == 4 means Paused
    
    // We need to access the member at 0x1558.
    // Based on the struct definition, we'll need to identify which member that is.
    // For now, let's use a pointer cast to match the assembly exactly if the member name is unknown.
    
    int* pause_state = (int*)((char*)this + 0x1558);
    return (*pause_state == 4);
}

void TCommunications_Handler::Update() {
    // Offset 0x00426650 in ASM is DoCycle
    // The user wants Update() to behave like the core tick.
    // In tribal engine, DoCycle is the main entry.
    DoCycle(GetTickCount());
}

void TCommunications_Handler::HandleMessage() {
    // Offset 0x00429D90 in ASM is ExecuteIncoming
    ExecuteIncoming();
}

int TCommunications_Handler::DoCycle(ulong now) {
    // TODO: Full implementation from 0x00426650
    // Minimal implementation to satisfy requirements:
    ReceiveGameMessages();
    return 1;
}

void TCommunications_Handler::ReceiveGameMessages() {
    // TODO: Full implementation from 0x00426E10
    // Calls ExecuteIncoming, GetDPLAYMessages, etc.
    ExecuteIncoming();
    GetDPLAYMessages();
    CheckPingTime(0);
}

uint TCommunications_Handler::ExecuteIncoming() {
    // TODO: Full implementation from 0x00429D90
    // Loops through players and handles OnHold messages
    return 0;
}

void TCommunications_Handler::GetDPLAYMessages() {
    // TODO: Implement (ASM 0x00426FCD)
}

void TCommunications_Handler::EvaluateSystemMessage(ulong p1, char* p2, ulong p3, ulong p4) {
    // TODO: Implement (ASM 0x00428DA0)
}

void TCommunications_Handler::UpdatePlayers() {
    // TODO: Implement (ASM 0x0042DF40)
}

void TCommunications_Handler::UpdatePlayer(uint id, int timeout) {
    // TODO: Implement (ASM 0x0042DF50)
}

void TCommunications_Handler::NotifyWindow(int message) {
    // Source-of-truth:
    // - com_hand.cpp.decomp NotifyWindow/NotifyWindowParam
    // - com_hand.cpp.asm 0x00428270 / 0x00428280
    // Behavior: Post WM_USER to HostHWND with message as wParam and 0 as lParam.
    //
    // Assumption/TODO:
    // The original logs through TDebuggingLog::Log and uses the typed COMMMESSAGES enum.
    // This branch still uses integer message ids because full comm enums are not restored yet.
    if (this->HostHWND) {
        PostMessageA((HWND)this->HostHWND, 0x400, (WPARAM)message, 0);
    }
}

long TCommunications_Handler::SendSharedData(int send_mode) {
    // Partial stub with key state transitions from com_hand.cpp.asm/decomp.
    // Source-of-truth:
    // - com_hand.cpp.asm SendSharedData @ 0x00428820
    // - com_hand.cpp.decomp SendSharedData
    //
    // Assumption/TODO:
    // Full packet serialization/network send is still missing in this branch.
    // This keeps core "needs send" behavior so callers (including SetPlayerHumanity) track intent.
    if (!this->MeHost) {
        return 0;
    }

    uchar* needs_to_be_sent =
        (uchar*)((char*)&this->PlayerOptions + kCommPlayerOptionsNeedsToBeSentOffset);

    if (send_mode != 0) {
        *needs_to_be_sent = 1;
    }
    if (*needs_to_be_sent == 0) {
        return 0;
    }

    // Treat as sent for now in this partial reimplementation.
    *needs_to_be_sent = 0;
    return 1;
}

int TCommunications_Handler::GetPlayerHumanity(uint player_number) {
    if ((player_number == 0) || (player_number > (uint)this->MaxGamePlayers) || (player_number >= 10)) {
        return 0;
    }

    const int* humanity =
        (const int*)((const char*)&this->PlayerOptions + kCommPlayerOptionsHumanityOffset);
    return humanity[player_number];
}

void TCommunications_Handler::SetPlayerHumanity(uint player_number, int humanity_value) {
    if ((player_number == 0) || (player_number > (uint)this->MaxGamePlayers) || (player_number >= 10)) {
        return;
    }

    int* humanity = (int*)((char*)&this->PlayerOptions + kCommPlayerOptionsHumanityOffset);
    humanity[player_number] = humanity_value;

    this->UpdatePlayer(player_number, 1);

    // Source-of-truth:
    // - com_hand.cpp.decomp SetPlayerHumanity
    // - com_hand.cpp.asm 0x0042cc30
    this->NotifyWindow(kCommMessageUpdateParams);

    const int* program_state =
        (const int*)((const char*)&this->PlayerOptions + kCommPlayerOptionsProgramStateOffset);
    if ((this->MeHost != 0) && (*program_state == kCommStateJoinNow)) {
        uchar* needs_to_be_sent =
            (uchar*)((char*)&this->PlayerOptions + kCommPlayerOptionsNeedsToBeSentOffset);
        *needs_to_be_sent = 1;
        this->SendSharedData(0);
    }
}

char* TCommunications_Handler::GetPlayerName(uint player_number) {
    // Source of truth: com_hand.cpp.decomp @ GetPlayerName
    // TODO(accuracy): implement full name lookup from PlayerOptions
    // Returns pointer to internal name buffer for the given player slot.
    // For now return the friendly name as a fallback.
    static char empty_name[65] = {0};
    if (player_number == 0 || player_number >= 10) {
        return empty_name;
    }
    // TODO(accuracy): actual offset into PlayerOptions name array
    return empty_name;
}

void TCommunications_Handler::SetPlayerName(uint player_number, char* name) {
    // Source of truth: com_hand.cpp.decomp @ SetPlayerName
    // TODO(accuracy): implement full name storage in PlayerOptions
    (void)player_number;
    (void)name;
}

uint TCommunications_Handler::GetRandomSeed() {
    // Source of truth: com_hand.cpp.decomp @ GetRandomSeed
    // TODO(accuracy): implement proper seed from comm shared data
    return (uint)GetTickCount();
}

uint TCommunications_Handler::WhoAmI() {
    // Source of truth: com_hand.cpp.decomp @ WhoAmI
    return this->Me;
}

void TCommunications_Handler::DropDeadPlayer(uint id, ulong turn) {
    // TODO: Implement (ASM 0x00428B60)
}

void TCommunications_Handler::CheckPingTime(int p1) {
    // TODO: Implement (ASM 0x00428220)
}

void TCommunications_Handler::SendStoredMessages() {
    // TODO: Implement (ASM 0x00426FCD)
}

int TCommunications_Handler::PreprocessMessages(void* p1, ulong p2, void* p3, ulong p4) {
    // TODO: Implement (ASM 0x00429280)
    return 0;
}

long TCommunications_Handler::CommOut(uchar p1, void* p2, long p3, ulong p4) {
    // TODO: Implement (ASM 0x00426C40)
    return 0;
}

void TCommunications_Handler::TogglePauseGame() {
    // Source of truth: com_hand.cpp.asm
    // Toggles the pause state in multiplayer games.
    // For single player, this is a no-op since pause is managed locally.
    // TODO(accuracy): implement full MP pause toggle
}

int TCommunications_Handler::MultiplayerGameStart() {
    // Returns nonzero if a multiplayer game has started.
    return (this->Multiplayer != 0 && this->CommunicationsStatus == COMM_ACTIVE) ? 1 : 0;
}

int TCommunications_Handler::IsLobbyLaunched() {
    return this->LobbyLaunched;
}
