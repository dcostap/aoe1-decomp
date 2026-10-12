; Asm_draw: the hand-written sprite and span drawing engine (Asm_draw.obj).
;
; Entry points set up the drawing state in THIS_DAT, then jump into per-length
; codelets through the dispatch tables. Each codelet draws one span piece and
; returns through draw_resume. Labels L56xxxx keep the original address of
; branch targets that have no recovered name yet.
;
; This source assembles to the original THIS_COD and THIS_DAT bytes with every
; address field relocated to the same target; tests/test_drawing_engine.py checks
; that against orig/empiresx.exe.
.586
.MMX
.model flat
option casemap:none

PUBLIC _ASMSet_Shadowing
PUBLIC _ASMSet_ShadowingEx
PUBLIC _ASMSet_Surface_Info
PUBLIC _ASMSet_Color_Xform
PUBLIC _ASMGet_Color_Xform
PUBLIC _ASMSet_Xlate_Table
PUBLIC _ASMGet_Xlate_Table
PUBLIC _ASMDraw_HLine
PUBLIC _ASMDraw_Sprite

THIS_DAT SEGMENT PARA PUBLIC 'DATA'
surface_offsets          DWORD 0
span_heads               DWORD 0
span_tails               DWORD 0
state_88C00C             DWORD 0
state_88C010             DWORD 0
draw_pixel_ptr           DWORD 0
state_88C018             DWORD 0
xlate_table              DWORD 0
draw_row_base            DWORD 0
state_88C024             DWORD 0
state_88C028             DWORD 0
state_88C02C             DWORD 0
state_88C030             DWORD 0
state_88C034             DWORD 0
draw_length              DWORD 0
draw_span                DWORD 0
color_xform              DWORD 0
draw_resume              DWORD 0
state_88C048             DWORD 0
draw_clip_skip           DWORD 0
state_88C050             DWORD 0
state_88C054             DWORD 0
state_88C058             DWORD 0
state_88C05C             DWORD 0
shadow_mask              DWORD 0
state_88C064             DWORD 0
state_88C068             DWORD 0
state_88C06C             DWORD 0
shadow_value             DWORD 0
state_88C074             DWORD 0
state_88C078             DWORD 0
state_88C07C             DWORD 0
min_line                 DWORD 0
max_line                 DWORD 0
min_span                 DWORD 0
max_span                 DWORD 0
THIS_DAT ENDS

THIS_COD SEGMENT PARA PUBLIC 'CODE'

; The original assembler filled code alignment with 3-byte cs-prefixed
; "mov eax, eax" no-ops, then one "mov eax, eax" or "nop" for the remainder.
; Each use states the ALIGN it reproduces and the byte count it inserted.
CODE_FILL MACRO count
    REPEAT count / 3
        BYTE 2Eh
        mov eax, eax
    ENDM
    IF count MOD 3 EQ 2
        mov eax, eax
    ELSEIF count MOD 3 EQ 1
        nop
    ENDIF
ENDM

; Shared exit: resume the caller through the saved continuation.
draw_done:
    jmp dword ptr ds:[draw_resume]
copy_1:
    mov al,byte ptr [esi]
    inc esi
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
copy_2:
    mov eax,dword ptr [esi]
    add esi,2
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
copy_2_cross:
    mov eax,dword ptr [esi]
    add esi,2
    mov byte ptr [edi],al
    mov byte ptr [edi+1],ah
    add edi,2
    jmp dword ptr ds:[draw_resume]
copy_3:
    mov eax,dword ptr [esi]
    add esi,3
    mov word ptr [edi],ax
    shr eax,8
    mov byte ptr [edi+2],ah
    add edi,3
    jmp dword ptr ds:[draw_resume]
copy_3_cross:
    mov eax,dword ptr [esi]
    add esi,3
    mov byte ptr [edi],al
    shr eax,8
    mov word ptr [edi+1],ax
    add edi,3
    jmp dword ptr ds:[draw_resume]
copy_4_0:
    mov eax,dword ptr [esi]
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    jmp dword ptr ds:[draw_resume]
copy_4_1:
    mov eax,dword ptr [esi]
    add esi,4
    mov word ptr [edi],ax
    shr eax,10h
    mov byte ptr [edi+2],al
    mov byte ptr [edi+3],ah
    add edi,4
    jmp dword ptr ds:[draw_resume]
copy_4_2:
    mov eax,dword ptr [esi]
    add esi,4
    mov word ptr [edi],ax
    shr eax,10h
    mov word ptr [edi+2],ax
    add edi,4
    jmp dword ptr ds:[draw_resume]
copy_4_3:
    mov eax,dword ptr [esi]
    add esi,4
    mov byte ptr [edi],al
    mov byte ptr [edi+1],ah
    shr eax,10h
    mov word ptr [edi+2],ax
    add edi,4
    jmp dword ptr ds:[draw_resume]
copy_5_0:
    mov eax,dword ptr [esi]
    mov bl,byte ptr [esi+4]
    mov dword ptr [edi],eax
    mov byte ptr [edi+4],bl
    add esi,5
    add edi,5
    jmp dword ptr ds:[draw_resume]
copy_5_middle:
    mov eax,dword ptr [esi]
    mov ebx,dword ptr [esi+3]
    mov word ptr [edi],ax
    shr eax,10h
    mov byte ptr [edi+2],al
    add esi,5
    mov word ptr [edi+3],bx
    add edi,5
    jmp dword ptr ds:[draw_resume]
copy_5_3:
    mov bl,byte ptr [esi]
    mov eax,dword ptr [esi+1]
    mov byte ptr [edi],bl
    mov dword ptr [edi+1],eax
    add esi,5
    add edi,5
    jmp dword ptr ds:[draw_resume]
copy_6_0:
    mov eax,dword ptr [esi]
    mov ebx,dword ptr [esi+4]
    mov dword ptr [edi],eax
    add esi,6
    mov word ptr [edi+4],bx
    add edi,6
    jmp dword ptr ds:[draw_resume]
copy_6_1:
    mov eax,dword ptr [esi]
    mov ebx,dword ptr [esi+4]
    mov word ptr [edi],ax
    shr eax,10h
    mov byte ptr [edi+2],al
    add esi,6
    mov word ptr [edi+4],bx
    mov byte ptr [edi+3],ah
    add edi,6
    jmp dword ptr ds:[draw_resume]
copy_6_2:
    mov eax,dword ptr [esi]
    mov ebx,dword ptr [esi+2]
    mov word ptr [edi],ax
    add esi,6
    mov dword ptr [edi+2],ebx
    add edi,6
    jmp dword ptr ds:[draw_resume]
copy_6_3:
    mov bl,byte ptr [esi]
    mov eax,dword ptr [esi+1]
    mov bh,byte ptr [esi+5]
    mov byte ptr [edi],bl
    mov dword ptr [edi+1],eax
    add esi,6
    mov byte ptr [edi+5],bh
    add edi,6
    jmp dword ptr ds:[draw_resume]
copy_7_0:
    mov eax,dword ptr [esi]
    mov ebx,dword ptr [esi+4]
    mov dword ptr [edi],eax
    mov word ptr [edi+4],bx
    shr ebx,10h
    add esi,7
    mov byte ptr [edi+6],bl
    add edi,7
    jmp dword ptr ds:[draw_resume]
copy_7_1:
    mov eax,dword ptr [esi-1]
    mov ebx,dword ptr [esi+3]
    mov byte ptr [edi],ah
    shr eax,10h
    add esi,7
    mov word ptr [edi+1],ax
    mov dword ptr [edi+3],ebx
    add edi,7
    jmp dword ptr ds:[draw_resume]
copy_7_2:
    mov eax,dword ptr [esi+2]
    mov dword ptr [edi+2],eax
    mov eax,dword ptr [esi]
    mov word ptr [edi],ax
    mov bl,byte ptr [esi+6]
    add esi,7
    mov byte ptr [edi+6],bl
    add edi,7
    jmp dword ptr ds:[draw_resume]
copy_7_3:
    mov eax,dword ptr [esi+1]
    mov dword ptr [edi+1],eax
    mov bl,byte ptr [esi]
    mov byte ptr [edi],bl
    mov eax,dword ptr [esi+5]
    add esi,7
    mov word ptr [edi+5],ax
    add edi,7
    jmp dword ptr ds:[draw_resume]
copy_long_0_0:
    mov eax,dword ptr [esi]
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT copy_long_0_0
    jmp dword ptr ds:[draw_resume]
copy_long_1_0:
    mov al,byte ptr [esi]
    inc esi
    mov byte ptr [edi],al
    inc edi
    dec ecx
L563206:
    mov eax,dword ptr [esi]
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L563206
    jmp dword ptr ds:[draw_resume]
copy_long_2_0:
    mov eax,dword ptr [esi]
    add esi,2
    mov word ptr [edi],ax
    add edi,2
    sub ecx,2
L563229:
    mov eax,dword ptr [esi]
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L563229
    jmp dword ptr ds:[draw_resume]
copy_long_3_0:
    mov eax,dword ptr [esi]
    add esi,3
    mov byte ptr [edi],al
    mov byte ptr [edi+1],ah
    shr eax,10h
    mov byte ptr [edi+2],al
    add edi,3
    sub ecx,3
L563254:
    mov eax,dword ptr [esi]
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L563254
    jmp dword ptr ds:[draw_resume]
copy_long_0_1:
    dec ecx
L56326A:
    mov eax,dword ptr [esi]
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L56326A
    mov al,byte ptr [esi]
    inc esi
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
copy_long_1_1:
    mov al,byte ptr [esi]
    inc esi
    mov byte ptr [edi],al
    inc edi
    sub ecx,2
L56328E:
    mov eax,dword ptr [esi]
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L56328E
    mov al,byte ptr [esi]
    inc esi
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
copy_long_2_1:
    mov eax,dword ptr [esi]
    add esi,2
    mov word ptr [edi],ax
    add edi,2
    sub ecx,3
L5632B7:
    mov eax,dword ptr [esi]
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L5632B7
    mov al,byte ptr [esi]
    inc esi
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
copy_long_3_1:
    mov eax,dword ptr [esi]
    add esi,3
    mov byte ptr [edi],al
    mov byte ptr [edi+1],ah
    shr eax,10h
    mov byte ptr [edi+2],al
    add edi,3
    sub ecx,4
L5632E8:
    mov eax,dword ptr [esi]
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L5632E8
    mov al,byte ptr [esi]
    inc esi
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
copy_long_0_2:
    sub ecx,2
L563306:
    mov eax,dword ptr [esi]
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L563306
    mov eax,dword ptr [esi]
    add esi,2
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
copy_long_1_2:
    mov al,byte ptr [esi]
    inc esi
    mov byte ptr [edi],al
    inc edi
    sub ecx,3
L56332F:
    mov eax,dword ptr [esi]
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L56332F
    mov eax,dword ptr [esi]
    add esi,2
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
copy_long_2_2:
    mov eax,dword ptr [esi]
    add esi,2
    mov word ptr [edi],ax
    add edi,2
    sub ecx,4
L56335D:
    mov eax,dword ptr [esi]
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L56335D
    mov eax,dword ptr [esi]
    add esi,2
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
copy_long_3_2:
    mov eax,dword ptr [esi]
    add esi,3
    mov byte ptr [edi],al
    mov byte ptr [edi+1],ah
    shr eax,10h
    mov byte ptr [edi+2],al
    add edi,3
    sub ecx,5
L563393:
    mov eax,dword ptr [esi]
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L563393
    mov eax,dword ptr [esi]
    add esi,2
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
copy_long_0_3:
    sub ecx,3
L5633B6:
    mov eax,dword ptr [esi]
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L5633B6
    mov eax,dword ptr [esi]
    add esi,3
    mov byte ptr [edi],al
    mov byte ptr [edi+1],ah
    shr eax,10h
    mov byte ptr [edi+2],al
    add edi,3
    jmp dword ptr ds:[draw_resume]
copy_long_1_3:
    mov al,byte ptr [esi]
    inc esi
    mov byte ptr [edi],al
    inc edi
    sub ecx,4
L5633E7:
    mov eax,dword ptr [esi]
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L5633E7
    mov eax,dword ptr [esi]
    add esi,3
    mov byte ptr [edi],al
    mov byte ptr [edi+1],ah
    shr eax,10h
    mov byte ptr [edi+2],al
    add edi,3
    jmp dword ptr ds:[draw_resume]
copy_long_2_3:
    mov eax,dword ptr [esi]
    add esi,2
    mov word ptr [edi],ax
    add edi,2
    sub ecx,5
L56341D:
    mov eax,dword ptr [esi]
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L56341D
    mov eax,dword ptr [esi]
    add esi,3
    mov byte ptr [edi],al
    mov byte ptr [edi+1],ah
    shr eax,10h
    mov byte ptr [edi+2],al
    add edi,3
    jmp dword ptr ds:[draw_resume]
copy_long_3_3:
    mov eax,dword ptr [esi]
    add esi,3
    mov byte ptr [edi],al
    mov byte ptr [edi+1],ah
    shr eax,10h
    mov byte ptr [edi+2],al
    add edi,3
    sub ecx,6
L56345B:
    mov eax,dword ptr [esi]
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L56345B
    mov eax,dword ptr [esi]
    add esi,3
    mov byte ptr [edi],al
    mov byte ptr [edi+1],ah
    shr eax,10h
    mov byte ptr [edi+2],al
    add edi,3
    jmp dword ptr ds:[draw_resume]
L563483:
    mov al,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],al
    inc esi
    inc edi
    jmp dword ptr ds:[draw_resume]
L56349B:
    mov ah,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    inc esi
    inc edi
    jmp dword ptr ds:[draw_resume]
L5634B3:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi],ax
    add esi,2
    add edi,2
    jmp dword ptr ds:[draw_resume]
L5634D0:
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    shr eax,8
    mov word ptr [edi],ax
    add esi,2
    add edi,2
    jmp dword ptr ds:[draw_resume]
L5634F1:
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    shr eax,8
    add esi,2
    mov byte ptr [edi],al
    mov byte ptr [edi+1],ah
    add edi,2
    jmp dword ptr ds:[draw_resume]
L563514:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi],ax
    shr eax,10h
    mov byte ptr [edi+2],al
    add esi,3
    add edi,3
    jmp dword ptr ds:[draw_resume]
L563537:
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,3
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    shr eax,10h
    mov word ptr [edi+1],ax
    add edi,3
    jmp dword ptr ds:[draw_resume]
L56355B:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi],ax
    add esi,2
    add edi,2
    mov al,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],al
    inc esi
    inc edi
    jmp dword ptr ds:[draw_resume]
L56358A:
    mov ah,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    inc esi
    inc edi
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi],ax
    add esi,2
    add edi,2
    jmp dword ptr ds:[draw_resume]
L5635B9:
    mov eax,dword ptr [esi]
    add edi,4
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-4],eax
    jmp dword ptr ds:[draw_resume]
L5635D6:
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,3
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    shr eax,10h
    mov word ptr [edi+1],ax
    add edi,3
    mov al,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],al
    inc esi
    inc edi
    jmp dword ptr ds:[draw_resume]
L56360C:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi],ax
    add esi,2
    add edi,2
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi],ax
    add esi,2
    add edi,2
    jmp dword ptr ds:[draw_resume]
L563640:
    mov ah,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    inc esi
    inc edi
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi],ax
    shr eax,10h
    mov byte ptr [edi+2],al
    add esi,3
    add edi,3
    jmp dword ptr ds:[draw_resume]
L563675:
    mov eax,dword ptr [esi]
    add edi,4
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-4],eax
    mov al,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],al
    inc esi
    inc edi
    jmp dword ptr ds:[draw_resume]
L5636A4:
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,3
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    shr eax,10h
    mov word ptr [edi+1],ax
    add edi,3
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi],ax
    add esi,2
    add edi,2
    jmp dword ptr ds:[draw_resume]
L5636DF:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi],ax
    add esi,2
    add edi,2
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi],ax
    shr eax,10h
    mov byte ptr [edi+2],al
    add esi,3
    add edi,3
    jmp dword ptr ds:[draw_resume]
L563719:
    mov ah,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    inc esi
    inc edi
    mov eax,dword ptr [esi]
    add edi,4
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-4],eax
    jmp dword ptr ds:[draw_resume]
L563748:
    mov eax,dword ptr [esi]
    add edi,4
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-4],eax
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi],ax
    add esi,2
    add edi,2
    jmp dword ptr ds:[draw_resume]
L56377C:
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,3
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    shr eax,10h
    mov word ptr [edi+1],ax
    add edi,3
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi],ax
    shr eax,10h
    mov byte ptr [edi+2],al
    add esi,3
    add edi,3
    jmp dword ptr ds:[draw_resume]
L5637BD:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi],ax
    add esi,2
    add edi,2
    mov eax,dword ptr [esi]
    add edi,4
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-4],eax
    jmp dword ptr ds:[draw_resume]
L5637F1:
    mov ah,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    inc esi
    inc edi
    mov eax,dword ptr [esi]
    add edi,4
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-4],eax
    mov al,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],al
    inc esi
    inc edi
    jmp dword ptr ds:[draw_resume]
L563832:
    mov eax,dword ptr [esi]
    add edi,4
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-4],eax
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi],ax
    shr eax,10h
    mov byte ptr [edi+2],al
    add esi,3
    add edi,3
    jmp dword ptr ds:[draw_resume]
L56386C:
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,3
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    shr eax,10h
    mov word ptr [edi+1],ax
    add edi,3
    mov eax,dword ptr [esi]
    add edi,4
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-4],eax
    jmp dword ptr ds:[draw_resume]
L5638A7:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi],ax
    add esi,2
    add edi,2
    mov eax,dword ptr [esi]
    add edi,4
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-4],eax
    mov al,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],al
    inc esi
    inc edi
    jmp dword ptr ds:[draw_resume]
L5638ED:
    mov ah,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    inc esi
    inc edi
    mov eax,dword ptr [esi]
    add edi,4
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-4],eax
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi],ax
    add esi,2
    add edi,2
    jmp dword ptr ds:[draw_resume]
L563933:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L563933
    jmp dword ptr ds:[draw_resume]
L563954:
    mov ah,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    inc esi
    inc edi
    dec ecx
L563967:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L563967
    jmp dword ptr ds:[draw_resume]
L563988:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi],ax
    add esi,2
    add edi,2
    sub ecx,2
L5639A2:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L5639A2
    jmp dword ptr ds:[draw_resume]
L5639C3:
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,3
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    shr eax,10h
    mov word ptr [edi+1],ax
    add edi,3
    sub ecx,3
L5639E4:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L5639E4
    jmp dword ptr ds:[draw_resume]
L563A05:
    dec ecx
L563A06:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L563A06
    mov al,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],al
    inc esi
    inc edi
    jmp dword ptr ds:[draw_resume]
L563A39:
    mov ah,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    inc esi
    inc edi
    sub ecx,2
L563A4E:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L563A4E
    mov al,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],al
    inc esi
    inc edi
    jmp dword ptr ds:[draw_resume]
L563A81:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi],ax
    add esi,2
    add edi,2
    sub ecx,3
L563A9B:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L563A9B
    mov al,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],al
    inc esi
    inc edi
    jmp dword ptr ds:[draw_resume]
L563ACE:
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,3
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    shr eax,10h
    mov word ptr [edi+1],ax
    add edi,3
    sub ecx,4
L563AEF:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L563AEF
    mov al,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],al
    inc esi
    inc edi
    jmp dword ptr ds:[draw_resume]
L563B22:
    sub ecx,2
L563B25:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L563B25
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi],ax
    add esi,2
    add edi,2
    jmp dword ptr ds:[draw_resume]
L563B5D:
    mov ah,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    inc esi
    inc edi
    sub ecx,3
L563B72:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L563B72
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi],ax
    add esi,2
    add edi,2
    jmp dword ptr ds:[draw_resume]
L563BAA:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi],ax
    add esi,2
    add edi,2
    sub ecx,4
L563BC4:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L563BC4
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi],ax
    add esi,2
    add edi,2
    jmp dword ptr ds:[draw_resume]
L563BFC:
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,3
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    shr eax,10h
    mov word ptr [edi+1],ax
    add edi,3
    sub ecx,5
L563C1D:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L563C1D
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi],ax
    add esi,2
    add edi,2
    jmp dword ptr ds:[draw_resume]
L563C55:
    sub ecx,3
L563C58:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L563C58
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi],ax
    shr eax,10h
    mov byte ptr [edi+2],al
    add esi,3
    add edi,3
    jmp dword ptr ds:[draw_resume]
L563C96:
    mov ah,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    inc esi
    inc edi
    sub ecx,4
L563CAB:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L563CAB
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi],ax
    shr eax,10h
    mov byte ptr [edi+2],al
    add esi,3
    add edi,3
    jmp dword ptr ds:[draw_resume]
L563CE9:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi],ax
    add esi,2
    add edi,2
    sub ecx,5
L563D03:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L563D03
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi],ax
    shr eax,10h
    mov byte ptr [edi+2],al
    add esi,3
    add edi,3
    jmp dword ptr ds:[draw_resume]
L563D41:
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,3
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    shr eax,10h
    mov word ptr [edi+1],ax
    add edi,3
    sub ecx,6
L563D62:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L563D62
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi],ax
    shr eax,10h
    mov byte ptr [edi+2],al
    add esi,3
    add edi,3
    jmp dword ptr ds:[draw_resume]
solid_1:
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
solid_2:
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
solid_2_cross:
    mov byte ptr [edi],al
    inc edi
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
solid_3:
    mov word ptr [edi],ax
    mov byte ptr [edi+2],al
    add edi,3
    jmp dword ptr ds:[draw_resume]
solid_3_cross:
    mov byte ptr [edi],al
    inc edi
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
solid_4_0:
    mov dword ptr [edi],eax
    add edi,4
    jmp dword ptr ds:[draw_resume]
solid_4_1:
    mov word ptr [edi],ax
    mov byte ptr [edi+2],al
    add edi,3
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
solid_4_2:
    mov word ptr [edi],ax
    add edi,2
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
solid_4_3:
    mov byte ptr [edi],al
    inc edi
    mov word ptr [edi],ax
    mov byte ptr [edi+2],al
    add edi,3
    jmp dword ptr ds:[draw_resume]
solid_5_0:
    mov dword ptr [edi],eax
    add edi,4
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
solid_5_1:
    mov word ptr [edi],ax
    mov byte ptr [edi+2],al
    add edi,3
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
solid_5_2:
    mov word ptr [edi],ax
    add edi,2
    mov word ptr [edi],ax
    mov byte ptr [edi+2],al
    add edi,3
    jmp dword ptr ds:[draw_resume]
solid_5_3:
    mov byte ptr [edi],al
    inc edi
    mov dword ptr [edi],eax
    add edi,4
    jmp dword ptr ds:[draw_resume]
solid_6_0:
    mov dword ptr [edi],eax
    add edi,4
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
solid_6_1:
    mov word ptr [edi],ax
    mov byte ptr [edi+2],al
    add edi,3
    mov word ptr [edi],ax
    mov byte ptr [edi+2],al
    add edi,3
    jmp dword ptr ds:[draw_resume]
solid_6_2:
    mov word ptr [edi],ax
    add edi,2
    mov dword ptr [edi],eax
    add edi,4
    jmp dword ptr ds:[draw_resume]
solid_6_3:
    mov byte ptr [edi],al
    inc edi
    mov dword ptr [edi],eax
    add edi,4
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
solid_7_0:
    mov dword ptr [edi],eax
    add edi,4
    mov word ptr [edi],ax
    mov byte ptr [edi+2],al
    add edi,3
    jmp dword ptr ds:[draw_resume]
solid_7_1:
    mov word ptr [edi],ax
    mov byte ptr [edi+2],al
    add edi,3
    mov dword ptr [edi],eax
    add edi,4
    jmp dword ptr ds:[draw_resume]
solid_7_2:
    mov word ptr [edi],ax
    add edi,2
    mov dword ptr [edi],eax
    add edi,4
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
solid_7_3:
    mov byte ptr [edi],al
    inc edi
    mov dword ptr [edi],eax
    add edi,4
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
solid_long_0_0:
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT solid_long_0_0
    jmp dword ptr ds:[draw_resume]
solid_long_1_0:
    mov byte ptr [edi],al
    inc edi
    dec ecx
L563F15:
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L563F15
    jmp dword ptr ds:[draw_resume]
solid_long_2_0:
    mov word ptr [edi],ax
    add edi,2
    sub ecx,2
L563F2E:
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L563F2E
    jmp dword ptr ds:[draw_resume]
solid_long_3_0:
    mov word ptr [edi],ax
    mov byte ptr [edi+2],al
    add edi,3
    sub ecx,3
L563F4A:
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L563F4A
    jmp dword ptr ds:[draw_resume]
solid_long_0_1:
    dec ecx
L563F5B:
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L563F5B
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
solid_long_1_1:
    mov byte ptr [edi],al
    inc edi
    sub ecx,2
L563F74:
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L563F74
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
solid_long_2_1:
    mov word ptr [edi],ax
    add edi,2
    sub ecx,3
L563F90:
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L563F90
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
solid_long_3_1:
    mov word ptr [edi],ax
    mov byte ptr [edi+2],al
    add edi,3
    sub ecx,4
L563FAF:
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L563FAF
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
solid_long_0_2:
    sub ecx,2
L563FC5:
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L563FC5
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
solid_long_1_2:
    mov byte ptr [edi],al
    inc edi
    sub ecx,3
L563FE1:
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L563FE1
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
solid_long_2_2:
    mov word ptr [edi],ax
    add edi,2
    sub ecx,4
L564000:
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L564000
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
solid_long_3_2:
    mov word ptr [edi],ax
    mov byte ptr [edi+2],al
    add edi,3
    sub ecx,5
L564022:
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L564022
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
solid_long_0_3:
    sub ecx,3
L56403B:
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L56403B
    mov word ptr [edi],ax
    mov byte ptr [edi+2],al
    add edi,3
    jmp dword ptr ds:[draw_resume]
solid_long_1_3:
    mov byte ptr [edi],al
    inc edi
    sub ecx,4
L56405A:
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L56405A
    mov word ptr [edi],ax
    mov byte ptr [edi+2],al
    add edi,3
    jmp dword ptr ds:[draw_resume]
solid_long_2_3:
    mov word ptr [edi],ax
    add edi,2
    sub ecx,5
L56407C:
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L56407C
    mov word ptr [edi],ax
    mov byte ptr [edi+2],al
    add edi,3
    jmp dword ptr ds:[draw_resume]
solid_long_3_3:
    mov word ptr [edi],ax
    mov byte ptr [edi+2],al
    add edi,3
    sub ecx,6
L5640A1:
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L5640A1
    mov word ptr [edi],ax
    mov byte ptr [edi+2],al
    add edi,3
    jmp dword ptr ds:[draw_resume]
pattern_1_even:
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
pattern_1_odd:
    mov byte ptr [edi],ah
    inc edi
    jmp dword ptr ds:[draw_resume]
pattern_2_even:
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
pattern_2_odd:
    mov byte ptr [edi],ah
    mov byte ptr [edi+1],al
    add edi,2
    jmp dword ptr ds:[draw_resume]
pattern_3_0:
    mov word ptr [edi],ax
    mov byte ptr [edi+2],al
    add edi,3
    jmp dword ptr ds:[draw_resume]
pattern_3_1:
    mov byte ptr [edi],ah
    mov word ptr [edi+1],ax
    add edi,3
    jmp dword ptr ds:[draw_resume]
pattern_3_2:
    mov word ptr [edi],ax
    add edi,2
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
pattern_3_3:
    mov byte ptr [edi],ah
    inc edi
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
pattern_4_0:
    mov dword ptr [edi],eax
    add edi,4
    jmp dword ptr ds:[draw_resume]
pattern_4_1:
    mov byte ptr [edi],ah
    mov word ptr [edi+1],ax
    add edi,3
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
pattern_4_2:
    mov word ptr [edi],ax
    add edi,2
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
pattern_4_3:
    mov byte ptr [edi],ah
    inc edi
    mov word ptr [edi],ax
    mov byte ptr [edi+2],al
    add edi,3
    jmp dword ptr ds:[draw_resume]
pattern_5_0:
    mov dword ptr [edi],eax
    add edi,4
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
pattern_5_1:
    mov byte ptr [edi],ah
    mov word ptr [edi+1],ax
    add edi,3
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
pattern_5_2:
    mov word ptr [edi],ax
    add edi,2
    mov word ptr [edi],ax
    mov byte ptr [edi+2],al
    add edi,3
    jmp dword ptr ds:[draw_resume]
