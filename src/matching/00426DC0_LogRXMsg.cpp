class TDebuggingLog;
extern TDebuggingLog* g_debug_log;
#if !defined(COM_HAND_TU_CONTEXT)
extern void Log(TDebuggingLog* this_, char* fmt, ...);
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_00[0x10C8];
    unsigned long current_turn;
    char gap_10CC[0x448];
    unsigned char RGE_Guaranteed_Delivery;
    char gap_1515[0x3];

    void LogRXMsg(unsigned int param_1, unsigned int param_2, unsigned long param_3, unsigned char param_4, unsigned char param_5);
};
#endif // COM_HAND_TU_CONTEXT


void TCommunications_Handler::LogRXMsg(unsigned int param_1, unsigned int param_2, unsigned long param_3, unsigned char param_4, unsigned char param_5)
{
    if (this->RGE_Guaranteed_Delivery != 0) {
        Log(g_debug_log, "GTD: RX Ser#%d From P#%d T#%ld ToExecT#%d %d", param_1, param_2, this->current_turn, param_3, param_4, param_4, param_5);
    }
}
