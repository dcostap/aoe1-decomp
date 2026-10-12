; Inf32: the hand-written DEFLATE decoder from compress.lib (Inf32.obj).
;
; ESI points at the caller-supplied state buffer for the whole decoder. The decoder
; keeps its own stack and registers there, so it can suspend when input runs out
; or output fills up and resume on the next Inf32Decode call. Register use inside
; the bit reader: DL holds the current input byte, CH the bits left in it, and DH
; receives each new byte from next_byte.
.386
.model flat
option casemap:none

PUBLIC _Inf32BufSize
PUBLIC _Inf32Decode

_TEXT SEGMENT
length_order    DWORD 40h, 44h, 48h, 0, 20h, 1Ch, 24h, 18h
                DWORD 28h, 14h, 2Ch, 10h, 30h, 0Ch, 34h, 8
                DWORD 38h, 4, 3Ch
length_extra    DWORD 0, 0, 0, 0, 0, 0, 0, 0
                DWORD 1, 1, 1, 1, 2, 2, 2, 2
                DWORD 3, 3, 3, 3, 4, 4, 4, 4
                DWORD 5, 5, 5, 5, 0, 63h, 63h
length_base     DWORD 3, 4, 5, 6, 7, 8, 9, 0Ah
                DWORD 0Bh, 0Dh, 0Fh, 11h, 13h, 17h, 1Bh, 1Fh
                DWORD 23h, 2Bh, 33h, 3Bh, 43h, 53h, 63h, 73h
                DWORD 83h, 0A3h, 0C3h, 0E3h, 102h, 0, 0
distance_extra  DWORD 0, 0, 0, 0, 1, 1, 2, 2
                DWORD 3, 3, 4, 4, 5, 5, 6, 6
                DWORD 7, 7, 8, 8, 9, 9, 0Ah, 0Ah
                DWORD 0Bh, 0Bh, 0Ch, 0Ch, 0Dh, 0Dh
distance_base   DWORD 1, 2, 3, 4, 5, 7, 9, 0Dh
                DWORD 11h, 19h, 21h, 31h, 41h, 61h, 81h, 0C1h
                DWORD 101h, 181h, 201h, 301h, 401h, 601h, 801h, 0C01h
                DWORD 1001h, 1801h, 2001h, 3001h, 4001h, 6001h
resume_table    DWORD start_stream, resume_next_byte, resume_flush_window, stored_block, fixed_block, dynamic_block, invalid_block

; Build a lookup table and overflow tree from code lengths; CF set on bad lengths.
build_decode_table: ; original 0054A870
    push eax
    push ebx
    push ecx
    push edx
    push edi
    push ebp
    lea edi,[esi+8274h]
    mov ecx,11h
    xor eax,eax
    rep stosd
    push ebx
    push esi
    mov ecx,[ebx]
    lea eax,[esi+8274h]
    mov esi,[ebx+8]
    mov ebx,eax
L54A894:
    mov edi,[esi]
    add esi,4
    inc dword ptr [ebx+edi*4]
    dec ecx
    jne SHORT L54A894
    pop esi
    pop ebx
    push esi
    lea edi,[esi+8234h]
    lea esi,[esi+8278h]
    xor eax,eax
    stosd
    mov cl,0Fh
L54A8B3:
    add eax,[esi]
    add esi,4
    add eax,eax
    mov [edi],eax
    add edi,4
    dec ecx
    jne SHORT L54A8B3
    pop esi
    cmp eax,10000h
    je SHORT L54A8E9
    push esi
    lea esi,[esi+8278h]
    mov cl,10h
    xor edx,edx
L54A8D5:
    add edx,[esi]
    add esi,4
    dec ecx
    jne SHORT L54A8D5
    pop esi
    cmp edx,1
    jbe SHORT L54A8E9
    stc
    jmp NEAR PTR L54A984
L54A8E9:
    push esi
    push ebx
    lea edx,[esi+8230h]
    mov edi,[ebx+4]
    mov ecx,[ebx]
    mov esi,[ebx+8]
L54A8F9:
    mov eax,[esi]
    add esi,4
    and eax,eax
    je SHORT L54A909
    lea ebx,[edx+eax*4]
    mov eax,[ebx]
    inc dword ptr [ebx]
