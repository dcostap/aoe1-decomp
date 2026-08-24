#include <stdlib.h>

#ifndef AOE1_TAUNT_CONTEXT_H
class TTaunt {
public:
    int GetTauntNo(char* text);
};
#endif

int TTaunt::GetTauntNo(char* text) {
    int value;

    if (*text == '!') {
        text++;
    }
    value = atoi(text);
    if (value == 0) {
        return 0;
    }
    return value & ((value > 999) - 1);
}