pattern_5_3:
    mov byte ptr [edi],ah
    inc edi
    mov dword ptr [edi],eax
    add edi,4
    jmp dword ptr ds:[draw_resume]
pattern_6_0:
    mov dword ptr [edi],eax
    add edi,4
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
pattern_6_1:
    mov byte ptr [edi],ah
    mov word ptr [edi+1],ax
    add edi,3
    mov word ptr [edi],ax
    mov byte ptr [edi+2],al
    add edi,3
    jmp dword ptr ds:[draw_resume]
pattern_6_2:
    mov word ptr [edi],ax
    add edi,2
    mov dword ptr [edi],eax
    add edi,4
    jmp dword ptr ds:[draw_resume]
pattern_6_3:
    mov byte ptr [edi],ah
    inc edi
    mov dword ptr [edi],eax
    add edi,4
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
pattern_7_0:
    mov dword ptr [edi],eax
    add edi,4
    mov word ptr [edi],ax
    mov byte ptr [edi+2],al
    add edi,3
    jmp dword ptr ds:[draw_resume]
pattern_7_1:
    mov byte ptr [edi],ah
    mov word ptr [edi+1],ax
    add edi,3
    mov dword ptr [edi],eax
    add edi,4
    jmp dword ptr ds:[draw_resume]
pattern_7_2:
    mov word ptr [edi],ax
    add edi,2
    mov dword ptr [edi],eax
    add edi,4
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
pattern_7_3:
    mov byte ptr [edi],ah
    inc edi
    mov dword ptr [edi],eax
    add edi,4
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
pattern_long_0_0:
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT pattern_long_0_0
    jmp dword ptr ds:[draw_resume]
pattern_long_1_0:
    mov byte ptr [edi],ah
    inc edi
    dec ecx
L564258:
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L564258
    jmp dword ptr ds:[draw_resume]
pattern_long_2_0:
    mov word ptr [edi],ax
    add edi,2
    sub ecx,2
L564271:
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L564271
    jmp dword ptr ds:[draw_resume]
pattern_long_3_0:
    mov byte ptr [edi],ah
    mov word ptr [edi+1],ax
    add edi,3
    sub ecx,3
L56428D:
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L56428D
    jmp dword ptr ds:[draw_resume]
pattern_long_0_1:
    dec ecx
L56429E:
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L56429E
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
pattern_long_1_1:
    mov byte ptr [edi],ah
    inc edi
    sub ecx,2
L5642B7:
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L5642B7
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
pattern_long_2_1:
    mov word ptr [edi],ax
    add edi,2
    sub ecx,3
L5642D3:
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L5642D3
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
pattern_long_3_1:
    mov byte ptr [edi],ah
    mov word ptr [edi+1],ax
    add edi,3
    sub ecx,4
L5642F2:
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L5642F2
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
pattern_long_0_2:
    sub ecx,2
L564308:
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L564308
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
pattern_long_1_2:
    mov byte ptr [edi],ah
    inc edi
    sub ecx,3
L564324:
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L564324
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
pattern_long_2_2:
    mov word ptr [edi],ax
    add edi,2
    sub ecx,4
L564343:
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L564343
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
pattern_long_3_2:
    mov byte ptr [edi],ah
    mov word ptr [edi+1],ax
    add edi,3
    sub ecx,5
L564365:
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L564365
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
pattern_long_0_3:
    sub ecx,3
L56437E:
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L56437E
    mov word ptr [edi],ax
    mov byte ptr [edi+2],al
    add edi,3
    jmp dword ptr ds:[draw_resume]
pattern_long_1_3:
    mov byte ptr [edi],ah
    inc edi
    sub ecx,4
L56439D:
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L56439D
    mov word ptr [edi],ax
    mov byte ptr [edi+2],al
    add edi,3
    jmp dword ptr ds:[draw_resume]
pattern_long_2_3:
    mov word ptr [edi],ax
    add edi,2
    sub ecx,5
L5643BF:
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L5643BF
    mov word ptr [edi],ax
    mov byte ptr [edi+2],al
    add edi,3
    jmp dword ptr ds:[draw_resume]
pattern_long_3_3:
    mov byte ptr [edi],ah
    mov word ptr [edi+1],ax
    add edi,3
    sub ecx,6
L5643E4:
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L5643E4
    mov word ptr [edi],ax
    mov byte ptr [edi+2],al
    add edi,3
    jmp dword ptr ds:[draw_resume]
L5643FD:
    mov al,byte ptr [esi]
    inc esi
    or eax,ebx
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
L56440B:
    mov eax,dword ptr [esi]
    or eax,ebx
    add esi,2
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
L56441E:
    mov eax,dword ptr [esi]
    or eax,ebx
    add esi,2
    mov byte ptr [edi],al
    mov byte ptr [edi+1],ah
    add edi,2
    jmp dword ptr ds:[draw_resume]
L564433:
    mov eax,dword ptr [esi]
    or eax,ebx
    add esi,3
    mov word ptr [edi],ax
    shr eax,8
    mov byte ptr [edi+2],ah
    add edi,3
    jmp dword ptr ds:[draw_resume]
L56444C:
    mov eax,dword ptr [esi]
    or eax,ebx
    add esi,3
    mov byte ptr [edi],al
    shr eax,8
    mov word ptr [edi+1],ax
    add edi,3
    jmp dword ptr ds:[draw_resume]
L564465:
    mov eax,dword ptr [esi]
    or eax,ebx
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    jmp dword ptr ds:[draw_resume]
L564477:
    mov eax,dword ptr [esi]
    or eax,ebx
    add esi,4
    mov byte ptr [edi],al
    mov byte ptr [edi+1],ah
    shr eax,10h
    mov byte ptr [edi+2],al
    mov byte ptr [edi+3],ah
    add edi,4
    jmp dword ptr ds:[draw_resume]
L564495:
    mov eax,dword ptr [esi]
    mov dl,byte ptr [esi+4]
    or eax,ebx
    or edx,ebx
    mov dword ptr [edi],eax
    mov byte ptr [edi+4],dl
    add esi,5
    add edi,5
    jmp dword ptr ds:[draw_resume]
L5644AF:
    mov eax,dword ptr [esi]
    mov edx,dword ptr [esi+3]
    or eax,ebx
    or edx,ebx
    mov word ptr [edi],ax
    shr eax,10h
    mov byte ptr [edi+2],al
    add esi,5
    mov word ptr [edi+3],dx
    add edi,5
    jmp dword ptr ds:[draw_resume]
L5644D1:
    mov dl,byte ptr [esi]
    mov eax,dword ptr [esi+1]
    or eax,ebx
    or edx,ebx
    mov byte ptr [edi],dl
    mov dword ptr [edi+1],eax
    add esi,5
    add edi,5
    jmp dword ptr ds:[draw_resume]
L5644EB:
    mov eax,dword ptr [esi]
    mov edx,dword ptr [esi+4]
    or eax,ebx
    or edx,ebx
    mov dword ptr [edi],eax
    add esi,6
    mov word ptr [edi+4],dx
    add edi,6
    jmp dword ptr ds:[draw_resume]
L564506:
    mov eax,dword ptr [esi]
    mov edx,dword ptr [esi+4]
    or eax,ebx
    or edx,ebx
    mov word ptr [edi],ax
    shr eax,10h
    mov byte ptr [edi+2],al
    add esi,6
    mov byte ptr [edi+3],ah
    mov word ptr [edi+4],dx
    add edi,6
    jmp dword ptr ds:[draw_resume]
L56452B:
    mov eax,dword ptr [esi]
    mov edx,dword ptr [esi+2]
    or eax,ebx
    or edx,ebx
    mov word ptr [edi],ax
    add esi,6
    mov dword ptr [edi+2],edx
    add edi,6
    jmp dword ptr ds:[draw_resume]
L564546:
    mov dl,byte ptr [esi]
    mov eax,dword ptr [esi+1]
    mov dh,byte ptr [esi+5]
    or eax,ebx
    or edx,ebx
    mov byte ptr [edi],dl
    mov dword ptr [edi+1],eax
    add esi,6
    mov byte ptr [edi+5],dh
    add edi,6
    jmp dword ptr ds:[draw_resume]
L564566:
    mov eax,dword ptr [esi]
    mov edx,dword ptr [esi+4]
    or eax,ebx
    or edx,ebx
    mov dword ptr [edi],eax
    mov word ptr [edi+4],dx
    shr edx,10h
    add esi,7
    mov byte ptr [edi+6],dl
    add edi,7
    jmp dword ptr ds:[draw_resume]
L564587:
    mov eax,dword ptr [esi]
    mov edx,dword ptr [esi+3]
    or eax,ebx
    or edx,ebx
    mov word ptr [edi],ax
    shr eax,10h
    mov byte ptr [edi+2],al
    mov dword ptr [edi+3],edx
    add esi,7
    add edi,7
    jmp dword ptr ds:[draw_resume]
L5645A8:
    mov eax,dword ptr [esi+2]
    or eax,ebx
    mov dword ptr [edi+2],eax
    mov eax,dword ptr [esi]
    mov dl,byte ptr [esi+6]
    or eax,ebx
    or edx,ebx
    mov word ptr [edi],ax
    add esi,7
    mov byte ptr [edi+6],dl
    add edi,7
    jmp dword ptr ds:[draw_resume]
L5645CB:
    mov eax,dword ptr [esi+1]
    or eax,ebx
    mov dword ptr [edi+1],eax
    mov dl,byte ptr [esi]
    mov eax,dword ptr [esi+5]
    or edx,ebx
    or eax,ebx
    mov byte ptr [edi],dl
    add esi,7
    mov word ptr [edi+5],ax
    add edi,7
    jmp dword ptr ds:[draw_resume]
L5645EE:
    mov eax,dword ptr [esi]
    or eax,ebx
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L5645EE
    jmp dword ptr ds:[draw_resume]
L564605:
    mov al,byte ptr [esi]
    or eax,ebx
    mov byte ptr [edi],al
    inc esi
    inc edi
    dec ecx
L56460E:
    mov eax,dword ptr [esi]
    or eax,ebx
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L56460E
    jmp dword ptr ds:[draw_resume]
L564625:
    mov ax,word ptr [esi]
    or eax,ebx
    mov word ptr [edi],ax
    add esi,2
    add edi,2
    sub ecx,2
L564636:
    mov eax,dword ptr [esi]
    or eax,ebx
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L564636
    jmp dword ptr ds:[draw_resume]
L56464D:
    mov eax,dword ptr [esi]
    or eax,ebx
    mov word ptr [edi],ax
    shr eax,10h
    mov byte ptr [edi+2],al
    add esi,3
    add edi,3
    sub ecx,3
L564663:
    mov eax,dword ptr [esi]
    or eax,ebx
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L564663
    jmp dword ptr ds:[draw_resume]
L56467A:
    dec ecx
L56467B:
    mov eax,dword ptr [esi]
    or eax,ebx
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L56467B
    mov al,byte ptr [esi]
    or eax,ebx
    mov byte ptr [edi],al
    inc esi
    inc edi
    jmp dword ptr ds:[draw_resume]
L56469A:
    mov al,byte ptr [esi]
    or eax,ebx
    mov byte ptr [edi],al
    inc esi
    inc edi
    sub ecx,2
L5646A5:
    mov eax,dword ptr [esi]
    or eax,ebx
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L5646A5
    mov al,byte ptr [esi]
    or eax,ebx
    mov byte ptr [edi],al
    inc esi
    inc edi
    jmp dword ptr ds:[draw_resume]
L5646C4:
    mov ax,word ptr [esi]
    or eax,ebx
    mov word ptr [edi],ax
    add esi,2
    add edi,2
    sub ecx,3
L5646D5:
    mov eax,dword ptr [esi]
    or eax,ebx
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L5646D5
    mov al,byte ptr [esi]
    or eax,ebx
    mov byte ptr [edi],al
    inc esi
    inc edi
    jmp dword ptr ds:[draw_resume]
L5646F4:
    mov eax,dword ptr [esi]
    or eax,ebx
    mov word ptr [edi],ax
    shr eax,10h
    mov byte ptr [edi+2],al
    add esi,3
    add edi,3
    sub ecx,4
L56470A:
    mov eax,dword ptr [esi]
    or eax,ebx
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L56470A
    mov al,byte ptr [esi]
    or eax,ebx
    mov byte ptr [edi],al
    inc esi
    inc edi
    jmp dword ptr ds:[draw_resume]
L564729:
    sub ecx,2
L56472C:
    mov eax,dword ptr [esi]
    or eax,ebx
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L56472C
    mov ax,word ptr [esi]
    or eax,ebx
    mov word ptr [edi],ax
    add esi,2
    add edi,2
    jmp dword ptr ds:[draw_resume]
L564751:
    mov al,byte ptr [esi]
    or eax,ebx
    mov byte ptr [edi],al
    inc esi
    inc edi
    sub ecx,3
L56475C:
    mov eax,dword ptr [esi]
    or eax,ebx
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L56475C
    mov ax,word ptr [esi]
    or eax,ebx
    mov word ptr [edi],ax
    add esi,2
    add edi,2
    jmp dword ptr ds:[draw_resume]
L564781:
    mov ax,word ptr [esi]
    or eax,ebx
    mov word ptr [edi],ax
    add esi,2
    add edi,2
    sub ecx,4
L564792:
    mov eax,dword ptr [esi]
    or eax,ebx
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L564792
    mov ax,word ptr [esi]
    or eax,ebx
    mov word ptr [edi],ax
    add esi,2
    add edi,2
    jmp dword ptr ds:[draw_resume]
L5647B7:
    mov eax,dword ptr [esi]
    or eax,ebx
    mov word ptr [edi],ax
    shr eax,10h
    mov byte ptr [edi+2],al
    add esi,3
    add edi,3
    sub ecx,5
L5647CD:
    mov eax,dword ptr [esi]
    or eax,ebx
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L5647CD
    mov ax,word ptr [esi]
    or eax,ebx
    mov word ptr [edi],ax
    add esi,2
    add edi,2
    jmp dword ptr ds:[draw_resume]
L5647F2:
    sub ecx,3
L5647F5:
    mov eax,dword ptr [esi]
    or eax,ebx
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L5647F5
    mov eax,dword ptr [esi]
    or eax,ebx
    mov word ptr [edi],ax
    shr eax,10h
    mov byte ptr [edi+2],al
    add esi,3
    add edi,3
    jmp dword ptr ds:[draw_resume]
L56481F:
    mov al,byte ptr [esi]
    or eax,ebx
    mov byte ptr [edi],al
    inc esi
    inc edi
    sub ecx,4
L56482A:
    mov eax,dword ptr [esi]
    or eax,ebx
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L56482A
    mov eax,dword ptr [esi]
    or eax,ebx
    mov word ptr [edi],ax
    shr eax,10h
    mov byte ptr [edi+2],al
    add esi,3
    add edi,3
    jmp dword ptr ds:[draw_resume]
L564854:
    mov ax,word ptr [esi]
    or eax,ebx
    mov word ptr [edi],ax
    add esi,2
    add edi,2
    sub ecx,5
L564865:
    mov eax,dword ptr [esi]
    or eax,ebx
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L564865
    mov eax,dword ptr [esi]
    or eax,ebx
    mov word ptr [edi],ax
    shr eax,10h
    mov byte ptr [edi+2],al
    add esi,3
    add edi,3
    jmp dword ptr ds:[draw_resume]
L56488F:
    mov eax,dword ptr [esi]
    or eax,ebx
    mov word ptr [edi],ax
    shr eax,10h
    mov byte ptr [edi+2],al
    add esi,3
    add edi,3
    sub ecx,6
L5648A5:
    mov eax,dword ptr [esi]
    or eax,ebx
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L5648A5
    mov eax,dword ptr [esi]
    or eax,ebx
    mov word ptr [edi],ax
    shr eax,10h
    mov byte ptr [edi+2],al
    add esi,3
    add edi,3
    jmp dword ptr ds:[draw_resume]
L5648CF:
    mov al,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    inc esi
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
L5648E7:
    mov ah,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    inc esi
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],ah
    inc edi
    jmp dword ptr ds:[draw_resume]
L5648FF:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,2
    or eax,dword ptr ds:[state_88C034]
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
L56491C:
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,2
    or eax,dword ptr ds:[state_88C034]
    shr eax,8
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
L56493D:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,3
    or eax,dword ptr ds:[state_88C034]
    mov word ptr [edi],ax
    shr eax,10h
    mov byte ptr [edi+2],al
    add edi,3
    jmp dword ptr ds:[draw_resume]
L564960:
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,3
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],ah
    shr eax,10h
    mov word ptr [edi+1],ax
    add edi,3
    jmp dword ptr ds:[draw_resume]
L564984:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,2
    or eax,dword ptr ds:[state_88C034]
    mov word ptr [edi],ax
    add edi,2
    mov al,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    inc esi
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
L5649B3:
    mov ah,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    inc esi
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],ah
    inc edi
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,2
    or eax,dword ptr ds:[state_88C034]
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
L5649E2:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C034]
    mov dword ptr [edi],eax
    add edi,4
    jmp dword ptr ds:[draw_resume]
L5649FE:
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,3
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],ah
    shr eax,10h
    mov word ptr [edi+1],ax
    add edi,3
    mov al,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    inc esi
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
L564A34:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,2
    or eax,dword ptr ds:[state_88C034]
    mov word ptr [edi],ax
    add edi,2
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,2
    or eax,dword ptr ds:[state_88C034]
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
L564A68:
    mov ah,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    inc esi
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],ah
    inc edi
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,3
    or eax,dword ptr ds:[state_88C034]
    mov word ptr [edi],ax
    shr eax,10h
    mov byte ptr [edi+2],al
    add edi,3
    jmp dword ptr ds:[draw_resume]
L564A9D:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C034]
    mov dword ptr [edi],eax
    add edi,4
    mov al,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    inc esi
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
L564ACB:
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,3
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],ah
    shr eax,10h
    mov word ptr [edi+1],ax
    add edi,3
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,2
    or eax,dword ptr ds:[state_88C034]
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
L564B06:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,2
    or eax,dword ptr ds:[state_88C034]
    mov word ptr [edi],ax
    add edi,2
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,3
    or eax,dword ptr ds:[state_88C034]
    mov word ptr [edi],ax
    shr eax,10h
    mov byte ptr [edi+2],al
    add edi,3
    jmp dword ptr ds:[draw_resume]
L564B40:
    mov ah,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    inc esi
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],ah
    inc edi
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C034]
    mov dword ptr [edi],eax
    add edi,4
    jmp dword ptr ds:[draw_resume]
L564B6E:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C034]
    mov dword ptr [edi],eax
    add edi,4
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,2
    or eax,dword ptr ds:[state_88C034]
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
L564BA1:
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,3
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],ah
    shr eax,10h
    mov word ptr [edi+1],ax
    add edi,3
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,3
    or eax,dword ptr ds:[state_88C034]
    mov word ptr [edi],ax
    shr eax,10h
    mov byte ptr [edi+2],al
    add edi,3
    jmp dword ptr ds:[draw_resume]
L564BE2:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,2
    or eax,dword ptr ds:[state_88C034]
    mov word ptr [edi],ax
    add edi,2
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C034]
    mov dword ptr [edi],eax
    add edi,4
    jmp dword ptr ds:[draw_resume]
L564C15:
    mov ah,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    inc esi
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],ah
    inc edi
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C034]
    mov dword ptr [edi],eax
    add edi,4
    mov al,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    inc esi
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
L564C55:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C034]
    mov dword ptr [edi],eax
    add edi,4
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,3
    or eax,dword ptr ds:[state_88C034]
    mov word ptr [edi],ax
    shr eax,10h
    mov byte ptr [edi+2],al
    add edi,3
    jmp dword ptr ds:[draw_resume]
L564C8E:
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,3
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],ah
    shr eax,10h
    mov word ptr [edi+1],ax
    add edi,3
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C034]
    mov dword ptr [edi],eax
    add edi,4
    jmp dword ptr ds:[draw_resume]
L564CC8:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,2
    or eax,dword ptr ds:[state_88C034]
    mov word ptr [edi],ax
    add edi,2
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C034]
    mov dword ptr [edi],eax
    add edi,4
    mov al,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    inc esi
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
L564D0D:
    mov ah,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    inc esi
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],ah
    inc edi
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C034]
    mov dword ptr [edi],eax
    add edi,4
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,2
    or eax,dword ptr ds:[state_88C034]
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
L564D52:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C034]
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L564D52
    jmp dword ptr ds:[draw_resume]
L564D73:
    mov ah,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    inc esi
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],ah
    inc edi
    dec ecx
L564D86:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C034]
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L564D86
    jmp dword ptr ds:[draw_resume]
L564DA7:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,2
    or eax,dword ptr ds:[state_88C034]
    mov word ptr [edi],ax
    add edi,2
    sub ecx,2
L564DC1:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C034]
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L564DC1
    jmp dword ptr ds:[draw_resume]
L564DE2:
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,3
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],ah
    shr eax,10h
    mov word ptr [edi+1],ax
    add edi,3
    sub ecx,3
L564E03:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C034]
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L564E03
    jmp dword ptr ds:[draw_resume]
L564E24:
    dec ecx
L564E25:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C034]
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L564E25
    mov al,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    inc esi
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
L564E58:
    mov ah,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    inc esi
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],ah
    inc edi
    sub ecx,2
L564E6D:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C034]
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L564E6D
    mov al,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    inc esi
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
L564EA0:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,2
    or eax,dword ptr ds:[state_88C034]
    mov word ptr [edi],ax
    add edi,2
    sub ecx,3
L564EBA:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C034]
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L564EBA
    mov al,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    inc esi
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
L564EED:
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,3
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],ah
    shr eax,10h
    mov word ptr [edi+1],ax
    add edi,3
    sub ecx,4
L564F0E:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C034]
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L564F0E
    mov al,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    inc esi
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
L564F41:
    sub ecx,2
L564F44:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C034]
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L564F44
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,2
    or eax,dword ptr ds:[state_88C034]
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
L564F7C:
    mov ah,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    inc esi
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],ah
    inc edi
    sub ecx,3
L564F91:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C034]
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L564F91
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,2
    or eax,dword ptr ds:[state_88C034]
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
L564FC9:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,2
    or eax,dword ptr ds:[state_88C034]
    mov word ptr [edi],ax
    add edi,2
    sub ecx,4
L564FE3:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C034]
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L564FE3
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,2
    or eax,dword ptr ds:[state_88C034]
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
L56501B:
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,3
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],ah
    shr eax,10h
    mov word ptr [edi+1],ax
    add edi,3
    sub ecx,5
L56503C:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C034]
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L56503C
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,2
    or eax,dword ptr ds:[state_88C034]
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
L565074:
    sub ecx,3
L565077:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C034]
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L565077
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,3
    or eax,dword ptr ds:[state_88C034]
    mov word ptr [edi],ax
    shr eax,10h
    mov byte ptr [edi+2],al
    add edi,3
    jmp dword ptr ds:[draw_resume]
L5650B5:
    mov ah,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    inc esi
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],ah
    inc edi
    sub ecx,4
L5650CA:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C034]
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L5650CA
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,3
    or eax,dword ptr ds:[state_88C034]
    mov word ptr [edi],ax
    shr eax,10h
    mov byte ptr [edi+2],al
    add edi,3
    jmp dword ptr ds:[draw_resume]
L565108:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,2
    or eax,dword ptr ds:[state_88C034]
    mov word ptr [edi],ax
    add edi,2
    sub ecx,5
L565122:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C034]
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L565122
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,3
    or eax,dword ptr ds:[state_88C034]
    mov word ptr [edi],ax
    shr eax,10h
    mov byte ptr [edi+2],al
    add edi,3
    jmp dword ptr ds:[draw_resume]
L565160:
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,3
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],ah
    shr eax,10h
    mov word ptr [edi+1],ax
    add edi,3
    sub ecx,6
L565181:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C034]
    add esi,4
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L565181
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,3
    or eax,dword ptr ds:[state_88C034]
    mov word ptr [edi],ax
    shr eax,10h
    mov byte ptr [edi+2],al
    add edi,3
    jmp dword ptr ds:[draw_resume]
L5651BF:
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
L5651CD:
    mov ax,word ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
L5651E6:
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    mov byte ptr [edi],al
    inc edi
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
L5651FC:
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi],eax
    add edi,3
    jmp dword ptr ds:[draw_resume]
L56521C:
    mov eax,dword ptr [edi-1]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-1],eax
    add edi,3
    jmp dword ptr ds:[draw_resume]
L56523E:
    mov ax,word ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov word ptr [edi],ax
    add edi,2
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
L56525F:
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    mov byte ptr [edi],al
    inc edi
    mov ax,word ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
L565280:
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi],eax
    add edi,4
    jmp dword ptr ds:[draw_resume]
L5652A5:
    mov eax,dword ptr [edi-1]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-1],eax
    add edi,3
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
L5652CF:
    mov ax,word ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov word ptr [edi],ax
    add edi,2
    mov ax,word ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
L5652FB:
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    mov byte ptr [edi],al
    inc edi
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi],eax
    add edi,3
    jmp dword ptr ds:[draw_resume]
L565323:
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi],eax
    add edi,4
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
L565350:
    mov eax,dword ptr [edi-1]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-1],eax
    add edi,3
    mov ax,word ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
L565385:
    mov ax,word ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov word ptr [edi],ax
    add edi,2
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi],eax
    add edi,3
    jmp dword ptr ds:[draw_resume]
L5653B8:
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    mov byte ptr [edi],al
    inc edi
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi],eax
    add edi,4
    jmp dword ptr ds:[draw_resume]
L5653E5:
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi],eax
    add edi,4
    mov ax,word ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
L56541D:
    mov eax,dword ptr [edi-1]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-1],eax
    add edi,3
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi],eax
    add edi,3
    jmp dword ptr ds:[draw_resume]
L565459:
    mov ax,word ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov word ptr [edi],ax
    add edi,2
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi],eax
    add edi,4
    jmp dword ptr ds:[draw_resume]
L565491:
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    mov byte ptr [edi],al
    inc edi
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi],eax
    add edi,4
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
L5654C6:
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi],eax
    add edi,4
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi],eax
    add edi,3
    jmp dword ptr ds:[draw_resume]
L565505:
    mov eax,dword ptr [edi-1]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-1],eax
    add edi,3
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi],eax
    add edi,4
    jmp dword ptr ds:[draw_resume]
L565546:
    mov ax,word ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov word ptr [edi],ax
    add edi,2
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi],eax
    add edi,4
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
L565586:
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    mov byte ptr [edi],al
    inc edi
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi],eax
    add edi,4
    mov ax,word ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
L5655C6:
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L5655C6
    jmp dword ptr ds:[draw_resume]
L5655F0:
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    mov byte ptr [edi],al
    inc edi
    dec ecx
L5655F9:
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L5655F9
    jmp dword ptr ds:[draw_resume]
L565623:
    mov ax,word ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov word ptr [edi],ax
    add edi,2
    sub ecx,2
L565639:
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L565639
    jmp dword ptr ds:[draw_resume]
L565663:
    mov eax,dword ptr [edi-1]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-1],eax
    add edi,3
    sub ecx,3
L565682:
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L565682
    jmp dword ptr ds:[draw_resume]
L5656AC:
    dec ecx
L5656AD:
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L5656AD
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
L5656DF:
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    mov byte ptr [edi],al
    inc edi
    sub ecx,2
L5656EA:
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L5656EA
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
L56571C:
    mov ax,word ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov word ptr [edi],ax
    add edi,2
    sub ecx,3
L565732:
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L565732
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
L565764:
    mov eax,dword ptr [edi-1]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-1],eax
    add edi,3
    sub ecx,4
L565783:
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L565783
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
L5657B5:
    sub ecx,2
L5657B8:
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L5657B8
    mov ax,word ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
L5657F5:
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    mov byte ptr [edi],al
    inc edi
    sub ecx,3
L565800:
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L565800
    mov ax,word ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
L56583D:
    mov ax,word ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov word ptr [edi],ax
    add edi,2
    sub ecx,4
L565853:
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L565853
    mov ax,word ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
L565890:
    mov eax,dword ptr [edi-1]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-1],eax
    add edi,3
    sub ecx,5
L5658AF:
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L5658AF
    mov ax,word ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
L5658EC:
    sub ecx,3
L5658EF:
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L5658EF
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi],eax
    add edi,3
    jmp dword ptr ds:[draw_resume]
L565933:
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    mov byte ptr [edi],al
    inc edi
    sub ecx,4
L56593E:
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L56593E
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi],eax
    add edi,3
    jmp dword ptr ds:[draw_resume]
L565982:
    mov ax,word ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov word ptr [edi],ax
    add edi,2
    sub ecx,5