L54A909:
    mov [edi],eax
    add edi,4
    dec ecx
    jne SHORT L54A8F9
    pop ebx
    pop esi
    mov edi,[ebx+0Ch]
    mov ecx,100h
    xor eax,eax
    rep stosd
    mov edi,[ebx+10h]
    mov ecx,[ebx]
    shl ecx,1
    rep stosd
    push esi
    mov esi,[ebx+8]
    mov ecx,[ebx]
    mov ebp,0FFFFFFFFh
L54A933:
    mov eax,[esi]
    add esi,4
    and eax,eax
    je SHORT L54A97F
    push ecx
    push ebx
    push esi
    sub esi,[ebx+8]
    sub esi,4
    mov edi,esi
    add edi,[ebx+4]
    mov edx,[edi]
    mov ecx,eax
    xor edi,edi
L54A950:
    shr edx,1
    rcl edi,1
    dec ecx
    jne SHORT L54A950
    mov ecx,eax
    cmp cl,8
    ja SHORT L54A98B
    mov edx,4
    shl edx,cl
    mov eax,100h
    shr eax,cl
    mov ecx,eax
    shl edi,2
    mov ebx,[ebx+0Ch]
L54A974:
    mov [edi+ebx],esi
    add edi,edx
    dec ecx
    jne SHORT L54A974
L54A97C:
    pop esi
    pop ebx
    pop ecx
L54A97F:
    dec ecx
    jne SHORT L54A933
    pop esi
    clc
L54A984:
    pop ebp
    pop edi
    pop edx
    pop ecx
    pop ebx
    pop eax
    ret
L54A98B:
    mov eax,edi
    and edi,0FFh
    shl edi,2
    add edi,[ebx+0Ch]
    mov edx,[edi]
    and edx,edx
    je SHORT L54A9D5
L54A99F:
    mov ebx,[ebx+10h]
    sub cl,9
    je SHORT L54A9B9
L54A9A7:
    mov edi,edx
    not edi
    shr ah,1
    adc edi,0
    mov edx,[ebx+edi*4]
    and edx,edx
    loopne L54A9A7
    je SHORT L54A9C7
L54A9B9:
    mov edi,edx
    not edi
    shr ah,1
    adc edi,0
    mov [ebx+edi*4],esi
    jmp SHORT L54A97C
L54A9C7:
    mov [ebx+edi*4],ebp
    mov edx,ebp
    sub ebp,2
    and ecx,ecx
    jne SHORT L54A9A7
    jmp SHORT L54A9B9
L54A9D5:
    mov [edi],ebp
    mov edx,ebp
    sub ebp,2
    jmp SHORT L54A99F

; Write consumed input and produced output back to the caller.
store_counts: ; original 0054A9DE
    push eax
    push ebp
    push edi
    mov ebp,[esi+0AD88h]
    mov edi,[ebp+10h]
    mov eax,[esi+822Ch]
    sub eax,[esi+8224h]
    mov [edi],eax
    mov edi,[ebp+1Ch]
    mov eax,[esi+8218h]
    sub eax,[esi+8210h]
    mov [edi],eax
    pop edi
    pop ebp
    pop eax
    ret

; Save registers and the decoder's stack, then leave Inf32Decode.
suspend_decoder: ; original 0054AA0D
    mov [esi+0AD64h],eax
    mov [esi+0AD68h],ebx
    mov [esi+0AD6Ch],ecx
    mov [esi+0AD70h],edx
    mov [esi+0AD74h],ebp
    mov [esi+0AD78h],edi
    pop ebx
    mov ecx,[esi+0AD8Ch]
    sub ecx,esp
    shr ecx,2
    mov [esi+0AD60h],ecx
    lea edi,[esi+0A95Ch]
L54AA49:
    pop eax
    mov [edi],eax
    add edi,4
    dec ecx
    jne SHORT L54AA49
    sub edi,4
    mov [esi+0AD5Ch],edi
    jmp ebx

; Restore the saved stack and registers and continue where decoding stopped.
resume_decoder: ; original 0054AA5D
    pop dword ptr [esi+0AD7Ch]
    mov ebx,[esi+0AD5Ch]
    mov ecx,[esi+0AD60h]
L54AA6F:
    push dword ptr [ebx]
    sub ebx,4
    dec ecx
    jne SHORT L54AA6F
    mov eax,[esi+0AD64h]
    mov ebx,[esi+0AD68h]
    mov ecx,[esi+0AD6Ch]
    mov edx,[esi+0AD70h]
    mov ebp,[esi+0AD74h]
    mov edi,[esi+0AD78h]
    jmp dword ptr [esi+0AD7Ch]

