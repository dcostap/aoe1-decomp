#include <windows.h>

#include "../../include/tribegam_context.h"

#if 0
class RGE_Base_Game {
public:
    char* get_string(long string_id, char* buffer, int buffer_size);
};

class TRIBE_Game : public RGE_Base_Game {
public:
    char* get_string(long string_id, char* buffer, int buffer_size);
};
#endif

extern void* StringTableX;

char* TRIBE_Game::get_string(long string_id, char* buffer, int buffer_size) {
    if (LoadStringA(StringTableX, (int)string_id, buffer, buffer_size) == 0) {
        return this->RGE_Base_Game::get_string(string_id, buffer, buffer_size);
    }
    buffer[buffer_size - 1] = '\0';
    return buffer;
}
