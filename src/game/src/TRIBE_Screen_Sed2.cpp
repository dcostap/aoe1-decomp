#include "../include/TRIBE_Screen_Sed.h"

// TODO: This file is decomp-first transliteration scaffolding for scr_sed2.cpp.
// TODO: Function bodies currently mirror raw decompiler placeholders and require parity fill-in.

// Auto-generated decompiler unit: scr_sed2.cpp.decomp
// SourceMap: C:/msdev/work/age1_x1/scr_sed2.cpp
#include "../include/common.h"

// Offset: 0x004ADC80
void SaveDisabledItemsInScenario(TRIBE_Screen_Sed* this_) {
    // --- Ghidra decompiler output ---
    // 
    // /* protected: void __thiscall TRIBE_Screen_Sed::SaveDisabledItemsInScenario(void) */
    // 
    // void __thiscall TRIBE_Screen_Sed::SaveDisabledItemsInScenario(TRIBE_Screen_Sed *this)
    // 
    // {
    //   short sVar1;
    //   int iVar2;
    //   long lVar3;
    //   T_Scenario *this_00;
    //   TButtonPanel **ppTVar4;
    //   int iVar5;
    //   
    //   if (this->player_num == 0) {
    //     this->player_num = 1;
    //   }
    //   iVar5 = 0;
    //   ppTVar4 = this->options_disable_button;
    //   do {
    //     iVar2 = TButtonPanel::get_state(*ppTVar4);
    //     if (iVar2 == 0) {
    //       sVar1 = this->player_num;
    //       this_00 = (T_Scenario *)this->world->_padding_;
    //     }
    //     else {
    //       sVar1 = this->player_num;
    //       this_00 = (T_Scenario *)this->world->_padding_;
    //     }
    //     T_Scenario::SetDisabledTechnology(this_00,sVar1 + -1,iVar5,(uint)(iVar2 == 0));
    //     iVar5 = iVar5 + 1;
    //     ppTVar4 = ppTVar4 + 1;
    //   } while (iVar5 < 0x10);
    //   lVar3 = TDropDownPanel::get_line(this->options_player_list);
    //   this->player_num = (short)lVar3 + 1;
    //   return;
    // }
    // 
    // 
}

// Offset: 0x004ADD00
void LoadDisabledItemsFromScenario(TRIBE_Screen_Sed* this_) {
    // --- Ghidra decompiler output ---
    // 
    // /* protected: void __thiscall TRIBE_Screen_Sed::LoadDisabledItemsFromScenario(void) */
    // 
    // void __thiscall TRIBE_Screen_Sed::LoadDisabledItemsFromScenario(TRIBE_Screen_Sed *this)
    // 
    // {
    //   int iVar1;
    //   int iVar2;
    //   TButtonPanel **ppTVar3;
    //   
    //   iVar2 = 0;
    //   ppTVar3 = this->options_disable_button;
    //   do {
    //     iVar1 = T_Scenario::GetDisabledTechnology
    //                       ((T_Scenario *)this->world->_padding_,this->player_num + -1,iVar2);
    //     if (iVar1 == 0) {
    //       (**(code **)((*ppTVar3)->_padding_ + 0xe0))(1);
    //     }
    //     else {
    //       (**(code **)((*ppTVar3)->_padding_ + 0xe0))(0);
    //     }
    //     iVar2 = iVar2 + 1;
    //     ppTVar3 = ppTVar3 + 1;
    //   } while (iVar2 < 0x10);
    //   return;
    // }
    // 
    // 
}

// Offset: 0x004ADD50
void save_info_in_scenario(TRIBE_Screen_Sed* this_) {
    // --- Ghidra decompiler output ---
    // 
    // /* protected: void __thiscall TRIBE_Screen_Sed::save_info_in_scenario(void) */
    // 
    // void __thiscall TRIBE_Screen_Sed::save_info_in_scenario(TRIBE_Screen_Sed *this)
    // 
    // {
    //   return;
    // }
    // 
    // 
}

// Offset: 0x004ADD60
void save_multi_victory_cond_in_scenario(TRIBE_Screen_Sed* this_) {
    // --- Ghidra decompiler output ---
    // 
    // /* protected: void __thiscall TRIBE_Screen_Sed::save_multi_victory_cond_in_scenario(void) */
    // 
    // void __thiscall TRIBE_Screen_Sed::save_multi_victory_cond_in_scenario(TRIBE_Screen_Sed *this)
    // 
    // {
    //   long lVar1;
    //   char *pcVar2;
    //   int iVar3;
    //   T_Scenario *pTVar4;
    //   int iVar5;
    //   
    //   switch(this->mp_victory_type) {
    //   case VictoryTypeStandard:
    //     iVar5 = 0;
    //     pTVar4 = (T_Scenario *)this->world->_padding_;
    //     break;
    //   case VictoryTypeConquest:
    //     iVar5 = 1;
    //     goto LAB_004adda4;
    //   case VictoryTypeScore:
    //     iVar5 = 2;
    //     pTVar4 = (T_Scenario *)this->world->_padding_;
    //     break;
    //   case VictoryTypeTime:
    //     iVar5 = 3;
    //     pTVar4 = (T_Scenario *)this->world->_padding_;
    //     break;
    //   default:
    //     iVar5 = 4;
    // LAB_004adda4:
    //     pTVar4 = (T_Scenario *)this->world->_padding_;
    //   }
    //   T_Scenario::SetMPVictory(pTVar4,iVar5);
    //   lVar1 = TDropDownPanel::get_id(this->victory_score);
    //   T_Scenario::SetVictoryScore((T_Scenario *)this->world->_padding_,lVar1);
    //   lVar1 = TDropDownPanel::get_id(this->victory_time);
    //   T_Scenario::SetVictoryTime((T_Scenario *)this->world->_padding_,lVar1);
    //   iVar5 = TButtonPanel::get_state(this->victory_cond_type[0]);
    //   if (iVar5 != 0) {
    //     iVar5 = 0;
    //     pTVar4 = (T_Scenario *)this->world->_padding_;
    //     goto LAB_004ade58;
    //   }
    //   iVar5 = TButtonPanel::get_state(this->victory_cond_type[1]);
    //   if (iVar5 == 0) {
    //     iVar5 = TButtonPanel::get_state(this->victory_cond_type[2]);
    //     if (iVar5 != 0) {
    //       iVar5 = 2;
    //       pTVar4 = (T_Scenario *)this->world->_padding_;
    //       goto LAB_004ade58;
    //     }
    //     iVar5 = TButtonPanel::get_state(this->victory_cond_type[3]);
    //     if (iVar5 != 0) {
    //       iVar5 = 3;
    //       pTVar4 = (T_Scenario *)this->world->_padding_;
    //       goto LAB_004ade58;
    //     }
    //     iVar5 = 4;
    //   }
    //   else {
    //     iVar5 = 1;
    //   }
    //   pTVar4 = (T_Scenario *)this->world->_padding_;
    // LAB_004ade58:
    //   T_Scenario::SetMPVictory(pTVar4,iVar5);
    //   lVar1 = TDropDownPanel::get_id(this->victory_score);
    //   T_Scenario::SetVictoryScore((T_Scenario *)this->world->_padding_,lVar1);
    //   lVar1 = TDropDownPanel::get_id(this->victory_time);
    //   T_Scenario::SetVictoryTime((T_Scenario *)this->world->_padding_,lVar1);
    //   iVar5 = TButtonPanel::get_state(this->victory_and_or[1]);
    //   if (iVar5 == 0) {
    //     pTVar4 = (T_Scenario *)this->world->_padding_;
    //   }
    //   else {
    //     pTVar4 = (T_Scenario *)this->world->_padding_;
    //   }
    //   T_Scenario::Set_victory_all_flag(pTVar4,(uint)(iVar5 != 0));
    //   iVar5 = TButtonPanel::get_state(this->victory_cond_on[0]);
    //   if ((iVar5 == 0) && (iVar5 = TButtonPanel::get_state(this->victory_cond_type[4]), iVar5 != 0)) {
    //     iVar5 = 0;
    //     pTVar4 = (T_Scenario *)this->world->_padding_;
    //   }
    //   else {
    //     iVar5 = 1;
    //     pTVar4 = (T_Scenario *)this->world->_padding_;
    //   }
    //   T_Scenario::Set_Multi_Conquest(pTVar4,iVar5);
    //   pcVar2 = TEditPanel::currentLine(this->victory_condition_explore);
    //   iVar5 = atoi(pcVar2);
    //   iVar3 = TButtonPanel::get_state(this->victory_cond_on[1]);
    //   if (iVar3 == 0) {
    //     iVar5 = 0;
    //     pTVar4 = (T_Scenario *)this->world->_padding_;
    //   }
    //   else {
    //     if (iVar5 < 1) {
    //       iVar5 = 1;
    //     }
    //     if (100 < iVar5) {
    //       iVar5 = 100;
    //     }
    //     pTVar4 = (T_Scenario *)this->world->_padding_;
    //   }
    //   T_Scenario::Set_Multi_Exploration(pTVar4,iVar5);
    //   pcVar2 = TEditPanel::currentLine(this->victory_condition_ruins);
    //   iVar5 = atoi(pcVar2);
    //   iVar3 = TButtonPanel::get_state(this->victory_cond_on[2]);
    //   if (iVar3 == 0) {
    //     iVar5 = 0;
    //     pTVar4 = (T_Scenario *)this->world->_padding_;
    //   }
    //   else {
    //     pTVar4 = (T_Scenario *)this->world->_padding_;
    //   }
    //   T_Scenario::Set_Multi_Ruins(pTVar4,iVar5);
    //   pcVar2 = TEditPanel::currentLine(this->victory_condition_artifacts);
    //   iVar5 = atoi(pcVar2);
    //   iVar3 = TButtonPanel::get_state(this->victory_cond_on[3]);
    //   if (iVar3 == 0) {
    //     iVar5 = 0;
    //     pTVar4 = (T_Scenario *)this->world->_padding_;
    //   }
    //   else {
    //     pTVar4 = (T_Scenario *)this->world->_padding_;
    //   }
    //   T_Scenario::Set_Multi_Artifacts(pTVar4,iVar5);
    //   pcVar2 = TEditPanel::currentLine(this->victory_condition_discoveries);
    //   iVar5 = atoi(pcVar2);
    //   iVar3 = TButtonPanel::get_state(this->victory_cond_on[4]);
    //   if (iVar3 == 0) {
    //     iVar5 = 0;
    //     pTVar4 = (T_Scenario *)this->world->_padding_;
    //   }
    //   else {
    //     pTVar4 = (T_Scenario *)this->world->_padding_;
    //   }
    //   T_Scenario::Set_Multi_Discoveries(pTVar4,iVar5);
    //   pcVar2 = TEditPanel::currentLine(this->victory_condition_gold);
    //   iVar5 = atoi(pcVar2);
    //   iVar3 = TButtonPanel::get_state(this->victory_cond_on[5]);
    //   if (iVar3 == 0) {
    //     T_Scenario::Set_Multi_Gold((T_Scenario *)this->world->_padding_,0);
    //     return;
    //   }
    //   T_Scenario::Set_Multi_Gold((T_Scenario *)this->world->_padding_,iVar5);
    //   return;
    // }
    // 
    // 
}

// Offset: 0x004AE05A
void FUN_004ae05a(int param_1) {
    // --- Ghidra decompiler output ---
    // 
    // void FUN_004ae05a(int param_1)
    // 
    // {
    //   char in_AL;
    //   int iVar1;
    //   char *pcVar2;
    //   long lVar3;
    //   long lVar4;
    //   int in_ECX;
    //   T_Scenario *pTVar5;
    //   int in_EDX;
    //   int unaff_EBX;
    //   int unaff_EBP;
    //   int iVar6;
    //   int unaff_EDI;
    //   bool in_CF;
    //   bool in_ZF;
    //   int iStack_14;
    //   int iStack_10;
    //   int iStack_c;
    //   long lStack_8;
    //   
    //   if (!in_CF && !in_ZF) {
    //     lStack_8 = 0x4ae044;
    //     T_Scenario::Set_Multi_Gold(*(T_Scenario **)(in_EDX + 0x5c),unaff_EDI);
    //     return;
    //   }
    //   pcVar2 = (char *)(unaff_EBP + -0x2277ffb6 + unaff_EBX * 8);
    //   *pcVar2 = *pcVar2 + in_AL;
    //   *(char *)(unaff_EBP + -0x6fffb523) = *(char *)(unaff_EBP + -0x6fffb523) + (char)in_EDX + -2;
    //   iVar1 = TButtonPanel::get_state(*(TButtonPanel **)(in_ECX + 0x684));
    //   if (iVar1 == 0) {
    //     pTVar5 = *(T_Scenario **)(*(int *)(in_ECX + 0x928) + 0x5c);
    //   }
    //   else {
    //     pTVar5 = *(T_Scenario **)(*(int *)(in_ECX + 0x928) + 0x5c);
    //   }
    //   T_Scenario::Set_victory_all_flag(pTVar5,(uint)(iVar1 != 0));
    //   iVar1 = TButtonPanel::get_state(*(TButtonPanel **)(in_ECX + 0x668));
    //   if ((iVar1 == 0) &&
    //      (iVar1 = TButtonPanel::get_state(*(TButtonPanel **)(in_ECX + 0x6f0)), iVar1 != 0)) {
    //     iVar1 = 0;
    //     pTVar5 = *(T_Scenario **)(*(int *)(in_ECX + 0x928) + 0x5c);
    //   }
    //   else {
    //     iVar1 = 1;
    //     pTVar5 = *(T_Scenario **)(*(int *)(in_ECX + 0x928) + 0x5c);
    //   }
    //   T_Scenario::Set_Multi_Conquest(pTVar5,iVar1);
    //   if (param_1 < 0) {
    //     return;
    //   }
    //   pcVar2 = TEditPanel::currentLine(*(TEditPanel **)(in_ECX + 0x76c));
    //   iVar1 = atoi(pcVar2);
    //   lVar3 = TDropDownPanel::get_line(*(TDropDownPanel **)(in_ECX + 0x734));
    //   lVar4 = TDropDownPanel::get_line(*(TDropDownPanel **)(in_ECX + 0x740));
    //   iVar6 = lVar4 + 1;
    //   lVar4 = TDropDownPanel::get_id(*(TDropDownPanel **)(in_ECX + 0x738));
    //   RGE_View::get_selection_area
    //             (*(RGE_View **)(in_ECX + 0x4c8),&iStack_14,&iStack_10,&iStack_c,&lStack_8,1);
    //   *(float *)(in_ECX + 0x488) = (float)iStack_14;
    //   *(float *)(in_ECX + 0x48c) = (float)iStack_10;
    //   *(float *)(in_ECX + 0x490) = (float)iStack_c;
    //   *(float *)(in_ECX + 0x494) = (float)lStack_8;
    //   T_Scenario::ClearSPVictoryCondition(*(T_Scenario **)(*(int *)(in_ECX + 0x928) + 0x5c),param_1);
    //   switch(lVar3) {
    //   case 1:
    //     if ((*(int *)(in_ECX + 0x480) != 0) && (*(int *)(in_ECX + 0x484) != 0)) {
    //       T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(in_ECX + 0x928) + 0x5c),param_1,3);
    //       T_Scenario::SetSPObject
    //                 (*(T_Scenario **)(*(int *)(in_ECX + 0x928) + 0x5c),param_1,
    //                  *(RGE_Static_Object **)(in_ECX + 0x480));
    //       T_Scenario::SetSPDestObjectID
    //                 (*(T_Scenario **)(*(int *)(in_ECX + 0x928) + 0x5c),param_1,
    //                  *(RGE_Static_Object **)(in_ECX + 0x484));
    //       return;
    //     }
    //     break;
    //   case 2:
    //     if (*(int *)(in_ECX + 0x480) != 0) {
    //       T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(in_ECX + 0x928) + 0x5c),param_1,3);
    //       T_Scenario::SetSPObject
    //                 (*(T_Scenario **)(*(int *)(in_ECX + 0x928) + 0x5c),param_1,
    //                  *(RGE_Static_Object **)(in_ECX + 0x480));
    //       T_Scenario::SetSPRectangle
    //                 (*(T_Scenario **)(*(int *)(in_ECX + 0x928) + 0x5c),param_1,
    //                  *(float *)(in_ECX + 0x488),*(float *)(in_ECX + 0x48c),*(float *)(in_ECX + 0x490),
    //                  *(float *)(in_ECX + 0x494));
    //       return;
    //     }
    //     break;
    //   case 3:
    //     T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(in_ECX + 0x928) + 0x5c),param_1,2);
    //     T_Scenario::SetSPObjectType(*(T_Scenario **)(*(int *)(in_ECX + 0x928) + 0x5c),param_1,lVar4);
    //     goto LAB_004ae57f;
    //   case 4:
    //     T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(in_ECX + 0x928) + 0x5c),param_1,2);
    //     T_Scenario::SetSPObjectType(*(T_Scenario **)(*(int *)(in_ECX + 0x928) + 0x5c),param_1,lVar4);
    //     T_Scenario::SetSPAmount(*(T_Scenario **)(*(int *)(in_ECX + 0x928) + 0x5c),param_1,iVar1);
    //     T_Scenario::SetSPRectangle
    //               (*(T_Scenario **)(*(int *)(in_ECX + 0x928) + 0x5c),param_1,*(float *)(in_ECX + 0x488),
    //                *(float *)(in_ECX + 0x48c),*(float *)(in_ECX + 0x490),*(float *)(in_ECX + 0x494));
    //     return;
    //   case 5:
    //     if (((0 < iVar6) && (iVar6 < 9)) && (iVar1 != 0)) {
    //       T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(in_ECX + 0x928) + 0x5c),param_1,1);
    //       T_Scenario::SetSPPlayerID(*(T_Scenario **)(*(int *)(in_ECX + 0x928) + 0x5c),param_1,iVar6);
    //       T_Scenario::SetSPObjectType(*(T_Scenario **)(*(int *)(in_ECX + 0x928) + 0x5c),param_1,lVar4);
    //       T_Scenario::SetSPAmount(*(T_Scenario **)(*(int *)(in_ECX + 0x928) + 0x5c),param_1,iVar1);
    //       return;
    //     }
    //     break;
    //   case 6:
    //     if (*(int *)(in_ECX + 0x480) != 0) {
    //       T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(in_ECX + 0x928) + 0x5c),param_1,1);
    //       T_Scenario::SetSPObject
    //                 (*(T_Scenario **)(*(int *)(in_ECX + 0x928) + 0x5c),param_1,
    //                  *(RGE_Static_Object **)(in_ECX + 0x480));
    //       return;
    //     }
    //     break;
    //   case 7:
    //     if ((0 < iVar6) && (iVar6 < 9)) {
    //       T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(in_ECX + 0x928) + 0x5c),param_1,1);
    //       T_Scenario::SetSPPlayerID(*(T_Scenario **)(*(int *)(in_ECX + 0x928) + 0x5c),param_1,iVar6);
    //       T_Scenario::SetSPObjectType(*(T_Scenario **)(*(int *)(in_ECX + 0x928) + 0x5c),param_1,lVar4);
    //       T_Scenario::SetSPAllFlag(*(T_Scenario **)(*(int *)(in_ECX + 0x928) + 0x5c),param_1,1);
    //       return;
    //     }
    //     break;
    //   case 8:
    //     if ((0 < iVar6) && (iVar6 < 9)) {
    //       T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(in_ECX + 0x928) + 0x5c),param_1,1);
    //       T_Scenario::SetSPPlayerID(*(T_Scenario **)(*(int *)(in_ECX + 0x928) + 0x5c),param_1,iVar6);
    //       return;
    //     }
    //     break;
    //   case 9:
    //     if (*(int *)(in_ECX + 0x480) != 0) {
    //       T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(in_ECX + 0x928) + 0x5c),param_1,5);
    //       T_Scenario::SetSPObject
    //                 (*(T_Scenario **)(*(int *)(in_ECX + 0x928) + 0x5c),param_1,
    //                  *(RGE_Static_Object **)(in_ECX + 0x480));
    //       return;
    //     }
    //     break;
    //   case 10:
    //     T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(in_ECX + 0x928) + 0x5c),param_1,4);
    //     lVar3 = 0;
    //     goto LAB_004ae570;
    //   case 0xb:
    //     T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(in_ECX + 0x928) + 0x5c),param_1,4);
    //     lVar3 = 3;
    //     goto LAB_004ae570;
    //   case 0xc:
    //     T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(in_ECX + 0x928) + 0x5c),param_1,4);
    //     lVar3 = 1;
    //     goto LAB_004ae570;
    //   case 0xd:
    //     T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(in_ECX + 0x928) + 0x5c),param_1,4);
    //     lVar3 = 2;
    //     goto LAB_004ae570;
    //   case 0xe:
    //     T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(in_ECX + 0x928) + 0x5c),param_1,4);
    //     lVar3 = 4;
    //     goto LAB_004ae570;
    //   case 0xf:
    //     T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(in_ECX + 0x928) + 0x5c),param_1,4);
    //     T_Scenario::SetSPAttribType(*(T_Scenario **)(*(int *)(in_ECX + 0x928) + 0x5c),param_1,5);
    //     lVar3 = TDropDownPanel::get_line(*(TDropDownPanel **)(in_ECX + 0x748));
    //     T_Scenario::SetSPAmount(*(T_Scenario **)(*(int *)(in_ECX + 0x928) + 0x5c),param_1,lVar3 + 1);
    //     return;
    //   case 0x10:
    //     T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(in_ECX + 0x928) + 0x5c),param_1,4);
    //     lVar3 = 6;
    //     goto LAB_004ae570;
    //   case 0x11:
    //     T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(in_ECX + 0x928) + 0x5c),param_1,6);
    //     lVar3 = TDropDownPanel::get_id(*(TDropDownPanel **)(in_ECX + 0x744));
    // LAB_004ae570:
    //     T_Scenario::SetSPAttribType(*(T_Scenario **)(*(int *)(in_ECX + 0x928) + 0x5c),param_1,lVar3);
    // LAB_004ae57f:
    //     T_Scenario::SetSPAmount(*(T_Scenario **)(*(int *)(in_ECX + 0x928) + 0x5c),param_1,iVar1);
    //     return;
    //   case 0x12:
    //     T_Scenario::SetSPVictoryType(*(T_Scenario **)(*(int *)(in_ECX + 0x928) + 0x5c),param_1,7);
    //     lVar3 = TDropDownPanel::get_id(*(TDropDownPanel **)(in_ECX + 0x74c));
    //     T_Scenario::SetSPAttribType(*(T_Scenario **)(*(int *)(in_ECX + 0x928) + 0x5c),param_1,lVar3);
    //   }
    //   return;
    // }
    // 
    // 
    // TODO: Full transliteration pending. Source of truth: scr_sed2.cpp.decomp @ 0x004AE05A
}

