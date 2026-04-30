	TITLE	build\obj\vcall_test.cpp
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
;	COMDAT ?test@Foo@@QAEHXZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?bar@Foo@@UAEHH@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?call_test@@YAHXZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ??0Foo@@QAE@XZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ??_7Foo@@6B@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
FLAT	GROUP _DATA, CONST, _BSS
	ASSUME	CS: FLAT, DS: FLAT, SS: FLAT
endif
PUBLIC	?bar@Foo@@UAEHH@Z				; Foo::bar
;	COMDAT ?bar@Foo@@UAEHH@Z
_TEXT	SEGMENT
_x$ = 8
?bar@Foo@@UAEHH@Z PROC NEAR				; Foo::bar, COMDAT
; File build\obj\vcall_test.cpp
; Line 7
	mov	eax, DWORD PTR _x$[esp-4]
	inc	eax
	ret	4
?bar@Foo@@UAEHH@Z ENDP					; Foo::bar
_TEXT	ENDS
PUBLIC	??_7Foo@@6B@					; Foo::`vftable'
PUBLIC	?call_test@@YAHXZ				; call_test
;	COMDAT ??_7Foo@@6B@
; File build\obj\vcall_test.cpp
CONST	SEGMENT
??_7Foo@@6B@ DD	FLAT:?bar@Foo@@UAEHH@Z			; Foo::`vftable'
CONST	ENDS
;	COMDAT ?call_test@@YAHXZ
_TEXT	SEGMENT
_f$ = -4
?call_test@@YAHXZ PROC NEAR				; call_test, COMDAT
; File build\obj\vcall_test.cpp
; Line 9
	push	ecx
; Line 11
	push	42					; 0000002aH
	lea	ecx, DWORD PTR _f$[esp+8]
	mov	DWORD PTR _f$[esp+8], OFFSET FLAT:??_7Foo@@6B@ ; Foo::`vftable'
	call	DWORD PTR ??_7Foo@@6B@			; Foo::`vftable'
; Line 12
	pop	ecx
	ret	0
?call_test@@YAHXZ ENDP					; call_test
_TEXT	ENDS
END
