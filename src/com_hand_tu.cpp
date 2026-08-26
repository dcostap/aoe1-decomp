// Authentic Com_hand.cpp owner wrapper.
//
// Source module: C:\\msdev\\work\\age1_x1\\Com_hand.cpp
// PDB address order is preserved below. The wrapper keeps matching, accepted
// drift, scratch, and verified-logic owners in their original source order.
// No exact tuning is performed in this TU pass.

#define COM_HAND_TU_CONTEXT 1
#include "../include/com_hand_context.h"
#define L com_hand_global_log

#define array_149C Kicked
#define arr_ PlayerStopTurn
#define field_1288 StepMode
#define field_1550 PlayerOptions.NeedsToBeSent
#define field_130C HostHWND
#define ptr_ Sync
#define debugging_log L
#define num_players MaxGamePlayers
#define my_player Me
#define bytes_sent TXPacketLength
#define error_logger Err
#define player_connected IsPlayerHuman
#define last_turn_ack LastTurnAck
#define low_player PlayerOptions.LowPlayerNumber
#define high_player PlayerOptions.HighPlayerNumber
#define pause_state PlayerOptions.ProgramState
#define rx_array OnHold
#define tx_array Resend
#define StoredMessages Resend
#define field_12b8 RXPacketLength
#define field_12bc RXPacketLengthHigh
#define field_12c0 TXPacketLength
#define field_12c4 TXPacketLengthHigh
#define field_10f0 lastRXDataRate
#define field_10f4 lastTXDataRate
#define field_1748 HoldCount
#define field_1340 ServiceTimeout
#define field_1338 TXPackets
#define field_1334 RXPackets
#define field_1514 RGE_Guaranteed_Delivery
#define field_1328 ResendAcknowledgements
#define field_132c ResentToOther
#define field_1330 DroppedPacketCount
#define field_1310 LobbyLaunched
#define field_14e4 GTDSerialNo
#define field_10ec dwStopTime
#define field_10e8 OutOfSyncFlag
#define field_10EC dwStopTime
#define field_10E8 OutOfSyncFlag
#define field_1298 AvgTurnTime
#define field_12a0 PauseChangePending
#define field_1518 IntentionallyDropPackets
#define field_1554 PlayerOptions.LastSentTime
#define str_11fa MyGameTitle
#define str_10f8 MyFriendlyName
#define str_1179 MyFormalName
#define field_12d8 MaxGamePlayers
#define field_000c TickStart
#define field_0010 TickCount
#define field_12d0 LastTimeoutMessageTime
#define field_12D4 CommunicationsStatus
#define field_1712 PlayerOptions.LowPlayerNumber
#define field_1710 PlayerOptions.HighPlayerNumber
#define field_1714 PlayerOptions.HostPlayerNumber
#define session_active HaveHostInit
#define connection_state current_turn
#define session_title MyGameTitle
#define player_mode ProgramState
#define game_state ProgramState
#define numPlayers MaxGamePlayers
#define f1344 LastPlayerCommunication
#define f1564 PlayerOptions.dcoID
#define f1594 PlayerOptions.PlayerReady
#define f15BC PlayerOptions.User1
#define f15E4 PlayerOptions.User2
#define f160C PlayerOptions.User3
#define f1634 PlayerOptions.User4
#define f165C PlayerOptions.User5
#define f1684 PlayerOptions.User6
#define f16AC PlayerOptions.User7
#define f16D4 PlayerOptions.Humanity
#define f1720 LastTurnAck
#define field_1718 PlayerOptions.GameHasStarted
#define field_001c MeHost
#define field_0020 HaveHostInit
#define field_1590 PlayerOptions.CommandTurnIncrement
#define field_10c8 current_turn
#define field_155c PlayerOptions.CurrentTurn
#define field_10dc AcknowledgeAfterMsec
#define field_10e0 Me
#define field_10e4 Multiplayer
#define field_128c turnstart
#define field_1294 mselapsed
#define field_0008 Steps
#define field_151c WaitingForAck
#define field_14c4 InQ
#define field_14c8 OutQ
#define field_12a8 ShuttingDown
#define clear_13c0 clear_13c0_alias