// Offset: 0x004AE070
void save_victory_cond_in_scenario(TRIBE_Screen_Sed* this_, int param_2) {
    // --- Ghidra decompiler output ---
    // 
    // /* WARNING: Variable defined which should be unmapped: x1 */
    // /* protected: void __thiscall TRIBE_Screen_Sed::save_victory_cond_in_scenario(int) */
    // 
    // void __thiscall TRIBE_Screen_Sed::save_victory_cond_in_scenario(TRIBE_Screen_Sed *this,int param_1)
    // 
    // {
    //   int iVar1;
    //   char *pcVar2;
    //   long lVar3;
    //   T_Scenario *pTVar4;
    //   int iVar5;
    //   long x1;
    //   long y1;
    //   long x2;
    //   long y2;
    //   int VictoryType;
    //   long local_4;
    //   
    //   iVar1 = TButtonPanel::get_state(this->victory_and_or[1]);
    //   if (iVar1 == 0) {
    //     pTVar4 = (T_Scenario *)this->world->_padding_;
    //   }
    //   else {
    //     pTVar4 = (T_Scenario *)this->world->_padding_;
    //   }
    //   T_Scenario::Set_victory_all_flag(pTVar4,(uint)(iVar1 != 0));
    //   iVar1 = TButtonPanel::get_state(this->victory_cond_on[0]);
    //   if ((iVar1 == 0) && (iVar1 = TButtonPanel::get_state(this->victory_cond_type[4]), iVar1 != 0)) {
    //     iVar1 = 0;
    //     pTVar4 = (T_Scenario *)this->world->_padding_;
    //   }
    //   else {
    //     iVar1 = 1;
    //     pTVar4 = (T_Scenario *)this->world->_padding_;
    //   }
    //   T_Scenario::Set_Multi_Conquest(pTVar4,iVar1);
    //   if (param_1 < 0) {
    //     return;
    //   }
    //   pcVar2 = TEditPanel::currentLine(this->victory_amount_input);
    //   iVar1 = atoi(pcVar2);
    //   local_4 = TDropDownPanel::get_line(this->victory_drop_down);
    //   lVar3 = TDropDownPanel::get_line(this->victory_enemy_player_list);
    //   iVar5 = lVar3 + 1;
    //   lVar3 = TDropDownPanel::get_id(this->victory_object_list);
    //   RGE_View::get_selection_area((RGE_View *)this->main_view,&y1,&x2,&y2,&VictoryType,1);
    //   this->px1 = (float)y1;
    //   this->py1 = (float)x2;
    //   this->px2 = (float)y2;
    //   this->py2 = (float)VictoryType;
    //   T_Scenario::ClearSPVictoryCondition((T_Scenario *)this->world->_padding_,param_1);
    //   switch(local_4) {
    //   case 1:
    //     if ((this->SelectedObject != (RGE_Static_Object *)0x0) &&
    //        (this->DestinationObject != (RGE_Static_Object *)0x0)) {
    //       T_Scenario::SetSPVictoryType((T_Scenario *)this->world->_padding_,param_1,3);
    //       T_Scenario::SetSPObject((T_Scenario *)this->world->_padding_,param_1,this->SelectedObject);
    //       T_Scenario::SetSPDestObjectID
    //                 ((T_Scenario *)this->world->_padding_,param_1,this->DestinationObject);
    //       return;
    //     }
    //     break;
    //   case 2:
    //     if (this->SelectedObject != (RGE_Static_Object *)0x0) {
    //       T_Scenario::SetSPVictoryType((T_Scenario *)this->world->_padding_,param_1,3);
    //       T_Scenario::SetSPObject((T_Scenario *)this->world->_padding_,param_1,this->SelectedObject);
    //       T_Scenario::SetSPRectangle
    //                 ((T_Scenario *)this->world->_padding_,param_1,this->px1,this->py1,this->px2,
    //                  this->py2);
    //       return;
    //     }
    //     break;
    //   case 3:
    //     T_Scenario::SetSPVictoryType((T_Scenario *)this->world->_padding_,param_1,2);
    //     T_Scenario::SetSPObjectType((T_Scenario *)this->world->_padding_,param_1,lVar3);
    //     goto LAB_004ae57f;
    //   case 4:
    //     T_Scenario::SetSPVictoryType((T_Scenario *)this->world->_padding_,param_1,2);
    //     T_Scenario::SetSPObjectType((T_Scenario *)this->world->_padding_,param_1,lVar3);
    //     T_Scenario::SetSPAmount((T_Scenario *)this->world->_padding_,param_1,iVar1);
    //     T_Scenario::SetSPRectangle
    //               ((T_Scenario *)this->world->_padding_,param_1,this->px1,this->py1,this->px2,this->py2)
    //     ;
    //     return;
    //   case 5:
    //     if (((0 < iVar5) && (iVar5 < 9)) && (iVar1 != 0)) {
    //       T_Scenario::SetSPVictoryType((T_Scenario *)this->world->_padding_,param_1,1);
    //       T_Scenario::SetSPPlayerID((T_Scenario *)this->world->_padding_,param_1,iVar5);
    //       T_Scenario::SetSPObjectType((T_Scenario *)this->world->_padding_,param_1,lVar3);
    //       T_Scenario::SetSPAmount((T_Scenario *)this->world->_padding_,param_1,iVar1);
    //       return;
    //     }
    //     break;
    //   case 6:
    //     if (this->SelectedObject != (RGE_Static_Object *)0x0) {
    //       T_Scenario::SetSPVictoryType((T_Scenario *)this->world->_padding_,param_1,1);
    //       T_Scenario::SetSPObject((T_Scenario *)this->world->_padding_,param_1,this->SelectedObject);
    //       return;
    //     }
    //     break;
    //   case 7:
    //     if ((0 < iVar5) && (iVar5 < 9)) {
    //       T_Scenario::SetSPVictoryType((T_Scenario *)this->world->_padding_,param_1,1);
    //       T_Scenario::SetSPPlayerID((T_Scenario *)this->world->_padding_,param_1,iVar5);
    //       T_Scenario::SetSPObjectType((T_Scenario *)this->world->_padding_,param_1,lVar3);
    //       T_Scenario::SetSPAllFlag((T_Scenario *)this->world->_padding_,param_1,1);
    //       return;
    //     }
    //     break;
    //   case 8:
    //     if ((0 < iVar5) && (iVar5 < 9)) {
    //       T_Scenario::SetSPVictoryType((T_Scenario *)this->world->_padding_,param_1,1);
    //       T_Scenario::SetSPPlayerID((T_Scenario *)this->world->_padding_,param_1,iVar5);
    //       return;
    //     }
    //     break;
    //   case 9:
    //     if (this->SelectedObject != (RGE_Static_Object *)0x0) {
    //       T_Scenario::SetSPVictoryType((T_Scenario *)this->world->_padding_,param_1,5);
    //       T_Scenario::SetSPObject((T_Scenario *)this->world->_padding_,param_1,this->SelectedObject);
    //       return;
    //     }
    //     break;
    //   case 10:
    //     T_Scenario::SetSPVictoryType((T_Scenario *)this->world->_padding_,param_1,4);
    //     lVar3 = 0;
    //     goto LAB_004ae570;
    //   case 0xb:
    //     T_Scenario::SetSPVictoryType((T_Scenario *)this->world->_padding_,param_1,4);
    //     lVar3 = 3;
    //     goto LAB_004ae570;
    //   case 0xc:
    //     T_Scenario::SetSPVictoryType((T_Scenario *)this->world->_padding_,param_1,4);
    //     lVar3 = 1;
    //     goto LAB_004ae570;
    //   case 0xd:
    //     T_Scenario::SetSPVictoryType((T_Scenario *)this->world->_padding_,param_1,4);
    //     lVar3 = 2;
    //     goto LAB_004ae570;
    //   case 0xe:
    //     T_Scenario::SetSPVictoryType((T_Scenario *)this->world->_padding_,param_1,4);
    //     lVar3 = 4;
    //     goto LAB_004ae570;
    //   case 0xf:
    //     T_Scenario::SetSPVictoryType((T_Scenario *)this->world->_padding_,param_1,4);
    //     T_Scenario::SetSPAttribType((T_Scenario *)this->world->_padding_,param_1,5);
    //     lVar3 = TDropDownPanel::get_line(this->victory_ages_list);
    //     T_Scenario::SetSPAmount((T_Scenario *)this->world->_padding_,param_1,lVar3 + 1);
    //     return;
    //   case 0x10:
    //     T_Scenario::SetSPVictoryType((T_Scenario *)this->world->_padding_,param_1,4);
    //     lVar3 = 6;
    //     goto LAB_004ae570;
    //   case 0x11:
    //     T_Scenario::SetSPVictoryType((T_Scenario *)this->world->_padding_,param_1,6);
    //     lVar3 = TDropDownPanel::get_id(this->victory_attribute_list);
    // LAB_004ae570:
    //     T_Scenario::SetSPAttribType((T_Scenario *)this->world->_padding_,param_1,lVar3);
    // LAB_004ae57f:
    //     T_Scenario::SetSPAmount((T_Scenario *)this->world->_padding_,param_1,iVar1);
    //     return;
    //   case 0x12:
    //     T_Scenario::SetSPVictoryType((T_Scenario *)this->world->_padding_,param_1,7);
    //     lVar3 = TDropDownPanel::get_id(this->victory_tech_list);
    //     T_Scenario::SetSPAttribType((T_Scenario *)this->world->_padding_,param_1,lVar3);
    //   }
    //   return;
    // }
    // 
    // 
}

// Offset: 0x004AE620
void load_victory_cond_from_scenario(TRIBE_Screen_Sed* this_, int param_2) {
    // --- Ghidra decompiler output ---
    // 
    // /* WARNING: Variable defined which should be unmapped: obj */
    // /* protected: void __thiscall TRIBE_Screen_Sed::load_victory_cond_from_scenario(int) */
    // 
    // void __thiscall
    // TRIBE_Screen_Sed::load_victory_cond_from_scenario(TRIBE_Screen_Sed *this,int param_1)
    // 
    // {
    //   float *pfVar1;
    //   int iVar2;
    //   int iVar3;
    //   long lVar4;
    //   RGE_Static_Object *pRVar5;
    //   RGE_Static_Object *pRVar6;
    //   int iVar7;
    //   long lVar8;
    //   long lVar9;
    //   long lVar10;
    //   RGE_Static_Object *obj;
    //   long y2;
    //   long x2;
    //   long y1;
    //   long x1;
    //   int VictoryType;
    //   int Amount;
    //   RGE_Static_Object *destobj;
    //   char str [40];
    //   int iStack_4;
    //   
    //   iVar2 = T_Scenario::Get_victory_all_flag((T_Scenario *)this->world->_padding_);
    //   iVar3 = this->victory_and_or[0]->_padding_;
    //   if (iVar2 == 0) {
    //     (**(code **)(iVar3 + 0xe0))(1);
    //     iVar3 = this->victory_and_or[1]->_padding_;
    //   }
    //   else {
    //     (**(code **)(iVar3 + 0xe0))(0);
    //     iVar3 = this->victory_and_or[1]->_padding_;
    //   }
    //   (**(code **)(iVar3 + 0xe0))(iVar2 != 0);
    //   if (-1 < iStack_4) {
    //     this->SelectedObject = (RGE_Static_Object *)0x0;
    //     this->DestinationObject = (RGE_Static_Object *)0x0;
    //     (**(code **)(*(int *)this->world->_padding_ + 8))();
    //     T_Scenario::SetSPWhich((T_Scenario *)this->world->_padding_,this->player_num + -1);
    //     iVar3 = T_Scenario::GetSPAmount((T_Scenario *)this->world->_padding_,iStack_4);
    //     itoa(iVar3,&destobj,10);
    //     TEditPanel::set_text(this->victory_amount_input,(char *)&destobj);
    //     iVar2 = T_Scenario::GetSPPlayerID((T_Scenario *)this->world->_padding_,iStack_4);
    //     TDropDownPanel::set_line(this->victory_enemy_player_list,iVar2 + -1);
    //     iVar2 = T_Scenario::GetSPObjectType((T_Scenario *)this->world->_padding_,iStack_4);
    //     lVar4 = TDropDownPanel::get_line(this->victory_object_list,iVar2);
    //     TDropDownPanel::setCurrentLineNumber(this->victory_object_list,lVar4);
    //     pRVar5 = T_Scenario::GetSPObject((T_Scenario *)this->world->_padding_,iStack_4);
    //     pRVar6 = T_Scenario::GetSPDestObjectID((T_Scenario *)this->world->_padding_,iStack_4);
    //     this->SelectedObject = pRVar5;
    //     this->DestinationObject = pRVar6;
    //     iVar2 = T_Scenario::GetSPVictoryType((T_Scenario *)this->world->_padding_,iStack_4);
    //     iVar7 = T_Scenario::GetSPAttribType((T_Scenario *)this->world->_padding_,iStack_4);
    //     pfVar1 = &this->px2;
    //     T_Scenario::GetSPRectangle
    //               ((T_Scenario *)this->world->_padding_,iStack_4,&this->px1,&this->py1,pfVar1,&this->py2
    //               );
    //     lVar4 = __ftol();
    //     lVar8 = __ftol();
    //     lVar9 = __ftol();
    //     lVar10 = __ftol();
    //     RGE_View::set_selection_area((RGE_View *)this->main_view,-1,-1,-1,-1);
    //     if (*pfVar1 != 0.0) {
    //       RGE_View::set_selection_area((RGE_View *)this->main_view,lVar4,lVar8,lVar9,lVar10);
    //     }
    //     switch(iVar2) {
    //     case 0:
    //       iVar3 = 0;
    //       break;
    //     case 1:
    //       if (iVar3 == 0) {
    //         if (pRVar5 == (RGE_Static_Object *)0x0) {
    //           iVar3 = T_Scenario::GetSPAllFlag((T_Scenario *)this->world->_padding_,iStack_4);
    //           if (iVar3 == 0) {
    //             iVar3 = 8;
    //           }
    //           else {
    //             iVar3 = 7;
    //           }
    //         }
    //         else {
    //           iVar3 = 6;
    //         }
    //       }
    //       else {
    //         iVar3 = 5;
    //       }
    //       break;
    //     case 2:
    //       T_Scenario::GetSPRectangle
    //                 ((T_Scenario *)this->world->_padding_,iStack_4,&this->px1,&this->py1,pfVar1,
    //                  &this->py2);
    //       if (*pfVar1 <= 0.0) {
    //         iVar3 = 3;
    //       }
    //       else {
    //         iVar3 = 4;
    //       }
    //       break;
    //     case 3:
    //       if (pRVar6 == (RGE_Static_Object *)0x0) {
    //         iVar3 = 2;
    //       }
    //       else {
    //         iVar3 = 1;
    //       }
    //       break;
    //     case 4:
    //       switch(iVar7) {
    //       case 0:
    //         iVar3 = 10;
    //         break;
    //       case 1:
    //         iVar3 = 0xc;
    //         break;
    //       case 2:
    //         iVar3 = 0xd;
    //         break;
    //       case 3:
    //         iVar3 = 0xb;
    //         break;
    //       case 4:
    //         iVar3 = 0xe;
    //         break;
    //       case 5:
    //         TDropDownPanel::setCurrentLineNumber(this->victory_drop_down,0xf);
    //         iVar3 = T_Scenario::GetSPAmount((T_Scenario *)this->world->_padding_,iStack_4);
    //         TDropDownPanel::setCurrentLineNumber(this->victory_ages_list,iVar3 + -1);
    //         return;
    //       case 6:
    //         iVar3 = 0x10;
    //         break;
    //       default:
    //         goto switchD_004ae82a_default;
    //       }
    //       break;
    //     case 5:
    //       if (pRVar5 == (RGE_Static_Object *)0x0) {
    //         return;
    //       }
    //       iVar3 = 9;
    //       break;
    //     case 6:
    //       TDropDownPanel::setCurrentLineNumber(this->victory_drop_down,0x11);
    //       TDropDownPanel::setCurrentLineId(this->victory_attribute_list,iVar7);
    //       return;
    //     case 7:
    //       TDropDownPanel::setCurrentLineNumber(this->victory_drop_down,0x12);
    //       TDropDownPanel::setCurrentLineId(this->victory_tech_list,iVar7);
    //       return;
    //     default:
    //       goto switchD_004ae82a_default;
    //     }
    //     TDropDownPanel::setCurrentLineNumber(this->victory_drop_down,iVar3);
    //   }
    // switchD_004ae82a_default:
    //   return;
    // }
    // 
    // 
}

// Offset: 0x004AE9D0
void load_multi_victory_cond_from_scenario(TRIBE_Screen_Sed* this_) {
    // --- Ghidra decompiler output ---
    // 
    // /* WARNING: Variable defined which should be unmapped: str */
    // /* protected: void __thiscall TRIBE_Screen_Sed::load_multi_victory_cond_from_scenario(void) */
    // 
    // void __thiscall TRIBE_Screen_Sed::load_multi_victory_cond_from_scenario(TRIBE_Screen_Sed *this)
    // 
    // {
    //   int iVar1;
    //   long lVar2;
    //   int iVar3;
    //   TButtonPanel *this_00;
    //   char *pcVar4;
    //   char acStack_24 [4];
    //   char str [20];
    //   
    //   iVar1 = T_Scenario::GetMPVictory((T_Scenario *)this->world->_padding_);
    //   switch(iVar1) {
    //   case 0:
    //     this->mp_victory_type = VictoryTypeStandard;
    //     break;
    //   case 1:
    //     this->mp_victory_type = VictoryTypeConquest;
    //     break;
    //   case 2:
    //     this->mp_victory_type = VictoryTypeScore;
    //     break;
    //   case 3:
    //     this->mp_victory_type = VictoryTypeTime;
    //     break;
    //   default:
    //     this->mp_victory_type = VictoryTypeCustom;
    //   }
    //   iVar1 = T_Scenario::GetVictoryScore((T_Scenario *)this->world->_padding_);
    //   if (iVar1 == 0) {
    //     iVar1 = 900;
    //   }
    //   acStack_24[0] = 'P';
    //   acStack_24[1] = -0x16;
    //   acStack_24[2] = 'J';
    //   acStack_24[3] = '\0';
    //   lVar2 = TDropDownPanel::get_line(this->victory_score,iVar1);
    //   acStack_24[0] = '\\';
    //   acStack_24[1] = -0x16;
    //   acStack_24[2] = 'J';
    //   acStack_24[3] = '\0';
    //   TDropDownPanel::set_line(this->victory_score,lVar2);
    //   iVar1 = T_Scenario::GetVictoryTime((T_Scenario *)this->world->_padding_);
    //   if (iVar1 == 0) {
    //     iVar1 = 9000;
    //   }
    //   acStack_24[0] = -0x7f;
    //   acStack_24[1] = -0x16;
    //   acStack_24[2] = 'J';
    //   acStack_24[3] = '\0';
    //   lVar2 = TDropDownPanel::get_line(this->victory_time,iVar1);
    //   acStack_24[0] = -0x73;
    //   acStack_24[1] = -0x16;
    //   acStack_24[2] = 'J';
    //   acStack_24[3] = '\0';
    //   TDropDownPanel::set_line(this->victory_time,lVar2);
    //   iVar1 = T_Scenario::Get_victory_all_flag((T_Scenario *)this->world->_padding_);
    //   if (iVar1 == 0) {
    //     this_00 = this->victory_and_or[0];
    //   }
    //   else {
    //     this_00 = this->victory_and_or[1];
    //   }
    //   TButtonPanel::set_radio_button(this_00);
    //   iVar1 = T_Scenario::Get_Multi_Conquest((T_Scenario *)this->world->_padding_);
    //   if (iVar1 == 0) {
    //     acStack_24[0] = -0x20;
    //     acStack_24[1] = -0x16;
    //     acStack_24[2] = 'J';
    //     acStack_24[3] = '\0';
    //     (**(code **)(this->victory_cond_on[0]->_padding_ + 0xe0))();
    //   }
    //   else {
    //     acStack_24[0] = -0x2c;
    //     acStack_24[1] = -0x16;
    //     acStack_24[2] = 'J';
    //     acStack_24[3] = '\0';
    //     (**(code **)(this->victory_cond_on[0]->_padding_ + 0xe0))();
    //   }
    //   acStack_24[0] = -0x12;
    //   acStack_24[1] = -0x16;
    //   acStack_24[2] = 'J';
    //   acStack_24[3] = '\0';
    //   iVar3 = T_Scenario::Get_Multi_Exploration((T_Scenario *)this->world->_padding_);
    //   iVar1 = this->victory_cond_on[1]->_padding_;
    //   if (iVar3 == 0) {
    //     acStack_24[0] = '\0';
    //     acStack_24[1] = '\0';
    //     acStack_24[2] = '\0';
    //     acStack_24[3] = '\0';
    //     (**(code **)(iVar1 + 0xe0))();
    //     pcVar4 = s_0;
    //   }
    //   else {
    //     acStack_24[0] = '\x01';
    //     acStack_24[1] = '\0';
    //     acStack_24[2] = '\0';
    //     acStack_24[3] = '\0';
    //     (**(code **)(iVar1 + 0xe0))();
    //     itoa(iVar3);
    //     pcVar4 = &stack0xffffffe4;
    //   }
    //   TEditPanel::set_text(this->victory_condition_explore,pcVar4);
    //   iVar3 = T_Scenario::Get_Multi_Ruins((T_Scenario *)this->world->_padding_);
    //   iVar1 = this->victory_cond_on[2]->_padding_;
    //   if (iVar3 == 0) {
    //     (**(code **)(iVar1 + 0xe0))();
    //     pcVar4 = s_0;
    //   }
    //   else {
    //     (**(code **)(iVar1 + 0xe0))();
    //     itoa(iVar3,&stack0xffffffe0);
    //     pcVar4 = &stack0xffffffe0;
    //   }
    //   TEditPanel::set_text(this->victory_condition_ruins,pcVar4);
    //   iVar3 = T_Scenario::Get_Multi_Artifacts((T_Scenario *)this->world->_padding_);
    //   iVar1 = this->victory_cond_on[3]->_padding_;
    //   if (iVar3 == 0) {
    //     (**(code **)(iVar1 + 0xe0))();
    //     pcVar4 = s_0;
    //   }
    //   else {
    //     (**(code **)(iVar1 + 0xe0))();
    //     itoa(iVar3,acStack_24,10);
    //     pcVar4 = acStack_24;
    //   }
    //   TEditPanel::set_text(this->victory_condition_artifacts,pcVar4);
    //   iVar3 = T_Scenario::Get_Multi_Discoveries((T_Scenario *)this->world->_padding_);
    //   iVar1 = this->victory_cond_on[4]->_padding_;
    //   if (iVar3 == 0) {
    //     (**(code **)(iVar1 + 0xe0))(0);
    //     pcVar4 = s_0;
    //   }
    //   else {
    //     (**(code **)(iVar1 + 0xe0))(1);
    //     itoa(iVar3,&stack0xffffffd8,10);
    //     pcVar4 = &stack0xffffffd8;
    //   }
    //   TEditPanel::set_text(this->victory_condition_discoveries,pcVar4);
    //   iVar3 = T_Scenario::Get_Multi_Gold((T_Scenario *)this->world->_padding_);
    //   iVar1 = this->victory_cond_on[5]->_padding_;
    //   if (iVar3 == 0) {
    //     (**(code **)(iVar1 + 0xe0))(0);
    //     pcVar4 = s_0;
    //   }
    //   else {
    //     (**(code **)(iVar1 + 0xe0))(1);
    //     itoa(iVar3,&stack0xffffffd4,10);
    //     pcVar4 = &stack0xffffffd4;
    //   }
    //   TEditPanel::set_text(this->victory_condition_gold,pcVar4);
    //   T_Scenario::Save_victory_conditions_into_players((T_Scenario *)this->world->_padding_,1);
    //   return;
    // }
    // 
    // 
}

// Offset: 0x004AEC95
void FUN_004aec95() {
    // --- Ghidra decompiler output ---
    // 
    // void FUN_004aec95(void)
    // 
    // {
    //   code *pcVar1;
    //   
    //   pcVar1 = (code *)swi(1);
    //   (*pcVar1)();
    //   return;
    // }
    // 
    // 
    // TODO: Full transliteration pending. Source of truth: scr_sed2.cpp.decomp @ 0x004AEC95
}

// Offset: 0x004AECB0
void save_diplomacy_in_scenario(TRIBE_Screen_Sed* this_, int param_2) {
    // --- Ghidra decompiler output ---
    // 
    // /* protected: void __thiscall TRIBE_Screen_Sed::save_diplomacy_in_scenario(int) */
    // 
    // void __thiscall TRIBE_Screen_Sed::save_diplomacy_in_scenario(TRIBE_Screen_Sed *this,int param_1)
    // 
    // {
    //   int iVar1;
    //   T_Scenario *this_00;
    //   TButtonPanel **ppTVar2;
    //   int iVar3;
    //   
    //   if (-1 < param_1) {
    //     iVar3 = 0;
    //     ppTVar2 = this->Diplomacy_friend_box[0] + 1;
    //     do {
    //       iVar1 = TButtonPanel::get_state((*(TButtonPanel *(*) [3])(ppTVar2 + -1))[0]);
    //       if (iVar1 == 1) {
    //         iVar1 = 0;
    //         this_00 = (T_Scenario *)this->world->_padding_;
    // LAB_004aed1a:
    //         T_Scenario::Set_player_attitude(this_00,param_1,iVar3,iVar1);
    //       }
    //       else {
    //         iVar1 = TButtonPanel::get_state(*ppTVar2);
    //         if (iVar1 == 1) {
    //           this_00 = (T_Scenario *)this->world->_padding_;
    //           iVar1 = 1;
    //           goto LAB_004aed1a;
    //         }
    //         iVar1 = TButtonPanel::get_state(ppTVar2[1]);
    //         if (iVar1 == 1) {
    //           iVar1 = 3;
    //           this_00 = (T_Scenario *)this->world->_padding_;
    //           goto LAB_004aed1a;
    //         }
    //       }
    //       iVar3 = iVar3 + 1;
    //       ppTVar2 = ppTVar2 + 3;
    //     } while (iVar3 < 8);
    //     iVar3 = TButtonPanel::get_state(this->Diplomacy_AlliedVictory[param_1]);
    //     T_Scenario::SetPlayerAlliedVictory((T_Scenario *)this->world->_padding_,param_1,iVar3);
    //   }
    //   return;
    // }
    // 
    // 
}

