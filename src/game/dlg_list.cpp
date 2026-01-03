#include "../common.h"
#include "dlg_list.h"

TListDialog::TListDialog(char* param_1) {
    /* TODO: Stub */
//                              undefined __thiscall TListDialog(TListDialog * this, char * param_1)
//              undefined         <UNASSIGNED>   <RETURN>
//              TListDialog *     ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     0043ee70(R)
//                               ??0TListDialog@@QAE@PAD@Z                                    XREF[1]:     RGE_Dialog_List:0047e678(c)
//                               TListDialog::TListDialog
//                              dlg_list.cpp:39 (66)
//         0043ee70     MOV        EAX,dword ptr [ESP + param_1]
//         0043ee74     PUSH       ESI
//         0043ee75     MOV        ESI,this
//         0043ee77     PUSH       EAX
//         0043ee78     CALL       TDialogPanel::TDialogPanel                       undefined TDialogPanel(TDialogPanel * this, c
//         0043ee7d     XOR        EAX,EAX
//         0043ee7f     MOV        word ptr [ESI + 0x4a4],0xffff
//         0043ee88     MOV        dword ptr [ESI + 0x490],EAX
//         0043ee8e     MOV        dword ptr [ESI + 0x494],EAX
//         0043ee94     MOV        dword ptr [ESI + 0x498],EAX
//         0043ee9a     MOV        dword ptr [ESI + 0x49c],EAX
//         0043eea0     MOV        dword ptr [ESI + 0x4a0],EAX
//         0043eea6     MOV        dword ptr [ESI + 0x4a8],EAX
//         0043eeac     MOV        dword ptr [ESI],TListDialog::`vftable'           = 0043eec0
//                              dlg_list.cpp:40 (6)
//         0043eeb2     MOV        EAX,ESI
//         0043eeb4     POP        ESI
//         0043eeb5     RET        0x4
//         0043eeb8     ??         90h
//         0043eeb9     NOP
//         0043eeba     NOP
//         0043eebb     NOP
//         0043eebc     NOP
//         0043eebd     NOP
//         0043eebe     NOP
//         0043eebf     NOP
}

