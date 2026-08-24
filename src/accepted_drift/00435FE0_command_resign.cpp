// RGE_Command::command_resign
// VA: 00435FE0
// Command.cpp:2003-2024
// 79 bytes, 11 diff bytes (13.92%).
// Register allocation quirk: load order of params differs.
// Original loads drop first (mov cl,[esp+18h]), then player (mov eax,[esp+14h]),
// then reason (mov ecx,[esp+14h]) after popping calloc args.
// Rebuilt loads reason first (mov ecx,[esp+1Ch]), then drop (mov al,[esp+18h]),
// then player (mov eax,[esp+0Ch]). All sources tried produce same pattern.
// 5 relocations masked (calloc, Log, submit calls + L address + format string).

#include <stdlib.h>

#ifndef COMMAND_TU_CONTEXT
class RGE_Command {
public:
    void submit(void* command, int size);
    void command_resign(int player, int drop, int reason);
};
#endif

#ifndef COMMAND_TU_CONTEXT
extern void* L;
extern void Log(void* log, const char* text, int a, int b);
#endif

void RGE_Command::command_resign(int player, int drop, int reason) {
    unsigned char* packet = (unsigned char*)calloc(1, 4);
    packet[2] = (unsigned char)drop;
    packet[0] = 0x0B;
    packet[1] = (unsigned char)player;
    packet[3] = (unsigned char)reason;
    Log(L, "      >SEND CMD RESIGN (PLR=%d,DROP=%d)", player, reason);
    this->submit(packet, 4);
}
