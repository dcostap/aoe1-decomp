// Auto-generated scaffold unit: Debuglog.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/Debuglog.cpp
#include "../include/common.h"

// Offset: 0x00436220
undefined TDebuggingLog(TDebuggingLog* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TDebuggingLog::TDebuggingLog(void)                                                 *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TDebuggingLog(TDebuggingLog * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TDebuggingLog *   ECX:4 (auto)   this
    //                               ??0TDebuggingLog@@QAE@XZ                                     XREF[1]:     setup_debugging_log:0041ee18(c)  
    //                               TDebuggingLog::TDebuggingLog
    //                              Debuglog.cpp:45 (4)
    //         00436220     PUSH       EBX
    //         00436221     PUSH       ESI
    //         00436222     MOV        EBX,this
    //                              Debuglog.cpp:47 (3)
    //         00436224     XOR        ESI,ESI
    //         00436226     PUSH       EDI
    //                              Debuglog.cpp:52 (18)
    //         00436227     PUSH       ESI
    //         00436228     MOV        dword ptr [EBX + 0x8],ESI
    //         0043622b     MOV        dword ptr [EBX + 0xc],ESI
    //         0043622e     MOV        dword ptr [EBX + 0x1c],ESI
    //         00436231     MOV        dword ptr [EBX + 0x18],ESI
    //         00436234     CALL       TDebuggingLog::LogSequence                       void LogSequence(TDebuggingLog * this, int pa
    //                              Debuglog.cpp:53 (8)
    //         00436239     PUSH       ESI
    //         0043623a     MOV        this,EBX
    //         0043623c     CALL       TDebuggingLog::LogTimestamp                      void LogTimestamp(TDebuggingLog * this, int p
    //                              Debuglog.cpp:54 (8)
    //         00436241     PUSH       ESI
    //         00436242     MOV        this,EBX
    //         00436244     CALL       TDebuggingLog::LogDateTimestamp                  void LogDateTimestamp(TDebuggingLog * this, i
    //                              Debuglog.cpp:55 (8)
    //         00436249     PUSH       ESI
    //         0043624a     MOV        this,EBX
    //         0043624c     CALL       TDebuggingLog::FlushToDisk                       void FlushToDisk(TDebuggingLog * this, int pa
    //                              Debuglog.cpp:58 (7)
    //         00436251     MOV        this,EBX
    //         00436253     CALL       TDebuggingLog::OpenLog                           void OpenLog(TDebuggingLog * this)
    //                              Debuglog.cpp:59 (14)
    //         00436258     PUSH       s_===Logging===                                  = "===Logging==="
    //         0043625d     PUSH       EBX
    //         0043625e     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00436263     ADD        ESP,0x8
    //                              Debuglog.cpp:60 (7)
    //         00436266     MOV        this,EBX
    //         00436268     CALL       TDebuggingLog::Time                              void Time(TDebuggingLog * this)
    //                              Debuglog.cpp:61 (35)
    //         0043626d     MOV        EDI,s_C:\APPLOGERR.TXT                           = 43h
    //         00436272     OR         this,0xffffffff
    //         00436275     XOR        EAX,EAX
    //         00436277     LEA        EDX,[EBX + 0x730]
    //         0043627d     SCASB.RE   ES:EDI=>s_C:\APPLOGERR.TXT                       = 43h
    //                                                                                  = ":\\APPLOGERR.TXT"
    //         0043627f     NOT        this
    //         00436281     SUB        EDI,this
    //         00436283     MOV        EAX,this
    //         00436285     MOV        ESI,EDI
    //         00436287     MOV        EDI,EDX
    //         00436289     SHR        this,0x2
    //         0043628c     MOVSD.REP  ES:EDI,ESI
    //         0043628e     MOV        this,EAX
    //                              Debuglog.cpp:62 (11)
    //         00436290     MOV        EAX,EBX
    //         00436292     AND        this,0x3
    //         00436295     MOVSB.REP  ES:EDI,ESI
    //         00436297     POP        EDI
    //         00436298     POP        ESI
    //         00436299     POP        EBX
    //         0043629a     RET
}

// Offset: 0x004362A0
void TDebuggingLog(TDebuggingLog* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TDebuggingLog::~TDebuggingLog(void)                                                *
    //                              *********************************************************************************************************
    //                              void __thiscall ~TDebuggingLog(TDebuggingLog * this)
    //              void              <VOID>         <RETURN>
    //              TDebuggingLog *   ECX:4 (auto)   this
    //                               ??1TDebuggingLog@@QAE@XZ                                     XREF[1]:     ~RGE_Base_Game:0041c685(c)  
    //                               TDebuggingLog::~TDebuggingLog
    //                              Debuglog.cpp:66 (5)
    //         004362a0     JMP        TDebuggingLog::CloseLog
}

// Offset: 0x004362B0
void LogFile(TDebuggingLog* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDebuggingLog::LogFile(int)                                                   *
    //                              *********************************************************************************************************
    //                              void __thiscall LogFile(TDebuggingLog * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              TDebuggingLog *   ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004362b0(R)  
    //                               ?LogFile@TDebuggingLog@@QAEXH@Z                              XREF[2]:     setup_cmd_options:0041e47d(c), 
    //                               TDebuggingLog::LogFile                                                    setup_debugging_log:0041ee4c(c)  
    //                              Debuglog.cpp:71 (11)
    //         004362b0     MOV        EAX,dword ptr [ESP + param_1]
    //         004362b4     PUSH       ESI
    //         004362b5     TEST       EAX,EAX
    //         004362b7     MOV        ESI,this
    //         004362b9     JZ         LAB_004362c4
    //                              Debuglog.cpp:73 (7)
    //         004362bb     MOV        dword ptr [ESI + 0x8],0x1
    //                              Debuglog.cpp:74 (2)
    //         004362c2     JMP        LAB_004362cb
    //                               LAB_004362c4                                                 XREF[1]:     004362b9(j)  
    //                              Debuglog.cpp:75 (7)
    //         004362c4     MOV        dword ptr [ESI + 0x8],0x0
    //                               LAB_004362cb                                                 XREF[1]:     004362c2(j)  
    //                              Debuglog.cpp:77 (23)
    //         004362cb     PUSH       EAX
    //         004362cc     MOV        this,ESI
    //         004362ce     CALL       TDebuggingLog::YesOrNo                           char * YesOrNo(TDebuggingLog * this, int para
    //         004362d3     PUSH       EAX
    //         004362d4     PUSH       s_Logging_to_File_%s                             = "Logging to File %s"
    //         004362d9     PUSH       ESI
    //         004362da     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         004362df     ADD        ESP,0xc
    //                              Debuglog.cpp:79 (4)
    //         004362e2     POP        ESI
    //         004362e3     RET        0x4
}

// Offset: 0x004362F0
void LogOutput(TDebuggingLog* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDebuggingLog::LogOutput(int)                                                 *
    //                              *********************************************************************************************************
    //                              void __thiscall LogOutput(TDebuggingLog * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              TDebuggingLog *   ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004362f0(R)  
    //                               ?LogOutput@TDebuggingLog@@QAEXH@Z                            XREF[2]:     setup_cmd_options:0041e4e1(c), 
    //                               TDebuggingLog::LogOutput                                                  setup_debugging_log:0041ee5e(c)  
    //                              Debuglog.cpp:82 (11)
    //         004362f0     MOV        EAX,dword ptr [ESP + param_1]
    //         004362f4     PUSH       ESI
    //         004362f5     TEST       EAX,EAX
    //         004362f7     MOV        ESI,this
    //         004362f9     JZ         LAB_00436304
    //                              Debuglog.cpp:84 (7)
    //         004362fb     MOV        dword ptr [ESI + 0xc],0x1
    //                              Debuglog.cpp:85 (2)
    //         00436302     JMP        LAB_0043630b
    //                               LAB_00436304                                                 XREF[1]:     004362f9(j)  
    //                              Debuglog.cpp:86 (7)
    //         00436304     MOV        dword ptr [ESI + 0xc],0x0
    //                               LAB_0043630b                                                 XREF[1]:     00436302(j)  
    //                              Debuglog.cpp:88 (23)
    //         0043630b     PUSH       EAX
    //         0043630c     MOV        this,ESI
    //         0043630e     CALL       TDebuggingLog::YesOrNo                           char * YesOrNo(TDebuggingLog * this, int para
    //         00436313     PUSH       EAX
    //         00436314     PUSH       s_Logging_to_OUTPUT_%s                           = "Logging to OUTPUT %s"
    //         00436319     PUSH       ESI
    //         0043631a     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         0043631f     ADD        ESP,0xc
    //                              Debuglog.cpp:90 (4)
    //         00436322     POP        ESI
    //         00436323     RET        0x4
}

// Offset: 0x00436330
void LogTimestamp(TDebuggingLog* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDebuggingLog::LogTimestamp(int)                                              *
    //                              *********************************************************************************************************
    //                              void __thiscall LogTimestamp(TDebuggingLog * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              TDebuggingLog *   ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00436333(R)  
    //                               ?LogTimestamp@TDebuggingLog@@QAEXH@Z                         XREF[3]:     setup_cmd_options:0041e489(c), 
    //                               TDebuggingLog::LogTimestamp                                               setup_debugging_log:0041ee6b(c), 
    //                                                                                                         TDebuggingLog:0043623c(c)  
    //                              Debuglog.cpp:93 (3)
    //         00436330     PUSH       ESI
    //         00436331     MOV        ESI,this
    //                              Debuglog.cpp:94 (11)
    //         00436333     MOV        this,dword ptr [ESP + param_1]
    //         00436337     XOR        EAX,EAX
    //         00436339     TEST       this,this
    //         0043633b     SETNZ      AL
    //                              Debuglog.cpp:99 (27)
    //         0043633e     MOV        this,EAX
    //         00436340     MOV        dword ptr [ESI],EAX
    //         00436342     PUSH       this
    //         00436343     MOV        this,ESI
    //         00436345     CALL       TDebuggingLog::YesOrNo                           char * YesOrNo(TDebuggingLog * this, int para
    //         0043634a     PUSH       EAX
    //         0043634b     PUSH       s_Timestamp_milliseconds_%s                      = "Timestamp milliseconds %s"
    //         00436350     PUSH       ESI
    //         00436351     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00436356     ADD        ESP,0xc
    //                              Debuglog.cpp:100 (4)
    //         00436359     POP        ESI
    //         0043635a     RET        0x4
}

// Offset: 0x00436360
void LogDateTimestamp(TDebuggingLog* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDebuggingLog::LogDateTimestamp(int)                                          *
    //                              *********************************************************************************************************
    //                              void __thiscall LogDateTimestamp(TDebuggingLog * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              TDebuggingLog *   ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00436360(R)  
    //                               ?LogDateTimestamp@TDebuggingLog@@QAEXH@Z                     XREF[1]:     TDebuggingLog:00436244(c)  
    //                               TDebuggingLog::LogDateTimestamp
    //                              Debuglog.cpp:103 (11)
    //         00436360     MOV        EAX,dword ptr [ESP + param_1]
    //         00436364     PUSH       ESI
    //         00436365     TEST       EAX,EAX
    //         00436367     MOV        ESI,this
    //         00436369     JZ         LAB_00436374
    //                              Debuglog.cpp:105 (7)
    //         0043636b     MOV        dword ptr [ESI + 0x4],0x1
    //                              Debuglog.cpp:106 (2)
    //         00436372     JMP        LAB_0043637b
    //                               LAB_00436374                                                 XREF[1]:     00436369(j)  
    //                              Debuglog.cpp:107 (7)
    //         00436374     MOV        dword ptr [ESI + 0x4],0x0
    //                               LAB_0043637b                                                 XREF[1]:     00436372(j)  
    //                              Debuglog.cpp:109 (25)
    //         0043637b     MOV        EAX,dword ptr [ESI]
    //         0043637d     MOV        this,ESI
    //         0043637f     PUSH       EAX
    //         00436380     CALL       TDebuggingLog::YesOrNo                           char * YesOrNo(TDebuggingLog * this, int para
    //         00436385     PUSH       EAX
    //         00436386     PUSH       s_Date_&_Time_stamp%s                            = "Date & Time stamp%s"
    //         0043638b     PUSH       ESI
    //         0043638c     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00436391     ADD        ESP,0xc
    //                              Debuglog.cpp:110 (4)
    //         00436394     POP        ESI
    //         00436395     RET        0x4
}

// Offset: 0x004363A0
void Time(TDebuggingLog* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDebuggingLog::Time(void)                                                     *
    //                              *********************************************************************************************************
    //                              void __thiscall Time(TDebuggingLog * this)
    //              void              <VOID>         <RETURN>
    //              TDebuggingLog *   ECX:4 (auto)   this
    //              undefined8        Stack[-0x8]:8  local_8                   XREF[4,1]:   004363df(W), 004363e3(R), 004363ef(W), 00436405(R), 
    //                                                                                     004363d2(W)  
    //              float             Stack[-0xc]:4  fTicksElapsed             XREF[2]:     004363b8(*), 004363c5(*)  
    //              long              Stack[-0x10]:4 ltime
    //              undefined8        Stack[-0x1c]:8 local_1c                  XREF[1]:     0043640c(*)  
    //                               ?Time@TDebuggingLog@@QAEXXZ                                  XREF[7]:     TCommunications_Handler:00425ef2(c
    //                               TDebuggingLog::Time                                                       DestroyMultiplayerGame:0042b8f3(c)
    //                                                                                                         UnlinkCurrentLevel:0042bbbb(c), 
    //                                                                                                         UnlinkCurrentLevel:0042be35(c), 
    //                                                                                                         TDebuggingLog:00436268(c), 
    //                                                                                                         OpenLog:0043658e(c), 
    //                                                                                                         CloseLog:004365e5(c)  
    //                              Debuglog.cpp:114 (5)
    //         004363a0     SUB        ESP,0xc
    //         004363a3     PUSH       ESI
    //         004363a4     PUSH       EDI
    //                              language.dll match for 0x78: "10"
    //                              Debuglog.cpp:120 (19)
    //         004363a5     PUSH       0x78
    //         004363a7     MOV        EDI,this
    //         004363a9     PUSH       s_C:\msdev\work\age1_x1\Debuglog.c               = "C:\\msdev\\work\\age1_x1\\Debuglog.cpp"
    //         004363ae     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //         004363b3     ADD        ESP,0x8
    //         004363b6     MOV        ESI,EAX
    //                              Debuglog.cpp:121 (13)
    //         004363b8     LEA        EAX=>fTicksElapsed,[ESP + 0x8]
    //         004363bc     PUSH       EAX
    //         004363bd     CALL       time                                             undefined time()
    //         004363c2     ADD        ESP,0x4
    //                              Debuglog.cpp:122 (10)
    //         004363c5     LEA        this=>fTicksElapsed,[ESP + 0x8]
    //         004363c9     PUSH       this
    //         004363ca     CALL       localtime                                        undefined localtime()
    //                              Debuglog.cpp:126 (24)
    //         004363cf     MOV        EDX,dword ptr [EDI + 0x20]
    //         004363d2     MOV        dword ptr [ESP + local_8+0x4],0x0
    //         004363da     SUB        ESI,EDX
    //         004363dc     ADD        ESP,0x4
    //         004363df     MOV        dword ptr [ESP + local_8],ESI
    //         004363e3     FILD       qword ptr [ESP + local_8]
    //                              Debuglog.cpp:128 (55)
    //         004363e7     TEST       EAX,EAX
    //         004363e9     FMUL       float ptr [DAT_0056f500]                         = 6Fh    o
    //         004363ef     FSTP       float ptr [ESP + local_8]
    //         004363f3     JNZ        LAB_004363fc
    //         004363f5     MOV        EAX,s_?                                          = "?"
    //         004363fa     JMP        LAB_00436405
    //                               LAB_004363fc                                                 XREF[1]:     004363f3(j)  
    //         004363fc     PUSH       EAX
    //         004363fd     CALL       asctime                                          undefined asctime()
    //         00436402     ADD        ESP,0x4
    //                               LAB_00436405                                                 XREF[1]:     004363fa(j)  
    //         00436405     FLD        float ptr [ESP + local_8]
    //         00436409     SUB        ESP,0x8
    //         0043640c     FSTP       double ptr [ESP]=>local_1c
    //         0043640f     PUSH       EAX=>s_?                                         = "?"
    //         00436410     PUSH       s_>>>TIME>>>__%s___[%7.1f_sec._ela               = ">>>TIME>>>  %s   [%7.1f sec. elapsed]"
    //         00436415     PUSH       EDI
    //         00436416     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         0043641b     ADD        ESP,0x14
    //                              Debuglog.cpp:129 (6)
    //         0043641e     POP        EDI
    //         0043641f     POP        ESI
    //         00436420     ADD        ESP,0xc
    //         00436423     RET
}

// Offset: 0x00436430
void FlushToDisk(TDebuggingLog* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDebuggingLog::FlushToDisk(int)                                               *
    //                              *********************************************************************************************************
    //                              void __thiscall FlushToDisk(TDebuggingLog * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              TDebuggingLog *   ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00436430(R)  
    //                               ?FlushToDisk@TDebuggingLog@@QAEXH@Z                          XREF[2]:     TCommunications_Handler:00425a66(c
    //                               TDebuggingLog::FlushToDisk                                                TDebuggingLog:0043624c(c)  
    //                              Debuglog.cpp:132 (11)
    //         00436430     MOV        EAX,dword ptr [ESP + param_1]
    //         00436434     PUSH       ESI
    //         00436435     TEST       EAX,EAX
    //         00436437     MOV        ESI,this
    //         00436439     JZ         LAB_00436444
    //                              Debuglog.cpp:134 (7)
    //         0043643b     MOV        dword ptr [ESI + 0x14],0x1
    //                              Debuglog.cpp:135 (2)
    //         00436442     JMP        LAB_0043644b
    //                               LAB_00436444                                                 XREF[1]:     00436439(j)  
    //                              Debuglog.cpp:136 (7)
    //         00436444     MOV        dword ptr [ESI + 0x14],0x0
    //                               LAB_0043644b                                                 XREF[1]:     00436442(j)  
    //                              Debuglog.cpp:138 (26)
    //         0043644b     MOV        EAX,dword ptr [ESI + 0x14]
    //         0043644e     MOV        this,ESI
    //         00436450     PUSH       EAX
    //         00436451     CALL       TDebuggingLog::YesOrNo                           char * YesOrNo(TDebuggingLog * this, int para
    //         00436456     PUSH       EAX
    //         00436457     PUSH       s_Flush_queue_each_message_%s                    = "Flush queue each message %s"
    //         0043645c     PUSH       ESI
    //         0043645d     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00436462     ADD        ESP,0xc
    //                              Debuglog.cpp:139 (4)
    //         00436465     POP        ESI
    //         00436466     RET        0x4
}

// Offset: 0x00436470
void LogSequence(TDebuggingLog* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDebuggingLog::LogSequence(int)                                               *
    //                              *********************************************************************************************************
    //                              void __thiscall LogSequence(TDebuggingLog * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              TDebuggingLog *   ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00436473(R)  
    //                               ?LogSequence@TDebuggingLog@@QAEXH@Z                          XREF[1]:     TDebuggingLog:00436234(c)  
    //                               TDebuggingLog::LogSequence
    //                              Debuglog.cpp:142 (3)
    //         00436470     PUSH       ESI
    //         00436471     MOV        ESI,this
    //                              Debuglog.cpp:143 (10)
    //         00436473     MOV        this,dword ptr [ESP + param_1]
    //         00436477     XOR        EAX,EAX
    //         00436479     CMP        this,EAX
    //         0043647b     JZ         LAB_00436489
    //                              Debuglog.cpp:145 (7)
    //         0043647d     MOV        dword ptr [ESI + 0x10],0x1
    //                              Debuglog.cpp:146 (3)
    //         00436484     MOV        dword ptr [ESI + 0x24],EAX
    //                              Debuglog.cpp:148 (2)
    //         00436487     JMP        LAB_0043648c
    //                               LAB_00436489                                                 XREF[1]:     0043647b(j)  
    //                              Debuglog.cpp:149 (3)
    //         00436489     MOV        dword ptr [ESI + 0x10],EAX
    //                               LAB_0043648c                                                 XREF[1]:     00436487(j)  
    //                              Debuglog.cpp:151 (26)
    //         0043648c     MOV        EAX,dword ptr [ESI + 0x10]
    //         0043648f     MOV        this,ESI
    //         00436491     PUSH       EAX
    //         00436492     CALL       TDebuggingLog::YesOrNo                           char * YesOrNo(TDebuggingLog * this, int para
    //         00436497     PUSH       EAX
    //         00436498     PUSH       s_Sequence_numbering%s                           = "Sequence numbering%s"
    //         0043649d     PUSH       ESI
    //         0043649e     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         004364a3     ADD        ESP,0xc
    //                              Debuglog.cpp:152 (4)
    //         004364a6     POP        ESI
    //         004364a7     RET        0x4
}

// Offset: 0x004364B0
void OpenLog(TDebuggingLog* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDebuggingLog::OpenLog(void)                                                  *
    //                              *********************************************************************************************************
    //                              void __thiscall OpenLog(TDebuggingLog * this)
    //              void              <VOID>         <RETURN>
    //              TDebuggingLog *   ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     004364ee(W), 004364f4(R), 0043654e(R), 00436556(W)  
    //              int               Stack[-0x8]:4  nLoop
    //                               ?OpenLog@TDebuggingLog@@QAEXXZ                               XREF[2]:     TDebuggingLog:00436253(c), 
    //                               TDebuggingLog::OpenLog                                                    Log:00436647(c)  
    //                              Debuglog.cpp:156 (7)
    //         004364b0     PUSH       this
    //         004364b1     PUSH       EBX
    //         004364b2     PUSH       EBP
    //         004364b3     MOV        EBP,this
    //         004364b5     PUSH       ESI
    //         004364b6     PUSH       EDI
    //                              Debuglog.cpp:157 (11)
    //         004364b7     MOV        EAX,dword ptr [EBP + 0x8]
    //         004364ba     TEST       EAX,EAX
    //         004364bc     JZ         LAB_00436599
    //                              Debuglog.cpp:160 (18)
    //         004364c2     MOV        EAX,dword ptr [EBP + 0x18]
    //         004364c5     TEST       EAX,EAX
    //         004364c7     JZ         LAB_004364d4
    //         004364c9     MOV        EAX,dword ptr [EBP + 0x1c]
    //         004364cc     TEST       EAX,EAX
    //         004364ce     JZ         LAB_00436599
    //                               LAB_004364d4                                                 XREF[1]:     004364c7(j)  
    //                              Debuglog.cpp:163 (18)
    //         004364d4     PUSH       0xa3
    //         004364d9     PUSH       s_C:\msdev\work\age1_x1\Debuglog.c               = "C:\\msdev\\work\\age1_x1\\Debuglog.cpp"
    //         004364de     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //         004364e3     MOV        dword ptr [EBP + 0x20],EAX
    //                              Debuglog.cpp:169 (18)
    //         004364e6     MOV        EAX,0x1
    //         004364eb     ADD        ESP,0x8
    //         004364ee     MOV        dword ptr [ESP + local_4],EAX
    //         004364f2     JMP        LAB_004364f8
    //                               LAB_004364f4                                                 XREF[1]:     0043655a(j)  
    //         004364f4     MOV        EAX,dword ptr [ESP + local_4]
    //                               LAB_004364f8                                                 XREF[1]:     004364f2(j)  
    //                              Debuglog.cpp:171 (3)
    //         004364f8     CMP        EAX,0x1
    //                              Debuglog.cpp:172 (42)
    //         004364fb     LEA        EBX,[EBP + 0x730]
    //         00436501     JNZ        LAB_00436527
    //         00436503     MOV        EDI,s_C:\AOELOG.txt                              = 43h
    //         00436508     OR         this,0xffffffff
    //         0043650b     XOR        EAX,EAX
    //         0043650d     SCASB.RE   ES:EDI=>s_C:\AOELOG.txt                          = 43h
    //                                                                                  = ":\\AOELOG.txt"
    //         0043650f     NOT        this
    //         00436511     SUB        EDI,this
    //         00436513     MOV        EAX,this
    //         00436515     MOV        ESI,EDI
    //         00436517     MOV        EDI,EBX
    //         00436519     SHR        this,0x2
    //         0043651c     MOVSD.REP  ES:EDI,ESI
    //         0043651e     MOV        this,EAX
    //         00436520     AND        this,0x3
    //         00436523     MOVSB.REP  ES:EDI,ESI
    //                              Debuglog.cpp:173 (2)
    //         00436525     JMP        LAB_00436537
    //                               LAB_00436527                                                 XREF[1]:     00436501(j)  
    //                              Debuglog.cpp:174 (16)
    //         00436527     DEC        EAX
    //         00436528     PUSH       EAX
    //         00436529     PUSH       s_C:\AOELOG%.2d.txt                              = "C:\\AOELOG%.2d.txt"
    //         0043652e     PUSH       EBX
    //         0043652f     CALL       sprintf                                          undefined sprintf()
    //         00436534     ADD        ESP,0xc
    //                               LAB_00436537                                                 XREF[1]:     00436525(j)  
    //                              Debuglog.cpp:176 (19)
    //         00436537     PUSH       s_wt                                             = "wt"
    //         0043653c     PUSH       EBX
    //         0043653d     CALL       fopen                                            undefined fopen()
    //         00436542     ADD        ESP,0x8
    //         00436545     MOV        [logstream],EAX                                  = 00000000
    //                              Debuglog.cpp:178 (18)
    //         0043654a     TEST       EAX,EAX
    //         0043654c     JNZ        LAB_00436570
    //         0043654e     MOV        EAX,dword ptr [ESP + local_4]
    //         00436552     INC        EAX
    //         00436553     CMP        EAX,0x19
    //         00436556     MOV        dword ptr [ESP + local_4],EAX
    //         0043655a     JLE        LAB_004364f4
    //                              Debuglog.cpp:187 (7)
    //         0043655c     MOV        dword ptr [EBP + 0x1c],0x1
    //                              Debuglog.cpp:188 (7)
    //         00436563     MOV        dword ptr [EBP + 0x18],0x0
    //                              Debuglog.cpp:191 (6)
    //         0043656a     POP        EDI
    //         0043656b     POP        ESI
    //         0043656c     POP        EBP
    //         0043656d     POP        EBX
    //         0043656e     POP        this
    //         0043656f     RET
    //                               LAB_00436570                                                 XREF[1]:     0043654c(j)  
    //                              Debuglog.cpp:181 (28)
    //         00436570     LEA        this,[EBP + 0x730]
    //         00436576     MOV        dword ptr [EBP + 0x18],0x1
    //         0043657d     PUSH       this
    //         0043657e     PUSH       s_Log_file_%s_is_opened                          = "Log file %s is opened"
    //         00436583     PUSH       EBP
    //         00436584     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00436589     ADD        ESP,0xc
    //                              Debuglog.cpp:182 (7)
    //         0043658c     MOV        this,EBP
    //         0043658e     CALL       TDebuggingLog::Time                              void Time(TDebuggingLog * this)
    //                              Debuglog.cpp:191 (12)
    //         00436593     POP        EDI
    //         00436594     POP        ESI
    //         00436595     POP        EBP
    //         00436596     POP        EBX
    //         00436597     POP        this
    //         00436598     RET
    //                               LAB_00436599                                                 XREF[2]:     004364bc(j), 004364ce(j)  
    //         00436599     POP        EDI
    //         0043659a     POP        ESI
    //         0043659b     POP        EBP
    //         0043659c     POP        EBX
    //         0043659d     POP        this
    //         0043659e     RET
}

// Offset: 0x004365A0
void FlushLog(TDebuggingLog* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDebuggingLog::FlushLog(void)                                                 *
    //                              *********************************************************************************************************
    //                              void __thiscall FlushLog(TDebuggingLog * this)
    //              void              <VOID>         <RETURN>
    //              TDebuggingLog *   ECX:4 (auto)   this
    //                               ?FlushLog@TDebuggingLog@@QAEXXZ                              XREF[2]:     EvaluateSystemMessage:00428eb0(c), 
    //                               TDebuggingLog::FlushLog                                                   DoChecksum:00433439(c)  
    //                              Debuglog.cpp:194 (7)
    //         004365a0     MOV        EAX,dword ptr [ECX + this->LogToFile]
    //         004365a3     TEST       EAX,EAX
    //         004365a5     JZ         LAB_004365b5
    //                              Debuglog.cpp:197 (14)
    //         004365a7     MOV        EAX,[logstream]                                  = 00000000
    //         004365ac     PUSH       EAX
    //         004365ad     CALL       fflush                                           undefined fflush()
    //         004365b2     ADD        ESP,0x4
    //                               LAB_004365b5                                                 XREF[1]:     004365a5(j)  
    //                              Debuglog.cpp:198 (1)
    //         004365b5     RET
}

// Offset: 0x004365C0
void CloseLog(TDebuggingLog* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TDebuggingLog::CloseLog(void)                                                 *
    //                              *********************************************************************************************************
    //                              void __thiscall CloseLog(TDebuggingLog * this)
    //              void              <VOID>         <RETURN>
    //              TDebuggingLog *   ECX:4 (auto)   this
    //                               ?CloseLog@TDebuggingLog@@QAEXXZ                              XREF[1]:     CloseLog:0043629b(T), 
    //                               TDebuggingLog::CloseLog                                                   ~TDebuggingLog:004362a0(j)  
    //                              Debuglog.cpp:201 (3)
    //         004365c0     PUSH       ESI
    //         004365c1     MOV        ESI,this
    //                              Debuglog.cpp:203 (7)
    //         004365c3     MOV        EAX,dword ptr [ESI + 0x8]
    //         004365c6     TEST       EAX,EAX
    //         004365c8     JZ         LAB_0043660d
    //                              Debuglog.cpp:206 (10)
    //         004365ca     LEA        EAX,[ESI + 0x730]
    //         004365d0     TEST       EAX,EAX
    //         004365d2     JZ         LAB_004365e3
    //                              Debuglog.cpp:207 (15)
    //         004365d4     PUSH       EAX
    //         004365d5     PUSH       s_Closing_debug_log_file_'%s'.                   = "Closing debug log file '%s'."
    //         004365da     PUSH       ESI
    //         004365db     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         004365e0     ADD        ESP,0xc
    //                               LAB_004365e3                                                 XREF[1]:     004365d2(j)  
    //                              Debuglog.cpp:209 (7)
    //         004365e3     MOV        this,ESI
    //         004365e5     CALL       TDebuggingLog::Time                              void Time(TDebuggingLog * this)
    //                              Debuglog.cpp:210 (11)
    //         004365ea     PUSH       s_Log_file_is_closed                             = "Log file is closed"
    //         004365ef     PUSH       ESI
    //         004365f0     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //                              Debuglog.cpp:211 (17)
    //         004365f5     MOV        EAX,[logstream]                                  = 00000000
    //         004365fa     ADD        ESP,0x8
    //         004365fd     PUSH       EAX
    //         004365fe     CALL       fclose                                           undefined fclose()
    //         00436603     ADD        ESP,0x4
    //                              Debuglog.cpp:212 (7)
    //         00436606     MOV        dword ptr [ESI + 0x18],0x0
    //                               LAB_0043660d                                                 XREF[1]:     004365c8(j)  
    //                              Debuglog.cpp:213 (2)
    //         0043660d     POP        ESI
    //         0043660e     RET
}

// Offset: 0x00436610
void Log(TDebuggingLog* this_, char* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __cdecl TDebuggingLog::Log(char *,...)                                                   *
    //                              *********************************************************************************************************
    //                              void __thiscall Log(TDebuggingLog * this, char * param_1, ...)
    //              void              <VOID>         <RETURN>
    //              TDebuggingLog *   ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     00436618(R)  
    //              char[32]          Stack[-0x24]   s1
    //              char[32]          Stack[-0x44]   s4
    //              char[32]          Stack[-0x64]   s3
    //              char[32]          Stack[-0x84]   s2
    //              long              Stack[-0x88]:4 ltime
    //                               ?Log@TDebuggingLog@@QAAXPADZZ                                XREF[549]:   ShowReturn:00424ed2(c), 
    //                               TDebuggingLog::Log                                                        ShowReturn:00424eff(c), 
    //                                                                                                         ShowReturn:00424f19(c), 
    //                                                                                                         ShowReturn:00424fdd(c), 
    //                                                                                                         ShowReturn:00425015(c), 
    //                                                                                                         ShowReturn:0042503f(c), 
    //                                                                                                         ShowReturn:0042506f(c), 
    //                                                                                                         ShowReturn:00425088(c), 
    //                                                                                                         ShowReturn:004250c9(c), 
    //                                                                                                         ShowReturn:004250f8(c), 
    //                                                                                                         ShowReturn:00425139(c), 
    //                                                                                                         ShowReturn:00425152(c), 
    //                                                                                                         ShowReturn:00425182(c), 
    //                                                                                                         ShowReturn:0042519c(c), 
    //                                                                                                         ShowReturn:004251af(c), 
    //                                                                                                         ShowReturn:004251df(c), 
    //                                                                                                         ShowReturn:004251f9(c), 
    //                                                                                                         ShowReturn:00425228(c), 
    //                                                                                                         ShowReturn:00425242(c), 
    //                                                                                                         NewCommand:00426559(c), [more]
    //                              Debuglog.cpp:216 (8)
    //         00436610     SUB        ESP,0x8c
    //         00436616     PUSH       EBX
    //         00436617     PUSH       EBP
    //                              Debuglog.cpp:224 (27)
    //         00436618     MOV        EBP,dword ptr [ESP + param_1]
    //         0043661f     PUSH       ESI
    //         00436620     XOR        ESI,ESI
    //         00436622     PUSH       EDI
    //         00436623     MOV        EAX,dword ptr [EBP + 0x8]
    //         00436626     CMP        EAX,ESI
    //         00436628     JNZ        LAB_00436633
    //         0043662a     CMP        dword ptr [EBP + 0xc],ESI
    //         0043662d     JZ         LAB_004367f9
    //                               LAB_00436633                                                 XREF[1]:     00436628(j)  
    //                              Debuglog.cpp:227 (9)
    //         00436633     CMP        dword ptr [EBP + 0x1c],ESI
    //         00436636     JNZ        LAB_004367f9
    //                              Debuglog.cpp:230 (9)
    //         0043663c     CMP        dword ptr [EBP + 0x18],ESI
    //         0043663f     JNZ        LAB_0043664c
    //         00436641     CMP        EAX,ESI
    //         00436643     JZ         LAB_0043664c
    //                              Debuglog.cpp:231 (7)
    //         00436645     MOV        this,EBP
    //         00436647     CALL       TDebuggingLog::OpenLog                           void OpenLog(TDebuggingLog * this)
    //                               LAB_0043664c                                                 XREF[2]:     0043663f(j), 00436643(j)  
    //                              Debuglog.cpp:233 (10)
    //         0043664c     CMP        dword ptr [EBP + 0x18],ESI
    //         0043664f     JNZ        LAB_00436668
    //         00436651     CMP        dword ptr [EBP + 0x8],ESI
    //         00436654     JZ         LAB_00436668
    //                              Debuglog.cpp:235 (7)
    //         00436656     MOV        dword ptr [EBP + 0x1c],0x1
    //                              Debuglog.cpp:296 (11)
    //         0043665d     POP        EDI
    //         0043665e     POP        ESI
    //         0043665f     POP        EBP
    //         00436660     POP        EBX
    //         00436661     ADD        ESP,0x8c
    //         00436667     RET
    //                               LAB_00436668                                                 XREF[2]:     0043664f(j), 00436654(j)  
    //                              Debuglog.cpp:239 (3)
    //         00436668     MOV        EDX,dword ptr [EBP + 0x24]
    //                              Debuglog.cpp:244 (32)
    //         0043666b     MOV        this,dword ptr [ESP + Stack[0x8]]
    //         00436672     LEA        EAX=>Stack[0xc],[ESP + 0xa8]
    //         00436679     LEA        EBX,[EBP + 0x28]
    //         0043667c     PUSH       EAX
    //         0043667d     INC        EDX
    //         0043667e     PUSH       this
    //         0043667f     PUSH       EBX
    //         00436680     MOV        dword ptr [EBP + 0x24],EDX
    //         00436683     CALL       vsprintf                                         undefined vsprintf()
    //         00436688     ADD        ESP,0xc
    //                              Debuglog.cpp:246 (17)
    //         0043668b     CALL       dword ptr [->KERNEL32.DLL::GetTickCount]         = 0048aaac
    //         00436691     MOV        EDX,dword ptr [EBP + 0x20]
    //         00436694     MOV        dword ptr [ESP + 0x10],EAX
    //         00436698     MOV        dword ptr [ESP + 0x14],ESI
    //                              Debuglog.cpp:251 (49)
    //         0043669c     MOV        EAX,dword ptr [EBP]
    //         0043669f     FILD       qword ptr [ESP + 0x10]
    //         004366a3     MOV        dword ptr [ESP + 0x10],EDX
    //         004366a7     MOV        dword ptr [ESP + 0x14],ESI
    //         004366ab     CMP        EAX,ESI
    //         004366ad     MOV        byte ptr [ESP + 0x5c],0x0
    //         004366b2     FISUB      dword ptr [ESP + 0x10]
    //         004366b6     MOV        byte ptr [ESP + 0x3c],0x0
    //         004366bb     MOV        byte ptr [ESP + 0x1c],0x0
    //         004366c0     MOV        byte ptr [ESP + 0x7c],0x0
    //         004366c5     FMUL       float ptr [DAT_0056f500]                         = 6Fh    o
    //         004366cb     JZ         LAB_004366ea
    //                              Debuglog.cpp:252 (29)
    //         004366cd     SUB        ESP,0x8
    //         004366d0     LEA        EAX,[ESP + 0x84]
    //         004366d7     FSTP       double ptr [ESP]
    //         004366da     PUSH       s_%.2f_|                                         = "%.2f |"
    //         004366df     PUSH       EAX
    //         004366e0     CALL       sprintf                                          undefined sprintf()
    //         004366e5     ADD        ESP,0x10
    //         004366e8     JMP        LAB_004366ec
    //                               LAB_004366ea                                                 XREF[1]:     004366cb(j)  
    //                              Debuglog.cpp:247 (2)
    //         004366ea     FSTP       ST0
    //                               LAB_004366ec                                                 XREF[1]:     004366e8(j)  
    //                              Debuglog.cpp:254 (5)
    //         004366ec     CMP        dword ptr [EBP + 0x4],ESI
    //         004366ef     JZ         LAB_00436749
    //                              Debuglog.cpp:256 (13)
    //         004366f1     LEA        this,[ESP + 0x18]
    //         004366f5     PUSH       this
    //         004366f6     CALL       time                                             undefined time()
    //         004366fb     ADD        ESP,0x4
    //                              Debuglog.cpp:257 (26)
    //         004366fe     LEA        EDX,[ESP + 0x18]
    //         00436702     PUSH       0x14
    //         00436704     PUSH       EDX
    //         00436705     CALL       ctime                                            undefined ctime()
    //         0043670a     ADD        ESP,0x4
    //         0043670d     PUSH       EAX
    //         0043670e     LEA        EAX,[ESP + 0x24]
    //         00436712     PUSH       EAX
    //         00436713     CALL       strncat                                          undefined strncat()
    //                              Debuglog.cpp:258 (49)
    //         00436718     MOV        EDI,s__|                                         = 20h
    //         0043671d     OR         this,0xffffffff
    //         00436720     XOR        EAX,EAX
    //         00436722     ADD        ESP,0xc
    //         00436725     SCASB.RE   ES:EDI=>s__|                                     = 20h
    //                                                                                  = 7Ch
    //         00436727     NOT        this
    //         00436729     SUB        EDI,this
    //         0043672b     LEA        EDX,[ESP + 0x1c]
    //         0043672f     MOV        ESI,EDI
    //         00436731     MOV        EDI,EDX
    //         00436733     MOV        EDX,this
    //         00436735     OR         this,0xffffffff
    //         00436738     SCASB.RE   ES:EDI
    //         0043673a     MOV        this,EDX
    //         0043673c     DEC        EDI
    //         0043673d     SHR        this,0x2
    //         00436740     MOVSD.REP  ES:EDI,ESI
    //         00436742     MOV        this,EDX
    //         00436744     AND        this,0x3
    //         00436747     MOVSB.REP  ES:EDI,ESI
    //                               LAB_00436749                                                 XREF[1]:     004366ef(j)  
    //                              Debuglog.cpp:261 (7)
    //         00436749     MOV        EAX,dword ptr [EBP + 0x10]
    //         0043674c     TEST       EAX,EAX
    //         0043674e     JZ         LAB_00436766
    //                              Debuglog.cpp:262 (22)
    //         00436750     MOV        EAX,dword ptr [EBP + 0x24]
    //         00436753     LEA        this,[ESP + 0x3c]
    //         00436757     PUSH       EAX
    //         00436758     PUSH       s_%ld_|                                          = "%ld |"
    //         0043675d     PUSH       this
    //         0043675e     CALL       sprintf                                          undefined sprintf()
    //         00436763     ADD        ESP,0xc
    //                               LAB_00436766                                                 XREF[1]:     0043674e(j)  
    //                              Debuglog.cpp:264 (20)
    //         00436766     MOV        EDI,s_>                                          = 3Eh
    //         0043676b     OR         this,0xffffffff
    //         0043676e     XOR        EAX,EAX
    //         00436770     LEA        EDX,[ESP + 0x5c]
    //         00436774     SCASB.RE   ES:EDI=>s_>                                      = 3Eh
    //         00436776     NOT        this
    //         00436778     SUB        EDI,this
    //                              Debuglog.cpp:266 (59)
    //         0043677a     PUSH       EBX
    //         0043677b     MOV        EAX,this
    //         0043677d     MOV        ESI,EDI
    //         0043677f     MOV        EDI,EDX
    //         00436781     LEA        EDX,[ESP + 0x40]
    //         00436785     SHR        this,0x2
    //         00436788     MOVSD.REP  ES:EDI,ESI
    //         0043678a     MOV        this,EAX
    //         0043678c     LEA        EAX,[ESP + 0x20]
    //         00436790     AND        this,0x3
    //         00436793     MOVSB.REP  ES:EDI,ESI
    //         00436795     LEA        this,[ESP + 0x60]
    //         00436799     LEA        ESI,[EBP + 0x348]
    //         0043679f     PUSH       this
    //         004367a0     PUSH       EDX
    //         004367a1     LEA        this,[ESP + 0x88]
    //         004367a8     PUSH       EAX
    //         004367a9     PUSH       this
    //         004367aa     PUSH       s_%s%s%s%s%s_                                    = "%s%s%s%s%s\n"
    //         004367af     PUSH       ESI
    //         004367b0     CALL       sprintf                                          undefined sprintf()
    //                              Debuglog.cpp:268 (10)
    //         004367b5     MOV        EAX,dword ptr [EBP + 0xc]
    //         004367b8     ADD        ESP,0x1c
    //         004367bb     TEST       EAX,EAX
    //         004367bd     JZ         LAB_004367c6
    //                              Debuglog.cpp:269 (7)
    //         004367bf     PUSH       ESI
    //         004367c0     CALL       dword ptr [->KERNEL32.DLL::OutputDebugStringA]   = 0048aa96
    //                               LAB_004367c6                                                 XREF[1]:     004367bd(j)  
    //                              Debuglog.cpp:271 (14)
    //         004367c6     MOV        EAX,dword ptr [EBP + 0x8]
    //         004367c9     TEST       EAX,EAX
    //         004367cb     JZ         LAB_004367f9
    //         004367cd     MOV        EAX,dword ptr [EBP + 0x18]
    //         004367d0     TEST       EAX,EAX
    //         004367d2     JZ         LAB_004367f9
    //                              Debuglog.cpp:273 (13)
    //         004367d4     MOV        EDX,dword ptr [logstream]                        = 00000000
    //         004367da     PUSH       EDX
    //         004367db     PUSH       ESI=>DAT_fffffff8
    //         004367dc     CALL       fputs                                            undefined fputs()
    //                              Debuglog.cpp:279 (10)
    //         004367e1     MOV        EAX,dword ptr [EBP + 0x14]
    //         004367e4     ADD        ESP,0x8
    //         004367e7     TEST       EAX,EAX
    //         004367e9     JZ         LAB_004367f9
    //                              Debuglog.cpp:280 (14)
    //         004367eb     MOV        EAX,[logstream]                                  = 00000000
    //         004367f0     PUSH       EAX
    //         004367f1     CALL       fflush                                           undefined fflush()
    //         004367f6     ADD        ESP,0x4
    //                               LAB_004367f9                                                 XREF[5]:     0043662d(j), 00436636(j), 
    //                                                                                                         004367cb(j), 004367d2(j), 
    //                                                                                                         004367e9(j)  
    //                              Debuglog.cpp:296 (11)
    //         004367f9     POP        EDI
    //         004367fa     POP        ESI
    //         004367fb     POP        EBP
    //         004367fc     POP        EBX
    //         004367fd     ADD        ESP,0x8c
    //         00436803     RET
}

// Offset: 0x00436810
char* YesOrNo(TDebuggingLog* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: char * __thiscall TDebuggingLog::YesOrNo(int)                                              *
    //                              *********************************************************************************************************
    //                              char * __thiscall YesOrNo(TDebuggingLog * this, int param_1)
    //              char *            EAX:4          <RETURN>
    //              TDebuggingLog *   ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00436810(R)  
    //                               ?YesOrNo@TDebuggingLog@@IAEPADH@Z                            XREF[6]:     LogFile:004362ce(c), 
    //                               TDebuggingLog::YesOrNo                                                    LogOutput:0043630e(c), 
    //                                                                                                         LogTimestamp:00436345(c), 
    //                                                                                                         LogDateTimestamp:00436380(c), 
    //                                                                                                         FlushToDisk:00436451(c), 
    //                                                                                                         LogSequence:00436492(c)  
    //                              Debuglog.cpp:300 (6)
    //         00436810     MOV        EAX,dword ptr [ESP + param_1]
    //         00436814     TEST       EAX,EAX
    //                              Debuglog.cpp:302 (7)
    //         00436816     MOV        EAX,s__is_now_ACTIVE.                            = " is now ACTIVE."
    //         0043681b     JNZ        LAB_00436822
    //                              Debuglog.cpp:304 (5)
    //         0043681d     MOV        EAX,s__has_been_deactivated.                     = " has been deactivated."
    //                               LAB_00436822                                                 XREF[1]:     0043681b(j)  
    //                              Debuglog.cpp:305 (3)
    //         00436822     RET        0x4
}

