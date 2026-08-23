#ifndef BASEGAME_GROUPED_TU
#include <windows.h>
class RGE_Base_Game {
public:
    virtual char* get_string(long, char*, int);
};
extern void* StringTable;
#endif

char* RGE_Base_Game::get_string(long string_id, char* buffer, int buffer_size) {
    int result = LoadStringA(StringTable, string_id, buffer, buffer_size);
    if (!result) {
        *buffer = 0;
    }
    buffer[buffer_size - 1] = 0;
    return buffer;
}
