// caseD_3 (00536932) - switch case in RGE_View::view_function
// tile_screen_row == 3
//
// This is a code fragment from the parent function RGE_View::view_function.
// It is entered via the switch jump table (at 0053690b) with ESI = this
// and uses the parent function's stack frame (0x78 bytes of locals).
// The body decrements _picked_type [esp+28h], adds tile_half_wid to
// start_scr_col2 [esp+20h], increments start_map_row2 [esp+3Ch], then
// jumps to the switch default handler (00536992).
//
// __declspec(naked) is required because this is not a real function entry
// point but a switch case body spliced into the parent function. The prologue
// and stack frame are provided by the parent. The padding after the jmp is
// only for computing the correct short-jmp displacement (0x3B = 59 bytes to
// end_marker); only the first 37 bytes are extracted and compared.

__declspec(naked) void caseD_3(void)
{
    __asm {
        mov edx,[esp+28h]
        mov ecx,[esp+20h]
        mov eax,[esp+3Ch]
        dec edx
        mov [esp+28h],edx
        mov dx,[esi+10Ch]
        add ecx,edx
        inc eax
        mov [esp+20h],ecx
        mov [esp+3Ch],eax
        jmp short end_marker
        ; pad to make jmp displacement = 0x3B (59 bytes from next ip to end_marker)
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
    end_marker:
    }
}
