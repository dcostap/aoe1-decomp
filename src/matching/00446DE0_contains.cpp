// contains (00446DE0, 25 bytes, dstring.cpp)
// calls strstr and converts result to 0/1
#include "game_globals.h"
#include "game_types.h"

extern "C" char* __cdecl strstr(const char*, const char*);

class DString {
public:
    char* stringValue;
};

int DString::contains(const char* param) const {
    return strstr(stringValue, param) != 0;
}