L565998:
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L565998
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi],eax
    add edi,3
    jmp dword ptr ds:[draw_resume]
L5659DC:
    mov eax,dword ptr [edi-1]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-1],eax
    add edi,3
    sub ecx,6
L5659FB:
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L5659FB
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi],eax
    add edi,3
    jmp dword ptr ds:[draw_resume]
L565A3F:
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
L565A59:
    mov dl,byte ptr [edi]
    mov ah,byte ptr [edx+ebx]
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov byte ptr [edi],ah
    inc edi
    jmp dword ptr ds:[draw_resume]
L565A73:
    mov ax,word ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
L565A98:
    mov ax,word ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    shl eax,8
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    shr eax,8
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
L565AC3:
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    bswap eax
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    bswap eax
    mov al,dl
    bswap eax
    mov dword ptr [edi],eax
    add edi,3
    jmp dword ptr ds:[draw_resume]
L565AF7:
    mov eax,dword ptr [edi-1]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov al,dl
    mov dword ptr [edi-1],eax
    add edi,3
    jmp dword ptr ds:[draw_resume]
L565B29:
    mov ax,word ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov word ptr [edi],ax
    add edi,2
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
L565B62:
    mov dl,byte ptr [edi]
    mov ah,byte ptr [edx+ebx]
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov byte ptr [edi],ah
    inc edi
    mov ax,word ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
L565B9B:
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov dword ptr [edi],eax
    add edi,4
    jmp dword ptr ds:[draw_resume]
L565BCC:
    mov eax,dword ptr [edi-1]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov al,dl
    mov dword ptr [edi-1],eax
    add edi,3
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
L565C12:
    mov ax,word ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov word ptr [edi],ax
    add edi,2
    mov ax,word ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
L565C56:
    mov dl,byte ptr [edi]
    mov ah,byte ptr [edx+ebx]
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov byte ptr [edi],ah
    inc edi
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    bswap eax
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    bswap eax
    mov al,dl
    bswap eax
    mov dword ptr [edi],eax
    add edi,3
    jmp dword ptr ds:[draw_resume]
L565C9E:
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov dword ptr [edi],eax
    add edi,4
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
L565CE3:
    mov eax,dword ptr [edi-1]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov al,dl
    mov dword ptr [edi-1],eax
    add edi,3
    mov ax,word ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
L565D34:
    mov ax,word ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov word ptr [edi],ax
    add edi,2
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    bswap eax
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    bswap eax
    mov al,dl
    bswap eax
    mov dword ptr [edi],eax
    add edi,3
    jmp dword ptr ds:[draw_resume]
L565D87:
    mov dl,byte ptr [edi]
    mov ah,byte ptr [edx+ebx]
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov byte ptr [edi],ah
    inc edi
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov dword ptr [edi],eax
    add edi,4
    jmp dword ptr ds:[draw_resume]
L565DCC:
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov dword ptr [edi],eax
    add edi,4
    mov ax,word ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
L565E1C:
    mov eax,dword ptr [edi-1]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov al,dl
    mov dword ptr [edi-1],eax
    add edi,3
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    bswap eax
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    bswap eax
    mov al,dl
    bswap eax
    mov dword ptr [edi],eax
    add edi,3
    jmp dword ptr ds:[draw_resume]
L565E7C:
    mov ax,word ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov word ptr [edi],ax
    add edi,2
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov dword ptr [edi],eax
    add edi,4
    jmp dword ptr ds:[draw_resume]
L565ECC:
    mov dl,byte ptr [edi]
    mov ah,byte ptr [edx+ebx]
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov byte ptr [edi],ah
    inc edi
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov dword ptr [edi],eax
    add edi,4
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
L565F25:
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov dword ptr [edi],eax
    add edi,4
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    bswap eax
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    bswap eax
    mov al,dl
    bswap eax
    mov dword ptr [edi],eax
    add edi,3
    jmp dword ptr ds:[draw_resume]
L565F84:
    mov eax,dword ptr [edi-1]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov al,dl
    mov dword ptr [edi-1],eax
    add edi,3
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov dword ptr [edi],eax
    add edi,4
    jmp dword ptr ds:[draw_resume]
L565FE1:
    mov ax,word ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov word ptr [edi],ax
    add edi,2
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov dword ptr [edi],eax
    add edi,4
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
L566045:
    mov dl,byte ptr [edi]
    mov ah,byte ptr [edx+ebx]
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov byte ptr [edi],ah
    inc edi
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov dword ptr [edi],eax
    add edi,4
    mov ax,word ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
L5660A9:
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L5660A9
    jmp dword ptr ds:[draw_resume]
L5660DF:
    mov dl,byte ptr [edi]
    mov ah,byte ptr [edx+ebx]
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov byte ptr [edi],ah
    inc edi
    dec ecx
L5660F4:
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L5660F4
    jmp dword ptr ds:[draw_resume]
L56612A:
    mov ax,word ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov word ptr [edi],ax
    add edi,2
    sub ecx,2
L56614C:
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L56614C
    jmp dword ptr ds:[draw_resume]
L566182:
    mov eax,dword ptr [edi-1]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov al,dl
    mov dword ptr [edi-1],eax
    add edi,3
    sub ecx,3
L5661B1:
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L5661B1
    jmp dword ptr ds:[draw_resume]
L5661E7:
    dec ecx
L5661E8:
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L5661E8
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
L566232:
    mov dl,byte ptr [edi]
    mov ah,byte ptr [edx+ebx]
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov byte ptr [edi],ah
    inc edi
    sub ecx,2
L566249:
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L566249
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
L566293:
    mov ax,word ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov word ptr [edi],ax
    add edi,2
    sub ecx,3
L5662B5:
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L5662B5
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
L5662FF:
    mov eax,dword ptr [edi-1]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov al,dl
    mov dword ptr [edi-1],eax
    add edi,3
    sub ecx,4
L56632E:
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L56632E
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov byte ptr [edi],al
    inc edi
    jmp dword ptr ds:[draw_resume]
L566378:
    sub ecx,2
L56637B:
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L56637B
    mov ax,word ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
L5663D0:
    mov dl,byte ptr [edi]
    mov ah,byte ptr [edx+ebx]
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov byte ptr [edi],ah
    inc edi
    sub ecx,3
L5663E7:
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L5663E7
    mov ax,word ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
L56643C:
    mov ax,word ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov word ptr [edi],ax
    add edi,2
    sub ecx,4
L56645E:
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L56645E
    mov ax,word ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
L5664B3:
    mov eax,dword ptr [edi-1]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov al,dl
    mov dword ptr [edi-1],eax
    add edi,3
    sub ecx,5
L5664E2:
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L5664E2
    mov ax,word ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov word ptr [edi],ax
    add edi,2
    jmp dword ptr ds:[draw_resume]
L566537:
    sub ecx,3
L56653A:
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L56653A
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    bswap eax
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    bswap eax
    mov al,dl
    bswap eax
    mov dword ptr [edi],eax
    add edi,3
    jmp dword ptr ds:[draw_resume]
L56659E:
    mov dl,byte ptr [edi]
    mov ah,byte ptr [edx+ebx]
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov byte ptr [edi],ah
    inc edi
    sub ecx,4
L5665B5:
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L5665B5
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    bswap eax
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    bswap eax
    mov al,dl
    bswap eax
    mov dword ptr [edi],eax
    add edi,3
    jmp dword ptr ds:[draw_resume]
L566619:
    mov ax,word ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov word ptr [edi],ax
    add edi,2
    sub ecx,5
L56663B:
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L56663B
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    bswap eax
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    bswap eax
    mov al,dl
    bswap eax
    mov dword ptr [edi],eax
    add edi,3
    jmp dword ptr ds:[draw_resume]
L56669F:
    mov eax,dword ptr [edi-1]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov al,dl
    mov dword ptr [edi-1],eax
    add edi,3
    sub ecx,6
L5666CE:
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    mov dword ptr [edi],eax
    add edi,4
    sub ecx,4
    ja SHORT L5666CE
    mov eax,dword ptr [edi]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    bswap eax
    or eax,dword ptr ds:[state_88C030]
    and eax,dword ptr ds:[state_88C02C]
    bswap eax
    mov al,dl
    bswap eax
    mov dword ptr [edi],eax
    add edi,3
    jmp dword ptr ds:[draw_resume]
    mov al,byte ptr [esi]
    mov byte ptr [edi],al
    inc esi
    inc edi
    jmp dword ptr ds:[draw_resume]
    mov eax,dword ptr [esi]
    mov byte ptr [edi],al
    add esi,2
    mov byte ptr [edi+2],ah
    add edi,3
    jmp dword ptr ds:[draw_resume]
    mov eax,dword ptr [esi]
    mov byte ptr [edi],al
    add esi,3
    mov byte ptr [edi+2],ah
    shr eax,10h
    mov byte ptr [edi+4],al
    add edi,5
    jmp dword ptr ds:[draw_resume]
    mov eax,dword ptr [esi]
    mov byte ptr [edi],al
    add esi,4
    mov byte ptr [edi+2],ah
    shr eax,10h
    mov byte ptr [edi+4],al
    mov byte ptr [edi+6],ah
    add edi,7
    jmp dword ptr ds:[draw_resume]
L566786:
    mov al,byte ptr [esi]
    inc esi
    mov byte ptr [edi],al
    dec edi
    jmp dword ptr ds:[draw_resume]
L566792:
    mov eax,dword ptr [esi]
    add esi,2
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L5667A5:
    mov eax,dword ptr [esi]
    add esi,3
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    shr eax,10h
    mov byte ptr [edi-2],al
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L5667BE:
    mov eax,dword ptr [esi]
    add esi,4
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,4
    jmp dword ptr ds:[draw_resume]
L5667D1:
    mov eax,dword ptr [esi]
    add esi,4
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    shr eax,10h
    mov byte ptr [edi-2],al
    mov byte ptr [edi-3],ah
    sub edi,4
    jmp dword ptr ds:[draw_resume]
L5667ED:
    mov eax,dword ptr [esi]
    mov bl,byte ptr [esi+4]
    bswap eax
    mov dword ptr [edi-3],eax
    add esi,5
    mov byte ptr [edi-4],bl
    sub edi,5
    jmp dword ptr ds:[draw_resume]
L566806:
    mov eax,dword ptr [esi]
    mov bl,byte ptr [esi+4]
    mov byte ptr [edi],al
    mov byte ptr [edi-4],bl
    mov byte ptr [edi-1],ah
    shr eax,10h
    mov byte ptr [edi-2],al
    add esi,5
    mov byte ptr [edi-3],ah
    sub edi,5
    jmp dword ptr ds:[draw_resume]
L566828:
    mov bl,byte ptr [esi]
    mov eax,dword ptr [esi+1]
    bswap eax
    mov byte ptr [edi],bl
    add esi,5
    mov dword ptr [edi-4],eax
    sub edi,5
    jmp dword ptr ds:[draw_resume]
L566840:
    mov eax,dword ptr [esi]
    mov ebx,dword ptr [esi+4]
    bswap eax
    mov dword ptr [edi-3],eax
    mov byte ptr [edi-4],bl
    add esi,6
    mov byte ptr [edi-5],bh
    sub edi,6
    jmp dword ptr ds:[draw_resume]
L56685C:
    mov eax,dword ptr [esi]
    mov ebx,dword ptr [esi+4]
    mov byte ptr [edi-5],bh
    mov byte ptr [edi-1],ah
    mov byte ptr [edi-4],bl
    mov byte ptr [edi],al
    shr eax,10h
    mov byte ptr [edi-2],al
    add esi,6
    mov byte ptr [edi-3],ah
    sub edi,6
    jmp dword ptr ds:[draw_resume]
L566881:
    mov eax,dword ptr [esi]
    mov ebx,dword ptr [esi+2]
    bswap ebx
    mov byte ptr [edi],al
    add esi,6
    mov byte ptr [edi-1],ah
    mov dword ptr [edi-5],ebx
    sub edi,6
    jmp dword ptr ds:[draw_resume]
L56689C:
    mov bl,byte ptr [esi]
    mov bh,byte ptr [esi+5]
    mov eax,dword ptr [esi+1]
    mov byte ptr [edi],bl
    bswap eax
    mov dword ptr [edi-4],eax
    add esi,6
    mov byte ptr [edi-5],bh
    sub edi,6
    jmp dword ptr ds:[draw_resume]
L5668BA:
    mov eax,dword ptr [esi]
    mov ebx,dword ptr [esi+4]
    bswap eax
    mov byte ptr [edi-4],bl
    mov dword ptr [edi-3],eax
    shr ebx,8
    add esi,7
    mov byte ptr [edi-5],bl
    mov byte ptr [edi-6],bh
    sub edi,7
    jmp dword ptr ds:[draw_resume]
L5668DC:
    mov eax,dword ptr [esi-1]
    mov ebx,dword ptr [esi+3]
    mov byte ptr [edi],ah
    shr eax,10h
    mov byte ptr [edi-1],al
    add esi,7
    mov byte ptr [edi-2],ah
    bswap ebx
    mov dword ptr [edi-6],ebx
    sub edi,7
    jmp dword ptr ds:[draw_resume]
L5668FE:
    mov eax,dword ptr [esi+2]
    bswap eax
    mov dword ptr [edi-5],eax
    mov eax,dword ptr [esi]
    mov bl,byte ptr [esi+6]
    mov byte ptr [edi],al
    mov byte ptr [edi-6],bl
    mov byte ptr [edi-1],ah
    add esi,7
    sub edi,7
    jmp dword ptr ds:[draw_resume]
L56691F:
    mov eax,dword ptr [esi+1]
    mov bl,byte ptr [esi]
    bswap eax
    mov byte ptr [edi],bl
    mov ebx,dword ptr [esi+5]
    mov dword ptr [edi-4],eax
    add esi,7
    mov byte ptr [edi-5],bl
    mov byte ptr [edi-6],bh
    sub edi,7
    jmp dword ptr ds:[draw_resume]
L566940:
    mov eax,dword ptr [esi]
    add esi,4
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L566940
    jmp dword ptr ds:[draw_resume]
L566958:
    mov al,byte ptr [esi]
    inc esi
    mov byte ptr [edi],al
    dec edi
    dec ecx
L56695F:
    mov eax,dword ptr [esi]
    add esi,4
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L56695F
    jmp dword ptr ds:[draw_resume]
L566977:
    mov eax,dword ptr [esi]
    add esi,2
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    sub edi,2
    sub ecx,2
L566987:
    mov eax,dword ptr [esi]
    add esi,4
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L566987
    jmp dword ptr ds:[draw_resume]
L56699F:
    mov eax,dword ptr [esi]
    add esi,3
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    shr eax,10h
    mov byte ptr [edi-2],al
    sub edi,3
    sub ecx,3
L5669B5:
    mov eax,dword ptr [esi]
    add esi,4
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L5669B5
    jmp dword ptr ds:[draw_resume]
L5669CD:
    dec ecx
L5669CE:
    mov eax,dword ptr [esi]
    add esi,4
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L5669CE
    mov al,byte ptr [esi]
    inc esi
    mov byte ptr [edi],al
    dec edi
    jmp dword ptr ds:[draw_resume]
L5669EC:
    mov al,byte ptr [esi]
    inc esi
    mov byte ptr [edi],al
    dec edi
    sub ecx,2
L5669F5:
    mov eax,dword ptr [esi]
    add esi,4
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L5669F5
    mov al,byte ptr [esi]
    inc esi
    mov byte ptr [edi],al
    dec edi
    jmp dword ptr ds:[draw_resume]
L566A13:
    mov eax,dword ptr [esi]
    add esi,2
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    sub edi,2
    sub ecx,3
L566A23:
    mov eax,dword ptr [esi]
    add esi,4
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L566A23
    mov al,byte ptr [esi]
    inc esi
    mov byte ptr [edi],al
    dec edi
    jmp dword ptr ds:[draw_resume]
L566A41:
    mov eax,dword ptr [esi]
    add esi,3
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    shr eax,10h
    mov byte ptr [edi-2],al
    sub edi,3
    sub ecx,4
L566A57:
    mov eax,dword ptr [esi]
    add esi,4
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L566A57
    mov al,byte ptr [esi]
    inc esi
    mov byte ptr [edi],al
    dec edi
    jmp dword ptr ds:[draw_resume]
L566A75:
    sub ecx,2
L566A78:
    mov eax,dword ptr [esi]
    add esi,4
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L566A78
    mov eax,dword ptr [esi]
    add esi,2
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L566A9D:
    mov al,byte ptr [esi]
    inc esi
    mov byte ptr [edi],al
    dec edi
    sub ecx,3
L566AA6:
    mov eax,dword ptr [esi]
    add esi,4
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L566AA6
    mov eax,dword ptr [esi]
    add esi,2
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L566ACB:
    mov eax,dword ptr [esi]
    add esi,2
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    sub edi,2
    sub ecx,4
L566ADB:
    mov eax,dword ptr [esi]
    add esi,4
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L566ADB
    mov eax,dword ptr [esi]
    add esi,2
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L566B00:
    mov eax,dword ptr [esi]
    add esi,3
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    shr eax,10h
    mov byte ptr [edi-2],al
    sub edi,3
    sub ecx,5
L566B16:
    mov eax,dword ptr [esi]
    add esi,4
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L566B16
    mov eax,dword ptr [esi]
    add esi,2
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L566B3B:
    sub ecx,3
L566B3E:
    mov eax,dword ptr [esi]
    add esi,4
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L566B3E
    mov eax,dword ptr [esi]
    add esi,3
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    shr eax,10h
    mov byte ptr [edi-2],al
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L566B69:
    mov al,byte ptr [esi]
    inc esi
    mov byte ptr [edi],al
    dec edi
    sub ecx,4
L566B72:
    mov eax,dword ptr [esi]
    add esi,4
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L566B72
    mov eax,dword ptr [esi]
    add esi,3
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    shr eax,10h
    mov byte ptr [edi-2],al
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L566B9D:
    mov eax,dword ptr [esi]
    add esi,2
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    sub edi,2
    sub ecx,5
L566BAD:
    mov eax,dword ptr [esi]
    add esi,4
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L566BAD
    mov eax,dword ptr [esi]
    add esi,3
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    shr eax,10h
    mov byte ptr [edi-2],al
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L566BD8:
    mov eax,dword ptr [esi]
    add esi,3
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    shr eax,10h
    mov byte ptr [edi-2],al
    sub edi,3
    sub ecx,6
L566BEE:
    mov eax,dword ptr [esi]
    add esi,4
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L566BEE
    mov eax,dword ptr [esi]
    add esi,3
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    shr eax,10h
    mov byte ptr [edi-2],al
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L566C19:
    mov al,byte ptr [esi]
    inc esi
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],al
    dec edi
    jmp dword ptr ds:[draw_resume]
L566C31:
    mov ah,byte ptr [esi]
    inc esi
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    dec edi
    jmp dword ptr ds:[draw_resume]
L566C49:
    mov eax,dword ptr [esi]
    add esi,2
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L566C68:
    mov eax,dword ptr [esi-1]
    add esi,2
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    shr eax,8
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L566C8B:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,2
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L566CAA:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    shr eax,10h
    mov byte ptr [edi-2],al
    add esi,3
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L566CCF:
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    shr eax,10h
    mov byte ptr [edi-1],al
    mov byte ptr [edi-2],ah
    add esi,3
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L566CF5:
    mov eax,dword ptr [esi-1]
    add esi,2
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    shr eax,8
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    sub edi,2
    mov ah,byte ptr [esi]
    inc esi
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    dec edi
    jmp dword ptr ds:[draw_resume]
L566D2A:
    mov al,byte ptr [esi]
    inc esi
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],al
    dec edi
    mov eax,dword ptr [esi-1]
    add esi,2
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    shr eax,8
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L566D5F:
    mov eax,dword ptr [esi]
    sub edi,4
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi+1],eax
    jmp dword ptr ds:[draw_resume]
L566D7E:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    shr eax,10h
    mov byte ptr [edi-2],al
    add esi,3
    sub edi,3
    mov ah,byte ptr [esi]
    inc esi
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    dec edi
    jmp dword ptr ds:[draw_resume]
L566DB5:
    mov eax,dword ptr [esi-1]
    add esi,2
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    shr eax,8
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    sub edi,2
    mov eax,dword ptr [esi-1]
    add esi,2
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    shr eax,8
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L566DF5:
    mov al,byte ptr [esi]
    inc esi
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],al
    dec edi
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    shr eax,10h
    mov byte ptr [edi-1],al
    mov byte ptr [edi-2],ah
    add esi,3
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L566E2D:
    mov eax,dword ptr [esi]
    sub edi,4
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi+1],eax
    mov ah,byte ptr [esi]
    inc esi
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    dec edi
    jmp dword ptr ds:[draw_resume]
L566E5E:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    shr eax,10h
    mov byte ptr [edi-2],al
    add esi,3
    sub edi,3
    mov eax,dword ptr [esi-1]
    add esi,2
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    shr eax,8
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L566EA0:
    mov eax,dword ptr [esi-1]
    add esi,2
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    shr eax,8
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    sub edi,2
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    shr eax,10h
    mov byte ptr [edi-1],al
    mov byte ptr [edi-2],ah
    add esi,3
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L566EE3:
    mov al,byte ptr [esi]
    inc esi
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],al
    dec edi
    mov eax,dword ptr [esi]
    sub edi,4
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi+1],eax
    jmp dword ptr ds:[draw_resume]
L566F14:
    mov eax,dword ptr [esi]
    sub edi,4
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi+1],eax
    mov eax,dword ptr [esi-1]
    add esi,2
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    shr eax,8
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L566F50:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    shr eax,10h
    mov byte ptr [edi-2],al
    add esi,3
    sub edi,3
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    shr eax,10h
    mov byte ptr [edi-1],al
    mov byte ptr [edi-2],ah
    add esi,3
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L566F95:
    mov eax,dword ptr [esi-1]
    add esi,2
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    shr eax,8
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    sub edi,2
    mov eax,dword ptr [esi]
    sub edi,4
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi+1],eax
    jmp dword ptr ds:[draw_resume]
L566FD1:
    mov al,byte ptr [esi]
    inc esi
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],al
    dec edi
    mov eax,dword ptr [esi]
    sub edi,4
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi+1],eax
    mov ah,byte ptr [esi]
    inc esi
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    dec edi
    jmp dword ptr ds:[draw_resume]
L567014:
    mov eax,dword ptr [esi]
    sub edi,4
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi+1],eax
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    shr eax,10h
    mov byte ptr [edi-1],al
    mov byte ptr [edi-2],ah
    add esi,3
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L567053:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    shr eax,10h
    mov byte ptr [edi-2],al
    add esi,3
    sub edi,3
    mov eax,dword ptr [esi]
    sub edi,4
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi+1],eax
    jmp dword ptr ds:[draw_resume]
L567091:
    mov eax,dword ptr [esi-1]
    add esi,2
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    shr eax,8
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    sub edi,2
    mov eax,dword ptr [esi]
    sub edi,4
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi+1],eax
    mov ah,byte ptr [esi]
    inc esi
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    dec edi
    jmp dword ptr ds:[draw_resume]
L5670DF:
    mov al,byte ptr [esi]
    inc esi
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],al
    dec edi
    mov eax,dword ptr [esi]
    sub edi,4
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi+1],eax
    mov eax,dword ptr [esi-1]
    add esi,2
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    shr eax,8
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L56712D:
    mov eax,dword ptr [esi]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L56712D
    jmp dword ptr ds:[draw_resume]
L567151:
    mov al,byte ptr [esi]
    inc esi
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],al
    dec edi
    dec ecx
L567164:
    mov eax,dword ptr [esi]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L567164
    jmp dword ptr ds:[draw_resume]
L567188:
    mov eax,dword ptr [esi-1]
    add esi,2
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    shr eax,8
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    sub edi,2
    sub ecx,2
L5671A8:
    mov eax,dword ptr [esi]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L5671A8
    jmp dword ptr ds:[draw_resume]
L5671CC:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    shr eax,10h
    mov byte ptr [edi-2],al
    add esi,3
    sub edi,3
    sub ecx,3
L5671EE:
    mov eax,dword ptr [esi]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L5671EE
    jmp dword ptr ds:[draw_resume]
L567212:
    dec ecx
L567213:
    mov eax,dword ptr [esi]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L567213
    mov ah,byte ptr [esi]
    inc esi
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    dec edi
    jmp dword ptr ds:[draw_resume]
L567249:
    mov al,byte ptr [esi]
    inc esi
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],al
    dec edi
    sub ecx,2
L56725E:
    mov eax,dword ptr [esi]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L56725E
    mov ah,byte ptr [esi]
    inc esi
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    dec edi
    jmp dword ptr ds:[draw_resume]
L567294:
    mov eax,dword ptr [esi-1]
    add esi,2
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    shr eax,8
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    sub edi,2
    sub ecx,3
L5672B4:
    mov eax,dword ptr [esi]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L5672B4
    mov ah,byte ptr [esi]
    inc esi
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    dec edi
    jmp dword ptr ds:[draw_resume]
L5672EA:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    shr eax,10h
    mov byte ptr [edi-2],al
    add esi,3
    sub edi,3
    sub ecx,4
L56730C:
    mov eax,dword ptr [esi]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L56730C
    mov ah,byte ptr [esi]
    inc esi
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    dec edi
    jmp dword ptr ds:[draw_resume]
L567342:
    sub ecx,2
L567345:
    mov eax,dword ptr [esi]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L567345
    mov eax,dword ptr [esi-1]
    add esi,2
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    shr eax,8
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L567386:
    mov al,byte ptr [esi]
    inc esi
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],al
    dec edi
    sub ecx,3
L56739B:
    mov eax,dword ptr [esi]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L56739B
    mov eax,dword ptr [esi-1]
    add esi,2
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    shr eax,8
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L5673DC:
    mov eax,dword ptr [esi-1]
    add esi,2
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    shr eax,8
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    sub edi,2
    sub ecx,4
L5673FC:
    mov eax,dword ptr [esi]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L5673FC
    mov eax,dword ptr [esi-1]
    add esi,2
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    shr eax,8
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L56743D:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    shr eax,10h
    mov byte ptr [edi-2],al
    add esi,3
    sub edi,3
    sub ecx,5
L56745F:
    mov eax,dword ptr [esi]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L56745F
    mov eax,dword ptr [esi-1]
    add esi,2
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    shr eax,8
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L5674A0:
    sub ecx,3
L5674A3:
    mov eax,dword ptr [esi]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L5674A3
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    shr eax,10h
    mov byte ptr [edi-1],al
    mov byte ptr [edi-2],ah
    add esi,3
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L5674E7:
    mov al,byte ptr [esi]
    inc esi
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],al
    dec edi
    sub ecx,4
L5674FC:
    mov eax,dword ptr [esi]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L5674FC
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    shr eax,10h
    mov byte ptr [edi-1],al
    mov byte ptr [edi-2],ah
    add esi,3
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L567540:
    mov eax,dword ptr [esi-1]
    add esi,2
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    shr eax,8
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    sub edi,2
    sub ecx,5
L567560:
    mov eax,dword ptr [esi]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L567560
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    shr eax,10h
    mov byte ptr [edi-1],al
    mov byte ptr [edi-2],ah
    add esi,3
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L5675A4:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    shr eax,10h
    mov byte ptr [edi-2],al
    add esi,3
    sub edi,3
    sub ecx,6
L5675C6:
    mov eax,dword ptr [esi]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    add esi,4
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L5675C6
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    shr eax,10h
    mov byte ptr [edi-1],al
    mov byte ptr [edi-2],ah
    add esi,3
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L56760A:
    mov al,byte ptr [esi]
    inc esi
    or eax,ebx
    mov byte ptr [edi],al
    dec edi
    jmp dword ptr ds:[draw_resume]
L567618:
    mov ax,word ptr [esi]
    or eax,ebx
    add esi,2
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L56762E:
    mov eax,dword ptr [esi]
    or eax,ebx
    add esi,3
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    shr eax,8
    mov byte ptr [edi-2],ah
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L567649:
    mov eax,dword ptr [esi]
    bswap eax
    or eax,ebx
    add esi,4
    mov dword ptr [edi-3],eax
    sub edi,4
    jmp dword ptr ds:[draw_resume]
L56765E:
    mov eax,dword ptr [esi]
    or eax,ebx
    add esi,4
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    shr eax,10h
    mov byte ptr [edi-2],al
    mov byte ptr [edi-3],ah
    sub edi,4
    jmp dword ptr ds:[draw_resume]
