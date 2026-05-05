// VA: 0052E530 TRIBE_World::command_init
// FLAGS: /GX required for original SEH/new/ctor cleanup basin
// left in scratch: /GX natural new emits expected SEH prolog, allocator size 0x18, ctor args, and store target,
// but VC5 sinks the member store/SEH restore into the non-null path. Original has common tail with `jmp`,
// `xor eax,eax`, then one store/FS restore. Explicit placement-new temp reproduced same sunk-store basin.

void* __cdecl operator new(unsigned int size);
void* __cdecl operator new(unsigned int size, void* place);

class TCommunications_Handler;
class TRIBE_Command;

class TRIBE_World {
public:
    char gap_00[0x58];
    TRIBE_Command* commands;

    void command_init(int unused, TCommunications_Handler* handler);
};

class TRIBE_Command {
public:
    char gap_00[0x18];
    TRIBE_Command(TRIBE_World* world, TCommunications_Handler* handler);
};

void TRIBE_World::command_init(int unused, TCommunications_Handler* handler) {
    TRIBE_Command* cmd = (TRIBE_Command*)operator new(0x18);
    if (cmd != 0) {
        cmd = new(cmd) TRIBE_Command(this, handler);
    } else {
        cmd = 0;
    }
    this->commands = cmd;
}
