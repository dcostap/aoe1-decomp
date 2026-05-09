// World.cpp:852-854, 89 bytes
// attempt 1: 23.6%, same null-store basin as 00541B60
// BEST: 23.6%. BLOCKER: identical to 00541B60/0052E530 - original fail path has
//   ctor; jmp common; null xor eax; common mov [esi+58h],eax before EH teardown;
//   rebuilt new expression sinks the store/teardown into the non-null path.
// 2026 retry after 0052E530: revalidated, same 21-byte positional / 15-byte edit diff.
// 2026-05-09 GraniteCub: tried 18 focused variants: direct assignment, zero-init local,
// explicit if/goto/two-stage common-store forms, assignment-in-if/comma/do-while,
// param2 local, this alias, volatile local, no-virtual command surface, void*/int member,
// ctor signature casts, and brief /O1+/GX flag probe. Same blocker as 0052E650:
// direct new keeps exact EH/new/ctor family but sinks store into success path; artificial
// `if (p == 0) p = 0;` reaches a closer common-store basin (16 positional/11 edit)
// but inserts a redundant post-merge test before the store. Left cleaner direct-new source.
// FLAGS: /GX
class RGE_Game_World;

class RGE_Command {
public:
    virtual ~RGE_Command();
    char gap_04[0x18 - 0x04];
    RGE_Command(RGE_Game_World*, void*);
};

class RGE_Game_World {
public:
    char gap_00[0x58];
    RGE_Command* command;  // +0x58

    void command_init(int param1, void* param2);
};

void RGE_Game_World::command_init(int param1, void* param2) {
    RGE_Command* p = new RGE_Command(this, param2);
    command = p;
}
