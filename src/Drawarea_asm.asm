; Recovered assembly-owned TDrawArea methods.
.586
.model flat
option casemap:none

AREA_SYSTEM EQU 0
AREA_WIDTH EQU 18h
AREA_HEIGHT EQU 1Ch
AREA_CURRENT_OFFSETS EQU 0C0h
SYSTEM_DRAW_TYPE EQU 478h

EXTERN ?Lock@TDrawArea@@QAEPAEPADH@Z:PROC
EXTERN ?Unlock@TDrawArea@@QAEXPAD@Z:PROC
PUBLIC ?PtrClear@TDrawArea@@QAEXPAUtagRECT@@H@Z
PUBLIC ?PtrSpanCopy@TDrawArea@@QAEXPAV1@JJPAUtagRECT@@PAPAE@Z
PUBLIC ?OverlayMemCopy@TDrawArea@@QAEXAAUtagRECT@@0HHHH@Z

.data
ptr_clear_name BYTE 'PtrClear',0 ; original 00584574
span_copy_name BYTE 'PtrSpanCopy',0 ; original 00584598
overlay_copy_name BYTE 'OverlayMemCopy',0 ; original 005845C4

.code
; Preserve the original clipping, lock, row fill, and unlock sequence.
?PtrClear@TDrawArea@@QAEXPAUtagRECT@@H@Z PROC
    push ebp
    mov ebp, esp
    sub esp, 14h
    mov eax, DWORD PTR [ebp+8]
    push ebx
    push esi
    push edi
    mov edi, ecx
    test eax, eax
    mov DWORD PTR [ebp-14h], edi
    je clear_whole_area
    mov esi, DWORD PTR [eax]
    mov edx, DWORD PTR [eax+4]
    mov ecx, DWORD PTR [eax+8]
    mov eax, DWORD PTR [eax+12]
    mov DWORD PTR [ebp-4], esi
    mov DWORD PTR [ebp+8], edx
    jmp clear_check_rectangle
clear_whole_area:
    mov ecx, DWORD PTR [edi+AREA_WIDTH]
    mov eax, DWORD PTR [edi+AREA_HEIGHT]
    xor esi, esi
    xor edx, edx
    mov DWORD PTR [ebp-4], esi
    mov DWORD PTR [ebp+8], edx
clear_check_rectangle:
    test ecx, ecx
    jl clear_return
    cmp esi, ecx
    jg clear_return
    cmp esi, DWORD PTR [edi+AREA_WIDTH]
    jge clear_return
    test eax, eax
    jl clear_return
    cmp edx, eax
    jg clear_return
    cmp edx, DWORD PTR [edi+AREA_HEIGHT]
    jge clear_return
    test esi, esi
    jge clear_right
    xor esi, esi
    mov DWORD PTR [ebp-4], esi
clear_right:
    mov ebx, DWORD PTR [edi+AREA_WIDTH]
    cmp ecx, ebx
    jl clear_top
    lea ecx, [ebx-1]
clear_top:
    test edx, edx
    jge clear_bottom
    xor edx, edx
    mov DWORD PTR [ebp+8], edx
clear_bottom:
    mov ebx, DWORD PTR [edi+AREA_HEIGHT]
    cmp eax, ebx
    jl clear_dimensions
    lea eax, [ebx-1]
clear_dimensions:
    sub eax, edx
    sub ecx, esi
    inc eax
    inc ecx
    mov DWORD PTR [ebp-8], eax
    mov eax, DWORD PTR [edi+AREA_SYSTEM]
    test eax, eax
    mov DWORD PTR [ebp-0Ch], ecx
    je clear_rows
    cmp BYTE PTR [eax+SYSTEM_DRAW_TYPE], 2
    jne clear_rows
    push 1
    push OFFSET ptr_clear_name
    mov ecx, edi
    call ?Lock@TDrawArea@@QAEPAEPADH@Z
    test eax, eax
    je clear_return
clear_rows:
    mov eax, DWORD PTR [edi+AREA_CURRENT_OFFSETS]
    mov DWORD PTR [ebp-10h], eax
    ; The original inline fill block saves these registers inside its outer frame.
    push esi
    push edi
    push ebx
    cld
    mov edx, DWORD PTR [ebp+12]
    mov al, dl
    mov ah, dl
    shl eax, 16
    mov al, dl
    mov ah, al
