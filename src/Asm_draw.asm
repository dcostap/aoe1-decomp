; Original Asm_draw.obj drawing state and entrypoints.
; Standalone MASM source. C/C++ compilation remains on VC5.
.586
.MMX
.model flat
option casemap:none

PUBLIC _ASMSet_Shadowing
PUBLIC _ASMSet_Surface_Info
PUBLIC _ASMSet_Color_Xform
PUBLIC _ASMGet_Color_Xform
PUBLIC _ASMSet_Xlate_Table
PUBLIC _ASMDraw_HLine

.data
surface_offsets DWORD 0       ; original 0088C000
span_heads DWORD 0            ; original 0088C004
span_tails DWORD 0            ; original 0088C008
xlate_table DWORD 0           ; original 0088C01C
color_xform DWORD 0           ; original 0088C040
ALIGN 16
shadow_mask QWORD 2 DUP(0)     ; original 0088C060
shadow_value QWORD 2 DUP(0)    ; original 0088C070
min_line DWORD 0              ; original 0088C080
max_line DWORD 0              ; original 0088C084
min_span DWORD 0              ; original 0088C088
max_span DWORD 0              ; original 0088C08C
draw_pixel_ptr DWORD 0        ; original 0088C014
draw_row_base DWORD 0         ; original 0088C020
draw_length DWORD 0           ; original 0088C038
draw_span DWORD 0             ; original 0088C03C
draw_resume DWORD 0           ; original 0088C044
draw_clip_skip DWORD 0        ; original 0088C04C

.code
; The codelets retain the original store widths and cursor update order.
FILL_BYTES MACRO count
    IF count EQ 1
        mov BYTE PTR [edi], al
        inc edi
    ELSEIF count EQ 2
        mov WORD PTR [edi], ax
        add edi, 2
    ELSEIF count EQ 3
        mov WORD PTR [edi], ax
        mov BYTE PTR [edi+2], al
        add edi, 3
    ELSEIF count EQ 4
        mov DWORD PTR [edi], eax
        add edi, 4
    ENDIF
ENDM

PATTERN_BYTES MACRO count, odd
    IF odd AND (count EQ 1)
        mov BYTE PTR [edi], ah
        inc edi
    ELSEIF odd AND (count EQ 2)
        mov BYTE PTR [edi], ah
        mov BYTE PTR [edi+1], al
        add edi, 2
    ELSEIF odd AND (count EQ 3)
        mov BYTE PTR [edi], ah
        mov WORD PTR [edi+1], ax
        add edi, 3
    ELSE
        FILL_BYTES count
    ENDIF
ENDM

SHORT_FILL MACRO name, first, second, third, odd:=<0>
name LABEL NEAR
    PATTERN_BYTES first, odd
    FILL_BYTES second
    FILL_BYTES third
    jmp DWORD PTR [draw_resume]
ENDM

LONG_FILL MACRO head, tail, pattern:=<0>
LOCAL fill_loop
IF pattern
pattern_long_&head&_&tail LABEL NEAR
    PATTERN_BYTES head, (head AND 1)
ELSE
solid_long_&head&_&tail LABEL NEAR
    FILL_BYTES head
ENDIF
    IF (head+tail) EQ 1
        dec ecx
    ELSEIF (head+tail) GT 1
        sub ecx, head+tail
    ENDIF
fill_loop:
    FILL_BYTES 4
    sub ecx, 4
    ja fill_loop
    FILL_BYTES tail
    jmp DWORD PTR [draw_resume]
ENDM

draw_done LABEL NEAR
    jmp DWORD PTR [draw_resume]
