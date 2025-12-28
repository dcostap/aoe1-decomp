// Class: RGE_Scenario_File_Info
// Size:  0x10C
//
// Member Layout:
// [0x000] char[260] filename (sz: 0x104)
// [0x104] long scenario_num
// [0x108] RGE_Scenario_File_Entry * scenarios
// ----------------------------------------------------------------

// Function: RGE_Scenario_File_Info
// Address: 0048cea0
RGE_Scenario_File_Info * __thiscall
RGE_Scenario_File_Info::RGE_Scenario_File_Info(RGE_Scenario_File_Info *this,char *param_1)
{
  long *plVar1;
  char cVar2;
  int iVar3;
  RGE_Scenario_File_Entry *pRVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  char *pcVar9;
  int iVar10;
  RGE_Scenario_File_Info *pRVar11;
  
  uVar6 = 0xffffffff;
  do {
    pcVar9 = param_1;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar9 = param_1 + 1;
    cVar2 = *param_1;
    param_1 = pcVar9;
  } while (cVar2 != '\0');
  uVar6 = ~uVar6;
  pcVar9 = pcVar9 + -uVar6;
  pRVar11 = this;
  for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)pRVar11->filename = *(undefined4 *)pcVar9;
    pcVar9 = pcVar9 + 4;
    pRVar11 = (RGE_Scenario_File_Info *)(pRVar11->filename + 4);
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    pRVar11->filename[0] = *pcVar9;
    pcVar9 = pcVar9 + 1;
    pRVar11 = (RGE_Scenario_File_Info *)(pRVar11->filename + 1);
  }
  iVar3 = rge_open(this->filename,0x8000);
  if (iVar3 != -1) {
    plVar1 = &this->scenario_num;
    rge_read_uncompressed(iVar3,plVar1,4);
    iVar8 = 0;
    if (*plVar1 < 1) {
      this->scenarios = (RGE_Scenario_File_Entry *)0x0;
    }
    else {
      pRVar4 = (RGE_Scenario_File_Entry *)calloc(*plVar1,0x10c);
      this->scenarios = pRVar4;
      if (0 < *plVar1) {
        iVar10 = 0;
        do {
          rge_read_uncompressed(iVar3,this->scenarios->name + iVar10 + -8,4);
          rge_read_uncompressed(iVar3,this->scenarios->name + iVar10,0x104);
          uVar5 = (**(code **)(rge_base_game->_padding_ + 0x38))(iVar3);
          iVar8 = iVar8 + 1;
          *(undefined4 *)(this->scenarios->name + iVar10 + -4) = uVar5;
          iVar10 = iVar10 + 0x10c;
        } while (iVar8 < this->scenario_num);
        rge_close(iVar3);
        reload_scenarios(this);
        return this;
      }
    }
    rge_close(iVar3);
    reload_scenarios(this);
    return this;
  }
  this->scenario_num = 0;
  this->scenarios = (RGE_Scenario_File_Entry *)0x0;
  reload_scenarios(this);
  return this;
}

// --------------------------------------------------

// Function: ~RGE_Scenario_File_Info
// Address: 0048cfd0
void __thiscall RGE_Scenario_File_Info::~RGE_Scenario_File_Info(RGE_Scenario_File_Info *this)
{
  RGE_Scenario_Header *this_00;
  int iVar1;
  int iVar2;
  
  save(this);
  if (0 < this->scenario_num) {
    iVar2 = 0;
    if (0 < this->scenario_num) {
      iVar1 = 0;
      do {
        this_00 = *(RGE_Scenario_Header **)(this->scenarios->name + iVar1 + -4);
        if (this_00 != (RGE_Scenario_Header *)0x0) {
          RGE_Scenario_Header::~RGE_Scenario_Header(this_00);
          operator_delete(this_00);
        }
        iVar2 = iVar2 + 1;
        iVar1 = iVar1 + 0x10c;
      } while (iVar2 < this->scenario_num);
    }
    free(this->scenarios);
    this->scenarios = (RGE_Scenario_File_Entry *)0x0;
    this->scenario_num = 0;
  }
  return;
}

// --------------------------------------------------