clear_next_row:
    mov ebx, DWORD PTR [ebp+8]
    mov edi, DWORD PTR [ebp-10h]
    mov edi, DWORD PTR [edi+ebx*4]
    add edi, DWORD PTR [ebp-4]
    mov ecx, DWORD PTR [ebp-0Ch]
    mov edx, ecx
    sub ecx, edi
    sub ecx, edx
    and ecx, 3
    sub edx, ecx
    jle clear_tail
    rep stosb
    mov ecx, edx
    and edx, 3
    shr ecx, 2
    rep stosd
clear_tail:
    add ecx, edx
    rep stosb
    inc DWORD PTR [ebp+8]
    dec DWORD PTR [ebp-8]
    jne clear_next_row
    pop ebx
    pop edi
    pop esi
    mov ecx, DWORD PTR [ebp-14h]
    mov eax, DWORD PTR [ecx+AREA_SYSTEM]
    test eax, eax
    je clear_return
    cmp BYTE PTR [eax+SYSTEM_DRAW_TYPE], 2
    jne clear_return
    push OFFSET ptr_clear_name
    call ?Unlock@TDrawArea@@QAEXPAD@Z
clear_return:
    pop edi
    pop esi
    pop ebx
    mov esp, ebp
    pop ebp
    ret 8
?PtrClear@TDrawArea@@QAEXPAUtagRECT@@H@Z ENDP

; The receiver supplies pixels. The first argument is the destination.
; The original locks the destination conditionally and does not unlock it here.
?PtrSpanCopy@TDrawArea@@QAEXPAV1@JJPAUtagRECT@@PAPAE@Z PROC
    push ebp
    mov ebp, esp
    sub esp, 0Ch
    push ebx
    push esi
    push edi
    mov edi, DWORD PTR [ebp+14h]
    mov edx, ecx
    mov eax, DWORD PTR [edi]
    mov DWORD PTR [ebp-4], edx
    test eax, eax
    jl span_return
    mov ecx, DWORD PTR [edi+8]
    cmp eax, ecx
    jg span_return
    cmp ecx, DWORD PTR [edx+AREA_WIDTH]
    jge span_return
    mov ecx, DWORD PTR [edi+4]
    test ecx, ecx
    jl span_return
    mov eax, DWORD PTR [edi+12]
    cmp ecx, eax
    jg span_return
    cmp eax, DWORD PTR [edx+AREA_HEIGHT]
    jge span_return
    mov edx, DWORD PTR [ebp+0Ch]
    sub eax, ecx
    inc eax
    test edx, edx
    mov DWORD PTR [ebp+14h], eax
    jl span_return
    mov ebx, DWORD PTR [ebp+8]
    cmp edx, DWORD PTR [ebx+AREA_WIDTH]
    jge span_return
    mov esi, DWORD PTR [ebp+10h]
    test esi, esi
    jl span_return
    mov ecx, DWORD PTR [ebx+AREA_HEIGHT]
    cmp esi, ecx
    jge span_return
    add eax, esi
    cmp eax, ecx
    jle span_lock
    sub ecx, esi
    mov DWORD PTR [ebp+14h], ecx
span_lock:
    mov eax, DWORD PTR [ebp-4]
    mov eax, DWORD PTR [eax+AREA_SYSTEM]
    test eax, eax
    je span_tables
    cmp BYTE PTR [eax+SYSTEM_DRAW_TYPE], 2
    jne span_tables
    push 1
    push OFFSET span_copy_name
    mov ecx, ebx
    call ?Lock@TDrawArea@@QAEPAEPADH@Z
    test eax, eax
    je span_return
    mov edx, DWORD PTR [ebp+0Ch]
