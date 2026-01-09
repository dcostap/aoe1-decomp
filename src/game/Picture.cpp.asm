#include "common.h"
#include "Picture.h"

TPicture::TPicture(char* param_1, long param_2, int param_3, void* param_4, int param_5) {
    /* TODO: Stub */
    //                              undefined __thiscall TPicture(TPicture * this, char * param_1, long 
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TPicture *        ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     0046de0b(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     0046de06(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0046dde0(R)  
    //              void *            Stack[0x10]:4  param_4                   XREF[1]:     0046dde9(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[1]:     0046de01(R)  
    //                               ??0TPicture@@QAE@PADJHPAXH@Z                                 XREF[3]:     set_bitmap:00436a87(c), 
    //                               TPicture::TPicture                                                        load_pic:0047a53f(c), 
    //                                                                                                         save:0048c7a5(c)  
    //                              Picture.cpp:11 (63)
    //         0046dde0     MOV        EDX,dword ptr [ESP + param_3]
    //         0046dde4     PUSH       ESI
    //         0046dde5     MOV        ESI,this
    //         0046dde7     XOR        EAX,EAX
    //         0046dde9     MOV        this,dword ptr [ESP + param_4]
    //         0046dded     MOV        dword ptr [ESI],EAX
    //         0046ddef     MOV        dword ptr [ESI + 0x4],EAX
    //         0046ddf2     MOV        dword ptr [ESI + 0x8],EAX
    //         0046ddf5     MOV        dword ptr [ESI + 0xc],EAX
    //         0046ddf8     MOV        dword ptr [ESI + 0x10],EAX
    //         0046ddfb     MOV        dword ptr [ESI + 0x14],EAX
    //         0046ddfe     MOV        dword ptr [ESI + 0x18],EAX
    //         0046de01     MOV        EAX,dword ptr [ESP + param_5]
    //         0046de05     PUSH       EAX
    //         0046de06     MOV        EAX,dword ptr [ESP + param_2]
    //         0046de0a     PUSH       this
    //         0046de0b     MOV        this,dword ptr [ESP + param_1]
    //         0046de0f     PUSH       EDX
    //         0046de10     PUSH       EAX
    //         0046de11     PUSH       this
    //         0046de12     MOV        this,ESI
    //         0046de14     MOV        word ptr [ESI + 0x1c],0x1
    //         0046de1a     CALL       TPicture::Load                                   void Load(TPicture * this, char * param_1, lo
    //                              Picture.cpp:22 (6)
    //         0046de1f     MOV        EAX,ESI
    //         0046de21     POP        ESI
    //         0046de22     RET        0x14
    //         0046de25     ??         90h
    //         0046de26     NOP
    //         0046de27     NOP
    //         0046de28     NOP
    //         0046de29     NOP
    //         0046de2a     NOP
    //         0046de2b     NOP
    //         0046de2c     NOP
    //         0046de2d     NOP
    //         0046de2e     NOP
    //         0046de2f     NOP
}

TPicture::TPicture(int param_1, int param_2) {
    /* TODO: Stub */
    //                              undefined __thiscall TPicture(TPicture * this, int param_1, int para
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TPicture *        ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0046de31(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0046defb(R)  
    //                               ??0TPicture@@QAE@HH@Z                                        XREF[1]:     RGE_Scenario:0048b32d(c)  
    //                               TPicture::TPicture
    //                              Picture.cpp:25 (1)
    //         0046de30     PUSH       EBX
    //                              Picture.cpp:35 (54)
    //         0046de31     MOV        EBX,dword ptr [ESP + param_1]
    //         0046de35     PUSH       EBP
    //         0046de36     PUSH       ESI
    //         0046de37     MOV        ESI,this
    //         0046de39     PUSH       EDI
    //         0046de3a     PUSH       0x4
    //         0046de3c     XOR        EAX,EAX
    //         0046de3e     LEA        EBP,[ESI + 0x10]
    //         0046de41     LEA        EDI,[ESI + 0x18]
    //         0046de44     PUSH       EBP
    //         0046de45     PUSH       EBX
    //         0046de46     MOV        dword ptr [ESI],EAX
    //         0046de48     MOV        dword ptr [ESI + 0x4],EAX
    //         0046de4b     MOV        dword ptr [ESI + 0x8],EAX
    //         0046de4e     MOV        dword ptr [ESI + 0xc],EAX
    //         0046de51     MOV        dword ptr [EBP],EAX
    //         0046de54     MOV        dword ptr [ESI + 0x14],EAX
    //         0046de57     MOV        dword ptr [EDI],EAX
    //         0046de59     MOV        word ptr [ESI + 0x1c],0x1
    //         0046de5f     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0046de64     ADD        ESP,0xc
    //                              Picture.cpp:36 (15)
    //         0046de67     LEA        EAX,[ESI + 0x14]
    //         0046de6a     PUSH       0x4
    //         0046de6c     PUSH       EAX
    //         0046de6d     PUSH       EBX
    //         0046de6e     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0046de73     ADD        ESP,0xc
    //                              Picture.cpp:37 (12)
    //         0046de76     PUSH       0x4
    //         0046de78     PUSH       EDI
    //         0046de79     PUSH       EBX
    //         0046de7a     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         0046de7f     ADD        ESP,0xc
    //                              Picture.cpp:38 (12)
    //         0046de82     LEA        EAX,[ESI + 0x1c]
    //         0046de85     PUSH       0x2
    //         0046de87     PUSH       EAX
    //         0046de88     PUSH       EBX
    //         0046de89     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              Picture.cpp:40 (12)
    //         0046de8e     MOV        this,dword ptr [EBP]
    //         0046de91     XOR        EAX,EAX
    //         0046de93     ADD        ESP,0xc
    //         0046de96     CMP        this,EAX
    //         0046de98     JZ         LAB_0046dea1
    //                              Picture.cpp:41 (7)
    //         0046de9a     MOV        dword ptr [EBP],0x2
    //                               LAB_0046dea1                                                 XREF[1]:     0046de98(j)  
    //                              Picture.cpp:43 (9)
    //         0046dea1     CMP        dword ptr [ESI + 0x14],EAX
    //         0046dea4     JLE        LAB_0046def3
    //         0046dea6     CMP        dword ptr [EDI],EAX
    //         0046dea8     JLE        LAB_0046def3
    //                              Picture.cpp:45 (26)
    //         0046deaa     PUSH       0x1
    //         0046deac     MOV        this,ESI
    //         0046deae     CALL       TPicture::AlignedWidth                           long AlignedWidth(TPicture * this)
    //         0046deb3     IMUL       EAX,dword ptr [EDI]
    //         0046deb6     ADD        EAX,0x428
    //         0046debb     PUSH       EAX
    //         0046debc     CALL       calloc                                           undefined calloc()
    //         0046dec1     ADD        ESP,0x8
    //                              Picture.cpp:46 (27)
    //         0046dec4     MOV        this,ESI
    //         0046dec6     MOV        dword ptr [ESI],EAX
    //         0046dec8     CALL       TPicture::AlignedWidth                           long AlignedWidth(TPicture * this)
    //         0046decd     IMUL       EAX,dword ptr [EDI]
    //         0046ded0     ADD        EAX,0x428
    //         0046ded5     PUSH       EAX
    //         0046ded6     MOV        EAX,dword ptr [ESI]
    //         0046ded8     PUSH       EAX
    //         0046ded9     PUSH       EBX
    //         0046deda     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              Picture.cpp:48 (8)
    //         0046dedf     MOV        EAX,dword ptr [ESI]
    //         0046dee1     ADD        ESP,0xc
    //         0046dee4     MOV        dword ptr [ESI + 0x4],EAX
    //                              Picture.cpp:49 (8)
    //         0046dee7     ADD        EAX,0x428
    //         0046deec     MOV        dword ptr [ESI + 0x8],EAX
    //                              Picture.cpp:51 (4)
    //         0046deef     XOR        EAX,EAX
    //         0046def1     JMP        LAB_0046defb
    //                               LAB_0046def3                                                 XREF[2]:     0046dea4(j), 0046dea8(j)  
    //                              Picture.cpp:53 (2)
    //         0046def3     MOV        dword ptr [ESI],EAX
    //                              Picture.cpp:54 (3)
    //         0046def5     MOV        dword ptr [ESI + 0x4],EAX
    //                              Picture.cpp:55 (3)
    //         0046def8     MOV        dword ptr [ESI + 0x8],EAX
    //                               LAB_0046defb                                                 XREF[1]:     0046def1(j)  
    //                              Picture.cpp:60 (23)
    //         0046defb     MOV        this,dword ptr [ESP + param_2]
    //         0046deff     MOV        dword ptr [ESI + 0xc],EAX
    //         0046df02     CMP        this,EAX
    //         0046df04     JZ         LAB_0046df95
    //         0046df0a     CMP        dword ptr [ESI],EAX
    //         0046df0c     JZ         LAB_0046df95
    //                              Picture.cpp:62 (13)
    //         0046df12     PUSH       0x18
    //         0046df14     CALL       malloc                                           undefined malloc()
    //         0046df19     ADD        ESP,0x4
    //         0046df1c     MOV        dword ptr [ESI + 0xc],EAX
    //                              Picture.cpp:63 (4)
    //         0046df1f     TEST       EAX,EAX
    //         0046df21     JZ         LAB_0046df63
    //                              Picture.cpp:64 (25)
    //         0046df23     MOV        this,dword ptr [ESI]
    //         0046df25     CMP        dword ptr [ECX + this->OwnMemory],0x3
    //         0046df29     JNZ        LAB_0046df45
    //         0046df2b     MOV        EDX,dword ptr [this->Dib]
    //         0046df2d     LEA        EDX,[EDX + this->Dib*0x1 + 0xc]
    //         0046df31     PUSH       EDX
    //         0046df32     PUSH       EAX
    //         0046df33     PUSH       this
    //         0046df34     CALL       DibCheckTrans                                    int DibCheckTrans(BITMAPINFO256 * param_1, TR
    //         0046df39     ADD        ESP,0xc
    //                              Picture.cpp:76 (9)
    //         0046df3c     MOV        EAX,ESI
    //         0046df3e     POP        EDI
    //         0046df3f     POP        ESI
    //         0046df40     POP        EBP
    //         0046df41     POP        EBX
    //         0046df42     RET        0x8
    //                               LAB_0046df45                                                 XREF[1]:     0046df29(j)  
    //                              Picture.cpp:64 (21)
    //         0046df45     MOV        EDX,dword ptr [ECX + this+0x20]
    //         0046df48     MOV        EDI,dword ptr [this->Dib]
    //         0046df4a     LEA        EDX,[EDI + EDX*0x4]
    //         0046df4d     ADD        EDX,this
    //         0046df4f     PUSH       EDX
    //         0046df50     PUSH       EAX
    //         0046df51     PUSH       this
    //         0046df52     CALL       DibCheckTrans                                    int DibCheckTrans(BITMAPINFO256 * param_1, TR
    //         0046df57     ADD        ESP,0xc
    //                              Picture.cpp:76 (9)
    //         0046df5a     MOV        EAX,ESI
    //         0046df5c     POP        EDI
    //         0046df5d     POP        ESI
    //         0046df5e     POP        EBP
    //         0046df5f     POP        EBX
    //         0046df60     RET        0x8
    //                               LAB_0046df63                                                 XREF[1]:     0046df21(j)  
    //                              Picture.cpp:67 (11)
    //         0046df63     MOV        EAX,dword ptr [ESI]
    //         0046df65     PUSH       EAX
    //         0046df66     CALL       DibFree                                          void DibFree(tagBITMAPINFOHEADER * param_1)
    //         0046df6b     ADD        ESP,0x4
    //                              Picture.cpp:68 (6)
    //         0046df6e     MOV        dword ptr [ESI],0x0
    //                              Picture.cpp:69 (7)
    //         0046df74     MOV        dword ptr [ESI + 0x4],0x0
    //                              Picture.cpp:70 (7)
    //         0046df7b     MOV        dword ptr [EBP],0x0
    //                              Picture.cpp:71 (7)
    //         0046df82     MOV        dword ptr [ESI + 0x14],0x0
    //                              Picture.cpp:72 (6)
    //         0046df89     MOV        dword ptr [EDI],0x0
    //                              Picture.cpp:73 (6)
    //         0046df8f     MOV        word ptr [ESI + 0x1c],0x1
    //                               LAB_0046df95                                                 XREF[2]:     0046df04(j), 0046df0c(j)  
    //                              Picture.cpp:76 (9)
    //         0046df95     MOV        EAX,ESI
    //         0046df97     POP        EDI
    //         0046df98     POP        ESI
    //         0046df99     POP        EBP
    //         0046df9a     POP        EBX
    //         0046df9b     RET        0x8
    //         0046df9e     ??         90h
    //         0046df9f     NOP
}

TPicture::TPicture() {
    /* TODO: Stub */
    //                              undefined __thiscall TPicture(TPicture * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TPicture *        ECX:4 (auto)   this
    //                               ??0TPicture@@QAE@XZ
    //                               TPicture::TPicture
    //                              Picture.cpp:79 (2)
    //         0046dfa0     MOV        EAX,this
    //                              Picture.cpp:80 (4)
    //         0046dfa2     XOR        this,this
    //         0046dfa4     MOV        dword ptr [EAX],this
    //                              Picture.cpp:81 (3)
    //         0046dfa6     MOV        dword ptr [EAX + 0x4],this
    //                              Picture.cpp:82 (3)
    //         0046dfa9     MOV        dword ptr [EAX + 0x8],this
    //                              Picture.cpp:83 (3)
    //         0046dfac     MOV        dword ptr [EAX + 0xc],this
    //                              Picture.cpp:84 (3)
    //         0046dfaf     MOV        dword ptr [EAX + 0x10],this
    //                              Picture.cpp:85 (3)
    //         0046dfb2     MOV        dword ptr [EAX + 0x14],this
    //                              Picture.cpp:86 (3)
    //         0046dfb5     MOV        dword ptr [EAX + 0x18],this
    //                              Picture.cpp:87 (6)
    //         0046dfb8     MOV        word ptr [EAX + 0x1c],0x1
    //                              Picture.cpp:88 (1)
    //         0046dfbe     RET
    //         0046dfbf     ??         90h
}

TPicture::~TPicture() {
    /* TODO: Stub */
    //                              void __thiscall ~TPicture(TPicture * this)
    //              void              <VOID>         <RETURN>
    //              TPicture *        ECX:4 (auto)   this
    //                               ??1TPicture@@QAE@XZ                                          XREF[7]:     set_bitmap:00436ab4(c), 
    //                               TPicture::~TPicture                                                       set_bitmap:00436bf3(c), 
    //                                                                                                         load_pic:0047a586(c), 
    //                                                                                                         free_pic:0047a5ce(c), 
    //                                                                                                         ~RGE_Scenario:0048b638(c), 
    //                                                                                                         save:0048c7cc(c), 
    //                                                                                                         save:0048c7e2(c)  
    //                              Picture.cpp:91 (3)
    //         0046dfc0     PUSH       ESI
    //         0046dfc1     MOV        ESI,this
    //                              Picture.cpp:92 (7)
    //         0046dfc3     MOV        EAX,dword ptr [ESI + 0x10]
    //         0046dfc6     TEST       EAX,EAX
    //         0046dfc8     JZ         LAB_0046e013
    //                              Picture.cpp:94 (7)
    //         0046dfca     MOV        EAX,dword ptr [ESI + 0xc]
    //         0046dfcd     TEST       EAX,EAX
    //         0046dfcf     JZ         LAB_0046dff2
    //                              Picture.cpp:96 (12)
    //         0046dfd1     MOV        this,dword ptr [EAX + 0x14]
    //         0046dfd4     TEST       this,this
    //         0046dfd6     JZ         LAB_0046dfe6
    //         0046dfd8     CMP        dword ptr [EAX],0x0
    //         0046dfdb     JZ         LAB_0046dfe6
    //                              Picture.cpp:97 (9)
    //         0046dfdd     PUSH       this
    //         0046dfde     CALL       free                                             undefined free()
    //         0046dfe3     ADD        ESP,0x4
    //                               LAB_0046dfe6                                                 XREF[2]:     0046dfd6(j), 0046dfdb(j)  
    //                              Picture.cpp:98 (12)
    //         0046dfe6     MOV        EAX,dword ptr [ESI + 0xc]
    //         0046dfe9     PUSH       EAX
    //         0046dfea     CALL       free                                             undefined free()
    //         0046dfef     ADD        ESP,0x4
    //                               LAB_0046dff2                                                 XREF[1]:     0046dfcf(j)  
    //                              Picture.cpp:100 (6)
    //         0046dff2     MOV        EAX,dword ptr [ESI]
    //         0046dff4     TEST       EAX,EAX
    //         0046dff6     JZ         LAB_0046e013
    //                              Picture.cpp:102 (3)
    //         0046dff8     MOV        this,dword ptr [ESI + 0x10]
    //                              Picture.cpp:103 (11)
    //         0046dffb     PUSH       EAX
    //         0046dffc     CMP        this,0x2
    //         0046dfff     JNZ        LAB_0046e00b
    //         0046e001     CALL       free                                             undefined free()
    //                              Picture.cpp:105 (3)
    //         0046e006     ADD        ESP,0x4
    //                              Picture.cpp:109 (2)
    //         0046e009     POP        ESI
    //         0046e00a     RET
    //                               LAB_0046e00b                                                 XREF[1]:     0046dfff(j)  
    //                              Picture.cpp:105 (8)
    //         0046e00b     CALL       DibFree                                          void DibFree(tagBITMAPINFOHEADER * param_1)
    //         0046e010     ADD        ESP,0x4
    //                               LAB_0046e013                                                 XREF[2]:     0046dfc8(j), 0046dff6(j)  
    //                              Picture.cpp:109 (2)
    //         0046e013     POP        ESI
    //         0046e014     RET
    //         0046e015     ??         90h
    //         0046e016     NOP
    //         0046e017     NOP
    //         0046e018     NOP
    //         0046e019     NOP
    //         0046e01a     NOP
    //         0046e01b     NOP
    //         0046e01c     NOP
    //         0046e01d     NOP
    //         0046e01e     NOP
    //         0046e01f     NOP
}

void TPicture::Save(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall Save(TPicture * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              TPicture *        ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0046e026(R)  
    //                               ?Save@TPicture@@QAEXH@Z                                      XREF[1]:     save:0048c7fd(c)  
    //                               TPicture::Save
    //                              Picture.cpp:112 (6)
    //         0046e020     PUSH       EBX
    //         0046e021     PUSH       EBP
    //         0046e022     PUSH       ESI
    //         0046e023     MOV        ESI,this
    //         0046e025     PUSH       EDI
    //                              Picture.cpp:113 (19)
    //         0046e026     MOV        EDI,dword ptr [ESP + param_1]
    //         0046e02a     LEA        EAX,[ESI + 0x10]
    //         0046e02d     PUSH       0x4
    //         0046e02f     PUSH       EAX
    //         0046e030     PUSH       EDI
    //         0046e031     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0046e036     ADD        ESP,0xc
    //                              Picture.cpp:114 (15)
    //         0046e039     LEA        EBX,[ESI + 0x14]
    //         0046e03c     PUSH       0x4
    //         0046e03e     PUSH       EBX
    //         0046e03f     PUSH       EDI
    //         0046e040     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0046e045     ADD        ESP,0xc
    //                              Picture.cpp:115 (15)
    //         0046e048     LEA        EBP,[ESI + 0x18]
    //         0046e04b     PUSH       0x4
    //         0046e04d     PUSH       EBP
    //         0046e04e     PUSH       EDI
    //         0046e04f     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0046e054     ADD        ESP,0xc
    //                              Picture.cpp:116 (12)
    //         0046e057     LEA        this,[ESI + 0x1c]
    //         0046e05a     PUSH       0x2
    //         0046e05c     PUSH       this
    //         0046e05d     PUSH       EDI
    //         0046e05e     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              Picture.cpp:118 (15)
    //         0046e063     MOV        EAX,dword ptr [EBX]
    //         0046e065     ADD        ESP,0xc
    //         0046e068     TEST       EAX,EAX
    //         0046e06a     JLE        LAB_0046e09d
    //         0046e06c     CMP        dword ptr [EBP],0x0
    //         0046e070     JLE        LAB_0046e09d
    //                              Picture.cpp:120 (18)
    //         0046e072     MOV        EDX,dword ptr [ESI + 0x4]
    //         0046e075     PUSH       0x428
    //         0046e07a     PUSH       EDX
    //         0046e07b     PUSH       EDI
    //         0046e07c     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0046e081     ADD        ESP,0xc
    //                              Picture.cpp:121 (25)
    //         0046e084     MOV        this,ESI
    //         0046e086     CALL       TPicture::AlignedWidth                           long AlignedWidth(TPicture * this)
    //         0046e08b     IMUL       EAX,dword ptr [EBP]
    //         0046e08f     PUSH       EAX
    //         0046e090     MOV        EAX,dword ptr [ESI + 0x8]
    //         0046e093     PUSH       EAX
    //         0046e094     PUSH       EDI
    //         0046e095     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         0046e09a     ADD        ESP,0xc
    //                               LAB_0046e09d                                                 XREF[2]:     0046e06a(j), 0046e070(j)  
    //                              Picture.cpp:123 (7)
    //         0046e09d     POP        EDI
    //         0046e09e     POP        ESI
    //         0046e09f     POP        EBP
    //         0046e0a0     POP        EBX
    //         0046e0a1     RET        0x4
    //         0046e0a4     ??         90h
    //         0046e0a5     NOP
    //         0046e0a6     NOP
    //         0046e0a7     NOP
    //         0046e0a8     NOP
    //         0046e0a9     NOP
    //         0046e0aa     NOP
    //         0046e0ab     NOP
    //         0046e0ac     NOP
    //         0046e0ad     NOP
    //         0046e0ae     NOP
    //         0046e0af     NOP
    return;
}

void TPicture::Load(char* param_1, long param_2, int param_3, void* param_4, int param_5) {
    /* TODO: Stub */
    //                              void __thiscall Load(TPicture * this, char * param_1, long param_2, 
    //              void              <VOID>         <RETURN>
    //              TPicture *        ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     0046e0c7(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     0046e0f5(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0046e1b1(R)  
    //              void *            Stack[0x10]:4  param_4                   XREF[1]:     0046e1aa(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[1]:     0046e1bc(R)  
    //              char[260]         Stack[-0x108   temp_file_name            XREF[2,3]:   0046e101(*), 0046e11d(R), 0046e105(*), 0046e12a(*), 
    //                                                                                     0046e137(*)  
    //              _iobuf *          Stack[-0x10c   temp_file
    //                               ?Load@TPicture@@QAEXPADJHPAXH@Z                              XREF[1]:     TPicture:0046de1a(c)  
    //                               TPicture::Load
    //                              Picture.cpp:126 (9)
    //         0046e0b0     SUB        ESP,0x108
    //         0046e0b6     PUSH       EBX
    //         0046e0b7     PUSH       ESI
    //         0046e0b8     PUSH       EDI
    //                              language.dll match for 0x7f: "N"
    //                              Picture.cpp:127 (14)
    //         0046e0b9     PUSH       0x7f
    //         0046e0bb     MOV        ESI,this
    //         0046e0bd     PUSH       s_C:\msdev\work\age1_x1\Picture.cp               = "C:\\msdev\\work\\age1_x1\\Picture.cpp"
    //         0046e0c2     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //                              Picture.cpp:132 (31)
    //         0046e0c7     MOV        EDI,dword ptr [ESP + param_1]
    //         0046e0ce     XOR        EBX,EBX
    //         0046e0d0     MOV        dword ptr [ESI + 0xc],EBX
    //         0046e0d3     MOV        dword ptr [ESI + 0x10],0x1
    //         0046e0da     MOV        AL,[shape_file_first]                            = 00h
    //         0046e0df     ADD        ESP,0x8
    //         0046e0e2     CMP        AL,BL
    //         0046e0e4     JZ         LAB_0046e0f1
    //                              Picture.cpp:133 (11)
    //         0046e0e6     PUSH       EDI
    //         0046e0e7     CALL       DibOpenFile                                      tagBITMAPINFOHEADER * DibOpenFile(char * para
    //         0046e0ec     ADD        ESP,0x4
    //         0046e0ef     MOV        dword ptr [ESI],EAX
    //                               LAB_0046e0f1                                                 XREF[1]:     0046e0e4(j)  
    //                              Picture.cpp:135 (16)
    //         0046e0f1     CMP        dword ptr [ESI],EBX
    //         0046e0f3     JNZ        LAB_0046e146
    //         0046e0f5     MOV        EAX,dword ptr [ESP + param_2]
    //         0046e0fc     CMP        EAX,-0x1
    //         0046e0ff     JZ         LAB_0046e146
    //                              Picture.cpp:139 (28)
    //         0046e101     LEA        this=>temp_file_name,[ESP + 0xc]
    //         0046e105     LEA        EDX=>temp_file_name[4],[ESP + 0x10]
    //         0046e109     PUSH       this
    //         0046e10a     PUSH       EDX
    //         0046e10b     PUSH       EAX
    //         0046e10c     PUSH       0x62696e61
    //         0046e111     CALL       RESFILE_Extract_to_File                          int RESFILE_Extract_to_File(ulong param_1, ul
    //         0046e116     ADD        ESP,0x10
    //         0046e119     TEST       EAX,EAX
    //         0046e11b     JZ         LAB_0046e146
    //                              Picture.cpp:141 (13)
    //         0046e11d     MOV        EAX,dword ptr [ESP + temp_file_name[0]]
    //         0046e121     PUSH       EAX
    //         0046e122     CALL       fclose                                           undefined fclose()
    //         0046e127     ADD        ESP,0x4
    //                              Picture.cpp:142 (13)
    //         0046e12a     LEA        this=>temp_file_name[4],[ESP + 0x10]
    //         0046e12e     PUSH       this
    //         0046e12f     CALL       DibOpenFile                                      tagBITMAPINFOHEADER * DibOpenFile(char * para
    //         0046e134     ADD        ESP,0x4
    //                              Picture.cpp:143 (15)
    //         0046e137     LEA        EDX=>temp_file_name[4],[ESP + 0x10]
    //         0046e13b     MOV        dword ptr [ESI],EAX
    //         0046e13d     PUSH       EDX
    //         0046e13e     CALL       __unlink                                         undefined __unlink()
    //         0046e143     ADD        ESP,0x4
    //                               LAB_0046e146                                                 XREF[3]:     0046e0f3(j), 0046e0ff(j), 
    //                                                                                                         0046e11b(j)  
    //                              Picture.cpp:147 (12)
    //         0046e146     CMP        byte ptr [shape_file_first],BL                   = 00h
    //         0046e14c     JNZ        LAB_0046e15d
    //         0046e14e     CMP        dword ptr [ESI],EBX
    //         0046e150     JNZ        LAB_0046e15d
    //                              Picture.cpp:148 (11)
    //         0046e152     PUSH       EDI
    //         0046e153     CALL       DibOpenFile                                      tagBITMAPINFOHEADER * DibOpenFile(char * para
    //         0046e158     ADD        ESP,0x4
    //         0046e15b     MOV        dword ptr [ESI],EAX
    //                               LAB_0046e15d                                                 XREF[2]:     0046e14c(j), 0046e150(j)  
    //                              Picture.cpp:150 (10)
    //         0046e15d     MOV        EAX,dword ptr [ESI]
    //         0046e15f     CMP        EAX,EBX
    //         0046e161     JZ         LAB_0046e240
    //                              Picture.cpp:152 (3)
    //         0046e167     MOV        dword ptr [ESI + 0x4],EAX
    //                              Picture.cpp:153 (29)
    //         0046e16a     MOV        this,dword ptr [EAX + 0x10]
    //         0046e16d     CMP        this,0x3
    //         0046e170     JNZ        LAB_0046e17a
    //         0046e172     MOV        this,dword ptr [EAX]
    //         0046e174     LEA        this,[ECX + EAX*0x1 + this->TransInfo]
    //         0046e178     JMP        LAB_0046e184
    //                               LAB_0046e17a                                                 XREF[1]:     0046e170(j)  
    //         0046e17a     MOV        EDX,dword ptr [EAX + 0x20]
    //         0046e17d     MOV        this,dword ptr [EAX]
    //         0046e17f     LEA        this,[this->Dib + EDX*0x4]
    //         0046e182     ADD        this,EAX
    //                               LAB_0046e184                                                 XREF[1]:     0046e178(j)  
    //         0046e184     MOV        dword ptr [ESI + 0x8],this
    //                              Picture.cpp:154 (6)
    //         0046e187     MOV        EDX,dword ptr [EAX + 0x4]
    //         0046e18a     MOV        dword ptr [ESI + 0x14],EDX
    //                              Picture.cpp:155 (3)
    //         0046e18d     MOV        this,dword ptr [EAX + 0x8]
    //                              Picture.cpp:157 (7)
    //         0046e190     CMP        this,EBX
    //         0046e192     MOV        dword ptr [ESI + 0x18],this
    //         0046e195     JGE        LAB_0046e1a4
    //                              Picture.cpp:160 (11)
    //         0046e197     NEG        this
    //         0046e199     MOV        word ptr [ESI + 0x1c],0x1
    //         0046e19f     MOV        dword ptr [ESI + 0x18],this
    //                              Picture.cpp:162 (2)
    //         0046e1a2     JMP        LAB_0046e1aa
    //                               LAB_0046e1a4                                                 XREF[1]:     0046e195(j)  
    //                              Picture.cpp:163 (6)
    //         0046e1a4     MOV        word ptr [ESI + 0x1c],0xffff
    //                               LAB_0046e1aa                                                 XREF[1]:     0046e1a2(j)  
    //                              Picture.cpp:166 (18)
    //         0046e1aa     MOV        this,dword ptr [ESP + param_4]
    //         0046e1b1     MOV        EDI,dword ptr [ESP + param_3]
    //         0046e1b8     CMP        this,EBX
    //         0046e1ba     JZ         LAB_0046e1cf
    //                              Picture.cpp:167 (19)
    //         0046e1bc     MOV        EDX,dword ptr [ESP + param_5]
    //         0046e1c3     PUSH       EDX
    //         0046e1c4     PUSH       EDI
    //         0046e1c5     PUSH       this
    //         0046e1c6     PUSH       EAX
    //         0046e1c7     CALL       DibMapToPalette                                  void DibMapToPalette(tagBITMAPINFOHEADER * pa
    //         0046e1cc     ADD        ESP,0x10
    //                               LAB_0046e1cf                                                 XREF[1]:     0046e1ba(j)  
    //                              Picture.cpp:169 (8)
    //         0046e1cf     CMP        EDI,EBX
    //         0046e1d1     JZ         LAB_0046e25a
    //                              Picture.cpp:171 (10)
    //         0046e1d7     PUSH       0x18
    //         0046e1d9     CALL       malloc                                           undefined malloc()
    //         0046e1de     ADD        ESP,0x4
    //                              Picture.cpp:172 (7)
    //         0046e1e1     CMP        EAX,EBX
    //         0046e1e3     MOV        dword ptr [ESI + 0xc],EAX
    //         0046e1e6     JZ         LAB_0046e22e
    //                              Picture.cpp:173 (25)
    //         0046e1e8     MOV        ESI,dword ptr [ESI]
    //         0046e1ea     CMP        dword ptr [ESI + 0x10],0x3
    //         0046e1ee     JNZ        LAB_0046e20d
    //         0046e1f0     MOV        this,dword ptr [ESI]
    //         0046e1f2     LEA        this,[ECX + ESI*0x1 + this->TransInfo]
    //         0046e1f6     PUSH       this
    //         0046e1f7     PUSH       EAX
    //         0046e1f8     PUSH       ESI
    //         0046e1f9     CALL       DibCheckTrans                                    int DibCheckTrans(BITMAPINFO256 * param_1, TR
    //         0046e1fe     ADD        ESP,0xc
    //                              Picture.cpp:197 (12)
    //         0046e201     POP        EDI
    //         0046e202     POP        ESI
    //         0046e203     POP        EBX
    //         0046e204     ADD        ESP,0x108
    //         0046e20a     RET        0x14
    //                               LAB_0046e20d                                                 XREF[1]:     0046e1ee(j)  
    //                              Picture.cpp:173 (21)
    //         0046e20d     MOV        EDX,dword ptr [ESI + 0x20]
    //         0046e210     MOV        this,dword ptr [ESI]
    //         0046e212     LEA        this,[this->Dib + EDX*0x4]
    //         0046e215     ADD        this,ESI
    //         0046e217     PUSH       this
    //         0046e218     PUSH       EAX
    //         0046e219     PUSH       ESI
    //         0046e21a     CALL       DibCheckTrans                                    int DibCheckTrans(BITMAPINFO256 * param_1, TR
    //         0046e21f     ADD        ESP,0xc
    //                              Picture.cpp:197 (12)
    //         0046e222     POP        EDI
    //         0046e223     POP        ESI
    //         0046e224     POP        EBX
    //         0046e225     ADD        ESP,0x108
    //         0046e22b     RET        0x14
    //                               LAB_0046e22e                                                 XREF[1]:     0046e1e6(j)  
    //                              Picture.cpp:176 (11)
    //         0046e22e     MOV        EDX,dword ptr [ESI]
    //         0046e230     PUSH       EDX
    //         0046e231     CALL       DibFree                                          void DibFree(tagBITMAPINFOHEADER * param_1)
    //         0046e236     ADD        ESP,0x4
    //                              Picture.cpp:177 (2)
    //         0046e239     MOV        dword ptr [ESI],EBX
    //                              Picture.cpp:178 (3)
    //         0046e23b     MOV        dword ptr [ESI + 0x4],EBX
    //                              Picture.cpp:186 (2)
    //         0046e23e     JMP        LAB_0046e24b
    //                               LAB_0046e240                                                 XREF[1]:     0046e161(j)  
    //                              Picture.cpp:188 (2)
    //         0046e240     MOV        dword ptr [ESI],EBX
    //                              Picture.cpp:189 (3)
    //         0046e242     MOV        dword ptr [ESI + 0x4],EBX
    //                              Picture.cpp:190 (3)
    //         0046e245     MOV        dword ptr [ESI + 0x8],EBX
    //                              Picture.cpp:191 (3)
    //         0046e248     MOV        dword ptr [ESI + 0xc],EBX
    //                               LAB_0046e24b                                                 XREF[1]:     0046e23e(j)  
    //                              Picture.cpp:192 (3)
    //         0046e24b     MOV        dword ptr [ESI + 0x10],EBX
    //                              Picture.cpp:193 (3)
    //         0046e24e     MOV        dword ptr [ESI + 0x14],EBX
    //                              Picture.cpp:194 (3)
    //         0046e251     MOV        dword ptr [ESI + 0x18],EBX
    //                              Picture.cpp:195 (6)
    //         0046e254     MOV        word ptr [ESI + 0x1c],0x1
    //                               LAB_0046e25a                                                 XREF[1]:     0046e1d1(j)  
    //                              Picture.cpp:197 (12)
    //         0046e25a     POP        EDI
    //         0046e25b     POP        ESI
    //         0046e25c     POP        EBX
    //         0046e25d     ADD        ESP,0x108
    //         0046e263     RET        0x14
    //         0046e266     ??         90h
    //         0046e267     NOP
    //         0046e268     NOP
    //         0046e269     NOP
    //         0046e26a     NOP
    //         0046e26b     NOP
    //         0046e26c     NOP
    //         0046e26d     NOP
    //         0046e26e     NOP
    //         0046e26f     NOP
    return;
}

void TPicture::Init(BITMAPINFO256* param_1, uchar* param_2, TRANSINFO* param_3) {
    /* TODO: Stub */
    //                              void __thiscall Init(TPicture * this, BITMAPINFO256 * param_1, uchar
    //              void              <VOID>         <RETURN>
    //              TPicture *        ECX:4 (auto)   this
    //              BITMAPINFO256 *   Stack[0x4]:4   param_1                   XREF[1]:     0046e274(R)  
    //              uchar *           Stack[0x8]:4   param_2                   XREF[1]:     0046e270(R)  
    //              TRANSINFO *       Stack[0xc]:4   param_3                   XREF[1]:     0046e27b(R)  
    //                               ?Init@TPicture@@QAEXPAUBITMAPINFO256@@PAEPAUTRANSINFO@@@Z
    //                               TPicture::Init
    //                              Picture.cpp:200 (11)
    //         0046e270     MOV        EDX,dword ptr [ESP + param_2]
    //         0046e274     MOV        EAX,dword ptr [ESP + param_1]
    //         0046e278     MOV        dword ptr [ECX + this->Bits],EDX
    //                              Picture.cpp:204 (12)
    //         0046e27b     MOV        EDX,dword ptr [ESP + param_3]
    //         0046e27f     MOV        dword ptr [this->Dib],EAX
    //         0046e281     MOV        dword ptr [ECX + this->BitmapInfo],EAX
    //         0046e284     MOV        dword ptr [ECX + this->TransInfo],EDX
    //                              Picture.cpp:205 (7)
    //         0046e287     MOV        dword ptr [ECX + this->OwnMemory],0x0
    //                              Picture.cpp:206 (6)
    //         0046e28e     MOV        EDX,dword ptr [EAX + 0x4]
    //         0046e291     MOV        dword ptr [ECX + this->Width],EDX
    //                              Picture.cpp:207 (3)
    //         0046e294     MOV        EAX,dword ptr [EAX + 0x8]
    //                              Picture.cpp:209 (7)
    //         0046e297     TEST       EAX,EAX
    //         0046e299     MOV        dword ptr [ECX + this->Height],EAX
    //         0046e29c     JGE        LAB_0046e2ac
    //                              Picture.cpp:212 (11)
    //         0046e29e     NEG        EAX
    //         0046e2a0     MOV        word ptr [ECX + this->Orien],0x1
    //         0046e2a6     MOV        dword ptr [ECX + this->Height],EAX
    //                              Picture.cpp:216 (3)
    //         0046e2a9     RET        0xc
    //                               LAB_0046e2ac                                                 XREF[1]:     0046e29c(j)  
    //                              Picture.cpp:215 (6)
    //         0046e2ac     MOV        word ptr [ECX + this->Orien],0xffff
    //                              Picture.cpp:216 (3)
    //         0046e2b2     RET        0xc
    //         0046e2b5     ??         90h
    //         0046e2b6     NOP
    //         0046e2b7     NOP
    //         0046e2b8     NOP
    //         0046e2b9     NOP
    //         0046e2ba     NOP
    //         0046e2bb     NOP
    //         0046e2bc     NOP
    //         0046e2bd     NOP
    //         0046e2be     NOP
    //         0046e2bf     NOP
    return;
}

long TPicture::AlignedWidth() {
    /* TODO: Stub */
    //                              long __thiscall AlignedWidth(TPicture * this)
    //              long              EAX:4          <RETURN>
    //              TPicture *        ECX:4 (auto)   this
    //                               ?AlignedWidth@TPicture@@QAEJXZ                               XREF[10]:    set_bitmap:00436af7(c), 
    //                               TPicture::AlignedWidth                                                    set_bitmap:00436b00(c), 
    //                                                                                                         set_bitmap:00436b12(c), 
    //                                                                                                         TPicture:0046deae(c), 
    //                                                                                                         TPicture:0046dec8(c), 
    //                                                                                                         Save:0046e086(c), 
    //                                                                                                         GetPixel:0046e432(c), 
    //                                                                                                         GetPixel:0046e44e(c), 
    //                                                                                                         GetPixel:0046e474(c), 
    //                                                                                                         GetPixel:0046e488(c)  
    //                              Picture.cpp:219 (8)
    //         0046e2c0     MOV        EAX,dword ptr [ECX + this->Width]
    //         0046e2c3     ADD        EAX,0x3
    //         0046e2c6     AND        AL,0xfc
    //                              Picture.cpp:221 (1)
    //         0046e2c8     RET
    //         0046e2c9     ??         90h
    //         0046e2ca     NOP
    //         0046e2cb     NOP
    //         0046e2cc     NOP
    //         0046e2cd     NOP
    //         0046e2ce     NOP
    //         0046e2cf     NOP
    return 0;
}

void TPicture::Draw(TDrawArea* param_1, long param_2, long param_3, int param_4, int param_5) {
    /* TODO: Stub */
    //                              void __thiscall Draw(TPicture * this, TDrawArea * param_1, long para
    //              void              <VOID>         <RETURN>
    //              TPicture *        ECX:4 (auto)   this
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[2]:     0046e308(R), 0046e351(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[2]:     0046e2fd(R), 0046e346(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[2]:     0046e302(R), 0046e34b(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[2]:     0046e2e6(R), 0046e330(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[2]:     0046e2df(R), 0046e325(R)  
    //                               ?Draw@TPicture@@QAEXPAVTDrawArea@@JJHH@Z                     XREF[2]:     draw:0047a6a4(c), 
    //                               TPicture::Draw                                                            draw:004b8985(c)  
    //                              Picture.cpp:224 (1)
    //         0046e2d0     PUSH       ESI
    //                              Picture.cpp:225 (7)
    //         0046e2d1     MOV        ESI,dword ptr [ECX + this->TransInfo]
    //         0046e2d4     TEST       ESI,ESI
    //         0046e2d6     JZ         LAB_0046e325
    //                              Picture.cpp:231 (73)
    //         0046e2d8     MOV        EAX,dword ptr [ECX + this->Height]
    //         0046e2db     MOV        EDX,dword ptr [ECX + this->Width]
    //         0046e2de     PUSH       EDI
    //         0046e2df     MOV        EDI,dword ptr [ESP + param_5]
    //         0046e2e3     PUSH       0x0
    //         0046e2e5     PUSH       EDI
    //         0046e2e6     MOV        EDI,dword ptr [ESP + param_4]
    //         0046e2ea     PUSH       EDI
    //         0046e2eb     PUSH       0x1
    //         0046e2ed     PUSH       EAX
    //         0046e2ee     PUSH       EDX
    //         0046e2ef     PUSH       0x0
    //         0046e2f1     PUSH       0x0
    //         0046e2f3     PUSH       ESI
    //         0046e2f4     MOV        ESI,dword ptr [ECX + this->Bits]
    //         0046e2f7     MOV        this,dword ptr [ECX + this->BitmapInfo]
    //         0046e2fa     PUSH       ESI
    //         0046e2fb     PUSH       this
    //         0046e2fc     PUSH       EAX
    //         0046e2fd     MOV        EAX,dword ptr [ESP + param_2]
    //         0046e301     PUSH       EDX
    //         0046e302     MOV        EDX,dword ptr [ESP + param_3]
    //         0046e306     PUSH       EDX
    //         0046e307     PUSH       EAX
    //         0046e308     MOV        EAX,dword ptr [ESP + param_1]
    //         0046e30c     MOV        EDX,dword ptr [EAX + 0x8]
    //         0046e30f     LEA        this,[EAX + 0x28]
    //         0046e312     MOV        EAX,dword ptr [EAX + 0xc]
    //         0046e315     PUSH       this
    //         0046e316     PUSH       EDX
    //         0046e317     PUSH       EAX
    //         0046e318     CALL       TransDibBlt                                      void TransDibBlt(BITMAPINFO256 * param_1, uch
    //         0046e31d     ADD        ESP,0x48
    //         0046e320     POP        EDI
    //                              Picture.cpp:241 (4)
    //         0046e321     POP        ESI
    //         0046e322     RET        0x14
    //                               LAB_0046e325                                                 XREF[1]:     0046e2d6(j)  
    //                              Picture.cpp:239 (68)
    //         0046e325     MOV        ESI,dword ptr [ESP + param_5]
    //         0046e329     MOV        EAX,dword ptr [ECX + this->Height]
    //         0046e32c     MOV        EDX,dword ptr [ECX + this->Width]
    //         0046e32f     PUSH       ESI
    //         0046e330     MOV        ESI,dword ptr [ESP + param_4]
    //         0046e334     PUSH       ESI
    //         0046e335     MOV        ESI,dword ptr [ECX + this->Bits]
    //         0046e338     MOV        this,dword ptr [ECX + this->BitmapInfo]
    //         0046e33b     PUSH       0x1
    //         0046e33d     PUSH       EAX
    //         0046e33e     PUSH       EDX
    //         0046e33f     PUSH       0x0
    //         0046e341     PUSH       0x0
    //         0046e343     PUSH       ESI
    //         0046e344     PUSH       this
    //         0046e345     PUSH       EAX
    //         0046e346     MOV        EAX,dword ptr [ESP + param_2]
    //         0046e34a     PUSH       EDX
    //         0046e34b     MOV        EDX,dword ptr [ESP + param_3]
    //         0046e34f     PUSH       EDX
    //         0046e350     PUSH       EAX
    //         0046e351     MOV        EAX,dword ptr [ESP + param_1]
    //         0046e355     MOV        EDX,dword ptr [EAX + 0x8]
    //         0046e358     LEA        this,[EAX + 0x28]
    //         0046e35b     MOV        EAX,dword ptr [EAX + 0xc]
    //         0046e35e     PUSH       this
    //         0046e35f     PUSH       EDX
    //         0046e360     PUSH       EAX
    //         0046e361     CALL       DibBlt                                           void DibBlt(BITMAPINFO256 * param_1, uchar * 
    //         0046e366     ADD        ESP,0x40
    //                              Picture.cpp:241 (4)
    //         0046e369     POP        ESI
    //         0046e36a     RET        0x14
    //         0046e36d     ??         90h
    //         0046e36e     NOP
    //         0046e36f     NOP
    //                              * public: long __thiscall TPicture::Tile(class TDrawArea *,long,long,long,long,long,long,long,long,l... *
    //                              long __thiscall Tile(TPicture * this, TDrawArea * param_1, long para
    //              long              EAX:4          <RETURN>
    //              TPicture *        ECX:4 (auto)   this
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[1]:     0046e3b9(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     0046e3b3(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     0046e3ae(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     0046e3a9(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[1]:     0046e3a4(R)  
    //              long              Stack[0x18]:4  param_6                   XREF[1]:     0046e39f(R)  
    //              long              Stack[0x1c]:4  param_7                   XREF[1]:     0046e393(R)  
    //              long              Stack[0x20]:4  param_8                   XREF[1]:     0046e38e(R)  
    //              long              Stack[0x24]:4  param_9                   XREF[1]:     0046e389(R)  
    //              long              Stack[0x28]:4  param_10                  XREF[1]:     0046e384(R)  
    //              long              Stack[0x2c]:4  param_11                  XREF[1]:     0046e37f(R)  
    //                               ?Tile@TPicture@@QAEJPAVTDrawArea@@JJJJJJJJJJ@Z
    //                               TPicture::Tile
    //                              Picture.cpp:246 (98)
    //         0046e370     MOV        EAX,dword ptr [ECX + this->TransInfo]
    //         0046e373     XOR        EDX,EDX
    //         0046e375     TEST       EAX,EAX
    //         0046e377     PUSH       0x0
    //         0046e379     PUSH       0x0
    //         0046e37b     SETNZ      DL
    //         0046e37e     PUSH       EDX
    //         0046e37f     MOV        EDX,dword ptr [ESP + param_11]
    //         0046e383     PUSH       EDX
    //         0046e384     MOV        EDX,dword ptr [ESP + param_10]
    //         0046e388     PUSH       EDX
    //         0046e389     MOV        EDX,dword ptr [ESP + param_9]
    //         0046e38d     PUSH       EDX
    //         0046e38e     MOV        EDX,dword ptr [ESP + param_8]
    //         0046e392     PUSH       EDX
    //         0046e393     MOV        EDX,dword ptr [ESP + param_7]
    //         0046e397     PUSH       EAX
    //         0046e398     MOV        EAX,dword ptr [ECX + this->Bits]
    //         0046e39b     MOV        this,dword ptr [ECX + this->BitmapInfo]
    //         0046e39e     PUSH       EAX
    //         0046e39f     MOV        EAX,dword ptr [ESP + param_6]
    //         0046e3a3     PUSH       this
    //         0046e3a4     MOV        this,dword ptr [ESP + param_5]
    //         0046e3a8     PUSH       EDX
    //         0046e3a9     MOV        EDX,dword ptr [ESP + param_4]
    //         0046e3ad     PUSH       EAX
    //         0046e3ae     MOV        EAX,dword ptr [ESP + param_3]
    //         0046e3b2     PUSH       this
    //         0046e3b3     MOV        this,dword ptr [ESP + param_2]
    //         0046e3b7     PUSH       EDX
    //         0046e3b8     PUSH       EAX
    //         0046e3b9     MOV        EAX,dword ptr [ESP + param_1]
    //         0046e3bd     PUSH       this
    //         0046e3be     MOV        this,dword ptr [EAX + 0x8]
    //         0046e3c1     LEA        EDX,[EAX + 0x28]
    //         0046e3c4     PUSH       EDX
    //         0046e3c5     MOV        EDX,dword ptr [EAX + 0xc]
    //         0046e3c8     PUSH       this
    //         0046e3c9     PUSH       EDX
    //         0046e3ca     CALL       TileDibBlt                                       long TileDibBlt(BITMAPINFO256 * param_1, ucha
    //         0046e3cf     ADD        ESP,0x4c
    //                              Picture.cpp:252 (3)
    //         0046e3d2     RET        0x2c
    //         0046e3d5     ??         90h
    //         0046e3d6     NOP
    //         0046e3d7     NOP
    //         0046e3d8     NOP
    //         0046e3d9     NOP
    //         0046e3da     NOP
    //         0046e3db     NOP
    //         0046e3dc     NOP
    //         0046e3dd     NOP
    //         0046e3de     NOP
    //         0046e3df     NOP
    return;
}

uchar TPicture::GetPixel(long param_1, long param_2, int param_3, int param_4) {
    /* TODO: Stub */
    //                              uchar __thiscall GetPixel(TPicture * this, long param_1, long param_
    //              uchar             AL:1           <RETURN>
    //              TPicture *        ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     0046e3fa(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     0046e40f(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0046e424(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     0046e3e5(R)  
    //                               ?GetPixel@TPicture@@QAEEJJHH@Z
    //                               TPicture::GetPixel
    //                              Picture.cpp:256 (5)
    //         0046e3e0     PUSH       EBX
    //         0046e3e1     PUSH       ESI
    //         0046e3e2     MOV        ESI,this
    //         0046e3e4     PUSH       EDI
    //                              Picture.cpp:262 (11)
    //         0046e3e5     MOV        this,dword ptr [ESP + param_4]
    //         0046e3e9     MOV        AL,byte ptr [ESI + 0x1c]
    //         0046e3ec     TEST       this,this
    //         0046e3ee     JZ         LAB_0046e3fa
    //                              Picture.cpp:263 (10)
    //         0046e3f0     DEC        AL
    //         0046e3f2     NEG        AL
    //         0046e3f4     SBB        EAX,EAX
    //         0046e3f6     AND        EAX,0x2
    //         0046e3f9     DEC        EAX
    //                               LAB_0046e3fa                                                 XREF[1]:     0046e3ee(j)  
    //                              Picture.cpp:265 (42)
    //         0046e3fa     MOV        EBX,dword ptr [ESP + param_1]
    //         0046e3fe     TEST       EBX,EBX
    //         0046e400     JLE        LAB_0046e4a4
    //         0046e406     CMP        EBX,dword ptr [ESI + 0x14]
    //         0046e409     JGE        LAB_0046e4a4
    //         0046e40f     MOV        EDI,dword ptr [ESP + param_2]
    //         0046e413     TEST       EDI,EDI
    //         0046e415     JL         LAB_0046e4a4
    //         0046e41b     CMP        EDI,dword ptr [ESI + 0x18]
    //         0046e41e     JGE        LAB_0046e4a4
    //                              Picture.cpp:267 (8)
    //         0046e424     MOV        this,dword ptr [ESP + param_3]
    //         0046e428     TEST       this,this
    //         0046e42a     JZ         LAB_0046e46e
    //                              Picture.cpp:269 (2)
    //         0046e42c     CMP        AL,0x1
    //                              Picture.cpp:270 (26)
    //         0046e42e     MOV        this,ESI
    //         0046e430     JNZ        LAB_0046e44e
    //         0046e432     CALL       TPicture::AlignedWidth                           long AlignedWidth(TPicture * this)
    //         0046e437     IMUL       EAX,EDI
    //         0046e43a     MOV        EDX,dword ptr [ESI + 0x8]
    //         0046e43d     MOV        this,dword ptr [ESI + 0x14]
    //         0046e440     ADD        EAX,EDX
    //         0046e442     SUB        EAX,EBX
    //         0046e444     MOV        AL,byte ptr [EAX + this->Dib*0x1 + -0x1]
    //                              Picture.cpp:286 (6)
    //         0046e448     POP        EDI
    //         0046e449     POP        ESI
    //         0046e44a     POP        EBX
    //         0046e44b     RET        0x10
    //                               LAB_0046e44e                                                 XREF[1]:     0046e430(j)  
    //                              Picture.cpp:272 (26)
    //         0046e44e     CALL       TPicture::AlignedWidth                           long AlignedWidth(TPicture * this)
    //         0046e453     MOV        EDX,dword ptr [ESI + 0x18]
    //         0046e456     MOV        this,dword ptr [ESI + 0x14]
    //         0046e459     SUB        EDX,EDI
    //         0046e45b     DEC        EDX
    //         0046e45c     IMUL       EAX,EDX
    //         0046e45f     ADD        EAX,dword ptr [ESI + 0x8]
    //         0046e462     SUB        EAX,EBX
    //         0046e464     MOV        AL,byte ptr [EAX + this->Dib*0x1 + -0x1]
    //                              Picture.cpp:286 (6)
    //         0046e468     POP        EDI
    //         0046e469     POP        ESI
    //         0046e46a     POP        EBX
    //         0046e46b     RET        0x10
    //                               LAB_0046e46e                                                 XREF[1]:     0046e42a(j)  
    //                              Picture.cpp:276 (2)
    //         0046e46e     CMP        AL,0x1
    //                              Picture.cpp:277 (18)
    //         0046e470     MOV        this,ESI
    //         0046e472     JNZ        LAB_0046e488
    //         0046e474     CALL       TPicture::AlignedWidth                           long AlignedWidth(TPicture * this)
    //         0046e479     IMUL       EAX,EDI
    //         0046e47c     ADD        EAX,dword ptr [ESI + 0x8]
    //         0046e47f     MOV        AL,byte ptr [EAX + EBX*0x1]
    //                              Picture.cpp:286 (6)
    //         0046e482     POP        EDI
    //         0046e483     POP        ESI
    //         0046e484     POP        EBX
    //         0046e485     RET        0x10
    //                               LAB_0046e488                                                 XREF[1]:     0046e472(j)  
    //                              Picture.cpp:279 (22)
    //         0046e488     CALL       TPicture::AlignedWidth                           long AlignedWidth(TPicture * this)
    //         0046e48d     MOV        EDX,dword ptr [ESI + 0x18]
    //         0046e490     MOV        this,dword ptr [ESI + 0x8]
    //         0046e493     SUB        EDX,EDI
    //         0046e495     DEC        EDX
    //         0046e496     IMUL       EAX,EDX
    //         0046e499     ADD        EAX,this
    //         0046e49b     MOV        AL,byte ptr [EAX + EBX*0x1]
    //                              Picture.cpp:286 (14)
    //         0046e49e     POP        EDI
    //         0046e49f     POP        ESI
    //         0046e4a0     POP        EBX
    //         0046e4a1     RET        0x10
    //                               LAB_0046e4a4                                                 XREF[4]:     0046e400(j), 0046e409(j), 
    //                                                                                                         0046e415(j), 0046e41e(j)  
    //         0046e4a4     POP        EDI
    //         0046e4a5     POP        ESI
    //         0046e4a6     XOR        AL,AL
    //         0046e4a8     POP        EBX
    //         0046e4a9     RET        0x10
    //         0046e4ac     ??         90h
    //         0046e4ad     NOP
    //         0046e4ae     NOP
    //         0046e4af     NOP
    return 0;
}

long TPicture::Tile(TDrawArea* param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

