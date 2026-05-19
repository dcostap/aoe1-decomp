// 0042A650 TCommunications_Handler::RXAcknowledgeStoredMessage
// Size: 139 bytes
// MATCHED 2026-05-19: reuse param_2 as the moving destination offset and keep a
// separate loop_idx. Directly repeating the StoredMessages expression lets VC5
// use edx for loop_idx, esi for offset, eax for base, ecx for loaded value.

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

    if (!this->RGE_Guaranteed_Delivery) {
        Log(G_LOG_PTR, "!RGEGTD RxAck");
        return 0;
    }

    Log(G_LOG_PTR, "COMM: RX ACK from P#%d for Ser#%d", param_2, param_1);
    this->WaitingForAck = 0;

    loop_idx = 0;
    param_2 = param_2 * 4 + 0x10;
    do {
        if (*(int*)((char*)this->StoredMessages + loop_idx + 4) == (int)param_1 &&
            *(int*)((char*)this->StoredMessages + loop_idx + 4) != 0) {
            *(int*)((char*)this->StoredMessages + param_2) = 0;
        }
        loop_idx += 0x38;
        param_2 += 0x38;
    } while (loop_idx <= 0x6D98);
    return 1;
}