span_tables:
    mov ecx, DWORD PTR [edi]
    mov eax, DWORD PTR [ebp-4]
    mov DWORD PTR [ebp+10h], edx
    mov edx, DWORD PTR [edi+4]
    mov DWORD PTR [ebp-8], ecx
    mov ecx, DWORD PTR [eax+AREA_CURRENT_OFFSETS]
    mov DWORD PTR [ebp+8], edx
    mov edx, DWORD PTR [ebx+AREA_CURRENT_OFFSETS]
    mov DWORD PTR [ebp+0Ch], esi
    mov DWORD PTR [ebp-0Ch], ecx
    mov DWORD PTR [ebp-4], edx
    push esi
    push edi
    push ebx
    cld
span_next_row:
    mov eax, DWORD PTR [ebp+8]
    mov ebx, DWORD PTR [ebp+0Ch]
    mov esi, DWORD PTR [ebp-0Ch]
    mov edi, DWORD PTR [ebp-4]
    mov esi, DWORD PTR [esi+eax*4]
    mov edi, DWORD PTR [edi+ebx*4]
    add esi, DWORD PTR [ebp-8]
    add edi, DWORD PTR [ebp+10h]
    mov ebx, DWORD PTR [ebp+18h]
    mov ebx, DWORD PTR [ebx+eax*4]
    or ebx, ebx
    je span_row_done
span_next_node:
    push esi
    push edi
    mov eax, DWORD PTR [ebx+8]
    add esi, eax
    add edi, eax
    mov ecx, DWORD PTR [ebx+0Ch]
    sub ecx, eax
    inc ecx
    mov eax, ecx
    sub ecx, edi
    sub ecx, eax
    and ecx, 3
    sub eax, ecx
    jle span_tail
    rep movsb
    mov ecx, eax
    and eax, 3
    shr ecx, 2
    rep movsd
span_tail:
    add ecx, eax
    rep movsb
    pop edi
    pop esi
    mov ebx, DWORD PTR [ebx]
    or ebx, ebx
    jne span_next_node
span_row_done:
    inc DWORD PTR [ebp+8]
    inc DWORD PTR [ebp+0Ch]
    dec DWORD PTR [ebp+14h]
    jne span_next_row
    pop ebx
    pop edi
    pop esi
span_return:
    pop edi
    pop esi
    pop ebx
    mov esp, ebp
    pop ebp
    ret 14h
?PtrSpanCopy@TDrawArea@@QAEXPAV1@JJPAUtagRECT@@PAPAE@Z ENDP

; Copy overlapping overlay rows in the requested direction.
; Width rounds up to complete DWORDs, as in the original.
?OverlayMemCopy@TDrawArea@@QAEXAAUtagRECT@@0HHHH@Z PROC
    push ebp
    mov ebp, esp
    sub esp, 18h
    mov eax, DWORD PTR [ebp+10h]
    push ebx
    push esi
    push edi
    test eax, eax
    mov DWORD PTR [ebp-18h], ecx
    jne overlay_lock
    mov eax, DWORD PTR [ebp+14h]
    test eax, eax
    je overlay_return
overlay_lock:
    mov eax, DWORD PTR [ecx+AREA_SYSTEM]
    test eax, eax
    je overlay_rectangle
    cmp BYTE PTR [eax+SYSTEM_DRAW_TYPE], 2
    jne overlay_rectangle
    push 1
    push OFFSET overlay_copy_name
    call ?Lock@TDrawArea@@QAEPAEPADH@Z
    test eax, eax
    je overlay_return
overlay_rectangle:
    mov eax, DWORD PTR [ebp+8]
    mov edi, DWORD PTR [ebp+18h]
    mov DWORD PTR [ebp-10h], 0
    mov edx, DWORD PTR [eax+12]
    mov ecx, DWORD PTR [eax+4]
    mov ebx, DWORD PTR [eax+8]
    mov eax, DWORD PTR [eax]
    mov esi, edx
    sub esi, ecx
    inc esi
    mov DWORD PTR [ebp-4], esi
    mov esi, ebx
    sub esi, eax
    add eax, edi
    add esi, 4
    mov DWORD PTR [ebp-0Ch], eax
    mov eax, DWORD PTR [ebp+0Ch]
    sar esi, 2
    mov DWORD PTR [ebp-14h], esi
    mov esi, edi
    add esi, DWORD PTR [eax]
    mov DWORD PTR [ebp-8], esi
    mov esi, DWORD PTR [ebp+14h]
    test esi, esi
    mov esi, DWORD PTR [ebp+1Ch]
    jge overlay_down
    add edx, esi
    mov DWORD PTR [ebp+8], -1
    mov DWORD PTR [ebp+0Ch], edx
    mov edx, DWORD PTR [eax+12]
    add edx, esi
    mov DWORD PTR [ebp+18h], edx