; Copy ECX bytes from ESI to EDI, dword-aligning EDI first.
copy_bytes: ; original 0054AAA1
    jecxz L54AABB
    test edi,3
    je SHORT L54AAAF
    movsb
    dec ecx
    jmp SHORT copy_bytes
L54AAAF:
    push ecx
    shr ecx,2
    rep movsd
    pop ecx
    and ecx,3
    rep movsb
L54AABB:
    ret

; Load the next input byte into DH, suspending when input runs out.
next_byte: ; original 0054AABC
    cmp dword ptr [esi+8224h],0
    je SHORT L54AADD
    push ebx
    mov ebx,[esi+8220h]
    mov dh,[ebx]
    inc ebx
    mov [esi+8220h],ebx
    pop ebx
    dec dword ptr [esi+8224h]
    ret
L54AADD:
    cmp dword ptr [esi+0AD80h],0
    je SHORT L54AAE9
    mov dh,0FFh
    ret
L54AAE9:
    mov dword ptr [esi+0A958h],1
    call store_counts
    call suspend_decoder
    jmp NEAR PTR return_suspended

; Resume point after input ran out.
resume_next_byte: ; original 0054AB02
    call resume_decoder
    jmp SHORT next_byte
    xchg ebx,ebx            ; ALIGN 4 filler from the original assembler
    nop                     ; ALIGN 4 filler from the original assembler

; Discard CL bits from the bit buffer; CH counts bits left in DL.
drop_bits: ; original 0054AB0C
    sub ch,cl
    ja SHORT L54AB20
    add cl,ch
    shr edx,cl
    call next_byte
    mov cl,ch
    neg cl
    add ch,8
L54AB20:
    shr edx,cl
    ret
    nop                     ; ALIGN 4 filler from the original assembler

; Move to the next input byte after the current one is used up.
refill_bits: ; original 0054AB24
    mov cl,ch
    shr edx,cl
    call next_byte
    mov cl,8
    sub cl,ch
    shr edx,cl
    ret

; Read CL bits into EAX.
get_bits: ; original 0054AB34
    cmp cl,8
    ja SHORT L54AB5A
    mov eax,1
    shl eax,cl
    dec eax
    and eax,edx
    sub ch,cl
    ja SHORT L54AB57
    add cl,ch
    shr edx,cl
    call next_byte
    mov cl,ch
    neg cl
    add ch,8
L54AB57:
    shr edx,cl
    ret
L54AB5A:
    sub cl,8
    mov al,dl
    mov ah,ch
    xchg cl,ch
    shr edx,cl
    call next_byte
    mov cl,8
    sub cl,ah
    shr edx,cl
    mov cl,ch
    mov ch,ah
    mov ah,1
    shl ah,cl
    dec ah
    and ah,dl
    sub ch,cl
    jbe SHORT L54AB83
    shr edx,cl
    ret
L54AB83:
    add cl,ch
    shr edx,cl
    call next_byte
    mov cl,ch
    neg cl
    shr edx,cl
    add ch,8
    ret
    xchg ebx,ebx            ; ALIGN 4 filler from the original assembler

; Decode one literal/length symbol into EAX.
decode_literal: ; original 0054AB98
    movzx ebx,dl
    mov ebx,[esi+ebx*4+8BC0h]
    mov eax,ebx
    and eax,eax
    js SHORT L54ABB7
    shr eax,2
    mov cl,[ebx+esi+8740h]
    jmp NEAR PTR drop_bits
L54ABB7:
    call refill_bits
L54ABBC:
    not ebx
    dec ch
    jl SHORT L54ABD8
L54ABC2:
    shr edx,1
    adc bl,0
    mov ebx,[esi+ebx*4+8FC0h]
    and ebx,ebx
    js SHORT L54ABBC
    mov eax,ebx
    shr eax,2
    ret
L54ABD8:
    call next_byte
    mov ch,7
    jmp SHORT L54ABC2
    xchg ebx,ebx            ; ALIGN 4 filler from the original assembler
    nop                     ; ALIGN 4 filler from the original assembler

; Decode one distance symbol into EAX.
decode_distance: ; original 0054ABE4
    movzx ebx,dl
    mov ebx,[esi+ebx*4+99C0h]
    mov eax,ebx
    and eax,eax
    js SHORT L54AC03
    shr eax,2
    mov cl,[ebx+esi+9940h]
    jmp NEAR PTR drop_bits
L54AC03:
    call refill_bits
