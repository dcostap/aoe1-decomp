// Auto-generated scaffold unit: color.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/color.cpp
#include "../include/common.h"

// Offset: 0x00423EE0
void RGE_translate_palette(tagPALETTEENTRY* param_1, tagPALETTEENTRY* param_2, tagPALETTEENTRY param_3, long param_4, int param_5, int param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * void __cdecl RGE_translate_palette(struct tagPALETTEENTRY *,struct tagPALETTEENTRY *,struct tagPAL... *
    //                              *********************************************************************************************************
    //                              void __cdecl RGE_translate_palette(tagPALETTEENTRY * param_1, tagPAL
    //              void              <VOID>         <RETURN>
    //              tagPALETTEENTR    Stack[0x4]:4   param_1                   XREF[4]:     00423ee7(R), 00423efd(W), 00424019(R), 0042405f(R)  
    //              tagPALETTEENTR    Stack[0x8]:4   param_2                   XREF[4]:     00423ee3(R), 00423f33(W), 00423f58(R), 00423f5d(W)  
    //              tagPALETTEENTRY   Stack[0xc]:4   param_3                   XREF[1,2]:   00423f90(R), 00423fa1(R), 00423fe8(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[3]:     00423fc2(R), 00424005(R), 00424046(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[1]:     00423f01(R)  
    //              int               Stack[0x18]:4  param_6                   XREF[1]:     00423f0b(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00423f2f(W), 00423f67(R)  
    //              long[3]           Stack[-0x10]   intense                   XREF[3,9]:   00423ef6(W), 00424063(R), 0042408f(W), 00423f24(W), 
    //                                                                                     00423f44(R), 00423f4d(W), 00423f6b(R), 00423f2b(W), 
    //                                                                                     00423f3b(*), 00423f47(*), 00423f50(*), 00423f63(R)  
    //              long              Stack[-0x14]:4 index1
    //                               ?RGE_translate_palette@@YAXPAUtagPALETTEENTRY@@0U1@JHH@Z     XREF[4]:     RGE_fade_palette:0042424e(c), 
    //                               RGE_translate_palette                                                     RGE_fade_palette:0042431b(c), 
    //                                                                                                         RGE_Color_Table:004246d0(c), 
    //                                                                                                         RGE_fade_palette_step:004936a6(c)  
    //                              color.cpp:23 (3)
    //         00423ee0     SUB        ESP,0x10
    //                              color.cpp:32 (30)
    //         00423ee3     MOV        ECX,dword ptr [ESP + param_2]
    //         00423ee7     MOV        EDX,dword ptr [ESP + param_1]
    //         00423eeb     PUSH       EBX
    //         00423eec     PUSH       EBP
    //         00423eed     XOR        EAX,EAX
    //         00423eef     LEA        EBP,[ECX + 0x3]
    //         00423ef2     PUSH       ESI
    //         00423ef3     SUB        ECX,EDX
    //         00423ef5     PUSH       EDI
    //         00423ef6     MOV        dword ptr [ESP + intense[0]],EAX
    //         00423efa     LEA        EDI,[EDX + 0x1]
    //         00423efd     MOV        dword ptr [ESP + param_1],ECX
    //                               LAB_00423f01                                                 XREF[1]:     00424093(j)  
    //                              color.cpp:34 (20)
    //         00423f01     CMP        EAX,dword ptr [ESP + param_5]
    //         00423f05     JZ         LAB_0042406c
    //         00423f0b     CMP        EAX,dword ptr [ESP + param_6]
    //         00423f0f     JZ         LAB_0042406c
    //                              color.cpp:43 (3)
    //         00423f15     MOV        EBX,dword ptr [EDI + -0x1]
    //                              color.cpp:44 (10)
    //         00423f18     XOR        EAX,EAX
    //         00423f1a     MOV        AL,byte ptr [EDI]
    //         00423f1c     AND        EBX,0xff
    //                              color.cpp:45 (17)
    //         00423f22     XOR        ECX,ECX
    //         00423f24     MOV        dword ptr [ESP + intense[1]],EBX
    //         00423f28     MOV        CL,byte ptr [EDI + 0x1]
    //         00423f2b     MOV        dword ptr [ESP + intense[2]],EAX
    //         00423f2f     MOV        dword ptr [ESP + local_4],ECX
    //                              color.cpp:67 (313)
    //         00423f33     MOV        dword ptr [ESP + param_2],0x2
    //                               LAB_00423f3b                                                 XREF[1]:     00423f61(j)  
    //         00423f3b     LEA        EAX=>intense[2],[ESP + 0x18]
    //         00423f3f     MOV        ESI,0x2
    //                               LAB_00423f44                                                 XREF[1]:     00423f56(j)  
    //         00423f44     MOV        ECX,dword ptr [EAX + intense[1]]
    //         00423f47     MOV        EDX,dword ptr [EAX]=>intense[2]
    //         00423f49     CMP        ECX,EDX
    //         00423f4b     JGE        LAB_00423f52
    //         00423f4d     MOV        dword ptr [EAX + intense[1]],EDX
    //         00423f50     MOV        dword ptr [EAX]=>intense[2],ECX
    //                               LAB_00423f52                                                 XREF[1]:     00423f4b(j)  
    //         00423f52     ADD        EAX,0x4
    //         00423f55     DEC        ESI
    //         00423f56     JNZ        LAB_00423f44
    //         00423f58     MOV        EAX,dword ptr [ESP + param_2]
    //         00423f5c     DEC        EAX
    //         00423f5d     MOV        dword ptr [ESP + param_2],EAX
    //         00423f61     JNZ        LAB_00423f3b
    //         00423f63     MOV        EDX,dword ptr [ESP + intense[2]]
    //         00423f67     MOV        EAX,dword ptr [ESP + local_4]
    //         00423f6b     MOV        ESI,dword ptr [ESP + intense[1]]
    //         00423f6f     MOV        ECX,0xff
    //         00423f74     ADD        EAX,EDX
    //         00423f76     SUB        ECX,ESI
    //         00423f78     IMUL       EAX,ECX
    //         00423f7b     CDQ
    //         00423f7c     AND        EDX,0x1ff
    //         00423f82     ADD        EAX,EDX
    //         00423f84     MOV        ECX,EAX
    //         00423f86     MOV        EAX,0x80808081
    //         00423f8b     SAR        ECX,0x9
    //         00423f8e     ADD        ECX,ESI
    //         00423f90     MOV        ESI,dword ptr [ESP + param_3.peRed]
    //         00423f94     AND        ESI,0xff
    //         00423f9a     IMUL       ESI,ECX
    //         00423f9d     IMUL       ESI
    //         00423f9f     ADD        EDX,ESI
    //         00423fa1     MOV        ESI,dword ptr [ESP + param_3.peGreen]
    //         00423fa5     SAR        EDX,0x7
    //         00423fa8     MOV        EAX,EDX
    //         00423faa     AND        ESI,0xff
    //         00423fb0     SHR        EAX,0x1f
    //         00423fb3     IMUL       ESI,ECX
    //         00423fb6     ADD        EDX,EAX
    //         00423fb8     MOV        EAX,0x51eb851f
    //         00423fbd     SUB        EDX,EBX
    //         00423fbf     MOV        BL,byte ptr [EDI + -0x1]
    //         00423fc2     IMUL       EDX,dword ptr [ESP + param_4]
    //         00423fc7     IMUL       EDX
    //         00423fc9     SAR        EDX,0x5
    //         00423fcc     MOV        EAX,EDX
    //         00423fce     SHR        EAX,0x1f
    //         00423fd1     ADD        EDX,EAX
    //         00423fd3     MOV        EAX,0x80808081
    //         00423fd8     ADD        DL,BL
    //         00423fda     MOV        byte ptr [EBP + -0x3],DL
    //         00423fdd     IMUL       ESI
    //         00423fdf     MOV        BL,byte ptr [EDI]
    //         00423fe1     ADD        EDX,ESI
    //         00423fe3     SAR        EDX,0x7
    //         00423fe6     MOV        EAX,EDX
    //         00423fe8     MOV        ESI,dword ptr [ESP + param_3.peBlue]
    //         00423fec     SHR        EAX,0x1f
    //         00423fef     ADD        EDX,EAX
    //         00423ff1     MOV        EAX,EBX
    //         00423ff3     AND        EAX,0xff
    //         00423ff8     AND        ESI,0xff
    //         00423ffe     SUB        EDX,EAX
    //         00424000     MOV        EAX,0x51eb851f
    //         00424005     IMUL       EDX,dword ptr [ESP + param_4]
    //         0042400a     IMUL       ESI,ECX
    //         0042400d     IMUL       EDX
    //         0042400f     SAR        EDX,0x5
    //         00424012     MOV        EAX,EDX
    //         00424014     SHR        EAX,0x1f
    //         00424017     ADD        EDX,EAX
    //         00424019     MOV        EAX,dword ptr [ESP + param_1]
    //         0042401d     ADD        DL,BL
    //         0042401f     MOV        byte ptr [EAX + EDI*0x1],DL
    //         00424022     MOV        EAX,0x80808081
    //         00424027     IMUL       ESI
    //         00424029     MOV        BL,byte ptr [EDI + 0x1]
    //         0042402c     ADD        EDX,ESI
    //         0042402e     SAR        EDX,0x7
    //         00424031     MOV        ECX,EDX
    //         00424033     MOV        EAX,EBX
    //         00424035     SHR        ECX,0x1f
    //         00424038     ADD        EDX,ECX
    //         0042403a     AND        EAX,0xff
    //         0042403f     SUB        EDX,EAX
    //         00424041     MOV        EAX,0x51eb851f
    //         00424046     IMUL       EDX,dword ptr [ESP + param_4]
    //         0042404b     IMUL       EDX
    //         0042404d     SAR        EDX,0x5
    //         00424050     MOV        ECX,EDX
    //         00424052     SHR        ECX,0x1f
    //         00424055     ADD        EDX,ECX
    //         00424057     ADD        DL,BL
    //         00424059     MOV        byte ptr [EBP + -0x1],DL
    //         0042405c     MOV        DL,byte ptr [EDI + 0x2]
    //         0042405f     MOV        ECX,dword ptr [ESP + param_1]
    //         00424063     MOV        EAX,dword ptr [ESP + intense[0]]
    //         00424067     MOV        byte ptr [EBP],DL
    //         0042406a     JMP        LAB_00424083
    //                               LAB_0042406c                                                 XREF[2]:     00423f05(j), 00423f0f(j)  
    //                              color.cpp:36 (6)
    //         0042406c     MOV        DL,byte ptr [EDI + -0x1]
    //         0042406f     MOV        byte ptr [EBP + -0x3],DL
    //                              color.cpp:37 (5)
    //         00424072     MOV        DL,byte ptr [EDI]
    //         00424074     MOV        byte ptr [ECX + EDI*0x1],DL
    //                              color.cpp:38 (6)
    //         00424077     MOV        DL,byte ptr [EDI + 0x1]
    //         0042407a     MOV        byte ptr [EBP + -0x1],DL
    //                              color.cpp:39 (28)
    //         0042407d     MOV        DL,byte ptr [EDI + 0x2]
    //         00424080     MOV        byte ptr [EBP],DL
    //                               LAB_00424083                                                 XREF[1]:     0042406a(j)  
    //         00424083     INC        EAX
    //         00424084     ADD        EDI,0x4
    //         00424087     ADD        EBP,0x4
    //         0042408a     CMP        EAX,0x100
    //         0042408f     MOV        dword ptr [ESP + intense[0]],EAX
    //         00424093     JL         LAB_00423f01
    //                              color.cpp:67 (8)
    //         00424099     POP        EDI
    //         0042409a     POP        ESI
    //         0042409b     POP        EBP
    //         0042409c     POP        EBX
    //         0042409d     ADD        ESP,0x10
    //         004240a0     RET
}

// Offset: 0x004240B0
void RGE_fade_palette(TDrawArea* param_1, tagPALETTEENTRY param_2, float param_3, uchar param_4, tagPALETTEENTRY* param_5, int param_6, int param_7) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * void __cdecl RGE_fade_palette(class TDrawArea *,struct tagPALETTEENTRY,float,unsigned char,struct ... *
    //                              *********************************************************************************************************
    //                              void __cdecl RGE_fade_palette(TDrawArea * param_1, tagPALETTEENTRY p
    //              void              <VOID>         <RETURN>
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[2]:     00424107(R), 00424165(R)  
    //              tagPALETTEENTRY   Stack[0x8]:4   param_2                   XREF[2]:     00424236(R), 00424303(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[7]:     00424178(R), 0042417f(R), 004241d5(R), 004241ed(R), 
    //                                                                                     0042429e(R), 004242a9(R), 004242c1(R)  
    //              uchar             Stack[0x10]:1  param_4                   XREF[1]:     00424198(R)  
    //              tagPALETTEENTR    Stack[0x14]:4  param_5                   XREF[1]:     00424100(R)  
    //              int               Stack[0x18]:4  param_6                   XREF[1]:     0042418d(R)  
    //              int               Stack[0x1c]:4  param_7                   XREF[1]:     00424186(R)  
    //              tagPALETTEENTR    Stack[-0x404   palette2                  XREF[0,4]:   00424240(*), 00424256(*), 0042430d(*), 00424323(*)  
    //              tagPALETTEENTR    Stack[-0x804   palette1                  XREF[3,8]:   004241a4(W), 00424214(R), 004242e8(R), 00424112(*), 
    //                                                                                     00424124(*), 00424135(*), 00424144(*), 00424248(*), 
    //                                                                                     00424315(*), 00424120(*), 00424128(*)  
    //              float             Stack[-0x808   fade_time2                XREF[3]:     00424194(W), 004241ba(R), 00424287(R)  
    //              long              Stack[-0x80c   old_time                  XREF[0,2]:   004240bc(W), 00424161(R)  
    //              uchar             Stack[-0x80d   done
    //              float             Stack[-0x814   delta_time
    //                               ?RGE_fade_palette@@YAXPAVTDrawArea@@UtagPALETTEENTRY@@MEPAU  XREF[4]:     set_focus:0047bc0c(c), 
    //                               RGE_fade_palette                                                          set_focus:0047bc70(c), 
    //                                                                                                         set_focus:0047bc8e(c), 
    //                                                                                                         set_focus:0047bcb7(c)  
    //                              color.cpp:71 (8)
    //         004240b0     SUB        ESP,0x810
    //         004240b6     PUSH       EBX
    //         004240b7     PUSH       EBP
    //                              color.cpp:72 (8)
    //         004240b8     XOR        BL,BL
    //         004240ba     PUSH       ESI
    //         004240bb     PUSH       EDI
    //         004240bc     MOV        byte ptr [ESP + old_time+0x3],BL
    //                              color.cpp:84 (7)
    //         004240c0     XOR        EAX,EAX
    //                               LAB_004240c2                                                 XREF[1]:     004240fe(j)  
    //         004240c2     MOV        byte ptr [ESP + EAX*0x1 + 0x20],0x0
    //                              color.cpp:88 (13)
    //         004240c7     MOV        byte ptr [ESP + EAX*0x1 + 0x420],0x0
    //         004240cf     MOV        byte ptr [ESP + EAX*0x1 + 0x22],0x0
    //                              color.cpp:89 (13)
    //         004240d4     MOV        byte ptr [ESP + EAX*0x1 + 0x422],0x0
    //         004240dc     MOV        byte ptr [ESP + EAX*0x1 + 0x21],0x0
    //                              color.cpp:90 (13)
    //         004240e1     MOV        byte ptr [ESP + EAX*0x1 + 0x421],0x0
    //         004240e9     MOV        byte ptr [ESP + EAX*0x1 + 0x23],0x0
    //                              color.cpp:91 (18)
    //         004240ee     MOV        byte ptr [ESP + EAX*0x1 + 0x423],0x0
    //         004240f6     ADD        EAX,0x4
    //         004240f9     CMP        EAX,0x400
    //         004240fe     JL         LAB_004240c2
    //                              color.cpp:94 (18)
    //         00424100     MOV        EDX,dword ptr [ESP + param_5]
    //         00424107     MOV        ESI,dword ptr [ESP + param_1]
    //         0042410e     TEST       EDX,EDX
    //         00424110     JNZ        LAB_00424120
    //                              color.cpp:95 (12)
    //         00424112     LEA        EAX=>palette1[1],[ESP + 0x20]
    //         00424116     MOV        ECX,ESI
    //         00424118     PUSH       EAX
    //         00424119     CALL       TDrawArea::GetPalette                            void GetPalette(TDrawArea * this, tagPALETTEE
    //                              color.cpp:96 (2)
    //         0042411e     JMP        LAB_0042416c
    //                               LAB_00424120                                                 XREF[1]:     00424110(j)  
    //                              color.cpp:99 (16)
    //         00424120     LEA        ESI=>palette1[1].peGreen,[ESP + 0x21]
    //         00424124     LEA        EDI=>palette1[1],[ESP + 0x20]
    //         00424128     LEA        EBP=>palette1[1].peBlue,[ESP + 0x22]
    //         0042412c     SUB        ESI,EDX
    //         0042412e     SUB        EDI,EDX
    //                              color.cpp:157 (126)
    //         00424130     LEA        EAX,[EDX + 0x1]
    //         00424133     SUB        EBP,EDX
    //         00424135     LEA        ECX=>palette1[1],[ESP + 0x20]
    //         00424139     MOV        EDX,0x100
    //                               LAB_0042413e                                                 XREF[1]:     0042415f(j)  
    //         0042413e     MOV        BL,byte ptr [EAX + -0x1]
    //         00424141     ADD        EAX,0x4
    //         00424144     MOV        byte ptr [ECX]=>palette1[1],BL
    //         00424146     MOV        BL,byte ptr [EAX + -0x3]
    //         00424149     MOV        byte ptr [ESI + EAX*0x1 + -0x4],BL
    //         0042414d     MOV        BL,byte ptr [EAX + -0x4]
    //         00424150     MOV        byte ptr [EDI + EAX*0x1 + -0x4],BL
    //         00424154     MOV        BL,byte ptr [EAX + -0x2]
    //         00424157     MOV        byte ptr [EBP + EAX*0x1 + -0x4],BL
    //         0042415b     ADD        ECX,0x4
    //         0042415e     DEC        EDX
    //         0042415f     JNZ        LAB_0042413e
    //         00424161     MOV        BL,byte ptr [ESP + old_time+0x3]
    //         00424165     MOV        ESI,dword ptr [ESP + param_1]
    //                               LAB_0042416c                                                 XREF[1]:     0042411e(j)  
    //         0042416c     PUSH       0x69
    //         0042416e     PUSH       s_C:\msdev\work\age1_x1\color.cpp                = "C:\\msdev\\work\\age1_x1\\color.cpp"
    //         00424173     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //         00424178     FLD        float ptr [ESP + param_3]
    //         0042417f     FMUL       float ptr [ESP + param_3]
    //         00424186     MOV        EDI,dword ptr [ESP + param_7]
    //         0042418d     MOV        EBP,dword ptr [ESP + param_6]
    //         00424194     MOV        dword ptr [ESP + fade_time2],EAX
    //         00424198     MOV        AL,byte ptr [ESP + param_4]
    //         0042419f     ADD        ESP,0x8
    //         004241a2     CMP        AL,0x1
    //         004241a4     FSTP       float ptr [ESP + palette1[0].peRed]
    //         004241a8     JNZ        LAB_00424278
    //                              language.dll match for 0x70: "B"
    //                               LAB_004241ae                                                 XREF[1]:     00424267(j)  
    //                              color.cpp:112 (12)
    //         004241ae     PUSH       0x70
    //         004241b0     PUSH       s_C:\msdev\work\age1_x1\color.cpp                = "C:\\msdev\\work\\age1_x1\\color.cpp"
    //         004241b5     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //                              color.cpp:113 (27)
    //         004241ba     MOV        ECX,dword ptr [ESP + fade_time2]
    //         004241be     ADD        ESP,0x8
    //         004241c1     SUB        EAX,ECX
    //         004241c3     MOV        dword ptr [ESP + Stack[-0x810]],EAX
    //         004241c7     FILD       dword ptr [ESP + Stack[-0x810]]
    //         004241cb     FMUL       float ptr [DAT_0056f020]                         = 6Fh    o
    //         004241d1     FSTP       float ptr [ESP + Stack[-0x810]]
    //                              color.cpp:114 (55)
    //         004241d5     FLD        float ptr [ESP + param_3]
    //         004241dc     FCOMP      double ptr [DAT_0056f028]
    //         004241e2     FNSTSW     AX
    //         004241e4     TEST       AH,0x41
    //         004241e7     JNZ        LAB_00424225
    //         004241e9     FLD        float ptr [ESP + Stack[-0x810]]
    //         004241ed     FCOMP      float ptr [ESP + param_3]
    //         004241f4     FNSTSW     AX
    //         004241f6     TEST       AH,0x41
    //         004241f9     JZ         LAB_00424225
    //         004241fb     FLD        float ptr [ESP + Stack[-0x810]]
    //         004241ff     FCOMP      float ptr [DAT_0056f030]
    //         00424205     FNSTSW     AX
    //         00424207     TEST       AH,0x1
    //         0042420a     JNZ        LAB_00424225
    //                              color.cpp:119 (25)
    //         0042420c     FLD        float ptr [ESP + Stack[-0x810]]
    //         00424210     FMUL       float ptr [ESP + Stack[-0x810]]
    //         00424214     FDIV       float ptr [ESP + palette1[0].peRed]
    //         00424218     FMUL       float ptr [DAT_0056f034]
    //         0042421e     CALL       __ftol                                           undefined __ftol()
    //         00424223     JMP        LAB_0042422a
    //                               LAB_00424225                                                 XREF[3]:     004241e7(j), 004241f9(j), 
    //                                                                                                         0042420a(j)  
    //                              color.cpp:115 (5)
    //         00424225     MOV        EAX,0x64
    //                               LAB_0042422a                                                 XREF[1]:     00424223(j)  
    //                              color.cpp:122 (5)
    //         0042422a     CMP        EAX,0x64
    //         0042422d     JL         LAB_00424236
    //                              color.cpp:124 (5)
    //         0042422f     MOV        EAX,0x64
    //                              color.cpp:125 (2)
    //         00424234     MOV        BL,0x1
    //                               LAB_00424236                                                 XREF[1]:     0042422d(j)  
    //                              color.cpp:127 (32)
    //         00424236     MOV        ECX,dword ptr [ESP + param_2.peRed]
    //         0042423d     PUSH       EDI
    //         0042423e     PUSH       EBP
    //         0042423f     PUSH       EAX
    //         00424240     LEA        EDX=>palette2[1],[ESP + 0x42c]
    //         00424247     PUSH       ECX
    //         00424248     LEA        EAX=>palette1[1],[ESP + 0x30]
    //         0042424c     PUSH       EDX
    //         0042424d     PUSH       EAX
    //         0042424e     CALL       RGE_translate_palette                            void RGE_translate_palette(tagPALETTEENTRY * 
    //         00424253     ADD        ESP,0x18
    //                              color.cpp:128 (23)
    //         00424256     LEA        ECX=>palette2[1],[ESP + 0x420]
    //         0042425d     PUSH       ECX
    //         0042425e     MOV        ECX,ESI
    //         00424260     CALL       TDrawArea::SetPalette                            void SetPalette(TDrawArea * this, tagPALETTEE
    //         00424265     TEST       BL,BL
    //         00424267     JZ         LAB_004241ae
    //                              color.cpp:157 (11)
    //         0042426d     POP        EDI
    //         0042426e     POP        ESI
    //         0042426f     POP        EBP
    //         00424270     POP        EBX
    //         00424271     ADD        ESP,0x810
    //         00424277     RET
    //                               LAB_00424278                                                 XREF[2]:     004241a8(j), 00424334(j)  
    //                              color.cpp:136 (15)
    //         00424278     PUSH       0x88
    //         0042427d     PUSH       s_C:\msdev\work\age1_x1\color.cpp                = "C:\\msdev\\work\\age1_x1\\color.cpp"
    //         00424282     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //                              color.cpp:138 (34)
    //         00424287     MOV        ECX,dword ptr [ESP + fade_time2]
    //         0042428b     ADD        ESP,0x8
    //         0042428e     SUB        EAX,ECX
    //         00424290     MOV        dword ptr [ESP + Stack[-0x810]],EAX
    //         00424294     FILD       dword ptr [ESP + Stack[-0x810]]
    //         00424298     FMUL       float ptr [DAT_0056f020]                         = 6Fh    o
    //         0042429e     FSUBR      float ptr [ESP + param_3]
    //         004242a5     FSTP       float ptr [ESP + Stack[-0x810]]
    //                              color.cpp:139 (55)
    //         004242a9     FLD        float ptr [ESP + param_3]
    //         004242b0     FCOMP      double ptr [DAT_0056f028]
    //         004242b6     FNSTSW     AX
    //         004242b8     TEST       AH,0x41
    //         004242bb     JNZ        LAB_004242f9
    //         004242bd     FLD        float ptr [ESP + Stack[-0x810]]
    //         004242c1     FCOMP      float ptr [ESP + param_3]
    //         004242c8     FNSTSW     AX
    //         004242ca     TEST       AH,0x41
    //         004242cd     JZ         LAB_004242f9
    //         004242cf     FLD        float ptr [ESP + Stack[-0x810]]
    //         004242d3     FCOMP      float ptr [DAT_0056f030]
    //         004242d9     FNSTSW     AX
    //         004242db     TEST       AH,0x1
    //         004242de     JNZ        LAB_004242f9
    //                              color.cpp:144 (25)
    //         004242e0     FLD        float ptr [ESP + Stack[-0x810]]
    //         004242e4     FMUL       float ptr [ESP + Stack[-0x810]]
    //         004242e8     FDIV       float ptr [ESP + palette1[0].peRed]
    //         004242ec     FMUL       float ptr [DAT_0056f034]
    //         004242f2     CALL       __ftol                                           undefined __ftol()
    //         004242f7     JMP        LAB_004242fb
    //                               LAB_004242f9                                                 XREF[3]:     004242bb(j), 004242cd(j), 
    //                                                                                                         004242de(j)  
    //                              color.cpp:140 (2)
    //         004242f9     XOR        EAX,EAX
    //                               LAB_004242fb                                                 XREF[1]:     004242f7(j)  
    //                              color.cpp:147 (4)
    //         004242fb     TEST       EAX,EAX
    //         004242fd     JG         LAB_00424303
    //                              color.cpp:149 (2)
    //         004242ff     XOR        EAX,EAX
    //                              color.cpp:150 (2)
    //         00424301     MOV        BL,0x1
    //                               LAB_00424303                                                 XREF[1]:     004242fd(j)  
    //                              color.cpp:152 (32)
    //         00424303     MOV        EDX,dword ptr [ESP + param_2.peRed]
    //         0042430a     PUSH       EDI
    //         0042430b     PUSH       EBP
    //         0042430c     PUSH       EAX
    //         0042430d     LEA        EAX=>palette2[1],[ESP + 0x42c]
    //         00424314     PUSH       EDX
    //         00424315     LEA        ECX=>palette1[1],[ESP + 0x30]
    //         00424319     PUSH       EAX
    //         0042431a     PUSH       ECX
    //         0042431b     CALL       RGE_translate_palette                            void RGE_translate_palette(tagPALETTEENTRY * 
    //         00424320     ADD        ESP,0x18
    //                              color.cpp:153 (23)
    //         00424323     LEA        EDX=>palette2[1],[ESP + 0x420]
    //         0042432a     MOV        ECX,ESI
    //         0042432c     PUSH       EDX
    //         0042432d     CALL       TDrawArea::SetPalette                            void SetPalette(TDrawArea * this, tagPALETTEE
    //         00424332     TEST       BL,BL
    //         00424334     JZ         LAB_00424278
    //                              color.cpp:157 (11)
    //         0042433a     POP        EDI
    //         0042433b     POP        ESI
    //         0042433c     POP        EBP
    //         0042433d     POP        EBX
    //         0042433e     ADD        ESP,0x810
    //         00424344     RET
}

// Offset: 0x00424350
undefined RGE_Color_Table(RGE_Color_Table* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Color_Table::RGE_Color_Table(int)                                              *
    //                              *********************************************************************************************************
    //                              undefined __thiscall RGE_Color_Table(RGE_Color_Table * this, int par
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Color_Tabl    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0042435b(R)  
    //              char[300]         Stack[-0x130   tempname                  XREF[0,4]:   004243e0(*), 004243f0(R), 004243b3(*), 004243c6(*)  
    //              short             Stack[-0x132   temp_color
    //                               ??0RGE_Color_Table@@QAE@H@Z                                  XREF[1]:     color_table_init:005419a6(c)  
    //                               RGE_Color_Table::RGE_Color_Table
    //                              color.cpp:162 (11)
    //         00424350     SUB        ESP,0x130
    //         00424356     PUSH       EBX
    //         00424357     PUSH       ESI
    //         00424358     MOV        ESI,this
    //         0042435a     PUSH       EDI
    //                              color.cpp:168 (28)
    //         0042435b     MOV        EDI,dword ptr [ESP + param_1]
    //         00424362     PUSH       0x1e
    //         00424364     LEA        EBX,[ESI + 0x4]
    //         00424367     MOV        dword ptr [ESI],RGE_Color_Table::`vftable'       = 00424420
    //         0042436d     PUSH       EBX
    //         0042436e     PUSH       EDI
    //         0042436f     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00424374     ADD        ESP,0xc
    //                              color.cpp:169 (15)
    //         00424377     LEA        EAX,[ESI + 0x26]
    //         0042437a     PUSH       0x2
    //         0042437c     PUSH       EAX
    //         0042437d     PUSH       EDI
    //         0042437e     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00424383     ADD        ESP,0xc
    //                              color.cpp:170 (15)
    //         00424386     LEA        this,[ESI + 0x22]
    //         00424389     PUSH       0x2
    //         0042438b     PUSH       this
    //         0042438c     PUSH       EDI
    //         0042438d     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00424392     ADD        ESP,0xc
    //                              color.cpp:171 (15)
    //         00424395     LEA        EDX,[ESI + 0x25]
    //         00424398     PUSH       0x1
    //         0042439a     PUSH       EDX
    //         0042439b     PUSH       EDI
    //         0042439c     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004243a1     ADD        ESP,0xc
    //                              color.cpp:172 (15)
    //         004243a4     LEA        EAX,[ESI + 0x24]
    //         004243a7     PUSH       0x1
    //         004243a9     PUSH       EAX
    //         004243aa     PUSH       EDI
    //         004243ab     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004243b0     ADD        ESP,0xc
    //                              color.cpp:174 (19)
    //         004243b3     LEA        this=>tempname[4],[ESP + 0x10]
    //         004243b7     PUSH       EBX
    //         004243b8     PUSH       s_data\%s                                        = "data\\%s"
    //         004243bd     PUSH       this
    //         004243be     CALL       sprintf                                          undefined sprintf()
    //         004243c3     ADD        ESP,0xc
    //                              color.cpp:175 (20)
    //         004243c6     LEA        EDX=>tempname[4],[ESP + 0x10]
    //         004243ca     PUSH       s_r                                              = "r"
    //         004243cf     PUSH       EDX
    //         004243d0     CALL       fopen                                            undefined fopen()
    //         004243d5     MOV        EBX,EAX
    //         004243d7     ADD        ESP,0x8
    //                              color.cpp:176 (4)
    //         004243da     TEST       EBX,EBX
    //         004243dc     JZ         LAB_0042440d
    //                              color.cpp:178 (2)
    //         004243de     XOR        EDI,EDI
    //                               LAB_004243e0                                                 XREF[1]:     00424402(j)  
    //                              color.cpp:180 (16)
    //         004243e0     LEA        EAX=>tempname[2],[ESP + 0xe]
    //         004243e4     PUSH       EAX
    //         004243e5     PUSH       s_%hd                                            = "%hd"
    //         004243ea     PUSH       EBX
    //         004243eb     CALL       fscanf                                           undefined fscanf()
    //                              color.cpp:181 (20)
    //         004243f0     MOV        this,byte ptr [ESP + tempname[2]]
    //         004243f4     ADD        ESP,0xc
    //         004243f7     MOV        byte ptr [EDI + ESI*0x1 + 0x28],this
    //         004243fb     INC        EDI
    //         004243fc     CMP        EDI,0x100
    //         00424402     JL         LAB_004243e0
    //                              color.cpp:183 (9)
    //         00424404     PUSH       EBX
    //         00424405     CALL       fclose                                           undefined fclose()
    //         0042440a     ADD        ESP,0x4
    //                               LAB_0042440d                                                 XREF[1]:     004243dc(j)  
    //                              color.cpp:186 (14)
    //         0042440d     MOV        EAX,ESI
    //         0042440f     POP        EDI
    //         00424410     POP        ESI
    //         00424411     POP        EBX
    //         00424412     ADD        ESP,0x130
    //         00424418     RET        0x4
}

// Offset: 0x00424440
undefined RGE_Color_Table(RGE_Color_Table* this_, FILE* param_2, short param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Color_Table::RGE_Color_Table(struct _iobuf *,short)                            *
    //                              *********************************************************************************************************
    //                              undefined __thiscall RGE_Color_Table(RGE_Color_Table * this, _iobuf 
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Color_Tabl    ECX:4 (auto)   this
    //              _iobuf *          Stack[0x4]:4   param_1                   XREF[3]:     00424466(*), 0042446e(*), 0042448f(R)  
    //              short             Stack[0x8]:2   param_2                   XREF[3]:     00424441(R), 00424460(*), 0042448b(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     0042447e(W), 00424496(*), 004244ac(R)  
    //              char *            Stack[-0x8]:4  file_name
    //                               ??0RGE_Color_Table@@QAE@PAU_iobuf@@F@Z                       XREF[1]:     data_load_color_tables:00541082(c)
    //                               RGE_Color_Table::RGE_Color_Table
    //                              color.cpp:191 (1)
    //         00424440     PUSH       this
    //                              color.cpp:196 (15)
    //         00424441     MOV        AX,word ptr [ESP + param_2]
    //         00424446     PUSH       EBX
    //         00424447     MOV        EBX,this
    //         00424449     PUSH       EBP
    //         0042444a     PUSH       ESI
    //         0042444b     PUSH       EDI
    //         0042444c     MOV        word ptr [EBX + 0x26],AX
    //                              color.cpp:197 (16)
    //         00424450     MOV        this,0x40
    //         00424455     XOR        EAX,EAX
    //         00424457     LEA        EDI,[EBX + 0x28]
    //         0042445a     MOV        dword ptr [EBX],RGE_Color_Table::`vftable'       = 00424420
    //                              color.cpp:199 (43)
    //         00424460     LEA        EDX=>param_2,[ESP + 0x1c]
    //         00424464     STOSD.REP  ES:EDI
    //         00424466     LEA        this=>param_1,[ESP + 0x18]
    //         0042446a     LEA        EBP,[EBX + 0x4]
    //         0042446d     PUSH       this
    //         0042446e     MOV        this=>param_1,dword ptr [ESP + 0x1c]
    //         00424472     PUSH       EDX
    //         00424473     LEA        EAX,[EBX + 0x22]
    //         00424476     PUSH       EBP
    //         00424477     PUSH       EAX
    //         00424478     PUSH       s_%hd_%s_%hd_%hd                                 = "%hd %s %hd %hd"
    //         0042447d     PUSH       this
    //         0042447e     MOV        dword ptr [ESP + local_4],0x0
    //         00424486     CALL       fscanf                                           undefined fscanf()
    //                              color.cpp:201 (4)
    //         0042448b     MOV        DL,byte ptr [ESP + param_2]
    //                              color.cpp:202 (7)
    //         0042448f     MOV        AL,byte ptr [ESP + param_1]
    //         00424493     ADD        ESP,0x18
    //                              color.cpp:204 (22)
    //         00424496     LEA        this=>local_4,[ESP + 0x10]
    //         0042449a     MOV        byte ptr [EBX + 0x25],DL
    //         0042449d     MOV        byte ptr [EBX + 0x24],AL
    //         004244a0     PUSH       s_.col                                           = 2Eh
    //         004244a5     PUSH       EBP
    //         004244a6     PUSH       this
    //         004244a7     CALL       addstring                                        void addstring(char * * param_1, char * param
    //                              color.cpp:205 (36)
    //         004244ac     MOV        EDX,dword ptr [ESP + local_4]
    //         004244b0     OR         this,0xffffffff
    //         004244b3     MOV        EDI,EDX
    //         004244b5     XOR        EAX,EAX
    //         004244b7     ADD        ESP,0xc
    //         004244ba     SCASB.RE   ES:EDI
    //         004244bc     NOT        this
    //         004244be     SUB        EDI,this
    //         004244c0     MOV        EAX,this
    //         004244c2     MOV        ESI,EDI
    //         004244c4     MOV        EDI,EBP
    //         004244c6     SHR        this,0x2
    //         004244c9     MOVSD.REP  ES:EDI,ESI
    //         004244cb     MOV        this,EAX
    //         004244cd     AND        this,0x3
    //                              color.cpp:207 (6)
    //         004244d0     TEST       EDX,EDX
    //         004244d2     MOVSB.REP  ES:EDI,ESI
    //         004244d4     JZ         LAB_004244df
    //                              color.cpp:208 (9)
    //         004244d6     PUSH       EDX
    //         004244d7     CALL       free                                             undefined free()
    //         004244dc     ADD        ESP,0x4
    //                               LAB_004244df                                                 XREF[1]:     004244d4(j)  
    //                              color.cpp:209 (10)
    //         004244df     POP        EDI
    //         004244e0     POP        ESI
    //         004244e1     MOV        EAX,EBX
    //         004244e3     POP        EBP
    //         004244e4     POP        EBX
    //         004244e5     POP        this
    //         004244e6     RET        0x8
}

// Offset: 0x004244F0
undefined RGE_Color_Table(RGE_Color_Table* this_, char* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Color_Table::RGE_Color_Table(char *)                                           *
    //                              *********************************************************************************************************
    //                              undefined __thiscall RGE_Color_Table(RGE_Color_Table * this, char * 
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Color_Tabl    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     00424522(R)  
    //              char[300]         Stack[-0x130   tempname                  XREF[4,2]:   00424558(W), 0042455e(R), 004245a8(*), 004245b8(R), 
    //                                                                                     0042457a(*), 0042458e(*)  
    //              short             Stack[-0x134   temp_color
    //                               ??0RGE_Color_Table@@QAE@PAD@Z
    //                               RGE_Color_Table::RGE_Color_Table
    //                              color.cpp:214 (12)
    //         004244f0     SUB        ESP,0x130
    //         004244f6     PUSH       EBX
    //         004244f7     PUSH       EBP
    //         004244f8     MOV        EBP,this
    //         004244fa     PUSH       ESI
    //         004244fb     PUSH       EDI
    //                              color.cpp:223 (33)
    //         004244fc     MOV        this,0x40
    //         00424501     LEA        EBX,[EBP + 0x28]
    //         00424504     XOR        EAX,EAX
    //         00424506     MOV        EDI,EBX
    //         00424508     MOV        dword ptr [EBP],RGE_Color_Table::`vftable'       = 00424420
    //         0042450f     MOV        word ptr [EBP + 0x22],0x0
    //         00424515     MOV        byte ptr [EBP + 0x25],0x0
    //         00424519     MOV        byte ptr [EBP + 0x24],0x0
    //                              color.cpp:225 (34)
    //         0042451d     LEA        EDX,[EBP + 0x4]
    //         00424520     STOSD.REP  ES:EDI
    //         00424522     MOV        EDI,dword ptr [ESP + param_1]
    //         00424529     OR         this,0xffffffff
    //         0042452c     SCASB.RE   ES:EDI
    //         0042452e     NOT        this
    //         00424530     SUB        EDI,this
    //         00424532     MOV        EAX,this
    //         00424534     MOV        ESI,EDI
    //         00424536     MOV        EDI,EDX
    //         00424538     SHR        this,0x2
    //         0042453b     MOVSD.REP  ES:EDI,ESI
    //         0042453d     MOV        this,EAX
    //                              color.cpp:226 (50)
    //         0042453f     XOR        EAX,EAX
    //         00424541     AND        this,0x3
    //         00424544     MOVSB.REP  ES:EDI,ESI
    //         00424546     MOV        EDI,s_.col                                       = 2Eh
    //         0042454b     OR         this,0xffffffff
    //         0042454e     SCASB.RE   ES:EDI=>s_.col                                   = 2Eh
    //                                                                                  = 006c6f63
    //         00424550     NOT        this
    //         00424552     SUB        EDI,this
    //         00424554     MOV        EAX,this
    //         00424556     MOV        ESI,EDI
    //         00424558     MOV        dword ptr [ESP + tempname[0]],EAX
    //         0042455c     MOV        EDI,EDX
    //         0042455e     MOV        EDX,dword ptr [ESP + tempname[0]]
    //         00424562     OR         this,0xffffffff
    //         00424565     XOR        EAX,EAX
    //         00424567     SCASB.RE   ES:EDI
    //         00424569     MOV        this,EDX
    //         0042456b     DEC        EDI
    //         0042456c     SHR        this,0x2
    //         0042456f     MOVSD.REP  ES:EDI,ESI=>s_.col                               = 2Eh
    //                              color.cpp:228 (29)
    //         00424571     LEA        EAX,[EBP + 0x4]
    //         00424574     MOV        this,EDX
    //         00424576     PUSH       EAX
    //         00424577     AND        this,0x3
    //         0042457a     LEA        EAX=>tempname[4],[ESP + 0x18]
    //         0042457e     PUSH       s_data\%s                                        = "data\\%s"
    //         00424583     MOVSB.REP  ES:EDI,ESI=>s_.col                               = 2Eh
    //         00424585     PUSH       EAX
    //         00424586     CALL       sprintf                                          undefined sprintf()
    //         0042458b     ADD        ESP,0xc
    //                              color.cpp:229 (20)
    //         0042458e     LEA        this=>tempname[4],[ESP + 0x14]
    //         00424592     PUSH       s_r                                              = "r"
    //         00424597     PUSH       this
    //         00424598     CALL       fopen                                            undefined fopen()
    //         0042459d     MOV        EDI,EAX
    //         0042459f     ADD        ESP,0x8
    //                              color.cpp:230 (4)
    //         004245a2     TEST       EDI,EDI
    //         004245a4     JZ         LAB_004245d4
    //                              color.cpp:232 (2)
    //         004245a6     XOR        ESI,ESI
    //                               LAB_004245a8                                                 XREF[1]:     004245c9(j)  
    //                              color.cpp:234 (16)
    //         004245a8     LEA        EDX=>tempname,[ESP + 0x10]
    //         004245ac     PUSH       EDX
    //         004245ad     PUSH       s_%hd                                            = "%hd"
    //         004245b2     PUSH       EDI
    //         004245b3     CALL       fscanf                                           undefined fscanf()
    //                              color.cpp:235 (19)
    //         004245b8     MOV        AL,byte ptr [ESP + tempname[0]]
    //         004245bc     ADD        ESP,0xc
    //         004245bf     MOV        byte ptr [ESI + EBX*0x1],AL
    //         004245c2     INC        ESI
    //         004245c3     CMP        ESI,0x100
    //         004245c9     JL         LAB_004245a8
    //                              color.cpp:237 (9)
    //         004245cb     PUSH       EDI
    //         004245cc     CALL       fclose                                           undefined fclose()
    //         004245d1     ADD        ESP,0x4
    //                               LAB_004245d4                                                 XREF[1]:     004245a4(j)  
    //                              color.cpp:239 (15)
    //         004245d4     POP        EDI
    //         004245d5     MOV        EAX,EBP
    //         004245d7     POP        ESI
    //         004245d8     POP        EBP
    //         004245d9     POP        EBX
    //         004245da     ADD        ESP,0x130
    //         004245e0     RET        0x4
}

// Offset: 0x004245F0
undefined RGE_Color_Table(RGE_Color_Table* this_, TDrawArea* param_2, long param_3, tagPALETTEENTRY* param_4, tagPALETTEENTRY* param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Color_Table::RGE_Color_Table(class TDrawArea *,long,struct tagPALETTEENTRY ... *
    //                              *********************************************************************************************************
    //                              undefined __thiscall RGE_Color_Table(RGE_Color_Table * this, TDrawAr
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Color_Tabl    ECX:4 (auto)   this
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[1]:     00424613(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     004246b2(R)  
    //              tagPALETTEENTR    Stack[0xc]:4   param_3                   XREF[1]:     00424664(R)  
    //              tagPALETTEENTR    Stack[0x10]:4  param_4                   XREF[1]:     004245f6(R)  
    //              tagPALETTEENTR    Stack[-0x404   temp_palette              XREF[0,5]:   004246c2(*), 004246ef(R), 004246d5(*), 004246f4(*), 
    //                                                                                     00424700(R)  
    //              tagPALETTEENTR    Stack[-0x804   palette                   XREF[2,11]:  00424708(W), 00424725(R), 0042461a(*), 00424626(*), 
    //                                                                                     00424644(W), 004246ca(*), 00424718(R), 0042462a(*), 
    //                                                                                     00424630(*), 0042464a(*), 00424710(*), 0042471b(*), 
    //                                                                                     0042472d(R)  
    //              undefined4        Stack[-0x808   local_808                 XREF[2]:     0042470c(W), 00424735(R)  
    //              undefined4        Stack[-0x80c   local_80c                 XREF[2]:     004246f6(W), 0042471f(R)  
    //              undefined4        Stack[-0x810   local_810                 XREF[3]:     004246e3(W), 0042476f(R), 00424781(W)  
    //              undefined4        Stack[-0x814   local_814                 XREF[3]:     004246df(W), 00424763(R), 0042477d(W)  
    //              long              Stack[-0x818   index1                    XREF[3]:     00424607(W), 00424660(R), 0042475f(R)  
    //              undefined4        Stack[-0x81c   local_81c                 XREF[6,6]:   0042466f(W), 00424686(W), 004246b9(R), 004246fc(W), 
    //                                                                                     0042474f(W), 00424767(R), 00424677(W), 00424694(W), 
    //                                                                                     00424673(W), 0042468d(W), 0042467b(W), 00424698(W)  
    //              long              Stack[-0x820   temp_color
    //                               ??0RGE_Color_Table@@QAE@PAVTDrawArea@@JPAUtagPALETTEENTRY@@  XREF[2]:     set_palette:00467ea4(c), 
    //                               RGE_Color_Table::RGE_Color_Table                                          set_shadow_amount:00468282(c)  
    //                              color.cpp:245 (6)
    //         004245f0     SUB        ESP,0x81c
    //                              color.cpp:259 (29)
    //         004245f6     MOV        EDX,dword ptr [ESP + param_4]
    //         004245fd     PUSH       EBX
    //         004245fe     PUSH       EBP
    //         004245ff     PUSH       ESI
    //         00424600     MOV        ESI,this
    //         00424602     XOR        EBX,EBX
    //         00424604     CMP        EDX,EBX
    //         00424606     PUSH       EDI
    //         00424607     MOV        dword ptr [ESP + index1],ESI
    //         0042460b     MOV        dword ptr [ESI],RGE_Color_Table::`vftable'       = 00424420
    //         00424611     JNZ        LAB_00424626
    //                              color.cpp:260 (17)
    //         00424613     MOV        this,dword ptr [ESP + param_1]
    //         0042461a     LEA        EAX=>palette[1],[ESP + 0x2c]
    //         0042461e     PUSH       EAX
    //         0042461f     CALL       TDrawArea::GetPalette                            void GetPalette(TDrawArea * this, tagPALETTEE
    //                              color.cpp:261 (2)
    //         00424624     JMP        LAB_00424664
    //                               LAB_00424626                                                 XREF[1]:     00424611(j)  
    //                              color.cpp:264 (10)
    //         00424626     LEA        ESI=>palette[1],[ESP + 0x2c]
    //         0042462a     LEA        EDI=>palette[1].peGreen,[ESP + 0x2d]
    //         0042462e     SUB        ESI,EDX
    //                              color.cpp:319 (48)
    //         00424630     LEA        this=>palette[1].peGreen,[ESP + 0x2d]
    //         00424634     LEA        EAX,[EDX + 0x2]
    //         00424637     SUB        EDI,EDX
    //         00424639     MOV        EBP,0x100
    //                               LAB_0042463e                                                 XREF[1]:     0042465e(j)  
    //         0042463e     MOV        DL,byte ptr [EAX + -0x2]
    //         00424641     ADD        EAX,0x4
    //         00424644     MOV        byte ptr [ECX + palette[1].peRed],DL
    //         00424647     MOV        DL,byte ptr [EAX + -0x5]
    //         0042464a     MOV        byte ptr [this->_padding_]=>palette[1].peGreen
    //         0042464c     MOV        DL,byte ptr [EAX + -0x4]
    //         0042464f     MOV        byte ptr [ESI + EAX*0x1 + -0x4],DL
    //         00424653     MOV        DL,byte ptr [EAX + -0x3]
    //         00424656     MOV        byte ptr [EDI + EAX*0x1 + -0x4],DL
    //         0042465a     ADD        this,0x4
    //         0042465d     DEC        EBP
    //         0042465e     JNZ        LAB_0042463e
    //                              color.cpp:262 (4)
    //         00424660     MOV        ESI,dword ptr [ESP + index1]
    //                               LAB_00424664                                                 XREF[1]:     00424624(j)  
    //                              color.cpp:271 (11)
    //         00424664     MOV        EAX,dword ptr [ESP + param_3]
    //         0042466b     CMP        EAX,EBX
    //         0042466d     JNZ        LAB_00424681
    //                              color.cpp:273 (4)
    //         0042466f     MOV        byte ptr [ESP + local_81c],BL
    //                              color.cpp:274 (4)
    //         00424673     MOV        byte ptr [ESP + local_81c+0x2],BL
    //                              color.cpp:275 (4)
    //         00424677     MOV        byte ptr [ESP + local_81c+0x1],BL
    //                              color.cpp:276 (4)
    //         0042467b     MOV        byte ptr [ESP + local_81c+0x3],BL
    //                              color.cpp:278 (2)
    //         0042467f     JMP        LAB_0042469c
    //                               LAB_00424681                                                 XREF[1]:     0042466d(j)  
    //                              color.cpp:280 (2)
    //         00424681     MOV        this,byte ptr [EAX]
    //                              color.cpp:281 (7)
    //         00424683     MOV        DL,byte ptr [EAX + 0x2]
    //         00424686     MOV        byte ptr [ESP + local_81c],this
    //                              color.cpp:282 (7)
    //         0042468a     MOV        this,byte ptr [EAX + 0x1]
    //         0042468d     MOV        byte ptr [ESP + local_81c+0x2],DL
    //                              color.cpp:283 (11)
    //         00424691     MOV        DL,byte ptr [EAX + 0x3]
    //         00424694     MOV        byte ptr [ESP + local_81c+0x1],this
    //         00424698     MOV        byte ptr [ESP + local_81c+0x3],DL
    //                               LAB_0042469c                                                 XREF[1]:     0042467f(j)  
    //                              color.cpp:289 (22)
    //         0042469c     LEA        EDI,[ESI + 0x28]
    //         0042469f     MOV        this,0x40
    //         004246a4     XOR        EAX,EAX
    //         004246a6     MOV        word ptr [ESI + 0x22],BX
    //         004246aa     MOV        byte ptr [ESI + 0x25],BL
    //         004246ad     MOV        byte ptr [ESI + 0x24],BL
    //         004246b0     STOSD.REP  ES:EDI
    //                              color.cpp:292 (45)
    //         004246b2     MOV        EAX,dword ptr [ESP + param_2]
    //         004246b9     MOV        this,dword ptr [ESP + local_81c]
    //         004246bd     PUSH       -0x1
    //         004246bf     PUSH       -0x1
    //         004246c1     PUSH       EAX
    //         004246c2     LEA        EDX=>temp_palette[1],[ESP + 0x438]
    //         004246c9     PUSH       this
    //         004246ca     LEA        EAX=>palette[1],[ESP + 0x3c]
    //         004246ce     PUSH       EDX
    //         004246cf     PUSH       EAX
    //         004246d0     CALL       RGE_translate_palette                            void RGE_translate_palette(tagPALETTEENTRY * 
    //         004246d5     LEA        this=>temp_palette[1].peGreen,[ESP + 0x445]
    //         004246dc     ADD        ESP,0x18
    //                              color.cpp:295 (10)
    //         004246df     MOV        dword ptr [ESP + local_814],EBX
    //         004246e3     MOV        dword ptr [ESP + local_810],this
    //         004246e7     JMP        LAB_004246eb
    //                               LAB_004246e9                                                 XREF[1]:     00424785(j)  
    //                              color.cpp:286 (2)
    //         004246e9     XOR        EBX,EBX
    //                               LAB_004246eb                                                 XREF[1]:     004246e7(j)  
    //                              color.cpp:301 (7)
    //         004246eb     XOR        EDX,EDX
    //         004246ed     XOR        EBP,EBP
    //         004246ef     MOV        DL,byte ptr [ECX + temp_palette[1].peRed]
    //                              color.cpp:302 (8)
    //         004246f2     XOR        EAX,EAX
    //         004246f4     MOV        AL,byte ptr [this->_padding_]=>temp_palette[1]
    //         004246f6     MOV        dword ptr [ESP + local_80c],EDX
    //                              color.cpp:303 (54)
    //         004246fa     XOR        EDX,EDX
    //         004246fc     MOV        dword ptr [ESP + local_81c],EBX
    //         00424700     MOV        DL,byte ptr [ECX + temp_palette[1].peBlue]
    //         00424703     MOV        EDI,0x4e20
    //         00424708     MOV        dword ptr [ESP + palette[0].peRed],EAX
    //         0042470c     MOV        dword ptr [ESP + local_808],EDX
    //         00424710     LEA        ESI=>palette[1].peGreen,[ESP + 0x2d]
    //                               LAB_00424714                                                 XREF[1]:     0042475d(j)  
    //         00424714     XOR        EAX,EAX
    //         00424716     XOR        EDX,EDX
    //         00424718     MOV        AL,byte ptr [ESI + palette[1].peRed]
    //         0042471b     MOV        DL,byte ptr [ESI]=>palette[1].peGreen
    //         0042471d     MOV        this,EAX
    //         0042471f     MOV        EAX,dword ptr [ESP + local_80c]
    //         00424723     SUB        EAX,this
    //         00424725     MOV        this,dword ptr [ESP + palette[0].peRed]
    //         00424729     SUB        this,EDX
    //         0042472b     XOR        EDX,EDX
    //         0042472d     MOV        DL,byte ptr [ESI + palette[1].peBlue]
    //                              color.cpp:310 (25)
    //         00424730     IMUL       EAX,EAX
    //         00424733     MOV        EBX,EDX
    //         00424735     MOV        EDX,dword ptr [ESP + local_808]
    //         00424739     SUB        EDX,EBX
    //         0042473b     MOV        EBX,this
    //         0042473d     IMUL       EBX,this
    //         00424740     MOV        this,EDX
    //         00424742     ADD        EAX,EBX
    //         00424744     IMUL       this,EDX
    //         00424747     ADD        EAX,this
    //                              color.cpp:311 (4)
    //         00424749     CMP        EAX,EDI
    //         0042474b     JGE        LAB_00424753
    //                              color.cpp:313 (2)
    //         0042474d     MOV        EDI,EAX
    //                              color.cpp:314 (16)
    //         0042474f     MOV        dword ptr [ESP + local_81c],EBP
    //                               LAB_00424753                                                 XREF[1]:     0042474b(j)  
    //         00424753     INC        EBP
    //         00424754     ADD        ESI,0x4
    //         00424757     CMP        EBP,0xff
    //         0042475d     JLE        LAB_00424714
    //                              color.cpp:317 (44)
    //         0042475f     MOV        EAX,dword ptr [ESP + index1]
    //         00424763     MOV        EDX,dword ptr [ESP + local_814]
    //         00424767     MOV        this,byte ptr [ESP + local_81c]
    //         0042476b     MOV        byte ptr [EDX + EAX*0x1 + 0x28],this
    //         0042476f     MOV        this,dword ptr [ESP + local_810]
    //         00424773     INC        EDX
    //         00424774     ADD        this,0x4
    //         00424777     CMP        EDX,0xff
    //         0042477d     MOV        dword ptr [ESP + local_814],EDX
    //         00424781     MOV        dword ptr [ESP + local_810],this
    //         00424785     JLE        LAB_004246e9
    //                              color.cpp:319 (13)
    //         0042478b     POP        EDI
    //         0042478c     POP        ESI
    //         0042478d     POP        EBP
    //         0042478e     POP        EBX
    //         0042478f     ADD        ESP,0x81c
    //         00424795     RET        0x10
}

// Offset: 0x004247A0
void RGE_Color_Table(RGE_Color_Table* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall RGE_Color_Table::~RGE_Color_Table(void)                                    *
    //                              *********************************************************************************************************
    //                              void __thiscall ~RGE_Color_Table(RGE_Color_Table * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Color_Tabl    ECX:4 (auto)   this
    //                               ??1RGE_Color_Table@@UAE@XZ                                   XREF[1]:     `scalar_deleting_destructor':00424
    //                               RGE_Color_Table::~RGE_Color_Table
    //                              color.cpp:323 (6)
    //         004247a0     MOV        dword ptr [this->_padding_],RGE_Color_Table::`   = 00424420
    //                              color.cpp:324 (1)
    //         004247a6     RET
}

// Offset: 0x004247B0
void save(RGE_Color_Table* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Color_Table::save(int)                                                    *
    //                              *********************************************************************************************************
    //                              void __thiscall save(RGE_Color_Table * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Color_Tabl    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004247b4(R)  
    //                               ?save@RGE_Color_Table@@QAEXH@Z                               XREF[1]:     base_save:005438f6(c)  
    //                               RGE_Color_Table::save
    //                              color.cpp:329 (4)
    //         004247b0     PUSH       ESI
    //         004247b1     MOV        ESI,this
    //         004247b3     PUSH       EDI
    //                              color.cpp:330 (19)
    //         004247b4     MOV        EDI,dword ptr [ESP + param_1]
    //         004247b8     LEA        EAX,[ESI + 0x4]
    //         004247bb     PUSH       0x1e
    //         004247bd     PUSH       EAX
    //         004247be     PUSH       EDI
    //         004247bf     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004247c4     ADD        ESP,0xc
    //                              color.cpp:331 (15)
    //         004247c7     LEA        this,[ESI + 0x26]
    //         004247ca     PUSH       0x2
    //         004247cc     PUSH       this
    //         004247cd     PUSH       EDI
    //         004247ce     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004247d3     ADD        ESP,0xc
    //                              color.cpp:332 (15)
    //         004247d6     LEA        EDX,[ESI + 0x22]
    //         004247d9     PUSH       0x2
    //         004247db     PUSH       EDX
    //         004247dc     PUSH       EDI
    //         004247dd     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004247e2     ADD        ESP,0xc
    //                              color.cpp:333 (15)
    //         004247e5     LEA        EAX,[ESI + 0x25]
    //         004247e8     PUSH       0x1
    //         004247ea     PUSH       EAX
    //         004247eb     PUSH       EDI
    //         004247ec     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004247f1     ADD        ESP,0xc
    //                              color.cpp:334 (15)
    //         004247f4     ADD        ESI,0x24
    //         004247f7     PUSH       0x1
    //         004247f9     PUSH       ESI
    //         004247fa     PUSH       EDI
    //         004247fb     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00424800     ADD        ESP,0xc
    //                              color.cpp:335 (5)
    //         00424803     POP        EDI
    //         00424804     POP        ESI
    //         00424805     RET        0x4
}

