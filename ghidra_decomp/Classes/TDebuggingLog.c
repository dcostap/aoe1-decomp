// Class: TDebuggingLog
// Size:  0x7B0
//
// Member Layout:
// [0x000] int Timestamp
// [0x004] int DateTimestamp
// [0x008] int LogToFile
// [0x00C] int LogToOutput
// [0x010] int Sequence
// [0x014] int Flush
// [0x018] int LogIsOpen
// [0x01C] int LogError
// [0x020] ulong LogStartTickCount
// [0x024] ulong SeqNo
// [0x028] char[800] TBuff (sz: 0x320)
// [0x348] char[1000] osbuf (sz: 0x3E8)
// [0x730] char[128] Filename (sz: 0x80)
// ----------------------------------------------------------------

// Function: TDebuggingLog
// Address: 00436220
// [HELPER] s_C__APPLOGERR_TXT: "C:\APPLOGERR.TXT"
// [HELPER] s____Logging___: "===Logging==="
/* public: __thiscall TDebuggingLog::TDebuggingLog(void) */

TDebuggingLog * __thiscall TDebuggingLog::TDebuggingLog(TDebuggingLog *this)
{
  char cVar1;
  TDebuggingLog *this_00;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  this->LogToFile = 0;
  this->LogToOutput = 0;
  this->LogError = 0;
  this->LogIsOpen = 0;
  LogSequence(this,0);
  LogTimestamp(this,0);
  LogDateTimestamp(this,0);
  FlushToDisk(this,0);
  OpenLog(this);
  Log(this_00,(char *)this,s____Logging___);
  Time(this);
  uVar2 = 0xffffffff;
  pcVar4 = &s_C__APPLOGERR_TXT;
  do {
    pcVar5 = pcVar4;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar5 = pcVar4 + 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar5;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar4 = pcVar5 + -uVar2;
  pcVar5 = this->Filename;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar5 = pcVar5 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar5 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  }
  return this;
}

// --------------------------------------------------

// Function: CloseLog
// Address: 0043629b
// [HELPER] s_Closing_debug_log_file___s__: "Closing debug log file '%s'."
// [HELPER] s_Log_file_is_closed: "Log file is closed"
void __thiscall TDebuggingLog::CloseLog(TDebuggingLog *this)
{
  TDebuggingLog *this_00;
  
  if (this->LogToFile != 0) {
    if (this->Filename != (char *)0x0) {
      Log(this,(char *)this,s_Closing_debug_log_file___s__,this->Filename);
    }
    Time(this);
    Log(this_00,(char *)this,s_Log_file_is_closed);
    fclose(logstream);
    this->LogIsOpen = 0;
  }
  return;
}

// --------------------------------------------------

// Function: ~TDebuggingLog
// Address: 004362a0
// [HELPER] s_Closing_debug_log_file___s__: "Closing debug log file '%s'."
// [HELPER] s_Log_file_is_closed: "Log file is closed"
/* public: __thiscall TDebuggingLog::~TDebuggingLog(void) */

void __thiscall TDebuggingLog::~TDebuggingLog(TDebuggingLog *this)
{
  TDebuggingLog *this_00;
  
  if (this->LogToFile != 0) {
    if (this->Filename != (char *)0x0) {
      Log(this,(char *)this,s_Closing_debug_log_file___s__,this->Filename);
    }
    Time(this);
    Log(this_00,(char *)this,s_Log_file_is_closed);
    fclose(logstream);
    this->LogIsOpen = 0;
  }
  return;
}

// --------------------------------------------------

// Function: LogFile
// Address: 004362b0
// [HELPER] s_Logging_to_File__s: "Logging to File %s"
/* public: void __thiscall TDebuggingLog::LogFile(int) */

void __thiscall TDebuggingLog::LogFile(TDebuggingLog *this,int param_1)
{
  char *pcVar1;
  TDebuggingLog *this_00;
  
  if (param_1 == 0) {
    this->LogToFile = 0;
  }
  else {
    this->LogToFile = 1;
  }
  pcVar1 = YesOrNo(this,param_1);
  Log(this_00,(char *)this,s_Logging_to_File__s,pcVar1);
  return;
}

// --------------------------------------------------