L54AC08:
    not ebx
    dec ch
    jl SHORT L54AC24
L54AC0E:
    shr edx,1
    adc bl,0
    mov ebx,[esi+ebx*4+9DC0h]
    and ebx,ebx
    js SHORT L54AC08
    mov eax,ebx
    shr eax,2
    ret
L54AC24:
    call next_byte
    mov ch,7
    jmp SHORT L54AC0E

; Copy decoded window bytes to the caller, suspending when output is full.
flush_window: ; original 0054AC2D
    push eax
    push ebx
    push ecx
    push edx
    mov eax,[esi+8200h]
    mov [esi+8204h],eax
    sub eax,esi
    mov ebx,esi
L54AC41:
    mov ecx,eax
    cmp ecx,[esi+8210h]
    jbe SHORT L54AC51
    mov ecx,[esi+8210h]
L54AC51:
    sub eax,ecx
    sub [esi+8210h],ecx
    mov edi,[esi+820Ch]
    xchg ebx,esi
    call copy_bytes
    xchg ebx,esi
    mov [esi+820Ch],edi
    cmp dword ptr [esi+8210h],0
    je SHORT L54AC86
L54AC77:
    and eax,eax
    jne SHORT L54AC41
    pop edx
    pop ecx
    pop ebx
    pop eax
    mov [esi+8200h],esi
    ret
L54AC86:
    mov dword ptr [esi+0A958h],2
    call store_counts
    call suspend_decoder
    jmp NEAR PTR return_suspended

; Resume point after output filled up.
resume_flush_window: ; original 0054AC9F
    call resume_decoder
    jmp SHORT L54AC77

; Build the block's tables and decode literals and matches until end of block.
inflate_codes: ; original 0054ACA6
    lea ebx,[esi+0A8E0h]
    call build_decode_table
    jae SHORT L54ACB4
    ret
L54ACB4:
    lea ebx,[esi+0A908h]
    call build_decode_table
    jae SHORT L54ACC2
    ret
L54ACC2:
    mov edi,[esi+8200h]
    jmp SHORT L54ACDC
L54ACCA:
    mov [esi+8200h],edi
    clc
    ret
L54ACD2:
    mov [esi+8200h],edi
    stc
    ret
    xchg ebx,ebx            ; ALIGN 4 filler from the original assembler
L54ACDC:
    call decode_literal
    and ah,ah
    jne SHORT L54AD04
    mov [edi],al
    inc edi
    cmp edi,[esi+8208h]
    jb SHORT L54ACDC
    mov [esi+8200h],edi
    call flush_window
    mov edi,[esi+8200h]
    jmp SHORT L54ACDC
    nop                     ; ALIGN 4 filler from the original assembler
L54AD04:
    and al,al
    je SHORT L54ACCA
    mov cl,BYTE PTR cs:[ebx+length_extra-404h]
    call get_bits
    add eax,cs:[ebx+length_base-404h]
    cmp eax,102h
    ja SHORT L54ACD2
    mov ebp,eax
    call decode_distance
    mov cl,BYTE PTR cs:[ebx+distance_extra]
    call get_bits
    add eax,cs:[ebx+distance_base]
    push esi
    xchg ecx,ebp
    mov ebx,edi
    sub ebx,eax
    jb SHORT L54AD6E
    cmp ebx,esi
    jb SHORT L54AD6E
L54AD49:
    mov esi,ebx
    rep movsb
    pop esi
    mov ecx,ebp
    cmp edi,[esi+8208h]
    jb SHORT L54ACDC
    mov [esi+8200h],edi
    call flush_window
    mov edi,[esi+8200h]
    jmp NEAR PTR L54ACDC
L54AD6E:
    mov eax,esi
    sub eax,ebx
    mov ebx,[esi+8204h]
    sub ebx,eax
    cmp eax,ecx
    jae SHORT L54AD49
    sub ecx,eax
    xchg ecx,eax
    xchg ebx,esi
    rep movsb
    mov ecx,eax
    jmp SHORT L54AD49

; Read dynamic Huffman code lengths.
dynamic_block: ; original 0054AD89
    push ecx
    xor eax,eax
    lea edi,[esi+8740h]
    mov ecx,120h
    rep stosd
    lea edi,[esi+9940h]
    mov ecx,20h
    rep stosd
    lea edi,[esi+9F0Ch]
    mov ecx,13h
    rep stosd
    pop ecx
    mov cl,5
    call get_bits
    add eax,101h
    mov [esi+82B8h],eax
    cmp eax,11Eh
    jbe SHORT L54ADCF
    stc
    ret