// Offset: 0x004AED50
void load_diplomacy_from_scenario(TRIBE_Screen_Sed* this_, int param_2) {
    // --- Ghidra decompiler output ---
    // 
    // /* protected: void __thiscall TRIBE_Screen_Sed::load_diplomacy_from_scenario(int) */
    // 
    // void __thiscall TRIBE_Screen_Sed::load_diplomacy_from_scenario(TRIBE_Screen_Sed *this,int param_1)
    // 
    // {
    //   int iVar1;
    //   TButtonPanel **ppTVar2;
    //   TButtonPanel **ppTVar3;
    //   int iVar4;
    //   
    //   if (-1 < param_1) {
    //     iVar4 = 0;
    //     ppTVar2 = this->Diplomacy_AlliedVictory;
    //     ppTVar3 = this->Diplomacy_friend_box[0] + 1;
    //     do {
    //       iVar1 = T_Scenario::Get_player_attitude((T_Scenario *)this->world->_padding_,param_1,iVar4);
    //       if (iVar1 == 0) {
    //         TButtonPanel::set_radio_button((*(TButtonPanel *(*) [3])(ppTVar3 + -1))[0]);
    //       }
    //       if (iVar1 == 1) {
    //         TButtonPanel::set_radio_button(*ppTVar3);
    //       }
    //       if (iVar1 == 3) {
    //         TButtonPanel::set_radio_button(ppTVar3[1]);
    //       }
    //       (**(code **)((*ppTVar2)->_padding_ + 0xe0))(0);
    //       iVar4 = iVar4 + 1;
    //       ppTVar2 = ppTVar2 + 1;
    //       ppTVar3 = ppTVar3 + 3;
    //     } while (iVar4 < 8);
    //     iVar4 = this->Diplomacy_AlliedVictory[param_1]->_padding_;
    //     iVar1 = T_Scenario::GetPlayerAlliedVictory((T_Scenario *)this->world->_padding_,param_1);
    //     (**(code **)(iVar4 + 0xe0))(iVar1);
    //   }
    //   return;
    // }
    // 
    // 
}

// Offset: 0x004AEE10
void activate_victory_proper_fields(TRIBE_Screen_Sed* this_, int param_2, int param_3) {
    // --- Ghidra decompiler output ---
    // 
    // /* WARNING: Variable defined which should be unmapped: ptr */
    // /* protected: void __thiscall TRIBE_Screen_Sed::activate_victory_proper_fields(int,int) */
    // 
    // void __thiscall
    // TRIBE_Screen_Sed::activate_victory_proper_fields(TRIBE_Screen_Sed *this,int param_1,int param_2)
    // 
    // {
    //   TPanel *ptr [2];
    //   
    //   this->SelectRegionFlag = SELECT_OFF;
    //   if (param_2 == 0) {
    //     (**(code **)(this->victory_object_list->_padding_ + 0x14))();
    //     (**(code **)(this->victory_amount_text->_padding_ + 0x14))();
    //     (**(code **)(this->victory_amount_input->_padding_ + 0x14))();
    //     (**(code **)(this->victory_button_set_object->_padding_ + 0x14))(0);
    //     (**(code **)(this->victory_button_set_destination->_padding_ + 0x14))(0);
    //     (**(code **)(this->victory_button_go_to_dest->_padding_ + 0x14))(0);
    //     (**(code **)(this->victory_which_enemy_text->_padding_ + 0x14))(0);
    //     (**(code **)(this->victory_enemy_player_list->_padding_ + 0x14))(0);
    //     (**(code **)(this->victory_attribute_list->_padding_ + 0x14))(0);
    //     (**(code **)(this->victory_ages_list->_padding_ + 0x14))(0);
    //     (**(code **)(this->victory_tech_list->_padding_ + 0x14))(0);
    //     return;
    //   }
    //   TPanel::set_curr_child(this->bottom_panel,(TPanel *)0x0);
    //   switch(param_1) {
    //   default:
    //     return;
    //   case 1:
    //     (**(code **)(this->victory_button_set_object->_padding_ + 0x14))();
    //     (**(code **)(this->victory_button_set_destination->_padding_ + 0x14))();
    //     return;
    //   case 2:
    //     (**(code **)(this->victory_button_set_object->_padding_ + 0x14))();
    //     (**(code **)(this->victory_button_set_destination->_padding_ + 0x14))();
    //     (**(code **)(this->victory_button_go_to_dest->_padding_ + 0x14))();
    //     return;
    //   case 3:
    //     (**(code **)(this->victory_object_list->_padding_ + 0x14))();
    //     (**(code **)(this->victory_amount_text->_padding_ + 0x14))();
    //     (**(code **)(this->victory_amount_input->_padding_ + 0x14))();
    //                     /* language.dll match for 0x7766: "Type the number of objects." */
    //     TPanel::set_help_info((TPanel *)this->victory_amount_input,0x7766,-1);
    //     break;
    //   case 4:
    //     (**(code **)(this->victory_object_list->_padding_ + 0x14))();
    //     (**(code **)(this->victory_amount_text->_padding_ + 0x14))();
    //     (**(code **)(this->victory_amount_input->_padding_ + 0x14))();
    //                     /* language.dll match for 0x7767: "Type the number of objects." */
    //     TPanel::set_help_info((TPanel *)this->victory_amount_input,0x7767,-1);
    //     TPanel::set_curr_child(this->bottom_panel,(TPanel *)this->victory_amount_input);
    //     (**(code **)(this->victory_button_set_destination->_padding_ + 0x14))(param_2);
    //     (**(code **)(this->victory_button_go_to_dest->_padding_ + 0x14))(param_2);
    //     return;
    //   case 5:
    //     (**(code **)(this->victory_object_list->_padding_ + 0x14))();
    //     (**(code **)(this->victory_amount_text->_padding_ + 0x14))();
    //     (**(code **)(this->victory_amount_input->_padding_ + 0x14))();
    //     (**(code **)(this->victory_which_enemy_text->_padding_ + 0x14))(param_2);
    //                     /* language.dll match for 0x7768: "Type the number of objects." */
    //     TPanel::set_help_info((TPanel *)this->victory_amount_input,0x7768,-1);
    //     (**(code **)(this->victory_enemy_player_list->_padding_ + 0x14))(param_2);
    //     (**(code **)(this->_padding_ + 200))(&stack0xffffffe4,2);
    //     goto LAB_004af094;
    //   case 6:
    //   case 9:
    //     (**(code **)(this->victory_button_set_object->_padding_ + 0x14))();
    //     return;
    //   case 7:
    //     (**(code **)(this->victory_object_list->_padding_ + 0x14))();
    //     (**(code **)(this->victory_which_enemy_text->_padding_ + 0x14))();
    //     (**(code **)(this->victory_enemy_player_list->_padding_ + 0x14))();
    //     TPanel::set_curr_child(this->bottom_panel,(TPanel *)this->victory_enemy_player_list);
    //     return;
    //   case 8:
    //     (**(code **)(this->victory_which_enemy_text->_padding_ + 0x14))();
    //     (**(code **)(this->victory_enemy_player_list->_padding_ + 0x14))();
    // LAB_004af094:
    //     TPanel::set_curr_child(this->bottom_panel,(TPanel *)this->victory_enemy_player_list);
    //     return;
    //   case 10:
    //                     /* language.dll match for 0x7769: "Type the quantity of gold." */
    //     TPanel::set_help_info((TPanel *)this->victory_amount_input,0x7769,-1);
    //     (**(code **)(this->victory_amount_text->_padding_ + 0x14))();
    //     (**(code **)(this->victory_amount_input->_padding_ + 0x14))();
    //     TPanel::set_curr_child(this->bottom_panel,(TPanel *)this->victory_amount_input);
    //     return;
    //   case 0xb:
    //                     /* language.dll match for 0x776a: "Type the quantity of food." */
    //     TPanel::set_help_info((TPanel *)this->victory_amount_input,0x776a,-1);
    //     (**(code **)(this->victory_amount_text->_padding_ + 0x14))();
    //     (**(code **)(this->victory_amount_input->_padding_ + 0x14))();
    //     TPanel::set_curr_child(this->bottom_panel,(TPanel *)this->victory_amount_input);
    //     return;
    //   case 0xc:
    //                     /* language.dll match for 0x776b: "Type the quantity of wood." */
    //     TPanel::set_help_info((TPanel *)this->victory_amount_input,0x776b,-1);
    //     (**(code **)(this->victory_amount_text->_padding_ + 0x14))();
    //     (**(code **)(this->victory_amount_input->_padding_ + 0x14))();
    //     TPanel::set_curr_child(this->bottom_panel,(TPanel *)this->victory_amount_input);
    //     return;
    //   case 0xd:
    //                     /* language.dll match for 0x776c: "Type the quantity of stone." */
    //     TPanel::set_help_info((TPanel *)this->victory_amount_input,0x776c,-1);
    //     (**(code **)(this->victory_amount_text->_padding_ + 0x14))();
    //     (**(code **)(this->victory_amount_input->_padding_ + 0x14))();
    //     TPanel::set_curr_child(this->bottom_panel,(TPanel *)this->victory_amount_input);
    //     return;
    //   case 0xe:
    //                     /* language.dll match for 0x776d: "Type the number of population." */
    //     TPanel::set_help_info((TPanel *)this->victory_amount_input,0x776d,-1);
    //     (**(code **)(this->victory_amount_text->_padding_ + 0x14))();
    //     (**(code **)(this->victory_amount_input->_padding_ + 0x14))();
    //     TPanel::set_curr_child(this->bottom_panel,(TPanel *)this->victory_amount_input);
    //     return;
    //   case 0xf:
    //     (**(code **)(this->victory_ages_list->_padding_ + 0x14))();
    //     return;
    //   case 0x10:
    //                     /* language.dll match for 0x776e: "Type the percentage of exploration." */
    //     TPanel::set_help_info((TPanel *)this->victory_amount_input,0x776e,-1);
    //     (**(code **)(this->victory_amount_text->_padding_ + 0x14))();
    //     (**(code **)(this->victory_amount_input->_padding_ + 0x14))();
    //     break;
    //   case 0x11:
    //     (**(code **)(this->victory_amount_text->_padding_ + 0x14))();
    //     (**(code **)(this->victory_amount_input->_padding_ + 0x14))();
    //                     /* language.dll match for 0x776f: "Type the quantity." */
    //     TPanel::set_help_info((TPanel *)this->victory_amount_input,0x776f,-1);
    //     TPanel::set_curr_child(this->bottom_panel,(TPanel *)this->victory_amount_input);
    //     (**(code **)(this->victory_attribute_list->_padding_ + 0x14))();
    //     return;
    //   case 0x12:
    //     (**(code **)(this->victory_tech_list->_padding_ + 0x14))();
    //     return;
    //   }
    //   TPanel::set_curr_child(this->bottom_panel,(TPanel *)this->victory_amount_input);
    //   return;
    // }
    // 
    // 
}

// Offset: 0x004AF2D2
void FUN_004af2d2() {
    // --- Ghidra decompiler output ---
    // 
    // void FUN_004af2d2(void)
    // 
    // {
    //   return;
    // }
    // 
    // 
    // TODO: Full transliteration pending. Source of truth: scr_sed2.cpp.decomp @ 0x004AF2D2
}

// Offset: 0x004AF320
static void init_module_variables(TRIBE_Screen_Sed* this_) {
    // --- Ghidra decompiler output ---
    // 
    // /* protected: void __thiscall TRIBE_Screen_Sed::init_module_variables(void) */
    // 
    // void __thiscall TRIBE_Screen_Sed::init_module_variables(TRIBE_Screen_Sed *this)
    // 
    // {
    //   TEditPanel **ppTVar1;
    //   TDropDownPanel **ppTVar2;
    //   TButtonPanel **ppTVar3;
    //   TTextPanel **ppTVar4;
    //   TButtonPanel **ppTVar5;
    //   int iVar6;
    //   
    //   this->background_pic = (TShape *)0x0;
    //   this->main_view = (TRIBE_Main_View *)0x0;
    //   this->map_view = (RGE_Diamond_Map_View *)0x0;
    //   this->message_panel = (TMessagePanel *)0x0;
    //   this->bottom_panel = (TPanel *)0x0;
    //   this->set_player_first_flag = 0;
    //   ppTVar3 = this->scenario_mode_button;
    //   for (iVar6 = 10; iVar6 != 0; iVar6 = iVar6 + -1) {
    //     *ppTVar3 = (TButtonPanel *)0x0;
    //     ppTVar3 = ppTVar3 + 1;
    //   }
    //   this->menu_button = (TButtonPanel *)0x0;
    //   this->help_button = (TButtonPanel *)0x0;
    //   this->map_type_label = (TTextPanel *)0x0;
    //   ppTVar4 = this->map_type_text;
    //   iVar6 = 3;
    //   do {
    //     ppTVar4[-3] = (TTextPanel *)0x0;
    //     *ppTVar4 = (TTextPanel *)0x0;
    //     ppTVar4 = ppTVar4 + 1;
    //     iVar6 = iVar6 + -1;
    //   } while (iVar6 != 0);
    //   this->default_terrain_drop = (TDropDownPanel *)0x0;
    //   this->default_terrain_label = (TTextPanel *)0x0;
    //   this->map_size_drop = (TDropDownPanel *)0x0;
    //   this->map_size_label = (TTextPanel *)0x0;
    //   this->map_style_drop = (TDropDownPanel *)0x0;
    //   this->map_style_label = (TTextPanel *)0x0;
    //   this->map_generating_text = (TTextPanel *)0x0;
    //   this->random_seed_label = (TTextPanel *)0x0;
    //   this->random_seed_input = (TEditPanel *)0x0;
    //   this->random_seed_used_label = (TTextPanel *)0x0;
    //   this->random_seed_used_text = (TTextPanel *)0x0;
    //   this->generate_map_button = (TButtonPanel *)0x0;
    //   this->brush_size_label = (TTextPanel *)0x0;
    //   this->paint_type_label = (TTextPanel *)0x0;
    //   this->paint_terrain_label = (TTextPanel *)0x0;
    //   ppTVar4 = this->brush_size_button_label;
    //   iVar6 = 5;
    //   do {
    //     ppTVar4[-5] = (TTextPanel *)0x0;
    //     *ppTVar4 = (TTextPanel *)0x0;
    //     ppTVar4 = ppTVar4 + 1;
    //     iVar6 = iVar6 + -1;
    //   } while (iVar6 != 0);
    //   ppTVar4 = this->paint_type_button_label;
    //   iVar6 = 3;
    //   do {
    //     ppTVar4[-3] = (TTextPanel *)0x0;
    //     *ppTVar4 = (TTextPanel *)0x0;
    //     ppTVar4 = ppTVar4 + 1;
    //     iVar6 = iVar6 + -1;
    //   } while (iVar6 != 0);
    //   this->paint_terrain_list = (TListPanel *)0x0;
    //   this->paint_terrain_scrollbar = (TScrollBarPanel *)0x0;
    //   this->paint_elevation_list = (TListPanel *)0x0;
    //   this->paint_elevation_scrollbar = (TScrollBarPanel *)0x0;
    //   this->player_advance_civilization_drop = (TDropDownPanel *)0x0;
    //   this->player_label = (TTextPanel *)0x0;
    //   this->player_starting_age_label = (TTextPanel *)0x0;
    //   this->player_build_text = (TTextPanel *)0x0;
    //   this->player_city_text = (TTextPanel *)0x0;
    //   this->player_list = (TDropDownPanel *)0x0;
    //   this->player_number_list = (TDropDownPanel *)0x0;
    //   ppTVar1 = this->player_inven_input;
    //   iVar6 = 5;
    //   do {
    //     ppTVar1[-5] = (TEditPanel *)0x0;
    //     *ppTVar1 = (TEditPanel *)0x0;
    //     ppTVar1 = ppTVar1 + 1;
    //     iVar6 = iVar6 + -1;
    //   } while (iVar6 != 0);
    //   ppTVar2 = this->player_setting_drop;
    //   iVar6 = 2;
    //   do {
    //     ppTVar2[-3] = (TDropDownPanel *)0x0;
    //     *ppTVar2 = (TDropDownPanel *)0x0;
    //     ppTVar2 = ppTVar2 + 1;
    //     iVar6 = iVar6 + -1;
    //   } while (iVar6 != 0);
    //   this->BuildList = (TDropDownPanel *)0x0;
    //   this->CityLayout = (TDropDownPanel *)0x0;
    //   this->AiRules = (TDropDownPanel *)0x0;
    //   this->unit_player_list = (TDropDownPanel *)0x0;
    //   ppTVar4 = this->unit_mode_select_label;
    //   iVar6 = 4;
    //   do {
    //     ppTVar4[-4] = (TTextPanel *)0x0;
    //     *ppTVar4 = (TTextPanel *)0x0;
    //     ppTVar4 = ppTVar4 + 1;
    //     iVar6 = iVar6 + -1;
    //   } while (iVar6 != 0);
    //   this->unit_list = (TListPanel *)0x0;
    //   this->unit_scrollbar = (TScrollBarPanel *)0x0;
    //   this->unit_list_info = (List_Info *)0x0;
    //   this->button_unit_pics = (TShape *)0x0;
    //   this->button_bldg_pics[0] = (TShape *)0x0;
    //   this->button_bldg_pics[1] = (TShape *)0x0;
    //   this->button_bldg_pics[2] = (TShape *)0x0;
    //   this->button_bldg_pics[3] = (TShape *)0x0;
    //   this->button_bldg_pics[4] = (TShape *)0x0;
    //   this->object_panel = (TRIBE_Scenario_Editor_Panel_Object *)0x0;
    //   this->unit_list_size = 0;
    //   ppTVar3 = this->victory_cond_on;
    //   for (iVar6 = 6; iVar6 != 0; iVar6 = iVar6 + -1) {
    //     *ppTVar3 = (TButtonPanel *)0x0;
    //     ppTVar3 = ppTVar3 + 1;
    //   }
    //   ppTVar4 = this->victory_text_and_or;
    //   iVar6 = 2;
    //   do {
    //     ppTVar4[-5] = (TTextPanel *)0x0;
    //     *ppTVar4 = (TTextPanel *)0x0;
    //     ppTVar4 = ppTVar4 + 1;
    //     iVar6 = iVar6 + -1;
    //   } while (iVar6 != 0);
    //   this->victory_amount_label = (TTextPanel *)0x0;
    //   this->victory_long_label = (TTextPanel *)0x0;
    //   this->victory_condition_label = (TTextPanel *)0x0;
    //   this->victory_label_conquest = (TTextPanel *)0x0;
    //   this->victory_label_explore = (TTextPanel *)0x0;
    //   this->victory_label_explore_percent = (TTextPanel *)0x0;
    //   this->victory_label_ruins = (TTextPanel *)0x0;
    //   this->victory_label_artifacts = (TTextPanel *)0x0;
    //   this->victory_label_discoveries = (TTextPanel *)0x0;
    //   this->victory_label_gold = (TTextPanel *)0x0;
    //   this->victory_condition_explore = (TEditPanel *)0x0;
    //   this->victory_condition_ruins = (TEditPanel *)0x0;
    //   this->victory_condition_artifacts = (TEditPanel *)0x0;
    //   this->victory_condition_discoveries = (TEditPanel *)0x0;
    //   this->victory_condition_gold = (TEditPanel *)0x0;
    //   ppTVar3 = this->victory_cond_type;
    //   iVar6 = 5;
    //   do {
    //     ppTVar3[-5] = (TButtonPanel *)0x0;
    //     *ppTVar3 = (TButtonPanel *)0x0;
    //     ppTVar3 = ppTVar3 + 1;
    //     iVar6 = iVar6 + -1;
    //   } while (iVar6 != 0);
    //   this->victory_score_label = (TTextPanel *)0x0;
    //   this->victory_score = (TDropDownPanel *)0x0;
    //   this->victory_time_label = (TTextPanel *)0x0;
    //   this->victory_time = (TDropDownPanel *)0x0;
    //   ppTVar3 = this->victory_button;
    //   for (iVar6 = 0xc; iVar6 != 0; iVar6 = iVar6 + -1) {
    //     *ppTVar3 = (TButtonPanel *)0x0;
    //     ppTVar3 = ppTVar3 + 1;
    //   }
    //   this->victory_drop_down = (TDropDownPanel *)0x0;
    //   this->victory_object_list = (TDropDownPanel *)0x0;
    //   this->victory_player_list = (TDropDownPanel *)0x0;
    //   this->victory_ages_list = (TDropDownPanel *)0x0;
    //   this->victory_tech_list = (TDropDownPanel *)0x0;
    //   this->victory_button_set_object = (TButtonPanel *)0x0;
    //   this->victory_button_set_destination = (TButtonPanel *)0x0;
    //   this->victory_button_go_to_dest = (TButtonPanel *)0x0;
    //   this->victory_condition_text = (TTextPanel *)0x0;
    //   this->victory_condition_type = (TTextPanel *)0x0;
    //   this->victory_amount_text = (TTextPanel *)0x0;
    //   this->victory_amount_input = (TEditPanel *)0x0;
    //   this->victory_enemy_player_list = (TDropDownPanel *)0x0;
    //   this->victory_attribute_list = (TDropDownPanel *)0x0;
    //   this->victory_which_enemy_text = (TTextPanel *)0x0;
    //   this->victory_object_scrollbar = (TScrollBarPanel *)0x0;
    //   ppTVar4 = this->message_button_label;
    //   iVar6 = 5;
    //   do {
    //     ppTVar4[-5] = (TTextPanel *)0x0;
    //     *ppTVar4 = (TTextPanel *)0x0;
    //     ppTVar4 = ppTVar4 + 1;
    //     iVar6 = iVar6 + -1;
    //   } while (iVar6 != 0);
    //   this->message_input = (TEditPanel *)0x0;
    //   ppTVar2 = this->cinematic_input;
    //   iVar6 = 4;
    //   do {
    //     ppTVar2[-4] = (TDropDownPanel *)0x0;
    //     *ppTVar2 = (TDropDownPanel *)0x0;
    //     ppTVar2 = ppTVar2 + 1;
    //     iVar6 = iVar6 + -1;
    //   } while (iVar6 != 0);
    //   ppTVar3 = this->options_button;
    //   iVar6 = 1;
    //   do {
    //     ppTVar3[-1] = (TButtonPanel *)0x0;
    //     *ppTVar3 = (TButtonPanel *)0x0;
    //     ppTVar3 = ppTVar3 + 1;
    //     iVar6 = iVar6 + -1;
    //   } while (iVar6 != 0);
    //   this->options_player_list = (TDropDownPanel *)0x0;
    //   this->options_disable_tech_text = (TTextPanel *)0x0;
    //   ppTVar4 = this->options_disable_text;
    //   iVar6 = 0x10;
    //   do {
    //     ppTVar4[-0x10] = (TTextPanel *)0x0;
    //     *ppTVar4 = (TTextPanel *)0x0;
    //     ppTVar4 = ppTVar4 + 1;
    //     iVar6 = iVar6 + -1;
    //   } while (iVar6 != 0);
    //   this->Diplomacy_player_list = (TDropDownPanel *)0x0;
    //   ppTVar3 = this->Diplomacy_AlliedVictory;
    //   ppTVar5 = this->Diplomacy_friend_box[0] + 1;
    //   iVar6 = 8;
    //   do {
    //     ppTVar3[-0x25] = (TButtonPanel *)0x0;
    //     (*(TButtonPanel *(*) [3])(ppTVar5 + -1))[0] = (TButtonPanel *)0x0;
    //     *ppTVar5 = (TButtonPanel *)0x0;
    //     ppTVar5[1] = (TButtonPanel *)0x0;
    //     *ppTVar3 = (TButtonPanel *)0x0;
    //     ppTVar3 = ppTVar3 + 1;
    //     ppTVar5 = ppTVar5 + 3;
    //     iVar6 = iVar6 + -1;
    //   } while (iVar6 != 0);
    //   this->Diplomacy_status_label[0] = (TTextPanel *)0x0;
    //   this->Diplomacy_status_label[1] = (TTextPanel *)0x0;
    //   this->Diplomacy_status_label[2] = (TTextPanel *)0x0;
    //   this->Diplomacy_status_label[3] = (TTextPanel *)0x0;
    //   this->world = (TRIBE_World *)0x0;
    //   return;
    // }
    // 
    // 
}

