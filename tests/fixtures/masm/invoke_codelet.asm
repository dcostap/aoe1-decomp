; Test adapter only. This object does not enter the game build.
.586
.model flat
option casemap:none
PUBLIC _probe_codelet
.code
_probe_codelet PROC
    push ebp
    mov ebp, esp
    push ebx
    push esi
    push edi
    mov ebx, DWORD PTR [ebp+0Ch]
    mov DWORD PTR [ebx], OFFSET codelet_return
    mov esi, DWORD PTR [ebp+10h]
    mov edi, DWORD PTR [ebp+14h]
    mov ecx, DWORD PTR [ebp+18h]
    mov eax, DWORD PTR [ebp+1Ch]
    jmp DWORD PTR [ebp+8]
codelet_return:
    pop edi
    pop esi
    pop ebx
    pop ebp
    ret
_probe_codelet ENDP
END
