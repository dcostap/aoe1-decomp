extern void* L;
extern void* __cdecl calloc(unsigned int, unsigned int);

class RGE_Command {
public:
    void submit(void* data, int size);
};

class TRIBE_Command : public RGE_Command {
public:
    void command_trade_attribute(int param_1, int param_2, long param_3);
};

void Log(void* log, const char* fmt);

void TRIBE_Command::command_trade_attribute(int param_1, int param_2, long param_3) {
    unsigned char* buf = (unsigned char*)calloc(1, 0xC);
    int* p = (int*)(buf + 8);

    if (buf) {
        if (p) {
            *p = param_1;
            buf[0] = 0x6D;
            buf[1] = 1;
            *(long*)(buf + 4) = param_3;
            Log(L, "      >SEND CMD TRADE ATTR2");
            this->submit(buf, 0xC);
        }
    }
}
