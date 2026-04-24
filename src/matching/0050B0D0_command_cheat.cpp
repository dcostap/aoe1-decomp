extern "C" void* __cdecl calloc(size_t, size_t);

void* debugging_log_global;

void logCommonHistory(void* logObj, const char* format, int param);

class RGE_Command {
public:
    void submit(void* buf, int size);
};

class TRIBE_Command : public RGE_Command {
public:
    void command_cheat(short param1, short param2);
};

void TRIBE_Command::command_cheat(short param1, short param2) {
    void* buf = calloc(1, 16);
    if (buf) {
        ((unsigned char*)buf)[0] = 0x67;
        *(short*)((unsigned char*)buf + 2) = param1;
        *(short*)((unsigned char*)buf + 4) = param2;
        ((unsigned char*)buf)[1] = 6;
        logCommonHistory(debugging_log_global, "      >SEND CMD CHEAT %d", param2);
        submit(buf, 0x10);
    }
}
