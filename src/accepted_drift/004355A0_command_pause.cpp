// VA: 004355A0 RGE_Command::command_pause(int param_1, int* data, int count)
// PDB source: Command.cpp lines 1364-1399
// Default flags
//
// Behavior and call sequence are understood. Best source is a localized drift
// candidate: original computes `lea eax,[esi+2]` before the null-buffer branch and
// uses the equivalent `[ecx+eax]` addressing in the copy loop; VC5 keeps the same
// effects but schedules the LEA after the branch and encodes the commutative address
// as `[eax+ecx]`. Branch displacements shift by 3 bytes, but there is no tail/window
// truncation and calls/args/cleanup match.
//
// Attempt log:
// 1. Original scratch hoisted g_pLog into a local before the copy/header writes;
//    broad mismatch (pos 53.3898%, edit 55.9322%).
// 2. Removed log local and used direct `TDebuggingLog_Log(g_pLog, ...)`; call/log
//    schedule now matches after header stores.
// 3. Pointer-copy forms with separate src/dst chose EDI for the buffer and broad
//    prologue/register drift.
// 4. Delta copy shape `(char*)data - (char*)dst` produces the original register family,
//    loop counter in EDX, `sub ecx,eax`, byte header stores, log call, submit args, and
//    epilogue. Remaining drift is LEA-after-null-test plus `[eax+ecx]` vs `[ecx+eax]`.
// 5. Tried precomputing dst before null check, using param/long/pointer prelocals,
//    count-param loop, address-order casts, temp src pointer, and call-order variants;
//    either VC5 still sinks the LEA or worsens register/frame choice.
// ACCEPTED_DRIFT: reviewed by Boss. Remaining drift is localized and behavior-equivalent:
// rebuilt sinks `lea eax,[esi+2]` past the null-buffer branch and encodes the copy-loop
// load as `[eax+ecx]` instead of original `[ecx+eax]`. Allocation, copy bytes, header
// stores, log/submit calls and arguments, stack cleanup, size, and epilogue are identical.

#include <stdlib.h>

void __cdecl TDebuggingLog_Log(void* log_obj, const char* str);

struct RGE_Command {
    void submit(void* buf, int size);
    void command_pause(int param_1, int* data, int count);
};

#define g_pLog (*(void**)0x62C4FC)

void RGE_Command::command_pause(int param_1, int* data, int count) {
    if (data != 0 && count >= 1) {
        int alloc_size = count * 4 + 2;
        unsigned char* buf = (unsigned char*)calloc(1, alloc_size);
        if (buf != 0) {
            int* dst = (int*)(buf + 2);
            if (count > 0) {
                int* src = data;
                int n = count;
                do {
                    *dst = *src;
                    ++dst;
                    ++src;
                    --n;
                } while (n != 0);
            }
            buf[0] = 0x0D;
            buf[1] = (unsigned char)count;
            TDebuggingLog_Log(g_pLog, "      >SEND CMD PAUSE");
            this->submit(buf, alloc_size);
        }
    }
}
