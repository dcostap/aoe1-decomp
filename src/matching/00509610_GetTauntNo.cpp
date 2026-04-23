#include <stdlib.h>

class TTaunt {
public:
    int GetTauntNo(char* text);
};

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