L54ADCF:
    mov cl,5
    call get_bits
    inc eax
    mov [esi+82BCh],eax
    cmp eax,1Eh
    jbe SHORT L54ADE4
    stc
    ret
L54ADE4:
    mov cl,4
    call get_bits
    add eax,4
    mov ebp,eax
    mov ebx,OFFSET length_order
    lea edi,[esi+9F0Ch]
L54ADFB:
    mov cl,3
    call get_bits
    push ebx
    mov ebx,cs:[ebx]
    mov [edi+ebx],eax
    pop ebx
    add ebx,4
    dec ebp
    jne SHORT L54ADFB
    lea ebx,[esi+0A930h]
    call build_decode_table
    jae SHORT L54AE1E
    ret
L54AE1E:
    mov ebp,[esi+82BCh]
    add ebp,[esi+82B8h]
    lea edi,[esi+0A3F0h]
L54AE30:
    movzx ebx,dl
    mov ebx,[esi+ebx*4+9F58h]
    mov cl,[ebx+esi+9F0Ch]
    call drop_bits
    mov eax,ebx
    shr eax,2
    cmp al,0Fh
    ja SHORT L54AE55
    stosd
    dec ebp
    jne SHORT L54AE30
    jmp SHORT L54AE91
L54AE55:
    cmp al,10h
    jne SHORT L54AE68
    mov cl,2
    call get_bits
    add eax,3
    mov ebx,[edi-4]
    jmp SHORT L54AE84
L54AE68:
    cmp al,11h
    jne SHORT L54AE78
    mov cl,3
    call get_bits
    add eax,3
    jmp SHORT L54AE82
L54AE78:
    mov cl,7
    call get_bits
    add eax,0Bh
L54AE82:
    xor ebx,ebx
L54AE84:
    xchg ebx,eax
    sub ebp,ebx
    jb SHORT L54AEC2
L54AE89:
    stosd
    dec ebx
    jne SHORT L54AE89
    and ebp,ebp
    jne SHORT L54AE30
L54AE91:
    push ecx
    push esi
    mov ecx,[esi+82B8h]
    lea edi,[esi+8740h]
    lea esi,[esi+0A3F0h]
    rep movsd
    mov ebx,esi
    pop esi
    push esi
    mov ecx,[esi+82BCh]
    lea edi,[esi+9940h]
    mov esi,ebx
    rep movsd
    pop esi
    pop ecx
    jmp NEAR PTR inflate_codes
L54AEC2:
    stc
    ret

; Load the fixed Huffman code lengths.
fixed_block: ; original 0054AEC4
    push ecx
    lea edi,[esi+8740h]
    mov ecx,90h
    mov eax,8
    rep stosd
    mov ecx,70h
    mov eax,9
    rep stosd
    mov ecx,18h
    mov eax,7
    rep stosd
    mov ecx,8
    mov eax,8
    rep stosd
    lea edi,[esi+9940h]
    mov ecx,20h
    mov eax,5
    rep stosd
    pop ecx
    jmp NEAR PTR inflate_codes

; Copy a stored block.
stored_block: ; original 0054AF13
    cmp ch,8
    je SHORT L54AF1F
    mov cl,ch
    call drop_bits
L54AF1F:
    movzx ecx,dx
    call next_byte
    movzx eax,dh
    call next_byte
    mov ah,dh
    not ax
    cmp eax,ecx
    jne SHORT L54AF6B
    mov edi,[esi+8200h]
    jecxz L54AF53
L54AF40:
    call next_byte
    mov [edi],dh
    inc edi
    cmp edi,[esi+8208h]
    jae SHORT L54AF6D
L54AF50:
    dec ecx
    jne SHORT L54AF40
L54AF53:
    mov [esi+8200h],edi
    xor edx,edx
    call next_byte
    mov dl,dh
    call next_byte
    mov ch,8
    clc
    ret
L54AF6B:
    stc
    ret
L54AF6D:
    mov [esi+8200h],edi
    call flush_window
    mov edi,[esi+8200h]
    jmp SHORT L54AF50

; Read a block header and dispatch on its type.
decode_block: ; original 0054AF80
    mov cl,1
    call get_bits
    mov [esi+0AD84h],eax
    mov cl,2
    call get_bits
    jmp dword ptr cs:resume_table[eax*4+0Ch]
invalid_block: ; original 0054AF9C
    stc
    ret

