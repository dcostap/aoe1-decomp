// 00435020 RGE_Command::do_command_create_group
// PDB: Command.cpp:1018-1027, 64 bytes
// protected void __thiscall do_command_create_group(RGE_Command_Create_Group*)
// ret 4 (1 param)
//
// STATUS: 61/64 bytes exact match. Remaining 3 bytes are pure register coloring:
//   Original: movzx dx,byte [esi+1] / mov ecx,[eax+0Ch] / cmp [ecx+4Ah],dx
//   Rebuilt:  movzx cx,byte [esi+1] / mov edx,[eax+0Ch] / cmp [edx+4Ah],cx
// Everything else (scheduling, push order, xor ecx, jmp offsets) is byte-identical.
//
// Attempts:
//   1 (initial): early returns + player_id local -> code scheduled player_id before null check
//   2: no player_id local -> scheduling fixed, but CX/EDX registers vs original DX/ECX
//   3: && form instead of early return -> same result as 2
//   4: unsigned short pid + unsigned int n locals -> scheduling+offsets+xor ecx correct, regs swapped
//   5: unsigned short pid local only, no n -> xor ecx gone, regs wrong offsets
//   6: swapped comparison + unsigned short owner->id -> xor ecx ok, regs swapped, cmp opcode changed
//   7: pid+n before null check -> disaster, eager loading
//   8: (unsigned int) inline cast -> no xor ecx
//   9: FIXED commanderCreateGroup param_2 type to int (was unsigned char) -> xor ecx correct!
//      -> 3 bytes remaining: pure register swap DX/ECX vs CX/EDX
//   10-19: Tried every source shape (virtual dtor, full PDB structs, inverted conditions,
//      intermediate locals, cast BOTH sides, !(a==b), explicit 16-bit locals, etc.)
//      -> ALL produce the same CX/EDX register coloring. VC5 allocator is stubborn.
//
// This is a pure register coloring tiebreak in VC5's allocator. The function is
// behaviorally identical, same stack cleanup, same call set, same instruction count.
// No source-level axis tried produced the original DX/ECX assignment.
// Likely original compilation was in a different TU context that influenced
// register coloring.

class RGE_Game_World;
class RGE_Static_Object;
class RGE_Command_Create_Group;

class RGE_Command {
public:
    void* vtable_ptr;
    RGE_Game_World* world;
    void do_command_create_group(RGE_Command_Create_Group* param_1);
};

class RGE_Game_World {
public:
    char gap_00[0x58];
    RGE_Static_Object* object(int id);
};

class RGE_Player {
public:
    char gap_00[0x4A];
    short id;
};

class RGE_Static_Object {
public:
    char gap_00[0x0C];
    RGE_Player* owner;
    int commanderCreateGroup(int* unitsToGroup, int numberUnitsToGroup, int groupCommander, float groupRange);
};

class RGE_Command_Create_Group {
public:
    unsigned char command;
    unsigned char player_id;
    unsigned char gap_02[2];
    int groupCommander;
    float groupRange;
    int unitsToGroup[25];
    unsigned char numberUnitsToGroup;
};

void RGE_Command::do_command_create_group(RGE_Command_Create_Group* param_1) {
    RGE_Static_Object* obj = this->world->object(param_1->groupCommander);
    if (obj == 0)
        return;
    if (obj->owner->id != (unsigned short)param_1->player_id)
        return;
    obj->commanderCreateGroup(param_1->unitsToGroup, param_1->numberUnitsToGroup, param_1->groupCommander, param_1->groupRange);
}