TListDialog::~TListDialog() {
    /* TODO: Stub */
//                              void __thiscall ~TListDialog(TListDialog * this)
//              void              <VOID>         <RETURN>
//              TListDialog *     ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0043ef09(W)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0043eef9(W)
//                               ??1TListDialog@@UAE@XZ                                       XREF[2]:     `vector_deleting_destructor':0043e
//                               TListDialog::~TListDialog                                                 ~RGE_Dialog_List:0047e8a9(c)
//                              dlg_list.cpp:45 (35)
//         0043eee0     PUSH       -0x1
//         0043eee2     PUSH       FUN_0055d0e8
//         0043eee7     MOV        EAX,FS:[0x0]
//         0043eeed     PUSH       EAX
//         0043eeee     MOV        dword ptr FS:[0x0],ESP
//         0043eef5     PUSH       this
//         0043eef6     PUSH       ESI
//         0043eef7     MOV        ESI,this
//         0043eef9     MOV        dword ptr [ESP + local_10],ESI
//         0043eefd     MOV        dword ptr [ESI],TListDialog::`vftable'           = 0043eec0
//                              dlg_list.cpp:46 (18)
//         0043ef03     MOV        this,dword ptr [ESI + 0x490]
//         0043ef09     MOV        dword ptr [ESP + local_4],0x0
//         0043ef11     TEST       this,this
//         0043ef13     JZ         LAB_0043ef1b
//                              dlg_list.cpp:47 (6)
//         0043ef15     MOV        EAX,dword ptr [this->_padding_]
//         0043ef17     PUSH       0x1
//         0043ef19     CALL       dword ptr [EAX]
//                               LAB_0043ef1b                                                 XREF[1]:     0043ef13(j)
//                              dlg_list.cpp:48 (10)
//         0043ef1b     MOV        this,dword ptr [ESI + 0x494]
//         0043ef21     TEST       this,this
//         0043ef23     JZ         LAB_0043ef2b
//                              dlg_list.cpp:49 (6)
//         0043ef25     MOV        EDX,dword ptr [this->_padding_]
//         0043ef27     PUSH       0x1
//         0043ef29     CALL       dword ptr [EDX]
//                               LAB_0043ef2b                                                 XREF[1]:     0043ef23(j)
//                              dlg_list.cpp:50 (10)
//         0043ef2b     MOV        this,dword ptr [ESI + 0x498]
//         0043ef31     TEST       this,this
//         0043ef33     JZ         LAB_0043ef3b
//                              dlg_list.cpp:51 (6)
//         0043ef35     MOV        EAX,dword ptr [this->_padding_]
//         0043ef37     PUSH       0x1
//         0043ef39     CALL       dword ptr [EAX]
//                               LAB_0043ef3b                                                 XREF[1]:     0043ef33(j)
//                              dlg_list.cpp:52 (10)
//         0043ef3b     MOV        this,dword ptr [ESI + 0x49c]
//         0043ef41     TEST       this,this
//         0043ef43     JZ         LAB_0043ef4b
//                              dlg_list.cpp:53 (6)
//         0043ef45     MOV        EDX,dword ptr [this->_padding_]
//         0043ef47     PUSH       0x1
//         0043ef49     CALL       dword ptr [EDX]
//                               LAB_0043ef4b                                                 XREF[1]:     0043ef43(j)
//                              dlg_list.cpp:54 (10)
//         0043ef4b     MOV        this,dword ptr [ESI + 0x4a0]
//         0043ef51     TEST       this,this
//         0043ef53     JZ         LAB_0043ef5b
//                              dlg_list.cpp:55 (8)
//         0043ef55     MOV        EAX,dword ptr [this->_padding_]
//         0043ef57     PUSH       0x1
//         0043ef59     CALL       dword ptr [EAX]
//                               LAB_0043ef5b                                                 XREF[1]:     0043ef53(j)
//         0043ef5b     MOV        this,ESI
//                              dlg_list.cpp:56 (29)
//         0043ef5d     MOV        dword ptr [ESP + 0x10],0xffffffff
//         0043ef65     CALL       TDialogPanel::~TDialogPanel                      void ~TDialogPanel(TDialogPanel * this)
//         0043ef6a     MOV        this,dword ptr [ESP + 0x8]
//         0043ef6e     POP        ESI
//         0043ef6f     MOV        dword ptr FS:[0x0],this
//         0043ef76     ADD        ESP,0x10
//         0043ef79     RET
//         0043ef7a     ??         90h
//         0043ef7b     NOP
//         0043ef7c     NOP
//         0043ef7d     NOP
//         0043ef7e     NOP
//         0043ef7f     NOP
}