SHORT_FILL solid_1, 1, 0, 0
SHORT_FILL solid_2, 2, 0, 0
SHORT_FILL solid_2_cross, 1, 1, 0
SHORT_FILL solid_3, 3, 0, 0
SHORT_FILL solid_3_cross, 1, 2, 0
SHORT_FILL solid_4_0, 4, 0, 0
SHORT_FILL solid_4_1, 3, 1, 0
SHORT_FILL solid_4_2, 2, 2, 0
SHORT_FILL solid_4_3, 1, 3, 0
SHORT_FILL solid_5_0, 4, 1, 0
SHORT_FILL solid_5_1, 3, 2, 0
SHORT_FILL solid_5_2, 2, 3, 0
SHORT_FILL solid_5_3, 1, 4, 0
SHORT_FILL solid_6_0, 4, 2, 0
SHORT_FILL solid_6_1, 3, 3, 0
SHORT_FILL solid_6_2, 2, 4, 0
SHORT_FILL solid_6_3, 1, 4, 1
SHORT_FILL solid_7_0, 4, 3, 0
SHORT_FILL solid_7_1, 3, 4, 0
SHORT_FILL solid_7_2, 2, 4, 1
SHORT_FILL solid_7_3, 1, 4, 2
LONG_FILL 0, 0
LONG_FILL 1, 0
LONG_FILL 2, 0
LONG_FILL 3, 0
LONG_FILL 0, 1
LONG_FILL 1, 1
LONG_FILL 2, 1
LONG_FILL 3, 1
LONG_FILL 0, 2
LONG_FILL 1, 2
LONG_FILL 2, 2
LONG_FILL 3, 2
LONG_FILL 0, 3
LONG_FILL 1, 3
LONG_FILL 2, 3
LONG_FILL 3, 3

ALIGN 4
solid_fill_table LABEL DWORD ; original 0056A700, solid-color half
    DWORD OFFSET draw_done, OFFSET draw_done, OFFSET draw_done, OFFSET draw_done
    DWORD OFFSET solid_1, OFFSET solid_1, OFFSET solid_1, OFFSET solid_1
    DWORD OFFSET solid_2, OFFSET solid_2, OFFSET solid_2, OFFSET solid_2_cross
    DWORD OFFSET solid_3, OFFSET solid_3, OFFSET solid_3, OFFSET solid_3_cross
    DWORD OFFSET solid_4_0, OFFSET solid_4_1, OFFSET solid_4_2, OFFSET solid_4_3
    DWORD OFFSET solid_5_0, OFFSET solid_5_1, OFFSET solid_5_2, OFFSET solid_5_3
    DWORD OFFSET solid_6_0, OFFSET solid_6_1, OFFSET solid_6_2, OFFSET solid_6_3
    DWORD OFFSET solid_7_0, OFFSET solid_7_1, OFFSET solid_7_2, OFFSET solid_7_3
    REPT 6
        DWORD OFFSET solid_long_0_0, OFFSET solid_long_3_1, OFFSET solid_long_2_2, OFFSET solid_long_1_3
        DWORD OFFSET solid_long_0_1, OFFSET solid_long_3_2, OFFSET solid_long_2_3, OFFSET solid_long_1_0
        DWORD OFFSET solid_long_0_2, OFFSET solid_long_3_3, OFFSET solid_long_2_0, OFFSET solid_long_1_1
        DWORD OFFSET solid_long_0_3, OFFSET solid_long_3_0, OFFSET solid_long_2_1, OFFSET solid_long_1_2
    ENDM

pattern_fill_table LABEL DWORD ; original 0056A900, patterned forward-fill half
    DWORD OFFSET draw_done, OFFSET draw_done, OFFSET draw_done, OFFSET draw_done
    DWORD OFFSET pattern_1_even, OFFSET pattern_1_odd, OFFSET pattern_1_even, OFFSET pattern_1_odd
    DWORD OFFSET pattern_2_even, OFFSET pattern_2_odd, OFFSET pattern_2_even, OFFSET pattern_2_odd
    DWORD OFFSET pattern_3_0, OFFSET pattern_3_1, OFFSET pattern_3_2, OFFSET pattern_3_3
    DWORD OFFSET pattern_4_0, OFFSET pattern_4_1, OFFSET pattern_4_2, OFFSET pattern_4_3
    DWORD OFFSET pattern_5_0, OFFSET pattern_5_1, OFFSET pattern_5_2, OFFSET pattern_5_3
    DWORD OFFSET pattern_6_0, OFFSET pattern_6_1, OFFSET pattern_6_2, OFFSET pattern_6_3
    DWORD OFFSET pattern_7_0, OFFSET pattern_7_1, OFFSET pattern_7_2, OFFSET pattern_7_3
    REPT 6
        DWORD OFFSET pattern_long_0_0, OFFSET pattern_long_3_1, OFFSET pattern_long_2_2, OFFSET pattern_long_1_3
        DWORD OFFSET pattern_long_0_1, OFFSET pattern_long_3_2, OFFSET pattern_long_2_3, OFFSET pattern_long_1_0
        DWORD OFFSET pattern_long_0_2, OFFSET pattern_long_3_3, OFFSET pattern_long_2_0, OFFSET pattern_long_1_1
        DWORD OFFSET pattern_long_0_3, OFFSET pattern_long_3_0, OFFSET pattern_long_2_1, OFFSET pattern_long_1_2
    ENDM

