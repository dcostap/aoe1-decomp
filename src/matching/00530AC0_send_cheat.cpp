// VA: 00530AC0 TRIBE_World::send_cheat(short)
// BINARY NOTE: the direct target is TRIBE_Command::command_cheat(short, short).
// Keep the command owner and method name.  A generic InnerObj::method changes
// relocation identity even when the instruction bytes stay aligned.

#ifndef TWORLD_PHASE2_CONTEXT
class TRIBE_Command {
public:
    void command_cheat(short a, short b);
};

class TRIBE_World {
public:
    void send_cheat(short code);
    char pad[0x58];
    TRIBE_Command* field_58;
    char pad2[0x20];
    short field_7C;
};
#endif

void TRIBE_World::send_cheat(short code) {
    this->field_58->command_cheat(this->field_7C, code);
}