L56767C:
    mov eax,dword ptr [esi]
    mov dl,byte ptr [esi+4]
    or eax,ebx
    or edx,ebx
    bswap eax
    mov byte ptr [edi-4],dl
    mov dword ptr [edi-3],eax
    add esi,5
    sub edi,5
    jmp dword ptr ds:[draw_resume]
L567699:
    mov eax,dword ptr [esi]
    or eax,ebx
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    shr eax,10h
    mov byte ptr [edi-2],al
    add esi,3
    sub edi,3
    mov eax,dword ptr [esi]
    or eax,ebx
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    add esi,2
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L5676C3:
    mov dl,byte ptr [esi]
    mov eax,dword ptr [esi+1]
    or eax,ebx
    or edx,ebx
    bswap eax
    mov byte ptr [edi],dl
    mov dword ptr [edi-4],eax
    add esi,5
    sub edi,5
    jmp dword ptr ds:[draw_resume]
L5676DF:
    mov eax,dword ptr [esi]
    mov edx,dword ptr [esi+4]
    or eax,ebx
    or edx,ebx
    bswap eax
    mov dword ptr [edi-3],eax
    add esi,6
    mov byte ptr [edi-4],dl
    mov byte ptr [edi-5],dh
    sub edi,6
    jmp dword ptr ds:[draw_resume]
L5676FF:
    mov eax,dword ptr [esi]
    or eax,ebx
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    shr eax,10h
    mov byte ptr [edi-2],al
    add esi,3
    sub edi,3
    mov eax,dword ptr [esi]
    or eax,ebx
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    shr eax,10h
    mov byte ptr [edi-2],al
    add esi,3
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L56772F:
    mov eax,dword ptr [esi]
    mov edx,dword ptr [esi+2]
    or eax,ebx
    or edx,ebx
    bswap edx
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    add esi,6
    mov dword ptr [edi-5],edx
    sub edi,6
    jmp dword ptr ds:[draw_resume]
L56774E:
    mov dl,byte ptr [esi]
    mov dh,byte ptr [esi+5]
    mov eax,dword ptr [esi+1]
    or eax,ebx
    or edx,ebx
    bswap eax
    mov byte ptr [edi],dl
    mov dword ptr [edi-4],eax
    add esi,6
    mov byte ptr [edi-5],dh
    sub edi,6
    jmp dword ptr ds:[draw_resume]
L567770:
    mov eax,dword ptr [esi]
    mov edx,dword ptr [esi+4]
    or eax,ebx
    or edx,ebx
    bswap eax
    mov dword ptr [edi-3],eax
    mov byte ptr [edi-4],dl
    mov byte ptr [edi-5],dh
    shr ebx,10h
    add esi,7
    mov byte ptr [edi-6],dl
    sub edi,7
    jmp dword ptr ds:[draw_resume]
L567796:
    mov eax,dword ptr [esi]
    mov edx,dword ptr [esi+3]
    or eax,ebx
    or edx,ebx
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    shr eax,10h
    add esi,7
    mov byte ptr [edi-2],al
    bswap edx
    mov dword ptr [edi-6],edx
    sub edi,7
    jmp dword ptr ds:[draw_resume]
L5677BB:
    mov edx,dword ptr [esi]
    mov eax,dword ptr [esi+2]
    or edx,ebx
    or eax,ebx
    bswap eax
    mov byte ptr [edi],dl
    mov byte ptr [edi-1],dh
    mov dword ptr [edi-5],eax
    mov al,byte ptr [esi+6]
    add esi,7
    or eax,ebx
    mov byte ptr [edi-6],al
    sub edi,7
    jmp dword ptr ds:[draw_resume]
L5677E2:
    mov dl,byte ptr [esi]
    mov eax,dword ptr [esi+1]
    or eax,ebx
    or edx,ebx
    bswap eax
    mov byte ptr [edi],dl
    mov dword ptr [edi-4],eax
    mov eax,dword ptr [esi+5]
    add esi,7
    or eax,ebx
    mov byte ptr [edi-5],al
    mov byte ptr [edi-6],ah
    sub edi,7
    jmp dword ptr ds:[draw_resume]
L567809:
    mov eax,dword ptr [esi]
    bswap eax
    or eax,ebx
    add esi,4
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L567809
    jmp dword ptr ds:[draw_resume]
L567823:
    mov al,byte ptr [esi]
    or eax,ebx
    mov byte ptr [edi],al
    inc esi
    dec edi
    dec ecx
L56782C:
    mov eax,dword ptr [esi]
    bswap eax
    or eax,ebx
    add esi,4
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L56782C
    jmp dword ptr ds:[draw_resume]
L567846:
    mov eax,dword ptr [esi]
    or eax,ebx
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    add esi,2
    sub edi,2
    sub ecx,2
L567858:
    mov eax,dword ptr [esi]
    bswap eax
    or eax,ebx
    add esi,4
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L567858
    jmp dword ptr ds:[draw_resume]
L567872:
    mov eax,dword ptr [esi]
    or eax,ebx
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    shr eax,10h
    mov byte ptr [edi-2],al
    add esi,3
    sub edi,3
    sub ecx,3
L56788A:
    mov eax,dword ptr [esi]
    bswap eax
    or eax,ebx
    add esi,4
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L56788A
    jmp dword ptr ds:[draw_resume]
L5678A4:
    dec ecx
L5678A5:
    mov eax,dword ptr [esi]
    bswap eax
    or eax,ebx
    add esi,4
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L5678A5
    mov al,byte ptr [esi]
    or eax,ebx
    mov byte ptr [edi],al
    inc esi
    dec edi
    jmp dword ptr ds:[draw_resume]
L5678C7:
    mov al,byte ptr [esi]
    or eax,ebx
    mov byte ptr [edi],al
    inc esi
    dec edi
    sub ecx,2
L5678D2:
    mov eax,dword ptr [esi]
    bswap eax
    or eax,ebx
    add esi,4
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L5678D2
    mov al,byte ptr [esi]
    or eax,ebx
    mov byte ptr [edi],al
    inc esi
    dec edi
    jmp dword ptr ds:[draw_resume]
L5678F4:
    mov eax,dword ptr [esi]
    or eax,ebx
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    add esi,2
    sub edi,2
    sub ecx,3
L567906:
    mov eax,dword ptr [esi]
    bswap eax
    or eax,ebx
    add esi,4
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L567906
    mov al,byte ptr [esi]
    or eax,ebx
    mov byte ptr [edi],al
    inc esi
    dec edi
    jmp dword ptr ds:[draw_resume]
L567928:
    mov eax,dword ptr [esi]
    or eax,ebx
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    shr eax,10h
    mov byte ptr [edi-2],al
    add esi,3
    sub edi,3
    sub ecx,4
L567940:
    mov eax,dword ptr [esi]
    bswap eax
    or eax,ebx
    add esi,4
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L567940
    mov al,byte ptr [esi]
    or eax,ebx
    mov byte ptr [edi],al
    inc esi
    dec edi
    jmp dword ptr ds:[draw_resume]
L567962:
    sub ecx,2
L567965:
    mov eax,dword ptr [esi]
    bswap eax
    or eax,ebx
    add esi,4
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L567965
    mov eax,dword ptr [esi]
    or eax,ebx
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    add esi,2
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L56798E:
    mov al,byte ptr [esi]
    or eax,ebx
    mov byte ptr [edi],al
    inc esi
    dec edi
    sub ecx,3
L567999:
    mov eax,dword ptr [esi]
    bswap eax
    or eax,ebx
    add esi,4
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L567999
    mov eax,dword ptr [esi]
    or eax,ebx
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    add esi,2
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L5679C2:
    mov eax,dword ptr [esi]
    or eax,ebx
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    add esi,2
    sub edi,2
    sub ecx,4
L5679D4:
    mov eax,dword ptr [esi]
    bswap eax
    or eax,ebx
    add esi,4
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L5679D4
    mov eax,dword ptr [esi]
    or eax,ebx
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    add esi,2
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L5679FD:
    mov eax,dword ptr [esi]
    or eax,ebx
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    shr eax,10h
    mov byte ptr [edi-2],al
    add esi,3
    sub edi,3
    sub ecx,5
L567A15:
    mov eax,dword ptr [esi]
    bswap eax
    or eax,ebx
    add esi,4
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L567A15
    mov eax,dword ptr [esi]
    or eax,ebx
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    add esi,2
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L567A3E:
    sub ecx,3
L567A41:
    mov eax,dword ptr [esi]
    bswap eax
    or eax,ebx
    add esi,4
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L567A41
    mov eax,dword ptr [esi]
    or eax,ebx
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    shr eax,10h
    mov byte ptr [edi-2],al
    add esi,3
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L567A70:
    mov al,byte ptr [esi]
    or eax,ebx
    mov byte ptr [edi],al
    inc esi
    dec edi
    sub ecx,4
L567A7B:
    mov eax,dword ptr [esi]
    bswap eax
    or eax,ebx
    add esi,4
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L567A7B
    mov eax,dword ptr [esi]
    or eax,ebx
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    shr eax,10h
    mov byte ptr [edi-2],al
    add esi,3
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L567AAA:
    mov eax,dword ptr [esi]
    or eax,ebx
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    add esi,2
    sub edi,2
    sub ecx,5
L567ABC:
    mov eax,dword ptr [esi]
    bswap eax
    or eax,ebx
    add esi,4
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L567ABC
    mov eax,dword ptr [esi]
    or eax,ebx
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    shr eax,10h
    mov byte ptr [edi-2],al
    add esi,3
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L567AEB:
    mov eax,dword ptr [esi]
    or eax,ebx
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    shr eax,10h
    mov byte ptr [edi-2],al
    add esi,3
    sub edi,3
    sub ecx,6
L567B03:
    mov eax,dword ptr [esi]
    bswap eax
    or eax,ebx
    add esi,4
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L567B03
    mov eax,dword ptr [esi]
    or eax,ebx
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    shr eax,10h
    mov byte ptr [edi-2],al
    add esi,3
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L567B32:
    mov al,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    inc esi
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],al
    dec edi
    jmp dword ptr ds:[draw_resume]
L567B4A:
    mov ah,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    inc esi
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],ah
    dec edi
    jmp dword ptr ds:[draw_resume]
L567B62:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,2
    or eax,dword ptr ds:[state_88C034]
    xchg al,ah
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L567B82:
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,2
    or eax,dword ptr ds:[state_88C034]
    shr eax,8
    xchg al,ah
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L567BA6:
    mov al,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    inc esi
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],al
    dec edi
    mov ah,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    inc esi
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],ah
    dec edi
    jmp dword ptr ds:[draw_resume]
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,2
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L567BEF:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,3
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    shr eax,10h
    mov byte ptr [edi-2],al
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L567C14:
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,3
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],ah
    shr eax,10h
    mov byte ptr [edi-1],al
    mov byte ptr [edi-2],ah
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L567C3A:
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,2
    or eax,dword ptr ds:[state_88C034]
    shr eax,8
    xchg al,ah
    mov word ptr [edi-1],ax
    sub edi,2
    mov ah,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    inc esi
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],ah
    dec edi
    jmp dword ptr ds:[draw_resume]
L567C70:
    mov al,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    inc esi
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],al
    dec edi
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,2
    or eax,dword ptr ds:[state_88C034]
    shr eax,8
    xchg al,ah
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L567CA6:
    mov eax,dword ptr [esi]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C034]
    add esi,4
    mov dword ptr [edi-3],eax
    sub edi,4
    jmp dword ptr ds:[draw_resume]
L567CC5:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,3
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    shr eax,10h
    mov byte ptr [edi-2],al
    sub edi,3
    mov ah,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    inc esi
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],ah
    dec edi
    jmp dword ptr ds:[draw_resume]
L567CFC:
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,2
    or eax,dword ptr ds:[state_88C034]
    shr eax,8
    xchg al,ah
    mov word ptr [edi-1],ax
    sub edi,2
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,2
    or eax,dword ptr ds:[state_88C034]
    shr eax,8
    xchg al,ah
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L567D3E:
    mov al,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    inc esi
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],al
    dec edi
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,3
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],ah
    shr eax,10h
    mov byte ptr [edi-1],al
    mov byte ptr [edi-2],ah
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L567D76:
    mov eax,dword ptr [esi]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C034]
    add esi,4
    mov dword ptr [edi-3],eax
    sub edi,4
    mov ah,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    inc esi
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],ah
    dec edi
    jmp dword ptr ds:[draw_resume]
L567DA7:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,3
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    shr eax,10h
    mov byte ptr [edi-2],al
    sub edi,3
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,2
    or eax,dword ptr ds:[state_88C034]
    shr eax,8
    xchg al,ah
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L567DEA:
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,2
    or eax,dword ptr ds:[state_88C034]
    shr eax,8
    xchg al,ah
    mov word ptr [edi-1],ax
    sub edi,2
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,3
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],ah
    shr eax,10h
    mov byte ptr [edi-1],al
    mov byte ptr [edi-2],ah
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L567E2E:
    mov al,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    inc esi
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],al
    dec edi
    mov eax,dword ptr [esi]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C034]
    add esi,4
    mov dword ptr [edi-3],eax
    sub edi,4
    jmp dword ptr ds:[draw_resume]
L567E5F:
    mov eax,dword ptr [esi]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C034]
    add esi,4
    mov dword ptr [edi-3],eax
    sub edi,4
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,2
    or eax,dword ptr ds:[state_88C034]
    shr eax,8
    xchg al,ah
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L567E9C:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,3
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    shr eax,10h
    mov byte ptr [edi-2],al
    sub edi,3
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,3
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],ah
    shr eax,10h
    mov byte ptr [edi-1],al
    mov byte ptr [edi-2],ah
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L567EE1:
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,2
    or eax,dword ptr ds:[state_88C034]
    shr eax,8
    xchg al,ah
    mov word ptr [edi-1],ax
    sub edi,2
    mov eax,dword ptr [esi]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C034]
    add esi,4
    mov dword ptr [edi-3],eax
    sub edi,4
    jmp dword ptr ds:[draw_resume]
L567F1E:
    mov al,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    inc esi
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],al
    dec edi
    mov eax,dword ptr [esi]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C034]
    add esi,4
    mov dword ptr [edi-3],eax
    sub edi,4
    mov ah,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    inc esi
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],ah
    dec edi
    jmp dword ptr ds:[draw_resume]
L567F61:
    mov eax,dword ptr [esi]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C034]
    add esi,4
    mov dword ptr [edi-3],eax
    sub edi,4
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,3
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],ah
    shr eax,10h
    mov byte ptr [edi-1],al
    mov byte ptr [edi-2],ah
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L567FA0:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,3
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    shr eax,10h
    mov byte ptr [edi-2],al
    sub edi,3
    mov eax,dword ptr [esi]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C034]
    add esi,4
    mov dword ptr [edi-3],eax
    sub edi,4
    jmp dword ptr ds:[draw_resume]
L567FDE:
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,2
    or eax,dword ptr ds:[state_88C034]
    shr eax,8
    xchg al,ah
    mov word ptr [edi-1],ax
    sub edi,2
    mov eax,dword ptr [esi]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C034]
    add esi,4
    mov dword ptr [edi-3],eax
    sub edi,4
    mov ah,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    inc esi
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],ah
    dec edi
    jmp dword ptr ds:[draw_resume]
L56802D:
    mov al,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    inc esi
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],al
    dec edi
    mov eax,dword ptr [esi]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C034]
    add esi,4
    mov dword ptr [edi-3],eax
    sub edi,4
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,2
    or eax,dword ptr ds:[state_88C034]
    shr eax,8
    xchg al,ah
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L56807C:
    mov eax,dword ptr [esi]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C034]
    add esi,4
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L56807C
    jmp dword ptr ds:[draw_resume]
L5680A0:
    mov al,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    inc esi
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],al
    dec edi
    dec ecx
L5680B3:
    mov eax,dword ptr [esi]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C034]
    add esi,4
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L5680B3
    jmp dword ptr ds:[draw_resume]
L5680D7:
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,2
    or eax,dword ptr ds:[state_88C034]
    shr eax,8
    xchg al,ah
    mov word ptr [edi-1],ax
    sub edi,2
    sub ecx,2
L5680F8:
    mov eax,dword ptr [esi]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C034]
    add esi,4
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L5680F8
    jmp dword ptr ds:[draw_resume]
L56811C:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,3
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    shr eax,10h
    mov byte ptr [edi-2],al
    sub edi,3
    sub ecx,3
L56813E:
    mov eax,dword ptr [esi]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C034]
    add esi,4
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L56813E
    jmp dword ptr ds:[draw_resume]
L568162:
    dec ecx
L568163:
    mov eax,dword ptr [esi]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C034]
    add esi,4
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L568163
    mov ah,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    inc esi
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],ah
    dec edi
    jmp dword ptr ds:[draw_resume]
L568199:
    mov al,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    inc esi
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],al
    dec edi
    sub ecx,2
L5681AE:
    mov eax,dword ptr [esi]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C034]
    add esi,4
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L5681AE
    mov ah,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    inc esi
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],ah
    dec edi
    jmp dword ptr ds:[draw_resume]
L5681E4:
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,2
    or eax,dword ptr ds:[state_88C034]
    shr eax,8
    xchg al,ah
    mov word ptr [edi-1],ax
    sub edi,2
    sub ecx,3
L568205:
    mov eax,dword ptr [esi]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C034]
    add esi,4
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L568205
    mov ah,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    inc esi
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],ah
    dec edi
    jmp dword ptr ds:[draw_resume]
L56823B:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,3
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    shr eax,10h
    mov byte ptr [edi-2],al
    sub edi,3
    sub ecx,4
L56825D:
    mov eax,dword ptr [esi]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C034]
    add esi,4
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L56825D
    mov ah,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    inc esi
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],ah
    dec edi
    jmp dword ptr ds:[draw_resume]
L568293:
    sub ecx,2
L568296:
    mov eax,dword ptr [esi]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C034]
    add esi,4
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L568296
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,2
    or eax,dword ptr ds:[state_88C034]
    shr eax,8
    xchg al,ah
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L5682D8:
    mov al,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    inc esi
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],al
    dec edi
    sub ecx,3
L5682ED:
    mov eax,dword ptr [esi]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C034]
    add esi,4
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L5682ED
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,2
    or eax,dword ptr ds:[state_88C034]
    shr eax,8
    xchg al,ah
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L56832F:
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,2
    or eax,dword ptr ds:[state_88C034]
    shr eax,8
    xchg al,ah
    mov word ptr [edi-1],ax
    sub edi,2
    sub ecx,4
L568350:
    mov eax,dword ptr [esi]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C034]
    add esi,4
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L568350
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,2
    or eax,dword ptr ds:[state_88C034]
    shr eax,8
    xchg al,ah
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L568392:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,3
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    shr eax,10h
    mov byte ptr [edi-2],al
    sub edi,3
    sub ecx,5
L5683B4:
    mov eax,dword ptr [esi]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C034]
    add esi,4
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L5683B4
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,2
    or eax,dword ptr ds:[state_88C034]
    shr eax,8
    xchg al,ah
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L5683F6:
    sub ecx,3
L5683F9:
    mov eax,dword ptr [esi]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C034]
    add esi,4
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L5683F9
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,3
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],ah
    shr eax,10h
    mov byte ptr [edi-1],al
    mov byte ptr [edi-2],ah
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L56843D:
    mov al,byte ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    inc esi
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],al
    dec edi
    sub ecx,4
L568452:
    mov eax,dword ptr [esi]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C034]
    add esi,4
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L568452
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,3
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],ah
    shr eax,10h
    mov byte ptr [edi-1],al
    mov byte ptr [edi-2],ah
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L568496:
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,2
    or eax,dword ptr ds:[state_88C034]
    shr eax,8
    xchg al,ah
    mov word ptr [edi-1],ax
    sub edi,2
    sub ecx,5
L5684B7:
    mov eax,dword ptr [esi]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C034]
    add esi,4
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L5684B7
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,3
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],ah
    shr eax,10h
    mov byte ptr [edi-1],al
    mov byte ptr [edi-2],ah
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L5684FB:
    mov eax,dword ptr [esi]
    and eax,dword ptr ds:[state_88C02C]
    add esi,3
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],al
    mov byte ptr [edi-1],ah
    shr eax,10h
    mov byte ptr [edi-2],al
    sub edi,3
    sub ecx,6
L56851D:
    mov eax,dword ptr [esi]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C034]
    add esi,4
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L56851D
    mov eax,dword ptr [esi-1]
    and eax,dword ptr ds:[state_88C02C]
    add esi,3
    or eax,dword ptr ds:[state_88C034]
    mov byte ptr [edi],ah
    shr eax,10h
    mov byte ptr [edi-1],al
    mov byte ptr [edi-2],ah
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L568561:
    mov byte ptr [edi],al
    dec edi
    jmp dword ptr ds:[draw_resume]
L56856A:
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L568577:
    mov byte ptr [edi],al
    dec edi
    mov byte ptr [edi],al
    dec edi
    jmp dword ptr ds:[draw_resume]
L568583:
    mov word ptr [edi-2],ax
    mov byte ptr [edi],al
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L568592:
    mov byte ptr [edi],al
    dec edi
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L5685A2:
    mov dword ptr [edi-3],eax
    sub edi,4
    jmp dword ptr ds:[draw_resume]
L5685AE:
    mov word ptr [edi-2],ax
    mov byte ptr [edi],al
    sub edi,3
    mov byte ptr [edi],al
    dec edi
    jmp dword ptr ds:[draw_resume]
L5685C0:
    mov word ptr [edi-1],ax
    sub edi,2
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L5685D4:
    mov byte ptr [edi],al
    dec edi
    mov word ptr [edi-2],ax
    mov byte ptr [edi],al
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L5685E6:
    mov dword ptr [edi-3],eax
    sub edi,4
    mov byte ptr [edi],al
    dec edi
    jmp dword ptr ds:[draw_resume]
L5685F5:
    mov word ptr [edi-2],ax
    mov byte ptr [edi],al
    sub edi,3
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L56860B:
    mov word ptr [edi-1],ax
    sub edi,2
    mov word ptr [edi-2],ax
    mov byte ptr [edi],al
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L568621:
    mov byte ptr [edi],al
    dec edi
    mov dword ptr [edi-3],eax
    sub edi,4
    jmp dword ptr ds:[draw_resume]
L568630:
    mov dword ptr [edi-3],eax
    sub edi,4
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L568643:
    mov word ptr [edi-2],ax
    mov byte ptr [edi],al
    sub edi,3
    mov word ptr [edi-2],ax
    mov byte ptr [edi],al
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L56865B:
    mov word ptr [edi-1],ax
    sub edi,2
    mov dword ptr [edi-3],eax
    sub edi,4
    jmp dword ptr ds:[draw_resume]
L56866E:
    mov byte ptr [edi],al
    dec edi
    mov dword ptr [edi-3],eax
    sub edi,4
    mov byte ptr [edi],al
    dec edi
    jmp dword ptr ds:[draw_resume]
L568680:
    mov dword ptr [edi-3],eax
    sub edi,4
    mov word ptr [edi-2],ax
    mov byte ptr [edi],al
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L568695:
    mov word ptr [edi-2],ax
    mov byte ptr [edi],al
    sub edi,3
    mov dword ptr [edi-3],eax
    sub edi,4
    jmp dword ptr ds:[draw_resume]
L5686AA:
    mov word ptr [edi-1],ax
    sub edi,2
    mov dword ptr [edi-3],eax
    sub edi,4
    mov byte ptr [edi],al
    dec edi
    jmp dword ptr ds:[draw_resume]
L5686C0:
    mov byte ptr [edi],al
    dec edi
    mov dword ptr [edi-3],eax
    sub edi,4
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L5686D6:
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L5686D6
    jmp dword ptr ds:[draw_resume]
L5686E7:
    mov byte ptr [edi],al
    dec edi
    dec ecx
L5686EB:
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L5686EB
    jmp dword ptr ds:[draw_resume]
L5686FC:
    mov word ptr [edi-1],ax
    sub edi,2
    sub ecx,2
L568706:
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L568706
    jmp dword ptr ds:[draw_resume]
L568717:
    mov word ptr [edi-2],ax
    mov byte ptr [edi],al
    sub edi,3
    sub ecx,3
L568723:
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L568723
    jmp dword ptr ds:[draw_resume]
L568734:
    dec ecx
L568735:
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L568735
    mov byte ptr [edi],al
    dec edi
    jmp dword ptr ds:[draw_resume]
L568749:
    mov byte ptr [edi],al
    dec edi
    sub ecx,2
L56874F:
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L56874F
    mov byte ptr [edi],al
    dec edi
    jmp dword ptr ds:[draw_resume]
L568763:
    mov word ptr [edi-1],ax
    sub edi,2
    sub ecx,3
L56876D:
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L56876D
    mov byte ptr [edi],al
    dec edi
    jmp dword ptr ds:[draw_resume]
L568781:
    mov word ptr [edi-2],ax
    mov byte ptr [edi],al
    sub edi,3
    sub ecx,4
L56878D:
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L56878D
    mov byte ptr [edi],al
    dec edi
    jmp dword ptr ds:[draw_resume]
L5687A1:
    sub ecx,2
L5687A4:
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L5687A4
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L5687BC:
    mov byte ptr [edi],al
    dec edi
    sub ecx,3
L5687C2:
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L5687C2
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L5687DA:
    mov word ptr [edi-1],ax
    sub edi,2
    sub ecx,4
L5687E4:
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L5687E4
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L5687FC:
    mov word ptr [edi-2],ax
    mov byte ptr [edi],al
    sub edi,3
    sub ecx,5
L568808:
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L568808
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L568820:
    sub ecx,3
L568823:
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L568823
    mov word ptr [edi-2],ax
    mov byte ptr [edi],al
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L56883D:
    mov byte ptr [edi],al
    dec edi
    sub ecx,4
L568843:
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L568843
    mov word ptr [edi-2],ax
    mov byte ptr [edi],al
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L56885D:
    mov word ptr [edi-1],ax
    sub edi,2
    sub ecx,5
L568867:
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L568867
    mov word ptr [edi-2],ax
    mov byte ptr [edi],al
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L568881:
    mov word ptr [edi-2],ax
    mov byte ptr [edi],al
    sub edi,3
    sub ecx,6
L56888D:
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L56888D
    mov word ptr [edi-2],ax
    mov byte ptr [edi],al
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L5688A7:
    mov byte ptr [edi],al
    dec edi
    jmp dword ptr ds:[draw_resume]
L5688B0:
    mov byte ptr [edi],ah
    dec edi
    jmp dword ptr ds:[draw_resume]
L5688B9:
    mov byte ptr [edi-1],ah
    mov byte ptr [edi],al
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L5688C7:
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L5688D4:
    mov byte ptr [edi],al
    dec edi
    mov byte ptr [edi],ah
    dec edi
    jmp dword ptr ds:[draw_resume]
L5688E0:
    mov byte ptr [edi],al
    mov word ptr [edi-2],ax
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L5688EF:
    mov word ptr [edi-1],ax
    mov byte ptr [edi-2],ah
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L5688FF:
    mov word ptr [edi-1],ax
    sub edi,2
    mov byte ptr [edi],ah
    dec edi
    jmp dword ptr ds:[draw_resume]
L56890F:
    mov byte ptr [edi],al
    dec edi
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L56891F:
    mov dword ptr [edi-3],eax
    sub edi,4
    jmp dword ptr ds:[draw_resume]
L56892B:
    mov byte ptr [edi],al
    mov word ptr [edi-2],ax
    sub edi,3
    mov byte ptr [edi],ah
    dec edi
    jmp dword ptr ds:[draw_resume]
L56893D:
    mov word ptr [edi-1],ax
    sub edi,2
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L568951:
    mov byte ptr [edi],al
    dec edi
    mov word ptr [edi-1],ax
    mov byte ptr [edi-2],ah
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L568964:
    mov dword ptr [edi-3],eax
    sub edi,4
    mov byte ptr [edi],ah
    dec edi
    jmp dword ptr ds:[draw_resume]
L568973:
    mov byte ptr [edi],al
    mov word ptr [edi-2],ax
    sub edi,3
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L568989:
    mov word ptr [edi-1],ax
    sub edi,2
    mov word ptr [edi-1],ax
    mov byte ptr [edi-2],ah
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L5689A0:
    mov byte ptr [edi],al
    dec edi
    mov dword ptr [edi-3],eax
    sub edi,4
    jmp dword ptr ds:[draw_resume]
L5689AF:
    mov dword ptr [edi-3],eax
    sub edi,4
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L5689C2:
    mov byte ptr [edi],al
    mov word ptr [edi-2],ax
    sub edi,3
    mov word ptr [edi-1],ax
    mov byte ptr [edi-2],ah
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L5689DB:
    mov word ptr [edi-1],ax
    sub edi,2
    mov dword ptr [edi-3],eax
    sub edi,4
    jmp dword ptr ds:[draw_resume]