plain_copy_table LABEL DWORD ; original 0056A300, unmasked forward-copy half
    DWORD OFFSET draw_done, OFFSET draw_done, OFFSET draw_done, OFFSET draw_done
    DWORD OFFSET copy_1, OFFSET copy_1, OFFSET copy_1, OFFSET copy_1
    DWORD OFFSET copy_2, OFFSET copy_2, OFFSET copy_2, OFFSET copy_2_cross
    DWORD OFFSET copy_3, OFFSET copy_3, OFFSET copy_3, OFFSET copy_3_cross
    DWORD OFFSET copy_4_0, OFFSET copy_4_1, OFFSET copy_4_2, OFFSET copy_4_3
    DWORD OFFSET copy_5_0, OFFSET copy_5_middle, OFFSET copy_5_middle, OFFSET copy_5_3
    DWORD OFFSET copy_6_0, OFFSET copy_6_1, OFFSET copy_6_2, OFFSET copy_6_3
    DWORD OFFSET copy_7_0, OFFSET copy_7_1, OFFSET copy_7_2, OFFSET copy_7_3
    REPT 6
        DWORD OFFSET copy_long_0_0, OFFSET copy_long_3_1, OFFSET copy_long_2_2, OFFSET copy_long_1_3
        DWORD OFFSET copy_long_0_1, OFFSET copy_long_3_2, OFFSET copy_long_2_3, OFFSET copy_long_1_0
        DWORD OFFSET copy_long_0_2, OFFSET copy_long_3_3, OFFSET copy_long_2_0, OFFSET copy_long_1_1
        DWORD OFFSET copy_long_0_3, OFFSET copy_long_3_0, OFFSET copy_long_2_1, OFFSET copy_long_1_2
    ENDM

length_index LABEL BYTE      ; original 0056B300
lookup_value = 0
    REPT 32
        BYTE lookup_value*4
lookup_value = lookup_value+1
    ENDM
    REPT 14
lookup_value = 16
        REPT 16
            BYTE lookup_value*4
lookup_value = lookup_value+1
        ENDM
    ENDM

; Repeat the two shadow mask/value pairs across four row entries.
_ASMSet_Shadowing PROC
    push ebp
    mov ebp, esp
    mov eax, DWORD PTR [ebp+8]
    mov DWORD PTR [shadow_mask], eax
    mov DWORD PTR [shadow_mask+8], eax
    mov eax, DWORD PTR [ebp+12]
    mov DWORD PTR [shadow_value], eax
    mov DWORD PTR [shadow_value+8], eax
    mov eax, DWORD PTR [ebp+16]
    mov DWORD PTR [shadow_mask+4], eax
    mov DWORD PTR [shadow_mask+12], eax
    mov eax, DWORD PTR [ebp+20]
    mov DWORD PTR [shadow_value+4], eax
    mov DWORD PTR [shadow_value+12], eax
    pop ebp
    ret
_ASMSet_Shadowing ENDP

_ASMSet_Surface_Info PROC
    push ebp
    mov ebp, esp
    mov eax, DWORD PTR [ebp+8]
    mov DWORD PTR [surface_offsets], eax
    mov eax, DWORD PTR [ebp+12]
    mov DWORD PTR [span_heads], eax
    mov eax, DWORD PTR [ebp+16]
    mov DWORD PTR [span_tails], eax
    mov eax, DWORD PTR [ebp+24]
    mov DWORD PTR [min_line], eax
    mov eax, DWORD PTR [ebp+32]
    mov DWORD PTR [max_line], eax
    mov eax, DWORD PTR [ebp+20]
    mov DWORD PTR [min_span], eax
    mov eax, DWORD PTR [ebp+28]
    mov DWORD PTR [max_span], eax
    pop ebp
    ret