// Offset: 0x004AF6C0
static void create_all_buttons_etc(TRIBE_Screen_Sed* this_) {
    // --- Ghidra decompiler output ---
    // 
    // /* WARNING: Variable defined which should be unmapped: i */
    // /* protected: void __thiscall TRIBE_Screen_Sed::create_all_buttons_etc(void) */
    // 
    // void __thiscall TRIBE_Screen_Sed::create_all_buttons_etc(TRIBE_Screen_Sed *this)
    // 
    // {
    //   TListPanel **ppTVar1;
    //   TEditPanel **ppTVar2;
    //   code *pcVar3;
    //   bool bVar4;
    //   TPanel *pTVar5;
    //   int iVar6;
    //   long lVar7;
    //   TShape *pTVar8;
    //   RGE_Font *pRVar9;
    //   TRIBE_Scenario_Editor_Panel_Object *pTVar10;
    //   TButtonPanel **ppTVar11;
    //   TDropDownPanel **ppTVar12;
    //   TButtonPanel **ppTVar13;
    //   TTextPanel **ppTVar14;
    //   TEditPanel **ppTVar15;
    //   TButtonPanel *(*papTVar16) [3];
    //   undefined4 *unaff_FS_OFFSET;
    //   long lVar17;
    //   int iVar18;
    //   int iVar19;
    //   int iVar20;
    //   int i;
    //   int iStack_1c8;
    //   TPanel *ptr [4];
    //   char str4 [20];
    //   char str3 [20];
    //   char str1 [140];
    //   char str [100];
    //   char str2 [140];
    //   undefined4 local_c;
    //   code *pcStack_8;
    //   undefined4 uStack_4;
    //   
    //   local_c = *unaff_FS_OFFSET;
    //   uStack_4 = 0xffffffff;
    //   pcStack_8 = FUN_0055f54a;
    //   *unaff_FS_OFFSET = &local_c;
    //   ppTVar13 = this->scenario_mode_button;
    //                     /* language.dll match for 0x271a: "Map" */
    //   iVar6 = create_button(this,(TPanel *)this,ppTVar13,0x271a,1);
    //   if (iVar6 != 0) {
    //                     /* language.dll match for 0x76c0: "Click to create randomly generated or custom
    //                        maps." */
    //     TPanel::set_help_info((TPanel *)*ppTVar13,0x76c0,-1);
    //                     /* language.dll match for 0x271b: "Terrain" */
    //     iVar6 = create_button(this,(TPanel *)this,this->scenario_mode_button + 1,0x271b,1);
    //     if (iVar6 != 0) {
    //                     /* language.dll match for 0x76c1: "Click to place resources, elevation, cliffs,
    //                        forests, and water." */
    //       TPanel::set_help_info((TPanel *)this->scenario_mode_button[1],0x76c1,-1);
    //                     /* language.dll match for 0x271c: "Players" */
    //       iVar6 = create_button(this,(TPanel *)this,this->scenario_mode_button + 2,0x271c,1);
    //       if (iVar6 != 0) {
    //                     /* language.dll match for 0x76c2: "Click to choose the starting age, starting
    //                        stockpiles, civilization, starting technology, and computer personality for
    //                        each player." */
    //         TPanel::set_help_info((TPanel *)this->scenario_mode_button[2],0x76c2,-1);
    //                     /* language.dll match for 0x271d: "Units" */
    //         iVar6 = create_button(this,(TPanel *)this,this->scenario_mode_button + 3,0x271d,1);
    //         if (iVar6 != 0) {
    //                     /* language.dll match for 0x76c3: "Click to place buildings, villagers, military
    //                        units, and boats for each player, as well as world (Gaia) objects, such as
    //                        trees, Artifacts, Ruins, Discoveries, and grass clumps and other terrain
    //                        accents." */
    //           TPanel::set_help_info((TPanel *)this->scenario_mode_button[3],0x76c3,-1);
    //                     /* language.dll match for 0x2722: "Diplomacy" */
    //           iVar6 = create_button(this,(TPanel *)this,this->scenario_mode_button + 4,0x2722,1);
    //           if (iVar6 != 0) {
    //                     /* language.dll match for 0x76c8: "Click to choose the diplomatic stance of
    //                        players (ally, neutral, or enemy) and whether any players pursue allied
    //                        victory." */
    //             TPanel::set_help_info((TPanel *)this->scenario_mode_button[4],0x76c8,-1);
    //                     /* language.dll match for 0x271e: "Individual Victory" */
    //             iVar6 = create_button(this,(TPanel *)this,this->scenario_mode_button + 5,0x271e,1);
    //             if (iVar6 != 0) {
    //                     /* language.dll match for 0x76c4: "Click to choose unique victory conditions for
    //                        each player." */
    //               TPanel::set_help_info((TPanel *)this->scenario_mode_button[5],0x76c4,-1);
    //                     /* language.dll match for 0x2723: "Global Victory" */
    //               iVar6 = create_button(this,(TPanel *)this,this->scenario_mode_button + 6,0x2723,1);
    //               if (iVar6 != 0) {
    //                     /* language.dll match for 0x76c9: "Click to select one or more victory
    //                        conditions that all players must achieve." */
    //                 TPanel::set_help_info((TPanel *)this->scenario_mode_button[6],0x76c9,-1);
    //                     /* language.dll match for 0x2721: "Options" */
    //                 iVar6 = create_button(this,(TPanel *)this,this->scenario_mode_button + 7,0x2721,1);
    //                 if (iVar6 != 0) {
    //                     /* language.dll match for 0x76c7: "Click to enable the full tech tree or disable
    //                        technology for each player." */
    //                   TPanel::set_help_info((TPanel *)this->scenario_mode_button[7],0x76c7,-1);
    //                     /* language.dll match for 0x271f: "Messages" */
    //                   iVar6 = create_button(this,(TPanel *)this,this->scenario_mode_button + 8,0x271f,1)
    //                   ;
    //                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x76c5: "Click to write scenario instructions, hints,
    //                        a victory message, a loss message, and historical information." */
    //                     TPanel::set_help_info((TPanel *)this->scenario_mode_button[8],0x76c5,-1);
    //                     /* language.dll match for 0x2720: "Cinematics" */
    //                     iVar6 = create_button(this,(TPanel *)this,this->scenario_mode_button + 9,0x2720,
    //                                           1);
    //                     if (iVar6 != 0) {
    //                     /* language.dll match for 0x76c6: "Click to choose the cinematics that play at
    //                        the beginning and end of the scenario." */
    //                       TPanel::set_help_info((TPanel *)this->scenario_mode_button[9],0x76c6,-1);
    //                       iVar6 = 10;
    //                       ppTVar11 = ppTVar13;
    //                       do {
    //                         TButtonPanel::set_radio_info(*ppTVar11,ppTVar13,10);
    //                         (**(code **)((*ppTVar11)->_padding_ + 0x14))(1);
    //                         ppTVar11 = ppTVar11 + 1;
    //                         iVar6 = iVar6 + -1;
    //                       } while (iVar6 != 0);
    //                       ppTVar13 = &this->menu_button;
    //                     /* language.dll match for 0x2724: "Menu" */
    //                       iVar6 = create_button(this,(TPanel *)this,ppTVar13,0x2724,0);
    //                       if (iVar6 != 0) {
    //                     /* language.dll match for 0x774c: "Click to display the menu." */
    //                         TPanel::set_help_info((TPanel *)*ppTVar13,0x774c,-1);
    //                         (**(code **)((*ppTVar13)->_padding_ + 0x14))(1);
    //                     /* language.dll match for 0xfa9: "?" */
    //                         iVar6 = create_button(this,(TPanel *)this,&this->help_button,0xfa9,0);
    //                         if (iVar6 != 0) {
    //                           (**(code **)(this->help_button->_padding_ + 0x14))(1);
    //                     /* language.dll match for 0x29a6: "Map" */
    //                           iVar6 = create_text(this,this->bottom_panel,&this->map_type_label,0x29a6);
    //                           if (iVar6 != 0) {
    //                             ppTVar13 = this->map_type_button;
    //                             iVar6 = create_radio_button(this,this->bottom_panel,ppTVar13);
    //                             if (iVar6 != 0) {
    //                     /* language.dll match for 0x76cf: "Click to display the default terrain with no
    //                        resources (food, wood, stone, or gold)." */
    //                               TPanel::set_help_info((TPanel *)*ppTVar13,0x76cf,-1);
    //                               iVar6 = create_radio_button(this,this->bottom_panel,
    //                                                           this->map_type_button + 1);
    //                               if (iVar6 != 0) {
    //                     /* language.dll match for 0x76d0: "Click to display a random distribution of
    //                        land, water, and resources." */
    //                                 TPanel::set_help_info((TPanel *)this->map_type_button[1],0x76d0,-1);
    //                                 iVar6 = create_radio_button(this,this->bottom_panel,
    //                                                             this->map_type_button + 2);
    //                                 if (iVar6 != 0) {
    //                     /* language.dll match for 0x76d1: "Click to display a random distribution of
    //                        land, water, and resources based on the seed (number) you type." */
    //                                   TPanel::set_help_info
    //                                             ((TPanel *)this->map_type_button[2],0x76d1,-1);
    //                     /* language.dll match for 0x299c: "Blank Map" */
    //                                   iVar6 = create_text(this,this->bottom_panel,this->map_type_text,
    //                                                       0x299c);
    //                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x299d: "Random Map" */
    //                                     iVar6 = create_text(this,this->bottom_panel,
    //                                                         this->map_type_text + 1,0x299d);
    //                                     if (iVar6 != 0) {
    //                     /* language.dll match for 0x299e: "Seed Map" */
    //                                       iVar6 = create_text(this,this->bottom_panel,
    //                                                           this->map_type_text + 2,0x299e);
    //                                       if (iVar6 != 0) {
    //                     /* language.dll match for 0x299f: "Default Terrain" */
    //                                         iVar6 = create_text(this,this->bottom_panel,
    //                                                             &this->default_terrain_label,0x299f);
    //                                         if (iVar6 != 0) {
    //                                           iVar6 = create_drop_down(this,this->bottom_panel,
    //                                                                    &this->default_terrain_drop);
    //                                           if (iVar6 != 0) {
    //                     /* language.dll match for 0x76d6: "Click to set the default terrain." */
    //                                             TPanel::set_help_info
    //                                                       ((TPanel *)this->default_terrain_drop,0x76d6,
    //                                                        -1);
    //                                             iVar20 = 0;
    //                                             iVar19 = 1;
    //                                             iVar18 = 1;
    //                                             lVar17 = 1;
    //                                             lVar7 = TPanel::height((TPanel *)this);
    //                                             iVar6 = lVar7 + -200;
    //                                             lVar7 = TPanel::width((TPanel *)this);
    //                     /* language.dll match for 0x29a5: "GENERATING MAP" */
    //                                             iVar6 = TEasy_Panel::create_text
    //                                                               ((TEasy_Panel *)this,
    //                                                                (TPanel *)this->main_view,
    //                                                                &this->map_generating_text,0x29a5,0,0
    //                                                                ,lVar7,iVar6,lVar17,iVar18,iVar19,
    //                                                                iVar20);
    //                                             if (iVar6 != 0) {
    //                                               (**(code **)(this->map_generating_text->_padding_ +
    //                                                           0x14))(0);
    //                     /* language.dll match for 0x29a0: "Map Size" */
    //                                               iVar6 = create_text(this,this->bottom_panel,
    //                                                                   &this->map_size_label,0x29a0);
    //                                               if (iVar6 != 0) {
    //                                                 iVar6 = create_drop_down(this,this->bottom_panel,
    //                                                                          &this->map_size_drop);
    //                                                 if (iVar6 != 0) {
    //                     /* language.dll match for 0x76d2: "Select the map size. The larger the map, the
    //                        longer the game." */
    //                                                   TPanel::set_help_info
    //                                                             ((TPanel *)this->map_size_drop,0x76d2,-1
    //                                                             );
    //                     /* language.dll match for 0x29a1: "Map Type" */
    //                                                   iVar6 = create_text(this,this->bottom_panel,
    //                                                                       &this->map_style_label,0x29a1)
    //                                                   ;
    //                                                   if (iVar6 != 0) {
    //                                                     iVar6 = create_drop_down(this,this->bottom_panel
    //                                                                              ,&this->map_style_drop)
    //                                                     ;
    //                                                     if (iVar6 != 0) {
    //                     /* language.dll match for 0x76d3: "Select the distribution of land and water on
    //                        the map." */
    //                                                       TPanel::set_help_info
    //                                                                 ((TPanel *)this->map_style_drop,
    //                                                                  0x76d3,-1);
    //                     /* language.dll match for 0x29a2: "Seed" */
    //                                                       iVar6 = create_text(this,this->bottom_panel,
    //                                                                           &this->random_seed_label,
    //                                                                           0x29a2);
    //                                                       if (iVar6 != 0) {
    //                                                         iVar6 = create_edit(this,this->bottom_panel,
    //                                                                             &this->random_seed_input
    //                                                                             ,s_0,5,FormatUnsignedInt
    //                                                                             ,0,0);
    //                                                         if (iVar6 != 0) {
    //                     /* language.dll match for 0x76d4: "Type the number of the seed map to use. For
    //                        example, if you type 532, and select the same number of players, map size,
    //                        and map type, the same map always appears. You can type any number up to
    //                        99999." */
    //                                                           TPanel::set_help_info
    //                                                                     ((TPanel *)
    //                                                                      this->random_seed_input,0x76d4,
    //                                                                      -1);
    //                     /* language.dll match for 0x29a3: "Seed" */
    //                                                           iVar6 = create_text(this,this->
    //                                                   bottom_panel,&this->random_seed_used_label,0x29a3)
    //                                                   ;
    //                                                   if (iVar6 != 0) {
    //                                                     iVar6 = create_text(this,this->bottom_panel,
    //                                                                         &this->random_seed_used_text
    //                                                                         ,s_0);
    //                                                     if (iVar6 != 0) {
    //                     /* language.dll match for 0x29a4: "Generate Map" */
    //                                                       iVar6 = create_button(this,this->bottom_panel,
    //                                                                             &this->
    //                                                   generate_map_button,0x29a4,0);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x76d5: "Click to create the map." */
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)this->generate_map_button,
    //                                                                0x76d5,-1);
    //                                                     iVar6 = 3;
    //                                                     ppTVar11 = ppTVar13;
    //                                                     do {
    //                                                       TButtonPanel::set_radio_info
    //                                                                 (*ppTVar11,ppTVar13,3);
    //                                                       ppTVar11 = ppTVar11 + 1;
    //                                                       iVar6 = iVar6 + -1;
    //                                                     } while (iVar6 != 0);
    //                     /* language.dll match for 0x29af: "Brush Size" */
    //                                                     iVar6 = create_text(this,this->bottom_panel,
    //                                                                         &this->brush_size_label,
    //                                                                         0x29af);
    //                                                     if (iVar6 != 0) {
    //                     /* language.dll match for 0x29bc: "Terrain" */
    //                                                       iVar6 = create_text(this,this->bottom_panel,
    //                                                                           &this->paint_terrain_label
    //                                                                           ,0x29bc);
    //                                                       if (iVar6 != 0) {
    //                                                         ppTVar13 = this->brush_size_button;
    //                                                         iVar6 = create_radio_button(this,this->
    //                                                   bottom_panel,ppTVar13);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x76d9: "Click to select the brush size." */
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)*ppTVar13,0x76d9,-1);
    //                                                     iVar6 = create_radio_button(this,this->
    //                                                   bottom_panel,this->brush_size_button + 1);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x76da: "Click to select the brush size." */
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)this->brush_size_button[1],
    //                                                                0x76da,-1);
    //                                                     iVar6 = create_radio_button(this,this->
    //                                                   bottom_panel,this->brush_size_button + 2);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x76db: "Click to select the brush size." */
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)this->brush_size_button[2],
    //                                                                0x76db,-1);
    //                                                     iVar6 = create_radio_button(this,this->
    //                                                   bottom_panel,this->brush_size_button + 3);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x76dc: "Click to select the brush size." */
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)this->brush_size_button[3],
    //                                                                0x76dc,-1);
    //                                                     iVar6 = create_radio_button(this,this->
    //                                                   bottom_panel,this->brush_size_button + 4);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x76dd: "Click to select the brush size." */
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)this->brush_size_button[4],
    //                                                                0x76dd,-1);
    //                     /* language.dll match for 0x29b0: "Tiny" */
    //                                                     iVar6 = create_text(this,this->bottom_panel,
    //                                                                         this->
    //                                                   brush_size_button_label,0x29b0);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x29b1: "Small" */
    //                                                     iVar6 = create_text(this,this->bottom_panel,
    //                                                                         this->
    //                                                   brush_size_button_label + 1,0x29b1);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x29b2: "Medium" */
    //                                                     iVar6 = create_text(this,this->bottom_panel,
    //                                                                         this->
    //                                                   brush_size_button_label + 2,0x29b2);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x29b3: "Large" */
    //                                                     iVar6 = create_text(this,this->bottom_panel,
    //                                                                         this->
    //                                                   brush_size_button_label + 3,0x29b3);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x29b4: "Huge" */
    //                                                     iVar6 = create_text(this,this->bottom_panel,
    //                                                                         this->
    //                                                   brush_size_button_label + 4,0x29b4);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x29b9: "Brush Type" */
    //                                                     iVar6 = create_text(this,this->bottom_panel,
    //                                                                         &this->paint_type_label,
    //                                                                         0x29b9);
    //                                                     if (iVar6 != 0) {
    //                                                       iVar6 = create_radio_button(this,this->
    //                                                   bottom_panel,this->paint_type_button);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x76de: "Click to paint background terrain (grass,
    //                        forest, water, etc.)." */
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)this->paint_type_button[0],
    //                                                                0x76de,-1);
    //                                                     iVar6 = create_radio_button(this,this->
    //                                                   bottom_panel,this->paint_type_button + 1);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x76df: "Click to paint hills." */
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)this->paint_type_button[1],
    //                                                                0x76df,-1);
    //                                                     iVar6 = create_radio_button(this,this->
    //                                                   bottom_panel,this->paint_type_button + 2);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x76e0: "Click to paint cliffs. To paint cliffs, drag
    //                        the mouse. To delete cliffs, right-click and drag over the existing cliffs.
    //                        Placing cliffs on different elevations creates gaps between the cliffs that
    //                        villagers and military units may have difficulty moving through." */
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)this->paint_type_button[2],
    //                                                                0x76e0,-1);
    //                     /* language.dll match for 0x271a: "Map" */
    //                                                     iVar6 = create_text(this,this->bottom_panel,
    //                                                                         this->
    //                                                   paint_type_button_label,0x271a);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x2987: "Elevation" */
    //                                                     iVar6 = create_text(this,this->bottom_panel,
    //                                                                         this->
    //                                                   paint_type_button_label + 1,0x2987);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x29ba: "Cliffs" */
    //                                                     iVar6 = create_text(this,this->bottom_panel,
    //                                                                         this->
    //                                                   paint_type_button_label + 2,0x29ba);
    //                                                   if (iVar6 != 0) {
    //                                                     iVar6 = create_list(this,this->bottom_panel,
    //                                                                         &this->paint_terrain_list,
    //                                                                         &this->
    //                                                   paint_terrain_scrollbar);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x76e1: "Select the terrain to paint." */
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)this->paint_terrain_list,
    //                                                                0x76e1,-1);
    //                                                     iVar6 = create_list(this,this->bottom_panel,
    //                                                                         &this->paint_elevation_list,
    //                                                                         &this->
    //                                                   paint_elevation_scrollbar);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x76e2: "Select the elevation to paint. The larger the
    //                        elevation number, the higher the terrain. Elevation 2 is flat terrain." */
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)this->paint_elevation_list,
    //                                                                0x76e2,-1);
    //                                                     iVar6 = 5;
    //                                                     ppTVar11 = ppTVar13;
    //                                                     do {
    //                                                       TButtonPanel::set_radio_info
    //                                                                 (*ppTVar11,ppTVar13,5);
    //                                                       ppTVar11 = ppTVar11 + 1;
    //                                                       iVar6 = iVar6 + -1;
    //                                                     } while (iVar6 != 0);
    //                                                     iVar6 = 3;
    //                                                     ppTVar13 = this->paint_type_button;
    //                                                     do {
    //                                                       TButtonPanel::set_radio_info
    //                                                                 (*ppTVar13,this->paint_type_button,3
    //                                                                 );
    //                                                       ppTVar13 = ppTVar13 + 1;
    //                                                       iVar6 = iVar6 + -1;
    //                                                     } while (iVar6 != 0);
    //                                                     ppTVar13 = this->unit_mode_select;
    //                                                     iVar6 = create_radio_button(this,this->
    //                                                   bottom_panel,ppTVar13);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x76f8: "Click here, select a unit from the list box,
    //                        and then click a location on the map." */
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)*ppTVar13,0x76f8,-1);
    //                                                     iVar6 = create_radio_button(this,this->
    //                                                   bottom_panel,this->unit_mode_select + 1);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x76f7: "Click here, and then click the unit to
    //                        delete." */
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)this->unit_mode_select[1],
    //                                                                0x76f7,-1);
    //                                                     iVar6 = create_radio_button(this,this->
    //                                                   bottom_panel,this->unit_mode_select + 2);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x76f9: "Click here, and then click the unit to move
    //                        on the map." */
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)this->unit_mode_select[2],
    //                                                                0x76f9,-1);
    //                                                     iVar6 = create_radio_button(this,this->
    //                                                   bottom_panel,this->unit_mode_select + 3);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x76fa: "Click here, and then click the unit to rotate
    //                        on the map." */
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)this->unit_mode_select[3],
    //                                                                0x76fa,-1);
    //                     /* language.dll match for 0x2777: "Place" */
    //                                                     iVar6 = create_text(this,this->bottom_panel,
    //                                                                         this->unit_mode_select_label
    //                                                                         ,0x2777);
    //                                                     if (iVar6 != 0) {
    //                     /* language.dll match for 0x2778: "Delete" */
    //                                                       iVar6 = create_text(this,this->bottom_panel,
    //                                                                           this->
    //                                                   unit_mode_select_label + 1,0x2778);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x2779: "Move" */
    //                                                     iVar6 = create_text(this,this->bottom_panel,
    //                                                                         this->unit_mode_select_label
    //                                                                         + 2,0x2779);
    //                                                     if (iVar6 != 0) {
    //                     /* language.dll match for 0x277a: "Rotate" */
    //                                                       iVar6 = create_text(this,this->bottom_panel,
    //                                                                           this->
    //                                                   unit_mode_select_label + 3,0x277a);
    //                                                   if (iVar6 != 0) {
    //                                                     iVar6 = 4;
    //                                                     ppTVar11 = ppTVar13;
    //                                                     do {
    //                                                       TButtonPanel::set_radio_info
    //                                                                 (*ppTVar11,ppTVar13,4);
    //                                                       ppTVar11 = ppTVar11 + 1;
    //                                                       iVar6 = iVar6 + -1;
    //                                                     } while (iVar6 != 0);
    //                                                     TButtonPanel::set_radio_button(*ppTVar13);
    //                                                     ppTVar1 = &this->unit_list;
    //                                                     iVar6 = create_list(this,(TPanel *)this,ppTVar1,
    //                                                                         &this->unit_scrollbar);
    //                                                     if (iVar6 != 0) {
    //                     /* language.dll match for 0x76fb: "Select the unit to place on the map." */
    //                                                       TPanel::set_help_info
    //                                                                 ((TPanel *)*ppTVar1,0x76fb,-1);
    //                                                       TPanel::set_z_order((TPanel *)*ppTVar1,'\x02',
    //                                                                           0);
    //                                                       pTVar8 = (TShape *)operator_new(0x20);
    //                                                       uStack_4 = 0;
    //                                                       if (pTVar8 == (TShape *)0x0) {
    //                                                         pTVar8 = (TShape *)0x0;
    //                                                       }
    //                                                       else {
    //                                                         pTVar8 = (TShape *)
    //                                                                  TShape::TShape(pTVar8,s_btnunit_shp
    //                                                                                 ,0xc62a);
    //                                                       }
    //                                                       uStack_4 = 0xffffffff;
    //                                                       this->button_unit_pics = pTVar8;
    //                                                       if (pTVar8 != (TShape *)0x0) {
    //                                                         iVar6 = TShape::is_loaded(pTVar8);
    //                                                         if (iVar6 != 0) {
    //                                                           iVar6 = 0;
    //                                                           do {
    //                                                             iVar18 = iVar6;
    //                                                             if (iVar6 == 4) {
    //                                                               iVar18 = 1;
    //                                                             }
    //                                                             sprintf(str + 4,s_btnbldg_d_shp,iVar18);
    //                                                             pTVar8 = (TShape *)operator_new(0x20);
    //                                                             uStack_4 = 1;
    //                                                             if (pTVar8 == (TShape *)0x0) {
    //                                                               pTVar8 = (TShape *)0x0;
    //                                                             }
    //                                                             else {
    //                                                               pTVar8 = (TShape *)
    //                                                                        TShape::TShape(pTVar8,str + 4
    //                                                                                       ,iVar18 + 
    //                                                   0xc610);
    //                                                   }
    //                                                   uStack_4 = 0xffffffff;
    //                                                   this->button_bldg_pics[iVar18] = pTVar8;
    //                                                   if (pTVar8 == (TShape *)0x0) goto LAB_004b1a1f;
    //                                                   iVar18 = TShape::is_loaded(pTVar8);
    //                                                   if (iVar18 == 0) goto LAB_004b1a1f;
    //                                                   iVar6 = iVar6 + 1;
    //                                                   } while (iVar6 < 5);
    //                                                   ppTVar12 = &this->unit_player_list;
    //                                                   iVar6 = create_drop_down(this,this->bottom_panel,
    //                                                                            ppTVar12);
    //                                                   if (iVar6 == 0) goto LAB_004b1a29;
    //                     /* language.dll match for 0x76fc: "Select the player to place units for." */
    //                                                   TPanel::set_help_info
    //                                                             ((TPanel *)*ppTVar12,0x76fc,-1);
    //                                                   pRVar9 = RGE_Base_Game::get_font(rge_base_game,10)
    //                                                   ;
    //                                                   pTVar10 = (TRIBE_Scenario_Editor_Panel_Object *)
    //                                                             operator_new(0x21c);
    //                                                   uStack_4 = 2;
    //                                                   if (pTVar10 ==
    //                                                       (TRIBE_Scenario_Editor_Panel_Object *)0x0) {
    //                                                     pTVar10 = (TRIBE_Scenario_Editor_Panel_Object *)
    //                                                               0x0;
    //                                                   }
    //                                                   else {
    //                                                     pTVar10 = (TRIBE_Scenario_Editor_Panel_Object *)
    //                                                               TRIBE_Scenario_Editor_Panel_Object::
    //                                                               TRIBE_Scenario_Editor_Panel_Object
    //                                                                         (pTVar10,(TDrawArea *)
    //                                                                                  this->_padding_,
    //                                                                          (TPanel *)this,pRVar9->font
    //                                                                          ,pRVar9->font_wid,
    //                                                                          pRVar9->font_hgt,
    //                                                                          this->button_unit_pics,
    //                                                                          this->button_bldg_pics,
    //                                                                          (TRIBE_Player *)0x0);
    //                                                   }
    //                                                   uStack_4 = 0xffffffff;
    //                                                   this->object_panel = pTVar10;
    //                                                   if ((pTVar10 !=
    //                                                        (TRIBE_Scenario_Editor_Panel_Object *)0x0) &&
    //                                                      (pTVar10->_padding_ == 0)) {
    //                                                     (**(code **)(pTVar10->_padding_ + 0x14))(0);
    //                                                     TPanel::set_z_order((TPanel *)*ppTVar12,'\x01',0
    //                                                                        );
    //                     /* language.dll match for 0x2864: "Number of Players" */
    //                                                     iVar6 = create_text(this,this->bottom_panel,
    //                                                                         &this->player_label,0x2864);
    //                                                     if (iVar6 != 0) {
    //                     /* language.dll match for 0x2815: "Starting Age" */
    //                                                       iVar6 = create_text(this,this->bottom_panel,
    //                                                                           &this->
    //                                                   player_starting_age_label,0x2815);
    //                                                   if (iVar6 != 0) {
    //                                                     iVar6 = create_drop_down(this,this->bottom_panel
    //                                                                              ,&this->
    //                                                   player_advance_civilization_drop);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x7765: "Select the starting age." */
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)
    //                                                                this->
    //                                                   player_advance_civilization_drop,0x7765,-1);
    //                                                   Set_player_advance_civilization_text(this,0);
    //                                                   iVar6 = create_drop_down(this,this->bottom_panel,
    //                                                                            &this->player_list);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x76e6: "Select the player to customize." */
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)this->player_list,0x76e6,-1
    //                                                               );
    //                                                     iVar6 = create_drop_down(this,this->bottom_panel
    //                                                                              ,&this->
    //                                                   player_number_list);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x76e7: "Select the number of players." */
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)this->player_number_list,
    //                                                                0x76e7,-1);
    //                     /* language.dll match for 0x280b: "Food" */
    //                                                     iVar6 = create_text(this,this->bottom_panel,
    //                                                                         this->player_inven_label,
    //                                                                         0x280b);
    //                                                     if (iVar6 != 0) {
    //                     /* language.dll match for 0x280c: "Wood" */
    //                                                       iVar6 = create_text(this,this->bottom_panel,
    //                                                                           this->player_inven_label +
    //                                                                           1,0x280c);
    //                                                       if (iVar6 != 0) {
    //                     /* language.dll match for 0x280d: "Stone" */
    //                                                         iVar6 = create_text(this,this->bottom_panel,
    //                                                                             this->player_inven_label
    //                                                                             + 2,0x280d);
    //                                                         if (iVar6 != 0) {
    //                     /* language.dll match for 0x280e: "Gold" */
    //                                                           iVar6 = create_text(this,this->
    //                                                   bottom_panel,this->player_inven_label + 3,0x280e);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x2805: "Tribe Name" */
    //                                                     iVar6 = create_text(this,this->bottom_panel,
    //                                                                         this->player_inven_label + 4
    //                                                                         ,0x2805);
    //                                                     if (iVar6 != 0) {
    //                                                       iVar6 = 0;
    //                                                       ppTVar15 = this->player_inven_input;
    //                                                       do {
    //                                                         iVar18 = create_edit(this,this->bottom_panel
    //                                                                              ,ppTVar15,s_0,5,
    //                                                                              FormatUnsignedInt,0,0);
    //                                                         if (iVar18 == 0) goto LAB_004b1a29;
    //                                                         iVar6 = iVar6 + 1;
    //                                                         ppTVar15 = ppTVar15 + 1;
    //                                                       } while (iVar6 < 4);
    //                     /* language.dll match for 0x76e8: "Type the amount of food the player has at the
    //                        beginning of the game." */
    //                                                       TPanel::set_help_info
    //                                                                 ((TPanel *)
    //                                                                  this->player_inven_input[0],0x76e8,
    //                                                                  1);
    //                     /* language.dll match for 0x76e9: "Type the amount of wood the player has at the
    //                        beginning of the game." */
    //                                                       TPanel::set_help_info
    //                                                                 ((TPanel *)
    //                                                                  this->player_inven_input[1],0x76e9,
    //                                                                  1);
    //                     /* language.dll match for 0x76eb: "Type the amount of stone the player has at
    //                        the beginning of the game." */
    //                                                       TPanel::set_help_info
    //                                                                 ((TPanel *)
    //                                                                  this->player_inven_input[2],0x76eb,
    //                                                                  1);
    //                     /* language.dll match for 0x76ea: "Type the amount of gold the player has at the
    //                        beginning of the game." */
    //                                                       TPanel::set_help_info
    //                                                                 ((TPanel *)
    //                                                                  this->player_inven_input[3],0x76ea,
    //                                                                  1);
    //                                                       iVar6 = create_edit(this,this->bottom_panel,
    //                                                                           this->player_inven_input +
    //                                                                           4,s_,0x1c,FormatText,1,1);
    //                                                       if (iVar6 != 0) {
    //                     /* language.dll match for 0x76ec: "Type a tribe name if you want to replace the
    //                        civilization name with a unique name when the scenario is played as a
    //                        campaign." */
    //                                                         TPanel::set_help_info
    //                                                                   ((TPanel *)
    //                                                                    this->player_inven_input[4],
    //                                                                    0x76ec,1);
    //                     /* language.dll match for 0x2810: "Player Type" */
    //                                                         iVar6 = create_text(this,this->bottom_panel,
    //                                                                             this->
    //                                                   player_setting_label,0x2810);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x2811: "Civilization" */
    //                                                     iVar6 = create_text(this,this->bottom_panel,
    //                                                                         this->player_setting_label +
    //                                                                         1,0x2811);
    //                                                     if (iVar6 != 0) {
    //                                                       iVar6 = 0;
    //                                                       ppTVar12 = this->player_setting_drop;
    //                                                       do {
    //                                                         iVar18 = create_drop_down(this,this->
    //                                                   bottom_panel,ppTVar12);
    //                                                   if (iVar18 == 0) goto LAB_004b1a29;
    //                                                   iVar6 = iVar6 + 1;
    //                                                   ppTVar12 = ppTVar12 + 1;
    //                                                   } while (iVar6 < 2);
    //                     /* language.dll match for 0x76ed: "Select whether the position is played by the
    //                        computer, a human, or either. If you select Either, the position can be
    //                        played by a human or by the computer (if it is not filled by a human)." */
    //                                                   TPanel::set_help_info
    //                                                             ((TPanel *)this->player_setting_drop[0],
    //                                                              0x76ed,-1);
    //                     /* language.dll match for 0x76ee: "Select the player's civilization. Each
    //                        civilization has special skills and can research different technologies. More
    //                        than one player can select the same civilization." */
    //                                                   TPanel::set_help_info
    //                                                             ((TPanel *)this->player_setting_drop[1],
    //                                                              0x76ee,-1);
    //                                                   iVar6 = create_drop_down(this,this->bottom_panel,
    //                                                                            &this->BuildList);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x76ef: "Select the strategy the computer player uses
    //                        to determine which buildings, military units, boats, and technologies to
    //                        research." */
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)this->BuildList,0x76ef,-1);
    //                                                     iVar6 = create_drop_down(this,this->bottom_panel
    //                                                                              ,&this->CityLayout);
    //                                                     if (iVar6 != 0) {
    //                     /* language.dll match for 0x76f0: "Select the city plan the computer player uses
    //                        to determine where to construct buildings." */
    //                                                       TPanel::set_help_info
    //                                                                 ((TPanel *)this->CityLayout,0x76f0,
    //                                                                  -1);
    //                                                       iVar6 = create_drop_down(this,this->
    //                                                   bottom_panel,&this->AiRules);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x76f1: "Select the personality of the computer
    //                        player. For most situations, you can select Aggressive or Passive." */
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)this->AiRules,0x76f1,-1);
    //                     /* language.dll match for 0x2813: "Strategy" */
    //                                                     iVar6 = create_text(this,this->bottom_panel,
    //                                                                         &this->player_build_text,
    //                                                                         0x2813);
    //                                                     if (iVar6 != 0) {
    //                     /* language.dll match for 0x2814: "City Plan" */
    //                                                       iVar6 = create_text(this,this->bottom_panel,
    //                                                                           &this->player_city_text,
    //                                                                           0x2814);
    //                                                       if (iVar6 != 0) {
    //                     /* language.dll match for 0x2812: "Personality" */
    //                                                         iVar6 = create_text(this,this->bottom_panel,
    //                                                                             &this->AiRules_text,
    //                                                                             0x2812);
    //                                                         if (iVar6 != 0) {
    //                                                           pcVar3 = *(code **)(this->_padding_ + 200)
    //                                                           ;
    //                                                           (*pcVar3)(this->player_inven_input,5);
    //                                                           iVar6 = create_check_box(this,this->
    //                                                   bottom_panel,this->victory_cond_on);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x7704: "The first civilization (or team) to destroy
    //                        all opponents' villagers, military units, boats, and buildings wins the game.
    //                        You do not need to destroy trade vessels, transport vessels, fishing vessels,
    //                        Artifacts, Ruins, or walls." */
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)this->victory_cond_on[0],
    //                                                                0x7704,-1);
    //                                                     iVar6 = create_check_box(this,this->bottom_panel
    //                                                                              ,this->victory_cond_on
    //                                                                               + 1);
    //                                                     if (iVar6 != 0) {
    //                     /* language.dll match for 0x7706: "Type the percentage of the map that must be
    //                        explored." */
    //                                                       TPanel::set_help_info
    //                                                                 ((TPanel *)this->victory_cond_on[1],
    //                                                                  0x7706,-1);
    //                                                       iVar6 = create_check_box(this,this->
    //                                                   bottom_panel,this->victory_cond_on + 2);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x7707: "The first civilization (or team) to control
    //                        the designated number of Ruins wins the game. The game ends immediately.
    //                        There is no countdown clock. For allied victory, the Ruins must be controlled
    //                        by any of the allies." */
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)this->victory_cond_on[2],
    //                                                                0x7707,-1);
    //                                                     iVar6 = create_check_box(this,this->bottom_panel
    //                                                                              ,this->victory_cond_on
    //                                                                               + 3);
    //                                                     if (iVar6 != 0) {
    //                     /* language.dll match for 0x7708: "The first civilization (or team) to control
    //                        the designated number of Artifacts wins the game. The game ends immediately.
    //                        There is no countdown clock. For allied victory, the Artifacts must be
    //                        controlled by any of the allies." */
    //                                                       TPanel::set_help_info
    //                                                                 ((TPanel *)this->victory_cond_on[3],
    //                                                                  0x7708,-1);
    //                                                       iVar6 = create_check_box(this,this->
    //                                                   bottom_panel,this->victory_cond_on + 4);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x7709: "The first civilization (or team) to locate
    //                        the specified # of Discoveries wins. Discoveries are natural sites of
    //                        significance represented by a white horse etched into the ground. To locate a
    //                        Discovery, move a unit near it. A colored flag shows which civilizations have
    //                        located the Discovery. For allied victory, all allies must locate all
    //                        Discoveries." */
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)this->victory_cond_on[4],
    //                                                                0x7709,-1);
    //                                                     iVar6 = create_check_box(this,this->bottom_panel
    //                                                                              ,this->victory_cond_on
    //                                                                               + 5);
    //                                                     if (iVar6 != 0) {
    //                                                       TPanel::set_help_info
    //                                                                 ((TPanel *)this->victory_cond_on[5],
    //                                                                  0x770a,-1);
    //                                                       ppTVar13 = this->victory_and_or;
    //                                                       iVar6 = create_radio_button(this,this->
    //                                                   bottom_panel,ppTVar13);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x7701: "Click to allow players to achieve any one of
    //                        the custom victory conditions to win the game." */
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)*ppTVar13,0x7701,-1);
    //                                                     iVar6 = create_radio_button(this,this->
    //                                                   bottom_panel,this->victory_and_or + 1);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x7703: "Click to require players to achieve all of
    //                        the custom victory conditions to win the game." */
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)this->victory_and_or[1],
    //                                                                0x7703,-1);
    //                                                     iVar6 = 2;
    //                                                     ppTVar11 = ppTVar13;
    //                                                     do {
    //                                                       TButtonPanel::set_radio_info
    //                                                                 (*ppTVar11,ppTVar13,2);
    //                                                       ppTVar11 = ppTVar11 + 1;
    //                                                       iVar6 = iVar6 + -1;
    //                                                     } while (iVar6 != 0);
    //                                                     TButtonPanel::set_radio_button(*ppTVar13);
    //                     /* language.dll match for 0x28a2: "Any one" */
    //                                                     iVar6 = create_text(this,this->bottom_panel,
    //                                                                         this->victory_text_and_or,
    //                                                                         0x28a2);
    //                                                     if (iVar6 != 0) {
    //                     /* language.dll match for 0x28a3: "All" */
    //                                                       iVar6 = create_text(this,this->bottom_panel,
    //                                                                           this->victory_text_and_or
    //                                                                           + 1,0x28a3);
    //                                                       if (iVar6 != 0) {
    //                     /* language.dll match for 0x28a4: "Quantity" */
    //                                                         iVar6 = create_text(this,this->bottom_panel,
    //                                                                             &this->
    //                                                   victory_amount_label,0x28a4);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x28a5: "Which Conditions" */
    //                                                     iVar6 = create_text(this,this->bottom_panel,
    //                                                                         &this->victory_long_label,
    //                                                                         0x28a5);
    //                                                     if (iVar6 != 0) {
    //                     /* language.dll match for 0x10e0: "Victory Condition" */
    //                                                       iVar6 = create_text(this,this->bottom_panel,
    //                                                                           &this->
    //                                                   victory_condition_label,0x10e0);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x10e1: "Conquest" */
    //                                                     iVar6 = create_text(this,this->bottom_panel,
    //                                                                         &this->
    //                                                   victory_label_conquest,0x10e1);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x10e2: "Exploration" */
    //                                                     iVar6 = create_text(this,this->bottom_panel,
    //                                                                         &this->victory_label_explore
    //                                                                         ,0x10e2);
    //                                                     if (iVar6 != 0) {
    //                     /* language.dll match for 0x10e7: "Default" */
    //                                                       iVar6 = create_text(this,this->bottom_panel,
    //                                                                           &this->
    //                                                   victory_label_explore_percent,0x10e7);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x10e3: "Ruins" */
    //                                                     iVar6 = create_text(this,this->bottom_panel,
    //                                                                         &this->victory_label_ruins,
    //                                                                         0x10e3);
    //                                                     if (iVar6 != 0) {
    //                     /* language.dll match for 0x10e4: "Artifacts" */
    //                                                       iVar6 = create_text(this,this->bottom_panel,
    //                                                                           &this->
    //                                                   victory_label_artifacts,0x10e4);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x10e5: "Discoveries" */
    //                                                     iVar6 = create_text(this,this->bottom_panel,
    //                                                                         &this->
    //                                                   victory_label_discoveries,0x10e5);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x10e6: "Gold" */
    //                                                     iVar6 = create_text(this,this->bottom_panel,
    //                                                                         &this->victory_label_gold,
    //                                                                         0x10e6);
    //                                                     if (iVar6 != 0) {
    //                                                       iVar6 = create_edit(this,this->bottom_panel,
    //                                                                           &this->
    //                                                   victory_condition_explore,&s__,3,FormatUnsignedInt
    //                                                   ,0,0);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x770b: "Type the percentage of the map that must be
    //                        explored for an exploration victory." */
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)
    //                                                                this->victory_condition_explore,
    //                                                                0x770b,-1);
    //                                                     iVar6 = create_edit(this,this->bottom_panel,
    //                                                                         &this->
    //                                                   victory_condition_ruins,&s__,2,FormatUnsignedInt,0
    //                                                   ,0);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x770c: "Type the number of Ruins that must be
    //                        controlled for a Ruins victory." */
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)
    //                                                                this->victory_condition_ruins,0x770c,
    //                                                                -1);
    //                                                     ppTVar15 = &this->victory_condition_artifacts;
    //                                                     iVar6 = create_edit(this,this->bottom_panel,
    //                                                                         ppTVar15,&s__,2,
    //                                                                         FormatUnsignedInt,0,0);
    //                                                     if (iVar6 != 0) {
    //                     /* language.dll match for 0x770d: "Type the number of Artifacts that must be
    //                        controlled for an Artifacts victory." */
    //                                                       TPanel::set_help_info
    //                                                                 ((TPanel *)*ppTVar15,0x770d,-1);
    //                                                       ppTVar2 = &this->victory_condition_discoveries
    //                                                       ;
    //                                                       iVar6 = create_edit(this,this->bottom_panel,
    //                                                                           ppTVar2,&s__,2,
    //                                                                           FormatUnsignedInt,0,0);
    //                                                       if (iVar6 != 0) {
    //                     /* language.dll match for 0x770e: "Type the number of Discoveries that must be
    //                        located for a Discoveries victory." */
    //                                                         TPanel::set_help_info
    //                                                                   ((TPanel *)*ppTVar2,0x770e,-1);
    //                                                         iVar6 = create_edit(this,this->bottom_panel,
    //                                                                             &this->
    //                                                   victory_condition_gold,&s__,5,FormatUnsignedInt,0,
    //                                                   0);
    //                                                   if (iVar6 != 0) {
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)
    //                                                                this->victory_condition_gold,0x770f,
    //                                                                -1);
    //                                                     ptr[2] = (TPanel *)this->victory_condition_ruins
    //                                                     ;
    //                                                     ptr[1] = (TPanel *)
    //                                                              this->victory_condition_explore;
    //                                                     ptr[3] = (TPanel *)*ppTVar15;
    //                                                     str4._0_4_ = *ppTVar2;
    //                                                     (*pcVar3)(ptr + 1,4);
    //                     /* language.dll match for 0x10ec: "Standard" */
    //                                                     iVar6 = create_text(this,this->bottom_panel,
    //                                                                         this->
    //                                                   victory_cond_type_label,0x10ec);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x10e1: "Conquest" */
    //                                                     iVar6 = create_text(this,this->bottom_panel,
    //                                                                         this->
    //                                                   victory_cond_type_label + 1,0x10e1);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x10ea: "Score" */
    //                                                     iVar6 = create_text(this,this->bottom_panel,
    //                                                                         this->
    //                                                   victory_cond_type_label + 2,0x10ea);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x10e9: "Time Limit" */
    //                                                     iVar6 = create_text(this,this->bottom_panel,
    //                                                                         this->
    //                                                   victory_cond_type_label + 3,0x10e9);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x10eb: "Custom" */
    //                                                     iVar6 = create_text(this,this->bottom_panel,
    //                                                                         this->
    //                                                   victory_cond_type_label + 4,0x10eb);
    //                                                   if (iVar6 != 0) {
    //                                                     ppTVar13 = this->victory_cond_type;
    //                                                     iVar6 = create_radio_button(this,this->
    //                                                   bottom_panel,ppTVar13);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x7756: "Click to require players to achieve one of
    //                        the standard victory conditions (Artifacts, Ruins, Wonders, or Conquest) to
    //                        win the game." */
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)*ppTVar13,0x7756,-1);
    //                                                     iVar6 = create_radio_button(this,this->
    //                                                   bottom_panel,this->victory_cond_type + 1);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x7757: "The first civilization (or team) to destroy
    //                        all opponents' villagers, military units, boats, and buildings wins the game.
    //                        You do not need to destroy trade vessels, transport vessels, fishing vessels,
    //                        Artifacts, Ruins, or walls." */
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)this->victory_cond_type[1],
    //                                                                0x7757,-1);
    //                                                     iVar6 = create_radio_button(this,this->
    //                                                   bottom_panel,this->victory_cond_type + 2);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x7758: "Click to set the victory condition to Score.
    //                        The first player to achieve the specified score wins the game." */
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)this->victory_cond_type[2],
    //                                                                0x7758,-1);
    //                                                     iVar6 = create_radio_button(this,this->
    //                                                   bottom_panel,this->victory_cond_type + 3);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x7759: "Click to set the victory condition to Time
    //                        Limit. The player with the highest score at the end of the time limit wins
    //                        the game." */
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)this->victory_cond_type[3],
    //                                                                0x7759,-1);
    //                                                     iVar6 = create_radio_button(this,this->
    //                                                   bottom_panel,this->victory_cond_type + 4);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x775a: "Click to set one or more custom victory
    //                        conditions." */
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)this->victory_cond_type[4],
    //                                                                0x775a,-1);
    //                                                     iVar6 = 5;
    //                                                     ppTVar11 = ppTVar13;
    //                                                     do {
    //                                                       TButtonPanel::set_radio_info
    //                                                                 (*ppTVar11,ppTVar13,5);
    //                                                       ppTVar11 = ppTVar11 + 1;
    //                                                       iVar6 = iVar6 + -1;
    //                                                     } while (iVar6 != 0);
    //                                                     TButtonPanel::set_radio_button
    //                                                               (this->victory_cond_type[1]);
    //                     /* language.dll match for 0x10ea: "Score" */
    //                                                     iVar6 = create_text(this,this->bottom_panel,
    //                                                                         &this->victory_score_label,
    //                                                                         0x10ea);
    //                                                     if (iVar6 != 0) {
    //                                                       ppTVar12 = &this->victory_score;
    //                                                       iVar6 = create_drop_down(this,this->
    //                                                   bottom_panel,ppTVar12);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x775b: "Select the score for the game." */
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)*ppTVar12,0x775b,-1);
    //                                                     TDropDownPanel::empty_list(*ppTVar12);
    //                                                     TDropDownPanel::append_line
    //                                                               (*ppTVar12,s_3000,3000);
    //                                                     TDropDownPanel::append_line
    //                                                               (*ppTVar12,s_2700,0xa8c);
    //                     /* language.dll match for 0x960: "********** TRIBE ERRORS **********" */
    //                                                     TDropDownPanel::append_line
    //                                                               (*ppTVar12,s_2400,0x960);
    //                                                     TDropDownPanel::append_line
    //                                                               (*ppTVar12,s_2100,0x834);
    //                                                     TDropDownPanel::append_line
    //                                                               (*ppTVar12,s_1800,0x708);
    //                                                     TDropDownPanel::append_line
    //                                                               (*ppTVar12,s_1500,0x5dc);
    //                     /* language.dll match for 0x4b0: "Ready" */
    //                                                     TDropDownPanel::append_line
    //                                                               (*ppTVar12,s_1200,0x4b0);
    //                                                     TDropDownPanel::append_line(*ppTVar12,s_900,900)
    //                                                     ;
    //                                                     TDropDownPanel::append_line(*ppTVar12,s_800,800)
    //                                                     ;
    //                                                     TDropDownPanel::append_line(*ppTVar12,s_700,700)
    //                                                     ;
    //                                                     TDropDownPanel::append_line(*ppTVar12,s_600,600)
    //                                                     ;
    //                                                     TDropDownPanel::append_line(*ppTVar12,s_500,500)
    //                                                     ;
    //                                                     TDropDownPanel::append_line(*ppTVar12,s_400,400)
    //                                                     ;
    //                                                     TDropDownPanel::append_line(*ppTVar12,s_300,300)
    //                                                     ;
    //                     /* language.dll match for 0x10e9: "Time Limit" */
    //                                                     iVar6 = create_text(this,this->bottom_panel,
    //                                                                         &this->victory_time_label,
    //                                                                         0x10e9);
    //                                                     if (iVar6 != 0) {
    //                                                       ppTVar12 = &this->victory_time;
    //                                                       iVar6 = create_drop_down(this,this->
    //                                                   bottom_panel,ppTVar12);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x775c: "Select the time limit for the game." */
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)*ppTVar12,0x775c,-1);
    //                                                     TDropDownPanel::empty_list(*ppTVar12);
    //                     /* language.dll match for 0x2634: "15,000 years (2:00 hr)" */
    //                                                     TDropDownPanel::append_line
    //                                                               (*ppTVar12,0x2634,15000);
    //                     /* language.dll match for 0x2635: "13,000 years (1:45 hr)" */
    //                                                     TDropDownPanel::append_line
    //                                                               (*ppTVar12,0x2635,13000);
    //                     /* language.dll match for 0x2636: "11,000 years (1:30 hr)" */
    //                                                     TDropDownPanel::append_line
    //                                                               (*ppTVar12,0x2636,11000);
    //                     /* language.dll match for 0x2637: "9,000 years (1:15 hr)" */
    //                                                     TDropDownPanel::append_line
    //                                                               (*ppTVar12,0x2637,9000);
    //                     /* language.dll match for 0x2638: "7,000 years (60 min)" */
    //                                                     TDropDownPanel::append_line
    //                                                               (*ppTVar12,0x2638,7000);
    //                     /* language.dll match for 0x2639: "5,000 years (40 min)" */
    //                                                     TDropDownPanel::append_line
    //                                                               (*ppTVar12,0x2639,5000);
    //                     /* language.dll match for 0x263a: "3,000 years (25 min)" */
    //                                                     TDropDownPanel::append_line
    //                                                               (*ppTVar12,0x263a,3000);
    //                                                     ppTVar13 = this->victory_button;
    //                                                     iVar6 = 1;
    //                                                     do {
    //                                                       sprintf(str1 + 4,&s__d,iVar6);
    //                                                       sprintf(str2 + 4,s_<_d>,iVar6);
    //                                                       sprintf(str3 + 4,s__d_,iVar6);
    //                                                       sprintf(str4 + 4,s_<_d*>,iVar6);
    //                                                       iVar18 = create_button(this,this->bottom_panel
    //                                                                              ,ppTVar13,str1 + 4,
    //                                                                              str2 + 4,str3 + 4,
    //                                                                              str4 + 4);
    //                                                       if (iVar18 == 0) goto LAB_004b1a29;
    //                     /* language.dll match for 0x7712: "Click the number of the victory condition to
    //                        set or edit." */
    //                                                       TPanel::set_help_info
    //                                                                 ((TPanel *)*ppTVar13,0x7712,-1);
    //                                                       ppTVar13 = ppTVar13 + 1;
    //                                                       bVar4 = iVar6 < 0xc;
    //                                                       iVar6 = iVar6 + 1;
    //                                                     } while (bVar4);
    //                                                     iVar6 = create_drop_down(this,this->bottom_panel
    //                                                                              ,&this->
    //                                                   victory_drop_down);
    //                                                   if (iVar6 != 0) {
    //                                                     iVar6 = create_drop_down(this,this->bottom_panel
    //                                                                              ,&this->
    //                                                   victory_object_list);
    //                                                   if (iVar6 != 0) {
    //                                                     iVar6 = create_drop_down(this,this->bottom_panel
    //                                                                              ,&this->
    //                                                   victory_player_list);
    //                                                   if (iVar6 != 0) {
    //                                                     iVar6 = create_drop_down(this,this->bottom_panel
    //                                                                              ,&this->
    //                                                   victory_enemy_player_list);
    //                                                   if (iVar6 != 0) {
    //                                                     iVar6 = create_drop_down(this,this->bottom_panel
    //                                                                              ,&this->
    //                                                   victory_attribute_list);
    //                                                   if (iVar6 != 0) {
    //                                                     iVar6 = create_drop_down(this,this->bottom_panel
    //                                                                              ,&this->
    //                                                   victory_ages_list);
    //                                                   if (iVar6 != 0) {
    //                                                     iVar6 = create_drop_down(this,this->bottom_panel
    //                                                                              ,&this->
    //                                                   victory_tech_list);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x7716: "Select the victory condition." */
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)this->victory_drop_down,
    //                                                                0x7716,-1);
    //                     /* language.dll match for 0x7714: "Select a unit." */
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)this->victory_object_list,
    //                                                                0x7714,-1);
    //                     /* language.dll match for 0x7713: "Select the player to customize." */
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)this->victory_player_list,
    //                                                                0x7713,-1);
    //                     /* language.dll match for 0x7715: "Select the age." */
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)this->victory_ages_list,
    //                                                                0x7715,-1);
    //                     /* language.dll match for 0x7760: "Select which enemy player." */
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)
    //                                                                this->victory_enemy_player_list,
    //                                                                0x7760,-1);
    //                     /* language.dll match for 0x7761: "Select the attribute to achieve:  Razings
    //                        (enemy buildings to destroy), Conversions, Kill Ratio (# of units killed
    //                        compared to those lost), Wonders that must be built and held, Military
    //                        Population that must be created, Technologies that must be researched,
    //                        Villager Population that must be created, Kills (# of military units,
    //                        villagers, or boats that must be killed)." */
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)
    //                                                                this->victory_attribute_list,0x7761,
    //                                                                -1);
    //                     /* language.dll match for 0x7762: "Select the technology to achieve." */
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)this->victory_tech_list,
    //                                                                0x7762,-1);
    //                     /* language.dll match for 0x2870: "Victory Condition" */
    //                                                     iVar6 = create_text(this,this->bottom_panel,
    //                                                                         &this->
    //                                                   victory_condition_text,0x2870);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x2871: "Victory Type" */
    //                                                     iVar6 = create_text(this,this->bottom_panel,
    //                                                                         &this->
    //                                                   victory_condition_type,0x2871);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x2872: "Set Object" */
    //                                                     iVar6 = create_button(this,this->bottom_panel,
    //                                                                           &this->
    //                                                   victory_button_set_object,0x2872,0);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x2873: "Set Destination" */
    //                                                     iVar6 = create_button(this,this->bottom_panel,
    //                                                                           &this->
    //                                                   victory_button_set_destination,0x2873,0);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x2874: "Go to Destination" */
    //                                                     iVar6 = create_button(this,this->bottom_panel,
    //                                                                           &this->
    //                                                   victory_button_go_to_dest,0x2874,0);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x7717: "Click here, and then click a unit on the
    //                        map." */
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)
    //                                                                this->victory_button_set_object,
    //                                                                0x7717,-1);
    //                     /* language.dll match for 0x7718: "Click here, and then click a location on the
    //                        map or drag the mouse to create an area box." */
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)
    //                                                                this->victory_button_set_destination,
    //                                                                0x7718,-1);
    //                     /* language.dll match for 0x7719: "Click to display the destination location or
    //                        area." */
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)
    //                                                                this->victory_button_go_to_dest,
    //                                                                0x7719,-1);
    //                     /* language.dll match for 0x2875: "Quantity" */
    //                                                     iVar6 = create_text(this,this->bottom_panel,
    //                                                                         &this->victory_amount_text,
    //                                                                         0x2875);
    //                                                     if (iVar6 != 0) {
    //                     /* language.dll match for 0x2876: "Which Player" */
    //                                                       iVar6 = create_text(this,this->bottom_panel,
    //                                                                           &this->
    //                                                   victory_which_enemy_text,0x2876);
    //                                                   if (iVar6 != 0) {
    //                                                     iVar6 = create_edit(this,this->bottom_panel,
    //                                                                         &this->victory_amount_input,
    //                                                                         s_0,5,FormatUnsignedInt,0,0)
    //                                                     ;
    //                                                     if (iVar6 != 0) {
    //                                                       ppTVar13 = this->message_button;
    //                                                       iVar6 = 0;
    //                                                       ppTVar11 = ppTVar13;
    //                                                       do {
    //                                                         iVar18 = create_radio_button(this,this->
    //                                                   bottom_panel,ppTVar11);
    //                                                   if (iVar18 == 0) goto LAB_004b1a29;
    //                                                   iVar6 = iVar6 + 1;
    //                                                   ppTVar11 = ppTVar11 + 1;
    //                                                   } while (iVar6 < 5);
    //                     /* language.dll match for 0x771c: "Type the scenario instructions. Be sure to
    //                        explain what players must do to win the game." */
    //                                                   this->current_message = 0;
    //                                                   TPanel::set_help_info
    //                                                             ((TPanel *)*ppTVar13,0x771c,-1);
    //                     /* language.dll match for 0x771d: "Type the hints text for the scenario
    //                        (optional)." */
    //                                                   TPanel::set_help_info
    //                                                             ((TPanel *)this->message_button[1],
    //                                                              0x771d,-1);
    //                     /* language.dll match for 0x771e: "Type the victory message that appears for the
    //                        winner(s) of the scenario (optional)." */
    //                                                   TPanel::set_help_info
    //                                                             ((TPanel *)this->message_button[2],
    //                                                              0x771e,-1);
    //                     /* language.dll match for 0x771f: "Type the loss message that appears for the
    //                        loser(s) of the scenario (optional)." */
    //                                                   TPanel::set_help_info
    //                                                             ((TPanel *)this->message_button[3],
    //                                                              0x771f,-1);
    //                     /* language.dll match for 0x7720: "Type historical background information for
    //                        the scenario (optional)." */
    //                                                   TPanel::set_help_info
    //                                                             ((TPanel *)this->message_button[4],
    //                                                              0x7720,-1);
    //                     /* language.dll match for 0x2a36: "Scenario Instructions" */
    //                                                   iVar6 = create_text(this,this->bottom_panel,
    //                                                                       this->message_button_label,
    //                                                                       0x2a36);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x2a37: "Hints" */
    //                                                     iVar6 = create_text(this,this->bottom_panel,
    //                                                                         this->message_button_label +
    //                                                                         1,0x2a37);
    //                                                     if (iVar6 != 0) {
    //                     /* language.dll match for 0x2a38: "Victory" */
    //                                                       iVar6 = create_text(this,this->bottom_panel,
    //                                                                           this->message_button_label
    //                                                                           + 2,0x2a38);
    //                                                       if (iVar6 != 0) {
    //                     /* language.dll match for 0x2a39: "Loss" */
    //                                                         iVar6 = create_text(this,this->bottom_panel,
    //                                                                             this->
    //                                                   message_button_label + 3,0x2a39);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x2a31: "History" */
    //                                                     iVar6 = create_text(this,this->bottom_panel,
    //                                                                         this->message_button_label +
    //                                                                         4,0x2a31);
    //                                                     if (iVar6 != 0) {
    //                                                       iVar6 = 5;
    //                                                       ppTVar11 = ppTVar13;
    //                                                       do {
    //                                                         TButtonPanel::set_radio_info
    //                                                                   (*ppTVar11,ppTVar13,5);
    //                                                         ppTVar11 = ppTVar11 + 1;
    //                                                         iVar6 = iVar6 + -1;
    //                                                       } while (iVar6 != 0);
    //                                                       iVar6 = create_edit(this,this->bottom_panel,
    //                                                                           &this->message_input,s_,
    //                                                                           0xfff,FormatMultiLine,1,1)
    //                                                       ;
    //                                                       if (iVar6 != 0) {
    //                                                         TPanel::set_help_info
    //                                                                   ((TPanel *)this->message_input,-1,
    //                                                                    -1);
    //                     /* language.dll match for 0x2af9: "Pre-Game Cinematic" */
    //                                                         iVar6 = create_text(this,this->bottom_panel,
    //                                                                             this->cinematic_label,
    //                                                                             0x2af9);
    //                                                         if (iVar6 != 0) {
    //                     /* language.dll match for 0x2afa: "Victory Cinematic" */
    //                                                           iVar6 = create_text(this,this->
    //                                                   bottom_panel,this->cinematic_label + 1,0x2afa);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x2afb: "Loss Cinematic" */
    //                                                     iVar6 = create_text(this,this->bottom_panel,
    //                                                                         this->cinematic_label + 2,
    //                                                                         0x2afb);
    //                                                     if (iVar6 != 0) {
    //                     /* language.dll match for 0x2afc: "Scenario Instruction Map" */
    //                                                       iVar6 = create_text(this,this->bottom_panel,
    //                                                                           this->cinematic_label + 3,
    //                                                                           0x2afc);
    //                                                       if (iVar6 != 0) {
    //                                                         iVar6 = 0;
    //                                                         ppTVar12 = this->cinematic_input;
    //                                                         do {
    //                                                           iVar18 = create_drop_down(this,this->
    //                                                   bottom_panel,ppTVar12);
    //                                                   if (iVar18 == 0) goto LAB_004b1a29;
    //                                                   iVar6 = iVar6 + 1;
    //                                                   ppTVar12 = ppTVar12 + 1;
    //                                                   } while (iVar6 < 4);
    //                     /* language.dll match for 0x7724: "Select the cinematic that plays before a
    //                        scenario begins (optional)." */
    //                                                   TPanel::set_help_info
    //                                                             ((TPanel *)this->cinematic_input[0],
    //                                                              0x7724,-1);
    //                     /* language.dll match for 0x7725: "Select the victory cinematic that plays for
    //                        the winner(s) of the scenario (optional)." */
    //                                                   TPanel::set_help_info
    //                                                             ((TPanel *)this->cinematic_input[1],
    //                                                              0x7725,-1);
    //                     /* language.dll match for 0x7726: "Select the loss cinematic that plays for the
    //                        loser(s) of the scenario (optional)." */
    //                                                   TPanel::set_help_info
    //                                                             ((TPanel *)this->cinematic_input[2],
    //                                                              0x7726,-1);
    //                     /* language.dll match for 0x7727: "Select the mission briefing map that appears
    //                        before a campaign (optional)." */
    //                                                   TPanel::set_help_info
    //                                                             ((TPanel *)this->cinematic_input[3],
    //                                                              0x7727,-1);
    //                     /* language.dll match for 0x2604: "Full Tech Tree" */
    //                                                   iVar6 = create_text(this,this->bottom_panel,
    //                                                                       this->options_label,0x2604);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x32d7: "Disable Technology" */
    //                                                     iVar6 = create_text(this,this->bottom_panel,
    //                                                                         &this->
    //                                                   options_disable_tech_text,0x32d7);
    //                                                   if (iVar6 != 0) {
    //                                                     iVar6 = 0;
    //                                                     ppTVar13 = this->options_button;
    //                                                     do {
    //                                                       iVar18 = create_check_box(this,this->
    //                                                   bottom_panel,ppTVar13);
    //                                                   if (iVar18 == 0) goto LAB_004b1a29;
    //                                                   iVar6 = iVar6 + 1;
    //                                                   ppTVar13 = ppTVar13 + 1;
    //                                                   } while (iVar6 < 1);
    //                     /* language.dll match for 0x7729: "If there is a check in the box, all
    //                        civilizations can research all technologies in the game and the special
    //                        attributes usually associated with each civilization are removed. Otherwise,
    //                        each civilization can research limited technology and has special
    //                        attributes." */
    //                                                   TPanel::set_help_info
    //                                                             ((TPanel *)this->options_button[0],
    //                                                              0x7729,-1);
    //                                                   iVar6 = create_drop_down(this,this->bottom_panel,
    //                                                                            &this->
    //                                                   options_player_list);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x772b: "Select the player to customize." */
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)this->options_player_list,
    //                                                                0x772b,-1);
    //                                                     iVar6 = 0;
    //                                                     ppTVar13 = this->options_disable_button;
    //                                                     do {
    //                                                       iVar18 = create_check_box(this,this->
    //                                                   bottom_panel,ppTVar13);
    //                                                   if (iVar18 == 0) goto LAB_004b1a29;
    //                                                   iVar6 = iVar6 + 1;
    //                                                   ppTVar13 = ppTVar13 + 1;
    //                                                   } while (iVar6 < 0x10);
    //                     /* language.dll match for 0x772c: "Click to prevent the player from building a
    //                        Granary and accessing any units/technology available from it." */
    //                                                   TPanel::set_help_info
    //                                                             ((TPanel *)
    //                                                              this->options_disable_button[0],0x772c,
    //                                                              -1);
    //                     /* language.dll match for 0x772d: "Click to prevent the player from building a
    //                        Storage Pit and accessing any units/technology available from it." */
    //                                                   TPanel::set_help_info
    //                                                             ((TPanel *)
    //                                                              this->options_disable_button[1],0x772d,
    //                                                              -1);
    //                     /* language.dll match for 0x772e: "Click to prevent the player from building a
    //                        Dock and accessing any units/technology available from it." */
    //                                                   TPanel::set_help_info
    //                                                             ((TPanel *)
    //                                                              this->options_disable_button[2],0x772e,
    //                                                              -1);
    //                     /* language.dll match for 0x772f: "Click to prevent the player from building a
    //                        Barracks and accessing any units/technology available from it." */
    //                                                   TPanel::set_help_info
    //                                                             ((TPanel *)
    //                                                              this->options_disable_button[3],0x772f,
    //                                                              -1);
    //                     /* language.dll match for 0x7730: "Click to prevent the player from building a
    //                        Market and accessing any units/technology available from it." */
    //                                                   TPanel::set_help_info
    //                                                             ((TPanel *)
    //                                                              this->options_disable_button[4],0x7730,
    //                                                              -1);
    //                     /* language.dll match for 0x7731: "Click to prevent the player from building an
    //                        Archery Range and accessing any units/technology available from it." */
    //                                                   TPanel::set_help_info
    //                                                             ((TPanel *)
    //                                                              this->options_disable_button[5],0x7731,
    //                                                              -1);
    //                     /* language.dll match for 0x7732: "Click to prevent the player from building a
    //                        Stable and accessing any units/technology available from it." */
    //                                                   TPanel::set_help_info
    //                                                             ((TPanel *)
    //                                                              this->options_disable_button[6],0x7732,
    //                                                              -1);
    //                     /* language.dll match for 0x7733: "Click to prevent the player from building a
    //                        Temple and accessing any units/technology available from it." */
    //                                                   TPanel::set_help_info
    //                                                             ((TPanel *)
    //                                                              this->options_disable_button[7],0x7733,
    //                                                              -1);
    //                     /* language.dll match for 0x7734: "Click to prevent the player from building a
    //                        Government Center and accessing any units/technology available from it." */
    //                                                   TPanel::set_help_info
    //                                                             ((TPanel *)
    //                                                              this->options_disable_button[8],0x7734,
    //                                                              -1);
    //                     /* language.dll match for 0x7735: "Click to prevent the player from building a
    //                        Siege Workshop and accessing any units/technology available from it." */
    //                                                   TPanel::set_help_info
    //                                                             ((TPanel *)
    //                                                              this->options_disable_button[9],0x7735,
    //                                                              -1);
    //                     /* language.dll match for 0x7736: "Click to prevent the player from building an
    //                        Academy and accessing any units/technology available from it." */
    //                                                   TPanel::set_help_info
    //                                                             ((TPanel *)
    //                                                              this->options_disable_button[10],0x7736
    //                                                              ,-1);
    //                     /* language.dll match for 0x7737: "Click to prevent the player from advancing to
    //                        the Tool Age." */
    //                                                   TPanel::set_help_info
    //                                                             ((TPanel *)
    //                                                              this->options_disable_button[0xb],
    //                                                              0x7737,-1);
    //                     /* language.dll match for 0x7738: "Click to prevent the player from advancing to
    //                        the Bronze Age." */
    //                                                   TPanel::set_help_info
    //                                                             ((TPanel *)
    //                                                              this->options_disable_button[0xc],
    //                                                              0x7738,-1);
    //                     /* language.dll match for 0x7739: "Click to prevent the player from advancing to
    //                        the Iron Age." */
    //                                                   TPanel::set_help_info
    //                                                             ((TPanel *)
    //                                                              this->options_disable_button[0xd],
    //                                                              0x7739,-1);
    //                     /* language.dll match for 0x773a: "Click to prevent the player from building a
    //                        Town Center and accessing any units/technology available from it." */
    //                                                   TPanel::set_help_info
    //                                                             ((TPanel *)
    //                                                              this->options_disable_button[0xe],
    //                                                              0x773a,-1);
    //                     /* language.dll match for 0x773b: "Click to prevent the player from building a
    //                        Wonder." */
    //                                                   TPanel::set_help_info
    //                                                             ((TPanel *)
    //                                                              this->options_disable_button[0xf],
    //                                                              0x773b,-1);
    //                     /* language.dll match for 0x32c9: "Granary" */
    //                                                   iVar6 = create_text(this,this->bottom_panel,
    //                                                                       this->options_disable_text,
    //                                                                       0x32c9);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x32ca: "Storage Pit" */
    //                                                     iVar6 = create_text(this,this->bottom_panel,
    //                                                                         this->options_disable_text +
    //                                                                         1,0x32ca);
    //                                                     if (iVar6 != 0) {
    //                     /* language.dll match for 0x32cb: "Dock" */
    //                                                       iVar6 = create_text(this,this->bottom_panel,
    //                                                                           this->options_disable_text
    //                                                                           + 2,0x32cb);
    //                                                       if (iVar6 != 0) {
    //                     /* language.dll match for 0x32cc: "Barracks" */
    //                                                         iVar6 = create_text(this,this->bottom_panel,
    //                                                                             this->
    //                                                   options_disable_text + 3,0x32cc);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x32cd: "Market" */
    //                                                     iVar6 = create_text(this,this->bottom_panel,
    //                                                                         this->options_disable_text +
    //                                                                         4,0x32cd);
    //                                                     if (iVar6 != 0) {
    //                     /* language.dll match for 0x32ce: "Archery" */
    //                                                       iVar6 = create_text(this,this->bottom_panel,
    //                                                                           this->options_disable_text
    //                                                                           + 5,0x32ce);
    //                                                       if (iVar6 != 0) {
    //                     /* language.dll match for 0x32cf: "Stable" */
    //                                                         iVar6 = create_text(this,this->bottom_panel,
    //                                                                             this->
    //                                                   options_disable_text + 6,0x32cf);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x32d0: "Temple" */
    //                                                     iVar6 = create_text(this,this->bottom_panel,
    //                                                                         this->options_disable_text +
    //                                                                         7,0x32d0);
    //                                                     if (iVar6 != 0) {
    //                     /* language.dll match for 0x32d1: "Govt Ctr" */
    //                                                       iVar6 = create_text(this,this->bottom_panel,
    //                                                                           this->options_disable_text
    //                                                                           + 8,0x32d1);
    //                                                       if (iVar6 != 0) {
    //                     /* language.dll match for 0x32d2: "Siege Wkshop" */
    //                                                         iVar6 = create_text(this,this->bottom_panel,
    //                                                                             this->
    //                                                   options_disable_text + 9,0x32d2);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x32d3: "Academy" */
    //                                                     iVar6 = create_text(this,this->bottom_panel,
    //                                                                         this->options_disable_text +
    //                                                                         10,0x32d3);
    //                                                     if (iVar6 != 0) {
    //                     /* language.dll match for 0x32d4: "Tool Age" */
    //                                                       iVar6 = create_text(this,this->bottom_panel,
    //                                                                           this->options_disable_text
    //                                                                           + 0xb,0x32d4);
    //                                                       if (iVar6 != 0) {
    //                     /* language.dll match for 0x32d5: "Bronze Age" */
    //                                                         iVar6 = create_text(this,this->bottom_panel,
    //                                                                             this->
    //                                                   options_disable_text + 0xc,0x32d5);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x32d6: "Iron Age" */
    //                                                     iVar6 = create_text(this,this->bottom_panel,
    //                                                                         this->options_disable_text +
    //                                                                         0xd,0x32d6);
    //                                                     if (iVar6 != 0) {
    //                     /* language.dll match for 0x32d8: "Town Center" */
    //                                                       iVar6 = create_text(this,this->bottom_panel,
    //                                                                           this->options_disable_text
    //                                                                           + 0xe,0x32d8);
    //                                                       if (iVar6 != 0) {
    //                     /* language.dll match for 0x32d9: "Wonder" */
    //                                                         iVar6 = create_text(this,this->bottom_panel,
    //                                                                             this->
    //                                                   options_disable_text + 0xf,0x32d9);
    //                                                   if (iVar6 != 0) {
    //                                                     iVar6 = 0;
    //                                                     ppTVar14 = this->Diplomacy_player_text;
    //                                                     do {
    //                                                       iVar6 = iVar6 + 1;
    //                                                       sprintf(str1 + 4,&s__d,iVar6);
    //                                                       iVar18 = create_text(this,this->bottom_panel,
    //                                                                            ppTVar14,str1 + 4);
    //                                                       if (iVar18 == 0) goto LAB_004b1a29;
    //                                                       ppTVar14 = ppTVar14 + 1;
    //                                                     } while (iVar6 < 8);
    //                                                     iVar6 = create_drop_down(this,this->bottom_panel
    //                                                                              ,&this->
    //                                                   Diplomacy_player_list);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x773d: "Select the player to customize." */
    //                                                     TPanel::set_help_info
    //                                                               ((TPanel *)this->Diplomacy_player_list
    //                                                                ,0x773d,-1);
    //                                                     ptr[0] = (TPanel *)this->Diplomacy_AlliedVictory
    //                                                     ;
    //                                                     iStack_1c8 = 0;
    //                                                     papTVar16 = this->Diplomacy_friend_box;
    //                                                     do {
    //                                                       iVar6 = create_radio_button(this,this->
    //                                                   bottom_panel,*papTVar16);
    //                                                   if (iVar6 == 0) goto LAB_004b1a29;
    //                     /* language.dll match for 0x773f: "Click to set the player's diplomatic stance
    //                        toward this player as Ally. The player's military units do not attack this
    //                        civilization." */
    //                                                   TPanel::set_help_info
    //                                                             ((TPanel *)(*papTVar16)[0],0x773f,-1);
    //                                                   ppTVar13 = *papTVar16 + 1;
    //                                                   iVar6 = create_radio_button(this,this->
    //                                                   bottom_panel,ppTVar13);
    //                                                   if (iVar6 == 0) goto LAB_004b1a29;
    //                     /* language.dll match for 0x7740: "Click to set the player's diplomatic stance
    //                        toward this player as Neutral. The player's military units attack buildings
    //                        and villagers when commanded, and automatically attack all military units in
    //                        their sight."
    //                        language.dll match for 0x7740: "Click to set the player's diplomatic stance
    //                        toward this player as Neutral. The player's military units attack all
    //                        buildings and military units (but not villagers) who enter their sight." */
    //                                                   TPanel::set_help_info
    //                                                             ((TPanel *)*ppTVar13,0x7740,-1);
    //                                                   ppTVar11 = *papTVar16 + 2;
    //                                                   iVar6 = create_radio_button(this,this->
    //                                                   bottom_panel,ppTVar11);
    //                                                   if (iVar6 == 0) goto LAB_004b1a29;
    //                     /* language.dll match for 0x7741: "Click to set the player's diplomatic stance
    //                        toward this player as Enemy. The player's military units (except Scout)
    //                        attack all buildings, military units, and villagers who enter their sight."
    //                         */
    //                                                   TPanel::set_help_info
    //                                                             ((TPanel *)*ppTVar11,0x7741,-1);
    //                                                   TButtonPanel::set_radio_info
    //                                                             ((*papTVar16)[0],*papTVar16,3);
    //                                                   TButtonPanel::set_radio_info
    //                                                             (*ppTVar13,*papTVar16,3);
    //                                                   TButtonPanel::set_radio_info
    //                                                             (*ppTVar11,*papTVar16,3);
    //                                                   TButtonPanel::set_radio_button(*ppTVar13);
    //                                                   iVar6 = create_check_box(this,this->bottom_panel,
    //                                                                            (TButtonPanel **)ptr[0]);
    //                                                   pTVar5 = ptr[0];
    //                                                   if (iVar6 == 0) goto LAB_004b1a29;
    //                     /* language.dll match for 0x773e: "Click to select whether allied players win
    //                        and lose as team. Any allied player who achieves the victory condition wins
    //                        the game for all allies. You must select Allied Victory for all allies." */
    //                                                   TPanel::set_help_info
    //                                                             ((TPanel *)ptr[0]->_padding_,0x773e,-1);
    //                                                   ptr[0] = (TPanel *)&pTVar5->previousPanelValue;
    //                                                   iStack_1c8 = iStack_1c8 + 1;
    //                                                   papTVar16 = papTVar16 + 1;
    //                                                   } while (iStack_1c8 < 8);
    //                     /* language.dll match for 0x29cd: "Ally" */
    //                                                   iVar6 = create_text(this,this->bottom_panel,
    //                                                                       this->Diplomacy_status_label,
    //                                                                       0x29cd);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x29ce: "Neutral" */
    //                                                     iVar6 = create_text(this,this->bottom_panel,
    //                                                                         this->Diplomacy_status_label
    //                                                                         + 1,0x29ce);
    //                                                     if (iVar6 != 0) {
    //                     /* language.dll match for 0x29cf: "Enemy" */
    //                                                       iVar6 = create_text(this,this->bottom_panel,
    //                                                                           this->
    //                                                   Diplomacy_status_label + 2,0x29cf);
    //                                                   if (iVar6 != 0) {
    //                     /* language.dll match for 0x29d0: "Allied Victory" */
    //                                                     create_text(this,this->bottom_panel,
    //                                                                 this->Diplomacy_status_label + 3,
    //                                                                 0x29d0);
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   goto LAB_004b1a29;
    //                                                   }
    //                                                   }
    //                                                   }
    // LAB_004b1a1f:
    //                                                   this->_padding_ = 1;
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                   }
    //                                                 }
    //                                               }
    //                                             }
    //                                           }
    //                                         }
    //                                       }
    //                                     }
    //                                   }
    //                                 }
    //                               }
    //                             }
    //                           }
    //                         }
    //                       }
    //                     }
    //                   }
    //                 }
    //               }
    //             }
    //           }
    //         }
    //       }
    //     }
    //   }
    // LAB_004b1a29:
    //   *unaff_FS_OFFSET = local_c;
    //   return;
    // }
    // 
    // 
}