#include "matching/00425750_GameOver.cpp"
#include "matching/00425780_WaitingOnNamedInfo.cpp"
#include "matching/00425800_WaitingOnInfo.cpp"
#include "scratch/004258E0_StopIfSyncFail.cpp"
#include "matching/00425910_ShowSyncChatMsgs.cpp"
#define debug_log com_hand_drop_debug_log
#include "scratch/00425930_DropPacketsIntentionally.cpp"
#undef debug_log
#include "matching/00425960_SetStepMode.cpp"
#include "matching/00425970_SetSpeedControl.cpp"
#include "matching/00425990_CalculatePlayerRange.cpp"
#include "matching/00425A20_Step.cpp"
#include "matching/00425A40_TCommunications_Handler.cpp"
#include "accepted_drift/004261E0_TCommunications_Handler.cpp"
#include "matching/00426350_KillAnyMissingPlayers.cpp"
#undef g_pDirectPlay
#include "scratch/00426470_AddCommand.cpp"
#include "../include/com_hand_resender_ctor_context.h"
#include "matching/004264D0_get_command.cpp"
#include "matching/00426510_new_command.cpp"
#include "matching/00426530_NewCommand.cpp"
#include "../include/com_hand_resender_dtor_context.h"
#include "../include/com_hand_holder_ctor_context.h"
#include "matching/00426630_LastWorldRandom.cpp"
#include "../include/com_hand_holder_dtor_context.h"
#include "accepted_drift/00426650_DoCycle.cpp"
#undef S
#undef LAST_COMM_DUMP
#undef LAST_SENT_TIME
#undef COMM_STATE_PAUSE
#undef COMM_STATE_JOINNOW
#undef COMM_STATE_RUNNING
#undef COMM_SYNC_ERROR
#undef COMM_PLAYER_NOT_RESPONDING
#undef COMM_PLAYER_DROPPED
#undef rge_base_game
#include "matching/00426D40_HasKicked.cpp"
#include "matching/00426D50_SendPlayerName.cpp"
#include "matching/00426DC0_LogRXMsg.cpp"
#include "matching/00426E10_ReceiveGameMessages.cpp"
#undef debug_once
#undef last_time
#undef last_rx
#undef last_tx
#undef dplay_id
#undef dplay
#undef log_obj
#include "matching/00426FB0_ShutdownGameMessages.cpp"
#include "matching/00426FC0_GetDPLAYMessages.cpp"
#include "matching/00427300_CheckPingTime.cpp"
#include "matching/00427390_TXPing.cpp"
#define debug_log com_hand_ping_debug_log
#include "matching/00427440_TXDebugPing.cpp"
#undef debug_log
#include "matching/004274B0_FastSend.cpp"
#undef E_FAIL
#undef E_INVALIDARG
#undef S_SEND_SELF
#undef S_BAD_DCOID
#undef S_SLOW_FASTSEND
#undef S_INVALIDARG
#undef S_FASTSEND_FAIL
#undef S_COM_HAND_CPP
#include "scratch/00427600_PreprocessMessages.cpp"
#undef L
#define L com_hand_global_log
#undef S
#undef CS
#undef DCO_SELF
#undef DIRECT_PLAY
#undef RX_MESSAGE_PTR
#undef RX_MESSAGE_BASE
#undef DROP_COUNT
#undef LAST_SENT_TIME
#undef RGE_BASE_GAME
#include "scratch/00428270_NotifyWindow.cpp"
#include "matching/00428280_NotifyWindowParam.cpp"
#include "scratch/004282C0_EvaluatePlayerMessage.cpp"
#undef S
#include "matching/004286F0_SetPlayerStopTurn.cpp"
#include "matching/00428710_CheckPlayerStopTurn.cpp"
#undef L
#define L com_hand_global_log
#undef S
#include "matching/00428810_ReleaseSettings.cpp"
#include "scratch/00428820_SendSharedData.cpp"
#include "matching/004289A0_TEST.cpp"
#include "matching/00428A70_SetSelfPlayer.cpp"
#include "matching/00428B10_DropDeadPlayer.cpp"
#undef S
#include "matching/00428DA0_EvaluateSystemMessage.cpp"
#include "matching/00429760_SendGroupChatMsg.cpp"
#include "scratch/004297D0_SendChatMsgAll.cpp"
#include "accepted_drift/00429810_SendChatMsg.cpp"
#include "matching/00429870_TXChat.cpp"
#include "matching/00429A30_SendSpeedChange.cpp"
#include "scratch/00429A90_SendIResignMsg.cpp"
#include "matching/00429BD0_HiTurnAcknowledged.cpp"
#include "matching/00429C40_AllPlayersAcknowledged.cpp"
#include "matching/00429CE0_SendChecksumMessage.cpp"
#include "scratch/00429D90_ExecuteIncoming.cpp"
#include "matching/00429F80_ClearAllSerialNumbers.cpp"
#include "accepted_drift/00429FD0_ClearRXandTX.cpp"
#include "matching/0042A060_ClearRXForPlayer.cpp"
#define debug_log com_hand_count_debug_log
#include "scratch/0042A0C0_CountWaitingMessages.cpp"
#undef debug_log
#include "scratch/0042A130_ClearTXForPlayer.cpp"
#include "matching/0042A160_ClearRXTXForPlayer.cpp"
#include "accepted_drift/0042A180_StoreIncoming.cpp"
#include "scratch/0042A330_StoreForResend.cpp"
#include "matching/0042A540_TXAcknowledgeMessage.cpp"
#include "matching/0042A650_RXAcknowledgeStoredMessage.cpp"
#undef G_LOG_PTR
#include "verified_logic/0042A6E0_PurgeAcknowledgedStoredMessages.cpp"
#include "scratch/0042A800_SendStoredMessages.cpp"
#include "scratch/0042AD10_TXResendReply.cpp"
#include "matching/0042B0A0_TXResendRequest.cpp"
#include "accepted_drift/0042B200_GetNextSequence.cpp"
#include "accepted_drift/0042B270_CommOut.cpp"
#undef L
#define L com_hand_global_log
#undef DIRECT_PLAY
#undef DCO_SELF
#undef COM_HAND_CPP
#include "scratch/0042B860_DestroyMultiplayerGame.cpp"
#include "matching/0042BAD0_GetCommunicationsStatus.cpp"
#include "matching/0042BAE0_UnlinkCurrentLevel.cpp"
#include "accepted_drift/0042C5D0_UnlinkToLevel.cpp"
#include "matching/0042C690_AnalyzeCommunicationsStatus.cpp"
#include "accepted_drift/0042C7A0_ResetLastCommunicationTimes.cpp"
#include "matching/0042C7F0_IsPaused.cpp"
#include "matching/0042C800_DropAllHostedPlayers.cpp"
#include "matching/0042C840_LocalResumeGame.cpp"
#include "matching/0042C860_LocalPauseGame.cpp"
#include "scratch/0042C880_SendPauseGame.cpp"
#include "matching/0042C8F0_TogglePauseGame.cpp"
#include "matching/0042C930_RequestPauseGame.cpp"
#include "matching/0042C9A0_RequestResumeGame.cpp"
#include "matching/0042CA20_SetRandomSeed.cpp"
#include "matching/0042CA90_GetRandomSeed.cpp"
#include "matching/0042CAF0_WhoAmI.cpp"
#include "matching/0042CB00_IsHost.cpp"
#include "matching/0042CB20_GetCommStateStr.cpp"
#include "matching/0042CB30_GetReadyPlayerStr.cpp"
#include "matching/0042CC00_GetPlayerHumanity.cpp"
#include "matching/0042CC30_SetPlayerHumanity.cpp"
#include "matching/0042CC90_GetActivePlayerCount.cpp"
#include "matching/0042CCD0_IsPlayerHuman.cpp"
#include "matching/0042CD10_IsPlayerComputer.cpp"
#include "matching/0042CD50_GetCommInfo.cpp"
#include "matching/0042D0E0_GetPlayerName.cpp"
#include "matching/0042D120_UpdatePlayerInformation.cpp"
#include "matching/0042D170_IsLobbyLaunched.cpp"
#include "matching/0042D180_LaunchLobbyGame.cpp"
#include "matching/0042D2D0_InitPlayerInformation.cpp"
#include "scratch/0042D3B0_SetGameTitle.cpp"
#include "matching/0042D3E0_SetMyPlayerName.cpp"
#include "matching/0042D440_SetPlayerName.cpp"
#include "matching/0042D490_SetWindowHandle.cpp"
#include "matching/0042D4A0_CreateDirectPlayConversation.cpp"
#include "matching/0042D580_OpenMultiplayerConnection.cpp"
#include "matching/0042D590_CreateMultiplayerGame.cpp"
#include "matching/0042D720_PackPlayersDown.cpp"
#include "matching/0042D960_AddSelfPlayer.cpp"
#undef COMM_STATE_ERROR
#include "scratch/0042DA50_InitJoinGame.cpp"
#include "accepted_drift/0042DA80_JoinMultiplayerGame.cpp"
#undef g_pDirectPlay
#undef g_pDebugLog
#undef STR_NO_DP
#undef STR_OPEN_JOIN
#undef STR_JOIN_MP
#undef FIELD_DWORD
#undef FIELD_GUID
#include "matching/0042DC20_LaunchMultiplayerGame.cpp"
#include "accepted_drift/0042DD70_GetMyMultiPlayerCaps.cpp"
#undef OFF
#undef OFF_BYTE
#include "matching/0042DEA0_SetApplicationGUID.cpp"
#include "matching/0042DED0_GetDPInterface.cpp"
#include "matching/0042DEE0_SetServiceGUID.cpp"
#include "matching/0042DF10_SetSessionGUID.cpp"
#include "matching/0042DF40_UpdatePlayers.cpp"
#include "scratch/0042DF90_UpdatePlayer.cpp"
#undef g_pDirectPlay
#include "accepted_drift/0042E380_SetMyReadiness.cpp"
#undef L
#define L com_hand_global_log
#undef STR_SET_MY_READINESS
#undef STR_TX_RDY
#undef FIELD_DWORD
#undef FIELD_BYTE
#undef ARR
#include "matching/0042E500_GetClientReadiness.cpp"
#include "scratch/0042E580_IsPlayerReady.cpp"
#include "scratch/0042E5B0_ComputerPlayerGameStart.cpp"
#include "scratch/0042E5E0_MultiplayerGameStart.cpp"
#include "matching/0042E610_AllPlayersReady.cpp"
#include "matching/0042E670_DPlayGetSessionDesc.cpp"
#include "matching/0042E730_CommGetCaps.cpp"
#include "matching/0042E920_CloseSession.cpp"
#include "matching/0042E9B0_ReleaseComm.cpp"
#include "matching/0042EA10_Kick.cpp"
#include "matching/0042EB10_DestroyMyPlayer.cpp"
#include "matching/0042EB60_SetMyGameOptions.cpp"
#include "matching/0042EBF0_GetMyGameOptions.cpp"
#include "scratch/0042EC10_FreeOptions.cpp"
#include "matching/0042EC40_StringFromGUID.cpp"
#include "matching/0042ECC0_SetHostPlayerNumber.cpp"
#include "matching/0042ECD0_GetHostPlayerNumber.cpp"
#include "matching/0042ECE0_DebugSessionInformation.cpp"
#include "matching/0042EF00_EnableNewPlayers.cpp"
#include "matching/0042EF60_OutOfSync.cpp"
#include "matching/0042EF80_SendZoneMessage.cpp"
#include "matching/0042F040_EnumPlayersCallback2.cpp"
#include "scratch/0042F110_ForcePlayerEnumeration.cpp"
#include "scratch/0042F140_ForcePlayerDestroyAndCreate.cpp"
#include "matching/0042F190_ForceNameChange.cpp"
#include "matching/0042F230_SetSpeedV1.cpp"
#include "matching/0042F250_SetSpeedV2.cpp"
#include "matching/0042F270_IsPlayerOutOfSync.cpp"
