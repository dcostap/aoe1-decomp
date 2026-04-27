// attempt 1: 80 vs 90, too small
// attempt 2: 80 vs 90, while loop too small
// attempt 3: 80 vs 90, memmove/strlen too small
// PAUSED: VC5 memmove/strlen/while loop all produce 80 bytes, original uses repne scasb + rep movsd + rep movsb
// The rep-based string copy pattern is a specific VC5 codegen family that's hard to trigger

extern char s_Optional_Information;

class TCommunications_Handler {
public:
    char gap_0[0x10F8];
    char MyFriendlyName[64];
    char MyFormalName[64];

    void SetMyPlayerName(char* param_1);
};

void __cdecl memmove(void* dest, const void* src, unsigned int count);
unsigned int __cdecl strlen(const char* str);

void TCommunications_Handler::SetMyPlayerName(char* param_1) {
    unsigned int len = strlen(param_1);
    memmove(this->MyFriendlyName, param_1, len);
    len = strlen(&s_Optional_Information);
    memmove(this->MyFormalName, &s_Optional_Information, len);
}