_ASMSet_Surface_Info ENDP

; The original repeats the low byte without changing arithmetic flags.
_ASMSet_Color_Xform PROC
    push ebp
    mov ebp, esp
    mov eax, DWORD PTR [ebp+8]
    mov cl, al
    mov ah, al
    bswap eax
    mov al, cl
    mov ah, cl
    mov DWORD PTR [color_xform], eax
    pop ebp
    ret
_ASMSet_Color_Xform ENDP

_ASMGet_Color_Xform PROC
    mov eax, DWORD PTR [color_xform]
    and eax, 0FFh
    ret
_ASMGet_Color_Xform ENDP

_ASMSet_Xlate_Table PROC
    push ebp
    mov ebp, esp
    mov eax, DWORD PTR [ebp+8]
    mov DWORD PTR [xlate_table], eax
    pop ebp
    ret
_ASMSet_Xlate_Table ENDP

; Clip an inclusive horizontal line against the surface and linked visible spans.
_ASMDraw_HLine PROC
    push ebp
    mov ebp, esp
    push ebx
    push esi
    push edi
    mov eax, DWORD PTR [ebp+10h]
    cmp eax, DWORD PTR [min_line]
    jl hline_return
    cmp eax, DWORD PTR [max_line]
    jg hline_return
    mov eax, DWORD PTR [ebp+8]
    mov ebx, DWORD PTR [ebp+0Ch]
    cmp eax, ebx
    jle hline_check_x
    xchg ebx, eax
    mov DWORD PTR [ebp+8], eax
    mov DWORD PTR [ebp+0Ch], ebx
hline_check_x:
    cmp ebx, DWORD PTR [min_span]
    jl hline_return
    cmp eax, DWORD PTR [max_span]
    jg hline_return
    cmp eax, DWORD PTR [min_span]
    jge hline_right
    mov eax, DWORD PTR [min_span]
    mov DWORD PTR [ebp+8], eax
hline_right:
    cmp ebx, DWORD PTR [max_span]
    jle hline_head
    mov ebx, DWORD PTR [max_span]
    mov DWORD PTR [ebp+0Ch], ebx
hline_head:
    mov ecx, DWORD PTR [ebp+10h]
    mov esi, DWORD PTR [span_heads]
    mov edi, DWORD PTR [esi+ecx*4]
    or edi, edi
    je hline_return
    mov DWORD PTR [draw_span], edi
    mov edx, eax
    mov ecx, ebx
    sub ebx, eax
    inc ebx
    mov DWORD PTR [draw_length], ebx
    mov DWORD PTR [draw_resume], OFFSET hline_return
    mov esi, DWORD PTR [surface_offsets]
    mov eax, DWORD PTR [ebp+10h]
    mov eax, DWORD PTR [esi+eax*4]
    mov DWORD PTR [draw_row_base], eax
    add eax, edx
    mov DWORD PTR [draw_pixel_ptr], eax
hline_find_span:
    cmp ecx, DWORD PTR [edi+8]
    jl hline_return
    cmp edx, DWORD PTR [edi+0Ch]
    jle hline_in_span
    mov edi, DWORD PTR [edi]
    or edi, edi
    jne hline_find_span
    jmp hline_return
hline_in_span:
    cmp edx, DWORD PTR [edi+8]
    jl hline_clip
    cmp ecx, DWORD PTR [edi+0Ch]
    jg hline_clip
    mov al, BYTE PTR [ebp+14h]
    mov ecx, DWORD PTR [draw_length]
    mov ah, al
    mov edx, ecx
    shl eax, 16
    and edx, 7Fh
    cmp ecx, 80h
    jl hline_direct_index
    or dl, 80h
hline_direct_index:
    mov edi, DWORD PTR [draw_pixel_ptr]
    mov al, BYTE PTR [ebp+14h]
    mov ebx, edi
    mov ah, al
    and ebx, 3
    or bl, BYTE PTR [edx+length_index]
    jmp DWORD PTR [ebx*4+solid_fill_table]
hline_clip:
    mov DWORD PTR [draw_span], edi
    jmp hline_clip_span
