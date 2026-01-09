#include "common.h"
#include "fractal.h"

void PointMaker::SetDefaultValues() {
    /* TODO: Stub */
    //                              void __thiscall SetDefaultValues(PointMaker * this)
    //              void              <VOID>         <RETURN>
    //              PointMaker *      ECX:4 (auto)   this
    //                               ?SetDefaultValues@PointMaker@@QAEXXZ                         XREF[2]:     PointMaker:0044ac61(c), 
    //                               PointMaker::SetDefaultValues                                              ~PointMaker:0044ac8a(c)  
    //                              fractal.cpp:29 (3)
    //         0044ab90     PUSH       ESI
    //         0044ab91     MOV        EDX,this
    //                              fractal.cpp:31 (10)
    //         0044ab93     MOV        ESI,0x2
    //         0044ab98     MOV        EAX,0x3
    //                              fractal.cpp:34 (11)
    //         0044ab9d     MOV        this,0x118
    //         0044aba2     MOV        dword ptr [EDX + 0xfc4],ESI
    //                              fractal.cpp:38 (31)
    //         0044aba8     MOV        dword ptr [EDX + 0xffc],ESI
    //         0044abae     PUSH       EDI
    //         0044abaf     MOV        dword ptr [EDX + 0xfc0],EAX
    //         0044abb5     MOV        dword ptr [EDX + 0xfd8],this
    //         0044abbb     MOV        dword ptr [EDX + 0xfd4],this
    //         0044abc1     MOV        dword ptr [EDX + 0xff8],EAX
    //                              fractal.cpp:40 (2)
    //         0044abc7     XOR        ESI,ESI
    //                              fractal.cpp:42 (6)
    //         0044abc9     MOV        dword ptr [EDX + 0x100c],EAX
    //                              fractal.cpp:48 (88)
    //         0044abcf     MOV        this,0x3e8
    //         0044abd4     XOR        EAX,EAX
    //         0044abd6     LEA        EDI,[EDX + 0x8]
    //         0044abd9     MOV        dword ptr [EDX + 0xfc8],0x32
    //         0044abe3     MOV        dword ptr [EDX + 0xfcc],0x6
    //         0044abed     MOV        dword ptr [EDX + 0x1000],0x4
    //         0044abf7     MOV        dword ptr [EDX + 0x1040],0xf
    //         0044ac01     MOV        dword ptr [EDX + 0xfd0],ESI
    //         0044ac07     MOV        dword ptr [EDX + 0x1008],0x1
    //         0044ac11     MOV        dword ptr [EDX + 0x1018],0x10
    //         0044ac1b     MOV        dword ptr [EDX + 0xfdc],0x7d0
    //         0044ac25     STOSD.REP  ES:EDI
    //                              fractal.cpp:49 (6)
    //         0044ac27     MOV        dword ptr [EDX + 0x1030],ESI
    //                              fractal.cpp:50 (6)
    //         0044ac2d     MOV        dword ptr [EDX + 0x1034],ESI
    //                              fractal.cpp:51 (6)
    //         0044ac33     MOV        dword ptr [EDX + 0x103c],ESI
    //                              fractal.cpp:52 (6)
    //         0044ac39     MOV        dword ptr [EDX + 0x1038],ESI
    //                              fractal.cpp:53 (3)
    //         0044ac3f     POP        EDI
    //         0044ac40     POP        ESI
    //         0044ac41     RET
    //         0044ac42     ??         90h
    //         0044ac43     NOP
    //         0044ac44     NOP
    //         0044ac45     NOP
    //         0044ac46     NOP
    //         0044ac47     NOP
    //         0044ac48     NOP
    //         0044ac49     NOP
    //         0044ac4a     NOP
    //         0044ac4b     NOP
    //         0044ac4c     NOP
    //         0044ac4d     NOP
    //         0044ac4e     NOP
    //         0044ac4f     NOP
    return;
}

PointMaker::PointMaker() {
    /* TODO: Stub */
    //                              undefined __thiscall PointMaker(PointMaker * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              PointMaker *      ECX:4 (auto)   this
    //                               ??0PointMaker@@QAE@XZ
    //                               PointMaker::PointMaker
    //                              fractal.cpp:56 (17)
    //         0044ac50     PUSH       ESI
    //         0044ac51     MOV        ESI,this
    //         0044ac53     XOR        EAX,EAX
    //         0044ac55     MOV        dword ptr [ESI + 0x1024],EAX
    //         0044ac5b     MOV        dword ptr [ESI + 0x1028],EAX
    //                              fractal.cpp:57 (5)
    //         0044ac61     CALL       PointMaker::SetDefaultValues                     void SetDefaultValues(PointMaker * this)
    //                              fractal.cpp:58 (7)
    //         0044ac66     MOV        this,ESI
    //         0044ac68     CALL       PointMaker::MakeArrays                           void MakeArrays(PointMaker * this)
    //                              fractal.cpp:59 (7)
    //         0044ac6d     MOV        this,ESI
    //         0044ac6f     CALL       PointMaker::CreateMasks                          void CreateMasks(PointMaker * this)
    //                              fractal.cpp:60 (4)
    //         0044ac74     MOV        EAX,ESI
    //         0044ac76     POP        ESI
    //         0044ac77     RET
    //         0044ac78     ??         90h
    //         0044ac79     NOP
    //         0044ac7a     NOP
    //         0044ac7b     NOP
    //         0044ac7c     NOP
    //         0044ac7d     NOP
    //         0044ac7e     NOP
    //         0044ac7f     NOP
}

PointMaker::~PointMaker() {
    /* TODO: Stub */
    //                              void __thiscall ~PointMaker(PointMaker * this)
    //              void              <VOID>         <RETURN>
    //              PointMaker *      ECX:4 (auto)   this
    //                               ??1PointMaker@@QAE@XZ
    //                               PointMaker::~PointMaker
    //                              fractal.cpp:63 (3)
    //         0044ac80     PUSH       ESI
    //         0044ac81     MOV        ESI,this
    //                              fractal.cpp:64 (5)
    //         0044ac83     CALL       PointMaker::DeleteArrays                         void DeleteArrays(PointMaker * this)
    //                              fractal.cpp:65 (7)
    //         0044ac88     MOV        this,ESI
    //         0044ac8a     CALL       PointMaker::SetDefaultValues                     void SetDefaultValues(PointMaker * this)
    //                              fractal.cpp:66 (2)
    //         0044ac8f     XOR        EAX,EAX
    //                              fractal.cpp:67 (19)
    //         0044ac91     MOV        this,ESI
    //         0044ac93     MOV        dword ptr [ESI + 0x1024],EAX
    //         0044ac99     MOV        dword ptr [ESI + 0x1028],EAX
    //         0044ac9f     CALL       PointMaker::DeleteMasks                          void DeleteMasks(PointMaker * this)
    //                              fractal.cpp:68 (2)
    //         0044aca4     POP        ESI
    //         0044aca5     RET
    //         0044aca6     ??         90h
    //         0044aca7     NOP
    //         0044aca8     NOP
    //         0044aca9     NOP
    //         0044acaa     NOP
    //         0044acab     NOP
    //         0044acac     NOP
    //         0044acad     NOP
    //         0044acae     NOP
    //         0044acaf     NOP
}

void PointMaker::CreateMasks() {
    /* TODO: Stub */
    //                              void __thiscall CreateMasks(PointMaker * this)
    //              void              <VOID>         <RETURN>
    //              PointMaker *      ECX:4 (auto)   this
    //              undefined1        Stack[-0x4]:1  local_4                   XREF[1]:     0044ae86(W)  
    //              undefined1        Stack[-0x5]:1  local_5                   XREF[1]:     0044ae7f(W)  
    //              undefined1        Stack[-0x6]:1  local_6                   XREF[1]:     0044ae78(W)  
    //              undefined1        Stack[-0x7]:1  local_7                   XREF[1]:     0044ae71(W)  
    //              char[49]          Stack[-0x38]   ptr5                      XREF[1,49]:  0044ae05(W), 0044ae09(W), 0044ae0d(W), 0044ae11(W), 
    //                                                                                     0044ae15(W), 0044af70(*), 0044ae19(W), 0044ae1d(W), 
    //                                                                                     0044ae21(W), 0044ae25(W), 0044ae29(W), 0044ae2d(W), 
    //                                                                                     0044ae31(W), 0044aeab(W), 0044aeaf(W), 0044aeb3(W), 
    //                                                                                     0044aeb7(W), 0044aebb(W), 0044ae35(W), 0044ae39(W)  
    //              char[36]          Stack[-0x5c]   ptr4                      XREF[1,33]:  0044ada1(W), 0044ada5(W), 0044af5f(*), 0044ada9(W), 
    //                                                                                     0044adad(W), 0044adb1(W), 0044adb5(W), 0044adb9(W), 
    //                                                                                     0044adbd(W), 0044adc1(W), 0044adc5(W), 0044adc9(W), 
    //                                                                                     0044adcd(W), 0044add1(W), 0044add5(W), 0044add9(W), 
    //                                                                                     0044addd(W), 0044ade1(W), 0044ade5(W), 0044ade9(W)  
    //              undefined1        Stack[-0x5d]:1 local_5d                  XREF[1]:     0044ad9d(W)  
    //              undefined1        Stack[-0x5e]:1 local_5e                  XREF[1]:     0044ad99(W)  
    //              undefined1        Stack[-0x5f]:1 local_5f                  XREF[1]:     0044ad95(W)  
    //              char[25]          Stack[-0x78]   ptr3                      XREF[2,25]:  0044ad31(W), 0044af3c(R), 0044ad35(W), 0044ad39(W), 
    //                                                                                     0044ad3d(W), 0044ad41(W), 0044af30(*), 0044ad45(W), 
    //                                                                                     0044ad49(W), 0044ad4d(W), 0044ad51(W), 0044ad55(W), 
    //                                                                                     0044ad59(W), 0044ad5d(W), 0044ad61(W), 0044ad65(W), 
    //                                                                                     0044ad69(W), 0044ad6d(W), 0044ad71(W), 0044ad75(W)  
    //              char[16]          Stack[-0x88]   ptr2                      XREF[0,15]:  0044ad01(W), 0044aefa(R), 0044ad05(W), 0044ad09(W), 
    //                                                                                     0044ad0d(W), 0044ad11(W), 0044af26(R), 0044ad15(W), 
    //                                                                                     0044ad19(W), 0044ad1d(W), 0044ad21(W), 0044af2c(R), 
    //                                                                                     0044ad25(W), 0044ad29(W), 0044ad2d(W)  
    //                               ?CreateMasks@PointMaker@@IAEXXZ                              XREF[1]:     PointMaker:0044ac6f(c)  
    //                               PointMaker::CreateMasks
    //                              fractal.cpp:71 (11)
    //         0044acb0     SUB        ESP,0x84
    //         0044acb6     PUSH       EBX
    //         0044acb7     PUSH       ESI
    //         0044acb8     PUSH       EDI
    //         0044acb9     MOV        EBX,this
    //                              fractal.cpp:75 (64)
    //         0044acbb     PUSH       0x10
    //         0044acbd     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0044acc2     ADD        ESP,0x4
    //         0044acc5     MOV        dword ptr [EBX + 0xfa8],EAX
    //         0044accb     PUSH       0x19
    //         0044accd     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0044acd2     ADD        ESP,0x4
    //         0044acd5     MOV        dword ptr [EBX + 0xfac],EAX
    //         0044acdb     PUSH       0x24
    //         0044acdd     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0044ace2     ADD        ESP,0x4
    //         0044ace5     MOV        dword ptr [EBX + 0xfb0],EAX
    //         0044aceb     PUSH       0x31
    //         0044aced     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0044acf2     ADD        ESP,0x4
    //         0044acf5     MOV        dword ptr [EBX + 0xfb4],EAX
    //                              fractal.cpp:77 (2)
    //         0044acfb     XOR        AL,AL
    //                              fractal.cpp:78 (2)
    //         0044acfd     MOV        this,0x1
    //                              fractal.cpp:84 (126)
    //         0044acff     MOV        DL,0x2
    //         0044ad01     MOV        byte ptr [ESP + ptr2[4]],AL
    //         0044ad05     MOV        byte ptr [ESP + ptr2[5]],AL
    //         0044ad09     MOV        byte ptr [ESP + ptr2[6]],AL
    //         0044ad0d     MOV        byte ptr [ESP + ptr2[7]],AL
    //         0044ad11     MOV        byte ptr [ESP + ptr2[8]],AL
    //         0044ad15     MOV        byte ptr [ESP + ptr2[9]],this
    //         0044ad19     MOV        byte ptr [ESP + ptr2[10]],this
    //         0044ad1d     MOV        byte ptr [ESP + ptr2[11]],AL
    //         0044ad21     MOV        byte ptr [ESP + ptr2[12]],AL
    //         0044ad25     MOV        byte ptr [ESP + ptr2[13]],this
    //         0044ad29     MOV        byte ptr [ESP + ptr2[14]],this
    //         0044ad2d     MOV        byte ptr [ESP + ptr2[15]],AL
    //         0044ad31     MOV        byte ptr [ESP + ptr3[0]],AL
    //         0044ad35     MOV        byte ptr [ESP + ptr3[1]],AL
    //         0044ad39     MOV        byte ptr [ESP + ptr3[2]],AL
    //         0044ad3d     MOV        byte ptr [ESP + ptr3[3]],AL
    //         0044ad41     MOV        byte ptr [ESP + ptr3[4]],AL
    //         0044ad45     MOV        byte ptr [ESP + ptr3[5]],AL
    //         0044ad49     MOV        byte ptr [ESP + ptr3[6]],AL
    //         0044ad4d     MOV        byte ptr [ESP + ptr3[7]],AL
    //         0044ad51     MOV        byte ptr [ESP + ptr3[8]],AL
    //         0044ad55     MOV        byte ptr [ESP + ptr3[9]],AL
    //         0044ad59     MOV        byte ptr [ESP + ptr3[10]],this
    //         0044ad5d     MOV        byte ptr [ESP + ptr3[11]],this
    //         0044ad61     MOV        byte ptr [ESP + ptr3[12]],this
    //         0044ad65     MOV        byte ptr [ESP + ptr3[13]],AL
    //         0044ad69     MOV        byte ptr [ESP + ptr3[14]],AL
    //         0044ad6d     MOV        byte ptr [ESP + ptr3[15]],this
    //         0044ad71     MOV        byte ptr [ESP + ptr3[16]],DL
    //         0044ad75     MOV        byte ptr [ESP + ptr3[17]],this
    //         0044ad79     MOV        byte ptr [ESP + ptr3[18]],AL
    //                              fractal.cpp:85 (20)
    //         0044ad7d     MOV        byte ptr [ESP + ptr3[19]],AL
    //         0044ad81     MOV        byte ptr [ESP + ptr3[20]],this
    //         0044ad85     MOV        byte ptr [ESP + ptr3[21]],this
    //         0044ad89     MOV        byte ptr [ESP + ptr3[22]],this
    //         0044ad8d     MOV        byte ptr [ESP + ptr3[23]],AL
    //                              fractal.cpp:86 (20)
    //         0044ad91     MOV        byte ptr [ESP + ptr3[24]],AL
    //         0044ad95     MOV        byte ptr [ESP + local_5f],AL
    //         0044ad99     MOV        byte ptr [ESP + local_5e],AL
    //         0044ad9d     MOV        byte ptr [ESP + local_5d],AL
    //         0044ada1     MOV        byte ptr [ESP + ptr4[0]],AL
    //                              fractal.cpp:88 (24)
    //         0044ada5     MOV        byte ptr [ESP + ptr4[4]],AL
    //         0044ada9     MOV        byte ptr [ESP + ptr4[5]],AL
    //         0044adad     MOV        byte ptr [ESP + ptr4[6]],AL
    //         0044adb1     MOV        byte ptr [ESP + ptr4[7]],AL
    //         0044adb5     MOV        byte ptr [ESP + ptr4[8]],AL
    //         0044adb9     MOV        byte ptr [ESP + ptr4[9]],AL
    //                              fractal.cpp:89 (24)
    //         0044adbd     MOV        byte ptr [ESP + ptr4[10]],AL
    //         0044adc1     MOV        byte ptr [ESP + ptr4[11]],this
    //         0044adc5     MOV        byte ptr [ESP + ptr4[12]],this
    //         0044adc9     MOV        byte ptr [ESP + ptr4[13]],this
    //         0044adcd     MOV        byte ptr [ESP + ptr4[14]],this
    //         0044add1     MOV        byte ptr [ESP + ptr4[15]],AL
    //                              fractal.cpp:90 (24)
    //         0044add5     MOV        byte ptr [ESP + ptr4[16]],AL
    //         0044add9     MOV        byte ptr [ESP + ptr4[17]],this
    //         0044addd     MOV        byte ptr [ESP + ptr4[18]],DL
    //         0044ade1     MOV        byte ptr [ESP + ptr4[19]],DL
    //         0044ade5     MOV        byte ptr [ESP + ptr4[20]],this
    //         0044ade9     MOV        byte ptr [ESP + ptr4[21]],AL
    //                              fractal.cpp:91 (8)
    //         0044aded     MOV        byte ptr [ESP + ptr4[22]],AL
    //         0044adf1     MOV        byte ptr [ESP + ptr4[27]],AL
    //                              fractal.cpp:92 (8)
    //         0044adf5     MOV        byte ptr [ESP + ptr4[28]],AL
    //         0044adf9     MOV        byte ptr [ESP + ptr4[33]],AL
    //                              fractal.cpp:93 (24)
    //         0044adfd     MOV        byte ptr [ESP + ptr4[34]],AL
    //         0044ae01     MOV        byte ptr [ESP + ptr4[35]],AL
    //         0044ae05     MOV        byte ptr [ESP + ptr5[0]],AL
    //         0044ae09     MOV        byte ptr [ESP + ptr5[1]],AL
    //         0044ae0d     MOV        byte ptr [ESP + ptr5[2]],AL
    //         0044ae11     MOV        byte ptr [ESP + ptr5[3]],AL
    //                              fractal.cpp:95 (28)
    //         0044ae15     MOV        byte ptr [ESP + ptr5[4]],AL
    //         0044ae19     MOV        byte ptr [ESP + ptr5[5]],AL
    //         0044ae1d     MOV        byte ptr [ESP + ptr5[6]],AL
    //         0044ae21     MOV        byte ptr [ESP + ptr5[7]],AL
    //         0044ae25     MOV        byte ptr [ESP + ptr5[8]],AL
    //         0044ae29     MOV        byte ptr [ESP + ptr5[9]],AL
    //         0044ae2d     MOV        byte ptr [ESP + ptr5[10]],AL
    //                              fractal.cpp:96 (8)
    //         0044ae31     MOV        byte ptr [ESP + ptr5[11]],AL
    //         0044ae35     MOV        byte ptr [ESP + ptr5[17]],AL
    //                              fractal.cpp:97 (8)
    //         0044ae39     MOV        byte ptr [ESP + ptr5[18]],AL
    //         0044ae3d     MOV        byte ptr [ESP + ptr5[24]],AL
    //                              fractal.cpp:98 (8)
    //         0044ae41     MOV        byte ptr [ESP + ptr5[25]],AL
    //         0044ae45     MOV        byte ptr [ESP + ptr5[31]],AL
    //                              fractal.cpp:99 (8)
    //         0044ae49     MOV        byte ptr [ESP + ptr5[32]],AL
    //         0044ae4d     MOV        byte ptr [ESP + ptr5[38]],AL
    //                              fractal.cpp:100 (11)
    //         0044ae51     MOV        byte ptr [ESP + ptr5[39]],AL
    //         0044ae55     MOV        byte ptr [ESP + ptr5[45]],AL
    //                              fractal.cpp:101 (49)
    //         0044ae5c     MOV        byte ptr [ESP + ptr5[46]],AL
    //         0044ae63     MOV        byte ptr [ESP + ptr5[47]],AL
    //         0044ae6a     MOV        byte ptr [ESP + ptr5[48]],AL
    //         0044ae71     MOV        byte ptr [ESP + local_7],AL
    //         0044ae78     MOV        byte ptr [ESP + local_6],AL
    //         0044ae7f     MOV        byte ptr [ESP + local_5],AL
    //         0044ae86     MOV        byte ptr [ESP + local_4],AL
    //                              fractal.cpp:102 (163)
    //         0044ae8d     MOV        EAX,dword ptr [EBX + 0xfa8]
    //         0044ae93     MOV        byte ptr [ESP + ptr4[23]],this
    //         0044ae97     MOV        byte ptr [ESP + ptr4[26]],this
    //         0044ae9b     MOV        byte ptr [ESP + ptr4[29]],this
    //         0044ae9f     MOV        byte ptr [ESP + ptr4[30]],this
    //         0044aea3     MOV        byte ptr [ESP + ptr4[31]],this
    //         0044aea7     MOV        byte ptr [ESP + ptr4[32]],this
    //         0044aeab     MOV        byte ptr [ESP + ptr5[12]],this
    //         0044aeaf     MOV        byte ptr [ESP + ptr5[13]],this
    //         0044aeb3     MOV        byte ptr [ESP + ptr5[14]],this
    //         0044aeb7     MOV        byte ptr [ESP + ptr5[15]],this
    //         0044aebb     MOV        byte ptr [ESP + ptr5[16]],this
    //         0044aebf     MOV        byte ptr [ESP + ptr5[19]],this
    //         0044aec3     MOV        byte ptr [ESP + ptr5[23]],this
    //         0044aec7     MOV        byte ptr [ESP + ptr5[26]],this
    //         0044aecb     MOV        byte ptr [ESP + ptr5[30]],this
    //         0044aecf     MOV        byte ptr [ESP + ptr5[33]],this
    //         0044aed3     MOV        byte ptr [ESP + ptr5[37]],this
    //         0044aed7     MOV        byte ptr [ESP + ptr5[40]],this
    //         0044aede     MOV        byte ptr [ESP + ptr5[41]],this
    //         0044aee5     MOV        byte ptr [ESP + ptr5[42]],this
    //         0044aeec     MOV        byte ptr [ESP + ptr5[43]],this
    //         0044aef3     MOV        byte ptr [ESP + ptr5[44]],this
    //         0044aefa     MOV        this,dword ptr [ESP + ptr2[4]]
    //         0044aefe     MOV        byte ptr [ESP + ptr4[24]],DL
    //         0044af02     MOV        byte ptr [ESP + ptr4[25]],DL
    //         0044af06     MOV        byte ptr [ESP + ptr5[20]],DL
    //         0044af0a     MOV        byte ptr [ESP + ptr5[21]],DL
    //         0044af0e     MOV        byte ptr [ESP + ptr5[22]],DL
    //         0044af12     MOV        byte ptr [ESP + ptr5[27]],DL
    //         0044af16     MOV        byte ptr [ESP + ptr5[29]],DL
    //         0044af1a     MOV        byte ptr [ESP + ptr5[34]],DL
    //         0044af1e     MOV        byte ptr [ESP + ptr5[35]],DL
    //         0044af22     MOV        byte ptr [ESP + ptr5[36]],DL
    //         0044af26     MOV        EDX,dword ptr [ESP + ptr2[8]]
    //         0044af2a     MOV        dword ptr [EAX],this
    //         0044af2c     MOV        this,dword ptr [ESP + ptr2[12]]
    //                              fractal.cpp:103 (36)
    //         0044af30     LEA        ESI=>ptr3[4],[ESP + 0x1c]
    //         0044af34     MOV        byte ptr [ESP + ptr5[28]],0x3
    //         0044af39     MOV        dword ptr [EAX + 0x4],EDX
    //         0044af3c     MOV        EDX,dword ptr [ESP + ptr3[0]]
    //         0044af40     MOV        dword ptr [EAX + 0x8],this
    //         0044af43     MOV        this,0x6
    //         0044af48     MOV        dword ptr [EAX + 0xc],EDX
    //         0044af4b     MOV        EDI,dword ptr [EBX + 0xfac]
    //         0044af51     MOVSD.REP  ES:EDI,ESI
    //         0044af53     MOVSB      ES:EDI,ESI
    //                              fractal.cpp:104 (17)
    //         0044af54     MOV        EDI,dword ptr [EBX + 0xfb0]
    //         0044af5a     MOV        this,0x9
    //         0044af5f     LEA        ESI=>ptr4[4],[ESP + 0x38]
    //         0044af63     MOVSD.REP  ES:EDI,ESI
    //                              fractal.cpp:105 (18)
    //         0044af65     MOV        EDI,dword ptr [EBX + 0xfb4]
    //         0044af6b     MOV        this,0xc
    //         0044af70     LEA        ESI=>ptr5[4],[ESP + 0x5c]
    //         0044af74     MOVSD.REP  ES:EDI,ESI
    //         0044af76     MOVSB      ES:EDI,ESI
    //                              fractal.cpp:106 (10)
    //         0044af77     POP        EDI
    //         0044af78     POP        ESI
    //         0044af79     POP        EBX
    //         0044af7a     ADD        ESP,0x84
    //         0044af80     RET
    //         0044af81     ??         90h
    //         0044af82     NOP
    //         0044af83     NOP
    //         0044af84     NOP
    //         0044af85     NOP
    //         0044af86     NOP
    //         0044af87     NOP
    //         0044af88     NOP
    //         0044af89     NOP
    //         0044af8a     NOP
    //         0044af8b     NOP
    //         0044af8c     NOP
    //         0044af8d     NOP
    //         0044af8e     NOP
    //         0044af8f     NOP
    return;
}

