extern void* DAT_0062c4fc;
void __cdecl debug_log(void* log, const char* msg);
extern char DAT_00580c28[];

class TCommunications_Handler_dp {
public:
    void DropPacketsIntentionally(int flag);
    char gap_00[0x1518];
    int intentional_drop;
};


void TCommunications_Handler_dp::DropPacketsIntentionally(int flag) {
    this->intentional_drop = flag;
    if (flag) {
        debug_log(DAT_0062c4fc, DAT_00580c28);
    }
}
