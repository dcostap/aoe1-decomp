// 0042A650 TCommunications_Handler::RXAcknowledgeStoredMessage
// Size: 139 bytes

#define G_LOG_PTR (*(int*)0x62C4FC)

void Log(int log_obj, const char* fmt, ...);

class TCommunications_Handler {
public:
    char gap_00[0x1514];
    unsigned char RGE_Guaranteed_Delivery; // +0x1514
    char gap_1515[7];
    int WaitingForAck;                     // +0x151C
    int* StoredMessages;                   // +0x1520

    int RXAcknowledgeStoredMessage(unsigned int param_1, unsigned int param_2);
};

int TCommunications_Handler::RXAcknowledgeStoredMessage(unsigned int param_1, unsigned int param_2) {
    unsigned int loop_idx;
    unsigned int offset;

    if (!this->RGE_Guaranteed_Delivery) {
        Log(G_LOG_PTR, "!RGEGTD RxAck");
        return 0;
    }

    Log(G_LOG_PTR, "COMM: RX ACK from P#%d for Ser#%d", param_2, param_1);
    this->WaitingForAck = 0;

    this->WaitingForAck = 0;

    loop_idx = 0;
    offset = param_2 * 4 + 0x10;
    do {
        char* const msgs = (char*)this->StoredMessages;
        if (*(int*)(msgs + loop_idx + 4) == (int)param_1 && *(int*)(msgs + loop_idx + 4) != 0) {
            *(int*)(msgs + offset) = 0;
        }
        loop_idx += 0x38;
        offset += 0x38;
    } while (loop_idx <= 0x6D98);
    return 1;
}