L5689EE:
    mov byte ptr [edi],al
    dec edi
    mov dword ptr [edi-3],eax
    sub edi,4
    mov byte ptr [edi],ah
    dec edi
    jmp dword ptr ds:[draw_resume]
L568A00:
    mov dword ptr [edi-3],eax
    sub edi,4
    mov word ptr [edi-1],ax
    mov byte ptr [edi-2],ah
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L568A16:
    mov byte ptr [edi],al
    mov word ptr [edi-2],ax
    sub edi,3
    mov dword ptr [edi-3],eax
    sub edi,4
    jmp dword ptr ds:[draw_resume]
L568A2B:
    mov word ptr [edi-1],ax
    sub edi,2
    mov dword ptr [edi-3],eax
    sub edi,4
    mov byte ptr [edi],ah
    dec edi
    jmp dword ptr ds:[draw_resume]
L568A41:
    mov byte ptr [edi],al
    dec edi
    mov dword ptr [edi-3],eax
    sub edi,4
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L568A57:
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L568A57
    jmp dword ptr ds:[draw_resume]
L568A68:
    mov byte ptr [edi],al
    dec edi
    dec ecx
L568A6C:
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L568A6C
    jmp dword ptr ds:[draw_resume]
L568A7D:
    mov word ptr [edi-1],ax
    sub edi,2
    sub ecx,2
L568A87:
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L568A87
    jmp dword ptr ds:[draw_resume]
L568A98:
    mov byte ptr [edi],al
    mov word ptr [edi-2],ax
    sub edi,3
    sub ecx,3
L568AA4:
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L568AA4
    jmp dword ptr ds:[draw_resume]
L568AB5:
    dec ecx
L568AB6:
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L568AB6
    mov byte ptr [edi],ah
    dec edi
    jmp dword ptr ds:[draw_resume]
L568ACA:
    mov byte ptr [edi],al
    dec edi
    sub ecx,2
L568AD0:
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L568AD0
    mov byte ptr [edi],ah
    dec edi
    jmp dword ptr ds:[draw_resume]
L568AE4:
    mov word ptr [edi-1],ax
    sub edi,2
    sub ecx,3
L568AEE:
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L568AEE
    mov byte ptr [edi],ah
    dec edi
    jmp dword ptr ds:[draw_resume]
L568B02:
    mov byte ptr [edi],al
    mov word ptr [edi-2],ax
    sub edi,3
    sub ecx,4
L568B0E:
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L568B0E
    mov byte ptr [edi],ah
    dec edi
    jmp dword ptr ds:[draw_resume]
L568B22:
    sub ecx,2
L568B25:
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L568B25
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L568B3D:
    mov byte ptr [edi],al
    dec edi
    sub ecx,3
L568B43:
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L568B43
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L568B5B:
    mov word ptr [edi-1],ax
    sub edi,2
    sub ecx,4
L568B65:
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L568B65
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L568B7D:
    mov byte ptr [edi],al
    mov word ptr [edi-2],ax
    sub edi,3
    sub ecx,5
L568B89:
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L568B89
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L568BA1:
    sub ecx,3
L568BA4:
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L568BA4
    mov word ptr [edi-1],ax
    mov byte ptr [edi-2],ah
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L568BBF:
    mov byte ptr [edi],al
    dec edi
    sub ecx,4
L568BC5:
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L568BC5
    mov word ptr [edi-1],ax
    mov byte ptr [edi-2],ah
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L568BE0:
    mov word ptr [edi-1],ax
    sub edi,2
    sub ecx,5
L568BEA:
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L568BEA
    mov word ptr [edi-1],ax
    mov byte ptr [edi-2],ah
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L568C05:
    mov byte ptr [edi],al
    mov word ptr [edi-2],ax
    sub edi,3
    sub ecx,6
L568C11:
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L568C11
    mov word ptr [edi-1],ax
    mov byte ptr [edi-2],ah
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L568C2C:
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    mov byte ptr [edi],al
    dec edi
    jmp dword ptr ds:[draw_resume]
L568C3A:
    mov ax,word ptr [edi-1]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L568C55:
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    mov byte ptr [edi],al
    dec edi
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    mov byte ptr [edi],al
    dec edi
    jmp dword ptr ds:[draw_resume]
L568C6B:
    mov eax,dword ptr [edi-2]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-2],eax
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L568C8D:
    mov eax,dword ptr [edi-3]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L568CAF:
    mov ax,word ptr [edi-1]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov word ptr [edi-1],ax
    sub edi,2
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    mov byte ptr [edi],al
    dec edi
    jmp dword ptr ds:[draw_resume]
L568CD2:
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    mov byte ptr [edi],al
    dec edi
    mov ax,word ptr [edi-1]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L568CF5:
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,4
    jmp dword ptr ds:[draw_resume]
L568D1C:
    mov eax,dword ptr [edi-2]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-2],eax
    sub edi,3
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    mov byte ptr [edi],al
    dec edi
    jmp dword ptr ds:[draw_resume]
L568D46:
    mov ax,word ptr [edi-1]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov word ptr [edi-1],ax
    sub edi,2
    mov ax,word ptr [edi-1]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L568D76:
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    mov byte ptr [edi],al
    dec edi
    mov eax,dword ptr [edi-3]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L568DA0:
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,4
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    mov byte ptr [edi],al
    dec edi
    jmp dword ptr ds:[draw_resume]
L568DCF:
    mov eax,dword ptr [edi-2]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-2],eax
    sub edi,3
    mov ax,word ptr [edi-1]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L568E06:
    mov ax,word ptr [edi-1]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov word ptr [edi-1],ax
    sub edi,2
    mov eax,dword ptr [edi-3]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L568E3D:
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    mov byte ptr [edi],al
    dec edi
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,4
    jmp dword ptr ds:[draw_resume]
L568E6C:
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,4
    mov ax,word ptr [edi-1]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L568EA8:
    mov eax,dword ptr [edi-2]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-2],eax
    sub edi,3
    mov eax,dword ptr [edi-3]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L568EE6:
    mov ax,word ptr [edi-1]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov word ptr [edi-1],ax
    sub edi,2
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,4
    jmp dword ptr ds:[draw_resume]
L568F22:
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    mov byte ptr [edi],al
    dec edi
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,4
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    mov byte ptr [edi],al
    dec edi
    jmp dword ptr ds:[draw_resume]
L568F59:
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,4
    mov eax,dword ptr [edi-3]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L568F9C:
    mov eax,dword ptr [edi-2]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-2],eax
    sub edi,3
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,4
    jmp dword ptr ds:[draw_resume]
L568FDF:
    mov ax,word ptr [edi-1]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov word ptr [edi-1],ax
    sub edi,2
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,4
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    mov byte ptr [edi],al
    dec edi
    jmp dword ptr ds:[draw_resume]
L569023:
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    mov byte ptr [edi],al
    dec edi
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,4
    mov ax,word ptr [edi-1]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L569067:
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L569067
    jmp dword ptr ds:[draw_resume]
L569093:
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    mov byte ptr [edi],al
    dec edi
    dec ecx
L56909C:
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L56909C
    jmp dword ptr ds:[draw_resume]
L5690C8:
    mov ax,word ptr [edi-1]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov word ptr [edi-1],ax
    sub edi,2
    sub ecx,2
L5690E0:
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L5690E0
    jmp dword ptr ds:[draw_resume]
L56910C:
    mov eax,dword ptr [edi-2]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-2],eax
    sub edi,3
    sub ecx,3
L56912B:
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L56912B
    jmp dword ptr ds:[draw_resume]
L569157:
    dec ecx
L569158:
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L569158
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    mov byte ptr [edi],al
    dec edi
    jmp dword ptr ds:[draw_resume]
L56918C:
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    mov byte ptr [edi],al
    dec edi
    sub ecx,2
L569197:
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L569197
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    mov byte ptr [edi],al
    dec edi
    jmp dword ptr ds:[draw_resume]
L5691CB:
    mov ax,word ptr [edi-1]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov word ptr [edi-1],ax
    sub edi,2
    sub ecx,3
L5691E3:
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L5691E3
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    mov byte ptr [edi],al
    dec edi
    jmp dword ptr ds:[draw_resume]
L569217:
    mov eax,dword ptr [edi-2]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-2],eax
    sub edi,3
    sub ecx,4
L569236:
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L569236
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    mov byte ptr [edi],al
    dec edi
    jmp dword ptr ds:[draw_resume]
L56926A:
    sub ecx,2
L56926D:
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L56926D
    mov ax,word ptr [edi-1]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L5692AE:
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    mov byte ptr [edi],al
    dec edi
    sub ecx,3
L5692B9:
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L5692B9
    mov ax,word ptr [edi-1]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L5692FA:
    mov ax,word ptr [edi-1]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov word ptr [edi-1],ax
    sub edi,2
    sub ecx,4
L569312:
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L569312
    mov ax,word ptr [edi-1]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L569353:
    mov eax,dword ptr [edi-2]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-2],eax
    sub edi,3
    sub ecx,5
L569372:
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L569372
    mov ax,word ptr [edi-1]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L5693B3:
    sub ecx,3
L5693B6:
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L5693B6
    mov eax,dword ptr [edi-3]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L5693FE:
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    mov byte ptr [edi],al
    dec edi
    sub ecx,4
L569409:
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L569409
    mov eax,dword ptr [edi-3]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L569451:
    mov ax,word ptr [edi-1]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov word ptr [edi-1],ax
    sub edi,2
    sub ecx,5
L569469:
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L569469
    mov eax,dword ptr [edi-3]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L5694B1:
    mov eax,dword ptr [edi-2]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-2],eax
    sub edi,3
    sub ecx,6
L5694D0:
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L5694D0
    mov eax,dword ptr [edi-3]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    bswap eax
    mov dword ptr [edi-3],eax
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L569518:
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],al
    dec edi
    jmp dword ptr ds:[draw_resume]
L569532:
    mov dl,byte ptr [edi]
    mov ah,byte ptr [edx+ebx]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    dec edi
    jmp dword ptr ds:[draw_resume]
L56954C:
    mov ax,word ptr [edi-1]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    shl eax,8
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    shr eax,8
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L569579:
    mov ax,word ptr [edi-1]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L5695A0:
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],al
    dec edi
    mov dl,byte ptr [edi]
    mov ah,byte ptr [edx+ebx]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    dec edi
    jmp dword ptr ds:[draw_resume]
L5695CE:
    mov eax,dword ptr [edi-2]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    bswap eax
    mov al,dl
    bswap eax
    mov dword ptr [edi-2],eax
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L569604:
    mov eax,dword ptr [edi-3]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov al,dl
    mov dword ptr [edi-3],eax
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L569636:
    mov ax,word ptr [edi-1]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi-1],ax
    sub edi,2
    mov dl,byte ptr [edi]
    mov ah,byte ptr [edx+ebx]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    dec edi
    jmp dword ptr ds:[draw_resume]
L569671:
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],al
    dec edi
    mov ax,word ptr [edi-1]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L5696AC:
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-3],eax
    sub edi,4
    jmp dword ptr ds:[draw_resume]
L5696DF:
    mov eax,dword ptr [edi-2]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    bswap eax
    mov al,dl
    bswap eax
    mov dword ptr [edi-2],eax
    sub edi,3
    mov dl,byte ptr [edi]
    mov ah,byte ptr [edx+ebx]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    dec edi
    jmp dword ptr ds:[draw_resume]
L569729:
    mov ax,word ptr [edi-1]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi-1],ax
    sub edi,2
    mov ax,word ptr [edi-1]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L569771:
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],al
    dec edi
    mov eax,dword ptr [edi-3]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov al,dl
    mov dword ptr [edi-3],eax
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L5697B7:
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-3],eax
    sub edi,4
    mov dl,byte ptr [edi]
    mov ah,byte ptr [edx+ebx]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    dec edi
    jmp dword ptr ds:[draw_resume]
L5697FE:
    mov eax,dword ptr [edi-2]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    bswap eax
    mov al,dl
    bswap eax
    mov dword ptr [edi-2],eax
    sub edi,3
    mov ax,word ptr [edi-1]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L569855:
    mov ax,word ptr [edi-1]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi-1],ax
    sub edi,2
    mov eax,dword ptr [edi-3]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov al,dl
    mov dword ptr [edi-3],eax
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L5698A8:
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],al
    dec edi
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-3],eax
    sub edi,4
    jmp dword ptr ds:[draw_resume]
L5698EF:
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-3],eax
    sub edi,4
    mov ax,word ptr [edi-1]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L569943:
    mov eax,dword ptr [edi-2]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    bswap eax
    mov al,dl
    bswap eax
    mov dword ptr [edi-2],eax
    sub edi,3
    mov eax,dword ptr [edi-3]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov al,dl
    mov dword ptr [edi-3],eax
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L5699A5:
    mov ax,word ptr [edi-1]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi-1],ax
    sub edi,2
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-3],eax
    sub edi,4
    jmp dword ptr ds:[draw_resume]
L5699F9:
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],al
    dec edi
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-3],eax
    sub edi,4
    mov dl,byte ptr [edi]
    mov ah,byte ptr [edx+ebx]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    dec edi
    jmp dword ptr ds:[draw_resume]
L569A54:
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-3],eax
    sub edi,4
    mov eax,dword ptr [edi-3]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov al,dl
    mov dword ptr [edi-3],eax
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L569AB3:
    mov eax,dword ptr [edi-2]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    bswap eax
    mov al,dl
    bswap eax
    mov dword ptr [edi-2],eax
    sub edi,3
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-3],eax
    sub edi,4
    jmp dword ptr ds:[draw_resume]
L569B16:
    mov ax,word ptr [edi-1]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi-1],ax
    sub edi,2
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-3],eax
    sub edi,4
    mov dl,byte ptr [edi]
    mov ah,byte ptr [edx+ebx]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    dec edi
    jmp dword ptr ds:[draw_resume]
L569B7E:
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],al
    dec edi
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-3],eax
    sub edi,4
    mov ax,word ptr [edi-1]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L569BE6:
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L569BE6
    jmp dword ptr ds:[draw_resume]
L569C1E:
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],al
    dec edi
    dec ecx
L569C33:
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L569C33
    jmp dword ptr ds:[draw_resume]
L569C6B:
    mov ax,word ptr [edi-1]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi-1],ax
    sub edi,2
    sub ecx,2
L569C8F:
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L569C8F
    jmp dword ptr ds:[draw_resume]
L569CC7:
    mov eax,dword ptr [edi-2]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    bswap eax
    mov al,dl
    bswap eax
    mov dword ptr [edi-2],eax
    sub edi,3
    sub ecx,3
L569CFA:
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L569CFA
    jmp dword ptr ds:[draw_resume]
L569D32:
    dec ecx
L569D33:
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L569D33
    mov dl,byte ptr [edi]
    mov ah,byte ptr [edx+ebx]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    dec edi
    jmp dword ptr ds:[draw_resume]
L569D7F:
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],al
    dec edi
    sub ecx,2
L569D96:
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L569D96
    mov dl,byte ptr [edi]
    mov ah,byte ptr [edx+ebx]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    dec edi
    jmp dword ptr ds:[draw_resume]
L569DE2:
    mov ax,word ptr [edi-1]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi-1],ax
    sub edi,2
    sub ecx,3
L569E06:
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L569E06
    mov dl,byte ptr [edi]
    mov ah,byte ptr [edx+ebx]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    dec edi
    jmp dword ptr ds:[draw_resume]
L569E52:
    mov eax,dword ptr [edi-2]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    bswap eax
    mov al,dl
    bswap eax
    mov dword ptr [edi-2],eax
    sub edi,3
    sub ecx,4
L569E85:
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L569E85
    mov dl,byte ptr [edi]
    mov ah,byte ptr [edx+ebx]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],ah
    dec edi
    jmp dword ptr ds:[draw_resume]
L569ED1:
    sub ecx,2
L569ED4:
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L569ED4
    mov ax,word ptr [edi-1]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L569F2D:
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],al
    dec edi
    sub ecx,3
L569F44:
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L569F44
    mov ax,word ptr [edi-1]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L569F9D:
    mov ax,word ptr [edi-1]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi-1],ax
    sub edi,2
    sub ecx,4
L569FC1:
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L569FC1
    mov ax,word ptr [edi-1]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L56A01A:
    mov eax,dword ptr [edi-2]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    bswap eax
    mov al,dl
    bswap eax
    mov dword ptr [edi-2],eax
    sub edi,3
    sub ecx,5
L56A04D:
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L56A04D
    mov ax,word ptr [edi-1]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi-1],ax
    sub edi,2
    jmp dword ptr ds:[draw_resume]
L56A0A6:
    sub ecx,3
L56A0A9:
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L56A0A9
    mov eax,dword ptr [edi-3]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov al,dl
    mov dword ptr [edi-3],eax
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L56A10D:
    mov dl,byte ptr [edi]
    mov al,byte ptr [edx+ebx]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov byte ptr [edi],al
    dec edi
    sub ecx,4
L56A124:
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L56A124
    mov eax,dword ptr [edi-3]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov al,dl
    mov dword ptr [edi-3],eax
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L56A188:
    mov ax,word ptr [edi-1]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov word ptr [edi-1],ax
    sub edi,2
    sub ecx,5
L56A1AC:
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L56A1AC
    mov eax,dword ptr [edi-3]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov al,dl
    mov dword ptr [edi-3],eax
    sub edi,3
    jmp dword ptr ds:[draw_resume]
L56A210:
    mov eax,dword ptr [edi-2]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    bswap eax
    mov al,dl
    bswap eax
    mov dword ptr [edi-2],eax
    sub edi,3
    sub ecx,6
L56A243:
    mov eax,dword ptr [edi-3]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    mov al,byte ptr [edx+ebx]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov dword ptr [edi-3],eax
    sub edi,4
    sub ecx,4
    ja SHORT L56A243
    mov eax,dword ptr [edi-3]
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    bswap eax
    mov dl,ah
    mov ah,byte ptr [edx+ebx]
    mov dl,al
    mov al,byte ptr [edx+ebx]
    bswap eax
    mov dl,al
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    mov al,dl
    mov dword ptr [edi-3],eax
    sub edi,3
    jmp dword ptr ds:[draw_resume]
    CODE_FILL 89 ; ALIGN 128

; Codelet dispatch tables, indexed by span length and destination alignment.
plain_copy_table         DWORD draw_done, draw_done, draw_done, draw_done
                         DWORD copy_1, copy_1, copy_1, copy_1
                         DWORD copy_2, copy_2, copy_2, copy_2_cross
                         DWORD copy_3, copy_3, copy_3, copy_3_cross
                         DWORD copy_4_0, copy_4_1, copy_4_2, copy_4_3
                         DWORD copy_5_0, copy_5_middle, copy_5_middle, copy_5_3
                         DWORD copy_6_0, copy_6_1, copy_6_2, copy_6_3
                         DWORD copy_7_0, copy_7_1, copy_7_2, copy_7_3
                         DWORD copy_long_0_0, copy_long_3_1, copy_long_2_2, copy_long_1_3
                         DWORD copy_long_0_1, copy_long_3_2, copy_long_2_3, copy_long_1_0
                         DWORD copy_long_0_2, copy_long_3_3, copy_long_2_0, copy_long_1_1
                         DWORD copy_long_0_3, copy_long_3_0, copy_long_2_1, copy_long_1_2
                         DWORD copy_long_0_0, copy_long_3_1, copy_long_2_2, copy_long_1_3
                         DWORD copy_long_0_1, copy_long_3_2, copy_long_2_3, copy_long_1_0
                         DWORD copy_long_0_2, copy_long_3_3, copy_long_2_0, copy_long_1_1
                         DWORD copy_long_0_3, copy_long_3_0, copy_long_2_1, copy_long_1_2
                         DWORD copy_long_0_0, copy_long_3_1, copy_long_2_2, copy_long_1_3
                         DWORD copy_long_0_1, copy_long_3_2, copy_long_2_3, copy_long_1_0
                         DWORD copy_long_0_2, copy_long_3_3, copy_long_2_0, copy_long_1_1
                         DWORD copy_long_0_3, copy_long_3_0, copy_long_2_1, copy_long_1_2
                         DWORD copy_long_0_0, copy_long_3_1, copy_long_2_2, copy_long_1_3
                         DWORD copy_long_0_1, copy_long_3_2, copy_long_2_3, copy_long_1_0
                         DWORD copy_long_0_2, copy_long_3_3, copy_long_2_0, copy_long_1_1
                         DWORD copy_long_0_3, copy_long_3_0, copy_long_2_1, copy_long_1_2
                         DWORD copy_long_0_0, copy_long_3_1, copy_long_2_2, copy_long_1_3
                         DWORD copy_long_0_1, copy_long_3_2, copy_long_2_3, copy_long_1_0
                         DWORD copy_long_0_2, copy_long_3_3, copy_long_2_0, copy_long_1_1
                         DWORD copy_long_0_3, copy_long_3_0, copy_long_2_1, copy_long_1_2
                         DWORD copy_long_0_0, copy_long_3_1, copy_long_2_2, copy_long_1_3
                         DWORD copy_long_0_1, copy_long_3_2, copy_long_2_3, copy_long_1_0
                         DWORD copy_long_0_2, copy_long_3_3, copy_long_2_0, copy_long_1_1
                         DWORD copy_long_0_3, copy_long_3_0, copy_long_2_1, copy_long_1_2
                         DWORD draw_done, draw_done, draw_done, draw_done
                         DWORD L563483, L56349B, L563483, L56349B
                         DWORD L5634B3, L5634D0, L5634B3, L5634F1
                         DWORD L563514, L563537, L56355B, L56358A
                         DWORD L5635B9, L5635D6, L56360C, L563640
                         DWORD L563675, L5636A4, L5636DF, L563719
                         DWORD L563748, L56377C, L5637BD, L5637F1
                         DWORD L563832, L56386C, L5638A7, L5638ED
                         DWORD L563933, L563ACE, L563BAA, L563C96
                         DWORD L563A05, L563BFC, L563CE9, L563954
                         DWORD L563B22, L563D41, L563988, L563A39
                         DWORD L563C55, L5639C3, L563A81, L563B5D
                         DWORD L563933, L563ACE, L563BAA, L563C96
                         DWORD L563A05, L563BFC, L563CE9, L563954
                         DWORD L563B22, L563D41, L563988, L563A39
                         DWORD L563C55, L5639C3, L563A81, L563B5D
                         DWORD L563933, L563ACE, L563BAA, L563C96
                         DWORD L563A05, L563BFC, L563CE9, L563954
                         DWORD L563B22, L563D41, L563988, L563A39
                         DWORD L563C55, L5639C3, L563A81, L563B5D
                         DWORD L563933, L563ACE, L563BAA, L563C96
                         DWORD L563A05, L563BFC, L563CE9, L563954
                         DWORD L563B22, L563D41, L563988, L563A39
                         DWORD L563C55, L5639C3, L563A81, L563B5D
                         DWORD L563933, L563ACE, L563BAA, L563C96
                         DWORD L563A05, L563BFC, L563CE9, L563954
                         DWORD L563B22, L563D41, L563988, L563A39
                         DWORD L563C55, L5639C3, L563A81, L563B5D
                         DWORD L563933, L563ACE, L563BAA, L563C96
                         DWORD L563A05, L563BFC, L563CE9, L563954
                         DWORD L563B22, L563D41, L563988, L563A39
                         DWORD L563C55, L5639C3, L563A81, L563B5D
solid_fill_table         DWORD draw_done, draw_done, draw_done, draw_done
                         DWORD solid_1, solid_1, solid_1, solid_1
                         DWORD solid_2, solid_2, solid_2, solid_2_cross
                         DWORD solid_3, solid_3, solid_3, solid_3_cross
                         DWORD solid_4_0, solid_4_1, solid_4_2, solid_4_3
                         DWORD solid_5_0, solid_5_1, solid_5_2, solid_5_3
                         DWORD solid_6_0, solid_6_1, solid_6_2, solid_6_3
                         DWORD solid_7_0, solid_7_1, solid_7_2, solid_7_3
                         DWORD solid_long_0_0, solid_long_3_1, solid_long_2_2, solid_long_1_3
                         DWORD solid_long_0_1, solid_long_3_2, solid_long_2_3, solid_long_1_0
                         DWORD solid_long_0_2, solid_long_3_3, solid_long_2_0, solid_long_1_1
                         DWORD solid_long_0_3, solid_long_3_0, solid_long_2_1, solid_long_1_2
                         DWORD solid_long_0_0, solid_long_3_1, solid_long_2_2, solid_long_1_3
                         DWORD solid_long_0_1, solid_long_3_2, solid_long_2_3, solid_long_1_0
                         DWORD solid_long_0_2, solid_long_3_3, solid_long_2_0, solid_long_1_1
                         DWORD solid_long_0_3, solid_long_3_0, solid_long_2_1, solid_long_1_2
                         DWORD solid_long_0_0, solid_long_3_1, solid_long_2_2, solid_long_1_3
                         DWORD solid_long_0_1, solid_long_3_2, solid_long_2_3, solid_long_1_0
                         DWORD solid_long_0_2, solid_long_3_3, solid_long_2_0, solid_long_1_1
                         DWORD solid_long_0_3, solid_long_3_0, solid_long_2_1, solid_long_1_2
                         DWORD solid_long_0_0, solid_long_3_1, solid_long_2_2, solid_long_1_3
                         DWORD solid_long_0_1, solid_long_3_2, solid_long_2_3, solid_long_1_0
                         DWORD solid_long_0_2, solid_long_3_3, solid_long_2_0, solid_long_1_1
                         DWORD solid_long_0_3, solid_long_3_0, solid_long_2_1, solid_long_1_2
                         DWORD solid_long_0_0, solid_long_3_1, solid_long_2_2, solid_long_1_3
                         DWORD solid_long_0_1, solid_long_3_2, solid_long_2_3, solid_long_1_0
                         DWORD solid_long_0_2, solid_long_3_3, solid_long_2_0, solid_long_1_1
                         DWORD solid_long_0_3, solid_long_3_0, solid_long_2_1, solid_long_1_2
                         DWORD solid_long_0_0, solid_long_3_1, solid_long_2_2, solid_long_1_3
                         DWORD solid_long_0_1, solid_long_3_2, solid_long_2_3, solid_long_1_0
                         DWORD solid_long_0_2, solid_long_3_3, solid_long_2_0, solid_long_1_1
                         DWORD solid_long_0_3, solid_long_3_0, solid_long_2_1, solid_long_1_2
pattern_fill_table       DWORD draw_done, draw_done, draw_done, draw_done
                         DWORD pattern_1_even, pattern_1_odd, pattern_1_even, pattern_1_odd
                         DWORD pattern_2_even, pattern_2_odd, pattern_2_even, pattern_2_odd
                         DWORD pattern_3_0, pattern_3_1, pattern_3_2, pattern_3_3
                         DWORD pattern_4_0, pattern_4_1, pattern_4_2, pattern_4_3
                         DWORD pattern_5_0, pattern_5_1, pattern_5_2, pattern_5_3
                         DWORD pattern_6_0, pattern_6_1, pattern_6_2, pattern_6_3
                         DWORD pattern_7_0, pattern_7_1, pattern_7_2, pattern_7_3
                         DWORD pattern_long_0_0, pattern_long_3_1, pattern_long_2_2, pattern_long_1_3
                         DWORD pattern_long_0_1, pattern_long_3_2, pattern_long_2_3, pattern_long_1_0
                         DWORD pattern_long_0_2, pattern_long_3_3, pattern_long_2_0, pattern_long_1_1
                         DWORD pattern_long_0_3, pattern_long_3_0, pattern_long_2_1, pattern_long_1_2
                         DWORD pattern_long_0_0, pattern_long_3_1, pattern_long_2_2, pattern_long_1_3
                         DWORD pattern_long_0_1, pattern_long_3_2, pattern_long_2_3, pattern_long_1_0
                         DWORD pattern_long_0_2, pattern_long_3_3, pattern_long_2_0, pattern_long_1_1
                         DWORD pattern_long_0_3, pattern_long_3_0, pattern_long_2_1, pattern_long_1_2
                         DWORD pattern_long_0_0, pattern_long_3_1, pattern_long_2_2, pattern_long_1_3
                         DWORD pattern_long_0_1, pattern_long_3_2, pattern_long_2_3, pattern_long_1_0
                         DWORD pattern_long_0_2, pattern_long_3_3, pattern_long_2_0, pattern_long_1_1
                         DWORD pattern_long_0_3, pattern_long_3_0, pattern_long_2_1, pattern_long_1_2
                         DWORD pattern_long_0_0, pattern_long_3_1, pattern_long_2_2, pattern_long_1_3
                         DWORD pattern_long_0_1, pattern_long_3_2, pattern_long_2_3, pattern_long_1_0
                         DWORD pattern_long_0_2, pattern_long_3_3, pattern_long_2_0, pattern_long_1_1
                         DWORD pattern_long_0_3, pattern_long_3_0, pattern_long_2_1, pattern_long_1_2
                         DWORD pattern_long_0_0, pattern_long_3_1, pattern_long_2_2, pattern_long_1_3
                         DWORD pattern_long_0_1, pattern_long_3_2, pattern_long_2_3, pattern_long_1_0
                         DWORD pattern_long_0_2, pattern_long_3_3, pattern_long_2_0, pattern_long_1_1
                         DWORD pattern_long_0_3, pattern_long_3_0, pattern_long_2_1, pattern_long_1_2
                         DWORD pattern_long_0_0, pattern_long_3_1, pattern_long_2_2, pattern_long_1_3
                         DWORD pattern_long_0_1, pattern_long_3_2, pattern_long_2_3, pattern_long_1_0
                         DWORD pattern_long_0_2, pattern_long_3_3, pattern_long_2_0, pattern_long_1_1
                         DWORD pattern_long_0_3, pattern_long_3_0, pattern_long_2_1, pattern_long_1_2