overlay_down:
    mov edx, DWORD PTR [ebp+14h]
    test edx, edx
    jle overlay_horizontal
    lea edx, [esi+ecx]
    mov DWORD PTR [ebp+8], 1
    mov DWORD PTR [ebp+0Ch], edx
    mov edx, DWORD PTR [eax+4]
    add edx, esi
    mov DWORD PTR [ebp+18h], edx
    mov edx, DWORD PTR [ebp+14h]
    test edx, edx
overlay_horizontal:
    jne overlay_table
    mov edx, DWORD PTR [eax+4]
    add ecx, esi
    add edx, esi
    mov DWORD PTR [ebp+0Ch], ecx
    mov DWORD PTR [ebp+18h], edx
    mov edx, DWORD PTR [ebp+10h]
    mov ecx, 1
    test edx, edx
    mov DWORD PTR [ebp+8], ecx
    jge overlay_table
    mov edx, DWORD PTR [eax+8]
    mov DWORD PTR [ebp-10h], ecx
    lea ecx, [edi+ebx-3]
    lea eax, [edx+edi-3]
    mov DWORD PTR [ebp-0Ch], ecx
    mov DWORD PTR [ebp-8], eax
overlay_table:
    mov ecx, DWORD PTR [ebp-18h]
    mov eax, DWORD PTR [ebp-10h]
    test eax, eax
    mov edx, DWORD PTR [ecx+AREA_CURRENT_OFFSETS]
    mov DWORD PTR [ebp+14h], edx
    jne overlay_reverse
    push esi
    push edi
    push ebx
    cld
    mov ebx, DWORD PTR [ebp+14h]
    mov eax, DWORD PTR [ebp+0Ch]
    mov edx, DWORD PTR [ebp+18h]
overlay_next_forward:
    mov esi, DWORD PTR [ebx+eax*4]
    mov edi, DWORD PTR [ebx+edx*4]
    add esi, DWORD PTR [ebp-0Ch]
    add edi, DWORD PTR [ebp-8]
    mov ecx, DWORD PTR [ebp-14h]
    rep movsd
    add eax, DWORD PTR [ebp+8]
    add edx, DWORD PTR [ebp+8]
    dec DWORD PTR [ebp-4]
    jne overlay_next_forward
    pop ebx
    pop edi
    pop esi
    jmp overlay_unlock
overlay_reverse:
    push esi
    push edi
    push ebx
    std
    mov ebx, DWORD PTR [ebp+14h]
    mov eax, DWORD PTR [ebp+0Ch]
    mov edx, DWORD PTR [ebp+18h]
overlay_next_reverse:
    mov esi, DWORD PTR [ebx+eax*4]
    mov edi, DWORD PTR [ebx+edx*4]
    add esi, DWORD PTR [ebp-0Ch]
    add edi, DWORD PTR [ebp-8]
    mov ecx, DWORD PTR [ebp-14h]
    rep movsd
    add eax, DWORD PTR [ebp+8]
    add edx, DWORD PTR [ebp+8]
    dec DWORD PTR [ebp-4]
    jne overlay_next_reverse
    cld
    pop ebx
    pop edi
    pop esi
overlay_unlock:
    mov ecx, DWORD PTR [ebp-18h]
    mov eax, DWORD PTR [ecx+AREA_SYSTEM]
    test eax, eax
    je overlay_return
    cmp BYTE PTR [eax+SYSTEM_DRAW_TYPE], 2
    jne overlay_return
    push OFFSET overlay_copy_name
    call ?Unlock@TDrawArea@@QAEXPAD@Z
overlay_return:
    pop edi
    pop esi
    pop ebx
    mov esp, ebp
    pop ebp
    ret 18h
?OverlayMemCopy@TDrawArea@@QAEXAAUtagRECT@@0HHHH@Z ENDP
END
