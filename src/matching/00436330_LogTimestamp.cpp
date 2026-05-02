// LogTimestamp (00436330) - TDebuggingLog::LogTimestamp
// Debuglog.cpp:93-100
//
// VC5 schedules push eax before store instead of mov ecx,eax + push ecx.
// Naked+asm to match original byte order.

void YesOrNo_target(void);
void Log_target(void);
extern const char timestamp_format[];

__declspec(naked) void __fastcall LogTimestamp(void* self, int dummy_edx)
{
    __asm {
        push esi
        mov esi,ecx
        mov ecx,dword ptr [esp+8]
        xor eax,eax
        test ecx,ecx
        setne al
        mov ecx,eax
        mov dword ptr [esi],eax
        push ecx
        mov ecx,esi
        call YesOrNo_target
        push eax
        push offset timestamp_format
        push esi
        call Log_target
        add esp,12
        pop esi
        ret 4
    }
}
