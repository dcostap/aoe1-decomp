class TDebuggingLog {
public:
    char gap_00[0x10];
    int Sequence;
    char gap_14[0x10];
    int SeqNo;

    char* YesOrNo(int value);
    void LogSequence(int param_1);
};

extern char s_Sequence_numbering[];
extern void __cdecl Log(TDebuggingLog* this_, char* format, char* value);

void TDebuggingLog::LogSequence(int param_1) {
    if (param_1 != 0) {
        this->Sequence = 1;
        this->SeqNo = 0;
    } else {
        this->Sequence = 0;
    }

    Log(this, s_Sequence_numbering, this->YesOrNo(this->Sequence));
}