void PointMaker::DeleteMasks() {
    /* TODO: Stub */
    //                              void __thiscall DeleteMasks(PointMaker * this)
    //              void              <VOID>         <RETURN>
    //              PointMaker *      ECX:4 (auto)   this
    //                               ?DeleteMasks@PointMaker@@IAEXXZ                              XREF[1]:     ~PointMaker:0044ac9f(c)  
    //                               PointMaker::DeleteMasks
    //                              fractal.cpp:109 (3)
    //         0044af90     PUSH       ESI
    //         0044af91     MOV        ESI,this
    //                              fractal.cpp:110 (27)
    //         0044af93     MOV        EAX,dword ptr [ESI + 0xfa8]
    //         0044af99     PUSH       EAX
    //         0044af9a     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0044af9f     MOV        this,dword ptr [ESI + 0xfac]
    //         0044afa5     ADD        ESP,0x4
    //         0044afa8     PUSH       this
    //         0044afa9     CALL       operator_delete                                  void operator_delete(void * param_1)
    //                              fractal.cpp:111 (33)
    //         0044afae     MOV        EDX,dword ptr [ESI + 0xfb0]
    //         0044afb4     ADD        ESP,0x4
    //         0044afb7     PUSH       EDX
    //         0044afb8     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0044afbd     MOV        EAX,dword ptr [ESI + 0xfb4]
    //         0044afc3     ADD        ESP,0x4
    //         0044afc6     PUSH       EAX
    //         0044afc7     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0044afcc     ADD        ESP,0x4
    //                              fractal.cpp:112 (2)
    //         0044afcf     POP        ESI
    //         0044afd0     RET
    //         0044afd1     ??         90h
    //         0044afd2     NOP
    //         0044afd3     NOP
    //         0044afd4     NOP
    //         0044afd5     NOP
    //         0044afd6     NOP
    //         0044afd7     NOP
    //         0044afd8     NOP
    //         0044afd9     NOP
    //         0044afda     NOP
    //         0044afdb     NOP
    //         0044afdc     NOP
    //         0044afdd     NOP
    //         0044afde     NOP
    //         0044afdf     NOP
    return;
}

void PointMaker::DrawMask(int param_1, int param_2, int param_3) {
    /* TODO: Stub */
    //                              void __thiscall DrawMask(PointMaker * this, int param_1, int param_2
    //              void              <VOID>         <RETURN>
    //              PointMaker *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[14]:    0044afe3(R), 0044b078(W), 0044b091(R), 0044b09d(W), 
    //                                                                                     0044b0c4(R), 0044b0cc(W), 0044b0e1(W), 0044b0fa(R), 
    //                                                                                     0044b106(W), 0044b126(R), 0044b12e(W), 0044b15c(R), 
    //                                                                                     0044b1d7(R), 0044b1e7(W)  
    //              int               Stack[0x8]:4   param_2                   XREF[10]:    0044b001(R), 0044b087(W), 0044b095(W), 0044b0a3(W), 
    //                                                                                     0044b0ab(R), 0044b0f0(W), 0044b0fe(W), 0044b10c(W), 
    //                                                                                     0044b13b(R), 0044b1cb(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[4]:     0044b00d(R), 0044b164(W), 0044b1bf(R), 0044b1c5(W)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0044b02f(W), 0044b1d3(R)  
    //              int               Stack[-0x8]:4  len                       XREF[2]:     0044b168(W), 0044b16e(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[3]:     0044b154(W), 0044b1db(R), 0044b1f2(W)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[3]:     0044b147(W), 0044b1cf(R), 0044b1ee(W)  
    //              int               Stack[-0x14]:4 mapptr
    //                               ?DrawMask@PointMaker@@IAEXHHH@Z
    //                               PointMaker::DrawMask
    //                              fractal.cpp:115 (3)
    //         0044afe0     SUB        ESP,0x10
    //                              fractal.cpp:116 (70)
    //         0044afe3     MOV        EDX,dword ptr [ESP + param_1]
    //         0044afe7     PUSH       EBX
    //         0044afe8     PUSH       EBP
    //         0044afe9     PUSH       ESI
    //         0044afea     PUSH       EDI
    //         0044afeb     MOV        EDI,this
    //         0044afed     MOV        EBP,dword ptr [EDI + 0xfd4]
    //         0044aff3     CMP        EDX,EBP
    //         0044aff5     JG         LAB_0044b1fc
    //         0044affb     MOV        ESI,dword ptr [EDI + 0xfd8]
    //         0044b001     MOV        EAX,dword ptr [ESP + param_2]
    //         0044b005     CMP        EAX,ESI
    //         0044b007     JG         LAB_0044b1fc
    //         0044b00d     MOV        this,dword ptr [ESP + param_3]
    //         0044b011     LEA        EBX,[ECX + EDX*0x1 + this+0x2]
    //         0044b015     TEST       EBX,EBX
    //         0044b017     JL         LAB_0044b1fc
    //         0044b01d     LEA        EBX,[ECX + EAX*0x1 + this+0x2]
    //         0044b021     TEST       EBX,EBX
    //         0044b023     JL         LAB_0044b1fc
    //                              fractal.cpp:118 (3)
    //         0044b029     LEA        EBX,[ECX + this+0x2]
    //                              fractal.cpp:120 (9)
    //         0044b02c     CMP        this,0x2
    //         0044b02f     MOV        dword ptr [ESP + local_4],EBX
    //         0044b033     JNZ        LAB_0044b051
    //                              fractal.cpp:123 (7)
    //         0044b035     LEA        EBX,[EDX + 0x4]
    //         0044b038     CMP        EBX,EBP
    //         0044b03a     JG         LAB_0044b042
    //                              fractal.cpp:124 (6)
    //         0044b03c     TEST       EDX,EDX
    //         0044b03e     JGE        LAB_0044b042
    //         0044b040     XOR        EDX,EDX
    //                               LAB_0044b042                                                 XREF[2]:     0044b03a(j), 0044b03e(j)  
    //                              fractal.cpp:126 (7)
    //         0044b042     LEA        EBX,[EAX + 0x4]
    //         0044b045     CMP        EBX,ESI
    //         0044b047     JG         LAB_0044b06d
    //                              fractal.cpp:127 (6)
    //         0044b049     TEST       EAX,EAX
    //         0044b04b     JGE        LAB_0044b06d
    //         0044b04d     XOR        EAX,EAX
    //                              fractal.cpp:130 (7)
    //         0044b04f     JMP        LAB_0044b06d
    //                               LAB_0044b051                                                 XREF[1]:     0044b033(j)  
    //         0044b051     CMP        this,0x3
    //         0044b054     JNZ        LAB_0044b06d
    //                              fractal.cpp:133 (7)
    //         0044b056     LEA        EBX,[EDX + 0x5]
    //         0044b059     CMP        EBX,EBP
    //         0044b05b     JG         LAB_0044b063
    //                              fractal.cpp:134 (6)
    //         0044b05d     TEST       EDX,EDX
    //         0044b05f     JGE        LAB_0044b063
    //         0044b061     XOR        EDX,EDX
    //                               LAB_0044b063                                                 XREF[2]:     0044b05b(j), 0044b05f(j)  
    //                              fractal.cpp:136 (10)
    //         0044b063     XOR        EBX,EBX
    //         0044b065     CMP        ESI,0x5
    //         0044b068     SETL       BL
    //         0044b06b     ADD        EAX,EBX
    //                               LAB_0044b06d                                                 XREF[4]:     0044b047(j), 0044b04b(j), 
    //                                                                                                         0044b04f(j), 0044b054(j)  
    //                              fractal.cpp:140 (5)
    //         0044b06d     CMP        this,0x4
    //         0044b070     JNZ        LAB_0044b0db
    //                              fractal.cpp:142 (10)
    //         0044b072     MOV        this,dword ptr [EDI + 0xfb0]
    //         0044b078     MOV        dword ptr [ESP + param_1],this
    //                              fractal.cpp:143 (15)
    //         0044b07c     LEA        this,[EDX + 0x6]
    //         0044b07f     CMP        this,EBP
    //         0044b081     JLE        LAB_0044b08d
    //         0044b083     MOV        EBX,EBP
    //         0044b085     SUB        EBX,EDX
    //         0044b087     MOV        dword ptr [ESP + param_2],EBX
    //                              fractal.cpp:144 (22)
    //         0044b08b     JMP        LAB_0044b0af
    //                               LAB_0044b08d                                                 XREF[1]:     0044b081(j)  
    //         0044b08d     TEST       EDX,EDX
    //         0044b08f     JGE        LAB_0044b0a3
    //         0044b091     MOV        EBX,dword ptr [ESP + param_1]
    //         0044b095     MOV        dword ptr [ESP + param_2],this
    //         0044b099     SUB        EBX,EDX
    //         0044b09b     XOR        EDX,EDX
    //         0044b09d     MOV        dword ptr [ESP + param_1],EBX
    //                              fractal.cpp:145 (14)
    //         0044b0a1     JMP        LAB_0044b0ab
    //                               LAB_0044b0a3                                                 XREF[1]:     0044b08f(j)  
    //         0044b0a3     MOV        dword ptr [ESP + param_2],0x6
    //                               LAB_0044b0ab                                                 XREF[1]:     0044b0a1(j)  
    //         0044b0ab     MOV        EBX,dword ptr [ESP + param_2]
    //                               LAB_0044b0af                                                 XREF[1]:     0044b08b(j)  
    //                              fractal.cpp:146 (9)
    //         0044b0af     LEA        this,[EAX + 0x6]
    //         0044b0b2     CMP        this,ESI
    //         0044b0b4     JLE        LAB_0044b0bd
    //         0044b0b6     SUB        ESI,EAX
    //                              fractal.cpp:147 (26)
    //         0044b0b8     JMP        LAB_0044b13f
    //                               LAB_0044b0bd                                                 XREF[1]:     0044b0b4(j)  
    //         0044b0bd     TEST       EAX,EAX
    //         0044b0bf     JGE        LAB_0044b0d4
    //         0044b0c1     IMUL       EAX,EBP
    //         0044b0c4     MOV        ESI,dword ptr [ESP + param_1]
    //         0044b0c8     SUB        ESI,EAX
    //         0044b0ca     XOR        EAX,EAX
    //         0044b0cc     MOV        dword ptr [ESP + param_1],ESI
    //         0044b0d0     MOV        ESI,this
    //                              fractal.cpp:148 (7)
    //         0044b0d2     JMP        LAB_0044b13f
    //                               LAB_0044b0d4                                                 XREF[1]:     0044b0bf(j)  
    //         0044b0d4     MOV        ESI,0x6
    //                              fractal.cpp:150 (2)
    //         0044b0d9     JMP        LAB_0044b13f
    //                               LAB_0044b0db                                                 XREF[1]:     0044b070(j)  
    //                              fractal.cpp:152 (10)
    //         0044b0db     MOV        this,dword ptr [EDI + 0xfb4]
    //         0044b0e1     MOV        dword ptr [ESP + param_1],this
    //                              fractal.cpp:153 (15)
    //         0044b0e5     LEA        this,[EDX + 0x7]
    //         0044b0e8     CMP        this,EBP
    //         0044b0ea     JLE        LAB_0044b0f6
    //         0044b0ec     MOV        this,EBP
    //         0044b0ee     SUB        this,EDX
    //         0044b0f0     MOV        dword ptr [ESP + param_2],this
    //                              fractal.cpp:154 (22)
    //         0044b0f4     JMP        LAB_0044b114
    //                               LAB_0044b0f6                                                 XREF[1]:     0044b0ea(j)  
    //         0044b0f6     TEST       EDX,EDX
    //         0044b0f8     JGE        LAB_0044b10c
    //         0044b0fa     MOV        EBX,dword ptr [ESP + param_1]
    //         0044b0fe     MOV        dword ptr [ESP + param_2],this
    //         0044b102     SUB        EBX,EDX
    //         0044b104     XOR        EDX,EDX
    //         0044b106     MOV        dword ptr [ESP + param_1],EBX
    //                              fractal.cpp:155 (10)
    //         0044b10a     JMP        LAB_0044b114
    //                               LAB_0044b10c                                                 XREF[1]:     0044b0f8(j)  
    //         0044b10c     MOV        dword ptr [ESP + param_2],0x7
    //                               LAB_0044b114                                                 XREF[2]:     0044b0f4(j), 0044b10a(j)  
    //                              fractal.cpp:156 (9)
    //         0044b114     LEA        this,[EAX + 0x7]
    //         0044b117     CMP        this,ESI
    //         0044b119     JLE        LAB_0044b11f
    //         0044b11b     SUB        ESI,EAX
    //                              fractal.cpp:157 (23)
    //         0044b11d     JMP        LAB_0044b13b
    //                               LAB_0044b11f                                                 XREF[1]:     0044b119(j)  
    //         0044b11f     TEST       EAX,EAX
    //         0044b121     JGE        LAB_0044b136
    //         0044b123     IMUL       EAX,EBP
    //         0044b126     MOV        ESI,dword ptr [ESP + param_1]
    //         0044b12a     SUB        ESI,EAX
    //         0044b12c     XOR        EAX,EAX
    //         0044b12e     MOV        dword ptr [ESP + param_1],ESI
    //         0044b132     MOV        ESI,this
    //                              fractal.cpp:158 (11)
    //         0044b134     JMP        LAB_0044b13b
    //                               LAB_0044b136                                                 XREF[1]:     0044b121(j)  
    //         0044b136     MOV        ESI,0x7
    //                               LAB_0044b13b                                                 XREF[2]:     0044b11d(j), 0044b134(j)  
    //         0044b13b     MOV        EBX,dword ptr [ESP + param_2]
    //                               LAB_0044b13f                                                 XREF[3]:     0044b0b8(j), 0044b0d2(j), 
    //                                                                                                         0044b0d9(j)  
    //                              fractal.cpp:160 (5)
    //         0044b13f     IMUL       EAX,EBP
    //         0044b142     ADD        EAX,EDX
    //                              fractal.cpp:166 (20)
    //         0044b144     MOV        EDX,ESI
    //         0044b146     DEC        ESI
    //         0044b147     MOV        dword ptr [ESP + local_10],EAX
    //         0044b14b     TEST       EDX,EDX
    //         0044b14d     JZ         LAB_0044b1fc
    //         0044b153     INC        ESI
    //         0044b154     MOV        dword ptr [ESP + local_c],ESI
    //                               LAB_0044b158                                                 XREF[1]:     0044b1f6(j)  
    //                              fractal.cpp:168 (26)
    //         0044b158     TEST       EBX,EBX
    //         0044b15a     JLE        LAB_0044b1d3
    //         0044b15c     MOV        this,dword ptr [ESP + param_1]
    //         0044b160     MOV        ESI,EAX
    //         0044b162     SUB        this,EAX
    //         0044b164     MOV        dword ptr [ESP + param_3],EBX
    //         0044b168     MOV        dword ptr [ESP + len],this
    //         0044b16c     JMP        LAB_0044b172
    //                               LAB_0044b16e                                                 XREF[1]:     0044b1c9(j)  
    //         0044b16e     MOV        this,dword ptr [ESP + len]
    //                               LAB_0044b172                                                 XREF[1]:     0044b16c(j)  
    //                              fractal.cpp:169 (77)
    //         0044b172     MOVSX      EBX,byte ptr [this->Prime.x + ESI*0x1]
    //         0044b176     CMP        ESI,0x1
    //         0044b179     JL         LAB_0044b1bf
    //         0044b17b     MOV        EAX,dword ptr [EDI + 0x1004]
    //         0044b181     DEC        EAX
    //         0044b182     CMP        ESI,EAX
    //         0044b184     JGE        LAB_0044b1bf
    //         0044b186     MOV        this,dword ptr [EDI + 0x1024]
    //         0044b18c     MOV        DL,byte ptr [this->Prime.x + ESI*0x1]
    //         0044b18f     LEA        EAX,[this->Prime.x + ESI*0x1]
    //         0044b192     TEST       DL,DL
    //         0044b194     JNZ        LAB_0044b1a7
    //         0044b196     MOV        byte ptr [EAX],BL
    //         0044b198     MOV        EAX,dword ptr [EDI + 0xfec]
    //         0044b19e     INC        EAX
    //         0044b19f     MOV        dword ptr [EDI + 0xfec],EAX
    //         0044b1a5     JMP        LAB_0044b1bf
    //                               LAB_0044b1a7                                                 XREF[1]:     0044b194(j)  
    //         0044b1a7     MOVSX      this,DL
    //         0044b1aa     MOV        EBP,EBX
    //         0044b1ac     ADD        EBP,this
    //         0044b1ae     CMP        EBP,0xff
    //         0044b1b4     JGE        LAB_0044b1bc
    //         0044b1b6     ADD        BL,DL
    //         0044b1b8     MOV        byte ptr [EAX],BL
    //         0044b1ba     JMP        LAB_0044b1bf
    //                               LAB_0044b1bc                                                 XREF[1]:     0044b1b4(j)  
    //         0044b1bc     MOV        byte ptr [EAX],0xff
    //                               LAB_0044b1bf                                                 XREF[4]:     0044b179(j), 0044b184(j), 
    //                                                                                                         0044b1a5(j), 0044b1ba(j)  
    //                              fractal.cpp:168 (20)
    //         0044b1bf     MOV        EAX,dword ptr [ESP + param_3]
    //         0044b1c3     INC        ESI
    //         0044b1c4     DEC        EAX
    //         0044b1c5     MOV        dword ptr [ESP + param_3],EAX
    //         0044b1c9     JNZ        LAB_0044b16e
    //         0044b1cb     MOV        EBX,dword ptr [ESP + param_2]
    //         0044b1cf     MOV        EAX,dword ptr [ESP + local_10]
    //                               LAB_0044b1d3                                                 XREF[1]:     0044b15a(j)  
    //                              fractal.cpp:170 (41)
    //         0044b1d3     MOV        EDX,dword ptr [ESP + local_4]
    //         0044b1d7     MOV        ESI,dword ptr [ESP + param_1]
    //         0044b1db     MOV        this,dword ptr [ESP + local_c]
    //         0044b1df     ADD        ESI,EDX
    //         0044b1e1     MOV        EDX,dword ptr [EDI + 0xfd4]
    //         0044b1e7     MOV        dword ptr [ESP + param_1],ESI
    //         0044b1eb     ADD        EAX,EDX
    //         0044b1ed     DEC        this
    //         0044b1ee     MOV        dword ptr [ESP + local_10],EAX
    //         0044b1f2     MOV        dword ptr [ESP + local_c],this
    //         0044b1f6     JNZ        LAB_0044b158
    //                               LAB_0044b1fc                                                 XREF[5]:     0044aff5(j), 0044b007(j), 
    //                                                                                                         0044b017(j), 0044b023(j), 
    //                                                                                                         0044b14d(j)  
    //                              fractal.cpp:172 (10)
    //         0044b1fc     POP        EDI
    //         0044b1fd     POP        ESI
    //         0044b1fe     POP        EBP
    //         0044b1ff     POP        EBX
    //         0044b200     ADD        ESP,0x10
    //         0044b203     RET        0xc
    //         0044b206     ??         90h
    //         0044b207     NOP
    //         0044b208     NOP
    //         0044b209     NOP
    //         0044b20a     NOP
    //         0044b20b     NOP
    //         0044b20c     NOP
    //         0044b20d     NOP
    //         0044b20e     NOP
    //         0044b20f     NOP
    return;
}