// Function: LogOutput
// Address: 004362f0
// [HELPER] s_Logging_to_OUTPUT__s: "Logging to OUTPUT %s"
/* public: void __thiscall TDebuggingLog::LogOutput(int) */

void __thiscall TDebuggingLog::LogOutput(TDebuggingLog *this,int param_1)
{
  char *pcVar1;
  TDebuggingLog *this_00;
  
  if (param_1 == 0) {
    this->LogToOutput = 0;
  }
  else {
    this->LogToOutput = 1;
  }
  pcVar1 = YesOrNo(this,param_1);
  Log(this_00,(char *)this,s_Logging_to_OUTPUT__s,pcVar1);
  return;
}

// --------------------------------------------------

// Function: LogTimestamp
// Address: 00436330
// [HELPER] s_Timestamp_milliseconds__s: "Timestamp milliseconds %s"
/* public: void __thiscall TDebuggingLog::LogTimestamp(int) */

void __thiscall TDebuggingLog::LogTimestamp(TDebuggingLog *this,int param_1)
{
  char *pcVar1;
  TDebuggingLog *this_00;
  
  this->Timestamp = (uint)(param_1 != 0);
  pcVar1 = YesOrNo(this,(uint)(param_1 != 0));
  Log(this_00,(char *)this,s_Timestamp_milliseconds__s,pcVar1);
  return;
}

// --------------------------------------------------

// Function: LogDateTimestamp
// Address: 00436360
// [HELPER] s_Date___Time_stamp_s: "Date & Time stamp%s"
/* public: void __thiscall TDebuggingLog::LogDateTimestamp(int) */

void __thiscall TDebuggingLog::LogDateTimestamp(TDebuggingLog *this,int param_1)
{
  char *pcVar1;
  TDebuggingLog *this_00;
  
  if (param_1 == 0) {
    this->DateTimestamp = 0;
  }
  else {
    this->DateTimestamp = 1;
  }
  pcVar1 = YesOrNo(this,this->Timestamp);
  Log(this_00,(char *)this,s_Date___Time_stamp_s,pcVar1);
  return;
}

// --------------------------------------------------

// Function: Time
// Address: 004363a0
// [HELPER] s_: ""
// [HELPER] s_C__msdev_work_age1_x1_Debuglog_c: "C:\msdev\work\age1_x1\Debuglog.cpp"
// [HELPER] s__: "}"
/* WARNING: Variable defined which should be unmapped: ltime */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __thiscall TDebuggingLog::Time(void) */

void __thiscall TDebuggingLog::Time(TDebuggingLog *this)
{
  float fVar1;
  ulong uVar2;
  int iVar3;
  char *pcVar4;
  TDebuggingLog *extraout_ECX;
  TDebuggingLog *extraout_ECX_00;
  TDebuggingLog *this_00;
  long ltime;
  float fTicksElapsed;
  
                    /* language.dll match for 0x78: "10" */
  uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_Debuglog_c,0x78);
  time();
  iVar3 = localtime();
  fVar1 = (float)(uVar2 - this->LogStartTickCount) * _DAT_0056f500;
  if (iVar3 == 0) {
    pcVar4 = s__;
    this_00 = extraout_ECX;
  }
  else {
    pcVar4 = (char *)asctime();
    this_00 = extraout_ECX_00;
  }
  Log(this_00,(char *)this,s_>>>TIME>>>___s_____7_1f_sec__ela,pcVar4,(double)fVar1);
  return;
}

// --------------------------------------------------

// Function: FlushToDisk
// Address: 00436430
// [HELPER] s_Flush_queue_each_message__s: "Flush queue each message %s"
/* public: void __thiscall TDebuggingLog::FlushToDisk(int) */

void __thiscall TDebuggingLog::FlushToDisk(TDebuggingLog *this,int param_1)
{
  char *pcVar1;
  TDebuggingLog *this_00;
  
  if (param_1 == 0) {
    this->Flush = 0;
  }
  else {
    this->Flush = 1;
  }
  pcVar1 = YesOrNo(this,this->Flush);
  Log(this_00,(char *)this,s_Flush_queue_each_message__s,pcVar1);
  return;
}

// --------------------------------------------------

// Function: LogSequence
// Address: 00436470
// [HELPER] s_Sequence_numbering_s: "Sequence numbering%s"
/* public: void __thiscall TDebuggingLog::LogSequence(int) */

