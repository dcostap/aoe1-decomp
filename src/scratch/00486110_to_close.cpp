// VA: 00486110 RGE_RMM_Object_Generator::to_close
// PDB: rmm_obj.cpp lines 185-202 (97 bytes, 47 asm lines)
// Default flags
//
// Blocked: Multi-axis VC5 scheduling constraints prevent exact match.
// Not an accepted_drift candidate: structural differences are too broad.
//
// The function checks if (x,y) is within land_inner_radius of any land point.
// Loop over lands entries (stride 0x10), return 1 on match, 0 if none close.
//
// Attempt log (15+ focused variants, 6-variant lab):
//
// Issue 1 — Prologue radius hoisting:
//   `info_line->land_inner_radius` accessed via struct member syntax causes VC5
//   to load it from [esp+4] before saving registers (prologue: 11 bytes vs 4).
//   Fix: Use `*(long*)((char*)info_line + 0x24)` to prevent hoisting.
//
// Issue 2 — Duplicate guard check:
//   `if (count > 0) { do { ... } while (i < count); }` generates TWO
//   `test edi,edi; jle exit` checks — one for the if, one before the loop.
//   Removing the `if` fixes the duplicate but re-introduces issue 1 (hoisting).
//   No source pattern eliminates both simultaneously.
//
// Issue 3 — y load placement:
//   VC5 places `mov ebp, [esp+1Ch]` (load y from param) inside the loop body
//   instead of before it, unless prologue is the hoisted version.
//
// Issue 4 — add/inc ordering:
//   VC5 emits `add edx,10h` BEFORE `inc esi` in some patterns; original has
//   `inc esi` first.
//
// Issue 5 — Loop bottom:
//   Most forms emit inverted `jge exit; jmp loop` (4 bytes) instead of
//   original `jl loop` (2 bytes). `for(;;)` with bottom `if(i>=count)break;`
//   fixes this to `jl` but retains other issues.
//
// Issue 6 — Size:
//   Best basin gives 96 bytes vs original 97. The duplicate guard or prologue
//   hoisting eats the missing byte.
//
// No source/flag workaround found for the combined constraint cluster.
// Not suitable for accepted_drift — diff is structural (multi-instruction
// scheduling/layout), not a localized no-op.

struct RGE_Object_Info_Line {
    char gap_00[0x24];
    long land_inner_radius;
};

struct RGE_RMM_Object_Generator {
    char area[0x18FC];

    unsigned char to_close(RGE_Object_Info_Line* info_line, long x, long y);
};

unsigned char RGE_RMM_Object_Generator::to_close(RGE_Object_Info_Line* info_line, long x, long y) {
    long i = 0;
    long count = *(long*)((char*)this + 0x18F8);

    if (count > 0) {
        long* p = (long*)((char*)this + 0x12CC);
        long r = *(long*)((char*)info_line + 0x24);

        do {
            long dx = x - *(p - 1);
            if (dx < 0) dx = -dx;

            long dy = y - *p;
            if (dy < 0) dy = -dy;

            if (dx < r && dy < r) {
                return 1;
            }

            i++;
            p = (long*)((char*)p + 0x10);
        } while (i < count);
    }

    return 0;
}
