// Class: RGE_Color_Table
// Size:  0x128
//
// VTable Layout:
// [00] `scalar_deleting_destructor'
//
// Member Layout:
// [0x004] char[30] color_table_name (sz: 0x1E)
// [0x022] short resource_id
// [0x024] uchar type
// [0x025] uchar map_color
// [0x026] short id
// [0x028] uchar[256] table (sz: 0x100)
// ----------------------------------------------------------------

// Function: RGE_Color_Table
// Address: 00424350
// [HELPER] s__hd: "%hd"
// [HELPER] s_data__s: "data\%s"
// [HELPER] s_r: "r"
/* WARNING: Variable defined which should be unmapped: temp_color */
/* public: __thiscall RGE_Color_Table::RGE_Color_Table(int) */

RGE_Color_Table * __thiscall RGE_Color_Table::RGE_Color_Table(RGE_Color_Table *this,int param_1)
{
  int iVar1;
  int iVar2;
  short temp_color;
  char tempname [300];
  
  this->_padding_ = (int)&_vftable_;
  rge_read(param_1,this->color_table_name,0x1e);
  rge_read(param_1,&this->id,2);
  rge_read(param_1,&this->resource_id,2);
  rge_read(param_1,&this->map_color,1);
  rge_read(param_1,&this->type,1);
  sprintf(tempname + 4,s_data__s,this->color_table_name);
  iVar1 = fopen(tempname + 4,s_r);
  if (iVar1 != 0) {
    iVar2 = 0;
    do {
      fscanf(iVar1,s__hd,tempname + 2);
      this->table[iVar2] = tempname[2];
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x100);
    fclose(iVar1);
  }
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 00424420
/* public: virtual void * __thiscall RGE_Color_Table::`scalar deleting destructor'(unsigned int) */

void * __thiscall RGE_Color_Table::_scalar_deleting_destructor_(RGE_Color_Table *this,uint param_1)
{
  ~RGE_Color_Table(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: RGE_Color_Table
// Address: 00424440
// [HELPER] s__col: ".col"
// [HELPER] s__hd__s__hd__hd: "%hd %s %hd %hd"
/* WARNING: Variable defined which should be unmapped: file_name */
/* public: __thiscall RGE_Color_Table::RGE_Color_Table(struct _iobuf *,short) */

RGE_Color_Table * __thiscall
RGE_Color_Table::RGE_Color_Table(RGE_Color_Table *this,_iobuf *param_1,short param_2)
{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  uchar *puVar6;
  char *pcVar7;
  char *pcVar8;
  char *file_name;
  char *local_4;
  
  this->id = param_2;
  this->_padding_ = (int)&_vftable_;
  puVar6 = this->table;
  for (iVar2 = 0x40; iVar2 != 0; iVar2 = iVar2 + -1) {
    puVar6[0] = '\0';
    puVar6[1] = '\0';
    puVar6[2] = '\0';
    puVar6[3] = '\0';
    puVar6 = puVar6 + 4;
  }
  pcVar8 = this->color_table_name;
  local_4 = (char *)0x0;
  fscanf(param_1,s__hd__s__hd__hd,&this->resource_id,pcVar8,&param_2,&param_1);
  this->map_color = (uchar)param_2;
  this->type = (uchar)param_1;
  addstring(&local_4,pcVar8,&s__col);
  uVar3 = 0xffffffff;
  pcVar5 = local_4;
  do {
    pcVar7 = pcVar5;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar7 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar7;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar5 = pcVar7 + -uVar3;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar8 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar8 = pcVar8 + 1;
  }
  if (local_4 != (char *)0x0) {
    free(local_4);
  }
  return this;
}

// --------------------------------------------------

// Function: RGE_Color_Table
// Address: 004244f0
// [HELPER] s__col: ".col"
// [HELPER] s__hd: "%hd"
// [HELPER] s_data__s: "data\%s"
// [HELPER] s_r: "r"
/* WARNING: Variable defined which should be unmapped: temp_color */
/* public: __thiscall RGE_Color_Table::RGE_Color_Table(char *) */

RGE_Color_Table * __thiscall RGE_Color_Table::RGE_Color_Table(RGE_Color_Table *this,char *param_1)
{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  uchar *puVar7;
  char *pcVar8;
  char *pcVar9;
  short temp_color;
  char tempname [300];
  
  this->_padding_ = (int)&_vftable_;
  this->resource_id = 0;
  this->map_color = '\0';
  this->type = '\0';
  puVar7 = this->table;
  for (iVar2 = 0x40; iVar2 != 0; iVar2 = iVar2 + -1) {
    puVar7[0] = '\0';
    puVar7[1] = '\0';
    puVar7[2] = '\0';
    puVar7[3] = '\0';
    puVar7 = puVar7 + 4;
  }
  uVar3 = 0xffffffff;
  do {
    pcVar5 = param_1;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar5 = param_1 + 1;
    cVar1 = *param_1;
    param_1 = pcVar5;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar5 = pcVar5 + -uVar3;
  pcVar9 = this->color_table_name;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar9 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar3 = 0xffffffff;
  pcVar5 = &s__col;
  do {
    pcVar9 = pcVar5;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar9 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar9;
  } while (cVar1 != '\0');
  tempname._0_4_ = ~uVar3;
  iVar2 = -1;
  pcVar5 = this->color_table_name;
  do {
    pcVar8 = pcVar5;
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    pcVar8 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar8;
  } while (cVar1 != '\0');
  pcVar5 = pcVar9 + -tempname._0_4_;
  pcVar9 = pcVar8 + -1;
  for (uVar3 = (uint)tempname._0_4_ >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar3 = tempname._0_4_ & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar9 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar9 = pcVar9 + 1;
  }
  sprintf(tempname + 4,s_data__s,this->color_table_name);
  iVar2 = fopen(tempname + 4,s_r);
  if (iVar2 != 0) {
    iVar6 = 0;
    do {
      fscanf(iVar2,s__hd,tempname);
      this->table[iVar6] = tempname[0];
      iVar6 = iVar6 + 1;
    } while (iVar6 < 0x100);
    fclose(iVar2);
  }
  return this;
}

// --------------------------------------------------

// Function: RGE_Color_Table
// Address: 004245f0
/* WARNING: Variable defined which should be unmapped: temp_color */
/* public: __thiscall RGE_Color_Table::RGE_Color_Table(class TDrawArea *,long,struct tagPALETTEENTRY
   *,struct tagPALETTEENTRY *) */

void __thiscall
RGE_Color_Table::RGE_Color_Table
          (RGE_Color_Table *this,TDrawArea *param_1,long param_2,tagPALETTEENTRY *param_3,
          tagPALETTEENTRY *param_4)
{
  uchar *puVar1;
  int iVar2;
  int iVar3;
  uchar *puVar4;
  int iVar5;
  uchar *puVar6;
  long temp_color;
  tagPALETTEENTRY local_81c;
  long index1;
  int local_814;
  tagPALETTEENTRY palette [256];
  tagPALETTEENTRY temp_palette [256];
  
  this->_padding_ = (int)&_vftable_;
  if (param_4 == (tagPALETTEENTRY *)0x0) {
    TDrawArea::GetPalette(param_1,palette + 1);
  }
  else {
    puVar4 = &palette[1].peGreen;
    iVar3 = 0x100;
    puVar6 = &param_4->peBlue;
    do {
      puVar1 = puVar6 + 4;
      ((tagPALETTEENTRY *)(puVar4 + -1))->peRed = ((tagPALETTEENTRY *)(puVar6 + -2))->peRed;
      *puVar4 = puVar6[-1];
      puVar1[(int)palette - (int)param_4] = *puVar6;
      puVar1[(int)palette + (1 - (int)param_4)] = puVar6[1];
      puVar4 = puVar4 + 4;
      iVar3 = iVar3 + -1;
      puVar6 = puVar1;
    } while (iVar3 != 0);
  }
  if (param_3 == (tagPALETTEENTRY *)0x0) {
    local_81c.peRed = '\0';
    local_81c.peGreen = '\0';
    local_81c.peBlue = '\0';
    local_81c.peFlags = '\0';
  }
  else {
    local_81c = *param_3;
  }
  this->resource_id = 0;
  this->map_color = '\0';
  this->type = '\0';
  puVar4 = this->table;
  for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {
    puVar4[0] = '\0';
    puVar4[1] = '\0';
    puVar4[2] = '\0';
    puVar4[3] = '\0';
    puVar4 = puVar4 + 4;
  }
  RGE_translate_palette(palette + 1,temp_palette + 1,local_81c,param_2,-1,-1);
  puVar4 = &temp_palette[1].peGreen;
  local_814 = 0;
  do {
    iVar5 = 0;
    local_81c.peRed = '\0';
    local_81c.peGreen = '\0';
    local_81c.peBlue = '\0';
    local_81c.peFlags = '\0';
    iVar3 = 20000;
    puVar6 = &palette[1].peGreen;
    do {
      iVar2 = (uint)((tagPALETTEENTRY *)(puVar4 + -1))->peRed -
              (uint)((tagPALETTEENTRY *)(puVar6 + -1))->peRed;
      iVar2 = iVar2 * iVar2 + ((uint)*puVar4 - (uint)*puVar6) * ((uint)*puVar4 - (uint)*puVar6) +
              ((uint)puVar4[1] - (uint)puVar6[1]) * ((uint)puVar4[1] - (uint)puVar6[1]);
      if (iVar2 < iVar3) {
        iVar3 = iVar2;
        local_81c = (tagPALETTEENTRY)iVar5;
      }
      iVar5 = iVar5 + 1;
      puVar6 = puVar6 + 4;
    } while (iVar5 < 0x100);
    this->table[local_814] = local_81c.peRed;
    local_814 = local_814 + 1;
    puVar4 = puVar4 + 4;
  } while (local_814 < 0x100);
  return;
}

// --------------------------------------------------

// Function: ~RGE_Color_Table
// Address: 004247a0
/* public: virtual __thiscall RGE_Color_Table::~RGE_Color_Table(void) */

void __thiscall RGE_Color_Table::~RGE_Color_Table(RGE_Color_Table *this)
{
  this->_padding_ = (int)&_vftable_;
  return;
}

// --------------------------------------------------

// Function: save
// Address: 004247b0
/* public: void __thiscall RGE_Color_Table::save(int) */

void __thiscall RGE_Color_Table::save(RGE_Color_Table *this,int param_1)
{
  rge_write(param_1,this->color_table_name,0x1e);
  rge_write(param_1,&this->id,2);
  rge_write(param_1,&this->resource_id,2);
  rge_write(param_1,&this->map_color,1);
  rge_write(param_1,&this->type,1);
  return;
}

// --------------------------------------------------

