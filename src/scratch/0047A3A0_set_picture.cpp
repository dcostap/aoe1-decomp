// STATUS: PAUSED
// BLOCKER: exact legacy source uses forbidden naked inline assembly
// NOTE: moved from matching after the 2026-08-16 inline-assembly policy audit
// NEXT: use the proven TPicturePanel layout, free_pic member, and virtual slot surface

// set_picture (0047A3A0) - TPicturePanel::set_picture
// Pnl_pic.cpp:93-99
//
// Uses naked+asm because mixing C++ and inline asm forces EBP frame.

void free_pic_target(void);

__declspec(naked) void __fastcall set_picture_hack(void* self, int dummy_edx)
{
    __asm {
        push esi
        mov esi,ecx
        call free_pic_target
        mov ecx,dword ptr [esp+12]
        mov eax,dword ptr [esp+8]
        mov edx,dword ptr [esi]
        mov dword ptr [esi+256],ecx
        push 1
        mov ecx,esi
        mov dword ptr [esi+280],eax
        mov dword ptr [esi+268],0
        call dword ptr [edx+32]
        pop esi
        ret 8
    }
}
