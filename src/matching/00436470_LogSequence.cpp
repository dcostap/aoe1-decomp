#ifndef DEBUGLOG_CANONICAL_TU
class TDebuggingLog {
public:
    char gap_00[0x10];
    int Sequence;
    char gap_14[0x10];
    int SeqNo;

protected:
    char* YesOrNo(int value);
public:
    void __cdecl Log(char* format, ...);
    void LogSequence(int param_1);
};
#endif

extern char s_Sequence_numbering[];
void TDebuggingLog::LogSequence(int param_1) {
    if (param_1 != 0) {
        this->Sequence = 1;
        this->SeqNo = 0;
    } else {
        this->Sequence = 0;
    }

    this->Log(s_Sequence_numbering, this->YesOrNo(this->Sequence));
}
