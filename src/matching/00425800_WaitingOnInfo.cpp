// 00425800 TCommunications_Handler::WaitingOnInfo
// Source: Com_hand.cpp lines 155-201, size 211 bytes
// char* WaitingOnInfo(unsigned int param_1)

#include "../../include/com_hand_context.h"

// ——— Globals ———
extern char g_status_buffer[0x20];         // 0x0062C588 — string output buffer

char* TCommunications_Handler::WaitingOnInfo(unsigned int param_1)
{
    unsigned int player = param_1;

    if (IsPlayerComputer(player)) {
        rge_base_game->get_string(0x4B1, g_status_buffer, 0x20);
        return g_status_buffer;
    }
    if (!IsPlayerHuman(player)) {
        rge_base_game->get_string(0x4B2, g_status_buffer, 0x20);
        return g_status_buffer;
    }
    if (LastTurnAck[player] < 4) {
        rge_base_game->get_string(0x4B3, g_status_buffer, 0x20);
        return g_status_buffer;
    }
    if (LastTurnAck[player] < current_turn) {
        rge_base_game->get_string(0x4B4, g_status_buffer, 0x20);
        return g_status_buffer;
    }

    rge_base_game->get_string(0x4B0, g_status_buffer, 0x20);
    return g_status_buffer;
}
