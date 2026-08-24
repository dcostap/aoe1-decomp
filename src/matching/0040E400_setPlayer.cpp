extern "C" char* __cdecl strcpy(char* dest, const char* src);
extern "C" char* __cdecl strncpy(char* dest, const char* src, unsigned int count);

#ifndef AOE1_AIMODULE_TU_CONTEXT
class AIModule {
public:
    char gap_00[0x4C];
    int playerNumberValue;
    char playerNameValue[0x40];

    void setPlayer(int playerNumber, char* playerName);
};
#endif

extern char s_Unknown[];

void AIModule::setPlayer(int playerNumber, char* playerName) {
    this->playerNumberValue = playerNumber;
    if (playerName != 0) {
        strncpy(this->playerNameValue, playerName, 0x3F);
        return;
    }
    strcpy(this->playerNameValue, s_Unknown);
}