void PointMaker::ClearArrays() {
    /* TODO: Stub */
    //                              void __thiscall ClearArrays(PointMaker * this)
    //              void              <VOID>         <RETURN>
    //              PointMaker *      ECX:4 (auto)   this
    //                               ?ClearArrays@PointMaker@@QAEXXZ                              XREF[2]:     CreateShape:0044b32e(c), 
    //                               PointMaker::ClearArrays                                                   CreateShape:0044b47e(c)  
    //                              fractal.cpp:176 (4)
    //         0044b210     MOV        EDX,this
    //         0044b212     PUSH       ESI
    //         0044b213     PUSH       EDI
    //                              fractal.cpp:177 (20)
    //         0044b214     MOV        EAX,dword ptr [EDX + 0x103c]
    //         0044b21a     TEST       EAX,EAX
    //         0044b21c     JNZ        LAB_0044b23e
    //         0044b21e     MOV        EDI,dword ptr [EDX + 0x1028]
    //         0044b224     TEST       EDI,EDI
    //         0044b226     JZ         LAB_0044b23e
    //                              fractal.cpp:178 (22)
    //         0044b228     MOV        this,dword ptr [EDX + 0x1004]
    //         0044b22e     XOR        EAX,EAX
    //         0044b230     MOV        ESI,this
    //         0044b232     SHR        this,0x2
    //         0044b235     STOSD.REP  ES:EDI
    //         0044b237     MOV        this,ESI
    //         0044b239     AND        this,0x3
    //         0044b23c     STOSB.REP  ES:EDI
    //                               LAB_0044b23e                                                 XREF[2]:     0044b21c(j), 0044b226(j)  
    //                              fractal.cpp:180 (32)
    //         0044b23e     MOV        EDI,dword ptr [EDX + 0x1024]
    //         0044b244     TEST       EDI,EDI
    //         0044b246     JZ         LAB_0044b25e
    //         0044b248     MOV        this,dword ptr [EDX + 0x1004]
    //         0044b24e     XOR        EAX,EAX
    //         0044b250     MOV        EDX,this
    //         0044b252     SHR        this,0x2
    //         0044b255     STOSD.REP  ES:EDI
    //         0044b257     MOV        this,EDX
    //         0044b259     AND        this,0x3
    //         0044b25c     STOSB.REP  ES:EDI
    //                               LAB_0044b25e                                                 XREF[1]:     0044b246(j)  
    //                              fractal.cpp:182 (3)
    //         0044b25e     POP        EDI
    //         0044b25f     POP        ESI
    //         0044b260     RET
    //         0044b261     ??         90h
    //         0044b262     NOP
    //         0044b263     NOP
    //         0044b264     NOP
    //         0044b265     NOP
    //         0044b266     NOP
    //         0044b267     NOP
    //         0044b268     NOP
    //         0044b269     NOP
    //         0044b26a     NOP
    //         0044b26b     NOP
    //         0044b26c     NOP
    //         0044b26d     NOP
    //         0044b26e     NOP
    //         0044b26f     NOP
    return;
}

void PointMaker::DeleteArrays() {
    /* TODO: Stub */
    //                              void __thiscall DeleteArrays(PointMaker * this)
    //              void              <VOID>         <RETURN>
    //              PointMaker *      ECX:4 (auto)   this
    //                               ?DeleteArrays@PointMaker@@QAEXXZ                             XREF[1]:     ~PointMaker:0044ac83(c)  
    //                               PointMaker::DeleteArrays
    //                              fractal.cpp:185 (3)
    //         0044b270     PUSH       ESI
    //         0044b271     MOV        ESI,this
    //                              fractal.cpp:186 (10)
    //         0044b273     MOV        EAX,dword ptr [ESI + 0x1024]
    //         0044b279     TEST       EAX,EAX
    //         0044b27b     JZ         LAB_0044b286
    //                              fractal.cpp:187 (9)
    //         0044b27d     PUSH       EAX
    //         0044b27e     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0044b283     ADD        ESP,0x4
    //                               LAB_0044b286                                                 XREF[1]:     0044b27b(j)  
    //                              fractal.cpp:188 (10)
    //         0044b286     MOV        EAX,dword ptr [ESI + 0x1028]
    //         0044b28c     TEST       EAX,EAX
    //         0044b28e     JZ         LAB_0044b299
    //                              fractal.cpp:189 (9)
    //         0044b290     PUSH       EAX
    //         0044b291     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0044b296     ADD        ESP,0x4
    //                               LAB_0044b299                                                 XREF[1]:     0044b28e(j)  
    //                              fractal.cpp:190 (20)
    //         0044b299     MOV        dword ptr [ESI + 0x1024],0x0
    //         0044b2a3     MOV        dword ptr [ESI + 0x1028],0x0
    //                              fractal.cpp:191 (2)
    //         0044b2ad     POP        ESI
    //         0044b2ae     RET
    //         0044b2af     ??         90h
    return;
}

void PointMaker::MakeArrays() {
    /* TODO: Stub */
    //                              void __thiscall MakeArrays(PointMaker * this)
    //              void              <VOID>         <RETURN>
    //              PointMaker *      ECX:4 (auto)   this
    //                               ?MakeArrays@PointMaker@@QAEXXZ                               XREF[1]:     PointMaker:0044ac68(c)  
    //                               PointMaker::MakeArrays
    //                              fractal.cpp:194 (4)
    //         0044b2b0     PUSH       ESI
    //         0044b2b1     MOV        ESI,this
    //         0044b2b3     PUSH       EDI
    //                              fractal.cpp:197 (34)
    //         0044b2b4     MOV        EDI,0x9
    //         0044b2b9     MOV        EAX,dword ptr [ESI + 0xfd8]
    //         0044b2bf     IMUL       EAX,dword ptr [ESI + 0xfd4]
    //         0044b2c6     MOV        dword ptr [ESI + 0x1004],EAX
    //                               LAB_0044b2cc                                                 XREF[1]:     0044b2f0(j)  
    //         0044b2cc     MOV        EAX,dword ptr [ESI + 0x1024]
    //         0044b2d2     TEST       EAX,EAX
    //         0044b2d4     JNZ        LAB_0044b2f2
    //                              fractal.cpp:199 (28)
    //         0044b2d6     MOV        this,dword ptr [ESI + 0x1004]
    //         0044b2dc     PUSH       this
    //         0044b2dd     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0044b2e2     ADD        ESP,0x4
    //         0044b2e5     MOV        EDX,EDI
    //         0044b2e7     DEC        EDI
    //         0044b2e8     MOV        dword ptr [ESI + 0x1024],EAX
    //         0044b2ee     TEST       EDX,EDX
    //         0044b2f0     JNZ        LAB_0044b2cc
    //                               LAB_0044b2f2                                                 XREF[1]:     0044b2d4(j)  
    //                              fractal.cpp:202 (15)
    //         0044b2f2     MOV        EDI,0x9
    //                               LAB_0044b2f7                                                 XREF[1]:     0044b31b(j)  
    //         0044b2f7     MOV        EAX,dword ptr [ESI + 0x1028]
    //         0044b2fd     TEST       EAX,EAX
    //         0044b2ff     JNZ        LAB_0044b31d
    //                              fractal.cpp:204 (28)
    //         0044b301     MOV        EAX,dword ptr [ESI + 0x1004]
    //         0044b307     PUSH       EAX
    //         0044b308     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0044b30d     ADD        ESP,0x4
    //         0044b310     MOV        this,EDI
    //         0044b312     DEC        EDI
    //         0044b313     MOV        dword ptr [ESI + 0x1028],EAX
    //         0044b319     TEST       this,this
    //         0044b31b     JNZ        LAB_0044b2f7
    //                               LAB_0044b31d                                                 XREF[1]:     0044b2ff(j)  
    //                              fractal.cpp:206 (3)
    //         0044b31d     POP        EDI
    //         0044b31e     POP        ESI
    //         0044b31f     RET
    return;
}

int PointMaker::CreateShape() {
    /* TODO: Stub */
    //                              int __thiscall CreateShape(PointMaker * this)
    //              int               EAX:4          <RETURN>
    //              PointMaker *      ECX:4 (auto)   this
    //                               ?CreateShape@PointMaker@@QAEHXZ
    //                               PointMaker::CreateShape
    //                              fractal.cpp:209 (5)
    //         0044b320     PUSH       EBX
    //         0044b321     PUSH       EBP
    //         0044b322     PUSH       ESI
    //         0044b323     MOV        ESI,this
    //                              fractal.cpp:210 (9)
    //         0044b325     XOR        EBX,EBX
    //         0044b327     PUSH       EDI
    //         0044b328     MOV        dword ptr [ESI + 0xfe0],EBX
    //                              fractal.cpp:211 (5)
    //         0044b32e     CALL       PointMaker::ClearArrays                          void ClearArrays(PointMaker * this)
    //                              fractal.cpp:212 (7)
    //         0044b333     MOV        this,ESI
    //         0044b335     CALL       PointMaker::PrepareLimits                        void PrepareLimits(PointMaker * this)
    //                              fractal.cpp:215 (49)
    //         0044b33a     MOV        EDI,dword ptr [ESI + 0x1044]
    //         0044b340     PUSH       0xd7
    //         0044b345     PUSH       s_C:\msdev\work\age1_x1\fractal.cp               = "C:\\msdev\\work\\age1_x1\\fractal.cpp"
    //         0044b34a     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         0044b34f     MOV        this,dword ptr [ESI + 0xfd4]
    //         0044b355     MOV        EBP,EAX
    //         0044b357     MOV        EAX,0x32
    //         0044b35c     ADD        ESP,0x8
    //         0044b35f     SUB        EAX,EDI
    //         0044b361     IMUL       this,EAX
    //         0044b364     SHL        this,0x1
    //         0044b366     MOV        EAX,0x51eb851f
    //                              fractal.cpp:216 (66)
    //         0044b36b     PUSH       0xd8
    //         0044b370     IMUL       this
    //         0044b372     MOV        this,EDX
    //         0044b374     MOV        EAX,EBP
    //         0044b376     SAR        this,0x5
    //         0044b379     MOV        EDX,this
    //         0044b37b     PUSH       s_C:\msdev\work\age1_x1\fractal.cp               = "C:\\msdev\\work\\age1_x1\\fractal.cpp"
    //         0044b380     SHR        EDX,0x1f
    //         0044b383     ADD        this,EDX
    //         0044b385     CDQ
    //         0044b386     IDIV       this
    //         0044b388     ADD        EDX,EDI
    //         0044b38a     MOV        EDI,dword ptr [ESI + 0x104c]
    //         0044b390     MOV        dword ptr [ESI + 0xfb8],EDX
    //         0044b396     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         0044b39b     MOV        this,dword ptr [ESI + 0xfd8]
    //         0044b3a1     MOV        EBP,EAX
    //         0044b3a3     MOV        EAX,0x32
    //         0044b3a8     ADD        ESP,0x8
    //         0044b3ab     SUB        EAX,EDI
    //                              fractal.cpp:219 (49)
    //         0044b3ad     MOV        dword ptr [ESI + 0xfec],EBX
    //         0044b3b3     IMUL       this,EAX
    //         0044b3b6     SHL        this,0x1
    //         0044b3b8     MOV        EAX,0x51eb851f
    //         0044b3bd     MOV        dword ptr [ESI + 0xfe0],EBX
    //         0044b3c3     IMUL       this
    //         0044b3c5     MOV        this,EDX
    //         0044b3c7     MOV        EAX,EBP
    //         0044b3c9     SAR        this,0x5
    //         0044b3cc     MOV        EDX,this
    //         0044b3ce     SHR        EDX,0x1f
    //         0044b3d1     ADD        this,EDX
    //         0044b3d3     CDQ
    //         0044b3d4     IDIV       this
    //         0044b3d6     MOV        this,dword ptr [ESI + 0xfb8]
    //         0044b3dc     MOV        dword ptr [ESI],this
    //                              fractal.cpp:220 (19)
    //         0044b3de     MOV        this,ESI
    //         0044b3e0     LEA        EAX,[EDX + EDI*0x1]
    //         0044b3e3     MOV        dword ptr [ESI + 0xfbc],EAX
    //         0044b3e9     MOV        dword ptr [ESI + 0x4],EAX
    //         0044b3ec     CALL       PointMaker::DrawPrimaryIntoProbabilityArray      void DrawPrimaryIntoProbabilityArray(PointMak
    //                              fractal.cpp:222 (7)
    //         0044b3f1     MOV        this,ESI
    //         0044b3f3     CALL       PointMaker::ErrorCheckingAndCorrection           void ErrorCheckingAndCorrection(PointMaker * 
    //                              fractal.cpp:224 (6)
    //         0044b3f8     MOV        EDI,dword ptr [ESI + 0xfdc]
    //                              fractal.cpp:226 (29)
    //         0044b3fe     MOV        EAX,dword ptr [ESI + 0xfec]
    //         0044b404     XOR        EBP,EBP
    //         0044b406     CMP        EAX,EDI
    //         0044b408     MOV        dword ptr [ESI + 0xfe4],EBX
    //         0044b40e     JGE        LAB_0044b455
    //                               LAB_0044b410                                                 XREF[1]:     0044b453(j)  
    //         0044b410     MOV        EDX,EBP
    //         0044b412     INC        EBP
    //         0044b413     CMP        EDX,0x5dc
    //         0044b419     JGE        LAB_0044b455
    //                              fractal.cpp:228 (5)
    //         0044b41b     MOV        this,dword ptr [ESI + 0x4]
    //         0044b41e     MOV        EAX,dword ptr [ESI]
    //                              fractal.cpp:229 (12)
    //         0044b420     MOV        EDX,dword ptr [ESI + 0x1018]
    //         0044b426     MOV        dword ptr [ESI + 0xfbc],this
    //                              fractal.cpp:232 (25)
    //         0044b42c     MOV        this,ESI
    //         0044b42e     MOV        dword ptr [ESI + 0xfb8],EAX
    //         0044b434     MOV        dword ptr [ESI + 0x101c],EDX
    //         0044b43a     MOV        dword ptr [ESI + 0xfe0],EBX
    //         0044b440     CALL       PointMaker::MakeFirstLink                        int MakeFirstLink(PointMaker * this)
    //                              fractal.cpp:233 (16)
    //         0044b445     PUSH       EAX
    //         0044b446     MOV        this,ESI
    //         0044b448     CALL       PointMaker::Branch                               void Branch(PointMaker * this, int param_1)
    //         0044b44d     CMP        dword ptr [ESI + 0xfec],EDI
    //         0044b453     JL         LAB_0044b410
    //                               LAB_0044b455                                                 XREF[2]:     0044b40e(j), 0044b419(j)  
    //                              fractal.cpp:235 (7)
    //         0044b455     MOV        this,ESI
    //         0044b457     CALL       PointMaker::CreateMapBasedOnProbabilityArray     void CreateMapBasedOnProbabilityArray(PointMa
    //                              fractal.cpp:236 (7)
    //         0044b45c     MOV        this,ESI
    //         0044b45e     CALL       PointMaker::MapCleanUpEliminatingSinglesOnly     void MapCleanUpEliminatingSinglesOnly(PointMa
    //                              fractal.cpp:237 (6)
    //         0044b463     MOV        EAX,dword ptr [ESI + 0xfec]
    //                              fractal.cpp:238 (5)
    //         0044b469     POP        EDI
    //         0044b46a     POP        ESI
    //         0044b46b     POP        EBP
    //         0044b46c     POP        EBX
    //         0044b46d     RET
    //         0044b46e     ??         90h
    //         0044b46f     NOP
    return 0;
}

int PointMaker::CreateShape(int param_1, int param_2) {
    /* TODO: Stub */
    //                              int __thiscall CreateShape(PointMaker * this, int param_1, int param
    //              int               EAX:4          <RETURN>
    //              PointMaker *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0044b48e(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0044b48a(R)  
    //                               ?CreateShape@PointMaker@@QAEHHH@Z
    //                               PointMaker::CreateShape
    //                              fractal.cpp:241 (5)
    //         0044b470     PUSH       EBX
    //         0044b471     PUSH       EBP
    //         0044b472     PUSH       ESI
    //         0044b473     MOV        ESI,this
    //                              fractal.cpp:243 (9)
    //         0044b475     XOR        EBX,EBX
    //         0044b477     PUSH       EDI
    //         0044b478     MOV        dword ptr [ESI + 0xfe0],EBX
    //                              fractal.cpp:244 (5)
    //         0044b47e     CALL       PointMaker::ClearArrays                          void ClearArrays(PointMaker * this)
    //                              fractal.cpp:245 (7)
    //         0044b483     MOV        this,ESI
    //         0044b485     CALL       PointMaker::PrepareLimits                        void PrepareLimits(PointMaker * this)
    //                              fractal.cpp:248 (14)
    //         0044b48a     MOV        this,dword ptr [ESP + param_2]
    //         0044b48e     MOV        EAX,dword ptr [ESP + param_1]
    //         0044b492     MOV        dword ptr [ESI + 0xfbc],this
    //                              fractal.cpp:249 (3)
    //         0044b498     MOV        dword ptr [ESI + 0x4],this
    //                              fractal.cpp:250 (27)
    //         0044b49b     MOV        this,ESI
    //         0044b49d     MOV        dword ptr [ESI + 0xfec],EBX
    //         0044b4a3     MOV        dword ptr [ESI + 0xfe0],EBX
    //         0044b4a9     MOV        dword ptr [ESI + 0xfb8],EAX
    //         0044b4af     MOV        dword ptr [ESI],EAX
    //         0044b4b1     CALL       PointMaker::DrawPrimaryIntoProbabilityArray      void DrawPrimaryIntoProbabilityArray(PointMak
    //                              fractal.cpp:252 (7)
    //         0044b4b6     MOV        this,ESI
    //         0044b4b8     CALL       PointMaker::ErrorCheckingAndCorrection           void ErrorCheckingAndCorrection(PointMaker * 
    //                              fractal.cpp:253 (6)
    //         0044b4bd     MOV        EDI,dword ptr [ESI + 0xfdc]
    //                              fractal.cpp:256 (28)
    //         0044b4c3     MOV        EAX,dword ptr [ESI + 0xfec]
    //         0044b4c9     XOR        EBP,EBP
    //         0044b4cb     CMP        EAX,EDI
    //         0044b4cd     MOV        dword ptr [ESI + 0xfe4],EBX
    //         0044b4d3     JGE        LAB_0044b519
    //                               LAB_0044b4d5                                                 XREF[1]:     0044b517(j)  
    //         0044b4d5     MOV        EAX,EBP
    //         0044b4d7     INC        EBP
    //         0044b4d8     CMP        EAX,0x5dc
    //         0044b4dd     JGE        LAB_0044b519
    //                              fractal.cpp:258 (5)
    //         0044b4df     MOV        this,dword ptr [ESI]
    //         0044b4e1     MOV        EDX,dword ptr [ESI + 0x4]
    //                              fractal.cpp:259 (12)
    //         0044b4e4     MOV        EAX,dword ptr [ESI + 0x1018]
    //         0044b4ea     MOV        dword ptr [ESI + 0xfb8],this
    //                              fractal.cpp:262 (25)
    //         0044b4f0     MOV        this,ESI
    //         0044b4f2     MOV        dword ptr [ESI + 0xfbc],EDX
    //         0044b4f8     MOV        dword ptr [ESI + 0x101c],EAX
    //         0044b4fe     MOV        dword ptr [ESI + 0xfe0],EBX
    //         0044b504     CALL       PointMaker::MakeFirstLink                        int MakeFirstLink(PointMaker * this)
    //                              fractal.cpp:263 (16)
    //         0044b509     PUSH       EAX
    //         0044b50a     MOV        this,ESI
    //         0044b50c     CALL       PointMaker::Branch                               void Branch(PointMaker * this, int param_1)
    //         0044b511     CMP        dword ptr [ESI + 0xfec],EDI
    //         0044b517     JL         LAB_0044b4d5
    //                               LAB_0044b519                                                 XREF[2]:     0044b4d3(j), 0044b4dd(j)  
    //                              fractal.cpp:266 (7)
    //         0044b519     MOV        this,ESI
    //         0044b51b     CALL       PointMaker::CreateMapBasedOnProbabilityArray     void CreateMapBasedOnProbabilityArray(PointMa
    //                              fractal.cpp:267 (7)
    //         0044b520     MOV        this,ESI
    //         0044b522     CALL       PointMaker::MapCleanUpEliminatingSinglesOnly     void MapCleanUpEliminatingSinglesOnly(PointMa
    //                              fractal.cpp:268 (6)
    //         0044b527     MOV        EAX,dword ptr [ESI + 0xfec]
    //                              fractal.cpp:269 (7)
    //         0044b52d     POP        EDI
    //         0044b52e     POP        ESI
    //         0044b52f     POP        EBP
    //         0044b530     POP        EBX
    //         0044b531     RET        0x8
    //         0044b534     ??         90h
    //         0044b535     NOP
    //         0044b536     NOP
    //         0044b537     NOP
    //         0044b538     NOP
    //         0044b539     NOP
    //         0044b53a     NOP
    //         0044b53b     NOP
    //         0044b53c     NOP
    //         0044b53d     NOP
    //         0044b53e     NOP
    //         0044b53f     NOP
    return 0;
}