L56AB00                  DWORD draw_done, draw_done, draw_done, draw_done
                         DWORD L5643FD, L5643FD, L5643FD, L5643FD
                         DWORD L56440B, L56440B, L56440B, L56441E
                         DWORD L564433, L564433, L564433, L56444C
                         DWORD L564465, L564477, L564477, L564477
                         DWORD L564495, L5644AF, L5644AF, L5644D1
                         DWORD L5644EB, L564506, L56452B, L564546
                         DWORD L564566, L564587, L5645A8, L5645CB
                         DWORD L5645EE, L5646F4, L564781, L56481F
                         DWORD L56467A, L5647B7, L564854, L564605
                         DWORD L564729, L56488F, L564625, L56469A
                         DWORD L5647F2, L56464D, L5646C4, L564751
                         DWORD L5645EE, L5646F4, L564781, L56481F
                         DWORD L56467A, L5647B7, L564854, L564605
                         DWORD L564729, L56488F, L564625, L56469A
                         DWORD L5647F2, L56464D, L5646C4, L564751
                         DWORD L5645EE, L5646F4, L564781, L56481F
                         DWORD L56467A, L5647B7, L564854, L564605
                         DWORD L564729, L56488F, L564625, L56469A
                         DWORD L5647F2, L56464D, L5646C4, L564751
                         DWORD L5645EE, L5646F4, L564781, L56481F
                         DWORD L56467A, L5647B7, L564854, L564605
                         DWORD L564729, L56488F, L564625, L56469A
                         DWORD L5647F2, L56464D, L5646C4, L564751
                         DWORD L5645EE, L5646F4, L564781, L56481F
                         DWORD L56467A, L5647B7, L564854, L564605
                         DWORD L564729, L56488F, L564625, L56469A
                         DWORD L5647F2, L56464D, L5646C4, L564751
                         DWORD L5645EE, L5646F4, L564781, L56481F
                         DWORD L56467A, L5647B7, L564854, L564605
                         DWORD L564729, L56488F, L564625, L56469A
                         DWORD L5647F2, L56464D, L5646C4, L564751
                         DWORD draw_done, draw_done, draw_done, draw_done
                         DWORD L5648CF, L5648E7, L5648CF, L5648E7
                         DWORD L5648FF, L56491C, L5648FF, L56491C
                         DWORD L56493D, L564960, L564984, L5649B3
                         DWORD L5649E2, L5649FE, L564A34, L564A68
                         DWORD L564A9D, L564ACB, L564B06, L564B40
                         DWORD L564B6E, L564BA1, L564BE2, L564C15
                         DWORD L564C55, L564C8E, L564CC8, L564D0D
                         DWORD L564D52, L564EED, L564FC9, L5650B5
                         DWORD L564E24, L56501B, L565108, L564D73
                         DWORD L564F41, L565160, L564DA7, L564E58
                         DWORD L565074, L564DE2, L564EA0, L564F7C
                         DWORD L564D52, L564EED, L564FC9, L5650B5
                         DWORD L564E24, L56501B, L565108, L564D73
                         DWORD L564F41, L565160, L564DA7, L564E58
                         DWORD L565074, L564DE2, L564EA0, L564F7C
                         DWORD L564D52, L564EED, L564FC9, L5650B5
                         DWORD L564E24, L56501B, L565108, L564D73
                         DWORD L564F41, L565160, L564DA7, L564E58
                         DWORD L565074, L564DE2, L564EA0, L564F7C
                         DWORD L564D52, L564EED, L564FC9, L5650B5
                         DWORD L564E24, L56501B, L565108, L564D73
                         DWORD L564F41, L565160, L564DA7, L564E58
                         DWORD L565074, L564DE2, L564EA0, L564F7C
                         DWORD L564D52, L564EED, L564FC9, L5650B5
                         DWORD L564E24, L56501B, L565108, L564D73
                         DWORD L564F41, L565160, L564DA7, L564E58
                         DWORD L565074, L564DE2, L564EA0, L564F7C
                         DWORD L564D52, L564EED, L564FC9, L5650B5
                         DWORD L564E24, L56501B, L565108, L564D73
                         DWORD L564F41, L565160, L564DA7, L564E58
                         DWORD L565074, L564DE2, L564EA0, L564F7C
L56AF00                  DWORD draw_done, draw_done, draw_done, draw_done
                         DWORD L5651BF, L5651BF, L5651BF, L5651BF
                         DWORD L5651CD, L5651CD, L5651CD, L5651E6
                         DWORD L5651FC, L56521C, L56523E, L56525F
                         DWORD L565280, L5652A5, L5652CF, L5652FB
                         DWORD L565323, L565350, L565385, L5653B8
                         DWORD L5653E5, L56541D, L565459, L565491
                         DWORD L5654C6, L565505, L565546, L565586
                         DWORD L5655C6, L565764, L56583D, L565933
                         DWORD L5656AC, L565890, L565982, L5655F0
                         DWORD L5657B5, L5659DC, L565623, L5656DF
                         DWORD L5658EC, L565663, L56571C, L5657F5
                         DWORD L5655C6, L565764, L56583D, L565933
                         DWORD L5656AC, L565890, L565982, L5655F0
                         DWORD L5657B5, L5659DC, L565623, L5656DF
                         DWORD L5658EC, L565663, L56571C, L5657F5
                         DWORD L5655C6, L565764, L56583D, L565933
                         DWORD L5656AC, L565890, L565982, L5655F0
                         DWORD L5657B5, L5659DC, L565623, L5656DF
                         DWORD L5658EC, L565663, L56571C, L5657F5
                         DWORD L5655C6, L565764, L56583D, L565933
                         DWORD L5656AC, L565890, L565982, L5655F0
                         DWORD L5657B5, L5659DC, L565623, L5656DF
                         DWORD L5658EC, L565663, L56571C, L5657F5
                         DWORD L5655C6, L565764, L56583D, L565933
                         DWORD L5656AC, L565890, L565982, L5655F0
                         DWORD L5657B5, L5659DC, L565623, L5656DF
                         DWORD L5658EC, L565663, L56571C, L5657F5
                         DWORD L5655C6, L565764, L56583D, L565933
                         DWORD L5656AC, L565890, L565982, L5655F0
                         DWORD L5657B5, L5659DC, L565623, L5656DF
                         DWORD L5658EC, L565663, L56571C, L5657F5
                         DWORD draw_done, draw_done, draw_done, draw_done
                         DWORD L565A3F, L565A59, L565A3F, L565A59
                         DWORD L565A73, L565A98, L565A73, L565A98
                         DWORD L565AC3, L565AF7, L565B29, L565B62
                         DWORD L565B9B, L565BCC, L565C12, L565C56
                         DWORD L565C9E, L565CE3, L565D34, L565D87
                         DWORD L565DCC, L565E1C, L565E7C, L565ECC
                         DWORD L565F25, L565F84, L565FE1, L566045
                         DWORD L5660A9, L5662FF, L56643C, L56659E
                         DWORD L5661E7, L5664B3, L566619, L5660DF
                         DWORD L566378, L56669F, L56612A, L566232
                         DWORD L566537, L566182, L566293, L5663D0
                         DWORD L5660A9, L5662FF, L56643C, L56659E
                         DWORD L5661E7, L5664B3, L566619, L5660DF
                         DWORD L566378, L56669F, L56612A, L566232
                         DWORD L566537, L566182, L566293, L5663D0
                         DWORD L5660A9, L5662FF, L56643C, L56659E
                         DWORD L5661E7, L5664B3, L566619, L5660DF
                         DWORD L566378, L56669F, L56612A, L566232
                         DWORD L566537, L566182, L566293, L5663D0
                         DWORD L5660A9, L5662FF, L56643C, L56659E
                         DWORD L5661E7, L5664B3, L566619, L5660DF
                         DWORD L566378, L56669F, L56612A, L566232
                         DWORD L566537, L566182, L566293, L5663D0
                         DWORD L5660A9, L5662FF, L56643C, L56659E
                         DWORD L5661E7, L5664B3, L566619, L5660DF
                         DWORD L566378, L56669F, L56612A, L566232
                         DWORD L566537, L566182, L566293, L5663D0
                         DWORD L5660A9, L5662FF, L56643C, L56659E
                         DWORD L5661E7, L5664B3, L566619, L5660DF
                         DWORD L566378, L56669F, L56612A, L566232
                         DWORD L566537, L566182, L566293, L5663D0

; Span length (0-255) to dispatch-table row.
length_index             BYTE 0, 4, 8, 00Ch, 010h, 014h, 018h, 01Ch, 020h, 024h, 028h, 02Ch, 030h, 034h, 038h, 03Ch
                         BYTE 040h, 044h, 048h, 04Ch, 050h, 054h, 058h, 05Ch, 060h, 064h, 068h, 06Ch, 070h, 074h, 078h, 07Ch
                         BYTE 040h, 044h, 048h, 04Ch, 050h, 054h, 058h, 05Ch, 060h, 064h, 068h, 06Ch, 070h, 074h, 078h, 07Ch
                         BYTE 040h, 044h, 048h, 04Ch, 050h, 054h, 058h, 05Ch, 060h, 064h, 068h, 06Ch, 070h, 074h, 078h, 07Ch
                         BYTE 040h, 044h, 048h, 04Ch, 050h, 054h, 058h, 05Ch, 060h, 064h, 068h, 06Ch, 070h, 074h, 078h, 07Ch
                         BYTE 040h, 044h, 048h, 04Ch, 050h, 054h, 058h, 05Ch, 060h, 064h, 068h, 06Ch, 070h, 074h, 078h, 07Ch
                         BYTE 040h, 044h, 048h, 04Ch, 050h, 054h, 058h, 05Ch, 060h, 064h, 068h, 06Ch, 070h, 074h, 078h, 07Ch
                         BYTE 040h, 044h, 048h, 04Ch, 050h, 054h, 058h, 05Ch, 060h, 064h, 068h, 06Ch, 070h, 074h, 078h, 07Ch
                         BYTE 040h, 044h, 048h, 04Ch, 050h, 054h, 058h, 05Ch, 060h, 064h, 068h, 06Ch, 070h, 074h, 078h, 07Ch
                         BYTE 040h, 044h, 048h, 04Ch, 050h, 054h, 058h, 05Ch, 060h, 064h, 068h, 06Ch, 070h, 074h, 078h, 07Ch
                         BYTE 040h, 044h, 048h, 04Ch, 050h, 054h, 058h, 05Ch, 060h, 064h, 068h, 06Ch, 070h, 074h, 078h, 07Ch
                         BYTE 040h, 044h, 048h, 04Ch, 050h, 054h, 058h, 05Ch, 060h, 064h, 068h, 06Ch, 070h, 074h, 078h, 07Ch
                         BYTE 040h, 044h, 048h, 04Ch, 050h, 054h, 058h, 05Ch, 060h, 064h, 068h, 06Ch, 070h, 074h, 078h, 07Ch
                         BYTE 040h, 044h, 048h, 04Ch, 050h, 054h, 058h, 05Ch, 060h, 064h, 068h, 06Ch, 070h, 074h, 078h, 07Ch
                         BYTE 040h, 044h, 048h, 04Ch, 050h, 054h, 058h, 05Ch, 060h, 064h, 068h, 06Ch, 070h, 074h, 078h, 07Ch
                         BYTE 040h, 044h, 048h, 04Ch, 050h, 054h, 058h, 05Ch, 060h, 064h, 068h, 06Ch, 070h, 074h, 078h, 07Ch
L56B400                  DWORD L56CC80, L56CD20, L56CC85, L56CD31
                         DWORD L56CC80, L56CD20, L56CD60, L56CE00
                         DWORD L56CC80, L56CD20, L56CEA0, L56CF40
                         DWORD L56CC80, L56CD20, L56CC60, L56D2E0
L56B440                  DWORD L56D0E0, L56D140, L56D100, L56D14B
                         DWORD L56D0E0, L56D140, L56D160, L56D1A0
                         DWORD L56D0E0, L56D140, L56D1E0, L56D220
                         DWORD L56D0E0, L56D140, L56D0C0, L56D2E0
L56B480                  DWORD L56D2CE, L56CFE5, L56CFE0, L56CC20
                         DWORD L56D080, L56D2CE, L56D2CE, L56D2CE
                         DWORD L56D2CE, L56D2CE, L56D2CE, L56D2CE
                         DWORD L56D2CE, L56D2CE, L56D2CE, L56D2CE
L56B4C0                  DWORD L56D2CE, L56D265, L56D260, L56D0A0
                         DWORD L56D2C0, L56D2CE, L56D2CE, L56D2CE
                         DWORD L56D2CE, L56D2CE, L56D2CE, L56D2CE
                         DWORD L56D2CE, L56D2CE, L56D2CE, L56D2CE
L56B500                  DWORD L56D720, L56D7C0, L56D725, L56D7D1
                         DWORD L56D720, L56D7C0, L56D800, L56D8A0
                         DWORD L56D720, L56D7C0, L56D940, L56D9E0
                         DWORD L56D720, L56D7C0, L56D700, L56DB40
L56B540                  DWORD L56D460, L56D4C0, L56D480, L56D4CB
                         DWORD L56D460, L56D4C0, L56D4E0, L56D520
                         DWORD L56D460, L56D4C0, L56D560, L56D5A0
                         DWORD L56D460, L56D4C0, L56D440, L56DB40
L56B580                  DWORD L56D2CE, L56DA85, L56DA80, L56DB20
                         DWORD L56D6C0, L56D2CE, L56D2CE, L56D2CE
                         DWORD L56D2CE, L56D2CE, L56D2CE, L56D2CE
                         DWORD L56D2CE, L56D2CE, L56D2CE, L56D2CE
L56B5C0                  DWORD L56D2CE, L56D5E5, L56D5E0, L56D640
                         DWORD L56D420, L56D2CE, L56D2CE, L56D2CE
                         DWORD L56D2CE, L56D2CE, L56D2CE, L56D2CE
                         DWORD L56D2CE, L56D2CE, L56D2CE, L56D2CE
L56B600                  DWORD draw_done, draw_done, draw_done, draw_done
                         DWORD L566786, L566786, L566786, L566786
                         DWORD L566792, L566792, L566792, L566792
                         DWORD L5667A5, L5667A5, L5667A5, L5667A5
                         DWORD L5667D1, L5667D1, L5667D1, L5667BE
                         DWORD L566828, L566806, L566806, L5667ED
                         DWORD L56689C, L566881, L56685C, L566840
                         DWORD L56691F, L5668FE, L5668DC, L5668BA
                         DWORD L566B69, L566ACB, L566A41, L566940
                         DWORD L566958, L566B9D, L566B00, L5669CD
                         DWORD L5669EC, L566977, L566BD8, L566A75
                         DWORD L566A9D, L566A13, L56699F, L566B3B
                         DWORD L566B69, L566ACB, L566A41, L566940
                         DWORD L566958, L566B9D, L566B00, L5669CD
                         DWORD L5669EC, L566977, L566BD8, L566A75
                         DWORD L566A9D, L566A13, L56699F, L566B3B
                         DWORD L566B69, L566ACB, L566A41, L566940
                         DWORD L566958, L566B9D, L566B00, L5669CD
                         DWORD L5669EC, L566977, L566BD8, L566A75
                         DWORD L566A9D, L566A13, L56699F, L566B3B
                         DWORD L566B69, L566ACB, L566A41, L566940
                         DWORD L566958, L566B9D, L566B00, L5669CD
                         DWORD L5669EC, L566977, L566BD8, L566A75
                         DWORD L566A9D, L566A13, L56699F, L566B3B
                         DWORD L566B69, L566ACB, L566A41, L566940
                         DWORD L566958, L566B9D, L566B00, L5669CD
                         DWORD L5669EC, L566977, L566BD8, L566A75
                         DWORD L566A9D, L566A13, L56699F, L566B3B
                         DWORD L566B69, L566ACB, L566A41, L566940
                         DWORD L566958, L566B9D, L566B00, L5669CD
                         DWORD L5669EC, L566977, L566BD8, L566A75
                         DWORD L566A9D, L566A13, L56699F, L566B3B
                         DWORD draw_done, draw_done, draw_done, draw_done
                         DWORD L566C19, L566C31, L566C19, L566C31
                         DWORD L566C8B, L566C68, L566C49, L566C68
                         DWORD L566D2A, L566CF5, L566CAA, L566CCF
                         DWORD L566DF5, L566DB5, L566D7E, L566D5F
                         DWORD L566EE3, L566EA0, L566E5E, L566E2D
                         DWORD L566FD1, L566F95, L566F50, L566F14
                         DWORD L5670DF, L567091, L567053, L567014
                         DWORD L5674E7, L5673DC, L5672EA, L56712D
                         DWORD L567151, L567540, L56743D, L567212
                         DWORD L567249, L567188, L5675A4, L567342
                         DWORD L567386, L567294, L5671CC, L5674A0
                         DWORD L5674E7, L5673DC, L5672EA, L56712D
                         DWORD L567151, L567540, L56743D, L567212
                         DWORD L567249, L567188, L5675A4, L567342
                         DWORD L567386, L567294, L5671CC, L5674A0
                         DWORD L5674E7, L5673DC, L5672EA, L56712D
                         DWORD L567151, L567540, L56743D, L567212
                         DWORD L567249, L567188, L5675A4, L567342
                         DWORD L567386, L567294, L5671CC, L5674A0
                         DWORD L5674E7, L5673DC, L5672EA, L56712D
                         DWORD L567151, L567540, L56743D, L567212
                         DWORD L567249, L567188, L5675A4, L567342
                         DWORD L567386, L567294, L5671CC, L5674A0
                         DWORD L5674E7, L5673DC, L5672EA, L56712D
                         DWORD L567151, L567540, L56743D, L567212
                         DWORD L567249, L567188, L5675A4, L567342
                         DWORD L567386, L567294, L5671CC, L5674A0
                         DWORD L5674E7, L5673DC, L5672EA, L56712D
                         DWORD L567151, L567540, L56743D, L567212
                         DWORD L567249, L567188, L5675A4, L567342
                         DWORD L567386, L567294, L5671CC, L5674A0
L56BA00                  DWORD draw_done, draw_done, draw_done, draw_done
                         DWORD L568561, L568561, L568561, L568561
                         DWORD L568577, L56856A, L56856A, L56856A
                         DWORD L568592, L568583, L568583, L568583
                         DWORD L5685D4, L5685C0, L5685AE, L5685A2
                         DWORD L568621, L56860B, L5685F5, L5685E6
                         DWORD L56866E, L56865B, L568643, L568630
                         DWORD L5686C0, L5686AA, L568695, L568680
                         DWORD L56883D, L5687DA, L568781, L5686D6
                         DWORD L5686E7, L56885D, L5687FC, L568734
                         DWORD L568749, L5686FC, L568881, L5687A1
                         DWORD L5687BC, L568763, L568717, L568820
                         DWORD L56883D, L5687DA, L568781, L5686D6
                         DWORD L5686E7, L56885D, L5687FC, L568734
                         DWORD L568749, L5686FC, L568881, L5687A1
                         DWORD L5687BC, L568763, L568717, L568820
                         DWORD L56883D, L5687DA, L568781, L5686D6
                         DWORD L5686E7, L56885D, L5687FC, L568734
                         DWORD L568749, L5686FC, L568881, L5687A1
                         DWORD L5687BC, L568763, L568717, L568820
                         DWORD L56883D, L5687DA, L568781, L5686D6
                         DWORD L5686E7, L56885D, L5687FC, L568734
                         DWORD L568749, L5686FC, L568881, L5687A1
                         DWORD L5687BC, L568763, L568717, L568820
                         DWORD L56883D, L5687DA, L568781, L5686D6
                         DWORD L5686E7, L56885D, L5687FC, L568734
                         DWORD L568749, L5686FC, L568881, L5687A1
                         DWORD L5687BC, L568763, L568717, L568820
                         DWORD L56883D, L5687DA, L568781, L5686D6
                         DWORD L5686E7, L56885D, L5687FC, L568734
                         DWORD L568749, L5686FC, L568881, L5687A1
                         DWORD L5687BC, L568763, L568717, L568820
                         DWORD draw_done, draw_done, draw_done, draw_done
                         DWORD L5688A7, L5688B0, L5688A7, L5688B0
                         DWORD L5688D4, L5688C7, L5688B9, L5688C7
                         DWORD L56890F, L5688FF, L5688E0, L5688EF
                         DWORD L568951, L56893D, L56892B, L56891F
                         DWORD L5689A0, L568989, L568973, L568964
                         DWORD L5689EE, L5689DB, L5689C2, L5689AF
                         DWORD L568A41, L568A2B, L568A16, L568A00
                         DWORD L568BBF, L568B5B, L568B02, L568A57
                         DWORD L568A68, L568BE0, L568B7D, L568AB5
                         DWORD L568ACA, L568A7D, L568C05, L568B22
                         DWORD L568B3D, L568AE4, L568A98, L568BA1
                         DWORD L568BBF, L568B5B, L568B02, L568A57
                         DWORD L568A68, L568BE0, L568B7D, L568AB5
                         DWORD L568ACA, L568A7D, L568C05, L568B22
                         DWORD L568B3D, L568AE4, L568A98, L568BA1
                         DWORD L568BBF, L568B5B, L568B02, L568A57
                         DWORD L568A68, L568BE0, L568B7D, L568AB5
                         DWORD L568ACA, L568A7D, L568C05, L568B22
                         DWORD L568B3D, L568AE4, L568A98, L568BA1
                         DWORD L568BBF, L568B5B, L568B02, L568A57
                         DWORD L568A68, L568BE0, L568B7D, L568AB5
                         DWORD L568ACA, L568A7D, L568C05, L568B22
                         DWORD L568B3D, L568AE4, L568A98, L568BA1
                         DWORD L568BBF, L568B5B, L568B02, L568A57
                         DWORD L568A68, L568BE0, L568B7D, L568AB5
                         DWORD L568ACA, L568A7D, L568C05, L568B22
                         DWORD L568B3D, L568AE4, L568A98, L568BA1
                         DWORD L568BBF, L568B5B, L568B02, L568A57
                         DWORD L568A68, L568BE0, L568B7D, L568AB5
                         DWORD L568ACA, L568A7D, L568C05, L568B22
                         DWORD L568B3D, L568AE4, L568A98, L568BA1
L56BE00                  DWORD draw_done, draw_done, draw_done, draw_done
                         DWORD L56760A, L56760A, L56760A, L56760A
                         DWORD L567618, L567618, L567618, L567618
                         DWORD L56762E, L56762E, L56762E, L56762E
                         DWORD L56765E, L56765E, L56765E, L567649
                         DWORD L5676C3, L567699, L567699, L56767C
                         DWORD L56774E, L56772F, L5676FF, L5676DF
                         DWORD L5677E2, L5677BB, L567796, L567770
                         DWORD L567A70, L5679C2, L567928, L567809
                         DWORD L567823, L567AAA, L5679FD, L5678A4
                         DWORD L5678C7, L567846, L567AEB, L567962
                         DWORD L56798E, L5678F4, L567872, L567A3E
                         DWORD L567A70, L5679C2, L567928, L567809
                         DWORD L567823, L567AAA, L5679FD, L5678A4
                         DWORD L5678C7, L567846, L567AEB, L567962
                         DWORD L56798E, L5678F4, L567872, L567A3E
                         DWORD L567A70, L5679C2, L567928, L567809
                         DWORD L567823, L567AAA, L5679FD, L5678A4
                         DWORD L5678C7, L567846, L567AEB, L567962
                         DWORD L56798E, L5678F4, L567872, L567A3E
                         DWORD L567A70, L5679C2, L567928, L567809
                         DWORD L567823, L567AAA, L5679FD, L5678A4
                         DWORD L5678C7, L567846, L567AEB, L567962
                         DWORD L56798E, L5678F4, L567872, L567A3E
                         DWORD L567A70, L5679C2, L567928, L567809
                         DWORD L567823, L567AAA, L5679FD, L5678A4
                         DWORD L5678C7, L567846, L567AEB, L567962
                         DWORD L56798E, L5678F4, L567872, L567A3E
                         DWORD L567A70, L5679C2, L567928, L567809
                         DWORD L567823, L567AAA, L5679FD, L5678A4
                         DWORD L5678C7, L567846, L567AEB, L567962
                         DWORD L56798E, L5678F4, L567872, L567A3E
                         DWORD draw_done, draw_done, draw_done, draw_done
                         DWORD L567B32, L567B4A, L567B32, L567B4A
                         DWORD L567BA6, L567B82, L567B62, L567B82
                         DWORD L567C70, L567C3A, L567BEF, L567C14
                         DWORD L567D3E, L567CFC, L567CC5, L567CA6
                         DWORD L567E2E, L567DEA, L567DA7, L567D76
                         DWORD L567F1E, L567EE1, L567E9C, L567E5F
                         DWORD L56802D, L567FDE, L567FA0, L567F61
                         DWORD L56843D, L56832F, L56823B, L56807C
                         DWORD L5680A0, L568496, L568392, L568162
                         DWORD L568199, L5680D7, L5684FB, L568293
                         DWORD L5682D8, L5681E4, L56811C, L5683F6
                         DWORD L56843D, L56832F, L56823B, L56807C
                         DWORD L5680A0, L568496, L568392, L568162
                         DWORD L568199, L5680D7, L5684FB, L568293
                         DWORD L5682D8, L5681E4, L56811C, L5683F6
                         DWORD L56843D, L56832F, L56823B, L56807C
                         DWORD L5680A0, L568496, L568392, L568162
                         DWORD L568199, L5680D7, L5684FB, L568293
                         DWORD L5682D8, L5681E4, L56811C, L5683F6
                         DWORD L56843D, L56832F, L56823B, L56807C
                         DWORD L5680A0, L568496, L568392, L568162
                         DWORD L568199, L5680D7, L5684FB, L568293
                         DWORD L5682D8, L5681E4, L56811C, L5683F6
                         DWORD L56843D, L56832F, L56823B, L56807C
                         DWORD L5680A0, L568496, L568392, L568162
                         DWORD L568199, L5680D7, L5684FB, L568293
                         DWORD L5682D8, L5681E4, L56811C, L5683F6
                         DWORD L56843D, L56832F, L56823B, L56807C
                         DWORD L5680A0, L568496, L568392, L568162
                         DWORD L568199, L5680D7, L5684FB, L568293
                         DWORD L5682D8, L5681E4, L56811C, L5683F6