void __thiscall TDebuggingLog::LogSequence(TDebuggingLog *this,int param_1)
{
  char *pcVar1;
  TDebuggingLog *this_00;
  
  if (param_1 == 0) {
    this->Sequence = 0;
  }
  else {
    this->Sequence = 1;
    this->SeqNo = 0;
  }
  pcVar1 = YesOrNo(this,this->Sequence);
  Log(this_00,(char *)this,s_Sequence_numbering_s,pcVar1);
  return;
}

// --------------------------------------------------

// Function: OpenLog
// Address: 004364b0
// [HELPER] s_C__AOELOG__2d_txt: "C:\AOELOG%.2d.txt"
// [HELPER] s_C__AOELOG_txt: "C:\AOELOG.txt"
// [HELPER] s_C__msdev_work_age1_x1_Debuglog_c: "C:\msdev\work\age1_x1\Debuglog.cpp"
// [HELPER] s_Log_file__s_is_opened: "Log file %s is opened"
// [HELPER] s_wt: "wt"
/* WARNING: Variable defined which should be unmapped: nLoop */
/* public: void __thiscall TDebuggingLog::OpenLog(void) */

void __thiscall TDebuggingLog::OpenLog(TDebuggingLog *this)
{
  char *pcVar1;
  char cVar2;
  ulong uVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  int nLoop;
  int local_4;
  
  if ((this->LogToFile == 0) || ((this->LogIsOpen != 0 && (this->LogError == 0)))) {
    return;
  }
  uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_Debuglog_c,0xa3);
  this->LogStartTickCount = uVar3;
  local_4 = 1;
  do {
    pcVar1 = this->Filename;
    if (local_4 == 1) {
      uVar4 = 0xffffffff;
      pcVar6 = &s_C__AOELOG_txt;
      do {
        pcVar7 = pcVar6;
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        pcVar7 = pcVar6 + 1;
        cVar2 = *pcVar6;
        pcVar6 = pcVar7;
      } while (cVar2 != '\0');
      uVar4 = ~uVar4;
      pcVar6 = pcVar7 + -uVar4;
      pcVar7 = pcVar1;
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcVar7 = pcVar7 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar7 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcVar7 = pcVar7 + 1;
      }
    }
    else {
      sprintf(pcVar1,s_C__AOELOG__2d_txt,local_4 + -1);
    }
    logstream = (_iobuf *)fopen(pcVar1,s_wt);
    if (logstream != (_iobuf *)0x0) {
      this->LogIsOpen = 1;
      Log((TDebuggingLog *)this->Filename,(char *)this,s_Log_file__s_is_opened,this->Filename);
      Time(this);
      return;
    }
    local_4 = local_4 + 1;
    if (0x19 < local_4) {
      this->LogError = 1;
      this->LogIsOpen = 0;
      return;
    }
    logstream = (_iobuf *)0x0;
  } while( true );
}

// --------------------------------------------------

// Function: FlushLog
// Address: 004365a0
/* public: void __thiscall TDebuggingLog::FlushLog(void) */

void __thiscall TDebuggingLog::FlushLog(TDebuggingLog *this)
{
  if (this->LogToFile != 0) {
    fflush(logstream);
  }
  return;
}

// --------------------------------------------------

// Function: CloseLog
// Address: 004365c0
// [HELPER] s_Closing_debug_log_file___s__: "Closing debug log file '%s'."
// [HELPER] s_Log_file_is_closed: "Log file is closed"
/* public: void __thiscall TDebuggingLog::CloseLog(void) */

void __thiscall TDebuggingLog::CloseLog(TDebuggingLog *this)
{
  TDebuggingLog *this_00;
  
  if (this->LogToFile != 0) {
    if (this->Filename != (char *)0x0) {
      Log(this,(char *)this,s_Closing_debug_log_file___s__,this->Filename);
    }
    Time(this);
    Log(this_00,(char *)this,s_Log_file_is_closed);
    fclose(logstream);
    this->LogIsOpen = 0;
  }
  return;
}

// --------------------------------------------------

// Function: Log
// Address: 00436610
// [HELPER] s_: ""
// [HELPER] s___2f__: "%.2f |"
// [HELPER] s___: "]\n"
// [HELPER] s__ld__: "%ld |"
// [HELPER] s__s_s_s_s_s_: "%s%s%s%s%s\n"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __cdecl TDebuggingLog::Log(char *,...) */

