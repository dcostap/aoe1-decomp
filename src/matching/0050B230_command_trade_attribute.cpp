// VA: 0050B230 TRIBE_Command::command_trade_attribute
// PDB: tcommand.cpp lines 1632-1660.
// Preserve the shipped redundant object-list pointer check.

extern void* __cdecl calloc(unsigned int, unsigned int);

#ifndef TCOMMAND_CONTEXT_H
class TDebuggingLog {
public:
    void __cdecl Log(char* format, ...);
};

extern TDebuggingLog* L;

class RGE_Command {
protected:
    void submit(void* data, long size);
};

class TRIBE_Command : public RGE_Command {
public:
    void command_trade_attribute(int param_1, int param_2, long param_3);
};

class TRIBE_Command_Trade_Attribute {
public:
    unsigned char command;
    unsigned char unit_num;
    char gap_02[2];
    long attribute;
};
#endif

void TRIBE_Command::command_trade_attribute(int param_1, int param_2, long param_3) {
    TRIBE_Command_Trade_Attribute* buf =
        (TRIBE_Command_Trade_Attribute*)calloc(1, 0xC);
    int* p = (int*)(buf + 1);

    if (buf) {
        if (p) {
            *p = param_1;
            buf->command = 0x6D;
            buf->unit_num = 1;
            buf->attribute = param_3;
            L->Log((char*)"      >SEND CMD TRADE ATTR2");
            this->submit(buf, 0xC);
        }
    }
}