long TListDialog::setup(TPanel* param_1, char* param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, char* param_10, long param_11, long param_12, long param_13, long param_14, char** param_15, short param_16, short param_17, long param_18, long param_19, long param_20, long param_21, long param_22) {
    /* TODO: Stub */
//                              long __thiscall setup(TListDialog * this, TPanel * param_1, char * p
//              long              EAX:4          <RETURN>
//              TListDialog *     ECX:4 (auto)   this
//              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     0043ef9a(R)
//              char *            Stack[0x8]:4   param_2                   XREF[1]:     0043ef8d(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     0043ef80(R)
//              long              Stack[0x10]:4  param_4                   XREF[1]:     0043ef95(R)
//              long              Stack[0x14]:4  param_5                   XREF[1]:     0043ef84(R)
//              long              Stack[0x18]:4  param_6                   XREF[1]:     0043efdf(R)
//              long              Stack[0x1c]:4  param_7                   XREF[1]:     0043efda(R)
//              long              Stack[0x20]:4  param_8                   XREF[1]:     0043efd3(R)
//              long              Stack[0x24]:4  param_9                   XREF[1]:     0043efc6(R)
//              char *            Stack[0x28]:4  param_10                  XREF[1]:     0043efb9(R)
//              long              Stack[0x2c]:4  param_11                  XREF[1]:     0043f011(R)
//              long              Stack[0x30]:4  param_12                  XREF[1]:     0043f008(R)
//              long              Stack[0x34]:4  param_13                  XREF[1]:     0043f004(R)
//              long              Stack[0x38]:4  param_14                  XREF[1]:     0043f000(R)
//              char * *          Stack[0x3c]:4  param_15
//              short             Stack[0x40]:2  param_16
//              short             Stack[0x44]:2  param_17
//              long              Stack[0x48]:4  param_18
//              long              Stack[0x4c]:4  param_19
//              long              Stack[0x50]:4  param_20
//              long              Stack[0x54]:4  param_21
//              long              Stack[0x58]:4  param_22
//                               ?setup@TListDialog@@QAEJPAVTPanel@@PADJJJJJJJ1JJJJPAPADFFJJ  XREF[2]:     setup:0043f201(c),
//                               TListDialog::setup                                                        setup:0047e80d(c)
//                              dlg_list.cpp:66 (50)
//         0043ef80     MOV        EAX,dword ptr [ESP + param_3]
//         0043ef84     MOV        EDX,dword ptr [ESP + param_5]
//         0043ef88     PUSH       EBX
//         0043ef89     PUSH       EBP
//         0043ef8a     PUSH       ESI
//         0043ef8b     MOV        ESI,this
//         0043ef8d     MOV        this,dword ptr [ESP + param_2]
//         0043ef91     PUSH       EDI
//         0043ef92     PUSH       0x1
//         0043ef94     PUSH       EAX
//         0043ef95     MOV        EAX,dword ptr [ESP + param_4]
//         0043ef99     PUSH       this
//         0043ef9a     MOV        this,dword ptr [ESP + param_1]
//         0043ef9e     PUSH       EDX
//         0043ef9f     PUSH       EAX
//         0043efa0     PUSH       this
//         0043efa1     CALL       TPanel::renderArea                               TDrawArea * renderArea(TPanel * this)
//         0043efa6     PUSH       EAX
//         0043efa7     MOV        this,ESI
//         0043efa9     CALL       TDialogPanel::setup                              int setup(TDialogPanel * this, TDrawArea * pa
//         0043efae     TEST       EAX,EAX
//         0043efb0     JNZ        LAB_0043efb9
//                              dlg_list.cpp:96 (7)
//         0043efb2     POP        EDI
//         0043efb3     POP        ESI
//         0043efb4     POP        EBP
//         0043efb5     POP        EBX
//         0043efb6     RET        0x58
//                               LAB_0043efb9                                                 XREF[1]:     0043efb0(j)
//                              dlg_list.cpp:71 (13)
//         0043efb9     MOV        EAX,dword ptr [ESP + param_10]
//         0043efbd     TEST       EAX,EAX
//         0043efbf     JZ         LAB_0043f000
//         0043efc1     CMP        byte ptr [EAX],0x0
//         0043efc4     JZ         LAB_0043f000
//                              dlg_list.cpp:73 (51)
//         0043efc6     MOV        this,dword ptr [ESP + param_9]
//         0043efca     PUSH       0x1
//         0043efcc     PUSH       0x1
//         0043efce     PUSH       0x1
//         0043efd0     PUSH       0x4
//         0043efd2     PUSH       this
//         0043efd3     MOV        this,dword ptr [ESP + param_8]
//         0043efd7     MOV        EDX,dword ptr [ESI]
//         0043efd9     PUSH       this
//         0043efda     MOV        this,dword ptr [ESP + param_7]
//         0043efde     PUSH       this
//         0043efdf     MOV        this,dword ptr [ESP + param_6]
//         0043efe3     PUSH       this
//         0043efe4     PUSH       EAX
//         0043efe5     LEA        EAX,[ESI + 0x490]
//         0043efeb     MOV        this,ESI
//         0043efed     PUSH       EAX
//         0043efee     PUSH       ESI
//         0043efef     CALL       dword ptr [EDX + 0x100]
//         0043eff5     TEST       EAX,EAX
//         0043eff7     JNZ        LAB_0043f000
//                              dlg_list.cpp:96 (7)
//         0043eff9     POP        EDI
//         0043effa     POP        ESI
//         0043effb     POP        EBP
//         0043effc     POP        EBX
//         0043effd     RET        0x58
//                               LAB_0043f000                                                 XREF[3]:     0043efbf(j), 0043efc4(j),
//                                                                                                         0043eff7(j)
//                              dlg_list.cpp:77 (44)
//         0043f000     MOV        this,dword ptr [ESP + param_14]
//         0043f004     MOV        EDX,dword ptr [ESP + param_13]
//         0043f008     MOV        EAX,dword ptr [ESP + param_12]
//         0043f00c     MOV        EDI,dword ptr [ESI]
//         0043f00e     PUSH       0xb
//         0043f010     PUSH       this=>DAT_fffffff8
//         0043f011     MOV        this,dword ptr [ESP + param_11]
//         0043f015     PUSH       EDX=>DAT_fffffff4
//         0043f016     LEA        EBX,[ESI + 0x494]
//         0043f01c     PUSH       EAX=>DAT_fffffff0
//         0043f01d     PUSH       this
//         0043f01e     PUSH       EBX
//         0043f01f     PUSH       ESI
//         0043f020     MOV        this,ESI
//         0043f022     CALL       dword ptr [EDI + 0x110]
//         0043f028     TEST       EAX,EAX
//         0043f02a     JNZ        LAB_0043f033
//                              dlg_list.cpp:96 (7)
//         0043f02c     POP        EDI
//         0043f02d     POP        ESI
//         0043f02e     POP        EBP
//         0043f02f     POP        EBX
//         0043f030     RET        0x58
//                               LAB_0043f033                                                 XREF[1]:     0043f02a(j)
//                              dlg_list.cpp:78 (24)
//         0043f033     MOV        EDX,dword ptr [EBX]
//         0043f035     PUSH       0x14
//         0043f037     LEA        EAX,[ESI + 0x498]
//         0043f03d     PUSH       EDX=>DAT_fffffff8
//         0043f03e     PUSH       EAX=>DAT_fffffff4
//         0043f03f     MOV        this,ESI
//         0043f041     CALL       dword ptr [EDI + 0x118]
//         0043f047     TEST       EAX,EAX
//         0043f049     JNZ        LAB_0043f052
//                              dlg_list.cpp:96 (7)
//         0043f04b     POP        EDI
//         0043f04c     POP        ESI
//         0043f04d     POP        EBP
//         0043f04e     POP        EBX
//         0043f04f     RET        0x58
//                               LAB_0043f052                                                 XREF[1]:     0043f049(j)
//                              dlg_list.cpp:80 (8)
//         0043f052     MOV        EAX,dword ptr [ESP + 0x4c]
//         0043f056     TEST       EAX,EAX
//         0043f058     JZ         LAB_0043f06a
//                              dlg_list.cpp:81 (16)
//         0043f05a     MOV        this,dword ptr [EBX]
//         0043f05c     MOV        EBP,dword ptr [ESP + 0x50]
//         0043f060     PUSH       EBP
//         0043f061     PUSH       EAX=>DAT_fffffff8
//         0043f062     MOV        EDX,dword ptr [this->_padding_]
//         0043f064     CALL       dword ptr [EDX + 0xe0]
//                               LAB_0043f06a                                                 XREF[1]:     0043f058(j)
//                              dlg_list.cpp:84 (4)
//         0043f06a     MOV        EAX,dword ptr [ESP + 0x54]
//                              dlg_list.cpp:85 (19)
//         0043f06e     MOV        this,dword ptr [EBX]
//         0043f070     PUSH       0x1
//         0043f072     PUSH       EAX=>DAT_fffffff8
//         0043f073     PUSH       offset DAT_fffffff4
//         0043f075     MOV        word ptr [ESI + 0x4a4],AX
//         0043f07c     CALL       TListPanel::scroll_cur_line                      void scroll_cur_line(TListPanel * this, uchar
//                              dlg_list.cpp:88 (55)
//         0043f081     MOV        EAX,dword ptr [ESP + 0x68]
//         0043f085     MOV        this,dword ptr [ESP + 0x64]
//         0043f089     MOV        EDX,dword ptr [ESP + 0x60]
//         0043f08d     PUSH       0x0
//         0043f08f     PUSH       0x0=>DAT_fffffff8
//         0043f091     MOV        EDI,dword ptr [EDI + 0xe8]
//         0043f097     PUSH       0x0=>DAT_fffffff4
//         0043f099     PUSH       EAX=>DAT_fffffff0
//         0043f09a     MOV        EAX,dword ptr [ESP + 0x68]
//         0043f09e     PUSH       this
//         0043f09f     PUSH       EDX
//         0043f0a0     PUSH       EAX
//         0043f0a1     PUSH       0x0
//         0043f0a3     LEA        this,[ESI + 0x49c]
//                              language.dll match for 0xfa1: "OK"
//         0043f0a9     PUSH       0xfa1
//         0043f0ae     PUSH       this
//         0043f0af     PUSH       ESI
//         0043f0b0     MOV        this,ESI
//         0043f0b2     CALL       EDI
//         0043f0b4     TEST       EAX,EAX
//         0043f0b6     JNZ        LAB_0043f0bf
//                              dlg_list.cpp:96 (7)
//         0043f0b8     POP        EDI
//         0043f0b9     POP        ESI
//         0043f0ba     POP        EBP
//         0043f0bb     POP        EBX
//         0043f0bc     RET        0x58
//                               LAB_0043f0bf                                                 XREF[1]:     0043f0b6(j)
//                              dlg_list.cpp:89 (49)
//         0043f0bf     MOV        EDX,dword ptr [ESP + 0x68]
//         0043f0c3     MOV        EAX,dword ptr [ESP + 0x64]
//         0043f0c7     MOV        this,dword ptr [ESP + 0x60]
//         0043f0cb     PUSH       0x0
//         0043f0cd     PUSH       0x0=>DAT_fffffff8
//         0043f0cf     PUSH       0x0=>DAT_fffffff4
//         0043f0d1     PUSH       EDX=>DAT_fffffff0
//         0043f0d2     MOV        EDX,dword ptr [ESP + 0x6c]
//         0043f0d6     PUSH       EAX
//         0043f0d7     PUSH       this
//         0043f0d8     PUSH       EDX
//         0043f0d9     LEA        EBP,[ESI + 0x4a0]
//         0043f0df     PUSH       0x0
//                              language.dll match for 0xfa2: "Cancel"
//         0043f0e1     PUSH       0xfa2
//         0043f0e6     PUSH       EBP
//         0043f0e7     PUSH       ESI
//         0043f0e8     MOV        this,ESI
//         0043f0ea     CALL       EDI
//         0043f0ec     TEST       EAX,EAX
//         0043f0ee     JNZ        LAB_0043f0f7
//                              dlg_list.cpp:96 (7)
//         0043f0f0     POP        EDI
//         0043f0f1     POP        ESI
//         0043f0f2     POP        EBP
//         0043f0f3     POP        EBX
//         0043f0f4     RET        0x58
//                               LAB_0043f0f7                                                 XREF[1]:     0043f0ee(j)
//                              dlg_list.cpp:90 (3)
//         0043f0f7     MOV        EBP,dword ptr [EBP]
//                              dlg_list.cpp:93 (30)
//         0043f0fa     MOV        this,ESI
//         0043f0fc     MOV        dword ptr [EBP + 0x298],0x1b
//         0043f106     MOV        dword ptr [EBP + 0x29c],0x0
//         0043f110     MOV        EAX,dword ptr [EBX]
//         0043f112     PUSH       EAX
//         0043f113     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
//                              dlg_list.cpp:96 (12)
//         0043f118     POP        EDI
//         0043f119     POP        ESI
//         0043f11a     POP        EBP
//         0043f11b     MOV        EAX,0x1
//         0043f120     POP        EBX
//         0043f121     RET        0x58
//         0043f124     ??         90h
//         0043f125     NOP
//         0043f126     NOP
//         0043f127     NOP
//         0043f128     NOP
//         0043f129     NOP
//         0043f12a     NOP
//         0043f12b     NOP
//         0043f12c     NOP
//         0043f12d     NOP
//         0043f12e     NOP
//         0043f12f     NOP
    return 0;
}

