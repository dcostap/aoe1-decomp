
extern "C" void* __cdecl calloc(unsigned int, unsigned int);

// Log function at 00436610
class TDebuggingLog {
public:
    void Log(char* buf, const char* fmt, int val);
};

// Submit function at 004352C0  
class RGE_Command {
public:
    void submit(unsigned char* data, long size);
};

// Globals
extern char* g_log_buffer;         // [0x62C4FC]
extern const char g_fmt_str[];     // [0x588D10]

class TMap {
public:
    char gap_00[4];

    void checkForBuildInsertionSimple(unsigned char type, RGE_Command* cmd,
                                       int count, TDebuggingLog* log, long param5);
};

void TMap::checkForBuildInsertionSimple(unsigned char type, RGE_Command* cmd,
                                         int count, TDebuggingLog* log, long param5)
{
    if (cmd == 0 || count < 1)
        return;

    int size = count * 4 + 12;
    unsigned char* buf = (unsigned char*)calloc(1, size);
    if (buf == 0)
        return;

    int* dst = (int*)(buf + 12);
    for (int i = 0; i < count; i++)
        dst[i] = ((int*)cmd)[i];

    buf[0] = 0x68;
    buf[1] = (unsigned char)count;
    buf[2] = type;
    *(int*)(buf + 4) = (int)log;
    *(int*)(buf + 8) = (int)param5;

    log->Log(g_log_buffer, (char*)&g_fmt_str, count);
    cmd->submit(buf, size);
}