// Offset: 0x004B1A50
static void position_panels(TRIBE_Screen_Sed* this_) {
    // --- Ghidra decompiler output ---
    // 
    // /* public: void __thiscall TRIBE_Screen_Sed::position_panels(void) */
    // 
    // void __thiscall TRIBE_Screen_Sed::position_panels(TRIBE_Screen_Sed *this)
    // 
    // {
    //   TButtonPanel *pTVar1;
    //   int iVar2;
    //   uint uVar3;
    //   TEditPanel **ppTVar4;
    //   TButtonPanel **ppTVar5;
    //   TDropDownPanel **ppTVar6;
    //   TTextPanel **ppTVar7;
    //   TButtonPanel **ppTVar8;
    //   int iVar9;
    //   TScrollBarPanel *this_00;
    //   uint uVar10;
    //   
    //   if (this->main_view != (TRIBE_Main_View *)0x0) {
    //     iVar9 = 0;
    //     do {
    //       if (iVar9 == 0) {
    //         pTVar1 = (TButtonPanel *)0x0;
    //       }
    //       else {
    //         pTVar1 = this->scenario_mode_button[iVar9 + -1];
    //       }
    //       (**(code **)(this->scenario_mode_button[iVar9]->_padding_ + 0x18))
    //                 (7,2,2,2,2,0x32,0x6d,0x16,0x16,pTVar1,0,0,0);
    //       iVar9 = iVar9 + 1;
    //     } while (iVar9 < 5);
    //     iVar9 = 5;
    //     do {
    //       if (iVar9 == 5) {
    //         pTVar1 = (TButtonPanel *)0x0;
    //       }
    //       else {
    //         pTVar1 = this->scenario_mode_button[iVar9 + -1];
    //       }
    //       (**(code **)(this->scenario_mode_button[iVar9]->_padding_ + 0x18))
    //                 (7,2,2,2,2,0x32,0x6d,0x16,0x16,pTVar1,this->scenario_mode_button[iVar9 + -5],0,0);
    //       iVar9 = iVar9 + 1;
    //     } while (iVar9 < 10);
    //     (**(code **)(this->menu_button->_padding_ + 0x18))(9,2,5,3,3,0x3a,0x3a,0x14,0x28,0,0,0,0);
    //     (**(code **)(this->help_button->_padding_ + 0x18))(10,5,5,5,5,0x14,0x1e,0x14,0x1e,0,0,0,0);
    //     (**(code **)(*(int *)this->map_view + 0x18))(10,0,0,0,0,0xe6,0xe6,0x87,0x87,0,0,0,0);
    //     (**(code **)(this->bottom_panel->_padding_ + 0x18))
    //               (8,2,2,2,2,0,0,0x89,0x89,0,0,this->map_view,0);
    //                     /* language.dll match for 0x7c: "B" */
    //     (**(code **)(this->unit_list->_padding_ + 0x18))
    //               (7,0,6,0,4,0x7c,200,0,0,0,this->menu_button,0,this->bottom_panel);
    //     (**(code **)(this->object_panel->_padding_ + 0x18))(8,4,4,4,4,0x96,0x96,0x6c,0x6c,0,0,0,0);
    //     this_00 = (TScrollBarPanel *)this->unit_list;
    //     iVar9 = TTextPanel::numberLines((TTextPanel *)this_00);
    //     iVar2 = TTextPanel::numberDrawLines((TTextPanel *)this_00);
    //     if (iVar2 < iVar9) {
    //                     /* language.dll match for 0x68: "Arial" */
    //       (**(code **)(this->unit_list->_padding_ + 0x18))
    //                 (7,0,6,0,4,0x68,0xdc,0,0,0,this->menu_button,0,this->bottom_panel);
    //       (**(code **)(this->unit_scrollbar->_padding_ + 0x18))
    //                 (7,1,1,0,2,0x12,0x12,0,0,this->unit_list,this->menu_button,0,this->bottom_panel);
    //       this_00 = this->unit_scrollbar;
    //     }
    //     (**(code **)(*(int *)this->main_view + 0x18))
    //               (7,0,6,0,4,0,0,0,0,this_00,this->menu_button,0,this->bottom_panel);
    //     (**(code **)(this->message_panel->_padding_ + 0x18))(8,4,4,4,4,0,0,0x18,0x18,0,0,0,0);
    //                     /* language.dll match for 0x78: "10" */
    //     (**(code **)(this->map_type_label->_padding_ + 0x1c))(4,4,0x78,0x16);
    //     (**(code **)(this->map_type_button[0]->_padding_ + 0x1c))(4,0x16,0x16,0x16);
    //     (**(code **)(this->map_type_button[1]->_padding_ + 0x1c))(4,0x2c,0x16,0x16);
    //     (**(code **)(this->map_type_button[2]->_padding_ + 0x1c))(4,0x42,0x16,0x16);
    //                     /* language.dll match for 0x73: "B" */
    //     (**(code **)(this->map_type_text[0]->_padding_ + 0x1c))(0x24,0x16,0x73,0x16);
    //                     /* language.dll match for 0x73: "B" */
    //     (**(code **)(this->map_type_text[1]->_padding_ + 0x1c))(0x24,0x2c,0x73,0x16);
    //                     /* language.dll match for 0x73: "B" */
    //     (**(code **)(this->map_type_text[2]->_padding_ + 0x1c))(0x24,0x42,0x73,0x16);
    //                     /* language.dll match for 0x82: "B" */
    //     (**(code **)(this->map_size_label->_padding_ + 0x1c))(0xaa,4,0x82,0x16);
    //     (**(code **)(this->map_size_drop->_padding_ + 0x1c))(0xaa,0x16,0xaa,0x16);
    //                     /* language.dll match for 0x82: "B" */
    //     (**(code **)(this->map_style_label->_padding_ + 0x1c))(0xaa,0x30,0x82,0x16);
    //     (**(code **)(this->map_style_drop->_padding_ + 0x1c))(0xaa,0x42,0xaa,0x16);
    //                     /* language.dll match for 0x82: "B" */
    //     (**(code **)(this->default_terrain_label->_padding_ + 0x1c))(0xaa,0x30,0x82,0x16);
    //     (**(code **)(this->default_terrain_drop->_padding_ + 0x1c))(0xaa,0x42,0xaa,0x16);
    //                     /* language.dll match for 0x78: "10" */
    //     (**(code **)(this->random_seed_label->_padding_ + 0x1c))(0x24,0x5a,0x78,0x16);
    //                     /* language.dll match for 0x70: "B" */
    //     (**(code **)(this->random_seed_input->_padding_ + 0x1c))(0x24,0x70,0x37,0x16);
    //                     /* language.dll match for 0x78: "10" */
    //     (**(code **)(this->random_seed_used_label->_padding_ + 0x1c))(0x24,0x5a,0x78,0x16);
    //                     /* language.dll match for 0x70: "B" */
    //     (**(code **)(this->random_seed_used_text->_padding_ + 0x1c))(0x24,0x70,0x37,0x16);
    //                     /* language.dll match for 0x82: "B" */
    //     (**(code **)(this->generate_map_button->_padding_ + 0x1c))(0xb4,0x60,0x82,0x26);
    //                     /* language.dll match for 0x73: "B" */
    //     (**(code **)(this->paint_terrain_list->_padding_ + 0x1c))(0x73,0x17,0xa5,0x6e);
    //                     /* language.dll match for 0x73: "B" */
    //     (**(code **)(this->paint_terrain_label->_padding_ + 0x1c))(0x73,1,0x3c,0x16);
    //                     /* language.dll match for 0x73: "B" */
    //     (**(code **)(this->paint_elevation_list->_padding_ + 0x1c))(0x73,0x17,0xa5,0x6e);
    //                     /* language.dll match for 0x6e: "Copperplate Gothic Light" */
    //     (**(code **)(this->paint_type_label->_padding_ + 0x1c))(2,1,0x6e,0x14);
    //     (**(code **)(this->paint_type_button[0]->_padding_ + 0x1c))(2,0x17,0x1e,0x16);
    //     (**(code **)(this->paint_type_button[1]->_padding_ + 0x1c))(2,0x2d,0x1e,0x16);
    //     (**(code **)(this->paint_type_button[2]->_padding_ + 0x1c))(2,0x43,0x1e,0x16);
    //     (**(code **)(this->paint_type_button_label[0]->_padding_ + 0x1c))(0x21,0x17,0x51,0x16);
    //     (**(code **)(this->paint_type_button_label[1]->_padding_ + 0x1c))(0x21,0x2d,0x51,0x16);
    //     (**(code **)(this->paint_type_button_label[2]->_padding_ + 0x1c))(0x21,0x43,0x51,0x16);
    //                     /* language.dll match for 0x6e: "Copperplate Gothic Light" */
    //     (**(code **)(this->brush_size_label->_padding_ + 0x1c))(0x118,4,0x6e,0x14);
    //     (**(code **)(this->brush_size_button[0]->_padding_ + 0x1c))(0x11a,0x17,0x1e,0x16);
    //     (**(code **)(this->brush_size_button[1]->_padding_ + 0x1c))(0x11a,0x2d,0x1e,0x16);
    //     (**(code **)(this->brush_size_button[2]->_padding_ + 0x1c))(0x11a,0x43,0x1e,0x16);
    //     (**(code **)(this->brush_size_button[3]->_padding_ + 0x1c))(0x11a,0x59,0x1e,0x16);
    //                     /* language.dll match for 0x6f: "12" */
    //     (**(code **)(this->brush_size_button[4]->_padding_ + 0x1c))(0x11a,0x6f,0x1e,0x16);
    //     (**(code **)(this->brush_size_button_label[0]->_padding_ + 0x1c))(0x139,0x17,0x5a,0x16);
    //     (**(code **)(this->brush_size_button_label[1]->_padding_ + 0x1c))(0x139,0x2d,0x5a,0x16);
    //     (**(code **)(this->brush_size_button_label[2]->_padding_ + 0x1c))(0x139,0x43,0x5a,0x16);
    //     (**(code **)(this->brush_size_button_label[3]->_padding_ + 0x1c))(0x139,0x59,0x5a,0x16);
    //                     /* language.dll match for 0x6f: "12" */
    //     (**(code **)(this->brush_size_button_label[4]->_padding_ + 0x1c))(0x139,0x6f,0x5a,0x16);
    //     (**(code **)(this->player_label->_padding_ + 0x1c))(4,4,0x50,0x12);
    //     (**(code **)(this->player_starting_age_label->_padding_ + 0x1c))(4,0x5c,0x5f,0x12);
    //                     /* language.dll match for 0x6e: "Copperplate Gothic Light" */
    //     (**(code **)(this->player_advance_civilization_drop->_padding_ + 0x1c))(4,0x6e,0x96,0x16);
    //     (**(code **)(this->player_label->_padding_ + 0x1c))(4,0x2a,0x96,0x12);
    //     (**(code **)(this->player_list->_padding_ + 0x1c))(4,7,0x96,0x16);
    //     (**(code **)(this->player_number_list->_padding_ + 0x1c))(4,0x3e,0x96,0x16);
    //     iVar9 = 0xa6;
    //     ppTVar4 = this->player_inven_input;
    //     do {
    //       iVar2 = 0x19;
    //       do {
    //         (**(code **)(((TTextPanel *)ppTVar4[-5])->_padding_ + 0x1c))(iVar9,iVar2 + -0x12,0x37,0x12);
    //         (**(code **)((*ppTVar4)->_padding_ + 0x1c))(iVar9,iVar2,0x37,0x16);
    //         iVar2 = iVar2 + 0x2c;
    //         ppTVar4 = ppTVar4 + 1;
    //       } while (iVar2 < 0x71);
    //       iVar9 = iVar9 + 0x44;
    //     } while (iVar9 < 0x12e);
    //     (**(code **)(this->player_inven_label[4]->_padding_ + 0x1c))(0xa6,0x5c,100,0x12);
    //                     /* language.dll match for 0x6e: "Copperplate Gothic Light" */
    //     (**(code **)(this->player_inven_input[4]->_padding_ + 0x1c))(0xa6,0x6e,0x7d,0x16);
    //     iVar9 = 0x19;
    //     ppTVar6 = this->player_setting_drop;
    //     do {
    //                     /* language.dll match for 0x82: "B" */
    //       (**(code **)(((TTextPanel *)ppTVar6[-3])->_padding_ + 0x1c))(500,iVar9 + -0x12,0x82,0x12);
    //                     /* language.dll match for 0x82: "B" */
    //       (**(code **)((*ppTVar6)->_padding_ + 0x1c))(500,iVar9,0x82,0x16);
    //       iVar9 = iVar9 + 0x2c;
    //       ppTVar6 = ppTVar6 + 1;
    //     } while (iVar9 < 0x71);
    //     (**(code **)(this->BuildList->_padding_ + 0x1c))(300,0x45,0xbe,0x16);
    //     (**(code **)(this->CityLayout->_padding_ + 0x1c))(300,0x19,0xbe,0x16);
    //                     /* language.dll match for 0x82: "B" */
    //     (**(code **)(this->player_build_text->_padding_ + 0x1c))(300,0x33,0x82,0x12);
    //                     /* language.dll match for 0x82: "B" */
    //     (**(code **)(this->player_city_text->_padding_ + 0x1c))(300,7,0x82,0x12);
    //                     /* language.dll match for 0x82: "B" */
    //     (**(code **)(this->AiRules_text->_padding_ + 0x1c))(300,0x5c,0x82,0x12);
    //                     /* language.dll match for 0x6e: "Copperplate Gothic Light" */
    //     (**(code **)(this->AiRules->_padding_ + 0x1c))(300,0x6e,0xbe,0x16);
    //     (**(code **)(this->unit_player_list->_padding_ + 0x1c))(4,4,0x96,0x16);
    //     (**(code **)(this->unit_mode_select[0]->_padding_ + 0x1c))(0xa0,0x16,0x1e,0x16);
    //     (**(code **)(this->unit_mode_select[1]->_padding_ + 0x1c))(0xa0,0x30,0x1e,0x16);
    //     (**(code **)(this->unit_mode_select[2]->_padding_ + 0x1c))(0xa0,0x4a,0x1e,0x16);
    //     (**(code **)(this->unit_mode_select[3]->_padding_ + 0x1c))(0xa0,0x62,0x1e,0x16);
    //                     /* language.dll match for 0x6e: "Copperplate Gothic Light" */
    //     (**(code **)(this->unit_mode_select_label[0]->_padding_ + 0x1c))(0xc0,0x16,0x6e,0x16);
    //                     /* language.dll match for 0x6e: "Copperplate Gothic Light" */
    //     (**(code **)(this->unit_mode_select_label[1]->_padding_ + 0x1c))(0xc0,0x30,0x6e,0x16);
    //                     /* language.dll match for 0x6e: "Copperplate Gothic Light" */
    //     (**(code **)(this->unit_mode_select_label[2]->_padding_ + 0x1c))(0xc0,0x4a,0x6e,0x16);
    //                     /* language.dll match for 0x6e: "Copperplate Gothic Light" */
    //     (**(code **)(this->unit_mode_select_label[3]->_padding_ + 0x1c))(0xc0,0x62,0x6e,0x16);
    //                     /* language.dll match for 0x78: "10" */
    //     (**(code **)(this->victory_condition_label->_padding_ + 0x1c))(0x22,0,0x78,0x12);
    //     (**(code **)(this->victory_cond_type[0]->_padding_ + 0x1c))(0xe,0x12,0x14,0x12);
    //     (**(code **)(this->victory_cond_type[1]->_padding_ + 0x1c))(0xe,0x26,0x14,0x12);
    //     (**(code **)(this->victory_cond_type[2]->_padding_ + 0x1c))(0xe,0x3a,0x14,0x12);
    //     (**(code **)(this->victory_cond_type[3]->_padding_ + 0x1c))(0xe,0x4e,0x14,0x12);
    //     (**(code **)(this->victory_cond_type[4]->_padding_ + 0x1c))(0xe,0x62,0x14,0x12);
    //                     /* language.dll match for 0x78: "10" */
    //     (**(code **)(this->victory_cond_type_label[0]->_padding_ + 0x1c))(0x22,0x12,0x78,0x12);
    //                     /* language.dll match for 0x78: "10" */
    //     (**(code **)(this->victory_cond_type_label[1]->_padding_ + 0x1c))(0x22,0x26,0x78,0x12);
    //                     /* language.dll match for 0x78: "10" */
    //     (**(code **)(this->victory_cond_type_label[2]->_padding_ + 0x1c))(0x22,0x3a,0x78,0x12);
    //                     /* language.dll match for 0x78: "10" */
    //     (**(code **)(this->victory_cond_type_label[3]->_padding_ + 0x1c))(0x22,0x4e,0x78,0x12);
    //                     /* language.dll match for 0x78: "10" */
    //     (**(code **)(this->victory_cond_type_label[4]->_padding_ + 0x1c))(0x22,0x62,0x78,0x12);
    //     (**(code **)(this->victory_score_label->_padding_ + 0x1c))(0xa4,0x12,100,0x12);
    //     (**(code **)(this->victory_score->_padding_ + 0x1c))(0xa4,0x28,100,0x16);
    //     (**(code **)(this->victory_time_label->_padding_ + 0x1c))(0xa4,0x12,0xdc,0x12);
    //     (**(code **)(this->victory_time->_padding_ + 0x1c))(0xa4,0x28,0xdc,0x16);
    //     (**(code **)(this->victory_cond_on[0]->_padding_ + 0x1c))(0xa4,0x12,0x14,0x12);
    //     (**(code **)(this->victory_cond_on[1]->_padding_ + 0x1c))(0xa4,0x26,0x14,0x12);
    //     (**(code **)(this->victory_cond_on[2]->_padding_ + 0x1c))(0xa4,0x3a,0x14,0x12);
    //     (**(code **)(this->victory_cond_on[3]->_padding_ + 0x1c))(0xa4,0x4e,0x14,0x12);
    //     (**(code **)(this->victory_cond_on[4]->_padding_ + 0x1c))(0xa4,0x62,0x14,0x12);
    //                     /* language.dll match for 0x76: "B" */
    //     (**(code **)(this->victory_cond_on[5]->_padding_ + 0x1c))(0xa4,0x76,0x14,0x12);
    //                     /* language.dll match for 0x82: "B" */
    //     (**(code **)(this->victory_label_conquest->_padding_ + 0x1c))(0xb8,0x12,0x82,0x12);
    //                     /* language.dll match for 0x82: "B" */
    //     (**(code **)(this->victory_label_explore->_padding_ + 0x1c))(0xb8,0x26,0x82,0x12);
    //                     /* language.dll match for 0x82: "B" */
    //     (**(code **)(this->victory_label_ruins->_padding_ + 0x1c))(0xb8,0x3a,0x82,0x12);
    //                     /* language.dll match for 0x82: "B" */
    //     (**(code **)(this->victory_label_artifacts->_padding_ + 0x1c))(0xb8,0x4e,0x82,0x12);
    //                     /* language.dll match for 0x82: "B" */
    //     (**(code **)(this->victory_label_discoveries->_padding_ + 0x1c))(0xb8,0x62,0x82,0x12);
    //     (**(code **)(this->victory_amount_label->_padding_ + 0x1c))(0x126,0,0x5a,0x12);
    //     (**(code **)(this->victory_condition_explore->_padding_ + 0x1c))(0x126,0x26,0x3c,0x12);
    //     (**(code **)(this->victory_condition_ruins->_padding_ + 0x1c))(0x126,0x3a,0x3c,0x12);
    //     (**(code **)(this->victory_condition_artifacts->_padding_ + 0x1c))(0x126,0x4e,0x3c,0x12);
    //     (**(code **)(this->victory_condition_discoveries->_padding_ + 0x1c))(0x126,0x62,0x3c,0x12);
    //     (**(code **)(this->victory_and_or[0]->_padding_ + 0x1c))(0x180,0x12,0x14,0x12);
    //     (**(code **)(this->victory_and_or[1]->_padding_ + 0x1c))(0x180,0x26,0x14,0x12);
    //     (**(code **)(this->victory_text_and_or[0]->_padding_ + 0x1c))(0x194,0x12,0x5a,0x12);
    //     (**(code **)(this->victory_text_and_or[1]->_padding_ + 0x1c))(0x194,0x26,0x5a,0x12);
    //     uVar10 = 0;
    //     ppTVar5 = this->victory_button;
    //     do {
    //       uVar3 = (int)uVar10 >> 0x1f;
    //       (**(code **)((*ppTVar5)->_padding_ + 0x1c))
    //                 (((int)(uVar10 + (uVar3 & 3)) >> 2) * 0x30 + 0xdc,
    //                  (((uVar10 ^ uVar3) - uVar3 & 3 ^ uVar3) - uVar3) * 0x1a + 0x1e,0x2c,0x16);
    //       uVar10 = uVar10 + 1;
    //       ppTVar5 = ppTVar5 + 1;
    //     } while ((int)uVar10 < 0xc);
    //     (**(code **)(this->victory_player_list->_padding_ + 0x1c))(4,4,0x96,0x16);
    //     (**(code **)(this->victory_drop_down->_padding_ + 0x1c))(4,0x1c,0xb4,0x16);
    //     (**(code **)(this->victory_condition_text->_padding_ + 0x1c))(0xdc,4,0x8c,0x16);
    //     (**(code **)(this->victory_button_set_object->_padding_ + 0x1c))(4,0x38,0x96,0x16);
    //     (**(code **)(this->victory_button_set_destination->_padding_ + 0x1c))(4,0x52,0x96,0x16);
    //     (**(code **)(this->victory_button_go_to_dest->_padding_ + 0x1c))(4,0x6c,0x96,0x16);
    //     (**(code **)(this->victory_amount_text->_padding_ + 0x1c))(0xa0,0x50,0x3c,0x16);
    //                     /* language.dll match for 0x66: "Copperplate Gothic Light" */
    //     (**(code **)(this->victory_amount_input->_padding_ + 0x1c))(0xa0,0x66,0x32,0x16);
    //                     /* language.dll match for 0x66: "Copperplate Gothic Light" */
    //     (**(code **)(this->victory_enemy_player_list->_padding_ + 0x1c))(4,0x66,0x96,0x16);
    //     (**(code **)(this->victory_attribute_list->_padding_ + 0x1c))(4,0x38,0xb4,0x16);
    //     (**(code **)(this->victory_which_enemy_text->_padding_ + 0x1c))(4,0x50,0x96,0x16);
    //     (**(code **)(this->victory_object_list->_padding_ + 0x1c))(4,0x38,0xb4,0x16);
    //     (**(code **)(this->victory_ages_list->_padding_ + 0x1c))(4,0x38,0xb4,0x16);
    //     (**(code **)(this->victory_tech_list->_padding_ + 0x1c))(4,0x38,0xb4,0x16);
    //     iVar9 = 8;
    //     ppTVar7 = this->message_button_label;
    //     do {
    //       (**(code **)(((TButtonPanel *)ppTVar7[-5])->_padding_ + 0x1c))(4,iVar9,0x1e,0x12);
    //                     /* language.dll match for 0x82: "B" */
    //       (**(code **)((*ppTVar7)->_padding_ + 0x1c))(0x24,iVar9,0x82,0x12);
    //       iVar9 = iVar9 + 0x19;
    //       ppTVar7 = ppTVar7 + 1;
    //     } while (iVar9 < 0x85);
    //     (**(code **)(this->message_input->_padding_ + 0x18))(7,0xaf,4,0x28,4,0,0,0,0,0,0,0,0);
    //     iVar9 = 0x16;
    //     ppTVar6 = this->cinematic_input;
    //     do {
    //       (**(code **)(((TTextPanel *)ppTVar6[-4])->_padding_ + 0x1c))(4,iVar9 + -0x12,0xaa,0x12);
    //       (**(code **)((*ppTVar6)->_padding_ + 0x1c))(4,iVar9,0xaa,0x16);
    //       iVar9 = iVar9 + 0x2c;
    //       ppTVar6 = ppTVar6 + 1;
    //     } while (iVar9 < 0x9a);
    //     (**(code **)(this->cinematic_label[3]->_padding_ + 0x1c))(0xb2,4,0xaa,0x12);
    //     (**(code **)(this->cinematic_input[3]->_padding_ + 0x1c))(0xb2,0x16,0xaa,0x16);
    //     iVar9 = 0x2c;
    //     ppTVar5 = (TButtonPanel **)this->options_label;
    //     do {
    //       (**(code **)(ppTVar5[1]->_padding_ + 0x1c))(3,iVar9,0x14,0x14);
    //       (**(code **)((*ppTVar5)->_padding_ + 0x1c))(0x16,iVar9,0x87,0x14);
    //       iVar9 = iVar9 + 0x1a;
    //       ppTVar5 = ppTVar5 + 1;
    //     } while (iVar9 < 0x46);
    //     (**(code **)(this->options_disable_tech_text->_padding_ + 0x1c))(0xa0,3,0xa0,0x16);
    //     (**(code **)(this->options_player_list->_padding_ + 0x1c))(3,3,0x96,0x16);
    //     ppTVar7 = this->options_disable_text;
    //     iVar9 = 0x1a;
    //     do {
    //       (**(code **)(((TButtonPanel *)ppTVar7[-0x10])->_padding_ + 0x1c))(0xa0,iVar9,0x14,0x14);
    //       (**(code **)((*ppTVar7)->_padding_ + 0x1c))(0xb4,iVar9,0x87,0x14);
    //       iVar9 = iVar9 + 0x14;
    //       ppTVar7 = ppTVar7 + 1;
    //     } while (iVar9 < 0x7e);
    //     ppTVar7 = this->options_disable_text + 5;
    //     iVar9 = 0x1a;
    //     do {
    //       (**(code **)(((TButtonPanel *)ppTVar7[-0x10])->_padding_ + 0x1c))(0x13b,iVar9,0x14,0x14);
    //       (**(code **)((*ppTVar7)->_padding_ + 0x1c))(0x14f,iVar9,0x87,0x14);
    //       iVar9 = iVar9 + 0x14;
    //       ppTVar7 = ppTVar7 + 1;
    //     } while (iVar9 < 0x7e);
    //     ppTVar7 = this->options_disable_text + 10;
    //     iVar9 = 6;
    //     do {
    //       (**(code **)(((TButtonPanel *)ppTVar7[-0x10])->_padding_ + 0x1c))(0x1d6,iVar9,0x14,0x14);
    //       (**(code **)((*ppTVar7)->_padding_ + 0x1c))(0x1ea,iVar9,0x87,0x14);
    //       iVar9 = iVar9 + 0x14;
    //       ppTVar7 = ppTVar7 + 1;
    //     } while (iVar9 < 0x7e);
    //     (**(code **)(this->Diplomacy_player_list->_padding_ + 0x1c))(4,4,0x96,0x16);
    //     iVar9 = 0x96;
    //     ppTVar5 = this->Diplomacy_AlliedVictory;
    //     ppTVar8 = this->Diplomacy_friend_box[0] + 1;
    //     do {
    //       (**(code **)(((TTextPanel *)ppTVar5[-0x25])->_padding_ + 0x1c))(iVar9,0x1c,0x1e,0x16);
    //       (**(code **)((*(TButtonPanel *(*) [3])(ppTVar8 + -1))[0]->_padding_ + 0x1c))
    //                 (iVar9,0x34,0x1a,0x12);
    //       (**(code **)((*ppTVar8)->_padding_ + 0x1c))(iVar9,0x48,0x1a,0x12);
    //       (**(code **)(ppTVar8[1]->_padding_ + 0x1c))(iVar9,0x5c,0x1a,0x12);
    //                     /* language.dll match for 0x70: "B" */
    //       (**(code **)((*ppTVar5)->_padding_ + 0x1c))(iVar9,0x70,0x1a,0x12);
    //       iVar9 = iVar9 + 0x1f;
    //       ppTVar5 = ppTVar5 + 1;
    //       ppTVar8 = ppTVar8 + 3;
    //     } while (iVar9 < 0x18e);
    //     (**(code **)(this->Diplomacy_status_label[0]->_padding_ + 0x1c))(2,0x34,0x91,0x16);
    //     (**(code **)(this->Diplomacy_status_label[1]->_padding_ + 0x1c))(2,0x48,0x91,0x16);
    //     (**(code **)(this->Diplomacy_status_label[2]->_padding_ + 0x1c))(2,0x5c,0x91,0x16);
    //                     /* language.dll match for 0x70: "B" */
    //     (**(code **)(this->Diplomacy_status_label[3]->_padding_ + 0x1c))(2,0x70,0x91,0x16);
    //   }
    //   return;
    // }
    // 
    // 
}