hline_next_span:
    mov ebx, DWORD PTR [draw_span]
    mov ebx, DWORD PTR [ebx]
    or ebx, ebx
    je hline_return
    mov DWORD PTR [draw_span], ebx
    mov DWORD PTR [draw_resume], OFFSET hline_return
hline_clip_span:
    mov ebx, DWORD PTR [draw_span]
    mov edi, DWORD PTR [ebp+8]
    mov edx, DWORD PTR [ebp+0Ch]
    mov ecx, DWORD PTR [draw_length]
    cmp edx, DWORD PTR [ebx+8]
    jl hline_return
    cmp edi, DWORD PTR [ebx+0Ch]
    jg hline_next_span
    xor eax, eax
    cmp edi, DWORD PTR [ebx+8]
    jge hline_clip_right
    mov eax, DWORD PTR [ebx+8]
    sub eax, edi
    sub ecx, eax
hline_clip_right:
    mov DWORD PTR [draw_clip_skip], eax
    cmp edx, DWORD PTR [ebx+0Ch]
    jle hline_clipped_fill
    mov eax, edx
    sub eax, DWORD PTR [ebx+0Ch]
    sub ecx, eax
    mov DWORD PTR [draw_resume], OFFSET hline_next_span
hline_clipped_fill:
    mov edi, DWORD PTR [draw_pixel_ptr]
    mov al, BYTE PTR [ebp+14h]
    mov edx, ecx
    mov ah, al
    and edx, 7Fh
    shl eax, 16
    cmp ecx, 80h
    jl hline_clipped_index
    or dl, 80h
hline_clipped_index:
    add edi, DWORD PTR [draw_clip_skip]
    mov al, BYTE PTR [ebp+14h]
    mov ebx, edi
    mov ah, al
    and ebx, 3
    or bl, BYTE PTR [edx+length_index]
    jmp DWORD PTR [ebx*4+solid_fill_table]
hline_return:
    pop edi
    pop esi
    pop ebx
    pop ebp
    ret
_ASMDraw_HLine ENDP

; Sprite literal-copy blocks. Short blocks retain their distinct read order.
; Some blocks read outside the requested payload. Do not narrow those reads.
copy_1 LABEL NEAR
    mov al, BYTE PTR [esi]
    inc esi
    mov BYTE PTR [edi], al
    inc edi
    jmp DWORD PTR [draw_resume]
copy_2 LABEL NEAR
    mov eax, DWORD PTR [esi]
    add esi, 2
    mov WORD PTR [edi], ax
    add edi, 2
    jmp DWORD PTR [draw_resume]
copy_2_cross LABEL NEAR
    mov eax, DWORD PTR [esi]
    add esi, 2
    mov BYTE PTR [edi], al
    mov BYTE PTR [edi+1], ah
    add edi, 2
    jmp DWORD PTR [draw_resume]
copy_3 LABEL NEAR
    mov eax, DWORD PTR [esi]
    add esi, 3
    mov WORD PTR [edi], ax
    shr eax, 8
    mov BYTE PTR [edi+2], ah
    add edi, 3
    jmp DWORD PTR [draw_resume]
copy_3_cross LABEL NEAR
    mov eax, DWORD PTR [esi]
    add esi, 3
    mov BYTE PTR [edi], al
    shr eax, 8
    mov WORD PTR [edi+1], ax
    add edi, 3
    jmp DWORD PTR [draw_resume]
copy_4_0 LABEL NEAR
    mov eax, DWORD PTR [esi]
    add esi, 4
    mov DWORD PTR [edi], eax
    add edi, 4
    jmp DWORD PTR [draw_resume]
copy_4_1 LABEL NEAR
    mov eax, DWORD PTR [esi]
    add esi, 4
    mov WORD PTR [edi], ax
    shr eax, 16
    mov BYTE PTR [edi+2], al
    mov BYTE PTR [edi+3], ah
    add edi, 4
    jmp DWORD PTR [draw_resume]
copy_4_2 LABEL NEAR
    mov eax, DWORD PTR [esi]
    add esi, 4
    mov WORD PTR [edi], ax
    shr eax, 16
    mov WORD PTR [edi+2], ax
    add edi, 4
    jmp DWORD PTR [draw_resume]
