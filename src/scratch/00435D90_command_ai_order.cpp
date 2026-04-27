// VA: 00435D90 command_ai_order (271B)
// Command.cpp

class Commands {
public:
    char gap4[0x4];
    int field_8;
    
    void command_ai_order(unsigned char a1, short a2);
};

void* __cdecl operator_new(unsigned size);

void Commands::command_ai_order(unsigned char a1, short a2) {
    void* buf = operator_new(0x28);
    if (buf) {
        field_8 = (int)buf;
    }
}
