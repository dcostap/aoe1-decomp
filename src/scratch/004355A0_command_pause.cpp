// VA: 004355A0 RGE_Command::command_pause(int param_1, int* data, int count)
// PDB source: Command.cpp lines 1364-1399
// Default flags
//
// __thiscall: this in ecx, 3 stack params. ret 0Ch cleanup.
//
// 114/118 edit-match bytes, only 7 positional diff bytes.
// Remaining: lea [esi+2] scheduled after test ebx,ebx (original computes before).

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
            void* log = g_pLog;
            int cnt = count;
            if (cnt > 0) {
                int i = 0;
                do {
                    dst[i] = data[i];
                    i++;
                } while (i < cnt);
            }
            buf[0] = 0x0D;
            buf[1] = (unsigned char)cnt;
            TDebuggingLog_Log(log, "      >SEND CMD PAUSE");
            this->submit(buf, alloc_size);
        }
    }
}