copy_4_3 LABEL NEAR
    mov eax, DWORD PTR [esi]
    add esi, 4
    mov BYTE PTR [edi], al
    mov BYTE PTR [edi+1], ah
    shr eax, 16
    mov WORD PTR [edi+2], ax
    add edi, 4
    jmp DWORD PTR [draw_resume]
copy_5_0 LABEL NEAR
    mov eax, DWORD PTR [esi]
    mov bl, BYTE PTR [esi+4]
    mov DWORD PTR [edi], eax
    mov BYTE PTR [edi+4], bl
    add esi, 5
    add edi, 5
    jmp DWORD PTR [draw_resume]
copy_5_middle LABEL NEAR
    mov eax, DWORD PTR [esi]
    mov ebx, DWORD PTR [esi+3]
    mov WORD PTR [edi], ax
    shr eax, 16
    mov BYTE PTR [edi+2], al
    add esi, 5
    mov WORD PTR [edi+3], bx
    add edi, 5
    jmp DWORD PTR [draw_resume]
copy_5_3 LABEL NEAR
    mov bl, BYTE PTR [esi]
    mov eax, DWORD PTR [esi+1]
    mov BYTE PTR [edi], bl
    mov DWORD PTR [edi+1], eax
    add esi, 5
    add edi, 5
    jmp DWORD PTR [draw_resume]
copy_6_0 LABEL NEAR
    mov eax, DWORD PTR [esi]
    mov ebx, DWORD PTR [esi+4]
    mov DWORD PTR [edi], eax
    add esi, 6
    mov WORD PTR [edi+4], bx
    add edi, 6
    jmp DWORD PTR [draw_resume]
copy_6_1 LABEL NEAR
    mov eax, DWORD PTR [esi]
    mov ebx, DWORD PTR [esi+4]
    mov WORD PTR [edi], ax
    shr eax, 16
    mov BYTE PTR [edi+2], al
    add esi, 6
    mov WORD PTR [edi+4], bx
    mov BYTE PTR [edi+3], ah
    add edi, 6
    jmp DWORD PTR [draw_resume]
copy_6_2 LABEL NEAR
    mov eax, DWORD PTR [esi]
    mov ebx, DWORD PTR [esi+2]
    mov WORD PTR [edi], ax
    add esi, 6
    mov DWORD PTR [edi+2], ebx
    add edi, 6
    jmp DWORD PTR [draw_resume]
copy_6_3 LABEL NEAR
    mov bl, BYTE PTR [esi]
    mov eax, DWORD PTR [esi+1]
    mov bh, BYTE PTR [esi+5]
    mov BYTE PTR [edi], bl
    mov DWORD PTR [edi+1], eax
    add esi, 6
    mov BYTE PTR [edi+5], bh
    add edi, 6
    jmp DWORD PTR [draw_resume]
copy_7_0 LABEL NEAR
    mov eax, DWORD PTR [esi]
    mov ebx, DWORD PTR [esi+4]
    mov DWORD PTR [edi], eax
    mov WORD PTR [edi+4], bx
    shr ebx, 16
    add esi, 7
    mov BYTE PTR [edi+6], bl
    add edi, 7
    jmp DWORD PTR [draw_resume]
copy_7_1 LABEL NEAR
    mov eax, DWORD PTR [esi-1]
    mov ebx, DWORD PTR [esi+3]
    mov BYTE PTR [edi], ah
    shr eax, 16
    add esi, 7
    mov WORD PTR [edi+1], ax
    mov DWORD PTR [edi+3], ebx
    add edi, 7
    jmp DWORD PTR [draw_resume]
copy_7_2 LABEL NEAR
    mov eax, DWORD PTR [esi+2]
    mov DWORD PTR [edi+2], eax
    mov eax, DWORD PTR [esi]
    mov WORD PTR [edi], ax
    mov bl, BYTE PTR [esi+6]
    add esi, 7
    mov BYTE PTR [edi+6], bl
    add edi, 7
    jmp DWORD PTR [draw_resume]
copy_7_3 LABEL NEAR
    mov eax, DWORD PTR [esi+1]
    mov DWORD PTR [edi+1], eax
    mov bl, BYTE PTR [esi]
    mov BYTE PTR [edi], bl
    mov eax, DWORD PTR [esi+5]
    add esi, 7
    mov WORD PTR [edi+5], ax
    add edi, 7
    jmp DWORD PTR [draw_resume]

