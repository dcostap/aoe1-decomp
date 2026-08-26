// Authentic gameinfo.cpp owner wrapper.
//
// Module: C:\\msdev\\work\\age1_x1\\gameinfo.cpp.
// PDB line order and exact anchors:
//   0044C5A0-0044CBB0 RGE_Campaign_Info owners, lines 28-238
//   0044CBC0-0044CEF0 RGE_Campaign_Info / RGE_Person_Info owners, lines 242-396
//   0044D050-0044D180 RGE_Person_Info owners, lines 400-451
//   0044D1A0-0044D9E0 RGE_Game_Info owners, lines 467-757
//   0044DA00-0044DA50 RGE_Game_Info owners, lines 761-792
//
// The shared context owns one canonical class surface.  The included files
// retain their complete owner bodies and are ordered by the PDB address bands.
#define GAMEINFO_SHARED_CONTEXT 1
#include "../include/gameinfo_context.h"

#include "matching/0044C5A0_RGE_Campaign_Info.cpp"
#include "matching/0044C780_RGE_Campaign_Info.cpp"
#include "matching/0044C870_RGE_Campaign_Info.cpp"
#include "matching/0044C8A0_save.cpp"
#include "matching/0044C930_rehook_campaigns.cpp"
#include "matching/0044CA90_set_current_scenario.cpp"
#include "matching/0044CAD0_verify_campaign_name.cpp"
#include "matching/0044CB20_get_scenario_list.cpp"
#include "matching/0044CBB0_get_current_scenario.cpp"
#include "matching/0044CBC0_notify_of_scenario_complete.cpp"
#include "matching/0044CC20_open_scenario.cpp"
#include "matching/0044CC40_RGE_Person_Info.cpp"
#include "matching/0044CD40_RGE_Person_Info.cpp"
#include "matching/0044CDA0_RGE_Person_Info.cpp"
#include "matching/0044CE10_save.cpp"
#include "matching/0044CE90_rehook_campaigns.cpp"
#include "matching/0044CEE0_get_name.cpp"
#include "matching/0044CEF0_set_current_campaign.cpp"
#include "matching/0044D050_get_current_campaign.cpp"

#include "matching/0044D0C0_get_current_scenario.cpp"
#include "matching/0044D0F0_set_current_scenario.cpp"
#include "matching/0044D130_get_scenario_list.cpp"
#include "matching/0044D160_notify_of_scenario_complete.cpp"
#include "matching/0044D180_open_scenario.cpp"

#include "matching/0044D1A0_RGE_Game_Info.cpp"
#include "matching/0044D300_RGE_Game_Info.cpp"
#include "matching/0044D3B0_save.cpp"
#include "matching/0044D470_find_campaigns.cpp"
#include "matching/0044D710_add_new_person.cpp"
#include "matching/0044D7D0_set_current_person.cpp"
#include "matching/0044D7F0_set_current_campaign.cpp"
#include "matching/0044D820_set_current_scenario.cpp"
#include "matching/0044D850_get_people_list.cpp"
#include "matching/0044D8C0_get_campaign_list.cpp"
#include "matching/0044D940_get_scenario_list.cpp"
#include "matching/0044D990_get_current_scenario.cpp"
#include "matching/0044D9B0_get_current_campaign.cpp"
#include "matching/0044D9D0_get_current_player.cpp"
#include "matching/0044D9E0_get_current_player_name.cpp"
#include "matching/0044DA00_notify_of_scenario_complete.cpp"
#include "matching/0044DA30_open_scenario.cpp"
#include "matching/0044DA50_remove_player.cpp"

#undef GAMEINFO_SHARED_CONTEXT