// Offset: 0x004B29E0
void activate_victory_panel(TRIBE_Screen_Sed* this_, int param_2) {
    // --- Ghidra decompiler output ---
    // 
    // /* protected: void __thiscall TRIBE_Screen_Sed::activate_victory_panel(int) */
    // 
    // void __thiscall TRIBE_Screen_Sed::activate_victory_panel(TRIBE_Screen_Sed *this,int param_1)
    // 
    // {
    //   int iVar1;
    //   long lVar2;
    //   TButtonPanel **ppTVar3;
    //   int iVar4;
    //   
    //   iVar4 = 0;
    //   ppTVar3 = this->victory_button;
    //   do {
    //     (**(code **)((*ppTVar3)->_padding_ + 0x14))(param_1);
    //     iVar1 = T_Scenario::GetSPVictoryType((T_Scenario *)this->world->_padding_,iVar4);
    //     if (param_1 != 0) {
    //       (**(code **)((*ppTVar3)->_padding_ + 0xe0))
    //                 ((-(iVar1 != 0) & 2U) + (this->CurrentVictory == iVar4));
    //     }
    //     iVar4 = iVar4 + 1;
    //     ppTVar3 = ppTVar3 + 1;
    //   } while (iVar4 < 0xc);
    //   (**(code **)(this->victory_drop_down->_padding_ + 0x14))(param_1);
    //   (**(code **)(this->victory_condition_text->_padding_ + 0x14))(param_1);
    //   (**(code **)(this->victory_player_list->_padding_ + 0x14))(param_1);
    //   if (param_1 != 0) {
    //     TDropDownPanel::set_line(this->victory_player_list,this->player_num + -1);
    //     return;
    //   }
    //   lVar2 = TDropDownPanel::get_line(this->victory_player_list);
    //   this->player_num = (short)lVar2 + 1;
    //   return;
    // }
    // 
    // 
}

