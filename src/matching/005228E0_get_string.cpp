class RGE_Base_Game {
public:
    char* get_string(long string_id, char* buffer, int buffer_size);
};

class TRIBE_Game : public RGE_Base_Game {
public:
    char* get_string(long string_id, char* buffer, int buffer_size);
};

extern void* StringTableX;
extern int (__stdcall *LoadStringA)(void* module, int string_id, char* buffer, int buffer_size);

char* TRIBE_Game::get_string(long string_id, char* buffer, int buffer_size) {
    if (LoadStringA(StringTableX, (int)string_id, buffer, buffer_size) == 0) {
        return ((RGE_Base_Game*)this)->get_string(string_id, buffer, buffer_size);
    }
    buffer[buffer_size - 1] = '\0';
    return buffer;
}