L56C200                  DWORD draw_done, draw_done, draw_done, draw_done
                         DWORD L568C2C, L568C2C, L568C2C, L568C2C
                         DWORD L568C55, L568C3A, L568C3A, L568C3A
                         DWORD L568CD2, L568CAF, L568C8D, L568C6B
                         DWORD L568D76, L568D46, L568D1C, L568CF5
                         DWORD L568E3D, L568E06, L568DCF, L568DA0
                         DWORD L568F22, L568EE6, L568EA8, L568E6C
                         DWORD L569023, L568FDF, L568F9C, L568F59
                         DWORD L5693FE, L5692FA, L569217, L569067
                         DWORD L569093, L569451, L569353, L569157
                         DWORD L56918C, L5690C8, L5694B1, L56926A
                         DWORD L5692AE, L5691CB, L56910C, L5693B3
                         DWORD L5693FE, L5692FA, L569217, L569067
                         DWORD L569093, L569451, L569353, L569157
                         DWORD L56918C, L5690C8, L5694B1, L56926A
                         DWORD L5692AE, L5691CB, L56910C, L5693B3
                         DWORD L5693FE, L5692FA, L569217, L569067
                         DWORD L569093, L569451, L569353, L569157
                         DWORD L56918C, L5690C8, L5694B1, L56926A
                         DWORD L5692AE, L5691CB, L56910C, L5693B3
                         DWORD L5693FE, L5692FA, L569217, L569067
                         DWORD L569093, L569451, L569353, L569157
                         DWORD L56918C, L5690C8, L5694B1, L56926A
                         DWORD L5692AE, L5691CB, L56910C, L5693B3
                         DWORD L5693FE, L5692FA, L569217, L569067
                         DWORD L569093, L569451, L569353, L569157
                         DWORD L56918C, L5690C8, L5694B1, L56926A
                         DWORD L5692AE, L5691CB, L56910C, L5693B3
                         DWORD L5693FE, L5692FA, L569217, L569067
                         DWORD L569093, L569451, L569353, L569157
                         DWORD L56918C, L5690C8, L5694B1, L56926A
                         DWORD L5692AE, L5691CB, L56910C, L5693B3
                         DWORD draw_done, draw_done, draw_done, draw_done
                         DWORD L569518, L569532, L569518, L569532
                         DWORD L5695A0, L569579, L56954C, L569579
                         DWORD L569671, L569636, L5695CE, L569604
                         DWORD L569771, L569729, L5696DF, L5696AC
                         DWORD L5698A8, L569855, L5697FE, L5697B7
                         DWORD L5699F9, L5699A5, L569943, L5698EF
                         DWORD L569B7E, L569B16, L569AB3, L569A54
                         DWORD L56A10D, L569F9D, L569E52, L569BE6
                         DWORD L569C1E, L56A188, L56A01A, L569D32
                         DWORD L569D7F, L569C6B, L56A210, L569ED1
                         DWORD L569F2D, L569DE2, L569CC7, L56A0A6
                         DWORD L56A10D, L569F9D, L569E52, L569BE6
                         DWORD L569C1E, L56A188, L56A01A, L569D32
                         DWORD L569D7F, L569C6B, L56A210, L569ED1
                         DWORD L569F2D, L569DE2, L569CC7, L56A0A6
                         DWORD L56A10D, L569F9D, L569E52, L569BE6
                         DWORD L569C1E, L56A188, L56A01A, L569D32
                         DWORD L569D7F, L569C6B, L56A210, L569ED1
                         DWORD L569F2D, L569DE2, L569CC7, L56A0A6
                         DWORD L56A10D, L569F9D, L569E52, L569BE6
                         DWORD L569C1E, L56A188, L56A01A, L569D32
                         DWORD L569D7F, L569C6B, L56A210, L569ED1
                         DWORD L569F2D, L569DE2, L569CC7, L56A0A6
                         DWORD L56A10D, L569F9D, L569E52, L569BE6
                         DWORD L569C1E, L56A188, L56A01A, L569D32
                         DWORD L569D7F, L569C6B, L56A210, L569ED1
                         DWORD L569F2D, L569DE2, L569CC7, L56A0A6
                         DWORD L56A10D, L569F9D, L569E52, L569BE6
                         DWORD L569C1E, L56A188, L56A01A, L569D32
                         DWORD L569D7F, L569C6B, L56A210, L569ED1
                         DWORD L569F2D, L569DE2, L569CC7, L56A0A6
L56C600                  DWORD L56DB71, L56DB77, L56DB7B, L56DB84
                         DWORD L56DB71, L56DB77, L56DB8B, L56DB96
                         DWORD L56DB71, L56DB77, L56DB96, L56DBA0
                         DWORD L56DB71, L56DB77, L56DBA9, L56DBB5
L56C640                  DWORD L56DBBB, L56DBC2, L56DBC8, L56DBCC
                         DWORD L56DBD3, L56DBDA, L56DBDA, L56DBDA
                         DWORD L56DBDA, L56DBDA, L56DBDA, L56DBDA
                         DWORD L56DBDA, L56DBDA, L56DBDA, L56DBDA
_ASMSet_Shadowing:
    push ebp
    mov ebp,esp
    mov eax,dword ptr [ebp+8]
    mov dword ptr ds:[shadow_mask],eax
    mov dword ptr ds:[state_88C068],eax
    mov eax,dword ptr [ebp+0Ch]
    mov dword ptr ds:[shadow_value],eax
    mov dword ptr ds:[state_88C078],eax
    mov eax,dword ptr [ebp+10h]
    mov dword ptr ds:[state_88C064],eax
    mov dword ptr ds:[state_88C06C],eax
    mov eax,dword ptr [ebp+14h]
    mov dword ptr ds:[state_88C074],eax
    mov dword ptr ds:[state_88C07C],eax
    pop ebp
    ret
    CODE_FILL 7  ; ALIGN 16
_ASMSet_ShadowingEx:
    push ebp
    mov ebp,esp
    push ebx
    push esi
    mov esi,dword ptr [ebp+8]
    mov eax,dword ptr [esi]
    mov ebx,dword ptr [esi+4]
    mov ecx,dword ptr [esi+8]
    mov edx,dword ptr [esi+0Ch]
    mov dword ptr ds:[shadow_mask],eax
    mov dword ptr ds:[state_88C064],ebx
    mov dword ptr ds:[state_88C068],ecx
    mov dword ptr ds:[state_88C06C],edx
    mov eax,dword ptr [esi+10h]
    mov ebx,dword ptr [esi+14h]
    mov ecx,dword ptr [esi+18h]
    mov edx,dword ptr [esi+1Ch]
    mov dword ptr ds:[shadow_value],eax
    mov dword ptr ds:[state_88C074],ebx
    mov dword ptr ds:[state_88C078],ecx
    mov dword ptr ds:[state_88C07C],edx
    pop esi
    pop ebx
    pop ebp
    ret
    CODE_FILL 15 ; ALIGN 16
_ASMSet_Surface_Info:
    push ebp
    mov ebp,esp
    mov eax,dword ptr [ebp+8]
    mov dword ptr ds:[surface_offsets],eax
    mov eax,dword ptr [ebp+0Ch]
    mov dword ptr ds:[span_heads],eax
    mov eax,dword ptr [ebp+10h]
    mov dword ptr ds:[span_tails],eax
    mov eax,dword ptr [ebp+18h]
    mov dword ptr ds:[min_line],eax
    mov eax,dword ptr [ebp+20h]
    mov dword ptr ds:[max_line],eax
    mov eax,dword ptr [ebp+14h]
    mov dword ptr ds:[min_span],eax
    mov eax,dword ptr [ebp+1Ch]
    mov dword ptr ds:[max_span],eax
    pop ebp
    ret
    CODE_FILL 3  ; ALIGN 16
_ASMSet_Color_Xform:
    push ebp
    mov ebp,esp
    mov eax,dword ptr [ebp+8]
    mov cl,al
    mov ah,al
    bswap eax
    mov al,cl
    mov ah,cl
    mov dword ptr ds:[color_xform],eax
    pop ebp
    ret
    CODE_FILL 9  ; ALIGN 16
_ASMGet_Color_Xform:
    mov eax,dword ptr ds:[color_xform]
    and eax,0FFh
    ret
    CODE_FILL 21 ; ALIGN 32
_ASMSet_Xlate_Table:
    push ebp
    mov ebp,esp
    mov eax,dword ptr [ebp+8]
    mov dword ptr ds:[xlate_table],eax
    pop ebp
    ret
    CODE_FILL 19 ; ALIGN 32
_ASMGet_Xlate_Table:
    mov eax,dword ptr ds:[xlate_table]
    ret
    CODE_FILL 26 ; ALIGN 32
_ASMDraw_HLine:
    push ebp
    mov ebp,esp
    push ebx
    push esi
    push edi
    mov eax,dword ptr [ebp+10h]
    cmp eax,dword ptr ds:[min_line]
    jl NEAR PTR hline_return
    cmp eax,dword ptr ds:[max_line]
    jg NEAR PTR hline_return
    mov eax,dword ptr [ebp+8]
    mov ebx,dword ptr [ebp+0Ch]
    cmp eax,ebx
    jle SHORT L56C812
    xchg ebx,eax
    mov dword ptr [ebp+8],eax
    mov dword ptr [ebp+0Ch],ebx
L56C812:
    cmp ebx,dword ptr ds:[min_span]
    jl NEAR PTR hline_return
    cmp eax,dword ptr ds:[max_span]
    jg NEAR PTR hline_return
    cmp eax,dword ptr ds:[min_span]
    jge SHORT L56C83A
    mov eax,dword ptr ds:[min_span]
    mov dword ptr [ebp+8],eax
L56C83A:
    cmp ebx,dword ptr ds:[max_span]
    jle SHORT L56C84B
    mov ebx,dword ptr ds:[max_span]
    mov dword ptr [ebp+0Ch],ebx
L56C84B:
    mov ecx,dword ptr [ebp+10h]
    mov esi,dword ptr ds:[span_heads]
    mov edi,dword ptr [esi+ecx*4]
    or edi,edi
    je NEAR PTR hline_return
    mov dword ptr ds:[draw_span],edi
    mov edx,eax
    mov ecx,ebx
    sub ebx,eax
    inc ebx
    mov dword ptr ds:[draw_length],ebx
    mov dword ptr ds:[draw_resume],OFFSET hline_return
    mov esi,dword ptr ds:[surface_offsets]
    mov eax,dword ptr [ebp+10h]
    mov eax,dword ptr [esi+eax*4]
    mov dword ptr ds:[draw_row_base],eax
    add eax,edx
    mov dword ptr ds:[draw_pixel_ptr],eax
L56C894:
    cmp ecx,dword ptr [edi+8]
    jl NEAR PTR hline_return
    cmp edx,dword ptr [edi+0Ch]
    jle SHORT L56C8AD
    mov edi,dword ptr [edi]
    or edi,edi
    jne SHORT L56C894
    jmp NEAR PTR hline_return
L56C8AD:
    cmp edx,dword ptr [edi+8]
    jl SHORT L56C8F2
    cmp ecx,dword ptr [edi+0Ch]
    jg SHORT L56C8F2
    mov al,byte ptr [ebp+14h]
    mov ecx,dword ptr ds:[draw_length]
    mov ah,al
    mov edx,ecx
    shl eax,10h
    and edx,7Fh
    cmp ecx,80h
    jl SHORT L56C8D5
    or dl,80h
L56C8D5:
    mov edi,dword ptr ds:[draw_pixel_ptr]
    mov al,byte ptr [ebp+14h]
    mov ebx,edi
    mov ah,al
    and ebx,3
    or bl,byte ptr [edx+length_index]
    jmp dword ptr [ebx*4+solid_fill_table]
L56C8F2:
    mov dword ptr ds:[draw_span],edi
    jmp SHORT L56C91A
hline_next_span:
    mov ebx,dword ptr ds:[draw_span]
    mov ebx,dword ptr [ebx]
    or ebx,ebx
    je NEAR PTR hline_return
    mov dword ptr ds:[draw_span],ebx
    mov dword ptr ds:[draw_resume],OFFSET hline_return
L56C91A:
    mov ebx,dword ptr ds:[draw_span]
    mov edi,dword ptr [ebp+8]
    mov edx,dword ptr [ebp+0Ch]
    mov ecx,dword ptr ds:[draw_length]
    cmp edx,dword ptr [ebx+8]
    jl SHORT hline_return
    cmp edi,dword ptr [ebx+0Ch]
    jg SHORT hline_next_span
    xor eax,eax
    cmp edi,dword ptr [ebx+8]
    jge SHORT L56C944
    mov eax,dword ptr [ebx+8]
    sub eax,edi
    sub ecx,eax
L56C944:
    mov dword ptr ds:[draw_clip_skip],eax
    cmp edx,dword ptr [ebx+0Ch]
    jle SHORT L56C95F
    mov eax,edx
    sub eax,dword ptr [ebx+0Ch]
    sub ecx,eax
    mov dword ptr ds:[draw_resume],OFFSET hline_next_span
L56C95F:
    mov edi,dword ptr ds:[draw_pixel_ptr]
    mov al,byte ptr [ebp+14h]
    mov edx,ecx
    mov ah,al
    and edx,7Fh
    shl eax,10h
    cmp ecx,80h
    jl SHORT L56C97D
    or dl,80h
L56C97D:
    add edi,dword ptr ds:[draw_clip_skip]
    mov al,byte ptr [ebp+14h]
    mov ebx,edi
    mov ah,al
    and ebx,3
    or bl,byte ptr [edx+length_index]
    jmp dword ptr [ebx*4+solid_fill_table]
hline_return:
    pop edi
    pop esi
    pop ebx
    pop ebp
    ret
    CODE_FILL 1  ; ALIGN 16
_ASMDraw_Sprite:
    push ebp
    mov ebp,esp
    push ebx
    push esi
    push edi
    mov eax,dword ptr [ebp+10h]
    mov ecx,dword ptr [ebp+18h]
    xor edx,edx
    lea ebx,[ecx+eax-1]
    cmp ebx,dword ptr ds:[min_line]
    jl NEAR PTR L56D2F4
    cmp eax,dword ptr ds:[max_line]
    jg NEAR PTR L56D2F4
    cmp eax,dword ptr ds:[min_line]
    jge SHORT L56C9E4
    mov edx,dword ptr ds:[min_line]
    sub edx,eax
    xor eax,eax
    sub ecx,edx
    shl edx,2
    mov dword ptr [ebp+10h],eax
L56C9E4:
    cmp ebx,dword ptr ds:[max_line]
    jle SHORT L56C9F4
    sub ebx,dword ptr ds:[max_line]
    sub ecx,ebx
L56C9F4:
    mov dword ptr [ebp+18h],ecx
    xor ebx,ebx
    mov dword ptr ds:[draw_length],ebx
    mov eax,dword ptr [ebp+0Ch]
    mov dword ptr ds:[state_88C024],eax
    cmp eax,dword ptr ds:[max_span]
    jg NEAR PTR L56D2F4
    add eax,dword ptr [ebp+14h]
    dec eax
    mov dword ptr ds:[state_88C028],eax
    cmp eax,dword ptr ds:[min_span]
    jl NEAR PTR L56D2F4
    mov eax,dword ptr [ebp+1Ch]
    add eax,dword ptr [ebp+8]
    add eax,edx
    mov dword ptr ds:[state_88C00C],eax
    mov eax,dword ptr [ebp+20h]
    add eax,dword ptr [ebp+8]
    add eax,edx
    mov dword ptr ds:[state_88C010],eax
    mov eax,dword ptr [ebp+24h]
    xor ecx,ecx
    test eax,1
    je SHORT L56CA55
    mov ecx,80h
    jmp SHORT L56CA71
L56CA55:
    mov ebx,dword ptr ds:[color_xform]
    mov dword ptr ds:[state_88C030],ecx
    mov dword ptr ds:[state_88C02C],0FFFFFFFFh
    mov dword ptr ds:[state_88C034],ebx
L56CA71:
    mov dword ptr ds:[state_88C048],ecx
    test eax,2
    jne NEAR PTR L56D300
    CODE_FILL 30 ; ALIGN 32
L56CAA0:
    mov eax,dword ptr [ebp+10h]
    mov ebx,dword ptr ds:[draw_length]
    add eax,ebx
    mov esi,dword ptr ds:[span_heads]
    mov edi,dword ptr [esi+eax*4]
    or edi,edi
    je NEAR PTR L56D2E0
    mov dword ptr ds:[draw_span],edi
    test byte ptr ds:[state_88C048],80h
    je SHORT L56CAF6
    and eax,3
    mov edx,dword ptr [eax*4+shadow_value]
    mov ecx,dword ptr [eax*4+shadow_mask]
    mov eax,dword ptr ds:[color_xform]
    mov dword ptr ds:[state_88C030],edx
    mov dword ptr ds:[state_88C02C],ecx
    and eax,ecx
    or eax,edx
    mov dword ptr ds:[state_88C034],eax
L56CAF6:
    mov esi,dword ptr ds:[state_88C010]
    xor eax,eax
    mov ax,word ptr [esi+ebx*4]
    mov edx,dword ptr ds:[state_88C024]
    test eax,8000h
    jne NEAR PTR L56D2E0
    add edx,eax
    mov ax,word ptr [esi+ebx*4+2]
    mov ecx,dword ptr ds:[state_88C028]
    sub ecx,eax
    mov esi,dword ptr ds:[surface_offsets]
    mov eax,dword ptr [ebp+10h]
    add eax,ebx
    mov eax,dword ptr [esi+eax*4]
    mov dword ptr ds:[draw_row_base],eax
    add eax,edx
    mov dword ptr ds:[draw_pixel_ptr],eax
    mov esi,dword ptr ds:[state_88C00C]
    mov eax,dword ptr [esi+ebx*4]
    add eax,dword ptr [ebp+8]
    mov dword ptr ds:[state_88C018],eax
L56CB4D:
    cmp ecx,dword ptr [edi+8]
    jl NEAR PTR L56D2E0
    cmp edx,dword ptr [edi+0Ch]
    jle SHORT L56CB66
    mov edi,dword ptr [edi]
    or edi,edi
    jne SHORT L56CB4D
    jmp NEAR PTR L56D2E0
L56CB66:
    cmp edx,dword ptr [edi+8]
    jl SHORT L56CB8B
    cmp ecx,dword ptr [edi+0Ch]
    jg SHORT L56CB8B
    mov eax,OFFSET L56D0A0
    mov dword ptr ds:[draw_resume],eax
    mov edi,dword ptr ds:[draw_pixel_ptr]
    mov esi,dword ptr ds:[state_88C018]
    jmp NEAR PTR L56D0A0
L56CB8B:
    mov eax,OFFSET L56CC20
    mov dword ptr ds:[draw_resume],eax
    mov dword ptr ds:[draw_span],edi
    mov edi,dword ptr ds:[draw_pixel_ptr]
    mov esi,dword ptr ds:[state_88C018]
    jmp NEAR PTR L56CC20
    CODE_FILL 20 ; ALIGN 32
L56CBC0:
    mov esi,dword ptr ds:[state_88C050]
    mov edi,dword ptr ds:[state_88C054]
    mov ebx,dword ptr ds:[draw_span]
    mov ebx,dword ptr [ebx]
    or ebx,ebx
    je NEAR PTR L56D2E0
    mov dword ptr ds:[draw_resume],OFFSET L56CC20
    xor eax,eax
    mov al,byte ptr [esi]
    sub edi,dword ptr ds:[draw_row_base]
    mov ecx,eax
    inc esi
    and eax,0Fh
    mov dword ptr ds:[draw_span],ebx
    jmp dword ptr [eax*4+L56B400]
    CODE_FILL 29 ; ALIGN 32
L56CC20:
    mov dword ptr ds:[state_88C050],esi
    xor eax,eax
    mov dword ptr ds:[state_88C054],edi
    mov al,byte ptr [esi]
    sub edi,dword ptr ds:[draw_row_base]
    mov ecx,eax
    inc esi
    and eax,0Fh
    mov ebx,dword ptr ds:[draw_span]
    jmp dword ptr [eax*4+L56B400]
    CODE_FILL 23 ; ALIGN 32
L56CC60:
    mov eax,ecx
    shr eax,4
    jmp dword ptr [eax*4+L56B480]
    CODE_FILL 20 ; ALIGN 32
L56CC80:
    shr ecx,2
    jmp SHORT L56CC8B
L56CC85:
    shl ecx,4
    mov cl,byte ptr [esi]
    inc esi
L56CC8B:
    mov edx,edi
    add edx,ecx
    dec edx
L56CC90:
    cmp edx,dword ptr [ebx+8]
    jl SHORT L56CCF2
    cmp edi,dword ptr [ebx+0Ch]
    jg SHORT L56CD01
    xor eax,eax
    cmp edi,dword ptr [ebx+8]
    jge SHORT L56CCAA
    mov eax,dword ptr [ebx+8]
    sub eax,edi
    add esi,eax
    sub ecx,eax
L56CCAA:
    mov dword ptr ds:[draw_clip_skip],eax
    cmp edx,dword ptr [ebx+0Ch]
    jle SHORT L56CCC5
    mov eax,edx
    sub eax,dword ptr [ebx+0Ch]
    sub ecx,eax
    mov dword ptr ds:[draw_resume],OFFSET L56CBC0
L56CCC5:
    mov edi,dword ptr ds:[state_88C054]
    xor ebx,ebx
    add edi,dword ptr ds:[draw_clip_skip]
    sub bl,ch
    mov eax,edi
    and bl,80h
    and eax,3
    or bl,cl
    or al,byte ptr ds:[state_88C048]
    or al,byte ptr [ebx+length_index]
    jmp dword ptr [eax*4+plain_copy_table]
L56CCF2:
    mov edi,dword ptr ds:[state_88C054]
    add esi,ecx
    add edi,ecx
    jmp NEAR PTR L56CC20
L56CD01:
    mov ebx,dword ptr [ebx]
    or ebx,ebx
    jne SHORT L56CC90
    jmp NEAR PTR L56D2E0
    CODE_FILL 20 ; ALIGN 32
L56CD20:
    shr ecx,2
    mov edi,dword ptr ds:[state_88C054]
    add edi,ecx
    jmp dword ptr ds:[draw_resume]
L56CD31:
    shl ecx,4
    mov edi,dword ptr ds:[state_88C054]
    mov cl,byte ptr [esi]
    inc esi
    add edi,ecx
    jmp dword ptr ds:[draw_resume]
    CODE_FILL 27 ; ALIGN 32
L56CD60:
    shr ecx,4
    jne SHORT L56CD68
    mov cl,byte ptr [esi]
    inc esi
L56CD68:
    mov edx,edi
    add edx,ecx
    dec edx
L56CD6D:
    cmp edx,dword ptr [ebx+8]
    jl SHORT L56CDCC
    cmp edi,dword ptr [ebx+0Ch]
    jg SHORT L56CDDB
    xor eax,eax
    cmp edi,dword ptr [ebx+8]
    jge SHORT L56CD87
    mov eax,dword ptr [ebx+8]
    sub eax,edi
    add esi,eax
    sub ecx,eax
L56CD87:
    mov dword ptr ds:[draw_clip_skip],eax
    cmp edx,dword ptr [ebx+0Ch]
    jle SHORT L56CDA2
    mov eax,edx
    sub eax,dword ptr [ebx+0Ch]
    sub ecx,eax
    mov dword ptr ds:[draw_resume],OFFSET L56CBC0
L56CDA2:
    mov edi,dword ptr ds:[state_88C054]
    add edi,dword ptr ds:[draw_clip_skip]
    mov eax,edi
    and eax,3
    or al,byte ptr [ecx+length_index]
    mov ebx,dword ptr ds:[color_xform]
    or al,byte ptr ds:[state_88C048]
    jmp dword ptr [eax*4+L56AB00]
L56CDCC:
    mov edi,dword ptr ds:[state_88C054]
    add esi,ecx
    add edi,ecx
    jmp NEAR PTR L56CC20
L56CDDB:
    mov ebx,dword ptr [ebx]
    or ebx,ebx
    jne SHORT L56CD6D
    jmp NEAR PTR L56D2E0
    CODE_FILL 26 ; ALIGN 32
L56CE00:
    shr ecx,4
    jne SHORT L56CE08
    mov cl,byte ptr [esi]
    inc esi
L56CE08:
    mov edx,edi
    add edx,ecx
    dec edx
L56CE0D:
    cmp edx,dword ptr [ebx+8]
    jl SHORT L56CE7C
    cmp edi,dword ptr [ebx+0Ch]
    jg SHORT L56CE8A
    xor eax,eax
    cmp edi,dword ptr [ebx+8]
    jge SHORT L56CE25
    mov eax,dword ptr [ebx+8]
    sub eax,edi
    sub ecx,eax
L56CE25:
    mov dword ptr ds:[draw_clip_skip],eax
    cmp edx,dword ptr [ebx+0Ch]
    jle SHORT L56CE40
    mov eax,edx
    sub eax,dword ptr [ebx+0Ch]
    sub ecx,eax
    mov dword ptr ds:[draw_resume],OFFSET L56CBC0
L56CE40:
    mov edi,dword ptr ds:[state_88C054]
    mov al,byte ptr [esi]
    add edi,dword ptr ds:[draw_clip_skip]
    mov ah,al
    mov ebx,edi
    shl eax,10h
    and ebx,3
    mov al,byte ptr [esi]
    or bl,byte ptr [ecx+length_index]
    mov ah,al
    or bl,byte ptr ds:[state_88C048]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    inc esi
    jmp dword ptr [ebx*4+solid_fill_table]
L56CE7C:
    mov edi,dword ptr ds:[state_88C054]
    inc esi
    add edi,ecx
    jmp NEAR PTR L56CC20
L56CE8A:
    mov ebx,dword ptr [ebx]
    or ebx,ebx
    jne NEAR PTR L56CE0D
    jmp NEAR PTR L56D2E0
    CODE_FILL 7  ; ALIGN 16
L56CEA0:
    shr ecx,4
    jne SHORT L56CEA8
    mov cl,byte ptr [esi]
    inc esi
L56CEA8:
    mov edx,edi
    add edx,ecx
    dec edx
L56CEAD:
    cmp edx,dword ptr [ebx+8]
    jl SHORT L56CF1C
    cmp edi,dword ptr [ebx+0Ch]
    jg SHORT L56CF2A
    xor eax,eax
    cmp edi,dword ptr [ebx+8]
    jge SHORT L56CEC5
    mov eax,dword ptr [ebx+8]
    sub eax,edi
    sub ecx,eax
L56CEC5:
    mov dword ptr ds:[draw_clip_skip],eax
    cmp edx,dword ptr [ebx+0Ch]
    jle SHORT L56CEE0
    mov eax,edx
    sub eax,dword ptr [ebx+0Ch]
    sub ecx,eax
    mov dword ptr ds:[draw_resume],OFFSET L56CBC0
L56CEE0:
    mov edi,dword ptr ds:[state_88C054]
    mov al,byte ptr [esi]
    add edi,dword ptr ds:[draw_clip_skip]
    mov ah,al
    mov ebx,edi
    shl eax,10h
    and ebx,3
    mov al,byte ptr [esi]
    or bl,byte ptr [ecx+length_index]
    mov ah,al
    or bl,byte ptr ds:[state_88C048]
    inc esi
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C034]
    jmp dword ptr [ebx*4+solid_fill_table]
L56CF1C:
    mov edi,dword ptr ds:[state_88C054]
    inc esi
    add edi,ecx
    jmp NEAR PTR L56CC20
L56CF2A:
    mov ebx,dword ptr [ebx]
    or ebx,ebx
    jne NEAR PTR L56CEAD
    jmp NEAR PTR L56D2E0
    CODE_FILL 7  ; ALIGN 16
L56CF40:
    shr ecx,4
    jne SHORT L56CF48
    mov cl,byte ptr [esi]
    inc esi
L56CF48:
    mov edx,edi
    add edx,ecx
    dec edx
L56CF4D:
    cmp edx,dword ptr [ebx+8]
    jl SHORT L56CFAC
    cmp edi,dword ptr [ebx+0Ch]
    jg SHORT L56CFB9
    xor eax,eax
    cmp edi,dword ptr [ebx+8]
    jge SHORT L56CF65
    mov eax,dword ptr [ebx+8]
    sub eax,edi
    sub ecx,eax
L56CF65:
    mov dword ptr ds:[draw_clip_skip],eax
    cmp edx,dword ptr [ebx+0Ch]
    jle SHORT L56CF80
    mov eax,edx
    sub eax,dword ptr [ebx+0Ch]
    sub ecx,eax
    mov dword ptr ds:[draw_resume],OFFSET L56CBC0
L56CF80:
    mov edi,dword ptr ds:[state_88C054]
    add edi,dword ptr ds:[draw_clip_skip]
    mov eax,edi
    and eax,3
    xor edx,edx
    or al,byte ptr [ecx+length_index]
    mov ebx,dword ptr ds:[xlate_table]
    or al,byte ptr ds:[state_88C048]
    jmp dword ptr [eax*4+L56AF00]
L56CFAC:
    mov edi,dword ptr ds:[state_88C054]
    add edi,ecx
    jmp NEAR PTR L56CC20
L56CFB9:
    mov ebx,dword ptr [ebx]
    or ebx,ebx
    jne SHORT L56CF4D
    jmp NEAR PTR L56D2E0
    CODE_FILL 28 ; ALIGN 32