// Function: save
// Address: 0048d040
void __thiscall RGE_Scenario_File_Info::save(RGE_Scenario_File_Info *this)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = rge_open(this->filename,0x8301,0x180);
  if (iVar1 != -1) {
    rge_write_uncompressed(iVar1,&this->scenario_num,4);
    iVar2 = 0;
    if (0 < this->scenario_num) {
      iVar3 = 0;
      do {
        rge_write_uncompressed(iVar1,this->scenarios->name + iVar3 + -8,4);
        rge_write_uncompressed(iVar1,this->scenarios->name + iVar3,0x104);
        (**(code **)(**(int **)(this->scenarios->name + iVar3 + -4) + 4))(iVar1);
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 0x10c;
      } while (iVar2 < this->scenario_num);
    }
    rge_close(iVar1);
  }
  return;
}

// --------------------------------------------------

// Function: reload_scenarios
// Address: 0048d0e0
// [HELPER] s__s__scn: "%s*.scn"
// [HELPER] s__s__scx: "%s*.scx"
// [HELPER] s__s_s: "%s%s"
void __thiscall RGE_Scenario_File_Info::reload_scenarios(RGE_Scenario_File_Info *this)
{
  char cVar1;
  byte bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  RGE_Scenario_File_Entry *pRVar6;
  char *pcVar7;
  char *pcVar8;
  RGE_Scenario_Header *pRVar9;
  uint uVar10;
  uint uVar11;
  RGE_Scenario_Header **ppRVar12;
  char *pcVar13;
  int iVar14;
  RGE_Scenario_Header **ppRVar15;
  bool bVar16;
  bool bVar17;
  uchar looped;
  uchar found_in_list;
  long handle;
  long count;
  RGE_Scenario_File_Entry *new_scenarios;
  long version;
  char file_name [256];
  _finddata_t file_info;
  
  iVar14 = 0;
  sprintf(file_name + 4,s__s__scn,rge_base_game->prog_info->scenario_dir);
  iVar4 = __findfirst(file_name + 4,&file_info.time_create);
  iVar5 = iVar4;
  while (iVar5 != -1) {
    iVar14 = iVar14 + 1;
    iVar5 = __findnext(iVar4,&file_info.time_create);
  }
  sprintf(file_name + 4,s__s__scx,rge_base_game->prog_info->scenario_dir);
  iVar4 = __findfirst(file_name + 4,&file_info.time_create);
  iVar5 = iVar4;
  while (iVar5 != -1) {
    iVar14 = iVar14 + 1;
    iVar5 = __findnext(iVar4,&file_info.time_create);
  }
  sprintf(file_name + 4,s__s__scn,rge_base_game->prog_info->scenario_dir);
  if (0 < iVar14) {
    count = __findfirst(file_name + 4,&file_info.time_create);
    bVar17 = count == -1;
    if (bVar17) {
      sprintf(file_name + 4,s__s__scx,rge_base_game->prog_info->scenario_dir);
      count = __findfirst(file_name + 4,&file_info.time_create);
    }
    if (count != -1) {
      pRVar6 = (RGE_Scenario_File_Entry *)calloc(iVar14,0x10c);
      ppRVar12 = &pRVar6->scenario_header;
LAB_0048d24d:
      iVar5 = 0;
      bVar3 = false;
      if (0 < this->scenario_num) {
        pcVar8 = this->scenarios->name;
        do {
          pcVar13 = file_info.name + 4;
          pcVar7 = pcVar8;
          do {
            bVar2 = *pcVar7;
            bVar16 = bVar2 < (byte)*pcVar13;
            if (bVar2 != *pcVar13) {
LAB_0048d29a:
              iVar4 = (1 - (uint)bVar16) - (uint)(bVar16 != 0);
              goto LAB_0048d29f;
            }
            if (bVar2 == 0) break;
            bVar2 = pcVar7[1];
            bVar16 = bVar2 < (byte)pcVar13[1];
            if (bVar2 != pcVar13[1]) goto LAB_0048d29a;
            pcVar7 = pcVar7 + 2;
            pcVar13 = pcVar13 + 2;
          } while (bVar2 != 0);
          iVar4 = 0;
LAB_0048d29f:
          if (iVar4 == 0) {
            if ((int)file_info.size <= this->scenarios[iVar5].time) {
              uVar10 = 0xffffffff;
              pcVar8 = this->scenarios[iVar5].name;
              goto code_r0x0048d2e8;
            }
            break;
          }
          iVar5 = iVar5 + 1;
          pcVar8 = pcVar8 + 0x10c;
        } while (iVar5 < this->scenario_num);
      }
      goto LAB_0048d332;
    }
  }
  return;
  while( true ) {
    uVar10 = uVar10 - 1;
    pcVar13 = pcVar8 + 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar13;
    if (cVar1 == '\0') break;
code_r0x0048d2e8:
    pcVar13 = pcVar8;
    if (uVar10 == 0) break;
  }
  uVar10 = ~uVar10;
  bVar3 = true;
  pcVar8 = pcVar13 + -uVar10;
  ppRVar15 = ppRVar12;
  for (uVar11 = uVar10 >> 2; ppRVar15 = ppRVar15 + 1, uVar11 != 0; uVar11 = uVar11 - 1) {
    *ppRVar15 = *(RGE_Scenario_Header **)pcVar8;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
    *(char *)ppRVar15 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    ppRVar15 = (RGE_Scenario_Header **)((int)ppRVar15 + 1);
  }
  ((RGE_Scenario_File_Entry *)(ppRVar12 + -1))->time = this->scenarios[iVar5].time;
  *ppRVar12 = this->scenarios[iVar5].scenario_header;
  this->scenarios[iVar5].scenario_header = (RGE_Scenario_Header *)0x0;
LAB_0048d332:
  if (!bVar3) {
    uVar10 = 0xffffffff;
    pcVar8 = file_info.name + 4;
    do {
      pcVar13 = pcVar8;
      if (uVar10 == 0) break;
      uVar10 = uVar10 - 1;
      pcVar13 = pcVar8 + 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar13;
    } while (cVar1 != '\0');
    uVar10 = ~uVar10;
    pcVar8 = pcVar13 + -uVar10;
    ppRVar15 = ppRVar12;
    for (uVar11 = uVar10 >> 2; ppRVar15 = ppRVar15 + 1, uVar11 != 0; uVar11 = uVar11 - 1) {
      *ppRVar15 = *(RGE_Scenario_Header **)pcVar8;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
      *(char *)ppRVar15 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      ppRVar15 = (RGE_Scenario_Header **)((int)ppRVar15 + 1);
    }
    ((RGE_Scenario_File_Entry *)(ppRVar12 + -1))->time = file_info.size;
    sprintf(file_name + 4,s__s_s,rge_base_game->prog_info->scenario_dir,file_info.name + 4);
    iVar5 = rge_open(file_name + 4,0x8000);
    if (-1 < iVar5) {
      rge_read_uncompressed(iVar5,file_name,4);
      pRVar9 = (RGE_Scenario_Header *)(**(code **)(rge_base_game->_padding_ + 0x38))(iVar5);
      *ppRVar12 = pRVar9;
      rge_close(iVar5);
    }
  }
  ppRVar12 = ppRVar12 + 0x43;
  iVar5 = __findnext(count,&file_info.time_create);
  if (iVar5 == -1) {
    if (bVar17) {
LAB_0048d44e:
      if (this->scenarios != (RGE_Scenario_File_Entry *)0x0) {
        iVar5 = 0;
        if (0 < this->scenario_num) {
          iVar4 = 0;
          do {
            pRVar9 = *(RGE_Scenario_Header **)(this->scenarios->name + iVar4 + -4);
            if (pRVar9 != (RGE_Scenario_Header *)0x0) {
              RGE_Scenario_Header::~RGE_Scenario_Header(pRVar9);
              operator_delete(pRVar9);
            }
            iVar5 = iVar5 + 1;
            iVar4 = iVar4 + 0x10c;
          } while (iVar5 < this->scenario_num);
        }
        free(this->scenarios);
      }
      this->scenarios = pRVar6;
      this->scenario_num = iVar14;
      return;
    }
    sprintf(file_name + 4,s__s__scx,rge_base_game->prog_info->scenario_dir);
    count = __findfirst(file_name + 4,&file_info.time_create);
    if (count == -1) goto LAB_0048d44e;
    bVar17 = true;
  }
  goto LAB_0048d24d;
}

// --------------------------------------------------

// Function: get_scenario_name
// Address: 0048d4d0
char * __thiscall
RGE_Scenario_File_Info::get_scenario_name(RGE_Scenario_File_Info *this,long param_1)
{
  if ((param_1 < this->scenario_num) && (-1 < param_1)) {
    return this->scenarios[param_1].name;
  }
  return (char *)0x0;
}

// --------------------------------------------------

// Function: get_scenario_info
// Address: 0048d500
RGE_Scenario_Header * __thiscall
RGE_Scenario_File_Info::get_scenario_info(RGE_Scenario_File_Info *this,long param_1)
{
  if ((param_1 < this->scenario_num) && (-1 < param_1)) {
    return this->scenarios[param_1].scenario_header;
  }
  return (RGE_Scenario_Header *)0x0;
}

// --------------------------------------------------

