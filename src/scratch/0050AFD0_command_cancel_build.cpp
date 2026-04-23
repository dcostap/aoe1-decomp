class TDebuggingLog {
public:
    char gap_00[0x4];
    int id;
    void Log(char* text, char* message);
};

class RGE_Static_Object {
public:
    char gap_00[0x4];
    int id;
};

class TRIBE_Command_Cancel_Build {
public:
    unsigned char command;
    unsigned char gap_01[3];
    int unit_id;
};

class RGE_Command {
public:
    void* vtable_ptr;
    void* world;
    unsigned char* last_order;
    long last_order_size;
    long last_order_time;
    void* com_hand;

    void submit(void* packet, int size);
};

class TRIBE_Command : public RGE_Command {
public:
    void command_cancel_build(RGE_Static_Object* param_1);
};

extern char* L;
extern void* calloc(unsigned int, unsigned int);

void TRIBE_Command::command_cancel_build(RGE_Static_Object* param_1) {
    TRIBE_Command_Cancel_Build* packet = (TRIBE_Command_Cancel_Build*)calloc(1, 8);
    if (packet != 0) {
        TDebuggingLog* logger = (TDebuggingLog*)param_1->id;
        packet->command = 0x6A;
        packet->unit_id = logger->id;
        logger->Log(L, (char*)"      >SEND CMD CANCELBLD");
        this->submit(packet, 8);
    }
}
// tried raw bytes, then typed packet surface, then logger id field; mismatch stayed at the log/packet store scheduling basin
// remaining drift is the early push of the log string versus the packet byte store