// Offset: 0x004B2AA0
int MakeFileList(TRIBE_Screen_Sed* this_, TDropDownPanel* param_2, char* param_3, char* param_4, uchar param_5, uchar param_6) {
    // --- Ghidra decompiler output ---
    // 
    // /* WARNING: Variable defined which should be unmapped: count */
    // /* protected: int __thiscall TRIBE_Screen_Sed::MakeFileList(class TDropDownPanel *,char *,char
    //    *,unsigned char,unsigned char) */
    // 
    // int __thiscall
    // TRIBE_Screen_Sed::MakeFileList
    //           (TRIBE_Screen_Sed *this,TDropDownPanel *param_1,char *param_2,char *param_3,uchar param_4,
    //           uchar param_5)
    // 
    // {
    //   char cVar1;
    //   int iVar2;
    //   uint uVar3;
    //   int iVar4;
    //   char *pcVar5;
    //   int count;
    //   int extension_strlen;
    //   _finddata_t fileInfo;
    //   char file_name [260];
    //   char path [260];
    //   
    //   extension_strlen = 0;
    //   TDropDownPanel::empty_list(param_1);
    //   if (param_4 != '\0') {
    //                     /* language.dll match for 0x2775: " <None> " */
    //     TDropDownPanel::append_line(param_1,0x2775,0);
    //   }
    //   if (param_5 != '\0') {
    //                     /* language.dll match for 0x277b: "Random" */
    //     TDropDownPanel::append_line(param_1,0x277b,0);
    //   }
    //   sprintf(path + 4,s__s__s,param_2,param_3);
    //   iVar2 = __findfirst(path + 4,&fileInfo.time_create);
    //   uVar3 = 0xffffffff;
    //   do {
    //     if (uVar3 == 0) break;
    //     uVar3 = uVar3 - 1;
    //     cVar1 = *param_3;
    //     param_3 = param_3 + 1;
    //   } while (cVar1 != '\0');
    //   fileInfo.attrib = ~uVar3 - 1;
    //   iVar4 = iVar2;
    //   do {
    //     if (iVar4 == -1) {
    //       return extension_strlen;
    //     }
    //     uVar3 = 0xffffffff;
    //     extension_strlen = extension_strlen + 1;
    //     pcVar5 = fileInfo.name + 4;
    //     do {
    //       if (uVar3 == 0) break;
    //       uVar3 = uVar3 - 1;
    //       cVar1 = *pcVar5;
    //       pcVar5 = pcVar5 + 1;
    //     } while (cVar1 != '\0');
    //     iVar4 = (~uVar3 - 1) - fileInfo.attrib;
    //     strncpy(file_name + 4,fileInfo.name + 4,iVar4);
    //     file_name[iVar4 + 4] = '\0';
    //     TDropDownPanel::append_line(param_1,file_name + 4,0);
    //     iVar4 = __findnext(iVar2,&fileInfo.time_create);
    //   } while( true );
    // }
    // 
    // 
    // TODO: Full transliteration pending. Source of truth: scr_sed2.cpp.decomp @ 0x004B2AA0
    return 0;
}

