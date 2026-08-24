// TTaunt::GetTauntText - uses strcpy to copy a hardcoded string into TBuff
#include <string.h>

#ifndef AOE1_TAUNT_CONTEXT_H
class TTaunt {
public:
    char gap_00[0x14];
    char TBuff[32];

    char* GetTauntText(int id);
};
#endif

char* TTaunt::GetTauntText(int id) {
    strcpy(this->TBuff, (const char*)0x588B88);
    return this->TBuff;
}
