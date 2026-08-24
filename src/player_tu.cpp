// Authentic player.cpp prefix.
//
// This is the largest currently compilable PDB-ordered prefix.  It stops at
// scenario_load, whose scratch source still has 232 grouped bytes of drift.
// Keep the prefix honest: later anchors are not inserted before that owner.
//
// PDB source order and retained evidence:
//   0046E4B0  player.cpp:91-167   isolated exact load-constructor anchor
//   0046E770  player.cpp:177-274  reviewed constructor drift
//   0046EB00  player.cpp:279-325  isolated exact destructor anchor
//   0046ECE0-0046F410             28 exact ordinary and recovered owners
//
// The prefix has 31 normal owners: 30 exact and one accepted drift.  The
// compiler also emits the exact scalar deleting destructor at 0046E750.
// The first excluded normal owner is 0046F420 scenario_load.  The remaining
// player.cpp owners are inventoried in the captain report.
//
// Their source files retain sole ownership of their VAs.

#define PLAYER_GROUPED_TU
#include "../include/player_context.h"

#include "matching/0046E4B0_RGE_Player.cpp"
#include "accepted_drift/0046E770_RGE_Player.cpp"
#include "matching/0046EB00_RGE_Player.cpp"
#include "matching/0046ECE0_set_game_status.cpp"
#include "matching/0046ED50_do_resign.cpp"
#include "matching/0046ed90_get_resigned.cpp"
#include "matching/0046eda0_aiStatus.cpp"
#include "matching/0046edb0_computerPlayer.cpp"
#include "matching/0046EDC0_isEnemy.cpp"
#include "matching/0046EE00_isAlly.cpp"
#include "matching/0046EE40_isNeutral.cpp"
#include "matching/0046EE80_isAllNeutral.cpp"
#include "matching/0046eed0_setDiplomaticStance.cpp"
#include "matching/0046eee0_loadAIInformation.cpp"
#include "matching/0046EEF0_sendUnitAIOrder.cpp"
#include "matching/0046EF40_processAIOrder.cpp"
#include "matching/0046EFB0_sendGameOrder.cpp"
#include "matching/0046EFE0_sendAddWaypointCommand.cpp"
#include "matching/0046F010_processAddWaypointCommand.cpp"
#include "matching/0046F050_sendPlayCommand.cpp"
#include "matching/0046F140_sendPlayCommand.cpp"
#include "matching/0046f200_pathingAttemptCap.cpp"
#include "matching/0046f210_setPathingAttemptCap.cpp"
#include "matching/0046f220_pathingDelayCap.cpp"
#include "matching/0046f230_setPathingDelayCap.cpp"
#include "matching/0046f240_currentUpdatePathingAttempts.cpp"
#include "matching/0046F250_availablePathingAttempts.cpp"
#include "matching/0046f290_incrementPathingAttempts.cpp"
#include "matching/0046F2A0_sendChatMessage.cpp"
#include "matching/0046F3A0_make_scenario_obj.cpp"
#include "matching/0046f410_scenario_save.cpp"

#undef PLAYER_GROUPED_TU