void __thiscall TDebuggingLog::Log(TDebuggingLog *this,char *param_1,...)
{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  undefined4 in_stack_00000008;
  long ltime;
  char s2 [32];
  char s3 [32];
  char s4 [32];
  char s1 [32];
  
  if (((*(int *)(param_1 + 8) != 0) || (*(int *)(param_1 + 0xc) != 0)) &&
     (*(int *)(param_1 + 0x1c) == 0)) {
    if ((*(int *)(param_1 + 0x18) == 0) && (*(int *)(param_1 + 8) != 0)) {
      OpenLog((TDebuggingLog *)param_1);
    }
    if ((*(int *)(param_1 + 0x18) == 0) && (*(int *)(param_1 + 8) != 0)) {
      param_1[0x1c] = '\x01';
      param_1[0x1d] = '\0';
      param_1[0x1e] = '\0';
      param_1[0x1f] = '\0';
      return;
    }
    *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
    vsprintf(param_1 + 0x28,in_stack_00000008,&stack0x0000000c);
    uVar2 = GetTickCount();
    s4[4] = '\0';
    s3[4] = '\0';
    s2[4] = '\0';
    s1[4] = '\0';
    if (*(int *)param_1 != 0) {
      sprintf(s1 + 4,s___2f__,
              (double)(((float)uVar2 - (float)*(int *)(param_1 + 0x20)) * _DAT_0056f500));
    }
    if (*(int *)(param_1 + 4) != 0) {
      time();
      uVar3 = ctime(s2,0x14);
      strncat(s2 + 4,uVar3);
      uVar2 = 0xffffffff;
      pcVar6 = &s___;
      do {
        pcVar7 = pcVar6;
        if (uVar2 == 0) break;
        uVar2 = uVar2 - 1;
        pcVar7 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar7;
      } while (cVar1 != '\0');
      uVar2 = ~uVar2;
      iVar4 = -1;
      pcVar6 = s2 + 4;
      do {
        pcVar8 = pcVar6;
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        pcVar8 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar8;
      } while (cVar1 != '\0');
      pcVar6 = pcVar7 + -uVar2;
      pcVar7 = pcVar8 + -1;
      for (uVar5 = uVar2 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcVar7 = pcVar7 + 4;
      }
      for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
        *pcVar7 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcVar7 = pcVar7 + 1;
      }
    }
    if (*(int *)(param_1 + 0x10) != 0) {
      sprintf(s3 + 4,s__ld__,*(undefined4 *)(param_1 + 0x24));
    }
    uVar2 = 0xffffffff;
    pcVar6 = s4;
    pcVar7 = &s_>;
    do {
      pcVar8 = pcVar7;
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      pcVar8 = pcVar7 + 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar8;
    } while (cVar1 != '\0');
    uVar2 = ~uVar2;
    pcVar7 = pcVar8 + -uVar2;
    for (uVar5 = uVar2 >> 2; pcVar6 = pcVar6 + 4, uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar6 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
    }
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *pcVar6 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pcVar6 = pcVar6 + 1;
    }
    sprintf(param_1 + 0x348,s__s_s_s_s_s_,s1 + 4,s2 + 4,s3 + 4,s4 + 4,param_1 + 0x28);
    if (*(int *)(param_1 + 0xc) != 0) {
      OutputDebugStringA();
    }
    if (((*(int *)(param_1 + 8) != 0) && (*(int *)(param_1 + 0x18) != 0)) &&
       (fputs(param_1 + 0x348,logstream), *(int *)(param_1 + 0x14) != 0)) {
      fflush();
    }
  }
  return;
}

// --------------------------------------------------

// Function: YesOrNo
// Address: 00436810
// [HELPER] s__has_been_deactivated_: " has been deactivated."
// [HELPER] s__is_now_ACTIVE_: " is now ACTIVE."
/* protected: char * __thiscall TDebuggingLog::YesOrNo(int) */

char * __thiscall TDebuggingLog::YesOrNo(TDebuggingLog *this,int param_1)
{
  char *pcVar1;
  
  pcVar1 = s__is_now_ACTIVE_;
  if (param_1 == 0) {
    pcVar1 = s__has_been_deactivated_;
  }
  return pcVar1;
}

// --------------------------------------------------

