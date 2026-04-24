// tried a raw 4-byte packet with direct field stores; mismatch stayed at the early packet-load order
// tried swapping the log args and then adding byte locals; VC5 still pulled the second/third arg loads into a different basin
// leaving in scratch: behavior looks right, but the remaining mismatch is the prolog/packet-field load order before the log call

#include <stdlib.h>

class RGE_Command {
public:
    void submit(void* command, int size);
    void command_resign(int player, int drop, int reason);
};

extern void* L;
extern void Log(void* log, const char* text, int a, int b);

void RGE_Command::command_resign(int player, int drop, int reason) {
    unsigned char* packet = (unsigned char*)calloc(1, 4);
    packet[2] = (unsigned char)drop;
    packet[0] = 0x0B;
    packet[1] = (unsigned char)player;
    packet[3] = (unsigned char)reason;
    Log(L, "      >SEND CMD RESIGN (PLR=%d,DROP=%d)", player, reason);
    this->submit(packet, 4);
}
