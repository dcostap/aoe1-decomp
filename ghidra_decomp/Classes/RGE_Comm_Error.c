// Class: RGE_Comm_Error
// Size:  0x8
//
// Member Layout:
// [0x000] void * HostHWND
// [0x004] long LastReportedError
// ----------------------------------------------------------------

// Function: RGE_Comm_Error
// Address: 00424e40
void __thiscall RGE_Comm_Error::RGE_Comm_Error(RGE_Comm_Error *this,void *param_1)
{
  this->HostHWND = param_1;
  this->LastReportedError = 0;
  return;
}

// --------------------------------------------------

// Function: NotifyWindowParam
// Address: 00424e60
// [HELPER] s_COMM__Send_msg_to_window_WM_USER: "COMM: Send msg to window WM_USER  Msg=%d  Param=%d "
void __thiscall
RGE_Comm_Error::NotifyWindowParam(RGE_Comm_Error *this,COMMMESSAGES param_1,long param_2)
{
  PostMessageA(this->HostHWND,0x400,param_1,param_2);
  TDebuggingLog::Log(L,(char *)L,s_COMM__Send_msg_to_window_WM_USER,param_1,param_2);
  return;
}

// --------------------------------------------------

// Function: ~RGE_Comm_Error
// Address: 00424ea0
void __thiscall RGE_Comm_Error::~RGE_Comm_Error(RGE_Comm_Error *this)
{
  return;
}

// --------------------------------------------------