void PointMaker::Branch(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall Branch(PointMaker * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              PointMaker *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0044b5a7(R)  
    //                               ?Branch@PointMaker@@IAEXH@Z                                  XREF[3]:     CreateShape:0044b448(c), 
    //                               PointMaker::Branch                                                        CreateShape:0044b50c(c), 
    //                                                                                                         0044b5d3(c)  
    //                              fractal.cpp:276 (6)
    //         0044b540     PUSH       EBX
    //         0044b541     PUSH       EBP
    //         0044b542     PUSH       ESI
    //         0044b543     MOV        ESI,this
    //         0044b545     PUSH       EDI
    //                              fractal.cpp:279 (72)
    //         0044b546     CMP        dword ptr [ESI + 0x101c],0x1
    //         0044b54d     JLE        LAB_0044b5e3
    //         0044b553     PUSH       0x116
    //         0044b558     PUSH       s_C:\msdev\work\age1_x1\fractal.cp               = "C:\\msdev\\work\\age1_x1\\fractal.cpp"
    //         0044b55d     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         0044b562     CDQ
    //         0044b563     MOV        this,0x64
    //         0044b568     ADD        ESP,0x8
    //         0044b56b     IDIV       this
    //         0044b56d     MOV        EAX,dword ptr [ESI + 0xfc8]
    //         0044b573     LEA        EAX,[EAX + EAX*0x4]
    //         0044b576     SHL        EAX,0x1
    //         0044b578     CMP        EDX,EAX
    //         0044b57a     JGE        LAB_0044b5e3
    //         0044b57c     MOV        this,dword ptr [ESI + 0xfdc]
    //         0044b582     MOV        EAX,dword ptr [ESI + 0xfec]
    //         0044b588     SHL        this,0x1
    //         0044b58a     CMP        EAX,this
    //         0044b58c     JGE        LAB_0044b5e3
    //                              fractal.cpp:281 (6)
    //         0044b58e     MOV        this,dword ptr [ESI + 0x101c]
    //                              fractal.cpp:282 (19)
    //         0044b594     MOV        EAX,dword ptr [ESI + 0xfc0]
    //         0044b59a     DEC        this
    //         0044b59b     XOR        EBX,EBX
    //         0044b59d     TEST       EAX,EAX
    //         0044b59f     MOV        dword ptr [ESI + 0x101c],this
    //         0044b5a5     JLE        LAB_0044b5e3
    //                              fractal.cpp:285 (8)
    //         0044b5a7     MOV        EBP,dword ptr [ESP + param_1]
    //                               LAB_0044b5ab                                                 XREF[1]:     0044b5e1(j)  
    //         0044b5ab     MOV        EDX,dword ptr [ESI + EBP*0x8 + 0x8]
    //                              fractal.cpp:286 (25)
    //         0044b5af     MOV        this,ESI
    //         0044b5b1     MOV        dword ptr [ESI + 0xfb8],EDX
    //         0044b5b7     MOV        EAX,dword ptr [ESI + EBP*0x8 + 0xc]
    //         0044b5bb     MOV        dword ptr [ESI + 0xfbc],EAX
    //         0044b5c1     CALL       PointMaker::MakeNewLink                          int MakeNewLink(PointMaker * this)
    //         0044b5c6     MOV        EDI,EAX
    //                              fractal.cpp:287 (8)
    //         0044b5c8     MOV        this,ESI
    //         0044b5ca     PUSH       EDI
    //         0044b5cb     CALL       PointMaker::DrawCurrentBranchIntoProbArray       void DrawCurrentBranchIntoProbArray(PointMake
    //                              fractal.cpp:288 (19)
    //         0044b5d0     PUSH       EDI
    //         0044b5d1     MOV        this,ESI
    //         0044b5d3     CALL       PointMaker::Branch                               void Branch(PointMaker * this, int param_1)
    //         0044b5d8     MOV        EAX,dword ptr [ESI + 0xfc0]
    //         0044b5de     INC        EBX
    //         0044b5df     CMP        EBX,EAX
    //         0044b5e1     JL         LAB_0044b5ab
    //                               LAB_0044b5e3                                                 XREF[4]:     0044b54d(j), 0044b57a(j), 
    //                                                                                                         0044b58c(j), 0044b5a5(j)  
    //                              fractal.cpp:292 (12)
    //         0044b5e3     MOV        EAX,dword ptr [ESI + 0xfc4]
    //         0044b5e9     XOR        EDI,EDI
    //         0044b5eb     TEST       EAX,EAX
    //         0044b5ed     JLE        LAB_0044b609
    //                               LAB_0044b5ef                                                 XREF[1]:     0044b607(j)  
    //                              fractal.cpp:294 (7)
    //         0044b5ef     MOV        this,ESI
    //         0044b5f1     CALL       PointMaker::MakeSatelliteLink                    int MakeSatelliteLink(PointMaker * this)
    //                              fractal.cpp:295 (19)
    //         0044b5f6     PUSH       EAX
    //         0044b5f7     MOV        this,ESI
    //         0044b5f9     CALL       PointMaker::DrawCurrentSatelliteIntoProbArray    void DrawCurrentSatelliteIntoProbArray(PointM
    //         0044b5fe     MOV        EAX,dword ptr [ESI + 0xfc4]
    //         0044b604     INC        EDI
    //         0044b605     CMP        EDI,EAX
    //         0044b607     JL         LAB_0044b5ef
    //                               LAB_0044b609                                                 XREF[1]:     0044b5ed(j)  
    //                              fractal.cpp:298 (7)
    //         0044b609     POP        EDI
    //         0044b60a     POP        ESI
    //         0044b60b     POP        EBP
    //         0044b60c     POP        EBX
    //         0044b60d     RET        0x4
    return;
}

int PointMaker::MakeFirstLink() {
    /* TODO: Stub */
    //                              int __thiscall MakeFirstLink(PointMaker * this)
    //              int               EAX:4          <RETURN>
    //              PointMaker *      ECX:4 (auto)   this
    //                               ?MakeFirstLink@PointMaker@@IAEHXZ                            XREF[2]:     CreateShape:0044b440(c), 
    //                               PointMaker::MakeFirstLink                                                 CreateShape:0044b504(c)  
    //                              fractal.cpp:306 (3)
    //         0044b610     PUSH       EBX
    //         0044b611     PUSH       ESI
    //         0044b612     PUSH       EDI
    //                              fractal.cpp:308 (66)
    //         0044b613     PUSH       0x134
    //         0044b618     MOV        ESI,this
    //         0044b61a     PUSH       s_C:\msdev\work\age1_x1\fractal.cp               = "C:\\msdev\\work\\age1_x1\\fractal.cpp"
    //         0044b61f     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         0044b624     CDQ
    //         0044b625     IDIV       dword ptr [ESI + 0x100c]
    //         0044b62b     ADD        ESP,0x8
    //         0044b62e     PUSH       0x134
    //         0044b633     PUSH       s_C:\msdev\work\age1_x1\fractal.cp               = "C:\\msdev\\work\\age1_x1\\fractal.cpp"
    //         0044b638     MOV        EDI,EDX
    //         0044b63a     ADD        EDI,0x2
    //         0044b63d     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         0044b642     CDQ
    //         0044b643     XOR        EAX,EDX
    //         0044b645     ADD        ESP,0x8
    //         0044b648     SUB        EAX,EDX
    //         0044b64a     AND        EAX,0x1
    //         0044b64d     XOR        EAX,EDX
    //         0044b64f     SUB        EAX,EDX
    //         0044b651     JZ         LAB_0044b655
    //         0044b653     NEG        EDI
    //                               LAB_0044b655                                                 XREF[1]:     0044b651(j)  
    //                              fractal.cpp:309 (64)
    //         0044b655     PUSH       0x135
    //         0044b65a     PUSH       s_C:\msdev\work\age1_x1\fractal.cp               = "C:\\msdev\\work\\age1_x1\\fractal.cpp"
    //         0044b65f     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         0044b664     CDQ
    //         0044b665     IDIV       dword ptr [ESI + 0x100c]
    //         0044b66b     ADD        ESP,0x8
    //         0044b66e     PUSH       0x135
    //         0044b673     PUSH       s_C:\msdev\work\age1_x1\fractal.cp               = "C:\\msdev\\work\\age1_x1\\fractal.cpp"
    //         0044b678     MOV        EBX,EDX
    //         0044b67a     ADD        EBX,0x2
    //         0044b67d     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         0044b682     CDQ
    //         0044b683     XOR        EAX,EDX
    //         0044b685     ADD        ESP,0x8
    //         0044b688     SUB        EAX,EDX
    //         0044b68a     AND        EAX,0x1
    //         0044b68d     XOR        EAX,EDX
    //         0044b68f     SUB        EAX,EDX
    //         0044b691     JZ         LAB_0044b695
    //         0044b693     NEG        EBX
    //                               LAB_0044b695                                                 XREF[1]:     0044b691(j)  
    //                              fractal.cpp:311 (6)
    //         0044b695     MOV        this,dword ptr [ESI + 0xfb8]
    //                              fractal.cpp:312 (8)
    //         0044b69b     MOV        EDX,dword ptr [ESI + 0xfbc]
    //         0044b6a1     MOV        EAX,EDI
    //                              fractal.cpp:313 (12)
    //         0044b6a3     MOV        dword ptr [ESI + 0x1010],EDI
    //         0044b6a9     ADD        EAX,this
    //         0044b6ab     MOV        this,EBX
    //         0044b6ad     ADD        this,EDX
    //                              fractal.cpp:316 (30)
    //         0044b6af     MOV        EDX,dword ptr [ESI + 0x1044]
    //         0044b6b5     CMP        EAX,EDX
    //         0044b6b7     MOV        dword ptr [ESI + 0x1014],EBX
    //         0044b6bd     JGE        LAB_0044b6cd
    //         0044b6bf     TEST       EDI,EDI
    //         0044b6c1     MOV        EAX,EDX
    //         0044b6c3     JGE        LAB_0044b6cd
    //         0044b6c5     NEG        EDI
    //         0044b6c7     MOV        dword ptr [ESI + 0x1010],EDI
    //                               LAB_0044b6cd                                                 XREF[2]:     0044b6bd(j), 0044b6c3(j)  
    //                              fractal.cpp:317 (24)
    //         0044b6cd     MOV        EDX,dword ptr [ESI + 0x104c]
    //         0044b6d3     CMP        this,EDX
    //         0044b6d5     JGE        LAB_0044b6e5
    //         0044b6d7     TEST       EBX,EBX
    //         0044b6d9     MOV        this,EDX
    //         0044b6db     JGE        LAB_0044b6e5
    //         0044b6dd     NEG        EBX
    //         0044b6df     MOV        dword ptr [ESI + 0x1014],EBX
    //                               LAB_0044b6e5                                                 XREF[2]:     0044b6d5(j), 0044b6db(j)  
    //                              fractal.cpp:318 (31)
    //         0044b6e5     MOV        EDX,dword ptr [ESI + 0x1048]
    //         0044b6eb     CMP        EAX,EDX
    //         0044b6ed     JL         LAB_0044b704
    //         0044b6ef     LEA        EAX,[EDX + -0x1]
    //         0044b6f2     MOV        EDX,dword ptr [ESI + 0x1010]
    //         0044b6f8     TEST       EDX,EDX
    //         0044b6fa     JLE        LAB_0044b704
    //         0044b6fc     NEG        EDX
    //         0044b6fe     MOV        dword ptr [ESI + 0x1010],EDX
    //                               LAB_0044b704                                                 XREF[2]:     0044b6ed(j), 0044b6fa(j)  
    //                              fractal.cpp:319 (31)
    //         0044b704     MOV        EDX,dword ptr [ESI + 0x1050]
    //         0044b70a     CMP        this,EDX
    //         0044b70c     JL         LAB_0044b723
    //         0044b70e     LEA        this,[EDX + -0x1]
    //         0044b711     MOV        EDX,dword ptr [ESI + 0x1014]
    //         0044b717     TEST       EDX,EDX
    //         0044b719     JLE        LAB_0044b723
    //         0044b71b     NEG        EDX
    //         0044b71d     MOV        dword ptr [ESI + 0x1014],EDX
    //                               LAB_0044b723                                                 XREF[2]:     0044b70c(j), 0044b719(j)  
    //                              fractal.cpp:321 (6)
    //         0044b723     MOV        dword ptr [ESI + 0xfbc],this
    //                              fractal.cpp:323 (12)
    //         0044b729     MOV        this,dword ptr [ESI + 0xfe0]
    //         0044b72f     MOV        dword ptr [ESI + 0xfb8],EAX
    //                              fractal.cpp:325 (39)
    //         0044b735     POP        EDI
    //         0044b736     MOV        dword ptr [ESI + this->Prime.x*0x8 + 0x8],EAX
    //         0044b73a     MOV        EDX,dword ptr [ESI + 0xfe0]
    //         0044b740     MOV        EAX,dword ptr [ESI + 0xfbc]
    //         0044b746     MOV        dword ptr [ESI + EDX*0x8 + 0xc],EAX
    //         0044b74a     MOV        EAX,dword ptr [ESI + 0xfe0]
    //         0044b750     LEA        this,[EAX + 0x1]
    //         0044b753     MOV        dword ptr [ESI + 0xfe0],this
    //         0044b759     POP        ESI
    //         0044b75a     POP        EBX
    //         0044b75b     RET
    //         0044b75c     ??         90h
    //         0044b75d     NOP
    //         0044b75e     NOP
    //         0044b75f     NOP
    return 0;
}

int PointMaker::MakeNewLink() {
    /* TODO: Stub */
    //                              int __thiscall MakeNewLink(PointMaker * this)
    //              int               EAX:4          <RETURN>
    //              PointMaker *      ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0044b819(W), 0044b869(R)  
    //                               ?MakeNewLink@PointMaker@@IAEHXZ                              XREF[1]:     Branch:0044b5c1(c)  
    //                               PointMaker::MakeNewLink
    //                              fractal.cpp:328 (5)
    //         0044b760     PUSH       this
    //         0044b761     PUSH       EBX
    //         0044b762     PUSH       EBP
    //         0044b763     PUSH       ESI
    //         0044b764     PUSH       EDI
    //                              fractal.cpp:330 (64)
    //         0044b765     PUSH       0x14a
    //         0044b76a     MOV        ESI,this
    //         0044b76c     PUSH       s_C:\msdev\work\age1_x1\fractal.cp               = "C:\\msdev\\work\\age1_x1\\fractal.cpp"
    //         0044b771     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         0044b776     CDQ
    //         0044b777     IDIV       dword ptr [ESI + 0x100c]
    //         0044b77d     ADD        ESP,0x8
    //         0044b780     PUSH       0x14a
    //         0044b785     PUSH       s_C:\msdev\work\age1_x1\fractal.cp               = "C:\\msdev\\work\\age1_x1\\fractal.cpp"
    //         0044b78a     MOV        EBX,EDX
    //         0044b78c     INC        EBX
    //         0044b78d     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         0044b792     CDQ
    //         0044b793     XOR        EAX,EDX
    //         0044b795     ADD        ESP,0x8
    //         0044b798     SUB        EAX,EDX
    //         0044b79a     AND        EAX,0x1
    //         0044b79d     XOR        EAX,EDX
    //         0044b79f     SUB        EAX,EDX
    //         0044b7a1     JZ         LAB_0044b7a5
    //         0044b7a3     NEG        EBX
    //                               LAB_0044b7a5                                                 XREF[1]:     0044b7a1(j)  
    //                              fractal.cpp:331 (62)
    //         0044b7a5     PUSH       0x14b
    //         0044b7aa     PUSH       s_C:\msdev\work\age1_x1\fractal.cp               = "C:\\msdev\\work\\age1_x1\\fractal.cpp"
    //         0044b7af     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         0044b7b4     CDQ
    //         0044b7b5     IDIV       dword ptr [ESI + 0x100c]
    //         0044b7bb     ADD        ESP,0x8
    //         0044b7be     PUSH       0x14b
    //         0044b7c3     PUSH       s_C:\msdev\work\age1_x1\fractal.cp               = "C:\\msdev\\work\\age1_x1\\fractal.cpp"
    //         0044b7c8     MOV        EDI,EDX
    //         0044b7ca     INC        EDI
    //         0044b7cb     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         0044b7d0     CDQ
    //         0044b7d1     XOR        EAX,EDX
    //         0044b7d3     ADD        ESP,0x8
    //         0044b7d6     SUB        EAX,EDX
    //         0044b7d8     AND        EAX,0x1
    //         0044b7db     XOR        EAX,EDX
    //         0044b7dd     SUB        EAX,EDX
    //         0044b7df     JZ         LAB_0044b7e3
    //         0044b7e1     NEG        EDI
    //                               LAB_0044b7e3                                                 XREF[1]:     0044b7df(j)  
    //                              fractal.cpp:332 (6)
    //         0044b7e3     MOV        EAX,dword ptr [ESI + 0x1010]
    //                              fractal.cpp:334 (34)
    //         0044b7e9     MOV        EDX,dword ptr [ESI + 0xfb8]
    //         0044b7ef     MOV        this,dword ptr [ESI + 0x1014]
    //         0044b7f5     ADD        EBX,EAX
    //         0044b7f7     ADD        EDI,this
    //         0044b7f9     LEA        EBP,[EBX + EDX*0x1]
    //         0044b7fc     CMP        EBP,0x5
    //         0044b7ff     JGE        LAB_0044b80b
    //         0044b801     NEG        EBX
    //         0044b803     NEG        EAX
    //         0044b805     MOV        dword ptr [ESI + 0x1010],EAX
    //                               LAB_0044b80b                                                 XREF[1]:     0044b7ff(j)  
    //                              fractal.cpp:335 (36)
    //         0044b80b     MOV        EAX,dword ptr [ESI + 0xfd4]
    //         0044b811     LEA        EBP,[EBX + EDX*0x1]
    //         0044b814     ADD        EAX,-0x5
    //         0044b817     CMP        EBP,EAX
    //         0044b819     MOV        dword ptr [ESP + local_4],EAX
    //         0044b81d     JL         LAB_0044b82f
    //         0044b81f     MOV        EAX,dword ptr [ESI + 0x1010]
    //         0044b825     NEG        EBX
    //         0044b827     NEG        EAX
    //         0044b829     MOV        dword ptr [ESI + 0x1010],EAX
    //                               LAB_0044b82f                                                 XREF[1]:     0044b81d(j)  
    //                              fractal.cpp:336 (26)
    //         0044b82f     MOV        EAX,dword ptr [ESI + 0xfbc]
    //         0044b835     LEA        EBP,[EDI + EAX*0x1]
    //         0044b838     CMP        EBP,0x5
    //         0044b83b     JGE        LAB_0044b849
    //         0044b83d     MOV        EDI,EBX
    //         0044b83f     NEG        EDI
    //         0044b841     NEG        this
    //         0044b843     MOV        dword ptr [ESI + 0x1014],this
    //                               LAB_0044b849                                                 XREF[1]:     0044b83b(j)  
    //                              fractal.cpp:337 (18)
    //         0044b849     MOV        this,dword ptr [ESI + 0xfd8]
    //         0044b84f     LEA        EBP,[EDI + EAX*0x1]
    //         0044b852     ADD        this,-0x5
    //         0044b855     CMP        EBP,this
    //         0044b857     JL         LAB_0044b85b
    //         0044b859     NEG        EDI
    //                               LAB_0044b85b                                                 XREF[1]:     0044b857(j)  
    //                              fractal.cpp:339 (2)
    //         0044b85b     ADD        EBX,EDX
    //                              fractal.cpp:340 (2)
    //         0044b85d     ADD        EDI,EAX
    //                              fractal.cpp:341 (10)
    //         0044b85f     CMP        EBX,0x5
    //         0044b862     JGE        LAB_0044b869
    //         0044b864     MOV        EBX,0x5
    //                               LAB_0044b869                                                 XREF[1]:     0044b862(j)  
    //                              fractal.cpp:342 (10)
    //         0044b869     MOV        EAX,dword ptr [ESP + local_4]
    //         0044b86d     CMP        EBX,EAX
    //         0044b86f     JL         LAB_0044b873
    //         0044b871     MOV        EBX,EAX
    //                               LAB_0044b873                                                 XREF[1]:     0044b86f(j)  
    //                              fractal.cpp:343 (10)
    //         0044b873     CMP        EDI,0x5
    //         0044b876     JGE        LAB_0044b87d
    //         0044b878     MOV        EDI,0x5
    //                               LAB_0044b87d                                                 XREF[1]:     0044b876(j)  
    //                              fractal.cpp:344 (6)
    //         0044b87d     CMP        EDI,this
    //         0044b87f     JL         LAB_0044b883
    //         0044b881     MOV        EDI,this
    //                               LAB_0044b883                                                 XREF[1]:     0044b87f(j)  
    //                              fractal.cpp:346 (73)
    //         0044b883     PUSH       0x15a
    //         0044b888     PUSH       s_C:\msdev\work\age1_x1\fractal.cp               = "C:\\msdev\\work\\age1_x1\\fractal.cpp"
    //         0044b88d     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         0044b892     CDQ
    //         0044b893     XOR        EAX,EDX
    //         0044b895     ADD        ESP,0x8
    //         0044b898     SUB        EAX,EDX
    //         0044b89a     AND        EAX,0x1
    //         0044b89d     XOR        EAX,EDX
    //         0044b89f     SUB        EAX,EDX
    //         0044b8a1     JZ         LAB_0044b8cc
    //         0044b8a3     PUSH       0x15a
    //         0044b8a8     PUSH       s_C:\msdev\work\age1_x1\fractal.cp               = "C:\\msdev\\work\\age1_x1\\fractal.cpp"
    //         0044b8ad     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         0044b8b2     CDQ
    //         0044b8b3     MOV        this,0x3
    //         0044b8b8     ADD        ESP,0x8
    //         0044b8bb     IDIV       this
    //         0044b8bd     MOV        EAX,dword ptr [ESI + 0x1010]
    //         0044b8c3     DEC        EDX
    //         0044b8c4     ADD        EAX,EDX
    //         0044b8c6     MOV        dword ptr [ESI + 0x1010],EAX
    //                               LAB_0044b8cc                                                 XREF[1]:     0044b8a1(j)  
    //                              fractal.cpp:347 (73)
    //         0044b8cc     PUSH       0x15b
    //         0044b8d1     PUSH       s_C:\msdev\work\age1_x1\fractal.cp               = "C:\\msdev\\work\\age1_x1\\fractal.cpp"
    //         0044b8d6     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         0044b8db     CDQ
    //         0044b8dc     XOR        EAX,EDX
    //         0044b8de     ADD        ESP,0x8
    //         0044b8e1     SUB        EAX,EDX
    //         0044b8e3     AND        EAX,0x1
    //         0044b8e6     XOR        EAX,EDX
    //         0044b8e8     SUB        EAX,EDX
    //         0044b8ea     JZ         LAB_0044b915
    //         0044b8ec     PUSH       0x15b
    //         0044b8f1     PUSH       s_C:\msdev\work\age1_x1\fractal.cp               = "C:\\msdev\\work\\age1_x1\\fractal.cpp"
    //         0044b8f6     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         0044b8fb     CDQ
    //         0044b8fc     MOV        this,0x3
    //         0044b901     ADD        ESP,0x8
    //         0044b904     IDIV       this
    //         0044b906     MOV        EAX,dword ptr [ESI + 0x1014]
    //         0044b90c     DEC        EDX
    //         0044b90d     ADD        EAX,EDX
    //         0044b90f     MOV        dword ptr [ESI + 0x1014],EAX
    //                               LAB_0044b915                                                 XREF[1]:     0044b8ea(j)  
    //                              fractal.cpp:350 (18)
    //         0044b915     MOV        EDX,dword ptr [ESI + 0xfe0]
    //         0044b91b     MOV        dword ptr [ESI + 0xfb8],EBX
    //         0044b921     MOV        dword ptr [ESI + 0xfbc],EDI
    //                              fractal.cpp:352 (41)
    //         0044b927     POP        EDI
    //         0044b928     MOV        dword ptr [ESI + EDX*0x8 + 0x8],EBX
    //         0044b92c     MOV        EAX,dword ptr [ESI + 0xfe0]
    //         0044b932     MOV        this,dword ptr [ESI + 0xfbc]
    //         0044b938     MOV        dword ptr [ESI + EAX*0x8 + 0xc],this
    //         0044b93c     MOV        EAX,dword ptr [ESI + 0xfe0]
    //         0044b942     LEA        EDX,[EAX + 0x1]
    //         0044b945     MOV        dword ptr [ESI + 0xfe0],EDX
    //         0044b94b     POP        ESI
    //         0044b94c     POP        EBP
    //         0044b94d     POP        EBX
    //         0044b94e     POP        this
    //         0044b94f     RET
    return 0;
}

int PointMaker::MakeSatelliteLink() {
    /* TODO: Stub */
    //                              int __thiscall MakeSatelliteLink(PointMaker * this)
    //              int               EAX:4          <RETURN>
    //              PointMaker *      ECX:4 (auto)   this
    //                               ?MakeSatelliteLink@PointMaker@@IAEHXZ                        XREF[1]:     Branch:0044b5f1(c)  
    //                               PointMaker::MakeSatelliteLink
    //                              fractal.cpp:355 (4)
    //         0044b950     PUSH       EBX
    //         0044b951     PUSH       EBP
    //         0044b952     PUSH       ESI
    //         0044b953     PUSH       EDI
    //                              fractal.cpp:357 (64)
    //         0044b954     PUSH       0x165
    //         0044b959     MOV        ESI,this
    //         0044b95b     PUSH       s_C:\msdev\work\age1_x1\fractal.cp               = "C:\\msdev\\work\\age1_x1\\fractal.cpp"
    //         0044b960     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         0044b965     CDQ
    //         0044b966     IDIV       dword ptr [ESI + 0x1008]
    //         0044b96c     ADD        ESP,0x8
    //         0044b96f     PUSH       0x165
    //         0044b974     PUSH       s_C:\msdev\work\age1_x1\fractal.cp               = "C:\\msdev\\work\\age1_x1\\fractal.cpp"
    //         0044b979     MOV        EBX,EDX
    //         0044b97b     INC        EBX
    //         0044b97c     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         0044b981     CDQ
    //         0044b982     XOR        EAX,EDX
    //         0044b984     ADD        ESP,0x8
    //         0044b987     SUB        EAX,EDX
    //         0044b989     AND        EAX,0x1
    //         0044b98c     XOR        EAX,EDX
    //         0044b98e     SUB        EAX,EDX
    //         0044b990     JZ         LAB_0044b994
    //         0044b992     NEG        EBX
    //                               LAB_0044b994                                                 XREF[1]:     0044b990(j)  
    //                              fractal.cpp:358 (62)
    //         0044b994     PUSH       0x166
    //         0044b999     PUSH       s_C:\msdev\work\age1_x1\fractal.cp               = "C:\\msdev\\work\\age1_x1\\fractal.cpp"
    //         0044b99e     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         0044b9a3     CDQ
    //         0044b9a4     IDIV       dword ptr [ESI + 0x1008]
    //         0044b9aa     ADD        ESP,0x8
    //         0044b9ad     PUSH       0x166
    //         0044b9b2     PUSH       s_C:\msdev\work\age1_x1\fractal.cp               = "C:\\msdev\\work\\age1_x1\\fractal.cpp"
    //         0044b9b7     MOV        EDI,EDX
    //         0044b9b9     INC        EDI
    //         0044b9ba     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         0044b9bf     CDQ
    //         0044b9c0     XOR        EAX,EDX
    //         0044b9c2     ADD        ESP,0x8
    //         0044b9c5     SUB        EAX,EDX
    //         0044b9c7     AND        EAX,0x1
    //         0044b9ca     XOR        EAX,EDX
    //         0044b9cc     SUB        EAX,EDX
    //         0044b9ce     JZ         LAB_0044b9d2
    //         0044b9d0     NEG        EDI
    //                               LAB_0044b9d2                                                 XREF[1]:     0044b9ce(j)  
    //                              fractal.cpp:359 (6)
    //         0044b9d2     MOV        EAX,dword ptr [ESI + 0x1010]
    //                              fractal.cpp:361 (35)
    //         0044b9d8     MOV        EBP,dword ptr [ESI + 0xfb8]
    //         0044b9de     MOV        this,dword ptr [ESI + 0x1014]
    //         0044b9e4     ADD        EBX,EAX
    //         0044b9e6     MOV        EDX,EBX
    //         0044b9e8     ADD        EDI,this
    //         0044b9ea     ADD        EDX,EBP
    //         0044b9ec     CMP        EDX,0x3
    //         0044b9ef     JGE        LAB_0044b9fb
    //         0044b9f1     NEG        EBX
    //         0044b9f3     NEG        EAX
    //         0044b9f5     MOV        dword ptr [ESI + 0x1010],EAX
    //                               LAB_0044b9fb                                                 XREF[1]:     0044b9ef(j)  
    //                              fractal.cpp:362 (39)
    //         0044b9fb     MOV        EDX,dword ptr [ESI + 0xfb8]
    //         0044ba01     MOV        EAX,EBX
    //         0044ba03     ADD        EAX,EDX
    //         0044ba05     MOV        EDX,dword ptr [ESI + 0xfd4]
    //         0044ba0b     SUB        EDX,0x3
    //         0044ba0e     CMP        EAX,EDX
    //         0044ba10     JL         LAB_0044ba22
    //         0044ba12     MOV        EAX,dword ptr [ESI + 0x1010]
    //         0044ba18     NEG        EBX
    //         0044ba1a     NEG        EAX
    //         0044ba1c     MOV        dword ptr [ESI + 0x1010],EAX
    //                               LAB_0044ba22                                                 XREF[1]:     0044ba10(j)  
    //                              fractal.cpp:363 (26)
    //         0044ba22     MOV        EAX,dword ptr [ESI + 0xfbc]
    //         0044ba28     LEA        EDX,[EDI + EAX*0x1]
    //         0044ba2b     CMP        EDX,0x3
    //         0044ba2e     JGE        LAB_0044ba3c
    //         0044ba30     MOV        EDI,EBX
    //         0044ba32     NEG        EDI
    //         0044ba34     NEG        this
    //         0044ba36     MOV        dword ptr [ESI + 0x1014],this
    //                               LAB_0044ba3c                                                 XREF[1]:     0044ba2e(j)  
    //                              fractal.cpp:364 (32)
    //         0044ba3c     MOV        EDX,dword ptr [ESI + 0xfd8]
    //         0044ba42     LEA        this,[EDI + EAX*0x1]
    //         0044ba45     SUB        EDX,0x3
    //         0044ba48     CMP        this,EDX
    //         0044ba4a     JL         LAB_0044ba5c
    //         0044ba4c     MOV        this,dword ptr [ESI + 0x1014]
    //         0044ba52     NEG        EDI
    //         0044ba54     NEG        this
    //         0044ba56     MOV        dword ptr [ESI + 0x1014],this
    //                               LAB_0044ba5c                                                 XREF[1]:     0044ba4a(j)  
    //                              fractal.cpp:369 (6)
    //         0044ba5c     MOV        this,dword ptr [ESI + 0xfb8]
    //                              fractal.cpp:371 (38)
    //         0044ba62     MOV        EDX,dword ptr [ESI + 0xfe0]
    //         0044ba68     ADD        this,EBX
    //         0044ba6a     ADD        EDI,EAX
    //         0044ba6c     MOV        dword ptr [ESI + 0xfb8],this
    //         0044ba72     MOV        dword ptr [ESI + 0xfbc],EDI
    //         0044ba78     MOV        dword ptr [ESI + EDX*0x8 + 0x8],this
    //         0044ba7c     MOV        EAX,dword ptr [ESI + 0xfe0]
    //         0044ba82     MOV        this,dword ptr [ESI + 0xfbc]
    //                              fractal.cpp:373 (24)
    //         0044ba88     POP        EDI
    //         0044ba89     MOV        dword ptr [ESI + EAX*0x8 + 0xc],this
    //         0044ba8d     MOV        EAX,dword ptr [ESI + 0xfe0]
    //         0044ba93     LEA        EDX,[EAX + 0x1]
    //         0044ba96     MOV        dword ptr [ESI + 0xfe0],EDX
    //         0044ba9c     POP        ESI
    //         0044ba9d     POP        EBP
    //         0044ba9e     POP        EBX
    //         0044ba9f     RET
    return 0;
}

void PointMaker::DrawPrimaryIntoProbabilityArray() {
    /* TODO: Stub */
    //                              void __thiscall DrawPrimaryIntoProbabilityArray(PointMaker * this)
    //              void              <VOID>         <RETURN>
    //              PointMaker *      ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0044bb09(W), 0044bb20(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     0044bb0e(W), 0044bb1b(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[3]:     0044baf7(W), 0044bb41(R), 0044bb48(W)  
    //              int               Stack[-0x10]:4 i                         XREF[3]:     0044bae5(W), 0044bb03(R), 0044bb17(W)  
    //              int               Stack[-0x14]:4 desty
    //                               ?DrawPrimaryIntoProbabilityArray@PointMaker@@IAEXXZ          XREF[2]:     CreateShape:0044b3ec(c), 
    //                               PointMaker::DrawPrimaryIntoProbabilityArray                               CreateShape:0044b4b1(c)  
    //                              fractal.cpp:378 (9)
    //         0044baa0     SUB        ESP,0x10
    //         0044baa3     PUSH       EBX
    //         0044baa4     PUSH       EBP
    //         0044baa5     PUSH       ESI
    //         0044baa6     MOV        ESI,this
    //         0044baa8     PUSH       EDI
    //                              fractal.cpp:379 (19)
    //         0044baa9     MOV        EDX,dword ptr [ESI]
    //         0044baab     MOV        EAX,dword ptr [ESI + 0x4]
    //         0044baae     MOV        this,dword ptr [ESI + 0x1000]
    //         0044bab4     MOV        EDI,EDX
    //         0044bab6     MOV        EBX,EAX
    //         0044bab8     SUB        EDI,this
    //         0044baba     SUB        EBX,this
    //                              fractal.cpp:380 (2)
    //         0044babc     ADD        EAX,this
    //                              fractal.cpp:381 (9)
    //         0044babe     TEST       EDI,EDI
    //         0044bac0     LEA        EBP,[this->Prime.x + EDX*0x1]
    //         0044bac3     JGE        LAB_0044bac7
    //         0044bac5     XOR        EDI,EDI
    //                               LAB_0044bac7                                                 XREF[1]:     0044bac3(j)  
    //                              fractal.cpp:382 (6)
    //         0044bac7     TEST       EBX,EBX
    //         0044bac9     JGE        LAB_0044bacd
    //         0044bacb     XOR        EBX,EBX
    //                               LAB_0044bacd                                                 XREF[1]:     0044bac9(j)  
    //                              fractal.cpp:383 (13)
    //         0044bacd     MOV        EDX,dword ptr [ESI + 0xfd4]
    //         0044bad3     DEC        EDX
    //         0044bad4     CMP        EBP,EDX
    //         0044bad6     JLE        LAB_0044bada
    //         0044bad8     MOV        EBP,EDX
    //                               LAB_0044bada                                                 XREF[1]:     0044bad6(j)  
    //                              fractal.cpp:384 (17)
    //         0044bada     MOV        EDX,dword ptr [ESI + 0xfd8]
    //         0044bae0     DEC        EDX
    //         0044bae1     CMP        EAX,EDX
    //         0044bae3     JLE        LAB_0044baeb
    //         0044bae5     MOV        dword ptr [ESP + i],EDX
    //         0044bae9     MOV        EAX,EDX
    //                               LAB_0044baeb                                                 XREF[1]:     0044bae3(j)  
    //                              fractal.cpp:391 (28)
    //         0044baeb     TEST       this,this
    //         0044baed     MOV        dword ptr [ESI + 0xff4],0x1
    //         0044baf7     MOV        dword ptr [ESP + local_c],0x0
    //         0044baff     JLE        LAB_0044bb4e
    //         0044bb01     JMP        LAB_0044bb07
    //                               LAB_0044bb03                                                 XREF[1]:     0044bb4c(j)  
    //         0044bb03     MOV        EAX,dword ptr [ESP + i]
    //                               LAB_0044bb07                                                 XREF[1]:     0044bb01(j)  
    //                              fractal.cpp:393 (39)
    //         0044bb07     MOV        EDX,EDI
    //         0044bb09     MOV        dword ptr [ESP + local_4],EBX
    //         0044bb0d     INC        EDI
    //         0044bb0e     MOV        dword ptr [ESP + local_8],EBP
    //         0044bb12     INC        EBX
    //         0044bb13     MOV        this,EAX
    //         0044bb15     DEC        EBP
    //         0044bb16     DEC        EAX
    //         0044bb17     MOV        dword ptr [ESP + i],EAX
    //         0044bb1b     MOV        EAX,dword ptr [ESP + local_8]
    //         0044bb1f     PUSH       this
    //         0044bb20     MOV        this,dword ptr [ESP + local_4]
    //         0044bb24     PUSH       EAX
    //         0044bb25     PUSH       this
    //         0044bb26     PUSH       EDX
    //         0044bb27     MOV        this,ESI
    //         0044bb29     CALL       PointMaker::AddingRect                           void AddingRect(PointMaker * this, int param_
    //                              fractal.cpp:394 (32)
    //         0044bb2e     MOV        EAX,dword ptr [ESI + 0xff4]
    //         0044bb34     MOV        this,dword ptr [ESI + 0x1000]
    //         0044bb3a     INC        EAX
    //         0044bb3b     MOV        dword ptr [ESI + 0xff4],EAX
    //         0044bb41     MOV        EAX,dword ptr [ESP + local_c]
    //         0044bb45     INC        EAX
    //         0044bb46     CMP        EAX,this
    //         0044bb48     MOV        dword ptr [ESP + local_c],EAX
    //         0044bb4c     JL         LAB_0044bb03
    //                               LAB_0044bb4e                                                 XREF[1]:     0044baff(j)  
    //                              fractal.cpp:397 (8)
    //         0044bb4e     POP        EDI
    //         0044bb4f     POP        ESI
    //         0044bb50     POP        EBP
    //         0044bb51     POP        EBX
    //         0044bb52     ADD        ESP,0x10
    //         0044bb55     RET
    //         0044bb56     ??         90h
    //         0044bb57     NOP
    //         0044bb58     NOP
    //         0044bb59     NOP
    //         0044bb5a     NOP
    //         0044bb5b     NOP
    //         0044bb5c     NOP
    //         0044bb5d     NOP
    //         0044bb5e     NOP
    //         0044bb5f     NOP
    return;
}

void PointMaker::DrawCurrentBranchIntoProbArray(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall DrawCurrentBranchIntoProbArray(PointMaker * this, in
    //              void              <VOID>         <RETURN>
    //              PointMaker *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[2]:     0044bb63(R), 0044bc49(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     0044bbea(W), 0044bc3c(R), 0044bc43(W)  
    //              int               Stack[-0x8]:4  i                         XREF[5]:     0044bb8a(W), 0044bbd8(W), 0044bbf6(R), 0044bc1e(R), 
    //                                                                                     0044bc23(W)  
    //              int               Stack[-0xc]:4  desty
    //                               ?DrawCurrentBranchIntoProbArray@PointMaker@@IAEXH@Z          XREF[1]:     Branch:0044b5cb(c)  
    //                               PointMaker::DrawCurrentBranchIntoProbArray
    //                              fractal.cpp:401 (3)
    //         0044bb60     SUB        ESP,0x8
    //                              fractal.cpp:402 (28)
    //         0044bb63     MOV        EDX,dword ptr [ESP + param_1]
    //         0044bb67     PUSH       EBX
    //         0044bb68     PUSH       EBP
    //         0044bb69     PUSH       ESI
    //         0044bb6a     MOV        ESI,this
    //         0044bb6c     PUSH       EDI
    //         0044bb6d     MOV        this,dword ptr [ESI + EDX*0x8 + 0x8]
    //         0044bb71     MOV        EAX,dword ptr [ESI + 0xff8]
    //         0044bb77     MOV        EDX,dword ptr [ESI + EDX*0x8 + 0xc]
    //         0044bb7b     MOV        EDI,this
    //         0044bb7d     MOV        EBX,EDX
    //                              fractal.cpp:403 (9)
    //         0044bb7f     LEA        EBP,[EAX + this->Prime.x*0x1]
    //         0044bb82     SUB        EDI,EAX
    //         0044bb84     SUB        EBX,EAX
    //         0044bb86     ADD        EDX,EAX
    //                              fractal.cpp:404 (12)
    //         0044bb88     TEST       EBP,EBP
    //         0044bb8a     MOV        dword ptr [ESP + i],EDX
    //         0044bb8e     JL         LAB_0044bcbb
    //                              fractal.cpp:405 (8)
    //         0044bb94     TEST       EDX,EDX
    //         0044bb96     JL         LAB_0044bcbb
    //                              fractal.cpp:406 (12)
    //         0044bb9c     CMP        EDI,dword ptr [ESI + 0xfd4]
    //         0044bba2     JGE        LAB_0044bcbb
    //                              fractal.cpp:407 (12)
    //         0044bba8     CMP        EBX,dword ptr [ESI + 0xfd8]
    //         0044bbae     JGE        LAB_0044bcbb
    //                              fractal.cpp:408 (6)
    //         0044bbb4     TEST       EDI,EDI
    //         0044bbb6     JGE        LAB_0044bbba
    //         0044bbb8     XOR        EDI,EDI
    //                               LAB_0044bbba                                                 XREF[1]:     0044bbb6(j)  
    //                              fractal.cpp:409 (6)
    //         0044bbba     TEST       EBX,EBX
    //         0044bbbc     JGE        LAB_0044bbc0
    //         0044bbbe     XOR        EBX,EBX
    //                               LAB_0044bbc0                                                 XREF[1]:     0044bbbc(j)  
    //                              fractal.cpp:411 (13)
    //         0044bbc0     MOV        this,dword ptr [ESI + 0xfd4]
    //         0044bbc6     CMP        EBP,this
    //         0044bbc8     JL         LAB_0044bbcd
    //         0044bbca     LEA        EBP,[this->Prime.x + -0x1]
    //                               LAB_0044bbcd                                                 XREF[1]:     0044bbc8(j)  
    //                              fractal.cpp:412 (17)
    //         0044bbcd     MOV        this,dword ptr [ESI + 0xfd8]
    //         0044bbd3     CMP        EDX,this
    //         0044bbd5     JL         LAB_0044bbde
    //         0044bbd7     DEC        this
    //         0044bbd8     MOV        dword ptr [ESP + i],this
    //         0044bbdc     MOV        EDX,this
    //                               LAB_0044bbde                                                 XREF[1]:     0044bbd5(j)  
    //                              fractal.cpp:419 (28)
    //         0044bbde     TEST       EAX,EAX
    //         0044bbe0     MOV        dword ptr [ESI + 0xff4],0x1
    //         0044bbea     MOV        dword ptr [ESP + local_4],0x0
    //         0044bbf2     JLE        LAB_0044bc49
    //         0044bbf4     JMP        LAB_0044bbfa
    //                               LAB_0044bbf6                                                 XREF[1]:     0044bc47(j)  
    //         0044bbf6     MOV        EDX,dword ptr [ESP + i]
    //                               LAB_0044bbfa                                                 XREF[1]:     0044bbf4(j)  
    //                              fractal.cpp:421 (11)
    //         0044bbfa     PUSH       EDX
    //         0044bbfb     PUSH       EBP
    //         0044bbfc     PUSH       EBX
    //         0044bbfd     PUSH       EDI
    //         0044bbfe     MOV        this,ESI
    //         0044bc00     CALL       PointMaker::AddingRect                           void AddingRect(PointMaker * this, int param_
    //                              fractal.cpp:422 (11)
    //         0044bc05     MOV        EAX,dword ptr [ESI + 0xfd4]
    //         0044bc0b     INC        EDI
    //         0044bc0c     CMP        EDI,EAX
    //         0044bc0e     JGE        LAB_0044bc49
    //                              fractal.cpp:423 (11)
    //         0044bc10     MOV        EAX,dword ptr [ESI + 0xfd8]
    //         0044bc16     INC        EBX
    //         0044bc17     CMP        EBX,EAX
    //         0044bc19     JGE        LAB_0044bc49
    //                              fractal.cpp:424 (3)
    //         0044bc1b     DEC        EBP
    //         0044bc1c     JS         LAB_0044bc49
    //                              fractal.cpp:425 (11)
    //         0044bc1e     MOV        EAX,dword ptr [ESP + i]
    //         0044bc22     DEC        EAX
    //         0044bc23     MOV        dword ptr [ESP + i],EAX
    //         0044bc27     JS         LAB_0044bc49
    //                              fractal.cpp:426 (32)
    //         0044bc29     MOV        EAX,dword ptr [ESI + 0xff4]
    //         0044bc2f     MOV        this,dword ptr [ESI + 0xff8]
    //         0044bc35     INC        EAX
    //         0044bc36     MOV        dword ptr [ESI + 0xff4],EAX
    //         0044bc3c     MOV        EAX,dword ptr [ESP + local_4]
    //         0044bc40     INC        EAX
    //         0044bc41     CMP        EAX,this
    //         0044bc43     MOV        dword ptr [ESP + local_4],EAX
    //         0044bc47     JL         LAB_0044bbf6
    //                               LAB_0044bc49                                                 XREF[5]:     0044bbf2(j), 0044bc0e(j), 
    //                                                                                                         0044bc19(j), 0044bc1c(j), 
    //                                                                                                         0044bc27(j)  
    //                              fractal.cpp:428 (72)
    //         0044bc49     MOV        this,dword ptr [ESP + param_1]
    //         0044bc4d     MOV        EAX,dword ptr [ESI + 0xfd4]
    //         0044bc53     IMUL       EAX,dword ptr [ESI + this->Prime.x*0x8 + 0xc]
    //         0044bc58     MOV        EDI,dword ptr [ESI + this->Prime.x*0x8 + 0x8]
    //         0044bc5c     MOV        this,dword ptr [ESI + 0xff4]
    //         0044bc62     ADD        EAX,EDI
    //         0044bc64     CMP        EAX,0x1
    //         0044bc67     JL         LAB_0044bcbb
    //         0044bc69     MOV        EDX,dword ptr [ESI + 0x1004]
    //         0044bc6f     DEC        EDX
    //         0044bc70     CMP        EAX,EDX
    //         0044bc72     JGE        LAB_0044bcbb
    //         0044bc74     MOV        EDX,dword ptr [ESI + 0x1024]
    //         0044bc7a     ADD        EAX,EDX
    //         0044bc7c     MOV        DL,byte ptr [EAX]
    //         0044bc7e     TEST       DL,DL
    //         0044bc80     JNZ        LAB_0044bc9b
    //         0044bc82     MOV        byte ptr [EAX],this
    //         0044bc84     MOV        EAX,dword ptr [ESI + 0xfec]
    //         0044bc8a     INC        EAX
    //         0044bc8b     MOV        dword ptr [ESI + 0xfec],EAX
    //                              fractal.cpp:429 (10)
    //         0044bc91     POP        EDI
    //         0044bc92     POP        ESI
    //         0044bc93     POP        EBP
    //         0044bc94     POP        EBX
    //         0044bc95     ADD        ESP,0x8
    //         0044bc98     RET        0x4
    //                               LAB_0044bc9b                                                 XREF[1]:     0044bc80(j)  
    //                              fractal.cpp:428 (19)
    //         0044bc9b     MOVSX      ESI,DL
    //         0044bc9e     MOV        EDI,this
    //         0044bca0     ADD        EDI,ESI
    //         0044bca2     CMP        EDI,0xff
    //         0044bca8     JGE        LAB_0044bcb8
    //         0044bcaa     ADD        this,DL
    //         0044bcac     MOV        byte ptr [EAX],this
    //                              fractal.cpp:429 (10)
    //         0044bcae     POP        EDI
    //         0044bcaf     POP        ESI
    //         0044bcb0     POP        EBP
    //         0044bcb1     POP        EBX
    //         0044bcb2     ADD        ESP,0x8
    //         0044bcb5     RET        0x4
    //                               LAB_0044bcb8                                                 XREF[1]:     0044bca8(j)  
    //                              fractal.cpp:428 (3)
    //         0044bcb8     MOV        byte ptr [EAX],0xff
    //                               LAB_0044bcbb                                                 XREF[6]:     0044bb8e(j), 0044bb96(j), 
    //                                                                                                         0044bba2(j), 0044bbae(j), 
    //                                                                                                         0044bc67(j), 0044bc72(j)  
    //                              fractal.cpp:429 (10)
    //         0044bcbb     POP        EDI
    //         0044bcbc     POP        ESI
    //         0044bcbd     POP        EBP
    //         0044bcbe     POP        EBX
    //         0044bcbf     ADD        ESP,0x8
    //         0044bcc2     RET        0x4
    //         0044bcc5     ??         90h
    //         0044bcc6     NOP
    //         0044bcc7     NOP
    //         0044bcc8     NOP
    //         0044bcc9     NOP
    //         0044bcca     NOP
    //         0044bccb     NOP
    //         0044bccc     NOP
    //         0044bccd     NOP
    //         0044bcce     NOP
    //         0044bccf     NOP
    return;
}

void PointMaker::DrawCurrentSatelliteIntoProbArray(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall DrawCurrentSatelliteIntoProbArray(PointMaker * this,
    //              void              <VOID>         <RETURN>
    //              PointMaker *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0044bcd1(R)  
    //                               ?DrawCurrentSatelliteIntoProbArray@PointMaker@@IAEXH@Z       XREF[1]:     Branch:0044b5f9(c)  
    //                               PointMaker::DrawCurrentSatelliteIntoProbArray
    //                              fractal.cpp:432 (1)
    //         0044bcd0     PUSH       EBX
    //                              fractal.cpp:444 (28)
    //         0044bcd1     MOV        EBX,dword ptr [ESP + param_1]
    //         0044bcd5     PUSH       ESI
    //         0044bcd6     MOV        ESI,this
    //         0044bcd8     PUSH       EDI
    //         0044bcd9     MOV        EDI,dword ptr [ESI + 0xffc]
    //         0044bcdf     MOV        dword ptr [ESI + 0xff4],0x2
    //         0044bce9     TEST       EDI,EDI
    //         0044bceb     JL         LAB_0044bd0f
    //                               LAB_0044bced                                                 XREF[1]:     0044bd0d(j)  
    //                              fractal.cpp:446 (18)
    //         0044bced     MOV        EAX,dword ptr [ESI + EBX*0x8 + 0xc]
    //         0044bcf1     MOV        this,dword ptr [ESI + EBX*0x8 + 0x8]
    //         0044bcf5     PUSH       EDI
    //         0044bcf6     PUSH       EAX
    //         0044bcf7     PUSH       this
    //         0044bcf8     MOV        this,ESI
    //         0044bcfa     CALL       PointMaker::AddingCircle                         void AddingCircle(PointMaker * this, int para
    //                              fractal.cpp:447 (16)
    //         0044bcff     MOV        this,dword ptr [ESI + 0xff4]
    //         0044bd05     INC        this
    //         0044bd06     DEC        EDI
    //         0044bd07     MOV        dword ptr [ESI + 0xff4],this
    //         0044bd0d     JNS        LAB_0044bced
    //                               LAB_0044bd0f                                                 XREF[1]:     0044bceb(j)  
    //                              fractal.cpp:459 (68)
    //         0044bd0f     MOV        EAX,dword ptr [ESI + EBX*0x8 + 0xc]
    //         0044bd13     MOV        EDX,dword ptr [ESI + EBX*0x8 + 0x8]
    //         0044bd17     IMUL       EAX,dword ptr [ESI + 0xfd4]
    //         0044bd1e     ADD        EAX,EDX
    //         0044bd20     MOV        EDX,dword ptr [ESI + 0xff4]
    //         0044bd26     CMP        EAX,0x1
    //         0044bd29     JL         LAB_0044bd75
    //         0044bd2b     MOV        this,dword ptr [ESI + 0x1004]
    //         0044bd31     DEC        this
    //         0044bd32     CMP        EAX,this
    //         0044bd34     JGE        LAB_0044bd75
    //         0044bd36     MOV        this,dword ptr [ESI + 0x1024]
    //         0044bd3c     ADD        EAX,this
    //         0044bd3e     MOV        this,byte ptr [EAX]
    //         0044bd40     TEST       this,this
    //         0044bd42     JNZ        LAB_0044bd59
    //         0044bd44     MOV        byte ptr [EAX],DL
    //         0044bd46     MOV        EAX,dword ptr [ESI + 0xfec]
    //         0044bd4c     INC        EAX
    //         0044bd4d     MOV        dword ptr [ESI + 0xfec],EAX
    //                              fractal.cpp:460 (6)
    //         0044bd53     POP        EDI
    //         0044bd54     POP        ESI
    //         0044bd55     POP        EBX
    //         0044bd56     RET        0x4
    //                               LAB_0044bd59                                                 XREF[1]:     0044bd42(j)  
    //                              fractal.cpp:459 (19)
    //         0044bd59     MOVSX      ESI,this
    //         0044bd5c     MOV        EDI,EDX
    //         0044bd5e     ADD        EDI,ESI
    //         0044bd60     CMP        EDI,0xff
    //         0044bd66     JGE        LAB_0044bd72
    //         0044bd68     ADD        DL,this
    //         0044bd6a     MOV        byte ptr [EAX],DL
    //                              fractal.cpp:460 (6)
    //         0044bd6c     POP        EDI
    //         0044bd6d     POP        ESI
    //         0044bd6e     POP        EBX
    //         0044bd6f     RET        0x4
    //                               LAB_0044bd72                                                 XREF[1]:     0044bd66(j)  
    //                              fractal.cpp:459 (3)
    //         0044bd72     MOV        byte ptr [EAX],0xff
    //                               LAB_0044bd75                                                 XREF[2]:     0044bd29(j), 0044bd34(j)  
    //                              fractal.cpp:460 (6)
    //         0044bd75     POP        EDI
    //         0044bd76     POP        ESI
    //         0044bd77     POP        EBX
    //         0044bd78     RET        0x4
    //         0044bd7b     ??         90h
    //         0044bd7c     NOP
    //         0044bd7d     NOP
    //         0044bd7e     NOP
    //         0044bd7f     NOP
    return;
}

void PointMaker::AddingRect(int param_1, int param_2, int param_3, int param_4) {
    /* TODO: Stub */
    //                              void __thiscall AddingRect(PointMaker * this, int param_1, int param
    //              void              <VOID>         <RETURN>
    //              PointMaker *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[4]:     0044bd8e(R), 0044bdd0(W), 0044be83(R), 0044be8e(W)  
    //              int               Stack[0x8]:4   param_2                   XREF[7]:     0044bd8a(R), 0044bda6(W), 0044be2c(R), 0044be7f(R), 
    //                                                                                     0044bebe(W), 0044bf6b(R), 0044bf72(W)  
    //              int               Stack[0xc]:4   param_3                   XREF[4]:     0044bd94(R), 0044bddb(W), 0044be87(R), 0044be92(W)  
    //              int               Stack[0x10]:4  param_4                   XREF[3]:     0044bd9f(R), 0044bdb3(W), 0044be9c(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0044bdaa(W), 0044bf11(R)  
    //              int               Stack[-0x8]:4  w
    //                               ?AddingRect@PointMaker@@IAEXHHHH@Z                           XREF[2]:     DrawPrimaryIntoProbabilityArray:00
    //                               PointMaker::AddingRect                                                    DrawCurrentBranchIntoProbArray:004
    //                              fractal.cpp:464 (1)
    //         0044bd80     PUSH       this
    //                              fractal.cpp:465 (59)
    //         0044bd81     MOV        EDX,dword ptr [ECX + this->Width]
    //         0044bd87     PUSH       EBX
    //         0044bd88     PUSH       EBP
    //         0044bd89     PUSH       ESI
    //         0044bd8a     MOV        ESI,dword ptr [ESP + param_2]
    //         0044bd8e     MOV        EAX,dword ptr [ESP + param_1]
    //         0044bd92     MOV        EBX,ESI
    //         0044bd94     MOV        EBP,dword ptr [ESP + param_3]
    //         0044bd98     IMUL       EBX,EDX
    //         0044bd9b     ADD        EBX,EAX
    //         0044bd9d     SUB        EBP,EAX
    //         0044bd9f     MOV        EAX,dword ptr [ESP + param_4]
    //         0044bda3     PUSH       EDI
    //         0044bda4     SUB        EAX,ESI
    //         0044bda6     MOV        dword ptr [ESP + param_2],EBX
    //         0044bdaa     MOV        dword ptr [ESP + local_4],EBP
    //         0044bdae     LEA        ESI,[EAX + -0x1]
    //         0044bdb1     MOV        EDI,ESI
    //         0044bdb3     MOV        dword ptr [ESP + param_4],ESI
    //         0044bdb7     IMUL       EDI,EDX
    //         0044bdba     ADD        EDI,EBX
    //                              fractal.cpp:466 (8)
    //         0044bdbc     TEST       EBP,EBP
    //         0044bdbe     JL         LAB_0044bf7c
    //                              fractal.cpp:467 (8)
    //         0044bdc4     TEST       EAX,EAX
    //         0044bdc6     JL         LAB_0044bf7c
    //                              fractal.cpp:469 (14)
    //         0044bdcc     MOV        EAX,EBX
    //         0044bdce     TEST       EBP,EBP
    //         0044bdd0     MOV        dword ptr [ESP + param_1],EAX
    //         0044bdd4     JL         LAB_0044bea0
    //                              fractal.cpp:482 (58)
    //         0044bdda     INC        EBP
    //         0044bddb     MOV        dword ptr [ESP + param_3],EBP
    //                               LAB_0044bddf                                                 XREF[1]:     0044be96(j)  
    //         0044bddf     MOV        EDX,dword ptr [ECX + this->ProbabilityAdd]
    //         0044bde5     CMP        EAX,0x1
    //         0044bde8     JL         LAB_0044be30
    //         0044bdea     MOV        ESI,dword ptr [ECX + this->SizeArrays]
    //         0044bdf0     DEC        ESI
    //         0044bdf1     CMP        EAX,ESI
    //         0044bdf3     JGE        LAB_0044be30
    //         0044bdf5     MOV        ESI,dword ptr [ECX + this->ProbArray]
    //         0044bdfb     ADD        ESI,EAX
    //         0044bdfd     MOV        AL,byte ptr [ESI]
    //         0044bdff     TEST       AL,AL
    //         0044be01     JNZ        LAB_0044be14
    //         0044be03     MOV        byte ptr [ESI],DL
    //         0044be05     MOV        EAX,dword ptr [ECX + this->ProbabilityTiles]
    //         0044be0b     INC        EAX
    //         0044be0c     MOV        dword ptr [ECX + this->ProbabilityTiles],EAX
    //         0044be12     JMP        LAB_0044be30
    //                               LAB_0044be14                                                 XREF[1]:     0044be01(j)  
    //                              fractal.cpp:471 (28)
    //         0044be14     MOVSX      EBX,AL
    //         0044be17     MOV        EBP,EDX
    //         0044be19     ADD        EBP,EBX
    //         0044be1b     CMP        EBP,0xff
    //         0044be21     JGE        LAB_0044be29
    //         0044be23     ADD        DL,AL
    //         0044be25     MOV        byte ptr [ESI],DL
    //         0044be27     JMP        LAB_0044be2c
    //                               LAB_0044be29                                                 XREF[1]:     0044be21(j)  
    //         0044be29     MOV        byte ptr [ESI],0xff
    //                               LAB_0044be2c                                                 XREF[1]:     0044be27(j)  
    //         0044be2c     MOV        EBX,dword ptr [ESP + param_2]
    //                               LAB_0044be30                                                 XREF[3]:     0044bde8(j), 0044bdf3(j), 
    //                                                                                                         0044be12(j)  
    //                              fractal.cpp:472 (83)
    //         0044be30     MOV        EDX,dword ptr [ECX + this->ProbabilityAdd]
    //         0044be36     CMP        EDI,0x1
    //         0044be39     JL         LAB_0044be83
    //         0044be3b     MOV        EAX,dword ptr [ECX + this->SizeArrays]
    //         0044be41     DEC        EAX
    //         0044be42     CMP        EDI,EAX
    //         0044be44     JGE        LAB_0044be83
    //         0044be46     MOV        EAX,dword ptr [ECX + this->ProbArray]
    //         0044be4c     LEA        ESI,[EAX + EDI*0x1]
    //         0044be4f     MOV        AL,byte ptr [EAX + EDI*0x1]
    //         0044be52     TEST       AL,AL
    //         0044be54     JNZ        LAB_0044be67
    //         0044be56     MOV        byte ptr [ESI],DL
    //         0044be58     MOV        EAX,dword ptr [ECX + this->ProbabilityTiles]
    //         0044be5e     INC        EAX
    //         0044be5f     MOV        dword ptr [ECX + this->ProbabilityTiles],EAX
    //         0044be65     JMP        LAB_0044be83
    //                               LAB_0044be67                                                 XREF[1]:     0044be54(j)  
    //         0044be67     MOVSX      EBX,AL
    //         0044be6a     MOV        EBP,EDX
    //         0044be6c     ADD        EBP,EBX
    //         0044be6e     CMP        EBP,0xff
    //         0044be74     JGE        LAB_0044be7c
    //         0044be76     ADD        DL,AL
    //         0044be78     MOV        byte ptr [ESI],DL
    //         0044be7a     JMP        LAB_0044be7f
    //                               LAB_0044be7c                                                 XREF[1]:     0044be74(j)  
    //         0044be7c     MOV        byte ptr [ESI],0xff
    //                               LAB_0044be7f                                                 XREF[1]:     0044be7a(j)  
    //         0044be7f     MOV        EBX,dword ptr [ESP + param_2]
    //                               LAB_0044be83                                                 XREF[3]:     0044be39(j), 0044be44(j), 
    //                                                                                                         0044be65(j)  
    //                              fractal.cpp:469 (29)
    //         0044be83     MOV        EAX,dword ptr [ESP + param_1]
    //         0044be87     MOV        EDX,dword ptr [ESP + param_3]
    //         0044be8b     INC        EDI
    //         0044be8c     INC        EAX
    //         0044be8d     DEC        EDX
    //         0044be8e     MOV        dword ptr [ESP + param_1],EAX
    //         0044be92     MOV        dword ptr [ESP + param_3],EDX
    //         0044be96     JNZ        LAB_0044bddf
    //         0044be9c     MOV        ESI,dword ptr [ESP + param_4]
    //                               LAB_0044bea0                                                 XREF[1]:     0044bdd4(j)  
    //                              fractal.cpp:474 (10)
    //         0044bea0     MOV        EDI,dword ptr [ECX + this->Width]
    //         0044bea6     MOV        EAX,ESI
    //         0044bea8     ADD        EBX,EDI
    //                              fractal.cpp:475 (8)
    //         0044beaa     TEST       EAX,EAX
    //         0044beac     JL         LAB_0044bf7c
    //                              fractal.cpp:476 (11)
    //         0044beb2     MOV        EDX,EAX
    //         0044beb4     DEC        EAX
    //         0044beb5     TEST       EDX,EDX
    //         0044beb7     JZ         LAB_0044bf7c
    //                              fractal.cpp:482 (60)
    //         0044bebd     INC        EAX
    //         0044bebe     MOV        dword ptr [ESP + param_2],EAX
    //                               LAB_0044bec2                                                 XREF[1]:     0044bf76(j)  
    //         0044bec2     MOV        EDX,dword ptr [ECX + this->ProbabilityAdd]
    //         0044bec8     CMP        EBX,0x1
    //         0044becb     JL         LAB_0044bf11
    //         0044becd     MOV        EAX,dword ptr [ECX + this->SizeArrays]
    //         0044bed3     DEC        EAX
    //         0044bed4     CMP        EBX,EAX
    //         0044bed6     JGE        LAB_0044bf11
    //         0044bed8     MOV        EAX,dword ptr [ECX + this->ProbArray]
    //         0044bede     LEA        ESI,[EAX + EBX*0x1]
    //         0044bee1     MOV        AL,byte ptr [EAX + EBX*0x1]
    //         0044bee4     TEST       AL,AL
    //         0044bee6     JNZ        LAB_0044bef9
    //         0044bee8     MOV        byte ptr [ESI],DL
    //         0044beea     MOV        EAX,dword ptr [ECX + this->ProbabilityTiles]
    //         0044bef0     INC        EAX
    //         0044bef1     MOV        dword ptr [ECX + this->ProbabilityTiles],EAX
    //         0044bef7     JMP        LAB_0044bf11
    //                               LAB_0044bef9                                                 XREF[1]:     0044bee6(j)  
    //                              fractal.cpp:478 (24)
    //         0044bef9     MOVSX      EDI,AL
    //         0044befc     MOV        EBP,EDX
    //         0044befe     ADD        EBP,EDI
    //         0044bf00     CMP        EBP,0xff
    //         0044bf06     JGE        LAB_0044bf0e
    //         0044bf08     ADD        DL,AL
    //         0044bf0a     MOV        byte ptr [ESI],DL
    //         0044bf0c     JMP        LAB_0044bf11
    //                               LAB_0044bf0e                                                 XREF[1]:     0044bf06(j)  
    //         0044bf0e     MOV        byte ptr [ESI],0xff
    //                               LAB_0044bf11                                                 XREF[4]:     0044becb(j), 0044bed6(j), 
    //                                                                                                         0044bef7(j), 0044bf0c(j)  
    //                              fractal.cpp:479 (84)
    //         0044bf11     MOV        EDX,dword ptr [ESP + local_4]
    //         0044bf15     LEA        EAX,[EDX + EBX*0x1]
    //         0044bf18     MOV        EDX,dword ptr [ECX + this->ProbabilityAdd]
    //         0044bf1e     CMP        EAX,0x1
    //         0044bf21     JL         LAB_0044bf65
    //         0044bf23     MOV        ESI,dword ptr [ECX + this->SizeArrays]
    //         0044bf29     DEC        ESI
    //         0044bf2a     CMP        EAX,ESI
    //         0044bf2c     JGE        LAB_0044bf65
    //         0044bf2e     MOV        ESI,dword ptr [ECX + this->ProbArray]
    //         0044bf34     ADD        ESI,EAX
    //         0044bf36     MOV        AL,byte ptr [ESI]
    //         0044bf38     TEST       AL,AL
    //         0044bf3a     JNZ        LAB_0044bf4d
    //         0044bf3c     MOV        byte ptr [ESI],DL
    //         0044bf3e     MOV        EAX,dword ptr [ECX + this->ProbabilityTiles]
    //         0044bf44     INC        EAX
    //         0044bf45     MOV        dword ptr [ECX + this->ProbabilityTiles],EAX
    //         0044bf4b     JMP        LAB_0044bf65
    //                               LAB_0044bf4d                                                 XREF[1]:     0044bf3a(j)  
    //         0044bf4d     MOVSX      EDI,AL
    //         0044bf50     MOV        EBP,EDX
    //         0044bf52     ADD        EBP,EDI
    //         0044bf54     CMP        EBP,0xff
    //         0044bf5a     JGE        LAB_0044bf62
    //         0044bf5c     ADD        DL,AL
    //         0044bf5e     MOV        byte ptr [ESI],DL
    //         0044bf60     JMP        LAB_0044bf65
    //                               LAB_0044bf62                                                 XREF[1]:     0044bf5a(j)  
    //         0044bf62     MOV        byte ptr [ESI],0xff
    //                               LAB_0044bf65                                                 XREF[4]:     0044bf21(j), 0044bf2c(j), 
    //                                                                                                         0044bf4b(j), 0044bf60(j)  
    //                              fractal.cpp:480 (23)
    //         0044bf65     MOV        EDX,dword ptr [ECX + this->Width]
    //         0044bf6b     MOV        EAX,dword ptr [ESP + param_2]
    //         0044bf6f     ADD        EBX,EDX
    //         0044bf71     DEC        EAX
    //         0044bf72     MOV        dword ptr [ESP + param_2],EAX
    //         0044bf76     JNZ        LAB_0044bec2
    //                               LAB_0044bf7c                                                 XREF[4]:     0044bdbe(j), 0044bdc6(j), 
    //                                                                                                         0044beac(j), 0044beb7(j)  
    //                              fractal.cpp:482 (8)
    //         0044bf7c     POP        EDI
    //         0044bf7d     POP        ESI
    //         0044bf7e     POP        EBP
    //         0044bf7f     POP        EBX
    //         0044bf80     POP        this
    //         0044bf81     RET        0x10
    //         0044bf84     ??         90h
    //         0044bf85     NOP
    //         0044bf86     NOP
    //         0044bf87     NOP
    //         0044bf88     NOP
    //         0044bf89     NOP
    //         0044bf8a     NOP
    //         0044bf8b     NOP
    //         0044bf8c     NOP
    //         0044bf8d     NOP
    //         0044bf8e     NOP
    //         0044bf8f     NOP
    return;
}

void PointMaker::AddingCircle(int param_1, int param_2, int param_3) {
    /* TODO: Stub */
    //                              void __thiscall AddingCircle(PointMaker * this, int param_1, int par
    //              void              <VOID>         <RETURN>
    //              PointMaker *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1
    //              int               Stack[0x8]:4   param_2
    //              int               Stack[0xc]:4   param_3                   XREF[8]:     0044bf90(R), 0044bfa6(W), 0044bfbf(R), 0044bfc3(W), 
    //                                                                                     0044bfe8(R), 0044c003(R), 0044c0b4(R), 0044c0fb(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0044bfd9(W), 0044c192(R)  
    //              int               Stack[-0x8]:4  step                      XREF[2]:     0044c0f2(W), 0044c137(R)  
    //              float             Stack[-0xc]:4  x                         XREF[4]:     0044c0c2(W), 0044c0e8(R), 0044c121(W), 0044c125(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[3]:     0044bfbb(W), 0044c01d(R), 0044c133(R)  
    //              float             Stack[-0x14]:4 W                         XREF[3]:     0044bfcf(W), 0044c00e(R), 0044c082(W)  
    //              float             Stack[-0x18]:4 lasty                     XREF[3]:     0044bfc7(W), 0044bfff(R), 0044c08b(W)  
    //              float             Stack[-0x1c]:4 lastx                     XREF[8]:     0044bff2(W), 0044bffb(R), 0044c023(R), 0044c079(R), 
    //                                                                                     0044c0e0(W), 0044c0e4(R), 0044c109(W), 0044c129(R)  
    //              float             Stack[-0x20]:4 curx
    //                               ?AddingCircle@PointMaker@@IAEXHHH@Z                          XREF[1]:     DrawCurrentSatelliteIntoProbArray:
    //                               PointMaker::AddingCircle
    //                              fractal.cpp:486 (26)
    //         0044bf90     MOV        EAX,dword ptr [ESP + param_3]
    //         0044bf94     SUB        ESP,0x1c
    //         0044bf97     TEST       EAX,EAX
    //         0044bf99     PUSH       EBX
    //         0044bf9a     PUSH       EBP
    //         0044bf9b     PUSH       ESI
    //         0044bf9c     PUSH       EDI
    //         0044bf9d     MOV        ESI,this
    //         0044bf9f     JNZ        LAB_0044bfaa
    //         0044bfa1     MOV        EAX,0x1
    //         0044bfa6     MOV        dword ptr [ESP + param_3],EAX
    //                               LAB_0044bfaa                                                 XREF[1]:     0044bf9f(j)  
    //                              fractal.cpp:488 (21)
    //         0044bfaa     LEA        this,[EAX + EAX*0x2]
    //         0044bfad     MOV        EAX,0x168
    //         0044bfb2     CDQ
    //         0044bfb3     FILD       dword ptr [ESI + 0xfd4]
    //         0044bfb9     IDIV       this
    //         0044bfbb     FSTP       float ptr [ESP + local_10]
    //                              fractal.cpp:492 (60)
    //         0044bfbf     FILD       dword ptr [ESP + param_3]
    //         0044bfc3     FSTP       float ptr [ESP + param_3]
    //         0044bfc7     MOV        dword ptr [ESP + lasty],0x0
    //         0044bfcf     MOV        dword ptr [ESP + W],0x0
    //         0044bfd7     XOR        EDI,EDI
    //         0044bfd9     MOV        dword ptr [ESP + local_4],EAX
    //                               LAB_0044bfdd                                                 XREF[1]:     0044c19c(j)  
    //         0044bfdd     PUSH       EDI
    //         0044bfde     MOV        this,trig
    //         0044bfe3     CALL       TRIGONOMETRY::sin360                             float sin360(TRIGONOMETRY * this, int param_1)
    //         0044bfe8     FMUL       float ptr [ESP + param_3]
    //         0044bfec     PUSH       EDI
    //         0044bfed     MOV        this,trig
    //         0044bff2     FSTP       float ptr [ESP + lastx]
    //         0044bff6     CALL       TRIGONOMETRY::cos360                             float cos360(TRIGONOMETRY * this, int param_1)
    //                              fractal.cpp:493 (34)
    //         0044bffb     FLD        float ptr [ESP + lastx]
    //         0044bfff     FCOMP      float ptr [ESP + lasty]
    //         0044c003     FMUL       float ptr [ESP + param_3]
    //         0044c007     FNSTSW     AX
    //         0044c009     TEST       AH,0x40
    //         0044c00c     JZ         LAB_0044c01d
    //         0044c00e     FCOM       float ptr [ESP + W]
    //         0044c012     FNSTSW     AX
    //         0044c014     TEST       AH,0x40
    //         0044c017     JNZ        LAB_0044c190
    //                               LAB_0044c01d                                                 XREF[1]:     0044c00c(j)  
    //                              fractal.cpp:495 (92)
    //         0044c01d     FLD        float ptr [ESP + local_10]
    //         0044c021     FMUL       ST1
    //         0044c023     FADD       float ptr [ESP + lastx]
    //         0044c027     CALL       __ftol                                           undefined __ftol()
    //         0044c02c     MOV        EDX,dword ptr [ESI + 0xff4]
    //         0044c032     CMP        EAX,0x1
    //         0044c035     JL         LAB_0044c079
    //         0044c037     MOV        this,dword ptr [ESI + 0x1004]
    //         0044c03d     DEC        this
    //         0044c03e     CMP        EAX,this
    //         0044c040     JGE        LAB_0044c079
    //         0044c042     MOV        this,dword ptr [ESI + 0x1024]
    //         0044c048     ADD        EAX,this
    //         0044c04a     MOV        this,byte ptr [EAX]
    //         0044c04c     TEST       this,this
    //         0044c04e     JNZ        LAB_0044c061
    //         0044c050     MOV        byte ptr [EAX],DL
    //         0044c052     MOV        EAX,dword ptr [ESI + 0xfec]
    //         0044c058     INC        EAX
    //         0044c059     MOV        dword ptr [ESI + 0xfec],EAX
    //         0044c05f     JMP        LAB_0044c079
    //                               LAB_0044c061                                                 XREF[1]:     0044c04e(j)  
    //         0044c061     MOVSX      EBX,this
    //         0044c064     MOV        EBP,EDX
    //         0044c066     ADD        EBP,EBX
    //         0044c068     CMP        EBP,0xff
    //         0044c06e     JGE        LAB_0044c076
    //         0044c070     ADD        DL,this
    //         0044c072     MOV        byte ptr [EAX],DL
    //         0044c074     JMP        LAB_0044c079
    //                               LAB_0044c076                                                 XREF[1]:     0044c06e(j)  
    //         0044c076     MOV        byte ptr [EAX],0xff
    //                               LAB_0044c079                                                 XREF[4]:     0044c035(j), 0044c040(j), 
    //                                                                                                         0044c05f(j), 0044c074(j)  
    //                              fractal.cpp:496 (4)
    //         0044c079     MOV        EDX,dword ptr [ESP + lastx]
    //                              fractal.cpp:497 (44)
    //         0044c07d     PUSH       0x1f1
    //         0044c082     FSTP       float ptr [ESP + W]
    //         0044c086     PUSH       s_C:\msdev\work\age1_x1\fractal.cp               = "C:\\msdev\\work\\age1_x1\\fractal.cpp"
    //         0044c08b     MOV        dword ptr [ESP + lasty],EDX
    //         0044c08f     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         0044c094     CDQ
    //         0044c095     XOR        EAX,EDX
    //         0044c097     ADD        ESP,0x8
    //         0044c09a     SUB        EAX,EDX
    //         0044c09c     AND        EAX,0x1
    //         0044c09f     XOR        EAX,EDX
    //         0044c0a1     SUB        EAX,EDX
    //         0044c0a3     JZ         LAB_0044c192
    //                              fractal.cpp:499 (42)
    //         0044c0a9     PUSH       EDI
    //         0044c0aa     MOV        this,trig
    //         0044c0af     CALL       TRIGONOMETRY::sin360                             float sin360(TRIGONOMETRY * this, int param_1)
    //         0044c0b4     FMUL       float ptr [ESP + param_3]
    //         0044c0b8     PUSH       0x1f3
    //         0044c0bd     PUSH       s_C:\msdev\work\age1_x1\fractal.cp               = "C:\\msdev\\work\\age1_x1\\fractal.cpp"
    //         0044c0c2     FSTP       float ptr [ESP + x]
    //         0044c0c6     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         0044c0cb     CDQ
    //         0044c0cc     XOR        EAX,EDX
    //         0044c0ce     ADD        ESP,0x8
    //         0044c0d1     SUB        EAX,EDX
    //                              fractal.cpp:500 (96)
    //         0044c0d3     MOV        this,trig
    //         0044c0d8     AND        EAX,0x1
    //         0044c0db     PUSH       EDI
    //         0044c0dc     XOR        EAX,EDX
    //         0044c0de     SUB        EAX,EDX
    //         0044c0e0     MOV        dword ptr [ESP + lastx],EAX
    //         0044c0e4     FILD       dword ptr [ESP + lastx]
    //         0044c0e8     FADD       float ptr [ESP + x]
    //         0044c0ec     FSUB       float ptr [DAT_00570440]
    //         0044c0f2     FSTP       float ptr [ESP + step]
    //         0044c0f6     CALL       TRIGONOMETRY::cos360                             float cos360(TRIGONOMETRY * this, int param_1)
    //         0044c0fb     FMUL       float ptr [ESP + param_3]
    //         0044c0ff     PUSH       0x1f4
    //         0044c104     PUSH       s_C:\msdev\work\age1_x1\fractal.cp               = "C:\\msdev\\work\\age1_x1\\fractal.cpp"
    //         0044c109     FSTP       float ptr [ESP + lastx]
    //         0044c10d     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //         0044c112     CDQ
    //         0044c113     XOR        EAX,EDX
    //         0044c115     ADD        ESP,0x8
    //         0044c118     SUB        EAX,EDX
    //         0044c11a     AND        EAX,0x1
    //         0044c11d     XOR        EAX,EDX
    //         0044c11f     SUB        EAX,EDX
    //         0044c121     MOV        dword ptr [ESP + x],EAX
    //         0044c125     FILD       dword ptr [ESP + x]
    //         0044c129     FADD       float ptr [ESP + lastx]
    //         0044c12d     FSUB       float ptr [DAT_00570440]
    //                              fractal.cpp:501 (91)
    //         0044c133     FMUL       float ptr [ESP + local_10]
    //         0044c137     FADD       float ptr [ESP + step]
    //         0044c13b     CALL       __ftol                                           undefined __ftol()
    //         0044c140     MOV        this,dword ptr [ESI + 0xff4]
    //         0044c146     INC        this
    //         0044c147     CMP        EAX,0x1
    //         0044c14a     JL         LAB_0044c192
    //         0044c14c     MOV        EDX,dword ptr [ESI + 0x1004]
    //         0044c152     DEC        EDX
    //         0044c153     CMP        EAX,EDX
    //         0044c155     JGE        LAB_0044c192
    //         0044c157     MOV        EDX,dword ptr [ESI + 0x1024]
    //         0044c15d     ADD        EAX,EDX
    //         0044c15f     MOV        DL,byte ptr [EAX]
    //         0044c161     TEST       DL,DL
    //         0044c163     JNZ        LAB_0044c176
    //         0044c165     MOV        byte ptr [EAX],this
    //         0044c167     MOV        EAX,dword ptr [ESI + 0xfec]
    //         0044c16d     INC        EAX
    //         0044c16e     MOV        dword ptr [ESI + 0xfec],EAX
    //         0044c174     JMP        LAB_0044c192
    //                               LAB_0044c176                                                 XREF[1]:     0044c163(j)  
    //         0044c176     MOVSX      EBX,DL
    //         0044c179     MOV        EBP,this
    //         0044c17b     ADD        EBP,EBX
    //         0044c17d     CMP        EBP,0xff
    //         0044c183     JGE        LAB_0044c18b
    //         0044c185     ADD        this,DL
    //         0044c187     MOV        byte ptr [EAX],this
    //         0044c189     JMP        LAB_0044c192
    //                               LAB_0044c18b                                                 XREF[1]:     0044c183(j)  
    //         0044c18b     MOV        byte ptr [EAX],0xff
    //                              fractal.cpp:493 (4)
    //         0044c18e     JMP        LAB_0044c192
    //                               LAB_0044c190                                                 XREF[1]:     0044c017(j)  
    //         0044c190     FSTP       ST0
    //                               LAB_0044c192                                                 XREF[6]:     0044c0a3(j), 0044c14a(j), 
    //                                                                                                         0044c155(j), 0044c174(j), 
    //                                                                                                         0044c189(j), 0044c18e(j)  
    //                              fractal.cpp:489 (16)
    //         0044c192     ADD        EDI,dword ptr [ESP + local_4]
    //         0044c196     CMP        EDI,0x168
    //         0044c19c     JL         LAB_0044bfdd
    //                              fractal.cpp:504 (10)
    //         0044c1a2     POP        EDI
    //         0044c1a3     POP        ESI
    //         0044c1a4     POP        EBP
    //         0044c1a5     POP        EBX
    //         0044c1a6     ADD        ESP,0x1c
    //         0044c1a9     RET        0xc
    //         0044c1ac     ??         90h
    //         0044c1ad     NOP
    //         0044c1ae     NOP
    //         0044c1af     NOP
    return;
}

void PointMaker::CreateMapBasedOnProbabilityArray() {
    /* TODO: Stub */
    //                              void __thiscall CreateMapBasedOnProbabilityArray(PointMaker * this)
    //              void              <VOID>         <RETURN>
    //              PointMaker *      ECX:4 (auto)   this
    //                               ?CreateMapBasedOnProbabilityArray@PointMaker@@IAEXXZ         XREF[2]:     CreateShape:0044b457(c), 
    //                               PointMaker::CreateMapBasedOnProbabilityArray                              CreateShape:0044b51b(c)  
    //                              fractal.cpp:519 (1)
    //         0044c1b0     PUSH       ESI
    //                              fractal.cpp:521 (14)
    //         0044c1b1     MOV        ESI,dword ptr [ECX + this->SizeArrays]
    //         0044c1b7     XOR        EDX,EDX
    //         0044c1b9     XOR        EAX,EAX
    //         0044c1bb     TEST       ESI,ESI
    //         0044c1bd     JLE        LAB_0044c1e1
    //                               LAB_0044c1bf                                                 XREF[1]:     0044c1df(j)  
    //                              fractal.cpp:522 (12)
    //         0044c1bf     MOV        ESI,dword ptr [ECX + this->ProbArray]
    //         0044c1c5     CMP        byte ptr [EAX + ESI*0x1],0x0
    //         0044c1c9     JZ         LAB_0044c1d6
    //                              fractal.cpp:526 (22)
    //         0044c1cb     MOV        ESI,dword ptr [ECX + this->PlacementArray]
    //         0044c1d1     INC        EDX
    //         0044c1d2     MOV        byte ptr [ESI + EAX*0x1],0x1
    //                               LAB_0044c1d6                                                 XREF[1]:     0044c1c9(j)  
    //         0044c1d6     MOV        ESI,dword ptr [ECX + this->SizeArrays]
    //         0044c1dc     INC        EAX
    //         0044c1dd     CMP        EAX,ESI
    //         0044c1df     JL         LAB_0044c1bf
    //                               LAB_0044c1e1                                                 XREF[1]:     0044c1bd(j)  
    //                              fractal.cpp:528 (6)
    //         0044c1e1     MOV        EAX,dword ptr [ECX + this->NumTilesActuallyCho
    //                              fractal.cpp:529 (10)
    //         0044c1e7     POP        ESI
    //         0044c1e8     ADD        EAX,EDX
    //         0044c1ea     MOV        dword ptr [ECX + this->NumTilesActuallyChosen]
    //         0044c1f0     RET
    //         0044c1f1     ??         90h
    //         0044c1f2     NOP
    //         0044c1f3     NOP
    //         0044c1f4     NOP
    //         0044c1f5     NOP
    //         0044c1f6     NOP
    //         0044c1f7     NOP
    //         0044c1f8     NOP
    //         0044c1f9     NOP
    //         0044c1fa     NOP
    //         0044c1fb     NOP
    //         0044c1fc     NOP
    //         0044c1fd     NOP
    //         0044c1fe     NOP
    //         0044c1ff     NOP
    return;
}

void PointMaker::SetPoint(int param_1, int param_2) {
    /* TODO: Stub */
    //                              void __thiscall SetPoint(PointMaker * this, int param_1, int param_2)
    //              void              <VOID>         <RETURN>
    //              PointMaker *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0044c200(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0044c204(R)  
    //                               ?SetPoint@PointMaker@@QAEXHH@Z
    //                               PointMaker::SetPoint
    //                              fractal.cpp:533 (20)
    //         0044c200     MOV        EAX,dword ptr [ESP + param_1]
    //         0044c204     MOV        EDX,dword ptr [ESP + param_2]
    //         0044c208     MOV        dword ptr [ECX + this->x],EAX
    //         0044c20e     MOV        dword ptr [ECX + this->y],EDX
    //                              fractal.cpp:535 (3)
    //         0044c214     RET        0x8
    //         0044c217     ??         90h
    //         0044c218     NOP
    //         0044c219     NOP
    //         0044c21a     NOP
    //         0044c21b     NOP
    //         0044c21c     NOP
    //         0044c21d     NOP
    //         0044c21e     NOP
    //         0044c21f     NOP
    return;
}

void PointMaker::SetMaxNumberOfBranches(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall SetMaxNumberOfBranches(PointMaker * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              PointMaker *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0044c220(R)  
    //                               ?SetMaxNumberOfBranches@PointMaker@@QAEXH@Z
    //                               PointMaker::SetMaxNumberOfBranches
    //                              fractal.cpp:538 (10)
    //         0044c220     MOV        EAX,dword ptr [ESP + param_1]
    //         0044c224     MOV        dword ptr [ECX + this->MaxNumberOfBranches],EAX
    //                              fractal.cpp:540 (3)
    //         0044c22a     RET        0x4
    //         0044c22d     ??         90h
    //         0044c22e     NOP
    //         0044c22f     NOP
    return;
}

void PointMaker::SetChanceOfNextNode(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall SetChanceOfNextNode(PointMaker * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              PointMaker *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0044c230(R)  
    //                               ?SetChanceOfNextNode@PointMaker@@QAEXH@Z
    //                               PointMaker::SetChanceOfNextNode
    //                              fractal.cpp:543 (10)
    //         0044c230     MOV        EAX,dword ptr [ESP + param_1]
    //         0044c234     MOV        dword ptr [ECX + this->ChanceOfNextNode],EAX
    //                              fractal.cpp:545 (3)
    //         0044c23a     RET        0x4
    //         0044c23d     ??         90h
    //         0044c23e     NOP
    //         0044c23f     NOP
    return;
}

void PointMaker::SetNumberOfSatellites(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall SetNumberOfSatellites(PointMaker * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              PointMaker *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0044c240(R)  
    //                               ?SetNumberOfSatellites@PointMaker@@QAEXH@Z
    //                               PointMaker::SetNumberOfSatellites
    //                              fractal.cpp:548 (10)
    //         0044c240     MOV        EAX,dword ptr [ESP + param_1]
    //         0044c244     MOV        dword ptr [ECX + this->NumberOfSatellites],EAX
    //                              fractal.cpp:550 (3)
    //         0044c24a     RET        0x4
    //         0044c24d     ??         90h
    //         0044c24e     NOP
    //         0044c24f     NOP
    return;
}

void PointMaker::SetSplitsPerBranch(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall SetSplitsPerBranch(PointMaker * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              PointMaker *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0044c250(R)  
    //                               ?SetSplitsPerBranch@PointMaker@@QAEXH@Z
    //                               PointMaker::SetSplitsPerBranch
    //                              fractal.cpp:553 (10)
    //         0044c250     MOV        EAX,dword ptr [ESP + param_1]
    //         0044c254     MOV        dword ptr [ECX + this->NumSplitsPerBranch],EAX
    //                              fractal.cpp:555 (3)
    //         0044c25a     RET        0x4
    //         0044c25d     ??         90h
    //         0044c25e     NOP
    //         0044c25f     NOP
    return;
}

void PointMaker::SetWidthAndHeight(int param_1, int param_2) {
    /* TODO: Stub */
    //                              void __thiscall SetWidthAndHeight(PointMaker * this, int param_1, in
    //              void              <VOID>         <RETURN>
    //              PointMaker *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0044c260(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0044c264(R)  
    //                               ?SetWidthAndHeight@PointMaker@@QAEXHH@Z
    //                               PointMaker::SetWidthAndHeight
    //                              fractal.cpp:558 (20)
    //         0044c260     MOV        EAX,dword ptr [ESP + param_1]
    //         0044c264     MOV        EDX,dword ptr [ESP + param_2]
    //         0044c268     MOV        dword ptr [ECX + this->Width],EAX
    //         0044c26e     MOV        dword ptr [ECX + this->Height],EDX
    //                              fractal.cpp:560 (3)
    //         0044c274     RET        0x8
    //         0044c277     ??         90h
    //         0044c278     NOP
    //         0044c279     NOP
    //         0044c27a     NOP
    //         0044c27b     NOP
    //         0044c27c     NOP
    //         0044c27d     NOP
    //         0044c27e     NOP
    //         0044c27f     NOP
    return;
}

void PointMaker::SetStartPositionRadius(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall SetStartPositionRadius(PointMaker * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              PointMaker *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0044c280(R)  
    //                               ?SetStartPositionRadius@PointMaker@@QAEXH@Z
    //                               PointMaker::SetStartPositionRadius
    //                              fractal.cpp:563 (10)
    //         0044c280     MOV        EAX,dword ptr [ESP + param_1]
    //         0044c284     MOV        dword ptr [ECX + this->PrimaryRadius],EAX
    //                              fractal.cpp:565 (3)
    //         0044c28a     RET        0x4
    //         0044c28d     ??         90h
    //         0044c28e     NOP
    //         0044c28f     NOP
    return;
}

void PointMaker::SetBranchsRadius(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall SetBranchsRadius(PointMaker * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              PointMaker *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0044c290(R)  
    //                               ?SetBranchsRadius@PointMaker@@QAEXH@Z
    //                               PointMaker::SetBranchsRadius
    //                              fractal.cpp:568 (10)
    //         0044c290     MOV        EAX,dword ptr [ESP + param_1]
    //         0044c294     MOV        dword ptr [ECX + this->BranchRadius],EAX
    //                              fractal.cpp:570 (3)
    //         0044c29a     RET        0x4
    //         0044c29d     ??         90h
    //         0044c29e     NOP
    //         0044c29f     NOP
    return;
}

void PointMaker::SetSatelliteRadius(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall SetSatelliteRadius(PointMaker * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              PointMaker *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0044c2a0(R)  
    //                               ?SetSatelliteRadius@PointMaker@@QAEXH@Z
    //                               PointMaker::SetSatelliteRadius
    //                              fractal.cpp:573 (10)
    //         0044c2a0     MOV        EAX,dword ptr [ESP + param_1]
    //         0044c2a4     MOV        dword ptr [ECX + this->SatelliteRadius],EAX
    //                              fractal.cpp:575 (3)
    //         0044c2aa     RET        0x4
    //         0044c2ad     ??         90h
    //         0044c2ae     NOP
    //         0044c2af     NOP
    return;
}

void PointMaker::SetMaxNumberOfBranchLevels(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall SetMaxNumberOfBranchLevels(PointMaker * this, int pa
    //              void              <VOID>         <RETURN>
    //              PointMaker *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0044c2b0(R)  
    //                               ?SetMaxNumberOfBranchLevels@PointMaker@@QAEXH@Z
    //                               PointMaker::SetMaxNumberOfBranchLevels
    //                              fractal.cpp:578 (20)
    //         0044c2b0     MOV        EAX,dword ptr [ESP + param_1]
    //         0044c2b4     MOV        dword ptr [ECX + this->MaxBranchFlag],0x1
    //         0044c2be     MOV        dword ptr [ECX + this->MaxNumberOfBranchLevels
    //                              fractal.cpp:581 (3)
    //         0044c2c4     RET        0x4
    //         0044c2c7     ??         90h
    //         0044c2c8     NOP
    //         0044c2c9     NOP
    //         0044c2ca     NOP
    //         0044c2cb     NOP
    //         0044c2cc     NOP
    //         0044c2cd     NOP
    //         0044c2ce     NOP
    //         0044c2cf     NOP
    return;
}

void PointMaker::SetSatelliteDistance(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall SetSatelliteDistance(PointMaker * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              PointMaker *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0044c2d0(R)  
    //                               ?SetSatelliteDistance@PointMaker@@QAEXH@Z
    //                               PointMaker::SetSatelliteDistance
    //                              fractal.cpp:584 (10)
    //         0044c2d0     MOV        EAX,dword ptr [ESP + param_1]
    //         0044c2d4     MOV        dword ptr [ECX + this->SatelliteDistance],EAX
    //                              fractal.cpp:586 (3)
    //         0044c2da     RET        0x4
    //         0044c2dd     ??         90h
    //         0044c2de     NOP
    //         0044c2df     NOP
    return;
}

void PointMaker::SetBranchDistance(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall SetBranchDistance(PointMaker * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              PointMaker *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0044c2e0(R)  
    //                               ?SetBranchDistance@PointMaker@@QAEXH@Z
    //                               PointMaker::SetBranchDistance
    //                              fractal.cpp:589 (10)
    //         0044c2e0     MOV        EAX,dword ptr [ESP + param_1]
    //         0044c2e4     MOV        dword ptr [ECX + this->BranchDistance],EAX
    //                              fractal.cpp:591 (3)
    //         0044c2ea     RET        0x4
    //         0044c2ed     ??         90h
    //         0044c2ee     NOP
    //         0044c2ef     NOP
    return;
}

void PointMaker::SetMinimumNumberOfTiles(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall SetMinimumNumberOfTiles(PointMaker * this, int param
    //              void              <VOID>         <RETURN>
    //              PointMaker *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0044c2f0(R)  
    //                               ?SetMinimumNumberOfTiles@PointMaker@@QAEXH@Z
    //                               PointMaker::SetMinimumNumberOfTiles
    //                              fractal.cpp:594 (10)
    //         0044c2f0     MOV        EAX,dword ptr [ESP + param_1]
    //         0044c2f4     MOV        dword ptr [ECX + this->MinimumNumTiles],EAX
    //                              fractal.cpp:596 (3)
    //         0044c2fa     RET        0x4
    //         0044c2fd     ??         90h
    //         0044c2fe     NOP
    //         0044c2ff     NOP
    return;
}

void PointMaker::SetDrawToOneArray() {
    /* TODO: Stub */
    //                              void __thiscall SetDrawToOneArray(PointMaker * this)
    //              void              <VOID>         <RETURN>
    //              PointMaker *      ECX:4 (auto)   this
    //                               ?SetDrawToOneArray@PointMaker@@QAEXXZ
    //                               PointMaker::SetDrawToOneArray
    //                              fractal.cpp:599 (10)
    //         0044c300     MOV        dword ptr [ECX + this->DrawToOneArrayFlag],0x1
    //                              fractal.cpp:601 (1)
    //         0044c30a     RET
    //         0044c30b     ??         90h
    //         0044c30c     NOP
    //         0044c30d     NOP
    //         0044c30e     NOP
    //         0044c30f     NOP
    return;
}

void PointMaker::SetBorderDepthPercentage(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall SetBorderDepthPercentage(PointMaker * this, int para
    //              void              <VOID>         <RETURN>
    //              PointMaker *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0044c310(R)  
    //                               ?SetBorderDepthPercentage@PointMaker@@QAEXH@Z
    //                               PointMaker::SetBorderDepthPercentage
    //                              fractal.cpp:604 (4)
    //         0044c310     MOV        EAX,dword ptr [ESP + param_1]
    //                              fractal.cpp:606 (21)
    //         0044c314     CMP        EAX,0x1e
    //         0044c317     MOV        dword ptr [ECX + this->BorderDepthPercentage],
    //         0044c31d     JLE        LAB_0044c329
    //         0044c31f     MOV        dword ptr [ECX + this->BorderDepthPercentage],
    //                               LAB_0044c329                                                 XREF[1]:     0044c31d(j)  
    //                              fractal.cpp:607 (21)
    //         0044c329     MOV        EDX,dword ptr [ECX + this->BorderDepthPercenta
    //         0044c32f     MOV        EAX,0x5
    //         0044c334     CMP        EDX,EAX
    //         0044c336     JGE        LAB_0044c33e
    //         0044c338     MOV        dword ptr [ECX + this->BorderDepthPercentage],
    //                               LAB_0044c33e                                                 XREF[1]:     0044c336(j)  
    //                              fractal.cpp:608 (5)
    //         0044c33e     CALL       PointMaker::PrepareLimits                        void PrepareLimits(PointMaker * this)
    //                              fractal.cpp:609 (3)
    //         0044c343     RET        0x4
    //         0044c346     ??         90h
    //         0044c347     NOP
    //         0044c348     NOP
    //         0044c349     NOP
    //         0044c34a     NOP
    //         0044c34b     NOP
    //         0044c34c     NOP
    //         0044c34d     NOP
    //         0044c34e     NOP
    //         0044c34f     NOP
    return;
}

char* PointMaker::RetrieveMap() {
    /* TODO: Stub */
    //                              char * __thiscall RetrieveMap(PointMaker * this)
    //              char *            EAX:4          <RETURN>
    //              PointMaker *      ECX:4 (auto)   this
    //                               ?RetrieveMap@PointMaker@@QAEPADXZ
    //                               PointMaker::RetrieveMap
    //                              fractal.cpp:613 (6)
    //         0044c350     MOV        EAX,dword ptr [ECX + this->PlacementArray]
    //                              fractal.cpp:615 (1)
    //         0044c356     RET
    //         0044c357     ??         90h
    //         0044c358     NOP
    //         0044c359     NOP
    //         0044c35a     NOP
    //         0044c35b     NOP
    //         0044c35c     NOP
    //         0044c35d     NOP
    //         0044c35e     NOP
    //         0044c35f     NOP
    return 0;
}

char* PointMaker::RetrieveProbMap() {
    /* TODO: Stub */
    //                              char * __thiscall RetrieveProbMap(PointMaker * this)
    //              char *            EAX:4          <RETURN>
    //              PointMaker *      ECX:4 (auto)   this
    //                               ?RetrieveProbMap@PointMaker@@QAEPADXZ
    //                               PointMaker::RetrieveProbMap
    //                              fractal.cpp:618 (6)
    //         0044c360     MOV        EAX,dword ptr [ECX + this->ProbArray]
    //                              fractal.cpp:620 (1)
    //         0044c366     RET
    //         0044c367     ??         90h
    //         0044c368     NOP
    //         0044c369     NOP
    //         0044c36a     NOP
    //         0044c36b     NOP
    //         0044c36c     NOP
    //         0044c36d     NOP
    //         0044c36e     NOP
    //         0044c36f     NOP
    return 0;
}

void PointMaker::ErrorCheckingAndCorrection() {
    /* TODO: Stub */
    //                              void __thiscall ErrorCheckingAndCorrection(PointMaker * this)
    //              void              <VOID>         <RETURN>
    //              PointMaker *      ECX:4 (auto)   this
    //                               ?ErrorCheckingAndCorrection@PointMaker@@IAEXXZ               XREF[2]:     CreateShape:0044b3f3(c), 
    //                               PointMaker::ErrorCheckingAndCorrection                                    CreateShape:0044b4b8(c)  
    //                              fractal.cpp:623 (1)
    //         0044c370     PUSH       ESI
    //                              fractal.cpp:624 (16)
    //         0044c371     MOV        ESI,dword ptr [ECX + this->Width]
    //         0044c377     PUSH       EDI
    //         0044c378     MOV        EDI,dword ptr [ECX + this->Height]
    //         0044c37e     IMUL       EDI,ESI
    //                              fractal.cpp:625 (39)
    //         0044c381     MOV        EAX,dword ptr [ECX + this->BranchRadius]
    //         0044c387     MOV        dword ptr [ECX + this->SizeArrays],EDI
    //         0044c38d     CMP        EAX,ESI
    //         0044c38f     JLE        LAB_0044c3a8
    //         0044c391     LEA        EDX,[ESI + ESI*0x1]
    //         0044c394     MOV        EAX,0x55555556
    //         0044c399     IMUL       EDX
    //         0044c39b     MOV        EAX,EDX
    //         0044c39d     SHR        EAX,0x1f
    //         0044c3a0     ADD        EDX,EAX
    //         0044c3a2     MOV        dword ptr [ECX + this->BranchRadius],EDX
    //                               LAB_0044c3a8                                                 XREF[1]:     0044c38f(j)  
    //                              fractal.cpp:626 (31)
    //         0044c3a8     CMP        dword ptr [ECX + this->SatelliteRadius],ESI
    //         0044c3ae     JLE        LAB_0044c3c7
    //         0044c3b0     LEA        EDX,[ESI + ESI*0x1]
    //         0044c3b3     MOV        EAX,0x55555556
    //         0044c3b8     IMUL       EDX
    //         0044c3ba     MOV        EAX,EDX
    //         0044c3bc     SHR        EAX,0x1f
    //         0044c3bf     ADD        EDX,EAX
    //         0044c3c1     MOV        dword ptr [ECX + this->SatelliteRadius],EDX
    //                               LAB_0044c3c7                                                 XREF[1]:     0044c3ae(j)  
    //                              fractal.cpp:627 (31)
    //         0044c3c7     CMP        dword ptr [ECX + this->PrimaryRadius],ESI
    //         0044c3cd     JLE        LAB_0044c3e6
    //         0044c3cf     LEA        EDX,[ESI + ESI*0x1]
    //         0044c3d2     MOV        EAX,0x55555556
    //         0044c3d7     IMUL       EDX
    //         0044c3d9     MOV        EAX,EDX
    //         0044c3db     SHR        EAX,0x1f
    //         0044c3de     ADD        EDX,EAX
    //         0044c3e0     MOV        dword ptr [ECX + this->PrimaryRadius],EDX
    //                               LAB_0044c3e6                                                 XREF[1]:     0044c3cd(j)  
    //                              fractal.cpp:628 (21)
    //         0044c3e6     MOV        EDX,dword ptr [ECX + this->NumSplitsPerBranch]
    //         0044c3ec     MOV        EAX,0x4
    //         0044c3f1     CMP        EDX,EAX
    //         0044c3f3     JLE        LAB_0044c3fb
    //         0044c3f5     MOV        dword ptr [ECX + this->NumSplitsPerBranch],EAX
    //                               LAB_0044c3fb                                                 XREF[1]:     0044c3f3(j)  
    //                              fractal.cpp:629 (14)
    //         0044c3fb     CMP        dword ptr [ECX + this->NumberOfSatellites],EAX
    //         0044c401     JLE        LAB_0044c409
    //         0044c403     MOV        dword ptr [ECX + this->NumberOfSatellites],EAX
    //                               LAB_0044c409                                                 XREF[1]:     0044c401(j)  
    //                              fractal.cpp:633 (35)
    //         0044c409     MOV        EAX,EDI
    //         0044c40b     MOV        EDI,0xa
    //         0044c410     CDQ
    //         0044c411     IDIV       dword ptr [ECX + this->MinimumNumTiles]
    //         0044c417     MOV        dword ptr [ECX + this->DrawToOneArrayFlag],0x0
    //         0044c421     MOV        ESI,EAX
    //         0044c423     MOV        EAX,EDI
    //         0044c425     SUB        EAX,ESI
    //         0044c427     LEA        EAX,[EAX + EAX*0x4]
    //         0044c42a     SHL        EAX,0x1
    //                              fractal.cpp:634 (21)
    //         0044c42c     CMP        EAX,0x23
    //         0044c42f     MOV        dword ptr [ECX + this->ChanceOfNextNode],EAX
    //         0044c435     JGE        LAB_0044c441
    //         0044c437     MOV        dword ptr [ECX + this->ChanceOfNextNode],0x23
    //                               LAB_0044c441                                                 XREF[1]:     0044c435(j)  
    //                              fractal.cpp:635 (21)
    //         0044c441     MOV        EDX,dword ptr [ECX + this->ChanceOfNextNode]
    //         0044c447     MOV        EAX,0x50
    //         0044c44c     CMP        EDX,EAX
    //         0044c44e     JLE        LAB_0044c456
    //         0044c450     MOV        dword ptr [ECX + this->ChanceOfNextNode],EAX
    //                               LAB_0044c456                                                 XREF[1]:     0044c44e(j)  
    //                              fractal.cpp:636 (10)
    //         0044c456     MOV        EAX,dword ptr [ECX + this->MaxBranchFlag]
    //         0044c45c     TEST       EAX,EAX
    //         0044c45e     JNZ        LAB_0044c47e
    //                              fractal.cpp:637 (30)
    //         0044c460     MOV        EDX,dword ptr [ECX + this->ChanceOfNextNode]
    //         0044c466     MOV        EAX,0x66666667
    //         0044c46b     IMUL       EDX
    //         0044c46d     SAR        EDX,0x1
    //         0044c46f     MOV        EAX,EDX
    //         0044c471     SHR        EAX,0x1f
    //         0044c474     ADD        EDX,EAX
    //         0044c476     SUB        ESI,EDX
    //         0044c478     MOV        dword ptr [ECX + this->MaxNumberOfBranchLevels
    //                               LAB_0044c47e                                                 XREF[1]:     0044c45e(j)  
    //                              fractal.cpp:638 (14)
    //         0044c47e     CMP        dword ptr [ECX + this->MaxNumberOfBranchLevels
    //         0044c484     JGE        LAB_0044c48c
    //         0044c486     MOV        dword ptr [ECX + this->MaxNumberOfBranchLevels
    //                               LAB_0044c48c                                                 XREF[1]:     0044c484(j)  
    //                              fractal.cpp:639 (21)
    //         0044c48c     MOV        EDX,dword ptr [ECX + this->MaxNumberOfBranchLe
    //         0044c492     MOV        EAX,0x1e
    //         0044c497     CMP        EDX,EAX
    //         0044c499     JLE        LAB_0044c4a1
    //         0044c49b     MOV        dword ptr [ECX + this->MaxNumberOfBranchLevels
    //                               LAB_0044c4a1                                                 XREF[1]:     0044c499(j)  
    //                              fractal.cpp:641 (13)
    //         0044c4a1     POP        EDI
    //         0044c4a2     MOV        dword ptr [ECX + this->MaxBranchFlag],0x0
    //         0044c4ac     POP        ESI
    //         0044c4ad     RET
    //         0044c4ae     ??         90h
    //         0044c4af     NOP
    return;
}

void PointMaker::PrepareLimits() {
    /* TODO: Stub */
    //                              void __thiscall PrepareLimits(PointMaker * this)
    //              void              <VOID>         <RETURN>
    //              PointMaker *      ECX:4 (auto)   this
    //                               ?PrepareLimits@PointMaker@@IAEXXZ                            XREF[3]:     CreateShape:0044b335(c), 
    //                               PointMaker::PrepareLimits                                                 CreateShape:0044b485(c), 
    //                                                                                                         SetBorderDepthPercentage:0044c33e(
    //                              fractal.cpp:644 (1)
    //         0044c4b0     PUSH       ESI
    //                              fractal.cpp:645 (35)
    //         0044c4b1     MOV        ESI,dword ptr [ECX + this->Width]
    //         0044c4b7     PUSH       EDI
    //         0044c4b8     MOV        EDI,dword ptr [ECX + this->BorderDepthPercenta
    //         0044c4be     MOV        EDX,EDI
    //         0044c4c0     MOV        EAX,0x51eb851f
    //         0044c4c5     IMUL       EDX,ESI
    //         0044c4c8     IMUL       EDX
    //         0044c4ca     SAR        EDX,0x5
    //         0044c4cd     MOV        EAX,EDX
    //         0044c4cf     SHR        EAX,0x1f
    //         0044c4d2     ADD        EDX,EAX
    //                              fractal.cpp:646 (37)
    //         0044c4d4     MOV        EAX,0x51eb851f
    //         0044c4d9     SUB        ESI,EDX
    //         0044c4db     MOV        dword ptr [ECX + this->LeftLimit],EDX
    //         0044c4e1     MOV        dword ptr [ECX + this->RightLimit],ESI
    //         0044c4e7     MOV        ESI,dword ptr [ECX + this->Height]
    //         0044c4ed     MOV        EDX,ESI
    //         0044c4ef     IMUL       EDX,EDI
    //         0044c4f2     IMUL       EDX
    //         0044c4f4     SAR        EDX,0x5
    //         0044c4f7     MOV        EAX,EDX
    //                              fractal.cpp:647 (22)
    //         0044c4f9     POP        EDI
    //         0044c4fa     SHR        EAX,0x1f
    //         0044c4fd     ADD        EDX,EAX
    //         0044c4ff     SUB        ESI,EDX
    //         0044c501     MOV        dword ptr [ECX + this->TopLimit],EDX
    //         0044c507     MOV        dword ptr [ECX + this->BottomLimit],ESI
    //         0044c50d     POP        ESI
    //         0044c50e     RET
    //         0044c50f     ??         90h
    return;
}

void PointMaker::MapCleanUpEliminatingSinglesOnly() {
    /* TODO: Stub */
    //                              void __thiscall MapCleanUpEliminatingSinglesOnly(PointMaker * this)
    //              void              <VOID>         <RETURN>
    //              PointMaker *      ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0044c529(W), 0044c58f(R)  
    //              int               Stack[-0x8]:4  h                         XREF[2]:     0044c52d(W), 0044c586(R)  
    //              int               Stack[-0xc]:4  w
    //                               ?MapCleanUpEliminatingSinglesOnly@PointMaker@@IAEXXZ         XREF[2]:     CreateShape:0044b45e(c), 
    //                               PointMaker::MapCleanUpEliminatingSinglesOnly                              CreateShape:0044b522(c)  
    //                              fractal.cpp:650 (3)
    //         0044c510     SUB        ESP,0x8
    //                              fractal.cpp:651 (14)
    //         0044c513     MOV        EDX,dword ptr [ECX + this->Height]
    //         0044c519     MOV        EAX,dword ptr [ECX + this->Width]
    //         0044c51f     PUSH       EBX
    //         0044c520     DEC        EDX
    //                              fractal.cpp:652 (21)
    //         0044c521     MOV        EBX,0x1
    //         0044c526     DEC        EAX
    //         0044c527     CMP        EDX,EBX
    //         0044c529     MOV        dword ptr [ESP + local_4],EDX
    //         0044c52d     MOV        dword ptr [ESP + h],EAX
    //         0044c531     JLE        LAB_0044c59b
    //         0044c533     PUSH       EDI
    //         0044c534     PUSH       ESI
    //         0044c535     PUSH       EBP
    //                               LAB_0044c536                                                 XREF[1]:     0044c596(j)  
    //                              fractal.cpp:653 (9)
    //         0044c536     MOV        EDI,0x1
    //         0044c53b     CMP        EAX,EDI
    //         0044c53d     JLE        LAB_0044c593
    //                               LAB_0044c53f                                                 XREF[1]:     0044c58d(j)  
    //                              fractal.cpp:655 (21)
    //         0044c53f     MOV        EDX,dword ptr [ECX + this->Width]
    //         0044c545     MOV        EAX,EBX
    //         0044c547     IMUL       EAX,EDX
    //         0044c54a     MOV        ESI,dword ptr [ECX + this->PlacementArray]
    //         0044c550     ADD        EAX,EDI
    //         0044c552     ADD        EAX,ESI
    //                              fractal.cpp:656 (2)
    //         0044c554     XOR        ESI,ESI
    //                              fractal.cpp:658 (15)
    //         0044c556     MOV        EBP,EAX
    //         0044c558     SUB        EBP,EDX
    //         0044c55a     CMP        byte ptr [EBP],0x0
    //         0044c55e     JLE        LAB_0044c565
    //         0044c560     MOV        ESI,0x1
    //                               LAB_0044c565                                                 XREF[1]:     0044c55e(j)  
    //                              fractal.cpp:661 (7)
    //         0044c565     CMP        byte ptr [EAX + -0x1],0x0
    //         0044c569     JLE        LAB_0044c56c
    //         0044c56b     INC        ESI
    //                               LAB_0044c56c                                                 XREF[1]:     0044c569(j)  
    //                              fractal.cpp:662 (7)
    //         0044c56c     CMP        byte ptr [EAX + 0x1],0x0
    //         0044c570     JLE        LAB_0044c573
    //         0044c572     INC        ESI
    //                               LAB_0044c573                                                 XREF[1]:     0044c570(j)  
    //                              fractal.cpp:663 (7)
    //         0044c573     CMP        byte ptr [EAX + EDX*0x1],0x0
    //         0044c577     JLE        LAB_0044c57a
    //         0044c579     INC        ESI
    //                               LAB_0044c57a                                                 XREF[1]:     0044c577(j)  
    //                              fractal.cpp:668 (12)
    //         0044c57a     CMP        byte ptr [EAX],0x0
    //         0044c57d     JZ         LAB_0044c586
    //         0044c57f     TEST       ESI,ESI
    //         0044c581     JNZ        LAB_0044c586
    //         0044c583     MOV        byte ptr [EAX],0x0
    //                               LAB_0044c586                                                 XREF[2]:     0044c57d(j), 0044c581(j)  
    //                              fractal.cpp:653 (13)
    //         0044c586     MOV        EAX,dword ptr [ESP + h]
    //         0044c58a     INC        EDI
    //         0044c58b     CMP        EDI,EAX
    //         0044c58d     JL         LAB_0044c53f
    //         0044c58f     MOV        EDX,dword ptr [ESP + local_4]
    //                               LAB_0044c593                                                 XREF[1]:     0044c53d(j)  
    //                              fractal.cpp:652 (8)
    //         0044c593     INC        EBX
    //         0044c594     CMP        EBX,EDX
    //         0044c596     JL         LAB_0044c536
    //         0044c598     POP        EBP
    //         0044c599     POP        ESI
    //         0044c59a     POP        EDI
    //                               LAB_0044c59b                                                 XREF[1]:     0044c531(j)  
    //                              fractal.cpp:670 (5)
    //         0044c59b     POP        EBX
    //         0044c59c     ADD        ESP,0x8
    //         0044c59f     RET
    return;
}