// Offset: 0x004B2BC0
int Set_player_advance_civilization_text(TRIBE_Screen_Sed* this_, int param_2) {
    // --- Ghidra decompiler output ---
    // 
    // /* protected: int __thiscall TRIBE_Screen_Sed::Set_player_advance_civilization_text(int) */
    // 
    // int __thiscall
    // TRIBE_Screen_Sed::Set_player_advance_civilization_text(TRIBE_Screen_Sed *this,int param_1)
    // 
    // {
    //   TDropDownPanel::empty_list(this->player_advance_civilization_drop);
    //                     /* language.dll match for 0x1069: "Stone Age" */
    //   TDropDownPanel::append_line(this->player_advance_civilization_drop,0x1069,0);
    //                     /* language.dll match for 0x106a: "Tool Age" */
    //   TDropDownPanel::append_line(this->player_advance_civilization_drop,0x106a,1);
    //                     /* language.dll match for 0x106b: "Bronze Age" */
    //   TDropDownPanel::append_line(this->player_advance_civilization_drop,0x106b,2);
    //                     /* language.dll match for 0x106c: "Iron Age" */
    //   TDropDownPanel::append_line(this->player_advance_civilization_drop,0x106c,3);
    //                     /* language.dll match for 0x106d: "Post-Iron Age" */
    //   TDropDownPanel::append_line(this->player_advance_civilization_drop,0x106d,4);
    //   TDropDownPanel::setCurrentLineNumber(this->player_advance_civilization_drop,0);
    //   (**(code **)(this->player_advance_civilization_drop->_padding_ + 0x14))(0);
    //   return 1;
    // }
    // 
    // 
    // TODO: Full transliteration pending. Source of truth: scr_sed2.cpp.decomp @ 0x004B2BC0
    return 0;
}

// Offset: 0x004B2C50
void SavePlayerActiveStatus(TRIBE_Screen_Sed* this_) {
    // --- Ghidra decompiler output ---
    // 
    // /* protected: void __thiscall TRIBE_Screen_Sed::SavePlayerActiveStatus(void) */
    // 
    // void __thiscall TRIBE_Screen_Sed::SavePlayerActiveStatus(TRIBE_Screen_Sed *this)
    // 
    // {
    //   long lVar1;
    //   TRIBE_World *pTVar2;
    //   int iVar3;
    //   int iVar4;
    //   int iVar5;
    //   
    //   lVar1 = TDropDownPanel::get_line(this->player_number_list);
    //   pTVar2 = this->world;
    //   iVar4 = lVar1 + 1;
    //   iVar5 = 0;
    //   iVar3 = (int)(short)pTVar2->_padding_;
    //   if (iVar3 != 1 && -1 < iVar3 + -1) {
    //     do {
    //       RGE_Scenario::Set_player_Active((RGE_Scenario *)pTVar2->_padding_,iVar5,(uint)(iVar5 < iVar4))
    //       ;
    //       pTVar2 = this->world;
    //       iVar5 = iVar5 + 1;
    //     } while (iVar5 < (short)pTVar2->_padding_ + -1);
    //   }
    //   TDropDownPanel::empty_list(this->victory_player_list);
    //   TDropDownPanel::empty_list(this->victory_enemy_player_list);
    //   TDropDownPanel::empty_list(this->options_player_list);
    //   TDropDownPanel::empty_list(this->Diplomacy_player_list);
    //   TDropDownPanel::empty_list(this->player_list);
    //   TDropDownPanel::empty_list(this->unit_player_list);
    //                     /* language.dll match for 0x2776: "Gaia" */
    //   TDropDownPanel::append_line(this->unit_player_list,0x2776,0);
    //   if (0 < iVar4) {
    //                     /* language.dll match for 0x2865: "Player 1" */
    //     iVar3 = 0x2865;
    //     do {
    //       TDropDownPanel::append_line(this->unit_player_list,iVar3,0);
    //       TDropDownPanel::append_line(this->victory_player_list,iVar3,0);
    //       TDropDownPanel::append_line(this->victory_enemy_player_list,iVar3,0);
    //       TDropDownPanel::append_line(this->options_player_list,iVar3,0);
    //       TDropDownPanel::append_line(this->Diplomacy_player_list,iVar3,0);
    //       TDropDownPanel::append_line(this->player_list,iVar3,0);
    //       iVar5 = iVar3 + -0x2864;
    //       iVar3 = iVar3 + 1;
    //     } while (iVar5 < iVar4);
    //   }
    //   if (iVar4 <= this->player_num) {
    //     set_player(this,(short)iVar4,'\0','\0');
    //   }
    //   TDropDownPanel::set_line(this->victory_player_list,this->player_num + -1);
    //   TDropDownPanel::set_line(this->options_player_list,this->player_num + -1);
    //   TDropDownPanel::set_line(this->Diplomacy_player_list,this->player_num + -1);
    //   TDropDownPanel::set_line(this->player_list,this->player_num + -1);
    //   TDropDownPanel::set_line(this->unit_player_list,(int)this->player_num);
    //   return;
    // }
    // 
    // 
}

// Offset: 0x004B2DD0
int create_check_box(TRIBE_Screen_Sed* this_, TPanel* param_2, TButtonPanel** param_3) {
    // --- Ghidra decompiler output ---
    // 
    // /* protected: int __thiscall TRIBE_Screen_Sed::create_check_box(class TPanel *,class TButtonPanel *
    //    *) */
    // 
    // int __thiscall
    // TRIBE_Screen_Sed::create_check_box(TRIBE_Screen_Sed *this,TPanel *param_1,TButtonPanel **param_2)
    // 
    // {
    //   int iVar1;
    //   
    //   iVar1 = TEasy_Panel::create_check_box((TEasy_Panel *)this,param_1,param_2,0,0,0,0,1,0);
    //   if (iVar1 == 0) {
    //     return 0;
    //   }
    //   TPanel::set_z_order((TPanel *)*param_2,'\x01',0);
    //   (**(code **)((*param_2)->_padding_ + 0x14))(0);
    //   if (this->_padding_ != 0) {
    //     TButtonPanel::set_bevel_info
    //               (*param_2,3,(uint)(byte)this->_padding_,(uint)*(byte *)((int)&this->_padding_ + 1),
    //                (uint)*(byte *)((int)&this->_padding_ + 2),(uint)*(byte *)((int)&this->_padding_ + 3)
    //                ,(uint)(byte)this->_padding_,(uint)*(byte *)((int)&this->_padding_ + 1));
    //   }
    //   return 1;
    // }
    // 
    // 
    // TODO: Full transliteration pending. Source of truth: scr_sed2.cpp.decomp @ 0x004B2DD0
    return 0;
}

// Offset: 0x004B2E60
int create_radio_button(TRIBE_Screen_Sed* this_, TPanel* param_2, TButtonPanel** param_3) {
    // --- Ghidra decompiler output ---
    // 
    // /* protected: int __thiscall TRIBE_Screen_Sed::create_radio_button(class TPanel *,class TButtonPanel
    //    * *) */
    // 
    // int __thiscall
    // TRIBE_Screen_Sed::create_radio_button(TRIBE_Screen_Sed *this,TPanel *param_1,TButtonPanel **param_2)
    // 
    // {
    //   int iVar1;
    //   
    //   iVar1 = TEasy_Panel::create_radio_button((TEasy_Panel *)this,param_1,param_2,0,0,0,0,1,0);
    //   if (iVar1 == 0) {
    //     return 0;
    //   }
    //   TPanel::set_z_order((TPanel *)*param_2,'\x01',0);
    //   (**(code **)((*param_2)->_padding_ + 0x14))(0);
    //   if (this->_padding_ != 0) {
    //     TButtonPanel::set_bevel_info
    //               (*param_2,3,(uint)(byte)this->_padding_,(uint)*(byte *)((int)&this->_padding_ + 1),
    //                (uint)*(byte *)((int)&this->_padding_ + 2),(uint)*(byte *)((int)&this->_padding_ + 3)
    //                ,(uint)(byte)this->_padding_,(uint)*(byte *)((int)&this->_padding_ + 1));
    //   }
    //   return 1;
    // }
    // 
    // 
    // TODO: Full transliteration pending. Source of truth: scr_sed2.cpp.decomp @ 0x004B2E60
    return 0;
}