L56CFE0:
    mov cl,byte ptr [esi]
    inc esi
    jne SHORT L56CFEA
L56CFE5:
    mov ecx,1
L56CFEA:
    cmp dword ptr ds:[state_88C058],0
    je SHORT L56D060
    mov edx,edi
    add edx,ecx
    dec edx
L56CFF8:
    cmp edx,dword ptr [ebx+8]
    jl SHORT L56D060
    cmp edi,dword ptr [ebx+0Ch]
    jg SHORT L56D06D
    xor eax,eax
    cmp edi,dword ptr [ebx+8]
    jge SHORT L56D010
    mov eax,dword ptr [ebx+8]
    sub eax,edi
    sub ecx,eax
L56D010:
    mov dword ptr ds:[draw_clip_skip],eax
    cmp edx,dword ptr [ebx+0Ch]
    jle SHORT L56D02B
    mov eax,edx
    sub eax,dword ptr [ebx+0Ch]
    sub ecx,eax
    mov dword ptr ds:[draw_resume],OFFSET L56CBC0
L56D02B:
    mov edi,dword ptr ds:[state_88C054]
    mov eax,dword ptr ds:[state_88C05C]
    add edi,dword ptr ds:[draw_clip_skip]
    and eax,dword ptr ds:[state_88C02C]
    mov ebx,edi
    or eax,dword ptr ds:[state_88C030]
    and ebx,3
    or bl,byte ptr [ecx+length_index]
    or bl,byte ptr ds:[state_88C048]
    jmp dword ptr [ebx*4+solid_fill_table]
L56D060:
    mov edi,dword ptr ds:[state_88C054]
    add edi,ecx
    jmp NEAR PTR L56CC20
L56D06D:
    mov ebx,dword ptr [ebx]
    or ebx,ebx
    jne SHORT L56CFF8
    jmp NEAR PTR L56D2E0
    CODE_FILL 8  ; ALIGN 16
L56D080:
    mov al,byte ptr [esi]
    call L56DB60
    add edi,ecx
    jmp NEAR PTR L56CC20
    CODE_FILL 18 ; ALIGN 32
L56D0A0:
    xor eax,eax
    mov al,byte ptr [esi]
    mov ecx,eax
    and eax,0Fh
    inc esi
    jmp dword ptr [eax*4+L56B440]
    CODE_FILL 15 ; ALIGN 16
L56D0C0:
    mov eax,ecx
    shr eax,4
    jmp dword ptr [eax*4+L56B4C0]
    CODE_FILL 20 ; ALIGN 32
L56D0E0:
    shr ecx,2
    mov eax,edi
    and eax,3
    or al,byte ptr [ecx+length_index]
    or al,byte ptr ds:[state_88C048]
    jmp dword ptr [eax*4+plain_copy_table]
    CODE_FILL 5  ; ALIGN 16
L56D100:
    shl ecx,4
    xor ebx,ebx
    mov cl,byte ptr [esi]
    sub bl,ch
    mov eax,edi
    and bl,80h
    and eax,3
    or bl,cl
    or al,byte ptr ds:[state_88C048]
    or al,byte ptr [ebx+length_index]
    inc esi
    jmp dword ptr [eax*4+plain_copy_table]
    CODE_FILL 25 ; ALIGN 32
L56D140:
    shr ecx,2
    add edi,ecx
    jmp dword ptr ds:[draw_resume]
L56D14B:
    shl ecx,4
    mov cl,byte ptr [esi]
    inc esi
    add edi,ecx
    jmp dword ptr ds:[draw_resume]
    CODE_FILL 7  ; ALIGN 16
L56D160:
    shr ecx,4
    jne SHORT L56D168
    mov cl,byte ptr [esi]
    inc esi
L56D168:
    mov eax,edi
    and eax,3
    or al,byte ptr [ecx+length_index]
    mov ebx,dword ptr ds:[color_xform]
    or al,byte ptr ds:[state_88C048]
    jmp dword ptr [eax*4+L56AB00]
    CODE_FILL 26 ; ALIGN 32
L56D1A0:
    shr ecx,4
    jne SHORT L56D1A8
    mov cl,byte ptr [esi]
    inc esi
L56D1A8:
    mov al,byte ptr [esi]
    mov ebx,edi
    mov ah,al
    and ebx,3
    shl eax,10h
    or bl,byte ptr [ecx+length_index]
    mov al,byte ptr [esi]
    or bl,byte ptr ds:[state_88C048]
    inc esi
    mov ah,al
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    jmp dword ptr [ebx*4+solid_fill_table]
    CODE_FILL 8  ; ALIGN 16
L56D1E0:
    shr ecx,4
    jne SHORT L56D1E8
    mov cl,byte ptr [esi]
    inc esi
L56D1E8:
    mov al,byte ptr [esi]
    mov ebx,edi
    mov ah,al
    and ebx,3
    shl eax,10h
    or bl,byte ptr [ecx+length_index]
    mov al,byte ptr [esi]
    or bl,byte ptr ds:[state_88C048]
    inc esi
    mov ah,al
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C034]
    jmp dword ptr [ebx*4+solid_fill_table]
    CODE_FILL 8  ; ALIGN 16
L56D220:
    shr ecx,4
    jne SHORT L56D228
    mov cl,byte ptr [esi]
    inc esi
L56D228:
    mov eax,edi
    and eax,3
    or al,byte ptr [ecx+length_index]
    mov ebx,dword ptr ds:[xlate_table]
    or al,byte ptr ds:[state_88C048]
    xor edx,edx
    jmp dword ptr [eax*4+L56AF00]
    CODE_FILL 24 ; ALIGN 32
L56D260:
    mov cl,byte ptr [esi]
    inc esi
    jmp SHORT L56D26A
L56D265:
    mov ecx,1
L56D26A:
    cmp dword ptr ds:[state_88C058],0
    je SHORT L56D29C
    mov eax,dword ptr ds:[state_88C05C]
    mov ebx,edi
    and eax,dword ptr ds:[state_88C02C]
    and ebx,3
    or eax,dword ptr ds:[state_88C030]
    or bl,byte ptr [ecx+length_index]
    or bl,byte ptr ds:[state_88C048]
    jmp dword ptr [ebx*4+solid_fill_table]
L56D29C:
    add edi,ecx
    jmp dword ptr ds:[draw_resume]
    CODE_FILL 28 ; ALIGN 32
L56D2C0:
    mov al,byte ptr [esi]
    call L56DB60
    add edi,ecx
    jmp NEAR PTR L56D0A0
L56D2CE:
    int 3
    jmp dword ptr ds:[draw_resume]
    CODE_FILL 11 ; ALIGN 16
L56D2E0:
    mov eax,dword ptr ds:[draw_length]
    inc eax
    mov dword ptr ds:[draw_length],eax
    cmp eax,dword ptr [ebp+18h]
    jl NEAR PTR L56CAA0
L56D2F4:
    pop edi
    pop esi
    pop ebx
    pop ebp
    ret
    CODE_FILL 7  ; ALIGN 16
L56D300:
    mov eax,dword ptr [ebp+10h]
    mov ebx,dword ptr ds:[draw_length]
    add eax,ebx
    mov esi,dword ptr ds:[span_tails]
    mov edi,dword ptr [esi+eax*4]
    or edi,edi
    je NEAR PTR L56DB40
    mov dword ptr ds:[draw_span],edi
    test byte ptr ds:[state_88C048],80h
    je SHORT L56D356
    and eax,3
    mov edx,dword ptr [eax*4+shadow_value]
    mov ecx,dword ptr [eax*4+shadow_mask]
    mov eax,dword ptr ds:[color_xform]
    mov dword ptr ds:[state_88C030],edx
    mov dword ptr ds:[state_88C02C],ecx
    and eax,ecx
    or eax,edx
    mov dword ptr ds:[state_88C034],eax
L56D356:
    mov esi,dword ptr ds:[state_88C010]
    xor eax,eax
    mov ax,word ptr [esi+ebx*4+2]
    mov edx,dword ptr ds:[state_88C024]
    test eax,8000h
    jne NEAR PTR L56DB40
    add edx,eax
    mov ax,word ptr [esi+ebx*4]
    mov ecx,dword ptr ds:[state_88C028]
    sub ecx,eax
    mov esi,dword ptr ds:[surface_offsets]
    mov eax,dword ptr [ebp+10h]
    add eax,ebx
    mov eax,dword ptr [esi+eax*4]
    mov dword ptr ds:[draw_row_base],eax
    add eax,ecx
    mov dword ptr ds:[draw_pixel_ptr],eax
    mov esi,dword ptr ds:[state_88C00C]
    mov eax,dword ptr [esi+ebx*4]
    add eax,dword ptr [ebp+8]
    mov dword ptr ds:[state_88C018],eax
L56D3AD:
    cmp edx,dword ptr [edi+0Ch]
    jg NEAR PTR L56DB40
    cmp ecx,dword ptr [edi+8]
    jge SHORT L56D3C7
    mov edi,dword ptr [edi+4]
    or edi,edi
    jne SHORT L56D3AD
    jmp NEAR PTR L56DB40
L56D3C7:
    cmp edx,dword ptr [edi+8]
    jl SHORT L56D3E9
    cmp ecx,dword ptr [edi+0Ch]
    jg SHORT L56D3E9
    mov eax,OFFSET L56D420
    mov dword ptr ds:[draw_resume],eax
    mov edi,dword ptr ds:[draw_pixel_ptr]
    mov esi,dword ptr ds:[state_88C018]
    jmp SHORT L56D420
L56D3E9:
    mov eax,OFFSET L56D6C0
    mov dword ptr ds:[draw_resume],eax
    mov dword ptr ds:[draw_span],edi
    mov edi,dword ptr ds:[draw_pixel_ptr]
    mov esi,dword ptr ds:[state_88C018]
    jmp NEAR PTR L56D6C0
    CODE_FILL 22 ; ALIGN 32
L56D420:
    xor eax,eax
    mov al,byte ptr [esi]
    mov ecx,eax
    and eax,0Fh
    inc esi
    jmp dword ptr [eax*4+L56B540]
    CODE_FILL 15 ; ALIGN 16
L56D440:
    mov eax,ecx
    shr eax,4
    jmp dword ptr [eax*4+L56B5C0]
    CODE_FILL 20 ; ALIGN 32
L56D460:
    shr ecx,2
    mov eax,edi
    and eax,3
    or al,byte ptr [ecx+length_index]
    or al,byte ptr ds:[state_88C048]
    jmp dword ptr [eax*4+L56B600]
    CODE_FILL 5  ; ALIGN 16
L56D480:
    shl ecx,4
    xor ebx,ebx
    mov cl,byte ptr [esi]
    sub bl,ch
    mov eax,edi
    and bl,80h
    and eax,3
    or bl,cl
    or al,byte ptr ds:[state_88C048]
    or al,byte ptr [ebx+length_index]
    inc esi
    jmp dword ptr [eax*4+L56B600]
    CODE_FILL 25 ; ALIGN 32
L56D4C0:
    shr ecx,2
    sub edi,ecx
    jmp dword ptr ds:[draw_resume]
L56D4CB:
    shl ecx,4
    mov cl,byte ptr [esi]
    inc esi
    sub edi,ecx
    jmp dword ptr ds:[draw_resume]
    CODE_FILL 7  ; ALIGN 16
L56D4E0:
    shr ecx,4
    jne SHORT L56D4E8
    mov cl,byte ptr [esi]
    inc esi
L56D4E8:
    mov eax,edi
    and eax,3
    or al,byte ptr [ecx+length_index]
    mov ebx,dword ptr ds:[color_xform]
    or al,byte ptr ds:[state_88C048]
    jmp dword ptr [eax*4+L56BE00]
    CODE_FILL 26 ; ALIGN 32
L56D520:
    shr ecx,4
    jne SHORT L56D528
    mov cl,byte ptr [esi]
    inc esi
L56D528:
    mov al,byte ptr [esi]
    mov ebx,edi
    mov ah,al
    and ebx,3
    shl eax,10h
    or bl,byte ptr [ecx+length_index]
    mov al,byte ptr [esi]
    or bl,byte ptr ds:[state_88C048]
    inc esi
    mov ah,al
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    jmp dword ptr [ebx*4+L56BA00]
    CODE_FILL 8  ; ALIGN 16
L56D560:
    shr ecx,4
    jne SHORT L56D568
    mov cl,byte ptr [esi]
    inc esi
L56D568:
    mov al,byte ptr [esi]
    mov ebx,edi
    mov ah,al
    and ebx,3
    shl eax,10h
    or bl,byte ptr [ecx+length_index]
    mov al,byte ptr [esi]
    or bl,byte ptr ds:[state_88C048]
    inc esi
    mov ah,al
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C034]
    jmp dword ptr [ebx*4+L56BA00]
    CODE_FILL 8  ; ALIGN 16
L56D5A0:
    shr ecx,4
    jne SHORT L56D5A8
    mov cl,byte ptr [esi]
    inc esi
L56D5A8:
    mov eax,edi
    and eax,3
    or al,byte ptr [ecx+length_index]
    mov ebx,dword ptr ds:[xlate_table]
    or al,byte ptr ds:[state_88C048]
    xor edx,edx
    jmp dword ptr [eax*4+L56C200]
    CODE_FILL 24 ; ALIGN 32
L56D5E0:
    mov cl,byte ptr [esi]
    inc esi
    jmp SHORT L56D5EA
L56D5E5:
    mov ecx,1
L56D5EA:
    cmp dword ptr ds:[state_88C058],0
    je SHORT L56D61C
    mov eax,dword ptr ds:[state_88C05C]
    mov ebx,edi
    and eax,dword ptr ds:[state_88C02C]
    and ebx,3
    or eax,dword ptr ds:[state_88C030]
    or bl,byte ptr [ecx+length_index]
    or bl,byte ptr ds:[state_88C048]
    jmp dword ptr [ebx*4+L56BA00]
L56D61C:
    sub edi,ecx
    jmp dword ptr ds:[draw_resume]
    CODE_FILL 28 ; ALIGN 32
L56D640:
    mov al,byte ptr [esi]
    call L56DB60
    add edi,ecx
    jmp NEAR PTR L56D420
    CODE_FILL 18 ; ALIGN 32
L56D660:
    mov esi,dword ptr ds:[state_88C050]
    mov edi,dword ptr ds:[state_88C054]
    mov ebx,dword ptr ds:[draw_span]
    mov ebx,dword ptr [ebx+4]
    or ebx,ebx
    je NEAR PTR L56DB40
    mov dword ptr ds:[draw_resume],OFFSET L56D6C0
    xor eax,eax
    mov al,byte ptr [esi]
    sub edi,dword ptr ds:[draw_row_base]
    mov ecx,eax
    inc esi
    and eax,0Fh
    mov dword ptr ds:[draw_span],ebx
    jmp dword ptr [eax*4+L56B500]
    CODE_FILL 28 ; ALIGN 32
L56D6C0:
    mov dword ptr ds:[state_88C050],esi
    xor eax,eax
    mov dword ptr ds:[state_88C054],edi
    mov al,byte ptr [esi]
    sub edi,dword ptr ds:[draw_row_base]
    mov ecx,eax
    inc esi
    and eax,0Fh
    mov ebx,dword ptr ds:[draw_span]
    jmp dword ptr [eax*4+L56B500]
    CODE_FILL 23 ; ALIGN 32
L56D700:
    mov eax,ecx
    shr eax,4
    jmp dword ptr [eax*4+L56B580]
    CODE_FILL 20 ; ALIGN 32
L56D720:
    shr ecx,2
    jmp SHORT L56D72B
L56D725:
    shl ecx,4
    mov cl,byte ptr [esi]
    inc esi
L56D72B:
    mov edx,edi
    sub edx,ecx
    inc edx
L56D730:
    cmp edx,dword ptr [ebx+0Ch]
    jg SHORT L56D792
    cmp edi,dword ptr [ebx+8]
    jl SHORT L56D7A1
    xor eax,eax
    cmp edi,dword ptr [ebx+0Ch]
    jle SHORT L56D74A
    mov eax,edi
    sub eax,dword ptr [ebx+0Ch]
    add esi,eax
    sub ecx,eax
L56D74A:
    mov dword ptr ds:[draw_clip_skip],eax
    cmp edx,dword ptr [ebx+8]
    jge SHORT L56D765
    mov eax,dword ptr [ebx+8]
    sub eax,edx
    sub ecx,eax
    mov dword ptr ds:[draw_resume],OFFSET L56D660
L56D765:
    mov edi,dword ptr ds:[state_88C054]
    xor ebx,ebx
    sub edi,dword ptr ds:[draw_clip_skip]
    sub bl,ch
    mov eax,edi
    and bl,80h
    and eax,3
    or bl,cl
    or al,byte ptr ds:[state_88C048]
    or al,byte ptr [ebx+length_index]
    jmp dword ptr [eax*4+L56B600]
L56D792:
    mov edi,dword ptr ds:[state_88C054]
    add esi,ecx
    sub edi,ecx
    jmp NEAR PTR L56D6C0
L56D7A1:
    mov ebx,dword ptr [ebx+4]
    or ebx,ebx
    jne SHORT L56D730
    jmp NEAR PTR L56DB40
    CODE_FILL 19 ; ALIGN 32
L56D7C0:
    shr ecx,2
    mov edi,dword ptr ds:[state_88C054]
    sub edi,ecx
    jmp dword ptr ds:[draw_resume]
L56D7D1:
    shl ecx,4
    mov edi,dword ptr ds:[state_88C054]
    mov cl,byte ptr [esi]
    inc esi
    sub edi,ecx
    jmp dword ptr ds:[draw_resume]
    CODE_FILL 27 ; ALIGN 32
L56D800:
    shr ecx,4
    jne SHORT L56D808
    mov cl,byte ptr [esi]
    inc esi
L56D808:
    mov edx,edi
    sub edx,ecx
    inc edx
L56D80D:
    cmp edx,dword ptr [ebx+0Ch]
    jg SHORT L56D86C
    cmp edi,dword ptr [ebx+8]
    jl SHORT L56D87B
    xor eax,eax
    cmp edi,dword ptr [ebx+0Ch]
    jle SHORT L56D827
    mov eax,edi
    sub eax,dword ptr [ebx+0Ch]
    add esi,eax
    sub ecx,eax
L56D827:
    mov dword ptr ds:[draw_clip_skip],eax
    cmp edx,dword ptr [ebx+8]
    jge SHORT L56D842
    mov eax,dword ptr [ebx+8]
    sub eax,edx
    sub ecx,eax
    mov dword ptr ds:[draw_resume],OFFSET L56D660
L56D842:
    mov edi,dword ptr ds:[state_88C054]
    sub edi,dword ptr ds:[draw_clip_skip]
    mov eax,edi
    and eax,3
    or al,byte ptr [ecx+length_index]
    mov ebx,dword ptr ds:[color_xform]
    or al,byte ptr ds:[state_88C048]
    jmp dword ptr [eax*4+L56BE00]
L56D86C:
    mov edi,dword ptr ds:[state_88C054]
    add esi,ecx
    sub edi,ecx
    jmp NEAR PTR L56D6C0
L56D87B:
    mov ebx,dword ptr [ebx+4]
    or ebx,ebx
    jne SHORT L56D80D
    jmp NEAR PTR L56DB40
    CODE_FILL 25 ; ALIGN 32
L56D8A0:
    shr ecx,4
    jne SHORT L56D8A8
    mov cl,byte ptr [esi]
    inc esi
L56D8A8:
    mov edx,edi
    sub edx,ecx
    inc edx
L56D8AD:
    cmp edx,dword ptr [ebx+0Ch]
    jg SHORT L56D91C
    cmp edi,dword ptr [ebx+8]
    jl SHORT L56D92A
    xor eax,eax
    cmp edi,dword ptr [ebx+0Ch]
    jle SHORT L56D8C5
    mov eax,edi
    sub eax,dword ptr [ebx+0Ch]
    sub ecx,eax
L56D8C5:
    mov dword ptr ds:[draw_clip_skip],eax
    cmp edx,dword ptr [ebx+8]
    jge SHORT L56D8E0
    mov eax,dword ptr [ebx+8]
    sub eax,edx
    sub ecx,eax
    mov dword ptr ds:[draw_resume],OFFSET L56D660
L56D8E0:
    mov edi,dword ptr ds:[state_88C054]
    mov al,byte ptr [esi]
    sub edi,dword ptr ds:[draw_clip_skip]
    mov ah,al
    mov ebx,edi
    shl eax,10h
    and ebx,3
    mov al,byte ptr [esi]
    or bl,byte ptr [ecx+length_index]
    mov ah,al
    or bl,byte ptr ds:[state_88C048]
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C030]
    inc esi
    jmp dword ptr [ebx*4+L56BA00]
L56D91C:
    mov edi,dword ptr ds:[state_88C054]
    inc esi
    sub edi,ecx
    jmp NEAR PTR L56D6C0
L56D92A:
    mov ebx,dword ptr [ebx+4]
    or ebx,ebx
    jne NEAR PTR L56D8AD
    jmp NEAR PTR L56DB40
    CODE_FILL 6  ; ALIGN 16
L56D940:
    shr ecx,4
    jne SHORT L56D948
    mov cl,byte ptr [esi]
    inc esi
L56D948:
    mov edx,edi
    sub edx,ecx
    inc edx
L56D94D:
    cmp edx,dword ptr [ebx+0Ch]
    jg SHORT L56D9BC
    cmp edi,dword ptr [ebx+8]
    jl SHORT L56D9CA
    xor eax,eax
    cmp edi,dword ptr [ebx+0Ch]
    jle SHORT L56D965
    mov eax,edi
    sub eax,dword ptr [ebx+0Ch]
    sub ecx,eax
L56D965:
    mov dword ptr ds:[draw_clip_skip],eax
    cmp edx,dword ptr [ebx+8]
    jge SHORT L56D980
    mov eax,dword ptr [ebx+8]
    sub eax,edx
    sub ecx,eax
    mov dword ptr ds:[draw_resume],OFFSET L56D660
L56D980:
    mov edi,dword ptr ds:[state_88C054]
    mov al,byte ptr [esi]
    sub edi,dword ptr ds:[draw_clip_skip]
    mov ah,al
    mov ebx,edi
    shl eax,10h
    and ebx,3
    mov al,byte ptr [esi]
    or bl,byte ptr [ecx+length_index]
    mov ah,al
    or bl,byte ptr ds:[state_88C048]
    inc esi
    and eax,dword ptr ds:[state_88C02C]
    or eax,dword ptr ds:[state_88C034]
    jmp dword ptr [ebx*4+L56BA00]
L56D9BC:
    mov edi,dword ptr ds:[state_88C054]
    inc esi
    sub edi,ecx
    jmp NEAR PTR L56D6C0
L56D9CA:
    mov ebx,dword ptr [ebx+4]
    or ebx,ebx
    jne NEAR PTR L56D94D
    jmp NEAR PTR L56DB40
    CODE_FILL 6  ; ALIGN 16
L56D9E0:
    shr ecx,4
    jne SHORT L56D9E8
    mov cl,byte ptr [esi]
    inc esi
L56D9E8:
    mov edx,edi
    sub edx,ecx
    inc edx
L56D9ED:
    cmp edx,dword ptr [ebx+0Ch]
    jg SHORT L56DA4C
    cmp edi,dword ptr [ebx+8]
    jl SHORT L56DA59
    xor eax,eax
    cmp edi,dword ptr [ebx+0Ch]
    jle SHORT L56DA05
    mov eax,edi
    sub eax,dword ptr [ebx+0Ch]
    sub ecx,eax
L56DA05:
    mov dword ptr ds:[draw_clip_skip],eax
    cmp edx,dword ptr [ebx+8]
    jge SHORT L56DA20
    mov eax,dword ptr [ebx+8]
    sub eax,edx
    sub ecx,eax
    mov dword ptr ds:[draw_resume],OFFSET L56D660
L56DA20:
    mov edi,dword ptr ds:[state_88C054]
    sub edi,dword ptr ds:[draw_clip_skip]
    mov eax,edi
    and eax,3
    or al,byte ptr [ecx+length_index]
    mov ebx,dword ptr ds:[xlate_table]
    or al,byte ptr ds:[state_88C048]
    xor edx,edx
    jmp dword ptr [eax*4+L56C200]
L56DA4C:
    mov edi,dword ptr ds:[state_88C054]
    sub edi,ecx
    jmp NEAR PTR L56D6C0
L56DA59:
    mov ebx,dword ptr [ebx+4]
    or ebx,ebx
    jne SHORT L56D9ED
    jmp NEAR PTR L56DB40
    CODE_FILL 27 ; ALIGN 32
L56DA80:
    mov cl,byte ptr [esi]
    inc esi
    jne SHORT L56DA8A
L56DA85:
    mov ecx,1
L56DA8A:
    cmp dword ptr ds:[state_88C058],0
    je SHORT L56DB00
    mov edx,edi
    sub edx,ecx
    inc edx
L56DA98:
    cmp edx,dword ptr [ebx+0Ch]
    jg SHORT L56DB00
    cmp edi,dword ptr [ebx+8]
    jl SHORT L56DB0D
    xor eax,eax
    cmp edi,dword ptr [ebx+0Ch]
    jle SHORT L56DAB0
    mov eax,edi
    sub eax,dword ptr [ebx+0Ch]
    sub ecx,eax
L56DAB0:
    mov dword ptr ds:[draw_clip_skip],eax
    cmp edx,dword ptr [ebx+8]
    jge SHORT L56DACB
    mov eax,dword ptr [ebx+8]
    sub eax,edx
    sub ecx,eax
    mov dword ptr ds:[draw_resume],OFFSET L56D660
L56DACB:
    mov edi,dword ptr ds:[state_88C054]
    mov eax,dword ptr ds:[state_88C05C]
    sub edi,dword ptr ds:[draw_clip_skip]
    and eax,dword ptr ds:[state_88C02C]
    mov ebx,edi
    or eax,dword ptr ds:[state_88C030]
    and ebx,3
    or bl,byte ptr [ecx+length_index]
    or bl,byte ptr ds:[state_88C048]
    jmp dword ptr [ebx*4+L56BA00]
L56DB00:
    mov edi,dword ptr ds:[state_88C054]
    sub edi,ecx
    jmp NEAR PTR L56D6C0
L56DB0D:
    mov ebx,dword ptr [ebx+4]
    or ebx,ebx
    jne SHORT L56DA98
    jmp SHORT L56DB40
    CODE_FILL 10 ; ALIGN 16
L56DB20:
    mov al,byte ptr [esi]
    call L56DB60
    add edi,ecx
    jmp NEAR PTR L56D6C0
    CODE_FILL 18 ; ALIGN 32
L56DB40:
    mov eax,dword ptr ds:[draw_length]
    inc eax
    mov dword ptr ds:[draw_length],eax
    cmp eax,dword ptr [ebp+18h]
    jl NEAR PTR L56D300
    pop edi
    pop esi
    pop ebx
    pop ebp
    ret
    CODE_FILL 7  ; ALIGN 16
L56DB60:
    xor eax,eax
    mov al,byte ptr [esi]
    mov ecx,eax
    inc esi
    and eax,0Fh
    jmp dword ptr [eax*4+L56C600]
L56DB71:
    shr ecx,2
    add esi,ecx
    ret
L56DB77:
    shr ecx,2
    ret
L56DB7B:
    shl ecx,4
    mov cl,byte ptr [esi]
    inc esi
    add esi,ecx
    ret
L56DB84:
    shl ecx,4
    mov cl,byte ptr [esi]
    inc esi
    ret
L56DB8B:
    shr ecx,4
    jne SHORT L56DB93
    mov cl,byte ptr [esi]
    inc esi
L56DB93:
    add esi,ecx
    ret
L56DB96:
    shr ecx,4
    jne SHORT L56DB9E
    mov cl,byte ptr [esi]
    inc esi
L56DB9E:
    inc esi
    ret
L56DBA0:
    shr ecx,4
    jne SHORT L56DBA8
    mov cl,byte ptr [esi]
    inc esi
L56DBA8:
    ret
L56DBA9:
    mov eax,ecx
    shr eax,4
    jmp dword ptr [eax*4+L56C640]
L56DBB5:
    mov ecx,0
    ret
L56DBBB:
    int 3
    mov ecx,0
    ret
L56DBC2:
    mov ecx,1
    ret
L56DBC8:
    mov cl,byte ptr [esi]
    inc esi
    ret
L56DBCC:
    int 3
    mov ecx,0
    ret
L56DBD3:
    int 3
    mov ecx,0
    ret
L56DBDA:
    int 3
    mov ecx,0
    ret
THIS_COD ENDS

END