; Initial state: set up table descriptors and decode blocks until the final one.
start_stream: ; original 0054AF9E
    mov dword ptr [esi+0A8E0h],120h
    lea eax,[esi+82C0h]
    mov [esi+0A8E4h],eax
    lea eax,[esi+8740h]
    mov [esi+0A8E8h],eax
    lea eax,[esi+8BC0h]
    mov [esi+0A8ECh],eax
    lea eax,[esi+8FC0h]
    mov [esi+0A8F0h],eax
    mov dword ptr [esi+0A908h],20h
    lea eax,[esi+98C0h]
    mov [esi+0A90Ch],eax
    lea eax,[esi+9940h]
    mov [esi+0A910h],eax
    lea eax,[esi+99C0h]
    mov [esi+0A914h],eax
    lea eax,[esi+9DC0h]
    mov [esi+0A918h],eax
    mov dword ptr [esi+0A930h],13h
    lea eax,[esi+9EC0h]
    mov [esi+0A934h],eax
    lea eax,[esi+9F0Ch]
    mov [esi+0A938h],eax
    lea eax,[esi+9F58h]
    mov [esi+0A93Ch],eax
    lea eax,[esi+0A358h]
    mov [esi+0A940h],eax
    lea eax,[esi+8000h]
    mov [esi+8204h],eax
    mov [esi+8208h],eax
    mov [esi+8200h],esi
    xor edx,edx
    call next_byte
    mov dl,dh
    call next_byte
    mov ch,8
L54B074:
    call decode_block
    jb SHORT L54B093
    cmp dword ptr [esi+0AD84h],1
    jne SHORT L54B074
    call flush_window
    call store_counts
    jmp NEAR PTR return_end
L54B093:
    call flush_window
    push eax
    push ebp
    push edi
    mov ebp,[esi+0AD88h]
    mov edi,[ebp+10h]
    mov eax,[esi+822Ch]
    mov [edi],eax
    mov edi,[ebp+1Ch]
    mov eax,[esi+8218h]
    sub eax,[esi+8210h]
    mov [edi],eax
    pop edi
    pop ebp
    pop eax
    jmp NEAR PTR return_invalid

; int Inf32BufSize(void): size of the decoder state.
_Inf32BufSize: ; original 0054B0C5
    mov eax,0AD90h
    ret

; int Inf32Decode(input, input_offset, *input_size, output, output_offset, *output_size, state, final)
; returns 0 when suspended, -1 at end of stream, -2 on invalid data.
_Inf32Decode: ; original 0054B0CB
    push ebp
    mov ebp,esp
    push ebx
    push ecx
    push edx
    push esi
    push edi
    mov esi,[ebp+20h]
    mov [esi+0AD88h],ebp
    mov [esi+0AD8Ch],esp
    mov eax,[ebp+8]
    mov [esi+8228h],eax
    mov eax,[ebp+0Ch]
    mov [esi+8230h],eax
    mov eax,[ebp+10h]
    mov eax,[eax]
    mov [esi+822Ch],eax
    mov eax,[esi+8228h]
    add eax,[esi+8230h]
    mov [esi+8220h],eax
    mov eax,[esi+822Ch]
    mov [esi+8224h],eax
    mov eax,[ebp+14h]
    mov [esi+8214h],eax
    mov eax,[ebp+18h]
    mov [esi+821Ch],eax
    mov eax,[ebp+1Ch]
    mov eax,[eax]
    mov [esi+8218h],eax
    mov eax,[esi+8214h]
    add eax,[esi+821Ch]
    mov [esi+820Ch],eax
    mov eax,[esi+8218h]
    mov [esi+8210h],eax
    mov eax,[ebp+24h]
    mov [esi+0AD80h],eax
    mov ebx,[esi+0A958h]
    jmp dword ptr cs:resume_table[ebx*4]
return_suspended: ; original 0054B16F
    xor eax,eax
return_result: ; original 0054B171
    pop edi
    pop esi
    pop edx
    pop ecx
    pop ebx
    pop ebp
    ret
return_end: ; original 0054B178
    mov eax,0FFFFFFFFh
    jmp SHORT return_result
return_invalid: ; original 0054B17F
    mov eax,0FFFFFFFEh
    jmp SHORT return_result
_TEXT ENDS

Inf32Dat SEGMENT PARA PUBLIC 'DATA'
    BYTE 0AD90h DUP (0)
Inf32Dat ENDS

END