long TListDialog::setup(TPanel* param_1, char* param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, int param_10, long param_11, long param_12, long param_13, long param_14, char** param_15, short param_16, short param_17, long param_18, long param_19, long param_20, long param_21, long param_22) {
    /* TODO: Stub */
//                              long __thiscall setup(TListDialog * this, TPanel * param_1, char * p
//              long              EAX:4          <RETURN>
//              TListDialog *     ECX:4 (auto)   this
//              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     0043f1f5(R)
//              char *            Stack[0x8]:4   param_2                   XREF[1]:     0043f1ed(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     0043f1e5(R)
//              long              Stack[0x10]:4  param_4                   XREF[1]:     0043f1dd(R)
//              long              Stack[0x14]:4  param_5                   XREF[1]:     0043f1d5(R)
//              long              Stack[0x18]:4  param_6                   XREF[1]:     0043f1cd(R)
//              long              Stack[0x1c]:4  param_7                   XREF[1]:     0043f1c5(R)
//              long              Stack[0x20]:4  param_8                   XREF[1]:     0043f1bd(R)
//              long              Stack[0x24]:4  param_9                   XREF[1]:     0043f1b1(R)
//              int               Stack[0x28]:4  param_10                  XREF[1]:     0043f13d(R)
//              long              Stack[0x2c]:4  param_11                  XREF[1]:     0043f1a8(R)
//              long              Stack[0x30]:4  param_12                  XREF[1]:     0043f1a0(R)
//              long              Stack[0x34]:4  param_13                  XREF[1]:     0043f198(R)
//              long              Stack[0x38]:4  param_14                  XREF[1]:     0043f190(R)
//              char * *          Stack[0x3c]:4  param_15                  XREF[1]:     0043f188(R)
//              short             Stack[0x40]:2  param_16                  XREF[1]:     0043f180(R)
//              short             Stack[0x44]:2  param_17                  XREF[1]:     0043f178(R)
//              long              Stack[0x48]:4  param_18                  XREF[1]:     0043f170(R)
//              long              Stack[0x4c]:4  param_19                  XREF[1]:     0043f168(R)
//              long              Stack[0x50]:4  param_20                  XREF[1]:     0043f160(R)
//              long              Stack[0x54]:4  param_21                  XREF[1]:     0043f159(R)
//              long              Stack[0x58]:4  param_22                  XREF[1]:     0043f152(R)
//              char[256]         Stack[-0x104   str                       XREF[0,2]:   0043f136(*), 0043f1b8(*)
//                               ?setup@TListDialog@@QAEJPAVTPanel@@PADJJJJJJJHJJJJPAPADFFJJ
//                               TListDialog::setup
//                              dlg_list.cpp:106 (6)
//         0043f130     SUB        ESP,0x100
//                              dlg_list.cpp:109 (28)
//         0043f136     LEA        EAX=>str[4],[ESP]
//         0043f13a     PUSH       ESI
//         0043f13b     MOV        ESI,this
//         0043f13d     MOV        this,dword ptr [ESP + param_10]
//         0043f144     PUSH       0x100
//         0043f149     PUSH       EAX
//         0043f14a     PUSH       this
//         0043f14b     MOV        this,ESI
//         0043f14d     CALL       TPanel::get_string                               int get_string(TPanel * this, int param_1, ch
//                              dlg_list.cpp:115 (180)
//         0043f152     MOV        EDX,dword ptr [ESP + param_22]
//         0043f159     MOV        EAX,dword ptr [ESP + param_21]
//         0043f160     MOV        this,dword ptr [ESP + param_20]
//         0043f167     PUSH       EDX
//         0043f168     MOV        EDX,dword ptr [ESP + param_19]
//         0043f16f     PUSH       EAX
//         0043f170     MOV        EAX,dword ptr [ESP + param_18]
//         0043f177     PUSH       this
//         0043f178     MOV        this,dword ptr [ESP + param_17]
//         0043f17f     PUSH       EDX
//         0043f180     MOV        EDX,dword ptr [ESP + param_16]
//         0043f187     PUSH       EAX
//         0043f188     MOV        EAX,dword ptr [ESP + param_15]
//         0043f18f     PUSH       this
//         0043f190     MOV        this,dword ptr [ESP + param_14]
//         0043f197     PUSH       EDX
//         0043f198     MOV        EDX,dword ptr [ESP + param_13]
//         0043f19f     PUSH       EAX
//         0043f1a0     MOV        EAX,dword ptr [ESP + param_12]
//         0043f1a7     PUSH       this
//         0043f1a8     MOV        this,dword ptr [ESP + param_11]
//         0043f1af     PUSH       EDX
//         0043f1b0     PUSH       EAX
//         0043f1b1     MOV        EAX,dword ptr [ESP + param_9]
//         0043f1b8     LEA        EDX=>str[4],[ESP + 0x30]
//         0043f1bc     PUSH       this
//         0043f1bd     MOV        this,dword ptr [ESP + param_8]
//         0043f1c4     PUSH       EDX
//         0043f1c5     MOV        EDX,dword ptr [ESP + param_7]
//         0043f1cc     PUSH       EAX
//         0043f1cd     MOV        EAX,dword ptr [ESP + param_6]
//         0043f1d4     PUSH       this
//         0043f1d5     MOV        this,dword ptr [ESP + param_5]
//         0043f1dc     PUSH       EDX
//         0043f1dd     MOV        EDX,dword ptr [ESP + param_4]
//         0043f1e4     PUSH       EAX
//         0043f1e5     MOV        EAX,dword ptr [ESP + param_3]
//         0043f1ec     PUSH       this
//         0043f1ed     MOV        this,dword ptr [ESP + param_2]
//         0043f1f4     PUSH       EDX
//         0043f1f5     MOV        EDX,dword ptr [ESP + param_1]
//         0043f1fc     PUSH       EAX
//         0043f1fd     PUSH       this
//         0043f1fe     PUSH       EDX
//         0043f1ff     MOV        this,ESI
//         0043f201     CALL       TListDialog::setup                               long setup(TListDialog * this, TPanel * param
//                              dlg_list.cpp:116 (10)
//         0043f206     POP        ESI
//         0043f207     ADD        ESP,0x100
//         0043f20d     RET        0x58
    return 0;
}

