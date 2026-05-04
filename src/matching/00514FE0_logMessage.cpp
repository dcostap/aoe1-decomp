// VA: 00514FE0 TRIBE_Player::logMessage
// tplayer.cpp lines 1950-1959
// MATCHED: this virtual varargs method is a cdecl member function with `this` passed on the stack.
// Original uses plain `textOut`, not `textOut + 4`; the stack-based vararg pack is `(&format) + 1`.

extern "C" int __cdecl vsprintf(char* buffer, const char* format, void* argptr);

class AIModule {
public:
    void __cdecl logCommonHistory(char* message);
};

class TRIBE_Player {
public:
    char gap_00[0x238];
    AIModule* playerAI;

    void __cdecl logMessage(char* format, ...);
};

void __cdecl TRIBE_Player::logMessage(char* format, ...) {
    char textOut[1024];

    if (this->playerAI != 0) {
        vsprintf(textOut, format, (&format) + 1);
        this->playerAI->logCommonHistory(textOut);
    }
}
