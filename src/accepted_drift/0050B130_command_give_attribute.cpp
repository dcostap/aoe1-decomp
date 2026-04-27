// ACCEPTED_DRIFT: packet-fill scheduling/register drift only. Rebuilt loads/stores the two amount dwords before the byte fields while original fills byte 3 first; all writes target the same newly allocated packet before the same log/submit calls and stack cleanup.
// tried natural packet-fill form from the tcommand.cpp packet: behavior is correct, but VC5 schedules the two amount loads before the byte/int arg loads; no match yet.
// tried local arg temps; no codegen change.
// tried volatile packet writes; preserves store order slightly better, but still leaves broad register/scheduling drift, so kept in scratch.
// tried spelling amount arguments as int instead of float; same codegen family, kept int because packet stores raw dwords like the original.
#include <stdlib.h>

class RGE_Command {
public:
    void submit(void* data, int size);
};

class TRIBE_Command : public RGE_Command {
public:
    void command_give_attribute(int player_id, int to_player_id, int attr, float amount, float amount2);
};

extern void* L;
extern void Log(void* log, const char* format, ...);

void TRIBE_Command::command_give_attribute(int player_id, int to_player_id, int attr, float amount, float amount2) {
    unsigned char* packet = (unsigned char*)calloc(1, 0x0C);
    unsigned char attr_byte = (unsigned char)attr;
    int to_player = to_player_id;
    int player = player_id;
    ((volatile unsigned char*)packet)[3] = attr_byte;
    *(float*)(packet + 4) = amount;
    float amount2_value = amount2;
    packet[0] = 0x6C;
    packet[1] = (unsigned char)player;
    packet[2] = (unsigned char)to_player;
    *(float*)(packet + 8) = amount2_value;
    Log(L, "      >SEND CMD GIVE ATTR (PLR=%d,TO=%d)", player, to_player);
    this->submit(packet, 0x0C);
}