long TListDialog::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) {
    /* TODO: Stub */
//                              long __thiscall key_down_action(TListDialog * this, long param_1, sh
//              long              EAX:4          <RETURN>
//              TListDialog *     ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1
//              short             Stack[0x8]:2   param_2
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//              int               Stack[0x14]:4  param_5
//                               ?key_down_action@TListDialog@@UAEJJFHHH@Z                    XREF[3]:     0056fba4(*), 00571d9c(*),
//                               TListDialog::key_down_action                                              0057662c(*)
//                              dlg_list.cpp:122 (2)
//         0043f210     XOR        EAX,EAX
//                              dlg_list.cpp:131 (3)
//         0043f212     RET        0x14
//         0043f215     ??         90h
//         0043f216     NOP
//         0043f217     NOP
//         0043f218     NOP
//         0043f219     NOP
//         0043f21a     NOP
//         0043f21b     NOP
//         0043f21c     NOP
//         0043f21d     NOP
//         0043f21e     NOP
//         0043f21f     NOP
    return 0;
}

long TListDialog::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    /* TODO: Stub */
//                              long __thiscall action(TListDialog * this, TPanel * param_1, long pa
//              long              EAX:4          <RETURN>
//              TListDialog *     ECX:4 (auto)   this
//              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     0043f220(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     0043f224(R)
//              ulong             Stack[0xc]:4   param_3                   XREF[1]:     0043f306(R)
//              ulong             Stack[0x10]:4  param_4                   XREF[1]:     0043f301(R)
//                               ?action@TListDialog@@UAEJPAVTPanel@@JKK@Z                    XREF[3]:     0056fbac(*), 00571da4(*),
//                               TListDialog::action                                                       00576634(*)
//                              dlg_list.cpp:137 (19)
//         0043f220     MOV        EAX,dword ptr [ESP + param_1]
//         0043f224     MOV        EDX,dword ptr [ESP + param_2]
//         0043f228     PUSH       ESI
//         0043f229     MOV        ESI,this
//         0043f22b     TEST       EAX,EAX
//         0043f22d     JZ         LAB_0043f301
//                              dlg_list.cpp:140 (8)
//         0043f233     CMP        EAX,dword ptr [ESI + 0x49c]
//         0043f239     JNZ        LAB_0043f28a
//                              dlg_list.cpp:142 (9)
//         0043f23b     CMP        EDX,0x1
//         0043f23e     JNZ        LAB_0043f301
//                              dlg_list.cpp:144 (11)
//         0043f244     MOV        this,dword ptr [ESI + 0x494]
//         0043f24a     CALL       TTextPanel::currentLineNumber                    int currentLineNumber(TTextPanel * this)
//                              dlg_list.cpp:145 (18)
//         0043f24f     MOV        this,dword ptr [ESI + 0x494]
//         0043f255     MOV        word ptr [ESI + 0x4a4],AX
//         0043f25c     CALL       TTextPanel::currentLine                          char * currentLine(TTextPanel * this)
//                              dlg_list.cpp:146 (17)
//         0043f261     MOV        this,dword ptr [ESI + 0x40]
//         0043f264     MOV        dword ptr [ESI + 0x4a8],EAX
//         0043f26a     TEST       this,this
//         0043f26c     JZ         LAB_0043f2f8
//                              dlg_list.cpp:147 (15)
//         0043f272     MOV        EAX,dword ptr [this->_padding_]
//         0043f274     PUSH       0x0
//         0043f276     PUSH       0x0
//         0043f278     PUSH       0x1
//         0043f27a     PUSH       ESI
//         0043f27b     CALL       dword ptr [EAX + 0xb4]
//                              dlg_list.cpp:148 (5)
//         0043f281     MOV        EAX,0x1
//                              dlg_list.cpp:174 (4)
//         0043f286     POP        ESI
//         0043f287     RET        0x10
//                               LAB_0043f28a                                                 XREF[1]:     0043f239(j)
//                              dlg_list.cpp:151 (8)
//         0043f28a     CMP        EAX,dword ptr [ESI + 0x4a0]
//         0043f290     JNZ        LAB_0043f2b6
//                              dlg_list.cpp:153 (5)
//         0043f292     CMP        EDX,0x1
//         0043f295     JNZ        LAB_0043f301
//                              dlg_list.cpp:155 (7)
//         0043f297     MOV        this,dword ptr [ESI + 0x40]
//         0043f29a     TEST       this,this
//         0043f29c     JZ         LAB_0043f2f8
//                              dlg_list.cpp:156 (15)
//         0043f29e     MOV        EDX,dword ptr [this->_padding_]
//         0043f2a0     PUSH       0x0
//         0043f2a2     PUSH       0x0
//         0043f2a4     PUSH       0x2
//         0043f2a6     PUSH       ESI
//         0043f2a7     CALL       dword ptr [EDX + 0xb4]
//                              dlg_list.cpp:157 (5)
//         0043f2ad     MOV        EAX,0x1
//                              dlg_list.cpp:174 (4)
//         0043f2b2     POP        ESI
//         0043f2b3     RET        0x10
//                               LAB_0043f2b6                                                 XREF[1]:     0043f290(j)
//                              dlg_list.cpp:160 (10)
//         0043f2b6     MOV        this,dword ptr [ESI + 0x494]
//         0043f2bc     CMP        EAX,this
//         0043f2be     JNZ        LAB_0043f301
//                              dlg_list.cpp:162 (5)
//         0043f2c0     CMP        EDX,0x3
//         0043f2c3     JNZ        LAB_0043f301
//                              dlg_list.cpp:164 (5)
//         0043f2c5     CALL       TTextPanel::currentLineNumber                    int currentLineNumber(TTextPanel * this)
//                              dlg_list.cpp:165 (18)
//         0043f2ca     MOV        this,dword ptr [ESI + 0x494]
//         0043f2d0     MOV        word ptr [ESI + 0x4a4],AX
//         0043f2d7     CALL       TTextPanel::currentLine                          char * currentLine(TTextPanel * this)
//                              dlg_list.cpp:166 (13)
//         0043f2dc     MOV        this,dword ptr [ESI + 0x40]
//         0043f2df     MOV        dword ptr [ESI + 0x4a8],EAX
//         0043f2e5     TEST       this,this
//         0043f2e7     JZ         LAB_0043f2f8
//                              dlg_list.cpp:167 (15)
//         0043f2e9     MOV        EAX,dword ptr [this->_padding_]
//         0043f2eb     PUSH       0x0
//         0043f2ed     PUSH       0x0
//         0043f2ef     PUSH       0x1
//         0043f2f1     PUSH       ESI
//         0043f2f2     CALL       dword ptr [EAX + 0xb4]
//                               LAB_0043f2f8                                                 XREF[3]:     0043f26c(j), 0043f29c(j),
//                                                                                                         0043f2e7(j)
//                              dlg_list.cpp:168 (5)
//         0043f2f8     MOV        EAX,0x1
//                              dlg_list.cpp:174 (4)
//         0043f2fd     POP        ESI
//         0043f2fe     RET        0x10
//                               LAB_0043f301                                                 XREF[5]:     0043f22d(j), 0043f23e(j),
//                                                                                                         0043f295(j), 0043f2be(j),
//                                                                                                         0043f2c3(j)
//                              dlg_list.cpp:173 (19)
//         0043f301     MOV        this,dword ptr [ESP + param_4]
//         0043f305     PUSH       this
//         0043f306     MOV        this,dword ptr [ESP + param_3]
//         0043f30a     PUSH       this
//         0043f30b     PUSH       EDX
//         0043f30c     PUSH       EAX
//         0043f30d     MOV        this,ESI
//         0043f30f     CALL       TEasy_Panel::action                              long action(TEasy_Panel * this, TPanel * para
//                              dlg_list.cpp:174 (4)
//         0043f314     POP        ESI
//         0043f315     RET        0x10
//         0043f318     ??         90h
//         0043f319     NOP
//         0043f31a     NOP
//         0043f31b     NOP
//         0043f31c     NOP
//         0043f31d     NOP
//         0043f31e     NOP
//         0043f31f     NOP
    return 0;
}

