// VA: 00514FE0 TRIBE_Player::logMessage
// PDB: tplayer.cpp:1950-1959
// The cdecl member keeps the original stack-based vararg pack.

#include <stdio.h>

#include "../../include/taitacmd.h"
#include "../../include/tplayer.h"

void __cdecl TRIBE_Player::logMessage(char* format, ...) {
    char textOut[1024];

    if (this->playerAI != 0) {
        vsprintf(textOut, format, (char*)((&format) + 1));
        this->playerAI->logCommonHistory(textOut);
    }
}
