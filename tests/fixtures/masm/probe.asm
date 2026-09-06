.586
.MMX
.model flat
option casemap:none

EXTERN _ExitProcess@4:PROC
PUBLIC _ASMSet_Color_Xform
PUBLIC _probe_start
PUBLIC _probe_color
PUBLIC ?set@AsmProbe@@QAEXH@Z

.data
_probe_color DWORD 0
_probe_vector QWORD 0
_probe_integer DWORD 0

.code
; Recover the low-byte replication operation at original VA 0056C760.
_ASMSet_Color_Xform PROC
    push ebp
    mov ebp, esp
    mov eax, DWORD PTR [ebp+8]
    mov cl, al
    mov ah, al
    bswap eax
    mov al, cl
    mov ah, cl
    mov DWORD PTR [_probe_color], eax
    pop ebp
    ret
_ASMSet_Color_Xform ENDP

_probe_start PROC
    xor esi, esi
probe_next:
    mov eax, esi
    xor eax, 0A5C30000h
    push eax
    call _ASMSet_Color_Xform
    add esp, 4
    mov eax, esi
    and eax, 0FFh
    imul eax, eax, 01010101h
    cmp eax, DWORD PTR [_probe_color]
    jne probe_failed
    inc esi
    cmp esi, 10000h
    jne probe_next
    pxor mm0, mm0
    pcmpeqb mm0, mm0
    psrlw mm0, 1
    movq QWORD PTR [_probe_vector], mm0
    emms
    cmp DWORD PTR [_probe_vector], 07FFF7FFFh
    jne probe_failed
    cmp DWORD PTR [_probe_vector+4], 07FFF7FFFh
    jne probe_failed
    fld1
    fld1
    faddp st(1), st(0)
    fistp DWORD PTR [_probe_integer]
    cmp DWORD PTR [_probe_integer], 2
    jne probe_failed
    push 0
    call _ExitProcess@4
probe_failed:
    push 1
    call _ExitProcess@4
_probe_start ENDP

; Test VC5 C++ member-name decoration and the thiscall argument convention.
?set@AsmProbe@@QAEXH@Z PROC
    mov eax, DWORD PTR [esp+4]
    mov DWORD PTR [ecx], eax
    ret 4
?set@AsmProbe@@QAEXH@Z ENDP
END
