#include "..\..\include\game_globals.h"

void __cdecl ds_stream_pause(void) {
    __asm {
        mov eax, 1
        mov _stream_paused, eax
    }
}