; Long copies use byte stores for the three-byte prefix and suffix.
COPY_PART MACRO count
    IF count EQ 1
        mov al, BYTE PTR [esi]
        inc esi
        mov BYTE PTR [edi], al
        inc edi
    ELSEIF count EQ 2
        mov eax, DWORD PTR [esi]
        add esi, 2
        mov WORD PTR [edi], ax
        add edi, 2
    ELSEIF count EQ 3
        mov eax, DWORD PTR [esi]
        add esi, 3
        mov BYTE PTR [edi], al
        mov BYTE PTR [edi+1], ah
        shr eax, 16
        mov BYTE PTR [edi+2], al
        add edi, 3
    ELSEIF count EQ 4
        mov eax, DWORD PTR [esi]
        add esi, 4
        mov DWORD PTR [edi], eax
        add edi, 4
    ENDIF
ENDM

LONG_COPY MACRO head, tail
LOCAL copy_loop
copy_long_&head&_&tail LABEL NEAR
    COPY_PART head
    IF (head+tail) EQ 1
        dec ecx
    ELSEIF (head+tail) GT 1
        sub ecx, head+tail
    ENDIF
copy_loop:
    COPY_PART 4
    sub ecx, 4
    ja copy_loop
    COPY_PART tail
    jmp DWORD PTR [draw_resume]
ENDM

LONG_COPY 0, 0
LONG_COPY 1, 0
LONG_COPY 2, 0
LONG_COPY 3, 0
LONG_COPY 0, 1
LONG_COPY 1, 1
LONG_COPY 2, 1
LONG_COPY 3, 1
LONG_COPY 0, 2
LONG_COPY 1, 2
LONG_COPY 2, 2
LONG_COPY 3, 2
LONG_COPY 0, 3
LONG_COPY 1, 3
LONG_COPY 2, 3
LONG_COPY 3, 3

; Patterned fills select AL or AH for the initial destination parity.
; DWORD stores retain all four input bytes; short stores use the low word.
SHORT_FILL pattern_1_even, 1, 0, 0
SHORT_FILL pattern_1_odd, 1, 0, 0, 1
SHORT_FILL pattern_2_even, 2, 0, 0
SHORT_FILL pattern_2_odd, 2, 0, 0, 1
SHORT_FILL pattern_3_0, 3, 0, 0
SHORT_FILL pattern_3_1, 3, 0, 0, 1
SHORT_FILL pattern_3_2, 2, 1, 0
SHORT_FILL pattern_3_3, 1, 2, 0, 1
SHORT_FILL pattern_4_0, 4, 0, 0
SHORT_FILL pattern_4_1, 3, 1, 0, 1
SHORT_FILL pattern_4_2, 2, 2, 0
SHORT_FILL pattern_4_3, 1, 3, 0, 1
SHORT_FILL pattern_5_0, 4, 1, 0
SHORT_FILL pattern_5_1, 3, 2, 0, 1
SHORT_FILL pattern_5_2, 2, 3, 0
SHORT_FILL pattern_5_3, 1, 4, 0, 1
SHORT_FILL pattern_6_0, 4, 2, 0
SHORT_FILL pattern_6_1, 3, 3, 0, 1
SHORT_FILL pattern_6_2, 2, 4, 0
SHORT_FILL pattern_6_3, 1, 4, 1, 1
SHORT_FILL pattern_7_0, 4, 3, 0
SHORT_FILL pattern_7_1, 3, 4, 0, 1
SHORT_FILL pattern_7_2, 2, 4, 1
SHORT_FILL pattern_7_3, 1, 4, 2, 1
LONG_FILL 0, 0, 1
LONG_FILL 1, 0, 1
LONG_FILL 2, 0, 1
LONG_FILL 3, 0, 1
LONG_FILL 0, 1, 1
LONG_FILL 1, 1, 1
LONG_FILL 2, 1, 1
LONG_FILL 3, 1, 1
LONG_FILL 0, 2, 1
LONG_FILL 1, 2, 1
LONG_FILL 2, 2, 1
LONG_FILL 3, 2, 1
LONG_FILL 0, 3, 1
LONG_FILL 1, 3, 1
LONG_FILL 2, 3, 1
LONG_FILL 3, 3, 1
END