// Function: ShowReturn
// Address: 00424eb0
// [HELPER] s_COM_Aborted: "COM Aborted"
// [HELPER] s_COM_Error_pending: "COM Error pending"
// [HELPER] s_COM_Invalid_Handle: "COM Invalid Handle"
// [HELPER] s_COM_Invalid_Pointer: "COM Invalid Pointer"
// [HELPER] s_COM_error_Access_Denied: "COM error Access Denied"
// [HELPER] s____COMM______DP_CALL_FAILED__Cod: "+++COMM______DP CALL FAILED_(Code %u)_____ %s____"
// [HELPER] s_____Access_Denied___busy_service: "!!! Access Denied - busy service or invalid use of host commands."
// [HELPER] s_____Active_Players___command_inv: "!!! Active Players - command invalid with active players."
// [HELPER] s_____Already_Initialized: "!!! Already Initialized"
// [HELPER] s_____Application_has_not_been_sta: "!!! Application has not been started yet."
// [HELPER] s_____Buffer_size_failure__LARGE_: "!!! Buffer size failure (LARGE)"
// [HELPER] s_____Buffer_size_failure__SMALL_: "!!! Buffer size failure (SMALL)"
// [HELPER] s_____Busy_Rcvd: "!!! Busy Rcvd"
// [HELPER] s_____COMM_TIMEOUT_Rcvd_from_HOST_: "!!! COMM TIMEOUT Rcvd from HOST connection."
// [HELPER] s_____COMM__CLASS_NO_AGGREGATION_: "!!! COMM: CLASS NO AGGREGATION."
// [HELPER] s_____Can_t_Add_Player: "!!! Can't Add Player"
// [HELPER] s_____Can_t_Create_Group: "!!! Can't Create Group"
// [HELPER] s_____Can_t_create_player_: "!!! Can't create player."
// [HELPER] s_____Can_t_create_session_: "!!! Can't create session."
// [HELPER] s_____Can_t_load_CAPI: "!!! Can't load CAPI"
// [HELPER] s_____Can_t_load_security_SSPI_pac: "!!! Can't load security SSPI package."
// [HELPER] s_____Can_t_load_security_package_: "!!! Can't load security package."
// [HELPER] s_____Can_t_start_the_application_: "!!! Can't start the application."
// [HELPER] s_____Communications___Session_is_: "!!! Communications / Session is Unavailable"
// [HELPER] s_____Device_caps_are_not_availabl: "!!! Device caps are not available."
// [HELPER] s_____ERROR_: "!!! ERROR!"
// [HELPER] s_____Exception_Raised: "!!! Exception Raised"
// [HELPER] s_____GENERIC__Undefined__ERROR_: "!!! GENERIC (Undefined) ERROR "
// [HELPER] s_____Invalid_Flags: "!!! Invalid Flags"
// [HELPER] s_____Invalid_Group: "!!! Invalid Group"
// [HELPER] s_____Invalid_Object: "!!! Invalid Object"
// [HELPER] s_____Invalid_Params: "!!! Invalid Params"
// [HELPER] s_____Invalid_Player: "!!! Invalid Player"
// [HELPER] s_____Lost_connection_to_session_: "!!! Lost connection to session."
// [HELPER] s_____No_Connection: "!!! No Connection"
// [HELPER] s_____No_Interface: "!!! No Interface"
// [HELPER] s_____No_messages: "!!! No messages"
// [HELPER] s_____No_name_server_running_: "!!! No name server running!"
// [HELPER] s_____No_players_are_connected_: "!!! No players are connected!"
// [HELPER] s_____No_sessions_are_available: "!!! No sessions are available"
// [HELPER] s_____Not_A_Lobby_Session: "!!! Not A Lobby Session"
// [HELPER] s_____Not_able_to_do_multipayer_: "!!! Not able to do multipayer!"
// [HELPER] s_____Out_Of_Memory: "!!! Out Of Memory"
// [HELPER] s_____Player_Lost_connection_: "!!! Player Lost connection."
// [HELPER] s_____Security_authentify_failed_: "!!! Security authentify failed."
// [HELPER] s_____Send_overflow_: "!!! Send overflow!"
// [HELPER] s_____The_encryption_failed_: "!!! The encryption failed."
// [HELPER] s_____The_secure_logon_failed_: "!!! The secure logon failed."
// [HELPER] s_____The_secure_password_is_inval: "!!! The secure password is invalid."
// [HELPER] s_____The_security_sign_failed_: "!!! The security sign failed."
// [HELPER] s_____The_session_is_in_the_proces: "!!! The session is in the process of connecting"
// [HELPER] s_____Unable_to_create_server: "!!! Unable to create server"
// [HELPER] s_____Unknown_application_specifie: "!!! Unknown application specified"
// [HELPER] s_____Unsupported_: "!!! Unsupported."
// [HELPER] s_____User_Cancel: "!!! User Cancel"
// [HELPER] s______s__Unhandled_DP_ERROR_excep: "!!! %s: Unhandled DP ERROR/exception in call.  Result=%ld  (%d)"
void __thiscall RGE_Comm_Error::ShowReturn(RGE_Comm_Error *this,long param_1,char *param_2)
{
  TDebuggingLog *this_00;
  TDebuggingLog *this_01;
  TDebuggingLog *pTVar1;
  TDebuggingLog *this_02;
  char *pcVar2;
  
  if (param_1 == 0) {
    return;
  }
  TDebuggingLog::Log((TDebuggingLog *)this,(char *)L,s____COMM______DP_CALL_FAILED__Cod,param_1,
                     param_2);
  this->LastReportedError = param_1;
  if (param_1 < -0x7fffbffe) {
    if (param_1 == -0x7fffbfff) {
      TDebuggingLog::Log(this_00,(char *)L,s_____Unsupported_);
      return;
    }
    if (param_1 == -0x7ffffff6) {
      TDebuggingLog::Log(L,(char *)L,s_COM_Error_pending);
      return;
    }
  }
  else if (param_1 < -0x7ffbfeef) {
    if (param_1 == -0x7ffbfef0) {
      TDebuggingLog::Log(L,(char *)L,s_____COMM__CLASS_NO_AGGREGATION_);
      return;
    }
    switch(param_1) {
    case -0x7fffbffe:
      NotifyWindowParam(this,COMM_FATAL_ERROR,0);
      TDebuggingLog::Log(L,(char *)L,s_____No_Interface);
      return;
    case -0x7fffbffd:
      TDebuggingLog::Log(this_00,(char *)L,s_COM_Invalid_Pointer);
      return;
    case -0x7fffbffc:
      TDebuggingLog::Log(this_00,(char *)L,s_COM_Aborted);
      return;
    case -0x7fffbffb:
      TDebuggingLog::Log(this_00,(char *)L,s_____GENERIC__Undefined__ERROR_);
      NotifyWindowParam(this,COMM_FATAL_ERROR,0);
      return;
    }
  }
  else if (param_1 < -0x7ff8fff1) {
    if (param_1 == -0x7ff8fff2) {
      TDebuggingLog::Log(L,(char *)L,s_____Out_Of_Memory);
      return;
    }
    if (param_1 == -0x7ff8fffb) {
      pcVar2 = s_COM_error_Access_Denied;
      pTVar1 = this_00;
LAB_004254c5:
      TDebuggingLog::Log(pTVar1,(char *)L,pcVar2);
      NotifyWindowParam(this,COMM_NO_LINK,0);
      return;
    }
    if (param_1 == -0x7ff8fffa) {
      TDebuggingLog::Log(this_00,(char *)L,s_COM_Invalid_Handle);
      return;
    }
  }
  else if (param_1 < -0x7788fffa) {
    if (param_1 == -0x7788fffb) {
      TDebuggingLog::Log(this_00,(char *)L,s_____Already_Initialized);
      return;
    }
    if (param_1 == -0x7ff8ffa9) {
      TDebuggingLog::Log(this_00,(char *)L,s_____Invalid_Params);
      return;
    }
  }
  else if (param_1 < -0x7788ffeb) {
    if (param_1 == -0x7788ffec) {
      TDebuggingLog::Log(this_00,(char *)L,s_____Active_Players___command_inv);
      return;
    }
    if (param_1 == -0x7788fff6) {
      pcVar2 = s_____Access_Denied___busy_service;
      pTVar1 = L;
      goto LAB_004254c5;
    }
  }
  else if (param_1 < -0x7788ffd7) {
    if (param_1 == -0x7788ffd8) {
      pcVar2 = s_____Can_t_Add_Player;
      pTVar1 = L;
LAB_004253bf:
      TDebuggingLog::Log(pTVar1,(char *)L,pcVar2);
      NotifyWindowParam(this,COMM_NO_NEW_PLAYERS,0);
      return;
    }
    if (param_1 == -0x7788ffe2) {
      TDebuggingLog::Log(this_00,(char *)L,s_____Buffer_size_failure__SMALL_);
      return;
    }
  }
  else if (param_1 < -0x7788ffc3) {
    if (param_1 == -0x7788ffc4) {
      TDebuggingLog::Log(this_00,(char *)L,s_____Can_t_create_player_);
      return;
    }
    if (param_1 == -0x7788ffce) {
      TDebuggingLog::Log(this_00,(char *)L,s_____Can_t_Create_Group);
      return;
    }
  }
  else if (param_1 < -0x7788ffaf) {
    if (param_1 == -0x7788ffb0) {
      TDebuggingLog::Log(this_00,(char *)L,s_____Device_caps_are_not_availabl);
      TDebuggingLog::Log(this_01,(char *)L,s_____ERROR_);
      return;
    }
    if (param_1 == -0x7788ffba) {
      TDebuggingLog::Log(L,(char *)L,s_____Can_t_create_session_);
      return;
    }
  }
  else if (param_1 < -0x7788ff87) {
    if (param_1 == -0x7788ff88) {
      TDebuggingLog::Log(this_00,(char *)L,s_____Invalid_Flags);
      return;
    }
    if (param_1 == -0x7788ffa6) {
      TDebuggingLog::Log(L,(char *)L,s_____Exception_Raised);
      return;
    }
  }
  else if (param_1 < -0x7788ff69) {
    if (param_1 == -0x7788ff6a) {
      TDebuggingLog::Log(L,(char *)L,s_____Invalid_Player);
      return;
    }
    if (param_1 == -0x7788ff7e) {
      TDebuggingLog::Log(this_00,(char *)L,s_____Invalid_Object);
      return;
    }
  }
  else if (param_1 < -0x7788ff5f) {
    if (param_1 == -0x7788ff60) {
      TDebuggingLog::Log(this_00,(char *)L,s_____Not_able_to_do_multipayer_);
      return;
    }
    if (param_1 == -0x7788ff65) {
      TDebuggingLog::Log(this_00,(char *)L,s_____Invalid_Group);
      return;
    }
  }
  else if (param_1 < -0x7788ff41) {
    if (param_1 == -0x7788ff42) {
      TDebuggingLog::Log(this_00,(char *)L,s_____No_messages);
      return;
    }
    if (param_1 == -0x7788ff56) {
      TDebuggingLog::Log(L,(char *)L,s_____No_Connection);
      return;
    }
  }
  else if (param_1 < -0x7788ff2d) {
    if (param_1 == -0x7788ff2e) {
      TDebuggingLog::Log(L,(char *)L,s_____No_players_are_connected_);
      return;
    }
    if (param_1 == -0x7788ff38) {
      TDebuggingLog::Log(this_00,(char *)L,s_____No_name_server_running_);
      return;
    }
  }
  else if (param_1 < -0x7788ff19) {
    if (param_1 == -0x7788ff1a) {
      TDebuggingLog::Log(this_00,(char *)L,s_____Send_overflow_);
      return;
    }
    if (param_1 == -0x7788ff24) {
      TDebuggingLog::Log(this_00,(char *)L,s_____No_sessions_are_available);
      return;
    }
  }
  else if (param_1 < -0x7788ff05) {
    if (param_1 == -0x7788ff06) {
      pcVar2 = s_____Communications___Session_is_;
      pTVar1 = this_00;
      goto LAB_004253bf;
    }
    if (param_1 == -0x7788ff10) {
      TDebuggingLog::Log(L,(char *)L,s_____COMM_TIMEOUT_Rcvd_from_HOST_);
      NotifyWindowParam(this,COMM_HOST_BUSY,0);
      return;
    }
  }
  else if (param_1 < -0x7788fee7) {
    if (param_1 == -0x7788fee8) {
      NotifyWindowParam(this,COMM_NO_LINK,0);
      TDebuggingLog::Log(L,(char *)L,s_____User_Cancel);
      return;
    }
    if (param_1 == -0x7788fef2) {
      TDebuggingLog::Log(this_00,(char *)L,s_____Busy_Rcvd);
      return;
    }
  }
  else if (param_1 < -0x7788fed3) {
    if (param_1 == -0x7788fed4) {
      TDebuggingLog::Log(this_00,(char *)L,s_____Player_Lost_connection_);
      return;
    }
    if (param_1 == -0x7788fede) {
      TDebuggingLog::Log(this_00,(char *)L,s_____Unable_to_create_server);
      return;
    }
  }
  else if (param_1 < -0x7788febf) {
    if (param_1 == -0x7788fec0) {
      pcVar2 = s_____Unknown_application_specifie;
      pTVar1 = this_00;
      goto LAB_004254c5;
    }
    if (param_1 == -0x7788feca) {
      TDebuggingLog::Log(L,(char *)L,s_____Lost_connection_to_session_);
      NotifyWindowParam(this,COMM_CANCEL_GAME,0);
      return;
    }
  }
  else if (param_1 < -0x7788feab) {
    if (param_1 == -0x7788feac) {
      TDebuggingLog::Log(L,(char *)L,s_____The_secure_password_is_inval);
      return;
    }
    if (param_1 == -0x7788feb6) {
      NotifyWindowParam(this,COMM_NO_NEW_PLAYERS,0);
      TDebuggingLog::Log(this_02,(char *)L,s_____The_session_is_in_the_proces);
      return;
    }
  }
  else if (param_1 < -0x7788fc17) {
    if (param_1 == -0x7788fc18) {
      TDebuggingLog::Log(this_00,(char *)L,s_____Buffer_size_failure__LARGE_);
      return;
    }
    if (param_1 == -0x7788fea2) {
      TDebuggingLog::Log(this_00,(char *)L,s_____The_session_is_in_the_proces);
      return;
    }
  }
  else if (param_1 < -0x7788fc03) {
    if (param_1 == -0x7788fc04) {
      TDebuggingLog::Log(this_00,(char *)L,s_____Application_has_not_been_sta);
      return;
    }
    if (param_1 == -0x7788fc0e) {
      TDebuggingLog::Log(L,(char *)L,s_____Can_t_start_the_application_);
      return;
    }
  }
  else if (param_1 < -0x7788fbe5) {
    if (param_1 == -0x7788fbe6) {
      TDebuggingLog::Log(this_00,(char *)L,s_____Unknown_application_specifie);
      return;
    }
    if (param_1 == -0x7788fbf0) {
      return;
    }
  }
  else if (param_1 < -0x7788f82f) {
    if (param_1 == -0x7788f830) {
      TDebuggingLog::Log(this_00,(char *)L,s_____Security_authentify_failed_);
      return;
    }
    if (param_1 == -0x7788fbd2) {
      TDebuggingLog::Log(L,(char *)L,s_____Not_A_Lobby_Session);
      return;
    }
  }
  else if (param_1 < -0x7788f81b) {
    if (param_1 == -0x7788f81c) {
      TDebuggingLog::Log(L,(char *)L,s_____The_encryption_failed_);
      return;
    }
    if (param_1 == -0x7788f826) {
      TDebuggingLog::Log(this_00,(char *)L,s_____Can_t_load_security_SSPI_pac);
      return;
    }
  }
  else if (param_1 < -0x7788f807) {
    if (param_1 == -0x7788f808) {
      TDebuggingLog::Log(this_00,(char *)L,s_____Can_t_load_security_package_);
      return;
    }
    if (param_1 == -0x7788f812) {
      TDebuggingLog::Log(this_00,(char *)L,s_____The_security_sign_failed_);
      return;
    }
  }
  else {
    if (param_1 == -0x7788f7f4) {
      TDebuggingLog::Log(this_00,(char *)L,s_____Can_t_load_CAPI);
      return;
    }
    if (param_1 == -0x7788f7e0) {
      TDebuggingLog::Log(this_00,(char *)L,s_____The_secure_logon_failed_);
      return;
    }
  }
  TDebuggingLog::Log(L,(char *)L,s______s__Unhandled_DP_ERROR_excep,param_2,param_1,param_1);
  return;
}

// --------------------------------------------------

