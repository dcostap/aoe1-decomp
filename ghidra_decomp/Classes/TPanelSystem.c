// Class: TPanelSystem
// Size:  0xAD8
//
// Member Layout:
// [0x000] TPanel * mouseOwnerValue
// [0x004] TPanel * keyboardOwnerValue
// [0x008] TPanel * modalPanelValue
// [0x00C] TPanel * currentPanelValue
// [0x010] PanelNode * panelListValue
// [0x014] int numberActivePanelsValue
// [0x018] TPanel * prevCurrentChildValue
// [0x01C] void *[10] palette (sz: 0x28)
// [0x044] char[10][260] palette_file (sz: 0xA28)
// [0xA6C] int[10] palette_use_count (sz: 0x28)
// [0xA94] long[10] palette_id (sz: 0x28)
// [0xABC] ulong Imc
// [0xAC0] int ImeEnabled
// [0xAC4] int ImeOn
// [0xAC8] int InputEnabled
// [0xACC] int saved_colors
// [0xAD0] ulong save_back_color
// [0xAD4] ulong save_text_color
// ----------------------------------------------------------------

// Function: TPanelSystem
// Address: 00463be0
/* public: __thiscall TPanelSystem::TPanelSystem(void) */

TPanelSystem * __thiscall TPanelSystem::TPanelSystem(TPanelSystem *this)
{
  int *piVar1;
  char (*pacVar2) [260];
  int iVar3;
  
  this->ImeEnabled = 1;
  this->InputEnabled = 1;
  this->mouseOwnerValue = (TPanel *)0x0;
  this->keyboardOwnerValue = (TPanel *)0x0;
  this->modalPanelValue = (TPanel *)0x0;
  this->currentPanelValue = (TPanel *)0x0;
  this->panelListValue = (PanelNode *)0x0;
  this->numberActivePanelsValue = 0;
  this->prevCurrentChildValue = (TPanel *)0x0;
  this->Imc = 0;
  this->ImeOn = 0;
  this->saved_colors = 0;
  piVar1 = this->palette_use_count;
  pacVar2 = this->palette_file;
  iVar3 = 10;
  do {
    piVar1[-0x294] = 0;
    (*pacVar2)[0] = '\0';
    *piVar1 = 0;
    piVar1[10] = 0;
    piVar1 = piVar1 + 1;
    pacVar2 = pacVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  setup(this);
  return this;
}

// --------------------------------------------------

// Function: ~TPanelSystem
// Address: 00463c50
/* public: __thiscall TPanelSystem::~TPanelSystem(void) */

void __thiscall TPanelSystem::~TPanelSystem(TPanelSystem *this)
{
  PanelNode *pPVar1;
  TPanel *pTVar2;
  PanelNode *pPVar3;
  void **ppvVar4;
  char (*pacVar5) [260];
  int local_4;
  
  restore_system_colors(this);
  pPVar1 = this->panelListValue;
  if (pPVar1 != (PanelNode *)0x0) {
    pPVar3 = pPVar1->next_node;
    if (pPVar3 != pPVar1) {
      do {
        pPVar3 = pPVar3->next_node;
        pTVar2 = pPVar3->prev_node->panel;
        if (pTVar2 != (TPanel *)0x0) {
          (**(code **)pTVar2->_padding_)(1);
        }
        free(pPVar3->prev_node);
      } while (pPVar3 != this->panelListValue);
    }
    free(this->panelListValue);
    this->panelListValue = (PanelNode *)0x0;
  }
  pacVar5 = this->palette_file;
  ppvVar4 = this->palette;
  local_4 = 10;
  do {
    if (*ppvVar4 != (void *)0x0) {
      DeleteObject(*ppvVar4);
      *ppvVar4 = (void *)0x0;
      (*pacVar5)[0] = '\0';
      ppvVar4[0x294] = (void *)0x0;
      this->palette_id[0] = 0;
    }
    ppvVar4 = ppvVar4 + 1;
    pacVar5 = pacVar5 + 1;
    local_4 = local_4 + -1;
  } while (local_4 != 0);
  EnableIME(this);
  return;
}

// --------------------------------------------------

// Function: currentPanel
// Address: 00463d00
/* public: class TPanel * __thiscall TPanelSystem::currentPanel(void)const  */

TPanel * __thiscall TPanelSystem::currentPanel(TPanelSystem *this)
{
  return this->currentPanelValue;
}

// --------------------------------------------------

// Function: previousPanel
// Address: 00463d10
/* public: class TPanel * __thiscall TPanelSystem::previousPanel(void)const  */

TPanel * __thiscall TPanelSystem::previousPanel(TPanelSystem *this)
{
  TPanel *pTVar1;
  
  if (this->currentPanelValue != (TPanel *)0x0) {
    pTVar1 = TPanel::previousPanel(this->currentPanelValue);
    return pTVar1;
  }
  return (TPanel *)0x0;
}

// --------------------------------------------------

// Function: mouseOwner
// Address: 00463d20
/* public: class TPanel * __thiscall TPanelSystem::mouseOwner(void)const  */

TPanel * __thiscall TPanelSystem::mouseOwner(TPanelSystem *this)
{
  return this->mouseOwnerValue;
}

// --------------------------------------------------

// Function: keyboardOwner
// Address: 00463d30
/* public: class TPanel * __thiscall TPanelSystem::keyboardOwner(void)const  */

TPanel * __thiscall TPanelSystem::keyboardOwner(TPanelSystem *this)
{
  return this->keyboardOwnerValue;
}

// --------------------------------------------------

// Function: modalPanel
// Address: 00463d40
/* public: class TPanel * __thiscall TPanelSystem::modalPanel(void)const  */

TPanel * __thiscall TPanelSystem::modalPanel(TPanelSystem *this)
{
  return this->modalPanelValue;
}

// --------------------------------------------------

// Function: panel
// Address: 00463d50
/* public: class TPanel * __thiscall TPanelSystem::panel(char *) */

TPanel * __thiscall TPanelSystem::panel(TPanelSystem *this,char *param_1)
{
  PanelNode *pPVar1;
  
  pPVar1 = findPanelNode(this,param_1);
  if (pPVar1 != (PanelNode *)0x0) {
    return pPVar1->panel;
  }
  return (TPanel *)0x0;
}

// --------------------------------------------------

// Function: numberActivePanels
// Address: 00463d70
/* public: int __thiscall TPanelSystem::numberActivePanels(void)const  */

int __thiscall TPanelSystem::numberActivePanels(TPanelSystem *this)
{
  return this->numberActivePanelsValue;
}

// --------------------------------------------------

// Function: addPanel
// Address: 00463d80
/* public: int __thiscall TPanelSystem::addPanel(class TPanel *,int,int) */

int __thiscall TPanelSystem::addPanel(TPanelSystem *this,TPanel *param_1,int param_2,int param_3)
{
  char *pcVar1;
  PanelNode *pPVar2;
  
  pcVar1 = TPanel::panelName(param_1);
  pPVar2 = findPanelNode(this,pcVar1);
  if (pPVar2 == (PanelNode *)0x0) {
    pPVar2 = (PanelNode *)calloc(1,0xc);
    if (pPVar2 == (PanelNode *)0x0) {
      return 0;
    }
    pPVar2->panel = param_1;
    TPanel::setPreviousPanel(param_1,(TPanel *)0x0);
    pPVar2->prev_node = this->panelListValue->prev_node;
    pPVar2->next_node = this->panelListValue;
    this->panelListValue->prev_node = pPVar2;
    pPVar2->prev_node->next_node = pPVar2;
    this->numberActivePanelsValue = this->numberActivePanelsValue + 1;
  }
  if (param_2 != 0) {
    setCurrentPanel(this,param_1,param_3);
  }
  return 1;
}

// --------------------------------------------------

// Function: removePanel
// Address: 00463e10
/* public: int __thiscall TPanelSystem::removePanel(char *) */

int __thiscall TPanelSystem::removePanel(TPanelSystem *this,char *param_1)
{
  PanelNode *pPVar1;
  
  if (param_1 == (char *)0x0) {
    return (int)param_1;
  }
  pPVar1 = findPanelNode(this,param_1);
  if (pPVar1 == (PanelNode *)0x0) {
    return 0;
  }
  this->numberActivePanelsValue = this->numberActivePanelsValue + -1;
  pPVar1->prev_node->next_node = pPVar1->next_node;
  pPVar1->next_node->prev_node = pPVar1->prev_node;
  free(pPVar1);
  return 1;
}

// --------------------------------------------------

// Function: setCurrentPanel
// Address: 00463e60
/* public: int __thiscall TPanelSystem::setCurrentPanel(char *,int) */

int __thiscall TPanelSystem::setCurrentPanel(TPanelSystem *this,char *param_1,int param_2)
{
  PanelNode *pPVar1;
  
  pPVar1 = findPanelNode(this,param_1);
  if (pPVar1 != (PanelNode *)0x0) {
    if (this->mouseOwnerValue != (TPanel *)0x0) {
      TPanel::release_mouse(this->mouseOwnerValue);
    }
    this->modalPanelValue = (TPanel *)0x0;
    this->keyboardOwnerValue = (TPanel *)0x0;
    setCurrentPanel(this,pPVar1->panel,param_2);
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: restorePreviousPanel
// Address: 00463eb0
/* public: int __thiscall TPanelSystem::restorePreviousPanel(int) */

int __thiscall TPanelSystem::restorePreviousPanel(TPanelSystem *this,int param_1)
{
  TPanel *this_00;
  int iVar1;
  TPanel *this_01;
  TPanel *pTVar2;
  char *pcVar3;
  
  if (this->currentPanelValue == (TPanel *)0x0) {
    return 0;
  }
  this_01 = TPanel::previousPanel(this->currentPanelValue);
  if (this_01 == (TPanel *)0x0) {
    return 0;
  }
  this_00 = this->currentPanelValue;
  if (param_1 == 0) {
    TPanel::setPreviousPanel(this_01,this_00);
  }
  else {
    pTVar2 = TPanel::previousPanel(this_01);
    if (pTVar2 == this_00) {
      TPanel::setPreviousPanel(this_01,(TPanel *)0x0);
    }
    pcVar3 = TPanel::panelName(this_00);
    destroyPanel(this,pcVar3);
  }
  iVar1 = this_01->_padding_;
  this->currentPanelValue = this_01;
  (**(code **)(iVar1 + 0xc0))(1);
  (**(code **)(this->currentPanelValue->_padding_ + 0x20))(2);
  UpdateWindow(AppWnd);
  return 1;
}

// --------------------------------------------------

// Function: setMouseOwner
// Address: 00463f40
/* public: void __thiscall TPanelSystem::setMouseOwner(class TPanel *) */

void __thiscall TPanelSystem::setMouseOwner(TPanelSystem *this,TPanel *param_1)
{
  this->mouseOwnerValue = param_1;
  return;
}

// --------------------------------------------------

// Function: setKeyboardOwner
// Address: 00463f50
/* public: void __thiscall TPanelSystem::setKeyboardOwner(class TPanel *) */

void __thiscall TPanelSystem::setKeyboardOwner(TPanelSystem *this,TPanel *param_1)
{
  this->keyboardOwnerValue = param_1;
  return;
}

// --------------------------------------------------

// Function: setModalPanel
// Address: 00463f60
/* public: void __thiscall TPanelSystem::setModalPanel(class TPanel *) */

void __thiscall TPanelSystem::setModalPanel(TPanelSystem *this,TPanel *param_1)
{
  int iVar1;
  TPanel *pTVar2;
  TPanel *pTVar3;
  
  if ((this->modalPanelValue != (TPanel *)0x0) && (param_1 != (TPanel *)0x0)) {
    TPanel::setPreviousModalPanel(param_1,this->modalPanelValue);
  }
  pTVar2 = this->modalPanelValue;
  if (pTVar2 == (TPanel *)0x0) {
    pTVar3 = this->prevCurrentChildValue;
    if ((pTVar3 == (TPanel *)0x0) || (pTVar2 = pTVar3->parent_panel, pTVar2 == (TPanel *)0x0))
    goto LAB_00463fac;
  }
  else {
    if ((pTVar2->tab_stop != 0) || (pTVar2 = pTVar2->parent_panel, pTVar2 == (TPanel *)0x0))
    goto LAB_00463fac;
    pTVar3 = this->prevCurrentChildValue;
  }
  TPanel::set_curr_child(pTVar2,pTVar3);
LAB_00463fac:
  this->prevCurrentChildValue = (TPanel *)0x0;
  this->modalPanelValue = param_1;
  if ((param_1 != (TPanel *)0x0) && (param_1 != this->currentPanelValue)) {
    pTVar2 = param_1->parent_panel;
    if (pTVar2 != (TPanel *)0x0) {
      this->prevCurrentChildValue = pTVar2->curr_child;
      TPanel::set_curr_child(pTVar2,param_1);
      return;
    }
    iVar1 = param_1->_padding_;
    this->prevCurrentChildValue = (TPanel *)0x0;
    (**(code **)(iVar1 + 0xc0))(1);
  }
  return;
}

// --------------------------------------------------

// Function: setCurrentPanelModal
// Address: 00463ff0
/* public: void __thiscall TPanelSystem::setCurrentPanelModal(void) */

void __thiscall TPanelSystem::setCurrentPanelModal(TPanelSystem *this)
{
  TPanel *pTVar1;
  
  pTVar1 = this->modalPanelValue;
  if ((pTVar1 != (TPanel *)0x0) && (pTVar1 != this->currentPanelValue)) {
    TPanel::setPreviousModalPanel(this->currentPanelValue,pTVar1);
  }
  this->modalPanelValue = this->currentPanelValue;
  return;
}

// --------------------------------------------------

// Function: restorePreviousModalPanel
// Address: 00464010
/* public: int __thiscall TPanelSystem::restorePreviousModalPanel(void) */

int __thiscall TPanelSystem::restorePreviousModalPanel(TPanelSystem *this)
{
  TPanel *pTVar1;
  
  if (this->modalPanelValue == (TPanel *)0x0) {
    return 0;
  }
  pTVar1 = TPanel::previousModalPanel(this->modalPanelValue);
  if (pTVar1 == (TPanel *)0x0) {
    return 0;
  }
  (**(code **)(pTVar1->_padding_ + 0xc0))(1);
  setMouseOwner(this,pTVar1);
  setKeyboardOwner(this,pTVar1);
  this->modalPanelValue = pTVar1;
  return 1;
}

// --------------------------------------------------

// Function: destroyPanel
// Address: 00464060
/* public: int __thiscall TPanelSystem::destroyPanel(char *) */

int __thiscall TPanelSystem::destroyPanel(TPanelSystem *this,char *param_1)
{
  PanelNode *pPVar1;
  
  if (param_1 == (char *)0x0) {
    return (int)param_1;
  }
  pPVar1 = findPanelNode(this,param_1);
  if (pPVar1 == (PanelNode *)0x0) {
    return 0;
  }
  this->numberActivePanelsValue = this->numberActivePanelsValue + -1;
  if (this->currentPanelValue == pPVar1->panel) {
    this->currentPanelValue = (TPanel *)0x0;
  }
  if (this->mouseOwnerValue == pPVar1->panel) {
    this->mouseOwnerValue = (TPanel *)0x0;
  }
  if (this->keyboardOwnerValue == pPVar1->panel) {
    this->keyboardOwnerValue = (TPanel *)0x0;
  }
  if (this->modalPanelValue == pPVar1->panel) {
    this->modalPanelValue = (TPanel *)0x0;
  }
  pPVar1->prev_node->next_node = pPVar1->next_node;
  pPVar1->next_node->prev_node = pPVar1->prev_node;
  if (pPVar1->panel != (TPanel *)0x0) {
    (**(code **)pPVar1->panel->_padding_)(1);
  }
  free(pPVar1);
  return 1;
}

// --------------------------------------------------

// Function: inSystem
// Address: 00464100
/* public: int __thiscall TPanelSystem::inSystem(char *) */

int __thiscall TPanelSystem::inSystem(TPanelSystem *this,char *param_1)
{
  PanelNode *pPVar1;
  
  pPVar1 = findPanelNode(this,param_1);
  return (uint)(pPVar1 != (PanelNode *)0x0);
}

// --------------------------------------------------

// Function: inSystem
// Address: 00464120
/* public: int __thiscall TPanelSystem::inSystem(class TPanel *) */

int __thiscall TPanelSystem::inSystem(TPanelSystem *this,TPanel *param_1)
{
  char *pcVar1;
  PanelNode *pPVar2;
  
  if (param_1 != (TPanel *)0x0) {
    pcVar1 = TPanel::panelName(param_1);
    pPVar2 = findPanelNode(this,pcVar1);
    if (pPVar2 != (PanelNode *)0x0) {
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: setup
// Address: 00464150
/* protected: int __thiscall TPanelSystem::setup(void) */

int __thiscall TPanelSystem::setup(TPanelSystem *this)
{
  PanelNode *pPVar1;
  ulong uVar2;
  
  pPVar1 = (PanelNode *)calloc(1,0xc);
  this->panelListValue = pPVar1;
  if (pPVar1 == (PanelNode *)0x0) {
    return 0;
  }
  pPVar1->panel = (TPanel *)0x0;
  this->panelListValue->prev_node = this->panelListValue;
  this->panelListValue->next_node = this->panelListValue;
  uVar2 = GetSysColor(5);
  this->save_back_color = uVar2;
  uVar2 = GetSysColor(8);
  this->save_text_color = uVar2;
  this->saved_colors = 1;
  return 1;
}

// --------------------------------------------------

// Function: findPanelNode
// Address: 004641b0
/* protected: struct PanelNode * __thiscall TPanelSystem::findPanelNode(char *) */

PanelNode * __thiscall TPanelSystem::findPanelNode(TPanelSystem *this,char *param_1)
{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  PanelNode *pPVar5;
  bool bVar6;
  
  if (param_1 != (char *)0x0) {
    pPVar5 = this->panelListValue->next_node;
    if (pPVar5 != this->panelListValue) {
      do {
        pbVar2 = (byte *)TPanel::panelName(pPVar5->panel);
        pbVar4 = (byte *)param_1;
        do {
          bVar1 = *pbVar2;
          bVar6 = bVar1 < *pbVar4;
          if (bVar1 != *pbVar4) {
LAB_004641f9:
            iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
            goto LAB_004641fe;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar2[1];
          bVar6 = bVar1 < pbVar4[1];
          if (bVar1 != pbVar4[1]) goto LAB_004641f9;
          pbVar2 = pbVar2 + 2;
          pbVar4 = pbVar4 + 2;
        } while (bVar1 != 0);
        iVar3 = 0;
LAB_004641fe:
      } while ((iVar3 != 0) && (pPVar5 = pPVar5->next_node, pPVar5 != this->panelListValue));
    }
    if (pPVar5 != this->panelListValue) {
      pbVar4 = (byte *)TPanel::panelName(pPVar5->panel);
      do {
        bVar1 = *pbVar4;
        bVar6 = bVar1 < (byte)*param_1;
        if (bVar1 != *param_1) {
LAB_00464242:
          iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
          goto LAB_00464247;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar4[1];
        bVar6 = bVar1 < ((byte *)param_1)[1];
        if (bVar1 != ((byte *)param_1)[1]) goto LAB_00464242;
        pbVar4 = pbVar4 + 2;
        param_1 = (char *)((byte *)param_1 + 2);
      } while (bVar1 != 0);
      iVar3 = 0;
LAB_00464247:
      if (iVar3 == 0) {
        return pPVar5;
      }
    }
  }
  return (PanelNode *)0x0;
}

// --------------------------------------------------

// Function: setCurrentPanel
// Address: 00464260
/* protected: void __thiscall TPanelSystem::setCurrentPanel(class TPanel *,int) */

void __thiscall TPanelSystem::setCurrentPanel(TPanelSystem *this,TPanel *param_1,int param_2)
{
  int iVar1;
  int unaff_retaddr;
  
  TPanel::setPreviousPanel(param_1,this->currentPanelValue);
  if (this->currentPanelValue != (TPanel *)0x0) {
    (**(code **)(this->currentPanelValue->_padding_ + 0xc0))(0);
  }
  iVar1 = param_1->_padding_;
  this->currentPanelValue = param_1;
  (**(code **)(iVar1 + 0xc0))(1);
  (**(code **)(this->currentPanelValue->_padding_ + 0x20))(2);
  UpdateWindow(AppWnd);
  if (unaff_retaddr != 0) {
    setCurrentPanelModal(this);
  }
  return;
}

// --------------------------------------------------

// Function: get_palette
// Address: 004642c0
// [HELPER] s__s_pal: "%s.pal"
/* public: void * __thiscall TPanelSystem::get_palette(char *,long) */

void * __thiscall TPanelSystem::get_palette(TPanelSystem *this,char *param_1,long param_2)
{
  char cVar1;
  byte bVar2;
  int iVar3;
  char (*pacVar4) [260];
  int iVar5;
  void *pvVar6;
  uint uVar7;
  uint uVar8;
  long *plVar9;
  byte *pbVar10;
  char *pcVar11;
  int iVar12;
  char *pcVar13;
  bool bVar14;
  char (*local_10c) [260];
  char file_name2 [260];
  
  file_name2._0_4_ = this;
  if (param_1 == (char *)0x0) {
    file_name2[4] = '\0';
  }
  else {
    iVar3 = strchr(param_1,0x2e);
    if (iVar3 == 0) {
      sprintf(file_name2 + 4,s__s_pal,param_1);
    }
    else {
      uVar7 = 0xffffffff;
      do {
        pcVar11 = param_1;
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        pcVar11 = param_1 + 1;
        cVar1 = *param_1;
        param_1 = pcVar11;
      } while (cVar1 != '\0');
      uVar7 = ~uVar7;
      pcVar13 = file_name2;
      pcVar11 = pcVar11 + -uVar7;
      for (uVar8 = uVar7 >> 2; pcVar13 = pcVar13 + 4, uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined4 *)pcVar13 = *(undefined4 *)pcVar11;
        pcVar11 = pcVar11 + 4;
      }
      for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *pcVar13 = *pcVar11;
        pcVar11 = pcVar11 + 1;
        pcVar13 = pcVar13 + 1;
      }
    }
    strupr(file_name2 + 4);
  }
  local_10c = this->palette_file;
  iVar3 = -1;
  iVar12 = 0;
  plVar9 = this->palette_id;
  do {
    if ((void *)plVar9[-0x29e] == (void *)0x0) {
      if (iVar3 == -1) {
        iVar3 = iVar12;
      }
    }
    else {
      if ((param_2 != -1) && (*plVar9 == param_2)) {
LAB_0046445b:
        this->palette_use_count[iVar12] = this->palette_use_count[iVar12] + 1;
        return this->palette[iVar12];
      }
      pbVar10 = (byte *)(file_name2 + 4);
      pacVar4 = local_10c;
      do {
        bVar2 = (*pacVar4)[0];
        bVar14 = bVar2 < *pbVar10;
        if (bVar2 != *pbVar10) {
LAB_00464390:
          iVar5 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);
          goto LAB_00464395;
        }
        if (bVar2 == 0) break;
        bVar2 = (*pacVar4)[1];
        bVar14 = bVar2 < pbVar10[1];
        if (bVar2 != pbVar10[1]) goto LAB_00464390;
        pacVar4 = (char (*) [260])(*pacVar4 + 2);
        pbVar10 = pbVar10 + 2;
      } while (bVar2 != 0);
      iVar5 = 0;
LAB_00464395:
      this = (TPanelSystem *)file_name2._0_4_;
      if (iVar5 == 0) goto LAB_0046445b;
    }
    iVar12 = iVar12 + 1;
    plVar9 = plVar9 + 1;
    local_10c = local_10c + 1;
  } while (iVar12 < 10);
  if (iVar3 == -1) {
    return (void *)0x0;
  }
  pvVar6 = ReadPalette(file_name2 + 4,param_2,1);
  this->palette[iVar3] = pvVar6;
  if (pvVar6 == (void *)0x0) {
    return (void *)0x0;
  }
  uVar7 = 0xffffffff;
  this->palette_use_count[iVar3] = this->palette_use_count[iVar3] + 1;
  pcVar11 = file_name2 + 4;
  do {
    pcVar13 = pcVar11;
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    pcVar13 = pcVar11 + 1;
    cVar1 = *pcVar11;
    pcVar11 = pcVar13;
  } while (cVar1 != '\0');
  uVar7 = ~uVar7;
  pcVar11 = pcVar13 + -uVar7;
  pacVar4 = this->palette_file + iVar3;
  for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
    *(undefined4 *)*pacVar4 = *(undefined4 *)pcVar11;
    pcVar11 = pcVar11 + 4;
    pacVar4 = (char (*) [260])(*pacVar4 + 4);
  }
  for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
    (*pacVar4)[0] = *pcVar11;
    pcVar11 = pcVar11 + 1;
    pacVar4 = (char (*) [260])(*pacVar4 + 1);
  }
  this->palette_id[iVar3] = param_2;
  return this->palette[iVar3];
}

// --------------------------------------------------

// Function: release_palette
// Address: 00464480
/* public: void __thiscall TPanelSystem::release_palette(void *) */

void __thiscall TPanelSystem::release_palette(TPanelSystem *this,void *param_1)
{
  void **ppvVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  ppvVar1 = this->palette;
  do {
    if (*ppvVar1 == param_1) {
      iVar2 = this->palette_use_count[iVar3] + -1;
      this->palette_use_count[iVar3] = iVar2;
      if (iVar2 == 0) {
        DeleteObject(this->palette[iVar3]);
        this->palette[iVar3] = (void *)0x0;
        this->palette_file[iVar3][0] = '\0';
      }
      return;
    }
    iVar3 = iVar3 + 1;
    ppvVar1 = ppvVar1 + 1;
  } while (iVar3 < 10);
  return;
}

// --------------------------------------------------

// Function: DisableIME
// Address: 004644e0
/* public: void __thiscall TPanelSystem::DisableIME(void) */

void __thiscall TPanelSystem::DisableIME(TPanelSystem *this)
{
  ulong uVar1;
  
  if (this->ImeEnabled != 0) {
    uVar1 = _ImmAssociateContext_8(AppWnd,0);
    this->Imc = uVar1;
    this->ImeEnabled = 0;
  }
  return;
}

// --------------------------------------------------

// Function: EnableIME
// Address: 00464510
/* public: void __thiscall TPanelSystem::EnableIME(void) */

void __thiscall TPanelSystem::EnableIME(TPanelSystem *this)
{
  if ((this->Imc != 0) && (this->ImeEnabled == 0)) {
    _ImmAssociateContext_8(AppWnd,this->Imc);
  }
  return;
}

// --------------------------------------------------

// Function: IsIMEEnabled
// Address: 00464540
/* public: int __thiscall TPanelSystem::IsIMEEnabled(void) */

int __thiscall TPanelSystem::IsIMEEnabled(TPanelSystem *this)
{
  return this->ImeEnabled;
}

// --------------------------------------------------

// Function: TurnIMEOn
// Address: 00464550
/* public: void __thiscall TPanelSystem::TurnIMEOn(void) */

void __thiscall TPanelSystem::TurnIMEOn(TPanelSystem *this)
{
  if (((this->ImeOn == 0) && (this->ImeEnabled != 0)) && (this->Imc != 0)) {
    _ImmSetOpenStatus_8(this->Imc,1);
    this->ImeOn = 1;
  }
  return;
}

// --------------------------------------------------

// Function: TurnIMEOff
// Address: 00464590
/* public: void __thiscall TPanelSystem::TurnIMEOff(void) */

void __thiscall TPanelSystem::TurnIMEOff(TPanelSystem *this)
{
  if (((this->ImeOn != 0) && (this->ImeEnabled != 0)) && (this->Imc != 0)) {
    _ImmSetOpenStatus_8(this->Imc,0);
    this->ImeOn = 0;
  }
  return;
}

// --------------------------------------------------

// Function: IsIMEOn
// Address: 004645d0
/* public: int __thiscall TPanelSystem::IsIMEOn(void) */

int __thiscall TPanelSystem::IsIMEOn(TPanelSystem *this)
{
  return this->ImeOn;
}

// --------------------------------------------------

// Function: GetInputEnabled
// Address: 004645e0
/* public: int __thiscall TPanelSystem::GetInputEnabled(void) */

int __thiscall TPanelSystem::GetInputEnabled(TPanelSystem *this)
{
  return this->InputEnabled;
}

// --------------------------------------------------

// Function: EnableInput
// Address: 004645f0
/* public: void __thiscall TPanelSystem::EnableInput(void) */

void __thiscall TPanelSystem::EnableInput(TPanelSystem *this)
{
  this->InputEnabled = 1;
  return;
}

// --------------------------------------------------

// Function: DisableInput
// Address: 00464600
/* public: void __thiscall TPanelSystem::DisableInput(void) */

void __thiscall TPanelSystem::DisableInput(TPanelSystem *this)
{
  this->InputEnabled = 0;
  return;
}

// --------------------------------------------------

// Function: stop_sound_system
// Address: 00464610
/* public: void __thiscall TPanelSystem::stop_sound_system(void) */

void __thiscall TPanelSystem::stop_sound_system(TPanelSystem *this)
{
  PanelNode *pPVar1;
  
  for (pPVar1 = this->panelListValue->next_node;
      (pPVar1 != (PanelNode *)0x0 && (pPVar1 != this->panelListValue)); pPVar1 = pPVar1->next_node)
{
    if (pPVar1->panel != (TPanel *)0x0) {
      (**(code **)(pPVar1->panel->_padding_ + 0xd0))();
    }
  }
  return;
}

// --------------------------------------------------

// Function: restart_sound_system
// Address: 00464640
/* public: int __thiscall TPanelSystem::restart_sound_system(void) */

int __thiscall TPanelSystem::restart_sound_system(TPanelSystem *this)
{
  PanelNode *pPVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 1;
  for (pPVar1 = this->panelListValue->next_node;
      (pPVar1 != (PanelNode *)0x0 && (pPVar1 != this->panelListValue)); pPVar1 = pPVar1->next_node)
{
    if ((pPVar1->panel != (TPanel *)0x0) &&
       (iVar2 = (**(code **)(pPVar1->panel->_padding_ + 0xd4))(), iVar2 == 0)) {
      iVar3 = 0;
    }
  }
  return iVar3;
}

// --------------------------------------------------

// Function: restore_system_colors
// Address: 00464680
/* WARNING: Variable defined which should be unmapped: colors */
/* public: void __thiscall TPanelSystem::restore_system_colors(void) */

void __thiscall TPanelSystem::restore_system_colors(TPanelSystem *this)
{
  ulong uVar1;
  ulong colors [2];
  int elems [2];
  
  if (this->saved_colors != 0) {
    uVar1 = GetSysColor(5);
    if ((uVar1 == this->save_back_color) && (uVar1 = GetSysColor(8), uVar1 == this->save_text_color)
       ) {
      return;
    }
    colors[1] = this->save_back_color;
    elems[0] = this->save_text_color;
    elems[1] = 5;
    SetSysColors(2,elems + 1,colors + 1);
  }
  return;
}

// --------------------------------------------------

// Function: set_restore
// Address: 004646f0
/* public: void __thiscall TPanelSystem::set_restore(void) */

void __thiscall TPanelSystem::set_restore(TPanelSystem *this)
{
  PanelNode *pPVar1;
  
  pPVar1 = this->panelListValue->next_node;
  if (pPVar1 != this->panelListValue) {
    do {
      if (pPVar1->panel != (TPanel *)0x0) {
        pPVar1->panel->need_restore = '\x01';
      }
      pPVar1 = pPVar1->next_node;
    } while (pPVar1 != this->panelListValue);
  }
  return;
}

// --------------------------------------------------

