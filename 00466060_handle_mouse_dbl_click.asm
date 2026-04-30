	TITLE	src/scratch/00466060_handle_mouse_dbl_click.cpp
	.386P
include listing.inc
if @Version gt 510
.model FLAT
else
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
_DATA	SEGMENT DWORD USE32 PUBLIC 'DATA'
_DATA	ENDS
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
_BSS	SEGMENT DWORD USE32 PUBLIC 'BSS'
_BSS	ENDS
_TLS	SEGMENT DWORD USE32 PUBLIC 'TLS'
_TLS	ENDS
;	COMDAT ?handle_mouse_dbl_click@TPanel@@QAEJEJJHH@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
FLAT	GROUP _DATA, CONST, _BSS
	ASSUME	CS: FLAT, DS: FLAT, SS: FLAT
endif
PUBLIC	?handle_mouse_dbl_click@TPanel@@QAEJEJJHH@Z	; TPanel::handle_mouse_dbl_click
;	COMDAT ?handle_mouse_dbl_click@TPanel@@QAEJEJJHH@Z
_TEXT	SEGMENT
_param_1$ = 8
_param_2$ = 12
_param_3$ = 16
_param_4$ = 20
_param_5$ = 24
_this$ = -4
?handle_mouse_dbl_click@TPanel@@QAEJEJJHH@Z PROC NEAR	; TPanel::handle_mouse_dbl_click, COMDAT
; File src/scratch/00466060_handle_mouse_dbl_click.cpp
; Line 54
	push	ecx
	push	ebx
	push	ebp
	push	esi
	mov	esi, ecx
	push	edi
	mov	DWORD PTR _this$[esp+20], esi
; Line 55
	mov	eax, DWORD PTR [esi+108]
	test	eax, eax
	jne	SHORT $L255
; Line 56
	xor	eax, eax
; Line 86
	pop	edi
	pop	esi
	pop	ebp
	pop	ebx
	pop	ecx
	ret	20					; 00000014H
$L255:
; Line 58
	mov	eax, DWORD PTR [esi+104]
	mov	edi, DWORD PTR _param_5$[esp+16]
	mov	ebp, DWORD PTR _param_3$[esp+16]
	mov	ebx, DWORD PTR _param_2$[esp+16]
	test	eax, eax
	jne	SHORT $L261
; Line 59
	mov	eax, DWORD PTR [esi]
	push	ebp
	push	ebx
	mov	ecx, esi
	call	DWORD PTR [eax+188]
	test	eax, eax
	jne	SHORT $L257
; Line 86
	pop	edi
	pop	esi
	pop	ebp
	pop	ebx
	pop	ecx
	ret	20					; 00000014H
$L257:
; Line 62
	mov	esi, DWORD PTR [esi+92]
	test	esi, esi
	je	SHORT $L284
$L259:
; Line 64
	mov	eax, DWORD PTR _param_4$[esp+16]
	mov	ecx, DWORD PTR [esi]
	push	edi
	push	eax
	mov	eax, DWORD PTR _param_1$[esp+24]
	mov	edx, DWORD PTR [ecx]
	push	ebp
	push	ebx
	push	eax
	call	DWORD PTR [edx+124]
	test	eax, eax
	jne	SHORT $L282
	mov	esi, DWORD PTR [esi+4]
	test	esi, esi
	jne	SHORT $L259
$L284:
; Line 62
	mov	esi, DWORD PTR _this$[esp+20]
$L261:
; Line 69
	mov	eax, DWORD PTR [esi+128]
	test	eax, eax
	jne	SHORT $L263
; Line 70
	xor	eax, eax
; Line 86
	pop	edi
	pop	esi
	pop	ebp
	pop	ebx
	pop	ecx
	ret	20					; 00000014H
$L263:
; Line 73
	mov	al, BYTE PTR _param_1$[esp+16]
; Line 74
	mov	edx, DWORD PTR [esi]
	cmp	al, 1
	mov	eax, DWORD PTR _param_4$[esp+16]
	push	edi
	push	eax
	push	ebp
	push	ebx
	mov	ecx, esi
	jne	SHORT $L265
	call	DWORD PTR [edx+148]
; Line 75
	jmp	SHORT $L266
$L265:
; Line 76
	call	DWORD PTR [edx+168]
$L266:
; Line 78
	test	eax, eax
	jne	SHORT $L267
; Line 81
	mov	ecx, DWORD PTR _param_4$[esp+16]
	mov	edx, DWORD PTR _param_1$[esp+16]
	push	edi
	push	ecx
	push	ebp
	push	ebx
	push	edx
	push	esi
	call	DWORD PTR [edi+112]
	add	esp, 24					; 00000018H
$L282:
; Line 82
	mov	eax, 1
$L267:
; Line 86
	pop	edi
	pop	esi
	pop	ebp
	pop	ebx
	pop	ecx
	ret	20					; 00000014H
?handle_mouse_dbl_click@TPanel@@QAEJEJJHH@Z ENDP	; TPanel::handle_mouse_dbl_click
_TEXT	ENDS
END
